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
  Printf_CFL("Freemem %d \n",freeMemory());

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;



  Printf_CFL("Freemem %d \n",freeMemory());



  test_enable_disable_columns(config_handle);
  test_join_columns_no_terminate(config_handle);
  test_join_columns_terminate(config_handle);
  test_if_columns_normal_case(config_handle);
  test_if_columns_terminate_case(config_handle);
  test_if_columns_non_terminate_case(config_handle);
  test_try_no_invert_pass(config_handle);
  test_try_no_invert_fail(config_handle);
  test_try_invert(config_handle);
  test_try_termination(config_handle);
  test_try_no_termination(config_handle);
  test_for_no_termination(config_handle);
  test_for_termination(config_handle);
  test_while_column_no_termination(config_handle);
  test_while_column_termination(config_handle);
  test_do_while_column_no_termination(config_handle);
  test_do_while_column_termination(config_handle);
  free(config_handle);
}

/*
**
**  This test will exercise the Enable and Disable op codes
*/
static void test_enable_disable_columns(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "enable_no_terminate", "enable_terminate",
                                "disable_column", "reset_column",
                                "column_to_reset" };
  const char* enable_terminate[] = { "enable_terminate" };
  const char* enable_columns[] = { "disable_column", "reset_column",
                                  "column_to_reset" };
  const char* disable_columns[] = { "reset_column", "column_to_reset" };
  const char* column_to_reset[] = { "column_to_reset" };


  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "enable_no_terminate", true);
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(enable_terminate),
    enable_terminate, false);

  Asm_log_message_CFL(input, "terminate column");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "enable_terminate", false);
  Asm_log_message_CFL(input,
    "will enable threads and wait 15 seconds and terminate");
  // other columns will be disabled when this columns terminate
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(enable_columns), enable_columns,
    true);
  Asm_wait_time_delay_CFL(input, 15000);
  Asm_log_message_CFL(input, "timer is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "disable_column", false);
  Asm_log_message_CFL(input, "will disable reset column after 7 seconds");
  Asm_wait_time_delay_CFL(input, 7000);
  Asm_disable_columns_CFL(input, NAME_SIZE_CFL(disable_columns),
    disable_columns);
  Asm_log_message_CFL(
    input,
    "Now will wait till enable_terminate column terminates this column");
  Asm_wait_CFL(input, "FALSE", -1, false, NULL,
    NULL); // this column will continually block
  Asm_log_message_CFL(
    input, "-------------- message should not happen ----------------------");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "reset_column", false);
  Asm_log_message_CFL(input, "Repeating Message Every 3 Seconds");
  Asm_reset_columns_CFL(input, NAME_SIZE_CFL(column_to_reset), column_to_reset);
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_reset_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "column_to_reset", false);
  Asm_log_message_CFL(input,
    "column to reset will print message and terminate");

  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void test_join_columns_no_terminate(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "test_join", "delay_terminate" };
  const char* delay_terminate[] = { "delay_terminate" };


  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "test_join", true);
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(delay_terminate), delay_terminate,
    false);
  Asm_log_message_CFL(input, "waiting for join");
  Asm_join_columns_CFL(input, NAME_SIZE_CFL(delay_terminate), delay_terminate,
    true);
  Asm_log_message_CFL(input, "Column has been joined");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "delay_terminate", false);
  Asm_log_message_CFL(input, "will wait 5 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "timer is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void test_join_columns_terminate(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "launch_column", "test_join",
                                "delay_terminate" };
  const char* delay_terminate[] = { "delay_terminate" };
  const char* test_join[] = { "test_join" };


  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "launch_column", true);
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(test_join), test_join, true);
  Asm_log_message_CFL(input, "waiting for 15 seconds");
  Asm_wait_time_delay_CFL(input, 15000);
  Asm_log_message_CFL(input, "timer is done");
  Asm_log_message_CFL(input, "Disabling Column");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_join", false);
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(delay_terminate), delay_terminate,
    false);
  Asm_log_message_CFL(input, "waiting for join");
  Asm_join_columns_CFL(input, NAME_SIZE_CFL(delay_terminate), delay_terminate,
    true);
  Asm_log_message_CFL(input, "Column has been joined");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "delay_terminate", false);
  Asm_log_message_CFL(input, "will wait 5 seconds and reset");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "timer is done");
  Asm_reset_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
 Printf_CFL("free memory %d \n",freeMemory());
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

