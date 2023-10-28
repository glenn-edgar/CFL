
#include "CFL_inner_engine.h"
#include "CFL_s_bit_stack.h"
#include "CFL_s_bit_engine.h"
#include "CFL_s_bit_operators.h"

static void iterate_input_stream(const void *input, s_bit_working_control_CFL_t *working_control);
static bool pop_last_instruction(s_bit_working_control_CFL_t *working_control);


bool process_s_bit_buffer_CFL(const void *input,const  s_bit_definition_CFL_t *s_bit_buffer_interface){
   
    bool result = false;
    s_bit_working_control_CFL_t *working_control = (s_bit_working_control_CFL_t*)private_heap_malloc_CFL(input,sizeof(s_bit_working_control_CFL_t));
    working_control->operator_stream = s_bit_buffer_interface->operator_stream;
    working_control->stream_length = s_bit_buffer_interface->stream_length;
    working_control->instruction_index = 0;
    working_control->result = false;
   
    working_control->bitmap = get_bitmap_control_CFL(input,s_bit_buffer_interface->bit_map_number);
   
    working_control->stack_control = bit_initialize_s_stack_CFL(input,s_bit_buffer_interface->parameter_stack_size,s_bit_buffer_interface->operator_stack_size);
   
   
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





#define EXPRESSION_START 0
#define EVALUATE_BUFFER_EXPRESSION 1    
#define EVALUATE_LOGICAL_EXPRESSION 2
#define EXPRESSION_END 3

unsigned verify_expression_start(const void *input,s_bit_working_control_CFL_t *working_control,s_operator_CFL_t operator){

    (void)input;
    unsigned return_value;
    uint8_t operator_type = operator.operator_type;
    uint16_t operator_value = operator.operator_index_value;

    switch(operator_type){
      case S_BIT_VALUE_CFL:
      case S_BIT_BUFFER_POSITION_CFL:
      case S_BIT_OPERATOR_END_CFL:
           ASSERT_PRINT_F("s_bit_engine: operator type %d is not a valid start operator\n",operator_type);
           break;

      case S_BIT_LOGIC_OPERATOR_CFL:
           return_value = EVALUATE_LOGICAL_EXPRESSION;

           break;
      case S_BIT_BUFFER_OPERATOR_CFL:
           return_value = EVALUATE_BUFFER_EXPRESSION;


           break;
      
      default:
              ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n",operator_type);
              break;
      
    }
    s_operator_type_CFL_t s_op = {operator_type,operator_value,bit_parameter_stack_size_CFL(working_control->stack_control)};
    bit_push_op_stack_CFL(working_control->stack_control, s_op);
    return return_value;
}

unsigned evaluate_logical_expression(const void *input,s_bit_working_control_CFL_t *working_control,s_operator_CFL_t operator){
    unsigned return_value;
    uint8_t operator_type = operator.operator_type;
    unsigned op_type;
    uint16_t operator_value = operator.operator_index_value;

    switch(operator_type){
      case S_BIT_BUFFER_POSITION_CFL:
            ASSERT_PRINT_F("s_bit_engine: operator type %d is not a valid  operator\n",operator_type);
           break;


      
      case S_BIT_BUFFER_OPERATOR_CFL:
      case S_BIT_LOGIC_OPERATOR_CFL:
           return_value = verify_expression_start(input,working_control,operator);
           break;

     case S_BIT_VALUE_CFL:
           ;
           s_parameter_type_CFL_t parameter = {operator_type,operator_value};
           bit_push_parameter_stack_CFL(working_control->stack_control, parameter);
           return_value =  EVALUATE_LOGICAL_EXPRESSION;
           break;
      case S_BIT_OPERATOR_END_CFL:
              ;  
              s_operator_type_CFL_t working_instruction = bit_pop_op_stack_CFL(working_control->stack_control);
              op_type = working_instruction.operator_type; 
              uint16_t op_value = working_instruction.operator_value;
              uint8_t p_stack_start = working_instruction.parameter_stack_start; // index of operator or value
              process_logical_operator_CFL(input, working_control, op_value, p_stack_start);
              if(op_type == S_BIT_BUFFER_OPERATOR_CFL){
                return_value = EVALUATE_BUFFER_EXPRESSION;
              }
              else if(op_type == S_BIT_LOGIC_OPERATOR_CFL){
                return_value = EVALUATE_LOGICAL_EXPRESSION;
              }
              else{
                ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n",op_type);
              }
              break;
      default:
              ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n",operator_type);
              break;
      
    }
    
    return return_value;
}


unsigned evaluate_buffer_expression(const void *input,s_bit_working_control_CFL_t *working_control,s_operator_CFL_t operator){
    unsigned return_value;
    unsigned op_type;
    uint8_t operator_type = operator.operator_type;
    uint16_t operator_value = operator.operator_index_value;
    
    switch(operator_type){
      case S_BIT_VALUE_CFL:
      case S_BIT_BUFFER_OPERATOR_CFL:
      case S_BIT_LOGIC_OPERATOR_CFL:
           ASSERT_PRINT_F("s_bit_engine: operator type %d is not a valid start operator\n",operator_type);
           break;

      case S_BIT_BUFFER_POSITION_CFL:
           ;
           s_parameter_type_CFL_t parameter = {operator_type,operator_value};
           bit_push_parameter_stack_CFL(working_control->stack_control, parameter);
           return_value = EVALUATE_BUFFER_EXPRESSION;
           break;
      case S_BIT_OPERATOR_END_CFL:
              ;    
              s_operator_type_CFL_t working_instruction = bit_pop_op_stack_CFL(working_control->stack_control);
              s_operator_type_CFL_t *return_op;
              uint16_t op_value = working_instruction.operator_value;
              uint8_t p_stack_start = working_instruction.parameter_stack_start; // index of operator or value
              process_buffer_operator_CFL(input, working_control,op_value,p_stack_start);
              return_op = bit_peak_op_stack_CFL(working_control->stack_control);
              if(return_op == NULL){
                return EXPRESSION_END;
              }
              op_type = return_op->operator_type;
              if(op_type == S_BIT_BUFFER_OPERATOR_CFL){
                return_value = EVALUATE_BUFFER_EXPRESSION;
              }
              else if(op_type == S_BIT_LOGIC_OPERATOR_CFL){
                return_value = EVALUATE_LOGICAL_EXPRESSION;
              }
              else{
                ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n",op_type);
              }
              
              break;
      default:
              ASSERT_PRINT_F("s_bit_engine: unknown operator type %d\n",operator_type);
              break;
      
    }
    
    return return_value;
}






static void iterate_input_stream(const void *input, s_bit_working_control_CFL_t *working_control){
    unsigned state = EXPRESSION_START;
  
    while(working_control->instruction_index < working_control->stream_length){
       
      s_operator_CFL_t operator = working_control->operator_stream[working_control->instruction_index];
      
      working_control->instruction_index++;
       
      switch (state) {
        case EXPRESSION_START:
          state = verify_expression_start(input,working_control,operator);
          break;
           
        case EVALUATE_BUFFER_EXPRESSION:
          state = evaluate_buffer_expression(input,working_control,operator);
          if(state == EXPRESSION_END){
            state = EXPRESSION_START;
          } 
          break;

        case EVALUATE_LOGICAL_EXPRESSION:  
          state = evaluate_logical_expression(input,working_control,operator);
          if(state == EXPRESSION_END){
            state = EXPRESSION_START;
          }
          break;

        default:
          ASSERT_PRINT_F("s_bit_engine: unknown state %d\n",state);
          break;

        }

    }
    
 

}


