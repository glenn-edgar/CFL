#include "test_column_events.h"
#include "CFL_user_functions.h"
#include "test_interface_functions.h"

static void chain_events_for(Handle_config_CFL_t* config_handle);
static void chain_events_while(Handle_config_CFL_t* config_handle);
static void chain_events_if(Handle_config_CFL_t* config_handle);
static void chain_events_try_a(Handle_config_CFL_t* config_handle);
static void chain_events_try_b(Handle_config_CFL_t* config_handle);

void test_chain_events(void) {



  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  Printf_CFL("test_allocation");
 Printf_CFL("Freemem %d \n",freeMemory());

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;


  chain_events_for(config_handle);
  chain_events_while(config_handle);
  chain_events_if(config_handle);
  chain_events_try_a(config_handle);
  chain_events_try_b(config_handle);
}
#if 0
typedef struct For_control_CFL_t {
  bool                    state;
  bool                    terminate_flag;
  unsigned short          number_of_columns;
  unsigned short* column_indexes;
  unsigned                number_of_iterations;
  unsigned                current_iterations;
  One_shot_function_CFL_t fn;
  void* user_data;
}For_control_CFL_t;

#endif

static void for_function(void* handle, void* params,
  Event_data_CFL_t* event_data) {
  For_control_CFL_t* for_control;
  Event_data_CFL_t* event_data_array;

  for_control = (For_control_CFL_t*)params;
  event_data_array = (Event_data_CFL_t*)for_control->user_data;

  Printf_CFL("<------- for_function ---->\n");
  Printf_CFL("%s index %d count %d termination %d\n", __func__,
    for_control->current_iterations,
    for_control->number_of_iterations, for_control->terminate_flag);
  for (int i = 0; i < for_control->number_of_columns; i++) {
    Printf_CFL("column %d event %d \n", i, event_data_array[i].event_index);
  }

  // terminate on next to last iteration
  if (for_control->current_iterations >=
    for_control->number_of_iterations - 1) {
    Printf_CFL("terminating for loop\n");
    for_control->terminate_flag = true;
  }
  Printf_CFL("<------- end for_function ---->\n");
}

static void process_column_event(void* handle, void* params,
  Event_data_CFL_t* event_data) {
  Event_data_CFL_t* passed_event_data =
    Get_current_column_local_event_CFL(handle);

  Printf_CFL("<------- increment_event ---->\n");
  Printf_CFL("%s event %d \n", __func__, passed_event_data->event_index);
  Printf_CFL((char*)passed_event_data->params);
  passed_event_data->event_index++;
  Printf_CFL("%s event %d \n", __func__, passed_event_data->event_index);
  Printf_CFL("<------- end increment_event ---->\n");
}

static void chain_events_for(Handle_config_CFL_t* config_handle) {

  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "test_for", "for_0", "for_1", "for_2" };
  const char* for_columns[] = { "for_0", "for_1", "for_2" };

#define TEST_EVENT 25
  #if 0
  static const char* test_data[] = { "test_data_0", "test_data_1",
                                    "test_data_2" };
  #endif
  Event_data_CFL_t test_event[] = {
      {.event_index = TEST_EVENT, .event_data = 0, .params = (void*)"test_0"},
      {.event_index = TEST_EVENT + 1,
       .event_data = 1,
       .params = (void*)"test_1"},
      {.event_index = TEST_EVENT + 2,
       .event_data = 2,
       .params = (void*)"test_2"} };



  Store_one_shot_function_CFL(input, "for_function", for_function);
  Store_one_shot_function_CFL(input, "process_column_event",
    process_column_event);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "test_for", true);
  Asm_log_message_CFL(input, "starting for command");

  Asm_for_columns_CFL(input, 4, NAME_SIZE_CFL(for_columns), for_columns,
    (char *)"for_function", (void*)test_event);
  Asm_log_message_CFL(input, "done with for statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_0", false);
  Asm_log_message_CFL(input, "for_0 should be active");
  Asm_store_current_column_event_CFL(input, &test_event[0]);
  Asm_one_shot_CFL(input, "process_column_event", NULL);
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "for_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_1", false);
  Asm_log_message_CFL(input, "for_1 should be active");
  Asm_store_current_column_event_CFL(input, &test_event[1]);
  Asm_one_shot_CFL(input, "process_column_event", NULL);
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "for_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_2", false);
  Asm_log_message_CFL(input, "for_2 should be active");
  Asm_store_current_column_event_CFL(input, &test_event[2]);
  Asm_one_shot_CFL(input, "process_column_event", NULL);
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "for_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}
#if 0
typedef struct While_column_control_CFL_t
{

  void* user_data;
  bool state;
  unsigned short number_of_columns;
  unsigned short* column_indexes;
  unsigned current_iterations;

} While_column_control_CFL_t;
#endif

