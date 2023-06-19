#ifndef __USER_FUNCTION_H__
#define __USER_FUNCTION_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#include "Cfl_debug.h"

// comment out to disable
#define __PRIORITY_HEAP_DEBUG__
#define NAME_SIZE_CFL(x) sizeof(x) / sizeof(char *)

#define NO_TIME_OUT_CFL -1

#define PRINT_BUF_SIZE_CFL 256
#define ENABLE_DEBUG_MSG_CFL 
                                                                                                                           
/*
**
**  User Modified items
**
*/
typedef long long unsigned (*Elasped_ms_fn)(void);

typedef struct Time_control_CFL_t
{
  int tick_ms;
  Elasped_ms_fn ms_fn;
  unsigned short current_millis;
  unsigned short start_millis;
  unsigned char second;
  unsigned char minute;
  unsigned char hour;
  unsigned char day;
  unsigned char dow;
  unsigned char month;
  unsigned short day_of_year;
  unsigned short year;
} Time_control_CFL_t;

typedef struct Event_data_CFL_t
{
  short event_index;
  float event_data;
  void* params;

} Event_data_CFL_t;

typedef struct Event_control_CFL_t {
  unsigned short id;
  unsigned short rx_index;
  unsigned short tx_index;
  unsigned short current_queued_number;
  unsigned short max_number;
  Event_data_CFL_t* event_data_queue;


} Event_control_CFL_t;

typedef void (*Idle_function_CFL_t)(void* handle, Time_control_CFL_t* timer_control, bool init_flag);
typedef void (*Calendar_function_CFL_t)(void* handle, Time_control_CFL_t* timer_control, bool init_flag);



#define RETICK_EVENT_CFL           -11   
#define ENGINE_TERMINATE_EVENT_CFL -10
#define EVENT_TERMINATION_CFL      -9
#define EVENT_INIT_CFL             -8
#define TIMER_TICK_CFL             -7
#define SECOND_TICK_CFL            -6
#define MINUTE_TICK_CFL            -5
#define HOUR_TICK_CFL              -4
#define DAY_TICK_CFL               -3
#define MONTH_TICK_CFL             -2
#define YEAR_TICK_CFL              -1


#define USER_EVENT_START_CFL        0


// add event id;s at this point

/*
** Column Functions Return Functions
**
*/

#define CONTINUE_CFL 1
#define DISABLE_CFL 2
#define HALT_CFL 3
#define RESET_CFL 4
#define TERMINATE_CFL 5
#define ENGINE_TERMINATE_CFL 6
#define COLUMN_STATE_CHANGE_CFL 7

// include user defined events  after this

/*
**
**  End of User Modified Items
**
*/

/*
**  Configure,  Start and Stop Engine
*/

typedef void (*One_shot_function_CFL_t)(void* handle, void* params, Event_data_CFL_t* event_data);

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

typedef struct Try_column_CFL_t
{
  bool init_flag;
  bool invert_flag;
  bool terminate_flag;
  unsigned char progress_step;
  unsigned short current_column_index;
  unsigned short column_number;
  unsigned short* column_indexes;
  bool final_state;
  void* user_data;

} Try_column_CFL_t;






typedef bool (*Bool_function_CFL_t)(void* handle, void* params, Event_data_CFL_t* event_data);
typedef void (*If_function_CFL_t)(void* handle, If_control_CFL_t* params);
typedef void (*Try_function_CFL_t)(void* handle, Try_column_CFL_t* params);






typedef union {
    One_shot_function_CFL_t   one_shot_fn;
    Bool_function_CFL_t       bool_fn;
    If_function_CFL_t         if_fn;
    Try_function_CFL_t        try_fn;
    
} CFL_fn_t;
          
typedef int (*Column_function_CFL_t)(void* handle, void *aux_fun, void* params, Event_data_CFL_t* event_data);


#include "CFL_column_function_structures.h"


typedef struct handle_config_CFL_t
{

  unsigned number_of_columns;
  unsigned number_of_column_elements;
  unsigned number_column_functions;
  unsigned number_bool_functions;
  unsigned number_if_functions;
  unsigned one_shot_functions;
  unsigned number_of_try_functions;
  unsigned number_of_named_queues;
  unsigned number_df_buffers;
  unsigned number_of_compiled_s_log_expressions;
  unsigned number_of_state_machines;
  Debug_out_CFL_t debug_out;
} Handle_config_CFL_t;

