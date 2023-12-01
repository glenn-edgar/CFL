

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





void shift_bit_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    shift_bit_buffer_CFL_t* setup = (shift_bit_buffer_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    unsigned start_bit = setup->start_bit;
    unsigned ending_bit = setup->ending_bit;
    int direction = setup->shift_direction;
  
    bitmap_shift_bits_CFL(source_bmp, start_bit,ending_bit,direction);
    
}


void clear_bit_map_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    clear_bit_map_CFL_t* setup = (clear_bit_map_CFL_t*)params;
   
    Bitmap_CFL* map = get_bitmap_control_CFL(handle,setup->buffer_number);
    bool state = setup->state;

    for(unsigned i = setup->start; i< setup->ending;i++){
    
        bitmap_set_bit_CFL(map,i,state);
    }

}



void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}

void bit_map_or_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_or_CFL_t* setup = (bit_map_or_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bool destination_bit = bitmap_get_bit_CFL(destination_bmp,setup->destination_offset + i);
        bool output_bit = source_bit || destination_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
    }
}


void  this_should_not_happen_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    (void)params;
    Printf_CFL("wait not triggered should not happen");
}  


void dump_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    dump_buffer_CFL_t* setup = (dump_buffer_CFL_t*)params;
    uint16_t size = setup->size;
    
    uint8_t *bit_map = bitmap_buffer(handle,setup->buffer_number);
   
    Printf_CFL("\n\nDumping Buffer %d\n",setup->buffer_number);
    Printf_CFL("Buffer Size %d\n",size);
    Printf_CFL("Buffer Bit Map ");
    for(unsigned i = 0; i< size;i++){
        Printf_CFL("%02x ",bit_map[i]);
    }
    Printf_CFL("\n\n");
    
}


void bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;

    const s_bit_expression_CFL_t* setup = (const s_bit_expression_CFL_t*)params; 
    bool result = process_s_bit_buffer_CFL(input, setup->definition);
    
    Bitmap_CFL *bmp = get_bitmap_control_CFL(input, setup->buffer_number);
    bitmap_set_bit_CFL(bmp,setup->offset,result);  
}


void bit_map_and_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_and_CFL_t* setup = (bit_map_and_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bool destination_bit = bitmap_get_bit_CFL(destination_bmp,setup->destination_offset + i);
        bool output_bit = source_bit && destination_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
    }
}


void  my_then_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    my_then_one_shot_CFL_t* setup = (my_then_one_shot_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    bitmap_set_bit_CFL(source_bmp,setup->bit_position,true);
    Printf_CFL("then branch passed");
}


void  my_else_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    my_else_one_shot_CFL_t* setup = (my_else_one_shot_CFL_t*)params;
    Printf_CFL("else branch %s",setup->message);
}  


void  verify_trigger_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    (void)params;
    Printf_CFL("****************************** verify condition triggered  ************************** \n");
}  


void  if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    if_then_else_bit_map_CFL_t* setup = (if_then_else_bit_map_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->if_bit);
    if(source_bit == true){
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


void bit_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void )event_data;
    bit_map_copy_CFL_t* setup = (bit_map_copy_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,source_bit);
    }
}


void bit_map_not_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_not_CFL_t* setup = (bit_map_not_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        
        bool output_bit = !source_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
    }
}


void bit_map_xor_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_xor_CFL_t* setup = (bit_map_xor_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bool destination_bit = bitmap_get_bit_CFL(destination_bmp,setup->destination_offset + i);
        bool output_bit = source_bit ^ destination_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
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

bool verify_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    verify_bit_map_s_expr_CFL_t* setup = (verify_bit_map_s_expr_CFL_t*)params;  
    bool result = process_s_bit_buffer_CFL(input, setup->definition);
    return result;  
}


bool wait_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    wait_bit_map_s_expr_CFL_t* setup = (wait_bit_map_s_expr_CFL_t*)params;
    bool result = process_s_bit_buffer_CFL(input, setup->definition);
    return result;    
}

