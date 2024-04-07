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

int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);

#include "CFL_useful_utilities.h"
int sequence_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data );
    


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

    
int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct Change_state_structure_CFL_t
{

  const uint32_t state_hash;
  
} Change_state_structure_CFL_t;

int change_state_function_CFL(const void *input, void *aux, void *params, Event_data_CFL_t *event);


typedef struct MCESM_log_CFL_t
{
  const char *entry_message;
  const char *exit_message;
  
} MCESM_log_CFL_t;

void MCESM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event);

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);

typedef struct Sm_enable_CFL_t
{
  const uint32_t sm_hash;
  
} Sm_enable_CFL_t;

void Enable_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event);


typedef struct Log_message_CFL_t{
   const char *entry_message;
   const bool  exit_flag;
   const char *exit_message;
}Log_message_CFL_t;

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);



void Initialize_sm_structure_CFL(const void *input, void *params, Event_data_CFL_t *event_data);




void Disable_current_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event);



     
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
