#include "CFL_user_functions.h"
#include "CFL_debug.h"
#include "CFL_s_logical_operations.h"
#include "test_interface_functions.h"

static void test_s_logic_operation_1(Handle_config_CFL_t *config);
static void test_s_logic_operation_2(Handle_config_CFL_t *config);

void unit_test_s_logical_operations(void){

   Printf_CFL("s_int_expr_unit_tests");
   Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);
   
   config_handle->number_df_buffers = 2;
   

   test_s_logic_operation_1(config_handle);
   test_s_logic_operation_2(config_handle);
      free(config_handle);

}

// testing basic df operations
static void test_s_logic_operation_1(Handle_config_CFL_t *config){

 
    void* input =  Configure_engine_CFL(config,40000,2500);
   
    
    // setup df_buffer 1
    // setup df buffer 2
    Define_df_buf_CFL(input,"test_1",25,0,NULL);
    Define_df_buf_CFL(input,"test_2",20,0,NULL);
    unsigned index_1 = Get_df_buf_index_CFL(input,"test_1");
    unsigned index_2 = Get_df_buf_index_CFL(input,"test_2");
    Reset_df_buf_CFL(input,index_1,true);
    Reset_df_buf_CFL(input,index_2,true);
    Print_df_buf_CFL(input,index_1);
    Print_df_buf_CFL(input,index_2);
    Reset_df_buf_CFL(input,index_1,false);
    Reset_df_buf_CFL(input,index_2,false);
    Print_df_buf_CFL(input,index_1);
    Print_df_buf_CFL(input,index_2);
    Set_df_buf_number_CFL(input,index_1,10, true);
    Printf_CFL("value %d \n",Get_df_buf_value_CFL(input,index_1,10));
    Set_df_buf_number_CFL(input,index_1,10, false);
    Printf_CFL("value %d \n",Get_df_buf_value_CFL(input,index_1,10));
    const unsigned short position_indexes[5] = {1,3,5,7,9};
    Set_df_buf_positions_CFL(input,index_1,5,position_indexes,true);
    Copy_df_buff_array_CFL(input,index_1,index_2,1,0,10);
    Print_df_buf_CFL(input,index_1);
    Print_df_buf_CFL(input,index_2);
    Printf_CFL("Match result true %d \n",Match_df_buf_positions_CFL(input,index_1,5,position_indexes,true));
    Printf_CFL("Match result false %d \n",Match_df_buf_positions_CFL(input,index_2,5,position_indexes,true));
    Print_df_buf_CFL(input,index_1);
    Printf_CFL("Shift right 1");
    Shift_df_buf_array_CFL(input,index_1,-1,1,10,true,true);
    Print_df_buf_CFL(input,index_1);
    Printf_CFL("Shift left 5");
    Shift_df_buf_array_CFL(input,index_1,5,1,10,true,true);
    Print_df_buf_CFL(input,index_1);
    const unsigned short position_indexes_2[5] = {15,16,17,18,19};
    Set_df_buf_positions_CFL(input,index_1,5,position_indexes_2, true);
    Print_df_buf_CFL(input,index_1);
    
   
    Destroy_engine_CFL(input);
   
    Printf_CFL("Free Memory %d \n",freeMemory());    
}
#if 0
typedef struct CFL_s_log_userdata_t{
    unsigned short buf_index;
    unsigned short  buf_size;
} CFL_s_log_userdata_t;

typedef struct CFL_s_log_op_handle_t {
    void* s_short_compiled_handle;
    CFL_s_log_userdata_t user_data;
} CFL_s_log_op_handle_t;

static S_short_fn_record_CFL_t s_verify_fn_tbl[] = {
    {"&&", and_verify_fn}, // and
    {"||", or_verify_fn},  // or
    {"~", not_verify_fn},  // not
    {"&@", and_tbl_verify_fn}, // input buffer positions result and of buffer positions
    {"|@", or_tbl_verify_fn}, // input buffer positions result or of buffer positions
    {"~@", not_tbl_verify_fn},// input buffer positions result not of buffer positions

};

