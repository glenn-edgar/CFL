#include "test_state_machine.h"
#include "Cfl_user_functions.h"
#include "test_interface_functions.h"


static void test_state_machine(Handle_config_CFL_t* config_handle);


void test_state_machine(void) {





  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  Printf_CFL("column control test\n");
  

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  config_handle->number_of_state_machines = 10;



  



  test_state_machine(config_handle);
 
  free(config_handle);
}
static void test_state_machine(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,200000,2500);

    // define the column list
    const char * start_column_names[] = {
        "start_column"};
    Asm_columns_CFL(input,1,start_column_names);

   /* 
    Defining Column "start_column"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "start_column", true);
    Asm_log_message_CFL(input,"start column");
    Asm_wait_time_delay_CFL(input,10000);
    Asm_log_message_CFL(input,"terminating engine");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    // define the column list
    const char * test_sm_column_array[] = {
        "test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain","test_sm_manager_chain"};
    Asm_columns_CFL(input,4,test_sm_column_array);
    Define_named_event_queue_CFL(input,test_sm_test_state1_queue,10);
    Define_named_event_queue_CFL(input,test_sm_test_state2_queue,10);
    Define_named_event_queue_CFL(input,test_sm_test_state3_queue,10);
    Define_named_event_queue_CFL(input,test_sm_queue,10);
    static const char *test_sm_array[] = { test_sm };
     Define_state_machine_CFL(input, 1, test_sm_array);
      static const char *test_sm_state_array state[] = {
test_state1,test_state2,test_state3
};
    Asm_define_sm(input,test_sm,3,test_sm_state_array,test_sm_manager_chain,test_sm_queue,test_state1,(void *)test_data);
