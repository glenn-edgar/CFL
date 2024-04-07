
#include "CFL_inner_engine.h"
#include "CFL_s_float_stack.h"


s_float_stack_control_CFL_t *float_initialize_s_stack_CFL(const void *input,uint16_t p_stack_size,uint16_t op_stack_size){ 

    s_float_stack_control_CFL_t * stack_control =  private_heap_malloc_CFL(input,sizeof(s_float_stack_control_CFL_t ));
    stack_control->s_op_stack_top = 0;
    stack_control->s_p_stack_top = 0;
    stack_control->s_op_stack_size = op_stack_size;
    stack_control->s_p_stack_size = p_stack_size;
    stack_control->s_op_stack = private_heap_malloc_CFL(input,sizeof(s_float_operator_type_CFL_t)*op_stack_size);
    stack_control->s_p_stack = private_heap_malloc_CFL(input,sizeof( s_float_parameter_type_CFL_t)*p_stack_size);
   
    return stack_control;
}
void float_free_s_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control);void float_free_s_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control){

    private_heap_free_CFL(input,stack_control->s_op_stack);
    private_heap_free_CFL(input,stack_control->s_p_stack);
    private_heap_free_CFL(input,stack_control);
    
}

void float_push_parameter_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control, s_float_parameter_type_CFL_t* op){

 if(stack_control->s_p_stack_top <stack_control->s_p_stack_size-1){
    stack_control->s_p_stack[stack_control->s_p_stack_top] = *op;
    stack_control->s_p_stack_top++;

  }
  else{
    ASSERT_PRINT_F(input,"s_stack parameter stack overflow stack size %d\n",stack_control->s_p_stack_size);
  }




}

s_float_parameter_type_CFL_t *float_pop_parameter_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control){
    if(stack_control->s_p_stack_top == 0){
         ASSERT_PRINT_F(input,"s_stack parameter stack underflow stack size %d\n",stack_control->s_p_stack_size);
    }
 
    stack_control->s_p_stack_top--;

    return &stack_control->s_p_stack[stack_control->s_p_stack_top];
}


s_float_parameter_type_CFL_t  *float_s_get_parameter_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control ,uint16_t stack_start){
    
    if(stack_start > stack_control->s_p_stack_top){
      ASSERT_PRINT_F(input,"s_stack parameter stack start is not valid %d\n",stack_control->s_p_stack_size);
    }
   
    return &stack_control->s_p_stack[stack_start];


}



void float_release_parameter_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control, unsigned number_of_parameters){
    if(stack_control->s_p_stack_top < number_of_parameters){
        ASSERT_PRINT_F(input,"s_stack parameter stack underflow stack size %d\n",stack_control->s_p_stack_size);
    }
    stack_control->s_p_stack_top -= number_of_parameters;
}


void float_push_op_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control, s_float_operator_type_CFL_t *op){

  if(stack_control->s_op_stack_top < stack_control->s_op_stack_size-1){

    stack_control->s_op_stack[stack_control->s_op_stack_top] = *op;
    stack_control->s_op_stack_top++;
   
  }
  else{
    ASSERT_PRINT_F(input,"s_stack parameter stack overflow stack size %d\n",stack_control->s_op_stack_size);
  }


}

s_float_operator_type_CFL_t  *float_pop_op_stack_CFL(const void *input,s_float_stack_control_CFL_t *stack_control){
   
    if(stack_control->s_op_stack_top == 0){
        ASSERT_PRINT_F(input,"s_stack parameter stack underflow stack size %d\n",stack_control->s_op_stack_size);
    }
    stack_control->s_op_stack_top--;
    return &stack_control->s_op_stack[stack_control->s_op_stack_top];
    
}

s_float_operator_type_CFL_t *float_peak_op_stack_CFL(s_float_stack_control_CFL_t *stack_control){
  
  if(stack_control->s_op_stack_top > 0){
    return &stack_control->s_op_stack[stack_control->s_op_stack_top-1];
  }
  
  return NULL;
  


}

uint16_t float_op_stack_size_CFL(s_float_stack_control_CFL_t *stack_control){
    return stack_control->s_op_stack_top;
}

uint16_t float_parameter_stack_size_CFL(s_float_stack_control_CFL_t *stack_control){
    
    return stack_control->s_p_stack_top;
}


