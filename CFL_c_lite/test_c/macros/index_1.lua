print("loading macro_expansion_commands.lua")

dofile("macros/macro_expansion_commands.lua")
print("loaded macro_expansion_commands.lua")

file = nil -- insure file is global
function set_output_file(file_name)
    close_output_file()
    file = io.open(file_name, "w")

end

function close_output_file()
    if file == nil then
        return
    end
    file:flush()
    file:close()
end
PXT.cwd("macros")

dofile("compile.lua")
--dofile("test_preprocessor.lua")


print("Compiling macros...")
dofile("asm_macros.lua")

print("Done compiling macros.")
PXT.cwd("../")
compile_directory_mac()
PXT.cwd("basics")
print("Compiling basics...")
compile_directory_mac()
PXT.cwd("../")
PXT.cwd("data_flow")
print("Compiling data_flow...")
compile_directory_mac()
PXT.cwd("../")
PXT.cwd("named_and_column_events")
print("Compiling named_column_events...")
compile_directory_mac()
PXT.cwd("../")
PXT.cwd("state_machine")
print("Compiling state_machine...")
compile_directory_mac()
PXT.cwd("../")
PXT.cwd("unit_tests")
print("Compiling unit_tests...")

compile_directory_mac()
PXT.cwd("../")

os.exit(0)
