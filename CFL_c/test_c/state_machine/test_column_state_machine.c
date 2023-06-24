


#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

static void test_column_state_machine_a(Handle_config_CFL_t* config_handle);

void test_column_state_machine(void) {
  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);

  
  


  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;
  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  config_handle->number_df_buffers = 2;
  config_handle->number_of_compiled_s_log_expressions = 5;
   
  test_column_state_machine_a(config_handle);
}

/*  
typedef struct process_event_t_CFL
{
    unsigned short event_number;
    short *event_indexes;
    bool block_flag;
    short return_value;
    void *user_data;
} process_event_t_CFL;
*/


#define event_1   12
#define event_2   13
#define event_3   14
#define event_4   15
#define event_5   16
#define event_6   17
#define event_7   18
#define event_8   19

#define event_9 25
#define event_10 26

static const char *user_data_0 = "state machine 0 user data \n";

static void sm_0_handler(void* input, void *params, Event_data_CFL_t *event_data){
   process_event_t_CFL *process_event = (process_event_t_CFL *)params;
   process_event->return_value = HALT_CFL;
   Printf_CFL("sm_0_handler %d \n",event_data->event_index);
   if( event_data->event_index == EVENT_INIT_CFL){
   
      Printf_CFL("sm_0_handler EVENT_INIT_CFL %s\n",process_event->user_data);
   }     
   if( event_data->event_index == EVENT_TERMINATION_CFL){
      Printf_CFL("sm_0_handler EVENT_TERMINATION_CFL %s\n",process_event->user_data);
   }
   if( event_data->event_index == event_1){
      Printf_CFL("sm_0_handler event %d %s\n",event_1,process_event->user_data);
   }
   if( event_data->event_index == event_2){
    Change_local_column_state_CFL(input,1);
    process_event->return_value = COLUMN_STATE_CHANGE_CFL;
     Printf_CFL("sm_0_handler event %d  %s\n",event_2,process_event->user_data);
   }


}

static const char *user_data_1 = "state machine 1 user data \n";

static void sm_1_handler(void* input, void *params, Event_data_CFL_t *event_data){
   process_event_t_CFL *process_event = (process_event_t_CFL *)params;
   process_event->return_value = HALT_CFL;
   Printf_CFL("sm_1_handler %d \n",event_data->event_index);
   if( event_data->event_index == EVENT_INIT_CFL){
      Printf_CFL("sm_1_handler EVENT_INIT_CFL %s\n",process_event->user_data);
   }     
   if( event_data->event_index == EVENT_TERMINATION_CFL){
      Printf_CFL("sm_1_handler EVENT_TERMINATION_CFL %s\n",process_event->user_data);
      
   }
   if( event_data->event_index == event_3){
      Printf_CFL("sm_1_handler event %d %s\n",event_3,process_event->user_data);
   }
   if( event_data->event_index == event_4){
     Printf_CFL("sm_1_handler event %d  %s\n",event_4,process_event->user_data);
     Change_local_column_state_CFL(input,2);
       process_event->return_value = COLUMN_STATE_CHANGE_CFL;
   }


}

static const char *user_data_2 = "state machine 2 user data \n";

static void sm_2_handler(void* input, void *params, Event_data_CFL_t *event_data){
   process_event_t_CFL *process_event = (process_event_t_CFL *)params;
   process_event->return_value = HALT_CFL;
   Printf_CFL("sm_2_handler %d \n",event_data->event_index);
   if( event_data->event_index == EVENT_INIT_CFL){
      Printf_CFL("sm_2_handler EVENT_INIT_CFL %s\n",process_event->user_data);
   }     
   if( event_data->event_index == EVENT_TERMINATION_CFL){
      Printf_CFL("sm_2_handler EVENT_TERMINATION_CFL %s\n",process_event->user_data);
   }
   if( event_data->event_index == event_5){
      Printf_CFL("sm_2_handler event %d %s\n",event_5,process_event->user_data);
      
   }
   if( event_data->event_index == event_6){
     Printf_CFL("sm_2_handler event %d  %s\n",event_6,process_event->user_data);
     Change_local_column_state_CFL(input,3);
      process_event->return_value = COLUMN_STATE_CHANGE_CFL;
   }


}
static const char *user_data_3 = "state machine 3 user data \n";

static void sm_3_handler(void* input, void *params, Event_data_CFL_t *event_data){
   process_event_t_CFL *process_event = (process_event_t_CFL *)params;
   process_event->return_value = HALT_CFL;
   Printf_CFL("sm_3_handler %d \n",event_data->event_index);
   if( event_data->event_index == EVENT_INIT_CFL){
      Printf_CFL("sm_3_handler EVENT_INIT_CFL %s\n",process_event->user_data);
   }     
   if( event_data->event_index == EVENT_TERMINATION_CFL){
      Printf_CFL("sm_3_handler EVENT_TERMINATION_CFL %s\n",process_event->user_data);
   }
   if( event_data->event_index == event_7){
      Printf_CFL("sm_3_handler event %d %s\n",event_7,process_event->user_data);
   }
   if( event_data->event_index == event_8){
     Printf_CFL("sm_3_handler event %d  %s\n",event_8,process_event->user_data);
     Change_local_column_state_CFL(input,0);
      process_event->return_value = COLUMN_STATE_CHANGE_CFL;
   }


}

