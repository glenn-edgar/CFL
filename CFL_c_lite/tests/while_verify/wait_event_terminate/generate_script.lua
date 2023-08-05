local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../../lua_compiler/"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

local wait_event_terminate_fn_header = [[

void wait_event_terminate(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local wait_event_terminate_fn_code = [[

void wait_event_terminate(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   While_event_control_ROM_t *while_event_control = (While_event_control_ROM_t *)params;
   char *message = (char *)while_event_control->user_data;
  
  Printf_CFL("\n\n *************** Terminate function ---   %s\n\n",message);  
 
  
}
]]

Store_one_shot_function("WAIT_EVENT_TERMINATE",'wait_event_terminate',wait_event_terminate_fn_code,wait_event_terminate_fn_header)

local user_code = [[


void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}

static const char wait_event_terminate_message[] = "wait event terminate function called\n";
]]



Store_user_code(user_code)


set_output("test_script.h")

local entry_point = "test_entry_point"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,allocate_once_heap_size,private_heap_size,default_event_queue_size)  

-- start of user events
set_user_event_start(100)


-- returns the event id
test_event_id = add_user_event("test_event","test_event")

-- returns const event address
test_def = generate_event("user_test_event",get_event("test_event"),false, 'NULL')


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
   Log_msg("this column will terminate because not enough time to receive 10 events")
   Wait_event(test_event_id,10,9000,false, "WAIT_EVENT_TERMINATE", 'wait_event_terminate_message')
   Log_msg("10 events have been received")
   Log_msg("stopping engine")
   terminate_column()
end_column()

dump_output('debug_write')
   


  

