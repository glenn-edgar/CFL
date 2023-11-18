#include "CFL_inner_engine.h"
#include "CFL_s_register_engine.h"
#include "CFL_s_register_operations.h"

static int16_t pop_last_instruction(s_register_working_control_CFL_t *working_control);
static void iterate_input_stream(const void *input, s_register_working_control_CFL_t *working_control);

int16_t process_s_register_buffer_CFL(const void *input, const s_register_definition_CFL_t *s_register_buffer_interface)
{
        int16_t result = 0;
        s_register_working_control_CFL_t *working_control = (s_register_working_control_CFL_t *)private_heap_malloc_CFL(input, 
                  sizeof(s_register_working_control_CFL_t));
        working_control->operator_stream = s_register_buffer_interface->operator_stream;
        working_control->stream_length = s_register_buffer_interface->stream_length;
        working_control->instruction_index = 0;
        working_control->result = 0;

        working_control->regmap = get_registermap_control_CFL(input, s_register_buffer_interface->bit_map_number);

        working_control->stack_control = register_initialize_s_stack_CFL(input, s_register_buffer_interface->parameter_stack_size,
                                                                         s_register_buffer_interface->operator_stack_size);

        iterate_input_stream(input, working_control);
        result = pop_last_instruction(working_control);
        register_free_s_stack_CFL(input, working_control->stack_control);
        private_heap_free_CFL(input, working_control);
        return result;
}

static int16_t pop_last_instruction(s_register_working_control_CFL_t *working_control)
{
        int16_t stack_number = register_parameter_stack_size_CFL(working_control->stack_control);
        if (stack_number != 1)
        {
                ASSERT_PRINT_F("s_register_engine: parameter stack size is not equal to %d\n", stack_number);
        }
        s_register_parameter_type_CFL_t *parameter = register_pop_parameter_stack_CFL(working_control->stack_control);

        return parameter->parameter_value.value;
}

#define EXPRESSION_START 0
#define EVALUATE_EXPRESSION 1
#define EXPRESSION_END 2


static unsigned verify_expression_start(const void *input, s_register_working_control_CFL_t *working_control, s_register_operator_CFL_t operator)
{

        (void)input;
        unsigned return_value;
        uint8_t operator_type = operator.operator_type;
        REGISTER_STREAM_CFL_t operator_value = operator.data;

        switch (operator_type)
        {
        case S_REGISTER_VALUE_CFL:
        case S_REGISTER_BUFFER_POSITION_CFL:
        case S_REGISTER_OPERATOR_END_CFL:
                ASSERT_PRINT_F("s_bit_engine: operator type %d is not a valid start operator\n", operator_type);
                break;

        case  S_REGISTER_OPERATOR_CFL:
                return_value = EVALUATE_EXPRESSION;

                break;

        default:
                ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n", operator_type);
                break;
        }
        s_register_operator_type_CFL_t s_op = {operator_type, operator_value, register_parameter_stack_size_CFL(working_control->stack_control)};
  
        register_push_op_stack_CFL(working_control->stack_control, &s_op);
   
        return return_value;
}

static unsigned evaluate_expression(const void *input, s_register_working_control_CFL_t *working_control, s_register_operator_CFL_t operator)
{
        unsigned return_value;
        uint16_t operator_type = operator.operator_type;

         REGISTER_STREAM_CFL_t operator_value = operator.data;

        switch (operator_type)
        {

        case S_REGISTER_OPERATOR_CFL:
                return_value = verify_expression_start(input, working_control, operator);
                break;

        case S_REGISTER_BUFFER_POSITION_CFL:
        case S_REGISTER_VALUE_CFL:
                ;
                s_register_parameter_type_CFL_t parameter = {operator_type, operator_value};
                register_push_parameter_stack_CFL(working_control->stack_control, &parameter);
                return_value = EVALUATE_EXPRESSION;
                break;
        case S_REGISTER_OPERATOR_END_CFL:;
                s_register_operator_type_CFL_t *working_instruction = register_pop_op_stack_CFL(working_control->stack_control);

                 REGISTER_STREAM_CFL_t op_value = working_instruction->operator_value;
                uint16_t p_stack_start = working_instruction->parameter_stack_start; // index of operator or value
                process_register_operator_CFL(input, working_control, op_value, p_stack_start);
                
                return_value = EVALUATE_EXPRESSION;

                break;
        default:
                ASSERT_PRINT_F("s_reg_engine: unknown operator type %d\n", operator_type);
                break;
        }

        return return_value;
}

static void iterate_input_stream(const void *input, s_register_working_control_CFL_t *working_control)
{
        unsigned state = EXPRESSION_START;

        
        while (working_control->instruction_index < working_control->stream_length)
        {

                s_register_operator_CFL_t operator= working_control->operator_stream[working_control->instruction_index];
              
              
                working_control->instruction_index++;

                switch (state)
                {
                case EXPRESSION_START:
                        state = verify_expression_start(input, working_control, operator);
                        break;

                case EVALUATE_EXPRESSION:
                        state = evaluate_expression(input, working_control, operator);
                        if (state == EXPRESSION_END)
                        {
                                state = EXPRESSION_START;
                        }
                        break;

                default:
                        ASSERT_PRINT_F("s_bit_engine: unknown state %d\n", state);
                        break;
                }
        }
}
