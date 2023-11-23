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


int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);


extern const int reset_buffer[1];
extern const int halt_buffer[1];
extern const int terminate_buffer[1];
extern const int terminate_engine_buffer[1];

int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    
typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



typedef struct clear_float_map_CFL_t{
    uint16_t buffer_number;
    float state;
    uint16_t start;
    uint16_t  number;
}clear_float_map_CFL_t;

void clear_float_map_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

typedef struct dump_float_buffer_CFL_t{
    uint16_t buffer_number;
    uint16_t size;
}dump_float_buffer_CFL_t;

void dump_float_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct float_map_copy_CFL_t{
    uint16_t source_buffer;
    uint16_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}float_map_copy_CFL_t;

void float_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


typedef struct set_float_buffer_CFL_t{
    uint16_t buffer_number;
    uint16_t start;
    uint16_t float_array_size;
    const float *float_array;
}set_float_buffer_CFL_t;

void set_float_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);
typedef struct s_float_expression_CFL_t{

    uint8_t buffer_number;
    uint16_t offset;
    const  s_float_definition_CFL_t* definition;
} s_float_expression_CFL_t;

void float_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);



void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);

   

#ifdef __cplusplus
}
#endif

#endif
