

#include "Cfl_user_functions.h"

#include "Cfl_core_functions.h"

static inline bool validate_event(int event_index, unsigned short event_number, short *event_indexes);

static void enable_indexes(void *input, unsigned column_number,
                           unsigned short *column_indexes);
static void disable_indexes(void *input, unsigned column_number,
                            unsigned short *column_indexes);
static unsigned number_Of_active_columns(void *input, unsigned column_number,
                                         unsigned short *column_indexes);
static void enable_if_indexes(void *input, If_control_CFL_t *if_control);



/*
   default column functions
*/
static int return_condition_code(void *handle, void *aux_fn,
                                 void *params, Event_data_CFL_t *event_data);
static int one_shot_handler(void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);
static int bidirectional_one_shot_handler(void *handle, void *aux_fn,
                                          void *params,
                                          Event_data_CFL_t *event_data);

static int while_handler(void *handle, void *aux_fn, void *params,
                         Event_data_CFL_t *event_data);

static int verify_handler(void *handle, void *aux_fn, void *params,
                          Event_data_CFL_t *event_data);

static int enable_columns(void *handle, void *aux_fn, void *params,
                          Event_data_CFL_t *event_data);
static int join_handler(void *handle, void *aux_fn, void *params,
                        Event_data_CFL_t *event_data);
static int if_column_handler(void *handle, void *aux_fn, void *params,
                             Event_data_CFL_t *event_data);
static int try_column_handler(void *handle, void *aux_fn, void *params,
                              Event_data_CFL_t *event_data);
static int for_column_handler(void *handle, void *aux_fn, void *params,
                              Event_data_CFL_t *event_data);
static int while_column_handler(void *handle, void *aux_fn, void *params,
                                Event_data_CFL_t *event_data);
static int do_while_column_handler(void *handle, void *aux_fn,
                                   void *params, Event_data_CFL_t *event_data);
static int event_function_handler(void *handle, void *aux_fn,
                                  void *params, Event_data_CFL_t *event_data);

static int enable_join_fn(void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

static const core_function_ref core_functions[] = {
    {"RETURN_CONDITION_CODE", return_condition_code},
    {"ONE_SHOT", one_shot_handler},
    {"BID_ONE_SHOT", bidirectional_one_shot_handler},

    {"WHILE", while_handler},
    {"VERIFY", verify_handler},
    {"JOIN_COLUMNS", join_handler},
    {"ENABLE_COLUMNS", enable_columns},
    {"IF_COLUMNS", if_column_handler},
    {"TRY_COLUMN", try_column_handler},
    {"FOR_COLUMN", for_column_handler},
    {"WHILE_COLUMN", while_column_handler},
    {"DO_WHILE_COLUMN", do_while_column_handler},
    {"EVENT_HANDLER_FN", event_function_handler},
    {"ENABLE_JOIN", enable_join_fn},

};

int reserve_column_function_space_CFL()
{
  return sizeof(core_functions) / sizeof(core_function_ref);
}

void load_column_functions_CFL(void *input)
{
  int size;
  const core_function_ref *ref_ptr;
  size = reserve_column_function_space_CFL();
  for (int i = 0; i < size; i++)
  {
    ref_ptr = core_functions + i;
    Store_column_function_CFL(input, ref_ptr->name, ref_ptr->fn);
  }
}

/*
** column functions
*/

static int return_condition_code(void *handle, void *aux_fn,
                                 void *params, Event_data_CFL_t *event_data)
{
  int *return_code;

  return_code = (int *)params;
  if (event_data->event_index > EVENT_INIT_CFL)
  {

    return *return_code;
  }
  return CONTINUE_CFL;
}

static int one_shot_handler(void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data)
{
  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
    return DISABLE_CFL;
  }
  return DISABLE_CFL;
}
static int bidirectional_one_shot_handler(void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{

  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    fn(handle, params, event_data);
  }

  return CONTINUE_CFL;
}

static inline int generate_return_code(bool termination_flag)
{
  if (termination_flag == true)
  {
    return TERMINATE_CFL;
  }
  return RESET_CFL;
}

