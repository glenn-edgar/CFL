#include "CFL_user_functions.h"
#include "CFL_column_function_structures.h" 

#include "CFL_definitions.h"
#include "CFL_event_manager.h"
#include "CFL_user_functions.h"
#include "Cfl_element_storeage.h"


typedef struct Named_event_queue_control_CFL_t {
  unsigned max_number;
  unsigned number;
  Hash_cell_control_CFL_t *names;
  Event_control_CFL_t *event_queues;
} Named_event_queue_control_CFL_t;

static void send_named_events_immediate_handler(void *handle, void *params,
                                                Event_data_CFL_t *event_data);
static void send_named_events_fn_handler(void *handle, void *params,
                                         Event_data_CFL_t *event_data);

static void reset_named_event_queue(void *handle, void *params,
                                    Event_data_CFL_t *event_data);


void allocate_named_event_queue_space_CFL(void *input,
                                          unsigned number) {

  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Named_event_queue_control_CFL_t *named_event_queue_control;

  named_event_queue_control =
      (Named_event_queue_control_CFL_t *)Allocate_once_malloc_CFL(
          handle, sizeof(Named_event_queue_control_CFL_t));

  named_event_queue_control->number = 0;
  named_event_queue_control->max_number = number;

  if (number > 0) {
    named_event_queue_control->names =
        contruct_hash_cell_control_CFL(handle, number);
    named_event_queue_control->event_queues =
        (Event_control_CFL_t *)Allocate_once_malloc_CFL(
            handle, sizeof(Event_control_CFL_t) * number);
  } else {
    named_event_queue_control->names = NULL;
    named_event_queue_control->event_queues = NULL;
  }
  handle->named_event_queue = named_event_queue_control;
}

unsigned named_event_reserve_one_shot_functions_CFL(){

      return 3;

}

void named_events_load_one_shot_functions(void *input){
  Store_one_shot_function_CFL(input, "SEND_NAMED_EVENTS_IMMEDIATE", send_named_events_immediate_handler);
   Store_one_shot_function_CFL(input, "SEND_NAMED_EVENTS_FN", send_named_events_fn_handler);  
   Store_one_shot_function_CFL(input, "RESET_NAMED_EVENT_QUEUES", reset_named_event_queue);                         
}



void Define_named_event_queue_CFL(void *input, const char *name, unsigned size ){
  Handle_CFL_t *handle;
  Named_event_queue_control_CFL_t *named_event_control;
  Event_control_CFL_t *event_control;
  int id;

  
  handle = (Handle_CFL_t *)input;
  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
  if (named_event_control->number >= named_event_control->max_number ) {
    ASSERT_PRINT_INT("Too many named event queues",
                     named_event_control->number);
  }
  
 
  named_event_control->number += 1;
  id = Store_Name_CFL(named_event_control->names, name);
  event_control = named_event_control->event_queues+id;
  initialize_event_data_CFL(handle, event_control, id, size);
}
    
  
  
/******************************************** Event Queue Functions */


static inline Send_named_event_t* assemble_event_indexes(void* input, unsigned number, const char** event_queue_names) {

  Send_named_event_t* send_event;

  send_event = (Send_named_event_t*)Allocate_once_malloc_CFL(input, sizeof(Send_named_event_t));
  send_event->event_queue_indexes = (unsigned short*)Allocate_once_malloc_CFL(input, sizeof(unsigned) * number);
  send_event->queue_number = number;
  for (unsigned i = 0; i < number; i++) {
    send_event->event_queue_indexes[i] =
      Get_named_event_queue_index_CFL(input, event_queue_names[i]);
  }
  return send_event;
}

void Asm_send_named_events_CFL(void* input, unsigned number,
  const char** event_queue_names,
  Event_data_CFL_t* event_data) {

  Send_named_event_t* send_event;

  send_event = assemble_event_indexes(input, number, event_queue_names);
  send_event->event_data.event_index = event_data->event_index;
  send_event->event_data.event_data = event_data->event_data;
  send_event->event_data.params = event_data->params;
  Asm_one_shot_CFL(input, "SEND_NAMED_EVENTS_IMMEDIATE", send_event);
}

void Asm_send_named_events_fn_CFL(void* input, unsigned number,
  const char** event_queue_names,
  const char* event_function, void* user_data) {

  Send_named_event_t* send_event;

  send_event = assemble_event_indexes(input, number, event_queue_names);
  send_event->fn = Get_one_shot_function_CFL(input, event_function);
  send_event->user_data = user_data;
  Asm_one_shot_CFL(input, "SEND_NAMED_EVENTS_FN", send_event);
}




void Asm_reset_named_event_queues_CFL(void* input, unsigned number, const char** event_queue_names) {
  Send_named_event_t* send_event;
  send_event = assemble_event_indexes(input, number, event_queue_names);
  Asm_one_shot_CFL(input, "RESET_NAMED_EVENT_QUEUES", send_event);
}

void Asm_prepare_rpc_message(void *input){
    Asm_one_shot_CFL(input, "PREPARE_RPC_MESSAGE", NULL);
}



