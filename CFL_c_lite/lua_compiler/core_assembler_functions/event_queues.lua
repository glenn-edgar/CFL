local named_queue_header_code = [[

typedef struct Event_data_t
{

  bool  malloc_flag;
  short event_index;
  void* params;

} Event_data_CFL_t;

typedef struct Event_control_CFL_t {
  unsigned short id;
  unsigned short rx_index;
  unsigned short tx_index;
  unsigned short current_queued_number;
  unsigned short max_number;
  Event_data_CFL_t* event_data_queue;


} Event_control_CFL_t;

typedef struct Event_control_RAM_t
{
  unsigned short rx_index;
  unsigned short tx_index;
    unsigned short current_queued_number;
} Event_data_RAM_t;

typedef struct Event_control_ROM_t{ 
  unsigned number;
  unsigned start_index;
} Event_control_ROM_t;



typedef struct Named_event_queue_control_CFL_t
{
  
  unsigned number;
  Event_control_CFL_t *event_queues;
} Named_event_queue_control_CFL_t;


]]

local queue_list = {}
local queue_names = {}
local queue_number = 0
local queue_list = {}


function define_named_queue(name,size)
    if queue_names[queue_name] ~= nil then
        print("Cannot define queue "..queue_name.." twice")
        os.exit(1)
     end
    
    queue_names[name] = {name, size,queue_number}
    return_value = queue_number
    queue_number = queue_number + 1
    table.insert(queue_list,name)
    return return_value
end

function initialize_event_queues(size)
    queue_list = {}
    queue_names = {}
    queue_number = 0
    define_named_queue("default",size)
end

function lookup_named_queue(queue_name)
    if( queue_names[queue_name] == nil) then
        print("Error: queue name "..queue_name.." not defined")
        os.exit(1)
    end
    return queue_names[queue_name][3]
end

local function dump_ram_data_structures()
   local number = 0
   local count  = 0
   for i,queue_name in ipairs(queue_list) do
      queue_data = queue_names[queue_name]
      count = count + 1
      number = number + queue_data[2]
   end
   write_output("\n\n//----------RAM data structures for event queues ----\n\n")
   format_string = "static Event_data_CFL_t event_data_array[%d];\n"
   local message = string.format(format_string,number)
   
   write_output(message)
   format_string = "static Event_control_RAM_t event_control_ram[%d];\n"
   message = string.format(format_string,count)
   write_output(message)
end

local function dump_rom_data_structures()
    number = 0;
    write_output("\n\n//------  ROM data structures for event queues ----\n\n")
    for i,queue_name in ipairs(queue_list) do
        queue_data = queue_names[queue_name]
        format_string = "static const Event_control_ROM_t event_control_rom_%s = { %d, %d };\n"
        size = queue_data[2]
       
        local message = string.format(format_string,queue_name,number,size)
        number = number + size
        write_output(message)
    end
    format_string ="static const Named_event_queue_control_CFL_t queue_control = { %d, {\n"
    local message = string.format(format_string,number)
    write_output(message)
    
    for i,queue_name in ipairs(queue_list) do

        format_string = "     &event_control_rom_%s,\n"
        local message = string.format(format_string,queue_name)
        write_output(message)
    end
    write_output("     }\n};\n")

end

local header_documentation = [[
/*

------------------------------------------ Event queue documentation ---------------------------------------------
typedef struct Event_data_CFL_t
{
  short event_index;
  bool  malloc_flag;
  void* params;

} Event_data_CFL_t;


typedef struct Event_control_RAM_CFL_t
{
  unsigned short rx_index;
  unsigned short tx_index;
  unsigned short current_queued_number;
} Event_data_RAM_t;

typedef struct Event_control_ROM_t{ 
  unsigned                 number;
  unsigned                start_index;
  Event_control_RAM_CFL_t *event_control_ram;
} Event_control_ROM_t;



typedef struct Named_event_queue_control_CFL_t
{
 
  unsigned number;
  Event_control_CFL_t *event_queues;
} Named_event_queue_control_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/
]]


function dump_event_queues()
    write_output(header_documentation)
    dump_ram_data_structures()
    dump_rom_data_structures()

 end


