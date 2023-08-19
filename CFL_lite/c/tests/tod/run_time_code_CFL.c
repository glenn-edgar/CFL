

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

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}

void tod_verify_reset(const void *input,void *params,Event_data_CFL_t *eventdata){
   (void)input;
   (void)eventdata;
   Wait_tod_ROM_CFL_t *wait_tod = (Wait_tod_ROM_CFL_t *)params;
   Printf_CFL("terminate flag %d \n",wait_tod->terminate_flag);
   Printf_CFL(" %s \n",(const char *)wait_tod->user_data);
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

static bool test_while_tod_operations(unsigned short op_type, short ref, short compare ){
    
    switch(op_type){
       
        case OP_LT_CFL:
            if (compare < ref)
            {
                return true;
            }
            break;
        case OP_LE_CFL:
            if (compare <= ref)
            {
                return true;
            }
            break;
        case OP_EQ_CFL:
            
            if (ref != compare)
            {
               
                return true;
            }
            break;    
        case OP_GE_CFL:
            if (compare >= ref )
            {
                return true;
            }
            break;
        case OP_GT_CFL:
            if (compare > ref)
            {
                return true;
            }
            break;
        default:
        ASSERT_PRINT_INT("Invalid operator type",op_type);
    }
   
    return false;


}



bool test_tod_condition(const void *input, void *user_data, Event_data_CFL_t *event_data)
{
    (void)event_data;

    Wait_tod_ROM_CFL_t *wait_tod = (Wait_tod_ROM_CFL_t *)user_data;
    Time_control_CFL_t *time_control = Get_time_control_CFL(input);
    if (wait_tod->day_of_year >= 0)
    {
        if( test_while_tod_operations(wait_tod->op_type,time_control->day_of_year,  wait_tod->day_of_year ) == false){
            return true;
        }
    
    }
    if (wait_tod->month >= 0)
    {
        if( test_while_tod_operations(wait_tod->op_type,time_control->month,  wait_tod->month ) == false){
            return true;
        }
    }
    if (wait_tod->day >= 0)
    {
        if( test_while_tod_operations(wait_tod->op_type,time_control->day,  wait_tod->day ) == false){
            return true;
        }
    }
    if (wait_tod->dow >= 0)
    {
        if( test_while_tod_operations(wait_tod->op_type,time_control->dow,  wait_tod->dow ) == false){
            return true;
        }
    }
    if (wait_tod->hour >= 0)
    {
        if( test_while_tod_operations(wait_tod->op_type,time_control->hour,  wait_tod->hour ) == false){
            return true;
        }
    }
    if (wait_tod->minute >= 0)
    {
        if( test_while_tod_operations(wait_tod->op_type,time_control->minute,  wait_tod->minute ) == false){
            return true;
        }
     
    }
  
    if (wait_tod->second >= 0)
    {
      
        if( test_while_tod_operations(wait_tod->op_type,time_control->second,  wait_tod->second ) == false){
            return true;
        }
    }

    return false;
}
