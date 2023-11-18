#ifndef __CFL_S_REGISTER_ENGINE_H__
#define __CFL_S_REGISTER_ENGINE_H__

#include <stdint.h> 
#include <stdbool.h>
#include "CFL_register_map.h"
#include "CFL_s_register_stack.h"



// operator types
#define S_REGISTER_VALUE_CFL 0
#define S_REGISTER_BUFFER_POSITION_CFL 1
#define S_REGISTER_OPERATOR_CFL 2
#define S_REGISTER_OPERATOR_END_CFL 3


// S_REGISTER_OPERATOR_CFL operators
#define S_REGISTER_MULTIPLY_CFL 0
#define S_REGISTER_DIVIDE_CFL 1
#define S_REGISTER_ADD_CFL 2
#define S_REGISTER_SUBTRACT_CFL 3
#define S_REGISTER_MODULUS_CFL 4
#define S_REGISTER_SHIFT_CFL  5

#define S_REGISTER_BITWISE_AND_CFL 6
#define S_REGISTER_BITWISE_OR_CFL 7
#define S_REGISTER_BITWISE_XOR_CFL 8
#define S_REGISTER_BITWISE_NOR_CFL 9

#define S_REGISTER_LOGICAL_AND_CFL 10
#define S_REGISTER_LOGICAL_OR_CFL 11

#define S_REGISTER_GT_CFL   14 
#define  S_REGISTER_GE_CFL   15  
#define S_REGISTER_EQ_CFL   16  
#define S_REGISTER_LE_CFL  17  
#define S_REGISTER_LT_CFL  18  






typedef struct s_register_operator_CFL_t{
  uint8_t operator_type;  // value or operator
  REGISTER_STREAM_CFL_t data; // index of operator or value
}s_register_operator_CFL_t;

 typedef struct s_register_definition_CFL_t{
    uint8_t bit_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_register_operator_CFL_t *operator_stream;
}s_register_definition_CFL_t;

typedef struct s_register_working_control_CFL_t{
    Registermap_CFL_t              *regmap;
    register_s_stack_control_CFL_t *stack_control;
    uint8_t                         instruction_index;
    uint8_t                         stream_length;
    const s_register_operator_CFL_t *operator_stream;
    float                            result;
}s_register_working_control_CFL_t;

int16_t process_s_register_buffer_CFL(const void *input, const  s_register_definition_CFL_t*s_register_buffer_interface);





#endif // __CFL_S_REGISTER_ENGINE_H__