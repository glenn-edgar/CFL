#ifndef __CFL_S_LOGICAL_OPERATIONS_H__
#define __CFL_S_LOGICAL_OPERATIONS_H__
#include "CFL_user_functions.h"
#ifdef __cplusplus
extern "C" {
#endif
#if 0
// logical operators are
static S_short_fn_record_CFL_t s_verify_fn_tbl[] = {
    {"&&", and_verify_fn}, // and
    {"||", or_verify_fn},  // or
    {"~", not_verify_fn},  // not
    {"&@", and_tbl_verify_fn}, // input buffer positions result and of buffer positions
    {"|@", or_tbl_verify_fn}, // input buffer positions result or of buffer positions
    {"~@", not_tbl_verify_fn},// input buffer positions result not of buffer positions

};
#endif
                      
CFL_s_log_op_handle_t* Compile_s_log_op_CFL(void* input, unsigned buffer_index, const char* s_expression);
bool Execute_s_log_op_CFL(void* input, CFL_s_log_op_handle_t* s_log_op_handle);
void Free_s_log_op_handle_CFL(void* input, CFL_s_log_op_handle_t* s_log_op_handle);

#ifdef __cplusplus
}
#endif

#endif