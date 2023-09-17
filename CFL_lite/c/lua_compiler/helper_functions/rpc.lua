

--[[

typedef struct rpc_ram_message_t
{    

  Event_data_CFL_t sent_event;
  Event_data_CFL_t received_event;
} rpc_ram_message_CFL_t;


typedef struct rpc_rom_message_t
{
  unsigned short    rpc_request_id;
  unsigned short    unique_id;  // insuring that rpc message is valid
  unsigned short    destination_queue;
  unsigned short    receieved_queue;
  rpc_ram_message_CFL_t *ram_message;
} rpc_rom_message_CFL_t;

#define RPC_MESSAGE_ID_CFL 0xdeadbeef
#define RPC_EVENT_CFL 0xbeefdead

typedef void (*Generate_RPC_event_CFL_t )(const void *input, rpc_rom_message_CFL_t *params);
typedef void (*Process_RPC_event_CFL_t )(const void *input, rpc_ram_message_CFL_t *params);

]]


local rpc_client_event_generator_header = [[

int rpc_client_event_generator_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);

]]

local rpc_client_event_generator_body = [[

int rpc_client_event_generator_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){
  Generate_RPC_event_CFL_t generate_rpc_event = (Generate_RPC_event_CFL_t)aux_fn;
  rpc_rom_message_CFL_t *rpc_message = (rpc_rom_message_CFL_t *)params;
  if(event_data->event_index == RPC_EVENT_CFL){
    generate_rpc_event(input,rpc_message); 
    Event_data_CFL_t event_data_to_send = ( RPC_EVENT_CFL, false,(void *)rpc_message);
    enqueue_event_CFL(input,rpc_message->destination_queue, &event_data_to_send);
    return DISABLE_CFL;
  }
  return DISABLE_CFL;
}

]]

Store_column_function("RPC_CLIENT_EVENT_GENERATOR","rpc_client_event_generator_CFL", rpc_client_event_generator_body,rpc_client_event_generator_header)



function generate_rpc_event(rpc_event_generator_fn,destination_queue,request_id)
  if( active_column == nil) then
    error("generate_rpc_event must be called inside a column function")
  end
  receieved_queue = active_column["queue_name"] 
  local aux_fn = Get_generate_rpc_event(rpc_event_generator_fn)
  Activate_one_shot_function(client_server_fn)
  local unique_ram_name = generate_unique_function_name()
  local message = string.format("rpc_ram_message_CFL_t %s;\n",unique_ram_name)
  Store_user_code(message)
  local unique_name = generate_unique_function_name()
  local message = string.format("const rpc_rom_message_CFL_t %s = {%s,RPC_MESSAGE_ID_CFL,%s,%s,&s};\n",unique_name,request_id,destination_queue,receieved_queue,unique_ram_name)
  Store_user_code(message)
  column_fn = Get_column_function("RPC_CLIENT_EVENT_GENERATOR")
  Activate_column_function("RPC_CLIENT_EVENT_GENERATOR")
  store_column_element("RPC_CLIENT_EVENT_GENERATOR",aux_fn,"(void *)&"..unique_name)
end

local rpc_client_event_processor_header = [[

int rpc_client_event_processor_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);

]]

local rpc_client_event_processor_body = [[

  
  
  
  int rpc_client_event_processor_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){
    Client_Process_RPC_event_CFL_t client_process_rpc_event = (Client_Process_RPC_event_CFL_t)aux_fn;
    if(event_data->event_index == RPC_EVENT_CFL){
      rpc_ram_message_CFL_t *rpc_message = (rpc_ram_message_CFL_t *)event_data->event_data;
      if(rpc_message->unique_id != RPC_MESSAGE_ID_CFL){
          ASSERT_PRINT_F("unique id is not valid expected %x got %x\n",RPC_MESSAGE_ID_CFL,rpc_message->unique_id);
      }
      client_process_rpc_event(input,params,rpc_message);
      if(rpc_message->ram_message.sent_event.malloc_flag == true){
        private_heap_free_CFL(input,rpc_message->ram_message.sent_event.event_data);
      }
      if(rpc_message->ram_message.received_event.malloc_flag == true){
        private_heap_free_CFL(input,rpc_message->ram_message.received_event.event_data);
      }
      return HALT_CFL;
    }



  }
  


]]

Store_column_function("RPC_CLIENT_EVENT_PROCESSOR","rpc_client_event_processor_CFL", rpc_client_event_processor_body,rpc_client_event_processor_header)

