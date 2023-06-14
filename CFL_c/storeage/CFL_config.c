#include "CFL_named_event_queue_manager.h"
#include "CFL_column_element.h"
#include "CFL_columns.h"
#include "CFL_event_token.h"
#include "CFL_functions.h"
#include "CFL_local_heap_functions.h"
#include "CFL_data_flow_buffers.h"
#include "CFL_state_machine.h"
#include "CFL_user_functions.h"
#include "CFL_tod_functions.h"
#include "CFL_s_expr_buffers.h"
#include "CFL_column_state_machine.h"





Handle_config_CFL_t* Create_config_handle_CFL(Debug_out_CFL_t debug_out){

  Handle_config_CFL_t* config;
  config = (Handle_config_CFL_t*)malloc(sizeof(Handle_config_CFL_t));
  memset(config, 0, sizeof(Handle_config_CFL_t));
  config->debug_out = debug_out;
  return config;
}
  

void* Configure_engine_CFL(Handle_config_CFL_t* config, unsigned allocate_once_heap_size, unsigned private_heap_size) {
  Handle_CFL_t* handle;
  

  

  handle = (Handle_CFL_t*)create_allocate_once_heap_CFL(allocate_once_heap_size, private_heap_size);
  if(config->debug_out == NULL){
     config_debug_handle_CFL(handle,NULL);
  }else{
      config_debug_handle_CFL(handle,config->debug_out);
  }
  

 allocate_column_elements_CFL(handle, config->number_of_column_elements);
   
  allocate_function_space_CFL(
    handle, config->number_column_functions, config->number_bool_functions,
    config->number_if_functions, config->one_shot_functions,
    config->number_of_try_functions);
     allocate_columns_CFL(handle, config->number_of_columns);


  allocate_named_event_queue_space_CFL(handle,
    config->number_of_named_queues);
 
  
  allocate_df_buf_space_CFL(handle, config->number_df_buffers);
 
  Constuct_sm_system_CFL(handle, config);
  Initialize_bool_functions_CFL(handle);
  Initialize_s_logical_expression_buffers_CFL(handle,config->number_of_compiled_s_log_expressions);
  Initialize_column_state_machine_CFL(handle);
  return handle;
}

   

void Destroy_engine_CFL(void* input) {
  Handle_CFL_t* handle;
  handle = (Handle_CFL_t*)input;
  free_allocate_once_heap_CFL(handle);
}

/*
** Allocate once heap
*/

void* Allocate_once_malloc_CFL(void* input, int size) {
  Handle_CFL_t* handle;
  handle = (Handle_CFL_t*)input;
  return allocate_once_CFL(handle, size);
}

int Allocate_once_remaining_heap_size_CFL(void* input) {
  Handle_CFL_t* handle;
  handle = (Handle_CFL_t*)input;
  return remaining_allocate_once_heap_size_CFL(handle);
}

/*
** Local Private Heap
*/
void* Private_heap_malloc_CFL(void* input, unsigned size) {
  Handle_CFL_t* handle;
  handle = (Handle_CFL_t*)input;
  return private_heap_malloc_CFL(handle, size);
}

void Private_heap_free_CFL(void* input, void* ptr) {
  Handle_CFL_t* handle;
  handle = (Handle_CFL_t*)input;
  private_heap_free_CFL(handle, ptr);
}

int Private_heap_largest_free_block_CFL(void* input) {
  Handle_CFL_t* handle;
  handle = (Handle_CFL_t*)input;
  return private_heap_largest_block_CFL(handle);
}

void Dump_private_heap_blocks_CFL(void *input) {
  Handle_CFL_t* handle;
  handle = (Handle_CFL_t*)input;
  private_heap_dump_blocks_CFL(handle);
}
