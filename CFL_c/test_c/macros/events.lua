
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
    print("made it here")
    local array_name = queue_table.array_name
    local queue_number = queue_table.queue_number
    message = string.format("     Asm_reset_named_event_queues_CFL(input,%s,%s);\n",queue_number,array_name)
    file:write(message)
end


function Prepare_rpc_message()
    -- TBD
end

function Send_rpc_server(server_queue)
    -- TBD
end

function Wait_rpc_message(queue)

    -- TBD
end

function Dispose_rpc_message()

    -- TBD
end

function Wait_rpc_message(queue)

    -- TBD
end 

function Wait_rpc_response_message(queue)

    -- TBD
end

function  Send_rpc_response_message()

    -- TBD
end

function Generate_event_queues(queue_name,queue_list)
    
    local return_value = {}
    return_value.queue_number = #queue_list

    local queue_arrary  = table.concat(queue_list,",")
  
    local message = string.format("    const char *%s[] = {%s};\n",queue_name,queue_arrary)
   
    file:write(message)
    return_value.array_name = queue_name
    
    return return_value
end
