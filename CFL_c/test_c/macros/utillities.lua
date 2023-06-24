

function q(input)
    input = tostring(input)
    return '"' .. input .. '"'
end

function quote_list(input)
    local return_value = {}
    for i,v in ipairs(input) do
        table.insert(return_value,q(v))
    end
    return return_value
end


function Comment(input)
    local message = string.format("    // %s\n",input)
    file:write(message)

end 