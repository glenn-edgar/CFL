
set_h_file("bit_maps_1.h")
local entry_point = "bit_maps_1_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

define_bit_map("bit_map_1",152,true)
add_bit_map_label("bit_map_1","l0",0)
add_bit_map_label("bit_map_1","l1",1)
add_bit_map_label("bit_map_1","l2",2)
add_bit_map_label("bit_map_1","l3",3)
add_bit_map_label("bit_map_1","l4",4)
add_bit_map_label("bit_map_1","l5",5)
add_bit_map_label("bit_map_1","l6",6)
add_bit_map_label("bit_map_1","l7",7)
add_bit_map_label("bit_map_1","l8",8)




define_bit_map("bit_map_2",63,false)
define_bit_map("bit_map_3",75)

define_columns({"start_column","configure_bit_maps","s_expression_bit_map","complex_expression_bit_map"})

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({"s_expression_bit_map","complex_expression_bit_map"},true)
    Wait_delay(6000)
    Log_msg('terminating system')
    terminate_column()
end_column()

define_column("configure_bit_maps",false,nil)
    Log_msg('configure bit maps')
    clear_bit_map("bit_map_1",true)
    dump_bit_map_buffer("bit_map_1")
    clear_bit_map("bit_map_1",false)
    dump_bit_map_buffer("bit_map_1")
    clear_bit_map("bit_map_2",true)
    dump_bit_map_buffer("bit_map_2")
    cp_buffer("bit_map_2","bit_map_1",0,5,63)
    dump_bit_map_buffer("bit_map_1")
    and_bit_map_buffer("bit_map_2","bit_map_1",0,0,63)
    dump_bit_map_buffer("bit_map_1")
    or_bit_map_buffer("bit_map_2","bit_map_1",0,0,63)
    dump_bit_map_buffer("bit_map_1")
    xor_bit_map_buffer("bit_map_2","bit_map_1",0,0,63)
    dump_bit_map_buffer("bit_map_1")
    not_bit_map_buffer("bit_map_1","bit_map_1",0,0,128)
    dump_bit_map_buffer("bit_map_1")
    Log_msg('terminating bit map configuration')
    terminate_column()
end_column()
--[[
p1 = 6
p2 = 7
p3 = 8
s_expression_1 = s_and_buffer("bit_map_2",{1,2,3,4,p1,p2,p3,11,12,13})
print("s expression_1")
dump_s_expression(s_expression_1)
s_expression_2 = s_or_buffer("bit_map_2",{1,2,3,4,p1,p2,p3,11,12,13})
print("s expression_2")
dump_s_expression(s_expression_2)
s_expression_3 = s_nor_buffer("bit_map_2",{1,2,3,4,p1,p2,p3,11,12,13})
print("s expression_3")
dump_s_expression(s_expression_3)
s_expression_4 = s_and({true,false,true,false,true,false,true,false,true,false})
print("s expression_4")
dump_s_expression(s_expression_4)
s_expression_5 = s_or({true,false,true,false,true,false,true,false,true,false})
print("s expression_5")
dump_s_expression(s_expression_5)
s_expression_6 = s_nor({true,false,true,false,true,false,true,false,true,false})
print("s expression_6")
dump_s_expression(s_expression_6)

s_expression_7 = s_and({s_expression_1,true,s_expression_2,false})
print("dumping nested s expression")

dump_s_expression(s_expression_7)
]]--

p1 = 6
p2 = 7
p3 = 8

bs_expression_1 = s_and_buffer("bit_map_2",{1,2,3,4,p1,p2,p3,11,12,13})

bs_expression_2 = s_or_buffer("bit_map_2",{1,2,3,4,p1,p2,p3,11,12,13})

bs_expression_3 = s_nor_buffer("bit_map_2",{1,2,3,4,p1,p2,p3,11,12,13})

s_expression_1 = s_and("bit_map_2",{true,true,true,true,true,true,true,true,true,true})
s_expression_2 = s_or("bit_map_2",{false,false,false,false,false,false,false,false,false,true})
s_expression_3 = s_nor("bit_map_2",{false,false,false,false,false,false,false,false,false,false})

cs_expression_1 = s_and("bit_map_2",{s_expression_1,true,s_expression_2,false})
cs_expression_2 = s_and("bit_map_2",{s_expression_1,true,s_expression_2,true})
--,bs_expression_1,bs_expression_2,bs_expression_3
cs_expression_3 = s_and("bit_map_2",{s_expression_1,s_expression_2,cs_expression_2,bs_expression_1,bs_expression_2})
define_column("s_expression_bit_map",false,nil)
    Log_msg('s expression bit map')
    clear_bit_map("bit_map_1",false)
    dump_bit_map_buffer("bit_map_1")
    clear_bit_map("bit_map_2",true)
    dump_bit_map_buffer("bit_map_2")

    Log_msg("bs expression 1")
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_1)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("bs expression 2")
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("bs expression 3")
    s_bit_expression("bit_map_1", 0,"bit_map_2",bs_expression_3)
    dump_bit_map_buffer("bit_map_1")

    Log_msg("s expression 1")  
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_1)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("s expression 2")
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("s expression 3")
    s_bit_expression("bit_map_1", 0,"bit_map_2",s_expression_3)
    dump_bit_map_buffer("bit_map_1")


    Log_msg('terminating s expression bit map')
    terminate_column()
end_column()




define_column("complex_expression_bit_map",false,nil)
    Log_msg('s expression bit map')
    clear_bit_map("bit_map_1",false)
    dump_bit_map_buffer("bit_map_1")
    clear_bit_map("bit_map_2",true)
    dump_bit_map_buffer("bit_map_2")
    Log_msg("cs_expression_1")
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_1)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("cs_expression_2")
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_2)
    dump_bit_map_buffer("bit_map_1")
    Log_msg("cs_expression_3")
    s_bit_expression("bit_map_1", 0,"bit_map_2",cs_expression_3)
    dump_bit_map_buffer("bit_map_1")   
    
    Log_msg('terminating s expression bit map')
    terminate_column()
end_column()

dump_build()
