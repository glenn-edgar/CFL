set_h_file("column_events.h")

local entry_point = "column_events_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  


set_user_event_start(100)

-- returns the event id
column_event_1_name = add_user_event("column_event_1")
-- returns const event address
column_event_1 = generate_event(get_event("column_event_1"),false, 'NULL')
column_event_1_id = get_event_number("column_event_1")


-- returns the event id
column_event_2_name = add_user_event("column_event_2")
-- returns const event address
column_event_2 = generate_event(get_event("column_event_2"),false, 'NULL')
column_event_2_id = get_event_number("column_event_2")

column_event_3_name = add_user_event("column_event_3")
-- returns const event address
column_event_3 = generate_event(get_event("column_event_3"),false, 'NULL')
column_event_3_id = get_event_number("column_event_3")
-- returns the event id
column_event_4_name = add_user_event("column_event_4")
-- returns const event address
column_event_4 = generate_event(get_event("column_event_4"),false, 'NULL')
column_event_4_id = get_event_number("column_event_4")
local routing_template = [[


bool routing_<<p,name>>(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  (void)input;
  (void)params;
  <<dump_events,event_list>>
  return false;
}
]]

function print_events(event_list)
  
   local return_value = {}
  for i = 1, #event_list do
   
    table.insert(return_value,"   if(event_data->event_index == "..event_list[i].."){")
    table.insert(return_value,"      return true;")
    table.insert(return_value,"   }")
  end
  return table.concat(return_value,"\n")
end


local routing_1_header = [[


bool routing_1(void *input, void *params,Event_data_CFL_t *event_data);
]]


reset_template_tables()
variable_table["name"] = '1'
variable_table["event_list"] = {column_event_1_id ,column_event_2_id }

function_table['dump_events'] = print_events
local routing_1_code = Expand_text_stream(routing_template)

Store_boolean_function("ROUTING_1",'routing_1',routing_1_code,routing_1_header)





local routing_2_header = [[


bool routing_2(void *input, void *params,Event_data_CFL_t *event_data);
]]


reset_template_tables()
variable_table["name"] = '2'
variable_table["event_list"] = {column_event_4_id ,column_event_3_id }
function_table['dump_events'] = print_events
local routing_2_code = Expand_text_stream(routing_template)

Store_boolean_function("ROUTING_2",'routing_2',routing_2_code,routing_2_header)





-- start of user events




local column_list_1 = {"terminate_column","event_generator"}
local column_list_2 = {"event_distributor"}
local column_list_3 = {"event_client_1","event_client_2"}
define_columns(column_list_1,0)
define_columns(column_list_2,4)
define_columns(column_list_3,2)

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
  display_event( {column_event_1_name,column_event_2_name,column_event_3_name,column_event_4_name})
  halt_column()
end_column()

define_column("event_client_2",true)
  Log_msg("event_client_2")
  display_event( {column_event_1_name,column_event_2_name,column_event_3_name,column_event_4_name})
  halt_column()
end_column()

dump_build()

