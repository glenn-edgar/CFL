


dofile("functions.lua")

---
--- load helper functions
----
dofile("return_codes.lua")








function initialize_build_variables()
    build_status = {}
    build_status["column_status"] = false
    build_status["column_name"] = nil
    build_status["allocate_once_heap_size"] = 0
    build_status["private_heap_size"] = 0
    column_number = 0
    column_list = {}
    column_names = {}
    queue_number = 0
    queue_list = {}
    queue_names = {}
    column_element = {}
   
end

function start_build(allocate_once_heap_size,private_heap_size)
   initialize_build_variables()
    build_status["allocate_once_heap_size"] = allocate_once_heap_size
    build_status["private_heap_size"] = private_heap_size

end

function define_columns(column_list)
    for i,v in ipairs(column_list) do
       column_names[v] = {}
       column_names[v]["defined"] = false
       column_names[v]["number"] = column_number
       column_number = column_number + 1
       table.insert(column_list,v)      
    end
end

function define_named_queue(queue_name,queue_size)
   if queue_names[queue_name] ~= nil then
      print("Cannot define queue "..queue_name.." twice")
      os.exit(1)
   end
    queue_names[queue_name] = {}
    queue_names[queue_name]["size"]= queue_size
    queue_names[queue_name]["number"] = queue_number    
    table.insert(queue_list,queue_name)
    queue_number = queue_number + 1
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
   column_data["start"] = #column_element_table -- zero based index
   build_status["column_element_count"] = 0 
   column_data["startup_flag"] = startup_flag   
   column_data["queue_name"] = queue_name
   if queue_name ~= nil then
      if queue_names[queue_name] == nil then
         print("Queue name "..queue_name.." not defined")
         os.exit(1)
      end               
      column_data["queue_number"] = queue_names[queue_name]["number"]
      
   else 
      column_data["queue_number"] = -1
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

   local column_data = columns[build_status["column_name"]]["data"]
   
   column_data["number"] = build_status["column_element_count"]
   column[build_status["column_name"]]["data"] = column_data
   build_status["column_status"] = false
   build_status["column_name"] = nil
   
end


function store_column_element(column_function,helper_function,user_data)
  local temp = {}
   temp["column_function"] = column_function
   temp["helper_function"] = helper_function
   temp["user_data"] = user_data
   table.insert(column_element,temp)
   build_status["column_element_count"] = build_status["column_element_count"] + 1
end

print(#arg)
if #arg >0 then
   dofile(arg[1])
end


