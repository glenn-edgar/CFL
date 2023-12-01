
set_h_file("bit_maps_1.h")
local entry_point = "bit_maps_1_handle"


local allocate_once_heap_size = 10000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

define_bit_map("bit_map_1",152,true)




define_bit_map("bit_map_2",63,false)
define_bit_map("bit_map_3",75)

define_columns({"start_column","configure_bit_maps","shift_bit_map","s_expression_bit_map","complex_expression_bit_map","if_then_else_test","wait_trigger","wait_test","verify_test","verify_fail_trigger"})

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({"configure_bit_maps","shift_bit_map","s_expression_bit_map","complex_expression_bit_map","if_then_else_test","wait_trigger","wait_test"},false)
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

--- defining user one shot functions

local my_then_one_shot_header = [[

typedef struct my_then_one_shot_CFL_t{
    uint16_t source_buffer;
    uint16_t bit_position;
}my_then_one_shot_CFL_t;


void my_then_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local  my_then_one_shot_body = [[

void  my_then_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    my_then_one_shot_CFL_t* setup = (my_then_one_shot_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    bitmap_set_bit_CFL(source_bmp,setup->bit_position,true);
    Printf_CFL("then branch passed");
}

]]



Store_one_shot_function("MY_ONE_SHOT_THEN_FN",'my_then_one_shot_fn', my_then_one_shot_body, my_then_one_shot_header)



local my_else_one_shot_header = [[

typedef struct my_else_one_shot_CFL_t{
    const char* message;
}my_else_one_shot_CFL_t;


void my_else_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local  my_else_one_shot_body = [[

void  my_else_one_shot_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    my_else_one_shot_CFL_t* setup = (my_else_one_shot_CFL_t*)params;
    Printf_CFL("else branch %s",setup->message);
}  

]]


Store_one_shot_function("MY_ONE_SHOT_ELSE_FN"," my_else_one_shot_fn", my_else_one_shot_body, my_else_one_shot_header)

local then_data_name = generate_unique_function_name()
local bit_map_1_number =  get_s_bit_buffer_number("bit_map_1")
local then_data = string.format("static const my_then_one_shot_CFL_t %s = {%d,%d};\n",then_data_name,bit_map_1_number,16) 

Store_user_code(then_data)

local else_data_name = generate_unique_function_name()
local else_data = string.format('static const my_else_one_shot_CFL_t %s = {"This is the message from else one shot\\n"};\n',else_data_name)

Store_user_code(else_data)


define_column("if_then_else_test",false,nil)
    Log_msg('if then else test')
 
    clear_bit_map("bit_map_1",false)
    clear_bit_map("bit_map_1",true,0,1)
    Log_msg("then test") 
    if_then_else_bit_map("bit_map_1",0,"MY_ONE_SHOT_THEN_FN",then_data_name,"MY_ONE_SHOT_ELSE_FN",else_data_name)   
    dump_bit_map_buffer("bit_map_1")
    clear_bit_map("bit_map_1",false)
    Log_msg("else test") 
    if_then_else_bit_map("bit_map_1",0,"MY_ONE_SHOT_THEN_FN",then_data_name,"MY_ONE_SHOT_ELSE_FN",else_data_name)   
    dump_bit_map_buffer("bit_map_1")
    terminate_column()
end_column()

define_column("wait_trigger",false,nil)
    clear_bit_map("bit_map_1",false)
    Log_msg('wait trigger')
    dump_bit_map_buffer("bit_map_1")
    Wait_delay(3000)
    Log_msg('triggering bit map 1')
    clear_bit_map("bit_map_1",true,0,2)
    dump_bit_map_buffer("bit_map_1")
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

wait_test_s_exp = s_and({p0,p1})

define_column("wait_test",false,nil)
    Log_msg('wait test')
    Wait_s_expression("bit_map_1",wait_test_s_exp,4000, true, "THIS_SHOULD_NOT_HAPPEN_ONE_SHOT", 'NULL')
    Log_msg("wait triggered")
    Enable_columns({"verify_test","verify_fail_trigger"},false)
    terminate_column()
end_column()

local verify_trigger_fn_header = [[



void verify_trigger_fn(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local  verify_trigger_fn_body = [[

void  verify_trigger_fn(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    (void)event_data;
    (void)params;
    Printf_CFL("****************************** verify condition triggered  ************************** \n");
}  

]]



Store_one_shot_function( "VERIFY_FAIL_RESULT","verify_trigger_fn",verify_trigger_fn_body, verify_trigger_fn_header)


verify_test_s_exp = s_nor({p0,p1})
define_column("verify_test",false,nil)
   Log_msg('verify test started')
   clear_bit_map("bit_map_1",false)
   dump_bit_map_buffer("bit_map_1")
   Verify_s_expression("bit_map_1",verify_test_s_exp, true,"VERIFY_FAIL_RESULT",'NULL')
   Wait_delay(15000)
   Log_msg('This step should not occur as column would be terminated by verify fail')
   terminate_column()
end_column()


define_column("verify_fail_trigger",false,nil)
   
   Wait_delay(3000)
   Log_msg("triggering verify fail")
   clear_bit_map("bit_map_1",true,0,2)
   dump_bit_map_buffer("bit_map_1")
   terminate_column()
end_column()


dump_build()

