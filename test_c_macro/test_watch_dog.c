#include "test_watch_dog.h"

static void test_watch_dog(Handle_config_CFL_t* config_handle);

void test_watch_dog(void) {
  Handle_config_CFL_t* config_handle = Create_config_handle_CFL();


  Printf_CFL("simple columnt test");
  Printf_CFL("free memory %d \n",freeMemory());


  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;
  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;

  test_watch_dog(config_handle);
  free(config_handle);
}

#if 0
typedef struct Column_watch_dog_CFL_t {
  bool                     termination_flag;
  unsigned                 column_index;
  unsigned                 trigger_count;
  unsigned                 current_count;
  One_shot_function_CFL_t trigger_function;

}Column_watch_dog_CFL_t;
#endif

static void watch_dog_timeout(void* input, void* params,
  Event_data_CFL_t* event_data) {
  Column_watch_dog_CFL_t* watch_dog = (Column_watch_dog_CFL_t*)params;

  if (watch_dog->termination_flag == true) {
    Printf_CFL("--------------->Watch dog terminated  column %d\n",
      watch_dog->column_index);
  }
  else {
    Printf_CFL("--------------->Watch dog reset  column %d\n",
      watch_dog->column_index);
  }
}

static void test_watch_dog(Handle_config_CFL_t* config_handle) {

  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "terminate_engine", "wd_test_normal",
                                "wd_test_terminate", "wd_test_reset" };
 //Event_data_CFL_t my_event_data = { 23, 45, NULL };



  Store_one_shot_function_CFL(input, "watch_dog_timeout", watch_dog_timeout);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "terminate_engine", true);
  Asm_log_message_CFL(input, "terminate engine starting");
  Asm_wait_time_delay_CFL(input, 20000);
  Asm_log_message_CFL(input, "time delay done");
  Asm_engine_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "wd_test_normal", true);
  Asm_log_message_CFL(input, "wd_test_normal starting");
  Asm_set_column_watch_dog_CFL(input, 1000, true, "watch_dog_timeout");
  Asm_wait_time_delay_CFL(input, 500);
  Asm_clear_column_watch_dog_CFL(input);
  Asm_log_message_CFL(input, "wait to see if wd fires");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "wd_test_normal done");
  Asm_reset_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "wd_test_terminate", true);
  Asm_log_message_CFL(input, "wd_test_terminate starting");
  Asm_set_column_watch_dog_CFL(input, 1000, true, "watch_dog_timeout");
  Asm_wait_time_delay_CFL(input, 1500);
  Asm_clear_column_watch_dog_CFL(input);
  Asm_log_message_CFL(input, "This should not be seen");
  Asm_reset_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "wd_test_reset", true);
  Asm_log_message_CFL(input, "wd_test_reset starting");
  Asm_set_column_watch_dog_CFL(input, 1000, false, "watch_dog_timeout");
  Asm_wait_time_delay_CFL(input, 1500);
  Asm_clear_column_watch_dog_CFL(input);
  Asm_log_message_CFL(input, "This should not be seen");
  Asm_reset_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Printf_CFL("Engine Done");
  Destroy_engine_CFL(input);
  Printf_CFL("free memory %d \n",freeMemory());
}
