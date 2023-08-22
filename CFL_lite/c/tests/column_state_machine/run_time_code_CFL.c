

//----------Run time code  ----

#include "run_time_code_CFL.h"



int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
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
int change_column_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
    (void)aux_fn;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        return CONTINUE_CFL;
    }
    unsigned short *new_state = (unsigned short *)params;
       
    change_local_column_state_CFL(input, *new_state);
    return COLUMN_STATE_CHANGE_CFL;
 }


void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char **message;
  
  unsigned column_index;
  int column_element_number;
  message = (char **)params;

  column_index = get_current_column_index_CFL(input);
  column_element_number = get_current_column_element_index_CFL(input);
  Printf_CFL("Log !!!! column index %d column element %d  ---> msg: %s\n",
              column_index, column_element_number, *message);
}

