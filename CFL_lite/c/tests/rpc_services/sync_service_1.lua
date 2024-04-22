set_h_file("sync_service_1.h")
local entry_point = "sync_service_1"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 





sync_server_no_wait_header = [[

void sync_server_no_wait(const void *input,void *param, Event_data_CFL_t *event_data);


]]


sync_server_no_wait_code = [[

int32_t sync_no_wait_data = 0;
void sync_server_no_wait(const void *input, void *param, Event_data_CFL_t *event_data){
    
    (void)event_data;
    (void) input;
    Rpc_data_CFL_t* rpc_data = (Rpc_data_CFL_t *)param;
    rpc_data->output_data_type = 1;
    sync_no_wait_data = sync_no_wait_data + 1;
    rpc_data->output =  (void *)&sync_no_wait_data;    
    rpc_data->output_malloc_flag = false;
    Printf_CFL(input,"receiver queue %d rpc_id %d\n",rpc_data->receiver_queue,rpc_data->rpc_id);
    Printf_CFL(input,"sync_server_no_wait %d\n",sync_no_wait_data);
    Printf_CFL(input,"input data type %d malloc flag %d data %d \n",rpc_data->input_data_type,rpc_data->input_malloc_flag,*(int32_t *)rpc_data->input);
    Printf_CFL(input,"output data type %d malloc flag %d data %d \n",rpc_data->output_data_type,rpc_data->output_malloc_flag,*(int32_t *)rpc_data->output);
    
}

]]


Store_one_shot_function("SYNC_SERVER",'sync_server_no_wait',sync_server_no_wait_code,sync_server_no_wait_header)


sync_data_load_header = [[

void sync_data_load_CFL(const void *input,void *param, Event_data_CFL_t *event_data);


]]


sync_data_load_code = [[

int32_t sync_data_load_data = 0;
void sync_data_load_CFL(const void *input, void *param, Event_data_CFL_t *event_data){
    
    (void)event_data;

    Rpc_data_CFL_t* rpc_data = (Rpc_data_CFL_t *)param;
    rpc_data->input_data_type = 0;
    sync_data_load_data = sync_data_load_data + 1;
    rpc_data->input =  (void *)&sync_data_load_data;    
    rpc_data->input_malloc_flag = false;
    
    Printf_CFL(input,"sync_data_load_CFL %d\n",sync_data_load_data);
    Printf_CFL(input,"receiver queue %d rpc_id %d\n",rpc_data->receiver_queue,rpc_data->rpc_id);
}

]]


Store_one_shot_function("SYNC_DATA_LOAD",'sync_data_load_CFL',sync_data_load_code,sync_data_load_header)


sync_data_verify_header = [[

void sync_data_verify_CFL(const void *input,void *param, Event_data_CFL_t *event_data);


]]


sync_data_verify_code = [[


void sync_data_verify_CFL(const void *input, void *param, Event_data_CFL_t *event_data){
    
    (void)event_data;
    Rpc_transfer_data_packet_CFL_t *transfer_data = (Rpc_transfer_data_packet_CFL_t *)param;
    Printf_CFL(input,"sync_data_verify_CFL\n");
    Printf_CFL(input,"Client data verify data type %d malloc flag %d data %d \n",transfer_data->data_type,transfer_data->malloc_flag,*(int32_t *)transfer_data->data);
 }
]]


Store_one_shot_function("SYNC_DATA_VERIFY",'sync_data_verify_CFL',sync_data_verify_code,sync_data_verify_header)



local rpc_list = {"sync_server_no_wait"}
Define_RPC_queues(rpc_list,4)


define_columns({"test_duration"} )
define_columns({"rpc_sync_server_no_wait"},4,2)
define_columns({"rpc_client_1", "rpc_client_2"})

 

define_column("test_duration",true)
  Log_msg('starting test_duration')
  
  Wait_delay(200000)
  Log_msg('ending test_duration')
  terminate_engine()
end_column()

define_column("rpc_sync_server_no_wait",true)
  Use_rpc_queue("sync_server_no_wait") 
  Log_msg("rpc_sync_server_no_wait starting")
  Sync_rpc_request_wait( "SYNC_SERVER",false)
  Log_msg("rpc_sync_server_no_wait starting")
  Wait_delay(1000)
  Log_msg("rpc_sync_server_no_wait ending")
  reset_column()
end_column()

define_column("rpc_client_1",true)
  Log_msg('starting rpc_client  1')

  Wait_delay(2000)
  Log_msg("rpc_client 1 request")
  Rpc_client_request_CFL("sync_server_no_wait",1,
                          "SYNC_DATA_LOAD","NULL",
                          "SYNC_DATA_VERIFY","NULL",
                          3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")
  reset_column()
end_column()    

define_column("rpc_client_2",true)
  Log_msg('starting rpc_client  2')

  Wait_delay(3000)
  Log_msg("rpc_client 1 request")
  Rpc_client_request_CFL("sync_server_no_wait",1,
                          "SYNC_DATA_LOAD","NULL",
                          "SYNC_DATA_VERIFY","NULL",
                          3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")
  reset_column()
end_column()    



dump_build()

