set_h_file("named_queues.h")

local entry_point = "column_queue_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  


local routing_1_header = [[


bool routing_1(void *input, void *params,Event_data_CFL_t *event_data);
]]

local routing_1_code = [[


bool routing_1(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  (void)input;
  (void)params;
  if(event_data->event_index == 100){
    return true;
  }
  if(event_data->event_index == 101){
    return true;
  }
  return false;
}
]]

Store_boolean_function("ROUTING_1",'routing_1',routing_1_code,routing_1_header)


local routing_2_header = [[


bool routing_2(void *input, void *params,Event_data_CFL_t *event_data);
]]

local routing_2_code = [[


bool routing_2(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  (void)input;
  (void)params;
  if(event_data->event_index == 102){
    return true;
  }
  if(event_data->event_index == 103){
    return true;
  }
  return false;
}
]]

Store_boolean_function("ROUTING_2",'routing_2',routing_2_code,routing_2_header)


-- start of user events
set_user_event_start(100)

-- returns the event id
column_event_1_id = add_user_event("column_event_1")
-- returns const event address
column_event_1 = generate_event(get_event("column_event_1"),false, 'NULL')

-- returns the event id
column_event_2_id = add_user_event("column_event_2")
-- returns const event address
column_event_2 = generate_event(get_event("column_event_2"),false, 'NULL')

column_event_3_id = add_user_event("column_event_3")
-- returns const event address
column_event_3 = generate_event(get_event("column_event_3"),false, 'NULL')

-- returns the event id
column_event_4_id = add_user_event("column_event_4")
-- returns const event address
column_event_4 = generate_event(get_event("column_event_4"),false, 'NULL')



local column_list_1 = {"terminate_column","event_generator"}
local column_list_2 = {"event_distributor"}
local column_list_3 = {"event_client_1","event_client_2"}
define_columns(column_list_1,0)
define_columns(column_list_2,4)
define_columns(column_list_3,2)
define_columns( {"idle_column"},0)

define_column("terminate_column",true)
  Wait_delay(12000)
  terminate_engine()
end_column()


define_column("event_generator",true)
 Log_msg("event generator start")
 Wait_delay(2000)
 Log_msg("sending events")
 send_queue_event("event_distributor",column_event_3)
 send_queue_event("event_distributor",column_event_4)
 send_queue_event("event_distributor",column_event_1)
 send_queue_event("event_distributor",column_event_2)
 send_queue_event("idle_column",column_event_2)  -- should not be sent

 Log_msg("done sending events")

 reset_column()
end_column()





define_column("event_distributor",true)
 Log_msg("event distributor start")
 conditional_send_event( "ROUTING_1", {"event_client_1"})
  conditional_send_event( "ROUTING_2", {"event_client_2"})
  halt_column()
end_column()


define_column("event_client_1",true)
  Log_msg("event_client_1")
  display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
  halt_column()
end_column()

define_column("event_client_2",true)
  Log_msg("event_client_2")
  display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
  halt_column()
end_column()


define_column("idle_column",false)
  Log_msg("idle column") -- should not be called
  display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
  halt_column()
end_column()

define_columns( {"push_front_event"},4)
define_column("push_front_event",true)
  Log_msg("push front event")
  display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
  push_front_event(column_event_1)
  push_front_event(column_event_2)
  push_front_event(column_event_3)
  push_front_event(column_event_4)
  halt_column()
end_column()

local residual_display_header = [[
  
  void residual_display(void *input, void *params,Event_data_CFL_t *event_data);
]]

local residual_display_code = [[
  void residual_display(void *input, void *params,Event_data_CFL_t *event_data)
  {
    (void)input;

    char *residual_message = (char *)params;
   
    Printf_CFL(input,"%s residual event index %d\n",residual_message,event_data->event_index);
  }
]]

Store_one_shot_function("RESIDUAL_DISPLAY",'residual_display',residual_display_code,residual_display_header)

Store_user_code([[
  static const char display_message[] = "display_message";
]])


define_columns( {"dump_residual_events"},4)
define_column("dump_residual_events",true)
  Log_msg("dump residual events")
  process_residual_named_event_queue("RESIDUAL_DISPLAY",'(void *)display_message')
  push_front_event(column_event_1)
  push_front_event(column_event_2)
  push_front_event(column_event_3)
  push_front_event(column_event_4)
  terminate_column()
end_column()

dump_build()

