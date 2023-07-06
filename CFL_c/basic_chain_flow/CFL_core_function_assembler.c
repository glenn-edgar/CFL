#include "Cfl_user_functions.h"


#include "Cfl_columns.h"
#include "Cfl_core_function_assembler.h"
#include "Cfl_functions.h"


void Asm_columns_CFL(void* input, int number, const char** column_names) {


  reserve_column_names_CFL(input, number, column_names);
}

void Asm_dump_nodes_CFL(void* input) {

  Asm_one_shot_CFL(input, "DUMP_NODES", NULL);
}

void Verify_nodes_CFL(void* input) {

  Asm_one_shot_CFL(input, "VERIFY_NODES", NULL);
}

static const bool column_return_code_true = true;
static const bool column_return_code_false = false;

void Asm_set_return_code(void* input, bool return_code) {

  if (return_code == true) {

    Asm_one_shot_CFL(input, "COLUMN_RETURN_CODE",
      (void*)&column_return_code_true);
  }
  else {
    Asm_one_shot_CFL(input, "COLUMN_RETURN_CODE",
      (void*)&column_return_code_false);
  }
}

void Asm_one_shot_terminate_CFL(void* input, const char* one_shot_function_name,
  void* parameters) {

  One_shot_function_CFL_t fn;
  fn = Get_one_shot_function_CFL(input, one_shot_function_name);

  Asm_store_column_element_CFL(input, "BID_ONE_SHOT", (void *)fn,
    (void*)parameters);
}
void Asm_one_shot_CFL(void* input, const char* one_shot_function_name,
  void* parameters) {

  One_shot_function_CFL_t fn;
  fn = Get_one_shot_function_CFL(input, one_shot_function_name);

  Asm_store_column_element_CFL(input, "ONE_SHOT", (void*)fn,
    (void*)parameters);
}

static const int reset_buffer[1] = { RESET_CFL };
void Asm_reset_CFL(void* input) {

  Asm_store_column_element_CFL(input, "RETURN_CONDITION_CODE", NULL,
    (void*)reset_buffer);
}

static const int halt_buffer[1] = { HALT_CFL };
void Asm_halt_CFL(void* input) {

  Asm_store_column_element_CFL(input, "RETURN_CONDITION_CODE", NULL,
    (void*)halt_buffer);
}

static const int terminate_buffer[1] = { TERMINATE_CFL };

void Asm_terminate_CFL(void* input) {
  Asm_store_column_element_CFL(input, "RETURN_CONDITION_CODE", NULL,
    (void*)terminate_buffer);
}

static const int terminate_engine_buffer[1] = { ENGINE_TERMINATE_CFL };
void Asm_engine_terminate_CFL(void* input) {
  Asm_store_column_element_CFL(input, "RETURN_CONDITION_CODE", NULL,
    (void*)terminate_engine_buffer);
}

void Asm_log_message_CFL(void* input, const char* message) {
  Asm_one_shot_CFL(input, "LOG_MESSAGE", (void*)message);
}

void Asm_send_event_CFL(void* input, Event_data_CFL_t* event_data) {
  Asm_one_shot_CFL(input, "SEND_EVENT", event_data);
}

void Asm_set_column_watch_dog_CFL(void* input, unsigned time_out_ms,
  bool term_flag,
  const char* one_shot_term_function) {
 
  Column_watch_dog_CFL_t* column_watch_dog;

  column_watch_dog = (Column_watch_dog_CFL_t*)Allocate_once_malloc_CFL(input, sizeof(Column_watch_dog_CFL_t));
  column_watch_dog->termination_flag = term_flag;
  column_watch_dog->trigger_count = time_out_ms;
  column_watch_dog->trigger_function =
    Get_one_shot_function_CFL(input, one_shot_term_function);

  Asm_one_shot_CFL(input, "SET_COLUMN_WATCH_DOG", column_watch_dog);
  
}

void Asm_clear_column_watch_dog_CFL(void* input) {
  Asm_one_shot_CFL(input, "CLEAR_COLUMN_WATCH_DOG", (void*)NULL);
}



