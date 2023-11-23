#include "CFL_s_float_operations.h"
#include <math.h>
#define M_PI 3.14159265358979323846

float get_parameter_value_CFL(Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameter)
{
    float result = 0;
    switch (parameter->parameter_type)
    {
    case S_FLOAT_VALUE_CFL:
        result = parameter->parameter_value.float_value;
        break;
    case S_FLOAT_BUFFER_POSITION_CFL:
        result = floatmap_get_value_CFL(bmp, parameter->parameter_value.buffer_position);
        break;
    default:
        ASSERT_PRINT_F("s_float_engine: unknown parameter type %d\n", parameter->parameter_type);
    }
    return result;
}

static float float_add(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float result = get_parameter_value_CFL(bmp, &parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
        result = result + get_parameter_value_CFL(bmp, &parameters[i]);
    }
    return result;
}

static float float_mul(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float result = get_parameter_value_CFL(bmp, &parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
        result = result * get_parameter_value_CFL(bmp, &parameters[i]);
    }
    return result;
}

static float float_sub(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(bmp, &parameters[1]);
    return parameter_1 - parameter_2;
}

static float float_divide(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(bmp, &parameters[1]);
    return parameter_1 / parameter_2;
}

static float float_mod(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(bmp, &parameters[1]);
    return fmod(parameter_1, parameter_2);
}

static float float_pow(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;
    float parameter_2;
    if (number_of_parameters != 2)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    parameter_2 = get_parameter_value_CFL(bmp, &parameters[1]);
    return pow(parameter_1, parameter_2);
}

static float float_exp(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return exp(parameter_1);
}
static float float_ln(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return log(parameter_1);
}

static float float_10_x(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return pow(10, parameter_1);
}

static float float_log(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return log10(parameter_1);
}

static float float_sin(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return sin(parameter_1);
}

static float float_cos(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return cos(parameter_1);
}

static float float_tan(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return tan(parameter_1);
}

static float float_asin(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return asin(parameter_1);
}

static float float_acos(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return acos(parameter_1);
}

static float float_atan(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return atan(parameter_1);
}

static float float_sinh(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return sinh(parameter_1);
}

static float float_cosh(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return cosh(parameter_1);
}

static float float_tanh(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return tanh(parameter_1);
}

static float float_asinh(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return asinh(parameter_1);
}

static float float_acosh(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return acosh(parameter_1);
}

static float float_atanh(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return atanh(parameter_1);
}

static float float_sqrt(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return sqrtf(parameter_1);
}

static float float_abs(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return fabs(parameter_1);
}

static float float_floor(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return floor(parameter_1);
}

static float float_ceil(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return ceil(parameter_1);
}

static float float_round(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return round(parameter_1);
}

static float float_trunc(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);
    return trunc(parameter_1);
}

static float float_degree(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return parameter_1 * 180.0 / M_PI;
}

static float float_radian(uint16_t number_of_parameters, Floatmap_CFL_t *bmp, s_float_parameter_type_CFL_t *parameters)
{
    float parameter_1;

    if (number_of_parameters != 1)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1 = get_parameter_value_CFL(bmp, &parameters[0]);

    return M_PI * parameter_1 / 180.0;
}

void process_float_operator_CFL(const void *input, s_float_working_control_CFL_t *working_control, FLOAT_STREAM_CFL_t op_value, uint16_t stack_start)
{
    (void)input;
    Floatmap_CFL_t *float_map = working_control->floatmap;
    float result = 0;
    unsigned number_of_parameters = float_parameter_stack_size_CFL(working_control->stack_control) - stack_start;
    
    s_float_parameter_type_CFL_t *parameters = float_s_get_parameter_stack_CFL(working_control->stack_control, stack_start);
    switch (op_value.operator_value)
    {
    case S_FLOAT_MULTIPLY_CFL:
        result = float_mul(number_of_parameters, float_map, parameters);
        break;
    case S_FLOAT_DIVIDE_CFL:
        result = float_divide(number_of_parameters, float_map, parameters);
        break;
    case S_FLOAT_ADD_CFL:
        result = float_add(number_of_parameters, float_map, parameters);
        break;
    case S_FLOAT_SUBTRACT_CFL:
        result = float_sub(number_of_parameters, float_map, parameters);
        break;
    case S_MODULUS_CFL:
        result = float_mod(number_of_parameters, float_map, parameters);
        break;
    case S_POWER_CFL:
        result = float_pow(number_of_parameters, float_map, parameters);
        break;
    case S_EXP_CFL:
        result = float_exp(number_of_parameters, float_map, parameters);
        break;
    case S_LN_CFL:
        result = float_ln(number_of_parameters, float_map, parameters);
        break;
    case S_10_x_CFL:
        result = float_10_x(number_of_parameters, float_map, parameters);
        break;
    case S_LOG_CFL:
        result = float_log(number_of_parameters, float_map, parameters);
        break;
    case S_SIN_CFL:
        result = float_sin(number_of_parameters, float_map, parameters);
        break;
    case S_COS_CFL:
        result = float_cos(number_of_parameters, float_map, parameters);
        break;
    case S_TAN_CFL:
        result = float_tan(number_of_parameters, float_map, parameters);
        break;
    case S_ASIN_CFL:
        result = float_asin(number_of_parameters, float_map, parameters);
        break;
    case S_ACOS_CFL:
        result = float_acos(number_of_parameters, float_map, parameters);
        break;
    case S_ATAN_CFL:
        result = float_atan(number_of_parameters, float_map, parameters);
        break;
    case S_SINH_CFL:
        result = float_sinh(number_of_parameters, float_map, parameters);
      
        break;
    case S_COSH_CFL:
        result = float_cosh(number_of_parameters, float_map, parameters);
        break;
    case S_TANH_CFL:
        result = float_tanh(number_of_parameters, float_map, parameters);
        break;
    case S_ASINH_CFL:
        result = float_asinh(number_of_parameters, float_map, parameters);
      
        break;
    case S_ACOSH_CFL:
        result = float_acosh(number_of_parameters, float_map, parameters);
        break;
    case S_ATANH_CFL:
        result = float_atanh(number_of_parameters, float_map, parameters);
        break;
    case S_SQRT_CFL:
        result = float_sqrt(number_of_parameters, float_map, parameters);
        break;
    case S_ABS_CFL:
        result = float_abs(number_of_parameters, float_map, parameters);
        break;
    case S_FLOOR_CFL:
        result = float_floor(number_of_parameters, float_map, parameters);
        break;
    case S_CEIL_CFL:
        result = float_ceil(number_of_parameters, float_map, parameters);
        break;
    case S_ROUND_CFL:
        result = float_round(number_of_parameters, float_map, parameters);
        break;
    case S_TRUNC_CFL:
        result = float_trunc(number_of_parameters, float_map, parameters);
        break;
    case S_PI_CFL:
        result = M_PI;
        break;
    case S_DEGREE_CFL:
        result = float_degree(number_of_parameters, float_map, parameters);
        break;
    case S_RADIAN_CFL:
        result = float_radian(number_of_parameters, float_map, parameters);
        break;

    default:
        ASSERT_PRINT_F("buffer ops: unknown operator type %d\n", op_value);
    }
   
    float_release_parameter_stack_CFL(working_control->stack_control, number_of_parameters);
    s_float_parameter_type_CFL_t p_op = {S_FLOAT_VALUE_CFL, {result}};
    float_push_parameter_stack_CFL(working_control->stack_control, &p_op);
}
