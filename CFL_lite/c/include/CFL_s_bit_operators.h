#ifndef __CFL_S_BIT_OPERATORS_H__
#define __CFL_S_BIT_OPERATORS_H__

#include "CFL_inner_engine.h"
#include "CFL_s_bit_engine.h"
#include "CFL_s_bit_stack.h"


void process_operator_CFL(const void *input, s_bit_working_control_CFL_t *working_control, uint16_t op_value, uint16_t stack_start);

#endif // __CFL_S_BIT_OPERATORS_H__