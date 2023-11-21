#ifndef __run_time_code_CFL_H__
#define __run_time_code_CFL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
#include "CFL_inner_engine.h"



//----------Ref function header code ----


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



typedef struct Verify_control_ROM_CFL_t
{
   bool terminate_flag;
   void* user_data;
   One_shot_function_CFL_t user_termination_fn;
} Verify_control_ROM_CFL_t;



int verify_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data);


int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);


typedef struct if_then_else_reg_map_CFL_t{
    uint8_t source_buffer;
    uint16_t if_reg;
    One_shot_function_CFL_t then_one_shot;
    One_shot_function_CFL_t else_one_shot;
    const void* then_data;
    const void* else_data;
} if_then_else_reg_map_CFL_t;


void if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct register_map_copy_CFL_t{
    uint16_t source_buffer;
    uint16_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}register_map_copy_CFL_t;

void register_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



typedef struct clear_register_map_CFL_t{
    uint16_t buffer_number;
    int16_t state;
    uint16_t start;
    uint16_t  number;
}clear_register_map_CFL_t;

void clear_register_map_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

typedef struct reg_my_then_one_shot_CFL_t{
    uint16_t source_buffer;
    uint16_t reg_position;
    int16_t result;
}reg_my_then_one_shot_CFL_t;


void reg_my_then_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct set_register_buffer_CFL_t{
    uint16_t buffer_number;
    uint16_t start;
    uint16_t register_array_size;
    const int16_t *register_array;
}set_register_buffer_CFL_t;

void set_register_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



void reg_verify_trigger_fn(const void *input, void *params, Event_data_CFL_t *event_data);

void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);



void this_should_not_happen_fn(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct reg_my_else_one_shot_CFL_t{
    const char* message;
}reg_my_else_one_shot_CFL_t;


void reg_my_else_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data);



void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);


typedef struct dump_register_buffer_CFL_t{
    uint16_t buffer_number;
    uint16_t size;
}dump_register_buffer_CFL_t;

void dump_register_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

typedef struct s_reg_expression_CFL_t{

    uint8_t buffer_number;
    uint16_t offset;
    const  s_register_definition_CFL_t* definition;
} s_reg_expression_CFL_t;

void reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);




typedef struct wait_reg_map_s_expr_CFL_t{
    const s_register_definition_CFL_t* definition;
    const void* time_out_data;
}wait_reg_map_s_expr_CFL_t;

bool wait_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);



typedef struct verify_reg_map_s_expr_CFL_t {
    const s_register_definition_CFL_t* definition;
   const void* error_message;
}verify_reg_map_s_expr_CFL_t;

bool verify_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

   

#ifdef __cplusplus
}
#endif

#endif
