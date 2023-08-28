#ifndef __run_time_code_CFL_H__
#define __run_time_code_CFL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
#include "CFL_inner_engine.h"



//----------Ref function header code ----



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


extern const int reset_buffer[1];
extern const int halt_buffer[1];
extern const int terminate_buffer[1];
extern const int terminate_engine_buffer[1];

int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    
typedef struct Join_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Join_column_CFL_t;

int join_columns_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct While_column_control_CFL_t
{
   bool  *state;
   unsigned *current_count;
   void* user_data;
   const unsigned short number_of_columns;
   const unsigned short* column_indexes;

   

} While_column_control_CFL_t;

int while_column_handler_CFL(const void *input, void *aux_fn,void *params, Event_data_CFL_t *event_data);


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);


int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);

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



void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);

typedef struct Disable_column_CFL_t {
    
    const unsigned short number_of_columns;
    const unsigned short *column_list;
}Disable_column_CFL_t;

void disable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



     
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

bool true_constant_handler(void *handle, void *params,
  Event_data_CFL_t *event_data); 
   

#ifdef __cplusplus
}
#endif

#endif
