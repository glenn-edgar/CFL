
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

function Store_column_function(op_code,c_function_name,function_code)
    if column_functions[op_code] ~= nil then
        print("Error: function code for "..op_code.." already defined")
        os.exit(1)
    end
    column_functions[op_code] = {}
    column_functions[op_code]["c_function_name"] = c_function_name
    column_functions[op_code]["function_code"] = function_code
    print("functions.lua: "..op_code.." function code inserted")
end

function Activate_column_function(op_code)
    if(column_functions[op_code] == nil) then
        print("Error: column function "..op_code.." not defined")
        os.exit(1)
    end
    active_column_functions[op_code] = true
end