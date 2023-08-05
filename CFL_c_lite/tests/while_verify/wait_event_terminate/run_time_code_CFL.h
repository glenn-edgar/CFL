#ifndef __run_time_code_CFL_H__
#define __run_time_code_CFL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
#include "CFL_inner_engine.h"



//----------Ref function header code ----


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);



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


int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);


void send_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);


void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);

void wait_event_terminate(const void *input, void *params,Event_data_CFL_t *event_data);







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

     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);
   

#ifdef __cplusplus
}
#endif

#endif
