

local queue_list = {}
local queue_names = {}
local queue_number = 0
local queue_list = {}
--
-- defining event names
--
local event_names = {}
local user_event_names = {}
local start_event_number = 100 
local current_event_number = start_event_number



function set_user_event_start(number)
  start_event_number = number
  current_event_number = number
end

function dump_user_defined_events()
  write_output("\n\n//nuser defined events \n\n")
  for name,event_data in pairs(user_event_names) do
    
    local format = "\n\n #define %s %s \n"
    local message = string.format(format,event_data[2],event_data[1])
    write_output(message)
  end
end

    
function add_system_event(event_name,data,number)
  if event_names[event_name] ~= nil then
    print("Error: event name "..event_name.." is already defined")
    os.exit(1)
 end
 event_names[event_name] = {number,data}
 
 
end

add_system_event("timer_tick",'TIMER_TICK_CFL',-7)
add_system_event("second",'SECOND_TICK_CFL',-6)
add_system_event("minute",'MINUTE_TICK_CFL',-5)
add_system_event("hour",'HOUR_TICK_CFL',-4)
add_system_event("day",'DAY_TICK_CFL',-3)
add_system_event("month",'MONTH_TICK_CFL',-2)
add_system_event("year",'YEAR_TICK_CFL',-1)

function add_user_event(event_name,data)
   if event_names[event_name] ~= nil then
      print("Error: event name "..event_name.." is already defined")
      os.exit(1)
   end
   event_names[event_name] = {current_event_number,data}
   user_event_names[event_name] = {current_event_number,data}
   current_event_number = current_event_number +1
   return data 
end


function get_event(event_name)
    if event_names[event_name] == nil then
        print("Error: event name "..event_name.." not defined")
        os.exit(1)
    end
    return event_names[event_name][2]
end


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
   format_string = "static Event_control_RAM_CFL_t event_control_ram[%d];\n"
   message = string.format(format_string,count)
   write_output(message)
end

local function dump_rom_data_structures()
    number = 0;
    write_output("\n\n//------  ROM data structures for event queues ----\n\n")
    for i,queue_name in ipairs(queue_list) do
        queue_data = queue_names[queue_name]
        format_string = "static const Event_control_ROM_CFL_t event_control_rom_%s = { %d, %d };\n"
        size = queue_data[2]
       
        local message = string.format(format_string,queue_name,size, number)
        number = number + size
        write_output(message)
    end
    format_string ="static const Event_control_ROM_CFL_t *queue_elements[] = {\n"
    local message = string.format(format_string)
    write_output(message)
    
    for i,queue_name in ipairs(queue_list) do

        format_string = "     &event_control_rom_%s,\n"
        local message = string.format(format_string,queue_name)
        write_output(message)
    end
    write_output("};\n")


    format_string ="static const Named_event_queue_control_CFL_t queue_control = { %d,%d,%s };\n"
    local message = string.format(format_string,#queue_list,number,"queue_elements")
    write_output(message)
    
  


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

typedef struct Event_control_ROM_CFL_t{ 
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
    dump_user_defined_events()
    dump_ram_data_structures()
    dump_rom_data_structures()

 end




