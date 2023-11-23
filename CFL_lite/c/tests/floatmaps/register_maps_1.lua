
set_h_file("register_maps_1.h")
local entry_point = "register_map_1_handle"


local allocate_once_heap_size = 10000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')


function initialize_register_maps()

    register_map_definition = {}
    register_map_list = {}
end

define_register_map("reg_map_1",32,0)
define_register_map("reg_map_2",32,32767)

define_columns({"start_column","configure_register_maps","s_expression_reg_map","s_complex_expression_reg_map","if_then_else_test","reg_wait_test","reg_verify_test",
                           "reg_verify_fail_trigger"})

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({"configure_register_maps","s_expression_reg_map","s_complex_expression_reg_map","if_then_else_test","reg_wait_test"},true)
    Wait_delay(10000)
    Log_msg('terminating system')
    terminate_column()
end_column()

define_column("configure_register_maps",false,nil)
    
    Log_msg('configure reg maps')
    dump_register_map_buffer("reg_map_1")
    dump_register_map_buffer("reg_map_2")
    clear_register_map("reg_map_1",10,10,20)
    clear_register_map("reg_map_2",-10,10,20)
    dump_register_map_buffer("reg_map_1")
    dump_register_map_buffer("reg_map_2")
    clear_register_map("reg_map_1",10,0,32)
    clear_register_map("reg_map_2",-10,0,32)
    dump_register_map_buffer("reg_map_1")
    dump_register_map_buffer("reg_map_2")
    clear_register_map("reg_map_1",0,0,32)
    clear_register_map("reg_map_2",0,0,32)
    dump_register_map_buffer("reg_map_1")
    dump_register_map_buffer("reg_map_2")
    array_1 = {-5,-4,-3,-2,-1,0,1,2,3,4,5}
    array_2 = {0,1,2,3,4,5,6,7,8,9,10}
    set_register_buffer_fn("reg_map_1",5,array_1)
    set_register_buffer_fn("reg_map_2",10,array_2)
    dump_register_map_buffer("reg_map_1")
    dump_register_map_buffer("reg_map_2")
    cp_register_buffer("reg_map_2","reg_map_1",10,20,11)
    dump_register_map_buffer("reg_map_1")
    
    terminate_column()
end_column()

local p0 = '@0'
local p1 = '@1'
local p2 = '@2'
local p3 = '@3'
local p4 = '@4'
local p5 = '@5'
local p6 = '@6'
local p7 = '@7'
local p8 = '@8'
local p9 = '@9'
local p10 = '@10'
local p11 = '@11'
local p12 = '@12'
local p13 = '@13'
local p14 = '@14'
local p15 = '@15'
local p16 = '@16'
local p17 = '@17'
local p18 = '@18'
local p19 = '@19'
local p20 = '@20'
local p21 = '@21'
local p22 = '@22'
local p23 = '@23'
local p24 = '@24'
local p25 = '@25'
local p26 = '@26'
local p27 = '@27'
local p28 = '@28'
local p29 = '@29'


local float_mul_1 = float_mul({1,2,3,4,5})
local float_mul_2 = float_mul({p1,p2,p3,p4,p5})

local float_add_1 = float_add{1,2,3,4,5})
local float_add_2 = float_add({p11,p12,p13,p14,p15})

local float_div_1 = float_div(10.5,5)
local float_div_2 = float_sub(10.5,5)

local float_mod_1 = float_mod(10.5,1.0)


local float_point_1 = float_pow(2.0,3.0)

local float_exp_1 = float_exp(2.0)

local float_ln_1 = float_ln(float_ln_1)



local float_log_1 = float_log(2.3)
local flow_10x_1 = float_10x(float_log_1)

local float_radian_1 = float_radian(45)

local float_deg_1  = float_deg(float_radian_1)

local float_pi_1 = float_pi()

local float_sin_1 = float_sin(float_radian_1)
local float_asin_1 = float_deg(float_asin(float_sin_1))
    
local float_cos_1 = float_cos(float_radian_1)
local float_acos_1 = float_deg(float_acos(float_cos_1))


local float_tan_1 = float_tan(float_radian_1)
local float_atan_1 = float_deg(float_atan(float_tan_1))

local float_sinh_1 = float_sinh(2.3)
local float_cosh_1 = float_cosh(2.3)
local float_tanh_1 = float_tanh(2.3)

