#include "test_column_control.h"
#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

static void test_enable_disable_columns(Handle_config_CFL_t* config_handle);

static void test_join_columns_no_terminate(Handle_config_CFL_t* config_handle);
static void test_join_columns_terminate(Handle_config_CFL_t* config_handle);
static void test_if_columns_normal_case(Handle_config_CFL_t* config_handle);
static void test_if_columns_terminate_case(Handle_config_CFL_t* config_handle);
static void
test_if_columns_non_terminate_case(Handle_config_CFL_t* config_handle);
static void test_try_no_invert_pass(Handle_config_CFL_t* config_handle);
static void test_try_no_invert_fail(Handle_config_CFL_t* config_handle);
static void test_try_invert(Handle_config_CFL_t* config_handle);
static void test_try_termination(Handle_config_CFL_t* config_handle);
static void test_try_no_termination(Handle_config_CFL_t* config_handle);
static void test_for_no_termination(Handle_config_CFL_t* config_handle);
static void test_for_termination(Handle_config_CFL_t* config_handle);
static void
test_while_column_no_termination(Handle_config_CFL_t* config_handle);
static void test_while_column_termination(Handle_config_CFL_t* config_handle);
static void
test_do_while_column_no_termination(Handle_config_CFL_t* config_handle);
static void
test_do_while_column_termination(Handle_config_CFL_t* config_handle);

void test_column_control() {





  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  Printf_CFL("column control test");
  

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;



  



  test_enable_disable_columns(config_handle);
  test_join_columns_no_terminate(config_handle);
  test_join_columns_terminate(config_handle);
  //test_if_columns_normal_case(config_handle);
  //test_if_columns_terminate_case(config_handle);
  //test_if_columns_non_terminate_case(config_handle);
  //test_try_no_invert_pass(config_handle);
  //test_try_no_invert_fail(config_handle);
  //test_try_invert(config_handle);
  //test_try_termination(config_handle);
  //test_try_no_termination(config_handle);
  //test_for_no_termination(config_handle);
  //test_for_termination(config_handle);
  //test_while_column_no_termination(config_handle);
  //test_while_column_termination(config_handle);
  //test_do_while_column_no_termination(config_handle);
  //test_do_while_column_termination(config_handle);
  free(config_handle);
}
static void test_enable_disable_columns(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    // define the column list
    const char * column_names[] = {
        "enable_no_terminate","enable_terminate","disable_column","reset_column","column_to_reset"};
    Asm_columns_CFL(input,5,column_names);

   /* 
    Defining Column "enable_no_terminate"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "enable_no_terminate", true);
    const char* enable_terminate[] = {"enable_terminate"};
    Asm_enable_columns_CFL(input,1,enable_terminate,false);
    Asm_log_message_CFL(input,"terminate column");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "enable_terminate"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "enable_terminate", false);
    Asm_log_message_CFL(input,"will enable threads and wait 15 seconds and terminate");
    const char* enable_columns[] = {"disable_column","reset_column","column_to_reset"};
    Asm_enable_columns_CFL(input,3,enable_columns,true);
    Asm_wait_time_delay_CFL(input,15000);
    Asm_log_message_CFL(input,"timer is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "disable_column"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "disable_column", false);
    Asm_log_message_CFL(input,"will disable reset column after 7 seconds");
    Asm_wait_time_delay_CFL(input,7000);
    const char* disable_columns[] = {"reset_column","column_to_reset"};
    Asm_disable_columns_CFL(input,2,disable_columns);
    Asm_log_message_CFL(input,"Now will wait till enable_terminate column terminates this column");
     Asm_wait_CFL(input,"FALSE", NO_TIME_OUT_CFL,false,NULL,NULL);
    Asm_log_message_CFL(input,"-------------- message should not happen ----------------------");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "reset_column"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "reset_column", false);
    Asm_log_message_CFL(input,"Repeating Message Every 3 Seconds");
    const char* column_to_reset[] = {"column_to_reset"};
    Asm_reset_columns_CFL(input,1,column_to_reset);
    Asm_wait_time_delay_CFL(input,3000);
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "column_to_reset"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "column_to_reset", false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("done with test_enable_disable_columns\n");
}
static void test_join_columns_terminate(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    // define the column list
    const char * column_names[] = {
        "test_join","delay_terminate"};
    Asm_columns_CFL(input,2,column_names);

   /* 
    Defining Column "test_join"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "test_join", true);
    const char* delay_terminate_enable[] = {"delay_terminate"};
    Asm_enable_columns_CFL(input,1,delay_terminate_enable,false);
    Asm_log_message_CFL(input,"waiting for join");
    const char* delay_terminate_join[] = {"delay_terminate"};
    Asm_join_columns_CFL(input,1,delay_terminate_join,true);
    Asm_log_message_CFL(input,"Column has been joined");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "delay_terminate"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "delay_terminate", false);
    Asm_log_message_CFL(input,"will wait 5 seconds and terminate");
    Asm_wait_time_delay_CFL(input,5000);
    Asm_log_message_CFL(input,"timer is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("done with test_join_columns_terminate\n");
}
static void test_join_columns_no_terminate(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    // define the column list
    const char * column_names[] = {
        "launch_column","test_join","delay_terminate"};
    Asm_columns_CFL(input,3,column_names);

   /* 
    Defining Column "launch_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "launch_column", true);
    const char* test_join[] = {"test_join"};
    Asm_enable_columns_CFL(input,1,test_join,true);
    Asm_log_message_CFL(input,"Waiting for 15 seconds");
    Asm_wait_time_delay_CFL(input,15000);
    Asm_log_message_CFL(input,"15 seconds is up");
    Asm_log_message_CFL(input,"Disabling Column");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_join"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_join", false);
    const char* delay_terminate_enable[] = {"delay_terminate"};
    Asm_enable_columns_CFL(input,1,delay_terminate_enable,false);
    Asm_log_message_CFL(input,"waiting for join");
    const char* delay_terminate_join[] = {"delay_terminate"};
    Asm_join_columns_CFL(input,1,delay_terminate_join,true);
    Asm_log_message_CFL(input,"Column has been joined");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "delay_terminate"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "delay_terminate", false);
    Asm_log_message_CFL(input,"will wait 5 seconds and terminate");
    Asm_wait_time_delay_CFL(input,5000);
    Asm_log_message_CFL(input,"timer is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("done with test_join_columns_no_terminate\n");
}