void Asm_store_columns_local_data_CFL(void* input, unsigned short column_number, const char** column_indexes, void **data) {

  Column_data_CFL_t* column_data;
  column_data = (Column_data_CFL_t*)Allocate_once_malloc_CFL(input, sizeof(Column_data_CFL_t));
  column_data->number = column_number;
  column_data->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(input, sizeof(unsigned short));
  column_data->data = (void**)Allocate_once_malloc_CFL(input, sizeof(void*)*column_number);
  for (int i = 0; i < column_number; i++) {
    short temp = Find_column_index_CFL(input, column_indexes[i]);
    if (temp <= 0) {
      ASSERT_PRINT_F("Invalid column name %s",column_indexes[i] );
    }
    column_data->column_indexes[i] = temp;
    column_data->data[i] = data[i];
  }
  Asm_one_shot_CFL(input, "SET_COLUMNS_DATA", column_data);

}


void Asm_store_current_column_local_data_CFL(void* input,void *data) {

  Asm_one_shot_CFL(input, "SET_CURRENT_COLUMN_DATA", data);
}

void Asm_wait_CFL(void* input, const char* bool_fn_name, int time_out_ms,
  bool terminate_flag, const char* one_shot_time_out_fn,
  void* user_data) {

  Bool_function_CFL_t fn;
  One_shot_function_CFL_t fn_time_out;
  While_control_CFL_t* while_control;

  fn = Get_bool_function_CFL(input, bool_fn_name);

  fn_time_out = Get_one_shot_function_CFL(input, one_shot_time_out_fn);

  while_control = (While_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(While_control_CFL_t));
  while_control->time_out_ms = time_out_ms;
  while_control->terminate_flag = terminate_flag;
  while_control->user_data = user_data;
  while_control->user_time_out_fn = fn_time_out;
  Asm_store_column_element_CFL(input, "WHILE", (void*)fn,
    (void*)while_control);
}

void Asm_wait_event_count_CFL(void* input, int event_id, int number_of_events,
  int time_out_ms, bool terminate_flag,
  const char* one_shot_time_out_fn,
  void* user_data) {

  While_event_control_CFL_t* while_event_control;
  One_shot_function_CFL_t fn_time_out;

  fn_time_out = Get_one_shot_function_CFL(input, one_shot_time_out_fn);


  while_event_control = (While_event_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(While_event_control_CFL_t));
  while_event_control->number_of_events = number_of_events;
  while_event_control->event_index = event_id;
  while_event_control->terminate_flag = terminate_flag;
  while_event_control->time_out_ms = time_out_ms;
  while_event_control->user_data = user_data;
  while_event_control->user_termination_fn = fn_time_out;

  Asm_wait_CFL(input, "WAIT_EVENT_COUNT", time_out_ms, terminate_flag,
    one_shot_time_out_fn, (void*)while_event_control);
}

void Asm_wait_time_delay_CFL(void* input, unsigned long time_delay_ms) {

  While_time_control_CFL_t* while_time_control;


  while_time_control = (While_time_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(While_time_control_CFL_t));
  while_time_control->time_delay = time_delay_ms;
  Asm_wait_CFL(input, "WAIT_TIME_DELAY", -1, false, NULL,
    (void*)while_time_control);
}

void Asm_verify_CFL(void* input, const char* bool_fn_name, bool terminate_flag,
  const char* one_shot_failure_fn, void* user_data) {


  Bool_function_CFL_t fn;
  One_shot_function_CFL_t fn_failure;

  Verify_control_CFL_t* verify_control;



  fn = Get_bool_function_CFL(input, bool_fn_name);

  fn_failure = Get_one_shot_function_CFL(input, one_shot_failure_fn);

  verify_control = (Verify_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(Verify_control_CFL_t));

  verify_control->terminate_flag = terminate_flag;
  verify_control->user_data = user_data;
  verify_control->user_termination_fn = fn_failure;

  Asm_store_column_element_CFL(input, "VERIFY", (void*)fn,
    (void*)verify_control);
}

void Asm_process_columns_action_CFL(void* input, char* one_shot_fn,
  unsigned col_number,
  const char** column_names,
  void* user_data) {
  Valid_column_indexes_t* valid_column_links;

  valid_column_links = (Valid_column_indexes_t*)Allocate_once_malloc_CFL(
    input, sizeof(Valid_column_indexes_t));
  valid_column_links->number_of_columns = col_number;
  valid_column_links->column_indexes =
    (unsigned short*)Allocate_once_malloc_CFL(input, sizeof(unsigned short) *
      col_number);
  valid_column_links->user_data = user_data;

  for (unsigned i = 0; i < col_number; i++) {
    unsigned short index = Find_column_index_CFL(input, *column_names++);

    valid_column_links->column_indexes[i] = index;
  }

  Asm_one_shot_CFL(input, one_shot_fn, (void*)valid_column_links);
}

