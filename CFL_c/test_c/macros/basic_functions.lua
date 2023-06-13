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
   --print("event_name",event_name,tostring(event_name ))
   local message = string.format("    Asm_wait_event_count_CFL(input, %s, %s,%s,true, %s, %s);\n",
                                    tostring(event_name),tostring(event_count),tostring(time_out_ms),tostring(one_shot_fail_fn),tostring(fn_parameter) )
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

