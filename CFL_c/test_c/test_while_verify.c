#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

#include "test_while_verify.h"

/*
  the while and verify commands are have various setup up conditions
  this is what there are many tests for these commands




*/


static void run_while_event_normal_test_a(Handle_config_CFL_t* config_handle);
static void run_while_event_normal_test_b(Handle_config_CFL_t* config_handle);
static void run_while_event_time_out_terminate_test(Handle_config_CFL_t* config_handle);
static void  run_while_event_time_out_reset_test(Handle_config_CFL_t* config_handle);
static void test_verify_opcode(Handle_config_CFL_t* config_handle);
static void test_while_opcode(Handle_config_CFL_t* config_handle);
static void test_while_time_out(Handle_config_CFL_t* config_handle);




void test_while_verify(void) {

  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  


  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;
  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  config_handle->debug_out = debug_write;
   
  run_while_event_normal_test_a(config_handle);
  run_while_event_normal_test_b(config_handle);
  run_while_event_time_out_reset_test(config_handle);
  run_while_event_time_out_terminate_test(config_handle);
  test_verify_opcode(config_handle);
  test_while_opcode(config_handle);
  test_while_time_out(config_handle);
}

/*

 while event test with no time out
 column1 tests


*/


static void run_while_event_normal_test_a(Handle_config_CFL_t* config_handle) {

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "wait_event","generate_event"};
    Asm_columns_CFL(input,2,column_names);
    Event_data_CFL_t my_event_data = { 23, 45, NULL};

   /* 
    Defining Column "generate_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "generate_event", true);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&my_event_data);
    Asm_log_message_CFL(input,"event has been sent");
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "wait_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "wait_event", true);
    Asm_log_message_CFL(input,"waiting for event");
    Asm_wait_event_count_CFL(input, 23, 10, NO_TIME_OUT_CFL, false, NULL, NULL);
    Asm_log_message_CFL(input,"Wait Event is Done");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Printf_CFL("Engine Done \n");
  Destroy_engine_CFL(input);
  
}
static void run_while_event_normal_test_b(Handle_config_CFL_t* config_handle) {

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "wait_event","generate_event"};
    Asm_columns_CFL(input,2,column_names);
    Event_data_CFL_t my_event_data = { 23, 45, NULL};

   /* 
    Defining Column "generate_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "generate_event", true);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&my_event_data);
    Asm_log_message_CFL(input,"event has been sent");
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     
    // This column has a time out but still should complete before timeout 

   /* 
    Defining Column "wait_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "wait_event", true);
    Asm_log_message_CFL(input,"waiting for event");
    Asm_wait_event_count_CFL(input, 23, 10,50000, false, NULL, NULL);
    Asm_log_message_CFL(input,"Wait Event is Done");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Printf_CFL("Engine Done\n");
  Destroy_engine_CFL(input);
 
}

 

static const char* test_while_time_out_data = "This is my private data";
static void test_while_time_out(void* input, void* params,
  Event_data_CFL_t* event_data) {
  While_event_control_CFL_t* data;
  data = (While_event_control_CFL_t*)params;
  Printf_CFL("\n\n While Event time out \n expected number of events %d "
    "actual events %d \n",
    data->number_of_events, data->current_count);
  Printf_CFL("terminate flag %d \n", data->terminate_flag);
  Printf_CFL("User data -->%s \n\n", (const char*)data->user_data);
}

static void
run_while_event_time_out_reset_test(Handle_config_CFL_t* config_handle) {

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "terminate_engine","wait_event","generate_event"};
    Asm_columns_CFL(input,3,column_names);
    Event_data_CFL_t my_event_data = { 23, 45, NULL};
    Store_one_shot_function_CFL(input,"test_while_time_out",test_while_time_out);

   /* 
    Defining Column "terminate_engine"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "terminate_engine", true);
    Asm_wait_time_delay_CFL(input,10000);
    Asm_log_message_CFL(input,"terminate_engine");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "generate_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "generate_event", true);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&my_event_data);
    Asm_log_message_CFL(input,"event has been sent");
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     
    // This column has a time out but will not complete and generate a reset

   /* 
    Defining Column "wait_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "wait_event", true);
    Asm_log_message_CFL(input,"column is starting again to reset");
    Asm_wait_event_count_CFL(input, 23, 10,2000, false, "test_while_time_out", (void*)test_while_time_out_data);
    Asm_log_message_CFL(input,"Wait Event is Done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

 Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);


  Printf_CFL("Engine Done \n");
  Destroy_engine_CFL(input);
}
static void
run_while_event_time_out_terminate_test(Handle_config_CFL_t* config_handle) {


    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "terminate_engine","wait_event","generate_event"};
    Asm_columns_CFL(input,3,column_names);
    Event_data_CFL_t my_event_data = { 23, 45, NULL};
    Store_one_shot_function_CFL(input,"test_while_time_out",test_while_time_out);

   /* 
    Defining Column "terminate_engine"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "terminate_engine", true);
    Asm_wait_time_delay_CFL(input,10000);
    Asm_log_message_CFL(input,"terminate_engine");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "generate_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "generate_event", true);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&my_event_data);
    Asm_log_message_CFL(input,"event has been sent");
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     
    // This column has a time out but will not complete and generate a reset

   /* 
    Defining Column "wait_event"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "wait_event", true);
    Asm_log_message_CFL(input,"column is starting should terminate");
    Asm_wait_event_count_CFL(input, -23, 10,2000,true, "test_while_time_out", (void*)test_while_time_out_data);
    Asm_log_message_CFL(input,"Wait Event is Done");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Printf_CFL("Engine Done \n");
  Destroy_engine_CFL(input);
  
}
/*
**
** Verify opcode
*/

