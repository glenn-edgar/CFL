

--[[

typedef struct s_bit_definition_CFL_t{
    uint8_t bit_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_operator_CFL_t *operator_stream;
}s_bit_definition_CFL_t;



]]

loc

-- operator types
local  S_BIT_VALUE_CFL = 0
local  S_BIT_BUFFER_POSITION_CFL 1
local  S_BIT_LOGIC_OPERATOR_CFL  2
local  S_BIT_BUFFER_OPERATOR_CFL 3
local  S_BIT_OPERATOR_END_CFL 4


-- S_BIT_LOGIC_OPERATOR_CFL operators

local S_BIT_LOGICAL_AND_CFL 0
local S_BIT_LOGICAL_OR_CFL 1
local S_BIT_LOGICAL_NOR_CFL 2



-- S_BIT_BUFFER_OPERATOR_CFL operators
local S_BIT_BUFFER_AND_CFL = 0
local S_BIT_BUFFER_OR_CFL = 1
local S_BIT_BUFFER_NOR_CFL =  2

operator_def = {}
operator_def["&&"] = {S_BIT_LOGIC_OPERATOR_CFL,S_BIT_LOGICAL_AND_CFL,S_BIT_VALUE_CFL}
operator_def["||"] = {S_BIT_LOGIC_OPERATOR_CFL,S_BIT_LOGICAL_OR_CFL,S_BIT_VALUE_CFL}
operator_def["~~"] = {S_BIT_LOGIC_OPERATOR_CFL,S_BIT_LOGICAL_NOR_CFL,S_BIT_VALUE_CFL}

operator_def["@&"] = {S_BIT_BUFFER_OPERATOR_CFL,S_BIT_LOGICAL_AND_CFL, S_BIT_BUFFER_POSITION_CFL}
operator_def["@|"] = {S_BIT_BUFFER_OPERATOR_CFL,S_BIT_LOGICAL_OR_CFL, S_BIT_BUFFER_POSITION_CFL}
operator_def["@~"] = {S_BIT_BUFFER_OPERATOR_CFL,S_BIT_LOGICAL_NOR_CFL, S_BIT_BUFFER_POSITION_CFL}


local encoded stream = {}



add_to_stream(stream_type,stream_value)
    table.insert(encoded_stream,{stream_type,stream_value})
end

function add_end_string_marker()
    add_to_stream(S_BIT_OPERATOR_END_CFL,0)
end

local bit_map_number,byte_number,bit_number

function is_valid_buffer_position(op)
    if type(op) == "number" and math.floor(op) == op then
        if(op >= 0 and op < bit_number) then
            return
        else
            print(number exceeds buffer length,bit_number,op)
            os.exit(1)
        end
    else
        print("buffer position must be an integer ",op)
        os.exit(1)
    end
end

function evaluate_first_parameter(op)
    if(operator_def[op] == nil)then
        print("first parameter is not an operator")
        os.exit(1)
    end
    add_to_stream(operator_def[op][1],operator_def[op][2])
    return operator_def[op][3]
end

function generate_immediate_stream(stream_type,op)
    if(is_operator(op))then
        print("unexpected operator")
        os.exit(1)
    end
    if(type(op)=="table") then
        if(stream_type == S_BIT_BUFFER_POSITION_CFL) then
          print("nested s_bit_expression not allowed in buffer position functions")
          os.exit(1)
        end
        generate_s_operator_stream(op) 
        return true
    end
    if(stream_type == S_BIT_VALUE_CFL) then
       if(type(op ~= "boolean")) then
          print("value must be boolean")
          os.exit(1)
       end
       add_to_stream(S_BIT_VALUE_CFL,op)
       return false
    end
    if(stream_type == S_BIT_BUFFER_POSITION_CFL) then
       is_valid_buffer_position(op)
       add_to_stream(S_BIT_BUFFER_POSITION_CFL,op)
       return false
    end
    print("unexpected stream type")
    os.exit(1)
end

local operator_stack = {}
local parameter_stack = {}


local function generate_s_operator_stream(s_expression)
    local stream_type = nil
    local parameter_stack_size = 0
    local op_stack_size = 0
    for i,op in ipairs(s_expression)
        parameter_stack_size = parameter_stack_size + 1
        if(i = 1 )then
            stream_type = evaluate_first_parameter(op)
        else
           if( generate_immediate_stream(stream_type,op) == true)then
              op_stack_size = op_stack_size + 1
           end
        end
    end
    add_end_string_marker()
    parameter_stack_size = parameter_stack_size + 1
    table.insert(parameter_stack,parameter_stack_size)
    table.insert(operator_stack,op_stack_size)
end

function determine_max(stack)
    local max = 0
    for i,v in ipairs(stack) do
        if(v > max) then
            max = v
        end
    end
    return max
end

function start_s_bit_stack_encoding(s_expression)
    encoded stream = {}
    operator_stack = {}
    parameter_stack = {}
    generate_s_operator_stream(s_expression)
    local max_parameter_stack_size = determine_max(parameter_stack)
    local max_operator_stack_size = determine_max(operator_stack)
    local stream_name = generate_unique_function_name()
    local message = string.format("const s_operator_CFL_t %s[%d] = {",stream_name,#encoded_stream)
    Store_user_code(message)
    for i,v = ipairs(encoded_stream) do
        local message = string.format("{%d,%d},",v[1],v[2])
        Store_user_code(message)
    end
    Store_user_code("};")
    
    return parameter_stack_size,op_stack_size,#encoded_stream,stream_name)
end





function generate_s_bit_expression(structure_name,source_bit_map,s_expression)
    bit_map_number,byte_number,bit_number = get_bit_map_number(source_bit_map)
    local parameter_stack_size,operator_stack_size,stream_length,operator_stream_name = start_s_bit_stack_encoding(s_expression)
 
    local message = string.format("const s_bit_definition_CFL_t %s = {%d,%d,%d,%d,%s};",structure_name,bit_map_number,
       parameter_stack_size,operator_stack_size,stream_length,operator_stream_name)
    Store_user_code(message)

end