Handle_config_CFL_t* Create_config_handle_CFL(Debug_out_CFL_t debug_out);

void* Configure_engine_CFL(Handle_config_CFL_t* config, unsigned allocate_once_heap_size, unsigned private_heap_size);

void Destroy_engine_CFL(void* handle);

/*
** Add user functions
**
*/

void Store_bool_function_CFL(void* input, const char* name, Bool_function_CFL_t function);
void Store_if_function_CFL(void* input, const char* name, If_function_CFL_t function);
void Store_column_function_CFL(void* input, const char* name, Column_function_CFL_t function);
void Store_one_shot_function_CFL(void* input, const char* name, One_shot_function_CFL_t function);
void Store_try_function_CFL(void* input, const char* name, Try_function_CFL_t function);


Bool_function_CFL_t Get_bool_function_CFL(void* input, const char* name);
If_function_CFL_t Get_if_function_CFL(void* input, const char* name);
Column_function_CFL_t Get_column_function_CFL(void* input, const char* name);
One_shot_function_CFL_t Get_one_shot_function_CFL(void* input, const char* name);
Try_function_CFL_t Get_try_function_CFL(void* input, const char* name);


typedef struct Symbol_record_CFL_t{
  const char* name;
  int   value;
  int   type;
} Symbol_record_CFL_t;

typedef  void*  Symbol_table_handle_CFL_t;

Symbol_table_handle_CFL_t Construct_symbol_table_CFL(void *input, unsigned short symbol_number, const Symbol_record_CFL_t* symbol_records);
bool Get_symbol_table_entry_CFL(void* input, Symbol_table_handle_CFL_t symbol_hamdle, const char* name, int* value, int* type);


void Store_s_expression_CFL(void* input,const char *s_expr_name, const char* s_expression);
CFL_s_log_op_handle_t* Get_s_expression_index_CFL(void* input, const char* s_expr_name); 




void Define_df_buf_CFL(void* input, const char* buf_name, unsigned short buf_size, unsigned short symbol_number, const Symbol_record_CFL_t* symbol_array);
unsigned short Get_df_buf_index_CFL(void* input, const char* name);
Symbol_table_handle_CFL_t Get_df_buf_symbol_table_CFL(void *input, unsigned short index);

unsigned short Get_df_buf_size_CFL(void* input, unsigned short index);
bool Get_df_buf_value_CFL(void *input,unsigned short buf_index, unsigned short position_index);
void Set_df_buf_number_CFL(void *input,unsigned short buf_index, unsigned short position_index, bool value);
void Reset_df_buf_CFL(void *input,unsigned short buf_index, bool value);
void Set_df_buf_positions_CFL(void *input,unsigned short buf_index, unsigned short position_number, const unsigned short* position_indexes, bool value);
void Copy_df_buff_array_CFL(void *input, unsigned short from_bufF_index, unsigned short to_buff_index, unsigned short from_start, unsigned short to_start, unsigned short number);
bool Match_df_buf_positions_CFL(void *input , unsigned short buf_index, unsigned short position_number,const unsigned short *positions, bool value);
void Shift_df_buf_array_CFL(void* input, unsigned short buf_index, int shift_number, unsigned short start, unsigned short number, bool back_fill,bool fill_bit);
void Print_df_buf_CFL(void *input,unsigned short buf_index);


/*
** Allocate once Heap
*/
void* Allocate_once_malloc_CFL(void* handle, int size);
int Allocate_once_remaining_heap_size_CFL(void* handle);

/*
Instruction building
*/

void Asm_columns_CFL(void* input, int number, const char** column_names);
void Asm_start_column_CFL(void* input, const char* column_name, bool start_flag);
void Asm_start_column_event_queue_CFL(void* input, const char* column_name, bool start_flag, const char* named_event_queue);
void Asm_store_column_element_CFL(void* input, const char* name, void* fn, void* params);
void Asm_store_column_element_direct_CFL(void* input, Column_function_CFL_t fn, void* aux_fun, void* params);
void Asm_end_column_CFL(void* input);





