

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


static inline void join_terminate_columns_CFL(const void *input, Join_column_CFL_t *join_column){
    unsigned short i;
    for(i=0;i<join_column->number_of_columns;i++){
        disable_column_CFL(input,join_column->column_list[i]);
    }
}

int join_columns_function_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Join_column_CFL_t *join_column = (Join_column_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        ; // do nothing
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        if(join_column->terminate_flag==true){
            join_terminate_columns_CFL(input,join_column);
        }
        return DISABLE_CFL;
    }


    if(event_data->event_index == TIMER_TICK_CFL ){
       if(join_columns_CFL(input,join_column->number_of_columns,join_column->column_list)==true){
           return DISABLE_CFL;
       }
       return HALT_CFL;
    }
    return HALT_CFL;
}




int terminate_reset_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{

  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    return HALT_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    return HALT_CFL;
  }
  
  
  if(fn(handle, params, event_data) == true)
  {
    return TERMINATE_CFL;
  }

  return RESET_CFL;
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

void display_fibonaci(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)params;

   fibonacci_data_t *fibonacci_data = (fibonacci_data_t *)retrieve_current_column_data_CFL(input);
  Printf_CFL(input,"Fibanaci Data  %d\n",fibonacci_data->fibonacci);  
 
}


void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
   (void)input;
  
   char **message;
   
   
   message = (char **)params;
   if(event_data->event_index == EVENT_INIT_CFL)
   {
     Printf_CFL(input,"Init event  %s\n",*message);  
     
   }
    if(event_data->event_index == EVENT_TERMINATION_CFL)
    {
       Printf_CFL(input,"Termination event %s\n",*message);
    }
 
   
 }


void initialize_fibonaci(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;

   (void)params;
   fibonacci_data_t *fibonacci_data = (fibonacci_data_t *)retrieve_current_column_data_CFL(input);
  
   fibonacci_data->number = 15;
   fibonacci_data->index = 2;
   fibonacci_data->fibonacci = 0;
   fibonacci_data->first = 0;
   fibonacci_data->second = 1;
  
}


void send_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  Event_data_CFL_t *event_data_to_send = (Event_data_CFL_t *)params;
  enqueue_event_CFL(input,0,event_data_to_send); 

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

void store_column_data(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  const Column_data_CFL_t *column_data = (const Column_data_CFL_t *)params;
  for(unsigned i= 0; i< column_data->number_of_columns; i++)
  {
   
  
    store_column_data_CFL(input,column_data->column_id[i],(void *)column_data->user_data);
  }

}


void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
  char **message;
  
 
  message = (char **)params;
  Printf_CFL(input,"Init event  %s\n",*message);  
 
  
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

bool calculate_fibonaci(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
   (void)params;

   fibonacci_data_t *fibonacci_data = (fibonacci_data_t *)retrieve_current_column_data_CFL(input);
   
   if(event_data->event_index != TIMER_TICK_CFL)
   {
     return false;
   }
   if(fibonacci_data->index <= fibonacci_data->number)
   {
     fibonacci_data->fibonacci = fibonacci_data->first + fibonacci_data->second;
     fibonacci_data->first = fibonacci_data->second;
     fibonacci_data->second = fibonacci_data->fibonacci;
     fibonacci_data->index++;
     return false;
   }
   else
   {
     return true;
   }
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
