
set_h_file("try_1.h")
local entry_point = "try_1_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')



test_try_function_header =[[

static const char user_data[] = "This is a test message for try \n";
void test_try_function(void* input, Try_column_CFL_t* try_control);

]]

test_try_function_code=[[
void test_try_function(void* input, Try_column_CFL_t* try_control) {
  (void)input; // unused parameter
  Try_function_RAM_t* try_ram = try_control->ram_data;
   Printf_CFL("%s final state %d column index %d \n", __func__,
    try_ram->final_state, try_ram->current_column_index);
   Printf_CFL("user data %s\n", try_control->user_data);
}
]]

Store_try_function("TEST_TRY",'test_try_function', test_try_function_code,test_try_function_header)
column_names = {"try_column","try_0","try_1","try_2"}
define_columns(column_names)

try_column_list = {"try_0","try_1","try_2"}

define_column("try_column", true)
  Log_msg("test where there is success in one of the try columns")
  Log_msg("try column is active")
  try_handler("TEST_TRY",try_column_list,false,'user_data')
  Log_msg("try column is done")
  terminate_column()
end_column()
     

  
define_column( "try_0", false)
  Log_msg("try_0 should be active")
  Wait_delay( 2000)
  Log_msg("try_0 is terminating with failure");
  set_column_return_code(false)
  terminate_column()
end_column()
     

   
define_column( "try_1", false);
  Log_msg("try_1 should be active");
  Wait_delay( 2000)
  Log_msg("try_1 is terminating with success");
  set_column_return_code(true)
  terminate_column()
end_column()
            

 
define_column( "try_2", false);
  Log_msg("try_2 should not be active");
  Wait_delay( 2000)
  Log_msg("try_2 is terminating");
  set_column_return_code(false)
  terminate_column()
end_column()
        
dump_build()


set_h_file("try_2.h")
local entry_point = "try_2_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')


column_names = {"try_column","try_0","try_1","try_2"}
define_columns(column_names)

try_column_list = {"try_0","try_1","try_2"}

define_column("try_column", true)
  Log_msg("test when all try columns  fail")
  Log_msg("try column is active")
  try_handler("TEST_TRY",try_column_list,false,'user_data')
  Log_msg("try column is done")
  terminate_column()
end_column()
define_column( "try_0", false)
  Log_msg("try_0 should be active")
  Wait_delay( 2000)
  Log_msg("try_0 is terminating with failure");
  set_column_return_code(false)
  terminate_column()
end_column()
     

   
define_column( "try_1", false);
  Log_msg("try_1 should be active");
  Wait_delay( 2000)
  Log_msg("try_1 is terminating with success");
  set_column_return_code(false)
  terminate_column()
end_column()
            

 
define_column( "try_2", false);
  Log_msg("try_2 should not be active");
  Wait_delay( 2000)
  Log_msg("try_2 is terminating");
  set_column_return_code(false)
  terminate_column()
end_column()
        
dump_build()
     

set_h_file("try_3.h")
local entry_point = "try_3_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')


column_names = {"try_column","try_0","try_1","try_2"}
define_columns(column_names)

try_column_list = {"try_0","try_1","try_2"}

define_column("try_column", true)
  Log_msg("test when all try columns  fail")
  Log_msg("try column is active")
  try_handler("TEST_TRY",try_column_list,true,'user_data')
  Log_msg("try column is done")
  terminate_column()
end_column()
define_column( "try_0", false)
  Log_msg("try_0 should be active")
  Wait_delay( 2000)
  Log_msg("try_0 is terminating with failure");
  set_column_return_code(true)
  terminate_column()
end_column()
     

   
define_column( "try_1", false);
  Log_msg("try_1 should be active");
  Wait_delay( 2000)
  Log_msg("try_1 is terminating with success");
  set_column_return_code(true)
  terminate_column()
end_column()
            

 
define_column( "try_2", false);
  Log_msg("try_2 should not be active");
  Wait_delay( 2000)
  Log_msg("try_2 is terminating");
  set_column_return_code(false)
  terminate_column()
end_column()
        
dump_build()
     