void Asm_disable_columns_CFL(void* input, int number_of_columns,
  const char** column_names) {

  Column_index_CFL_t* column_index;

  column_index = (Column_index_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(Column_index_CFL_t));
  column_index->column_number = number_of_columns;
  column_index->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);

  unsigned short* index_pointer = column_index->column_indexes;
  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }

  Asm_one_shot_CFL(input, "DISABLE_COLUMNS", column_index);
}

void Asm_reset_columns_CFL(void* input, int number_of_columns,
  const char** column_names) {

  Column_index_CFL_t* column_index;

  column_index = (Column_index_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(Column_index_CFL_t));
  column_index->column_number = number_of_columns;
  column_index->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);

  unsigned short* index_pointer = column_index->column_indexes;
  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }

  Asm_one_shot_CFL(input, "RESET_COLUMNS", column_index);
}

void Asm_enable_columns_CFL(void* input, int number_of_columns,
  const char** column_names, bool terminate_flag) {

  Column_index_CFL_t* column_index;

  column_index = (Column_index_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(Column_index_CFL_t));
  column_index->column_number = number_of_columns;
  column_index->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);
  column_index->terminate_flag = terminate_flag;
  unsigned short* index_pointer = column_index->column_indexes;
  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }

  Asm_store_column_element_CFL(input, "ENABLE_COLUMNS", NULL,
    (void*)column_index);
}

void Asm_join_columns_CFL(void* input, int number_of_columns,
  const char** column_names, bool termination_flag) {

  Column_index_CFL_t* column_index;

  column_index = (Column_index_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(Column_index_CFL_t));
  column_index->terminate_flag = termination_flag;
  column_index->column_number = number_of_columns;
  column_index->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);

  unsigned short* index_pointer = column_index->column_indexes;
  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }

  Asm_store_column_element_CFL(input, "JOIN_COLUMNS", NULL,
    (void*)column_index);
}

void Asm_if_columns_CFL(void* input, const char* if_function,
  int number_of_columns, const char** column_names,const char* termination_fn,void* user_data) {

  If_function_CFL_t fn_if;
  If_control_CFL_t* if_control;
  One_shot_function_CFL_t fn_one_shot;

  fn_if = Get_if_function_CFL(input, if_function);
  fn_one_shot = Get_one_shot_function_CFL(input, termination_fn);

  if_control = (If_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(If_control_CFL_t));

  if_control->column_number = number_of_columns;
  if_control->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);
  if_control->return_indexes =
    (bool*)Allocate_once_malloc_CFL(input, sizeof(bool) * number_of_columns);

  
  if_control->termination_fn = fn_one_shot;
  if_control->user_data = user_data;

  unsigned short* index_pointer = if_control->column_indexes;
  bool* bool_pointer = if_control->return_indexes;

  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
    *bool_pointer++ = false;
  }

  Asm_store_column_element_CFL(input, "IF_COLUMNS", (void*)fn_if,
    (void*)if_control);
}

void Asm_try_columns_CFL(void* input, const char* try_function_name,
  int number_of_columns, const char** column_names,bool invert_flag, void* user_data) {

  Try_function_CFL_t fn_try;
  Try_column_CFL_t* try_control;

  fn_try = Get_try_function_CFL(input, try_function_name);

  try_control = (Try_column_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(Try_column_CFL_t));
 
  try_control->invert_flag = invert_flag;
  try_control->column_number = number_of_columns;
  try_control->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);

  try_control->user_data = user_data;

  unsigned short* index_pointer = try_control->column_indexes;

  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }

  Asm_store_column_element_CFL(input, "TRY_COLUMN", (void*)fn_try,
    (void*)try_control);
}

void Asm_while_columns_CFL(void* input, const char* bool_fn_name,
  int number_of_columns, const char** column_names,
  void* user_data) {
  While_column_control_CFL_t* while_control;
  Bool_function_CFL_t fn;

  fn = Get_bool_function_CFL(input, bool_fn_name);

  while_control = (While_column_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(While_column_control_CFL_t));
  while_control->user_data = user_data;
  while_control->number_of_columns = number_of_columns;
  while_control->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);

  unsigned short* index_pointer = while_control->column_indexes;

  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }
  Asm_store_column_element_CFL(input, "WHILE_COLUMN", (void*)fn,
    (void*)while_control);
}

