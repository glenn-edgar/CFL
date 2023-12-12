set_h_file("rpc_services.h")
local entry_point = "rpc_services_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')

dofile("application_functions.lua")


define_columns({"start_column","rpc_server_column","rpc_client_column1","rpc_client_column2","rpc_client_column3"})

define_column("start_column",true,nil)
    Log_msg('start column')
    Enable_columns({"rpc_server_column","rpc_client_column1","rpc_client_column2","rpc_client_column3"},true)
    Wait_delay(60000)
    Log_msg('terminating')
    terminate_column()
end_column()


define_column("rpc_server_column",false,"server_queue")
    store_server_event_process("SERVICE_HANDLER_1",'NULL',{11,12,13,14,15})
    store_server_event_process("SERVICE_HANDLER_2",'NULL',{21,22,23,24,25})
    rpc_event_clean_up("RPC_CLEAN_UP_FUNCTION","(void *)clean_up_data",true)
    halt_column()
end_column()


define_column("rpc_client_column1",false,"client_queue1")
    generate_rpc_event("RPC_CLIENT_1_GENERATOR","server_queue",13)
    Wait_event(rpc_event_id, 1, 1000, true, "RPC_CLIENT_1_TIME_OUT", '"unexpected one second time out"')
    rpc_client_event_processor("PROCESS_EVENT_1",'"process event 1 user data"')
    Wait_delay(5000)
    reset_column()
end_column()

define_column("rpc_client_column2",false,"client_queue2")
    generate_rpc_event("RPC_CLIENT_2_GENERATOR","server_queue",23)
    rpc_client_event_processor("PROCESS_EVENT_1",'"process event 2 user data"')
    Wait_delay(5000)
    reset_column()
end_column()


define_column("rpc_client_column3",false,"client_queue3")
    Wait_delay(45000)
    generate_rpc_event("RPC_CLIENT_3_GENERATOR","server_queue",33)
    rpc_client_event_processor("PROCESS_EVENT_1",'"process event 3 user data"')
    Wait_delay(45000)
    reset_column()
end_column()

dump_build()