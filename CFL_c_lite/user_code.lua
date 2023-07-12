local user_code ={}


function Store_user_code(code)
    table.insert(user_code,code)
end


function dump_user_code()
    local message = "\n\n//----------User code ----\n\n"
    write_output(message)   
    for i,str in ipairs(user_code) do
        write_output(str)
    end
end