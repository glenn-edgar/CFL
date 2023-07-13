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

function start_build(allocate_once_heap_size,private_heap_size,default_event_queue_size)
   initialize_build_variables()
    build_status["allocate_once_heap_size"] = allocate_once_heap_size
    build_status["private_heap_size"] = private_heap_size
   initialize_event_queues(default_event_queue_size)
   initialize_columns()
   initialize_column_elements()

end



function dump_output()
  
   dump_functions()
   dump_user_code()
   dump_event_queues()
   dump_columns()
   dump_column_elements()
   
end





print(#arg)
if #arg >0 then
   dofile(arg[1])
end
close_output()
os.exit(1)

