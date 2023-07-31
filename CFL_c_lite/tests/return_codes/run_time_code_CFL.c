

//----------Run time code  ----

#include "run_time_code_CFL.h"





int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)aux_fn;
    int *return_code;
    return_code = (int *)params;
    printf("return_condition_CFL = %d\n",*return_code);
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        return CONTINUE_CFL;
    }
   
    return *return_code;
}

  static inline int generate_return_code_while(bool termination_flag)
  {
    if (termination_flag == true)
    {
      return TERMINATE_CFL;
    }
    return RESET_CFL;
  }  
int while_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
   
    const While_control_ROM_CFL_t *while_ctrl = (While_control_ROM_CFL_t *)params;
   
    While_control_RAM_CFL_t *while_ctrl_ram = while_ctrl->while_control_ram;
   
    if (event_data->event_index == EVENT_INIT_CFL)
    {
       
        while_ctrl_ram->current_count = 0;
        bool_fn(handle,(void *) while_ctrl->user_data, event_data);
       
        return CONTINUE_CFL;
    }
    printf("while_handler_CFL main\n");
    if (bool_fn(handle, (void *)while_ctrl->user_data, event_data) == true)
    {
        printf("while_handler_CFL main true\n");
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
    while_ctrl_ram->current_count += *(unsigned short *)event_data->params;
    if (while_ctrl_ram->current_count < while_ctrl->time_out_ms)
    {
        return HALT_CFL;
    }
    // Time out at this point
    while_ctrl->user_time_out_fn(handle, (void *)while_ctrl->user_data, event_data);

    return generate_return_code_while(while_ctrl->terminate_flag);
}




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

int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
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


void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
  char **message;
  
 
  message = (char **)params;
  Printf_CFL("Init event  %s\n",*message);  
 
  
}

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}

void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
   (void)input;
  
   char **message;
   
   
   message = (char **)params;
   if(event_data->event_index == EVENT_INIT_CFL)
   {
     Printf_CFL("Init event  %s\n",*message);  
     
   }
    if(event_data->event_index == EVENT_TERMINATION_CFL)
    {
       Printf_CFL("Termination event %s\n",*message);
    }
 
   
 }

 


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data)
{
  
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  const While_time_control_ROM_CFL_t *while_time_control = (const While_time_control_ROM_CFL_t *)params;
  printf("wait_time_delay_CFL %p \n",while_time_control);
  if (event_data->event_index == EVENT_INIT_CFL)
  {
     printf("wait_time_delay_CFL init\n");
    //printf("wait_time_delay_CFL init %d\n",handle->time_control->current_millis);
    printf("wait_time_delay_CFL init %d\n",*while_time_control->ending_time);
    *while_time_control->ending_time =
        handle->time_control->current_millis + while_time_control->time_delay;
    printf("wait_time_delay_CFL init end %d\n",*while_time_control->ending_time);
    return false;
  }
  if (event_data->event_index == TIMER_TICK_CFL)
  {
    printf("wait_time_delay_CFL timer tick %d %d %d\n",*while_time_control->ending_time,handle->time_control->current_millis,
    handle->time_control->current_millis);
    if (*while_time_control->ending_time <= handle->time_control->current_millis)
    {
      return true;
    }
  }

  return false;
}
