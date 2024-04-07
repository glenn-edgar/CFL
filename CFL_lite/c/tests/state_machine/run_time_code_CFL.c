

//----------Run time code  ----

#include "run_time_code_CFL.h"

int case_change_test(const void *input, void* params, Event_data_CFL_t* event_data, bool *continue_flag)
{

  
    Case_change_test_data_t *case_change_data = (Case_change_test_data_t *)params;
    *continue_flag = true;
    int event_id = event_data->event_index;
    switch(event_id)
    {
        case 101:
            return 0;
            *continue_flag = false;
            break;
        case 102:
            return 1;
            *continue_flag = false;
            break;
        case 103:
            return 2;
            *continue_flag = false;
            break;
        case 104:
            return 3;
            *continue_flag = false;
            break;
      
        case 114:
            Printf_CFL(input,case_change_data->debug_message);
            Printf_CFL(input," .............. event 114 processed here \n");
            *continue_flag = false;
            return -1;
            break;
        default:
            return -1;
            break;
        }
        return -1;
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

int SM_case_change_CFL(const void *input, void *fn_aux,void *params,Event_data_CFL_t *event_data){

   State_function_CFL_t case_change = (State_function_CFL_t)fn_aux;
   SM_case_change_CFL_t *sm_case_change = (SM_case_change_CFL_t *)params;
   if(event_data->event_index < 0){
    return CONTINUE_CFL;
   }
    bool continue_flag = false;
   int new_state = case_change(input,(void *)sm_case_change->user_data,event_data,&continue_flag);
   if(new_state >= 0 ){
       change_state_machine_CFL(input,sm_case_change->sm_id,new_state);
       return HALT_CFL;
   }
   if(continue_flag == true){
       return CONTINUE_CFL;
   }
   return HALT_CFL;

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
   


int sm_sync_events_CFL(const void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data){
    (void)aux_fn;
   
    sm_sync_events_t *sync_events = (sm_sync_events_t *)params;
    
    if(event_data->event_index == EVENT_INIT_CFL){
        
       
        Event_data_CFL_t   sync_event_data = {sync_events->sync_event_index,false,NULL};
        enqueue_event_CFL(input,sync_events->sm_queue_id,&sync_event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index >0)
    {
       
        if(event_data->event_index == sync_events->sync_event_index){
            return HALT_AND_DISABLE_CFL;
        }
    }

    return HALT_CFL;
}


int SM_debug_CFL(const void *input, void *fn_aux,void *params,Event_data_CFL_t *event_data){
   (void)fn_aux;
   (void)input;
   SM_debug_CFL_t *sm_debug = (SM_debug_CFL_t *)params;
   if(event_data->event_index < 0){
    return CONTINUE_CFL;
   }



   Printf_CFL(input,"State machine %d state %d event index %d %s\n",sm_debug->sm_id,sm_debug->state_id,event_data->event_index,sm_debug->debug_message);
   return CONTINUE_CFL;

}



int sm_feed_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    const SM_feed_state_CFL_t *sm_feed_state_struct = (const SM_feed_state_CFL_t *)params;

    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;

    Sm_control_ROM_CFL_t *sm_rom_array = (Sm_control_ROM_CFL_t *)handle->sm_rom;
    Sm_control_RAM_CFL_t *sm_ram_array = (Sm_control_RAM_CFL_t *)handle->sm_ram;
    Sm_control_ROM_CFL_t *sm_rom = &sm_rom_array[sm_feed_state_struct->sm_id];
    Sm_control_RAM_CFL_t *sm_ram = &sm_ram_array[sm_feed_state_struct->sm_id];
    if(event_data->event_index == EVENT_INIT_CFL){
        fn(input,(void *)sm_feed_state_struct->user_data,event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        fn(input,(void *)sm_feed_state_struct->user_data,event_data);
        return CONTINUE_CFL;
    }

    if(event_data->event_index < 0){
        return CONTINUE_CFL;
    }
    if(sm_ram->active == false)
    {
       return CONTINUE_CFL;
    }
    bool result = fn(input,(void *)sm_feed_state_struct->user_data,event_data);
    if( result == true){
        chain_single_sweep_CFL( input, sm_rom->column_ids[sm_ram->current_state], event_data);
        return HALT_CFL;
    }
    return CONTINUE_CFL;
        
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


void Asm_change_state_machine_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    ASM_change_state_machine_CFL_t *change_state_machine = (ASM_change_state_machine_CFL_t  *)params;
    change_state_machine_CFL(input,change_state_machine->sm_index,change_state_machine->state_index);

}

void enable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    enable_sm_CFL_t *enable_sm = (enable_sm_CFL_t *)params;
    for(unsigned i = 0; i< enable_sm->sm_number; i++)
    {
        enable_state_machine_CFL(input,enable_sm->sm_indexes[i]);
    }
    
}

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    
    Enable_column_CFL_t *enable_column = (Enable_column_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL )
    {
       
        for(unsigned i=0;i<enable_column->number_of_columns;i++){
            if(get_current_column_index_CFL(input) != enable_column->column_list[i]){
               enable_column_CFL(input,enable_column->column_list[i]);
            }
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




void SM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event) {
  (void)event;
 
  SM_log_CFL_t *sm_data = (SM_log_CFL_t *)params;
  if(event->event_index == EVENT_INIT_CFL){
   
    Printf_CFL(input, "-------------------- State Machine %d  current state %d .." ,sm_data->sm_id,sm_data->state_id);
    Printf_CFL(input,"%s\n" ,sm_data->entry_message);
    return;
  }
  if(event->event_index == EVENT_TERMINATION_CFL){
   
    Printf_CFL(input, "------------------------ State Machine %d  current state %d  ..",sm_data->sm_id,sm_data->state_id);
    Printf_CFL(input,"%s\n",sm_data->exit_message);
    return;
  }

}

    
void send_event_to_sm(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    sm_event_CFL_t *sm_event = (sm_event_CFL_t *)params;
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Sm_control_ROM_CFL_t *sm_rom_array = (Sm_control_ROM_CFL_t *)handle->sm_rom;
    Sm_control_RAM_CFL_t *sm_ram_array = (Sm_control_RAM_CFL_t *)handle->sm_ram;
    Sm_control_ROM_CFL_t *sm_rom = &sm_rom_array[sm_event->sm_id];
    Sm_control_RAM_CFL_t *sm_ram = &sm_ram_array[sm_event->sm_id];
    if(sm_ram->active == false)
    { 
        return; // sm is not active
    }
    unsigned short sm_queue_id = sm_rom->manager_column_id +1;
    Event_data_CFL_t *event_data_to_send = ( Event_data_CFL_t *)sm_event->event_data;
  
    enqueue_event_CFL(input,sm_queue_id, event_data_to_send);
  
}
void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
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

void disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    enable_sm_CFL_t *enable_sm = (enable_sm_CFL_t *)params;
    for(unsigned i = 0; i< enable_sm->sm_number; i++)
    {
        disable_state_machine_CFL(input,enable_sm->sm_indexes[i]);
    }
    
}

bool feed_events_test_a(const void *input, void* params, Event_data_CFL_t* event_data)
{

    (void)input;
    (void)event_data;
    (void)params;
    //Feed_events_test_data_a_t *feed_events_test_data = (Feed_events_test_data_a_t *)params;
  
    
    return true;
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

bool feed_events_test(const void *input, void* params, Event_data_CFL_t* event_data)
{

  
    Feed_events_test_data_t *feed_events_test_data = (Feed_events_test_data_t *)params;
    int event_id = event_data->event_index;
    switch(event_id)
    {
        
        case 114:
               Printf_CFL(input,feed_events_test_data->debug_message);
               Printf_CFL(input," .............. event 114 processed here \n");
               return false;
            break;
        default:
            return true;
    }
    return true;
}