typedef struct Verify_User_Data_t {

  short target_event;
  unsigned target_event_count;
  unsigned current_event_count;
  const char* message;
} Verify_User_Data_t;

static void verify_end(void* input, void* params,
  Event_data_CFL_t* event_data) {
  Verify_User_Data_t* user_data;
  user_data = (Verify_User_Data_t*)params;
  Printf_CFL("---------------->verify end %s \n", user_data->message);
}

static bool verify_test(void* input, void* params,
  Event_data_CFL_t* event_data) {
  Verify_User_Data_t* user_data;
  user_data = (Verify_User_Data_t*)params;

  if (event_data->event_index == EVENT_INIT_CFL) {
    user_data->current_event_count = 0;
   
  }
  if (event_data->event_index == user_data->target_event) {

    user_data->current_event_count += 1;

    if (user_data->current_event_count == user_data->target_event_count) {
      return false;
    }
  }
  return true;
}

static void test_verify_opcode(Handle_config_CFL_t* config_handle) {

  
  Verify_User_Data_t verify_user_data_reset;
  verify_user_data_reset.target_event = 23;
  verify_user_data_reset.target_event_count = 10;
  verify_user_data_reset.message = "-----------------> reset event";

  Verify_User_Data_t verify_user_data_terminate;
  verify_user_data_terminate.target_event = 23;
  verify_user_data_terminate.target_event_count = 5;
  verify_user_data_terminate.message = "-------------> termination event";
 
    void* input = Configure_engine_CFL(config_handle,50000,2500);

    // define the column list
    const char * column_names[] = {
        "terminate_engine","event_generator","verify_reset","verify_terminate"};
    Asm_columns_CFL(input,4,column_names);
    Event_data_CFL_t my_event_data = { 23, 45, NULL};
    Store_bool_function_CFL(input,"VERIFY_COUNT_EVENT",verify_test);
    Store_one_shot_function_CFL(input,"VERIFY_END",verify_end);

   /* 
    Defining Column "terminate_engine"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "terminate_engine", true);
    Asm_log_message_CFL(input,"terminate engine start");
    Asm_wait_time_delay_CFL(input,50000);
    Asm_log_message_CFL(input,"wait done");
    Asm_log_message_CFL(input,"stop engine");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "event_generator"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "event_generator", true);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&my_event_data);
    Asm_log_message_CFL(input,"event has been sent");
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "verify_reset"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "verify_reset", true);
    Asm_log_message_CFL(input,"verify terminate column");
    Asm_log_message_CFL(input,"this column will reset");
    Asm_verify_CFL(input,"VERIFY_COUNT_EVENT",false,"VERIFY_END",&verify_user_data_reset);
     Asm_wait_CFL(input,"FALSE", NO_TIME_OUT_CFL,false,NULL,NULL);
    Asm_log_message_CFL(input,"This should not happen");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "verify_terminate"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "verify_terminate", true);
    Asm_log_message_CFL(input,"verify terminate column");
    Asm_log_message_CFL(input,"this column will terminate");
    Asm_verify_CFL(input,"VERIFY_COUNT_EVENT",true,"VERIFY_END",&verify_user_data_terminate);
     Asm_wait_CFL(input,"FALSE", NO_TIME_OUT_CFL,false,NULL,NULL);
    Asm_log_message_CFL(input,"This should not happen");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

  Printf_CFL("starting engine");
  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Printf_CFL("Engine Done \n");
  Destroy_engine_CFL(input);
  
}
/*
**
** while opcode
*/

typedef struct While_User_Data_t {

  short target_event;
  unsigned target_event_count;
  unsigned current_event_count;
  const char* message;
} While_User_Data_t;

static void while_end(void* input, void* params, Event_data_CFL_t* event_data) {
  While_User_Data_t* user_data;
  user_data = (While_User_Data_t*)params;
  Printf_CFL("---------------->while end %s \n", user_data->message);
}

static bool while_test(void* input, void* params,
  Event_data_CFL_t* event_data) {
  While_User_Data_t* user_data;
  user_data = (While_User_Data_t*)params;

  if (event_data->event_index == EVENT_INIT_CFL) {
    user_data->current_event_count = 0;
   
  }
  if (event_data->event_index == user_data->target_event) {

    user_data->current_event_count += 1;

    if (user_data->current_event_count >= user_data->target_event_count) {

      return true;
    }
  }

  return false;
}

static void test_while_opcode(Handle_config_CFL_t* config_handle) {

  void* input = Configure_engine_CFL(config_handle, 50000, 2500);
  //const char* for_array[1] = { "event_generator" };
  const char* column_names[] = { "terminate_engine", "event_generator",
                                "while_terminate", "while_reset",
                                "while_normal" };
  Event_data_CFL_t my_event_data = { 23, 45, NULL };

  While_User_Data_t while_user_data_reset;
  while_user_data_reset.target_event = 23;
  while_user_data_reset.target_event_count = 10;
  while_user_data_reset.message = "-----------------> reset event";

  While_User_Data_t while_user_data_terminate;
  while_user_data_terminate.target_event = 23;
  while_user_data_terminate.target_event_count = 5;
  while_user_data_terminate.message = "-------------> termination event";

  While_User_Data_t while_user_data_normal;
  while_user_data_normal.target_event = 23;
  while_user_data_normal.target_event_count = 13;
  while_user_data_terminate.message = "-------------> termination event";


  Store_bool_function_CFL(input, "while_test", while_test);
  Store_one_shot_function_CFL(input, "while_end", while_end);

  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "terminate_engine", true);
  Asm_log_message_CFL(input, "terminate engine");
  Asm_wait_time_delay_CFL(input, 50000);
  Asm_log_message_CFL(input, "time delay done");
  Asm_log_message_CFL(input, "terminate_engine");
  Asm_engine_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "event_generator", true);
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "generate_event");
  Asm_send_event_CFL(input, &my_event_data);
  Asm_reset_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_terminate", true);
  Asm_log_message_CFL(input, "verify_terminate");
  Asm_wait_CFL(input, "FALSE", 1000, true, "while_end",
    &while_user_data_terminate);
  Asm_log_message_CFL(input, "this message should not happen");
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_reset", true);
  Asm_log_message_CFL(input, "while_reset");
  Asm_wait_CFL(input, "FALSE", 7000, false, "while_end",
    &while_user_data_reset);
  Asm_log_message_CFL(input, "this message should not happen");
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_normal", true);
  Asm_log_message_CFL(input, "while_normal");
  Asm_wait_CFL(input, "while_test", NO_TIME_OUT_CFL, false, NULL,
    &while_user_data_normal);
  Asm_log_message_CFL(input, "This message will hapen");
  Asm_end_column_CFL(input);

  Printf_CFL("starting engine");
  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Printf_CFL("Engine Done \n");
  Destroy_engine_CFL(input);
 
}
static void test_while_time_out(Handle_config_CFL_t* config_handle) {


    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "reset_loop","terminate_engine"};
    Asm_columns_CFL(input,2,column_names);

   /* 
    Defining Column "terminate_engine"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "terminate_engine", true);
    Asm_wait_time_delay_CFL(input,10000);
    Asm_log_message_CFL(input,"time delay done");
    Asm_log_message_CFL(input,"stop engine");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "reset_loop"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "reset_loop", true);
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"wait reset");
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     
  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Printf_CFL("Engine Done \n");
  Destroy_engine_CFL(input);
  
}
