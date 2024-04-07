

local entry_point = "wait_delay_handle"
set_h_file("wait_delay.h")

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7

start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')   


local column_list = {"terminate_engine","reset_loop"}
define_columns(column_list)

define_column("terminate_engine",true,0)
   Log_msg("this column will terminate the engine after 10 seconds")
   Wait_delay(10000)
   Log_msg("time delay done")
   Log_msg("stop engine")
   terminate_engine()
end_column()


define_column("reset_loop",true,0)
   Log_msg("this column will reset the engine every 2 seconds")
   Wait_delay(2000)
   Log_msg("two seconds past-- reset column")
   reset_column()
end_column()

dump_build()