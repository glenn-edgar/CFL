#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_data_flow_functions.h"
#include "CFL_s_logical_operations.h"

typedef struct df_buf_shift {
  unsigned short buf_index;
  unsigned short start;
  unsigned short number;
  short          shift_number;
  bool           back_fill;
  bool           fill_bit;
}df_buf_shift_t;

typedef struct df_copy_buf_t {
  unsigned short from_buf_index;
  unsigned short to_buf_index;
  unsigned short from_start;
  unsigned short to_start;
  unsigned short number;
}df_copy_buf_t;

typedef struct df_set_buf_positions_t {
  unsigned buf_index;
  unsigned short number;
  const unsigned short* positions;
  bool            value;
}df_set_buf_positions_t;

typedef struct df_buf_reset_t {
  unsigned buf_index;
  bool value;
}df_buf_reset_t;


typedef struct df_s_expression_t {
  unsigned short buf_index;
  unsigned short  buf_size;
  unsigned short  store_index;
  CFL_s_log_op_handle_t* s_log_op_handle;
  
}df_s_expression_t;

typedef struct df_wait_data_t {
  df_s_expression_t* s_expression;
  void* user_data;
}df_wait_data_t;

static inline void verify_bit_positions(void* handle, unsigned buf_index, unsigned bit_number, const bool* positions) {
  unsigned buf_size = Get_df_buf_size_CFL(handle, buf_index);
  unsigned i;
  for (i = 0; i < bit_number; i++) {
    if (positions[i] >= buf_size) {
      ASSERT_PRINT_INT("Bit position is greater than buf size", positions[i]);
    }
  }
}




void Asm_reset_df_buffer(void* input, const char* buffer_name, bool value) {
  df_buf_reset_t* df_buf_reset = (df_buf_reset_t*)Allocate_once_malloc_CFL(input, sizeof(df_buf_reset_t));
  df_buf_reset->buf_index = Get_df_buf_index_CFL(input, buffer_name);
  df_buf_reset->value = value;
  Asm_one_shot_CFL(input, "RESET_DF_BUFFER", df_buf_reset);
}

void Asm_set_df_buff_positions(void* input, const char* name, unsigned short number, const unsigned short* positions, bool value) {
  df_set_buf_positions_t* df_set_buf_positions = (df_set_buf_positions_t*)Allocate_once_malloc_CFL(input, sizeof(df_set_buf_positions_t));
  df_set_buf_positions->buf_index = Get_df_buf_index_CFL(input, name);
  df_set_buf_positions->number = number;
  df_set_buf_positions->positions = positions;
  df_set_buf_positions->value = value;
  Asm_one_shot_CFL(input, "SET_DF_BUF_POSITIONS", df_set_buf_positions);
}


void Asm_copy_df_buff_array(void* input, const char* from_bufF_name, const char* to_buff_name, unsigned short from_start, unsigned short to_start, unsigned short number) {
  df_copy_buf_t* df_copy_buf = (df_copy_buf_t*)Allocate_once_malloc_CFL(input, sizeof(df_copy_buf_t));
  unsigned short from_buf_index = Get_df_buf_index_CFL(input, from_bufF_name);
  unsigned short to_buf_index = Get_df_buf_index_CFL(input, to_buff_name);
  unsigned short from_size = Get_df_buf_size_CFL(input, from_buf_index);
  unsigned short to_size = Get_df_buf_size_CFL(input, to_buf_index);

  df_copy_buf->from_buf_index = from_buf_index;
  df_copy_buf->to_buf_index = to_buf_index;
  df_copy_buf->from_start = from_start;
  df_copy_buf->to_start = to_start;
  df_copy_buf->number = number;


  if (from_start + number > from_size) {
    ASSERT_PRINT_INT("Data flow buf from index exceeded", from_start + number);
  }
  if (to_start + number > to_size) {
    ASSERT_PRINT_INT("Data flow buf to index exceeded", to_start + number);
  }
  Asm_one_shot_CFL(input, "COPY_DF_BUF_ARRAY", df_copy_buf);

}

void Asm_shift_df_buffer(void* input, const char* buffer_name, short shift_number, unsigned start, unsigned number, bool back_fill, bool fill_bit) {

  df_buf_shift_t* df_buf_shift = (df_buf_shift_t*)Allocate_once_malloc_CFL(input, sizeof(df_buf_shift_t));
  df_buf_shift->buf_index = Get_df_buf_index_CFL(input, buffer_name);
  df_buf_shift->start = start;
  df_buf_shift->number = number;
  df_buf_shift->shift_number = shift_number;
  df_buf_shift->back_fill = back_fill;
  df_buf_shift->fill_bit = fill_bit;

  Asm_one_shot_CFL(input, "SHIFT_DF_BUFFER", df_buf_shift);

}

