
--- this test is to test sequence column command



set_h_file("sequence.h")
local entry_point = "sequence_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  



column_names = {"sequence_column","seq_0","seq_1","seq_2"}
sequence_list = {"seq_0","seq_1","seq_2"}
define_columns(column_names)


define_column("sequence_column", true)
  Log_msg("testing sequence columns command")
  Sequence_columns( sequence_list)
  Log_msg("sequence column test is done")
  terminate_column()
end_column()
     

  
define_column( "seq_0", false)
  Log_msg("seq_0 should be active")
  Wait_delay( 2000)
  Log_msg("seq_0 is terminating");
  terminate_column()
end_column()
     

   
define_column( "seq_1", false);
  Log_msg("seq_1 should be active");
  Wait_delay( 1000)
  Log_msg("seq_1 is terminating ");
  terminate_column()
end_column()
            

 
define_column( "seq_2", false);
  Log_msg("seq_2 should not be active");
  Wait_delay( 500 )
  Log_msg("seq_2 is terminating");
  terminate_column()
end_column()
        
dump_build()

----
----  Try command tests
----
----

set_h_file("try.h")
local entry_point = "try_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 



try_column_names = { "try_sequence", "try_fail_true","try_fail_false","try_true_true","try_true_false","try_test_1","try_test_2","try_test_3"}
define_columns(try_column_names)

sequence_list_1 = {"try_fail_true","try_fail_false","try_true_true","try_true_false"}
sequence_list_2 = {"try_test_1","try_test_2","try_test_3"}

define_column("try_sequence", true)
  Log_msg("various try type senarios")
  Sequence_columns( sequence_list_1)
  Log_msg("try test is done")
  terminate_column()
end_column()

define_column("try_fail_true", false)
  Log_msg("try_fail_true should be active")
  Set_column_flag(sequence_list_2, false)
  Display_column_flag(sequence_list_2)
  Set_column_flag({"try_fail_true"}, true)
  Try_columns( false, sequence_list_2)
  Display_column_flag({"try_fail_true"})
  Log_msg("try_fail_true is terminating")
  terminate_column()
end_column()

define_column("try_fail_false", false)
  Log_msg("try_fail_true should be active")
  Set_column_flag(sequence_list_2, true)
  Display_column_flag(sequence_list_2)
  Set_column_flag({"try_fail_false"}, true)
  Try_columns( true, sequence_list_2)
  Display_column_flag({"try_fail_false"})
  Log_msg("try_fail_false is terminating")
  terminate_column()
end_column()

define_column("try_true_true", false)
  Log_msg("try_true_true should be active")
  Set_column_flag(sequence_list_2, true)
  Display_column_flag(sequence_list_2)
  Set_column_flag({"try_true_true"},false)
  Try_columns( false, sequence_list_2)
  Display_column_flag({"try_true_true"})
  Log_msg("try_true_true is terminating")
  terminate_column()
end_column()

define_column("try_true_false", false)
  Log_msg("try_true_false should be active")
  Set_column_flag(sequence_list_2, false)
  Display_column_flag(sequence_list_2)
  Set_column_flag({"try_true_false"}, true)
  Try_columns( true, sequence_list_2)
  Display_column_flag({"try_true_false"})
  Log_msg("try_true_false is terminating")
  terminate_column()
end_column()


define_column( "try_test_1", false)
  Log_msg("try_test_1 is active")
  Wait_delay( 2000)
  Log_msg("try_test_1 is terminating");
  terminate_column()
end_column()
     

   
define_column( "try_test_2", false);
  Log_msg("try_test_2 is active");
  Wait_delay( 1000)
  Log_msg("try_test_2 is terminating ");
  terminate_column()
end_column()
            

 
define_column( "try_test_3", false);
  Log_msg("try_test_3 is active");
  Wait_delay( 500 )
  Log_msg("try_test_3 is terminating");
  terminate_column()
end_column()

dump_build()


set_h_file("assert_column.h")
local entry_point = "assert_column_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 



local assert_columns = {"assert_time_delay","assert_reset_pass","assert_reset_fail","assert_termination","error_column_1","error_column_2","error_column_3"}
local enable_columns = {"assert_reset_pass","assert_reset_fail","assert_termination"}
local error_columns = {"error_column_1" ,"error_column_2","error_column_3"}
define_columns(assert_columns)

define_column("assert_time_delay",true)
    Log_msg("assert_time_delay")
    Enable_columns(enable_columns, true)
    Wait_delay(20000)
    Log_msg("assert_time_delay is terminating")
    terminate_column()
end_column()

define_column("assert_reset_pass",false)
  Log_msg("assert_reset")
  Assert_column( 'TRUE','NULL', false, error_columns)
  Log_msg("assert_reset_pass is terminating")
end_column()
     

