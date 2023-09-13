#include <stddef.h>
#include <stdbool.h>

#include "CFL_private_heap.h"
#include "CFL_local_heap_functions.h"
#include "CFL_basic_defs.h"
#include "CFL_event_manager.h"
#include "CFL_inner_engine.h"

static Event_data_CFL_t init_event = {EVENT_INIT_CFL, false, NULL};
static Event_data_CFL_t term_event = {EVENT_TERMINATION_CFL, false, NULL};

static inline void disable_all_column_elements(const void *input, unsigned column_index)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;
  const Column_element_CFL_t *column_element_rom = handle->column_elements_ROM;
  unsigned char *flags = handle->column_elements_flags;

  unsigned column_element_number;
  char column_element_flag;

  for (int i = column->number - 1; i >= 0; i--)
  {
    column_element_number = column->start + i;
    column_element_flag = flags[column_element_number];
    if (((column_element_flag & COLUMN_ELEMENT_ACTIVE) != 0) &&
        ((column_element_flag & COLUMN_ELEMENT_INITIALIZED) != 0))
    {
      const Column_element_CFL_t *column_element = column_element_rom + column_element_number;
      column_element->column_function(handle, column_element->aux_fn,
                                      column_element->params, &term_event);
    }
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_INITIALIZED;
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_ACTIVE;
  }
}

static inline void disable_selected_column_elements(const void *input, unsigned short column_index,
                                                    unsigned short start_state, unsigned short end_state)
{

  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;
  const Column_element_CFL_t *column_element_rom = handle->column_elements_ROM;
  unsigned char *flags = handle->column_elements_flags;

  unsigned column_element_number;
  char column_element_flag;

  for (int i = end_state; i >= start_state; i--)
  {

    column_element_number = column->start + i;
    column_element_flag = flags[column_element_number];
    if (((column_element_flag % COLUMN_ELEMENT_ACTIVE) != 0) &&
        ((column_element_flag & COLUMN_ELEMENT_INITIALIZED) != 0))
    {
      const Column_element_CFL_t *column_element = column_element_rom + column_element_number;
      column_element->column_function(handle, column_element->aux_fn,
                                      column_element->params, &term_event);
    }
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_INITIALIZED;
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_ACTIVE;
  }
}

static inline void enable_all_column_elements(const void *input, unsigned column_index)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;
  handle->column_local_data[column_index] = NULL;

  unsigned char *flags = handle->column_elements_flags;

  for (int i = 0; i < column->number; i++)
  {
    unsigned column_element_number;

    column_element_number = column->start + i;
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_INITIALIZED;
    flags[column_element_number] = flags[column_element_number] | COLUMN_ELEMENT_ACTIVE;
  }
}

static inline void enable_column_element(const void *input, unsigned short column_index, unsigned char column_element_index)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;

  unsigned char *flags = handle->column_elements_flags;

  unsigned short column_element_number = column->start + column_element_index;
  flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_INITIALIZED;
  flags[column_element_number] = flags[column_element_number] | COLUMN_ELEMENT_ACTIVE;
}

static inline void change_column_state(const void *input, unsigned column_index)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const Column_ROM_CFL_t *column_ROM = handle->column_rom_data + column_index;

  int start_state = column_ROM->start_state;
  if (start_state < 0)
  {
    ASSERT_PRINT_INT("invalid column state machine start state", start_state);
  }
  int end_state = column_ROM->end_state;
  if (end_state < 0)
  {
    ASSERT_PRINT_INT("invalid column state machine end state", end_state);
  }
  int new_state = handle->column_state[column_index];
  disable_selected_column_elements(handle, column_index, start_state, end_state);
  enable_column_element(handle, column_index, new_state);
}