static bool while_function(void* handle, void* params,
  Event_data_CFL_t* event_data) {

  While_column_control_CFL_t* while_control =
    (While_column_control_CFL_t*)params;
  Event_data_CFL_t* event_data_array =
    (Event_data_CFL_t*)while_control->user_data;

  for (unsigned i = 0; i < while_control->number_of_columns; i++) {
    Printf_CFL("%s event index %d event data %f event params %p\n", __func__,
      event_data_array[i].event_index,
      event_data_array[i].event_data, event_data_array[i].params);
    Printf_CFL((char*)event_data_array[i].params);
  }
  Printf_CFL("%s current iteration %d \n", __func__,
    while_control->current_iterations);

  Printf_CFL("<------- end while_function ---->\n");
  if (while_control->current_iterations++ > 3) {
    return false;
  }
  return true;
}

static void chain_events_while(Handle_config_CFL_t* config_handle) {

  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "test_for", "for_0", "for_1", "for_2" };
  const char* while_columns[] = { "for_0", "for_1", "for_2" };

#define TEST_EVENT 25

  static const char* test_data[] = { "test_data_0", "test_data_1",
                                    "test_data_2" };
  Event_data_CFL_t test_event[] = { {.event_index = TEST_EVENT,
                                    .event_data = 0,
                                    .params = (void*)test_data[0]},
                                   {.event_index = TEST_EVENT + 1,
                                    .event_data = 1,
                                    .params = (void*)test_data[1]},
                                   {.event_index = TEST_EVENT + 2,
                                    .event_data = 2,
                                    .params = (void*)test_data[2]} };



  Store_bool_function_CFL(input, "while_function", while_function);
  Store_one_shot_function_CFL(input, "process_column_event",
    process_column_event);
  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "test_for", true);
  Asm_log_message_CFL(input, "starting for command");
  Asm_while_columns_CFL(input, "while_function", NAME_SIZE_CFL(while_columns),
    while_columns, (void*)test_event);

  Asm_log_message_CFL(input, "done with for statement");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_0", false);
  Asm_log_message_CFL(input, "for_0 should be active");
  Asm_store_current_column_event_CFL(input, &test_event[0]);
  Asm_one_shot_CFL(input, "process_column_event", NULL);
  Asm_wait_time_delay_CFL(input, 1000);
  Asm_log_message_CFL(input, "for_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_1", false);
  Asm_log_message_CFL(input, "for_1 should be active");
  Asm_store_current_column_event_CFL(input, &test_event[1]);
  Asm_one_shot_CFL(input, "process_column_event", NULL);
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "for_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "for_2", false);
  Asm_log_message_CFL(input, "for_2 should be active");
  Asm_store_current_column_event_CFL(input, &test_event[2]);
  Asm_one_shot_CFL(input, "process_column_event", NULL);
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "for_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
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

static void process_if_chains(void* input, void* params,
  Event_data_CFL_t* event_data) {
  Event_data_CFL_t* local_event = Get_current_column_local_event_CFL(input);

  local_event->event_index += 1;
  local_event->event_data += 2.0;
}
static void process_summary(void* input, void* params,
  Event_data_CFL_t* event_data) {
  If_control_CFL_t* if_control = (If_control_CFL_t*)params;
  Event_data_CFL_t* column_event_data =
    (Event_data_CFL_t*)if_control->user_data;

  unsigned short* column_indexes = if_control->column_indexes;
  bool* valid_indexes = if_control->return_indexes;
  column_event_data = (Event_data_CFL_t*)if_control->user_data;

  Printf_CFL("%s",__func__);
  for (unsigned i = 0; i < if_control->column_number; i++) {
    if (*valid_indexes) {

      Printf_CFL(
        "i %d column index %d  event index %d data %f params %s  \n", i,
        *column_indexes, column_event_data[i].event_index,
        column_event_data[i].event_data, (char*)column_event_data[i].params);
      Printf_CFL("---->param %s \n", (char*)column_event_data[i].params);
    }
    column_indexes++;
    valid_indexes++;
  }
}