define_column("assert_reset_fail",false)
  Log_msg("assert_reset")
  Wait_delay(4500)
  Assert_column( 'FALSE','NULL', false, error_columns)
  Log_msg("assert_reset_fail is terminating")
end_column()

define_column("assert_termination",false)
  Wait_delay(4000)
  Log_msg("assert_termination")
  Assert_column( 'FALSE',"NULL",true, error_columns)
  Log_msg("assert_termination is terminating")
end_column()

define_column("error_column_1",false)
  Log_msg("error_column_1 is active")
  Wait_delay(100)
  Log_msg("error_column_1 is terminating");
  terminate_column()
end_column()

define_column("error_column_2",false)
  Log_msg("error_column_2 is active")
  Wait_delay(100)
  Log_msg("error_column_2 is terminating");
  terminate_column()
end_column()

define_column("error_column_3",false)
  Log_msg("error_column_3 is active")
  Wait_delay(100)
  Log_msg("error_column_3 is terminating");
  terminate_column()
end_column()

dump_build()

set_h_file("assert_column_flag.h")
local entry_point = "assert_column_flag_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 


local assert_flag_columns = {"assert_col_flag_main","test_column_1","test_column_2","mark_column_1","mark_column_2","error_column_1","error_column_2","error_column_3"}
define_columns(assert_flag_columns)

local messages = [[


  static const char should_not_see_message[] = "should not see this message";
  static const char true_message[]= "true message";
  static const char fail_termination_message[] = "fail termination message";  
]]

Store_user_code(messages)

local true_header = [[

bool bool_true_function(const void *input,void *params,Event_data_CFL_t *event_data);

]]

local true_code = [[

bool bool_true_function(const void *input,void *params,Event_data_CFL_t *event_data)
{
    (void)event_data;
    char *message = (char *)params;
  
    Printf_CFL(input,"pass function -> %s \n",message);
    return true;  

}
]]

Store_boolean_function("TEST_TRUE","bool_true_function",true_code,true_header)

local false_header = [[

bool bool_false_function(const void *input,void *params,Event_data_CFL_t *event_data);

]]

local false_code = [[

bool bool_false_function(const void *input,void *params,Event_data_CFL_t *event_data)
{
    (void)event_data;
    char *message = (char *)params;
    
    Printf_CFL(input,"failure function -> %s \n",message);
    return false;  

}
]]

Store_boolean_function("TEST_FALSE","bool_false_function",false_code,false_header)

define_column("assert_col_flag_main",true)
  Log_msg("main column is active")
  Set_column_flag({"mark_column_1"}, true)
  Set_column_flag({"mark_column_2"}, false)
  Enable_columns({"test_column_1"},false)
  Join_columns({"test_column_1"})
  Enable_columns({"test_column_2"},true)
  Wait_delay(10000)
  Log_msg("main column is terminating")
  terminate_column()
end_column()

define_column("test_column_1",false)
  Log_msg("test_column_1 is active")
  Assert_flag("mark_column_1",true,"TEST_TRUE" ,"should_not_see_message", false, {"error_column_1","error_column_2","error_column_3"} ) 
  Log_msg("this test should pass")
  Assert_flag("mark_column_1",false,"TEST_TRUE" , "true_message",false, {"error_column_1","error_column_2","error_column_3"} )
  Log_msg("this test should pass")
  Assert_flag("mark_column_1",false,"TEST_FALSE" ,"fail_termination_message", true, {"error_column_1","error_column_2","error_column_3"} )
  Log_msg("should not see this log message")
  terminate_column()
end_column()

define_column("test_column_2",false)
  Log_msg("test_column_2 is active with reset flag option")
  Wait_delay(1000)
  Assert_flag("mark_column_2",true,"TEST_FALSE" ,"fail_termination_message", false, {} ) 
  Log_msg("should not see this log message")
  terminate_column()
end_column()

define_column("mark_column_1",false)
  Log_msg("test_column_1 is active")
  Wait_delay(100)
  Log_msg("test_column_1 is terminating");
  terminate_column()
end_column()

define_column("mark_column_2",false)
  Log_msg("test_column_2 is active")
  Wait_delay(100)
  Log_msg("test_column_2 is terminating");
  terminate_column()
end_column()




define_column("error_column_1",false)
  Log_msg("error_column_1 is active")
  Wait_delay(100)
  Log_msg("error_column_1 is terminating");
  terminate_column()
end_column()

define_column("error_column_2",false)
  Log_msg("error_column_2 is active")
  Wait_delay(100)
  Log_msg("error_column_2 is terminating");
  terminate_column()
end_column()

define_column("error_column_3",false)
  Log_msg("error_column_3 is active")
  Wait_delay(100)
  Log_msg("error_column_3 is terminating");
  terminate_column()
end_column()

dump_build()