static inline bool process_column_watch_dog(const void *input,
                                            unsigned short column_index,
                                            Event_data_CFL_t *event_data)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  Watch_dog_struct_CFL_t *watch_dog_struct = handle->watch_dog_struct[column_index];
  static unsigned current_column_index = 0;

  current_column_index = column_index;

  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return false;
  }

  if ((handle->column_flags[column_index] & WATCH_DOG_ACTIVE) == 0)
  {
    return false;
  }

  unsigned timer_tick = *((unsigned *)event_data->params);

  handle->watch_dog_count[column_index] += timer_tick;
  if (handle->watch_dog_count[column_index] <= watch_dog_struct->watch_dog_trigger_count)
  {
    return false;
  }

  One_shot_function_CFL_t watch_dog_triger = watch_dog_struct->watch_dog_trigger_function;

  if (watch_dog_triger != NULL)
  {
    watch_dog_triger(handle, &current_column_index, event_data);
  }

  if (watch_dog_struct->watch_dog_termination_flag == true)
  {
    disable_column_CFL(handle, column_index);
  }
  else
  {
    reset_column_CFL(handle, column_index);
  }
  return true;

  handle->watch_dog_count[column_index] = 0;

  return true;
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
    return;
  default:

    ASSERT_PRINT_INT("invalid return code", return_code);
  }
}

static inline int process_column_element(const Handle_CFL_t *handle,
                                         unsigned short column_element_index,
                                         Event_data_CFL_t *event_data)
{

  const Column_element_CFL_t *column_element = handle->column_elements_ROM + column_element_index;
  if ((handle->column_elements_flags[column_element_index] & COLUMN_ELEMENT_INITIALIZED) == 0)
  {

    column_element->column_function(handle, column_element->aux_fn,
                                    column_element->params, &init_event);
    handle->column_elements_flags[column_element_index] =
        handle->column_elements_flags[column_element_index] | COLUMN_ELEMENT_INITIALIZED;
  }

  return column_element->column_function(handle, column_element->aux_fn,
                                         column_element->params, event_data);
}

static inline bool inner_process_column(const Handle_CFL_t *handle,
                                        unsigned short column_index,
                                        Event_data_CFL_t *event_data)
{

  const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;

  if ((handle->column_flags[column_index] & COLUMN_ACTIVE) == 0)
  {
    return true;
  }

  if ((event_data->event_index == TIMER_TICK_CFL) && ((handle->column_flags[column_index] & WATCH_DOG_ACTIVE) != 0))
  {
    if (process_column_watch_dog(handle, column_index, event_data) == true)
    {

      return true;
    }
  }

  unsigned column_element_count = 0;

  for (unsigned i = 0; i < column->number; i++)
  {

    if ((handle->column_elements_flags[column->start + i] & COLUMN_ELEMENT_ACTIVE) == 0)
    {
      continue;
    }

    column_element_count += 1;
    handle->engine_control->current_column_element_index = i;

    int return_code = process_column_element(handle, column->start + i, event_data);

    validate_return_code(return_code);

    if (return_code == ENGINE_TERMINATE_CFL)
    {

      return false;
    }
    if (return_code == TERMINATE_CFL)
    {
      //printf("terminate column %d\n", column->id);
      disable_column_CFL(handle, column->id);

      return true;
    }
    if (return_code == RESET_CFL)
    {

      reset_column_CFL(handle, column->id);
      return true;
    }
    if (return_code == HALT_CFL)
    {

      return true;
    }
    if (return_code == DISABLE_CFL)
    {
      handle->column_elements_flags[column->start + i] &= ~(COLUMN_ELEMENT_ACTIVE);
    }
  }
  if (column_element_count == 0)
  {

    // column has no active column elements
    disable_column_CFL(handle, column->id);
  }

  return true;
}

