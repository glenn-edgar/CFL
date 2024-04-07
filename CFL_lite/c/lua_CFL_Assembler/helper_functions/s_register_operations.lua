-- operator types




local function pack_two(return_value,a,b)
    table.insert(return_value,a)
    table.insert(return_value,b)
    table.insert(return_value,"end")
    return return_value
end

function reg_gt(op1,op2)
    local return_value = {}
    table.insert(return_value,"gt")
    return pack_two(return_value,op1,op2)
end    

function reg_ge(op1,op2)
    local return_value = {}
    table.insert(return_value,"ge")
    return pack_two(return_value,op1,op2)
end

function reg_eq(op1,op2)
    local return_value = {}
    table.insert(return_value,"eq")
    return pack_two(return_value,op1,op2)
end
function reg_le(op1,op2)
    local return_value = {}
    table.insert(return_value,"le")
    return pack_two(return_value,op1,op2)
end
function reg_lt(op1,op2)
    local return_value = {}
    table.insert(return_value,"lt")
    return pack_two(return_value,op1,op2)
end



function reg_div(op1,op2)
    local return_value = {}
    table.insert(return_value,"/")
    return pack_two(return_value,op1,op2)
end

function reg_mod(op1,op2)
    local return_value = {}
    table.insert(return_value,"%")
    return pack_two(return_value,op1,op2)
end

function reg_shift(op1,op2)
    local return_value = {}
    table.insert(return_value,"<<")
    return pack_two(return_value,op1,op2)
end

local function fill_table(table_entry,operator)
    local return_value = {}
    table.insert(return_value,operator)
    for i,v in ipairs(table_entry) do
        table.insert(return_value,v)
    end
    table.insert(return_value,"end")
    return return_value
end

--- register_operations
function reg_mul(table_entry)
    return fill_table(table_entry,"*")
end

function reg_add(table_entry)
    return fill_table(table_entry,"+")
end    

function reg_sub(table_entry)
    return fill_table(table_entry,"-")
end

function reg_bit_and(table_entry)
    return fill_table(table_entry,"&")
end   
function reg_bit_or(table_entry)
    return fill_table(table_entry,"|")
end
function reg_bit_xor(table_entry)
    return fill_table(table_entry,"^")
end
function reg_bit_nor(table_entry)
    return fill_table(table_entry,"~")
end        


function reg_logical_and(table_entry)
    return fill_table(table_entry,"&&")
end    

function reg_logical_or(table_entry)
    return fill_table(table_entry,"||")
end







--[[

    Assemble s expression

]]--




--[[

   take flatten s expression and convert to register op array

]]--
 
local operator_number = 0

local S_REGISTER_VALUE_CFL = 0
local S_REGISTER_BUFFER_POSITION_CFL = 1
local S_REGISTER_OPERATOR_CFL = 2
local S_REGISTER_OPERATOR_END_CFL = 3


--S_REGISTER_OPERATOR_CFL operators
local S_REGISTER_MULTIPLY_CFL = 0 -- *
local S_REGISTER_DIVIDE_CFL =  1  -- /
local S_REGISTER_ADD_CFL =  2  -- +
local S_REGISTER_SUBTRACT_CFL = 3 -- -
local S_REGISTER_MODULUS_CFL = 4   -- %
local S_REGISTER_SHIFT_CFL = 5   -- <<

local S_REGISTER_BITWISE_AND_CFL  = 6  -- &
local S_REGISTER_BITWISE_OR_CFL   = 7  -- |
local S_REGISTER_BITWISE_XOR_CFL  = 8  -- ^
local S_REGISTER_BITWISE_NOR_CFL  = 9  -- ~

local S_REGISTER_LOGICAL_AND_CFL  = 10  -- &&
local S_REGISTER_LOGICAL_OR_CFL   = 11  -- ||


local S_REGISTER_GT_CFL  = 14  -- gt
local S_REGISTER_GE_CFL   = 15  -- ge
local S_REGISTER_EQ_CFL = 16  -- eq
local S_REGISTER_LE_CFL = 17  -- le
local S_REGISTER_LT_CFL = 18  -- lt


local register_operators = {}

register_operators["*"] = S_REGISTER_MULTIPLY_CFL 
register_operators["/"] = S_REGISTER_DIVIDE_CFL 
register_operators["+"] = S_REGISTER_ADD_CFL  
register_operators["-"] = S_REGISTER_SUBTRACT_CFL  
register_operators["%"] = S_REGISTER_MODULUS_CFL    
register_operators["<<"] = S_REGISTER_SHIFT_CFL    

register_operators["&"] = S_REGISTER_BITWISE_AND_CFL    
register_operators["|"] = S_REGISTER_BITWISE_OR_CFL    
register_operators["^"] = S_REGISTER_BITWISE_XOR_CFL    
register_operators["~"] = S_REGISTER_BITWISE_NOR_CFL   

register_operators["&&"] = S_REGISTER_LOGICAL_AND_CFL   
register_operators["||"] = S_REGISTER_LOGICAL_OR_CFL     


