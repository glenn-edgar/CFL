
local  rpc_queue_list = {}
local rpc_queue_position = {}
local rpc_queue_size = {}
local rpc_data_queue_names = {}


---
--- CFL Assembler RPC functions
---










local release_rpc_header = [[



typedef struct Release_rpc_event_CFL_t
{
    bool  *release_state;
    const uint16_t queue_id;
} Release_rpc_event_CFL_t;        


int release_rpc_request_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]






local release_rpc_code = [[

const Event_data_CFL_t new_rpc_event_CFL = { RPC_NEW_EVENT, false, NULL};


int release_rpc_request_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Release_rpc_event_CFL_t *release_rpc = (Release_rpc_event_CFL_t *)params;
    if( event_data->event_index == EVENT_INIT_CFL ){
        *release_rpc->release_state = false;
        return CONTINUE_CFL;
    
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL  ){
        reset_rpc_queue_CFL(input,release_rpc->queue_id);
        return CONTINUE_CFL;
    }
    if( event_data->event_index == TIMER_TICK_CFL ){
        if(*release_rpc->release_state == false){
            if( get_rpc_queue_number_CFL(input,release_rpc->queue_id) > 0){
                *release_rpc->release_state = true;
                uint16_t column_index =  get_current_column_index_CFL(input);
                front_enqueue_column_index_event_CFL(input, column_index,(Event_data_CFL_t *) &new_rpc_event_CFL);
                return HALT_CFL;
                
            }
         }
    }
    if( event_data->event_index == RPC_ACTION_COMPLETE_CFL ){
        if(*release_rpc->release_state == false){
            if( get_rpc_queue_number_CFL(input,release_rpc->queue_id) > 0){
                *release_rpc->release_state = true;
                uint16_t column_index =  get_current_column_index_CFL(input);
                front_enqueue_column_index_event_CFL(input, column_index,(Event_data_CFL_t *) &new_rpc_event_CFL);

            }
         }
         return HALT_CFL;
    }
    return CONTINUE_CFL;

}

]]


    

Store_column_function("RELEASE_RPC","release_rpc_request_CFL",release_rpc_code,release_rpc_header)

function Release_rpc_event() 
    local rpc_queue = get_rpc_queue()
    local rpc_queue_number = rpc_queue_position[rpc_queue]

    local bool_state = generate_unique_function_name()
    local message = string.format("bool %s = false;\n",bool_state)
    Store_user_code(message)

    local rpc_structure_name = generate_unique_function_name()
    message = string.format("const Release_rpc_event_CFL_t %s = { &%s, %d};\n",rpc_structure_name,bool_state,rpc_queue_number)
    Store_user_code(message)
    column_fn = Get_column_function("RELEASE_RPC")
    store_column_element( column_fn,"NULL","(void *)&"..rpc_structure_name)

end

local process_rpc_event_header = [[


typedef struct Process_rpc_CFL_t
{
    uint16_t *elasped_time;
    uint16_t *state;
    const uint16_t queue_id;
    const uint16_t rpc_number;
    const uint16_t *rpc_id_list;
    const uint16_t column_id;
    const uint16_t time_out_ms;
    const bool  terminate_flag;
    void *user_data;
} Process_rpc_CFL_t;


int process_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]



local process_rpc_event_code = [[
const Event_data_CFL_t rpc_client_event_CFL = { RPC_CLIENT_RESULT_CFL, false, NULL};
const Event_data_CFL_t action_complete_event_CFL = { RPC_ACTION_COMPLETE_CFL, false, NULL};

int process_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    One_shot_function_CFL_t rpc_error_fn = (One_shot_function_CFL_t )aux_fn;
    Process_rpc_CFL_t *process_rpc = (Process_rpc_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        *process_rpc->state = 0;
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        if(*process_rpc->state != 0){
            uint16_t column_index =  process_rpc->column_id;
            disable_column_CFL(input,column_index);
            Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,process_rpc->queue_id);
            column_index =  rpc_event->receiver_queue-1;
            disable_column_CFL(input,column_index);  // disable the sender
        }
        return CONTINUE_CFL;
    }
    if(event_data->event_index == RPC_NEW_EVENT){
        if(*process_rpc->state != 0){
            ASSERT_PRINT_F(input,"Received RPC NEW EVENT BEFORE COMPLETING CURRENT EVENT  server queue %d \n",process_rpc->queue_id);
        }
        Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,process_rpc->queue_id);
        for(int i = 0; i < process_rpc->rpc_number; i++){
            if(rpc_event->rpc_id == process_rpc->rpc_id_list[i]){
                uint16_t column_index =  process_rpc->column_id;
                store_column_data_CFL(input, column_index, (void *)&process_rpc->queue_id);
                reset_column_CFL(input,column_index);
                *process_rpc->elasped_time = 0;
                *process_rpc->state = 1;
                return HALT_CFL;
            }
        }
        *process_rpc->state = 0;
        return CONTINUE_CFL;
    }
    if(event_data->event_index == TIMER_TICK_CFL){
        if(*process_rpc->state == 0){
            return CONTINUE_CFL;
        }
        if(get_column_state_CFL(input, process_rpc->column_id) == false){
            Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,process_rpc->queue_id);
            uint16_t column_index =  rpc_event->receiver_queue-1;
            chain_single_sweep_CFL(input, column_index,(Event_data_CFL_t *) &rpc_client_event_CFL);
            dequeue_Rpc_data_CFL(input,process_rpc->queue_id);
            *process_rpc->state = 0;
            uint16_t current_column_id = get_current_column_index_CFL(input);
            front_enqueue_column_index_event_CFL(input, current_column_id,(Event_data_CFL_t *) &action_complete_event_CFL);
            return HALT_CFL;

        }

        if(process_rpc->time_out_ms <= 0){
            return HALT_CFL;
        }
        *process_rpc->elasped_time += *(int *)event_data->params;
        if(*process_rpc->elasped_time > process_rpc->time_out_ms){
           rpc_error_fn(input,process_rpc,event_data);
        }
        if(process_rpc->terminate_flag == true){
            return TERMINATE_CFL;
        }
        return RESET_CFL;
    }
    if(*process_rpc->state == 0){
        return CONTINUE_CFL;
    }
    return HALT_CFL;
}


]]

