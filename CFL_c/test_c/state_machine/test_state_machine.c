#include "test_state_machine.h"
#include "Cfl_user_functions.h"
#include "test_interface_functions.h"


static void test_state_machine_a(Handle_config_CFL_t* config_handle);
static void test_state_machine_b(Handle_config_CFL_t* config_handle);
static void test_state_machine_c(Handle_config_CFL_t* config_handle);
static void test_state_machine_d(Handle_config_CFL_t* config_handle);

void test_state_machine(void) {





  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  Printf_CFL("column control test\n");
  

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  config_handle->number_of_state_machines = 10;
  config_handle->number_of_named_queues = 50;


  



  //test_state_machine_a(config_handle);
 // test_state_machine_b(config_handle);
 // test_state_machine_c(config_handle);
  test_state_machine_d(config_handle);
  free(config_handle);
}

static const char *test_data = "test_data for test_state_machine_a";
static const char *state1_data = "state1_data for test_state_machine_a";
static const char *state2_data = "state2_data for test_state_machine_a";
static const char *state3_data = "state3_data for test_state_machine_a";

static void display_sm_user_data(void *input, void *params,Event_data_CFL_t *event_data) {
     Printf_CFL("display_sm_user_data: %s\n", (char*)Sms_get_user_data_CFL(input,0));
}


