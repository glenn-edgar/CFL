
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

define_columns({"start_column","configure_bit_maps"})

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({"configure_bit_maps"},true)
    Wait_delay(6000)
    Log_msg('terminating system')
    terminate_column()
end_column()

define_column("configure_bit_maps",false,nil)
    Log_msg('configure bit maps')
    
    Log_msg('terminating bit map configuration')
    terminate_column()
end_column()


dump_build()