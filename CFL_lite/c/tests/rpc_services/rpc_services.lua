set_h_file("rpc_services.h")
local entry_point = "rpc_services_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 

local rpc_client_setup_header = [[

void rpc_client_setup(const void *input, void* params, Event_data_CFL_t* event_data);

]]

local rpc_client_setup_code = [[

static const char rpc_client_setup_data[] = "rpc_client_setup_data";

void rpc_client_setup(const void *input, void* params, Event_data_CFL_t* event_data)
{
    (void)input;
    (void)event_data;
    RPC_CLIENT_DATA_EXCHANGE_t *rpc_client_data = (RPC_CLIENT_DATA_EXCHANGE_t *)params;
    rpc_client_data->rpc_client_data = rpc_client_setup_data;
    rpc_client_data->rpc_client_data_size = sizeof(rpc_client_setup_data);

}


]]

Store_one_shot_function("RPC_CLIENT_SETUP","rpc_client_setup", rpc_client_setup_header, rpc_client_setup_code)





local rpc_list = {"rpc_1","rpc_2","rpc_3","rpc_4"}
Define_RPC_queues(rpc_list,4)


define_columns({"test_duration","rpc_client"} )
define_columns({"rpc_server"},4)
define_columns({"rpc_worker_column"})


define_column("test_duration",true)
  Log_msg('starting test_duration')
  Wait_delay(20000)
  Log_msg('ending test_duration')
  terminate_engine()
end_column()



define_column("rpc_client",true)
  Log_msg('starting rpc_client')
  Rpc_client_request_CFL("rpc_1",1, rpc_client_setup,rpc_client_process, timeout, rpc_error_handler, 'NULL')
  Log_msg('ending rpc_client')
  terminate_column()    
end_column()


define_column("rpc_server",true)
  Use_rpc_queue("rpc_1") 
  Log_msg("rpc_server starting")
  
  Release_rpc_event()
  Process_rpc_request( {1,2,3,4}, "rpc_worker_column", -1,false, 'NULL','NULL')
  Trap_unused_rpc_events() 
  halt_column()
end_column()

define_column("rpc_worker_column",false)
    Log_msg("rpc_worker_column starting")
  terminate_column()
end_column()





dump_build()
