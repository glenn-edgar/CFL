column_functions = {}
one_shot_functions = {}
boolean_functions = {}
try_functions = {}
if_functions = {}
conditional_functions = {}

active_column_functions = {}
active_one_shot_functions = {}
active_boolean_functions = {}
active_try_functions = {}
active_if_functions = {}
active_conditional_functions = {}

function dump_column_functions()

    for fn_name, dummy in pairs(active_column_functions) do
        if active_column_functions[fn_name] ~= nil then
            local code = column_functions[fn_name]["function_code"]
            Store_basic_code(code)
            local header_code =
                column_functions[fn_name]["function_header_code"]
            Store_basic_header_code(header_code)
        end
    end
end
function dump_one_shot_functions()

    for fn_name, dummy in pairs(active_one_shot_functions) do

        if active_one_shot_functions[fn_name] ~= nil then
            local code = one_shot_functions[fn_name]["function_code"]
            Store_basic_code(code)
            local header_code =
                one_shot_functions[fn_name]["function_header_code"]
            Store_basic_header_code(header_code)

        end
    end

end

function dump_boolean_functions()

    for fn_name, dummy in pairs(active_boolean_functions) do
        local code = boolean_functions[fn_name]["function_code"]
        Store_basic_code(code)
        local header_code = boolean_functions[fn_name]["function_header_code"]
        Store_basic_header_code(header_code)
    end
end

function dump_try_functions()

    for fn_name, dummy in pairs(active_try_functions) do
        local code = try_functions[fn_name]["function_code"]
        Store_basic_code(code)
        local header_code = try_functions[fn_name]["function_header_code"]
        Store_basic_header_code(header_code)
    end
end

function dump_conditional_functions()

    for fn_name, dummy in pairs(active_conditional_functions) do
        local code = conditional_functions[fn_name]["function_code"]
        Store_basic_code(code)
        local header_code =
            conditional_functions[fn_name]["function_header_code"]
        Store_basic_header_code(header_code)
    end
end

function dump_if_functions() end

function dump_functions()

    dump_column_functions()
    dump_one_shot_functions()
    dump_boolean_functions()
    dump_try_functions()
    dump_if_functions()
    dump_conditional_functions()
end

function Store_column_function(op_code, c_function_name, function_code,
                               function_header_code)

    column_functions[op_code] = {}
    column_functions[op_code]["c_function_name"] = c_function_name
    column_functions[op_code]["function_code"] = function_code
    column_functions[op_code]["function_header_code"] = function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_column_function(op_code)

    if (column_functions[op_code] == nil) then

        print("Error: column function ++ " .. op_code .. " not defined")
        os.exit(1)
    end
    active_column_functions[op_code] = true

end

function Get_column_function(op_code)
    if (column_functions[op_code] == nil) then
        print("get_column_function")
        print("Error: column function -- " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_column_function(op_code)
    return column_functions[op_code]["c_function_name"]
end

function Store_one_shot_function(op_code, c_function_name, function_code,
                                 function_header_code)
    if one_shot_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    one_shot_functions[op_code] = {}
    one_shot_functions[op_code]["c_function_name"] = c_function_name
    one_shot_functions[op_code]["function_code"] = function_code
    one_shot_functions[op_code]["function_header_code"] = function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

local null_function_name = "null_function"
local null_code = [[
void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}
]]

local null_header_code = [[
void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data);
]]

Store_one_shot_function('NULL', null_function_name, null_code, null_header_code)

function Activate_one_shot_function(op_code)

    if (one_shot_functions[op_code] == nil) then
        print("Error: one shot function " .. op_code .. " not defined")
        os.exit(1)
    end
    active_one_shot_functions[op_code] = true

end

function Get_one_shot_function(op_code)
    if op_code == nil then
        Activate_one_shot_function(op_code)
        return 'NULL'
    end

    if opcode == 'NULL' then
        Activate_one_shot_function(op_code)
        return 'NULL'
    end

    if (one_shot_functions[op_code] == nil) then
        print("Error: one shot function " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_one_shot_function(op_code)
    return one_shot_functions[op_code]["c_function_name"]
end

function Store_boolean_function(op_code, c_function_name, function_code,
                                function_header_code)

    if boolean_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    boolean_functions[op_code] = {}
    boolean_functions[op_code]["c_function_name"] = c_function_name
    boolean_functions[op_code]["function_code"] = function_code
    boolean_functions[op_code]["function_header_code"] = function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_boolean_function(op_code)

    if (boolean_functions[op_code] == nil) then
        print("Error: bool function ++ " .. op_code .. " not defined")
        os.exit(1)
    end
    active_boolean_functions[op_code] = true

end

function Get_boolean_function(op_code)
    if (boolean_functions[op_code] == nil) then
        print("Error: bool function -- " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_boolean_function(op_code)
    return boolean_functions[op_code]["c_function_name"]
end

function Get_conditional_function(op_code)
    if (conditional_functions[op_code] == nil) then
        print("Error: conditional function -- " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_conditional_function(op_code)
    return conditional_functions[op_code]["c_function_name"]
end

function Store_conditional_function(op_code, c_function_name, function_code,
    function_header_code)

    if conditional_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    conditional_functions[op_code] = {}
    conditional_functions[op_code]["c_function_name"] = c_function_name
    conditional_functions[op_code]["function_code"] = function_code
    conditional_functions[op_code]["function_header_code"] = function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_conditional_function(op_code)

    if (conditional_functions[op_code] == nil) then
        print("Error: bool function ++ " .. op_code .. " not defined")
        os.exit(1)
    end
    active_conditonal_functions[op_code] = true

end
