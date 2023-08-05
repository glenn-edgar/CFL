local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../../lua_compiler/"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

local user_code = [[


void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}


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


local column_list = {"generate_event","wait_event"}
define_columns(column_list)

define_column("generate_event",true,nil)
   Log_msg("this column will generate an event every second")
   Wait_delay(1000)
   send_global_event(test_def)
   Log_msg("sending event")
   reset_column()
end_column()


define_column("wait_event",true,nil)
   Log_msg("this column will wait for to events and then stop the engine")
   -- termination will occur after 11 seconds which should not happen
   Wait_event(test_event_id,10, 11000, true, 'NULL', 'NULL')
   Log_msg("10 events have been received")
   Log_msg("stopping engine")
   terminate_engine()
end_column()

dump_output('debug_write')
   


  