static inline bool process_column_named_events(const Handle_CFL_t *handle,
                                               unsigned short column_index,
                                               Event_data_CFL_t *event_data)
{
  (void)event_data;
  bool result;
  Event_data_CFL_t *temp;
  const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;

  if (column->queue_number < 0)
  {

    return true;
  }
  
  if (is_queue_empty_CFL(handle, column->queue_number) == true)
  {
    return true;
  }

  while (true)
  {
   
    if (is_queue_empty_CFL(handle, column->queue_number) == true)
    {

      return true;
    }
    
    temp = peak_event_CFL(handle, column->queue_number);

    result = inner_process_column(handle, column_index, temp);

    
    dequeue_event_CFL(handle, column->queue_number);
   
    
    if (result == false)
    {
      return false; // engine shut down
    }
   
    return true; // hack to process only one event

  }
  return true; // should never get here
}

/*
**
** Public functions
**
*/

static bool test_column_count(const void *input){
  
   for(unsigned i=0;i<((Handle_CFL_t *)input)->number_of_columns;i++){
      if(((Handle_CFL_t *)input)->column_flags[i] & COLUMN_ACTIVE){
         return true;
      }
   }
   
   return false;
}

bool process_single_sweep_CFL(const void *input,
                              Event_data_CFL_t *event_data)
{

  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;

  for (unsigned short i = 0; i < handle->number_of_columns; i++)
  {

    const Column_ROM_CFL_t *column = handle->column_rom_data + i;

    if ((handle->column_flags[i] & COLUMN_ACTIVE) == 0)
    {
      //printf("column flag %d %d not active\n", i, handle->column_flags[i]);
      continue;
    }
   

    handle->engine_control->current_column_index = column->id;

    bool result = true;
    if (column->queue_number >= 0)
    {

      result = process_column_named_events(handle, i, event_data);
    }
    if (result == true)
    {

      handle->engine_control->ref_event_data.event_index = event_data->event_index;
      handle->engine_control->ref_event_data.params = event_data->params;
      handle->engine_control->ref_event_data.malloc_flag = event_data->malloc_flag;
      result = inner_process_column(handle, i, event_data);
      event_data->event_index = handle->engine_control->ref_event_data.event_index;
      event_data->malloc_flag = handle->engine_control->ref_event_data.malloc_flag;
      event_data->params = handle->engine_control->ref_event_data.params;
    }
    if (result == false)
    {
      disable_all_columns_CFL(handle);
      return false; // engine shut down
    }
  }
  
  return test_column_count(input);

}

void disable_all_columns_CFL(const void *input)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  unsigned column_number = handle->number_of_columns;
  for (unsigned i = 0; i < column_number; i++)
  {

    disable_column_CFL(handle, i);
  }
}

void enable_column_CFL(const void *input, unsigned column_index)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;

  enable_all_column_elements(input, column_index);
  handle->column_flags[column_index] = 0;
  handle->column_flags[column_index] = handle->column_flags[column_index] | COLUMN_ACTIVE;
}

void reset_column_CFL(const void *input, unsigned column_index)
{
  disable_all_column_elements(input, column_index);
  enable_column_CFL(input, column_index);
}

void disable_column_CFL(const void *input, unsigned column_index)
{

  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  disable_all_column_elements(input, column_index);
  handle->column_flags[column_index] =handle->column_flags[column_index] & COLUMN_SUCCESS;
  const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;
  if (column->queue_number >= 0)
  {
    reset_event_queue_CFL(handle, column->queue_number);
  }
}
bool column_state_CFL(const void *input, unsigned column_index)
{

  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if (handle->column_flags[column_index] & COLUMN_ACTIVE)
  {
    return true;
  }
  return false;
}

bool join_columns_CFL(const void *input, const unsigned short number_of_columns, const unsigned short *column_list)
{

  for (unsigned short i = 0; i < number_of_columns; i++)
  {
    if (column_state_CFL(input, column_list[i]) == true)
    {
      return false;
    }
  }
  return true;
}

