


function Conf_engine(config_handle,once_allocate_size,private_heap_size)
    local once_size = tostring(once_allocate_size)
    local private_size = tostring(private_heap_size)  
    
    local message = string.format("    void* input = Configure_engine_CFL(%s,%s,%s);\n",config_handle,once_size,private_size) 
    io.write(message)

end

function Def_columns(column_names,column_list) 
   
    io.write("    // define the column list\n")
    local message = string.format("    const char * %s[] = {\n",column_names)
    io.write(message)
    io.write("        ")
    for i, column in ipairs(column_list) do
        message = string.format("%s",column)
        io.write(message)
        if i < #column_list then
            io.write(",")
        end
       
    end
    io.write("};\n")
    
    local length = #column_list
    message = string.format("    Asm_columns_CFL(input,%d,%s);\n",length,column_names)
    io.write(message)
  
end

function Start_column(name,initial_state)
    local message = string.format("    /* \n")
    io.write(message)
    local message = string.format("    Defining Column %s  starting state %s \n",name,tostring(initial_state))
    io.write(message)
    local message = string.format("    */ \n")
    io.write(message)
    local message = string.format("    Asm_start_column_CFL(input, %s, %s);\n",name,tostring(initial_state))
    io.write(message)
end

function Store_one_shot(fn_string, fn_name)
    local message = string.format("    Store_one_shot_function_CFL(input,%s,%s);\n",fn_string,fn_name)
    io.write(message) 
end

function Log_msg(message)
    local message  = string.format("    Asm_log_message_CFL(input,%s);\n",message)
    io.write(message)
end

function Term_column()
    io.write("    Asm_terminate_CFL(input);\n" )
end
  
function  End_column()
    io.write("    Asm_end_column_CFL(input);\n" )
    local message = string.format("     \n")
    local message = string.format("     \n")
    local message = string.format("     \n")
    

end

