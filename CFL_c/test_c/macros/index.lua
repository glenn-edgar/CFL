PXT.cwd("macros")

dofile("compile.lua")
print("Compiling macros...")
dofile("asm_macros.lua")
print("Done compiling macros.")
PXT.cwd("../")
compile_directory()
os.exit()
