
local function generate_name_list(name, name_list)
    for i,v in ipairs(name_list) do
        name_list[i] = quote_string(v)
    end
    local message = string.format("    const char* %s[] = {%s};\n",name,table.concat(name_list,","))
    file:write(message)
end


function Enable_columns(col_name,column_list,disable_flag)
    if type(disable_flag) ~= "boolean" then
        print("disable_flag must be a boolean")
        assert(false)
    end
    disable_flag = tostring(disable_flag)
    
    if type(col_name) ~= "string" then
        print("col_name must be a string")
        assert(false)
    end
    if type(column_list) ~= "table" then
        print("column_list must be a table")
        assert(false)
    end
    generate_name_list(col_name,column_list)
    local message = string.format("    Asm_enable_columns_CFL(input,%d,%s,%s);\n",#column_list,col_name,disable_flag)
    file:write(message)
end

function Disable_columns(col_name,column_list)

    
    if type(column_list) ~= "table" then
        print("column_list must be a table")
        assert(false)
    end
    generate_name_list(col_name,column_list)
    local message = string.format("    Asm_disable_columns_CFL(input,%d,%s);\n",#column_list,col_name)
    file:write(message)
end

function Reset_columns(col_name,column_list)
    

   if type(col_name) ~= "string" then
        print("col_name must be a string")
        assert(false)
    end
    
    if type(column_list) ~= "table" then
        print("column_list must be a table")
        assert(false)
    end

    generate_name_list(col_name,column_list)
    local message = string.format("    Asm_reset_columns_CFL(input,%d,%s);\n",#column_list,col_name)
    file:write(message)
end

function Join_columns(col_name,column_list,disable_flag)
    if type(disable_flag) ~= "boolean" then
        print("disable_flag must be a boolean")
        assert(false)
    end
    disable_flag = tostring(disable_flag)
    if type(col_name) ~= "string" then
        print("col_name must be a string")
        assert(false)
    end
    
    if type(column_list) ~= "table" then
        print("column_list must be a table")
        assert(false)
    end
    generate_name_list(col_name,column_list)
    local message = string.format("    Asm_join_columns_CFL(input,%d,%s,%s);\n",#column_list,col_name,disable_flag)
    file:write(message)
end

function If_columns(if_name,col_name,column_list,termination_fn,user_data)
    termination_fn = quote_string(termination_fn)
    if_name = quote_string(if_name)
    generate_name_list(col_name,column_list)
    local message = string.format("    Asm_if_columns_CFL(input,%s,%d,%s,%s,%s);\n",
       if_name,#column_list,col_name,termination_fn,user_data);
    file:write(message)
end

function Set_return_code(return_code)
    if type(return_code) ~= "boolean" then
        print("return_code must be a boolean")
        assert(false)
    end
    return_code = tostring(return_code)
    local message = string.format("    Asm_set_return_code(input,%s);\n",return_code)
    file:write(message)
end

--void Asm_try_columns_CFL(void* input, const char* try_function_name, int number_of_columns,
--const char** column_names, bool terminate_flag, bool invert_flag, void* user_data);
function Try_columns(try_fn,col_name,column_list,invert_flag,user_data)
    
    verify_bool(invert_flag)
    try_fn = quote_string(try_fn)
    generate_name_list(col_name,column_list)
    local message = string.format("    Asm_try_columns_CFL(input,%s,%d,%s,%s,%s);\n",try_fn,#column_list,
        col_name,invert_flag,user_data)
    file:write(message)
end
          
function  While_columns(bool_fn,col_name,columns,user_data)
    
    bool_fn = quote_string(bool_fn)
    generate_name_list(col_name,columns)

    verify_string(user_data)
   
    local message = string.format("     Asm_while_columns_CFL(input,%s,%d,%s,%s);\n",
           bool_fn,#columns,col_name,user_data)

    file:write(message)
end

function verify_string(input)
    if type(input) ~= "string" then
        print("input must be a string",input)
        assert(false)
    end
end

function verify_bool(input)
    if type(input) ~= "boolean" then
        print("input must be a boolean",input)
        assert(false)
    end
end

