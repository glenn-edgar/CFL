function Halt_column()
    file:write("    Asm_halt_CFL(input);\n" )
end 

function Term_column()
    file:write("    Asm_terminate_CFL(input);\n" )
end
  

function  Reset_column()
    file:write("    Asm_reset_CFL(input);\n" )
end

function Stop_engine()
    file:write("    Asm_engine_terminate_CFL(input);\n" )
end

