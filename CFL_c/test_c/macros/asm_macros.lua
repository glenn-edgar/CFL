
print("Loading asm_macros.lua")

function q(input)
    input = tostring(input)
    return '"' .. input .. '"'
end

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

--[[
s expression operators    
static S_short_fn_record_CFL_t s_verify_fn_tbl[] = {
    {"&&", and_verify_fn}, // and
    {"||", or_verify_fn},  // or
    {"~", not_verify_fn},  // not
    {"&@", and_tbl_verify_fn}, // input buffer positions result and of buffer positions
    {"|@", or_tbl_verify_fn}, // input buffer positions result or of buffer positions
    {"~@", not_tbl_verify_fn},// input buffer positions result not of buffer positions

};

--]]--


function Init_df_buffers()
    master_symbol_table = {}
end

function Verify_entry(symbol_table,size, token)
    
    if symbol_table == nil then
      symbol_table = {}
    end
    
    local position = symbol_table[token]
    if position == nil then
      position = token
    end
    position = tonumber(position)
    if type(position) ~= "number" then
      print("Error: token " .. position .. " must be a number")
      os.exit()
    end
    
    if position % 1 ~= 0 then
      print("Error: token " .. position .. " must be an integer")
      os.exit()
    end
    
    if position < 0 then
      print("Error: token " .. position .. " must be greater than or equal to 0")
      os.exit()
    end
    
    if position > size-1 then
      print("Error: token " .. position .. " must be less than " .. size)
      os.exit()
    end

    return position
end

function Verify_positions(name,positions)
    local temp = master_symbol_table[name]
    if temp == nil then
      print("Error: buffer " .. name .. " not found")
        os.exit()
    end  
    local symbol_table = temp[2]
    local size = temp[1]
    
   
    for i = 1, #positions do
      
      if symbol_table ~= nil then
          local temp = symbol_table[positions[i]]
          
          if temp ~= nil then
             positions[i] = temp
             
          end
      end
      positions[i] = tonumber(positions[i])
      if type(positions[i]) ~= "number" then
         print("Error: position " .. positions[i] .. " must be a number")
         os.exit( )
      end
      
      if positions[i] % 1 ~= 0 then
          print("Error: position " .. positions[i] .. " must be an integer")
          os.exit()
      end
     
      if positions[i] < 0 then
          print("Error: position " .. positions[i] .. " must be a positive integer")
          os.exit()
      end
    
        
      if positions[i] > size-1 then
         
          print("Error: position " .. positions[i] .. " must be less than " .. size)
          os.exit()
      end   
              
     
    end
    return positions
  end

  function Store_s_expression_CFL(s_expr_name, s_expression)
    local message = string.format("    Asm_store_s_expression_CFL(input, %s, %s);\n",s_expr_name, s_expression)
    file:write(message)
end

           
function Print_df_buffer(name)
    name = tostring(name)
    local message = string.format("    Asm_print_df_buf_CFL(input, %s);\n",name)
    file:write(message)
end


function Define_df_buffer(name,size,symbol_table)
    
   name = tostring(name)
    size = tostring(size)
   master_symbol_table[name] = {size, symbol_table}
   local message = string.format("    Define_df_buf_CFL(input, %s, %s,0,NULL);\n",name,size)
   file:write(message)
end

function Reset_df_buffer(name,value)
    name = tostring(name)
    value = tostring(value)
   local message = string.format("    Asm_reset_df_buffer_CFL(input, %s, %s);\n",name,value)
    file:write(message)
end

