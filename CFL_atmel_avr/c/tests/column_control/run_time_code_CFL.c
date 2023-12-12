

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

int set_return_code_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Set_return_code_CFL_t *set_return_code = (Set_return_code_CFL_t *)params;
    if(event_data->event_index != EVENT_INIT_CFL){
        set_current_column_return_code_CFL(input, set_return_code->return_code);
        return DISABLE_CFL;
    }
    return HALT_CFL;
}

int while_column_handler_CFL(const void *input, void *aux_fn,void *params, Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    While_column_control_CFL_t *while_control;
    while_control = (While_column_control_CFL_t *)params;

    if (event_data->event_index == EVENT_INIT_CFL)
    {
       fn(input, while_control, event_data);
       *while_control->current_count = 0;
       *while_control->state = true;
      

    }

    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {

        for(unsigned i=0;i<while_control->number_of_columns;i++){
            disable_column_CFL(input,while_control->column_indexes[i]);
        }
    }
    if (event_data->event_index != TIMER_TICK_CFL)
    {
        return HALT_CFL;
    }
    
    if(*while_control->state == true){
        if(fn(input, while_control, event_data) == false)
        {
           
            // chains are already disabled
            return DISABLE_CFL;
        }else{
            *while_control->current_count = *while_control->current_count + 1;
            for(unsigned i=0;i<while_control->number_of_columns;i++){
                enable_column_CFL(input,while_control->column_indexes[i]);
            }
            
        }
        *while_control->state = false;
        return HALT_CFL;
    }else{
        if(join_columns_CFL(input,while_control->number_of_columns,while_control->column_indexes) == true){
            *while_control->state = true;
        }


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
           return CONTINUE_CFL;
       }
       return HALT_CFL;
    }
    return HALT_CFL;
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



 int try_column_handler_CFL(const void *input, void *aux_fn, void *params,
                              Event_data_CFL_t *event_data)
{
  bool pass_flag;
  Try_function_CFL_t fn = (Try_function_CFL_t)aux_fn;
  Try_column_CFL_t *rom_data = (Try_column_CFL_t *)params;
  Try_function_RAM_t *ram_data = rom_data->ram_data;
  pass_flag = !rom_data->invert_flag;
  if (event_data->event_index == EVENT_INIT_CFL)
  {
    
    ram_data->progress_step = 0;
    ram_data->current_column_index = 0;
    for(unsigned i=0;i<rom_data->column_number;i++){
        disable_column_CFL(input,rom_data->column_indexes[i]);
    }
    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    

    for(unsigned i=0;i<rom_data->column_number;i++){
        disable_column_CFL(input,rom_data->column_indexes[i]);
    }
    return CONTINUE_CFL;
  }
  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return HALT_CFL;
  }
  
  if (ram_data->progress_step == 0)
  {

    enable_column_CFL(input, rom_data->column_indexes[ram_data->current_column_index]);
    ram_data->progress_step = 1;
   
    return HALT_CFL;
  }

  if (column_state_CFL(input, rom_data->column_indexes[ram_data->current_column_index]) == true)
  { 
    return HALT_CFL;  // try column is still active
  }
    printf("column return code %d\n",get_current_column_return_code_CFL(input, rom_data->column_indexes[ram_data->current_column_index]));
    if( get_current_column_return_code_CFL(input, rom_data->column_indexes[ram_data->current_column_index]) == pass_flag)
    {
      ram_data->final_state = false;
      fn(input, rom_data);
      return DISABLE_CFL;
    }

    if (ram_data->current_column_index < rom_data->column_number - 1)
    {            // try next column                     
      ram_data->current_column_index += 1;
      ram_data->progress_step = 0;
      return HALT_CFL;
    }
    
     ram_data->final_state = true;
     fn(input, rom_data);
     return DISABLE_CFL;
}

int if_then_else_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t )aux_fn;
    If_then_else_CFL_t *if_then_else = (If_then_else_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            for(unsigned i=0;i<if_then_else->number_of_then_columns;i++){
          
                enable_column_CFL(input,if_then_else->then_column_list[i]);
            }
            
        }
        else{
            for(unsigned i=0;i<if_then_else->number_of_else_columns;i++){
          
                enable_column_CFL(input,if_then_else->else_column_list[i]);
            }

        }
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
       
        if(if_then_else->terminate_flag==false){
            return CONTINUE_CFL;
        }
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            for(unsigned i=0;i<if_then_else->number_of_then_columns;i++){
                 disable_column_CFL(input,if_then_else->then_column_list[i]);
             }
        }
         else{
            for(unsigned i=0;i<if_then_else->number_of_else_columns;i++){
                disable_column_CFL(input,if_then_else->else_column_list[i]);
            }
        }
        return CONTINUE_CFL;
    }
   
    
    if(event_data->event_index == TIMER_TICK_CFL ){
        if((if_then_else->join_flag == false)&&(if_then_else->terminate_flag==false)){
            return DISABLE_CFL;
        }
        if((if_then_else->join_flag == false)&&(if_then_else->terminate_flag == true)){
            return CONTINUE_CFL;
        }
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            if(join_columns_CFL(input,if_then_else->number_of_then_columns,if_then_else->then_column_list) == true){
                return DISABLE_CFL;
            }
        }else{
            if(join_columns_CFL(input,if_then_else->number_of_else_columns,if_then_else->else_column_list) == true){
                return DISABLE_CFL;
            }
        }
    }
    return HALT_CFL;
    
}





void disable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
   (void)event_data;
    Disable_column_CFL_t *disable_column = (Disable_column_CFL_t *)params;

    for(unsigned short i=0;i<disable_column->number_of_columns;i++){
        disable_column_CFL(input,disable_column->column_list[i]);
    }

}



void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
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


bool while_column_test(void* input, void* params, Event_data_CFL_t* event_data) {
  (void)input; // unused parameter
  While_column_control_CFL_t* while_control = (While_column_control_CFL_t*)params;
  
  if (event_data->event_index == EVENT_INIT_CFL) {
  
    return false;
  }

 
  const char** message = (const char**)while_control->user_data;
  Printf_CFL(*message); // testing user data
 
  Printf_CFL("number of iterations %d max_iterations 4 \n",*while_control->current_count);
  if (*while_control->current_count >= 4) {
    Printf_CFL("while column is terminating \n");
    return false;
  }
  Printf_CFL("returning true \n");
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

bool true_constant_handler(void *handle, void *params,
                                  Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return true;
}
bool false_constant_handler(void *handle, void *params,
                                   Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return false;
}
void test_try_function(void* input, Try_column_CFL_t* try_control) {
  (void)input; // unused parameter
  Try_function_RAM_t* try_ram = try_control->ram_data;
   Printf_CFL("%s final state %d column index %d \n", __func__,
    try_ram->final_state, try_ram->current_column_index);
   Printf_CFL("user data %s\n", try_control->user_data);
}