register_operators["gt"] = S_REGISTER_GT_CFL 
register_operators["ge"] =S_REGISTER_GE_CFL 
register_operators["eq"] =S_REGISTER_EQ_CFL 
register_operators["le"] =S_REGISTER_LE_CFL 
register_operators["lt"] = S_REGISTER_LT_CFL 



register_operators["end"] = S_REGISTER_OPERATOR_END_CFL  


local function check_for_integer(number)
    
    number = tonumber(number)
    if type(number) == "number" then
        
        if number == math.floor(number) then
            
             return true
        end

    end
    return false
 
end


local function handle_string(return_value,v,buffer_length)

    if register_operators[v] ~= nil then
       
        if v == "end" then
           
            table.insert(return_value,{S_REGISTER_OPERATOR_END_CFL,0})
        else
            operator_number = operator_number + 1
            table.insert(return_value,{S_REGISTER_OPERATOR_CFL,register_operators[v]})
        end
        return return_value
    end
   -- check for buffer position
   local first_char = string.sub(v,1,1)
   if first_char == "@" then
        local buffer_string =  string.sub(v, 2)
       
        if check_for_integer(buffer_string) then
            local buffer_position = tonumber(buffer_string)
           
            if (buffer_position < 0) or (buffer_position > buffer_length) then
                print("Error: Invalid buffer position",buffer_position)
                error("Invalid buffer position")
                os.exit(1)
            end
            table.insert(return_value,{S_REGISTER_BUFFER_POSITION_CFL,tonumber(buffer_position) } )
            return return_value
        else
            print("Error: Invalid input not a valid integer",v)
            error("Invalid input")
            os.exit(1)
        end
    else
        print("Error: Invalid input not an operator or a valid string",v)
        error("Invalid input")
        os.exit(1)
    end
end

local function flatten_register_s_expression(stream_input,return_value)
    if return_value ==  nil then
        return_value = {}
    end
  
    for i, v in ipairs(stream_input) do
        if type(v) == "table" then
            return_value = flatten_register_s_expression(v,return_value)
        else
            table.insert(return_value,v)
        end
    end
     
    return return_value
end

local function dump_flatten_register_expression(s_expression,tab)
    if tab == nil then
        tab = "->"
    end
    for i,v in ipairs(s_expression) do
        if(type(v) == "table") then
           
            dump_flatten_register_expression(v,"----"..tab)
           
            
        else
            local message = string.format("%s %s",tab,tostring(v))
            print(message)
        end
    end
end

local function assemble_flattened_s_expression(stream_input,buffer_length)
    flatten_input = {}
    return_value = {}
     
    --dump_flatten_register_expression(stream_input)
    flatten_input = flatten_register_s_expression(stream_input,flatten_input)
    --dump_flatten_register_expression(flatten_input)
    for i,v in ipairs(flatten_input) do

        if type(v) == "string" then
            return_value = handle_string(return_value,v,buffer_length)
        else
            if check_for_integer(v) then
                table.insert(return_value,{S_REGISTER_VALUE_CFL,v})
            else
                print("Error: Invalid input",v)
                error("Invalid input")
                os.exit(1)
            end
        end
    end
    return  return_value
end


local function start_s_reg_stack_encoding(source_reg_map,s_expression)
    
    local buffer_id, buffer_length = get_s_register_buffer_number(source_reg_map)
    parameter_stack = #s_expression+5
   
    encoded_stream =  assemble_flattened_s_expression(s_expression,buffer_length)
    
    local stream_name = generate_unique_function_name()
    local message = string.format("const s_register_operator_CFL_t %s[%d] = {",stream_name,#encoded_stream)
    Store_user_code(message)
   
    for i,v in ipairs(encoded_stream) do
       
        if v[1] == 0 then
            local message = string.format("{%d,{.value = %d}},",v[1],v[2])
            Store_user_code(message)
        end
        if v[1] == 1 then
            local message = string.format("{%d,{.buffer_position = %d}},",v[1],v[2])
            Store_user_code(message)
        end
        if v[1] == 2 then
            local message = string.format("{%d,{.operator_value = %d}},",v[1],v[2])
            Store_user_code(message)
        end
        if v[1] == 3 then
            local message = string.format("{%d,{.end = 0}},",v[1])
            Store_user_code(message)
        end
       
        
    end
    Store_user_code("};\n")
    
    return parameter_stack,#encoded_stream,stream_name
end


function generate_s_reg_expression(structure_name,source_reg_map,s_expression)

  
    reg_map_number,number = get_s_register_buffer_number(source_reg_map)
    operator_number = 5
    local parameter_stack_size,stream_length,operator_stream_name = start_s_reg_stack_encoding(source_reg_map,s_expression)

    

    local message = string.format("const  s_register_definition_CFL_t %s = {%d,%d,%d,%d,%s};\n",structure_name,reg_map_number,
       parameter_stack_size,operator_number,stream_length,operator_stream_name)
    Store_user_code(message)
   
end