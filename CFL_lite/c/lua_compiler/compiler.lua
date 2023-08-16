

dofile("template_processor.lua")
--- to test preprocessor
---- dofile("test_preprocessor.lua")

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
build_status = {} -- ensure global variable
function initialize_build_variables()
    build_status = {}
    build_status["column_status"] = false
    build_status["column_name"] = nil
    build_status["allocate_once_heap_pointer"] = nil
    build_status["allocate_once_heap_size"] = 0
    build_status["private_heap_size"] = 0
    

end

function start_build(entry_point,allocate_once_heap_pointer,  allocate_once_heap_size, private_heap_size,
                     default_event_queue_size,debug_function)

    
    initialize_build_variables()
    build_status["entry_point"] = entry_point
    build_status["allocate_once_heap_size"] = allocate_once_heap_size
    build_status["private_heap_size"] = private_heap_size
    build_status["allocate_once_heap_pointer"] = allocate_once_heap_pointer
    build_status["default_event_queue_size"] = default_event_queue_size
    build_status["debug_function"] = debug_function
    reset_user_defined_events()
    initialize_event_queues(default_event_queue_size)
    initialize_columns()
    initialize_column_elements()
    reset_code_buffers()
    

end
time_control_name = nil -- global variable
handle_name = nil -- global variable
engine_name = nil -- global variable
master_heap_starting_location_name = nil -- global variable
remaing_size_name = nil -- global variable
current_heap_pointer = nil -- global variable


function dump_header()
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
    
    /*
    --------------------------- Handle definition ------------------------------
    typedef struct Handle_CFL_t
    {
    
      const Named_event_queue_control_CFL_t *queue_rom;
      Event_control_RAM_CFL_t *queue_ram;
      Event_data_CFL_t *event_data;
    
      unsigned char *column_elements_flags;
      const Column_element_CFL_t *column_elements_ROM;
    
      unsigned char *column_flags;
      void **column_local_data;
      unsigned char *column_state;
      const unsigned short number_of_columns;
      const Column_ROM_CFL_t *column_rom_data;
    
      const unsigned short number_of_watch_dogs;
      bool *watch_dog_active;
      unsigned *watch_dog_count;
      unsigned *watch_dog_trigger_count;
      const Column_watch_dog_ROM_CFL_t *watch_dog_rom_data;
      Time_control_CFL_t *time_control;
      Engine_control_CFL_t *engine_control;
      Debug_out_CFL_t *debug_function;
      private_heap_malloc_fn malloc;
      private_heap_free_fn free;
      allocate_once_fn allocate_once;
      char *master_heap_starting_location; 
      const unsigned master_heap_size;             
      unsigned *remaining_heap_size;  // set by c runtime
      char **current_heap_location;  // set by c runtime
      CS_MEMORY_CONTROL *private_heap;      
      //char *working_heap_area; 
      unsigned private_heap_size;
    
    } Handle_CFL_t;
    

    ]]
    local header_code = [[

 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t %s =
{

  .queue_rom    = &%s,
  .queue_ram =  %s,
  .event_data = %s,

  .column_elements_flags =%s,
  .column_elements_ROM = %s,

  .column_flags = %s,
  .column_local_data = %s,
  .column_state = %s,
  .number_of_columns = %d,
  .column_rom_data = %s,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
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
} ;


]]


local message = string.format(header_code,
                              handle_name,
                              build_status["event_queue_control"],
                              build_status["event_queue_ram"],
                              build_status["event_data"],

                              build_status["column_element_ram"],
                              build_status["column_element_rom"],
                              
                              build_status["column_flags"],
                              build_status["local_data"],
                              build_status["new_state"],
                              #column_list,
                              build_status["column_data"],
                              
                              
                              time_control_name,
                              engine_name,
                              build_status["debug_function"],
                              build_status["allocate_once_heap_pointer"], 
                              build_status["allocate_once_heap_size"],
                              remaing_size_name,
                              current_heap_pointer,
                              heap_block_control,
                              build_status["private_heap_size"])   
write_output(message)




format = "const Handle_CFL_t*  %s(){\n"
message = string.format(format,build_status["entry_point"])

write_output(message)
format = "    return &%s;\n}\n"
message = string.format(format,handle_name)
write_output(message)

end



function dump_build()
  print("Dumping output")
  message = '#include "run_time_code_CFL.h"\n'
  write_output(message)
  dump_event_queues()
  Dump_user_code()
  
  
    
    
   
    dump_columns()
    dump_column_elements()
    
    dump_header()
    write_output(header_end)
    
end

function dump_runtime_support()
  dump_functions()
  
  dump_basic_code()
  dump_basic_header_code()
  
end


