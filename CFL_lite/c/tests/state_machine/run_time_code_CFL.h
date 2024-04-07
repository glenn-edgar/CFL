#ifndef __run_time_code_CFL_H__
#define __run_time_code_CFL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
#include "CFL_inner_engine.h"
#include "CFL_useful_utilities.h"



//----------Ref function header code ----

#include "CFL_state_machine.h"
#include "CFL_column_element_state_utilities.h"
#include "CFL_state_machine.h"
typedef struct Case_change_test_data_t
{
    const char *debug_message;
    
} Case_change_test_data_t;
    
int case_change_test(const void *input, void* params, Event_data_CFL_t* event_data, bool *continue_flag);


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


extern const int reset_buffer[1];
extern const int halt_buffer[1];
extern const int terminate_buffer[1];
extern const int terminate_engine_buffer[1];

int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    
int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct SM_case_change_CFL_t{
    const uint16_t sm_id;
    const void *user_data;
}SM_case_change_CFL_t;

int SM_case_change_CFL(const void *input, void *fn_aux,void *params, Event_data_CFL_t *event_data);


typedef struct state_change_CFL_t{
    unsigned short sm_id;
    unsigned short new_state_id;
    unsigned short event_number;
    const unsigned short *event_indexes;
}state_change_CFL_t;

int state_change_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);



typedef struct sm_sync_events_t{
  unsigned short sm_queue_id;
  int sync_event_index;

}sm_sync_events_t;

int sm_sync_events_CFL(const void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data);


typedef struct SM_debug_CFL_t{
    const uint16_t sm_id;
    const uint16_t state_id;
    const char *debug_message;
}SM_debug_CFL_t;

int  SM_debug_CFL(const void *input, void *fn_aux,void *params, Event_data_CFL_t *event_data);

typedef struct SM_feed_state_CFL_t
{
   uint16_t sm_id;
   const char *user_data;

  
}  SM_feed_state_CFL_t;   

int sm_feed_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

typedef struct Log_message_CFL_t{
   const char *entry_message;
   const bool  exit_flag;
   const char *exit_message;
}Log_message_CFL_t;

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);


typedef struct ASM_change_state_machine_CFL_t
{
    uint32_t sm_index;
    uint32_t state_index;
} ASM_change_state_machine_CFL_t;


void Asm_change_state_machine_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct enable_sm_CFL_t
{
    uint16_t sm_number;
    const uint16_t *sm_indexes;
} enable_sm_CFL_t;

void enable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



typedef struct SM_log_CFL_t
{
  const uint16_t sm_id;
  const uint16_t state_id;
  const char *entry_message;
  const char *exit_message;
  
} SM_log_CFL_t;

void SM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event);


 typedef struct sm_event_CFL_t
{
    short sm_id;
    const Event_data_CFL_t *event_data;
} sm_event_CFL_t;

void send_event_to_sm(const void *input, void *params, Event_data_CFL_t *event_data);

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);

typedef struct enable_disable_sm_CFL_t
{
    unsigned short sm_number;
    const unsigned short *sm_indexes;
} enable_disable_sm_CFL_t;

void enable_disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct disable_sm_CFL_t
{
    uint16_t sm_number;
    const uint16_t *sm_indexes;
} disable_sm_CFL_t;

void disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct Feed_events_test_data_a_t
{
    const char *debug_message;

} Feed_events_test_data_a_t;


bool feed_events_test_a(const void *input, void* params, Event_data_CFL_t* event_data);

     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);

typedef struct Feed_events_test_data_t
{
    const char *debug_message;

} Feed_events_test_data_t;


bool feed_events_test(const void *input, void* params, Event_data_CFL_t* event_data);
   

#ifdef __cplusplus
}
#endif

#endif
