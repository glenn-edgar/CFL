--[[


static const char* while_message = "This is a test message for while \n";

static bool while_column_test(void* input, void* params,
  Event_data_CFL_t* event_data) {
  While_column_control_CFL_t* while_control;
  const char* message;

  while_control = (While_column_control_CFL_t*)params;
  message = (const char*)while_control->user_data;
  Printf_CFL(message); // testing user data
 
  Printf_CFL("number of iterations %d max_iterations 4 \n",while_control->current_iterations);
  if (while_control->current_iterations >= 4) {
    Printf_CFL("while column is terminating \n");
    return false;
  }
  return true;
}


Start_function('test_while_column_no_termination')

column_names = { "test_while", "while_0", "while_1", "while_2" }
while_columns = { "while_0", "while_1", "while_2" }

Conf_engine('config_handle','50000','2500')
Def_columns('column_names',column_names)
Store_boolean_fn('while_column_test','while_column_test')


Start_column( "test_while", true)
  Log_msg( "starting while command")
  While_columns('while_column_test','while_columns',while_columns,'(void*)while_message')
  Log_msg( "done with while statement")
  Term_column()
End_column()

Start_column( "while_0", false)
  Log_msg( "while_0 should be active")
  Wait_delay( 1000)
  Log_msg( "while_0 is terminating")
  Term_column()
End_column()

Start_column( "while_1", false)
  Log_msg( "while_1 should be active")
  Wait_delay( 2000)
  Log_msg( "while_1 is terminating")
  Term_column()
End_column()

Start_column( "while_2", false)
  Log_msg( "while_2 should be active")
  Wait_delay( 3000)
  Log_msg( "while_2 is terminating")
  Term_column()
End_column()

Start_engine( 100, 30, 'default_idle_function', 'default_calendar_function')
Destroy_engine('Engine Done\\n')

Start_function('test_while_column_termination')

column_names = { "early_terminate", "test_while", "while_0","while_1", "while_2" }
while_columns = { "while_0", "while_1", "while_2" }
early_terminate_columns = { "test_while" }

Conf_engine('config_handle','50000','2500')

Def_columns('column_names',column_names)

Store_boolean_fn('while_column_test','while_column_test')


Start_column( "early_terminate", true)
  Log_msg( "early terminate")
  Wait_delay( 500)
  Disable_columns("early_terminate_columns",early_terminate_columns)
  Log_msg( "early_terminate is done")
  Term_column()
End_column()
 
Start_column( "test_while", true)
  Log_msg( "starting while command")
  While_columns('while_column_test','while_columns',while_columns,'(void*)while_message')
  Log_msg( "done with while statement")
  Term_column()
End_column()

Start_column( "while_0", false)
  Log_msg( "while_0 should be active")
  Wait_delay( 1000)
  Log_msg( "while_0 is terminating")
  Term_column()
End_column()

Start_column( "while_1", false)
  Log_msg( "while_1 should be active")
  Wait_delay( 2000)
  Log_msg( "while_1 is terminating")
  Term_column()
End_column()

Start_column( "while_2", false)
  Log_msg( "while_2 should be active")
  Wait_delay( 3000)
  Log_msg( "while_2 is terminating")
  Term_column()
End_column()


















]]