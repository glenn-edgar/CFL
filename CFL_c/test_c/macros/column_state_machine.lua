
function Store_column_start()
    local message = string.format("    Asm_store_column_starting_state_CFL(input);\n")
    file:write(message)
end

function Store_column_end()
    local message = string.format("     Asm_store_column_ending_state_CLF(input);\n")
    file:write(message)
end

function Change_column_state(column_state)
    column_state = tonumber(column_state)
    column_state = column_state//1
    local message = string.format("    Asm_change_column_state_CFL(input,%d);\n",column_state)
    file:write(message)
end

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

function Store_event_filter(event_handler_name,event_name, event_list, user_data,block_flag)
    event_name         = tostring(event_name)
    block_flag         = tostring(block_flag)
    return_value       = tostring(return_value)
    user_data          = tostring(user_data)
    event_handler_name = tostring(event_handler_name)
    
    generate_event_list(event_name,event_list)
    local message = string.format("    Asm_filter_events_CFL(input,%s,%d,%s,%s,%s);\n",
                                    event_handler_name,#event_list,event_name,block_flag,user_data)
    file:write(message)
end



function generate_event_list(event_name,event_list)
    file:write("    // define the event list\n")
    local message = string.format("    short  %s[] = {\n",event_name)
    file:write(message)
    file:write("        ")
    for i, event in ipairs(event_list) do
        event = tostring(event)
        message = string.format("%s",event)        
        file:write(message)
        if i < #event_list then
            file:write(",")
        end
       
    end
    file:write("};\n")
end 



