set_h_file("while_column.h")

local entry_point = "while_column_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

Store_user_code([[
static const char* while_message = "This is a test message for while \n";
]])

local test_bool_header = [[

bool while_column_test(void* input, void* params, Event_data_CFL_t* event_data);

]]

local test_bool_code = [[

bool while_column_test(void* input, void* params, Event_data_CFL_t* event_data) {
  (void)input; // unused parameter
  While_column_control_CFL_t* while_control = (While_column_control_CFL_t*)params;
  
  if (event_data->event_index == EVENT_INIT_CFL) {
  
    return false;
  }

 
  const char** message = (const char**)while_control->user_data;
  Printf_CFL(*message); // testing user data
 
  Printf_CFL("number of iterations %d max_iterations 4 \n",*while_control->current_count);
  if (*while_control->current_count >= 4) {
    Printf_CFL("while column is terminating \n");
    return false;
  }
  Printf_CFL("returning true \n");
  return true;
}


]]
Store_boolean_function('while_column_test','while_column_test',test_bool_code,test_bool_header)





column_names = { "test_while", "while_0", "while_1", "while_2" }
define_columns(column_names)
while_columns = { "while_0", "while_1", "while_2" }




define_column( "test_while", true)
  Log_msg( "starting while command")
  while_handler('while_column_test','while_message',while_columns)
  
  Log_msg( "done with while statement")
  terminate_column()
end_column()

define_column( "while_0", false)
  Log_msg( "while_0 should be active")
  Wait_delay( 1000)
  Log_msg( "while_0 is terminating")
  terminate_column()
end_column()

define_column( "while_1", false)
  Log_msg( "while_1 should be active")
  Wait_delay( 2000)
  Log_msg( "while_1 is terminating")
  terminate_column()
end_column()

define_column( "while_2", false)
  Log_msg( "while_2 should be active")
  Wait_delay( 3000)
  Log_msg( "while_2 is terminating")
  terminate_column()
end_column()


dump_build()


