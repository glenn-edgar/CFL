#ifndef __CFL_s_int_expression_H__
#define __CFL_s_int_expression_H__


typedef int (*S_fn_type_CFL_t)(void *handle, void *user_data, int number, int* parameters);

typedef struct S_fn_record_CFL_t {
    char* name;
    S_fn_type_CFL_t fn;
} S_fn_record_CFL_t;

void *Parse_s_int_expression_CFL(void *handle, int fn_number, S_fn_record_CFL_t* s_record, const char* input);


int Evaluate_s_int_expression_CFL(void* handle, void* s_handle, void* user_data);


void Free_s_int_expression(void* handle, void* s_handle);
#endif



