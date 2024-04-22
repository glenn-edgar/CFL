

dofile("template_processor.lua")
--- to test preprocessor
--dofile("test_preprocessor.lua")

PXT.cwd("core_assembler_functions")
dofile("useful_utilities.lua")
dofile("io.lua")


dofile("names.lua")
dofile("user_code.lua")
dofile("event_queues.lua")
dofile("functions.lua")
dofile("column_element.lua")
dofile("columns.lua")
PXT.cwd("../")

---
--- load helper functions
----
PXT.cwd("helper_functions")

dofile("op_code_loader.lua")

PXT.cwd("../")
build_status = {} -- ensure global variable
function initialize_build_variables()
    build_status = {}
    build_status["column_status"] = false
    build_status["column_name"] = nil
  
    

end

function start_build(entry_point,allocate_once_heap_pointer,  allocate_once_heap_size, private_heap_size,
                     default_event_queue_size,global_event_size,debug_function)

    reset_state_machine()
    initialize_build_variables()
    build_status["entry_point"] = entry_point
    build_status["allocate_once_heap_size"] = allocate_once_heap_size
    build_status["private_heap_size"] = private_heap_size
    build_status["allocate_once_heap_pointer"] = allocate_once_heap_pointer
    build_status["default_event_queue_size"] = default_event_queue_size
    build_status["debug_function"] = debug_function

    reset_user_defined_events()
    initialize_event_queues(default_event_queue_size,global_event_size)
    initialize_columns()
    initialize_column_elements()
    reset_code_buffers()
    initialize_bit_maps()
    initialize_register_maps()
    initialize_rpc_queues()
    

end
time_control_name = nil -- global variable
handle_name = nil -- global variable
engine_name = nil -- global variable
master_heap_starting_location_name = nil -- global variable
remaing_size_name = nil -- global variable
current_heap_pointer = nil -- global variable


function dump_header()
    generate_state_machines()
    time_control_name = generate_unique_function_name()
    local message = string.format("\n\nstatic Time_control_CFL_t %s;\n\n\n",time_control_name);
    write_output(message)
    engine_name = generate_unique_function_name()
    message = string.format("\n\nstatic Engine_control_CFL_t %s;\n\n\n",engine_name)
    write_output(message)
  
    

    remaing_size_name = generate_unique_function_name()
    message = string.format("/* remaining allocate heap size */\n\nstatic unsigned %s;\n\n\n",remaing_size_name)
    write_output(message)
    handle_name = generate_unique_function_name()
    current_heap_pointer = generate_unique_function_name()
    message = string.format("/* current heap pointer */\n\nstatic char* %s;\n\n\n",current_heap_pointer)
    write_output(message)
    heap_block_control = generate_unique_function_name()
    message = string.format("/* heap block area */\n\nstatic CS_MEMORY_CONTROL %s;\n\n\n",heap_block_control)
    write_output(message)
    
    
    local header_def = [[
    
    


const struct Handle_CFL_t %s =
{

  .queue_number = %s,
  .queue_rom = %s,
  .queue_ram = %s,

  .column_elements_flags =%s,
  .column_elements_ROM = %s,

  .watch_dog_struct = %s,
  .watch_dog_count  = %s,
   
   
  .column_flags = %s,
  .column_local_data = %s,
  .column_state = %s,
  .number_of_columns = %d,
  .column_rom_data = %s,

  
  
  
  .time_control = &%s,
  .engine_control =&%s,
  .debug_function = %s,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &%s,
  .master_heap_size = %s,
  .remaining_heap_size = &%s,
  .current_heap_location = &%s,
  .private_heap   = &%s,
  .private_heap_size =   %s,
  .number_of_sm      = %s,
  .sm_rom     =  %s,
  .sm_ram     = %s,
  .number_of_bitmaps = %d,
  .bitmaps = %s,
  .number_of_registermaps = %d,
  .registermaps = %s,
  .number_of_floatmaps = %d,
  .floatmaps = %s,
   .rpc_queue_number = %d,
  .rpc_queue_ram = %s,
  .rpc_queue_rom = %s
} ;

]]

local message = string.format(header_def,
                              handle_name,
                              build_status["event_queue_number"],
                              
                              
                              build_status["event_queue_rom"],
                              build_status["event_queue_ram"],

                              build_status["column_element_ram"],
                              build_status["column_element_rom"],
                              
                              build_status["watch_dog_struct"],
                              build_status["watch_dog_count"],
                              
                              build_status["column_flags"],
                              build_status["local_data"],
                              build_status["new_state"],
                              get_number_of_columns(),
                              build_status["column_data"],
                              
                              
                              time_control_name,
                              engine_name,
                              build_status["debug_function"],
                              build_status["allocate_once_heap_pointer"], 
                              build_status["allocate_once_heap_size"],
                              remaing_size_name,
                              current_heap_pointer,
                              heap_block_control,
                              build_status["private_heap_size"],
                              build_status["number_of_sm"],
                              build_status["sm_rom"],
                              build_status["sm_ram"] ,
                              build_status["number_of_bitmaps"],
                              build_status["bitmaps"],
                              build_status["number_of_register_maps"],
                              build_status["registermaps"],
                              build_status["number_of_float_maps"],
                              build_status["floatmaps"],
                              build_status["rpc_queue_number"],
                              build_status["rpc_queue_ram"],
                              build_status["rpc_queue_rom"]
                  
                              )                              
                              
                              
write_output(message)




format = "const Handle_CFL_t*  %s(){\n"
message = string.format(format,build_status["entry_point"])

write_output(message)
format = "    return &%s;\n}\n"
message = string.format(format,handle_name)
write_output(message)

end



function dump_build()

  message = '#include "run_time_code_CFL.h"\n'
  write_output(message)
  message = '#include "CFL_column_element_state_utilities.h"\n'
  write_output(message)
  message =  '#include "CFL_rpc_packets.h"'
  write_output(message)
  message = '#include "CFL_state_machine.h"\n'
  Store_basic_header_code(message)
  dump_event_queues()

  dump_rpc_queues()
  Dump_user_code()
  
  
    
    
    
    dump_columns()
    dump_column_elements()
    dump_bit_maps()
    dump_register_maps()
    dump_float_maps()
    dump_header()
    write_output(header_end)
    
    
end

function dump_runtime_support()

  message = '#include "CFL_column_element_state_utilities.h"\n'
  
  Store_basic_header_code(message)
  message = '#include "CFL_state_machine.h"\n'
  Store_basic_header_code(message)
  dump_functions()
  
  dump_basic_code()
  dump_basic_header_code()
  
end


