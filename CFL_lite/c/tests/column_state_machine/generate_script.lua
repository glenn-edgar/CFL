local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_compiler"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

dofile("column_state_machine.lua")
dump_runtime_support()



   



  

