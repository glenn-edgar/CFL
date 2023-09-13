set_h_file("state_machine_1.h")
local entry_point = "state_machine_1_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

local message = string.format('const char test_data[] = "%s\\n";\n',"test_data")
write_output(message)

reserve_state_machines({"test_sm"})
define_columns({"start_column"})

define_column("start_column",true,nil)
    Log_msg('start column')
    enable_disable_sms({"test_sm"})
    Wait_delay(20000)
    Log_msg('terminating')
    terminate_column()
end_column()





local state_list = {"test_state1","test_state2","test_state3","test_state4"}
local queue_name = "test_sm_queue"
local queue_size = 10
local user_data = "(void *)test_data"
define_state_machine("test_sm",state_list,queue_name,queue_size,user_data)



define_add_manager_chain()
    Log_msg('state machine manager starting')
    Wait_delay(2000)
    change_state("test_state1")
    Log_msg('this message should not be printed')
    halt_column()
end_column()


define_state("test_state1")
    Log_msg('state 1 starting')
    Wait_delay(2000)
    change_state("test_state2")
    Log_msg('this message should not be printed')
    halt_column()
end_column()

define_state("test_state2")
    Log_msg('state 2 starting')
    Wait_delay(2000)
    change_state("test_state3")
    Log_msg('this message should not be printed')
    halt_column()
end_column()


define_state("test_state3")
    Log_msg('state 3 starting')
    Wait_delay(2000)
    change_state("test_state4")
    Log_msg('this message should not be printed')
    halt_column()
end_column()


define_state("test_state4")
    Log_msg('state 4 starting')
    Wait_delay(2000)
    change_state("test_state1")
    Log_msg('this message should not be printed')
    halt_column()
end_column()



end_state_machine()

dump_build()
