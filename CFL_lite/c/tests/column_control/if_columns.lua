set_h_file("if_then_else.h")

local entry_point = "if_then_else_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  



column_names = { "test_1", "test_2", "test_3", "test_4", "test_5","then_column", "else_column"}
define_columns(column_names)
then_columns = { "then_column" }
else_columns = { "else_column" }





define_column( "test_1", true)
  Log_msg( "starting test_1")
  If_then_else_columns('TRUE','NULL',then_columns,else_columns,true,false)
  Log_msg( "ending test_1")
end_column()

define_column( "test_2",false)
  Log_msg( "starting test_2")
  If_then_else_columns('FALSE','NULL',then_columns,else_columns,false,false)
  Log_msg( "ending test_2")
end_column()

define_column( "test_3", false)
  Log_msg( "starting test_3")
  If_then_else_columns('TRUE','NULL',then_columns,{},false,true)
  Wait_delay( 1000)
  Log_msg( "ending test_3")
  terminate_column()
end_column()


define_column( "test_4", false)
  Log_msg( "starting test_4")
  If_then_else_columns('FALSE','NULL',{},else_columns,false,false)
  Log_msg( "ending test_4")
  terminate_column()
end_column()

define_column( "test_5", false)
  Log_msg( "starting test_5")
  If_then_else_columns('TRUE','NULL',{},else_columns,false,false)
  Log_msg( "ending test_5")
  terminate_column()
end_column()


define_column( "then_column", false)
  Log_msg( "then column active")
  Wait_delay( 3000)
  Log_msg( "then column is terminating")
  terminate_column()
end_column()

define_column( "else_column", false)
  Log_msg( "else column active")
  Wait_delay( 3000)
  Log_msg( "else column is terminating")
  terminate_column()
end_column()




dump_build()


