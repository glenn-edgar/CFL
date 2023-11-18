
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

define_columns({"start_column","configure_register_maps","s_expression_reg_map"})

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({"configure_register_maps","s_expression_reg_map"},true)
    Wait_delay(10000)
    Log_msg('terminating system')
    terminate_column()
end_column()

define_column("configure_register_maps",false,nil)
    
    Log_msg('configure bit maps')
    --clear_register_map("bit_map_1",true)
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

p0 = '@0'
p1 = '@1'
p2 = '@2'
p3 = '@3'
p4 = '@4'
p5 = '@5'
p6 = '@6'
p7 = '@7'
p8 = '@8'
p9 = '@9'
p10 = '@10'
p11 = '@11'
p12 = '@12'
p13 = '@13'
p14 = '@14'
p15 = '@15'
p16 = '@16'
p17 = '@17'
p18 = '@18'
p19 = '@19'
p20 = '@20'
p21 = '@21'
p22 = '@22'
p23 = '@23'
p24 = '@24'
p25 = '@25'
p26 = '@26'
p27 = '@27'
p28 = '@28'
p29 = '@29'


local mul_test = reg_mul({p1,p2,p3,p4})
local add_constant_test = reg_add({p1,15,p3,30})
local add_test = reg_add({p1,p2,p3,p4})
local sub_test = reg_sub({p1,p2})
local mod_test = reg_mod(p1,p2)
local div_test = reg_div(p1,p2)

local shift_test_1 = reg_shift(p1,1)
local shift_test_2 = reg_shift(p1,-1)

local reg_bit_and_test = reg_bit_and({p1,p2})
local reg_bit_or_test = reg_bit_or({p1,p2})
local reg_bit_xor_test = reg_bit_xor({p1,p2})
local reg_bit_nor_test = reg_bit_nor({p1,p2})

local reg_logical_and_test = reg_logical_and({p1,p2})
local reg_logical_or_test = reg_logical_or({p1,p2})

local reg_gt_test_1 = reg_gt(5,5)
local reg_gt_test_2 = reg_gt(5,4)

local reg_ge_test_1 = reg_ge(5,5)
local reg_ge_test_2 = reg_ge(5,4)

local reg_eq_test_1 = reg_eq(5,5)
local reg_eq_test_2 = reg_eq(5,4)

local reg_le_test_1 = reg_le(5,5)
local reg_le_test_2 = reg_le(4,5)

local reg_lt_test_1 = reg_lt(5,5)
local reg_lt_test_2 = reg_lt(4,5)





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


dump_build()
--[[

bs_expression_1 = s_and({p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16})

bs_expression_2 = s_or({p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16})

bs_expression_3 = s_nor({p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16})
--dump_s_expression(bs_expression_1)
s_expression_1 = s_and({true,true,true,true,true,true,true,true,true,true})
s_expression_2 = s_or({false,false,false,false,false,false,false,false,false,true})
s_expression_3 = s_nor({false,false,false,false,false,false,false,false,false,false})
--dump_s_expression(s_expression_1)

cs_expression_1 = s_and({s_expression_1,true,s_expression_2,false})
cs_expression_2 = s_and({s_expression_1,true,s_expression_2,true})
--,bs_expression_1,bs_expression_2,bs_expression_3
cs_expression_3 = s_and({s_expression_1,s_expression_2,cs_expression_2,bs_expression_1,bs_expression_2})
define_column("s_expression_bit_map",false,nil)
    Log_msg('s expression bit map')
    clear_bit_map("bit_map_1",false)
   
    clear_bit_map("bit_map_2",true)
   
    Log_msg("bs expression 1")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_1)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("bs expression 2")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("bs expression 3")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_3)
    dump_bit_map_buffer("bit_map_1")

    Log_msg("s expression 1")  
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_1)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("s expression 2")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("s expression 3")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_3)
    dump_bit_map_buffer("bit_map_1")


    Log_msg('terminating s expression bit map')
    terminate_column()
end_column()




define_column("complex_expression_bit_map",false,nil)
    Log_msg('s expression bit map')
    clear_bit_map("bit_map_1",false)
    
    clear_bit_map("bit_map_2",true)
   
    Log_msg("cs_expression_1")
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_1)
    clear_bit_map("bit_map_1",false)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("cs_expression_2")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("cs_expression_3")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_3)
    dump_bit_map_buffer("bit_map_1")   
    
    Log_msg('terminating s expression bit map')
    terminate_column()
end_column()




