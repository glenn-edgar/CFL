

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
    Printf_CFL("rpc request is %d\n",rpc_message->rpc_request_id);
    Printf_CFL("uniqe id is %x\n",rpc_message->unique_id);
    Printf_CFL("destination queue is %d\n",rpc_message->destination_queue);
    Printf_CFL("receive queue is %d\n",rpc_message->receieved_queue);
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
    received_event->event_index = sent_event->event_index +10;
    received_event->malloc_flag = sent_event->malloc_flag;
    received_event->params = sent_event->params; 
    printf("service handler 1\n");

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
        received_event->event_index = sent_event->event_index +120;
        received_event->malloc_flag = sent_event->malloc_flag;
        received_event->params = sent_event->params; 
        printf("service handler 2\n");
    
    }

]]


Store_server_process_rpc_event("SERVICE_HANDLER_2",'service_handler_2',service_handler_2_body,service_handler_2_header)


local rpc_client_1_time_out_header = [[
    void rpc_client_1_time_out(const void *input,void *user_data, Event_data_CFL_t *data);

]]

local rpc_client_1_time_out_body = [[
    void rpc_client_1_time_out(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       (void)data;
       Printf_CFL("unexpected one second time out %s \n",(const char *)user_data);
    }   

]]

Store_one_shot_function("RPC_CLIENT_1_TIME_OUT","rpc_client_1_time_out", rpc_client_1_time_out_body ,rpc_client_1_time_out_header)





local rpc_client_1_generator_header = [[
    void rpc_client_1_generator(const void *input,void *user_data, Event_data_CFL_t *data);

]]


local rpc_client_1_generator_body = [[
    void rpc_client_1_generator(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       data->event_index = 100;
       data->malloc_flag = false;
       data->params = "rpc_client_recieved_event_1";
      

    }
]]

Store_generate_rpc_event('RPC_CLIENT_1_GENERATOR', 'rpc_client_1_generator', rpc_client_1_generator_body,rpc_client_1_generator_header)
                                 

local rpc_client_2_generator_header = [[
    void rpc_client_2_generator(const void *input,void *user_data, Event_data_CFL_t *data);

]]


local rpc_client_2_generator_body = [[
    void rpc_client_2_generator(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       data->event_index = 200;
       data->malloc_flag = false;
       data->params = "rpc_client_recieved_event_2";


    }
]]

Store_generate_rpc_event('RPC_CLIENT_2_GENERATOR', 'rpc_client_2_generator', rpc_client_2_generator_body,rpc_client_2_generator_header)

local rpc_client_3_generator_header = [[
    void rpc_client_3_generator(const void *input,void *user_data, Event_data_CFL_t *data);

]]


local rpc_client_3_generator_body = [[
    void rpc_client_3_generator(const void *input,void *user_data, Event_data_CFL_t *data){
       (void)input;
       (void)user_data;
       data->event_index = 300;
       data->malloc_flag = false;
       data->params = "rpc_client_recieved_event_3";


    }
]]

Store_generate_rpc_event('RPC_CLIENT_3_GENERATOR', 'rpc_client_3_generator', rpc_client_3_generator_body,rpc_client_3_generator_header)


--rpc_client_event_processor("PROCESS_EVENT_1",'"process event 1 user data"')


local rpc_client_event_processor_header_1 = [[
    void rpc_client_event_processor_1(const void *input,void *user_data, rpc_ram_message_CFL_t *data);

]]

local rpc_client_event_processor_body_1 = [[
    void rpc_client_event_processor_1(const void *input,void *user_data, rpc_ram_message_CFL_t *data){
       (void)input;
       (void)user_data;
       (void)data;
       Printf_CFL("process event 1 user data %s \n",(const char *)user_data);
       Printf_CFL("sent event  is %d\n",data->sent_event.event_index);
       Printf_CFL("recieved event  is %d\n",data->received_event.event_index);
       Printf_CFL("sent event  is %d\n",data->sent_event.malloc_flag);
       Printf_CFL("recieved event  is %d\n",data->received_event.malloc_flag);
       Printf_CFL("sent event  is %s\n",(const char *)data->sent_event.params);
       Printf_CFL("recieved event  is %s\n",(const char *)data->received_event.params);
    }   

]]

Store_client_process_rpc_event("PROCESS_EVENT_1",'rpc_client_event_processor_1',rpc_client_event_processor_body_1,rpc_client_event_processor_header_1)