
local function generate_name_list(name, name_list)
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
    print("made it here")
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
