

set_h_file("basic_control.h")

local entry_point = "basic_control_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')


local column_list = {'enable_no_terminate','enable_terminate',"enable_terminate_test_column",'enable_reset_test_column',
                     'disable_column_test',"column_to_disable",
                     'test_join','delay_terminate'}


define_columns(column_list)


--
-- Testing the enable instruction
--
define_column("enable_no_terminate",true)
    Log_msg("will enable column and terminate")
    Enable_columns({'enable_terminate'},false)
    
    Log_msg("timer is done")
    terminate_column()
end_column()


--- this column will enable enable_terminate_test_column and then terminate
--- when the the column enable_terminate_test_column terminates the column will terminate
--- due to the true flag
define_column('enable_terminate',false)
    Log_msg('will enable columns and wait 15 seconds and terminate')
    Enable_columns({'enable_reset_test_column','enable_terminate_test_column'},true)
    Wait_delay(5000)
    Enable_columns({'enable_reset_test_column'},true)
    Wait_delay(11000)
    Log_msg('timer is done')
    terminate_column()
end_column()

define_column("enable_terminate_test_column",false)
    Log_msg("will wait 5 seconds and reset")
    Wait_delay(5000)
    reset_column()
end_column()

define_column("enable_reset_test_column",false)
    Log_msg("when reset happend this message will be seen")
    Wait_delay(17000)
    Log_msg("this message should not be seen")
    reset_column()
end_column()    
--
--
-- Testing the disable instruction
--
--


define_column('disable_column_test',true)
    Enable_columns({"column_to_disable"},false) 
    Log_msg("will disable reset column after 12 seconds")
    Wait_delay(12000)
    Disable_columns({"column_to_disable"})  
    Log_msg('Now will wait till enable_terminate column terminates this column')
    Wait_delay(1000)  -- wait to observe result 
    terminate_column()
end_column()
  
define_column("column_to_disable",false)
    Log_msg("will wait 5 seconds and reset")
    Wait_delay(5000)
    reset_column()
end_column()
  
---
---
--- Testing the join instruction
---
---


define_column('test_join',true)
    Enable_columns({'delay_terminate'},false)
    Log_msg("waiting for join")
    Join_columns({'delay_terminate'},true)
    Log_msg("Column has been joined")
    terminate_column()
end_column()  

define_column('delay_terminate',false)
    Log_msg("will wait 5 seconds and terminate")
    Wait_delay(5000)
    Log_msg("timer is done")
    terminate_column()
end_column()

dump_build()























--[[

Def_columns('column_names',column_names)
  
  

 Start_engine( 100, 30, 'default_idle_function', 'default_calendar_function')

  Destroy_engine('done with test_enable_disable_columns')




  Start_function('test_join_columns_terminate')


  column_names = quote_list( {"test_join", "delay_terminate" })
  delay_terminate = quote_list( {"delay_terminate" })

  Conf_engine('config_handle','50000','2500')
  Def_columns('column_names',column_names)
  
  Start_column('test_join',true)
  Enable_columns('delay_terminate_enable',delay_terminate,false)
  Log_msg("waiting for join")
  Join_columns('delay_terminate_join',delay_terminate,true)
  Log_msg("Column has been joined")
  Term_column()
  End_column()
  
  Start_column('delay_terminate',false)
  Log_msg("will wait 5 seconds and terminate")
  Wait_delay(5000)
  Log_msg("timer is done")
  Term_column()
  End_column()
  
  Start_engine( 100, 30, 'default_idle_function', 'default_calendar_function')
  Destroy_engine('done with test_join_columns_terminate')
  
Start_function('test_join_columns_no_terminate')

  
  column_names = quote_list( {"launch_column","test_join", "delay_terminate" })
  delay_terminate = quote_list( {"delay_terminate" })
  test_join       = quote_list( {"test_join"})
  
  Conf_engine('config_handle','50000','2500')
  Def_columns('column_names',column_names)
  
  Start_column('launch_column',true)
  Enable_columns('test_join',test_join,true)
  Log_msg("Waiting for 15 seconds")
  Wait_delay(15000)
  Log_msg("15 seconds is up")
  Log_msg("Disabling Column")
  Term_column()
  End_column()
  

  Start_column('test_join',false)
  Enable_columns('delay_terminate_enable',delay_terminate,false)
  Log_msg("waiting for join")
  Join_columns('delay_terminate_join',delay_terminate,true)
  Log_msg("Column has been joined")
  Term_column()
  End_column()
  
  Start_column('delay_terminate',false)
  Log_msg("will wait 5 seconds and terminate")
  Wait_delay(5000)
  Log_msg("timer is done")
  Term_column()
  End_column()
  
  Start_engine( 100, 30, 'default_idle_function', 'default_calendar_function')
  Destroy_engine('done with test_join_columns_no_terminate')








]]