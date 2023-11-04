#ifndef __CFL_s_float_stack_h__
#define __CFL_s_float_stack_h__

#include <stdint.h> 
#include <stdbool.h>

typedef union FLOAT_STREAM_CFL_t {
   float float_value;
   unsigned buffer_position;
}FLOAT_STREAM_CFL_t;


typedef struct s_float_operator_type_CFL_t{
  uint8_t  operator_type;  // value or operator
  FLOAT_STREAM_CFL_t operator_value; // index of operator or value
  uint8_t  parameter_stack_start; // index of operator or value
}s_float_operator_type_CFL_t;

typedef struct s_float_parameter_type_CFL_t{
   uint8_t  parameter_type;
   FLOAT_STREAM_CFL_t parameter_value;
}s_float_parameter_type_CFL_t;



typedef struct s_float_stack_control_CFL_t{
    int16_t s_op_stack_size;
    uint16_t s_op_stack_top;
    s_float_operator_type_CFL_t *s_op_stack;
    int16_t s_p_stack_size;
    uint16_t s_p_stack_top;
    s_float_parameter_type_CFL_t *s_p_stack;
}s_float_stack_control_CFL_t;

s_float_stack_control_CFL_t *float_initialize_s_stack_CFL(const void *input,uint16_t p_stack_size,uint16_t op_stack_size);

void float_free_s_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control);
void float_push_parameter_stack_CFL(s_float_stack_control_CFL_t *stack_control, s_float_parameter_type_CFL_t op);

s_float_parameter_type_CFL_t  float_pop_parameter_stack_CFL(s_float_stack_control_CFL_t *stack_control);

s_float_parameter_type_CFL_t  * float_s_get_parameter_stack_CFL(s_float_stack_control_CFL_t *stack_control ,uint16_t stack_start);
void float_release_parameter_stack_CFL(s_float_stack_control_CFL_t *stack_control, unsigned number_of_parameters);


void float_push_op_stack_CFL(s_float_stack_control_CFL_t *stack_control, s_float_operator_type_CFL_t op);

s_float_operator_type_CFL_t  float_pop_op_stack_CFL(s_float_stack_control_CFL_t *stack_control);

s_float_operator_type_CFL_t *float_peak_op_stack_CFL(s_float_stack_control_CFL_t *stack_control);
uint16_t float_op_stack_size_CFL(s_float_stack_control_CFL_t *stack_control);
uint16_t float_parameter_stack_size_CFL(s_float_stack_control_CFL_t *stack_control);



#endif
