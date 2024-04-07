local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_CFL_assembler/"
PXT.cwd(newDirectory)
dofile("lua_CFL_Assembler.lua")
PXT.cwd(current_working_directory)

dofile("state_machine_1.lua")
dofile("state_machine_2.lua")
dofile("state_machine_3.lua")  -- conditional state change

dump_runtime_support()



   



  

