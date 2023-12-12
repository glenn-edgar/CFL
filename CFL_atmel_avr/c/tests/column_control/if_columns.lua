set_h_file("if_then_else.h")

local entry_point = "if_then_else_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')



column_names = { "test_if", "if_then_0", "if_then_1", "if_then_2","if_else_0", "if_else_1", "if_else_2" }
define_columns(column_names)
then_columns = { "if_then_0", "if_then_1", "if_then_2" }
else_columns = { "if_else_0", "if_else_1", "if_else_2" }




define_column( "test_if", true)
  Log_msg( "starting test_if column")
  If_then_else_columns('TRUE','NULL',then_columns,else_columns,true,true)
  If_then_else_columns("FALSE",'NULL',then_columns,else_columns,true,true)
  
  If_then_else_columns('TRUE','NULL',then_columns,else_columns,false,false)
  If_then_else_columns("FALSE",'NULL',then_columns,else_columns,false,false)
  Log_msg( "done with if_then_else column")
  Wait_delay( 4000) -- wait till child columns are done
  Log_msg("time delay is over")
  If_then_else_columns('TRUE','NULL',then_columns,else_columns,false,true)
  If_then_else_columns("FALSE",'NULL',then_columns,else_columns,false,true)
  Log_msg("terminate flag set to true will kill child columns when terminate_column is called")
  terminate_column()
end_column()

define_column( "if_then_0", false)
  Log_msg( "if_then_0 should be active")
  Wait_delay( 1000)
  Log_msg( "if_then_0 is terminating")
  terminate_column()
end_column()

define_column( "if_then_1", false)
  Log_msg( "if_then_1 should be active")
  Wait_delay( 2000)
  Log_msg( "if_then_1 is terminating")
  terminate_column()
end_column()

define_column( "if_then_2", false)
  Log_msg( "if_then_2 should be active")
  Wait_delay( 3000)
  Log_msg( "if_then_2 is terminating")
  terminate_column()
end_column()



define_column( "if_else_0", false)
  Log_msg( "if_else_0 should be active")
  Wait_delay( 1000)
  Log_msg( "if_else_0 is terminating")
  terminate_column()
end_column()

define_column( "if_else_1", false)
  Log_msg( "if_else_1 should be active")
  Wait_delay( 2000)
  Log_msg( "if_else_1 is terminating")
  terminate_column()
end_column()

define_column( "if_else_2", false)
  Log_msg( "if_else_2 should be active")
  Wait_delay( 3000)
  Log_msg( "if_else_2 is terminating")
  terminate_column()
end_column()

dump_build()