static int while_handler(void *handle, void *aux_fn, void *params,
                         Event_data_CFL_t *event_data)
{
  Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
  While_control_CFL_t *while_ctrl;
  while_ctrl = (While_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {

    while_ctrl->current_count = 0;
    bool_fn(handle, while_ctrl->user_data, event_data);
    return CONTINUE_CFL;
  }

  if (bool_fn(handle, while_ctrl->user_data, event_data) == true)
  {
    return DISABLE_CFL;
  }
  if (while_ctrl->time_out_ms <= 0)
  {
    return HALT_CFL;
  }
  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return HALT_CFL;
  }

  while_ctrl->current_count += event_data->event_data;

  if (while_ctrl->current_count < while_ctrl->time_out_ms)
  {
    return HALT_CFL;
  }

  // Time out at this point
  while_ctrl->user_time_out_fn(handle, while_ctrl->user_data, event_data);

  return generate_return_code(while_ctrl->terminate_flag);
}

// handle time_out_ms -1

static int verify_handler(void *handle, void *aux_fn, void *params,
                          Event_data_CFL_t *event_data)
{
  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
  Verify_control_CFL_t *verify_control;

  verify_control = (Verify_control_CFL_t *)params;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    fn(handle, verify_control->user_data, event_data);
    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    return CONTINUE_CFL;
  }

  if (fn(handle, verify_control->user_data, event_data) == false)
  {
    if (verify_control->user_termination_fn != NULL)
    {
      verify_control->user_termination_fn(handle, verify_control->user_data,
                                          event_data);
    }

    return generate_return_code(verify_control->terminate_flag);
  }
  return CONTINUE_CFL;
}

// void Enable_Indexes_CFL(void *input, unsigned column_number, unsigned
// *column_indexes);
// enable_indexes(
// handle,column_index->column_number,column_index->column_indexes);

static int enable_columns(void *handle, void *aux_fn, void *params,
                          Event_data_CFL_t *event_data)
{
  Column_index_CFL_t *column_index;

  column_index = (Column_index_CFL_t *)params;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    enable_indexes(handle, column_index->column_number,
                   column_index->column_indexes);

    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    disable_indexes(handle, column_index->column_number,
                    column_index->column_indexes);
    return DISABLE_CFL;
  }
  if (column_index->terminate_flag == false)
  {

    return DISABLE_CFL;
  }

  return CONTINUE_CFL;
}

static int join_handler(void *handle, void *aux_fn, void *params,
                        Event_data_CFL_t *event_data)
{

  Column_index_CFL_t *column_index;
  column_index = (Column_index_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    column_index->init_flag = true;
    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    if (column_index->terminate_flag == true)
    {

      disable_indexes(handle, column_index->column_number,
                      column_index->column_indexes);
      return DISABLE_CFL;
    }
  }
  if (column_index->init_flag == true)
  {
    column_index->init_flag = false;
    return HALT_CFL;
  }
  if (number_Of_active_columns(handle, column_index->column_number,
                               column_index->column_indexes) == 0)
  {
    return DISABLE_CFL;
  }
  return HALT_CFL;
}

