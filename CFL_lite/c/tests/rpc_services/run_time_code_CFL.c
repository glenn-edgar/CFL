

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


int rpc_client_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    const Rpc_client_CFL_t *rpc_client = (const Rpc_client_CFL_t *)params;
    
    if(event_data->event_index == EVENT_INIT_CFL){
       
      
        rpc_client->rpc_data_loader(input,(void *)rpc_client->rpc_send_data,event_data);
        enqueue_rpc_request_CFL(input,rpc_client->queue_id,rpc_client->receiver_column,rpc_client->rpc_id,
          rpc_client->rpc_send_data->data_type,rpc_client->rpc_send_data->data,rpc_client->rpc_send_data->malloc_flag );
         
     
        if(rpc_client->time_out_ms > 0){
            *rpc_client->time_count_ms = 0;
        }
        
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        // do nothing for now
        return CONTINUE_CFL;
    }
    if(event_data->event_index == TIMER_TICK_CFL){
        if(rpc_client->time_out_ms > 0){
            *rpc_client->time_count_ms += *(uint32_t *)event_data->params;
            if(*rpc_client->time_count_ms > rpc_client->time_out_ms){
                rpc_client->rpc_error_handler(input,rpc_client->rpc_error_user_data,event_data);
                if(rpc_client->terminate_flag == true){
                    return TERMINATE_CFL;
                }
                return RESET_CFL;
            }
        }
        return HALT_CFL;
    }
    if(event_data->event_index == RPC_CLIENT_RESULT_CFL){
        printf("rpc client result event \n");
        Rpc_data_CFL_t* rpc_data = peak_rpc_data_CFL(input,rpc_client->queue_id);
        rpc_client->rpc_reply_data->data = rpc_data->output;
        rpc_client->rpc_reply_data->data_type = rpc_data->output_data_type;
        rpc_client->rpc_reply_data->malloc_flag = rpc_data->output_malloc_flag;
        printf("rpc client reply handler %d %s \n",rpc_data->output_data_type,(char *)rpc_data->output);
        rpc_client->rpc_reply_handler(input, (void *)rpc_client->rpc_reply_data, event_data);
        
        return HALT_AND_DISABLE_CFL;
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



const Event_data_CFL_t new_rpc_event_CFL = { RPC_NEW_EVENT, false, NULL};
const Event_data_CFL_t rpc_client_event_CFL = { RPC_CLIENT_RESULT_CFL, false, NULL};
const Event_data_CFL_t action_complete_event_CFL = { RPC_ACTION_COMPLETE_CFL, false, NULL};

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
        *release_rpc->release_state = false;
        if( get_rpc_queue_number_CFL(input,release_rpc->queue_id) > 0){
            *release_rpc->release_state = true;
            uint16_t column_index =  get_current_column_index_CFL(input); 
               
            front_enqueue_column_index_event_CFL(input, column_index,(Event_data_CFL_t *) &new_rpc_event_CFL);

        }
        
         return HALT_CFL;
    }
    // for all other paths and events
    return CONTINUE_CFL;

}

int free_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Free_rpc_event_CFL_t *free_rpc_event = (Free_rpc_event_CFL_t *)params;
    
    if(event_data->event_index == RPC_NEW_EVENT){
        
        dequeue_Rpc_data_CFL(input, free_rpc_event->queue_id);
        return HALT_CFL;
    }
    return CONTINUE_CFL;
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
const Event_data_CFL_t sync_rpc_client_event_CFL = { RPC_CLIENT_RESULT_CFL, false, NULL};

int sync_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    One_shot_function_CFL_t process_event_fn = (One_shot_function_CFL_t )aux_fn;
    Sync_rpc_CFL_t *sync_rpc = (Sync_rpc_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
       
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
    
        return CONTINUE_CFL;
    }
    
    if(event_data->event_index == TIMER_TICK_CFL){
        bool leave_flag = false;
        while(get_rpc_queue_number_CFL(input,sync_rpc->queue_id) > 0){
            leave_flag = true; 
            Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,sync_rpc->queue_id);
            uint16_t column_index =  rpc_event->receiver_queue;
            process_event_fn(input,(void *)rpc_event,event_data);
            chain_single_sweep_CFL(input, column_index,(Event_data_CFL_t *) &sync_rpc_client_event_CFL);
            dequeue_Rpc_data_CFL(input,sync_rpc->queue_id);
        }
        if(sync_rpc->wait_flag == true){
            if(leave_flag == true){
                return DISABLE_CFL;
            }else{
                return HALT_CFL;
            }
        }
        return DISABLE_CFL;
     
    }
    
    return HALT_CFL;
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


int process_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    One_shot_function_CFL_t rpc_error_fn = (One_shot_function_CFL_t )aux_fn;
    Process_rpc_CFL_t *process_rpc = (Process_rpc_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        *process_rpc->state = 0;
        *process_rpc->elasped_time = 0;
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        if(*process_rpc->state != 0){
            
           
            dequeue_Rpc_data_CFL(input,process_rpc->queue_id);
            disable_column_CFL(input,process_rpc->column_id); // disable worker column
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
                store_column_data_CFL(input, column_index, (void *)rpc_event);
               
                reset_column_CFL(input,column_index);
               
                *process_rpc->elasped_time = 0;
                *process_rpc->state = 1;
                return HALT_CFL;
            }
        }
        // this path is for no rpc_id match
        *process_rpc->state = 0;
        return CONTINUE_CFL;
    }
    if(event_data->event_index == TIMER_TICK_CFL){
        if(*process_rpc->state == 0){
            return CONTINUE_CFL;
        }
  
        
        
        if(get_column_state_CFL(input, process_rpc->column_id) == false){
            
            Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,process_rpc->queue_id);
            uint16_t column_index =  rpc_event->receiver_queue;

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
        
        *process_rpc->elasped_time += *(unsigned short *)event_data->params;
        
       
        if(*process_rpc->elasped_time >= process_rpc->time_out_ms){
        
           disable_column_CFL(input,process_rpc->column_id);
          
           rpc_error_fn(input,process_rpc,event_data);
        
           if(process_rpc->terminate_flag == true){
            
               return TERMINATE_CFL;
           }
           
           return RESET_CFL;
        }
    }
    
    return HALT_CFL;
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

