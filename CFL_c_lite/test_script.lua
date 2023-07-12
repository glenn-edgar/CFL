
set_output("test_script.h")

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(allocate_once_heap_size,private_heap_size,default_event_queue_size)  

local column_list = {"column1","column2","column3"}
define_columns(column_list)
define_named_queue("queue1",10) 
define_named_queue("queue2",10)
define_named_queue("queue3",10)



define_column("column1",true,"queue1")
  Log_msg("this is a test message")
  reset_column()
end_column()

define_column("column2",true,"queue2")
   halt_column()       
end_column()

define_column("column3",true,"queue3")
   terminate_column()
end_column()

define_columns({"column4"})
define_column("column4",true,nil)
   terminate_engine()
end_column()

dump_output()
