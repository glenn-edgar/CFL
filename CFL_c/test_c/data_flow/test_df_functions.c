#if 0

#include "CFL_user_functions.h"
#include "CFL_debug.h"
#include "CFL_data_flow_functions.h"
#include "test_interface_functions.h"


static void test_basic_df_functions(Handle_config_CFL_t* config);
static void test_s_expression(Handle_config_CFL_t* config);
static void test_s_expression_symbol_table(Handle_config_CFL_t* config);
static void test_wait_and_verify_df_functions(Handle_config_CFL_t* config);

void test_df_functions(void) {

    Printf_CFL("test_df_functions");


    Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

    Printf_CFL("column control test");
     Printf_CFL("free memory %d \n",freeMemory());

    config_handle->number_of_columns = 10;
    config_handle->number_of_column_elements = 200;

    config_handle->number_df_buffers = 5;
    test_basic_df_functions(config_handle);
    test_s_expression(config_handle);
    test_s_expression_symbol_table(config_handle);
    test_wait_and_verify_df_functions(config_handle);
    Printf_CFL("free memory %d \n",freeMemory());
}


static void test_basic_df_functions(Handle_config_CFL_t* config) {

    void* input = Configure_engine_CFL(config, 40000, 2500);
    const unsigned short set_positions[] = { 1,3,5,7,9,11,13,15,17,19 };

    const char* column_names[] = { "basic_df_test" };

    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);
    Define_df_buf_CFL(input, "test_1", 25,0,NULL);
    Define_df_buf_CFL(input, "test_2", 20,0,NULL);

    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));

    Asm_start_column_CFL(input, "basic_df_test", true);
    Asm_reset_df_buffer(input, "test_1", true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_reset_df_buffer(input, "test_1", false);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_set_df_buff_positions(input, "test_1", sizeof(set_positions) / sizeof(short), set_positions, true);
    Asm_print_df_buf_CFL(input, "test_1");

    Asm_reset_df_buffer(input, "test_2", false);
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_copy_df_buff_array(input, "test_1", "test_2", 1, 0, 19);
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_log_message_CFL(input, "implementing 1 shift");
    Asm_shift_df_buffer(input, "test_2", 1, 0, 19, true, true);
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_log_message_CFL(input, "implementing -1 shift");
    Asm_shift_df_buffer(input, "test_2", -1, 1, 19, true, true);
    Asm_print_df_buf_CFL(input, "test_2");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);

    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Start_engine_CFL(input, 100, 30, NULL, NULL);
    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Destroy_engine_CFL(input);
    Printf_CFL("engine is done");
    Printf_CFL("free memory %d \n",freeMemory());
}

static void test_s_expression(Handle_config_CFL_t* config) {


    void* input = Configure_engine_CFL(config, 40000, 2500);
    const unsigned short set_positions[] = { 1,3,5,7,9,11,13,15,17,19 };

    const char* column_names[] = { "basic_df_test" };

    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);
    Define_df_buf_CFL(input, "test_1", 25,0,NULL);
    Define_df_buf_CFL(input, "test_2", 20,0,NULL);
    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
        //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));

    Asm_start_column_CFL(input, "basic_df_test", true);
  
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_set_df_buff_positions(input, "test_1", sizeof(set_positions) / sizeof(short), set_positions, true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_store_s_expression(input,"test_1",0,"(|| (&@ 1 3 5  7 9)(&@ 1 3 5  7 9))"); // produce a true result
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_store_s_expression(input,"test_1",1,"(&& (&@ 1 3 5  7 9)(&@ 2 3 5  7 9))"); // produce a false result
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);


    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Start_engine_CFL(input, 100, 30, NULL, NULL);
    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Destroy_engine_CFL(input);
    Printf_CFL("engine is done");
    Printf_CFL("free memory %d \n",freeMemory());
}



static void test_s_expression_symbol_table(Handle_config_CFL_t* config) {
    Symbol_record_CFL_t symbol_tbl[] = {
      {"s_0",0,1},
      {"s_1",1,1},
      {"s_2",2,1},
      {"s_3",3,1},
      {"s_4",4,1},
      {"s_5",5,1},
      {"s_6",6,1},
      {"s_7",7,1},
      {"s_8",8,1},
      {"s_9",9,1},
      {"s_10",10,1},
      {"s_11",11,1},
      {"s_12",12,1},
      {"s_13",13,1},
      {"s_14",14,1},
      {"s_15",15,1},
      {"s_16",16,1},
      {"s_17",17,1},
      {"s_18",18,1},
      {"s_19",19,1},
    };
    
    enum register_names {
    s_0 = 0,
    s_1,
    s_2,
    s_3,
    s_4,
    s_5,
    s_6,
    s_7,
    s_8,
    s_9,
    s_10,
    s_11,
    s_12,
    s_13,
    s_14,
    s_15,
    s_16,
    s_17,
    s_18,
    s_19,
};

    void* input = Configure_engine_CFL(config, 40000, 2500);
    const unsigned short set_positions[] = { s_1,s_3,s_5,s_7,s_9,s_11,s_13,s_15,s_17,s_19 };

    const char* column_names[] = { "basic_df_test" };

    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);
    Define_df_buf_CFL(input, "test_1", 25,sizeof(symbol_tbl)/sizeof(symbol_tbl[0]),symbol_tbl);
   
    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
        //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));

    Asm_start_column_CFL(input, "basic_df_test", true);
  
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_set_df_buff_positions(input, "test_1", sizeof(set_positions) / sizeof(short), set_positions, true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_store_s_expression(input,"test_1",0,"(|| (&@ s_1 s_3 s_5  s_7 s_9)(&@ s_1 s_3 s_5  s_7 s_9))"); // produce a true result
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_store_s_expression(input,"test_1",1,"(&& (&@ 1 3 5  7 9)(&@ s_2 s_3 s_5  s_7 s_9))"); // produce a false result
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);


    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Start_engine_CFL(input, 100, 30, NULL, NULL);
    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Destroy_engine_CFL(input);
    Printf_CFL("engine is done");
     Printf_CFL("free memory %d \n",freeMemory());
}