void Asm_print_df_buf_CFL(void* input, const char* buffer_name) {

  unsigned short buf_index = Get_df_buf_index_CFL(input, buffer_name);
  unsigned short *buf = Allocate_once_malloc_CFL(input, sizeof(unsigned short));
  *buf = buf_index;
  Asm_one_shot_CFL(input, "PRINT_DF_BUF", (void*)buf);


}



void Asm_store_s_expression(void* input, const char* buffer_name,unsigned short store_index, const char* s_expression) {
  df_s_expression_t* df_s_expression = (df_s_expression_t*)Allocate_once_malloc_CFL(input, sizeof(df_s_expression_t));
  df_s_expression->buf_index = Get_df_buf_index_CFL(input, buffer_name);
  
  df_s_expression->buf_size = Get_df_buf_size_CFL(input,df_s_expression->buf_index);
  df_s_expression->store_index = store_index;
  df_s_expression->s_log_op_handle = Compile_s_log_op_CFL(input,df_s_expression->buf_index,s_expression);
  Asm_one_shot_CFL(input, "STORE_S_EXPRESSION", df_s_expression);
}




void Asm_wait_df_tokens_s_expression_CFL(void* input, const char* buf_name, int time_out_ms, char* one_shot_failure_fn, 
             void* user_data, bool terminate_flag,const char* s_expression) {

  df_s_expression_t* df_s_expression = (df_s_expression_t*)Allocate_once_malloc_CFL(input, sizeof(df_s_expression_t));
  df_s_expression->buf_index = Get_df_buf_index_CFL(input, buf_name);
  
  df_s_expression->buf_size = Get_df_buf_size_CFL(input,df_s_expression->buf_index);
  df_s_expression->store_index = 0;
  df_s_expression->s_log_op_handle = Compile_s_log_op_CFL(input,df_s_expression->buf_index,s_expression);
  
  df_wait_data_t* df_wait_data = (df_wait_data_t*)Allocate_once_malloc_CFL(input, sizeof(df_wait_data_t));
  df_wait_data->s_expression = df_s_expression;
  df_wait_data->user_data = user_data;

  
 

  Asm_wait_CFL(input,"TEST_S_EXPRESSION", time_out_ms, terminate_flag, one_shot_failure_fn,df_wait_data);

}


void Asm_verify_df_tokens_s_expression_CFL(void* input, const char* buf_name, const char* s_expression, const char* one_shot_failure_fn, void* user_data, bool terminate_flag) {

 df_s_expression_t* df_s_expression = (df_s_expression_t*)Allocate_once_malloc_CFL(input, sizeof(df_s_expression_t));
  df_s_expression->buf_index = Get_df_buf_index_CFL(input, buf_name);
  
  df_s_expression->buf_size = Get_df_buf_size_CFL(input,df_s_expression->buf_index);
  df_s_expression->store_index = 0;
  df_s_expression->s_log_op_handle = Compile_s_log_op_CFL(input,df_s_expression->buf_index,s_expression);
  
  df_wait_data_t* df_wait_data = (df_wait_data_t*)Allocate_once_malloc_CFL(input, sizeof(df_wait_data_t));
  df_wait_data->s_expression = df_s_expression;
  df_wait_data->user_data = user_data;
 
  Asm_verify_CFL(input,"TEST_S_EXPRESSION", terminate_flag, one_shot_failure_fn,df_wait_data);
  
}








int reserve_df_column_function_space_CFL() {
  return 0;
}


void load_df_column_functions_CFL(void* input) {
  ;
}


static bool test_s_expression(void* handle, void* params, Event_data_CFL_t* event_data);


static const bool_function_ref bool_functions[] = {
   
    {"TEST_S_EXPRESSION",test_s_expression},
    
};

int reserve_df_bool_function_space_CFL() {
  return sizeof(bool_functions) / sizeof(bool_function_ref);
}

void  load_df_bool_functions_CFL(void* input) {
  int size;
  const bool_function_ref* ref_ptr;
  size = reserve_df_bool_function_space_CFL();

  for (int i = 0; i < size; i++) {
    ref_ptr = bool_functions + i;
    Store_bool_function_CFL(input, ref_ptr->name, ref_ptr->fn);
  }
}


