#include "Cfl_definitions.h"
#include "Cfl_element_storeage.h"
#include "Cfl_local_heap_functions.h"
#include "Cfl_user_functions.h"

#include "Cfl_column_element.h"
#include "Cfl_functions.h"
// Node_control_CFL_t node_control;
// Node_cell_CFL_t* node_cell;
static void mark_columns(int number, Column_CFL_t *pointer);
static short find_column_index(Column_control_CFL_t *column_control,
                               const char *column_name);


short Find_column_index_CFL(void *input, const char *column_name)
{

  Handle_CFL_t *handle;
  Column_control_CFL_t *column_control;

  handle = (Handle_CFL_t *)input;
  column_control = (Column_control_CFL_t *)handle->columns;
  return find_column_index(column_control, column_name);
}

Column_CFL_t *find_column_entry_CFL(Handle_CFL_t *handle, unsigned index)
{
  Column_control_CFL_t *column_control;
  column_control = (Column_control_CFL_t *)handle->columns;
  if (index >= column_control->max_number)
  {
    ASSERT_PRINT(__func__, "invalid column entry");
  }
  return column_control->column + index;
}

void allocate_columns_CFL(Handle_CFL_t *handle, int number_of_columns)
{
  Column_control_CFL_t *column_control;
  Column_CFL_t *column;

  column_control =
      (Column_control_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Column_control_CFL_t));

  column_control->max_number = number_of_columns;
  column_control->current_number = 0;
  handle->columns = column_control;
  if (number_of_columns == 0)
  {
    return;
  }
  // column allocation
  column = (Column_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Column_CFL_t) *
                                                                number_of_columns);
  column_control->column = column;

  column_control->node_control.size = number_of_columns;
  mark_columns(number_of_columns, column);
  handle->ref_column = NULL;

  // do hash cells for name lookup

  column_control->column_names =
      contruct_hash_cell_control_CFL(handle, number_of_columns);

  // do node cells for priority queue
  column_control->node_cell = (Node_cell_CFL_t *)Allocate_once_malloc_CFL(
      handle, sizeof(Node_cell_CFL_t) * number_of_columns);

  column_control->node_control.active_array =
      (unsigned short *)Allocate_once_malloc_CFL(handle, sizeof(unsigned short) *
                                                             number_of_columns);

  PRH_disable_all_nodes_CFL(&column_control->node_control, number_of_columns,
                            column_control->node_cell);
}

void reserve_column_names_CFL(void *input, int number_of_columns,
                              const char **column_names)
{
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  int index;
  const char *column_name;
  Column_control_CFL_t *column_control;
  Column_CFL_t *column;
  column_control = (Column_control_CFL_t *)handle->columns;

  Verify_column_links_CFL(input);
  for (int i = 0; i < number_of_columns; i++)
  {
    column_name = *column_names++;
    Verify_column_links_CFL(input);

    if (column_control->current_number >= column_control->max_number)
    {
      ASSERT_PRINT("too many columns", column_name);
    }

    index = Find_Name_CFL(column_control->column_names, column_name);

    Verify_column_links_CFL(input);

    if (index >= 0)
    {
      ASSERT_PRINT("duplicate column name", column_name);
    }

    index = Store_Name_CFL(column_control->column_names, column_name);

    Verify_column_links_CFL(input);

    column = column_control->column + index;
    column->id = index;
    column->defined = false;

    Verify_column_links_CFL(input);
    column_control->current_number += 1;
  }
}

void Asm_start_column_event_queue_CFL(void *input, const char *column_name, bool start_flag, const char *named_event_queue)
{
  unsigned index;
  Handle_CFL_t *handle;
  Column_CFL_t *column;
  handle = (Handle_CFL_t *)input;

  Asm_start_column_CFL(input, column_name, start_flag);
  column = (Column_CFL_t *)handle->ref_column;
  index = Get_named_event_queue_index_CFL(input, named_event_queue);
  column->named_event_queue = Get_named_event_queue_CFL(input, index);
}

