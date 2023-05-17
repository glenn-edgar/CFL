
#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_s_int_expression.h"


static void test_integer_array_functions(Handle_config_CFL_t* config);

void s_expr_unit_tests(void){
   Printf_CFL("s_int_expr_unit_tests");
   Handle_config_CFL_t* config_handle = Create_config_handle_CFL();
   // no setting of parameters -- are parameters are set to zero
   test_integer_array_functions(config_handle);
   free(config_handle);

}

/************************************************  Integer Array Functions ***********************************************************************************************/

static int add_function(void *input, void *user_data,int count, int *args) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
         //Printf_CFL("%s %d args[%d] = %d \n",__func__,i,args[i]);
        sum += args[i];
    }
    //Printf_CFL("%s sum = %d \n",__func__,sum);
    return sum;
}

static int sub_function(void *input,void *user_data, int count, int *args) {
    int difference = args[0];
     //Printf_CFL("%s difference = %d \n",__func__,difference);
    for (int i = 1; i < count; i++) {
         //Printf_CFL("%s %d args[%d] = %d \n",__func__,i,args[i]);
        difference -= args[i];
    }
     //Printf_CFL("%s difference = %d \n",__func__,difference);
    return difference;
}

static int mul_function(void *input,void *user_data, int count, int *args) {
    int product = 1;
    for (int i = 0; i < count; i++) {
        //Printf_CFL("%s %d args[%d] = %d \n",__func__,i,args[i]);
        product *= args[i];
    }
    //Printf_CFL("%s product = %d \n",__func__,product);
    return product;
}

static int div_function(void *input, void *user_data, int count, int *args) {
    int quotient = args[0];
    for (int i = 1; i < count; i++) {
        if (args[i] == 0) {
            ASSERT_PRINT_INT("Division by zero at index",i);
            
        }
        quotient /= args[i];
    }
    return quotient;
}

static S_fn_record_CFL_t function_map[] = {
    {"add", add_function},
    {"sub", sub_function},
    {"mul", mul_function},
    {"div", div_function},
    
};
 

static void test_integer_array_functions(Handle_config_CFL_t*  config){
 
    void* input =  Configure_engine_CFL(config,40000,2500);
    void  *s_expr_handle;
    int   temp;

    const char *int_prompt = "(add 10 (sub 7 1 3) (mul 2 4) 5)";
    
    const char *int_prompt1 = "(add 10, (sub 7, 1, 3) (mul 2 , 4) , 5)";
    
    int fn_number = sizeof(function_map)/sizeof(function_map[0]);

    Printf_CFL("Remaining allocate once %d \n",Allocate_once_remaining_heap_size_CFL(input));
     Printf_CFL("largest private heap size %d \n",Private_heap_largest_free_block_CFL(input));

    s_expr_handle = Parse_s_int_expression_CFL(input, fn_number,function_map,int_prompt1);
    temp = Evaluate_s_int_expression_CFL(input,s_expr_handle, NULL);
    Printf_CFL("Result %d \n",temp);
    Printf_CFL("Remaining allocate once %d \n",Allocate_once_remaining_heap_size_CFL(input));
    Printf_CFL("largest private heap size %d \n",Private_heap_largest_free_block_CFL(input));
    
    s_expr_handle = Parse_s_int_expression_CFL(input, fn_number,function_map,int_prompt1);
    temp = Evaluate_s_int_expression_CFL(input,s_expr_handle, NULL);
    Printf_CFL("Result %d \n",temp);
    Printf_CFL("Remaining allocate once %d \n",Allocate_once_remaining_heap_size_CFL(input));
    Printf_CFL("largest private heap size %d \n",Private_heap_largest_free_block_CFL(input));     

    


   
    Destroy_engine_CFL(input);
   
    Printf_CFL("Free Memory %d \n",freeMemory());    
}