Store_column_function("PROCESS_RPC","process_rpc_event_CFL",process_rpc_event_code,process_rpc_event_header)


function Process_rpc_request( rpc_id_list, worker_column_name, time_out_ms, terminate_flag, rpc_error_handler,user_data)
    local rpc_queue = get_rpc_queue()
    local rpc_queue_number = rpc_queue_position[rpc_queue]
    local worker_column = get_column_number(worker_column_name)
    local rpc_error_fn = Get_one_shot_function(rpc_error_handler)

    local elasped_time = generate_unique_function_name()
    local message = string.format("uint16_t %s = 0;\n",elasped_time)
    Store_user_code(message)
    local state_name = generate_unique_function_name()
    message = string.format("uint16_t %s = 0;\n",state_name)
    Store_user_code(message)
    local rpc_id_list_name = generate_unique_function_name()
    message = string.format("const uint16_t %s[] = { %s };\n",rpc_id_list_name,table.concat(rpc_id_list,","))
    Store_user_code(message)
    local rpc_structure_name = generate_unique_function_name()
    message = string.format("const Process_rpc_CFL_t %s = { &%s, &%s, %d, %d, %s, %d, %d, %s, %s};\n",rpc_structure_name,elasped_time,state_name,rpc_queue_number,#rpc_id_list,rpc_id_list_name,worker_column,time_out_ms,terminate_flag,user_data)
    Store_user_code(message)
    local column_fn = Get_column_function("PROCESS_RPC")
    store_column_element(column_fn,rpc_error_fn,"(void *)&"..rpc_structure_name)
    
end



local trap_rpc_header = [[

typedef struct Trap_rpc_event_CFL_t
{
    const uint16_t queue_id;

} Trap_rpc_event_CFL_t;

int trap_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local trap_rpc_code = [[
int trap_rpc_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Trap_rpc_event_CFL_t *trap_rpc = (Trap_rpc_event_CFL_t *)params;
    if(event_data->event_index == RPC_NEW_EVENT){
        Rpc_data_CFL_t *rpc_event =   peak_rpc_data_CFL(input,trap_rpc->queue_id);
        ASSERT_PRINT_F(input,"UNHANDLED RPC EVENT  request id  %d  receiver queue %d \n",rpc_event->rpc_id,rpc_event->receiver_queue);
    }
    return CONTINUE_CFL;
}
]]

Store_column_function("TRAP_RPC_EVENT","trap_rpc_event_CFL",trap_rpc_code,trap_rpc_header)    


function Trap_unused_rpc_events() 
    local rpc_queue = get_rpc_queue()
    local rpc_queue_number = rpc_queue_position[rpc_queue]
    local unique_name = generate_unique_function_name()
    local message = string.format("const Trap_rpc_event_CFL_t %s = { %d};\n",unique_name,rpc_queue_number)
    Store_user_code(message)
    local column_fn = Get_column_function("TRAP_RPC_EVENT")
    store_column_element(column_fn,"NULL","(void *)&"..unique_name)
end


local rpc_client_header = [[

   typedef struct Rpc_client_CFL_t
   {
       const uint16_t queue_id;
       const uint16_t rpc_id;
       const uint16_t data_length;
       void *data;
       const bool malloc_flag;
       One_shot_function_CFL_t rpc_handler;
   } Rpc_client_CFL_t;

int rpc_client_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);
]]

local rpc_client_code = [[

int rpc_client_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Rpc_client_CFL_t *rpc_client = (Rpc_client_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        enqueue_rpc_request_CFL(input,rpc_client->queue_id,rpc=>rpc_id,rpc_client=>data_length,rpc_client->data,rpc_client->malloc_flag );
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        // do nothing for now
        return CONTINUE_CFL;
    }
    if(event_data->event_index == RPC_CLIENT_RESULT_CFL){
        Rpc_data_CFL_t* rpc_data = peak_rpc_data_CFL(input,rpc_client->queue_id);
        rpc_client->rpc_handler(input, rpc_data, event_data);
        return HALT_AND_DISABLE_CFL;
    }
    return HALT_CFL;
} 


]]

