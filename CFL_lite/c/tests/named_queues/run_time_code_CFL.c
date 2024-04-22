

//----------Run time code  ----

#include "run_time_code_CFL.h"


int process_residual_column_event_queue(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
  
  (void)event_data;
  const Residual_column_event_CFL_t *residual_column_event = (const Residual_column_event_CFL_t *)params;
  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if(event_data->event_index == EVENT_TERMINATION_CFL){
   
    unsigned queue_id = residual_column_event->column_id + 1;
 
    while(is_queue_empty_CFL( input, queue_id ) == false){
     
      Event_data_CFL_t *event_data = peak_event_CFL(input,queue_id);
     
      fn(input,(void*)residual_column_event->user_data,event_data);
     
      dequeue_event_CFL(input,queue_id);
    }
    return TERMINATE_CFL;
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


int display_event_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
  (void)aux_fn;
  const display_event_CFL_t *display_event = (const display_event_CFL_t *)params;
  
  for(unsigned i= 0; i< display_event->number_of_columns; i++)
  {
    if(event_data->event_index == display_event->event_array[i]){
      
      unsigned column_index = get_current_column_index_CFL(handle);
      unsigned column_element_number = get_current_column_element_index_CFL(handle);
      Printf_CFL(handle,"Display Event !!!! column index %d column element %d  ---> Event: %d\n",
              column_index, column_element_number,display_event->event_array[i]);
    }
    
  }
  

  return CONTINUE_CFL;
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



int conditional_send_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{

  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;


  const Conditional_send_event_CFL_t *conditional_send_event = (const Conditional_send_event_CFL_t *)params;


  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
    return HALT_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    fn(handle, params, event_data);
    return HALT_CFL;
  }
  
  
  if(fn(handle, params, event_data) == true)
  {
     for(unsigned i= 0; i< conditional_send_event->number_of_columns; i++)
      {
        
        enqueue_column_event_CFL(handle,conditional_send_event->queue_id[i],event_data);
      }
    
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
  void residual_display(void *input, void *params,Event_data_CFL_t *event_data)
  {
    (void)input;

    char *residual_message = (char *)params;
    uint16_t column_index = get_current_column_index_CFL(input);
   
    Printf_CFL(input,"%s current column index %d residual event index %d\n",residual_message,column_index, event_data->event_index);
  }

void send_queue_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  Queue_event_CFL_t *queue_event = (Queue_event_CFL_t *)params;
  Event_data_CFL_t *event_data_to_send = ( Event_data_CFL_t *)queue_event->event_data;
  
  unsigned event_queue_index = queue_event->event_queue_index;
  enqueue_column_event_CFL(input,event_queue_index,event_data_to_send); 

}


void send_front_queue_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  const Front_queue_event_CFL_t *front_queue_event = (const Front_queue_event_CFL_t *)params;
 

  front_enqueue_column_index_event_CFL(input,front_queue_event->column_id, (Event_data_CFL_t *)front_queue_event->event_data); 
                    
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

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}


bool routing_2(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  (void)input;
  (void)params;
  if(event_data->event_index == 102){
    return true;
  }
  if(event_data->event_index == 103){
    return true;
  }
  return false;
}


bool routing_1(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  (void)input;
  (void)params;
  if(event_data->event_index == 100){
    return true;
  }
  if(event_data->event_index == 101){
    return true;
  }
  return false;
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
