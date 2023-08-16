
function_table = {}
variable_table = {}
--print("loading template_processor.lua")




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
    local currentToken = ""
    
    for i = 1, #str do
      local char = str:sub(i, i)
      
      if char == " " or char == "\t" or char == "," then
        if currentToken ~= "" then
          table.insert(tokens, currentToken)
          currentToken = ""
        end
      else
        currentToken = currentToken .. char
      end
    end
    
    if currentToken ~= "" then
      table.insert(tokens, currentToken)
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






local function find_markers(text,marker,type,index,pat_array)
    
    local count = 0
    local flag = true
    local start_index = 0
    local end_index = 0
    while flag == true do
        start_index, end_index = string.find(text,marker,end_index+1,true)
      
        if start_index ==nil then
            flag = false
        else
           table.insert(index,start_index)
           temp = {  start_index, end_index ,type}
           pat_array[start_index] = temp
           count = count+1
      end
    end
    
    return count
end

local function expand_s_expression(str)
    local index = {}
    local pat_array = {}
    local expand = false    
    if find_markers(str,'<<',true,index,pat_array) > 0  then
       
       str = Expand_text_stream_a(str)
       expand = true      
        
    end
    
    -- results are expanded

    tokens = generate_tokens(str)
    
    -- tokenize string
    fn, args = extractFunction(tokens)
    
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


function Expand_text_stream(input_text)
   
   
    temp = Expand_text_stream_a(input_text)
    
    return temp
end   

function Expand_text_stream_a(input_text)
    
        

    local index= {}
    local pat_array ={}

    start_number = find_markers( input_text,'<<',true,index,pat_array)
    if start_number == 0 then
       
        return input_text
    end
   
    end_number = find_markers(input_text, '>>',false,index,pat_array)
    
    
    if start_number ~= end_number then
        print("Error: unbalanced << >> tokens",start_number,end_number,input_text)
        assert(false)
    end
   
    table.sort(index)
    
    
    scan_for_order(index,pat_array,input_text)

    temp =  build_text( index,pat_array,input_text)
    
   
    return temp
  end                      
  

      
function scan_for_order(index,pat_array,input)
   
    local level = 0
    for i,j in ipairs(index) do 
       
        local k = pat_array[j]
        
        if i==1 then
           
            if k[3]==false then
                print("Error: first token is >>",j,input)
                assert(false)
            end
            level = 1
        else
           if k[3] == true then
                level =level+1
            else
                level = level -1
            end
            if(level < 0) then
                print("Error: unbalanced << >> tokens",j,input)
                assert(false)
            end
        end
       
    end
    if level ~= 0 then
        print("Error: unbalanced << >> tokens",level,input)
        assert(false)
    end
   
end

function build_text(index,pat_array,input)
   
    local start = 1
    local ending = #input
    local level = 0
    local expression_start = 1
    local text_start = 1
    local return_value = ""
    for   i,j in ipairs( index  ) do
       
        local k = pat_array[j]
        
        
        if k[3] == true then
            level =level+1
            if level == 1 then    
                return_value = return_value .. input:sub(text_start,k[1]-1)
               
                expression_start = k[2]+1
                
            end
        else
            level = level -1
            
        end
        if level == 0 then
          
            
            return_value = return_value .. expand_s_expression(input:sub(expression_start,k[1]-1))
            
            
            text_start = k[2]+1
     
            
        end
    end
    return_value = return_value .. input:sub(text_start,ending)
    
   
    return return_value
end    


              
--print("template processor loaded  ")
  