#endif
static void test_s_logic_operation_2(Handle_config_CFL_t *config){

 
    void* input =  Configure_engine_CFL(config,40000,2500);
    

    Printf_CFL("largest heap size %d \n",Private_heap_largest_free_block_CFL(input));
    
    // setup df_buffer 1
    // setup df buffer 2
    Define_df_buf_CFL(input,"test_1",25,0,NULL);

    unsigned index_1 = Get_df_buf_index_CFL(input,"test_1");
    Reset_df_buf_CFL(input,index_1,false);
    
    const unsigned short position_indexes[5] = {15,16,17,18,19};
    Set_df_buf_positions_CFL(input,index_1,5,position_indexes,true);
    const unsigned short position_indexes_2[1] = {1};
    Set_df_buf_positions_CFL(input,index_1,1,position_indexes_2,true);
    Print_df_buf_CFL(input,index_1);

    const char *logic_expression_1 = "(~@ 0 1 2 3 4 5)";
    CFL_s_log_op_handle_t* s_log_op_handle_1 = Compile_s_log_op_CFL(input,index_1,logic_expression_1);
    Printf_CFL("expression 1 should be false result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_1));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_1);

    const char *logic_expression_2 = "(~@ 10 11 12 13 14)";
    CFL_s_log_op_handle_t* s_log_op_handle_2 = Compile_s_log_op_CFL(input,index_1,logic_expression_2);
    Printf_CFL("expression 2 should be true result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_2));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_2);

    const char *logic_expression_3 = "(|@ 0 1 2 3 4 5)";
    s_log_op_handle_1 = Compile_s_log_op_CFL(input,index_1,logic_expression_3);
    Printf_CFL("expression 1 should be true result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_1));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_1);

    const char * logic_expression_4 = "(|@ 10 11 12 13 14)";
    s_log_op_handle_2 = Compile_s_log_op_CFL(input,index_1,logic_expression_4);
    Printf_CFL("expression 2 should be false result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_2));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_2);

    const char *logic_expression_5 = "(&@ 15,16,17,18,19)";
    s_log_op_handle_1 = Compile_s_log_op_CFL(input,index_1,logic_expression_5);
    Printf_CFL("expression 1 should be true result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_1));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_1);


    const char *logic_expression_6 = "(&@ 0 1 2 3 4 5)";
    s_log_op_handle_2 = Compile_s_log_op_CFL(input,index_1,logic_expression_6);
    Printf_CFL("expression 2 should be false result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_2));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_2);

    const char *logic_expression_7 = "(~ (~@ 10 11 12 13 14) (&@ 0 1 2 3 4 5)) ";
    s_log_op_handle_1 = Compile_s_log_op_CFL(input,index_1,logic_expression_7);
    Printf_CFL("expression 1 should be false result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_1));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_1);

    const char *logic_expression_8 = "(~ (&@ 0 1 2 3 4 5) (&@ 0 1 2 3 4 5)) ";
    s_log_op_handle_2 = Compile_s_log_op_CFL(input,index_1,logic_expression_8);
    Printf_CFL("expression 2 should be true result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_2));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_2);

    const char *logic_expression_9 = "(|| (~@ 10 11 12 13 14) (&@ 15,16,17,18,19)) ";
    s_log_op_handle_1 = Compile_s_log_op_CFL(input,index_1,logic_expression_9);
    Printf_CFL("expression 1 should be true result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_1));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_1);

    const char *logic_expression_10 ="(|| (&@ 10 11 12 13 14) (~@ 15,16,17,18,19)) ";
    s_log_op_handle_2 = Compile_s_log_op_CFL(input,index_1,logic_expression_10);
    Printf_CFL("expression 2 should be false result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_2));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_2);

    const char *logic_expression_11 = "(&&  (&@ 15,16,17,18,19) (&@ 15,16,17,18,19)) ";
    s_log_op_handle_1 = Compile_s_log_op_CFL(input,index_1,logic_expression_11);
    Printf_CFL("expression 1 should be true result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_1));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_1);


    const char *logic_expression_12 = "(&& (&@ 10 11 12 13 14) (&@ 15,16,17,18,19)) ";
    s_log_op_handle_2 = Compile_s_log_op_CFL(input,index_1,logic_expression_12);
    Printf_CFL("expression 2 should be false result %d \n\n",Execute_s_log_op_CFL(input,s_log_op_handle_2));
    Free_s_log_op_handle_CFL(input,s_log_op_handle_2);

     Printf_CFL("largest heap size %d \n",Private_heap_largest_free_block_CFL(input));
    Destroy_engine_CFL(input);
   
    Printf_CFL("Free Memory %d \n",freeMemory());    
}