void Asm_do_while_columns_CFL(void* input, const char* bool_fn_name,
  int number_of_columns, const char** column_names,
  void* user_data) {
  While_column_control_CFL_t* while_control;
  Bool_function_CFL_t fn;

  fn = Get_bool_function_CFL(input, bool_fn_name);

  while_control = (While_column_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(While_column_control_CFL_t));
  while_control->user_data = user_data;
  while_control->number_of_columns = number_of_columns;
  while_control->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(unsigned short) * number_of_columns);

  unsigned short* index_pointer = while_control->column_indexes;

  for (int i = 0; i < number_of_columns; i++) {
    int index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }
  Asm_store_column_element_CFL(input, "DO_WHILE_COLUMN", (void*)fn,
    (void*)while_control);
}

void Asm_for_columns_CFL(void* input, int number_of_times,
  unsigned number_of_columns, const char** column_names,
  char* one_shot_function_name, void* user_data) {

  For_control_CFL_t* for_control;
  One_shot_function_CFL_t fn;

  fn = Get_one_shot_function_CFL(input, one_shot_function_name);

  for_control = (For_control_CFL_t*)Allocate_once_malloc_CFL(
    input, sizeof(For_control_CFL_t));
  for_control->number_of_columns = number_of_columns;
  for_control->number_of_iterations = number_of_times;
  for_control->fn = fn;
  for_control->user_data = user_data;
  for_control->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(
    input, sizeof(short) * number_of_columns);
  unsigned short* index_pointer = for_control->column_indexes;

  for (unsigned i = 0; i < number_of_columns; i++) {
    unsigned short index = Find_column_index_CFL(input, *column_names++);
    *index_pointer++ = index;
  }
  Asm_store_column_element_CFL(input, "FOR_COLUMN", NULL, (void*)for_control);
}



void Asm_attach_event_handler_CFL(void* input, short event_index, const char* fn_name, void* user_data) {

  Event_handler_fn_CFL_t* event_handler_fn;
  Column_function_CFL_t fn;
  event_handler_fn = (Event_handler_fn_CFL_t*)Allocate_once_malloc_CFL(input, sizeof(Event_handler_fn_CFL_t));
  event_handler_fn->activate_flag = false;
  event_handler_fn->event_number = 1;
  event_handler_fn->event_indexes = (short*)Allocate_once_malloc_CFL(input, sizeof(short));
  event_handler_fn->event_indexes[0] = event_index;
  event_handler_fn->user_data = user_data;
  fn = Get_column_function_CFL(input, fn_name);
  Asm_store_column_element_CFL(input, "EVENT_HANDLER_FN", (void*)fn, (void*)event_handler_fn);
}


void Asm_attach_multi_event_handler_CFL(void* input, unsigned number, const short* event_index, const char* fn_name, void* user_data) {

  Event_handler_fn_CFL_t* event_handler_fn;
  Column_function_CFL_t fn;
  event_handler_fn = (Event_handler_fn_CFL_t*)Allocate_once_malloc_CFL(input, sizeof(Event_handler_fn_CFL_t));
  event_handler_fn->activate_flag = false;
  event_handler_fn->event_number = number;
  event_handler_fn->event_indexes = (short*)Allocate_once_malloc_CFL(input, sizeof(short) * number);
  for (unsigned i = 0; i < number; i++) {
    event_handler_fn->event_indexes[i] = event_index[i];
  }
  event_handler_fn->user_data = user_data;
  fn = Get_column_function_CFL(input, fn_name);

  Asm_store_column_element_CFL(input, "EVENT_HANDLER_FN", (void*)fn, (void*)event_handler_fn);
}

void Asm_handle_enable_join_actions_CFL(void* input, unsigned number_of_columns, const char** column_names) {

  Enable_join_CFL_t* enable_join = (Enable_join_CFL_t*)Allocate_once_malloc_CFL(input, sizeof(Enable_join_CFL_t));
  enable_join->number_of_columns = number_of_columns;
  enable_join->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(input, sizeof(unsigned short) * number_of_columns);
  for (int i = 0; i < enable_join->number_of_columns; i++) {
    enable_join->column_indexes[i] = Find_column_index_CFL(input, column_names[i]);

  }
  Asm_store_column_element_CFL(input, "EVENT_HANDLER_FN",NULL, (void*)enable_join);
  

}