local float_asinh_1 = float_asinh(float_sinh_1)
local float_acosh_1 = float_acosh(float_cosh_1)
local float_atanh_1 = float_atanh(float_tanh_1)

local float_sqrt_1 = float_sqrt(2.3)

local float_abs_1 = float_abs(-2.3)
local float_abs_2 = float_abs(2.3)

local float_floor_1 = float_floor(2.3)
local float_floor_2 = float_floor(-2.3)


local float_ceil_1 = float_floor(2.3)
local float_ceil_2 = float_floor(-2.3)

local float_round_1 = float_floor(2.3)
local float_round_2 = float_floor(-2.3)

local float_trunc_1 = float_trunc(2.3)
local float_trunc_2 = float_trunc(-2.3)


-- x = 2x^2 + 2x + 4
local complex_1 = float_add(float_mul(2.0,float_pow(2.0,2.0)),float_mul(2.0,2.0)),4.0)




define_column("s_expression_reg_map",false,nil)
    
    Log_msg('s expression reg map')
    clear_register_map("reg_map_1",0,0,32)
    array_1 = {0,1,2,3,4}
    set_register_buffer_fn("reg_map_1",0,array_1)
    dump_register_map_buffer("reg_map_1")
    s_reg_expression("reg_map_1",0, "reg_map_1",add_test)
    dump_register_map_buffer("reg_map_1")
    s_reg_expression("reg_map_1",0, "reg_map_1",add_constant_test)
    dump_register_map_buffer("reg_map_1")
    s_reg_expression("reg_map_1",0, "reg_map_1",mul_test)
    dump_register_map_buffer("reg_map_1")

    array_1 = {5,2}
    set_register_buffer_fn("reg_map_1",1,array_1)
    dump_register_map_buffer("reg_map_1")


    s_reg_expression("reg_map_1",0, "reg_map_1",sub_test)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",mod_test)
    dump_register_map_buffer("reg_map_1")
    
    s_reg_expression("reg_map_1",0, "reg_map_1",div_test)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",shift_test_1)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",shift_test_2)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_bit_and_test)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_bit_or_test)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_bit_xor_test )
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_bit_nor_test)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_logical_and_test )
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_logical_or_test)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_gt_test_1)
    dump_register_map_buffer("reg_map_1")
    
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_gt_test_2)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_ge_test_1)
    dump_register_map_buffer("reg_map_1")
    
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_ge_test_2)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_eq_test_1)
    dump_register_map_buffer("reg_map_1")
    
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_eq_test_2)
    dump_register_map_buffer("reg_map_1")
 
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_le_test_1)
    dump_register_map_buffer("reg_map_1")
    
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_le_test_2)
    dump_register_map_buffer("reg_map_1")

    s_reg_expression("reg_map_1",0, "reg_map_1",reg_lt_test_1)
    dump_register_map_buffer("reg_map_1")
    
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_lt_test_2)
    dump_register_map_buffer("reg_map_1")
    Log_msg('terminating s expression reg map')
    terminate_column()
end_column()

define_column("s_complex_expression_reg_map",false,nil)
    Log_msg('terminating complex s expression reg map')
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_complex_1)
    dump_register_map_buffer("reg_map_1")
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_complex_2)
    dump_register_map_buffer("reg_map_1")
    s_reg_expression("reg_map_1",0, "reg_map_1",reg_complex_3)
    dump_register_map_buffer("reg_map_1")
    terminate_column()
end_column()


