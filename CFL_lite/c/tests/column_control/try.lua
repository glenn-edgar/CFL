--[[


pass_c([[
/*
** If opcode tests
*/

static void test_if_function(void* input, If_control_CFL_t* if_control) {
  // enable only even columns
  bool* enable_ptr = if_control->return_indexes;

  for (unsigned i = 0; i < if_control->column_number; i++) {
    if (i % 2 == 0) {
      *enable_ptr = true;
    }
    else {
      *enable_ptr = false;
    }
    enable_ptr++;
  }
}
#if 0
typedef struct If_control_CFL_t
{
  bool termination_flag;
  bool init_flag;
  unsigned short column_number;
  unsigned short* column_indexes;
  bool* return_indexes;
  One_shot_function_CFL_t termination_fn;
  void* user_data;
} If_control_CFL_t;
#endif

const char* try_user_data = "try_user_data";

static void final_try_function(void *input, void *params, Event_data_CFL_t *event_data) {
   If_control_CFL_t* if_control = (If_control_CFL_t*)params;

   printf("final_try_function called\n");
   for(unsigned i = 0; i < if_control->column_number; i++) {
     printf("if_control->return_indexes[%d] = %d\n", i, if_control->return_indexes[i]) ;
   }
   printf("user data is %s\n", (char*)if_control->user_data);

}




Start_function('test_if_columns_normal_case')

Conf_engine('config_handle','50000','2500')

column_names = quote_list({ "if_column", "test_if_0", "test_if_1",
                                "test_if_2", "test_if_3", "test_if_4",
                                "test_if_5" })

if_columns = quote_list({ "test_if_0", "test_if_1", "test_if_2",
                              "test_if_3", "test_if_4", "test_if_5" })


Store_if_function("local_if_function", 'test_if_function')
Store_one_shot("final_try_function", 'final_try_function')
Def_columns('column_names',column_names)

Start_column("if_column", true)
  Log_msg( "if normal case")
  Log_msg( "if column is active")
  If_columns('local_if_function','col_name',if_columns,"final_try_function",'(void*)try_user_data')
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

]]--