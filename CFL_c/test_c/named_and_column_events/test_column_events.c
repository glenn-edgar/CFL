
#include "test_column_events.h"
#include "CFL_user_functions.h"
#include "test_interface_functions.h"

static void column_event_test(Handle_config_CFL_t* config_handle);


void test_column_events(void) {



  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  Printf_CFL("test_allocation");
 Printf_CFL("Freemem %d \n",freeMemory());

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;

  column_event_test(config_handle);
  
}
  static void column_event_one_shot(void *input,void *param,Event_data_CFL_t *event_data){
    if(event_data->event_index == EVENT_INIT_CFL){
      ;

    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
      ;
    }
    Event_data_CFL_t *column_event = Get_current_column_local_event_CFL(input);
    Printf_CFL("user data for column_event_test %s \n",(char *)column_event->params);


  }
static void column_event_test(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "column_event_test"};
    Asm_columns_CFL(input,1,column_names);
    Event_data_CFL_t column_event_test = { 12, 45.2, (void*)"this is the column event test"};
    Store_one_shot_function_CFL(input,"column_event_handler",column_event_one_shot);

   /* 
    Defining Column "column_event_test"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "column_event_test", true);
    Asm_log_message_CFL(input,"starting column_event_test");
    Asm_store_current_column_event_CFL(input,&column_event_test);
    Asm_one_shot_CFL(input,"column_event_handler",NULL);
    Asm_log_message_CFL(input,"ending column_event_test");
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("nil");
}
