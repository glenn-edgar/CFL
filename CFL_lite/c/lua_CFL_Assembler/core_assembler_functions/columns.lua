local column_number = 0
local column_list = {}
local column_names = {}
local column_id = 0
local watch_dog_list = {}
local watch_dog_names = {}

function initialize_columns()
    column_number = 0
    column_list = {}
    column_names = {}
    column_id = 0
    watch_dog_list = {}
    watch_dog_names = {}
end

function get_number_of_columns()
   return #column_list
end


function get_column_id(name)
   if column_names[name] == nil then
      assert(false,"Column name "..name.." not specified in column list")
      
   end
   return column_names[name]["data"]["number"]
end

function define_columns(columns,queue_size,push_size)
    
    
    for i,v in ipairs(columns) do
      
       if column_names[v] ~= nil then

          assert(false,"Column name "..v.." already defined")
         
       end  
       if queue_size == nil then
         queue_size = build_status["default_event_queue_size"]
      end
         
        
         define_named_queue(v,queue_size,push_size)
        
       column_names[v] = {}
       column_names[v]["queue_size"] = queue_size
       column_names[v]["push_size"] = push_size
       column_names[v]["defined"] = false
       column_names[v]["number"] = column_number
       column_names[v]["queue_number"] = lookup_named_queue(v)
      
       column_number = column_number + 1

       table.insert(column_list,v)      
    end
    
end

function get_column_number(name)
   if column_names[name] == nil then
      assert(false,"Column name "..name.." not specified in column list")

   end
   return column_names[name]["number"]
end

active_column = nil -- insure variable is global
function define_column(name, startup_flag,sm_list)

   local sm_flag = false
   if sm_list == nil then
      sm_list = {}
      sm_flag = false
   end
   if #sm_list > 0 then
      sm_flag = true
   end

   
   if build_status["column_status"] == true then
      assert(false,"Cannot define column while another column is being defined")
      
   end
   if(column_names[name] == nil) then
      assert(false,"Column name "..name.." not specified in column list")
      
   end
   if(column_names[name]["defined"] == true) then
      assert(false,"Column name "..name.." already defined")
      
   end

  
   build_status["column_state_changes"] = {} -- list of column state changes
   build_status["column_status"] = true
   build_status["column_name"] = name
   local column_data = {}
   column_data["sm_flag"] = sm_flag
   column_data["rpc_queue"] = nil
   
   
   column_data["number"] = column_id
   column_id = column_id + 1
   column_data["start"] = get_column_element_count() -- zero based index
   build_status["number"] = 0 
   column_data["startup_flag"] = startup_flag   
   column_data["start_state"] =-1
   column_data["end_state"] = -1
  

   
   column_data["queue_number"] = lookup_named_queue(name)
 
   active_column = {}
   active_column["name"] = name
   active_column["queue_name"] = name
   active_column["number"] = column_data["number"]
   column_names[name]["defined"] = true
   column_names[name]["data"] = column_data
   if sm_flag == true then
      column_data["sm_data_structure"] =  '(void *)&'..MCESM_initialize(sm_list)
   else
      column_data["sm_data_structure"] = "NULL"
   end
  
end

function add_rpc_queue(rpc_queue)

   assert(active_column ~= nil,"Not in column definition")
   active_column["rpc_queue"] = rpc_queue
end

function get_rpc_queue()
   
   if active_column["rpc_queue"] == nil then
      assert(false,"Column name "..active_column["name"].." has no rpc queue defined")
      
   end
   return active_column["rpc_queue"]
end


function end_column()
   
   if build_status["column_status"] == false then
      assert(false,"Cannot end column while no column is being defined")
      
   end  
   
   if build_status["column_element_count"] == 0 then
      assert(false,"Cannot end column with no elements")
   
   end
   
   local column_name = build_status["column_name"]
   local column_data = column_names[column_name]["data"]
   
   column_data["number"] = build_status["column_element_count"] - column_data["start"]
   column_names[column_name]["data"] = column_data
   build_status["column_status"] = false
   build_status["column_name"] = nil
   if column_data["sm_flag"] == true then
      MCESM_finalize()
   end
   if column_data["start_state"] == -1 then
     
      return
   end
   if column_data["end_state"] == -1 then
      assert(false,"Column "..column_name.." has start state but no end state")
      
   end
   if type(column_data["start_state"]) ~= "number" then
      assert(false,"Column "..column_name.." has invalid start state")
      
   end
   if type(column_data["end_state"]) ~= "number" then
      assert(false,"Column "..column_name.." has invalid end state")
      
   end   
   if column_data["end_state"] < column_data["start_state"] then
      assert(false,"Column "..column_name.." has end state less than start state")
      
   end
   if(column_data["end_state"] < column_data["start_state"]) then
      assert(false,"Column "..column_name.." has end state less than start state")
      
   end
   if column_data["end_state"] > column_data["number"] then
      assert(false,"Column "..column_name.." has end state greater than number of elements")
      
   end
   if column_data["start_state"] > column_data["number"] then
      assert(false,"Column "..column_name.." has start state greater than number of elements")
      
   end
   -- check column state changes
   for i,state_change in ipairs(build_status["column_state_changes"]) do
       
      if state_change > column_data["end_state"]-column_data["start_state"] then
         assert(false,"Column "..column_name.." has state change greater than end state")
         
      end
   end
  
   active_column = nil
end


function check_for_undefined_columns()
   for i,v in ipairs(column_list) do
     
      if column_names[v]["defined"] == false then
         assert(false,"Column "..v.." not defined")
         
      end
   end
end

   

function output_column_RAM_data_structures()
    write_output("\n\n//----------RAM data structures for columns ----\n\n")

    
    
    build_status["watch_dog_count"] = generate_unique_function_name()
    local message = string.format("unsigned %s[%d];\n",build_status["watch_dog_count"],#column_list)
    write_output(message)
    
    build_status["watch_dog_struct"] = generate_unique_function_name()
    local message = string.format("Watch_dog_struct_CFL_t * %s[%d];\n",build_status["watch_dog_struct"],#column_list)
    write_output(message)
    
    
    
    
    
    
    
    
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



function output_column_ROM_data_structures()

    write_output("\n\n//----------ROM data structures for columns ----\n\n")
    build_status["column_data"] = generate_unique_function_name()
    local message = string.format("static const Column_ROM_CFL_t %s[] = {\n",build_status["column_data"])
    write_output(message)
    for i,v in ipairs(column_list) do
       queue_number = column_names[v]["data"]["queue_number"]
      
       local column_data = column_names[v]["data"]
       message = string.format("  { %d,%s, %d, %d, %d, %d, %d,%s },\n",
                            queue_number,
                            column_data["startup_flag"],
                            i-1,
                            column_data["number"],
                            column_data["start"],
                            column_data["start_state"],
                            column_data["end_state"],
                            column_data["sm_data_structure"])
       write_output(message)
  
    end
    write_output("};\n")
end




function dump_columns()
   
    check_for_undefined_columns()
    
    output_column_RAM_data_structures()
    output_column_ROM_data_structures()
  end