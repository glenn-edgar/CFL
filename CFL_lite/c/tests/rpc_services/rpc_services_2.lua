set_h_file("rpc_services_2.h")
local entry_point = "rpc_services_handle_2"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 








local rpc_list = {"rpc_server_no_response"}
Define_RPC_queues(rpc_list,4)


define_columns({"test_duration"} )
define_columns({"rpc_server_no_response"},4,2)
define_columns({"rpc_client_2"})
define_columns({"rpc_worker_time_out_column"})
 

define_column("test_duration",true)
  Log_msg('starting test_duration')
  
  Wait_delay(20000)
  Log_msg('ending test_duration')
  terminate_engine()
end_column()



define_column("rpc_server_no_response",true)
  Use_rpc_queue("rpc_server_no_response") 
  Log_msg("rpc_server_no_response starting")
  Release_rpc_event()
  Process_rpc_request( {1,2,3,4}, "rpc_worker_time_out_column", 3500,false, "SERVER_TIME_OUT","(void *)server_time_out_data")
  Trap_unused_rpc_events() 
  Free_unused_rpc_event() 
  Wait_delay(5000)
  Log_msg("rpc_server_no_response ending")
  halt_column()
end_column()



define_column("rpc_client_2",true)
  Log_msg('starting rpc_client')

  
  Rpc_client_request_CFL("rpc_server_no_response",1,
                          "RPC_DATA_LOAD","NULL",
                          "RPC_DATA_VERIFY","NULL",
                          3000,true,"CLIENT_TIME_OUT","(void *)time_out_data")
halt_column()
end_column()


define_column("rpc_worker_time_out_column",false)
    Log_msg("rpc_worker_column time out starting","rpc_worker_column rpc worker column  ending")
    One_shot("WORKER_FIRST_ACTION",'NULL')
    Wait_delay(7000)
    One_shot("WORKER_SECOND_ACTION",'NULL')
    terminate_column()
end_column()




dump_build()
