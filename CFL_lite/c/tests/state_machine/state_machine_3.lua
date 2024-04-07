set_h_file("state_machine_3.h")
local entry_point = "state_machine_3_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 

local message = string.format('const char test_data_2b[] = "%s\\n";\n',"test_data")
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




-- returns const event address
local user_case_event_header = [[

int user_case_event(const void *input, void* params, Event_data_CFL_t* event_data, bool *continue_flag);


]]

local user_case_event_code = [[

int user_case_event(const void *input, void* params, Event_data_CFL_t* event_data, bool *continue_flag)
{
    (void)input;
    (void)params;
    int return_value = -1;
    int event_id = event_data->event_id;
    switch(event_id)
    {
        case 101:
            return_value = 0;
            continue_flag = false;
            break;

        case 102:
            return_value = 1;
            continue_flag = false;
            break;

        case 103:
            return_value = 2;
            continue_flag = false;
            break;

        case 104:
            return_value = 3;
            continue_flag = false;
            break;
        
        default;
            return_value = -1;
            continue_flag = true;
            break;
    }
    return return_value;
}

]]




Store_state_function("USER_CASE_EVENT", "user_case_event", user_case_event_code,user_case_event_header)



local feed_events_header = [[

typedef struct Feed_events_test_data_a_t
{
    const char *debug_message;

} Feed_events_test_data_a_t;


bool feed_events_test_a(const void *input, void* params, Event_data_CFL_t* event_data);
]]

local feed_events_code = [[

bool feed_events_test_a(const void *input, void* params, Event_data_CFL_t* event_data)
{

    (void)input;
    (void)event_data;
    (void)params;
    //Feed_events_test_data_a_t *feed_events_test_data = (Feed_events_test_data_a_t *)params;
  
    
    return true;
}

]]

Store_boolean_function("SM_FEED_EVENTS_A", "feed_events_test_a", feed_events_code,feed_events_header)

local user_case_event_header = [[
typedef struct Case_change_test_data_t
{
    const char *debug_message;
    
} Case_change_test_data_t;
    
int case_change_test(const void *input, void* params, Event_data_CFL_t* event_data, bool *continue_flag);
]]


local user_case_event_code = [[
int case_change_test(const void *input, void* params, Event_data_CFL_t* event_data, bool *continue_flag)
{

  
    Case_change_test_data_t *case_change_data = (Case_change_test_data_t *)params;
    *continue_flag = true;
    int event_id = event_data->event_index;
    switch(event_id)
    {
        case 101:
            return 0;
            *continue_flag = false;
            break;
        case 102:
            return 1;
            *continue_flag = false;
            break;
        case 103:
            return 2;
            *continue_flag = false;
            break;
        case 104:
            return 3;
            *continue_flag = false;
            break;
      
        case 114:
            Printf_CFL(input,case_change_data->debug_message);
            Printf_CFL(input," .............. event 114 processed here \n");
            *continue_flag = false;
            return -1;
            break;
        default:
            return -1;
            break;
        }
        return -1;
    }



]]

Store_state_function("CASE_STATE_CHANGE_TEST", "case_change_test", user_case_event_code,user_case_event_header)


reserve_state_machines({"test_sm"})
define_columns({"start_column","event_generator"})

local message = [[

static const char test_data_11a[] = "state 1 debug message";
static const char test_data_21a[] = "state 2 debug message";
static const char test_data_31a[] = "state 3 debug message";
static const char test_data_41a[] = "state 4 debug message";



const Feed_events_test_data_t feed_test_data_1a = {
    .debug_message = "debug message for case construct"
};
const Feed_events_test_data_t feed_test_data_2a= {
    .debug_message = "debug message for feed events"
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
local state_column_list = {{"test_state1","state_1_col"},{"test_state2","state_2_col"},{"test_state3","state_3_col"},{"test_state4","state_4_col"}}

Store_user_code([[
const Feed_events_test_data_t feed_test_data_a = {
    .debug_message = "feed event 2 debug message"
};
]])


local user_data = "feed_test_data_a"


local user_data_1 = "feed_test_data_1a"
local user_data_2 = "feed_test_data_2a"

define_state_machine("test_sm","manager_column",state_column_list, user_data)


define_column("manager_column",false)
    Log_msg('state machine manager starting')

    sms_change_state("test_state4")
    Sm_case_change_function("CASE_STATE_CHANGE_TEST",user_data_1)
    State_feed_state("SM_FEED_EVENTS_A",user_data_2)
   
    halt_column()
end_column()


define_column("state_1_col",false)
    SM_log('state 1 starting','state_1 is exiting')
    sm_debug_function('test_data_11a')
   
    halt_column()
end_column()

define_column("state_2_col",false)
    Log_msg('state 2 starting')
    sm_debug_function('test_data_21a')
    halt_column()
end_column()


define_column("state_3_col",false)
    Log_msg('state 3 starting')
    sm_debug_function('test_data_31a')
    halt_column()
end_column()


define_column("state_4_col",false)
    Log_msg('state 4 starting')
    SM_sync_events(120)
    sm_debug_function('test_data_41a')
    halt_column()
end_column()





dump_build()
