
--- event functions
event_queue_table = {}


function Define_event_queue(queue_name,queue_size)
    queue_name = quote_string(queue_name)
    event_queue_table[queue_name] = queue_size
    local message = string.format("    Define_named_event_queue_CFL(input,%s,%s);\n",tostring(queue_name),tostring(queue_size))
    file:write(message)
end


function Generate_event(event_name, event_id,event_value,event_param)
       
    local message = string.format("    Event_data_CFL_t %s = { %s, %s, %s};\n",tostring(event_name),tostring(event_id),tostring(event_value),tostring(event_param))
     file:write(message)    
end        

function Send_event(event)
 local message = string.format("    Asm_send_event_CFL(input,%s);\n",tostring(event))
 file:write(message)
end

function Generate_event_queue_names(queue_name,queue_list)
    
    local return_value = {}
    return_value.queue_number = #queue_list

    local queue_arrary  = table.concat(queue_list,",")
  
    local message = string.format("    const char *%s[] = {%s};\n",queue_name,queue_arrary)
   
    file:write(message)
    return_value.array_name = queue_name
    
    return return_value
end

function Send_event_queue(queue_table,event_data_ptr)
    
    array_name = queue_table.array_name
    queue_number = queue_table.queue_number
    
    message = string.format("     Asm_send_named_events_CFL(input,%s,%s,%s);\n",queue_number,array_name,event_data_ptr)
    
    file:write(message)
   
end

function Reset_event_queues(queue_table)
   
    local array_name = queue_table.array_name
    local queue_number = queue_table.queue_number
    message = string.format("     Asm_reset_named_event_queues_CFL(input,%s,%s);\n",queue_number,array_name)
    file:write(message)
end

---
--- RPC functions
---
function Send_client_rpc_CFL(rpc_event_id, rpc_request_id, client_queue_name, server_queue_name,
    client_free_message_data, client_data_size, client_message_data)
local message = string.format("    Asm_send_rpc_CFL(input,%s,%s,%s,%s,%s,%s,%s);\n",
                  rpc_event_id, rpc_request_id, client_queue_name, server_queue_name,
                  client_free_message_data, client_data_size, client_message_data)
file:write(message)
end

function Wait_for_client_rpc_CFL(rpc_event,message_handler,user_data)
    local message = string.format("    Asm_wait_for_client_rpc_CFL(input,%s,%s,%s);\n",
                                           rpc_event,message_handler,user_data)
    file:write(message)
end

function Wait_for_server_rpc_CFL(rpc_event,bool_function,user_data)
    local message = string.format("    Asm_wait_for_server_rpc_CFL(input,%s,%s,%s);\n",
                                           rpc_event,bool_function,user_data)
    file:write(message)
end

function Dispose_RPC_event_CFL(rpc_event,flag,message_handler,user_data)
    local message = string.format("    Asm_dispose_rpc_event_CFL(input,%s,%s,%s,%s);\n",rpc_event,flag,
                                             message_handler,user_data)
 
    file:write(message)
end
---
--- this is originally for column state machine
--- the event handler is a one shot function
--- the Asm_process_event_CFL generates the following data structure
--- typedef struct process_event_t_CFL
---{
---    unsigned short event_number;
---    short *event_indexes;  -- used by outer function to determine which events to act on
---    bool block_flag;       -- for matched events deterime where they are blocked
---                           -- true means return HALT_CFL
---                           -- false means return CONTINUE_CFL
---                           -- for unmatched events the result is always CONTINUE_CFL
---    short return_value;    -- return value for matched events
---                           -- initialy set but can be changed by the one shot function
---    void *user_data;       -- user data passed to the one shot function
---} process_event_t_CFL;
--- The one shot function is passed this structure
--- setting the return_value field will determine the result

