

local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../lua_CFL_assembler/"
PXT.cwd(newDirectory)
dofile("lua_CFL_Assembler.lua")
PXT.cwd(current_working_directory)
dofile("basic_control.lua")
dofile("if_columns.lua")
dofile("while_column.lua")
dofile("supervisor.lua")
dofile("try.lua")
dofile("chain_column_sequence.lua")
dofile("chain_column_case.lua")
dump_runtime_support()




  

