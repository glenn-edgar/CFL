-- Generate a unique 10-letter function name

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



function generate_unique_function_name()
    local function_name
    repeat
        -- Generate a random 10-letter function name
        function_name = ""
        for i = 1, 10 do
            function_name = function_name .. string.char(math.random(97, 122))
        end
    until not _G[function_name] -- Check if the function name is not already in use
    return function_name
end 