function Store_event_filter(event_handler_name,event_name, event_list, user_data,block_flag)
    event_name         = tostring(event_name)
    block_flag         = tostring(block_flag)
    return_value       = tostring(return_value)
    user_data          = tostring(user_data)
    event_handler_name = quote_string(event_handler_name)
    
    generate_event_list(event_name,event_list)
    local message = string.format("    Asm_filter_events_CFL(input,%s,%d,%s,%s,%s);\n",
                                    event_handler_name,#event_list,event_name,block_flag,user_data)
    file:write(message)
end

--- this handler generates the following data structure
--- typedef struct Event_handler_fn_CFL_t {
---    bool                    event_flag;  -- used for sending the init to the column handler function
---    bool                    activate_flag;  -- set false not used
---    void* user_data;     -- data that is passed to the column handler function
--    unsigned short          event_number;  -- outer function sets this
--   short* event_indexes;    --- events that are passed to the column handler function
-- }Event_handler_fn_CFL_t;
--- A HALT_CFL is returned for unmatched events
--- The column function is used to return the return code for matched events

function Store_event_handler(event_array_name,event_indexes,column_handler,user_data)
    generate_event_list(event_array_name,event_indexes)
    column_handler = tostring(column_handler)
    user_data = tostring(user_data)
    local message = string.format("    Asm_attach_event_handler_CFL(input,%s,%s,%s,%s);\n",
                                    event_array_name,#event_indexes,column_handler,user_data)
    file:write(message)
end

---
--- this is originally for column state machine
--- the event handler is a one shot function
--- the Asm_process_event_CFL generates the following data structure
--- typedef struct process_event_t_CFL
---{
---    unsigned short event_number;
---    short *event_indexes;  -- used by outer function to determine which events to act on
---    bool block_flag;       -- for unmatchted events deterime where they are blocked
---                           -- true means return HALT_CFL
---                           -- false means return CONTINUE_CFL
---    short return_value;    -- return value for matched events
---                           -- initialy set but can be changed by the one shot function
---    void *user_data;       -- user data passed to the one shot function
---} process_event_t_CFL;
--- The one shot function is passed this structure
--- setting the return_value field will determine the result


function Store_sm_handler( event_name, event_handler_name, event_list, user_data)
    event_handler_name = tostring(event_handler_name)
    event_name         = tostring(event_name)

    return_value       = tostring(return_value)
    user_data          = tostring(user_data)
    
    generate_event_list(event_name,event_list)
    local message = string.format("    Asm_process_event_CFL(input,%s,%d,%s,COLUMN_STATE_CHANGE_CFL,true,%s);\n",
                                    event_handler_name,#event_list,event_name,user_data)
    file:write(message)
end

--typedef struct transfer_sm_events_t{
--    unsigned short sm_id;
--    unsigned short event_number; -- if 0 then all events > 0 are transferred
--    short *event_indexes;
--}transfer_sm_events_t;

function Transfer_all_events_to_state(state_machine_name)
    
    -- verify state machine name
    state_machine_name = quote_string(state_machine_name)
    local message = string.format("    Asm_transfer_events_to_state_CFL(input,%s,%d,%s);\n",
        state_machine_name,0,'NULL')
    
    
    file:write(message)
end

function Transfer_events_to_state(state_machine_name,event_list_name, event_list)
    state_machine_name = quote_string(state_machine_name)
    if #event_list == 0 then
        print("error number of events cannot be zero")
        os.exit()
    end
    generate_event_list(event_list_name,event_list)
    -- verify state machine name

    local message = string.format("    Asm_transfer_events_to_state_CFL(input,%s,%d,%s);\n",
       state_machine_name,#event_list,event_list_name)
    
    file:write(message)
end

function Transfer_all_events_to_sm(state_machine_name)
    state_machine_name = quote_string(state_machine_name)
    local message = string.format("    Asm_transfer_events_to_sm_CFL(input,%s,%d,%s);\n",
      state_machine_name,0,'NULL')
    
    file:write(message)
end


function Transfer_events_to_sm(state_machine_name,event_name_list, event_list)
    state_machine_name = quote_string(state_machine_name)
    generate_event_list(event_name_list,event_list)
    -- verify state machine name
    -- verify transfer_sm
    
    local message = string.format("    Asm_transfer_events_to_sm_CFL(input,%s,%d,%s);\n",
        state_machine_name,#event_list,event_name_list)
    file:write(message)
end
--
-- This is a column function as the monitoring is done continuously
--
function Conditional_state_change(state_machine_name,new_state,bool_fn,user_data)
    -- verify state_machine_name
    -- verify new_state
    local message = string.format("    Asm_conditional_state_change_CFL(input,%s,%s,%s,%s);\n",
    state_machine_name,new_state,bool_fn,user_data)
    file:write(message)
end
--
-- This is a column function as the monitoring is done continuously
--
function Conditional_sm_status(state_machine_name,enable_flag,bool_fn,user_data)
    -- verify state_machine_name
    -- verify enable_flag to be boolean
    local message = string.format("    Asm_conditional_sm_status_CFL(input,%s,%s,%s,%s);\n",
    state_machine_name,enable_flag,bool_fn,user_data)
    file:write(message)
end


 
---
--- utility functions
---

function Generate_event_queues(queue_name,queue_list)
    
    local return_value = {}
    return_value.queue_number = #queue_list

    local queue_arrary  = table.concat(queue_list,",")
  
    local message = string.format("    const char *%s[] = {%s};\n",queue_name,queue_arrary)
   
    file:write(message)
    return_value.array_name = queue_name
    
    return return_value
end
