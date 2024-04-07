set_h_file("state_machine_1.h")
local entry_point = "state_machine_1_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 


reserve_state_machines({"test_sm"})
define_columns({"start_column"})

define_column("start_column",true)
    Log_msg('start column')
    sms_enable({"test_sm"})
    Wait_delay(20000)
    Log_msg('disabling state machine')
    sms_disable({"test_sm"})
    enable_disable_sms({"test_sm"})
    Wait_delay(10000)
    Log_msg('terminating')
    terminate_column()
end_column()




local message = string.format('const char test_data[] = "%s\\n";\n',"test_data")
Store_user_code(message)



local user_data = "test_data"


state_column_list = { { "state_1", "state_1_col" }, { "state_2", "state_2_col" }, { "state_3", "state_3_col" }, { "state_4","state_4_col" } }
define_columns({"manager_column","state_1_col","state_2_col","state_3_col","state_4_col"},0)
define_state_machine("test_sm","manager_column",state_column_list, user_data)


define_column("manager_column",false)
    Log_msg('state machine manager starting')
    Wait_delay(2000)
    sms_change_state("state_2")
    Wait_delay(2000)
    Log_msg("manager column time out")
    halt_column()
end_column()


define_column("state_1_col",false)
    Log_msg('state 1 starting')
    Wait_delay(2000)
    sms_change_state("state_2")
    Log_msg('this message should not be printed')
    halt_column()
end_column()

define_column("state_2_col",false)
    Log_msg('state 2 starting')
    Wait_delay(2000)
    sms_change_state("state_3")
    Log_msg('this message should not be printed')
    halt_column()
end_column()


define_column("state_3_col",false)
    Log_msg('state 3 starting')
    Wait_delay(2000)
    sms_change_state("state_4")
    Log_msg('this message should not be printed')
    halt_column()
end_column()


define_column("state_4_col",false)
    Log_msg('state 4 starting')
    Wait_delay(2000)
    sms_change_state("state_1")
    Log_msg('this message should not be printed')
    halt_column()
end_column()





dump_build()
