PXT.cwd("core_assembler_functions")
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

function initialize_build_variables()
    build_status = {}
    build_status["column_status"] = false
    build_status["column_name"] = nil
    build_status["allocate_once_heap_size"] = 0
    build_status["private_heap_size"] = 0

end

function start_build(entry_point,allocate_once_heap_size, private_heap_size,
                     default_event_queue_size,debug_function)

    initialize_build_variables()
    build_status["entry_point"] = entry_point
    build_status["allocate_once_heap_size"] = allocate_once_heap_size
    build_status["private_heap_size"] = private_heap_size
    initialize_event_queues(default_event_queue_size)
    initialize_columns()
    initialize_column_elements()
    define_named_queue("main_queue",default_event_queue_size)

end

function dump_header(debug_function)
    local time_control_name = generate_unique_function_name()
    local message = string.format("\n\nstatic Time_control_CFL_t %s;\n\n\n",time_control_name);
    write_output(message)
    local engine_name = generate_unique_function_name()
    message = string.format("\n\nstatic Engine_control_CFL_t %s;\n\n\n",engine_name)
    write_output(message)
    local header_name = generate_unique_function_name()
    local header_code = [[
/*
--------------------------- Handle definition ------------------------------
typedef struct Handle_CFL_t {
    
    void*                              queue_rom;
    void*                              queue_ram;
    void*                              event_data;

    void*                              column_elements_RAM;
    void*                              column_elements_ROM;
                
    void*                              column_flags;
    void*                              column_local_data;
    void*                              column_state;
    void*                              column_data;
          
   void*                              watch_dog_ram_data;        
   void*                              watch_dog_rom_data;
   void*                              time_control;
   void*                              engine_control;
   void*                              debug_function;
   private_heap_malloc                malloc;
   private_heap_free                  free;
   allocate_once_malloc               allocate_once_malloc;
 }Handle_CFL_t;
 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


static const Handle_CFL_t %s = {
   .queue_rom = queue_control;
   .queue_ram = event_control_ram;
   .event_data = event_data_array;
   .column_elements_flags = column_element_RAM;
   .column_elements_ROM = column_elements_ROM;
   .column_flags = column_RAM_flags;
   .column_local_data = column_RAM_local_data;
   .column_new_state = column_RAM_new_state;
   .column_data_ROM = column_data_ROM;
   .watch_dog_ram_data = NULL;
   .watch_dog_rom_data = NULL;
   .time_control = &%s;
   .engine_control = &%s;
   .debug_function = %s;
}
]]
local message = string.format(header_code,header_name,time_control_name,engine_name,debug_function)
write_output(message)


local message = "static void "..build_status["entry_point"].."() {\n"
message = string.format(message)
write_output(message)
message = "   Start_engine_CFL(&%s,%s,%s);\n"
message = string.format(message,header_name,build_status["allocate_once_heap_size"],
                              build_status["private_heap_size"])
write_output(message)
write_output("}\n")


end



function dump_output(debug_function)
   print("Dumping output")
    --dump_functions()
   
    --dump_basic_header_code()
    
    --dump_basic_code()
  
    --dump_user_code()
    dump_event_queues()
    dump_columns()
    dump_column_elements()
  
    dump_header(debug_function)

end