static void chain_events_if(Handle_config_CFL_t* config) {

  const char* column_names[] = { "if_column", "test_if_0", "test_if_1",
                                "test_if_2", "test_if_3", "test_if_4",
                                "test_if_5" };
  const char* if_columns[] = { "test_if_0", "test_if_1", "test_if_2",
                              "test_if_3", "test_if_4", "test_if_5" };
  const char* test_data[] = { "test_data_0", "test_data_1",
                                    "test_data_2", "test_data_3",
                                    "test_data_4", "test_data_5" };
  Event_data_CFL_t test_event[] = { {.event_index = TEST_EVENT,
                                    .event_data = 0,
                                    .params = (void*)test_data[0]},
                                   {.event_index = TEST_EVENT + 1,
                                    .event_data = 1.1,
                                    .params = (void*)test_data[1]},
                                   {.event_index = TEST_EVENT + 2,
                                    .event_data = 2.2,
                                    .params = (void*)test_data[2]},
                                   {.event_index = TEST_EVENT + 3,
                                    .event_data = 3.3,
                                    .params = (void*)test_data[3]},
                                   {.event_index = TEST_EVENT + 4,
                                    .event_data = 4.4,
                                    .params = (void*)test_data[4]},
                                   {.event_index = TEST_EVENT + 5,
                                    .event_data = 5.5,
                                    .params = (void*)test_data[5]} };


  void* input = Configure_engine_CFL(config, 40000, 2500);
  Store_if_function_CFL(input, "local_if_function", test_if_function);
  Store_one_shot_function_CFL(input, "process_summary", process_summary);
  Store_one_shot_function_CFL(input, "process_if_chains", process_if_chains);

  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "if_column", true);
  Asm_log_message_CFL(input, "if column is active");

  
  Asm_if_columns_CFL(input, "local_if_function", NAME_SIZE_CFL(if_columns),
    if_columns, true, "process_summary", test_event);

  Asm_log_message_CFL(input, "if column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_0", false);
  Asm_store_current_column_event_CFL(input, &test_event[0]);
  Asm_one_shot_CFL(input, "process_if_chains", NULL);
  Asm_log_message_CFL(input, "test_if_0 should be active");
  Asm_log_message_CFL(input, "will wait 2 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "test_if_0 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_1", false);
  Asm_store_current_column_event_CFL(input, &test_event[1]);
  Asm_one_shot_CFL(input, "process_if_chains", NULL);
  Asm_log_message_CFL(input, "test_if_1 should not be active");
  Asm_log_message_CFL(input, "will wait 3 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 3000);
  Asm_log_message_CFL(input, "test_if_1 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_2", false);
  Asm_store_current_column_event_CFL(input, &test_event[2]);
  Asm_one_shot_CFL(input, "process_if_chains", NULL);
  Asm_log_message_CFL(input, "test_if_2 should be active");
  Asm_log_message_CFL(input, "will wait 4 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 4000);
  Asm_log_message_CFL(input, "test_if_2 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_3", false);
  Asm_store_current_column_event_CFL(input, &test_event[3]);
  Asm_one_shot_CFL(input, "process_if_chains", NULL);
  Asm_log_message_CFL(input, "test_if_0 should not be active");
  Asm_log_message_CFL(input, "will wait 5 seconds to ");
  Asm_wait_time_delay_CFL(input, 5000);
  Asm_log_message_CFL(input, "test_if_3 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_4", false);
  Asm_store_current_column_event_CFL(input, &test_event[4]);
  Asm_one_shot_CFL(input, "process_if_chains", NULL);
  Asm_log_message_CFL(input, "test_if_4 should be active");
  Asm_log_message_CFL(input, "will wait 6 seconds and terminate");
  Asm_wait_time_delay_CFL(input, 6000);
  Asm_log_message_CFL(input, "test_if_4 is terminating");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "test_if_5", false);
  Asm_store_current_column_event_CFL(input, &test_event[5]);
  Asm_one_shot_CFL(input, "process_if_chains", NULL);
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
  Event_data_CFL_t* event_data = (Event_data_CFL_t*)try_control->user_data;

  Printf_CFL("%s final state %d  index %d column index %d \n", __func__,
    try_control->final_state, try_control->current_column_index,
    try_control->column_indexes[try_control->current_column_index]);
  for (int i = 0; i <= try_control->current_column_index; i++) {
    Printf_CFL("index %d column_index %d \n", i,
      try_control->column_indexes[i]);
    Printf_CFL("---->event index %d event data %f \n",
      event_data[i].event_index, event_data[i].event_data);
    Printf_CFL("---->event params %s \n", (char*)event_data[i].params);
  }
}

static void chain_events_try_a(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "try_column", "try_0", "try_1", "try_2" };
  const char* try_columns[] = { "try_0", "try_1", "try_2" };
  static const char* test_data[] = { "test_data_0", "test_data_1",
                                    "test_data_2" };
  Event_data_CFL_t test_event[] = { {.event_index = TEST_EVENT,
                                    .event_data = 0,
                                    .params = (void*)test_data[0]},
                                   {.event_index = TEST_EVENT + 1,
                                    .event_data = 1.1,
                                    .params = (void*)test_data[1]},
                                   {.event_index = TEST_EVENT + 2,
                                    .event_data = 2.2,
                                    .params = (void*)test_data[2]} };


  Store_try_function_CFL(input, "local_try_function", test_try_function);
  Store_one_shot_function_CFL(input, "process_try_chains", process_if_chains);

  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "try_column", true);
  Asm_log_message_CFL(input, "try column is active");
  Asm_try_columns_CFL(input, "local_try_function", NAME_SIZE_CFL(try_columns),
    try_columns, true, false, (void*)test_event);
  Asm_log_message_CFL(input, "try column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_0", false);
  Asm_store_current_column_event_CFL(input, &test_event[0]);
  Asm_one_shot_CFL(input, "process_try_chains", NULL);
  Asm_log_message_CFL(input, "try_0 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_0 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_1", false);
  Asm_store_current_column_event_CFL(input, &test_event[1]);
  Asm_one_shot_CFL(input, "process_try_chains", NULL);
  Asm_log_message_CFL(input, "try_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_1 is terminating");
  Asm_set_return_code(input, true);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_2", false);
  Asm_store_current_column_event_CFL(input, &test_event[2]);
  Asm_one_shot_CFL(input, "process_try_chains", NULL);
  Asm_log_message_CFL(input, "try_2 should not be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_2 is terminating");
  Asm_set_return_code(input, true);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Start_engine_CFL(input, 100, 30, NULL, NULL);

  Destroy_engine_CFL(input);
  Printf_CFL("engine is done");
  Printf_CFL("free memory %d \n",freeMemory());
}
static void chain_events_try_b(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 40000, 2500);
  const char* column_names[] = { "try_column", "try_0", "try_1", "try_2" };
  const char* try_columns[] = { "try_0", "try_1", "try_2" };
  static const char* test_data[] = { "test_data_0", "test_data_1",
                                    "test_data_2" };
  Event_data_CFL_t test_event[] = { {.event_index = TEST_EVENT,
                                    .event_data = 0,
                                    .params = (void*)test_data[0]},
                                   {.event_index = TEST_EVENT + 1,
                                    .event_data = 1.1,
                                    .params = (void*)test_data[1]},
                                   {.event_index = TEST_EVENT + 2,
                                    .event_data = 2.2,
                                    .params = (void*)test_data[2]} };


  Store_try_function_CFL(input, "local_try_function", test_try_function);
  Store_one_shot_function_CFL(input, "process_try_chains", process_if_chains);

  Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);

  Asm_start_column_CFL(input, "try_column", true);
  Asm_log_message_CFL(input, "try column is active");
  Asm_try_columns_CFL(input, "local_try_function", NAME_SIZE_CFL(try_columns),
    try_columns, true, false, (void*)test_event);
  Asm_log_message_CFL(input, "try column is done");
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_0", false);
  Asm_store_current_column_event_CFL(input, &test_event[0]);
  Asm_one_shot_CFL(input, "process_try_chains", NULL);
  Asm_log_message_CFL(input, "try_0 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_0 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_1", false);
  Asm_store_current_column_event_CFL(input, &test_event[1]);
  Asm_one_shot_CFL(input, "process_try_chains", NULL);
  Asm_log_message_CFL(input, "try_1 should be active");
  Asm_wait_time_delay_CFL(input, 2000);
  Asm_log_message_CFL(input, "try_1 is terminating");
  Asm_set_return_code(input, false);
  Asm_terminate_CFL(input);
  Asm_end_column_CFL(input);

  Asm_start_column_CFL(input, "try_2", false);
  Asm_store_current_column_event_CFL(input, &test_event[2]);
  Asm_one_shot_CFL(input, "process_try_chains", NULL);
  Asm_log_message_CFL(input, "try_2 should  be active");
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
