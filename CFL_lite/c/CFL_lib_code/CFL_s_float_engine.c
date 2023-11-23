#include "CFL_inner_engine.h"
#include "CFL_s_float_engine.h"
#include "CFL_s_float_operations.h"

static float pop_last_instruction(s_float_working_control_CFL_t *working_control);
static void iterate_input_stream(const void *input, s_float_working_control_CFL_t *working_control);

float process_s_float_buffer_CFL(const void *input, const s_float_definition_CFL_t *s_float_buffer_interface)
{
        float result = 0;
        s_float_working_control_CFL_t *working_control = (s_float_working_control_CFL_t *)private_heap_malloc_CFL(input, 
                  sizeof(s_float_working_control_CFL_t));
        working_control->operator_stream = s_float_buffer_interface->operator_stream;
        working_control->stream_length = s_float_buffer_interface->stream_length;
        working_control->instruction_index = 0;
        working_control->result = 0;

        working_control->floatmap = get_floatmap_control_CFL(input, s_float_buffer_interface->float_map_number);

        working_control->stack_control = float_initialize_s_stack_CFL(input, s_float_buffer_interface->parameter_stack_size,
                                                                         s_float_buffer_interface->operator_stack_size);

        iterate_input_stream(input, working_control);
        result = pop_last_instruction(working_control);
        float_free_s_stack_CFL(input, working_control->stack_control);
        private_heap_free_CFL(input, working_control);
        return result;
}

static float pop_last_instruction(s_float_working_control_CFL_t *working_control)
{
        int16_t stack_number = float_parameter_stack_size_CFL(working_control->stack_control);
        if (stack_number != 1)
        {
                ASSERT_PRINT_F("s_float_engine: parameter stack size is not equal to  1 %d\n", stack_number);
        }
        s_float_parameter_type_CFL_t *parameter = float_pop_parameter_stack_CFL(working_control->stack_control);

        return parameter->parameter_value.float_value;
}

#define EXPRESSION_START 0
#define EVALUATE_EXPRESSION 1
#define EXPRESSION_END 2


static unsigned verify_expression_start(const void *input, s_float_working_control_CFL_t *working_control, s_float_operator_CFL_t operator)
{

        (void)input;
        unsigned return_value;
        uint8_t operator_type = operator.operator_type;
        FLOAT_STREAM_CFL_t operator_value = operator.data;
        switch (operator_type)
        {
        case S_FLOAT_VALUE_CFL:
        case S_FLOAT_BUFFER_POSITION_CFL:
        case S_FLOAT_OPERATOR_END_CFL:
                ASSERT_PRINT_F("s_bit_engine: operator type %d is not a valid start operator\n", operator_type);
                break;

        case  S_FLOAT_OPERATOR_CFL:
                return_value = EVALUATE_EXPRESSION;

                break;

        default:
                ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n", operator_type);
                break;
        }
        s_float_operator_type_CFL_t s_op = {operator_type, operator_value, float_parameter_stack_size_CFL(working_control->stack_control)};
  
        float_push_op_stack_CFL(working_control->stack_control, &s_op);
   
        return return_value;
}

static unsigned evaluate_expression(const void *input, s_float_working_control_CFL_t *working_control, s_float_operator_CFL_t operator)
{
        unsigned return_value;
        uint16_t operator_type = operator.operator_type;

         FLOAT_STREAM_CFL_t operator_value = operator.data;
       
        switch (operator_type)
        {

        case S_FLOAT_OPERATOR_CFL:
               
                return_value = verify_expression_start(input, working_control, operator);
                break;

        case S_FLOAT_BUFFER_POSITION_CFL:
        case S_FLOAT_VALUE_CFL:
              
                ;
                s_float_parameter_type_CFL_t parameter = {operator_type, operator_value};
                float_push_parameter_stack_CFL(working_control->stack_control, &parameter);
                return_value = EVALUATE_EXPRESSION;
                break;
        case S_FLOAT_OPERATOR_END_CFL:
              
                ;
                s_float_operator_type_CFL_t *working_instruction = float_pop_op_stack_CFL(working_control->stack_control);

                 FLOAT_STREAM_CFL_t op_value = working_instruction->operator_value;
                uint16_t p_stack_start = working_instruction->parameter_stack_start; // index of operator or value
              
                process_float_operator_CFL(input, working_control, op_value, p_stack_start);
                
                return_value = EVALUATE_EXPRESSION;

                break;
        default:
                ASSERT_PRINT_F("s_float_engine: unknown operator type %d\n", operator_type);
                break;
        }

        return return_value;
}

static void iterate_input_stream(const void *input, s_float_working_control_CFL_t *working_control)
{
        unsigned state = EXPRESSION_START;

     
        while (working_control->instruction_index < working_control->stream_length)
        {
              
                s_float_operator_CFL_t operator= working_control->operator_stream[working_control->instruction_index];
              
              
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
