local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_CFL_assembler/"
PXT.cwd(newDirectory)
dofile("lua_CFL_Assembler.lua")
PXT.cwd(current_working_directory)

dofile("rpc_services_1.lua")
dofile("rpc_services_2.lua")
dofile("sync_service_1.lua")
dofile("sync_service_2.lua")
dump_runtime_support()



   



  

