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



typedef struct Verify_control_ROM_CFL_t
{
   bool terminate_flag;
   void* user_data;
   One_shot_function_CFL_t user_termination_fn;
} Verify_control_ROM_CFL_t;



int verify_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data);


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

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);


void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);


void tod_verify_reset(const void *input,void *params,Event_data_CFL_t *eventdata);



#define OP_LT_CFL 0
#define OP_LE_CFL 1
#define OP_EQ_CFL 2
#define OP_GE_CFL 3
#define OP_GT_CFL 4


typedef struct Wait_tod_ROM_CFL_t
{
    unsigned short op_type;  //operation type
    short day_of_year;
    short month;
    short day;
    short dow;
    short hour;
    short minute;
    short second;
    bool terminate_flag;
    const void *user_data;

} Wait_tod_ROM_CFL_t;

bool test_tod_condition(const void *input, void *user_data, Event_data_CFL_t *event_data);


   

#ifdef __cplusplus
}
#endif

#endif
