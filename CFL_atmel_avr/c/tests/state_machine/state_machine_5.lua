set_h_file("state_machine_5.h")
local entry_point = "state_machine_5_handle"


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
-- returns the event id
filter_event_id = 200
-- returns const event address
filter_event = generate_event(200,false, 'NULL')

state_change_event_id = 201
filter_event = generate_event(200,false, 'NULL')
state_change_event = generate_event(201,false, 'NULL')




-- returns const event address







reserve_state_machines({"test_sm"})
define_columns({"start_column","event_generator"})

local message = [[

const char test_data_15[] = "state 1 debug message";
const char test_data_25[] = "state 2 debug message";
const char test_data_35[] = "state 3 debug message";
const char test_data_45[] = "state 4 debug message";
]]
Store_user_code(message)



define_column("start_column",true,nil)
    Log_msg('start column')
    enable_disable_sms({"test_sm"})
    Enable_columns({"event_generator"},true)
    Wait_delay(120000)
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
    Wait_delay(5000)
    send_state_machine_event("test_sm",filter_event)
    send_state_machine_event("test_sm",state_change_event)

    Wait_delay(30000  )
    reset_column()
end_column()

local state_list = {"test_state1","test_state2","test_state3","test_state4"}
local queue_name = "test_sm_queue"
local queue_size = 10

define_state_machine("test_sm",state_list,queue_name,queue_size,'NULL')



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
    sm_debug_function('test_data_15')
   
    halt_column()
end_column()

define_state("test_state2")
    Log_msg('state 2 starting')
    sm_debug_function('test_data_25')
    halt_column()
end_column()


define_state("test_state3")
    Log_msg('state 3 starting')
    sm_debug_function('test_data_35')
    halt_column()
end_column()


define_state("test_state4")

 Log_msg("executing a sequence of actions first")
 Log_msg("action 1")
 Wait_delay(1000)
 Log_msg("action 2")
 Wait_delay(1000)
 Log_msg("action 3")
 Change_column_state(0) -- setting initial state
 Log_msg("state machines are active at this point")
 --- these are event filters
 store_column_element('filter_event_1','NULL',"(void *)&filter_event_data_1")
  
 
 
 store_column_element('sm_0','NULL',"(void *)&sm_0_data")
 Set_column_state_machine_start()
 store_column_element('sm_1','NULL',"(void *)&sm_1_data")
 store_column_element('sm_2','NULL',"(void *)&sm_2_data")
 store_column_element('sm_3','NULL',"(void *)&sm_3_data")
 Set_column_state_machine_end()
 Log_msg("end step")
 halt_column()

end_column()

end_state_machine()


local filter_event_code = [[

static const char filter_event_data_1[] = "filter_event_data_1";



static int filter_event_1(const void *input,void *aux_fn,void *param,Event_data_CFL_t *event)
{
   (void)aux_fn;
   (void)param;
   (void)input;
  if( event->event_index == EVENT_INIT_CFL){
    
    Printf_CFL("filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    Printf_CFL("filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == <<p, filter_event >>){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  

if(event->event_index == <<p, sm_change_event >>){
    
  Printf_CFL("change state received doing changing column state to 3 \n");
  
  change_local_column_state_CFL(input,3);
  return HALT_CFL;

}
return CONTINUE_CFL;
}

]]

reset_template_tables()
variable_table["filter_event"] = filter_event_id
variable_table["sm_change_event"] = state_change_event_id
local expanded_code = Expand_text_stream(filter_event_code)
Store_user_code(expanded_code)

local sm_template_code = [[
    static unsigned <<p,name >>_data;
    static int <<p,name >>(const void *input,void *aux_fn,void *param, Event_data_CFL_t *event)
{
   (void)aux_fn;

   unsigned *count = (unsigned *)param;

  if( event->event_index == EVENT_INIT_CFL){
    Printf_CFL("<<p,name >> initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    
    *count = *count + 1;
   
    if(*count >=  5){
      
      change_local_column_state_CFL(input, <<p,state>>);
       return HALT_CFL;
    }
    return CONTINUE_CFL;
  
  }
  
  return CONTINUE_CFL;
}

]]

reset_template_tables()
variable_table["name"] = 'sm_0'
variable_table["state"] = 1
local expanded_code = Expand_text_stream(sm_template_code)
Store_user_code(expanded_code)

reset_template_tables()
variable_table["name"] = 'sm_1'
variable_table["state"] = 2
local expanded_code = Expand_text_stream(sm_template_code)
Store_user_code(expanded_code)

reset_template_tables()
variable_table["name"] = 'sm_2'
variable_table["state"] = 3
local expanded_code = Expand_text_stream(sm_template_code)
Store_user_code(expanded_code)

reset_template_tables()
variable_table["name"] = 'sm_3'
variable_table["state"] = 0
local expanded_code = Expand_text_stream(sm_template_code)
Store_user_code(expanded_code)







dump_build()
