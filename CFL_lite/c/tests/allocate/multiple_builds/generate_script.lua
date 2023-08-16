local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../../lua_compiler/"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)






local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 

set_h_file("build_1.h")
local entry_point = "test_entry_point_1"

start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write') 
dump_build()


set_h_file("build_2.h")
local entry_point = "test_entry_point_2"

start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write') 
dump_build()

dump_runtime_support()
