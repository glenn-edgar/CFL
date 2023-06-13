
#include "Cfl_inner_engine.h"
#include "Cfl_priority_queue.h"
#include "Cfl_user_functions.h"
#include "Cfl_event_manager.h"

static Event_data_CFL_t init_event = {EVENT_INIT_CFL, 0, NULL};
static Event_data_CFL_t term_event = {EVENT_TERMINATION_CFL, 0, NULL};

static inline void set_ref_engine_event(Engine_control_CFL_t *engine_control, Event_data_CFL_t *event_data)
{
  engine_control->ref_event_data = *event_data;
}
static inline void restore_ref_engine_event(Engine_control_CFL_t *engine_control, Event_data_CFL_t *event_data)
{
  *event_data = engine_control->ref_event_data;
}

static inline void change_column_state(Handle_CFL_t *handle,Column_CFL_t *column){

   (void)handle;
   

   Column_element_CFL_t *column_element;
   
   if(column->column_state_machine != true){
     ASSERT_PRINT_INT("column state machine not enabled",column->id);
   }
   
   
   for(unsigned i = column->start_state; i < column->end_state; i++){
    column_element = column->starting_column_element + i;
    
    
    column_element->active = false;
    column_element->initialized = false;
   }
   
    column_element = column->starting_column_element + column->new_state;
    column_element->active = true;
    column_element->initialized = false;
   
}

static  inline void send_terminal_event(Handle_CFL_t *handle,
                                       Column_control_CFL_t *column_control,
                                       unsigned index)
{

  Column_CFL_t *column;
  Column_element_CFL_t *column_element;
  column = (Column_CFL_t *)column_control->column + index;

  for (int i = column->column_element_number - 1; i >= 0; i--)
  {
    column_element = column->starting_column_element + i;

    if ((column_element->active == true) &&
        (column_element->initialized == true))
    {

      column_element->fn(handle, column_element->aux_function,
                         column_element->params, &term_event);
    }
    column_element->active = false;
    column_element->initialized = false;
  }
}

static inline void disable_column_low(Handle_CFL_t *handle,
                                      Column_control_CFL_t *column_control,
                                      unsigned index)
{
  Column_CFL_t *column;
  column = (Column_CFL_t *)column_control->column + index;
  column->local_event = NULL;
  if (column->active == false)
  {
    return;
  }

  PRH_dequeue_node_CFL(&column_control->node_control, index);

  send_terminal_event(handle, column_control, index);

  column->active = false;
}

static  inline void enable_column_low(Handle_CFL_t *handle,
                                     Column_control_CFL_t *column_control,
                                     unsigned index)
{
  (void)handle;
  Column_CFL_t *column;
  Column_element_CFL_t *column_element;
  column = column_control->column + index;

  for (int i = 0; i < column->column_element_number; i++)
  {

    column_element = column->starting_column_element + i;
    column_element->active = true;
    column_element->initialized = false;
    column_element->id = i;
  }
  column->reset_state = true;

  if (column->active == true)
  {
    return; // this case is an already active column being reset
  }
  
  PRH_enqueue_node_CFL(&column_control->node_control,
                       column_control->node_cell + index);
  column->active = true;
 
}
static inline Column_CFL_t *find_column_entry_CFL(Handle_CFL_t *handle,
                                                  unsigned column_index)
{

  Column_control_CFL_t *column_control;
  column_control = (Column_control_CFL_t *)handle->columns;

  if (column_index > column_control->max_number)
  {
    ASSERT_PRINT(__func__, "invalid column element");
  }
  return column_control->column + column_index;
}

static inline bool process_column_watch_dog(Handle_CFL_t *handle,
                                            Column_CFL_t *column,
                                            Event_data_CFL_t *event_data)
{
  Column_watch_dog_CFL_t *watch_dog;
  watch_dog = column->watch_dog_control;
  watch_dog->current_count += event_data->event_data;

  if (watch_dog->current_count >= watch_dog->trigger_count)
  {

    if (watch_dog->termination_flag == true)
    {

      Disable_column_CFL(handle, column->id);
    }
    else
    {

      Reset_column_CFL(handle, column->id);
    }
    watch_dog->column_index = column->id;
    watch_dog->trigger_function(handle, watch_dog, event_data);
    column->watch_dog_control = NULL;

    return true;
  }

  return false;
}

