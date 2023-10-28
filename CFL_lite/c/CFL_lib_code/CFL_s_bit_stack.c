#include "CFL_inner_engine.h"
#include "CFL_s_bit_stack.h"





s_stack_control_CFL_t *bit_initialize_s_stack_CFL(const void *input,uint16_t p_stack_size,uint16_t op_stack_size){
    s_stack_control_CFL_t* stack_control =  private_heap_malloc_CFL(input,sizeof(s_stack_control_CFL_t));
    stack_control->s_op_stack_top = 0;
    stack_control->s_p_stack_top = 0;
    stack_control->s_op_stack_size = op_stack_size;
    stack_control->s_p_stack_size = p_stack_size;
    stack_control->s_op_stack = private_heap_malloc_CFL(input,sizeof(uint16_t )*op_stack_size);
    stack_control->s_p_stack = private_heap_malloc_CFL(input,sizeof(s_parameter_type_CFL_t)*p_stack_size);
   
    return stack_control;
}

void bit_free_s_stack_CFL(const void *input,s_stack_control_CFL_t *stack_control){
    private_heap_free_CFL(input,stack_control->s_op_stack);
    private_heap_free_CFL(input,stack_control->s_p_stack);
    private_heap_free_CFL(input,stack_control);
    
}




void bit_push_parameter_stack_CFL(s_stack_control_CFL_t *stack_control, s_parameter_type_CFL_t op){
  if(stack_control->s_p_stack_top <stack_control->s_p_stack_size-1){
    stack_control->s_p_stack[stack_control->s_p_stack_top] = op;
    stack_control->s_p_stack_top++;
  }
  else{
    ASSERT_PRINT_F("s_stack parameter stack overflow stack size %d\n",stack_control->s_p_stack_size);
  }


}

s_parameter_type_CFL_t  bit_pop_parameter_stack_CFL(s_stack_control_CFL_t *stack_control){
    if(stack_control->s_p_stack_top > 0){
        stack_control->s_p_stack_top--;
        return stack_control->s_p_stack[stack_control->s_p_stack_top];
    }
    else{
        ASSERT_PRINT_F("s_stack parameter stack underflow stack size %d\n",stack_control->s_p_stack_size);
        
    }
    return stack_control->s_p_stack[stack_control->s_p_stack_top];
}

s_parameter_type_CFL_t  * s_bit_get_parameter_stack_CFL(s_stack_control_CFL_t *stack_control ,uint16_t stack_start){
    if(stack_start >= stack_control->s_p_stack_top){
      ASSERT_PRINT_F("s_stack parameter stack start is not valid %d\n",stack_control->s_p_stack_size);
    }
   
    return &stack_control->s_p_stack[stack_start];


}

void bit_release_parameter_stack_CFL(s_stack_control_CFL_t *stack_control, unsigned number_of_parameters){
    if(stack_control->s_p_stack_top < number_of_parameters){
        ASSERT_PRINT_F("s_stack parameter stack underflow stack size %d\n",stack_control->s_p_stack_size);
    }
    stack_control->s_p_stack_top -= number_of_parameters;
}


void bit_push_op_stack_CFL(s_stack_control_CFL_t *stack_control, s_operator_type_CFL_t op){
  if(stack_control->s_p_stack_top < stack_control->s_p_stack_size-1){

    stack_control->s_op_stack[stack_control->s_op_stack_top] = op;
    stack_control->s_op_stack_top++;
  }
  else{
    ASSERT_PRINT_F("s_stack parameter stack overflow stack size %d\n",stack_control->s_op_stack_size);
  }


}

s_operator_type_CFL_t  bit_pop_op_stack_CFL(s_stack_control_CFL_t *stack_control){
    if(stack_control->s_op_stack_top > 0){
        stack_control->s_op_stack_top--;
        
    }
    else{
        ASSERT_PRINT_F("s_stack parameter stack underflow stack size %d\n",stack_control->s_op_stack_size);
      
    }
    return stack_control->s_op_stack[stack_control->s_op_stack_top];
}
s_operator_type_CFL_t *bit_peak_op_stack_CFL(s_stack_control_CFL_t *stack_control){

  if(stack_control->s_op_stack_top > 0){
    return &stack_control->s_op_stack[stack_control->s_op_stack_top-1];
  }
  
  return NULL;
  


}

uint16_t bit_op_stack_size_CFL(s_stack_control_CFL_t *stack_control){
    return stack_control->s_op_stack_top;
}

uint16_t bit_parameter_stack_size_CFL(s_stack_control_CFL_t *stack_control){
    
    return stack_control->s_p_stack_top;
}