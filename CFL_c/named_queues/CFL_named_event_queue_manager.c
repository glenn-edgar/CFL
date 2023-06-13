#include "CFL_user_functions.h"
#include "CFL_column_function_structures.h"

#include "CFL_definitions.h"
#include "CFL_event_manager.h"
#include "CFL_user_functions.h"
#include "Cfl_element_storeage.h"

typedef struct Named_event_queue_control_CFL_t
{
  unsigned max_number;
  unsigned number;
  Hash_cell_control_CFL_t *names;
  Event_control_CFL_t *event_queues;
} Named_event_queue_control_CFL_t;

/*
   static utility functions
*/
static Send_named_event_t *assemble_event_indexes(void *input, unsigned number, const char **event_queue_names);
static void free_rpc_msg(void *input, Event_data_CFL_t *event_data);
static void validate_rpc_message_header(RPC_message_header_CFL_t *rpc_message_header);
static Send_named_event_t *assemble_event_indexes(void *input, unsigned number, const char **event_queue_names);

void allocate_named_event_queue_space_CFL(void *input,
                                              unsigned number)
{

  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Named_event_queue_control_CFL_t *named_event_queue_control;

  named_event_queue_control =
      (Named_event_queue_control_CFL_t *)Allocate_once_malloc_CFL(
          handle, sizeof(Named_event_queue_control_CFL_t));

  named_event_queue_control->number = 0;
  named_event_queue_control->max_number = number;

  if (number > 0)
  {
    named_event_queue_control->names =
        contruct_hash_cell_control_CFL(handle, number);
    named_event_queue_control->event_queues =
        (Event_control_CFL_t *)Allocate_once_malloc_CFL(
            handle, sizeof(Event_control_CFL_t) * number);
  }
  else
  {
    named_event_queue_control->names = NULL;
    named_event_queue_control->event_queues = NULL;
  }
  handle->named_event_queue = named_event_queue_control;
}

/*
   load one shot functions

*/

unsigned named_event_reserve_one_shot_functions_CFL()
{
  return 2;
}

static void send_named_events(void *handle, void *params, Event_data_CFL_t *event_data);
static void reset_named_event_queues(void *handle, void *params,Event_data_CFL_t *event_data);
void named_events_load_one_shot_functions_CFL(void *input)
{
  Store_one_shot_function_CFL(input, "SEND_NAMED_EVENTS", send_named_events);
  Store_one_shot_function_CFL(input, "RESET_NAMED_EVENT_QUEUES", reset_named_event_queues);
  
}

/*
   load bool functions

*/
// no bool functions
/*

    Load Column functions

*/
unsigned named_event_reserve_column_space_CFL()
{

  return 3;
}


static int wait_for_client_rpc(void *handle,void *fn_aux, void *params, Event_data_CFL_t *event_data);
static int wait_for_server_rpc(void *handle,void *fn_aux, void *params, Event_data_CFL_t *event_data);
static int dispose_rpc_event(void *handle,void *fn_aux, void *params, Event_data_CFL_t *event_data);

void load_name_event_column_functions_CFL(void *input)
{

  Store_column_function_CFL(input,"WAIT_FOR_CLIENT_RPC_EVENT",wait_for_client_rpc);
  Store_column_function_CFL(input,"WAIT_FOR_SERVER_RPC_EVENT",wait_for_server_rpc);
  Store_column_function_CFL(input,"DISPOSE_RPC_EVENT", dispose_rpc_event);
  
}

void Define_named_event_queue_CFL(void *input, const char *name, unsigned size)
{
  Handle_CFL_t *handle;
  Named_event_queue_control_CFL_t *named_event_control;
  Event_control_CFL_t *event_control;
  int id;

  handle = (Handle_CFL_t *)input;
  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
  if (named_event_control->number >= named_event_control->max_number)
  {
    ASSERT_PRINT_INT("Too many named event queues",
                     named_event_control->number);
  }

  named_event_control->number += 1;
  id = Store_Name_CFL(named_event_control->names, name);
  event_control = named_event_control->event_queues + id;
  initialize_event_data_CFL(handle, event_control, id, size);
}

