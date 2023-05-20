


function Conf_engine(config_handle,once_allocate_size,private_heap_size)
    local once_size = tostring(once_allocate_size)
    local private_size = tostring(private_heap_size)  
    io.write("\n")
    local message = string.format("    void* input = Configure_engine_CFL(%s,%s,%s);\n\n",config_handle,once_size,private_size) 
    io.write(message)

end

function Def_columns(column_names,column_list) 
   
    io.write("    // define the column list\n")
    local message = string.format("    const char * %s[] = {\n",column_names)
    io.write(message)
    io.write("        ")
    for i, column in ipairs(column_list) do
        message = string.format("%s",column)
        io.write(message)
        if i < #column_list then
            io.write(",")
        end
       
    end
    io.write("};\n")
    
    local length = #column_list
    message = string.format("    Asm_columns_CFL(input,%d,%s);\n",length,column_names)
    io.write(message)
  
end

function Store_one_shot(fn_string, fn_name)
    local message = string.format("    Store_one_shot_function_CFL(input,%s,%s);\n",fn_string,fn_name)
    io.write(message) 
end
function Comment(input)
    local message = string.format("    // %s\n",input)
    io.write(message)

end 
  
function Start_column(name,initial_state)
    local message = string.format("\n   /* \n")
    io.write(message)
    local message = string.format("    Defining Column %s  starting initial running state %s \n",name,tostring(initial_state))
    io.write(message)
    local message = string.format("    */ \n")
    io.write(message)
    local message = string.format("    Asm_start_column_CFL(input, %s, %s);\n",name,tostring(initial_state))
    io.write(message)
end



function Log_msg(message)
    local message  = string.format("    Asm_log_message_CFL(input,%s);\n",message)
    io.write(message)
end

function Wait_delay(delay)
    local message = string.format("    Asm_wait_time_delay_CFL(input,%s);\n",delay)
    io.write(message)
end


function One_shot(fn_string, fn_parameter)
    local message = string.format("    Asm_one_shot_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    io.write(message) 
end  

function One_shot_terminate(fn_string, fn_parameter)
    local message = string.format("    Asm_one_shot_terminate_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    io.write(message) 
end

function Halt_column()
    io.write("    Asm_halt_CFL(input);\n" )
end 

function Term_column()
    io.write("    Asm_terminate_CFL(input);\n" )
end
  

function  Reset_column()
    io.write("    Asm_reset_CFL(input);\n" )
end

function Stop_engine()
    io.write("    Asm_engine_terminate_CFL(input);\n" )
end

function  End_column()
    io.write("    Asm_end_column_CFL(input);\n" )
    local message = string.format("     \n")
    io.write(message)

end

--- event functions
function Generate_event(event_name, event_id,event_value,event_param)
       
       local message = string.format("    Event_data_CFL_t %s = { %s, %s, %s};\n",tostring(event_name),tostring(event_id),tostring(event_value),tostring(event_param))
        io.write(message)    
end        

function Send_event(event)
    local message = string.format("    Asm_send_event_CFL(input,%s);\n",tostring(event))
    io.write(message)
end

function Wait_event_no_time_out(event_name, event_count)
    local message = string.format("    Asm_wait_event_count_CFL(input, %s, %s, NO_TIME_OUT_CFL, false, NULL, NULL);\n",event_name,event_count)
    io.write(message)
end

function Wait_event_time_out_reset(event_name, event_count,time_out_ms,one_short_fail_fn,one_short_fail_fn_parameter)
    local message = string.format("    Asm_wait_event_count_CFL(input, %s, %s,%d, false, %s, %s);\n",
         event_name,event_count,time_out_ms,one_short_fail_fn,one_short_fail_fn_parameter)
    io.write(message)
end

function Wait_event_time_out_terminate(event_name, event_count,time_out_ms,one_short_fail_fn,one_short_fail_fn_parameter)
    local message = string.format("    Asm_wait_event_count_CFL(input, %s, %s,%d,true, %s, %s);\n",
         event_name,event_count,time_out_ms,one_short_fail_fn,one_short_fail_fn_parameter)
    io.write(message)
end



