#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_element_storeage.h"
#include "CFL_s_logical_operations.h"
#include  "CFL_s_expr_buffers.h"



typedef struct S_logic_expr_buffer_CFL_t{
    unsigned max_number;
    unsigned number;    
    Hash_cell_control_CFL_t *names;
   CFL_s_log_op_handle_t** s_expr_buffer;
}S_logic_expr_buffer_CFL_t;
 
void Initialize_s_logical_expression_buffers_CFL(void* input, unsigned short number){

    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    S_logic_expr_buffer_CFL_t *s_logical_expr_buffer_CFL = (S_logic_expr_buffer_CFL_t*)Allocate_once_malloc_CFL(input, sizeof(S_logic_expr_buffer_CFL_t));


    s_logical_expr_buffer_CFL->max_number = number;
    s_logical_expr_buffer_CFL->number = 0;
    if(number == 0){
        s_logical_expr_buffer_CFL->s_expr_buffer = NULL;
        s_logical_expr_buffer_CFL->names = NULL;
        handle->s_logic_buffer = s_logical_expr_buffer_CFL;
        return;
    }
    s_logical_expr_buffer_CFL->names = contruct_hash_cell_control_CFL(input,number);
    
    s_logical_expr_buffer_CFL->s_expr_buffer = (CFL_s_log_op_handle_t**)Allocate_once_malloc_CFL(input, sizeof(CFL_s_log_op_handle_t*)*number);
    handle->s_logic_buffer = s_logical_expr_buffer_CFL;



}
    
void Store_s_logical_expression_CFL(void* input,const char *buffer_name, const char *s_expr_name, const char* s_expression){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    
    unsigned short buffer_index = Get_df_buf_index_CFL(input,buffer_name);

    S_logic_expr_buffer_CFL_t *s_logical_expr_buffer = (S_logic_expr_buffer_CFL_t*)handle->s_logic_buffer;
    
    if(s_logical_expr_buffer->number >= s_logical_expr_buffer->max_number){
        ASSERT_PRINT_F("Error: s_logical_expr_buffer_CFL is full max number %d \n", s_logical_expr_buffer->max_number);
    }
    
    unsigned short index = Store_Name_CFL(s_logical_expr_buffer->names, s_expr_name); 
    
    s_logical_expr_buffer->number = s_logical_expr_buffer->number + 1;

    CFL_s_log_op_handle_t* s_log_op_handle = Compile_s_log_op_CFL(input,buffer_index, s_expression);
    
    s_logical_expr_buffer->s_expr_buffer[index] = s_log_op_handle;
    
}

CFL_s_log_op_handle_t* Get_s_logical_expression_index_CFL(void* input, const char* s_expr_name){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    
    S_logic_expr_buffer_CFL_t *s_logical_expr_buffer = (S_logic_expr_buffer_CFL_t*)handle->s_logic_buffer;
    
    short index = Find_Name_CFL(s_logical_expr_buffer->names, s_expr_name);
    
    if(index == -1){
        ASSERT_PRINT_F("Error: s_logical_expr_buffer_CFL %s not found \n", s_expr_name);
    }
    
    return s_logical_expr_buffer->s_expr_buffer[index];
    
}   