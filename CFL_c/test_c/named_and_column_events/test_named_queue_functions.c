
#include "test_named_queue_functions.h"
#include "CFL_user_functions.h"
#include "test_interface_functions.h"

static void test_basic_functions(Handle_config_CFL_t* config_handle);
static void test_rpc_server_client(Handle_config_CFL_t* config_handle);
void test_named_queue_functions(void) {

    Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);
    Printf_CFL("named event queue test");
    Printf_CFL("free memory %d \n",freeMemory());


    config_handle->number_of_columns = 30;
    config_handle->number_of_column_elements = 300;
    config_handle->number_column_functions = 100;
    config_handle->number_bool_functions = 50;
    config_handle->number_if_functions = 50;
    config_handle->one_shot_functions = 50;
    config_handle->number_of_try_functions = 50;
    config_handle->number_of_named_queues = 20;
    //test_basic_functions(config_handle);
    test_rpc_server_client(config_handle);
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

static void generate_event(void *input, void *param, Event_data_CFL_t *event_data){
 
     Event_data_CFL_t *event_data_a = (Event_data_CFL_t *)param;
     Send_named_event_CFL(input,0,event_data_a);


}


static void test_basic_functions(Handle_config_CFL_t* config_handle)
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
    const char *ev1[] = {"test_queue"};
    Define_named_event_queue_CFL(input,"test_queue",16);

   /* 
    Defining Column "test_column_state_machine"  starting initial running state true 
    */ 
    Asm_start_column_event_queue_CFL(input, "test_column_state_machine", true,"test_queue");
    Asm_log_message_CFL(input,"starting test_column_state_machine");
    // define the event list
    short  filter_events[] = {
        25,26};
    Asm_filter_events_CFL(input,"filter_handler",2,filter_events,true,(void *)filter_event_data);
     Asm_reset_named_event_queues_CFL(input,1,ev1);
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
     
    Store_one_shot_function_CFL(input,"GENERATE_EVENT",generate_event);

   /* 
    Defining Column "event_generator"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "event_generator", true);
    Asm_log_message_CFL(input,"starting event_generator");
    Asm_wait_time_delay_CFL(input,1000);
     Asm_send_named_events_CFL(input,1,ev1,&event_data_1);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
    Asm_one_shot_CFL(input,"GENERATE_EVENT",&event_data_2);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_2);
    Asm_wait_time_delay_CFL(input,1000);
     Asm_send_named_events_CFL(input,1,ev1,&event_data_3);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
     Asm_send_named_events_CFL(input,1,ev1,&event_data_4);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_2);
    Asm_wait_time_delay_CFL(input,1000);
     Asm_send_named_events_CFL(input,1,ev1,&event_data_5);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
     Asm_send_named_events_CFL(input,1,ev1,&event_data_6);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_2);
    Asm_wait_time_delay_CFL(input,1000);
     Asm_send_named_events_CFL(input,1,ev1,&event_data_7);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_1);
    Asm_wait_time_delay_CFL(input,1000);
     Asm_send_named_events_CFL(input,1,ev1,&event_data_8);
     Asm_send_named_events_CFL(input,1,ev1,&not_used);
     Asm_send_named_events_CFL(input,1,ev1,&filter_event_2);
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
#if 0   
typedef struct RPC_message_header_CFL_t {
   bool           success;
   unsigned       magic;
   unsigned short event_id;
   unsigned short request_id;
   unsigned short client_queue_id;
   unsigned short server_queue_id;
   bool           client_free_message_data;
   unsigned short client_data_size;
   void*          client_message_data;
   bool           server_free_message_data;
   unsigned short server_data_size;
   void*          server_message_data;
} RPC_message_header_CFL_t;
#endif

#define ACTION_1_REQUEST_ID 37
#define ACTION_2_REQUEST_ID 38

static const char *rpc_server_user_data_1 = "rpc_server_user_data_1";
static bool rpc_server_action_1(void *input, void *params, Event_data_CFL_t *event_data)
{
   if (event_data->event_index ==  EVENT_INIT_CFL){
      
      return true;
   }
   if(event_data->event_index == EVENT_TERMINATION_CFL){
    
      return true;
   }
   
   RPC_message_header_CFL_t *rpc_message_header = (RPC_message_header_CFL_t *)event_data->params;
   
   if(rpc_message_header->request_id == ACTION_1_REQUEST_ID){
      
      rpc_message_header->success = true;
      rpc_message_header->server_free_message_data = false;
      rpc_message_header->server_data_size = sizeof(rpc_server_user_data_1);
      rpc_message_header->server_message_data = (void *)rpc_server_user_data_1;
      return true;
   }
  
   return false;
     
}

static const char *rpc_server_user_data_2 = "rpc_server_user_data_2";
static bool rpc_server_action_2(void *input, void *params, Event_data_CFL_t *event_data)
{
   if (event_data->event_index ==  EVENT_INIT_CFL){
      ;
      return true;
   }
   if(event_data->event_index == EVENT_TERMINATION_CFL){
      return true;
   }
   RPC_message_header_CFL_t *rpc_message_header = (RPC_message_header_CFL_t *)event_data->params;
   if(rpc_message_header->request_id == ACTION_2_REQUEST_ID){
      rpc_message_header->success = true;
      rpc_message_header->server_free_message_data = false;
      rpc_message_header->server_data_size = sizeof(rpc_server_user_data_2);
      rpc_message_header->server_message_data = (void *)rpc_server_user_data_2;
      return true;
   }
   return false;
     
}

static const char *rpc_client_message_data_1 = "rpc_client_message_data_1";

static const char *rpc_client_user_data_1 = "rpc_client_user_data_1";
static void rpc_client_action_1(void *input, void *params, Event_data_CFL_t *event_data)
{
   RPC_message_header_CFL_t *rpc_message_header = (RPC_message_header_CFL_t *)event_data->params;
   Printf_CFL("\n\n\nrpc_client_action_1: event_id = %d\n", event_data->event_index);
   Printf_CFL("rpc_server data: %s \n", (char *)rpc_message_header->server_message_data);
   Printf_CFL("rpc_client data: %s \n", (char *)rpc_message_header->client_message_data);
  
}


static const char *rpc_client_failure_user_data_1 = "rpc_client_failure_user_data_1";

static void rpc_client_failure_1(void *input, void *params, Event_data_CFL_t *event_data)
{
   Printf_CFL("should not get here \n");
   Printf_CFL("didnot receive RPC Event \n");
}

static const char *rpc_client_message_data_2 = "rpc_client_message_data_2";

static const char *rpc_client_user_data_2 = "rpc_client_user_data_2";
static void rpc_client_action_2(void *input, void *params, Event_data_CFL_t *event_data)
{
   RPC_message_header_CFL_t *rpc_message_header = (RPC_message_header_CFL_t *)event_data->params;
   Printf_CFL("\n\n\nrpc_client_action_2: event_id = %d\n", event_data->event_index);
   Printf_CFL("rpc_server data: %s \n", (char *)rpc_message_header->server_message_data);
   Printf_CFL("rpc_client data: %s \n", (char *)rpc_message_header->client_message_data);
  
}


static const char *rpc_client_failure_user_data_2 = "rpc_client_failure_user_data_2";

static void rpc_client_failure_2(void *input, void *params, Event_data_CFL_t *event_data)
{
   Printf_CFL("should not get here \n");
   Printf_CFL("didnot receive RPC Event \n");
}


static const char *dispose_user_data_1 = "unhandled event \n";
static void dispose_event_1(void *input,void *params,Event_data_CFL_t *event_data){

  char *message = (char *)params;
  Printf_CFL("dispose_event_1: %d \n",event_data->event_index);
  Printf_CFL("dispose_event_1: %s \n",message);
   

}

static void test_rpc_server_client(Handle_config_CFL_t* config_handle)
{
    const char *named_queues[] = {"rpc_server","rpc_client_1","rpc_client_2"};

    void* input = Configure_engine_CFL(config_handle,50000,4000);

    // define the column list
    const char * column_names[] = {
        "init_columns","rpc_server","rpc_client_1","rpc_client_2","time_out"};
    Asm_columns_CFL(input,5,column_names);
    Define_named_event_queue_CFL(input,"rpc_server",16);
    Define_named_event_queue_CFL(input,"rpc_client_1",16);
    Define_named_event_queue_CFL(input,"rpc_client_2",16);
    Store_bool_function_CFL(input,"RPC_SERVER_ACTION_1",rpc_server_action_1);
    Store_bool_function_CFL(input,"RPC_SERVER_ACTION_2",rpc_server_action_2);
    Store_one_shot_function_CFL(input,"RPC_CLIENT_ACTION_1",rpc_client_action_1);
    Store_one_shot_function_CFL(input,"RPC_FAILURE_1",rpc_client_failure_1);
    Store_one_shot_function_CFL(input,"RPC_CLIENT_ACTION_2",rpc_client_action_2);
    Store_one_shot_function_CFL(input,"RPC_FAILURE_2",rpc_client_failure_2);
    Store_one_shot_function_CFL(input,"DISPOSE_EVENT_1",dispose_event_1);

   /* 
    Defining Column "init_columns"  starting initial running state true 
    */ 
    Asm_start_column_CFL(input, "init_columns", true);
    Asm_log_message_CFL(input,"starting int_columns");
     Asm_reset_named_event_queues_CFL(input,3,named_queues);
    Asm_terminate_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "rpc_server"  starting initial running state true 
    */ 
    Asm_start_column_event_queue_CFL(input, "rpc_server", true,"rpc_server");
    Asm_log_message_CFL(input,"starting rpc_server");
    Asm_wait_event_count_CFL(input, 45, 1, NO_TIME_OUT_CFL, false, NULL, NULL);
    Asm_wait_for_server_rpc_CFL(input,45,"RPC_SERVER_ACTION_1",(void *)rpc_server_user_data_1);
    Asm_wait_for_server_rpc_CFL(input,45,"RPC_SERVER_ACTION_2",(void *)rpc_server_user_data_2);
    Asm_dispose_rpc_event_CFL(input,45,true,"DISPOSE_EVENT_1",(void *)dispose_user_data_1);
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "rpc_client_1"  starting initial running state true 
    */ 
    Asm_start_column_event_queue_CFL(input, "rpc_client_1", true,"rpc_client_1");
    Asm_log_message_CFL(input,"starting rpc_client_1");
    Asm_send_rpc_CFL(input,45,37,"rpc_client_1","rpc_server",false,sizeof(rpc_client_message_data_1),(void *)rpc_client_message_data_1);
    Asm_wait_event_count_CFL(input, 45, 1,300,true, "RPC_FAILURE_1", (void *)rpc_client_failure_user_data_1);
    Asm_wait_for_client_rpc_CFL(input,45,"RPC_CLIENT_ACTION_1",(void *)rpc_client_user_data_1);
    Asm_wait_time_delay_CFL(input,3000);
    Asm_reset_CFL(input);
    Asm_end_column_CFL(input);
     

   /* 
    Defining Column "rpc_client_2"  starting initial running state true 
    */ 
    Asm_start_column_event_queue_CFL(input, "rpc_client_2", true,"rpc_client_2");
    Asm_log_message_CFL(input,"starting rpc_client_2");
    Asm_send_rpc_CFL(input,45,38,"rpc_client_2","rpc_server",false,sizeof(rpc_client_message_data_2),(void *)rpc_client_message_data_2);
    Asm_wait_event_count_CFL(input, 45, 1,300,true, "RPC_FAILURE_2", (void *)rpc_client_failure_user_data_2);
    Asm_wait_for_client_rpc_CFL(input,45,"RPC_CLIENT_ACTION_2",(void *)rpc_client_user_data_2);
    Asm_wait_time_delay_CFL(input,3000);
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
