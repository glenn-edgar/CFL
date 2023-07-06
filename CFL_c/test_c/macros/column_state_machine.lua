
function Store_column_start()
    local message = string.format("    Asm_store_column_starting_state_CFL(input);\n")
    file:write(message)
end

function Store_column_end()
    local message = string.format("     Asm_store_column_ending_state_CLF(input);\n")
    file:write(message)
end

function Change_column_state(column_state)
    column_state = tonumber(column_state)
    column_state = column_state//1
    local message = string.format("    Asm_change_column_state_CFL(input,%d);\n",column_state)
    file:write(message)
end











