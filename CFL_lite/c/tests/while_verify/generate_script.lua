local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_compiler/"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

dofile("delay_wait.lua")
dofile("wait_event_pass.lua")
dofile("wait_event_reset.lua")
dofile("wait_event_terminate.lua")
dofile("while_user_function.lua")
dofile("verify.lua")

dump_runtime_support()



   


  

