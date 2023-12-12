local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_compiler"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

dofile("basic_control.lua")
dofile("if_columns.lua")
dofile("while_column.lua")
dofile("try.lua")
dump_runtime_support()



   



  

