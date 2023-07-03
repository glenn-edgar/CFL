

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

function starts_with_quote(str)
    return string.sub(str, 1, 1) == "\""
end

function  quote_string(str)
   
    if starts_with_quote(str) ~= true then
        str = q(str)
    end
   
    return str
end

function Comment(input)
    local message = string.format("    // %s\n",input)
    file:write(message)

end 


