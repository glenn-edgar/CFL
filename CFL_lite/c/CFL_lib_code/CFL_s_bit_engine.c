
#include "CFL_inner_engine.h"
#include "CFL_s_bit_stack.h"
#include "CFL_s_bit_engine.h"
#include "CFL_s_bit_operators.h"

static void iterate_input_stream(const void *input, s_bit_working_control_CFL_t *working_control);
static bool pop_last_instruction(s_bit_working_control_CFL_t *working_control);


bool process_s_bit_buffer_CFL(const void *input, s_bit_definition_CFL_t *s_bit_buffer_interface){
    bool result = false;
    s_bit_working_control_CFL_t *working_control = (s_bit_working_control_CFL_t*)private_heap_malloc_CFL(input,sizeof(s_bit_working_control_CFL_t));
    working_control->operator_stream = s_bit_buffer_interface->operator_stream;
    working_control->stream_length = s_bit_buffer_interface->stream_length;
    working_control->instruction_index = 0;
    working_control->result = false;
    working_control->bitmap = get_bitmap_control_CFL(input,s_bit_buffer_interface->bit_map_number);
    bit_initialize_s_stack_CFL(input,s_bit_buffer_interface->parameter_stack_size,s_bit_buffer_interface->operator_stack_size);

   
    iterate_input_stream(input,working_control);
    result = pop_last_instruction(working_control);
    bit_free_s_stack_CFL(input,working_control->stack_control);
    private_heap_free_CFL(input,working_control);
    return result;
}


static bool pop_last_instruction(s_bit_working_control_CFL_t *working_control){
    int16_t stack_number = bit_parameter_stack_size_CFL(working_control->stack_control);
    if(stack_number != 1){
        ASSERT_PRINT_F("s_bit_engine: parameter stack size is not equal to %d\n",stack_number);
    }
    s_parameter_type_CFL_t parameter = bit_pop_parameter_stack_CFL(working_control->stack_control);
    if( parameter.parameter_value == 0){
        return false;
    }
    return true;
}





static void iterate_input_stream(const void *input, s_bit_working_control_CFL_t *working_control){
    bool operator_state = false;
    while(working_control->instruction_index < working_control->stream_length){
          
          s_operator_CFL_t operator = working_control->operator_stream[working_control->instruction_index];
          uint8_t operator_type = operator.operator_type;
          uint16_t operator_value = operator.operator_index_value;
          switch(operator_type){
            case S_BIT_VALUE_CFL:
             case S_BIT_BUFFER_POSITION_CFL:
                if(operator_state == false){
                    ASSERT_PRINT_F("s_bit_engine: operator state is false %d %d\n",operator_type,operator_value);
                }
                s_parameter_type_CFL_t parameter = {operator_type,operator_value};
                bit_push_parameter_stack_CFL(working_control->stack_control, parameter);
                break;

            case S_BIT_LOGIC_OPERATOR_CFL:
            case S_BIT_BUFFER_OPERATOR_CFL:
                if(operator_state == false){
                    ASSERT_PRINT_F("s_bit_engine: operator state is false %d\n",operator_type,operator_value);
                }
                operator_state = true;
                s_operator_type_CFL_t s_op = {operator_type,operator_value,bit_parameter_stack_size_CFL(working_control->stack_control)};
                bit_push_op_stack_CFL(working_control->stack_control, s_op);
                break;

            
            case  S_BIT_OPERATOR_END_CFL:
                process_next_s_bit_instr_CFL(input,working_control);
                operator_state = false;
                break;

          default:
            ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n",operator_type);
            break;  
        }
        working_control->instruction_index++;
        
    }
}