static int if_column_handler(void *input, void *aux_fn, void *params,
                             Event_data_CFL_t *event_data)
{

  If_function_CFL_t fn = (If_function_CFL_t)aux_fn;
  If_control_CFL_t *if_control;

  if_control = (If_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {

    if_control->init_flag = true;
    disable_indexes(input, if_control->column_number,
                    if_control->column_indexes);
    fn(input, if_control);
    enable_if_indexes(input, if_control);
    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    if (if_control->termination_flag == true)
    {

      disable_indexes(input, if_control->column_number,
                      if_control->column_indexes);
    }
  }

  if (if_control->init_flag == true)
  {
    if_control->init_flag = false;

    return HALT_CFL;
  }
  if (number_Of_active_columns(input, if_control->column_number,
                               if_control->column_indexes) == 0)
  {
    if_control->termination_fn(input, if_control, event_data);
    return DISABLE_CFL;
  }
  return HALT_CFL;
}

static int try_column_handler(void *input, void *aux_fn, void *params,
                              Event_data_CFL_t *event_data)
{

  Try_function_CFL_t fn = (Try_function_CFL_t)aux_fn;
  Try_column_CFL_t *data;
  bool pass_flag;

  data = (Try_column_CFL_t *)params;
  pass_flag = !data->invert_flag;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    data->progress_step = 0;
    data->current_column_index = 0;
    disable_indexes(input, data->column_number, data->column_indexes);
    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    if (data->terminate_flag == true)
    {

      disable_indexes(input, data->column_number, data->column_indexes);
    }
  }
  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return HALT_CFL;
  }
  if (data->progress_step == 0)
  {
    Enable_column_CFL(input, data->column_indexes[data->current_column_index]);
    data->progress_step = 1;
    return HALT_CFL;
  }

  if (Column_State_CFL(
          input, data->column_indexes[data->current_column_index]) == false)
  {

    if (Get_column_index_return_code_CFL(
            input, data->column_indexes[data->current_column_index]) ==
        pass_flag)
    {
      data->final_state = true;
      fn(input, data);
      return DISABLE_CFL;
    }

    if (data->current_column_index < data->column_number - 1)
    {
      data->current_column_index += 1;
      data->progress_step = 0;
      return HALT_CFL;
    }
    else
    {
      data->final_state = false;
      fn(input, data);
      return DISABLE_CFL;
    }

    return HALT_CFL;
  }
  return HALT_CFL; // try column is still active
}

static int for_column_handler(void *input, void *aux_fn, void *params,
                              Event_data_CFL_t *event_data)
{

  For_control_CFL_t *for_control;

  for_control = (For_control_CFL_t *)params;
  if (event_data->event_index == EVENT_INIT_CFL)
  {
    for_control->state = false;
    for_control->current_iterations = 0;
    for_control->terminate_flag = false;
    for_control->fn(input, for_control, event_data);
    enable_indexes(input, for_control->number_of_columns,
                   for_control->column_indexes);

    return CONTINUE_CFL;
  }
  if (event_data->event_index == TIMER_TICK_CFL)
  {
    if (for_control->state == false)
    {
      for_control->state = true;
      return HALT_CFL;
    }
    if (number_Of_active_columns(input, for_control->number_of_columns,
                                 for_control->column_indexes) == 0)
    {
      for_control->state = false;
      for_control->current_iterations += 1;
      if (for_control->current_iterations >=
          for_control->number_of_iterations)
      {
        for_control->terminate_flag = true;
        for_control->fn(input, for_control, event_data);
        return DISABLE_CFL;
      }
      for_control->fn(input, for_control, event_data);
      if (for_control->terminate_flag == true)
      {
        return DISABLE_CFL;
      }
      enable_indexes(input, for_control->number_of_columns,
                     for_control->column_indexes);
      return HALT_CFL;
    }
  }
  // non timer event

  return HALT_CFL;
}

static int while_column_handler(void *handle, void *aux_fn, void *params,
                                Event_data_CFL_t *event_data)
{
  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
  While_column_control_CFL_t *while_control;
  while_control = (While_column_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    while_control->state = 0;
    while_control->current_iterations = 0;
  }

  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    disable_indexes(handle, while_control->number_of_columns,
                    while_control->column_indexes);
  }
  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return HALT_CFL;
  }
  switch (while_control->state)
  {
  case 0:
    if (fn(handle, while_control, event_data) == false)
    {
      return DISABLE_CFL;
    }
    enable_indexes(handle, while_control->number_of_columns,
                   while_control->column_indexes);
    while_control->current_iterations += 1;
    while_control->state = 1;
    break;
  default:
    if (number_Of_active_columns(handle, while_control->number_of_columns,
                                 while_control->column_indexes) == 0)
    {
      while_control->state = 0;
    }
  }
  return HALT_CFL;
}

