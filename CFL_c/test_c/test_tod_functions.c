
#include "CFL_user_functions.h"
#include "test_tod_functions.h"
#include "test_interface_functions.h"

void test_tod_functions(Handle_config_CFL_t* config_handle);

void test_tod_functions(void){
  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  
  


  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;
  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  
 
  test_tod_functions(config_handle);
}


static void failure_function(void *input,void *params,Event_data_CFL_t *eventdata){
   Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)params;
   Printf_CFL("terminate flag %d \n",wait_tod->terminate_flag);
   Printf_CFL(" %s \n",(const char *)wait_tod->user_data);


}

void test_tod_functions(Handle_config_CFL_t* config_handle){



    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "test_wait_tod_second","test_verify_tod_second"};
    Asm_columns_CFL(input,2,column_names);
    Store_one_shot_function_CFL(input,"my_failure_fn",failure_function);

   /* 
    Defining Column "test_wait_tod_second"  starting initial running state false 
    */ 
    Asm_start_column_CFL(input, "test_wait_tod_second", false);
    Asm_log_message_CFL(input,"wait less than 10 seconds");
    Asm_wait_tod_lt(input, -1, -1, -1, -1, -1, 10);
    Asm_log_message_CFL(input,"wait less than equal 15 seconds");
    Asm_wait_tod_le(input, -1, -1, -1, -1, -1, 15);
    Asm_log_message_CFL(input,"wait equal 17 seconds");
    Asm_wait_tod_eq(input, -1, -1, -1, -1, -1, 17);
    Asm_log_message_CFL(input,"wait greater than equal 20 seconds");
    Asm_wait_tod_ge(input, -1, -1, -1, -1, -1, 20);
    Asm_log_message_CFL(input,"wait greater than 25 seconds");
    Asm_wait_tod_gt(input, -1, -1, -1, -1, -1, 25);
    Asm_log_message_CFL(input,"Reseting column");
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "test_verify_tod_second"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "test_verify_tod_second", true);
    Asm_log_message_CFL(input,"verify tod column staart");
    Asm_log_message_CFL(input,"verify less than 10 seconds");
    Asm_wait_tod_lt(input, -1, -1, -1, -1, -1, 10);
    Asm_wait_tod_ge(input, -1, -1, -1, -1, -1, 20);
    Asm_log_message_CFL(input,"made it past 20 seconds");
    Asm_log_message_CFL(input,"at reset at 28");
    Asm_verify_tod_lt(input, -1, -1, -1, -1, -1, 50,true,"my_failure_fn",(void *)"failure for verify 50");
    Asm_verify_tod_le(input, -1, -1, -1, -1, -1, 49,true,"my_failure_fn",(void *)"failure for verify 49");
    Asm_verify_tod_ge(input, -1, -1, -1, -1, -1, 28,false,"my_failure_fn",(void *)"failure for verify 28");
    Asm_wait_tod_ge(input, -1, -1, -1, -1, -1, 55);
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     
 
  Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);


  Printf_CFL("Engine Done");
  Destroy_engine_CFL(input);
 
}
