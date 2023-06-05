
#include "test_named_queue_functions.h"
#include "CFL_user_functions.h"
#include "test_interface_functions.h"

static void test_basic_functions(Handle_config_CFL_t* config_handle);
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
    test_basic_functions(config_handle);
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
     
    const char *ev1[] = {"test_queue"};

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
     Asm_send_named_events_CFL(input,1,ev1,&event_data_2);
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
   Printf_CFL("nil");
}
#if 0
static int dump_event_fn(void* input, void* aux_fun, void* params, Event_data_CFL_t* event_data) {

    const char* message = (const char*)params;

    if ((event_data->event_index != EVENT_TERMINATION_CFL) && (event_data->event_index != EVENT_INIT_CFL)) {

        Printf_CFL("%s column index %d event index %d  %s %s \n", __func__, Get_current_column_index_CFL(input), event_data->event_index, event_data->params, message);
    }
    return CONTINUE_CFL;
}

static void event_generator_fn(void* input, void* params, Event_data_CFL_t* event_data) {

    Event_data_CFL_t* reference_event = (Event_data_CFL_t*)params;

    event_data->event_index = reference_event->event_index + 1;
    event_data->event_data = reference_event->event_data + 1.0;
    event_data->params = reference_event->params;

}

static inline void configure_named_queues(void* input, unsigned number, const char** event_names, unsigned queue_size) {

    for (unsigned i = 0; i < number; i++) {
        Asm_create_named_event_queue_CFL(input, event_names[i], queue_size);
    }
}

static void test_named_queue_functions_basic_test(Handle_config_CFL_t* config_handle) {


    void* input = Configure_engine_CFL(config_handle, 40000, 2500);
    const char* column_names[] = { "initial_startup", "main_server_1","main_server_2","event_generator" };

    const char* startup_columns[] = { "main_server_1","main_server_2", "event_generator" };
    const char* event_columns_names[] = { "main_server_1", "main_server_2" };
    const char* event_queues[] = { "main_server_1","main_server_2" };


    Event_data_CFL_t event_data[] = { {25,25.0,(void*)"test_data_1"},
                                     {26,26.0,(void*)"test_data_2"},
                                     {27,26.0,(void*)"test_data_3"},
                                     {28,26.0,(void*)"test_data_4"},
                                     {0,0,(void*)"fn_event"} };




    Store_one_shot_function_CFL(input, "EVENT_GENERATOR_FN", event_generator_fn);
    Store_column_function_CFL(input, "DUMP_EVENT", dump_event_fn);
    Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);


    configure_named_queues(input, NAME_SIZE_CFL(event_queues), event_queues, 10);

    /************************* initial startup *******************************************/
    Asm_start_column_CFL(input, "initial_startup", true);
    //----------->
    Asm_log_message_CFL(input, "initial_startup");
    Asm_reset_named_event_queues_CFL(input, NAME_SIZE_CFL(event_queues), event_queues);
    // launch and don't wait for the main server and event generator to terminate
    Asm_enable_columns_CFL(input, NAME_SIZE_CFL(startup_columns), startup_columns, false);
    Asm_wait_time_delay_CFL(input, 10000);
    Asm_engine_terminate_CFL(input);
    //------->
    Asm_end_column_CFL(input);

    /************************* main server 1 *******************************************/
    Asm_start_column_event_queue_CFL(input, "main_server_1", false, "main_server_1");

    Asm_log_message_CFL(input, "Waiting for events");

    //Asm_log_message_CFL(input, "Dumping events with a 300+100 ms delay");
    Asm_attach_event_handler_CFL(input, 25, "DUMP_EVENT", (void*)"main_server_1");
    Asm_attach_event_handler_CFL(input, 26, "DUMP_EVENT", (void*)"main_server_1");
    Asm_attach_event_handler_CFL(input, 27, "DUMP_EVENT", (void*)"main_server_1");
    Asm_attach_event_handler_CFL(input, 28, "DUMP_EVENT", (void*)"main_server_1");
    Asm_attach_event_handler_CFL(input, 1, "DUMP_EVENT", (void*)"main_server_1");
    Asm_wait_time_delay_CFL(input, 300);
    Asm_reset_CFL(input);  // reset will pop all events from the named event queue
    //---->
    Asm_end_column_CFL(input);



    /************************* main server 2 *******************************************/
    Asm_start_column_event_queue_CFL(input, "main_server_2", false, "main_server_2");
    //----->
    //Asm_log_message_CFL(input, "Dumping events with  no delay delay");

    Asm_attach_event_handler_CFL(input, 25, "DUMP_EVENT", (void*)"main_server_2");
    Asm_attach_event_handler_CFL(input, 26, "DUMP_EVENT", (void*)"main_server_2");
    Asm_attach_event_handler_CFL(input, 27, "DUMP_EVENT", (void*)"main_server_2");
    Asm_attach_event_handler_CFL(input, 28, "DUMP_EVENT", (void*)"main_server_2");
    Asm_attach_event_handler_CFL(input, 1, "DUMP_EVENT", (void*)"main_server_2");

    Asm_reset_CFL(input);
    //---->
    Asm_end_column_CFL(input);


    /************************* event generator  *******************************************/
    Asm_start_column_CFL(input, "event_generator", false);
    //---->
    Asm_log_message_CFL(input, "Sending Event Every 3 Seconds");
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[0]);
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[1]);
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[2]);
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[3]);
    Asm_send_named_events_fn_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, "EVENT_GENERATOR_FN", &event_data[4]);
    Asm_wait_time_delay_CFL(input, 3000);
    //Asm_log_message_CFL(input, "Repeating Reset ");
    Asm_reset_CFL(input);
    //-->
    Asm_end_column_CFL(input);





    Start_engine_CFL(input, 100, 30, NULL, NULL);

    Destroy_engine_CFL(input);
    Printf_CFL("Engine Done");
    Printf_CFL("Remaining allocate once %d \n",Allocate_once_remaining_heap_size_CFL(input));
    Printf_CFL("free memory %d \n",freeMemory());
}



