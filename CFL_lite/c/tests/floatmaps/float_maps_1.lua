
set_h_file("float_maps_1.h")
local entry_point = "float_map_1_handle"


local allocate_once_heap_size = 10000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

--[[
function initialize_float_maps()

    float_map_definition = {}
    float_map_list = {}
end
]]

define_float_map("float_map_1",32,-1.)
define_float_map("float_map_2",32,1)

enable_columns = {}
table.insert(enable_columns,"configure_float_maps")
table.insert(enable_columns,"s_expression_reg_map")


def_columns = {"start_column",table.unpack(enable_columns)}

define_columns(def_columns)

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({table.unpack(enable_columns)} ,false)
   
    Log_msg('terminating system')
    terminate_column()
end_column()

define_column("configure_float_maps",false,nil)
    
    Log_msg('configure reg maps')
    dump_float_map_buffer("float_map_1")
    dump_float_map_buffer("float_map_2")
    clear_float_map("float_map_1",10.14,10,20)
    clear_float_map("float_map_2",-10.95,10,20)
    dump_float_map_buffer("float_map_1")
    dump_float_map_buffer("float_map_2")
    array_1 = {-5.1,-4.1,-3.1,-2.1,-1.1,0.1,1.1,2.1,3.1,4.1,5.1}
    array_2 = {0.2,1.2,2.2,3.2,4.2,5.2,6.2,7.2,8.2,9.2,10.2}
    set_float_buffer_fn("float_map_1",5,array_1)
    set_float_buffer_fn("float_map_2",10,array_2)
    dump_float_map_buffer("float_map_1")
    dump_float_map_buffer("float_map_2")
    cp_float_buffer("float_map_2","float_map_1",10,20,11)
    dump_float_map_buffer("float_map_1")
    dump_float_map_buffer("float_map_2")
    
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
local p30 = '@30'
local p31 = '@31'


local float_mul_1 = float_mul({1,2,3,4,5})
local float_mul_2 = float_mul({p1,p2,p3,p4,p5})

local float_add_1 = float_add({1,2,3,4,5})
local float_add_2 = float_add({p11,p12,p13,p14,p15})

local float_div_1 = float_div(10.5,5)
local float_sub_1 = float_sub(10.5,5)


local float_mod_1 = float_mod(10.5,1.0)


local float_power_1 = float_pow(2.0,3.0)



local float_ln_1 = float_ln(2.0)
local float_exp_1= float_exp(float_ln_1)


local float_log_1 = float_log(2.3)
local float_10x_1 = float_10x(float_log_1)

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

-- x = 3
-- x = 2x^2 + 2x + 4
local complex_1 = float_add( {float_mul({2.0,float_pow(3.0,2.0)}),  float_mul({2.0,3.0}),  4.0})



local float_mul_1 = float_mul({1,2,3,4,5})
local float_mul_2 = float_mul({p5,p6,p7,p8,p9})

local float_add_1 = float_add({1,2,3,4,5})
local float_add_2 = float_add({p15,p16,p17,p18,p19})


define_column("s_expression_reg_map",false,nil)
    
    Log_msg('s expression reg map')
    clear_float_map("float_map_1",0,0,32)
    array_1 = {1,2,3,4,5}
    
    set_float_buffer_fn("float_map_1",5,array_1)
    set_float_buffer_fn("float_map_1",15,array_1)
    dump_float_map_buffer("float_map_1")
    s_float_expression("float_map_1", 3,"float_map_1",float_mul_1)
    s_float_expression("float_map_1", 4,"float_map_1",float_mul_2)
    s_float_expression("float_map_1", 13,"float_map_1",float_add_1)
    s_float_expression("float_map_1", 14,"float_map_1",float_add_2)
    dump_float_map_buffer("float_map_1")
    clear_float_map("float_map_1",0,0,32)
    s_float_expression("float_map_1", 0,"float_map_1",float_sub_1) -- 10.5 - 5      5.5
    s_float_expression("float_map_1", 1,"float_map_1",float_div_1) -- 10.5 / 5      2.1
    s_float_expression("float_map_1", 2,"float_map_1",float_mod_1) -- 10.5 % 1.0    0.5
    s_float_expression("float_map_1", 3,"float_map_1",float_power_1) -- 2.0 ^ 3.0   8
    s_float_expression("float_map_1", 4,"float_map_1",complex_1) -- 2x^2 + 2x + 4   x = 3  = 2*9 + 2*3 +4    18+6+4 = 28
    dump_float_map_buffer("float_map_1")
    clear_float_map("float_map_1",0,0,32)
    s_float_expression("float_map_1", 0,"float_map_1",float_exp_1)  -- 2.0
    s_float_expression("float_map_1", 1,"float_map_1",float_10x_1)  -- 2.3
    s_float_expression("float_map_1", 2,"float_map_1",float_deg_1) -- 45

    s_float_expression("float_map_1", 3,"float_map_1",float_asin_1)  -- 45
    s_float_expression("float_map_1", 4,"float_map_1",float_acos_1) -- 45
    s_float_expression("float_map_1", 5,"float_map_1",float_atan_1) -- 45

    s_float_expression("float_map_1", 6,"float_map_1",float_asinh_1)  -- 2.3
    s_float_expression("float_map_1", 7,"float_map_1",float_acosh_1)  -- 2.3
    s_float_expression("float_map_1", 8,"float_map_1",float_atanh_1)  -- 2.3

    s_float_expression("float_map_1", 9,"float_map_1",float_sqrt_1)  -- 1.516575    
    s_float_expression("float_map_1", 10,"float_map_1",float_pi_1) -- 3.14159

  
    s_float_expression("float_map_1", 11,"float_map_1",float_abs_1)  -- 1.516575    
    s_float_expression("float_map_1", 12,"float_map_1",float_abs_2) -- 3.14159

  
  
    s_float_expression("float_map_1", 13,"float_map_1",float_floor_1)  -- 1.516575    
    s_float_expression("float_map_1", 14,"float_map_1",float_floor_2) -- 3.14159


 

    s_float_expression("float_map_1", 15,"float_map_1",float_ceil_1)  -- 1.516575    
    s_float_expression("float_map_1", 16,"float_map_1",float_ceil_2) -- 3.14159

    s_float_expression("float_map_1", 17,"float_map_1",float_round_1)  -- 1.516575    
    s_float_expression("float_map_1", 18,"float_map_1",float_round_2) -- 3.14159

    s_float_expression("float_map_1", 19,"float_map_1",float_trunc_1 )  -- 1.516575    
    s_float_expression("float_map_1", 20,"float_map_1",float_trunc_2 ) -- 3.14159

 
    dump_float_map_buffer("float_map_1")
    terminate_column()
end_column()



-- if then else

-- wait

-- verify







dump_build()
