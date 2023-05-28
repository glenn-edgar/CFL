#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_s_short_expression.h"
#include "CFL_debug.h"
#include "CFL_data_flow_buffers.h"
#include "CFL_s_logical_operations.h"

static short and_verify_fn(void *handle, void *user_data, int number, short *parameters);
static short or_verify_fn(void *handle, void *user_data, int number, short *parameters);
static short not_verify_fn(void *handle, void *user_data, int number, short *parameters);
static short and_tbl_verify_fn(void *handle, void *user_data, int number, short *parameters);
static short or_tbl_verify_fn(void *handle, void *user_data, int number, short *parameters);
static short not_tbl_verify_fn(void *handle, void *user_data, int number, short *parameters);

static short and_exec_fn(void *handle, void *user_data, int number, short *parameters);
static short or_exec_fn(void *handle, void *user_data, int number, short *parameters);
static short not_exec_fn(void *handle, void *user_data, int number, short *parameters);
static short and_tbl_exec_fn(void *handle, void *user_data, int number, short *parameters);
static short or_tbl_exec_fn(void *handle, void *user_data, int number, short *parameters);
static short not_tbl_exec_fn(void *handle, void *user_data, int number, short *parameters);

static S_short_fn_record_CFL_t s_verify_fn_tbl[] = {
    {"&&", and_verify_fn},
    {"||", or_verify_fn},
    {"~", not_verify_fn},
    {"&@", and_tbl_verify_fn},
    {"|@", or_tbl_verify_fn},
    {"~@", not_tbl_verify_fn},

};

static S_short_fn_record_CFL_t s_exec_fn_tbl[] = {
    {"&&", and_exec_fn},
    {"||", or_exec_fn},
    {"~", not_exec_fn},
    {"&@", and_tbl_exec_fn},
    {"|@", or_tbl_exec_fn},
    {"~@", not_tbl_exec_fn},

};



#define S_VERIFICATION_FN_TABLE_SIZE (sizeof(s_verify_fn_tbl) / sizeof(S_short_fn_record_CFL_t))
#define S_EXECUTION_FN_TABLE_SIZE (sizeof(s_exec_fn_tbl) / sizeof(S_short_fn_record_CFL_t))

void Free_s_log_op_handle_CFL(void *input, CFL_s_log_op_handle_t *s_log_op_handle)
{
    Free_s_short_expression_CFL(input, s_log_op_handle->s_short_compiled_handle);
    Private_heap_free_CFL(input, s_log_op_handle);
}
                      
CFL_s_log_op_handle_t *Compile_s_log_op_CFL(void *input, unsigned buffer_index, const char *s_expression)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    CFL_s_log_op_handle_t *s_log_op_handle = (CFL_s_log_op_handle_t *)Private_heap_malloc_CFL(input, sizeof(CFL_s_log_op_handle_t));

    if (S_EXECUTION_FN_TABLE_SIZE != S_VERIFICATION_FN_TABLE_SIZE)
    {
        ASSERT_PRINT("S_EXECUTION_FN_TABLE_SIZE != S_VERIFICATION_FN_TABLE_SIZE", "");
    }

    Symbol_table_handle_CFL_t symbol_table_handle = Get_df_buf_symbol_table_CFL(input, buffer_index);

    s_log_op_handle->s_short_compiled_handle = Parse_s_short_expression_CFL(handle, S_VERIFICATION_FN_TABLE_SIZE, s_verify_fn_tbl, s_expression, symbol_table_handle);
    s_log_op_handle->user_data.buf_index = buffer_index;
    s_log_op_handle->user_data.buf_size = Get_df_buf_size_CFL(input, s_log_op_handle->user_data.buf_index);

    Evaluate_s_short_expression_CFL(input, s_log_op_handle->s_short_compiled_handle, &s_log_op_handle->user_data);
    Free_s_short_expression_CFL(input, s_log_op_handle->s_short_compiled_handle);
    // Free_s_short_expression(handle, s_log_op_handle->s_short_compiled_handle);
    s_log_op_handle->s_short_compiled_handle = Parse_s_short_expression_CFL(handle, S_EXECUTION_FN_TABLE_SIZE, s_exec_fn_tbl, s_expression, symbol_table_handle);
    s_log_op_handle->user_data.buf_index = buffer_index;
    s_log_op_handle->user_data.buf_size = Get_df_buf_size_CFL(input, s_log_op_handle->user_data.buf_index);

    return s_log_op_handle;
}

bool Execute_s_log_op_CFL(void *input, CFL_s_log_op_handle_t *s_log_op_handle)
{

    short result = Evaluate_s_short_expression_CFL(input, s_log_op_handle->s_short_compiled_handle, &s_log_op_handle->user_data);
    if (result == 0)
    {
        return false;
    }
    return true;
}

