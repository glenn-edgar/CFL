local column_ram_header = [[

typedef struct Column_watch_dog_t
{
   bool termination_fl
   unsigned short column_index;
   unsigned trigger_count;
   unsigned current_count;
   One_shot_function_CFL_t trigger_function;

} Column_watch_dog_t;

typedef struct Column_watch_ROM_t
{
   bool termination_flag;
   unsigned short column_index;
   unsigned trigger_count;
   unsigned current_count;
   One_shot_function_CFL_t trigger_function;

} Column_watch_dog_CFL_t;

    typedef struct Column_RAM_t
{

     unsigned char                    flags;
     unsigned char                    new_state;
    ///unsigned                       active:1;
    //unsigned                       column_state_machine:1; // whether column is a state machine
    //unsigned                       column_state_change_request:1; // pending state change request
    //unsigned                       new_state:8; // new state of column
    void*                          local_data;
    Column_watch_dog_t*            watch_dog_control;
   
} typedef struct Column_RAM_t;

typedef struct Column_ROM_t
{
    unsigned short                 queue_number;
    bool                           auto_start;
    unsigned short                 id;
    unsigned short                 number;
    unsigned short                 start;
    unsigned short                 start_state;
    unsigned short                 end_state;    

} Column_ROM_t;
]]


function initialize_columns()
    column_number = 0
    column_list = {}
    column_names = {}
    column_id = 0
end
    
function define_columns(columns)
    for i,v in ipairs(columns) do
       
       column_names[v] = {}
       column_names[v]["defined"] = false
       column_names[v]["number"] = column_number
       column_number = column_number + 1
       table.insert(column_list,v)      
    end
    
end




function define_column(name, startup_flag,queue_name)
   print("define column "..name)
   if build_status["column_status"] == true then
      print("Cannot define column while another column is being defined")
      os.exit(1)
   end
   if(column_names[name] == nil) then
      print("Column name "..name.." not specified in column list")
      os.exit(1)
   end
   if(column_names[name]["defined"] == true) then
      print("Column name "..name.." already defined")
      os.exit(1)
   end
   
   build_status["column_status"] = true
   build_status["column_name"] = name
   local column_data = {}
   column_data["number"] = column_id
   column_id = column_id + 1
   column_data["start"] = #column_element_table -- zero based index
   build_status["number"] = 0 
   column_data["startup_flag"] = startup_flag   
   column_data["start_state"] = -1
   column_data["end_state"] = -1


   if queue_name == nil then
      column_data["queue_number"] = -1
   else
      column_data["queue_number"] = lookup_named_queue(queue_name)
   end

   column_names[name]["defined"] = true
   column_names[name]["data"] = column_data
  
end


function end_column()
   
   if build_status["column_status"] == false then
      print("Cannot end column while no column is being defined")
      os.exit(1)
   end  
   
   if build_status["column_element_count"] == 0 then
      print("Cannot end column with no elements")
      os.exit(1)
   end
   
   local column_name = build_status["column_name"]
   local column_data = column_names[column_name]["data"]
   
   column_data["number"] = build_status["column_element_count"] - column_data["start"]
   column_names[column_name]["data"] = column_data
   build_status["column_status"] = false
   build_status["column_name"] = nil
   
   
end


function check_for_undefined_columns()
   for i,v in ipairs(column_list) do

      if column_names[v]["defined"] == false then
         print("Column "..v.." not defined")
         os.exit(1)
      end
   end
end


function output_column_RAM_data_structures()
    write_output("\n\n//----------RAM data structures for columns ----\n\n")
    
    local message = string.format("unsigned char column_RAM_flags[%d];\n",#column_list)
    write_output(message)
    message = string.format("unsigned char column_RAM_new_state[%d];\n",#column_list) 
    write_output(message)
    message = string.format("void* column_RAM_local_data[%d];\n",#column_list)
    write_output(message)
    message = string.format("Column_watch_dog_t column_RAM_watch_dog_control[%d];\n",#column_list)
    write_output(message)
end



function output_column_ROM_data_structures()
    write_output("\n\n//----------ROM data structures for columns ----\n\n")
    local message = string.format("const Column_ROM_t column_ROM_data[] = {\n")
    write_output(message)
    for i,v in ipairs(column_list) do
       queue_number = column_names[v]["data"]["queue_number"]
      
       local column_data = column_names[v]["data"]
       message = string.format("  { %d,%d %s, %d, %d, %d, %d },\n",
                            i-1,
                            queue_number,
                            column_data["startup_flag"],
                            column_data["number"],
                            column_data["start"],
                            column_data["start_state"],
                            column_data["end_state"])
       write_output(message)
       
    end
    write_output("};\n")
end




function dump_columns()
    check_for_undefined_columns()
    output_column_RAM_data_structures()
    output_column_ROM_data_structures()
  end