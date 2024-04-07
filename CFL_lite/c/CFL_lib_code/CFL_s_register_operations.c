#include "CFL_inner_engine.h"
#include "CFL_s_register_operations.h"

static int16_t get_register_value(const void *input,Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t  *parameter){
    int16_t result = 0;
    if (parameter->parameter_type == S_REGISTER_VALUE_CFL)
        {
            result = (result + parameter->parameter_value.value);
    
        }
        else
        {
            result = registermap_get_value_CFL(input,bmp, parameter->parameter_value.buffer_position);
            
        }
        return result;
}






static int16_t  register_add_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{ 
    
    int16_t result = get_register_value(input,bmp,&parameters[0]);
    
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
          result = result + get_register_value(input,bmp,&parameters[i]);
       
    }
    return result;
}

static int16_t  register_subtract_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
     int16_t result = get_register_value(input,bmp,&parameters[0]);
    
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
        result = result - get_register_value(input,bmp,&parameters[i]);
       
    }
    return result;
}

static int16_t  register_multiply_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
   int16_t result = get_register_value(input,bmp,&parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
        result = result * get_register_value(input,bmp,&parameters[i]);
    }
    return result;
}

static int16_t  register_divide_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);
    return parameter_1 / parameter_2;
}

static int16_t  register_modulus_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
     parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);
    return parameter_1 % parameter_2;
}

static int16_t  bit_shift_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);
    if (parameter_2 > 0)
    {
        return parameter_1 << parameter_2;
    }
    parameter_2 = -parameter_2;
    return parameter_1 >> parameter_2;
}


static int16_t  bit_and_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    int16_t result = get_register_value(input,bmp,&parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
          result = result & get_register_value(input,bmp,&parameters[i]);
    }
    return result;
}
static int16_t  bit_or_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    int16_t result = get_register_value(input,bmp,&parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
         result = result | get_register_value(input,bmp,&parameters[i]);
    }
    return result;
}


static int16_t  bit_xor_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    int16_t result = get_register_value(input,bmp,&parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {
          result = result ^ get_register_value(input,bmp,&parameters[i]);
    }
    return result;
}

static int16_t  bit_nor_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    int16_t result = get_register_value(input,bmp,&parameters[0]);
    for (uint16_t i = 1; i < number_of_parameters; i++)
    {

          result = ~(result | get_register_value(input,bmp,&parameters[i]));

    }
    return result;
}

 

static int16_t logical_and_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters)
{
    for (uint16_t i = 0; i < number_of_parameters; i++)
    {
        if (get_register_value(input,bmp,&parameters[i])==0) {

             return 0;
           
        }
    }
    return 1;
}


static int16_t logical_or_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters){
     for (uint16_t i = 0; i < number_of_parameters; i++)
    {
        if (get_register_value(input,bmp,&parameters[i])!=0) {

             return 1;
           
        }
    }
    return 0;
}



     
static int16_t gt_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters){
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);
    return parameter_1 > parameter_2;
}
static int16_t  ge_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters){
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);
 
    return parameter_1 >= parameter_2;
}

 static int16_t  eq_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters){
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);

    return parameter_1 == parameter_2;
}

 static int16_t  le_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters){
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);
   
    return parameter_1 <= parameter_2;
}

 static int16_t  lt_op(const void *input,uint16_t number_of_parameters, Registermap_CFL_t *bmp, s_register_parameter_type_CFL_t *parameters){
    int16_t parameter_1;
    int16_t parameter_2;
    if(number_of_parameters != 2){
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", number_of_parameters);
    }
    parameter_1= get_register_value(input,bmp,&parameters[0]);
    parameter_2 = get_register_value(input,bmp,&parameters[1]);
 
    return parameter_1 < parameter_2;
}


void process_register_operator_CFL(const void *input,  s_register_working_control_CFL_t *working_control, REGISTER_STREAM_CFL_t op_value, uint16_t stack_start){
    (void)input;
    Registermap_CFL_t *reg_map = working_control->regmap;
    int16_t result = 0;
    unsigned number_of_parameters = register_parameter_stack_size_CFL(working_control->stack_control) - stack_start;
    if (number_of_parameters == 0)
    {
        ASSERT_PRINT_F(input,"buffer ops: number of parameters is %d  \n", 0);
    }
    s_register_parameter_type_CFL_t *parameters = register_s_get_parameter_stack_CFL(input,working_control->stack_control, stack_start);
   
    switch (op_value.operator_value)
    {
        case S_REGISTER_MULTIPLY_CFL:
            result = register_multiply_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_DIVIDE_CFL:
            result = register_divide_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_ADD_CFL:
            result = register_add_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_SUBTRACT_CFL:
            result = register_subtract_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_MODULUS_CFL:
            result = register_modulus_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_SHIFT_CFL:
            result = bit_shift_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_BITWISE_AND_CFL:
            result = bit_and_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_BITWISE_OR_CFL:
            result = bit_or_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_BITWISE_XOR_CFL:
            result = bit_xor_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_BITWISE_NOR_CFL:
            result = bit_nor_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_LOGICAL_AND_CFL:
            result = logical_and_op(input,number_of_parameters, reg_map, parameters);
            break;
        case S_REGISTER_LOGICAL_OR_CFL:
            result = logical_or_op(input,number_of_parameters, reg_map, parameters);
            break;
 
            
        case S_REGISTER_GT_CFL:
            result =gt_op(input,number_of_parameters, reg_map, parameters);
            break;
        case   S_REGISTER_GE_CFL:
            result = ge_op(input,number_of_parameters, reg_map, parameters);
            break;  
        case  S_REGISTER_EQ_CFL:
            result = eq_op(input,number_of_parameters, reg_map, parameters);
            break;
        case  S_REGISTER_LE_CFL :
            result = le_op(input,number_of_parameters, reg_map, parameters);
            break;
        case  S_REGISTER_LT_CFL:
            result = lt_op(input,number_of_parameters, reg_map, parameters);
            break;  

        default:
            ASSERT_PRINT_F(input,"buffer ops: unknown operator type %d\n", op_value);
    }
    
     register_release_parameter_stack_CFL(input,working_control->stack_control, number_of_parameters);
    s_register_parameter_type_CFL_t p_op = {S_REGISTER_VALUE_CFL, {result}};
    register_push_parameter_stack_CFL(input,working_control->stack_control, &p_op);
    
 

}

