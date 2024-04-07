-- operator types


local function fill_table(table_entry,operator)
    if type(table_entry) ~= "table" then
        print("Error: Invalid input not a table",table_entry)
        error("Invalid input")
        os.exit(1)
    end
    if(type(operator) ~= "string") then
        print("Error: Invalid input not a string",operator)
        error("Invalid input")
        os.exit(1)
    end
    local return_value = {}
    table.insert(return_value,operator)
    for i,v in ipairs(table_entry) do
        table.insert(return_value,v)
    end
    table.insert(return_value,"end")
    return return_value
end

local function pack_two(operator,a,b)
    local return_value = {}
    if type(return_value) ~= "table" then
        print("Error: Invalid input not a table",return_value)
        error("Invalid input")
        os.exit(1)
    end
    if(type(operator) ~= "string") then
        print("Error: Invalid input not a string",operator)
        error("Invalid input")
        os.exit(1)
    end
    table.insert(return_value,operator)
    table.insert(return_value,a)
    table.insert(return_value,b)
    table.insert(return_value,"end")
    return return_value
end

local function pack_one(operator,a)
    local return_value = {}
    if type(return_value) ~= "table" then
        print("Error: Invalid input not a table",return_value)
        error("Invalid input")
        os.exit(1)
    end
    if(type(operator) ~= "string") then
        print("Error: Invalid input not a string",operator)
        error("Invalid input")
        os.exit(1)
    end
    table.insert(return_value,operator)
    table.insert(return_value,a)
    table.insert(return_value,"end")
    return return_value
end

local function pack_zero(operator)
    local return_value = {}
    if type(return_value) ~= "table" then
        print("Error: Invalid input not a table",return_value)
        error("Invalid input")
        os.exit(1)
    end
    if(type(operator) ~= "string") then
        print("Error: Invalid input not a string",operator)
        error("Invalid input")
        os.exit(1)
    end
    table.insert(return_value,operator)
   
    table.insert(return_value,"end")
    return return_value
end


function float_mul(table_entry)

    return fill_table(table_entry, "*")
end

function float_add(table_entry)
    return fill_table(table_entry, "+")
end

function float_div(a,b)
    return pack_two("/",a,b)
end
    
function float_sub(a,b)
    return pack_two("-",a,b)
end



function float_mod(a,b)
    return pack_two("%",a,b)
end

function float_pow(a,b)
    return pack_two("^",a,b)
end

function float_exp(a)
    return pack_one("EXP",a)
end

function float_ln(a)
    return pack_one("LN",a)
end
    
function float_10x(a)
    return pack_one("10x",a)
end

function float_log(a)
    return pack_one("LOG",a)
end

function float_sin(a)
    return pack_one("SIN",a)
end 

function float_cos(a)
    return pack_one("COS",a)
end

function float_tan(a)
    return pack_one("TAN",a)
end

function float_asin(a)
    return pack_one("ASIN",a)
end

function float_acos(a)
    return pack_one("ACOS",a)
end

function float_atan(a)
    return pack_one("ATAN",a)
end

function float_sinh(a)
    return pack_one("SINH",a)
end

function float_cosh(a)
    return pack_one("COSH",a)
end

function float_tanh(a)
    return pack_one("TANH",a)
end 

function float_asinh(a)
    return pack_one("ASINH",a)
end

function float_acosh(a)
    return pack_one("ACOSH",a)
end

function float_atanh(a)
    return pack_one("ATANH",a)
end

function float_sqrt(a)
    return pack_one("SQRT",a)
end

function float_abs(a)
    return pack_one("ABS",a)
end

function float_floor(a)
    return pack_one("FLOOR",a)
end

function float_ceil(a)
    return pack_one("CEIL",a)
end

function float_round(a)
    return pack_one("RND",a)
end

function float_trunc(a)
    return pack_one("TRUNC",a)
end

function float_pi()
    return pack_zero("PI")
end

function float_deg(a)
    return pack_one("DEG",a)
end   

function float_radian(a)
    return pack_one("RAD",a)
end










--[[

    Assemble s expression

]]--




--[[
L
   take flatten s expression and convert to register op array

]]--
 
local operator_number = 0



-- operator types
local S_FLOAT_VALUE_CFL   = 0
local S_FLOAT_BUFFER_POSITION_CFL = 1
local S_FLOAT_OPERATOR_CFL   =2
local S_FLOAT_OPERATOR_END_CFL = 3

-- lS_FLOAT_OPERATOR_CFL operators
local S_FLOAT_MULTIPLY_CFL = 0
local S_FLOAT_DIVIDE_CFL = 1
local S_FLOAT_ADD_CFL  = 2
local S_FLOAT_SUBTRACT_CFL = 3
local S_MODULUS_CFL = 4
local S_POWER_CFL  = 5
local S_EXP_CFL    = 6
local S_LN_CFL     = 7
local S_10_x_CFL   = 8
local S_LOG_CFL    = 9
local S_SIN_CFL    = 10
local S_COS_CFL    = 11
local S_TAN_CFL    = 12
local S_ASIN_CFL   = 13
local S_ACOS_CFL   = 14
local S_ATAN_CFL   = 15
local S_SINH_CFL   = 16
local S_COSH_CFL   = 17
local S_TANH_CFL   = 18
local S_ASINH_CFL  = 19
local S_ACOSH_CFL  = 20
local S_ATANH_CFL  = 21
local S_SQRT_CFL   = 22
local S_ABS_CFL    = 23
local S_FLOOR_CFL  = 24
local S_CEIL_CFL   = 25
local S_ROUND_CFL  = 26
local S_TRUNC_CFL  = 27
local S_PI_CFL     =  28
local S_DEGREE_CFL = 29
local S_RADIAN_CFL = 30

