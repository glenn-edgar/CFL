

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


int sequence_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data ){
    (void)aux_fn;
   
    return sequence_columns_utility_CFL(input, params, event_data);

}
  static inline int generate_return_code_while(bool termination_flag)
  {
    if (termination_flag == true)
    {
      return TERMINATE_CFL;
    }
    return RESET_CFL;
  }  
int while_handler_CFL(const void *input, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
    
    const While_control_ROM_CFL_t *while_ctrl = (While_control_ROM_CFL_t *)params;
    While_control_RAM_CFL_t *while_ctrl_ram = while_ctrl->while_control_ram;
    
    if (event_data->event_index == EVENT_INIT_CFL)
    {
       
        
        while_ctrl_ram->current_count = 0;
        bool_fn(handle,(void *) while_ctrl->user_data, event_data);
        
        return CONTINUE_CFL;
    }
    
    if (bool_fn(handle, (void *)while_ctrl->user_data, event_data) == true)
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
    while_ctrl_ram->current_count += *(unsigned short *)event_data->params;
    if (while_ctrl_ram->current_count < while_ctrl->time_out_ms)
    {
        return HALT_CFL;
    }
    // Time out at this point
    while_ctrl->user_time_out_fn(handle, (void *)while_ctrl->user_data, event_data);
    
    return generate_return_code_while(while_ctrl->terminate_flag);
}



const int reset_buffer[1] = { RESET_CFL };
const int halt_buffer[1] = { HALT_CFL };
const int terminate_buffer[1] = { TERMINATE_CFL };
const int terminate_engine_buffer[1] = { ENGINE_TERMINATE_CFL };



int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)aux_fn;
    int *return_code;
    return_code = (int *)params;
    
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        return CONTINUE_CFL;
    }
   
    return *return_code;
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

int change_state_function_CFL(const void *input,void *aux,  void *params, Event_data_CFL_t *event_data) {
  (void)aux;
  Change_state_structure_CFL_t *sm_data = (Change_state_structure_CFL_t *)params;
  if(event_data->event_index == EVENT_INIT_CFL){
    return CONTINUE_CFL; // do nothing
  }
  if(event_data->event_index == EVENT_TERMINATION_CFL){
    return CONTINUE_CFL; // do nothing
  }
  
  Change_column_element_state_hash_CFL(input, sm_data->state_hash);
  return HALT_AND_DISABLE_CFL;
}


void MCESM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event) {
  (void)event;
  uint16_t sm_id;
  uint16_t sm_state;

  MCESM_log_CFL_t *sm_data = (MCESM_log_CFL_t *)params;
  if(event->event_index == EVENT_INIT_CFL){
    Get_sm_state_CFL(input,&sm_id,&sm_state );
    Printf_CFL(input, "State Machine %d  current state %d    ",sm_id,sm_state);
    Printf_CFL(input, sm_data->entry_message);
    return;
  }
  if(event->event_index == EVENT_TERMINATION_CFL){
    Get_sm_state_CFL(input,&sm_id,&sm_state );
    Printf_CFL(input, "State Machine %d  current state %d     ",sm_id,sm_state);
    Printf_CFL(input,sm_data->exit_message);
    return;
  }

}

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}

void Enable_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event) {
  (void)event;
  Sm_enable_CFL_t *sm_data = (Sm_enable_CFL_t *)params;

  Enable_column_element_sm_hash_CFL(input, sm_data->sm_hash);
}


void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  Log_message_CFL_t *log_message = (Log_message_CFL_t *)params;
  
  unsigned column_index;
  int column_element_number;

  if(event_data->event_index == EVENT_INIT_CFL){
      column_index = get_current_column_index_CFL(input);
      column_element_number = get_current_column_element_index_CFL(input);
      Printf_CFL(input,"Log !!!! entering column index %d column element %d  ---> msg: %s\n",
              column_index, column_element_number, log_message->entry_message);
      return;
  }
  if(event_data->event_index == EVENT_TERMINATION_CFL){
      if(log_message->exit_flag == true){
        column_index = get_current_column_index_CFL(input);
        column_element_number = get_current_column_element_index_CFL(input);
        Printf_CFL(input,"Log !!!! Termination msg: %s\n",log_message->exit_message);
      }
      return;
  }
}


void Initialize_sm_structure_CFL(const void *input, void *params, Event_data_CFL_t *event_data) {
  (void)event_data;
  (void)params;

  Initial_column_element_structures_CFL(input);
  Disable_all_sm_CFL(input);
}


void Disable_current_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event) {
  (void)event;
  (void)params;

  Disable_column_element_sm_current_CFL(input);
}

 


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data)
{
  
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  const While_time_control_ROM_CFL_t *while_time_control = (const While_time_control_ROM_CFL_t *)params;
  
  if (event_data->event_index == EVENT_INIT_CFL)
  {
    
    *while_time_control->start_time = handle->time_control->current_millis;
    
    return false;
  }
  if (event_data->event_index == TIMER_TICK_CFL)
  {
    unsigned timeElasped = handle->time_control->current_millis - *while_time_control->start_time;
    if (timeElasped >= while_time_control->time_delay)
    {
      return true;
    }
  }

  return false;
}
