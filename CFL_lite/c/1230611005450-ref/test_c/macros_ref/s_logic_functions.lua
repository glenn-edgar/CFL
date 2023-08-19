--s expression operators    
--static S_short_fn_record_CFL_t s_verify_fn_tbl[] = {
--    {"&&", and_verify_fn}, // and
--    {"||", or_verify_fn},  // or
--    {"~", not_verify_fn},  // not
--    {"&@", and_tbl_verify_fn}, // input buffer positions result and of buffer positions
--    {"|@", or_tbl_verify_fn}, // input buffer positions result or of buffer positions
--    {"~@", not_tbl_verify_fn},// input buffer positions result not of buffer positions
--
--};




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

function Verify_position(name,position)
  
    local table = master_symbol_table[name]

    if table == nil then
        print("Error: buffer " .. name .. " not found")
        os.exit()
    end  
    local symbol_table = table[2]
    local size = table[1]
    
    
   
      
    if symbol_table ~= nil then
          local temp = symbol_table[position]
          
          if temp ~= nil then
            position = temp
            
         end
    end
   
    position = tonumber(position)
   
    if type(position) ~= "number" then
        print("Error: position " .. position .. " must be a number")
        os.exit( )
    end
    
    if position % 1 ~= 0 then
        print("Error: position " .. position .. " must be an integer")
        os.exit()
    end
   
    if position < 0 then
        print("Error: position " .. position .. " must be a positive integer")
        os.exit()
    end
  
      
    if position > size-1 then
       
        print("Error: position " .. position .. " must be less than " .. size)
        os.exit()
    end
    
    return position
end


function Verify_positions(name,positions)
  
    
   
    for i = 1, #positions do
      positions[i] = Verify_position(name,positions[i])
      
   end
   return positions
 end

 function Store_s_expression_CFL(s_buffer_name, s_expr_name, s_expression)
   local message = string.format("    Store_s_logical_expression_CFL(input, %s,%s, %s);\n",s_buffer_name,s_expr_name, s_expression)
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



function Store_s_bit( buffer_name,s_bit, s_expr)
 
  bit_index = Verify_position(buffer_name,s_bit)
  
  local message = string.format("    Asm_store_s_bit_CFL(input, %s, %s, %s);\n",buffer_name,bit_index, s_expr)
   file:write(message)
end
--void Asm_store_s_bit_CFL(void* input, const char* buffer_name,unsigned short store_index, const char* s_expression);

function Wait_s_expr_no_time_out(s_buffer_name,one_short_fail_fn,user_data,terminate_flag,s_expr_name)
  local message = string.format("    Asm_wait_df_tokens_s_expression_CFL(input, %s,%d, %s, %s, %s,%s);\n",s_buffer_name,NO_TIME_OUT_CFL,one_short_fail_fn,
                                   user_data,terminate_flag.s_expr_name)
   file:write(message)
end

function Wait_s_expr_time_out(s_buffer_name, time_out_ms, one_shot_failure_fn, user_data, terminate_flag, s_expr_name)
  local message = string.format("    Asm_wait_df_tokens_s_expression_CFL(input, %s, %d, %s, %s, %s, %s);\n", s_buffer_name,
                                               time_out_ms, one_shot_failure_fn, user_data, terminate_flag, s_expr_name)
   file:write(message)
end
          
function Verify_s_expr(s_buffer_name,one_shot_failure_fn, user_data, terminate_flag, s_expr_buffer)
  local message = string.format("    Asm_verify_df_tokens_s_expression_CFL(input, %s,%s, %s, %s, %s);\n",s_buffer_name,
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
   return '"'..s_expr..'"'
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



