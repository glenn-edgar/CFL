#ifndef __run_time_code_CFL_H__
#define __run_time_code_CFL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
#include "CFL_inner_engine.h"
#include "CFL_useful_utilities.h"



//----------Ref function header code ----

#include "CFL_column_element_state_utilities.h"

int case_test_fn(const void *input, void* params, Event_data_CFL_t* event_data, bool *event_continue_flag);

extern const int reset_buffer[1];
extern const int halt_buffer[1];
extern const int terminate_buffer[1];
extern const int terminate_engine_buffer[1];

int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    typedef struct Supervisor_data_CFL_t
{
  const unsigned short reset_type;
  const unsigned short column_number;
  const unsigned short* column_list;
  bool *restart_mask;
  unsigned *reset_count;
  unsigned *secondary_reset_count;
  const bool terminate_flag;
  const void* user_data;

} Supervisor_data_CFL_t;


int supervisor_control_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data);


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);


int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);

typedef struct Chain_columns_case_CFL_t
{
   uint16_t number_of_columns;
   const uint16_t *column_list;
   const void *user_data;
  
} Chain_columns_case_CFL_t;   

int chain_columns_case_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct display_event_CFL_t 
{
  unsigned short number_of_columns; 
  unsigned short *event_array;

}display_event_CFL_t;

int display_event_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);


typedef struct While_column_control_CFL_t
{
   bool  *state;
   unsigned *current_count;
   void* user_data;
   const unsigned short number_of_columns;
   const unsigned short* column_indexes;

   

} While_column_control_CFL_t;

int while_column_handler_CFL(const void *input, void *aux_fn,void *params, Event_data_CFL_t *event_data);


typedef struct Join_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Join_column_CFL_t;

int join_columns_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct Chain_columns_sequence_CFL_t
{
   uint16_t number_of_columns;
   const uint16_t *column_list;
   uint16_t number_of_events;
   const int16_t *event_list;

} Chain_columns_sequence_CFL_t;   

int chain_columns_sequence_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);



typedef struct While_control_RAM_CFL_t{
    int current_count;
} While_control_RAM_CFL_t;


typedef struct While_control_ROM_t
{
    const int time_out_ms;
    const bool terminate_flag;
    const void* user_data;
    While_control_RAM_CFL_t *while_control_ram;
    One_shot_function_CFL_t user_time_out_fn;
    
} While_control_ROM_CFL_t;

int while_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data);

typedef struct Try_columns_CFL_t
{
  unsigned short column_number;
  const unsigned short *column_list;
  bool invert_flag;
  unsigned short *column_index;
  bool *state;
} Try_columns_CFL_t;

int try_columns_CFL(const void *input,void *fn_aux, void *params, Event_data_CFL_t *event_data );
#include "CFL_useful_utilities.h"
int sequence_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data );
    
#include "CFL_useful_utilities.h"    
typedef struct Assert_column_CFL_t
{

    sequence_columns_CFL_t sequence_columns;
    void *user_data;
    bool termination_flag;
    bool *result;
} Assert_column_CFL_t;


int assert_column_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data );

typedef struct If_then_else_CFL_t {
    const bool    terminate_flag;
    const bool    join_flag;
    const unsigned short number_of_then_columns;
    const unsigned short *then_column_list;
    const unsigned short number_of_else_columns;
    const unsigned short *else_column_list;
    void *user_data;
} If_then_else_CFL_t;

int if_then_else_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct Set_return_code_CFL_t
{
    unsigned short column_number;
    const unsigned short *column_list;
    bool bool_flag;
} Set_return_code_CFL_t;
            
void set_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data);
            

typedef struct Display_return_code_CFL_t
{
    unsigned short column_number;
    const unsigned short *column_list;
} Display_return_code_CFL_t;
            
void display_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data);
            
void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);

typedef struct Queue_event_CFL_t
{
  unsigned         event_queue_index;
  const Event_data_CFL_t *event_data;
}Queue_event_CFL_t;


void send_queue_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);



typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



typedef struct Disable_column_CFL_t {
    
    const unsigned short number_of_columns;
    const unsigned short *column_list;
}Disable_column_CFL_t;

void disable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct Log_message_CFL_t{
   const char *entry_message;
   const bool  exit_flag;
   const char *exit_message;
}Log_message_CFL_t;

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);

 
bool fn_column_control(const void* input, void* params, Event_data_CFL_t* event_data);


bool bool_true_function(const void *input,void *params,Event_data_CFL_t *event_data);

bool true_constant_handler(void *handle, void *params,
  Event_data_CFL_t *event_data); 
typedef struct Assert_flag_CFL_t
{
    bool flag_value;
    unsigned short column_index;
    Bool_function_CFL_t bool_fn;
    void *user_data;
} Assert_flag_CFL_t;


bool assert_flag_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


bool bool_false_function(const void *input,void *params,Event_data_CFL_t *event_data);

 
bool one_for_one_fn(const void* input, void* params, Event_data_CFL_t* event_data);


     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);
bool false_constant_handler(void *handle, void *params,
  Event_data_CFL_t *event_data);

bool while_column_test(void* input, void* params, Event_data_CFL_t* event_data);

   

#ifdef __cplusplus
}
#endif

#endif
