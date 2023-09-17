

local rpc_cleanup_one_shot_header = [[


int rpc_clean_up_one_shot(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local rpc_cleanup_one_shot_body = [[


int rpc_clean_up_one_shot(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)input;
    const char *user_data = (const char *)params;
    rpc_rom_message_CFL_t *rpc_message = (rpc_rom_message_CFL_t *)event_data->params;
    Printf_CFL("user data is %s\n",user_data);
    Printf_CFL("event  is %d\n",event_data->event_index);
    Printf_CFL("rpc message is %d\n",rpc_message->rpc_request_id);
    Printf_CFL("rpc message is %d\n",rpc_message->unique_id);
    Printf_CFL("rpc message is %d\n",rpc_message->destination_queue);
    Printf_CFL("rpc message is %d\n",rpc_message->receieved_queue);
    ASSERT_PRINT_F("unexpected rpc request %d\n",rpc_message->rpc_request_id);

}

]]

Store_one_shot_function("RPC_CLEAN_UP_FUNCTION","rpc_clean_up_one_shot", rpc_cleanup_one_shot_body ,rpc_cleanup_one_shot_header)

Store_user_code('const char clean_up_data[] = "clean up data for bad event";\n')

local service_handler_1_header = [[
    void   service_handler_1(const void *input,void *params, rpc_rom_message_CFL_t *data);
]]

local service_handler_1_body = [[
void    service_handler_1(const void *input,void *user_data, rpc_rom_message_CFL_t *data){
    (void)input;
    (void)user_data;
    rpc_ram_message_CFL_t *rpc_message = data->ram_message;
    Event_data_CFL_t *sent_event = &rpc_message->sent_event;
    Event_data_CFL_t *received_event = &rpc_message->received_event;
    sent_event->event_index = received_event->event_index +10;
    sent_event->malloc_flag = received_event->malloc_flag;
    sent_event->params = received_event->params; 

}

]]


Store_server_process_rpc_event("SERVICE_HANDLER_1",'service_handler_1',service_handler_1_body,service_handler_1_header)

local service_handler_2_header = [[
 void    service_handler_2(const void *input,void *user_data, rpc_rom_message_CFL_t *data);
]]

local service_handler_2_body = [[
    void    service_handler_2(const void *input,void *user_data, rpc_rom_message_CFL_t *data){
        (void)input;
        (void)user_data;
        rpc_ram_message_CFL_t *rpc_message = data->ram_message;
        Event_data_CFL_t *sent_event = &rpc_message->sent_event;
        Event_data_CFL_t *received_event = &rpc_message->received_event;
        sent_event->event_index = received_event->event_index +120;
        sent_event->malloc_flag = received_event->malloc_flag;
        sent_event->params = received_event->params; 
    
    }

]]


Store_server_process_rpc_event("SERVICE_HANDLER_2",'service_handler_2',service_handler_2_body,service_handler_2_header)

