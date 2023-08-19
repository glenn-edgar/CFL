#include "Cfl_core_aux_functions.h"
#include "Cfl_event_manager.h"
#include "Cfl_user_functions.h"

static inline void enable_indexes(void *input, unsigned column_number,
                                  unsigned short *column_indexes)
{
  for (unsigned i = 0; i < column_number; i++)
  {
    Enable_column_CFL(input, *column_indexes++);
  }
}
static inline void disable_indexes(void *input, unsigned column_number,
                                   unsigned short *column_indexes)
{
  for (unsigned i = 0; i < column_number; i++)
  {

    Disable_column_CFL(input, *column_indexes++);
  }
}

static inline void reset_indexes(void *input, unsigned column_number,
                                 unsigned short *column_indexes)
{
  for (unsigned i = 0; i < column_number; i++)
  {
    Reset_column_CFL(input, *column_indexes++);
  }
}

typedef struct if_function_ref
{
  const char *name;
  If_function_CFL_t fn;

} if_function_ref;

typedef struct try_function_ref
{
  const char *name;
  Try_function_CFL_t fn;

} try_function_ref;

static void log_message(void *handle, void *params,
                        Event_data_CFL_t *event_data);
static void send_event(void *handle, void *params,
                       Event_data_CFL_t *event_data);

static void disable_columns(void *handle, void *params,
                            Event_data_CFL_t *event_data);
static void reset_columns(void *handle, void *params,
                          Event_data_CFL_t *event_data);
static void set_column_return(void *handle, void *params,
                              Event_data_CFL_t *event_data);

static void set_column_watch_dog(void *handle, void *params,
                                 Event_data_CFL_t *event_data);
static void clear_column_watch_dog(void *handle, void *params,
                                   Event_data_CFL_t *event_data);
static void null_function(void *handle, void *params,
                          Event_data_CFL_t *event_data);
static void dump_nodes_handler(void *handle, void *params,
                               Event_data_CFL_t *event_data);
static void verify_nodes_handler(void *handle, void *params,
                                 Event_data_CFL_t *event_data);

static void set_current_column_event_handler(void *handle, void *params,
                                             Event_data_CFL_t *event_data);

static void set_column_event_handler(void *handle, void *params,
                                             Event_data_CFL_t *event_data);                                             

  

static const one_shot_function_ref one_shot_functions[] = {
    {"NULL", null_function},
    {"LOG_MESSAGE", log_message},
    {"SEND_EVENT", send_event},

    {"DISABLE_COLUMNS", disable_columns},
    {"RESET_COLUMNS", reset_columns},
    {"COLUMN_RETURN_CODE", set_column_return},

    {"SET_COLUMN_WATCH_DOG", set_column_watch_dog},
    {"CLEAR_COLUMN_WATCH_DOG", clear_column_watch_dog},
    {"DUMP_NODES", dump_nodes_handler},
    {"VERIFY_NODES", verify_nodes_handler},

    {"SET_COLUMNS_DATA", set_column_event_handler},
    {"SET_CURRENT_COLUMN_DATA", set_current_column_event_handler},
    

};



void load_one_shot_function_state_CFL(void *input)
{
  int size;
  const one_shot_function_ref *ref_ptr;
  size = reserve_one_shot_function_space_CFL();
  for (int i = 0; i < size; i++)
  {
    ref_ptr = one_shot_functions + i;
    Store_one_shot_function_CFL(input, ref_ptr->name, ref_ptr->fn);
  }
}

static bool wait_event_handler(void *handle, void *params,
                               Event_data_CFL_t *event_data);
static bool wait_time_delay(void *handle, void *params,
                            Event_data_CFL_t *event_data);
static bool true_constant_handler(void *handle, void *params,
                                  Event_data_CFL_t *event_data);
static bool false_constant_handler(void *handle, void *params,
                                   Event_data_CFL_t *event_data);

static const bool_function_ref bool_functions[] = {
    {"WAIT_EVENT_COUNT", wait_event_handler},
    {"WAIT_TIME_DELAY", wait_time_delay},
    {"TRUE", true_constant_handler},
    {"FALSE", false_constant_handler},

};

int reserve_bool_function_space_CFL()
{
  // Printf_CFL("bool function size");
  // Printf_CFL(sizeof(bool_functions)/sizeof(bool_function_ref));
  return sizeof(bool_functions) / sizeof(bool_function_ref);
}

void load_bool_functions_CFL(void *input)
{
  int size;
  const bool_function_ref *ref_ptr;
  size = reserve_bool_function_space_CFL();

  for (int i = 0; i < size; i++)
  {
    ref_ptr = bool_functions + i;
    Store_bool_function_CFL(input, ref_ptr->name, ref_ptr->fn);
  }
}

#if 0
static const if_function_ref if_functions[] = {

};

int reserve_if_function_space_CFL() {
  // Printf_CFL("if function size");
  // Printf_CFL(sizeof(if_functions)/sizeof(if_function_ref));
  return sizeof(if_functions) / sizeof(if_function_ref);
}

void load_if_functions_CFL(void *input) {
  int size;
  const if_function_ref *ref_ptr;
  size = reserve_if_function_space_CFL();
  for (int i = 0; i < size; i++) {
    ref_ptr = if_functions + i;
    Store_if_function_CFL(input, ref_ptr->name, ref_ptr->fn);
  }
}
#endif