local float_operators = {}
float_operators["*"]        =S_FLOAT_MULTIPLY_CFL 
float_operators["/"]        =S_FLOAT_DIVIDE_CFL 
float_operators["+"]        =S_FLOAT_ADD_CFL  
float_operators["-"]        =S_FLOAT_SUBTRACT_CFL 
float_operators["%"]        =S_MODULUS_CFL
float_operators["^"]        =S_POWER_CFL  
float_operators["EXP"]      =S_EXP_CFL    
float_operators["LN"]       =S_LN_CFL    
float_operators["10x"]      =S_10_x_CFL   
float_operators["LOG"]      =S_LOG_CFL    
float_operators["SIN"]      =S_SIN_CFL    
float_operators["COS"]      =S_COS_CFL    
float_operators["TAN"]      =S_TAN_CFL    
float_operators["ASIN"]     =S_ASIN_CFL  
float_operators["ACOS"]     =S_ACOS_CFL   
float_operators["ATAN"]     =S_ATAN_CFL   
float_operators["SINH"]     =S_SINH_CFL   
float_operators["COSH"]     =S_COSH_CFL   
float_operators["TANH"]     =S_TANH_CFL
float_operators["ASINH"]    =S_ASINH_CFL  
float_operators["ACOSH"]    =S_ACOSH_CFL  
float_operators["ATANH"]    =S_ATANH_CFL  
float_operators["SQRT"]     =S_SQRT_CFL   
float_operators["ABS"]      =S_ABS_CFL   
float_operators["FLOOR"]    =S_FLOOR_CFL  
float_operators["CEIL"]     =S_CEIL_CFL   
float_operators["RND"]      =S_ROUND_CFL 
float_operators["TRUNC"]    =S_TRUNC_CFL  
float_operators["PI"]       =S_PI_CFL     
float_operators["DEG"]      =S_DEGREE_CFL 
float_operators["RAD"]      =S_RADIAN_CFL 

float_operators["end"] = S_FLOAT_OPERATOR_END_CFL  


local function check_for_float(number)
    
    number = tonumber(number)
    if type(number) == "number" then
        
        return true

    end
    return false
 
end
 
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

    if float_operators[v] ~= nil then
       
        if v == "end" then
           
            table.insert(return_value,{S_FLOAT_OPERATOR_END_CFL,0})
        else
            operator_number = operator_number + 1
            table.insert(return_value,{S_FLOAT_OPERATOR_CFL,float_operators[v]})
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
            table.insert(return_value,{S_FLOAT_BUFFER_POSITION_CFL,tonumber(buffer_position) } )
            return return_value
        else
            print("Error: Invalid input not a valid float",v)
            error("Invalid input")
            os.exit(1)
        end
    else
        print("Error: Invalid input not an operator or a valid string",v)
        error("Invalid input")
        os.exit(1)
    end
end

local function flatten_float_s_expression(stream_input,return_value)
    if return_value ==  nil then
        return_value = {}
    end
  
    for i, v in ipairs(stream_input) do
        if type(v) == "table" then
            return_value = flatten_float_s_expression(v,return_value)
        else
            table.insert(return_value,v)
        end
    end
     
    return return_value
end

local function dump_flatten_float_expression(s_expression,tab)
    if tab == nil then
        tab = "->"
    end
    for i,v in ipairs(s_expression) do
        if(type(v) == "table") then
           
            dump_flatten_float_expression(v,"----"..tab)
           
            
        else
            local message = string.format("%s %s",tab,tostring(v))
            print(message)
        end
    end
end

local function assemble_flattened_s_expression(stream_input,buffer_length)
    flatten_input = {}
    return_value = {}
     
    --dump_flatten_float_expression(stream_input)
    flatten_input = flatten_float_s_expression(stream_input,flatten_input)
    --dump_flatten_float_expression(flatten_input)
    for i,v in ipairs(flatten_input) do

        if type(v) == "string" then
            return_value = handle_string(return_value,v,buffer_length)
        else
            if check_for_float(v) then
                table.insert(return_value,{S_FLOAT_VALUE_CFL,v})
            else
                print("Error: Invalid input",v)
                error("Invalid input")
                os.exit(1)
            end
        end
    end
    return  return_value
end


local function start_s_float_stack_encoding(source_float_map,s_expression)
    
    local buffer_id, buffer_length = get_s_float_buffer_number(source_float_map)
    parameter_stack = #s_expression+5
   
    encoded_stream =  assemble_flattened_s_expression(s_expression,buffer_length)
    
    local stream_name = generate_unique_function_name()
    local message = string.format("const s_float_operator_CFL_t %s[%d] = {",stream_name,#encoded_stream)
    Store_user_code(message)
   
    for i,v in ipairs(encoded_stream) do
       
        if v[1] == 0 then
            local message = string.format("{%d,{.float_value = %f}},",v[1],v[2])
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


function generate_s_float_expression(structure_name,source_float_map,s_expression)

  
    float_map_number,number = get_s_float_buffer_number(source_float_map)
    operator_number = 5
    local parameter_stack_size,stream_length,operator_stream_name = start_s_float_stack_encoding(source_float_map,s_expression)

    

    local message = string.format("const  s_float_definition_CFL_t %s = {%d,%d,%d,%d,%s};\n",structure_name,float_map_number,
       parameter_stack_size,operator_number,stream_length,operator_stream_name)
    Store_user_code(message)
   
end