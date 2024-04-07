

--[[

typedef struct s_bit_definition_CFL_t{
    uint8_t bit_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_operator_CFL_t *operator_stream;
}s_bit_definition_CFL_t;



]]


-- operator types
local  S_BIT_VALUE_CFL =0
local  S_BIT_BUFFER_POSITION_CFL =1
local  S_BIT_OPERATOR_CFL = 2
local  S_BIT_OPERATOR_XOR_CFL = 3
local  S_BIT_OPERATOR_NOT_CFL = 4
local  S_BIT_OPERATOR_END_CFL = 3


-- operators

local  S_BIT_AND_CFL= 0
local  S_BIT_OR_CFL =1
local  S_BIT_NOR_CFL =2



local operator_def = {}
operator_def["&&"] = {S_BIT_AND_CFL}
operator_def["||"] = {S_BIT_OR_CFL}
operator_def["~~"] = {S_BIT_NOR_CFL}
operator_def["^^"] = {S_BIT_OPERATOR_XOR_CFL}
operator_def["!!"] = {S_BIT_OPERATOR_NOT_CFL}

local encoded stream = {}
local operator_number = 0

local function error_r(text,value)
    type(value)
    print(text,value)
    error(value)
end


function isValidInteger(str)
    local num = tonumber(str)
    -- Check if 'num' is a number and an integer
    if num and num == math.floor(num) then
        return true
    else
        return false
    end
end

function add_to_stream(stream_type,stream_value)
    table.insert(encoded_stream,{stream_type,stream_value})
end



local function parse_stream_value(op)
 
  if type(op) == "boolean" then
      return S_BIT_VALUE_CFL,op
  end
  if type(op) == "string" then
    local first_char = string.sub(op,1,1)
    if first_char ~= "@" then
        error_r("ERROR: string values must start with @",op)
        os.exit(1)
    end
    local remaining = string.sub(op,2)
    if #remaining == 0 then
        error_r("ERROR: string values must have a number after the @",remaining)
        os.exit(1)
    end
    if isValidInteger(remaining) == false then
        error_r("ERROR: string values must have a number after the @",remaining)
        os.exit(1)
    end
    return S_BIT_BUFFER_POSITION_CFL, tonumber(remaining)
  end
  error_r("invalid op value ",op,type(op))
  os.exit(1)
end

local function generate_s_operator_stream(s_expression)
    local stream_type = nil
    encoded_stream = {}
    for i,op in ipairs(s_expression) do
        if(operator_def[op] ~= nil) then
            add_to_stream(S_BIT_OPERATOR_CFL,operator_def[op][1])
            operator_number = operator_number + 1
        elseif(op == ")") then
            add_to_stream(S_BIT_OPERATOR_END_CFL,0)
        else
            stream_type , op = parse_stream_value(op)
            if(stream_type ==  S_BIT_VALUE_CFL) then
                add_to_stream( S_BIT_VALUE_CFL,op)
            else
                add_to_stream(S_BIT_BUFFER_POSITION_CFL,op)
            end
        end
    end
    return operator_number,encoded_stream
    
end



local function start_s_bit_stack_encoding(s_expression)
    
    
    parameter_stack = #s_expression+5
   
    operator_number,encoded_stream = generate_s_operator_stream(s_expression)
    
    local stream_name = generate_unique_function_name()
    local message = string.format("const s_operator_CFL_t %s[%d] = {",stream_name,#encoded_stream)
    Store_user_code(message)
   
    for i,v in ipairs(encoded_stream) do
        if v[2] == false then
            v[2] = 0
        elseif v[2] == true then
            v[2] = 1
        end
       
        local message = string.format("{%d,%d},",v[1],v[2])
        Store_user_code(message)
    end
    Store_user_code("};\n")
    
    return parameter_stack,operator_number,#encoded_stream,stream_name
end




function generate_s_bit_expression(structure_name,source_bit_map,s_expression)

  
    bit_map_number,byte_number,bit_number = get_s_bit_buffer_number(source_bit_map)

    local parameter_stack_size,operator_stack_size,stream_length,operator_stream_name = start_s_bit_stack_encoding(s_expression)

    

    local message = string.format("const s_bit_definition_CFL_t %s = {%d,%d,%d,%d,%s};\n",structure_name,bit_map_number,
       parameter_stack_size,operator_stack_size,stream_length,operator_stream_name)
    Store_user_code(message)
   
end