

--[[

typedef struct s_bit_definition_CFL_t{
    uint8_t bit_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_operator_CFL_t *operator_stream;
}s_bit_definition_CFL_t;



]]


// operator types
local  S_BIT_VALUE_CFL =0
local  S_BIT_BUFFER_POSITION_CFL =1
local  S_BIT_OPERATOR_CFL = 2


// operators

local  S_BIT_AND_CFL= 0
local  S_BIT_OR_CFL =1
local  S_BIT_NOR_CFL =2



operator_def = {}
operator_def["&&"] = {S_BIT_AND_CFL}
operator_def["||"] = {S_BIT_OR_CFL}
operator_def["~~"] = {S_BIT_NOR_CFL}



local encoded stream = {}
local operator_number = 0


function add_to_stream(stream_type,stream_value)
    table.insert(encoded_stream,{stream_type,stream_value})
end


function parse_stream_value(op)
  
  if type(op) == "boolean" then
      return S_BIT_VALUE_CFL,op
  end
  if type(op) == "string" then
    local first_char = string.sub(position,1,1)
    if first_char ~= "@" then
        print("ERROR: string values must start with @",position)
        os.exit(1)
    end
    local remaining = string.sub(position,2)
    if #remaining == 0 then
        print("ERROR: string values must have a number after the @",position)
        os.exit(1)
    end
    if isValidInteger(remaining) == false then
        print("ERROR: string values must have a number after the @",position)
        os.exit(1)
    end
    return S_BIT_BUFFER_POSITION_CFL, tonumber(bp)
  end
  print("invalid op value ",op,type(op))
  os.exit(1)
end

local function generate_s_operator_stream(s_expression)
    local stream_type = nil
    
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
    
end



function start_s_bit_stack_encoding(s_expression)
    encoded_stream = {}
    operator_number = 0
    parameter_stack = #s_expression+5
   
    generate_s_operator_stream(s_expression)
  
    local stream_name = generate_unique_function_name()
    local message = string.format("const s_operator_CFL_t %s[%d] = {",stream_name,#encoded_stream)
    Store_user_code(message)
   
    for i,v in ipairs(encoded_stream) do
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