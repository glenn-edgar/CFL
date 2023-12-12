set_h_file("named_queues.h")

local entry_point = "named_queue_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

-- start of user events
set_user_event_start(100)

-- returns the event id
filter_event_id = add_user_event("filter_event")
-- returns const event address
filter_event = generate_event(get_event("filter_event"),false, 'NULL')

state_change_event_id = add_user_event("state_change_event")
state_change_event = generate_event(get_event("state_change_event"),false, 'NULL')

define_named_queue("queue1",10) 

local column_list = {"terminate_column","event_generator","test_sm_structure"}
define_columns(column_list)

define_column("terminate_column",true,nil)
  Wait_delay(120000)
  terminate_engine()
end_column()


define_column("event_generator",true,nil)
 Log_msg("event generator start")
 Wait_delay(15000)
 send_queue_event("queue1",filter_event)
 send_queue_event("queue1",state_change_event)
 reset_column()
end_column()






define_column("test_sm_structure",true,"queue1")
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




local filter_event_code = [[

static const char filter_event_data_1[] = "filter_event_data_1";



static int filter_event_1(const void *input,void *aux_fn,void *param,Event_data_CFL_t *event)
{
   (void)aux_fn;
   (void)param;
  if( event->event_index == EVENT_INIT_CFL){
    
    Printf_CFL("filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    Printf_CFL("filter_event_1 termination event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == <<p, filter_event >>){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  if(event->event_index == <<p, sm_change_event >>){
    
    Printf_CFL("filter event 2 received doing changing column state to 3 \n");
    change_local_column_state_CFL(input, 3);
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
   
    if(*count >=  3){
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

