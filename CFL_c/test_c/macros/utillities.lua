

function q(input)
    input = tostring(input)
    return '"' .. input .. '"'
end

function Comment(input)
    local message = string.format("    // %s\n",input)
    file:write(message)

end 