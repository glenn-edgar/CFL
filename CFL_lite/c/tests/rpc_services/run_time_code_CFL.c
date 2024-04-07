

//----------Run time code  ----

#include "run_time_code_CFL.h"


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
const Event_data_CFL_t rpc_client_event_CFL = { RPC_CLIENT_RESULT_CFL, false, NULL};
const Event_data_CFL_t action_complete_event_CFL = { RPC_ACTION_COMPLETE_CFL, false, NULL};

int process_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    One_shot_function_CFL_t rpc_error_fn = (One_shot_function_CFL_t )aux_fn;
    Process_rpc_CFL_t *process_rpc = (Process_rpc_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        *process_rpc->state = 0;
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        if(*process_rpc->state != 0){
            uint16_t column_index =  process_rpc->column_id;
            disable_column_CFL(input,column_index);
            Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,process_rpc->queue_id);
            column_index =  rpc_event->receiver_queue-1;
            disable_column_CFL(input,column_index);  // disable the sender
        }
        return CONTINUE_CFL;
    }
    if(event_data->event_index == RPC_NEW_EVENT){
        if(*process_rpc->state != 0){
            ASSERT_PRINT_F(input,"Received RPC NEW EVENT BEFORE COMPLETING CURRENT EVENT  server queue %d \n",process_rpc->queue_id);
        }
        Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,process_rpc->queue_id);
        for(int i = 0; i < process_rpc->rpc_number; i++){
            if(rpc_event->rpc_id == process_rpc->rpc_id_list[i]){
                uint16_t column_index =  process_rpc->column_id;
                store_column_data_CFL(input, column_index, (void *)&process_rpc->queue_id);
                reset_column_CFL(input,column_index);
                *process_rpc->elasped_time = 0;
                *process_rpc->state = 1;
                return HALT_CFL;
            }
        }
        *process_rpc->state = 0;
        return CONTINUE_CFL;
    }
    if(event_data->event_index == TIMER_TICK_CFL){
        if(*process_rpc->state == 0){
            return CONTINUE_CFL;
        }
        if(get_column_state_CFL(input, process_rpc->column_id) == false){
            Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,process_rpc->queue_id);
            uint16_t column_index =  rpc_event->receiver_queue-1;
            chain_single_sweep_CFL(input, column_index,(Event_data_CFL_t *) &rpc_client_event_CFL);
            dequeue_Rpc_data_CFL(input,process_rpc->queue_id);
            *process_rpc->state = 0;
            uint16_t current_column_id = get_current_column_index_CFL(input);
            front_enqueue_column_index_event_CFL(input, current_column_id,(Event_data_CFL_t *) &action_complete_event_CFL);
            return HALT_CFL;

        }

        if(process_rpc->time_out_ms <= 0){
            return HALT_CFL;
        }
        *process_rpc->elasped_time += *(int *)event_data->params;
        if(*process_rpc->elasped_time > process_rpc->time_out_ms){
           rpc_error_fn(input,process_rpc,event_data);
        }
        if(process_rpc->terminate_flag == true){
            return TERMINATE_CFL;
        }
        return RESET_CFL;
    }
    if(*process_rpc->state == 0){
        return CONTINUE_CFL;
    }
    return HALT_CFL;
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


int trap_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Trap_rpc_event_CFL_t *trap_rpc = (Trap_rpc_event_CFL_t *)params;
    if(event_data->event_index == RPC_NEW_EVENT){
        Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,trap_rpc->queue_id);
        ASSERT_PRINT_F(input,"UNHANDLED RPC EVENT  request id  %d  receiver queue %d \n",rpc_event->rpc_id,rpc_event->receiver_queue);
    }
    return CONTINUE_CFL;
}

const Event_data_CFL_t new_rpc_event_CFL = { RPC_NEW_EVENT, false, NULL};


int release_rpc_request_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Release_rpc_event_CFL_t *release_rpc = (Release_rpc_event_CFL_t *)params;
    if( event_data->event_index == EVENT_INIT_CFL ){
        *release_rpc->release_state = false;
        return CONTINUE_CFL;
    
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL  ){
        reset_rpc_queue_CFL(input,release_rpc->queue_id);
        return CONTINUE_CFL;
    }
    if( event_data->event_index == TIMER_TICK_CFL ){
        if(*release_rpc->release_state == false){
            if( get_rpc_queue_number_CFL(input,release_rpc->queue_id) > 0){
                *release_rpc->release_state = true;
                uint16_t column_index =  get_current_column_index_CFL(input);
                front_enqueue_column_index_event_CFL(input, column_index,(Event_data_CFL_t *) &new_rpc_event_CFL);
                return HALT_CFL;
                
            }
         }
    }
    if( event_data->event_index == RPC_ACTION_COMPLETE_CFL ){
        if(*release_rpc->release_state == false){
            if( get_rpc_queue_number_CFL(input,release_rpc->queue_id) > 0){
                *release_rpc->release_state = true;
                uint16_t column_index =  get_current_column_index_CFL(input);
                front_enqueue_column_index_event_CFL(input, column_index,(Event_data_CFL_t *) &new_rpc_event_CFL);

            }
         }
         return HALT_CFL;
    }
    return CONTINUE_CFL;

}

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
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
