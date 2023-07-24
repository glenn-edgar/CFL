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
time_control_name = nil -- global variable
handle_name = nil -- global variable
engine_name = nil -- global variable
function dump_header(debug_function)
    time_control_name = generate_unique_function_name()
    local message = string.format("\n\nstatic Time_control_CFL_t %s;\n\n\n",time_control_name);
    write_output(message)
    engine_name = generate_unique_function_name()
    message = string.format("\n\nstatic Engine_control_CFL_t %s;\n\n\n",engine_name)
    write_output(message)
    handle_name = generate_unique_function_name()
    local header_code = [[
/*
--------------------------- Handle definition ------------------------------
typedef struct Handle_CFL_t
{

  Named_event_queue_control_CFL_t *queue_rom;
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
  const char *master_heap_starting_location; // set by lua preprocessor
  unsigned master_heap_size;                 // set by lua preprocessor
  unsigned remaining_heap_size;
  char *current_heap_location;
  char *private_heap;      // set by lua preprocessor
  char *working_heap_area; // set by lua preprocessor
  unsigned private_heap_size;

} Handle_CFL_t;

 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t %s =
{

  .queue_rom    = &queue_control,
  .queue_ram = event_control_ram,
  .event_data = event_data_array,

  .column_elements_flags =column_element_RAM ,
  .column_elements_ROM = column_elements_ROM,

  .column_flags = column_RAM_flags,
  .column_local_data = column_RAM_local_data,
  .column_state = column_RAM_new_state,
  .number_of_columns = %d,
  .column_rom_data = column_data_ROM,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &%s,
  .engine_control =&%s,
  .debug_function =NULL,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = NULL,
  .master_heap_size = 0,
  .remaining_heap_size = 0,
  .current_heap_location = NULL,
   .private_heap   = NULL,
  .working_heap_area   =NULL,
  .private_heap_size =   0,
} ;



]]


local message = string.format(header_code,handle_name,#column_list,time_control_name,engine_name)   
write_output(message)


local message = "static void "..build_status["entry_point"].."() {\n"
message = string.format(message)
write_output(message)
message = " Start_engine_CFL(&%s,%s,%s);\n"
message = string.format(message,handle_name,build_status["allocate_once_heap_size"],
                              build_status["private_heap_size"])
write_output(message)
write_output("}\n")

format = "const Handle_CFL_t*  Get_handle_CFL(){\n"
message = string.format(format)
write_output(message)
format = "    return &%s;\n}\n"
message = string.format(format,handle_name)
write_output(message)

end



function dump_output(debug_function)
   print("Dumping output")
   message = '#include "CFL_inner_engine.h"\n'
    write_output(message)
    --dump_functions()
   
    --dump_basic_header_code()
    
    --dump_basic_code()
  
    --dump_user_code()
    dump_event_queues()
    dump_columns()
    dump_column_elements()
  
    dump_header(debug_function)
    message = "#endif\n"
    write_output(message)

end



