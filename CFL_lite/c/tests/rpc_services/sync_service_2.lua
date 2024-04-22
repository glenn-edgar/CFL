set_h_file("sync_service_2.h")
local entry_point = "sync_service_2"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 







local rpc_list = {"sync_server_1","sync_server_2"}
Define_RPC_queues(rpc_list,4)


define_columns({"test_duration"} )
define_columns({"sync_element_1","sync_element_2"},4,2)

 

define_column("test_duration",true)
  Log_msg('starting test_duration')
  Reset_RCP_Queue("sync_server_1")
  Reset_RCP_Queue("sync_server_2")
  Wait_delay(20000)
  Log_msg('ending test_duration')
  terminate_engine()
end_column()

define_column("sync_element_1",true)
  Log_msg('starting column sync_element_1')
  Use_rpc_queue("sync_server_1") 
  Wait_delay(1000)
  Log_msg("sync_element_1 server wait")
  Sync_rpc_request_wait( "SYNC_SERVER",true)
  Log_msg("sync_element_1 client wait")
  Rpc_client_request_CFL("sync_server_2",1,
     "SYNC_DATA_LOAD","NULL",
     "SYNC_DATA_VERIFY","NULL",
     3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")
  reset_column()
end_column()

define_column("sync_element_2",true)
Log_msg('starting column sync_element_2')
  Use_rpc_queue("sync_server_2") 
  Log_msg("sync_element_2 client wait")
  Rpc_client_request_CFL("sync_server_1",1,
     "SYNC_DATA_LOAD","NULL",
     "SYNC_DATA_VERIFY","NULL",
     3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")
  Wait_delay(1000)
  Log_msg("sync_element_1 server wait")
  Sync_rpc_request_wait( "SYNC_SERVER",true)
  reset_column()
end_column()








dump_build()
