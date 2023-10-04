#include "CFL_inner_engine.h"
#include "CFL_s_bit_stack.h"
#include "CFL_s_bit_engine.h"
#include "CFL_s_bit_operators.h"

// static get_buffer_value_CFL(const void *input,s_bit_working_control_CFL_t *working_control);
static bool logical_and(uint16_t number_of_parameters, s_parameter_type_CFL_t *parameters);

static bool logical_or(uint16_t number_of_parameters, s_parameter_type_CFL_t *parameters);

static bool logical_nor(uint16_t number_of_parameters, s_parameter_type_CFL_t *parameters);

static void process_buffer_operator_CFL(const void *input, s_bit_working_control_CFL_t *working_control, uint16_t op_value, uint16_t stack_start);
static void process_logical_operator_CFL(const void *input, s_bit_working_control_CFL_t *working_control, uint16_t op_value, uint16_t stack_start);

void process_next_s_bit_instr_CFL(const void *input, s_bit_working_control_CFL_t *working_control)
{

    s_operator_type_CFL_t working_instruction = bit_pop_op_stack_CFL(working_control->stack_control);

    uint8_t op_type = working_instruction.operator_type;
    uint16_t op_value = working_instruction.operator_value;
    uint8_t p_stack_start = working_instruction.parameter_stack_start; // index of operator or value
    // identify operator type
    switch (op_type)
    {

    case S_BIT_LOGIC_OPERATOR_CFL:
        process_logical_operator_CFL(input, working_control, op_value, p_stack_start);
        break;
    case S_BIT_BUFFER_OPERATOR_CFL:
        process_buffer_operator_CFL(input, working_control, op_value, p_stack_start);
        break;
    default:
        ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n", op_type);
    }
}

static void process_logical_operator_CFL(const void *input, s_bit_working_control_CFL_t *working_control, uint16_t op_value, uint16_t stack_start)
{
    (void)input;
    bool result = false;
    unsigned number_of_parameters = bit_parameter_stack_size_CFL(working_control->stack_control) - stack_start;
    s_parameter_type_CFL_t *parameters = s_bit_get_parameter_stack_CFL(working_control->stack_control, stack_start);
    // verify for logical values in parameter stack
    switch (op_value)
    {
    case S_BIT_LOGICAL_AND_CFL:
        result = logical_and(number_of_parameters, parameters);
        break;
    case S_BIT_LOGICAL_OR_CFL:
        result = logical_or(number_of_parameters, parameters);
        break;

    case S_BIT_LOGICAL_NOR_CFL:
        result = logical_nor(number_of_parameters, parameters);
        break;

    default:
        ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n", op_value);
    }
    s_parameter_type_CFL_t p_op = {S_BIT_VALUE_CFL, result};
    bit_push_parameter_stack_CFL(working_control->stack_control, p_op);
}


void verify_logical_parameters(uint16_t op_number, s_parameter_type_CFL_t *buffer_position)
{
    for (unsigned i = 0; i < op_number; i++)
    {
        s_parameter_type_CFL_t temp = *(buffer_position+i);
        if(temp.parameter_type != S_BIT_VALUE_CFL){
            ASSERT_PRINT_F("s_bit_engine: parameter type is not buffer position %d\n",temp.parameter_type);
        }
        if(temp.parameter_value > 1){
            ASSERT_PRINT_F("s_bit_engine: buffer position is out of range of boolean %d %d\n",temp,1);
        }
    }
}



static void get_buffer_positions(s_bit_working_control_CFL_t *working_control, uint16_t op_number,s_parameter_type_CFL_t *buffer_position)
{
    Bitmap_CFL *bmp = working_control->bitmap;
    uint16_t buffer_size = bmp->length;
    verify_logical_parameters(op_number, buffer_position);
    for (unsigned i = 0; i < op_number; i++)
    {
        s_parameter_type_CFL_t temp = *(buffer_position+i);
        if(temp.parameter_type != S_BIT_BUFFER_POSITION_CFL){
            ASSERT_PRINT_F("s_bit_engine: parameter type is not buffer position %d\n",temp.parameter_type);
        }
        if(temp.parameter_value >= buffer_size){
            ASSERT_PRINT_F("s_bit_engine: buffer position is out of range %d %d\n",temp,buffer_size);
        }
        buffer_position[i].parameter_value = bmp->data[temp.parameter_value];

    }
}

static void process_buffer_operator_CFL(const void *input, s_bit_working_control_CFL_t *working_control, uint16_t op_value, uint16_t stack_start)
{
    (void)input;
    bool result = false;
    unsigned number_of_parameters = bit_parameter_stack_size_CFL(working_control->stack_control) - stack_start;
    s_parameter_type_CFL_t *parameters = s_bit_get_parameter_stack_CFL(working_control->stack_control, stack_start);
    get_buffer_positions(working_control,number_of_parameters,parameters);
    switch (op_value)
    {
    case S_BIT_BUFFER_AND_CFL:
        result = logical_and(number_of_parameters, parameters);
        break;
    case S_BIT_BUFFER_OR_CFL:
        result = logical_or(number_of_parameters, parameters);
        break;

    case S_BIT_BUFFER_NOR_CFL:
        result = logical_nor(number_of_parameters, parameters);
        break;

    default:
        ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n", op_value);
    }
    bit_release_parameter_stack_CFL(working_control->stack_control, number_of_parameters);
    s_parameter_type_CFL_t p_op = {S_BIT_VALUE_CFL, result};
    bit_push_parameter_stack_CFL(working_control->stack_control, p_op);
}

static bool logical_and(uint16_t number_of_parameters, s_parameter_type_CFL_t *parameters)
{

    for (uint16_t i = 0; i < number_of_parameters; i++)
    {

        if (parameters[i].parameter_value == 0)
        {
            return false;
        }
    }
    return true;
}
static bool logical_or(uint16_t number_of_parameters, s_parameter_type_CFL_t *parameters)
{
    for (uint16_t i = 0; i < number_of_parameters; i++)
    {

        if (parameters[i].parameter_value > 0)
        {
            return true;
        }
    }
    return false;
}

static bool logical_nor(uint16_t number_of_parameters, s_parameter_type_CFL_t *parameters)
{
    for (uint16_t i = 0; i < number_of_parameters; i++)
    {

        if (parameters[i].parameter_value > 0)
        {
            return false;
        }
    }
    return true;
}
