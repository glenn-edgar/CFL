

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




void register_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void )event_data;
    register_map_copy_CFL_t* setup = (register_map_copy_CFL_t*)params;
    Registermap_CFL_t* source_bmp      =   get_registermap_control_CFL(input,setup->source_buffer);
    Registermap_CFL_t* destination_bmp =  get_registermap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        int16_t source_register = registermap_get_value_CFL(source_bmp,setup->source_offset + i);
        registermap_set_value_CFL(destination_bmp,setup->destination_offset + i,source_register);
    }
}

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}

void  if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    if_then_else_reg_map_CFL_t* setup = (if_then_else_reg_map_CFL_t* )params;
    Registermap_CFL_t* source_bmp      =  get_registermap_control_CFL(input,setup->source_buffer);
    bool source_reg =  registermap_get_value_CFL(source_bmp,setup->if_reg);
    if(source_reg == true){
        setup->then_one_shot(input,(void *)setup->then_data,event_data);
    }else{
        setup->else_one_shot(input,(void *)setup->else_data,event_data);
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


void set_register_buffer_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    set_register_buffer_CFL_t* setup = (set_register_buffer_CFL_t *)params;
   
    int16_t *register_map = registermap_buffer_CFL(handle,setup->buffer_number);
    
    
    for(unsigned i = 0; i< setup->register_array_size;i++){
    
        register_map[i+setup->start] = setup->register_array[i];
    }

}




void  reg_my_then_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    reg_my_then_one_shot_CFL_t* setup = (reg_my_then_one_shot_CFL_t*)params;
    Registermap_CFL_t* bmp      =   get_registermap_control_CFL(input,setup->source_buffer);
    registermap_set_value_CFL(bmp,setup->reg_position,setup->result);  
}


void  reg_verify_trigger_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    (void)params;
    Printf_CFL("**************************** verify condition triggered **********************************************\n");
}  


void  this_should_not_happen_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    (void)params;
    Printf_CFL("wait not triggered should not happen");
}  


void clear_register_map_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    clear_register_map_CFL_t* setup = (clear_register_map_CFL_t*)params;
   
    int16_t *register_map = registermap_buffer_CFL(handle,setup->buffer_number);
    
    
    for(unsigned i = setup->start; i< setup->number+setup->start;i++){
    
        register_map[i] = setup->state;
    }

}




void  reg_my_else_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    reg_my_else_one_shot_CFL_t* setup = (reg_my_else_one_shot_CFL_t*)params;
    Printf_CFL("else branch %s",setup->message);
}  


void dump_register_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    dump_register_buffer_CFL_t* setup = (dump_register_buffer_CFL_t*)params;
    uint16_t size = setup->size;
    
    int16_t *register_map = registermap_buffer_CFL(handle,setup->buffer_number);
   
    Printf_CFL("\n\nDumping Register Buffer %d\n",setup->buffer_number);
    Printf_CFL("Register Buffer Size %d\n",size);
    Printf_CFL("Buffer register Map ");
    for(unsigned i = 0; i< size;i++){
        Printf_CFL("%d ",register_map[i]);
    }
    Printf_CFL("\n\n");
    
}


void reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;

    const  s_reg_expression_CFL_t* setup = (const  s_reg_expression_CFL_t*)params; 
    int16_t result =  process_s_register_buffer_CFL(input, setup->definition);
    
    Registermap_CFL_t* bmp =  get_registermap_control_CFL(input, setup->buffer_number);
    registermap_set_value_CFL(bmp,setup->offset,result);  
}


bool verify_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    verify_reg_map_s_expr_CFL_t* setup = (verify_reg_map_s_expr_CFL_t*)params;  
    bool result = process_s_register_buffer_CFL(input, setup->definition);
    return result;  
}


bool wait_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    wait_reg_map_s_expr_CFL_t* setup = (wait_reg_map_s_expr_CFL_t*)params;
    bool result = process_s_register_buffer_CFL(input, setup->definition);
    return result;    
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
