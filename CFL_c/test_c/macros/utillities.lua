

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

function generate_event_list(event_name,event_list)
    if #event_list == 0 then
        return
    end
    file:write("    // define the event list\n")
    local message = string.format("    short  %s[] = {\n",event_name)
    file:write(message)
    file:write("        ")
    for i, event in ipairs(event_list) do
        event = tostring(event)
        message = string.format("%s",event)        
        file:write(message)
        if i < #event_list then
            file:write(",")
        end
       
    end
    file:write("};\n")
end 

function generate_name_list(name, name_list)
    if #name_list == 0 then
        return
    end
    for i,v in ipairs(name_list) do
        name_list[i] = quote_string(v)
    end
    local message = string.format("    const char* %s[] = {%s};\n",name,table.concat(name_list,","))
    file:write(message)
end