static int do_while_column_handler(void *handle, void *aux_fn,
                                   void *params, Event_data_CFL_t *event_data)
{
  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
  While_column_control_CFL_t *while_control;
  while_control = (While_column_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    while_control->state = 0;
    while_control->current_iterations = 0;
  }

  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    disable_indexes(handle, while_control->number_of_columns,
                    while_control->column_indexes);
  }
  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return HALT_CFL;
  }
  switch (while_control->state)
  {
  case 0:

    enable_indexes(handle, while_control->number_of_columns,
                   while_control->column_indexes);
    while_control->current_iterations += 1;
    while_control->state = 1;
    break;
  default:
    if (number_Of_active_columns(handle, while_control->number_of_columns,
                                 while_control->column_indexes) == 0)
    {
      while_control->state = 0;
      if (fn(handle, while_control, event_data) == false)
      {
        return DISABLE_CFL;
      }
    }
  }
  return HALT_CFL;
}

static int event_function_handler(void *handle, void *aux_fn,
                                  void *params, Event_data_CFL_t *event_data)
{

  Event_handler_fn_CFL_t *event_handler_fn = (Event_handler_fn_CFL_t *)params;
  Column_function_CFL_t fn = (Column_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    event_handler_fn->event_flag = false;
  }

  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    if (event_handler_fn->event_flag == true)
    {
      fn(handle, aux_fn, event_handler_fn->user_data, event_data);
    }
  }

  if (validate_event(event_data->event_index, event_handler_fn->event_number, event_handler_fn->event_indexes) == true)
  {
    if (event_handler_fn->event_flag == false)
    {
      Event_data_CFL_t init_event = {EVENT_INIT_CFL, 0, NULL};
      event_handler_fn->event_flag = true;
      fn(handle, aux_fn, event_handler_fn->user_data, &init_event);
    }

    return fn(handle, aux_fn, event_handler_fn->user_data, event_data);
  }
  else
  {
    if (event_handler_fn->event_flag == true)
    {

      return fn(handle, aux_fn, event_handler_fn->user_data, event_data);
    }

    return CONTINUE_CFL;
  }
  return HALT_CFL;
}

static int enable_join_fn(void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
  Enable_join_CFL_t *enable_join = (Enable_join_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {

    enable_join->time_wait_flag = false;
    for (int i = 0; i < enable_join->number_of_columns; i++)
    {
      Enable_column_CFL(input, enable_join->column_indexes[i]);
    }

    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    for (int i = 0; i < enable_join->number_of_columns; i++)
    {
      Disable_column_CFL(input, enable_join->column_indexes[i]);
    }

    return CONTINUE_CFL;
  }
  if (event_data->event_index == TIMER_TICK_CFL)
  {
    if (enable_join->time_wait_flag == false)
    {
      enable_join->time_wait_flag = true;

      return HALT_CFL;
    }

    if (Join_columns_CFL(input, enable_join->number_of_columns, enable_join->column_indexes) == true)
    {

      return DISABLE_CFL;
    }
    return HALT_CFL;
  }

  return HALT_CFL;
}

/*
**
** Local Run Time Support
**
*/

static inline bool validate_event(int event_index, unsigned short event_number, short *event_indexes)
{
  for (unsigned i = 0; i < event_number; i++)
  {
    if (event_indexes[i] == event_index)
    {
      return true;
    }
  }
  return false;
}

static unsigned number_Of_active_columns(void *input, unsigned column_number,
                                         unsigned short *column_indexes)
{
  unsigned return_value = 0;
  for (unsigned i = 0; i < column_number; i++)
  {

    if (Column_State_CFL(input, *column_indexes++) == true)
    {

      return_value += 1;
    }
  }
  return return_value;
}

static void enable_if_indexes(void *input, If_control_CFL_t *if_control)
{

  unsigned short *index = if_control->column_indexes;
  for (unsigned i = 0; i < if_control->column_number; i++)
  {
    bool state = if_control->return_indexes[i];

    if (state == true)
    {

      Enable_column_CFL(input, *index);
    }
    else
    {
      ; // disabled before this function was called
      // Disable_column_CFL(input,*index);
    }
    index++;
  }
}

static void enable_indexes(void *input, unsigned column_number,
                           unsigned short *column_indexes)
{
  for (unsigned i = 0; i < column_number; i++)
  {

    Enable_column_CFL(input, *column_indexes++);
  }
}
static void disable_indexes(void *input, unsigned column_number,
                            unsigned short *column_indexes)
{
  for (unsigned i = 0; i < column_number; i++)
  {
    Disable_column_CFL(input, *column_indexes++);
  }
}
