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


typedef struct rpc_server_event_clean_up_CFL_t
{
  void *user_data;
  bool terminate_flag;
} rpc_server_event_clean_up_CFL_t;

int rpc_server_event_clean_up_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);



int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


typedef struct rpc_server_event_processor_CFL_t
{
  void *user_data;
  unsigned short rpc_request_number;
  const unsigned short *rpc_request_list;
} rpc_server_event_processor_CFL_t;


int rpc_server_event_processor_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);


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


typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);




int rpc_clean_up_one_shot(const void *input, void *params, Event_data_CFL_t *event_data);


     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);
 void    service_handler_2(const void *input,void *user_data, rpc_rom_message_CFL_t *data);
    void   service_handler_1(const void *input,void *params, rpc_rom_message_CFL_t *data);
   

#ifdef __cplusplus
}
#endif

#endif
