
dofile("macros/template_processor.lua")

function pass_lua(input)
    
    input = Expand_text_stream(input)
    
    file:write(input)
end

function generate_code(input)
    output = "pass_c([["
    output  = output .."\n".. Expand_text_stream(input).."\n".."]])\n"
    file:write(output)
end

function write_comment(input)
    local message = string.format("--[[\n%s\n]]-- \n",input)
    file:write(message)

end 


function starts_with_quote(str)
    return string.sub(str, 1, 1) == "\""
end

function q(input)
    input = tostring(input)
    return '"' .. input .. '"'
end

function  quote_string(str)
   
   
    if starts_with_quote(str) ~= true then
        str = q(str)
    end
    
    return str
end

local function verify_bool(input)
    if type(input) ~= "boolean" then    
        print("Error: input is not a boolean",input)
        os.exit(1)
    end
end 

local function generate_column_name(sm_name,state_name)
    
    return  quote_string(sm_name.."_"..state_name.."_chain")
end

local function generate_queue_name(sm_name,state_name)
   
    return  quote_string(sm_name.."_"..state_name.."_queue")
end

local function generate_state_name(sm_name,state_name)
   return  quote_string(sm_name.."_"..state_name)
end 

local function generate_column(column_name,init_state,queue_name,code_table)
      verify_bool(init_state)
      local format_string = "     Start_queue_column(%s,%s,%s)\n"
      local message = string.format(format_string,column_name,init_state,queue_name)
      file:write(message)
 
      if code_table ~= nil then
          
          for i,code in ipairs(code_table) do
              
              temp = string.format("        %s\n",code)
              file:write(temp)
          end
      end
    

    file:write("     End_column()\n\n\n\n\n")
end

function dump_table(input)
    for i, v in ipairs(input) do
        print(i, v)
    end
    
end

function Def_state_machines(sm_array_name ,sm_list)
    local temp_sm_quote = {}
    for i, sm in ipairs(sm_list) do
        temp_sm_quote[i] = quote_string(sm)
    end
    local message = string.format("     Define_state_machines(%s,{%s})\n\n",quote_string(sm_array_name),table.concat(temp_sm_quote,","))
    file:write(message)
end

function Def_columns(column_names,column_list) 
    local temp_column_quote = {}
    for i, column in ipairs(column_list) do
        temp_column_quote[i] = quote_string(column)
    end
    local message = string.format("     Def_columns(%s,{%s})\n\n",quote_string(column_names),table.concat(temp_column_quote,","))
    file:write(message)
end



function Composite_state_machine(sm_name,state_names,initial_state,user_data,queue_size,state_code)
 
    local column_table = {}
    local format_string = ""
    local message = ""
    local sm_manager_chain_name = quote_string(sm_name.."_manager_chain")
    local sm_queue_name = quote_string(sm_name.."_queue")
    
    local column_name = ""
    local queue_name = ""
    
    local column_list = {}
    local queue_list = {}
    table.insert(column_list,sm_manager_chain_name)
    table.insert(queue_list,sm_queue_name)
    for i, state in ipairs(state_names) do
        
        column_name = generate_column_name(sm_name,state)
        queue_name = generate_queue_name(sm_name,state)
        column_table[state] = { column_name, queue_name }
        table.insert(column_list,column_name)
        table.insert(queue_list,queue_name)
    end
   
    

    message = string.format("     Def_columns(%s,{%s})\n\n",quote_string(sm_name.."_column_array"),table.concat(column_list,","))
    file:write(message)

    for i,queue_name in ipairs(queue_list) do
        format_string = "     Define_event_queue(%s,%d)\n\n"
        message = string.format(format_string,quote_string(queue_name),queue_size)
        file:write(message)
    end
    --local sm_string = string.format('    Define_state_machines("%s",{"%s"})\n\n',sm_name.."_array",sm_name)
    --file:write(sm_string)
    local temp_table = {}
    for i,temp1 in ipairs(state_names) do
        table.insert(temp_table,quote_string(temp1))
    end
    local temp_string = table.concat(temp_table,",")
    local format_string = "     Define_sm(%s,{%s},%s,%s,%s,%s)\n\n"
    local message = string.format(format_string,quote_string(sm_name),temp_string,quote_string(sm_manager_chain_name),
                    quote_string(sm_queue_name),quote_string(initial_state),quote_string(user_data))   
    file:write(message)
   
    for i, state_name in ipairs(state_names) do
        format_string = "       Define_state(%s,%s,%s)\n\n"
       
        temp_queue_name = generate_queue_name(sm_name,state_name)
        temp_chain = generate_column_name(sm_name,state_name)
        message = string.format(format_string,quote_string(state_name),quote_string(temp_chain),quote_string(temp_queue_name))
        file:write(message)
    end
    
    format_string = "     End_state_machine()\n\n\n\n\n"
    file:write(format_string)
   
    local return_value = {}
    return_value["state_machine_name"] = sm_name
    return_value["manager"] = {sm_manager_chain_name,sm_queue_name}

    --generate_column(sm_manager_chain_name,false,sm_queue_name,state_code["manager"])
    return_value["state"] = {}
    -- define manage column
    for i, state_name in ipairs(state_names) do
       table.insert(return_value["state"],state_name)
       --local state_table = state_code[state_name]
       --local column_name =  generate_column_name(sm_name,state_name)
       --local temp_queue = generate_queue_name(sm_name,state_name)
       --generate_column(column_name,false,temp_queue,state_table)
    end

    return_value["code"] = state_code
    return return_value
    
end

function Expand_table(column_queue_tbl)
   
    local state_code = column_queue_tbl["code"]
    local control_column_name = column_queue_tbl["manager"][1]
    local control_queue_name = column_queue_tbl["manager"][2]
   
    generate_column(control_column_name,false,control_queue_name,state_code["manager"])
   
    local state_data = column_queue_tbl["state"]
    sm_name = column_queue_tbl["state_machine_name"]
    for i, state_name in ipairs(state_data) do
       
       
        local code = state_code[state_name]
        local column_name =  generate_column_name(sm_name,state_name)
        local temp_queue = generate_queue_name(sm_name,state_name)
        generate_column(column_name,false,temp_queue,code)
     end

end


print("made it to the end of macro_expansion_commands.lua")