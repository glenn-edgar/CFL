


function Conf_engine(config_handle,once_allocate_size,private_heap_size)
    local once_size = tostring(once_allocate_size)
    local private_size = tostring(private_heap_size)  
    io.write("    void* input = Configure_engine_CFL("..config_handle..","..once_size..","..private_size..");\n" )
end

function Def_columns(column_names,column_list) 
   
    io.write("    // define the column list\n")
    io.write("    const char * "..column_names.."[] = {\n")
   
    io.write("        ")
    for i, column in ipairs(column_list) do
        io.write("\""..column.."\"")
        if i < #column_list then
            io.write(",")
        end
       
    end
    io.write("};\n")
    
    local length = #column_list
    
    io.write("    Asm_columns_CFL(input,"..length..","..column_names..");\n")
  
end

function Start_column(name,initial_state)
    io.write("    Asm_start_column_CFL(input, \""..name.."\", "..tostring(initial_state)..");\n" )
end

function Store_one_shot(fn_string, fn_name)
    io.write("    Store_one_shot_function_CFL(input, \""..fn_string .."\","..fn_name ..");\n" )
end

function Log_msg(message)

    io.write("    Asm_log_message_CFL(input, \""..message .."\");\n" )
end

function Term_column()
    io.write("    Asm_terminate_CFL(input);\n" )
end
  
function  End_column()
    io.write("    Asm_end_column_CFL(input);\n" )
end

