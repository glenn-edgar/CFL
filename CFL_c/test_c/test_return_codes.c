#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

static void test_basic_return_codes(Handle_config_CFL_t* config_handle);
static void test_dead_columns_and_dead_engine(Handle_config_CFL_t* config_handle);
static void test_second_minute_hour_day_event(Handle_config_CFL_t* config_handle);

void test_column_return_codes(void) {
  Handle_config_CFL_t* config_handle = Create_config_handle_CFL();

  
  


  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;
  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  config_handle->debug_out = debug_write;
   config_handle->debug_out = debug_write;
   
  test_basic_return_codes(config_handle);
  test_dead_columns_and_dead_engine(config_handle);
  test_second_minute_hour_day_event(config_handle);
}

static void one_shot_test(void* input, void* params,
  Event_data_CFL_t* event_data) {
  if (event_data->event_index == EVENT_INIT_CFL) {

    Printf_CFL("one shot test initialization \n");
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL) {
    Printf_CFL("one shot test termination \n");
  }
}

static void test_basic_return_codes(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle,50000, 4000);

  const char* column_names[] = { "terminate_column", "reset_column",
                                "terminate_engine_column", "halt_test" };

  Store_one_shot_function_CFL(input, "ONE_SHOT_TEST", one_shot_test);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);


  Asm_start_column_CFL(input, "terminate_column", true);
  //---->
  Asm_log_message_CFL(input, "this column will terminate");
  Asm_terminate_CFL(input);
  //---->
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "reset_column", true);
  //---->
  Asm_log_message_CFL(input, "Repeating Message Every 3 Seconds");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_reset_CFL(input);
  //--->
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "terminate_engine_column", true);
  //--->
  Asm_log_message_CFL(input,
    "This column will terminate the engine in 10 seconds");
  Asm_wait_time_delay_CFL(input, 10000);
  Asm_log_message_CFL(input, "Engine will terminate now");
  Asm_engine_terminate_CFL(input);
  //--->
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "halt_test", true);
  //--->
  Asm_one_shot_terminate_CFL(input, "ONE_SHOT_TEST", NULL);
  Asm_halt_CFL(input);
  //--->
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Destroy_engine_CFL(input);
  Printf_CFL("Engine Done\n");
}
  

static void
test_dead_columns_and_dead_engine(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 50000, 4000);

  const char* column_names[] = { "terminate_column", "terminate_engine_column" };


  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "terminate_column", true);
  //--->
  Asm_log_message_CFL(input,
    "column will terminate a now active column elements");
  //--->
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "terminate_engine_column", true);
  //--->
  Asm_log_message_CFL(input,
    "This column will terminate the engine in 2 seconds");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(
    input, "column will terminate and engine will because no active columns");
  //--->
  Asm_end_column_CFL(input);

  

  Destroy_engine_CFL(input);
  Printf_CFL("Engine Done \n");
  
}

static void test_second_minute_hour_day_event(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 50000, 4000);

  const char* column_names[] = {  "second_event","minute_event", "hour_event",
                                "day_event" };

   Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "second_event", true);
  //-->
  Asm_log_message_CFL(input, "-------------------------> second_event is starting");
  
  Asm_wait_event_count_CFL(input, SECOND_TICK_CFL, 2, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_wait_event_count_CFL(input, TIMER_TICK_CFL, 1, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_wait_event_count_CFL(input, SECOND_TICK_CFL, 2, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_wait_event_count_CFL(input, TIMER_TICK_CFL, 1, NO_TIME_OUT_CFL, false, NULL, NULL);
   Asm_wait_event_count_CFL(input, SECOND_TICK_CFL, 2, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_wait_event_count_CFL(input, TIMER_TICK_CFL, 1, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_wait_event_count_CFL(input, SECOND_TICK_CFL, 2, NO_TIME_OUT_CFL, false, NULL, NULL);
  
  Asm_log_message_CFL(input, "second_event is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);


Asm_start_column_CFL(input, "minute_event", true);
  //-->
  Asm_log_message_CFL(input, "-------------------------> minute_event is starting");

  Asm_wait_event_count_CFL(input,MINUTE_TICK_CFL, 1, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_log_message_CFL(input, "minute_event is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);


Asm_start_column_CFL(input, "hour_event", true);
  //-->
  Asm_log_message_CFL(input, "-------------------------> hour_event is starting");

 Asm_wait_event_count_CFL(input, HOUR_TICK_CFL, 1, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_log_message_CFL(input, "hour_event is done");
 Asm_terminate_CFL(input);
Asm_end_column_CFL(input);


Asm_start_column_CFL(input, "day_event",true);
  //-->
  Asm_log_message_CFL(input, "-------------------------> day_event is starting");
  
 Asm_wait_event_count_CFL(input, DAY_TICK_CFL, 1, NO_TIME_OUT_CFL, false, NULL, NULL);
  Asm_log_message_CFL(input, "day_event is done");
 Asm_terminate_CFL(input);
Asm_end_column_CFL(input);


 Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);

  Destroy_engine_CFL(input);
  Printf_CFL("Engine Done  \n");
  
}


  //---->
  
