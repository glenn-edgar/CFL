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

typedef struct display_event_CFL_t 
{
  unsigned short number_of_columns; 
  unsigned short *event_array;

}display_event_CFL_t;

int display_event_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);



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


typedef struct Residual_column_event_CFL_t
{
  const unsigned  column_id;
  const void *user_data;
}Residual_column_event_CFL_t;

int process_residual_column_event_queue(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);



int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);


typedef struct Conditional_send_event_CFL_t 
{
  unsigned short number_of_columns; 
  unsigned short *queue_id;
}Conditional_send_event_CFL_t;

int conditional_send_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);



typedef struct Front_queue_event_CFL_t
{
  unsigned         column_id;
  const Event_data_CFL_t *event_data;
}Front_queue_event_CFL_t;

void send_front_queue_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);


void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);
typedef struct Log_message_CFL_t{
   const char *entry_message;
   const bool  exit_flag;
   const char *exit_message;
}Log_message_CFL_t;

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);

  
  void residual_display(void *input, void *params,Event_data_CFL_t *event_data);

typedef struct Queue_event_CFL_t
{
  unsigned         event_queue_index;
  const Event_data_CFL_t *event_data;
}Queue_event_CFL_t;


void send_queue_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);




bool routing_2(void *input, void *params,Event_data_CFL_t *event_data);

     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);


bool routing_1(void *input, void *params,Event_data_CFL_t *event_data);
   

#ifdef __cplusplus
}
#endif

#endif