/*
** Start engine
**
*/

void Start_engine_CFL(void* handle, int ms_tick, int event_queue_depth, Idle_function_CFL_t idle_function, Calendar_function_CFL_t calendar_function);

/*
** Instructions used to higher level nodes
*/

void Asm_set_return_code(void* input, bool return_code);

/*
** Watch Dog functions
*/
void Asm_set_column_watch_dog_CFL(void* input, unsigned time_out_ms, bool term_flag, const char* one_shot_term_function);
void Asm_clear_column_watch_dog_CFL(void* input);

/*
** Internal Column Events
*/
void Asm_store_current_column_event_CFL(void* input, Event_data_CFL_t* event_data);

/*
**  return functions
*/
void Asm_halt_CFL(void* handle);
void Asm_reset_CFL(void* handle);
void Asm_terminate_CFL(void* handle);
void Asm_engine_terminate_CFL(void* handle);

// debug message
void Asm_log_message_CFL(void* handle, const char* messsage);

void Asm_one_shot_CFL(void* input, const char* one_shot_function_name, void* parameters);
void Asm_one_shot_terminate_CFL(void* input, const char* one_shot_function_name, void* parameters);
void Asm_process_columns_action_CFL(void* input, char* one_shot_fn, unsigned col_number, const char** columns,void *user_data);
void Asm_send_event_CFL(void* input, Event_data_CFL_t* params);

void Asm_wait_CFL(void* input, const char* bool_fn_name, int time_out_ms, bool terminate_flag, const char* one_shot_time_out_fn, void* user_data);
void Asm_wait_event_count_CFL(void* input, int event_id, int number_of_events, int time_out_ms, bool terminate_flag, const char* one_shot_time_out_fn, void* user_data);

void Asm_wait_time_delay_CFL(void* input, unsigned long time_delay_ms);

void Asm_verify_CFL(void* input, const char* bool_fn_name, bool terminate_flag, const char* one_shot_failure_fn, void* user_data);


// tod functions

