

set_h_file("state_machine_3.h")
local entry_point = "state_machine_3_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')


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


local sm_conditional_state_change_header = [[

typedef struct condition_state_change_t{
   unsigned short trigger_event;
   unsigned short trigger_count_limit;
   unsigned short *trigger_count;
}condition_state_change_t;

bool conditional_state_change(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local sm_conditional_state_change_body = [[

bool conditional_state_change(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    condition_state_change_t *condition_state_change = (condition_state_change_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        *condition_state_change->trigger_count = 0;
        return false;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return false;

    }
    if(event_data->event_index == condition_state_change->trigger_event){
        *condition_state_change->trigger_count = *condition_state_change->trigger_count + 1;
        if(*condition_state_change->trigger_count >= condition_state_change->trigger_count_limit){
            return true;
        }
    }
    return false;

}

]]

Store_boolean_function('conditional_state_change_fn','conditional_state_change',sm_conditional_state_change_body,sm_conditional_state_change_header)


Store_user_code([[
#define state_1_event 101
unsigned short test_counter = 0;
const condition_state_change_t bool_state_change = {state_1_event,3,&test_counter};

]])




reserve_state_machines({"test_sm"})
define_columns({"start_column","event_generator"})

local message = [[

const char test_data_12[] = "state 1 debug message";
const char test_data_22[] = "state 2 debug message";
const char test_data_32[] = "state 3 debug message";
const char test_data_42[] = "state 4 debug message";
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
    Wait_delay(1000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_2)
    Wait_delay(1000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_3)
    Wait_delay(1000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_4)
    Wait_delay(1000)
    send_state_machine_event("test_sm",filter_event_1)
    send_state_machine_event("test_sm",filter_event_2)
    send_state_machine_event("test_sm",filter_event_3)

    send_state_machine_event("test_sm",state_machine_event_1)
    reset_column()
end_column()

local state_list = {"test_state1","test_state2","test_state3","test_state4"}
local queue_name = "test_sm_queue"
local queue_size = 10

define_state_machine("test_sm",state_list,queue_name,queue_size,'NULL')





define_add_manager_chain()
    Log_msg('state machine manager starting')

    change_state("test_state1")
    redirect_event("TRUE","NULL")
   
    halt_column()
end_column()


define_state("test_state1")
    Log_msg('state 1 starting')
    state_change({state_2_event},"test_state2")
    sm_debug_function('test_data_12')
    
    halt_column()
end_column()

define_state("test_state2")
    Log_msg('state 2 starting')
    state_change({state_3_event},"test_state3")
    sm_debug_function('test_data_22')
    halt_column()
end_column()


define_state("test_state3")
    Log_msg('state 3 starting')
    sm_debug_function('test_data_32')
    state_change({state_4_event},"test_state4")
    
    halt_column()
end_column()


define_state("test_state4")
    Log_msg('state 4 starting')
    Activate_boolean_function('conditional_state_change_fn')
    conditional_state_change('conditional_state_change_fn','bool_state_change','test_state1')
    sm_debug_function('test_data_42')
    halt_column()
end_column()



end_state_machine()

dump_build()