/******************************************** Event Queue Functions */



void Asm_send_named_events_CFL(void *input, unsigned number,
                               const char **event_queue_names,
                               Event_data_CFL_t *event_data)
{

  Send_named_event_t *send_event;

  send_event = assemble_event_indexes(input, number, event_queue_names);
  send_event->event_data.event_index = event_data->event_index;
  send_event->event_data.event_data = event_data->event_data;
  send_event->event_data.params = event_data->params;
  Asm_one_shot_CFL(input, "SEND_NAMED_EVENTS", send_event);
}

static void send_named_events(void *handle, void *params, Event_data_CFL_t *event_data)
{
  (void)event_data;
  Send_named_event_t *send_event = (Send_named_event_t *)params;

  for (unsigned i = 0; i < send_event->queue_number; i++)
  {

    Send_named_event_CFL(handle, send_event->event_queue_indexes[i],
                         &send_event->event_data);
  }
}

void Asm_reset_named_event_queues_CFL(void *input, unsigned number, const char **event_queue_names)
{
  Send_named_event_t *send_event;
  send_event = assemble_event_indexes(input, number, event_queue_names);
  Asm_one_shot_CFL(input, "RESET_NAMED_EVENT_QUEUES", send_event);
}

static void reset_named_event_queues(void *handle, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  Send_named_event_t *send_event = (Send_named_event_t *)params;

  for (unsigned i = 0; i < send_event->queue_number; i++)
  {

    Reset_named_event_queue_CFL(handle, send_event->event_queue_indexes[i]);
  }
}



typedef struct Wait_for_rpc_data_t
{
  unsigned short rpc_event;
  void *user_data;
 
} Wait_for_rpc_data_t;

void Asm_wait_for_client_rpc_CFL(void *input, unsigned short rpc_event, const char *message_handler, void *user_data)
{
  One_shot_function_CFL_t fn = Get_one_shot_function_CFL(input, message_handler);
  Wait_for_rpc_data_t *wait_for_rpc_data = (Wait_for_rpc_data_t *)Allocate_once_malloc_CFL(input, sizeof(Wait_for_rpc_data_t));
  wait_for_rpc_data->rpc_event = rpc_event;

  wait_for_rpc_data->user_data = user_data;

  Asm_store_column_element_CFL(input, "WAIT_FOR_CLIENT_RPC_EVENT", (void *)fn, (void *)wait_for_rpc_data);
}



static int wait_for_client_rpc(void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data)
{
  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)fn_aux;
  Wait_for_rpc_data_t *wait_for_rpc_data = (Wait_for_rpc_data_t *)params;
  if (event_data->event_index == wait_for_rpc_data->rpc_event)
  {
   
    fn(input, wait_for_rpc_data->user_data, event_data);
    free_rpc_msg(input, event_data);
    return DISABLE_CFL;
  }
  return HALT_CFL;
}



void Asm_wait_for_server_rpc_CFL(void *input,unsigned short rpc_event, const char *bool_function, void *user_data){

  Wait_for_rpc_data_t *wait_for_rpc_data = (Wait_for_rpc_data_t *)Allocate_once_malloc_CFL(input, sizeof(Wait_for_rpc_data_t));
  wait_for_rpc_data->rpc_event = rpc_event;
  wait_for_rpc_data->user_data = user_data;
  Asm_store_column_element_CFL(input, "WAIT_FOR_SERVER_RPC_EVENT", 
                                      (void *)Get_bool_function_CFL(input, bool_function), (void *)wait_for_rpc_data);

}

