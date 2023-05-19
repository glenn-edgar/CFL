#ifndef __CFL_s_short_expression_H__
#define __CFL_s_short_expression_H__
#ifdef __cplusplus
extern "C" {
#endif

typedef short (*S_short_fn_type_CFL_t)(void *handle, void *user_data, int number, short* parameters);

typedef struct S_short_fn_record_CFL_t {
    const char* name;
    S_short_fn_type_CFL_t fn;
} S_short_fn_record_CFL_t;


void *Parse_s_short_expression_CFL(void *handle, int fn_number, S_short_fn_record_CFL_t* s_record, const char* input,Symbol_table_handle_CFL_t symbol_table);

short Evaluate_s_short_expression_CFL(void *handle, void *s_short_expression_handle, void *user_data);



void Free_s_short_expression_CFL(void* handle, void* s_handle);

#ifdef __cplusplus
}
#endif

#endif