void Asm_start_column_CFL(void *input, const char *column_name,
                          bool start_flag)
{
  Handle_CFL_t *handle;
  Column_control_CFL_t *column_control;
  Column_CFL_t *column;
  int column_index;

  handle = (Handle_CFL_t *)input;
  if (handle->ref_column != NULL)
  {
    ASSERT_PRINT(__func__, "column definition is already in progress");
  }

  Verify_column_links_CFL(input);
  column_control = (Column_control_CFL_t *)handle->columns;

  column_index = find_column_index(column_control, column_name);

  column = column_control->column + column_index;
  if (column->defined == true)
  {
    ASSERT_PRINT("column name previous been defined", column_name);
  }

  handle->ref_column = column;
  column->defined = true;
  column->auto_start = start_flag;
  column->active = false;
  column->named_event_queue = NULL;

  column->column_element_number = 0;
  column->starting_column_element = NULL;
  column->watch_dog_control = NULL;
  column->fn_success = false;
  column->column_state_machine = false;
  column->start_state = 0;
  column->end_state = 0;

  column->id = column_index;
  Verify_column_links_CFL(input);
}

void Asm_end_column_CFL(void *input)
{

  Handle_CFL_t *handle;
  handle = (Handle_CFL_t *)input;
  Column_CFL_t *column = (Column_CFL_t *)handle->ref_column;
  if (column->column_state_machine == true)
  {
    if (column->start_state <= column->end_state)
      ASSERT_PRINT("column state machine is not complete","");

  }
  handle->ref_column = NULL;
}

void Asm_store_column_element_CFL(void *input, const char *name,
                                  void *aux_fun, void *params)
{
  Handle_CFL_t *handle;
  Column_CFL_t *column;
  Column_element_CFL_t *column_element;
  Column_function_CFL_t fn;
  handle = (Handle_CFL_t *)input;
  fn = Get_column_function_CFL(handle, name);

  column = (Column_CFL_t *)handle->ref_column;
  if (column == NULL)
  {
    ASSERT_PRINT(__func__, "no active column generation");
  }

  column_element = allocate_column_element_CFL(handle);
  if (column->column_element_number == 0)
  {
    column->column_element_number = 1;
    column->starting_column_element = column_element;
  }
  else
  {
    column->column_element_number += 1;
  }
  column_element->active = false;
  column_element->initialized = false;
  column_element->fn = fn;
  column_element->aux_function = aux_fun;
  column_element->params = params;
}

void Asm_store_column_starting_state_CFL(void *input)
{
  Handle_CFL_t *handle;
  Column_CFL_t *column;
  handle = (Handle_CFL_t *)input;

  column = (Column_CFL_t *)handle->ref_column;
  if (column == NULL)
  {
    ASSERT_PRINT(__func__, "no active column generation");
  }
  column->column_state_machine = true;
  column->start_state = column->column_element_number;
}

void Asm_store_column_ending_state_CLF(void *input)
{
  Handle_CFL_t *handle;
  Column_CFL_t *column;
  handle = (Handle_CFL_t *)input;

  column = (Column_CFL_t *)handle->ref_column;
  if (column == NULL)
  {
    ASSERT_PRINT(__func__, "no active column generation");
  }

  column->end_state = column->column_element_number;
}

void Asm_store_column_element_direct_CFL(void *input, Column_function_CFL_t fn,
                                         void *aux_fun, void *params)
{
  Handle_CFL_t *handle;
  Column_CFL_t *column;
  Column_element_CFL_t *column_element;

  handle = (Handle_CFL_t *)input;

  column = (Column_CFL_t *)handle->ref_column;
  if (column == NULL)
  {
    ASSERT_PRINT(__func__, "no active column generation");
  }

  column_element = allocate_column_element_CFL(handle);
  if (column->column_element_number == 0)
  {
    column->column_element_number = 1;
    column->starting_column_element = column_element;
  }
  else
  {
    column->column_element_number += 1;
  }
  column_element->active = false;
  column_element->initialized = false;
  column_element->fn = fn;
  column_element->aux_function = aux_fun;
  column_element->params = params;
}

static void mark_columns(int number, Column_CFL_t *pointer)
{

  for (int i = 0; i < number; i++)
  {
    pointer->id = i;
    pointer->defined = false;
    pointer->active = false;
    pointer++;
  }
}

static short find_column_index(Column_control_CFL_t *column_control,
                               const char *column_name)
{
  short index;
  index = Find_Name_CFL(column_control->column_names, column_name);
  if (index < 0)
  {

    ASSERT_PRINT("column not found", column_name);
  }
  if (index >= (int)column_control->max_number)
  {
    ASSERT_PRINT(__func__, "bad index");
  }

  return index;
}