void initialize_columns_CFL(const void *input)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const Column_ROM_CFL_t *column = ((Handle_CFL_t *)handle)->column_rom_data;

  for (unsigned i = 0; i < handle->number_of_columns; i++)
  {
#if 0
    const Column_ROM_CFL_t *wcol = column + i;

    printf("auto start %d %d %d %d %d %d %d %d %d  \n",i,wcol->queue_number,
                                     wcol->auto_start,
                                     wcol->id,
                                     wcol->number,
                                     wcol->start,
                                     wcol->start_state,
                                     wcol->end_state,
                                     wcol->watch_dog_id);
#endif

    if (column[i].auto_start == true)
    {

      handle->column_flags[i] = COLUMN_ACTIVE;

      reset_column_CFL(handle, i);
    }
    else
    {

      handle->column_flags[i] = 0;
    }
  }
}

void set_current_column_return_code_CFL(const void *input, bool state)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  unsigned column_index = handle->engine_control->current_column_index;
  if (state == true)
  {
    handle->column_flags[column_index] = handle->column_flags[column_index] | COLUMN_SUCCESS;
  }
  else
  {
    handle->column_flags[column_index] = handle->column_flags[column_index] & ~COLUMN_SUCCESS;
  }
 
}

bool get_current_column_return_code_CFL(const void *input,unsigned short column_index)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  
  if (handle->column_flags[column_index] & COLUMN_SUCCESS)
  {
    return true;
  }
  return false;
}

unsigned get_current_column_element_index_CFL(const void *input)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  return (unsigned)handle->engine_control->current_column_element_index;
}

unsigned short get_current_column_index_CFL(const void *input)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  return (unsigned)handle->engine_control->current_column_index;
}

void change_local_column_state_CFL(const void *input, unsigned char new_state)
{

  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;

  unsigned column_index = handle->engine_control->current_column_index;

  const Column_ROM_CFL_t *column_ROM = handle->column_rom_data + column_index;
  if (column_ROM->start_state < 0)
  {
    ASSERT_PRINT("Column is not a column state machine", "");
  }
  unsigned state_number = column_ROM->end_state - column_ROM->start_state;
  if (new_state > state_number)
  {

    ASSERT_PRINT_INT("New state is out of range", new_state);
  }
  else
  {

    handle->column_state[column_index] = column_ROM->start_state + new_state;
    change_column_state(handle, column_index);
  }
}

void attach_watch_dog_handler_CFL(const void *input, const Watch_dog_struct_CFL_t *watch_dog_struct)
{
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  // find current column
  Engine_control_CFL_t *engine_control = handle->engine_control;
  unsigned column_index = engine_control->current_column_index;

  if ((handle->column_flags[column_index] & WATCH_DOG_ACTIVE) != 0)
  {
    ASSERT_PRINT_INT("column has watch dog active", column_index);
  }
  handle->column_flags[column_index] = handle->column_flags[column_index] | WATCH_DOG_ACTIVE;

  handle->watch_dog_struct[column_index] = (Watch_dog_struct_CFL_t *)watch_dog_struct;
}

void detach_watch_dog_handler_CFL(const void *input)
{
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Engine_control_CFL_t *engine_control = handle->engine_control;
  unsigned column_index = engine_control->current_column_index;
  handle->column_flags[column_index] = handle->column_flags[column_index] & ~WATCH_DOG_ACTIVE;

  handle->watch_dog_struct[column_index] = NULL;
  handle->watch_dog_count[column_index] = 0;
}

void store_local_column_data(const void *input, unsigned short column_id, void *column_data)
{
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  if (column_id >= handle->number_of_columns)
  {
    ASSERT_PRINT_INT("invalid column id", column_id);
  }

  handle->column_local_data[column_id] = column_data;
}

// current column id is used to retrieve the data
void *retrieve_local_column_data(const void *input)
{
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Engine_control_CFL_t *engine_control = handle->engine_control;
  unsigned column_index = engine_control->current_column_index;

  return handle->column_local_data[column_index];
}
