set_h_file("wait_event_reset.h")

local entry_point = "wait_event_reset_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7

start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  


local wait_event_reset_fn_header = [[

void wait_event_reset_b(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local wait_event_reset_fn_code = [[

void wait_event_reset_b(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   While_event_control_ROM_t *while_event_control = (While_event_control_ROM_t *)params;
   unsigned number_of_events = while_event_control->number_of_events;
   unsigned count = *while_event_control->current_count;
  
   Printf_CFL(input,"\n\n *************** Reset function ---  event count %d current count %d\n\n",number_of_events,count);
  
   char *message = (char *)while_event_control->user_data;
  
  Printf_CFL(input,"\n\n *************** Reset function ---   %s\n\n",message);  
 
  
}
]]

Store_one_shot_function("WAIT_EVENT_RESET_A",'wait_event_reset_b',wait_event_reset_fn_code,wait_event_reset_fn_header)

Store_user_code([[


static const char wait_event_reset_message_a[] = "wait event reset function called\n";


]])



Store_user_code(user_code)


 

-- start of user events
set_user_event_start(100)


-- returns the event id
test_event_id = add_user_event("test_event")

-- returns const event address
test_def = generate_event(get_event("test_event"),false, 'NULL')


local column_list = {"termination_engine","generate_event","wait_event"}
define_columns(column_list)

define_column("termination_engine",true,nil)
   Log_msg("this column will terminate the engine")
   Wait_delay(11000)
   Log_msg("stopping engine because 11 seconds have passed")
   terminate_engine()
end_column()


define_column("generate_event",true,nil)
   Log_msg("this column will generate an event every second")
   Wait_delay(1000)
   send_global_event(test_def)
   Log_msg("sending event")
   reset_column()
end_column()


define_column("wait_event",true,nil)
   Log_msg("wait event is column is starting")
   Log_msg("this column will reset because not enough time to receive 10 events")
   Wait_event(test_event_id,10,9000,false, "WAIT_EVENT_RESET_A", 'wait_event_reset_message_a')
   Log_msg("10 events have been received")
   Log_msg("stopping engine")
   terminate_column()
end_column()

dump_build()
   


  