local this_should_not_happen_header = [[



void this_should_not_happen_fn(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local  this_should_not_happen_body = [[

void  this_should_not_happen_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    (void)params;
    Printf_CFL("wait not triggered should not happen");
}  

]]



Store_one_shot_function( "THIS_SHOULD_NOT_HAPPEN_ONE_SHOT","this_should_not_happen_fn",this_should_not_happen_body, this_should_not_happen_header)

wait_test_s_exp = reg_logical_and({p0,p1})

define_column("reg_wait_test",false,nil)
    Log_msg('wait test')
    clear_register_map("reg_map_1",1,0,32)
    Wait_s_reg_expression("reg_map_1",wait_test_s_exp,4000, true, "THIS_SHOULD_NOT_HAPPEN_ONE_SHOT", 'NULL')
    Log_msg("wait triggered")
    Enable_columns({"reg_verify_test","reg_verify_fail_trigger"},true)
    Wait_delay(10000)
    terminate_column()
end_column()

local reg_verify_trigger_fn_header = [[



void reg_verify_trigger_fn(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local  reg_verify_trigger_fn_body = [[

void  reg_verify_trigger_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    (void)params;
    Printf_CFL("verify condition triggered \n");
}  

]]



Store_one_shot_function("REG_VERIFY_FAIL_RESULT","reg_verify_trigger_fn",reg_verify_trigger_fn_body, reg_verify_trigger_fn_header)


verify_test_s_reg_exp = reg_bit_nor({p0,p1})
define_column("reg_verify_test",false,nil)
   Log_msg('verify test started')
   clear_register_map("reg_map_1",0,0,32)
   dump_register_map_buffer("reg_map_1")
   Verify_s_register_expression("reg_map_1",verify_test_s_reg_exp, true,"REG_VERIFY_FAIL_RESULT",'NULL')
   Wait_delay(15000)
   Log_msg('This step should not occur as column would be terminated by verify fail')
   terminate_column()
end_column()


define_column("reg_verify_fail_trigger",false,nil)
   
   Wait_delay(3000)
   Log_msg("triggering verify fail")
   array_1 = {1}
   set_register_buffer_fn("reg_map_1",0,array_1)
   terminate_column()
end_column()

--- defining user one shot functions

local my_then_one_shot_header = [[

typedef struct reg_my_then_one_shot_CFL_t{
    uint16_t source_buffer;
    uint16_t reg_position;
    int16_t result;
}reg_my_then_one_shot_CFL_t;


void reg_my_then_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local  my_then_one_shot_body = [[

void  reg_my_then_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    reg_my_then_one_shot_CFL_t* setup = (reg_my_then_one_shot_CFL_t*)params;
    Registermap_CFL_t* bmp      =   get_registermap_control_CFL(input,setup->source_buffer);
    registermap_set_value_CFL(bmp,setup->reg_position,setup->result);  
}

]]



Store_one_shot_function("REG_MY_ONE_SHOT_THEN_FN",'reg_my_then_one_shot_fn', my_then_one_shot_body, my_then_one_shot_header)



local reg_my_else_one_shot_header = [[

typedef struct reg_my_else_one_shot_CFL_t{
    const char* message;
}reg_my_else_one_shot_CFL_t;


void reg_my_else_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local  reg_my_else_one_shot_body = [[

void  reg_my_else_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    reg_my_else_one_shot_CFL_t* setup = (reg_my_else_one_shot_CFL_t*)params;
    Printf_CFL("else branch %s",setup->message);
}  

]]


Store_one_shot_function("REG_MY_ONE_SHOT_ELSE_FN"," reg_my_else_one_shot_fn", reg_my_else_one_shot_body, reg_my_else_one_shot_header)

local then_data_name = generate_unique_function_name()
local reg_map_1_number =  get_s_register_buffer_number("reg_map_1")
local re_then_data = string.format("static const reg_my_then_one_shot_CFL_t %s = {%d,%d,%d};\n",then_data_name,reg_map_1_number,0,700) 

Store_user_code(re_then_data)

local else_data_name = generate_unique_function_name()
local else_data = string.format('static const reg_my_else_one_shot_CFL_t %s = {"This is the message from else one shot\\n"};\n',else_data_name)

Store_user_code(else_data)


define_column("if_then_else_test",false,nil)
    Log_msg('if then else test')

    Log_msg("then test") 
    clear_register_map("reg_map_1",1,0,32)    
    if_then_else_reg_map("reg_map_1",0,"REG_MY_ONE_SHOT_THEN_FN",then_data_name,"REG_MY_ONE_SHOT_ELSE_FN",else_data_name)   
    dump_register_map_buffer("reg_map_1")
    clear_register_map("reg_map_1",0,0,32)    
    if_then_else_reg_map("reg_map_1",0,"REG_MY_ONE_SHOT_THEN_FN",then_data_name,"REG_MY_ONE_SHOT_ELSE_FN",else_data_name)   
    dump_register_map_buffer("reg_map_1")
    terminate_column()
end_column()

dump_build()