void try_results(void* handle, Try_column_CFL_t* results) {


    Printf_CFL("%s try is done \n", __func__);


}





static int handle_immediate_events_fn(void* handle,  void* aux_fn, void* params, Event_data_CFL_t* event_data) {


    char* user_data = (char*)params;
    if (event_data->event_index == EVENT_INIT_CFL) {
        ;// do nothing for now
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL) {
        ; // do nothing for now
        return CONTINUE_CFL;
    }
    switch (event_data->event_index) {
    case 25:
        Printf_CFL("Event 25 is received and handled\n");
        Printf_CFL("%s user data %s \n", __func__, user_data);
        break;
    case 26:
        Printf_CFL("Event 26 is received and handled\n");
        Printf_CFL("%s user data %s \n", __func__, user_data);
        break;

    default:
        ASSERT_PRINT_INT("Invalid event index", event_data->event_index);
    }
    return RESET_CFL;

}
#if 0
typedef struct enable_join_t {
    bool                  time_wait_flag;
    unsigned short        number_of_columns;
    const    char** column_names;
    unsigned short* column_indexes;
}enable_join_t;

static inline enable_join_t* generate_enable_join(void* input, unsigned size, const char** column_names) {

    enable_join_t* enable_join = (enable_join_t*)Allocate_once_malloc_CFL(input, sizeof(enable_join_t));
    enable_join->number_of_columns = size;
    enable_join->column_names = column_names;
    enable_join->column_indexes = (unsigned short*)Allocate_once_malloc_CFL(input, size * sizeof(unsigned short));
    return enable_join;
}

static int  enable_join_fn(void* input, void* aux_fn, void* params, Event_data_CFL_t* event_data) {
    enable_join_t* enable_join = (enable_join_t*)params;


    if (event_data->event_index == EVENT_INIT_CFL) {

        Printf_CFL("init event received");
        for (int i = 0; i < enable_join->number_of_columns; i++) {
            enable_join->column_indexes[i] = Find_column_index_CFL(input, enable_join->column_names[i]);
            Enable_column_CFL(input, enable_join->column_indexes[i]);
        }
        enable_join->time_wait_flag = false;

        Printf_CFL("enable columns done");
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL) {
        for (int i = 0; i < enable_join->number_of_columns; i++) {
            Disable_column_CFL(input, enable_join->column_indexes[i]);
        }
        Printf_CFL("disable columns done");
        return CONTINUE_CFL;
    }
    if (event_data->event_index == TIMER_TICK_CFL) {
        if (enable_join->time_wait_flag == false) {
            enable_join->time_wait_flag = true;

            return HALT_CFL;
        }

        if (Join_columns_CFL(input, enable_join->number_of_columns, enable_join->column_indexes) == true) {
            Printf_CFL("join state done \n");

            return DISABLE_CFL;
        }
        return HALT_CFL;
    }

    return HALT_CFL;

}

