

//----------Run time code  ----

#include "run_time_code_CFL.h"


  
  
  
  int rpc_client_event_processor_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){
    Client_Process_RPC_event_CFL_t client_process_rpc_event = (Client_Process_RPC_event_CFL_t)aux_fn;
    if(event_data->event_index == RPC_EVENT_CFL){
      
      rpc_rom_message_CFL_t *rpc_message = (rpc_rom_message_CFL_t *)event_data->params;
      if(rpc_message->unique_id != RPC_MESSAGE_ID_CFL){
          ASSERT_PRINT_F("unique id is not valid expected %x got %x\n",RPC_MESSAGE_ID_CFL,rpc_message->unique_id);
      }
      client_process_rpc_event(input,params,rpc_message->ram_message);
      if(rpc_message->ram_message->sent_event.malloc_flag == true){
        private_heap_free_CFL(input,rpc_message->ram_message->sent_event.params);
      }
      if(rpc_message->ram_message->received_event.malloc_flag == true){
        private_heap_free_CFL(input,rpc_message->ram_message->received_event.params);
      }
      return DISABLE_CFL;
    }
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


int rpc_server_event_clean_up_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){
  One_shot_function_CFL_t one_shot_fn = (One_shot_function_CFL_t )aux_fn;
  rpc_server_event_clean_up_CFL_t *rpc_server_event_clean_up = (rpc_server_event_clean_up_CFL_t *)params;
  
  if(event_data->event_index == RPC_EVENT_CFL){
    // unhandled rpc message
    one_shot_fn(input,rpc_server_event_clean_up->user_data,event_data);
    if(rpc_server_event_clean_up->terminate_flag==true){
      return TERMINATE_CFL;
    }else{
      return RESET_CFL;
    }
  }

  return CONTINUE_CFL;
}



int rpc_client_event_generator_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){
  Generate_RPC_event_CFL_t generate_rpc_event = (Generate_RPC_event_CFL_t)aux_fn;
  rpc_rom_message_CFL_t *rpc_message = (rpc_rom_message_CFL_t *)params;
  if(event_data->event_index != EVENT_INIT_CFL){
  
    generate_rpc_event(input,params,&rpc_message->ram_message->sent_event); 
    Event_data_CFL_t event_data_to_send = {RPC_EVENT_CFL, false,(void *)rpc_message};
    enqueue_event_CFL(input,rpc_message->destination_queue, &event_data_to_send);
    return DISABLE_CFL;
  }
  return DISABLE_CFL;
}


int rpc_server_event_processor_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){

  Server_Process_RPC_event_CFL_t  server_process_rpc_event = (Server_Process_RPC_event_CFL_t)aux_fn;
  rpc_server_event_processor_CFL_t *rpc_server_event_processor = (rpc_server_event_processor_CFL_t *)params;
  
  if(event_data->event_index == RPC_EVENT_CFL){
    
    rpc_rom_message_CFL_t *rpc_message = (rpc_rom_message_CFL_t *)event_data->params;
    for(unsigned i = 0; i< rpc_server_event_processor->rpc_request_number; i++){
      if(rpc_message->rpc_request_id == rpc_server_event_processor->rpc_request_list[i]){
    
        
        if(rpc_message->unique_id != RPC_MESSAGE_ID_CFL){
          ASSERT_PRINT_F("unique id is not valid expected %x got %x\n",RPC_MESSAGE_ID_CFL,rpc_message->unique_id);
        }

        server_process_rpc_event(input,rpc_server_event_processor->user_data,rpc_message);
        enqueue_event_CFL(input,rpc_message->receieved_queue, event_data);
        return HALT_CFL;
        

      }
    }
  }

  return CONTINUE_CFL;
}



int rpc_clean_up_one_shot(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    const char *user_data = (const char *)params;
    rpc_rom_message_CFL_t *rpc_message = (rpc_rom_message_CFL_t *)event_data->params;
    Printf_CFL("user data is %s\n",user_data);
    Printf_CFL("event  is %d\n",event_data->event_index);
    Printf_CFL("rpc request is %d\n",rpc_message->rpc_request_id);
    Printf_CFL("uniqe id is %x\n",rpc_message->unique_id);
    Printf_CFL("destination queue is %d\n",rpc_message->destination_queue);
    Printf_CFL("receive queue is %d\n",rpc_message->receieved_queue);
    ASSERT_PRINT_F("unexpected rpc request %d\n",rpc_message->rpc_request_id);

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

    void rpc_client_1_time_out(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       (void)data;
       Printf_CFL("unexpected one second time out %s \n",(const char *)user_data);
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


bool wait_event_handler(const void *handle, void *params,
                               Event_data_CFL_t *event_data)
{
  (void)handle;
 
   
  const While_event_control_ROM_t *while_event_control_rom = (const While_event_control_ROM_t *)params;
  unsigned *current_count = while_event_control_rom->current_count;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    *current_count = 0;
    
    return true;
  }
  
  if (event_data->event_index == while_event_control_rom->event_index)
  {

    *current_count += 1;
    if (*current_count >= while_event_control_rom->number_of_events)
    {
    
      return true;
    }
  }

  return false;
}
    void rpc_client_1_generator(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       data->event_index = 100;
       data->malloc_flag = false;
       data->params = "rpc_client_recieved_event_1";
      

    }
    void rpc_client_2_generator(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       data->event_index = 200;
       data->malloc_flag = false;
       data->params = "rpc_client_recieved_event_2";


    }
    void rpc_client_3_generator(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       data->event_index = 300;
       data->malloc_flag = false;
       data->params = "rpc_client_recieved_event_3";


    }
    void rpc_client_event_processor_1(const void *input,void *user_data, rpc_ram_message_CFL_t *data){
       (void)input;
       (void)user_data;
       (void)data;
       Printf_CFL("process event 1 user data %s \n",(const char *)user_data);
       Printf_CFL("sent event  is %d\n",data->sent_event.event_index);
       Printf_CFL("recieved event  is %d\n",data->received_event.event_index);
       Printf_CFL("sent event  is %d\n",data->sent_event.malloc_flag);
       Printf_CFL("recieved event  is %d\n",data->received_event.malloc_flag);
       Printf_CFL("sent event  is %s\n",(const char *)data->sent_event.params);
       Printf_CFL("recieved event  is %s\n",(const char *)data->received_event.params);
    }   

void    service_handler_1(const void *input,void *user_data, rpc_rom_message_CFL_t *data){
    (void)input;
    (void)user_data;
    rpc_ram_message_CFL_t *rpc_message = data->ram_message;
    Event_data_CFL_t *sent_event = &rpc_message->sent_event;
    Event_data_CFL_t *received_event = &rpc_message->received_event;
    received_event->event_index = sent_event->event_index +10;
    received_event->malloc_flag = sent_event->malloc_flag;
    received_event->params = sent_event->params; 
    printf("service handler 1\n");

}

    void    service_handler_2(const void *input,void *user_data, rpc_rom_message_CFL_t *data){
        (void)input;
        (void)user_data;
        rpc_ram_message_CFL_t *rpc_message = data->ram_message;
        Event_data_CFL_t *sent_event = &rpc_message->sent_event;
        Event_data_CFL_t *received_event = &rpc_message->received_event;
        received_event->event_index = sent_event->event_index +120;
        received_event->malloc_flag = sent_event->malloc_flag;
        received_event->params = sent_event->params; 
        printf("service handler 2\n");
    
    }

