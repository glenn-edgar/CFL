/*
  change test 1 so that data is used instead of an evet


*/




#include "test_column_data.h"
#include "CFL_user_functions.h"
#include "test_interface_functions.h"

static void column_data_test_a(Handle_config_CFL_t* config_handle);
static void column_data_test_b(Handle_config_CFL_t* config_handle);



void test_column_data(void) {



  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  Printf_CFL("test_allocation");


  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;

  column_data_test_a(config_handle);
  column_data_test_b(config_handle);
  
}
  static const char *column_data_test = "this is the column data test";
  static void column_data_fn(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    char *column_data = (char *)Get_current_column_local_data_CFL(input);
    Printf_CFL("user data for column_data_test %s \n",column_data);


  }
static void column_data_test_a(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "column_data_test"};
    Asm_columns_CFL(input,1,column_names);
    Store_one_shot_function_CFL(input,"column_data_handler",column_data_fn);

   /* 
    Defining Column "column_data_test"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "column_data_test", true);
    Asm_log_message_CFL(input,"starting column_event_test");
    Asm_store_current_column_local_data_CFL(input,(void*) column_data_test);
    Asm_one_shot_CFL(input,"column_data_handler",NULL);
    Asm_log_message_CFL(input,"ending column_event_test");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("nil");
}
  static const char *column_data_test_1 = "this is the column data test 1";
  static const char *column_data_test_2 = "this is the column data test 2";
  static void column_data_fn_b(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    char *column_data = (char *)Get_current_column_local_data_CFL(input);
    Printf_CFL("user data for column_data_test %s \n",column_data);


  }
static void column_data_test_b(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "column_send","column_receive_1","column_receive_2"};
    Asm_columns_CFL(input,3,column_names);
    Store_one_shot_function_CFL(input,"column_data_handler_b",column_data_fn_b);

   /* 
    Defining Column "column_send"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "column_send", true);
    Asm_log_message_CFL(input,"starting column_set ");
    const char* send_columns[] = {"column_receive_1","column_receive_2"};
    void* send_data[] = {(void *)"this is the column data test 1",(void *)"this is the column data test 2"};
    Asm_store_columns_local_data_CFL(input, 2, send_columns, send_data);
    Asm_log_message_CFL(input,"ending column_set");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "column_receive_1"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "column_receive_1", true);
    Asm_log_message_CFL(input,"starting column_receive_1");
    Asm_one_shot_CFL(input,"column_data_handler_b",NULL);
    Asm_log_message_CFL(input,"ending column_receive_1");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "column_receive_2"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "column_receive_2", true);
    Asm_log_message_CFL(input,"starting column_receive_2");
    Asm_one_shot_CFL(input,"column_data_handler_b",NULL);
    Asm_log_message_CFL(input,"ending column_receive_2");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("nil");
}
