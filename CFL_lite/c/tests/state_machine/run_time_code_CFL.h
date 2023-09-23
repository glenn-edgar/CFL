#ifndef __run_time_code_CFL_H__
#define __run_time_code_CFL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
#include "CFL_inner_engine.h"



//----------Ref function header code ----


typedef struct SM_debug_CFL_t{
    unsigned short sm_id;
    unsigned short state_id;
    const char *debug_message;
}SM_debug_CFL_t;

int  SM_debug_CFL(const void *input, void *fn_aux,void *params, Event_data_CFL_t *event_data);


typedef struct state_change_CFL_t{
    unsigned short sm_id;
    unsigned short new_state_id;
    unsigned short event_number;
    const unsigned short *event_indexes;
}state_change_CFL_t;

int state_change_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);



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



typedef struct sync_events_t{
  unsigned short sm_id;
  int sync_event_index;

}sync_events_t;

int sync_events_CFL(const void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data);


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);


int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct redirect_CFL_t{
  unsigned short sm_id;
  void *user_data;

}redirect_CFL_t;


int redirect_event_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);

int change_column_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct conditional_state_change_CFL{
    unsigned short sm_id;
    unsigned short new_state_id;
    void *user_data;
  }conditional_state_change_CFL_t;
  
  
  int conditional_state_change_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);
  
extern const int reset_buffer[1];
extern const int halt_buffer[1];
extern const int terminate_buffer[1];
extern const int terminate_engine_buffer[1];

int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    
  typedef struct change_sm_state_CFL_t {
    unsigned short sm_id;
    unsigned short new_state;
  } change_sm_state_CFL_t;
  
  void change_sm_state_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct enable_disable_sm_CFL_t
{
    unsigned short sm_number;
    const unsigned short *sm_indexes;
} enable_disable_sm_CFL_t;

void enable_disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


 typedef struct sm_event_CFL_t
{
    short sm_id;
    const Event_data_CFL_t *event_data;
} sm_event_CFL_t;

void send_event_to_sm(const void *input, void *params, Event_data_CFL_t *event_data);



typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);


void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);


typedef struct condition_state_change_t{
   unsigned short trigger_event;
   unsigned short trigger_count_limit;
   unsigned short *trigger_count;
}condition_state_change_t;

bool conditional_state_change(const void *input, void *params, Event_data_CFL_t *event_data);

bool true_constant_handler(void *handle, void *params,
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
