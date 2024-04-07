set_h_file("state_machine_2.h")
local entry_point = "state_machine_2_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 

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
filter_event_4 = generate_event(114,false,'NULL')







local feed_events_header = [[

typedef struct Feed_events_test_data_t
{
    const char *debug_message;

} Feed_events_test_data_t;


bool feed_events_test(const void *input, void* params, Event_data_CFL_t* event_data);
]]

local feed_events_code = [[

bool feed_events_test(const void *input, void* params, Event_data_CFL_t* event_data)
{

  
    Feed_events_test_data_t *feed_events_test_data = (Feed_events_test_data_t *)params;
    int event_id = event_data->event_index;
    switch(event_id)
    {
        
        case 114:
               Printf_CFL(input,feed_events_test_data->debug_message);
               Printf_CFL(input," .............. event 114 processed here \n");
               return false;
            break;
        default:
            return true;
    }
    return true;
}

]]

Store_boolean_function("SM_FEED_EVENTS", "feed_events_test", feed_events_code,feed_events_header)

reserve_state_machines({"test_sm"})
define_columns({"start_column","event_generator"})

local message = [[

const char test_data_11[] = "state 1 debug message";
const char test_data_21[] = "state 2 debug message";
const char test_data_31[] = "state 3 debug message";
const char test_data_41[] = "state 4 debug message";



const Feed_events_test_data_t feed_test_data = {
    .debug_message = "feed event 2 debug message"
};

]]
Store_user_code(message)



define_column("start_column",true,nil)
    Log_msg('start column')
    enable_disable_sms({"test_sm"})
    Enable_columns({"event_generator"},true)
    Wait_delay(24000)
    Log_msg('terminating')
    terminate_column()
end_column()

define_column("event_generator",false,nil)
    Log_msg("event generator start")
    Wait_delay(2000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)
    send_state_machine_event("test_sm",filter_event_4)

    send_state_machine_event("test_sm",state_machine_event_1)

    Wait_delay(2000)

    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)
     send_state_machine_event("test_sm",filter_event_4)

    send_state_machine_event("test_sm",state_machine_event_2)

    Wait_delay(2000)

    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)
    send_state_machine_event("test_sm",filter_event_4)

    send_state_machine_event("test_sm",state_machine_event_3)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    Wait_delay(2000)

    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)
    send_state_machine_event("test_sm",filter_event_4)

    send_state_machine_event("test_sm",state_machine_event_4)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    reset_column()
end_column()

define_columns({"manager_column"},8)
define_columns({"state_1_col","state_2_col","state_3_col","state_4_col"},0)
local state_column_list = {{"test_state1","state_1_col"},{"test_state2","state_2_col"},{"test_state3","state_3_col"},{"test_state4","state_4_col"},}

local user_data = "feed_test_data"

define_state_machine("test_sm","manager_column",state_column_list, user_data)


define_column("manager_column",false)
    Log_msg('state machine manager starting')

    sms_change_state("test_state4")
    State_event_change({state_1_event},"test_state1")
    State_event_change({state_2_event},"test_state2")
    State_event_change({state_3_event},"test_state3")
    State_event_change({state_4_event},"test_state4")
    State_feed_state("SM_FEED_EVENTS",user_data)
   
    halt_column()
end_column()


define_column("state_1_col",false)
    SM_log('state 1 starting','state_1 is exiting')
    sm_debug_function('test_data_11')
   
    halt_column()
end_column()

define_column("state_2_col",false)
    Log_msg('state 2 starting')
    sm_debug_function('test_data_21')
    halt_column()
end_column()


define_column("state_3_col",false)
    Log_msg('state 3 starting')
    sm_debug_function('test_data_31')
    halt_column()
end_column()


define_column("state_4_col",false)
    Log_msg('state 4 starting')
    SM_sync_events(120)
    sm_debug_function('test_data_41')
    halt_column()
end_column()





dump_build()
