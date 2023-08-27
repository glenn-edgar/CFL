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

char *allocate_once_memory = NULL;

void create_allocate_once_heap(){
    allocate_once_memory = (char *)malloc(2000);
}

void free_allocate_once_heap(){
    free(allocate_once_memory);
}

]]

Store_user_code(user_code)


set_output("test_script.h")

local entry_point = "test_entry_point"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size)  


local column_list = {"terminate_engine","reset_loop"}
define_columns(column_list)

define_column("terminate_engine",true,nil)
   Log_msg("this column will terminate the engine after 10 seconds")
   Wait_delay(10000)
   Log_msg("time delay done")
   Log_msg("stop engine")
   terminate_engine()
end_column()


define_column("reset_loop",true,nil)
   Log_msg("this column will reset the engine every 2 seconds")
   Wait_delay(2000)
   Log_msg("two seconds past-- reset column")
   reset_column()
end_column()

dump_output('debug_write')
   


  

