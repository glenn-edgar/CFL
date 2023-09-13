local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_compiler"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

dofile("state_machine_1.lua")
dofile("state_machine_2.lua")
dofile("state_machine_3.lua")  -- conditional state change
dofile("state_machine_4.lua")  -- sync event
--dofile("state_machine_5.lua")  -- column state machine
dump_runtime_support()



   



  

