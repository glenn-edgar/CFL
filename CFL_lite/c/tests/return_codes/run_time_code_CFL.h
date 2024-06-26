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

extern const int reset_buffer[1];
extern const int halt_buffer[1];
extern const int terminate_buffer[1];
extern const int terminate_engine_buffer[1];

int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    

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


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);


typedef struct Join_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Join_column_CFL_t;

int join_columns_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);





int terminate_reset_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);



int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


   void display_fibonaci(void *input, void *params,Event_data_CFL_t *event_data);

void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data);


typedef struct fibonacci_data_t
{
  unsigned number;
  unsigned index;
  unsigned fibonacci;
  unsigned first;
  unsigned second;
}fibonacci_data_t;

   void initialize_fibonaci(void *input, void *params,Event_data_CFL_t *event_data);

void send_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);



typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct Log_message_CFL_t{
   const char *entry_message;
   const bool  exit_flag;
   const char *exit_message;
}Log_message_CFL_t;

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);

typedef struct Column_data_CFL_t
{
  unsigned short number_of_columns; 
  unsigned short *column_id;
  void *user_data;
}Column_data_CFL_t;


void store_column_data(const void *input, void *params,Event_data_CFL_t *event_data);



   void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data);

     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);

bool calculate_fibonaci(void *input, void *params,Event_data_CFL_t *event_data);





typedef struct While_event_control_ROM_t
{
   unsigned   number_of_events;
   short     event_index;
   int       time_out_ms;
   bool      terminate_flag;
   const void* user_data;
   unsigned  *current_count;
  
} While_event_control_ROM_t;

bool wait_event_handler(const void *handle, void *params,
                               Event_data_CFL_t *event_data);
   

#ifdef __cplusplus
}
#endif

#endif
