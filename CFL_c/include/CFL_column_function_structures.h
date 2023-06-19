#ifndef __CFL_Function_Defs_H__
#define __CFL_Function_Defs_H__

typedef struct Try_control_CFL_t
{
   Try_column_CFL_t try_column_data;
   Try_function_CFL_t fn;

} Try_control_CFL_t;

typedef struct While_control_CFL_t
{
   int time_out_ms;
   bool terminate_flag;
   void* user_data;
   int current_count;
   One_shot_function_CFL_t user_time_out_fn;

} While_control_CFL_t;

typedef struct Verify_control_CFL_t
{
   bool terminate_flag;
   void* user_data;
   One_shot_function_CFL_t user_termination_fn;
} Verify_control_CFL_t;

typedef struct While_event_control_CFL_t
{

   unsigned short  number_of_events;
   short     event_index;
   unsigned short current_count;
   int       time_out_ms;
   bool      terminate_flag;
   void* user_data;
   One_shot_function_CFL_t user_termination_fn;

} While_event_control_CFL_t;

typedef struct While_time_control_CFL_t
{
   Elasped_ms_fn ms_time;
   unsigned time_delay;
   unsigned ending_time;
} While_time_control_CFL_t;

typedef struct Column_index_CFL_t
{
   bool init_flag;
   bool terminate_flag;
   unsigned column_number;
   unsigned short* column_indexes;

} Column_index_CFL_t;

typedef struct Column_watch_dog_CFL_t
{
   bool termination_flag;
   unsigned short column_index;
   unsigned trigger_count;
   unsigned current_count;
   One_shot_function_CFL_t trigger_function;

} Column_watch_dog_CFL_t;

typedef struct For_control_CFL_t
{
   bool state;
   bool terminate_flag;
   unsigned short number_of_columns;
   unsigned short* column_indexes;
   unsigned number_of_iterations;
   unsigned current_iterations;
   One_shot_function_CFL_t fn;
   void* user_data;
} For_control_CFL_t;

typedef struct While_column_control_CFL_t
{

   void* user_data;
   bool state;
   unsigned short number_of_columns;
   unsigned short* column_indexes;
   unsigned current_iterations;

} While_column_control_CFL_t;

typedef struct Valid_column_indexes_t
{
   unsigned short number_of_columns;
   unsigned short* column_indexes;
   void* user_data;
} Valid_column_indexes_t;

typedef struct Event_handler_fn_CFL_t {
   bool                    event_flag;
   bool                    activate_flag;
   void* user_data;
   unsigned short          event_number;
   short* event_indexes;
}Event_handler_fn_CFL_t;
typedef struct Send_named_event_t {
   unsigned short     queue_number;
   unsigned short* event_queue_indexes;
   Event_data_CFL_t   event_data;
   One_shot_function_CFL_t fn;
   void* user_data;
} Send_named_event_t;



typedef struct Column_events_CFL_t {
   unsigned short    number;
   unsigned short* column_indexes;
   Event_data_CFL_t* event_data;
} Column_events_CFL_t;

typedef struct Enable_join_CFL_t {
   bool                  time_wait_flag;
   unsigned short        number_of_columns;
   unsigned short* column_indexes;
} Enable_join_CFL_t;

typedef struct Immediate_events_function_CFL_t {
   unsigned short number_of_events;
   short* event_indexes;
   One_shot_function_CFL_t fn;
   void* user_data;
} Immediate_events_function_CFL_t;

typedef struct DF_operations_t {
   unsigned buf_index;
   unsigned true_number;
   const bool* true_positions;
   unsigned false_number;
   const bool* false_positions;
   void* user_data;
} DF_operations_t;

typedef struct CFL_s_log_userdata_t{
    unsigned short buf_index;
    unsigned short  buf_size;
} CFL_s_log_userdata_t;

typedef struct CFL_s_log_op_handle_t {
    void* s_short_compiled_handle;
    CFL_s_log_userdata_t user_data;
} CFL_s_log_op_handle_t;

typedef struct Wait_tod_CFL_t
{
    short day_of_year;
    short month;
    short day_of_week;
    short hour;
    short minute;
    short second;
    bool terminate_flag;
    void *user_data;
} Wait_tod_CFL_t;

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
typedef struct process_event_t_CFL
{
    unsigned short event_number;
    short *event_indexes;
    bool block_flag;
    short return_value;
    void *user_data;
} process_event_t_CFL;
#endif