static inline void validate_return_code(int return_code)
{

  switch (return_code)
  {
  case CONTINUE_CFL:
  case DISABLE_CFL:
  case HALT_CFL:
  case RESET_CFL:
  case TERMINATE_CFL:
  case ENGINE_TERMINATE_CFL:
  case COLUMN_STATE_CHANGE_CFL:

    return;
  default:

    ASSERT_PRINT_INT("invalid return code", return_code);
  }
}

static inline int process_column_element(Handle_CFL_t *handle,
                                         Column_element_CFL_t *column_element,
                                         Event_data_CFL_t *event_data)
{

  if (column_element->initialized == false)
  {

    column_element->fn(handle, column_element->aux_function,
                       column_element->params, &init_event);
    column_element->initialized = true;
  }
   return column_element->fn(handle, column_element->aux_function,
                            column_element->params, event_data);
}

static inline bool inner_process_column(Handle_CFL_t *handle,
                                        Engine_control_CFL_t *engine_control,
                                        Column_control_CFL_t *column_control,
                                        Column_CFL_t *column,
                                        Event_data_CFL_t *event_data)
{

  (void)column_control;
  Column_element_CFL_t *column_element;
  unsigned column_element_count;
  unsigned return_code;

  if ((event_data->event_index == TIMER_TICK_CFL) &&
      (column->watch_dog_control != NULL))
  {
    if (process_column_watch_dog(handle, column, event_data) == true)
    {

      return true;
    }
  }

  column_element = column->starting_column_element;
  column_element_count = 0;
  for (unsigned i = 0; i < column->column_element_number; i++)
  {
     
    column_element = column->starting_column_element + i;

    if (column_element->active == false)
    {
      continue;
    }
    column_element_count += 1;
    engine_control->current_column_element_index = i;
    engine_control->current_column_element = column_element;
    
    return_code = process_column_element(handle, column_element, event_data);

    validate_return_code(return_code);
    // CONTINUE_CFL is ignored so for loop continues
    // restoring reference events

    if (return_code == COLUMN_STATE_CHANGE_CFL)
    {
      column_element->active = false;
      column_element->initialized = false;
      column_element->fn(handle, column_element->aux_function,
                         column_element->params, &term_event);
      change_column_state(handle,column);
      return true;  // terminates column processing
    }

    if (return_code == ENGINE_TERMINATE_CFL)
    {
      return false;
    }
    if (return_code == TERMINATE_CFL)
    {
      Disable_column_CFL(handle, column->id);
      column->reset_state = true;
      return true;
    }
    if (return_code == RESET_CFL)
    {
      column->reset_state = true;
      Reset_column_CFL(handle, column->id);
      return true;
    }
    if (return_code == HALT_CFL)
    {

      return true;
    }
    if (return_code == DISABLE_CFL)
    {

      column_element->active = false;
      column_element->initialized = false;
    }
  }
  if (column_element_count == 0)
  {
    // column has no active column elements
    Disable_column_CFL(handle, column->id);
  }

  return true;
}

static inline bool  process_column_named_events(Handle_CFL_t *handle,
                                               Engine_control_CFL_t *engine_control,
                                               Column_control_CFL_t *column_control,
                                               Column_CFL_t *column,
                                               Event_data_CFL_t *event_data)
{

  bool result;
  Event_data_CFL_t *temp;

  if (column->named_event_queue == NULL)
  {
    return true;
  }

  

  if (is_queue_empty_CFL(column->named_event_queue) == true)
  {
    return true;
  }

  
  while (true)
  {

    if (is_queue_empty_CFL(column->named_event_queue) == true)
    {

      return true;
    }
    

    temp = peak_event_CFL(column->named_event_queue);

    engine_control->ref_event_data.event_index = event_data->event_index;
    engine_control->ref_event_data.event_data = event_data->event_data;
    engine_control->ref_event_data.params = event_data->params;

    event_data->event_index = temp->event_index;
    event_data->event_data = temp->event_data;
    event_data->params = temp->params;

    result = inner_process_column(handle, engine_control, column_control, column, event_data);
    if (result == false)
    {
      return false;
    }

    event_data->event_index = engine_control->ref_event_data.event_index;
    event_data->event_data = engine_control->ref_event_data.event_data;
    event_data->params = engine_control->ref_event_data.params;

    if (is_queue_empty_CFL(column->named_event_queue) == false)
    {
      dequeue_event_CFL(column->named_event_queue);
    }
    
  }
  return true; // should never get here
}

