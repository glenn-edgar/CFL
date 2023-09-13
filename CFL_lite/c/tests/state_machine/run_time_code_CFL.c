

//----------Run time code  ----

#include "run_time_code_CFL.h"




int redirect_event_CFL(const void *input,void *fn_aux,void *params, Event_data_CFL_t *event_data){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Bool_function_CFL_t boolean_fn = (Bool_function_CFL_t )fn_aux;
    const redirect_CFL_t *redirect = (const redirect_CFL_t *)params;
    unsigned short sm_id = redirect->sm_id;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        boolean_fn(input, redirect->user_data, event_data);
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        boolean_fn(input,redirect->user_data, event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index <0)
    {
        return CONTINUE_CFL;
    }
    if(boolean_fn(input,redirect->user_data,event_data) == true){
        Sm_control_RAM_CFL_t sm_ram = handle->sm_ram[sm_id];
        Sm_control_ROM_CFL_t sm_rom = handle->sm_rom[sm_id];
        if(sm_ram.active == false){
            return CONTINUE_CFL;
        }
        unsigned short sm_queue_id = sm_rom.queue_ids[sm_ram.current_state];
        enqueue_event_CFL(input,sm_queue_id,event_data);
        return HALT_CFL;
    }

    return CONTINUE_CFL;
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



int SM_debug_CFL(const void *input, void *fn_aux,void *params,Event_data_CFL_t *event_data){
   (void)fn_aux;
   (void)input;
   SM_debug_CFL_t *sm_debug = (SM_debug_CFL_t *)params;
   if(event_data->event_index < 0){
       return CONTINUE_CFL;
   }
   Printf_CFL("State machine %d state %d event index %d %s\n",sm_debug->sm_id,sm_debug->state_id,event_data->event_index,sm_debug->debug_message);
   return HALT_CFL;

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

int state_change_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data){
    (void)fn_aux;
    const state_change_CFL_t *state_change = (const state_change_CFL_t *)params;
   if(event_data->event_index < 0){
       return CONTINUE_CFL;
   }
   for(unsigned i = 0 ;i< state_change->event_number;i++){
       if(event_data->event_index == state_change->event_indexes[i]){
           change_state_machine_CFL(input,state_change->sm_id,state_change->new_state_id);
           return HALT_CFL;
       }
   }
   return CONTINUE_CFL;
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
    
void send_event_to_sm(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    sm_event_CFL_t *sm_event = (sm_event_CFL_t *)params;
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Sm_control_ROM_CFL_t sm_rom = handle->sm_rom[sm_event->sm_id];
    unsigned short sm_queue_id = sm_rom.sm_queue_id;
    Event_data_CFL_t *event_data_to_send = ( Event_data_CFL_t *)sm_event->event_data;
   
    enqueue_event_CFL(input,sm_queue_id, event_data_to_send);
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


void change_sm_state_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    change_sm_state_CFL_t *change_sm_state = (change_sm_state_CFL_t *)params;
    change_state_machine_CFL(input,change_sm_state->sm_id,change_sm_state->new_state);
}
    
void enable_disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    
    enable_disable_sm_CFL_t *enable_disable_sm = (enable_disable_sm_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        for(unsigned i = 0; i< enable_disable_sm->sm_number; i++)
        {   
            enable_state_machine_CFL(input,enable_disable_sm->sm_indexes[i]);
        }
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        for(unsigned i = 0; i< enable_disable_sm->sm_number; i++)
        {   
            disable_state_machine_CFL(input,enable_disable_sm->sm_indexes[i]);
        }
    }
}

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    
    Enable_column_CFL_t *enable_column = (Enable_column_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL )
    {
       
        for(unsigned i=0;i<enable_column->number_of_columns;i++){
          
            enable_column_CFL(input,enable_column->column_list[i]);
        }
        
        
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        if(enable_column->terminate_flag==true){
           for(unsigned i=0;i<enable_column->number_of_columns;i++){
              disable_column_CFL(input,enable_column->column_list[i]);
           }
        }
    }
        


}



void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
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

bool true_constant_handler(void *handle, void *params,
                                  Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return true;
}