static const char *filter_event_data = "filter event user data \n";

static void filter_handler(void* input, void *params, Event_data_CFL_t *event_data){
   process_event_t_CFL *process_event = (process_event_t_CFL *)params;

   Printf_CFL("filter event handler %d \n",event_data->event_index);
   if( event_data->event_index == EVENT_INIT_CFL){
      Printf_CFL("filter event handler EVENT_INIT_CFL %s\n",process_event->user_data);
   }     
   if( event_data->event_index == EVENT_TERMINATION_CFL){
      Printf_CFL("filter event handler EVENT_TERMINATION_CFL %s\n",process_event->user_data);
   }
   if( event_data->event_index == event_9){
      Printf_CFL("filter event handler event %d %s\n",event_data->event_index,process_event->user_data);
   }
   if( event_data->event_index == 10){
     Printf_CFL("filter event handler %d  %s\n",event_data->event_index,process_event->user_data);
     
   }


}



static void test_column_state_machine_a(Handle_config_CFL_t* config_handle)
{

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "test_column_state_machine","event_generator","time_out"};
    Asm_columns_CFL(input,3,column_names);
    Event_data_CFL_t event_data_1 = { 12, 45.2, NULL};
    Event_data_CFL_t event_data_2 = { 13, 46.3, NULL};
    Event_data_CFL_t event_data_3 = { 14, 47.4, NULL};
    Event_data_CFL_t event_data_4 = { 15, 48.5, NULL};
    Event_data_CFL_t event_data_5 = { 16, 49.6, NULL};
    Event_data_CFL_t event_data_6 = { 17, 50.2, NULL};
    Event_data_CFL_t event_data_7 = { 18, 51.4, NULL};
    Event_data_CFL_t event_data_8 = { 19, 53.5, NULL};
    Event_data_CFL_t not_used = { 99, 53.5, NULL};
    Event_data_CFL_t filter_event_1 = { 25, 53.5, NULL};
    Event_data_CFL_t filter_event_2 = { 26, 53.5, NULL};
    Store_one_shot_function_CFL(input,"sm_0_handler",sm_0_handler);
    Store_one_shot_function_CFL(input,"sm_1_handler",sm_1_handler);
    Store_one_shot_function_CFL(input,"sm_2_handler",sm_2_handler);
    Store_one_shot_function_CFL(input,"sm_3_handler",sm_3_handler);
    Store_one_shot_function_CFL(input,"filter_handler",filter_handler);

   /* 
    Defining Column "test_column_state_machine"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "test_column_state_machine", true);
    Asm_log_message_CFL(input,"starting test_column_state_machine");
    // define the event list
    short  filter_events[] = {
        25,26};
    Asm_filter_events_CFL(input,"filter_handler",2,filter_events,true,(void *)filter_event_data);
    Asm_change_column_state_CFL(input,0);
    Asm_store_column_starting_state_CFL(input);
    // define the event list
    short  sm_0[] = {
        12,13};
    Asm_process_event_CFL(input,"sm_0_handler",2,sm_0,COLUMN_STATE_CHANGE_CFL,true,(void *)user_data_0);
    // define the event list
    short  sm_1[] = {
        14,15};
    Asm_process_event_CFL(input,"sm_1_handler",2,sm_1,COLUMN_STATE_CHANGE_CFL,true,(void *)user_data_1);
    // define the event list
    short  sm_2[] = {
        16,17};
    Asm_process_event_CFL(input,"sm_2_handler",2,sm_2,COLUMN_STATE_CHANGE_CFL,true,(void *)user_data_2);
    // define the event list
    short  sm_3[] = {
        18,19};
    Asm_process_event_CFL(input,"sm_3_handler",2,sm_3,COLUMN_STATE_CHANGE_CFL,true,(void *)user_data_3);
     Asm_store_column_ending_state_CLF(input);
    Asm_halt_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "event_generator"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "event_generator", true);
    Asm_log_message_CFL(input,"starting event_generator");
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_1);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_2);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_2);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_3);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_4);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_2);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_5);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_6);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_2);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_7);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_send_event_CFL(input,&event_data_8);
    Asm_send_event_CFL(input,&not_used);
    Asm_send_event_CFL(input,&filter_event_2);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "time_out"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "time_out", true);
    Asm_log_message_CFL(input,"starting time_out column");
    Asm_wait_time_delay_CFL(input,60000);
    Asm_engine_terminate_CFL(input);
    Asm_end_column_CFL(input);
     
    Start_engine_CFL(input, 100, 30, default_idle_function, default_calendar_function);
    Destroy_engine_CFL(input);
   Printf_CFL("nil\n");
}