static int wait_for_server_rpc(void *input, void *fn_aux, void *param, Event_data_CFL_t *event_data)
{
  Bool_function_CFL_t fn = (Bool_function_CFL_t)fn_aux;
  Wait_for_rpc_data_t *wait_for_rpc_data = (Wait_for_rpc_data_t *)param;
  if (event_data->event_index == EVENT_INIT_CFL)
  {
    if (fn(input, wait_for_rpc_data->user_data, event_data))
    {
      return CONTINUE_CFL;
    }
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    if (fn(input, wait_for_rpc_data->user_data, event_data))
    {
      return CONTINUE_CFL;
    }
  }
  if (event_data->event_index == wait_for_rpc_data->rpc_event)
  {
    RPC_message_header_CFL_t *rpc_message_header = (RPC_message_header_CFL_t *)event_data->params;
    validate_rpc_message_header(rpc_message_header);
    if (fn(input, wait_for_rpc_data->user_data, event_data) == false)
    {
     
      return CONTINUE_CFL;
    }
 
    rpc_message_header->success = true;
    
    Send_named_event_CFL(input, rpc_message_header->client_queue_id, event_data);
    
    return HALT_CFL;
  }
  // for other events like timer events
  return CONTINUE_CFL;
}

typedef struct RPC_dispose_data_t
{
  unsigned short rpc_event;
  bool                    flag;
  One_shot_function_CFL_t fn;
  void                    *user_data;
} RPC_dispose_data_t;

void Asm_dispose_rpc_event_CFL(void *input, unsigned short rpc_event,bool flag, const char *message_handler, void *user_data)
{
  RPC_dispose_data_t *dispose_data = (RPC_dispose_data_t *)Allocate_once_malloc_CFL(input, sizeof(RPC_dispose_data_t));
  dispose_data->rpc_event = rpc_event;
  dispose_data->flag = flag;
  dispose_data->fn = Get_one_shot_function_CFL(input, message_handler);
  dispose_data->user_data = user_data;
  Asm_store_column_element_CFL(input,"DISPOSE_RPC_EVENT",NULL, dispose_data);
}

static int dispose_rpc_event(void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data)
{
  (void)fn_aux; // unused parameter no aux function attached to this operation
  RPC_dispose_data_t *dispose_data = (RPC_dispose_data_t *)params;

  if (event_data->event_index == dispose_data->rpc_event)
  {
    if(dispose_data->fn != NULL){
      dispose_data->fn(input, dispose_data->user_data, event_data);
    }
  
    if(dispose_data->flag == false){
      free_rpc_msg(input, event_data);
      return HALT_CFL;
    }
    // flag is true
    RPC_message_header_CFL_t *header = (RPC_message_header_CFL_t *)event_data->params;
    
    Printf_CFL("RPC event %d was not handled\n", dispose_data->rpc_event);
    validate_rpc_message_header(header);
    
    Printf_CFL("RPC request id %d was not handled\n", header->request_id);
    Printf_CFL("RPC client queue id %d was not handled\n", header->client_queue_id);
    Printf_CFL("RPC server queue id %d was not handled\n\n", header->server_queue_id);

    ASSERT_PRINT("RPC event was not handled\n", "");
  }
  return CONTINUE_CFL;
}

/*
   RPC client functions

*/

void Asm_send_rpc_CFL(void *input, unsigned short rpc_event_id, unsigned short rpc_request_id,
                      const char *client_queue_name, const char *server_queue_name,
                      bool client_free_message_data, unsigned short client_data_size, void *client_message_data)
{

  Event_data_CFL_t *event_data = (Event_data_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Event_data_CFL_t));
  RPC_message_header_CFL_t *rpc_message_header = (RPC_message_header_CFL_t *)Allocate_once_malloc_CFL(input,
                                                                                                      sizeof(RPC_message_header_CFL_t));
  unsigned client_queue_id = Get_named_event_queue_index_CFL(input, client_queue_name);
  //unsigned server_queue_id = Get_named_event_queue_index_CFL(input, server_queue_name);
  rpc_message_header->magic = RPC_HEADER_MAGIC;
  rpc_message_header->success = false;
  rpc_message_header->event_id = rpc_event_id;
  rpc_message_header->request_id = rpc_request_id;
  rpc_message_header->client_queue_id = client_queue_id;
  rpc_message_header->client_free_message_data = client_free_message_data;
  rpc_message_header->client_data_size = client_data_size;
  rpc_message_header->client_message_data = client_message_data;
  event_data->event_index = rpc_event_id;
  event_data->event_data = 0;
  event_data->params = (void *)rpc_message_header;

  const char *queue_names[1] = {server_queue_name};
  Asm_send_named_events_CFL(input, 1, queue_names, event_data);
}



