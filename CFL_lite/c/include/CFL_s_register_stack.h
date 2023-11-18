#ifndef __CFL_S_REGISTER_STACK_H__
#define __CFL_S_REGISTER_STACK_H__
#include <stdint.h> 
#include <stdbool.h>
#include "CFL_s_register_engine.h"

typedef union REGISTER_STREAM_CFL_t {
   int16_t   value;
   uint16_t  buffer_position;
   uint16_t   operator_value;
   uint16_t   end;
}REGISTER_STREAM_CFL_t;


typedef struct s_register_operator_type_CFL_t{
  uint8_t operator_type;  // value or operator
  REGISTER_STREAM_CFL_t operator_value; // index of operator or value
  uint8_t parameter_stack_start; // index of operator or value
}s_register_operator_type_CFL_t;

typedef struct s_register_parameter_type_CFL_t{
   uint8_t  parameter_type;
   REGISTER_STREAM_CFL_t parameter_value;
}s_register_parameter_type_CFL_t;

typedef struct register_s_stack_control_CFL_t{
    int16_t s_op_stack_size;
    uint16_t s_op_stack_top;
    s_register_operator_type_CFL_t *s_op_stack;
    int16_t s_p_stack_size;
    uint16_t s_p_stack_top;
    s_register_parameter_type_CFL_t *s_p_stack;
}register_s_stack_control_CFL_t;

register_s_stack_control_CFL_t *register_initialize_s_stack_CFL(const void *input,uint16_t p_stack_size,uint16_t op_stack_size);

void register_free_s_stack_CFL(const void *input,register_s_stack_control_CFL_t*stack_control);
void register_push_parameter_stack_CFL(register_s_stack_control_CFL_t *stack_control, s_register_parameter_type_CFL_t *op);

s_register_parameter_type_CFL_t  *register_pop_parameter_stack_CFL(register_s_stack_control_CFL_t *stack_control);

s_register_parameter_type_CFL_t  *register_s_get_parameter_stack_CFL(register_s_stack_control_CFL_t *stack_control ,uint16_t stack_start);


void register_release_parameter_stack_CFL(register_s_stack_control_CFL_t*stack_control, unsigned number_of_parameters);


void register_push_op_stack_CFL(register_s_stack_control_CFL_t *stack_control, s_register_operator_type_CFL_t *op);

s_register_operator_type_CFL_t *register_pop_op_stack_CFL(register_s_stack_control_CFL_t *stack_control);

s_register_operator_type_CFL_t *register_peak_op_stack_CFL(register_s_stack_control_CFL_t *stack_control);
uint16_t register_op_stack_size_CFL(register_s_stack_control_CFL_t *stack_control);
uint16_t register_parameter_stack_size_CFL(register_s_stack_control_CFL_t *stack_control);



#endif




