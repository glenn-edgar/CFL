

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




void clear_float_map_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    clear_float_map_CFL_t* setup = (clear_float_map_CFL_t*)params;
   
    float *float_map = floatmap_buffer_CFL(handle,setup->buffer_number);
    
    
    for(unsigned i = setup->start; i< setup->number+setup->start;i++){
    
        float_map[i] = setup->state;
    }

}




void dump_float_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    dump_float_buffer_CFL_t* setup = (dump_float_buffer_CFL_t*)params;
    uint16_t size = setup->size;
    
   float *float_map = floatmap_buffer_CFL(handle,setup->buffer_number);
   
    Printf_CFL("\n\nDumping Float Buffer %d\n",setup->buffer_number);
    Printf_CFL("Float Buffer Size %d\n",size);
    Printf_CFL("Buffer float Map ");
    for(unsigned i = 0; i< size;i++){
        Printf_CFL("%f ",float_map[i]);
    }
    Printf_CFL("\n\n");
    
}


void float_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void )event_data;
    float_map_copy_CFL_t* setup = (float_map_copy_CFL_t*)params;
    Floatmap_CFL_t* source_bmp      =   get_floatmap_control_CFL(input,setup->source_buffer);
    Floatmap_CFL_t* destination_bmp =  get_floatmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        float source_float = floatmap_get_value_CFL(source_bmp,setup->source_offset + i);
        floatmap_set_value_CFL(destination_bmp,setup->destination_offset + i,source_float);
    }
}


void set_float_buffer_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    set_float_buffer_CFL_t* setup = (set_float_buffer_CFL_t *)params;
   
    float  *float_map = floatmap_buffer_CFL(handle,setup->buffer_number);
    
    
    for(unsigned i = 0; i< setup->float_array_size;i++){
    
        float_map[i+setup->start] = setup->float_array[i];
    }

}




void float_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;

    const  s_float_expression_CFL_t* setup = (const  s_float_expression_CFL_t*)params; 
    float result =  process_s_float_buffer_CFL(input, setup->definition);
    
    Floatmap_CFL_t* bmp =  get_floatmap_control_CFL(input, setup->buffer_number);
    floatmap_set_value_CFL(bmp,setup->offset,result);  
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