Store_column_function("RPC_CLIENT","rpc_client_CFL",rpc_client_header,rpc_client_code)

function Rpc_client_request_CFL(queue_name,rpc_id,data_length,data,malloc_flag,rpc_client_handler )
    
    local queue_number = rpc_queue_position[queue_name]
    local rpc_handler = Get_one_shot_function(rpc_client_handler)
    local unique_name = generate_unique_function_name()
    if data == 'NULL' then
        data = 'NULL'
    else
        data = '(void *)&'..data
    end
    local message = string.format("const Rpc_client_CFL_t %s = { %d, %d, %d, %s, %s, %s};\n",unique_name,queue_number,rpc_id,data_length,data,malloc_flag,rpc_handler)
    Store_user_code(message)
    store_column_element("RPC_CLIENT","NULL,(void *)&"..unique_name)
end



local function dump_ram_data_structures()
    rpc_data_queue_names = {}
     
     queue_ram_name = generate_unique_function_name()
     build_status["rpc_queue_ram"] = queue_ram_name
     write_output("\n\n//----------RAM data structures for rpc queues ----\n\n")
     format_string = "static RPC_Packet_control_RAM_CFL_t %s[%d];\n"
    local message = string.format(format_string, queue_ram_name,#rpc_queue_list)
    write_output(message)
  
    for i,queue_name in ipairs(rpc_queue_list) do
      local size = rpc_queue_size[queue_name]
     
      local rpc_queue_name = generate_unique_function_name()
      table.insert(rpc_data_queue_names,rpc_queue_name)
      format_string = "static Rpc_data_CFL_t   %s[%d];\n"

     
      local message = string.format(format_string,rpc_queue_name,size)
      write_output(message)
    end
     
  
  
     
  end
  
  local function dump_rom_array_structures()
    build_status["rpc_queue_number"] = #rpc_queue_list
    for i,queue_name in ipairs(rpc_queue_list) do
      local size = rpc_queue_size[queue_name]
      format_string = "     {  %d, %s },\n"
      message = string.format(format_string,size,rpc_data_queue_names[i])
      write_output(message)
    end
  end
  
  
  local function dump_rom_data_structures()
    write_output("\n\n//------  ROM data structures for rpc queues ----\n\n")
    rpc_rom_name = generate_unique_function_name()
    build_status["rpc_queue_rom"] = rpc_rom_name
    format_string = "static const RPC_Packet_control_ROM_CFL_t  %s[] = { \n"
    local message = string.format(format_string,rpc_rom_name)
    write_output(message)
    dump_rom_array_structures()
    write_output("};\n")
  end
  
  
  
  
  function dump_rpc_queues()

      dump_ram_data_structures()
      dump_rom_data_structures()
  
   end

   function Define_RPC_queues(queue_list,queue_size)
    for i,queue in ipairs(queue_list) do
        if rpc_queue_position[queue] ~= nil then
            assert(false,"RPC queue "..queue.." already defined")
        end
        rpc_queue_position[queue] = #rpc_queue_list
        rpc_queue_size[queue] = queue_size
        
        table.insert(rpc_queue_list,queue)
    end 

end

function Use_rpc_queue(queue_name) 
    assert(rpc_queue_position[queue_name] ~= nil,"RPC queue "..queue_name.." not defined")
    add_rpc_queue(queue_name)
end

