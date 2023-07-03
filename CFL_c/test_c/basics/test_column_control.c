#include "test_column_control.h"
#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

static void test_enable_disable_columns(Handle_config_CFL_t* config_handle);
static void test_join_columns_no_terminate(Handle_config_CFL_t* config_handle);
static void test_join_columns_terminate(Handle_config_CFL_t* config_handle);

static void test_if_columns_normal_case(Handle_config_CFL_t* config_handle);
static void test_if_columns_terminate_case(Handle_config_CFL_t* config_handle);

static void test_try_no_invert_pass(Handle_config_CFL_t* config_handle);
static void test_try_no_invert_fail(Handle_config_CFL_t* config_handle);
static void test_try_invert(Handle_config_CFL_t* config_handle);
static void test_try_termination(Handle_config_CFL_t* config_handle);


static void test_while_column_no_termination(Handle_config_CFL_t* config_handle);
static void test_while_column_termination(Handle_config_CFL_t* config_handle);


void test_column_control() {





  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  Printf_CFL("column control test\n");
  

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
  test_if_columns_normal_case(config_handle);
  test_if_columns_terminate_case(config_handle);
  
  test_try_no_invert_pass(config_handle);
  test_try_no_invert_fail(config_handle);
  test_try_invert(config_handle);
  test_try_termination(config_handle);
  test_while_column_no_termination(config_handle);
  test_while_column_termination(config_handle);
 
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
    Asm_log_message_CFL(input,"column to reset will print message and terminate");
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
/*
** If opcode tests
*/

static void test_if_function(void* input, If_control_CFL_t* if_control) {
  // enable only even columns
  bool* enable_ptr = if_control->return_indexes;

  for (unsigned i = 0; i < if_control->column_number; i++) {
    if (i % 2 == 0) {
      *enable_ptr = true;
    }
    else {
      *enable_ptr = false;
    }
    enable_ptr++;
  }
}
#if 0
typedef struct If_control_CFL_t
{
  bool termination_flag;
  bool init_flag;
  unsigned short column_number;
  unsigned short* column_indexes;
  bool* return_indexes;
  One_shot_function_CFL_t termination_fn;
  void* user_data;
} If_control_CFL_t;
#endif

const char* try_user_data = "try_user_data";

static void final_try_function(void *input, void *params, Event_data_CFL_t *event_data) {
   If_control_CFL_t* if_control = (If_control_CFL_t*)params;

   printf("final_try_function called\n");
   for(unsigned i = 0; i < if_control->column_number; i++) {
     printf("if_control->return_indexes[%d] = %d\n", i, if_control->return_indexes[i]) ;
   }
   printf("user data is %s\n", (char*)if_control->user_data);

}

static void test_if_columns_normal_case(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    Store_if_function_CFL(input,"local_if_function",test_if_function);
    Store_one_shot_function_CFL(input,"final_try_function",final_try_function);
    // define the column list
    const char * column_names[] = {
        "if_column","test_if_0","test_if_1","test_if_2","test_if_3","test_if_4","test_if_5"};
    Asm_columns_CFL(input,7,column_names);

   /* 
    Defining Column "if_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "if_column", true);
    Asm_log_message_CFL(input,"if normal case");
    Asm_log_message_CFL(input,"if column is active");
    const char* col_name[] = {"test_if_0","test_if_1","test_if_2","test_if_3","test_if_4","test_if_5"};
    Asm_if_columns_CFL(input,"local_if_function",6,col_name,"final_try_function",(void*)try_user_data);
    Asm_log_message_CFL(input,"if column is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_0", false);
    Asm_log_message_CFL(input,"test_if_0 should be active");
    Asm_log_message_CFL(input,"will wait 2 seconds and terminate");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"test_if_0 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_1", false);
    Asm_log_message_CFL(input,"test_if_1 should not be active");
    Asm_log_message_CFL(input,"will wait 3 seconds and terminate");
    Asm_wait_time_delay_CFL(input,3000);
    Asm_log_message_CFL(input,"test_if_1 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_2", false);
    Asm_log_message_CFL(input,"test_if_2 should be active");
    Asm_log_message_CFL(input,"will wait 4 seconds and terminate");
    Asm_wait_time_delay_CFL(input,4000);
    Asm_log_message_CFL(input,"test_if_2 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_3"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_3", false);
    Asm_log_message_CFL(input,"test_if_0 should not be active");
    Asm_log_message_CFL(input,"will wait 5 seconds to ");
    Asm_wait_time_delay_CFL(input,5000);
    Asm_log_message_CFL(input,"test_if_3 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_4"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_4", false);
    Asm_log_message_CFL(input,"test_if_4 should be active");
    Asm_log_message_CFL(input,"will wait 6 seconds and terminate");
    Asm_wait_time_delay_CFL(input,6000);
    Asm_log_message_CFL(input,"test_if_4 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_5"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_5", false);
    Asm_log_message_CFL(input,"test_if_5 should not be active");
    Asm_log_message_CFL(input,"will wait 7 seconds and reset");
    Asm_wait_time_delay_CFL(input,7000);
    Asm_log_message_CFL(input,"test_if_5 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
static void test_if_columns_terminate_case(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    // define the column list
    const char * column_names[] = {
        "early_termination","if_column","test_if_0","test_if_1","test_if_2","test_if_3","test_if_4","test_if_5"};
    Asm_columns_CFL(input,8,column_names);
    Store_if_function_CFL(input,"local_if_function",test_if_function);

   /* 
    Defining Column "early_termination"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "early_termination", true);
    Asm_log_message_CFL(input,"test to set that if_column cleans up sub chains on termination");
    Asm_log_message_CFL(input,"early_termination is active");
    const char* early_termination_column_names[] = {"if_column"};
    Asm_enable_columns_CFL(input,1,early_termination_column_names,true);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"early_termination is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "if_column"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "if_column", false);
    Asm_log_message_CFL(input,"if column is active");
    const char* if_column_name[] = {"test_if_0","test_if_1","test_if_2","test_if_3","test_if_4","test_if_5"};
    Asm_if_columns_CFL(input,"local_if_function",6,if_column_name,"NULL",NULL);
    Asm_log_message_CFL(input,"if column is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_0", false);
    Asm_log_message_CFL(input,"test_if_0 should be active");
    Asm_log_message_CFL(input,"will wait 2 seconds and terminate");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"test_if_0 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_1", false);
    Asm_log_message_CFL(input,"test_if_1 should not be active");
    Asm_log_message_CFL(input,"will wait 3 seconds and terminate");
    Asm_wait_time_delay_CFL(input,3000);
    Asm_log_message_CFL(input,"test_if_1 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_2", false);
    Asm_log_message_CFL(input,"test_if_2 should be active");
    Asm_log_message_CFL(input,"will wait 4 seconds and terminate");
    Asm_wait_time_delay_CFL(input,4000);
    Asm_log_message_CFL(input,"test_if_2 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_3"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_3", false);
    Asm_log_message_CFL(input,"test_if_0 should not be active");
    Asm_log_message_CFL(input,"will wait 5 seconds to ");
    Asm_wait_time_delay_CFL(input,5000);
    Asm_log_message_CFL(input,"test_if_3 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_4"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_4", false);
    Asm_log_message_CFL(input,"test_if_4 should be active");
    Asm_log_message_CFL(input,"will wait 6 seconds and terminate");
    Asm_wait_time_delay_CFL(input,6000);
    Asm_log_message_CFL(input,"test_if_4 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_if_5"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_if_5", false);
    Asm_log_message_CFL(input,"test_if_5 should not be active");
    Asm_log_message_CFL(input,"will wait 7 seconds and reset");
    Asm_wait_time_delay_CFL(input,7000);
    Asm_log_message_CFL(input,"test_if_5 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
static void test_try_function(void* input, Try_column_CFL_t* try_control) {

  Printf_CFL("%s final state %d column index %d \n", __func__,
    try_control->final_state, try_control->current_column_index);
}
static void test_try_no_invert_pass(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    Store_try_function_CFL(input,"test_try_function",test_try_function);
    // define the column list
    const char * column_names[] = {
        "try_column","try_0","try_1","try_2"};
    Asm_columns_CFL(input,4,column_names);

   /* 
    Defining Column "try_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "try_column", true);
    Asm_log_message_CFL(input,"test where there is success in one of the try columns");
    Asm_log_message_CFL(input,"try column is active");
    const char* try_name[] = {"try_0","try_1","try_2"};
    Asm_try_columns_CFL(input,"test_try_function",3,try_name,false,NULL);
    Asm_log_message_CFL(input,"try column is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_0", false);
    Asm_log_message_CFL(input,"try_0 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"try_0 is terminating with failure");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_1", false);
    Asm_log_message_CFL(input,"try_1 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"try_1 is terminating with success");
    Asm_set_return_code(input,true);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_2", false);
    Asm_log_message_CFL(input,"try_2 should not be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"try_2 is terminating");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
static void test_try_no_invert_fail(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    Store_try_function_CFL(input,"test_try_function",test_try_function);
    // define the column list
    const char * column_names[] = {
        "try_column","try_0","try_1","try_2"};
    Asm_columns_CFL(input,4,column_names);

   /* 
    Defining Column "try_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "try_column", true);
    Asm_log_message_CFL(input,"test when all try columns fail");
    Asm_log_message_CFL(input,"try column is active");
    const char* try_name[] = {"try_0","try_1","try_2"};
    Asm_try_columns_CFL(input,"test_try_function",3,try_name,false,NULL);
    Asm_log_message_CFL(input,"try column is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_0", false);
    Asm_log_message_CFL(input,"try_0 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"test_0 is terminating failure");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_1", false);
    Asm_log_message_CFL(input,"try_1 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"try_1 is terminating failure");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_2", false);
    Asm_log_message_CFL(input,"try_2 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"try_2 is terminating failure");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
static void test_try_invert(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    Store_try_function_CFL(input,"test_try_function",test_try_function);
    // define the column list
    const char * column_names[] = {
        "try_column","try_0","try_1","try_2"};
    Asm_columns_CFL(input,4,column_names);

   /* 
    Defining Column "try_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "try_column", true);
    Asm_log_message_CFL(input,"test of invert logic");
    Asm_log_message_CFL(input,"try column is active ");
    const char* try_name[] = {"try_0","try_1","try_2"};
    Asm_try_columns_CFL(input,"test_try_function",3,try_name,true,NULL);
    Asm_log_message_CFL(input,"try column is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_0", false);
    Asm_log_message_CFL(input,"try_0 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"test_0 is terminating success is failure");
    Asm_set_return_code(input,true);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_1", false);
    Asm_log_message_CFL(input,"try_1 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"try_1 is terminating failure which is success");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_2", false);
    Asm_log_message_CFL(input,"try_2 should be not be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"try_2 is terminating");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
static void test_try_termination(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    Store_try_function_CFL(input,"test_try_function",test_try_function);
    // define the column list
    const char * column_names[] = {
        "launch_column","try_column","try_0","try_1","try_2"};
    Asm_columns_CFL(input,5,column_names);

   /* 
    Defining Column "launch_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "launch_column", true);
    const char* launch_column_name[] = {"try_column"};
    Asm_enable_columns_CFL(input,1,launch_column_name,true);
    Asm_log_message_CFL(input,"test to see if try column terminates columns which are active when column terminates");
    Asm_log_message_CFL(input,"waiting for 2 seconds");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"timer is done");
    Asm_log_message_CFL(input,"Disabling Column");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "try_column", true);
    Asm_log_message_CFL(input,"try column is active");
    const char* try_name[] = {"try_0","try_1","try_2"};
    Asm_try_columns_CFL(input,"test_try_function",3,try_name,false,NULL);
    Asm_log_message_CFL(input,"try column is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_0", false);
    Asm_log_message_CFL(input,"try_0 should be active");
    Asm_wait_time_delay_CFL(input,5000);
    Asm_log_message_CFL(input,"test_0 is terminating");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_1", false);
    Asm_log_message_CFL(input,"try_1 should be active");
    Asm_wait_time_delay_CFL(input,6000);
    Asm_log_message_CFL(input,"try_1 is terminating");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "try_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "try_2", false);
    Asm_log_message_CFL(input,"try_2 should be active");
    Asm_wait_time_delay_CFL(input,7000);
    Asm_log_message_CFL(input,"try_2 is terminating");
    Asm_set_return_code(input,false);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
static const char* while_message = "This is a test message for while \n";

static bool while_column_test(void* input, void* params,
  Event_data_CFL_t* event_data) {
  While_column_control_CFL_t* while_control;
  const char* message;

  while_control = (While_column_control_CFL_t*)params;
  message = (const char*)while_control->user_data;
  Printf_CFL(message); // testing user data
 
  Printf_CFL("number of iterations %d max_iterations 4 \n",while_control->current_iterations);
  if (while_control->current_iterations >= 4) {
    Printf_CFL("while column is terminating \n");
    return false;
  }
  return true;
}
static void test_while_column_no_termination(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    // define the column list
    const char * column_names[] = {
        "test_while","while_0","while_1","while_2"};
    Asm_columns_CFL(input,4,column_names);
    Store_bool_function_CFL(input,"while_column_test",while_column_test);

   /* 
    Defining Column "test_while"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "test_while", true);
    Asm_log_message_CFL(input,"starting while command");
    const char* while_columns[] = {"while_0","while_1","while_2"};
     Asm_while_columns_CFL(input,"while_column_test",3,while_columns,(void*)while_message);
    Asm_log_message_CFL(input,"done with while statement");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_0", false);
    Asm_log_message_CFL(input,"while_0 should be active");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"while_0 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_1", false);
    Asm_log_message_CFL(input,"while_1 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"while_1 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_2", false);
    Asm_log_message_CFL(input,"while_2 should be active");
    Asm_wait_time_delay_CFL(input,3000);
    Asm_log_message_CFL(input,"while_2 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
static void test_while_column_termination(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,2500);

    // define the column list
    const char * column_names[] = {
        "early_terminate","test_while","while_0","while_1","while_2"};
    Asm_columns_CFL(input,5,column_names);
    Store_bool_function_CFL(input,"while_column_test",while_column_test);

   /* 
    Defining Column "early_terminate"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "early_terminate", true);
    Asm_log_message_CFL(input,"early terminate");
    Asm_wait_time_delay_CFL(input,500);
    const char* early_terminate_columns[] = {"test_while"};
    Asm_disable_columns_CFL(input,1,early_terminate_columns);
    Asm_log_message_CFL(input,"early_terminate is done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_while"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "test_while", true);
    Asm_log_message_CFL(input,"starting while command");
    const char* while_columns[] = {"while_0","while_1","while_2"};
     Asm_while_columns_CFL(input,"while_column_test",3,while_columns,(void*)while_message);
    Asm_log_message_CFL(input,"done with while statement");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_0"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_0", false);
    Asm_log_message_CFL(input,"while_0 should be active");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"while_0 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_1"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_1", false);
    Asm_log_message_CFL(input,"while_1 should be active");
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"while_1 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_2"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_2", false);
    Asm_log_message_CFL(input,"while_2 should be active");
    Asm_wait_time_delay_CFL(input,3000);
    Asm_log_message_CFL(input,"while_2 is terminating");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("Engine Done\n\n");
}
