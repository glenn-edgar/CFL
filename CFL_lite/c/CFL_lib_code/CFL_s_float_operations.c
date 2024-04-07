#include "CFL_s_float_operations.h"
#include <math.h>
#define M_PI 3.14159265358979323846

float get_parameter_value_CFL(const void *input,Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameter)
{
    float result = 0;
    switch (parameter->parameter_type)
    {
    case S_FLOAT_VALUE_CFL:
        result = parameter->parameter_value.float_value;
        break;
    case S_FLOAT_BUFFER_POSITION_CFL:
        result = floatmap_get_value_CFL(input,bmp, parameter->parameter_value.buffer_position);
        break;
    default:
        ASSERT_PRINT_F(input,"s_float_engine: unknown parameter type %d\n", parameter->parameter_type);
    }
    return result;
}

static float float_add(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float result = get_parameter_value_CFL(input,bmp, &parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
        result = result + get_parameter_value_CFL(input,bmp, &parameters[i]);
    }
    return result;
}

static float float_mul(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float result = get_parameter_value_CFL(input,bmp, &parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
        result = result * get_parameter_value_CFL(input,bmp, &parameters[i]);
    }
    return result;
}

static float float_sub(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(input,bmp, &parameters[1]);
    return parameter_1 - parameter_2;
}

static float float_divide(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(input,bmp, &parameters[1]);
    return parameter_1 / parameter_2;
}

static float float_mod(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(input,bmp, &parameters[1]);
    return fmod(parameter_1, parameter_2);
}

static float float_pow(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(input,bmp, &parameters[1]);
    return pow(parameter_1, parameter_2);
}

static float float_exp(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return exp(parameter_1);
}
static float float_ln(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return log(parameter_1);
}

static float float_10_x(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return pow(10, parameter_1);
}

static float float_log(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return log10(parameter_1);
}

static float float_sin(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return sin(parameter_1);
}

static float float_cos(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return cos(parameter_1);
}

static float float_tan(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return tan(parameter_1);
}

static float float_asin(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return asin(parameter_1);
}

static float float_acos(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return acos(parameter_1);
}

static float float_atan(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return atan(parameter_1);
}

static float float_sinh(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return sinh(parameter_1);
}

static float float_cosh(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return cosh(parameter_1);
}

static float float_tanh(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return tanh(parameter_1);
}

static float float_asinh(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return asinh(parameter_1);
}

static float float_acosh(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return acosh(parameter_1);
}

static float float_atanh(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return atanh(parameter_1);
}

static float float_sqrt(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return sqrtf(parameter_1);
}

static float float_abs(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return fabs(parameter_1);
}

static float float_floor(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return floor(parameter_1);
}

static float float_ceil(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return ceil(parameter_1);
}

static float float_round(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return round(parameter_1);
}

static float float_trunc(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);
    return trunc(parameter_1);
}

static float float_degree(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return parameter_1 * 180.0 / M_PI;
}

static float float_radian(const void *input,uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(input,bmp, &parameters[0]);

    return M_PI * parameter_1 / 180.0;
}

void process_float_operator_CFL(const void *input, s_float_working_control_CFL_t *working_control, FLOAT_STREAM_CFL_t op_value, uint16_t stack_start)
{
    (void)input;
    Floatmap_CFL_t *float_map = working_control->floatmap;
    float result = 0;
    unsigned number_of_parameters = float_parameter_stack_size_CFL(working_control->stack_control) - stack_start;
    
    s_float_parameter_type_CFL_t *parameters = float_s_get_parameter_stack_CFL(input,working_control->stack_control, stack_start);
    switch (op_value.operator_value)
    {
    case S_FLOAT_MULTIPLY_CFL:
        result = float_mul(input,number_of_parameters, float_map, parameters);
        break;
    case S_FLOAT_DIVIDE_CFL:
        result = float_divide(input,number_of_parameters, float_map, parameters);
        break;
    case S_FLOAT_ADD_CFL:
        result = float_add(input,number_of_parameters, float_map, parameters);
        break;
    case S_FLOAT_SUBTRACT_CFL:
        result = float_sub(input,number_of_parameters, float_map, parameters);
        break;
    case S_MODULUS_CFL:
        result = float_mod(input,number_of_parameters, float_map, parameters);
        break;
    case S_POWER_CFL:
        result = float_pow(input,number_of_parameters, float_map, parameters);
        break;
    case S_EXP_CFL:
        result = float_exp(input,number_of_parameters, float_map, parameters);
        break;
    case S_LN_CFL:
        result = float_ln(input,number_of_parameters, float_map, parameters);
        break;
    case S_10_x_CFL:
        result = float_10_x(input,number_of_parameters, float_map, parameters);
        break;
    case S_LOG_CFL:
        result = float_log(input,number_of_parameters, float_map, parameters);
        break;
    case S_SIN_CFL:
        result = float_sin(input,number_of_parameters, float_map, parameters);
        break;
    case S_COS_CFL:
        result = float_cos(input,number_of_parameters, float_map, parameters);
        break;
    case S_TAN_CFL:
        result = float_tan(input,number_of_parameters, float_map, parameters);
        break;
    case S_ASIN_CFL:
        result = float_asin(input,number_of_parameters, float_map, parameters);
        break;
    case S_ACOS_CFL:
        result = float_acos(input,number_of_parameters, float_map, parameters);
        break;
    case S_ATAN_CFL:
        result = float_atan(input,number_of_parameters, float_map, parameters);
        break;
    case S_SINH_CFL:
        result = float_sinh(input,number_of_parameters, float_map, parameters);
      
        break;
    case S_COSH_CFL:
        result = float_cosh(input,number_of_parameters, float_map, parameters);
        break;
    case S_TANH_CFL:
        result = float_tanh(input,number_of_parameters, float_map, parameters);
        break;
    case S_ASINH_CFL:
        result = float_asinh(input,number_of_parameters, float_map, parameters);
      
        break;
    case S_ACOSH_CFL:
        result = float_acosh(input,number_of_parameters, float_map, parameters);
        break;
    case S_ATANH_CFL:
        result = float_atanh(input,number_of_parameters, float_map, parameters);
        break;
    case S_SQRT_CFL:
        result = float_sqrt(input,number_of_parameters, float_map, parameters);
        break;
    case S_ABS_CFL:
        result = float_abs(input,number_of_parameters, float_map, parameters);
        break;
    case S_FLOOR_CFL:
        result = float_floor(input,number_of_parameters, float_map, parameters);
        break;
    case S_CEIL_CFL:
        result = float_ceil(input,number_of_parameters, float_map, parameters);
        break;
    case S_ROUND_CFL:
        result = float_round(input,number_of_parameters, float_map, parameters);
        break;
    case S_TRUNC_CFL:
        result = float_trunc(input,number_of_parameters, float_map, parameters);
        break;
    case S_PI_CFL:
        result = M_PI;
        break;
    case S_DEGREE_CFL:
        result = float_degree(input,number_of_parameters, float_map, parameters);
        break;
    case S_RADIAN_CFL:
        result = float_radian(input,number_of_parameters, float_map, parameters);
        break;

    default:
        ASSERT_PRINT_F(input,"buffer ops: unknown operator type %d\n", op_value);
    }
   
    float_release_parameter_stack_CFL(input,working_control->stack_control, number_of_parameters);
    s_float_parameter_type_CFL_t p_op = {S_FLOAT_VALUE_CFL, {result}};
    float_push_parameter_stack_CFL(input,working_control->stack_control, &p_op);
}
