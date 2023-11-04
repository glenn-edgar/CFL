#ifndef __CFL_S_FLOAT_ENGINE_H__
#define __CFL_S_FLOAT_ENGINE_H__
 
 #include "CFL_float_map.h"
 #include "CFL_s_float_stack.h"


#include <stdint.h> 
#include <stdbool.h>


// operator types
#define S_FLOAT_VALUE_CFL 0
#define S_FLOAT_BUFFER_POSITION_CFL 1
#define S_FLOAT_OPERATOR_CFL 2
#define S_FLOAT_OPERATOR_END_CFL 3

// S_FLOAT_OPERATOR_CFL operators
#define S_FLOAT_MULTIPLY_CFL 0
#define S_FLOAT_DIVIDE_CFL 1
#define S_FLOAT_ADD_CFL 2
#define S_FLOAT_SUBTRACT_CFL 3
#define S_MODULUS_CFL 4
#define S_POWER_CFL 5
#define S_EXP_CFL 6
#define S_LN_CFL   7
#define S_10_x_CFL 8
#define S_LOG_CFL  9
#define S_SIN_CFL  10
#define S_COS_CFL  11
#define S_TAN_CFL  12
#define S_ASIN_CFL 13
#define S_ACOS_CFL 14
#define S_ATAN_CFL 15
#define S_SINH_CFL 16
#define S_COSH_CFL 17
#define S_TANH_CFL 18
#define S_ASINH_CFL 19
#define S_ACOSH_CFL 20
#define S_ATANH_CFL 21
#define S_SQRT_CFL 22
#define S_ABS_CFL  23
#define S_FLOOR_CFL 24
#define S_CEIL_CFL 25
#define S_ROUND_CFL 26
#define S_TRUNC_CFL 27
#define S_PI_CFL      28
#define S_DEGREE_CFL 29
#define S_RADIAN_CFL 30



typedef struct s_float_operator_CFL_t{
  uint8_t operator_type;  // value or operator
  FLOAT_STREAM_CFL_t data; // index of operator or value
}s_float_operator_CFL_t;

 typedef struct s_float_definition_CFL_t{
    uint8_t float_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_float_operator_CFL_t *operator_stream;
}s_float_definition_CFL_t;

typedef struct s_float_working_control_CFL_t{
    Floatmap_CFL_t            *floatmap;
    s_float_stack_control_CFL_t *stack_control;
    uint8_t               instruction_index;
    uint8_t               stream_length;
    const s_float_operator_CFL_t *operator_stream;
    float               result;
}s_float_working_control_CFL_t;

float process_s_float_buffer_CFL(const void *input, const s_float_definition_CFL_t *s_float_buffer_interface);






#endif // __CFL_S_FLOAT_ENGINE_H__