static void test_state_machine_a(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,200000,2500);

    Store_one_shot_function_CFL(input,"DISPLAY_SM_USER_DATA",display_sm_user_data);
    // define the column list
    const char * start_column_names[] = {"start_column"};
    Asm_columns_CFL(input,1,start_column_names);
    static const char *sm_array_name[] = { "test_sm" };
    Define_state_machines_CFL(input, 1, sm_array_name);
    // define the column list
    const char * test_sm_column_array[] = {"test_sm_manager_chain","test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain"};
    Asm_columns_CFL(input,4,test_sm_column_array);
    Define_named_event_queue_CFL(input,"test_sm_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state1_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state2_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state3_queue",10);
    static const char *test_sm_state_array[] = {"test_state1","test_state2","test_state3"};
    Asm_define_state_machine_CFL(input,"test_sm",3,test_sm_state_array,"test_sm_manager_chain","test_sm_queue","test_state1",(void *)test_data);
    Asm_define_state_CFL(input,"test_state1","test_sm_test_state1_chain","test_sm_test_state1_queue");
    Asm_define_state_CFL(input,"test_state2","test_sm_test_state2_chain","test_sm_test_state2_queue");
    Asm_define_state_CFL(input,"test_state3","test_sm_test_state3_chain","test_sm_test_state3_queue");
    Asm_end_state_machine_CFL(input);

   /* 
    Defining Column "test_sm_manager_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_manager_chain", false,"test_sm_queue");
    Asm_log_message_CFL(input,"state machine manager starting");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state1_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state1_chain", false,"test_sm_test_state1_queue");
    Asm_log_message_CFL(input,"test_state1 starting");
    Asm_sms_set_user_data_CFL(input,"test_sm",(void *)state1_data);
    Asm_one_shot_CFL(input,"DISPLAY_SM_USER_DATA",NULL);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state2");
    Asm_change_state_CFL(input,"test_sm","test_state2");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state2_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state2_chain", false,"test_sm_test_state2_queue");
    Asm_log_message_CFL(input,"test_state2 starting");
    Asm_sms_set_user_data_CFL(input,"test_sm",(void *)state2_data);
    Asm_one_shot_CFL(input,"DISPLAY_SM_USER_DATA",NULL);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state3");
    Asm_change_state_CFL(input,"test_sm","test_state3");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state3_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state3_chain", false,"test_sm_test_state3_queue");
    Asm_log_message_CFL(input,"test_state3 starting");
    Asm_sms_set_user_data_CFL(input,"test_sm",(void *)state3_data);
    Asm_one_shot_CFL(input,"DISPLAY_SM_USER_DATA",NULL);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state1");
    Asm_change_state_CFL(input,"test_sm","test_state1");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "start_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "start_column", true);
    Asm_log_message_CFL(input,"start column");
    Asm_dump_state_machines_CFL(input);
    const char* sm_array_name1[] = { "test_sm" };
    Asm_enable_sms_CFL(input,1,sm_array_name1);
    Asm_one_shot_CFL(input,"DISPLAY_SM_USER_DATA",NULL);
    Asm_dump_state_machines_CFL(input);
    Asm_wait_time_delay_CFL(input,10000);
    const char* sm_array_name2[] = { "test_sm" };
    Asm_disable_sms_CFL(input,1,sm_array_name2);
    Asm_wait_time_delay_CFL(input,5000);
    const char* sm_array_name3[] = { "test_sm" };
    Asm_enable_sms_CFL(input,1,sm_array_name3);
    Asm_wait_time_delay_CFL(input,10000);
    Asm_log_message_CFL(input,"terminating engine");
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("done with test_state_machine\n");
}
static void test_state_machine_b(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,200000,2500);

    Store_one_shot_function_CFL(input,"DISPLAY_SM_USER_DATA",display_sm_user_data);
    // define the column list
    const char * start_column_names[] = {"start_column"};
    Asm_columns_CFL(input,1,start_column_names);
    static const char *sm_array_name[] = { "test_sm" };
    Define_state_machines_CFL(input, 1, sm_array_name);
    // define the column list
    const char * test_sm_column_array[] = {"test_sm_manager_chain","test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain"};
    Asm_columns_CFL(input,4,test_sm_column_array);
    Define_named_event_queue_CFL(input,"test_sm_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state1_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state2_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state3_queue",10);
    static const char *test_sm_state_array[] = {"test_state1","test_state2","test_state3"};
    Asm_define_state_machine_CFL(input,"test_sm",3,test_sm_state_array,"test_sm_manager_chain","test_sm_queue","test_state1",(void *)test_data);
    Asm_define_state_CFL(input,"test_state1","test_sm_test_state1_chain","test_sm_test_state1_queue");
    Asm_define_state_CFL(input,"test_state2","test_sm_test_state2_chain","test_sm_test_state2_queue");
    Asm_define_state_CFL(input,"test_state3","test_sm_test_state3_chain","test_sm_test_state3_queue");
    Asm_end_state_machine_CFL(input);

   /* 
    Defining Column "test_sm_manager_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_manager_chain", false,"test_sm_queue");
    Asm_log_message_CFL(input,"state machine manager starting");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state1_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state1_chain", false,"test_sm_test_state1_queue");
    Asm_log_message_CFL(input,"test_state1 starting");
    Asm_sms_set_user_data_CFL(input,"test_sm",(void *)state1_data);
    Asm_one_shot_CFL(input,"DISPLAY_SM_USER_DATA",NULL);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state2");
    Asm_change_state_CFL(input,"test_sm","test_state2");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state2_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state2_chain", false,"test_sm_test_state2_queue");
    Asm_log_message_CFL(input,"test_state2 starting");
    Asm_sms_set_user_data_CFL(input,"test_sm",(void *)state2_data);
    Asm_one_shot_CFL(input,"DISPLAY_SM_USER_DATA",NULL);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state3");
    Asm_change_state_CFL(input,"test_sm","test_state3");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state3_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state3_chain", false,"test_sm_test_state3_queue");
    Asm_log_message_CFL(input,"test_state3 starting");
    Asm_sms_set_user_data_CFL(input,"test_sm",(void *)state3_data);
    Asm_one_shot_CFL(input,"DISPLAY_SM_USER_DATA",NULL);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state1");
    Asm_change_state_CFL(input,"test_sm","test_state1");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "start_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "start_column", true);
    Asm_log_message_CFL(input,"start column");
    const char* sm_array_name1[] = { "test_sm" };
    Asm_enable_disable_sms_CFL(input,1,sm_array_name1);
    Asm_wait_time_delay_CFL(input,10000);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("done with test_state_machine\n");
}

static bool event_generator_fn(void *input, void *params,Event_data_CFL_t *event_data) {
  While_column_control_CFL_t *while_control = (While_column_control_CFL_t *)params;
  if (while_control->current_iterations >= 300){
    return false;
  } 
  return true;
  
  
}
static const char *sm_event_data = "test_data for test_state_machine_c";

static void display_event_fn(void *input, void *params,Event_data_CFL_t *event_data) {
  process_event_t_CFL *process_event =(process_event_t_CFL *)params;
  char *message = (char *)process_event->user_data;
  if( message != NULL){
    Printf_CFL("message: %s  event index %d\n", message,event_data->event_index);
  }else{
  Printf_CFL("display_event_fn: %d\n", event_data->event_index);
  }
}

static void test_state_machine_c(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,200000,2500);

    Store_bool_function_CFL(input,"event_generator",event_generator_fn);
    Store_one_shot_function_CFL(input,"display_event",display_event_fn);
    Event_data_CFL_t sm_event = { 47, 56.0, (void *)sm_event_data};
    // define the column list
    const char * start_column_names[] = {"start_column","while_event_column"};
    Asm_columns_CFL(input,2,start_column_names);
    static const char *sm_array_name[] = { "test_sm" };
    Define_state_machines_CFL(input, 1, sm_array_name);
    // define the column list
    const char * test_sm_column_array[] = {"test_sm_manager_chain","test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain"};
    Asm_columns_CFL(input,4,test_sm_column_array);
    Define_named_event_queue_CFL(input,"test_sm_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state1_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state2_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state3_queue",10);
    static const char *test_sm_state_array[] = {"test_state1","test_state2","test_state3"};
    Asm_define_state_machine_CFL(input,"test_sm",3,test_sm_state_array,"test_sm_manager_chain","test_sm_queue","test_state1",(void *)test_data);
    Asm_define_state_CFL(input,"test_state1","test_sm_test_state1_chain","test_sm_test_state1_queue");
    Asm_define_state_CFL(input,"test_state2","test_sm_test_state2_chain","test_sm_test_state2_queue");
    Asm_define_state_CFL(input,"test_state3","test_sm_test_state3_chain","test_sm_test_state3_queue");
    Asm_end_state_machine_CFL(input);

   /* 
    Defining Column "test_sm_manager_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_manager_chain", false,"test_sm_queue");
    Asm_log_message_CFL(input,"state machine manager starting");
    // define the event list
    short  sm_manager_array[] = {
        47};
    Asm_filter_events_CFL(input,"display_event",1,sm_manager_array,true,NULL);
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state1_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state1_chain", false,"test_sm_test_state1_queue");
    Asm_log_message_CFL(input,"test_state1 starting");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state2");
    Asm_change_state_CFL(input,"test_sm","test_state2");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state2_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state2_chain", false,"test_sm_test_state2_queue");
    Asm_log_message_CFL(input,"test_state2 starting");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state3");
    Asm_change_state_CFL(input,"test_sm","test_state3");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state3_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state3_chain", false,"test_sm_test_state3_queue");
    Asm_log_message_CFL(input,"test_state3 starting");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state1");
    Asm_change_state_CFL(input,"test_sm","test_state1");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "start_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "start_column", true);
    Asm_log_message_CFL(input,"start column");
    const char* sm_array_name1[] = { "test_sm" };
    Asm_enable_disable_sms_CFL(input,1,sm_array_name1);
    const char* while_column_array[] = {"while_event_column"};
     Asm_while_columns_CFL(input,"event_generator",1,while_column_array,NULL);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_event_column"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_event_column", false);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_sms_send_event_CFL(input,"test_sm",&sm_event);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("done with test_state_machine\n");
}
static const char *sm_event_data_1 = "test_data_1 for test_state_machine_c";
static const char *sm_event_data_2 = "test_data_2 for test_state_machine_c";
static const char *sm_event_data_3 = "test_data_3 for test_state_machine_c";
static const char *test_data_1 = "test_data for test_state_machine_a";
static const char *test_data_2 = "test_data for test_state_machine_a";
static const char *test_data_a = "top level state machine manager";
static const char *test_data_ba = "sub state manager  ";
static const char *test_data_b = "sub state state 1";
static const char *test_data_c = "sub state state 2";
static const char *test_data_d = "sub state state 3";
static void test_state_machine_d(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,200000,2500);

    Store_bool_function_CFL(input,"event_generator",event_generator_fn);
    Store_one_shot_function_CFL(input,"display_event",display_event_fn);
    Event_data_CFL_t sm_event_1 = { 47, 56.0, (void *)sm_event_data_1};
    Event_data_CFL_t sm_event_2 = { 48, 57.0, (void *)sm_event_data_2};
    Event_data_CFL_t sm_event_3 = { 49, 58.0, (void *)sm_event_data_3};
    // define the column list
    const char * start_column_names[] = {"start_column","while_event_column"};
    Asm_columns_CFL(input,2,start_column_names);
    static const char *sm_array_name[] = { "test_sm","test_sub_state" };
    Define_state_machines_CFL(input, 2, sm_array_name);
    // define the column list
    const char * test_sm_column_array[] = {"test_sm_manager_chain","test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain"};
    Asm_columns_CFL(input,4,test_sm_column_array);
    Define_named_event_queue_CFL(input,"test_sm_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state1_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state2_queue",10);
    Define_named_event_queue_CFL(input,"test_sm_test_state3_queue",10);
    static const char *test_sm_state_array[] = {"test_state1","test_state2","test_state3"};
    Asm_define_state_machine_CFL(input,"test_sm",3,test_sm_state_array,"test_sm_manager_chain","test_sm_queue","test_state1",(void *)test_data_1);
    Asm_define_state_CFL(input,"test_state1","test_sm_test_state1_chain","test_sm_test_state1_queue");
    Asm_define_state_CFL(input,"test_state2","test_sm_test_state2_chain","test_sm_test_state2_queue");
    Asm_define_state_CFL(input,"test_state3","test_sm_test_state3_chain","test_sm_test_state3_queue");
    Asm_end_state_machine_CFL(input);
    // define the column list
    const char * test_sub_state_column_array[] = {"test_sub_state_manager_chain","test_sub_state_test_state1_chain","test_sub_state_test_state2_chain","test_sub_state_test_state3_chain"};
    Asm_columns_CFL(input,4,test_sub_state_column_array);
    Define_named_event_queue_CFL(input,"test_sub_state_queue",10);
    Define_named_event_queue_CFL(input,"test_sub_state_test_state1_queue",10);
    Define_named_event_queue_CFL(input,"test_sub_state_test_state2_queue",10);
    Define_named_event_queue_CFL(input,"test_sub_state_test_state3_queue",10);
    static const char *test_sub_state_state_array[] = {"test_state1","test_state2","test_state3"};
    Asm_define_state_machine_CFL(input,"test_sub_state",3,test_sub_state_state_array,"test_sub_state_manager_chain","test_sub_state_queue","test_state1",(void *)test_data_2);
    Asm_define_state_CFL(input,"test_state1","test_sub_state_test_state1_chain","test_sub_state_test_state1_queue");
    Asm_define_state_CFL(input,"test_state2","test_sub_state_test_state2_chain","test_sub_state_test_state2_queue");
    Asm_define_state_CFL(input,"test_state3","test_sub_state_test_state3_chain","test_sub_state_test_state3_queue");
    Asm_end_state_machine_CFL(input);

   /* 
    Defining Column "test_sm_manager_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_manager_chain", false,"test_sm_queue");
    Asm_log_message_CFL(input,"------------top level state machine manager starting");
    // define the event list
    short  filtered_events[] = {
        47,48,49};
    Asm_filter_events_CFL(input,"display_event",3,filtered_events,false,(void *)test_data_a);
    Asm_transfer_events_to_state_CFL(input,"test_sm",0,NULL);
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state1_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state1_chain", false,"test_sm_test_state1_queue");
    Asm_log_message_CFL(input,"test_state1 starting");
    const char* test_state_1_sm_names[] = { "test_sub_state" };
    Asm_enable_disable_sms_CFL(input,1,test_state_1_sm_names);
    Asm_transfer_events_to_sm_CFL(input,"test_sub_state",0,NULL);
    Asm_log_message_CFL(input,"waiting 15 seconds");
    Asm_wait_time_delay_CFL(input,15000);
    Asm_log_message_CFL(input,"sub state machine test_sub_state is now disabled");
    Asm_log_message_CFL(input,"changing state to test_state2");
    Asm_change_state_CFL(input,"test_sm","test_state2");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state2_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state2_chain", false,"test_sm_test_state2_queue");
    Asm_log_message_CFL(input,"test_state2 starting");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state3");
    Asm_change_state_CFL(input,"test_sm","test_state3");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sm_test_state3_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sm_test_state3_chain", false,"test_sm_test_state3_queue");
    Asm_log_message_CFL(input,"test_state3 starting");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_log_message_CFL(input,"changing state to test_state1");
    Asm_change_state_CFL(input,"test_sm","test_state1");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sub_state_manager_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sub_state_manager_chain", false,"test_sub_state_queue");
    Asm_log_message_CFL(input,"------------- sub state machine manager starting");
    // define the event list
    short  sm_manager_array_1a[] = {
        47,48,49};
    Asm_filter_events_CFL(input,"display_event",3,sm_manager_array_1a,false,(void *)test_data_ba);
    Asm_transfer_events_to_state_CFL(input,"test_sub_state",0,NULL);
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sub_state_test_state1_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sub_state_test_state1_chain", false,"test_sub_state_test_state1_queue");
    Asm_log_message_CFL(input,"--- sub state --- test_state1 starting");
    // define the event list
    short  sm_manager_array_1[] = {
        47,48,49};
    Asm_filter_events_CFL(input,"display_event",3,sm_manager_array_1,true,(void *)test_data_b);
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"--- sub state ---- changing state to test_state2");
    Asm_change_state_CFL(input,"test_sub_state","test_state2");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sub_state_test_state2_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sub_state_test_state2_chain", false,"test_sub_state_test_state2_queue");
    Asm_log_message_CFL(input,"--- sub state ---test_state2 starting");
    // define the event list
    short  sm_manager_array_2[] = {
        47,48,49};
    Asm_filter_events_CFL(input,"display_event",3,sm_manager_array_2,true,(void *)test_data_c);
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"--- sub state -----------------changing state to test_state3");
    Asm_change_state_CFL(input,"test_sub_state","test_state3");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_sub_state_test_state3_chain"  starting initial running state false 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_sub_state_test_state3_chain", false,"test_sub_state_test_state3_queue");
    Asm_log_message_CFL(input,"---- sub state ----test_state3 starting");
    // define the event list
    short  sm_manager_array_3[] = {
        47,48,49};
    Asm_filter_events_CFL(input,"display_event",3,sm_manager_array_3,true,(void *)test_data_d);
    Asm_wait_time_delay_CFL(input,2000);
    Asm_log_message_CFL(input,"---- sub state ------------------ changing state to test_state1");
    Asm_change_state_CFL(input,"test_sub_state","test_state1");
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "start_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "start_column", true);
    Asm_log_message_CFL(input,"start column");
    const char* sm_array_name1[] = { "test_sm" };
    Asm_enable_disable_sms_CFL(input,1,sm_array_name1);
    Asm_wait_time_delay_CFL(input,200);
    const char* while_column_array[] = {"while_event_column"};
     Asm_while_columns_CFL(input,"event_generator",1,while_column_array,NULL);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "while_event_column"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "while_event_column", false);
    Asm_wait_time_delay_CFL(input,200);
    Asm_sms_send_event_CFL(input,"test_sm",&sm_event_1);
    Asm_sms_send_event_CFL(input,"test_sm",&sm_event_2);
    Asm_sms_send_event_CFL(input,"test_sm",&sm_event_3);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("done with test_state_machine\n");
}
