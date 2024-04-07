


    column_functions = {}
    one_shot_functions = {}
    boolean_functions = {}
    state_functions = {}
    

    
    rpc_event_generate_functions = {}
    rpc_event_client_process_functions = {}
    rpc_event_server_process_functions = {}

    active_column_functions = {}
    active_one_shot_functions = {}
    active_boolean_functions = {}
    active_state_functions = {}

   

  
    active_rpc_event_generate_functions = {}
    active_rpc_event_client_process_functions = {}
    active_rpc_event_server_process_functions = {}


function dump_rpc_event_generate_functions()

    for fn_name, dummy in pairs(active_rpc_event_generate_functions) do
        if active_rpc_event_generate_functions[fn_name] ~= nil then
            local code = rpc_event_generate_functions[fn_name]["function_code"]
            Store_basic_code(code)
            local header_code =
                rpc_event_generate_functions[fn_name]["function_header_code"]
            Store_basic_header_code(header_code)
        end
    end
end

function dump_rpc_event_client_process_functions()

    for fn_name, dummy in pairs(active_rpc_event_client_process_functions) do
        if active_rpc_event_client_process_functions[fn_name] ~= nil then
            local code = rpc_event_client_process_functions[fn_name]["function_code"]
            Store_basic_code(code)
            local header_code =
                rpc_event_client_process_functions[fn_name]["function_header_code"]
            Store_basic_header_code(header_code)
        end
    end
end

function dump_rpc_event_server_process_functions()

    for fn_name, dummy in pairs(active_rpc_event_server_process_functions) do
        if active_rpc_event_server_process_functions[fn_name] ~= nil then
            local code = rpc_event_server_process_functions[fn_name]["function_code"]
            Store_basic_code(code)
            local header_code =
                rpc_event_server_process_functions[fn_name]["function_header_code"]
            Store_basic_header_code(header_code)
        end
    end
end



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


function dump_state_functions()

    for fn_name, dummy in pairs(active_state_functions) do
        local code = state_functions[fn_name]["function_code"]
        Store_basic_code(code)
        local header_code = state_functions[fn_name]["function_header_code"]
        Store_basic_header_code(header_code)
    end
end

 



function dump_functions()
    dump_state_functions()
    dump_column_functions()
    dump_one_shot_functions()
    dump_boolean_functions()



    dump_rpc_event_generate_functions()
    dump_rpc_event_client_process_functions()
    dump_rpc_event_server_process_functions()
 
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
    assert( one_shot_functions[op_code] == nil ,"Error: function code for " .. op_code .. " already defined")
   
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
  
    assert(one_shot_functions[op_code] ~= nil, "one_shot_functions[op_code] is nil " .. op_code)
    
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
   
    assert(one_shot_functions[op_code] ~= nil, "one_shot_functions[op_code] is nil " .. op_code)
    
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

function Store_state_function(op_code, c_function_name, function_code,function_header_code)

    if state_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    state_functions[op_code] = {}
    state_functions[op_code]["c_function_name"] = c_function_name
    state_functions[op_code]["function_code"] = function_code
    state_functions[op_code]["function_header_code"] = function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_state_function(op_code)

    if (state_functions[op_code] == nil) then
        print("Error: state function ++ " .. op_code .. " not defined")
        os.exit(1)
    end
    active_state_functions[op_code] = true
end

function Get_state_function(op_code)
    if (state_functions[op_code] == nil) then
        print("Error: bstate function -- " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_state_function(op_code)
    return state_functions[op_code]["c_function_name"]
end












function Store_generate_rpc_event(op_code, c_function_name, function_code,
                                  function_header_code)

    if rpc_event_generate_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    rpc_event_generate_functions[op_code] = {}
    rpc_event_generate_functions[op_code]["c_function_name"] = c_function_name
    rpc_event_generate_functions[op_code]["function_code"] = function_code
    rpc_event_generate_functions[op_code]["function_header_code"] =
        function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_generate_rpc_event(op_code)

    if (rpc_event_generate_functions[op_code] == nil) then
        print("Error: bool function ++ " .. op_code .. " not defined")
        os.exit(1)
    end
    active_rpc_event_generate_functions[op_code] = true

end


function Get_generate_rpc_event(op_code)
    if (rpc_event_generate_functions[op_code] == nil) then
        print("Error: bool function -- " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_generate_rpc_event(op_code)
    return rpc_event_generate_functions[op_code]["c_function_name"]
end


function Store_client_process_rpc_event(op_code,c_function_name,function_code,function_header_code)
    if rpc_event_client_process_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    rpc_event_client_process_functions[op_code] = {}
    rpc_event_client_process_functions[op_code]["c_function_name"] = c_function_name
    rpc_event_client_process_functions[op_code]["function_code"] = function_code
    rpc_event_client_process_functions[op_code]["function_header_code"] =
        function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_client_process_rpc_event(op_code)

    if (rpc_event_client_process_functions[op_code] == nil) then
        print("Error: bool function ++ " .. op_code .. " not defined")
        os.exit(1)
    end
    active_rpc_event_client_process_functions[op_code] = true

end


function Get_client_process_event(op_code)
    if (rpc_event_client_process_functions[op_code] == nil) then
        print("Error: bool function -- " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_client_process_rpc_event(op_code)
    return rpc_event_client_process_functions[op_code]["c_function_name"]
end

function Store_server_process_rpc_event(op_code,c_function_name,function_code,function_header_code)
    if rpc_event_server_process_functions[op_code] ~= nil then
        print("Error: function code for " .. op_code .. " already defined")
        os.exit(1)
    end
    rpc_event_server_process_functions[op_code] = {}
    rpc_event_server_process_functions[op_code]["c_function_name"] = c_function_name
    rpc_event_server_process_functions[op_code]["function_code"] = function_code
    rpc_event_server_process_functions[op_code]["function_header_code"] =
        function_header_code
    -- print("functions.lua: " .. op_code .. " function code inserted")
end

function Activate_server_process_rpc_event(op_code)

    if (rpc_event_server_process_functions[op_code] == nil) then
        print("Error: bool function ++ " .. op_code .. " not defined")
        os.exit(1)
    end
    active_rpc_event_server_process_functions[op_code] = true

end


function Get_server_process_event(op_code)
    if (rpc_event_server_process_functions[op_code] == nil) then
        print("Error: bool function -- " .. op_code .. " not defined")
        os.exit(1)
    end
    Activate_server_process_rpc_event(op_code)
    return rpc_event_server_process_functions[op_code]["c_function_name"]
end