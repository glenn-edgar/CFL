#ifndef __run_time_code_CFL_H__
#define __run_time_code_CFL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
#include "CFL_inner_engine.h"



//----------Ref function header code ----


int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    

typedef struct While_control_RAM_CFL_t{
    int current_count;
} While_control_RAM_CFL_t;


typedef struct While_control_ROM_t
{
    int time_out_ms;
    bool terminate_flag;
    void* user_data;
    While_control_RAM_CFL_t *while_control_ram;
    One_shot_function_CFL_t user_time_out_fn;
    
} While_control_ROM_CFL_t;

int while_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data);


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);


int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data);



void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);


   void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data);

     
typedef struct While_time_control_ROM_t
{
   unsigned short time_delay;
   unsigned short *ending_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);
   

#ifdef __cplusplus
}
#endif

#endif
