#ifndef __CFL_s_float_expression_H__
#define __CFL_s_float_expression_H__


typedef float (*S_float_fn_type_CFL_t)(void *handle, void *user_data, int number, float* parameters);

typedef struct S_float_fn_record_CFL_t {
    char* name;
    S_float_fn_type_CFL_t fn;
} S_float_fn_record_CFL_t;

void *Parse_s_float_expression_CFL(void *handle, int fn_number, S_float_fn_record_CFL_t* s_record, const char* input);

float Evaluate_s_float_expression_CFL(void *handle, void *s_float_expression_handdle, void *user_data);



#endif