static void test_wait_and_verify_df_functions(Handle_config_CFL_t* config){

   Symbol_record_CFL_t symbol_tbl[] = {
      {"s_0",0,1},
      {"s_1",1,1},
      {"s_2",2,1},
      {"s_3",3,1},
      {"s_4",4,1},
      {"s_5",5,1},
      {"s_6",6,1},
      {"s_7",7,1},
      {"s_8",8,1},
      {"s_9",9,1},
      {"s_10",10,1},
      {"s_11",11,1},
      {"s_12",12,1},
      {"s_13",13,1},
      {"s_14",14,1},
      {"s_15",15,1},
      {"s_16",16,1},
      {"s_17",17,1},
      {"s_18",18,1},
      {"s_19",19,1},
    };
    
    enum register_names {
    s_0 = 0,
    s_1,
    s_2,
    s_3,
    s_4,
    s_5,
    s_6,
    s_7,
    s_8,
    s_9,
    s_10,
    s_11,
    s_12,
    s_13,
    s_14,
    s_15,
    s_16,
    s_17,
    s_18,
    s_19,
};

    void* input = Configure_engine_CFL(config, 40000, 2500);
    const unsigned short set_positions[] = { s_1,s_3,s_5,s_7,s_9,s_11,s_13,s_15,s_17,s_19 };

    const char* column_names[] = { "setup_buffer","shut_down_engine","wait_and_fail_terminate","wait_and_fail_reset","wait_verify_pass","wait_verify_fail_terminate","wait_verify_fail_reset" };
    const char* true_expression = "(|| (&@ s_1 s_3 s_5  s_7 s_9)(&@ s_1 s_3 s_5  s_7 s_9))";
    const char* false_expression = "(&& (&@ 1 3 5  7 9)(&@ s_2 s_3 s_5  s_7 s_9))";

   
    Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);
    Define_df_buf_CFL(input, "test_1", 25,sizeof(symbol_tbl)/sizeof(symbol_tbl[0]),symbol_tbl);
   
    

    Asm_start_column_CFL(input, "setup_buffer", true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_set_df_buff_positions(input, "test_1", sizeof(set_positions) / sizeof(short), set_positions, true);
    Asm_print_df_buf_CFL(input, "test_1");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "wait_and_fail_terminate", true);
    Asm_log_message_CFL(input, "wait_and_fail starting should terminate");
    Asm_wait_df_tokens_s_expression_CFL(input,"test_1",5000,NULL,NULL,true,false_expression); 
    Asm_log_message_CFL(input, "should not get here");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "shut_down_engine", true);
    Asm_log_message_CFL(input, "shut_down_engine");
    Asm_wait_time_delay_CFL(input,25000);// wait 25 seconds
    Asm_log_message_CFL(input, "engine shutting down");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "wait_and_fail_reset", true);
    Asm_log_message_CFL(input, "wait_and_fail_reset starting should reset every 5 seconds");
    //Asm_wait_time_delay_CFL(input,5000);// wait 5 seconds
    Asm_wait_df_tokens_s_expression_CFL(input,"test_1",5000,NULL,NULL,false,false_expression); 
    Asm_log_message_CFL(input, "should not get here");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "wait_verify_pass", true);
    Asm_log_message_CFL(input, "wait_verify_pass starting should succeed");
    Asm_wait_df_tokens_s_expression_CFL(input,"test_1",5000,NULL,NULL,false,true_expression); 
    Asm_verify_df_tokens_s_expression_CFL(input,"test_1",true_expression,NULL,NULL,true); 
    Asm_log_message_CFL(input, "should  get here");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "wait_verify_fail_terminate", true);
    Asm_log_message_CFL(input, "wait_verify_fail_terminate starting should terminate");
    Asm_wait_df_tokens_s_expression_CFL(input,"test_1",5000,NULL,NULL,false,true_expression); 
    Asm_verify_df_tokens_s_expression_CFL(input,"test_1",false_expression,NULL,NULL,true); 
    Asm_log_message_CFL(input, "should not get here");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "wait_verify_fail_reset", true);
    Asm_wait_time_delay_CFL(input,5000);// wait 5 seconds
    Asm_log_message_CFL(input, "wait_verify_fail_reset starting should reset every 5 seconds");
    
    Asm_wait_df_tokens_s_expression_CFL(input,"test_1",5000,NULL,NULL,false,true_expression); 
    Asm_verify_df_tokens_s_expression_CFL(input,"test_1",false_expression,NULL,NULL,false); 
    Asm_log_message_CFL(input, "should not get here");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);




    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Start_engine_CFL(input, 100, 30, NULL, NULL);
    //Printf_CFL("once heap size %d \n", Allocate_once_remaining_heap_size_CFL(input));
    //Printf_CFL("private heap size %d \n", Private_heap_largest_free_block_CFL(input));
    Destroy_engine_CFL(input);
    Printf_CFL("engine is done");
     Printf_CFL("free memory %d \n",freeMemory());
}



#endif