#ifndef __CFL_s_bit_stack__
#define __CFL_s_bit_stack__

#include <stdint.h> 
#include <stdbool.h>

typedef struct s_operator_type_CFL_t{
  uint8_t operator_type;  // value or operator
  uint16_t operator_value; // index of operator or value
  uint8_t parameter_stack_start; // index of operator or value
}s_operator_type_CFL_t;

typedef struct s_parameter_type_CFL_t{
   uint8_t  parameter_type;
   uint16_t parameter_value;
}s_parameter_type_CFL_t;

typedef struct s_stack_control_CFL_t{
    int16_t s_op_stack_size;
    uint16_t s_op_stack_top;
    s_operator_type_CFL_t *s_op_stack;
    int16_t s_p_stack_size;
    uint16_t s_p_stack_top;
    s_parameter_type_CFL_t *s_p_stack;
}s_stack_control_CFL_t;

s_stack_control_CFL_t *bit_initialize_s_stack_CFL(const void *input,uint16_t p_stack_size,uint16_t op_stack_size);

void bit_free_s_stack_CFL(const void *input,s_stack_control_CFL_t *stack_control);
void bit_push_parameter_stack_CFL(const void *input,s_stack_control_CFL_t *stack_control, s_parameter_type_CFL_t op);

s_parameter_type_CFL_t  bit_pop_parameter_stack_CFL(const void *input, s_stack_control_CFL_t *stack_control);

s_parameter_type_CFL_t  * s_bit_get_parameter_stack_CFL(const void *input,s_stack_control_CFL_t *stack_control ,uint16_t stack_start);
void bit_release_parameter_stack_CFL(const void *input,s_stack_control_CFL_t *stack_control, unsigned number_of_parameters);


void bit_push_op_stack_CFL(const void *input,s_stack_control_CFL_t *stack_control, s_operator_type_CFL_t op);

s_operator_type_CFL_t  bit_pop_op_stack_CFL(const void *input,s_stack_control_CFL_t *stack_control);

s_operator_type_CFL_t *bit_peak_op_stack_CFL(s_stack_control_CFL_t *stack_control);
uint16_t bit_op_stack_size_CFL(s_stack_control_CFL_t *stack_control);
uint16_t bit_parameter_stack_size_CFL(s_stack_control_CFL_t *stack_control);

#endif // __CFL_s_stack__