int reserve_if_function_space_CFL()
{
  // Printf_CFL("if function size");
  // Printf_CFL(sizeof(if_functions)/sizeof(if_function_ref));
  return 0;
}
void load_if_functions_CFL(void *input)
{
  (void)input;
  return;
}

#if 0
static const try_function_ref try_functions[] = {

};

int reserve_try_function_space_CFL() {
  // Printf_CFL("if function size");
  // Printf_CFL(sizeof(if_functions)/sizeof(if_function_ref));
  return sizeof(try_functions) / sizeof(try_function_ref);
}

void load_try_functions_CFL(void *input) {
  int size;
  const try_function_ref *ref_ptr;
  size = reserve_try_function_space_CFL();
  for (int i = 0; i < size; i++) {
    ref_ptr = try_functions + i;
    Store_try_function_CFL(input, ref_ptr->name, ref_ptr->fn);
  }
}
#endif
int reserve_try_function_space_CFL()
{
  // Printf_CFL("if function size");
  // Printf_CFL(sizeof(if_functions)/sizeof(if_function_ref));
  return 0;
}
void load_try_functions_CFL(void *input)
{
  (void)input;

  return;
}

/*
**  one shot functions
**
*/
static void null_function(void *handle, void *params,
                          Event_data_CFL_t *event_data)
{
 (void)handle;
  (void)params;
  (void)event_data;
  ; // null function
}

static void log_message(void *input, void *params,
                        Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char *message;
  
  unsigned column_index;
  int column_element_number;
  message = (char *)params;

  column_index = Get_current_column_index_CFL(input);
  column_element_number = Get_current_column_element_index_CFL(input);
  Printf_CFL("Log !!!! column index %d column element %d  ---> msg: %s\n",
              column_index, column_element_number, message);
}

static void set_column_return(void *handle, void *params,
                              Event_data_CFL_t *event_data)
{

   (void)handle;
   (void)event_data;
  Set_current_column_return_code_CFL(handle, *(bool *)params);
}


static void set_current_column_event_handler(void *input, void *params,
                                Event_data_CFL_t *event_data)
{
  (void)event_data;
  Set_local_data_current_column_CFL(input, params);
}



static void set_column_event_handler(void *input, void *params,
                                             Event_data_CFL_t *event_data)
{
 (void)event_data;
 Column_data_CFL_t *column_data = (Column_data_CFL_t *)params;
 for(unsigned i= 0;i<column_data->number;i++)
 {
   Set_local_data_CFL(input,column_data->column_indexes[i], column_data->data[i] );
   
 }

}



static void send_event(void *handle, void *params,
                       Event_data_CFL_t *event_data)
{
  (void)event_data;
  Event_data_CFL_t *passed_event;
  passed_event = (Event_data_CFL_t *)params;

  Queue_event_CFL(handle, passed_event);
}

static void disable_columns(void *handle, void *params,
                            Event_data_CFL_t *event_data)
{
  (void)event_data;
  Column_index_CFL_t *column_control;

  column_control = (Column_index_CFL_t *)params;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    disable_indexes(handle, column_control->column_number,
                    column_control->column_indexes);
  }
}
static void reset_columns(void *handle, void *params,
                          Event_data_CFL_t *event_data)
{

  (void)event_data;
  Column_index_CFL_t *column_control;

  column_control = (Column_index_CFL_t *)params;
  if (event_data->event_index == EVENT_INIT_CFL)
  {
    reset_indexes(handle, column_control->column_number,
                  column_control->column_indexes);
  }
}

static void set_column_watch_dog(void *input, void *params,
                                 Event_data_CFL_t *event_data)
{
  Set_column_watch_dog_CFL(input, params, event_data);
}

static void clear_column_watch_dog(void *input, void *params,
                                   Event_data_CFL_t *event_data)
{
  Clear_column_watch_dog_CFL(input, params, event_data);
}

static void dump_nodes_handler(void *input, void *params,
                               Event_data_CFL_t *event_data)
{
  (void)event_data;
  (void)params;
  Print_column_links_CFL(input);
}

static void verify_nodes_handler(void *input, void *params,
                                 Event_data_CFL_t *event_data)
{
   (void)event_data;
  (void)params;
  Verify_column_links_CFL(input);
}


/*

************************************* Boolean functions
*************************************

*/
 
static bool wait_event_handler(void *handle, void *params,
                               Event_data_CFL_t *event_data)
{
  (void)handle;
  While_event_control_CFL_t *while_event_control;

  while_event_control = (While_event_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {

    

    while_event_control->current_count = 0;
    
    return true;
  }
  
  if (event_data->event_index == while_event_control->event_index)
  {

    while_event_control->current_count += 1;
    if (while_event_control->current_count >=
        while_event_control->number_of_events)
    {
      

      return true;
    }
  }

  return false;
}

static bool wait_time_delay(void *input, void *params,
                            Event_data_CFL_t *event_data)
{
  While_time_control_CFL_t *while_time_control;

  while_time_control = (While_time_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    while_time_control->ms_time = (Get_time_control_CFL(input))->ms_fn;
    while_time_control->ending_time =
        while_time_control->ms_time() + while_time_control->time_delay;

    return false;
  }
  if (event_data->event_index == TIMER_TICK_CFL)
  {
    if (while_time_control->ending_time <= while_time_control->ms_time())
    {
      return true;
    }
  }

  return false;
}
static bool true_constant_handler(void *handle, void *params,
                                  Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return true;
}
static bool false_constant_handler(void *handle, void *params,
                                   Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return false;
}

/*
** runtime support
**
*/
