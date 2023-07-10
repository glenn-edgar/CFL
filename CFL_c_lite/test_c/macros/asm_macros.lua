

print("Loading asm_macros.lua")

table_names = {}
state_machine_names = {}

dofile("utillities.lua")
dofile("columns.lua")
dofile("return_codes.lua")
dofile("basic_functions.lua")
dofile("events.lua")
dofile("column_state_machine.lua")
dofile("s_logic_functions.lua")
dofile("state_machine.lua")
dofile("column_control.lua")



function Start_function(name)
    print("Start_function: " .. name)
    local message = string.format("static void %s(Handle_config_CFL_t* config_handle)\n",name)
    file:write(message)
    file:write("{\n")

end
function Dynamic_memory_size()
    file:write('Printf_CFL("once heap size %d \\n", Allocate_once_remaining_heap_size_CFL(input));\n')
    file:write('Printf_CFL("largest private heap free block %d \\n", Private_heap_largest_free_block_CFL(input));\n')

end

function Dump_private_heap_free_blocks()
    file:write('Printf_CFL("Dumping private heap free blocks \\n");\n')
    file:write(' Dump_private_heap_blocks_CFL(input);')

end

function Conf_engine(config_handle,once_allocate_size,private_heap_size)
    local once_size = tostring(once_allocate_size)
    local private_size = tostring(private_heap_size)
    table_names = {}  
    Init_df_buffers()
    file:write("\n")
    local message = string.format("    void* input = Configure_engine_CFL(%s,%s,%s);\n\n",config_handle,once_size,private_size) 
    file:write(message)

end


function Start_engine(tick_ms,queue_size, idle_function, calendar_function)
    verify_defined_columns()
    tick_ms = tostring(tick_ms)
    queue_size = tostring(queue_size)
    local message = string.format("    Start_engine_CFL(input, %s, %s, %s, %s);\n",tick_ms,queue_size,idle_function,calendar_function)
    file:write(message)
end



function Destroy_engine(message)
    
    message = tostring(message)
    file:write("    Destroy_engine_CFL(input);\n")
    if message ~= nil then
        file:write('   Printf_CFL("'..message..'\\n");\n')
    end
    file:write("}\n")
end


function Store_one_shot(fn_string, fn_name)
    fn_string = quote_string(fn_string)
    local message = string.format("    Store_one_shot_function_CFL(input,%s,%s);\n",fn_string,fn_name)
    file:write(message) 
end

function  Store_boolean_fn(fn_string, fn_parameter)
    fn_string = quote_string(fn_string)
    local message = string.format("    Store_bool_function_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    file:write(message) 
end

function Store_if_function(fn_string,fn_address)
    fn_string = quote_string(fn_string)
    local message = string.format("    Store_if_function_CFL(input,%s,%s);\n",fn_string,fn_address)
    file:write(message) 
end

function Store_try_function(fn_string,fn_address)
     fn_string = quote_string(fn_string)
     message = string.format("    Store_try_function_CFL(input,%s,%s);\n",fn_string,fn_address)  
     file:write(message)
end

function Dump_nodes()
   local message  = string.format("    Asm_dump_nodes_CFL(input);\n")
    file:write(message)
end







--- event functions
function Generate_event(event_name, event_id,event_value,event_param)
       
       local message = string.format("    Event_data_CFL_t %s = { %s, %s, %s};\n",tostring(event_name),tostring(event_id),tostring(event_value),tostring(event_param))
        file:write(message)    
end        

function Send_event(event)
    local message = string.format("    Asm_send_event_CFL(input,%s);\n",tostring(event))
    file:write(message)
end