static short and_verify_fn(void *handle, void *user_data, int number, short *parameters)
{

    (void)handle;
    (void)user_data;

    for (int i = 0; i < number; i++)
    {
        if (parameters[i] < 0)
        {
            ASSERT_PRINT_INT("&& parameters[i] <0", parameters[i]);
        }
    }
    return 0;
}

static short or_verify_fn(void *handle, void *user_data, int number, short *parameters)
{
    (void)handle;
    (void)user_data;
    for (int i = 0; i < number; i++)
    {
        if (parameters[i] < 0)
        {
            ASSERT_PRINT_INT("|| parameters[i] <0", parameters[i]);
        }
    }
    return 0;
}

static short not_verify_fn(void *handle, void *user_data, int number, short *parameters)
{

    (void)handle;
    (void)user_data;
    for (int i = 0; i < number; i++)
    {
        if (parameters[i] < 0)
        {
            ASSERT_PRINT_INT("~ parameters[i] <0", parameters[i]);
        }
    }
    return 0;
}

static short and_tbl_verify_fn(void *handle, void *user_data, int number, short *parameters)
{
     (void)handle;

    CFL_s_log_userdata_t *s_log_userdata = (CFL_s_log_userdata_t *)user_data;
    for (int i = 0; i < number; i++)
    {
        if (parameters[i] < 0)
        {
            ASSERT_PRINT_INT("&@ parameters[i] <0", parameters[i]);
        }
        if (parameters[i] >= s_log_userdata->buf_size)
        {
            ASSERT_PRINT_INT("&@ parameters[i] >= s_log_userdata->buffer_size", parameters[i]);
        }
    }
    return 0;
}

static short or_tbl_verify_fn(void *handle, void *user_data, int number, short *parameters)
{
    (void)handle;
    CFL_s_log_userdata_t *s_log_userdata = (CFL_s_log_userdata_t *)user_data;
    for (int i = 0; i < number; i++)
    {
        if (parameters[i] < 0)
        {
            ASSERT_PRINT_INT("|@ parameters[i] <0", parameters[i]);
        }
        if (parameters[i] >= s_log_userdata->buf_size)
        {
            ASSERT_PRINT_INT("|@ parameters[i] >= s_log_userdata->buffer_size", parameters[i]);
        }
    }
    return 0;
}

static short not_tbl_verify_fn(void *handle, void *user_data, int number, short *parameters)
{
    (void)handle;
    CFL_s_log_userdata_t *s_log_userdata = (CFL_s_log_userdata_t *)user_data;
    for (int i = 0; i < number; i++)
    {
        if (parameters[i] < 0)
        {
            ASSERT_PRINT_INT("~@ parameters[i] <0", parameters[i]);
        }
        if (parameters[i] >= s_log_userdata->buf_size)
        {
            ASSERT_PRINT_INT("~@ parameters[i] >= s_log_userdata->buffer_size", parameters[i]);
        }
    }

    return 0;
}

static short and_exec_fn(void *handle, void *user_data, int number, short *parameters)
{
    (void)handle;
    (void)user_data;
    for (int i = 0; i < number; i++)
    {
        if (parameters[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

static short or_exec_fn(void *handle, void *user_data, int number, short *parameters)
{
    (void)handle;
    (void)user_data;
    for (int i = 0; i < number; i++)
    {

        if (parameters[i] == 1)
        {
            return 1;
        }
    }
    return 0;
}

static short not_exec_fn(void *handle, void *user_data, int number, short *parameters)
{
    (void)handle;
    (void)user_data;
    for (int i = 0; i < number; i++)
    {
        if (parameters[i] > 0)
        {
            return 0;
        }
    }
    return 1;
}

static short and_tbl_exec_fn(void *input, void *user_data, int number, short *parameters)
{
    (void)input;
    CFL_s_log_userdata_t *userdata = (CFL_s_log_userdata_t *)user_data;
    for (int i = 0; i < number; i++)
    {
        int value = Get_df_buf_value_CFL(input, userdata->buf_index, parameters[i]);

        if (value == 0)
        {
            return 0;
        }
    }
    return 1;
}

static short or_tbl_exec_fn(void *input, void *user_data, int number, short *parameters)
{
    (void)input;
    CFL_s_log_userdata_t *userdata = (CFL_s_log_userdata_t *)user_data;
    for (int i = 0; i < number; i++)
    {
        int value = Get_df_buf_value_CFL(input, userdata->buf_index, parameters[i]);
        if (value > 0)
        {
            return 1;
        }
    }
    return 0;
}

static short not_tbl_exec_fn(void *input, void *user_data, int number, short *parameters)
{
    (void)input;
    CFL_s_log_userdata_t *userdata = (CFL_s_log_userdata_t *)user_data;
    for (int i = 0; i < number; i++)
    {
        int value = Get_df_buf_value_CFL(input, userdata->buf_index, parameters[i]);

        if (value > 0)
        {
            return 0;
        }
    }
    return 1;
}