CFL_s_log_op_handle_t* Compile_s_log_op_CFL(void* input, unsigned buffer_index, const char* s_expression);
bool Execute_s_log_op_CFL(void* input, CFL_s_log_op_handle_t* s_log_op_handle);

static bool test_s_expression(void* handle, void* params, Event_data_CFL_t* event_data){

  df_wait_data_t* df_wait_data = (df_wait_data_t*)params;
  bool result = Execute_s_log_op_CFL(handle, df_wait_data->s_expression->s_log_op_handle);
  return result;

 

}



static void df_buffer_shift(void* input, void* params, Event_data_CFL_t* event_data);
static void print_df_buf_CFL(void* input, void* parameter, Event_data_CFL_t* event_data);

static void reset_df_buffer(void* input, void* parameter, Event_data_CFL_t* event_data);
static void copy_df_buff_array(void* input, void* params, Event_data_CFL_t* event_data);
static void set_df_buf_positions(void* input, void* params, Event_data_CFL_t* event_data);
static void store_s_expression(void* input, void* params, Event_data_CFL_t* event_data);

static const one_shot_function_ref one_shot_functions[] = {

    
    {"PRINT_DF_BUF",print_df_buf_CFL },
    {"SHIFT_DF_BUFFER",df_buffer_shift},
    {"COPY_DF_BUF_ARRAY", copy_df_buff_array },
    {"SET_DF_BUF_POSITIONS",set_df_buf_positions },
    {"RESET_DF_BUFFER",reset_df_buffer},
    {"STORE_S_EXPRESSION",store_s_expression},
};

int reserve_df_one_shot_function_space_CFL() {
  // Printf_CFL("one shot function size");
  // Printf_CFL(sizeof(one_shot_functions)/sizeof(one_shot_function_ref));
  return sizeof(one_shot_functions) / sizeof(one_shot_function_ref);
}

void load_df_one_shot_function_state_CFL(void* input) {
  int size;
  const one_shot_function_ref* ref_ptr;
  size = reserve_df_one_shot_function_space_CFL();
  for (int i = 0; i < size; i++) {
    ref_ptr = one_shot_functions + i;
    Store_one_shot_function_CFL(input, ref_ptr->name, ref_ptr->fn);
  }
}

static void store_s_expression(void* input, void* params, Event_data_CFL_t* event_data) {
  df_s_expression_t* df_s_expression = (df_s_expression_t*)params;
  bool result = Execute_s_log_op_CFL(input, df_s_expression->s_log_op_handle);
   Set_df_buf_number_CFL(input, df_s_expression->buf_index, df_s_expression->store_index, result);

}

static void reset_df_buffer(void* input, void* parameter, Event_data_CFL_t* event_data) {
  df_buf_reset_t* df_buf_reset = (df_buf_reset_t*)parameter;
  Reset_df_buf_CFL(input, df_buf_reset->buf_index, df_buf_reset->value);
}



static void copy_df_buff_array(void* input, void* params, Event_data_CFL_t* event_data) {
  df_copy_buf_t* df_copy_buf = (df_copy_buf_t*)params;
  Copy_df_buff_array_CFL(input, df_copy_buf->from_buf_index, df_copy_buf->to_buf_index, df_copy_buf->from_start, df_copy_buf->to_start, df_copy_buf->number);

}


static void set_df_buf_positions(void* input, void* params, Event_data_CFL_t* event_data) {
  df_set_buf_positions_t* df_set_buf_positions = (df_set_buf_positions_t*)params;

  Set_df_buf_positions_CFL(input, df_set_buf_positions->buf_index, df_set_buf_positions->number, df_set_buf_positions->positions, df_set_buf_positions->value);
}


static void df_buffer_shift(void* input, void* params, Event_data_CFL_t* event_data) {

  df_buf_shift_t* df_buf_shift = (df_buf_shift_t*)params;

  Shift_df_buf_array_CFL(input, df_buf_shift->buf_index, df_buf_shift->shift_number, df_buf_shift->start, df_buf_shift->number,df_buf_shift->back_fill, df_buf_shift->fill_bit);
  

}

static void print_df_buf_CFL(void* input, void* parameter, Event_data_CFL_t* event_data) {
  unsigned short *buf_index = (unsigned short *)parameter;
  Print_df_buf_CFL(input, *buf_index);
}

























