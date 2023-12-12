set_h_file("state_machine_2.h")
local entry_point = "state_machine_2_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

local message = string.format('const char test_data_2[] = "%s\\n";\n',"test_data")
Store_user_code(message)

-- start of user events
set_user_event_start(100)


-- define event  id 
-- returns the event id

state_1_event = 101
state_2_event = 102
state_3_event = 103
state_4_event = 104



state_machine_event_1 = generate_event(101,false,'NULL')
state_machine_event_2 = generate_event(102,false,'NULL')
state_machine_event_3 = generate_event(103,false,'NULL')
state_machine_event_4 = generate_event(104,false,'NULL')
filter_event_1 = generate_event(111,false,'NULL')
filter_event_2 = generate_event(112,false,'NULL')
filter_event_3 = generate_event(113,false,'NULL')




-- returns const event address







reserve_state_machines({"test_sm"})
define_columns({"start_column","event_generator"})

local message = [[

const char test_data_11[] = "state 1 debug message";
const char test_data_21[] = "state 2 debug message";
const char test_data_31[] = "state 3 debug message";
const char test_data_41[] = "state 4 debug message";
]]
Store_user_code(message)



define_column("start_column",true,nil)
    Log_msg('start column')
    enable_disable_sms({"test_sm"})
    Enable_columns({"event_generator"},true)
    Wait_delay(60000)
    Log_msg('terminating')
    terminate_column()
end_column()

define_column("event_generator",false,nil)
    Log_msg("event generator start")
    Wait_delay(2000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_1)
    Wait_delay(2000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_2)
    Wait_delay(2000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_3)
    Wait_delay(2000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_4)
    reset_column()
end_column()

local state_list = {"test_state1","test_state2","test_state3","test_state4"}
local queue_name = "test_sm_queue"
local queue_size = 10
local user_data = "(void *)test_data_2"
define_state_machine("test_sm",state_list,queue_name,queue_size,user_data)



define_add_manager_chain()
    Log_msg('state machine manager starting')

    change_state("test_state1")
    state_change({state_1_event},"test_state1")
    state_change({state_2_event},"test_state2")
    state_change({state_3_event},"test_state3")
    state_change({state_4_event},"test_state4")
    redirect_event("TRUE","NULL")
   
    halt_column()
end_column()


define_state("test_state1")
    Log_msg('state 1 starting')
    sm_debug_function('test_data_11')
   
    halt_column()
end_column()

define_state("test_state2")
    Log_msg('state 2 starting')
    sm_debug_function('test_data_21')
    halt_column()
end_column()


define_state("test_state3")
    Log_msg('state 3 starting')
    sm_debug_function('test_data_31')
    halt_column()
end_column()


define_state("test_state4")
    Log_msg('state 4 starting')
    sm_debug_function('test_data_41')
    halt_column()
end_column()



end_state_machine()

dump_build()
