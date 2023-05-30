


#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

static void test_set_clear_print_functions(Handle_config_CFL_t* config_handle);
static void test_set_lua_symbol_table(Handle_config_CFL_t* config_handle);
static void test_wait_and_verify_df_functions(Handle_config_CFL_t* config_handle);
//static void test_verify_functions(Handle_config_CFL_t* config_handle);

void test_data_flow_functions(void) {
  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  
  


  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;
  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  config_handle->number_df_buffers = 2;
  config_handle->number_of_compiled_s_log_expressions = 5;
   
  test_set_clear_print_functions(config_handle);
  test_set_lua_symbol_table(config_handle);
  test_wait_and_verify_df_functions(config_handle);
  //test_verify_functions(config_handle);
}
static void test_set_clear_print_functions(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "test_buffer_functions"};
    Asm_columns_CFL(input,1,column_names);

   /* 
    Defining Column "test_buffer_functions"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "test_buffer_functions", true);
    Asm_log_message_CFL(input,"starting test_buffer_functions");
    Define_df_buf_CFL(input, "test_1", 64,0,NULL);
    Asm_reset_df_buffer_CFL(input, "test_1", true);
    Define_df_buf_CFL(input, "test_2", 32,0,NULL);
    Asm_reset_df_buffer_CFL(input, "test_2", false);
     unsigned short test_array_1[] = { 0,2,4,6,8,10,12,14,16 };
        Asm_set_df_buff_positions_CFL(input, "test_1", 9,{ test_array_1 }, false);
     unsigned short test_array_2[] = { 1,3,5,7,9,11,13,15,17 };
        Asm_set_df_buff_positions_CFL(input, "test_2", 9,{ test_array_2 }, true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_copy_df_buff_array_CFL(input, "test_1", "test_2", 0, 15, 15);
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("nil");
}
static void test_set_lua_symbol_table(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "test_buffer_functions"};
    Asm_columns_CFL(input,1,column_names);
    Define_df_buf_CFL(input, "test_1", 64,0,NULL);
    Define_df_buf_CFL(input, "test_2", 32,0,NULL);

   /* 
    Defining Column "test_buffer_functions"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "test_buffer_functions", true);
    Asm_log_message_CFL(input,"starting test_buffer_functions");
    Asm_reset_df_buffer_CFL(input, "test_1", true);
    Asm_reset_df_buffer_CFL(input, "test_2", false);
     unsigned short test_array_1[] = { 0,2,4,6,8,10,12,14,16 };
        Asm_set_df_buff_positions_CFL(input, "test_1", 9,{ test_array_1 }, false);
     unsigned short test_array_2[] = { 1,3,5,7,9,11,13,15,17 };
        Asm_set_df_buff_positions_CFL(input, "test_2", 9,{ test_array_2 }, true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_copy_df_buff_array_CFL(input, "test_1", "test_2", 0, 15, 15);
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n");
}

typedef struct end_message_t{
    const char *message;  
    
}end_message_t;
   
const char *while_termination_data = "while_termination_data";


static void while_termination(void *input,void *params,Event_data_CFL_t *event_data) {
   df_wait_data_t* df_wait_data = (df_wait_data_t* )params;
   
    
     Printf_CFL("while_termination: %s\n",df_wait_data->user_data);
}


static void test_wait_and_verify_df_functions(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    Store_one_shot_function_CFL(input,"ONE_SHOT_TERM",while_termination);
    Define_df_buf_CFL(input, "test_1", 32,0,NULL);
    Store_s_logical_expression_CFL(input, "test_1","true_s_expr", "( || ( &@ 1 3 5 7 9 ) ( &@ 1 3 5 7 9 ) )");
    Store_s_logical_expression_CFL(input, "test_1","false_s_expr", "( && ( &@ 1 3 5 7 9 ) ( &@ 2 3 5 7 9 ) )");
    // define the column list
    const char * column_names[] = {
        "setup_buffer","shut_down_engine","wait_and_fail_terminate","wait_and_fail_reset"};
    Asm_columns_CFL(input,4,column_names);

   /* 
    Defining Column "setup_buffer"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "setup_buffer", true);
    Asm_log_message_CFL(input,"starting test_buffer_functions");
    Asm_print_df_buf_CFL(input, "test_1");
     unsigned short test_array[] = { 1,3,5,7,9,11,13,15,17,19 };
        Asm_set_df_buff_positions_CFL(input, "test_1", 10,{ test_array }, true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "shut_down_engine"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "shut_down_engine", true);
    Asm_log_message_CFL(input,"startin shut engine down");
    Asm_wait_time_delay_CFL(input,25000);
    Asm_log_message_CFL(input,"Shutting engine down");
    Asm_dump_nodes_CFL(input);
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "wait_and_fail_terminate"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "wait_and_fail_terminate", true);
    Asm_log_message_CFL(input,"wait_and_fail_terminate starting should terminate");
    Asm_wait_df_tokens_s_expression_CFL(input, "test_1", 5000, "ONE_SHOT_TERM", (char *)while_termination_data, true, "false_s_expr");
    Asm_log_message_CFL(input,"should not get here");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "wait_and_fail_reset"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "wait_and_fail_reset", true);
    Asm_log_message_CFL(input,"wait_and_fail_terminate starting should reset every 5 seconds");
    Asm_wait_df_tokens_s_expression_CFL(input, "test_1", 5000, NULL, NULL, false, "false_s_expr");
    Asm_log_message_CFL(input,"should not get here");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     
Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
Printf_CFL("largest private heap free block %d \n", Private_heap_largest_free_block_CFL(input));
    Start_engine_CFL(input, 10, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n");
}
