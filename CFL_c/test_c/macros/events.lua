
--- event functions

function Define_event_queue(queue_name,queue_size)

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