#endif

#define RUN_TIME 125000
#define EVENT_TIME 30000

static void test_server_activity(Handle_config_CFL_t* config_handle) {


    void* input = Configure_engine_CFL(config_handle, 40000, 2500);

    const char* column_names[] = { "initial_startup","event_generator", "server","coordinator_1","worker_1_a","worker_1_b",
                                   "coordinator_2","worker_2_a","worker_2_b" , "coordinator_3","worker_3_a","worker_3_b" };

    const char* startup_columns[] = { "event_generator", "server" };
    const char* event_columns_names[] = { "server" };
    const char* coordinator_1[] = { "worker_1_a","worker_1_b" };
    const char* coordinator_2[] = { "worker_2_a","worker_2_b" };
    const char* coordinator_3[] = { "worker_3_a","worker_3_b" };
    const char* event_queues[] = { "server" };
    const short immediate_events[] = { 25,26 };
    const short sequential_events[] = { 28,1 };
    const short parallel_events[] = { 27 };

    Event_data_CFL_t event_data[] = { {25,25.0,(void*)"handled_direct"},
                                     {26,26.0,(void*)"handled_direct"},
                                     {27,26.0,(void*)"try_column_1"},
                                     {28,26.0,(void*)"try_column_2"},
                                     {0,0,(void*)"try_column_3"} };



    const char* coordinator_1_names[] = { "coordinator_1","coordinator_3" };

    const char* coordinator_2_names[] = { "coordinator_2" };
    const char* immediate_user_data = "immediate_user_data";



    Store_one_shot_function_CFL(input, "EVENT_GENERATOR_FN", event_generator_fn);
    Store_try_function_CFL(input, "TRY_RESULTS", try_results);
    Store_column_function_CFL(input, "HANDLE_IMMEDIATE_EVENTS", handle_immediate_events_fn);
#if 0
    Store_column_function_CFL(input, "ENABLE_JOIN", enable_join_fn);
#endif


    Asm_columns_CFL(input, NAME_SIZE_CFL(column_names), column_names);
    configure_named_queues(input, NAME_SIZE_CFL(event_queues), event_queues, 10);

    /************************* initial startup *******************************************/
    Asm_start_column_CFL(input, "initial_startup", true);
    //----------->
    Asm_log_message_CFL(input, "initial_startup");
    Asm_reset_named_event_queues_CFL(input, NAME_SIZE_CFL(event_queues), event_queues);
    // launch and don't wait for the main server and event generator to terminate
    Asm_enable_columns_CFL(input, NAME_SIZE_CFL(startup_columns), startup_columns, false);
    Asm_wait_time_delay_CFL(input, RUN_TIME);  // one hundred seconds
    Asm_engine_terminate_CFL(input);
    //------->
    Asm_end_column_CFL(input);


    /************************* event generator  *******************************************/
    Asm_start_column_CFL(input, "event_generator", false);
    //---->
    Asm_log_message_CFL(input, "Sending Event Every 15 Seconds");
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[0]);
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[1]);
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[2]);
    Asm_send_named_events_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, &event_data[3]);
    Asm_send_named_events_fn_CFL(input, NAME_SIZE_CFL(event_columns_names), event_columns_names, "EVENT_GENERATOR_FN", &event_data[4]);
    Asm_wait_time_delay_CFL(input, EVENT_TIME);  // event every 15 seconds
    Asm_log_message_CFL(input, "Wait done   ");
    Asm_reset_CFL(input);
    //-->
    Asm_end_column_CFL(input);



    /************************* server *******************************************/
    Asm_start_column_event_queue_CFL(input, "server", false, "server");

    //Asm_log_message_CFL(input, "Waiting for events");

    //Asm_log_message_CFL(input, "TOP LEVEL SERVER");
    Asm_attach_multi_event_handler_CFL(input, sizeof(immediate_events) / sizeof(short), immediate_events, "HANDLE_IMMEDIATE_EVENTS", (void*)immediate_user_data);
    Asm_handle_enable_join_actions_CFL(input, sizeof(parallel_events), parallel_events, NAME_SIZE_CFL(coordinator_1_names), coordinator_1_names);
    Asm_handle_enable_join_actions_CFL(input, sizeof(sequential_events), sequential_events, NAME_SIZE_CFL(coordinator_2_names), coordinator_2_names);

    Asm_reset_CFL(input);  // reset will pop event from the named event queue
    //---->
    Asm_end_column_CFL(input);

    /************************* coordinator 1 *******************************************/
    Asm_start_column_CFL(input, "coordinator_1", false);
    //---->
    Asm_log_message_CFL(input, "Coordinator 1");
    // store to data structure

    // launch and join workers
    Asm_log_message_CFL(input, "Coordinator 1 starting");
    Asm_enable_columns_CFL(input, NAME_SIZE_CFL(coordinator_1), coordinator_1, false);
    Asm_join_columns_CFL(input, NAME_SIZE_CFL(coordinator_1), coordinator_1, true);
    Asm_log_message_CFL(input, "Coordinator 1 done");
    // analyize results
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "worker_1_a", false);
    //---->
    Asm_log_message_CFL(input, "Worker 1 A starting");
    Asm_wait_time_delay_CFL(input, 1000);
    Asm_log_message_CFL(input, "Worker 1 A done");
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "worker_1_b", false);
    //---->
    Asm_log_message_CFL(input, "Worker 1 B starting");
    Asm_wait_time_delay_CFL(input, 2000);
    Asm_log_message_CFL(input, "Worker 1 B done");
    Asm_terminate_CFL(input);

    //-->
    Asm_end_column_CFL(input);



    /************************* coordinator 2 *******************************************/
    Asm_start_column_CFL(input, "coordinator_2", false);
    //---->
    Asm_log_message_CFL(input, "Coordinator starting 2");

    // run until failure as inverse flag is set to true
    Asm_try_columns_CFL(input, "TRY_RESULTS", NAME_SIZE_CFL(coordinator_2), coordinator_2, true, false, NULL);
    Asm_log_message_CFL(input, "Coordinator 2 done");
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "worker_2_a", false);
    //---->
    Asm_log_message_CFL(input, "Worker 2a starting");
    Asm_log_message_CFL(input, "Worker 2 A");
    Asm_wait_time_delay_CFL(input, 2000);
    Asm_log_message_CFL(input, "Worker 2 a done");
    Asm_set_return_code(input, false);
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "worker_2_b", false);
    //---->
    Asm_log_message_CFL(input, "Worker 2B starting");
    Asm_wait_time_delay_CFL(input, 4000);
    Asm_set_return_code(input, true);
    Asm_log_message_CFL(input, "Worker 2b done");
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    /************************* coordinator 3 *******************************************/
    Asm_start_column_CFL(input, "coordinator_3", false);
    //---->
    Asm_log_message_CFL(input, "Coordinator starting 3");

    // run until failure as inverse flag is set to true
    Asm_try_columns_CFL(input, "TRY_RESULTS", NAME_SIZE_CFL(coordinator_3), coordinator_3, true, false, NULL);
    Asm_log_message_CFL(input, "Coordinator 3 done");
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "worker_3_a", false);
    //---->
    Asm_log_message_CFL(input, "Worker 3a starting");
    Asm_log_message_CFL(input, "Worker 3 A");
    Asm_wait_time_delay_CFL(input, 2000);
    Asm_log_message_CFL(input, "Worker 3 a done");
    Asm_set_return_code(input, false);
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    Asm_start_column_CFL(input, "worker_3_b", false);
    //---->
    Asm_log_message_CFL(input, "Worker 3B starting");
    Asm_wait_time_delay_CFL(input, 4000);
    Asm_set_return_code(input, true);
    Asm_log_message_CFL(input, "Worker 3b done");
    Asm_terminate_CFL(input);
    //-->
    Asm_end_column_CFL(input);

    Start_engine_CFL(input, 100, 30, NULL, NULL);

    Destroy_engine_CFL(input);
    Printf_CFL("Engine Done");
    Printf_CFL("allocate once heap space %d \n",Allocate_once_remaining_heap_size_CFL(input));
    Printf_CFL("free memory %d \n",freeMemory());

}

#endif