/*

   C runtime support functions

*/

unsigned Get_named_event_queue_index_CFL(void *input, const char *name)
{
  Handle_CFL_t *handle;
  int return_value;
  Named_event_queue_control_CFL_t *named_event_control;
  // Event_control_CFL_t *event_control_queue;

  handle = (Handle_CFL_t *)input;

  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
  // event_control_queue = named_event_control->event_queues;
  return_value = Find_Name_CFL(named_event_control->names, name);
  if (return_value < 0)
  {
    ASSERT_PRINT(__func__, "Name not found");
  }
  return return_value;
}

Event_control_CFL_t *Get_named_event_queue_CFL(void *input, unsigned index)
{
  Handle_CFL_t *handle;
  Named_event_queue_control_CFL_t *named_event_control;
  Event_control_CFL_t *event_control_queue;

  handle = (Handle_CFL_t *)input;
  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
  if (index >= named_event_control->number)
  {
    ASSERT_PRINT_INT("Name Queue Index too large", index);
  }
  event_control_queue = named_event_control->event_queues;
  return &event_control_queue[index];
}

void Send_named_event_CFL(void *handle, unsigned index,
                          Event_data_CFL_t *event_data)
{
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);

  if (enqueue_event_CFL(event_control, event_data) == false)
  {
    ASSERT_PRINT(__func__, "Queue full");
  }
}

Event_data_CFL_t *Get_named_event_CFL(void *handle, unsigned index)
{
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return dequeue_event_CFL(event_control);
}

Event_data_CFL_t *Peak_named_event_CFL(void *handle, unsigned index)
{
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return peak_event_CFL(event_control);
}

unsigned Get_named_event_queue_number_CFL(void *handle, unsigned index)
{
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return get_queue_number_CFL(event_control);
}
Event_data_CFL_t *Pop_named_event_CFL(void *handle, unsigned index)
{
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return dequeue_event_CFL(event_control);
}

void Reset_named_event_queue_CFL(void *handle, unsigned index)
{
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  reset_event_queue_CFL(event_control);
}

/*

   static utility functions

*/

static void validate_rpc_message_header(RPC_message_header_CFL_t *rpc_message_header)
{
  if (rpc_message_header->magic != RPC_HEADER_MAGIC)
  {
    ASSERT_PRINT_F("RPC message header magic number is not correct received %x got %x \n", RPC_HEADER_MAGIC, rpc_message_header->magic);
  }
}

static void free_rpc_msg(void *input, Event_data_CFL_t *event_data)
{

  RPC_message_header_CFL_t *rpc_message_header = (RPC_message_header_CFL_t *)event_data->params;
  validate_rpc_message_header(rpc_message_header);
  if (rpc_message_header->client_free_message_data)
  {
    Private_heap_free_CFL(input, rpc_message_header->client_message_data);
  }
  if (rpc_message_header->server_free_message_data)
  {
    Private_heap_free_CFL(input, rpc_message_header->server_message_data);
  }
}
static Send_named_event_t *assemble_event_indexes(void *input, unsigned number, const char **event_queue_names)
{

  Send_named_event_t *send_event;

  send_event = (Send_named_event_t *)Allocate_once_malloc_CFL(input, sizeof(Send_named_event_t));
  send_event->event_queue_indexes = (unsigned short *)Allocate_once_malloc_CFL(input, sizeof(unsigned) * number);
  send_event->queue_number = number;
  for (unsigned i = 0; i < number; i++)
  {
    send_event->event_queue_indexes[i] =
        Get_named_event_queue_index_CFL(input, event_queue_names[i]);
  }
  return send_event;
}