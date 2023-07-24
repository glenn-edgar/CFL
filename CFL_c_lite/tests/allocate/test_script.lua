local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_compiler/"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

set_output("test_script.h")

local entry_point = "test_entry_point"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,allocate_once_heap_size,private_heap_size,default_event_queue_size) 
dump_output('debug_write') 