dump_build()
--[[
define_bit_map("bit_map_1",152,true)




define_bit_map("bit_map_2",63,false)
define_bit_map("bit_map_3",75)

define_columns({"start_column","configure_bit_maps","shift_bit_map","s_expression_bit_map","complex_expression_bit_map","if_then_else_test","wait_trigger","wait_test","verify_test","verify_fail_trigger"})

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({"configure_bit_maps","shift_bit_map","s_expression_bit_map","complex_expression_bit_map","if_then_else_test","wait_trigger","wait_test"},true)
    Wait_delay(10000)
    Log_msg('terminating system')
    terminate_column()
end_column()

define_column("configure_bit_maps",false,nil)
    Log_msg('configure bit maps')
    clear_bit_map("bit_map_1",true)
    Log_msg("clear bit map 1 true")
    dump_bit_map_buffer("bit_map_1")

    clear_bit_map("bit_map_1",false)
    clear_bit_map("bit_map_1",true,16,64)
    Log_msg("clear bit map 1 true 16,64")
    dump_bit_map_buffer("bit_map_1")


    clear_bit_map("bit_map_1",false)
    Log_msg("clear bit map 1 false")
    dump_bit_map_buffer("bit_map_1")
    clear_bit_map("bit_map_2",true)
    Log_msg("clear bit map 2 true")
    dump_bit_map_buffer("bit_map_2")
    cp_buffer("bit_map_2","bit_map_1",0,5,63)
    Log_msg("cp buffer 2 to 1 0,5,63")
    dump_bit_map_buffer("bit_map_1")

    and_bit_map_buffer("bit_map_2","bit_map_1",0,0,63)
    Log_msg("and buffer 2 to 1 0,0,63")
    dump_bit_map_buffer("bit_map_1")

    or_bit_map_buffer("bit_map_2","bit_map_1",0,0,63)
    Log_msg("or buffer 2 to 1 0,0,63")
    dump_bit_map_buffer("bit_map_1")


    xor_bit_map_buffer("bit_map_2","bit_map_1",0,0,63)
    Log_msg("xor buffer 2 to 1 0,0,63")
    dump_bit_map_buffer("bit_map_1")

    not_bit_map_buffer("bit_map_1","bit_map_1",0,0,128)
    Log_msg("not buffer 1 to bit buffer 1 0,0,128")
    dump_bit_map_buffer("bit_map_1")
    Log_msg('terminating bit map configuration')
    terminate_column()
end_column()

define_column("shift_bit_map",false,nil)
    Log_msg('shift bit maps')
    clear_bit_map("bit_map_1",false)
    clear_bit_map("bit_map_1",true,16,64)
    Log_msg("clear bit map 1 true 16,64")
    dump_bit_map_buffer("bit_map_1")
   
    for i = 1,8 do 
        clear_bit_map("bit_map_1",false)
        clear_bit_map("bit_map_1",true,16,64)
        shift_bit_map_buffer("bit_map_1",16,80,i)
        Log_msg("shift bit map "..tostring(i).." bit to the right")
        dump_bit_map_buffer("bit_map_1")
    end

   
    for i = 1,8 do 
        clear_bit_map("bit_map_1",false)
        clear_bit_map("bit_map_1",true,16,64)
        shift_bit_map_buffer("bit_map_1",0,64,-i)
        Log_msg("shift bit map "..tostring(-i).." bit to the right")
        dump_bit_map_buffer("bit_map_1")
    end

    

    terminate_column()

end_column()
p0 = '@0'
p1 = '@1'
p2 = '@2'
p3 = '@3'
p4 = '@4'
p5 = '@5'
p6 = '@6'
p7 = '@7'
p8 = '@8'
p9 = '@9'
p10 = '@10'
p11 = '@11'
p12 = '@12'
p13 = '@13'
p14 = '@14'
p15 = '@15'
p16 = '@16'
p17 = '@17'
p18 = '@18'
p19 = '@19'



bs_expression_1 = s_and({p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16})

bs_expression_2 = s_or({p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16})

bs_expression_3 = s_nor({p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16})
--dump_s_expression(bs_expression_1)
s_expression_1 = s_and({true,true,true,true,true,true,true,true,true,true})
s_expression_2 = s_or({false,false,false,false,false,false,false,false,false,true})
s_expression_3 = s_nor({false,false,false,false,false,false,false,false,false,false})
--dump_s_expression(s_expression_1)

cs_expression_1 = s_and({s_expression_1,true,s_expression_2,false})
cs_expression_2 = s_and({s_expression_1,true,s_expression_2,true})
--,bs_expression_1,bs_expression_2,bs_expression_3
cs_expression_3 = s_and({s_expression_1,s_expression_2,cs_expression_2,bs_expression_1,bs_expression_2})
define_column("s_expression_bit_map",false,nil)
    Log_msg('s expression bit map')
    clear_bit_map("bit_map_1",false)
   
    clear_bit_map("bit_map_2",true)
   
    Log_msg("bs expression 1")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_1)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("bs expression 2")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("bs expression 3")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_3)
    dump_bit_map_buffer("bit_map_1")

    Log_msg("s expression 1")  
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_1)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("s expression 2")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("s expression 3")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_3)
    dump_bit_map_buffer("bit_map_1")


    Log_msg('terminating s expression bit map')
    terminate_column()
end_column()




define_column("complex_expression_bit_map",false,nil)
    Log_msg('s expression bit map')
    clear_bit_map("bit_map_1",false)
    
    clear_bit_map("bit_map_2",true)
   
    Log_msg("cs_expression_1")
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_1)
    clear_bit_map("bit_map_1",false)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("cs_expression_2")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("cs_expression_3")
    clear_bit_map("bit_map_1",false)
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_3)
    dump_bit_map_buffer("bit_map_1")   
    
    Log_msg('terminating s expression bit map')
    terminate_column()
end_column()




]]--
