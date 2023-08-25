

//----------Run time code  ----

#include "run_time_code_CFL.h"

  static inline int generate_return_code_verify(bool termination_flag)
  {
    if (termination_flag == true)
    {
      return TERMINATE_CFL;
    }
    return RESET_CFL;
  }

int verify_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    

    Verify_control_ROM_CFL_t *verify_control = (Verify_control_ROM_CFL_t *)params;
    if (event_data->event_index == EVENT_INIT_CFL)
    {

        fn(handle, verify_control->user_data, event_data);
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        return CONTINUE_CFL;
    }

    if (fn(handle, verify_control->user_data, event_data) == false)
    {
        if (verify_control->user_termination_fn != NULL)
        {
            verify_control->user_termination_fn(handle, verify_control->user_data,event_data);
        }
        return generate_return_code_verify(verify_control->terminate_flag);
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


void send_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  Event_data_CFL_t *event_data_to_send = (Event_data_CFL_t *)params;
  enqueue_event_CFL(input,0,event_data_to_send); 

}

 
void verify_one_shot_terminate(const void *input, void *params,Event_data_CFL_t *event_data){
      (void)input;
      (void)params;
      (void)event_data;
      static char terminate_message[] = "  verify is terminating the column ";
      Printf_CFL("verify one shot reset function called %s\n\n",terminate_message);


}

void wait_event_reset(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   char *message = (char *)params;
   
  
  Printf_CFL("\n\n *************** Reset function ---   %s\n\n",message);  
 
  
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

 
void verify_one_shot_reset(const void *input, void *params,Event_data_CFL_t *event_data){
      (void)input;
      (void)params;
      (void)event_data;
      static char reset_message[] = " verify is resetting the column  ";
      Printf_CFL("\n\n verify one shot reset function called %s \n\n",reset_message);


}

void wait_event_reset_b(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   While_event_control_ROM_t *while_event_control = (While_event_control_ROM_t *)params;
   char *message = (char *)while_event_control->user_data;
  
  Printf_CFL("\n\n *************** Reset function ---   %s\n\n",message);  
 
  
}

void wait_event_terminate_b(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   While_event_control_ROM_t *while_event_control = (While_event_control_ROM_t *)params;
   char *message = (char *)while_event_control->user_data;
  
  Printf_CFL("\n\n *************** Terminate function ---   %s\n\n",message);  
 
  
}

void wait_event_terminate(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   
   char *message = (char *)params;
  
  Printf_CFL("\n\n *************** Terminate function ---   %s\n\n",message);  
 
  
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
bool false_constant_handler(void *handle, void *params,
                                   Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return false;
}
#define EVENT_TEST_EVENT 100
#define EVENT_TEST_EVENT_COUNT 5
  
bool test_bool_fn_a(const void *input, void *params,Event_data_CFL_t *event_data){
   (void)input;
   
   unsigned *count = (unsigned *)params;
   
   if(event_data->event_index == EVENT_INIT_CFL){
     
      *count = 0;
      Printf_CFL("\n\ninit event received\n\n");
   }
   if(event_data->event_index == EVENT_TEST_EVENT){
      *count = *count + 1;
      //printf("event count = %d\n",count);
      if(*count >= EVENT_TEST_EVENT_COUNT){
         Printf_CFL("\n\n 5 events received returning false \n\n");
         return false;  // verify will fail at this point
      }
   }
   return true; // verify will pass at this point
}


#define EVENT_TEST_EVENT 100

bool test_bool_fn(const void *input, void *params,Event_data_CFL_t *event_data)
{
    (void)input;
    unsigned *count = (unsigned *)params;
    if(event_data->event_index == EVENT_INIT_CFL)
    {
        *count = 0;
        Printf_CFL("\n\ninit event received from user function\n\n");
    }
    if(event_data->event_index == EVENT_TEST_EVENT)
    {
       *count = *count + 1;
        if(*count == 5)
        {
            Printf_CFL("\n\n 5 events received returning true \n\n");
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
