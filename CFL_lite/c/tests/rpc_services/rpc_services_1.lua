set_h_file("rpc_services_1.h")
local entry_point = "rpc_services_handle_1"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 



local time_out_header = [[

void time_out_data_function(const void *input,void *param, Event_data_CFL_t *event_data);
]]
local time_out_code = [[
void time_out_data_function(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;

  char *time_out_data = (char *)param;
   
   Printf_CFL(input,"client time out fn  %s \n",time_out_data);
  
}


]]

Store_one_shot_function("CLIENT_TIME_OUT",'time_out_data_function',time_out_code,time_out_header)

Store_user_code([[

const char time_out_data[] ="Time out for RPC CLIENT TIME OUT";

]])

local time_out_data = "time_out_data"



local server_time_out_header = [[

void server_time_out_data_function(const void *input,void *param, Event_data_CFL_t *event_data);
]]
local server_time_out_code = [[
void server_time_out_data_function(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;

   Process_rpc_CFL_t *rpc_data = (Process_rpc_CFL_t *)param;
   
   Printf_CFL(input,"server time out fn  %s \n",rpc_data->time_out_user_data);
  
}


]]

Store_one_shot_function("SERVER_TIME_OUT",'server_time_out_data_function',server_time_out_code,server_time_out_header)

Store_user_code([[

const char server_time_out_data[] ="Time out for RPC SERVER TIME OUT";

]])

local server_time_out_data = "server_time_out_data"





local worker_first_action_header =[[

void worker_first_action_code(const void *input, void *param, Event_data_CFL_t *event_data);

]]

local worker_first_action_code = [[

void worker_first_action_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   (void)param;

   Rpc_data_CFL_t *rpc_data = ( Rpc_data_CFL_t *)retrieve_current_column_data_CFL(input);
   if(rpc_data->input_data_type != 1){
       ASSERT_PRINT_INT(input,"input types do not match",rpc_data->input_data_type);
   }
   Printf_CFL(input,"Worker action input data type %d input data %s \n",rpc_data->input_data_type,(char *)rpc_data->input);

 
  
}



]]
Store_one_shot_function("WORKER_FIRST_ACTION",'worker_first_action_code',worker_first_action_code,worker_first_action_header)

local worker_second_action_header =[[

void worker_second_action_code(const void *input, void *param, Event_data_CFL_t *event_data);

]]

local worker_second_action_code = [[

static const char *worker_second_action_output_data = "Worker output action output data\n";
void worker_second_action_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   (void)param;
   
   Rpc_data_CFL_t *rpc_data = (Rpc_data_CFL_t *)retrieve_current_column_data_CFL(input);
   rpc_data->output = (void *)worker_second_action_output_data;
   rpc_data->output_data_type = 2;
   rpc_data->output_malloc_flag = false;
}



]]
Store_one_shot_function("WORKER_SECOND_ACTION",'worker_second_action_code',worker_second_action_code,worker_second_action_header)


local client_data_load_header =[[

void client_data_load_code(const void *input, void *param, Event_data_CFL_t *event_data);

]]

local client_data_load_code = [[

static const char *client_data_load_code_data = "Worker input action output data\n";
void client_data_load_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   (void)input;
   Rpc_transfer_data_packet_CFL_t *transfer_data = (Rpc_transfer_data_packet_CFL_t *)param;
   
   transfer_data->data = (void *)client_data_load_code_data;
   transfer_data->data_type = 1;
   transfer_data->malloc_flag = false;
}



]]
Store_one_shot_function("RPC_DATA_LOAD",'client_data_load_code',client_data_load_code,client_data_load_header)



local client_data_verify_header =[[

void client_data_verify_code(const void *input, void *param, Event_data_CFL_t *event_data);

]]

local client_data_verify_code = [[


void client_data_verify_code(const void *input, void *param, Event_data_CFL_t *event_data){
   
   (void)event_data;
   Rpc_transfer_data_packet_CFL_t *transfer_data = (Rpc_transfer_data_packet_CFL_t *)param;
   if(transfer_data->data_type != 2){
       ASSERT_PRINT_INT(input,"data types do not match",transfer_data->data_type);
   }
   Printf_CFL(input,"Client data verify data type %d data %s \n",transfer_data->data_type,(char *)transfer_data->data);
}



]]
Store_one_shot_function("RPC_DATA_VERIFY",'client_data_verify_code',client_data_verify_code,client_data_verify_header)

local rpc_list = {"rpc_server"}
Define_RPC_queues(rpc_list,4)


define_columns({"test_duration"} )
define_columns({"rpc_server"},4,2)
define_columns({"rpc_client"})
define_columns({"rpc_worker_column"})


define_column("test_duration",true)
  Log_msg('starting test_duration')
  
  Wait_delay(20000)
  Log_msg('ending test_duration')
  terminate_engine()
end_column()

define_column("rpc_server",true)
  Use_rpc_queue("rpc_server") 
  Log_msg("rpc_server starting")
  
  Release_rpc_event()
  Process_rpc_request( {1,2,3,4}, "rpc_worker_column", 3500,false, "SERVER_TIME_OUT","(void *)server_time_out_data")

  Free_unused_rpc_event() 
  halt_column()
end_column()



define_column("rpc_client",true)
  Log_msg('starting rpc_client')

  
  Rpc_client_request_CFL("rpc_server",1,
                          "RPC_DATA_LOAD","NULL",
                          "RPC_DATA_VERIFY","NULL",
                          3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")

  Wait_delay(1000)
  Rpc_client_request_CFL("rpc_server",4,
                          "RPC_DATA_LOAD","NULL",
                          "RPC_DATA_VERIFY","NULL",
                          3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")

Rpc_client_request_CFL("rpc_server",5,
                          "RPC_DATA_LOAD","NULL",
                          "RPC_DATA_VERIFY","NULL",
                          3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")


                      
  Log_msg('ending rpc_client')
  terminate_column()    
end_column()


define_column("rpc_worker_column",false)
    Log_msg("rpc_worker_column starting","rpc_worker_column ending")
    One_shot("WORKER_FIRST_ACTION",'NULL')
    Wait_delay(2000)
    One_shot("WORKER_SECOND_ACTION",'NULL')
    terminate_column()
end_column()






dump_build()