function rpc_client_event_processor(client_process_event_fn,user_data)
  local aux_fn = Get_client_process_event(client_process_event_fn)
  column_fn = Get_column_function("RPC_CLIENT_EVENT_PROCESSOR")
  Activate_column_function("RPC_CLIENT_EVENT_PROCESSOR")
  if(user_data ~= 'NULL') then
    store_column_element("RPC_CLIENT_EVENT_PROCESSOR",aux_fn,"(void *)&"..user_data)
  else
    store_column_element("RPC_CLIENT_EVENT_PROCESSOR",aux_fn,"NULL")
  end
end






local rpc_server_event_processor_header = [[

typedef struct rpc_server_event_processor_CFL_t
{
  void *user_data;
  unsigned short rpc_request_number;
  const unsigned short *rpc_request_list;
} rpc_server_event_processor_CFL_t;


int rpc_server_event_processor_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);

]]


local rpc_server_event_processor_body = [[

int rpc_server_event_processor_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){

  Server_Process_RPC_event_CFL_t  server_process_rpc_event = (Server_Process_RPC_event_CFL_t)aux_fn;
  rpc_server_event_processor_CFL_t *rpc_server_event_processor = (rpc_server_event_processor_CFL_t *)params;
  
  if(event_data->event_index == RPC_EVENT_CFL){
    rpc_rom_message_CFL_t *rpc_message = (rpc_rom_message_CFL_t *)event_data->params;
    for(unsigned i = 0; i< rpc_server_event_processor->rpc_request_number; i++){
      if(rpc_message->rpc_request_id == rpc_server_event_processor->rpc_request_list[i]){
    
        
        if(rpc_message->unique_id != RPC_MESSAGE_ID_CFL){
          ASSERT_PRINT_F("unique id is not valid expected %x got %x\n",RPC_MESSAGE_ID_CFL,rpc_message->unique_id);
        }

        server_process_rpc_event(input,rpc_server_event_processor->user_data,rpc_message);
        enqueue_event_CFL(input,rpc_message->receieved_queue, event_data);
        return HALT_CFL;
        

      }
    }
  }

  return CONTINUE_CFL;
}

]]

Store_column_function("RPC_SERVER_EVENT_PROCESSOR","rpc_server_event_processor_CFL", rpc_server_event_processor_body,rpc_server_event_processor_header)



function store_server_event_process(server_fn_name,user_data,rpc_request_list)
  aux_fn =  Get_server_process_event(server_fn_name)
  local request_list = generate_unique_function_name()
  local message = string.format("const unsigned short %s[] = {",request_list)
  Store_user_code(message)
  message = table.concat( rpc_request_list, ", ").."};\n"
  Store_user_code(message)
  local unique_name = generate_unique_function_name()
  message = string.format("const rpc_server_event_processor_CFL_t %s = {%s,%s,%s};\n",unique_name,user_data,#rpc_request_list,request_list)
  Store_user_code(message)
  column_fn = Get_column_function("RPC_SERVER_EVENT_PROCESSOR")
  Activate_column_function("RPC_SERVER_EVENT_PROCESSOR")
  store_column_element(column_fn,aux_fn,"(void *)&"..unique_name)
end



local rpc_server_event_clean_up_header = [[

typedef struct rpc_server_event_clean_up_CFL_t
{
  void *user_data;
  bool terminate_flag;
} rpc_server_event_clean_up_CFL_t;

int rpc_server_event_clean_up_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);


]]

local rpc_server_event_clean_up_body = [[

int rpc_server_event_clean_up_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data){
  One_shot_function_CFL_t one_shot_fn = (One_shot_function_CFL_t )aux_fn;
  rpc_server_event_clean_up_CFL_t *rpc_server_event_clean_up = (rpc_server_event_clean_up_CFL_t *)params;
  
  if(event_data->event_index == RPC_EVENT_CFL){
    // unhandled rpc message
    one_shot_fn(input,rpc_server_event_clean_up->user_data,event_data);
    if(rpc_server_event_clean_up->terminate_flag==true){
      return TERMINATE_CFL;
    }else{
      return RESET_CFL;
    }
  }

  return CONTINUE_CFL;
}


]]

Store_column_function("RPC_SERVER_EVENT_CLEAN_UP","rpc_server_event_clean_up_CFL", rpc_server_event_clean_up_body,rpc_server_event_clean_up_header)

function rpc_event_clean_up(cleanup_fun,user_data,terminate_flag)
  local aux_fn = Get_one_shot_function(cleanup_fun)
  Activate_one_shot_function(cleanup_fun)
  local unique_name = generate_unique_function_name()
  local message = string.format("rpc_server_event_clean_up_CFL_t %s = {%s,%s};\n",unique_name,user_data,terminate_flag)
  Store_user_code(message)
  column_fn = Get_column_function("RPC_SERVER_EVENT_CLEAN_UP")
  Activate_column_function("RPC_SERVER_EVENT_CLEAN_UP")
  store_column_element(column_fn,aux_fn,"(void *)&"..unique_name)
end