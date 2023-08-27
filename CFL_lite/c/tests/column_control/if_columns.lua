--[[

Start_engine( 100, 30, 'default_idle_function', 'default_calendar_function')
Destroy_engine('Engine Done\\n')

Start_function('test_if_columns_terminate_case')
 
  Conf_engine('config_handle','50000','2500')
  
  column_names = quote_list({ "early_termination", "if_column", "test_if_0",
                                "test_if_1",         "test_if_2", "test_if_3",
                                "test_if_4",         "test_if_5" } )


  if_columns = quote_list({ "test_if_0", "test_if_1", "test_if_2",
                              "test_if_3", "test_if_4", "test_if_5" })

  early_termination_column_names = quote_list({ "if_column" })


Def_columns('column_names',column_names)
Store_if_function("local_if_function", 'test_if_function')

Start_column("early_termination", true)
  Log_msg( "test to set that if_column cleans up sub chains on termination")
  Log_msg( "early_termination is active")
  Enable_columns('early_termination_column_names',early_termination_column_names,true)  
  Wait_delay(  1000)
  Log_msg( "early_termination is terminating")
  Term_column()
End_column()

Start_column("if_column", false)
  Log_msg( "if column is active")
  If_columns('local_if_function','if_column_name',if_columns,'NULL','NULL')
  Log_msg( "if column is done")
  Term_column()
End_column()

Start_column("test_if_0", false)
  Log_msg( "test_if_0 should be active")
  Log_msg( "will wait 2 seconds and terminate")
  Wait_delay(  2000)
  Log_msg( "test_if_0 is terminating")
  Term_column()
End_column()

Start_column("test_if_1", false)
  Log_msg( "test_if_1 should not be active")
  Log_msg( "will wait 3 seconds and terminate")
  Wait_delay(  3000)
  Log_msg( "test_if_1 is terminating")
  Term_column()
End_column()

Start_column("test_if_2", false)
  Log_msg( "test_if_2 should be active")
  Log_msg( "will wait 4 seconds and terminate")
  Wait_delay(  4000)
  Log_msg( "test_if_2 is terminating")
  Term_column()
End_column()

Start_column("test_if_3", false)
  Log_msg( "test_if_0 should not be active")
  Log_msg( "will wait 5 seconds to ")
  Wait_delay(  5000)
  Log_msg( "test_if_3 is terminating")
  Term_column()
End_column()

Start_column("test_if_4", false)
  Log_msg( "test_if_4 should be active")
  Log_msg( "will wait 6 seconds and terminate")
  Wait_delay(  6000)
  Log_msg( "test_if_4 is terminating")
  Term_column()
End_column()

Start_column("test_if_5", false)
  Log_msg( "test_if_5 should not be active")
  Log_msg( "will wait 7 seconds and reset")
  Wait_delay(  7000)
  Log_msg( "test_if_5 is terminating")
  Term_column()
End_column()

Start_engine( 100, 30, 'default_idle_function', 'default_calendar_function')
Destroy_engine('Engine Done\\n')


]]