void Asm_send_rpc_message(void *input, unsigned queue_index){
    Asm_one_shot_CFL(input, "SEND_RPC_MESSAGE", &queue_index);
}

typedef struct Wait_rpc_message {
    unsigned named_queue_index
} Wait_rpc_message_t;

void Asm_wait_rpc_message(void *input,const char * named_queue){
    unsigned name_queue_index = Get_named_event_queue_index_CFL(input, named_queue);
    Wait_rpc_message_t *wait_rpc_message = (Wait_rpc_message_t *)Allocate_once_malloc_CFL(input, sizeof(Wait_rpc_message_t));
    wait_rpc_message->named_queue_index = name_queue_index;
    Asm_wait_CFL(input,"WAIT_QUEUE_RPC",NO_TIME_OUT_CFL,true,NULL,wait_rpc_message);
}

void Asm_dispose_rpc_message(void *input){
    Asm_one_shot_CFL(input, "DISPOSE_RPC_MESSAGE", NULL);
} 

typedef struct RPC_message_CLF_t {
    unsigned short return_queue_index;
    unsigned short rpc_action_id;
    unsigned short size;
    void *data;
} RPC_message_CLF_t;

static void free_rpc_message_CFL(RPC_message_CLF_t *rpc_message){
    
    
}
 
static void dispose_rpc_message(void *input, void *params,
                                Event_data_CFL_t *event_data) {
  (void)event_data;
  (void)params;              
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Engine_control_CFL_t *engine_control = (Engine_control_CFL_t*)handle->engine_control;
  Column_CFL_t *column = (Column_CFL_t*)engine_control->current_column;
  Event_data_CFL_t *rpc_event = column->local_event;
  column->local_event = NULL;
  RPC_message_CLF_t *rpc_message = (RPC_message_CLF_t*)rpc_event->params;
  Private_heap_free_CFL(input,rpc_message->data);
  Private_heap_free_CFL(rpc_message);
  Private_heap_element_t()
  
}


static void send_named_events_immediate_handler(void *handle, void *params,
                                                Event_data_CFL_t *event_data)
{
  (void)event_data;
  Send_named_event_t *send_event;
  send_event = (Send_named_event_t *)params;

  for (unsigned i = 0; i < send_event->queue_number; i++)
  {

    Send_named_event_CFL(handle, send_event->event_queue_indexes[i],
                         &send_event->event_data);
  }
}
static void send_named_events_fn_handler(void *handle, void *params,
                                         Event_data_CFL_t *event_data)
{
  (void)event_data;
  Send_named_event_t *send_event;
  send_event = (Send_named_event_t *)params;

  send_event->fn(handle, send_event->user_data, &send_event->event_data);

  for (unsigned i = 0; i < send_event->queue_number; i++)
  {

    Send_named_event_CFL(handle, send_event->event_queue_indexes[i],
                         &send_event->event_data);
  }
}

static void reset_named_event_queue(void *handle, void *params,
                                    Event_data_CFL_t *event_data)
{

  (void)event_data;
  Send_named_event_t *send_event = (Send_named_event_t *)params;

  for (unsigned i = 0; i < send_event->queue_number; i++)
  {

    Reset_named_event_queue_CFL(handle, send_event->event_queue_indexes[i]);
  }
}







unsigned Get_named_event_queue_index_CFL(void *input, const char *name) {
  Handle_CFL_t *handle;
  int          return_value;
  Named_event_queue_control_CFL_t *named_event_control;
  //Event_control_CFL_t *event_control_queue;

  handle = (Handle_CFL_t *)input;
  

  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
 // event_control_queue = named_event_control->event_queues;
  return_value =  Find_Name_CFL(named_event_control->names, name);
  if(return_value < 0 ){
    ASSERT_PRINT(__func__, "Name not found");
  }
  return return_value;
}

Event_control_CFL_t *Get_named_event_queue_CFL(void *input, unsigned index) {
  Handle_CFL_t *handle;
  Named_event_queue_control_CFL_t *named_event_control;
  Event_control_CFL_t *event_control_queue;

  handle = (Handle_CFL_t *)input;
  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
  if (index >= named_event_control->number) {
    ASSERT_PRINT_INT( "Name Queue Index too large", index);
  }
  event_control_queue = named_event_control->event_queues;
  return &event_control_queue[index];
}

void Send_named_event_CFL(void *handle, unsigned index,
                          Event_data_CFL_t *event_data) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
 
  if( enqueue_event_CFL(event_control, event_data) == false){
    ASSERT_PRINT(__func__, "Queue full");
  }
}

Event_data_CFL_t *Get_named_event_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return dequeue_event_CFL(event_control);
}

Event_data_CFL_t *Peak_named_event_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return peak_event_CFL(event_control);
}

unsigned Get_named_event_queue_number_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return get_queue_number_CFL(event_control);
}
Event_data_CFL_t *Pop_named_event_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return dequeue_event_CFL(event_control);
}

void Reset_named_event_queue_CFL(void* handle, unsigned index){
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  reset_event_queue_CFL(event_control);
}