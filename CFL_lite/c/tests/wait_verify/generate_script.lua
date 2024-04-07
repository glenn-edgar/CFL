local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_CFL_assembler/"
PXT.cwd(newDirectory)
dofile("lua_CFL_Assembler.lua")
PXT.cwd(current_working_directory)
dofile("wait_delay.lua")
dofile("wait_event_pass.lua")
dofile("wait_event_reset.lua")
dofile("wait_event_terminate.lua")
dofile("while_user_function.lua")
dofile("verify.lua")
dump_runtime_support()







   


  

