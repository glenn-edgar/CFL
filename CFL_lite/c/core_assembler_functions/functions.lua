column_functions = {}
one_shot_functions = {}
boolean_functions = {}
try_functions = {}
if_functions = {}

active_column_functions = {}
active_one_shot_functions = {}
active_boolean_functions = {}
active_try_functions = {}
active_if_functions = {}




function dump_column_functions()
    
   
    for fn_name,dummy in pairs(active_column_functions) do
        if active_column_functions[fn_name] ~= nil then
            local code = column_functions[fn_name]["function_code"]
            Store_basic_code(code) 
            local header_code = column_functions[fn_name]["function_header_code"]
            Store_basic_header_code(header_code)
        end
    end
end
function dump_one_shot_functions()
    
   
    for fn_name,dummy in pairs(active_one_shot_functions) do
        if active_one_shot_functions[fn_name] ~= nil then
            local code = one_shot_functions[fn_name]["function_code"]
            Store_basic_code(code)
            local header_code = one_shot_functions[fn_name]["function_header_code"]
            Store_basic_header_code(header_code)
        end
    end
end

function dump_boolean_functions()
    print("dumping boolean functions")
   
    for fn_name,dummy in pairs(active_boolean_functions) do
        local code = boolean_functions[fn_name]["function_code"]
        Store_basic_code(code)
        local header_code = boolean_functions[fn_name]["function_header_code"]
        Store_basic_header_code(header_code)
    end
end

function dump_try_functions()
    print("dumping try functions")
    
    for fn_name,dummy in pairs(active_try_functions) do
        local code = try_functions[fn_name]["function_code"]
        Store_basic_code(code)
        local header_code = try_functions[fn_name]["function_header_code"]
        Store_basic_header_code(header_code)
    end
end

function dump_if_functions()
end

function dump_functions()
    print("dumping functions")
    dump_column_functions()
    dump_one_shot_functions()
    dump_boolean_functions()
    dump_try_functions()
    dump_if_functions()
end

function Store_column_function(op_code, c_function_name, function_code,function_header_code)
    print("Storing column function " .. op_code .. " " .. c_function_name .. " " .. function_code  )
    
    
    column_functions[op_code] = {}
    column_functions[op_code]["c_function_name"] = c_function_name
    column_functions[op_code]["function_code"] = function_code
    column_functions[op_code]["function_header_code"] = function_header_code
    --print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_column_function(op_code)

    if (column_functions[op_code] == nil) then
        print("Error: column function " .. op_code .. " not defined")
        os.exit(1)
    end
    active_column_functions[op_code] = true

end

function Get_column_function(op_code) 
    if (column_functions[op_code] == nil) then
        print("Error: column function " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_column_function(op_code)
    return column_functions[op_code]["c_function_name"]
end



function Store_one_shot_function(op_code,c_function_name,function_code, function_header_code)
    if one_shot_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    one_shot_functions[op_code] = {}
    one_shot_functions[op_code]["c_function_name"] = c_function_name
    one_shot_functions[op_code]["function_code"] = function_code
    one_shot_functions[op_code]["function_header_code"] = function_header_code
    --print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_one_shot_function(op_code)
  
    if (one_shot_functions[op_code] == nil) then
        print("Error: one shot function " .. op_code .. " not defined")
        os.exit(1)
    end
    active_one_shot_functions[op_code] = true

end 

function Get_one_shot_function(op_code)
    if op_code == nil then
        return 'NULL'
    end

    if opcode == 'NULL' then
        return 'NULL'
    end
    
    if (one_shot_functions[op_code] == nil) then
        print("Error: one shot function " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_one_shot_function(op_code)
    return one_shot_functions[op_code]["c_function_name"]
end

function Store_boolean_function(op_code, c_function_name, function_code, function_header_code)

    if boolean_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    boolean_functions[op_code] = {}
    boolean_functions[op_code]["c_function_name"] = c_function_name
    boolean_functions[op_code]["function_code"] = function_code
    boolean_functions[op_code]["function_header_code"] = function_header_code
    --print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_boolean_function(op_code)

    if (boolean_functions[op_code] == nil) then
        print("Error: column function " .. op_code .. " not defined")
        os.exit(1)
    end
    active_boolean_functions[op_code] = true

end

function Get_boolean_function(op_code) 
    if (boolean_functions[op_code] == nil) then
        print("Error: column function " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_boolean_function(op_code)
    return boolean_functions[op_code]["c_function_name"]
end