/*
**
** Public functions
**
*/

bool process_single_sweep_CFL(Handle_CFL_t *handle,
                              Event_data_CFL_t *event_data)
{

  Column_control_CFL_t *column_control;
  Column_CFL_t *column;
  Engine_control_CFL_t *engine_control;
  bool result;
  // Node_cell_CFL_t* working_ptr;
  // short node_cell_index;
  // short next_node_index;
  // short previous_backward_link;
  unsigned short node_number;
  unsigned short *node_list;

  column_control = (Column_control_CFL_t *)handle->columns;

  engine_control = (Engine_control_CFL_t *)handle->engine_control;

  node_list =
      PRH_generate_index_list(&column_control->node_control, &node_number);

  if (node_number == 0)
  {

    return false; // no active columns -- engine is empty
  }
  for (unsigned short i = 0; i < node_number; i++)
  {

    column = column_control->column + (*node_list++);
    if (column->active == false)
    {
      // column could have been disabled by a previous column
      continue;
    }

    

    engine_control->current_column = column;
    engine_control->current_column_index = column->id;

    result = true;
    if (column->named_queue_active == true)
    {

      result = process_column_named_events(handle, engine_control, column_control, column, event_data);
    }
    if (result == true)
    {

      result = inner_process_column(handle, engine_control, column_control, column, event_data);
    }
    if (result == false)
    {
      Disable_all_columns_CFL(handle);
      return false; // engine shut down
    }
  }
  return true;
}

#if 0
void Set_ref_event_CFL(void *input, unsigned ref_event)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;
  

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;

  set_valid_event(engine_control->current_column,engine_control->current_column_element_index, ref_event);
                  
}

void Clear_ref_event_CFL(void *input)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;

  clear_valid_event(engine_control->current_column,
                    engine_control->current_column_element_index);
}
#endif

void Disable_all_columns_CFL(void *input)
{
  Column_control_CFL_t *column_control;
  Handle_CFL_t *handle;
  Node_cell_CFL_t *working_ptr;
  short node_cell_index;
  handle = (Handle_CFL_t *)input;
  column_control = (Column_control_CFL_t *)handle->columns;
  node_cell_index = PRH_return_last_node_CFL(&column_control->node_control);

  while (node_cell_index != -1)
  {
    working_ptr =
        PRH_return_node_CFL(&column_control->node_control, node_cell_index);
    Disable_column_CFL(handle, node_cell_index);
    node_cell_index = PRH_return_previous_node_CFL(working_ptr);
  }
}

bool Get_column_index_return_code_CFL(void *input, unsigned index)
{
  Handle_CFL_t *handle;
  Column_CFL_t *column;

  handle = (Handle_CFL_t *)input;

  column = find_column_entry_CFL(handle, index);
  return column->fn_success;
}

void Reset_column_CFL(void *input, unsigned column_index)
{
  Handle_CFL_t *handle;

  Column_control_CFL_t *column_control;
  handle = (Handle_CFL_t *)input;
  column_control = (Column_control_CFL_t *)handle->columns;

  send_terminal_event(handle, column_control, column_index);
  enable_column_low(handle, column_control, column_index);
}

void Enable_column_CFL(void *input, unsigned column_index)
{
  Handle_CFL_t *handle;

  Column_control_CFL_t *column_control;
  handle = (Handle_CFL_t *)input;
  column_control = (Column_control_CFL_t *)handle->columns;

  enable_column_low(handle, column_control, column_index);
}

void Disable_column_CFL(void *input, unsigned column_index)
{

  Handle_CFL_t *handle;
  Column_control_CFL_t *column_control;
  handle = (Handle_CFL_t *)input;

  column_control = (Column_control_CFL_t *)handle->columns;
  disable_column_low(handle, column_control, column_index);
}
bool Column_State_CFL(void *input, unsigned column_index)
{

  Column_CFL_t *column;
  Handle_CFL_t *handle;
  handle = (Handle_CFL_t *)input;
  column = find_column_entry_CFL(handle, column_index);
  return column->active;
}

