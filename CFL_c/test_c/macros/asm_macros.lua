


function Conf_engine(config_handle,once_allocate_size,private_heap_size)
    local once_size = tostring(once_allocate_size)
    local private_size = tostring(private_heap_size)  
    file:write("\n")
    local message = string.format("    void* input = Configure_engine_CFL(%s,%s,%s);\n\n",config_handle,once_size,private_size) 
    file:write(message)

end

function Def_columns(column_names,column_list) 
   
    file:write("    // define the column list\n")
    local message = string.format("    const char * %s[] = {\n",column_names)
    file:write(message)
    file:write("        ")
    for i, column in ipairs(column_list) do
        message = string.format("%s",column)
        file:write(message)
        if i < #column_list then
            file:write(",")
        end
       
    end
    file:write("};\n")
    
    local length = #column_list
    message = string.format("    Asm_columns_CFL(input,%d,%s);\n",length,column_names)
    file:write(message)
  
end

function Store_one_shot(fn_string, fn_name)
    local message = string.format("    Store_one_shot_function_CFL(input,%s,%s);\n",fn_string,fn_name)
    file:write(message) 
end

function  Store_boolean_fn(fn_string, fn_parameter)
    local message = string.format("    Store_bool_function_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    file:write(message) 
end

function Comment(input)
    local message = string.format("    // %s\n",input)
    file:write(message)

end 
  
function Start_column(name,initial_state)
    local message = string.format("\n   /* \n")
    file:write(message)
    local message = string.format("    Defining Column %s  starting initial running state %s \n",name,tostring(initial_state))
    file:write(message)
    local message = string.format("    */ \n")
    file:write(message)
    local message = string.format("    Asm_start_column_CFL(input, %s, %s);\n",name,tostring(initial_state))
    file:write(message)
end



function Log_msg(message)
    local message  = string.format("    Asm_log_message_CFL(input,%s);\n",message)
    file:write(message)
end

function Wait_delay(delay)
    local message = string.format("    Asm_wait_time_delay_CFL(input,%s);\n",delay)
    file:write(message)
end


function One_shot(fn_string, fn_parameter)
    local message = string.format("    Asm_one_shot_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    file:write(message) 
end  

function One_shot_terminate(fn_string, fn_parameter)
    local message = string.format("    Asm_one_shot_terminate_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    file:write(message) 
end



function Halt_column()
    file:write("    Asm_halt_CFL(input);\n" )
end 

function Term_column()
    file:write("    Asm_terminate_CFL(input);\n" )
end
  

function  Reset_column()
    file:write("    Asm_reset_CFL(input);\n" )
end

function Stop_engine()
    file:write("    Asm_engine_terminate_CFL(input);\n" )
end

function  End_column()
    file:write("    Asm_end_column_CFL(input);\n" )
    local message = string.format("     \n")
    file:write(message)

end

--- event functions
function Generate_event(event_name, event_id,event_value,event_param)
       
       local message = string.format("    Event_data_CFL_t %s = { %s, %s, %s};\n",tostring(event_name),tostring(event_id),tostring(event_value),tostring(event_param))
        file:write(message)    
end        

function Send_event(event)
    local message = string.format("    Asm_send_event_CFL(input,%s);\n",tostring(event))
    file:write(message)
end

function Wait_event_no_time_out(event_name, event_count)
    local message = string.format("    Asm_wait_event_count_CFL(input, %s, %s, NO_TIME_OUT_CFL, false, NULL, NULL);\n",tostring(event_name),tostring(event_count))
    file:write(message)
end

function Wait_event_time_out_reset(event_name, event_count,time_out_ms,one_short_fail_fn,fn_parameter)
    local message = string.format("    Asm_wait_event_count_CFL(input, %s, %s,%s, false, %s, %s);\n",
         tostring(event_name),tostring(event_count),tostring(time_out_ms),tostring(one_short_fail_fn),tostring(fn_parameter))
    file:write(message)
end

function Wait_event_time_out_terminate(event_name, event_count,time_out_ms,one_shot_fail_fn,fn_parameter)

   local message = string.format("    Asm_wait_event_count_CFL(input, %s, %s,%s,true, %s, %s);\n",
   -                                 tostring(event_name),tostring(event_count),tostring(time_out_ms),tostring(one_shot_fail_fn),tostring(fn_parameter) )
    file:write(message)
end

function Wait_terminate(bool_fn,time_out_ms,one_shot_fail_fn,fn_parameter)
    local message = string.format("    Asm_wait_CFL(input,%s,%s,true,%s,%s);\n",tostring(bool_fn),tostring(time_out_ms),tostring(one_shot_fail_fn),tostring(fn_parameter))
    file:write(message)
end

function Wait_reset(bool_fn,time_out_ms,one_shot_fail_fn,fn_parameter)
    local message = string.format("    Asm_wait_CFL(input,%s,%s,false,%s,%s);\n",tostring(bool_fn),tostring(time_out_ms),tostring(one_shot_fail_fn),tostring(fn_parameter))
    file:write(message)
end

function Wait_no_time_out_reset( bool_fn, user_data)
    local message = string.format("     Asm_wait_CFL(input,%s, NO_TIME_OUT_CFL,false,NULL,%s);\n",tostring(bool_fn),tostring(user_data))
    file:write(message)
end

function Wait_no_time_out_terminate( bool_fn, user_data)
    local message = string.format("     Asm_wait_CFL(input,%s, NO_TIME_OUT_CFL,false,NULL,%s);\n",tostring(bool_fn),tostring(user_data))
    file:write(message)
end

--void Asm_verify_CFL(void* input, const char* bool_fn_name, bool terminate_flag, const char* one_shot_failure_fn, void* user_data);
function Verify_reset(bool_fn,end_fn,user_data)
    local message = string.format("    Asm_verify_CFL(input,%s,false,%s,%s);\n",tostring(bool_fn),tostring(end_fn),tostring(user_data))
    file:write(message)
end

function Verify_terminate(bool_fn,end_fn,user_data)
    local message = string.format("    Asm_verify_CFL(input,%s,true,%s,%s);\n",tostring(bool_fn),tostring(end_fn),tostring(user_data))
    file:write(message)
end

function Set_watch_dog( time_out,term_flag, one_shot_term_fn)

  time_out = tostring(time_out)
  term_flag = tostring(term_flag)
  one_shot_term_fn = tostring(one_shot_term_fn)
  local message = string.format("    Asm_set_column_watch_dog_CFL(input,%s,%s,%s);\n",time_out,term_flag,one_shot_term_fn )
  file:write(message)
end

function Clear_watch_dog()
    file:write("    Asm_clear_column_watch_dog_CFL(input);\n")
end


function Wait_tod_lt(doy, month, dow, hour, minute, second)
    local message = string.format("    Asm_wait_tod_lt(input, %s, %s, %s, %s, %s, %s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),tostring(second))
    file:write(message)
end

function Wait_tod_le(doy, month, dow, hour, minute, second)
    local message = string.format("    Asm_wait_tod_le(input, %s, %s, %s, %s, %s, %s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),tostring(second))
    file:write(message)
end

function Wait_tod_eq(doy, month, dow, hour, minute, second)
    local message = string.format("    Asm_wait_tod_eq(input, %s, %s, %s, %s, %s, %s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),tostring(second))
    file:write(message)
end

function Wait_tod_ge(doy, month, dow, hour, minute, second)
    local message = string.format("    Asm_wait_tod_ge(input, %s, %s, %s, %s, %s, %s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),tostring(second))
    file:write(message)
end

function Wait_tod_gt(doy, month, dow, hour, minute, second)
    local message = string.format("    Asm_wait_tod_gt(input, %s, %s, %s, %s, %s, %s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),tostring(second))
    file:write(message)
end

function Verify_tod_lt(doy, month, dow, hour, minute, second, terminate_flag,terminate_fn,user_data)
    local message = string.format("    Asm_verify_tod_lt(input, %s, %s, %s, %s, %s, %s,%s,%s,%s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),
                                                    tostring(second),tostring(terminate_flag),tostring(terminate_fn),tostring(user_data))
    file:write(message)
end

function Verify_tod_le(doy, month, dow, hour, minute, second, terminate_flag,terminate_fn,user_data)
    local message = string.format("    Asm_verify_tod_le(input, %s, %s, %s, %s, %s, %s,%s,%s,%s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),
                                                                       tostring(second),tostring(terminate_flag),tostring(terminate_fn),tostring(user_data))
    file:write(message)
end

function Verify_tod_eq(doy, month, dow, hour, minute, second, terminate_flag,terminate_fn,user_data)
    local message = string.format("    Asm_verify_tod_eq(input, %s, %s, %s, %s, %s, %s,%s,%s,%s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),
         tostring(second),tostring(terminate_flag),tostring(terminate_fn),tostring(user_data))
    file:write(message)
end

function Verify_tod_ge(doy, month, dow, hour, minute, second, terminate_flag,terminate_fn,user_data)
    local message = string.format("    Asm_verify_tod_ge(input, %s, %s, %s, %s, %s, %s,%s,%s,%s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),
                                                   tostring(second),tostring(terminate_flag),tostring(terminate_fn),tostring(user_data))
    file:write(message)
end

function Verify_tod_gt(doy, month, dow, hour, minute, second, terminate_flag,terminate_fn,user_data)
    local message = string.format("    Asm_verify_tod_gt(input, %s, %s, %s, %s, %s, %s,%s,%s,%s);\n",tostring(doy),tostring(month),tostring(dow),tostring(hour),tostring(minute),
                                                   tostring(second),tostring(terminate_flag),tostring(terminate_fn),tostring(user_data))
    file:write(message)
end



