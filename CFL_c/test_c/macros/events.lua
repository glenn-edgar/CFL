
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

function Wait_rpc_message(rpc_event,rpc_message_handle, -- a boolean function true message handled false message not handled
                                        rpc_user_data) -- user data to be passed to the function name
     
    rpc_event = tostring(rpc_event)
    rpc_message_handle = tostring(rpc_message_handle) 
    rpc_user_data = tostring(rpc_user_data)
    local message = string.format("      Asm_wait_for_rpc_CFL(input,%s,%s,%s);\n",rpc_event,rpc_message_handle,rpc_user_data)                                  
    file:write(message)
end

function Send_bad_rpc_response_message(rpc_event) -- send a bad response message and cleans up the sent rpc message
     rpc_event = tostring(rpc_event)
     local message = string.format("      Asm_send_rpc_bad_response_CFL(input,%s);\n",rpc_event)
     file:write(message)
end

--- a one shot function to handle the reply
-- a one shot function to handle the failure
-- termination flag either reset column or terminate column true is terminate false is reset
-- time out in ms
                                           
function Send_receive_rpc_message(rpc_event,message_handler,message_user_data, 
                                            failure_handler,failure_user_data, 
                                             time_out,termination_flag) 
    local message = string.format("      Asm_send_receive_rpc_CFL(input,%s,%s,%s,%s,%s,%s,%s);\n",
                            rpc_event,message_handler,message_user_data,failure_handler,failure_user_data,time_out,termination_flag)
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
