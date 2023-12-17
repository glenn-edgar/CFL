#include "CFL_inner_engine.h"
#include "CFL_s_bit_stack.h"
#include "CFL_s_bit_engine.h"
#include "CFL_s_bit_operators.h"
#include "CFL_bit_map.h"

static bool xor_op(uint16_t number_of_parameters, Bitmap_CFL *bmp, s_parameter_type_CFL_t *parameters){
    bool result = false;
    for (uint16_t i = 0; i < number_of_parameters; i++)
    {
        if (parameters[i].parameter_type == S_BIT_VALUE_CFL)
        {
            if (parameters[i].parameter_value > 0)
            {
                result = !result;
            }
        }
        else
        {
            if (bitmap_get_bit_CFL(bmp, parameters[i].parameter_value) > 0)
            {
                result = !result;
            }
        }
    }
    return result;


}



static bool and_op(uint16_t number_of_parameters, Bitmap_CFL *bmp, s_parameter_type_CFL_t *parameters)
{
    for (uint16_t i = 0; i < number_of_parameters; i++)
    {
        if (parameters[i].parameter_type == S_BIT_VALUE_CFL)
        {
            if (parameters[i].parameter_value == 0)
            {
                return false;
            }
        }
        else
        {
            if (bitmap_get_bit_CFL(bmp, parameters[i].parameter_value) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

static bool or_op(uint16_t number_of_parameters, Bitmap_CFL *bmp, s_parameter_type_CFL_t *parameters)
{
    for (uint16_t i = 0; i < number_of_parameters; i++)
    {
        if (parameters[i].parameter_type == S_BIT_VALUE_CFL)
        {
            if (parameters[i].parameter_value > 0)
            {
                return true;
            }
        }
        else
        {
            if (bitmap_get_bit_CFL(bmp, parameters[i].parameter_value) > 0)
            {
                return true;
            }
        }
    }
    return false;
}

static bool nor_op(uint16_t number_of_parameters, Bitmap_CFL *bmp, s_parameter_type_CFL_t *parameters)
{
    for (uint16_t i = 0; i < number_of_parameters; i++)
    {
        if (parameters[i].parameter_type == S_BIT_VALUE_CFL)
        {
            if (parameters[i].parameter_value > 0)
            {
                return false;
            }
        }
        else
        {
            if (bitmap_get_bit_CFL(bmp, parameters[i].parameter_value) > 0)
            {
                return false;
            }
        }
    }
    return true;
}

static bool not_op(uint16_t number_of_parameters, Bitmap_CFL *bmp, s_parameter_type_CFL_t *parameters){
     return nor_op(number_of_parameters, bmp, parameters);
}


void process_operator_CFL(const void *input, s_bit_working_control_CFL_t *working_control, uint16_t op_value, uint16_t stack_start)
{
    (void)input;
    Bitmap_CFL *bit_map = working_control->bitmap;
    bool result = false;
    unsigned number_of_parameters = bit_parameter_stack_size_CFL(working_control->stack_control) - stack_start;
    if (number_of_parameters == 0)
    {
        ASSERT_PRINT_F("buffer ops: number of parameters is %d  \n", 0);
    }
    s_parameter_type_CFL_t *parameters = s_bit_get_parameter_stack_CFL(working_control->stack_control, stack_start);

    switch (op_value)
    {
    case S_BIT_AND_CFL:
        result = and_op(number_of_parameters, bit_map, parameters);

        break;
    case S_BIT_OR_CFL:
        result = or_op(number_of_parameters, bit_map, parameters);
        break;
    case S_BIT_NOR_CFL:
        result = nor_op(number_of_parameters, bit_map, parameters);
        break;

    case  S_BIT_XOR_CFL:
         result = xor_op(number_of_parameters, bit_map, parameters);
         break;
    case S_BIT_NOT_CFL:
        result = not_op(number_of_parameters, bit_map, parameters);
        break;
    default:
        ASSERT_PRINT_F("buffer ops: unknown operator type %d\n", op_value);
    }
    bit_release_parameter_stack_CFL(working_control->stack_control, number_of_parameters);
    s_parameter_type_CFL_t p_op = {S_BIT_VALUE_CFL, result};
    bit_push_parameter_stack_CFL(working_control->stack_control, p_op);
}
