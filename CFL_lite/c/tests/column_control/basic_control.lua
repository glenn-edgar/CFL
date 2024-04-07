

set_h_file("basic_control.h")

local entry_point = "basic_control_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  


local column_list = {"enable_no_terminate","enable_no_terminate_test","enable_terminate","enable_terminate_test","disable","disable_test","join","join_test"}


define_columns(column_list)


--
-- Testing the enable instruction
--
define_column("enable_no_terminate",true)
    Log_msg("will enable column and terminate")
    Enable_columns({'enable_no_terminate_test'},false) 
    Log_msg("enable_no_terminate is done")
    terminate_column()
end_column()

define_column("enable_no_terminate_test",false)
    Log_msg("enable_no_terminate_test starting")
    Wait_delay(2000)
    Log_msg("enable_no_terminate_test is ending")
    terminate_column()
end_column()

define_column("enable_terminate",true)
    Log_msg("will enable column and terminate")
    Enable_columns({'enable_terminate_test' } , true) 
    Wait_delay(1000)
    Log_msg("enable_terminate is done")
    terminate_column()
end_column()

define_column("enable_terminate_test",false)
    Log_msg("enable_terminate_test starting")
    Wait_delay(2000)
    Log_msg("enable_terminate_test is ending")
    terminate_column()
end_column()

define_column("disable",true)
    Log_msg("disable  starting")
    Enable_columns({'disable_test' } , false) 
    Wait_delay(1000)
    Disable_columns({'disable_test' })
    Log_msg("Disable is done")
    terminate_column()
end_column()

define_column("disable_test",false)
    Log_msg("disable test is starting")
    Wait_delay(2000)
    Log_msg("disable test is  ending")
    terminate_column()
end_column()


define_column("join",true)
    Log_msg("join starting")
    Enable_columns({'join_test' } , false) 
    Wait_delay(1000)
    Join_columns({'join_test'})
    Log_msg("join is done")
    terminate_column()
end_column()

define_column("join_test",false)
    Log_msg("join test is starting")
    Wait_delay(2000)
    Log_msg("join test is  ending")
    terminate_column()
end_column()



dump_build()