bool Join_columns_CFL(void *input, unsigned short number_of_columns, unsigned short *column_list)
{

  for (unsigned short i = 0; i < number_of_columns; i++)
  {
    if (Column_State_CFL(input, column_list[i]) == true)
    {
      return false;
    }
  }
  return true;
}

void Print_column_links_CFL(void *input)
{

  Handle_CFL_t *handle;
  Column_control_CFL_t *column_control;

  handle = (Handle_CFL_t *)input;
  column_control = (Column_control_CFL_t *)handle->columns;
  PRH_print_forward_nodes_CFL(&column_control->node_control);
}

void Verify_column_links_CFL(void *input)
{

  Handle_CFL_t *handle;
  Column_control_CFL_t *column_control;

  handle = (Handle_CFL_t *)input;
  column_control = (Column_control_CFL_t *)handle->columns;
  PRH_verify_nodes_CFL(&column_control->node_control);
}

void initialize_columns_CFL(Handle_CFL_t *handle)
{

  Column_control_CFL_t *column_control;
  Column_CFL_t *column;

  column_control = (Column_control_CFL_t *)handle->columns;
  column = column_control->column;

  for (unsigned i = 0; i < column_control->current_number; i++)
  {

    if (column->auto_start == true)
    {
      Enable_column_CFL(handle, column->id);
    }
    else
    {
      column->local_event = NULL;
      column->active = false;
    }
    column++;
  }
}

void Set_local_event_current_column_CFL(void *input, Event_data_CFL_t *data)
{

  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;

  Set_local_event_CFL(input, engine_control->current_column_index, data);
}

Event_data_CFL_t *Get_current_column_local_event_CFL(void *input)
{

  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;

  return Get_local_event_CFL(input, engine_control->current_column_index);
}

void Set_local_event_CFL(void *input, unsigned column_index,
                         Event_data_CFL_t *data)
{

  Column_CFL_t *column;
  Handle_CFL_t *handle;

  handle = (Handle_CFL_t *)input;

  column = find_column_entry_CFL(handle, column_index);

  column->local_event = data;
}

Event_data_CFL_t *Get_local_event_CFL(void *input, unsigned column_index)
{

  Column_CFL_t *column;
  Handle_CFL_t *handle;

  handle = (Handle_CFL_t *)input;
  column = find_column_entry_CFL(handle, column_index);

  return column->local_event;
}

void Set_current_column_return_code_CFL(void *input, bool state)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;
  engine_control->current_column->fn_success = state;
}

bool Get_current_column_return_code_CFL(void *input)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;
  return engine_control->current_column->fn_success;
}




unsigned Get_current_column_element_index_CFL(void *input)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;
  return (unsigned)engine_control->current_column_element_index;
}

unsigned Get_current_column_index_CFL(void *input)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;
  return (unsigned)engine_control->current_column->id;
}

void Set_column_watch_dog_CFL(void *input, void *params,
                              Event_data_CFL_t *event_data)
{
  (void)event_data;
  Column_watch_dog_CFL_t *column_watchdog;
  Engine_control_CFL_t *engine_control;
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  column_watchdog = (Column_watch_dog_CFL_t *)params;
  column_watchdog->current_count = 0;

  engine_control = (Engine_control_CFL_t *)handle->engine_control;
  engine_control->current_column->watch_dog_control = column_watchdog;
}

void Clear_column_watch_dog_CFL(void *input, void *params,
                                Event_data_CFL_t *event_data)
{
  (void)event_data;
  (void)params;
  
  
  Engine_control_CFL_t *engine_control;
  Handle_CFL_t* handle = (Handle_CFL_t *)input;

  engine_control = (Engine_control_CFL_t *)handle->engine_control;
  engine_control->current_column->watch_dog_control = NULL;
}


void Change_local_column_state_CFL(void *input, unsigned short new_state){
 Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;
  handle = (Handle_CFL_t *)input;

  engine_control = (Engine_control_CFL_t *)handle->engine_control;
  Column_CFL_t *column = engine_control->current_column;
  if(column->column_state_machine != true){
    ASSERT_PRINT("Column is not a column state machine","");
  }
  unsigned state_number = column->end_state - column->start_state;
  if(new_state >= state_number){
    ASSERT_PRINT_INT("New state is out of range",new_state);
  }
  else{
    
    column->new_state = column->start_state + new_state;
  }
}