static void test_if_columns_normal_case(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "if_column", "test_if_0", "test_if_1",
                                "test_if_2", "test_if_3", "test_if_4",
                                "test_if_5" };
  const char* if_columns[] = { "test_if_0", "test_if_1", "test_if_2",
                              "test_if_3", "test_if_4", "test_if_5" };


  Store_if_function_CFL(input, "local_if_function", test_if_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "if_column", true);
  Asm_log_message_CFL(input, "if column is active");
  Asm_if_columns_CFL(input, "local_if_function", NAME_SIZE_CFL(if_columns),
    if_columns, true, NULL, NULL);
  Asm_log_message_CFL(input, "if column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_0", false);
  Asm_log_message_CFL(input, "test_if_0 should be active");
  Asm_log_message_CFL(input, "will wait 2 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "test_if_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_1", false);
  Asm_log_message_CFL(input, "test_if_1 should not be active");
  Asm_log_message_CFL(input, "will wait 3 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "test_if_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_2", false);
  Asm_log_message_CFL(input, "test_if_2 should be active");
  Asm_log_message_CFL(input, "will wait 4 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 4000);
  Asm_log_message_CFL(input, "test_if_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_3", false);
  Asm_log_message_CFL(input, "test_if_0 should not be active");
  Asm_log_message_CFL(input, "will wait 5 seconds to ");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "test_if_3 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_4", false);
  Asm_log_message_CFL(input, "test_if_4 should be active");
  Asm_log_message_CFL(input, "will wait 6 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 6000);
  Asm_log_message_CFL(input, "test_if_4 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_5", false);
  Asm_log_message_CFL(input, "test_if_5 should not be active");
  Asm_log_message_CFL(input, "will wait 7 seconds and reset");
  Asm_wait_time_delay_CFL(input, 7000);
  Asm_log_message_CFL(input, "test_if_5 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void test_if_columns_terminate_case(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "early_termination", "if_column", "test_if_0",
                                "test_if_1",         "test_if_2", "test_if_3",
                                "test_if_4",         "test_if_5" };
  const char* if_columns[] = { "test_if_0", "test_if_1", "test_if_2",
                              "test_if_3", "test_if_4", "test_if_5" };
  const char* early_termination_column_names[] = { "if_column" };


  Store_if_function_CFL(input, "local_if_function", test_if_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "early_termination", true);
  Asm_log_message_CFL(input, "early_termination is active");
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(early_termination_column_names),
    early_termination_column_names, true);
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "early_termination is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "if_column", false);
  Asm_log_message_CFL(input, "if column is active");
  Asm_if_columns_CFL(input, "local_if_function", NAME_SIZE_CFL(if_columns),
    if_columns, true, NULL, NULL);
  Asm_log_message_CFL(input, "if column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_0", false);
  Asm_log_message_CFL(input, "test_if_0 should be active");
  Asm_log_message_CFL(input, "will wait 2 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "test_if_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_1", false);
  Asm_log_message_CFL(input, "test_if_1 should not be active");
  Asm_log_message_CFL(input, "will wait 3 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "test_if_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_2", false);
  Asm_log_message_CFL(input, "test_if_2 should be active");
  Asm_log_message_CFL(input, "will wait 4 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 4000);
  Asm_log_message_CFL(input, "test_if_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_3", false);
  Asm_log_message_CFL(input, "test_if_0 should not be active");
  Asm_log_message_CFL(input, "will wait 5 seconds to ");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "test_if_3 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_4", false);
  Asm_log_message_CFL(input, "test_if_4 should be active");
  Asm_log_message_CFL(input, "will wait 6 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 6000);
  Asm_log_message_CFL(input, "test_if_4 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_5", false);
  Asm_log_message_CFL(input, "test_if_5 should not be active");
  Asm_log_message_CFL(input, "will wait 7 seconds and reset");
  Asm_wait_time_delay_CFL(input, 7000);
  Asm_log_message_CFL(input, "test_if_5 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

#if 0
static void test_if_columns_case(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "if_column", "test_if_0", "test_if_1",
                                "test_if_2", "test_if_3", "test_if_4",
                                "test_if_5" };
  const char* if_columns[] = { "test_if_0", "test_if_1", "test_if_2",
                              "test_if_3", "test_if_4", "test_if_5" };


  Store_if_function_CFL(input, "local_if_function", test_if_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "if_column", true);
  Asm_log_message_CFL(input, "if column is active");
  Asm_if_columns_CFL(input, "local_if_function", NAME_SIZE_CFL(if_columns),
    if_columns, true, NULL, NULL);
  Asm_log_message_CFL(input, "if column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_0", false);
  Asm_log_message_CFL(input, "test_if_0 should be active");
  Asm_log_message_CFL(input, "will wait 2 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "test_if_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_1", false);
  Asm_log_message_CFL(input, "test_if_1 should not be active");
  Asm_log_message_CFL(input, "will wait 3 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "test_if_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_2", false);
  Asm_log_message_CFL(input, "test_if_2 should be active");
  Asm_log_message_CFL(input, "will wait 4 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 4000);
  Asm_log_message_CFL(input, "test_if_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_3", false);
  Asm_log_message_CFL(input, "test_if_0 should not be active");
  Asm_log_message_CFL(input, "will wait 5 seconds to ");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "test_if_3 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_4", false);
  Asm_log_message_CFL(input, "test_if_4 should be active");
  Asm_log_message_CFL(input, "will wait 6 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 6000);
  Asm_log_message_CFL(input, "test_if_4 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_5", false);
  Asm_log_message_CFL(input, "test_if_5 should not be active");
  Asm_log_message_CFL(input, "will wait 7 seconds and reset");
  Asm_wait_time_delay_CFL(input, 7000);
  Asm_log_message_CFL(input, "test_if_5 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}
#endif 

static void
test_if_columns_non_terminate_case(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "early_terminate", "if_column", "test_if_0",
                                "test_if_1",       "test_if_2", "test_if_3",
                                "test_if_4",       "test_if_5" };
  const char* if_columns[] = { "test_if_0", "test_if_1", "test_if_2",
                              "test_if_3", "test_if_4", "test_if_5" };
  const char* early_terminate_columns[] = { "if_column" };


  Store_if_function_CFL(input, "local_if_function", test_if_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "early_terminate", true);
  Asm_log_message_CFL(input, "if column is done");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_disable_columns_CFL(input, NAME_SIZE_CFL(early_terminate_columns),
    early_terminate_columns);
  Asm_log_message_CFL(input, "early_terminate is done");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "if_column", true);
  Asm_log_message_CFL(input, "if column is active");
  Asm_if_columns_CFL(input, "local_if_function", NAME_SIZE_CFL(if_columns),
    if_columns, false, NULL, NULL);
  Asm_log_message_CFL(input, "if column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_0", false);
  Asm_log_message_CFL(input, "test_if_0 should be active");
  Asm_log_message_CFL(input, "will wait 2 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "test_if_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_1", false);
  Asm_log_message_CFL(input, "test_if_1 should not be active");
  Asm_log_message_CFL(input, "will wait 3 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "test_if_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_2", false);
  Asm_log_message_CFL(input, "test_if_2 should be active");
  Asm_log_message_CFL(input, "will wait 4 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 4000);
  Asm_log_message_CFL(input, "test_if_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_3", false);
  Asm_log_message_CFL(input, "test_if_0 should not be active");
  Asm_log_message_CFL(input, "will wait 5 seconds to ");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "test_if_3 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_4", false);
  Asm_log_message_CFL(input, "test_if_4 should be active");
  Asm_log_message_CFL(input, "will wait 6 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 6000);
  Asm_log_message_CFL(input, "test_if_4 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_5", false);
  Asm_log_message_CFL(input, "test_if_5 should not be active");
  Asm_log_message_CFL(input, "will wait 7 seconds and reset");
  Asm_wait_time_delay_CFL(input, 7000);
  Asm_log_message_CFL(input, "test_if_5 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void test_try_function(void* input, Try_column_CFL_t* try_control) {

  Printf_CFL("%s final state %d column index %d \n", __func__,
    try_control->final_state, try_control->current_column_index);
}

static void test_try_no_invert_pass(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "try_column", "try_0", "try_1", "try_2" };
  const char* try_columns[] = { "try_0", "try_1", "try_2" };


  Store_try_function_CFL(input, "local_try_function", test_try_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "try_column", true);
  Asm_log_message_CFL(input, "try column is active");
  Asm_try_columns_CFL(input, "local_try_function", NAME_SIZE_CFL(try_columns),
    try_columns, true, false, NULL);
  Asm_log_message_CFL(input, "try column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_0", false);
  Asm_log_message_CFL(input, "try_0 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_0 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_1", false);
  Asm_log_message_CFL(input, "try_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_1 is terminating");
  Asm_set_return_code(input, true);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_2", false);
  Asm_log_message_CFL(input, "try_3 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_3 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void test_try_no_invert_fail(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "try_column", "try_0", "try_1", "try_2" };
  const char* try_columns[] = { "try_0", "try_1", "try_2" };


  Store_try_function_CFL(input, "local_try_function", test_try_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "try_column", true);
  Asm_log_message_CFL(input, "try column is active");
  Asm_try_columns_CFL(input, "local_try_function", NAME_SIZE_CFL(try_columns),
    try_columns, true, false, NULL);
  Asm_log_message_CFL(input, "try column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_0", false);
  Asm_log_message_CFL(input, "try_0 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "test_0 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_1", false);
  Asm_log_message_CFL(input, "try_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_1 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_2", false);
  Asm_log_message_CFL(input, "try_2 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_2 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void test_try_invert(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "try_column", "try_0", "try_1", "try_2" };
  const char* try_columns[] = { "try_0", "try_1", "try_2" };


  Store_try_function_CFL(input, "local_try_function", test_try_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "try_column", true);
  Asm_log_message_CFL(input, "try column is active");
  Asm_try_columns_CFL(input, "local_try_function", NAME_SIZE_CFL(try_columns),
    try_columns, false, false, NULL);
  Asm_log_message_CFL(input, "try column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_0", false);
  Asm_log_message_CFL(input, "try_0 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "test_0 is terminating");
  Asm_set_return_code(input, true);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_1", false);
  Asm_log_message_CFL(input, "try_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_1 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_2", false);
  Asm_log_message_CFL(input, "try_2 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_2 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void test_try_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "launch_column", "try_column", "try_0", "try_1",
                                "try_2" };
  const char* try_columns[] = { "try_0", "try_1", "try_2" };
  const char* test_try[] = { "try_column" };


  Store_try_function_CFL(input, "local_try_function", test_try_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "launch_column", true);
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(test_try), test_try, true);
  Asm_log_message_CFL(input, "waiting for 2 seconds");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "timer is done");
  Asm_log_message_CFL(input, "Disabling Column");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_column", true);
  Asm_log_message_CFL(input, "try column is active");
  Asm_try_columns_CFL(input, "local_try_function", NAME_SIZE_CFL(try_columns),
    try_columns, true, false, NULL);
  Asm_log_message_CFL(input, "try column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_0", false);
  Asm_log_message_CFL(input, "try_0 should be active");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "test_0 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_1", false);
  Asm_log_message_CFL(input, "try_1 should be active");
  Asm_wait_time_delay_CFL(input, 6000);
  Asm_log_message_CFL(input, "try_1 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_2", false);
  Asm_log_message_CFL(input, "try_2 should be active");
  Asm_wait_time_delay_CFL(input, 7000);
  Asm_log_message_CFL(input, "try_2 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
   Printf_CFL("free memory %d \n",freeMemory());
}

static void test_try_no_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "launch_column", "try_column", "try_0", "try_1",
                                "try_2" };
  const char* try_columns[] = { "try_0", "try_1", "try_2" };
  const char* test_try[] = { "try_column" };


  Store_try_function_CFL(input, "local_try_function", test_try_function);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "launch_column", true);
  Asm_enable_columns_CFL(input, NAME_SIZE_CFL(test_try), test_try, true);
  Asm_log_message_CFL(input, "waiting for 2 seconds");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "timer is done");
  Asm_log_message_CFL(input, "Disabling Column");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_column", true);
  Asm_log_message_CFL(input, "try column is active");
  Asm_try_columns_CFL(input, "local_try_function", NAME_SIZE_CFL(try_columns),
    try_columns, false, false, NULL);
  Asm_log_message_CFL(input, "try column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_0", false);
  Asm_log_message_CFL(input, "try_0 should be active");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "test_0 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_1", false);
  Asm_log_message_CFL(input, "try_1 should be active");
  Asm_wait_time_delay_CFL(input, 6000);
  Asm_log_message_CFL(input, "try_1 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_2", false);
  Asm_log_message_CFL(input, "try_2 should be active");
  Asm_wait_time_delay_CFL(input, 7000);
  Asm_log_message_CFL(input, "try_2 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
   Printf_CFL("free memory %d \n",freeMemory());
}

static void test_for_no_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "test_for", "for_0", "for_1", "for_2" };
  const char* for_columns[] = { "for_0", "for_1", "for_2" };



  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "test_for", true);
  Asm_log_message_CFL(input, "starting for command");
  Asm_for_columns_CFL(input, 4, NAME_SIZE_CFL(for_columns), for_columns, NULL,
    NULL);
  Asm_log_message_CFL(input, "done with for statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_0", false);
  Asm_log_message_CFL(input, "for_0 should be active");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "for_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_1", false);
  Asm_log_message_CFL(input, "for_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "for_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_2", false);
  Asm_log_message_CFL(input, "try_2 should be active");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "try_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
   Printf_CFL("free memory %d \n",freeMemory());
}

static void test_for_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "early_terminate", "test_for", "for_0", "for_1",
                                "for_2" };
  const char* for_columns[] = { "for_0", "for_1", "for_2" };
  const char* early_terminate_columns[] = { "test_for" };



  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "early_terminate", true);
  Asm_log_message_CFL(input, "early terminate");
  Asm_wait_time_delay_CFL(input, 500);
  Asm_disable_columns_CFL(input, NAME_SIZE_CFL(early_terminate_columns),
    early_terminate_columns);
  Asm_log_message_CFL(input, "early_terminate is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);
  Asm_start_column_CFL(input, "test_for", true);
  Asm_log_message_CFL(input, "starting for command");
  Asm_for_columns_CFL(input, 4, NAME_SIZE_CFL(for_columns), for_columns, NULL,
    NULL);
  Asm_log_message_CFL(input, "done with for statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_0", false);
  Asm_log_message_CFL(input, "for_0 should be active");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "for_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_1", false);
  Asm_log_message_CFL(input, "for_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "for_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_2", false);
  Asm_log_message_CFL(input, "try_2 should be active");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "try_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static const char* while_message = "This is a test message for while";

static bool while_column_test(void* input, void* params,
  Event_data_CFL_t* event_data) {
  While_column_control_CFL_t* while_control;
  const char* message;

  while_control = (While_column_control_CFL_t*)params;
  message = (const char*)while_control->user_data;
  Printf_CFL(message); // testing user data
  Printf_CFL("free memory %d \n",freeMemory());
  Printf_CFL("%s number of iterations %d \n", __func__,
    while_control->current_iterations);
  if (while_control->current_iterations >= 4) {
    return false;
  }
  return true;
}

static void
test_while_column_no_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "test_while", "while_0", "while_1", "while_2" };
  const char* while_columns[] = { "while_0", "while_1", "while_2" };


  Store_bool_function_CFL(input, "while_column_test", while_column_test);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "test_while", true);
  Asm_log_message_CFL(input, "starting while command");
  Asm_while_columns_CFL(input, "while_column_test",
    NAME_SIZE_CFL(while_columns), while_columns,
    (void*)while_message);
  Asm_log_message_CFL(input, "done with while statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_0", false);
  Asm_log_message_CFL(input, "while_0 should be active");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "while_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_1", false);
  Asm_log_message_CFL(input, "while_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "while_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_2", false);
  Asm_log_message_CFL(input, "while_2 should be active");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "while_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
   Printf_CFL("free memory %d \n",freeMemory());
}

static void test_while_column_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "early_terminate", "test_while", "while_0",
                                "while_1", "while_2" };
  const char* while_columns[] = { "while_0", "while_1", "while_2" };
  const char* early_terminate_columns[] = { "test_while" };


  Store_bool_function_CFL(input, "while_column_test", while_column_test);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "early_terminate", true);
  Asm_log_message_CFL(input, "early terminate");
  Asm_wait_time_delay_CFL(input, 500);
  Asm_disable_columns_CFL(input, NAME_SIZE_CFL(early_terminate_columns),
    early_terminate_columns);
  Asm_log_message_CFL(input, "early_terminate is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_while", true);
  Asm_log_message_CFL(input, "starting while command");
  Asm_while_columns_CFL(input, "while_column_test",
    NAME_SIZE_CFL(while_columns), while_columns,
    (void*)while_message);
  Asm_log_message_CFL(input, "done with while statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_0", false);
  Asm_log_message_CFL(input, "while_0 should be active");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "while_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_1", false);
  Asm_log_message_CFL(input, "while_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "while_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_2", false);
  Asm_log_message_CFL(input, "while_2 should be active");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "while_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void
test_do_while_column_no_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "test_while", "while_0", "while_1", "while_2" };
  const char* while_columns[] = { "while_0", "while_1", "while_2" };



  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "test_while", true);
  Asm_log_message_CFL(input, "starting while command");
  // "false" function will return false
  // test to ensure that one iteration occurs
  Asm_do_while_columns_CFL(input, "FALSE", NAME_SIZE_CFL(while_columns),
    while_columns, NULL);
  Asm_log_message_CFL(input, "done with while statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_0", false);
  Asm_log_message_CFL(input, "while_0 should be active");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "while_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_1", false);
  Asm_log_message_CFL(input, "while_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "while_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_2", false);
  Asm_log_message_CFL(input, "while_2 should be active");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "while_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}

static void
test_do_while_column_termination(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "early_terminate", "test_while", "while_0",
                                "while_1", "while_2" };
  const char* while_columns[] = { "while_0", "while_1", "while_2" };
  const char* early_terminate_columns[] = { "test_while" };



  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "early_terminate", true);
  Asm_log_message_CFL(input, "early terminate");
  Asm_wait_time_delay_CFL(input, 500);
  Asm_disable_columns_CFL(input, NAME_SIZE_CFL(early_terminate_columns),
    early_terminate_columns);
  Asm_log_message_CFL(input, "early_terminate is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_while", true);
  Asm_log_message_CFL(input, "starting do while command");
  // "false" function will return false
  // test to ensure that one iteration occurs
  Asm_do_while_columns_CFL(input, "FALSE", NAME_SIZE_CFL(while_columns),
    while_columns, NULL);
  Asm_log_message_CFL(input, "done with do while statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_0", false);
  Asm_log_message_CFL(input, "while_0 should be active");
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "while_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_1", false);
  Asm_log_message_CFL(input, "while_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "while_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "while_2", false);
  Asm_log_message_CFL(input, "while_2 should be active");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "while_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
   Printf_CFL("free memory %d \n",freeMemory());
}