function Set_df_buff_positions(name,array_name,positions,value)

   positions = Verify_positions(name,positions) 
   local table_positions = table.concat(positions,",")
   array_name = tostring(array_name)
   file:write("     unsigned short " .. array_name .. "[] = { " .. table_positions .. " };\n    ")
   local message = string.format("    Asm_set_df_buff_positions_CFL(input, %s, %d,{ %s }, %s);\n",name,#positions,array_name,value)
    file:write(message)
end


      
function Copy_df_buff_array(from_bufF_name, to_buff_name, from_start, to_start, number)

   local message = string.format("    Asm_copy_df_buff_array_CFL(input, %s, %s, %s, %s, %s);\n",
                   tostring(from_bufF_name), tostring(to_buff_name), tostring(from_start), tostring(to_start), 
                   tostring(number))
    file:write(message)
   
end



function Store_s_bit(name, bit_index, s_buffer_name)
   local message = string.format("    Asm_store_s_expression_CFL(input, %s, %d, %s);\n",name,bit_index, s_buffer_name)
    file:write(message)
end


function Wait_s_expr_no_time_out(name,s_buffer_name,one_short_fail_fn,user_data,terminate_flag)
   local message = string.format("    Asm_wait_s_expression_CFL(input, %s, %s,%d, %s, %s, %s);\n",name,s_buffer_name,NO_TIME_OUT_CFL,one_short_fail_fn,
                                    user_data,terminate_flag)
    file:write(message)
end

function Wait_s_expr_time_out(name, s_buffer_name, time_out_ms, one_shot_failure_fn, user_data, terminate_flag, s_expr_buffer)
   local message = string.format("    Asm_wait_s_expression_CFL(input, %s, %s, %d, %s, %s, %s);\n",name, s_buffer_name,
                                                time_out_ms, one_shot_failure_fn, user_data, terminate_flag, s_expr_buffer)
    file:write(message)
end

function Verify_s_expr(name, s_buffer_name,s_expr_buffer, one_shot_failure_fn, user_data, terminate_flag, s_expr_buffer)
   local message = string.format("    Asm_verify_s_expression_CFL(input, %s, %s,%s, %s, %s, %s);\n",name, s_buffer_name,s_expr_buffer,
                                                 one_shot_failure_fn, user_data, terminate_flag, s_expr_buffer)
    file:write(message)
end

--S_logic s expression functions


function Generate_s_express(input_str, symbol_table,buffer_size)
    
   
    input_str = insertSpacesAroundParentheses(input_str)
   
    if not is_balanced(input_str) then
        print("Error: unbalanced parentheses in s-expression")
        os.exit()
    end
    local tokens = tokenize(input_str)
   
    if #tokens == 0 then
        print("Error: empty s-expression")
        os.exit()
    end
    if tokens[1] ~= "(" then
        print("Error: s-expression must start with ( instead of " .. tokens[1])
        os.exit()
    end
    if tokens[#tokens] ~= ")" then
        print("Error: s-expression must end with ) instead of " .. tokens[#tokens])
        os.exit()
    end
    local op_state = false
    for i = 1, #tokens - 1 do
        if tokens[i] == ")" then
            -- Skip this token
        elseif tokens[i] == "(" then
            op_state = true
        elseif op_state then
            check_opcode(tokens[i])
            op_state = false
        else
          
           tokens[i] = Verify_entry(symbol_table,buffer_size, tokens[i])
        end
    end
    local s_expr = table.concat(tokens, " ")
    --print(s_expr)
    return s_expr
end


function insertSpacesAroundParentheses(str)
    local result = ""
    for i = 1, #str do
      local char = str:sub(i, i)
      if char == '(' or char == ')' then
        result = result .. ' ' .. char .. ' '
      else
        result = result .. char
      end
    end
    return result
  end

function is_balanced(str)
    local count = 0
    for char in str:gmatch(".") do
        if char == "(" then
            count = count + 1
        elseif char == ")" then
            count = count - 1
            if count < 0 then
                return false
            end
        end
    end
    return count == 0
end

function tokenize(str)
    local tokens = {}
    for token in str:gmatch("%S+") do
        table.insert(tokens, token)
    end
    return tokens
end

function check_opcode(opcode)
 
    local valid_opcodes = {"&&","||","~","&@","|@","~@"}
    for i = 1, #valid_opcodes do
        if opcode == valid_opcodes[i] then
            return
        end
    end
    print("Error: invalid opcode " .. opcode)
end



