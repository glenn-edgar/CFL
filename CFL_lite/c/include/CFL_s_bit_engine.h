#ifndef _CFL_S_BIT_ENGINE_H_
#define _CFL_S_BIT_ENGINE_H_
#include <stdint.h> 
#include <stdbool.h>
#include "CFL_inner_engine.h"

// operator types
#define S_BIT_VALUE_CFL 0
#define S_BIT_BUFFER_POSITION_CFL 1
#define S_BIT_OPERATOR_CFL  2
#define S_BIT_OPERATOR_END_CFL 4

// operators

#define S_BIT_AND_CFL 0
#define S_BIT_OR_CFL 1
#define S_BIT_NOR_CFL 2





typedef struct s_operator_CFL_t{
  uint8_t operator_type;  // value or operator
  uint16_t operator_index_value; // index of operator or value
}s_operator_CFL_t;

 typedef struct s_bit_definition_CFL_t{
    uint8_t bit_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_operator_CFL_t *operator_stream;
}s_bit_definition_CFL_t;

typedef struct s_bit_working_control_CFL_t{
    Bitmap_CFL            *bitmap;
    s_stack_control_CFL_t *stack_control;
    uint8_t               instruction_index;
    uint8_t               stream_length;
    const s_operator_CFL_t *operator_stream;
    bool                  result;
}s_bit_working_control_CFL_t;

bool process_s_bit_buffer_CFL(const void *input, const s_bit_definition_CFL_t *s_bit_buffer_interface);





#endif