void time_out_data_function(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;

  char *time_out_data = (char *)param;
   
   Printf_CFL(input,"client time out fn  %s \n",time_out_data);
  
}



void worker_first_action_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   (void)param;

   Rpc_data_CFL_t *rpc_data = ( Rpc_data_CFL_t *)retrieve_current_column_data_CFL(input);
   if(rpc_data->input_data_type != 1){
       ASSERT_PRINT_INT(input,"input types do not match",rpc_data->input_data_type);
   }
   Printf_CFL(input,"Worker action input data type %d input data %s \n",rpc_data->input_data_type,(char *)rpc_data->input);

 
  
}



void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}


void client_data_verify_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   Rpc_transfer_data_packet_CFL_t *transfer_data = (Rpc_transfer_data_packet_CFL_t *)param;
   if(transfer_data->data_type != 2){
       ASSERT_PRINT_INT(input,"data types do not match",transfer_data->data_type);
   }
   Printf_CFL(input,"Client data verify data type %d data %s \n",transfer_data->data_type,(char *)transfer_data->data);
}




static const char *client_data_load_code_data = "Worker input action output data\n";
void client_data_load_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   (void)input;
   Rpc_transfer_data_packet_CFL_t *transfer_data = (Rpc_transfer_data_packet_CFL_t *)param;
   
   transfer_data->data = (void *)client_data_load_code_data;
   transfer_data->data_type = 1;
   transfer_data->malloc_flag = false;
}



void server_time_out_data_function(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;

   Process_rpc_CFL_t *rpc_data = (Process_rpc_CFL_t *)param;
   
   Printf_CFL(input,"server time out fn  %s \n",rpc_data->time_out_user_data);
  
}




void sync_data_verify_CFL(const void *input, void *param, Event_data_CFL_t *event_data){
    
    (void)event_data;
    Rpc_transfer_data_packet_CFL_t *transfer_data = (Rpc_transfer_data_packet_CFL_t *)param;
    Printf_CFL(input,"sync_data_verify_CFL\n");
    Printf_CFL(input,"Client data verify data type %d malloc flag %d data %d \n",transfer_data->data_type,transfer_data->malloc_flag,*(int32_t *)transfer_data->data);
 }
void ASM_reset_rpc_queue_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Reset_rpc_queue_CFL_t *reset_rpc_queue = (Reset_rpc_queue_CFL_t *)params;
    reset_rpc_queue_CFL(input,reset_rpc_queue->queue_id);

}


int32_t sync_no_wait_data = 0;
void sync_server_no_wait(const void *input, void *param, Event_data_CFL_t *event_data){
    
    (void)event_data;
    (void) input;
    Rpc_data_CFL_t* rpc_data = (Rpc_data_CFL_t *)param;
    rpc_data->output_data_type = 1;
    sync_no_wait_data = sync_no_wait_data + 1;
    rpc_data->output =  (void *)&sync_no_wait_data;    
    rpc_data->output_malloc_flag = false;
    Printf_CFL(input,"receiver queue %d rpc_id %d\n",rpc_data->receiver_queue,rpc_data->rpc_id);
    Printf_CFL(input,"sync_server_no_wait %d\n",sync_no_wait_data);
    Printf_CFL(input,"input data type %d malloc flag %d data %d \n",rpc_data->input_data_type,rpc_data->input_malloc_flag,*(int32_t *)rpc_data->input);
    Printf_CFL(input,"output data type %d malloc flag %d data %d \n",rpc_data->output_data_type,rpc_data->output_malloc_flag,*(int32_t *)rpc_data->output);
    
}


int32_t sync_data_load_data = 0;
void sync_data_load_CFL(const void *input, void *param, Event_data_CFL_t *event_data){
    
    (void)event_data;

    Rpc_data_CFL_t* rpc_data = (Rpc_data_CFL_t *)param;
    rpc_data->input_data_type = 0;
    sync_data_load_data = sync_data_load_data + 1;
    rpc_data->input =  (void *)&sync_data_load_data;    
    rpc_data->input_malloc_flag = false;
    
    Printf_CFL(input,"sync_data_load_CFL %d\n",sync_data_load_data);
    Printf_CFL(input,"receiver queue %d rpc_id %d\n",rpc_data->receiver_queue,rpc_data->rpc_id);
}


static const char *worker_second_action_output_data = "Worker output action output data\n";
void worker_second_action_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   (void)param;
   
   Rpc_data_CFL_t *rpc_data = (Rpc_data_CFL_t *)retrieve_current_column_data_CFL(input);
   rpc_data->output = (void *)worker_second_action_output_data;
   rpc_data->output_data_type = 2;
   rpc_data->output_malloc_flag = false;
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
