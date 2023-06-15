
function_table = {}
variable_table = {}
print("loading template_processor.lua")




function reset_template_tables()
 
  function_table = {}
  variable_table = {}
  function_table['p_l'] = output
  function_table['p'] = dump
  
end

function output(...)
 
  return_value = ""
  local args = {...}
  for i = 1, #args do
      if i==1 then
        token = args[i]
      elseif i==2 then
        return_value = return_value..args[i]
      else
        return_value = return_value..token..args[i]
      end
      
  end
 
  return return_value
end

function dump(x)
    return x
end








local function generate_tokens(str)
  local tokens = {}

  for token in string.gmatch(str, "[^,]+") do
      table.insert(tokens, token)
  end

  return tokens
end

local function extractFunction(list)
  if #list == 0 then
      return nil, {}
  else
      return list[1], {table.unpack(list, 2)}
  end
end

local function lookupParameter(tbl, index)
  if tbl[index] ~= nil then
      return tbl[index]
  else
      return index
  end
end



local function expand_s_expression(str)
    
 
    -- results are expanded
    tokens = generate_tokens(str)
    
    -- tokenize string
    fn, args = extractFunction(tokens)
    print("function is ",fn)
    print("args are ",table.concat(args, ","))    
    
    if function_table[fn] == nil then
       print("Error: function not found",fn)
       print("original string is ",str)
       print("tokens are ",tokens)
       os.exit(1)
        
    end
    local process_function = function_table[fn]
    local parameters = {}
    for i = 1, #args do
        local arg = args[i]
       
        arg = lookupParameter(variable_table, arg)
        
        table.insert(parameters, arg)
    end
    
    str = process_function(table.unpack(parameters))
    
    return str
    
    
  end
--[[
  function processTextWithTokens(text)
  local generate_text = function(input)
      -- implement or call your actual text generation function here
      return "generated text for: " .. input
  end

  local function parse(start)
      local first, last = text:find("<<", start)
      if not first then return text end  -- no more << found

      local firstEnd, lastEnd = text:find(">>", last + 1)
      if not firstEnd then
          error("Unbalanced << >> tokens")
      end

      -- recursive case: if another << token is found before the >> token
      local innerFirst, _ = text:find("<<", last + 1)
      if innerFirst and innerFirst < firstEnd then
          text = parse(last + 1)
          return parse(lastEnd + 1)  -- process remaining part of the text
      end

      local content = text:sub(last + 1, firstEnd - 1)
      local newText = generate_text(content)
      text = text:sub(1, first - 1) .. newText .. text:sub(lastEnd + 1)
      return parse(first - #content + #newText)  -- process remaining part of the text
  end

  return parse(1)  -- start parsing from the first character
end
]]--



  function Expand_text_stream(text)
    

    local function parse(start)
        local first, last = text:find("<<", start)
        if not first then return text end  -- no more << found
  
        local firstEnd, lastEnd = text:find(">>", last + 1)
        if not firstEnd then
            error("Unbalanced << >> tokens")
        end
  
        -- recursive case: if another << token is found before the >> token
        local innerFirst, _ = text:find("<<", last + 1)
        if innerFirst and innerFirst < firstEnd then
            text = parse(last + 1)
            return parse(lastEnd + 1)  -- process remaining part of the text
        end
  
        local content = text:sub(last + 1, firstEnd - 1)
        local newText = expand_s_expression(content)
        text = text:sub(1, first - 1) .. newText .. text:sub(lastEnd + 1)
        return parse(first - #content + #newText)  -- process remaining part of the text
    end

    parse(1)  -- start parsing from the first character
    return text
end
--[[
  function Expand_text_stream(s)
    if check_for_braces(s) == 0 then
        return s
    end
    -- This table will store the indices of the start and end of each token
    local token_indices = {}
    -- Iterate over the string
    for i=1,#s do
        -- Look for the start of a token
        if s:sub(i,i+1) == "<<" then
            table.insert(token_indices, {start=i})
        -- Look for the end of a token
        elseif s:sub(i,i+1) == ">>" then
            -- Find the last token that doesn't have an end
            for j=#token_indices,1,-1 do
                if not token_indices[j].stop then
                    token_indices[j].stop = i+1
                    break
                end
            end
        end
    end

    -- Ensure that all tokens are balanced
    for _,token in pairs(token_indices) do
        if not token.stop then
            error("Unbalanced tokens")
        end
    end

    -- Replace the tokens with the return value of generate_text
    for i=#token_indices,1,-1 do
        local token = token_indices[i]
        -- Get the inner content of the token
        local inner = s:sub(token.start+2, token.stop-2)
        -- Call the generate_text function with the inner content
        local generated =expand_s_expression(inner)
        print("generated is ",generated)
        -- Replace the token with the generated text
        s = s:sub(1, token.start-1) .. generated .. s:sub(token.stop+1)
    end
    
    -- Return the modified string
    return s
end
]]--