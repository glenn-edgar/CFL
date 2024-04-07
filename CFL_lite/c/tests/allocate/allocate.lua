

local entry_point = 'allocate_entry_point'
local allocate_once_memory_ptr = 'allocate_once_memory'
local debug_write_fn = 'debug_write'
local allocate_once_heap_size = 2000
local private_heap_size = 1000
local global_event_queue_size = 10
local default_event_queue_size = 10 
set_h_file("allocate.h")
start_build(entry_point,allocate_once_memory_ptr,allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,debug_write_fn ) 
dump_build()
dump_runtime_support()