void Asm_wait_tod_lt(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_le(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_eq(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_ge(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_gt(void *input, short doy, short month, short dow, short hour, short minute,  short second);

void Asm_verify_tod_lt(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char* one_shot_failure_fn, void* user_data);
void Asm_verify_tod_le(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char* one_shot_failure_fn, void* user_data);
void Asm_verify_tod_eq(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char* one_shot_failure_fn, void* user_data);
void Asm_verify_tod_ge(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char* one_shot_failure_fn, void* user_data);
void Asm_verify_tod_gt(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char* one_shot_failure_fn, void* user_data);



// column control
void Asm_disable_columns_CFL(void* input, int number_of_columns, const char** column_names);
void Asm_enable_columns_CFL(void* input, int number_of_columns, const char** column_names, bool terminate_flag);
void Asm_reset_columns_CFL(void* input, int number_of_columns, const char** column_names);
void Asm_join_columns_CFL(void* input, int number_of_columns, const char** column_names, bool terminate_flag);
void Asm_if_columns_CFL(void* input, const char* if_function,
  int number_of_columns, const char** column_names, bool terminate_flag, const char* termination_fn, void* user_data);
void Asm_try_columns_CFL(void* input, const char* try_function_name, int number_of_columns,
  const char** column_names, bool terminate_flag, bool invert_flag, void* user_data);

// column loop control

void Asm_while_columns_CFL(void* input, const char* bool_fn_name, int number_of_columns, const char** column_names, void* user_data);
void Asm_do_while_columns_CFL(void* input, const char* bool_fn_name, int number_of_columns, const char** column_names, void* user_data);
void Asm_for_columns_CFL(void* input, int number_of_times, int number_of_columns, const char** column_names,
  char* one_shot_function_name, void* user_data);




void Asm_attach_event_handler_CFL(void* input, short event_index, const char* fn_name, void* user_data);

void Asm_attach_multi_event_handler_CFL(void* input, unsigned number, const short* event_index, const char* fn_name, void* user_data);

void Asm_handle_enable_join_actions_CFL(void* input, unsigned number_of_events, const short* event_indexes, unsigned number_of_columns, const char** column_names);



/*
**  Data flow functions
*/

void Store_s_logical_expression_CFL(void* input,const char *buffer_name, const char *s_expr_name, const char* s_expression);
CFL_s_log_op_handle_t* Get_s_logical_expression_index_CFL(void* input, const char* s_expr_name);




void Asm_reset_df_buffer_CFL(void *input, const char *buffer_name, bool value);

void Asm_set_df_buff_positions_CFL(void *input,const char *name, unsigned short number, const unsigned short *positions, bool value);
void Asm_copy_df_buff_array_CFL(void *input, const char* from_bufF_name, const char* to_buff_name, unsigned short from_start, unsigned short to_start, unsigned short number);
void Asm_shift_df_buffer_CFL(void* input, const char* buffer_name, short shift_number, unsigned start, unsigned number, bool back_fill, bool fill_bit);
void Asm_print_df_buf_CFL(void *input, const char *buffer_name);
void Asm_store_s_bit_CFL(void* input, const char* buffer_name,unsigned short store_index, const char* s_expression);

void Asm_wait_df_tokens_s_expression_CFL(void* input, const char* buf_name, int time_out_ms, const char* one_shot_failure_fn, 
             void* user_data, bool terminate_flag,const char* s_expression_name);

void Asm_verify_df_tokens_s_expression_CFL(void* input, const char* buf_name, const char* one_shot_failure_fn, 
                                           void* user_data, bool terminate_flag,const char* s_expression_name);             

/*
** For Debug
*/

void Asm_dump_nodes_CFL(void* input);

void Verify_nodes_CFL(void* input);



/*
** Engine Functions
*/

Time_control_CFL_t* Get_time_control_CFL(void* handle);
void Queue_event_CFL(void* handle, Event_data_CFL_t* event_data);

/*
** Run time functions for building instructions
*/

// returns column index
short Find_column_index_CFL(void* handle, const char* column_name);


// column index refers to position of the column
void Enable_column_CFL(void* input, unsigned column_index);
void Disable_column_CFL(void* input, unsigned column_index);
void Reset_column_CFL(void* input, unsigned column_index);
void Disable_all_columns_CFL(void* input);
bool Column_State_CFL(void* input, unsigned column_index);
bool Join_columns_CFL(void* input, unsigned short column_number, unsigned short* column_indexes);




// used with Try opcode
bool Get_column_index_return_code_CFL(void* input, unsigned index);

// these instructions apply to current active column
void Set_current_column_return_code_CFL(void* input, bool state);
bool Get_current_column_return_code_CFL(void* input);

unsigned Get_current_column_index_CFL(void* input);
unsigned Get_current_column_element_index_CFL(void* input);
void Set_local_event_current_column_CFL(void* input, Event_data_CFL_t* data);
Event_data_CFL_t* Get_current_column_local_event_CFL(void* input);


/*
**
*/

void Set_local_event_CFL(void* input, unsigned column_index, Event_data_CFL_t* data);
Event_data_CFL_t* Get_local_event_CFL(void* input, unsigned column_index);


void Clear_column_watch_dog_CFL(void* input, void* params, Event_data_CFL_t* event_data);
void Set_column_watch_dog_CFL(void* input, void* params, Event_data_CFL_t* event_data);

// for debug
void Print_column_links_CFL(void* input);
void Verify_column_links_CFL(void* input);

/*
**
**  Local Private heap functions
**
*/
void* Private_heap_malloc_CFL(void* input, unsigned size);
void Private_heap_free_CFL(void* input, void* ptr);
int Private_heap_largest_free_block_CFL(void* input);
void Dump_private_heap_blocks_CFL(void *input);

#include "CFL_column_state_machine.h"
// prevent recursive include files

void Send_named_event_CFL(void *input, unsigned index,Event_data_CFL_t *event_data);
Event_control_CFL_t *Get_named_event_queue_CFL(void *input, unsigned index);
Event_data_CFL_t *Get_named_event_CFL(void *input, unsigned index);
Event_data_CFL_t *Peak_named_event_CFL(void *input, unsigned index);
Event_data_CFL_t *Pop_named_event_CFL(void *input, unsigned index);
#include "CFL_named_event_queue_manager.h"
#include "CFL_state_machine.h"

#ifdef __cplusplus
}
#endif

#endif