

function initialize_columns()
    column_number = 0
    column_list = {}
    column_names = {}
    column_id = 0
    watch_dog_list = {}
    watch_dog_names = {}
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
   column_data["watch_dog_number"] = -1

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
    build_status["column_flags"] = generate_unique_function_name() 
    local message = string.format("unsigned char %s[%d];\n",build_status["column_flags"],#column_list)
    write_output(message)
    build_status["new_state"] = generate_unique_function_name()
    message = string.format("unsigned char %s[%d];\n",build_status["new_state"],#column_list) 
    write_output(message)
      build_status["local_data"] = generate_unique_function_name()
    message = string.format("void* %s[%d];\n",build_status["local_data"],#column_list)
    write_output(message)
   
end

local column_header_definition = [[
/*
------------------------ ROM data structures for columns --------------------------
typedef struct Column_ROM_CFL_t
{
  short queue_number;
  bool auto_start;
  unsigned short id;
  unsigned short number;
  unsigned short start;
  short start_state;
  short end_state;
  short watch_dog_id;
} Column_ROM_CFL_t;

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
]]

function output_column_ROM_data_structures()
    write_output(column_header_definition)
    write_output("\n\n//----------ROM data structures for columns ----\n\n")
    build_status["column_data"] = generate_unique_function_name()
    local message = string.format("static const Column_ROM_CFL_t %s[] = {\n",build_status["column_data"])
    write_output(message)
    for i,v in ipairs(column_list) do
       queue_number = column_names[v]["data"]["queue_number"]
      
       local column_data = column_names[v]["data"]
       message = string.format("  { %d,%s, %d, %d, %d, %d, %d,%d },\n",
                            queue_number,
                            column_data["startup_flag"],
                            i-1,
                            column_data["number"],
                            column_data["start"],
                            column_data["start_state"],
                            column_data["end_state"],
                            column_data["watch_dog_number"])
       write_output(message)
       
    end
    write_output("};\n")
end




function dump_columns()
    check_for_undefined_columns()
    output_column_RAM_data_structures()
    output_column_ROM_data_structures()
  end