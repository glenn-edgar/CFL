function verify_defined_columns()
    local column_state = true
    for i, v in pairs(table_names) do
        if v == false then
            print("Column not defined: " .. i)
            column_state = false
        end
    end
    if column_state == false then
        os.exit()
    end
end


function validate_column_name(name)
    if table_names[name] == true then
        print("Column Name already defined: -" .. name .. "-")
        os.exit()
    end
    if table_names[name] == nil then
        for k,v in pairs(table_names) do
            if k == name then
                print("Existing Column Name: -" .. k.. "-" .. tostring(v))
            end
            print("Existing Column Name: -" .. k.. "-" .. tostring(v))
        end
        print("Non Existant Column Name: -" .. name .. "-")
       
        os.exit()
    end
    table_names[name] = true
end

function Def_columns(column_names,column_list) 
   
    file:write("    // define the column list\n")
    local message = string.format("    const char * %s[] = {\n",column_names)
    file:write(message)
    file:write("        ")
    for i, column in ipairs(column_list) do
        message = string.format("%s",column)
        table_names[message] = false
        
        file:write(message)
        if i < #column_list then
            file:write(",")
        end
       
    end
    file:write("};\n")
    
    local length = #column_list
    message = string.format("    Asm_columns_CFL(input,%d,%s);\n",length,column_names)
    file:write(message)
  
end

function Start_column(name,initial_state)
    validate_column_name(name)
    local message = string.format("\n   /* \n")
    file:write(message)
    local message = string.format("    Defining Column %s  starting initial running state %s \n",name,tostring(initial_state))
    file:write(message)
    local message = string.format("    */ \n")
    file:write(message)
    local message = string.format("    Asm_start_column_CFL(input, %s, %s);\n",name,tostring(initial_state))
    file:write(message)
end

function Start_queue_column(name,initial_state,named_queue)
    validate_column_name(name)
    local message = string.format("\n   /* \n")
    file:write(message)
    local message = string.format("    Defining Column %s  starting initial running state %s \n",name,tostring(initial_state))
    file:write(message)
    local message = string.format("    */ \n")
    file:write(message)
    local message = string.format("    Asm_start_column_event_queue_CFL(input, %s, %s,%s);\n",name,tostring(initial_state),tostring(named_queue))
    file:write(message)
end

function  End_column()
    file:write("    Asm_end_column_CFL(input);\n" )
    local message = string.format("     \n")
    file:write(message)

end