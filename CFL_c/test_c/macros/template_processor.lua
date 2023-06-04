


function parseInputString(input)
    local output = input -- Output string initialized with the input string
  
    -- Pattern to match <<enclosed_string>> markers
    local pattern = "<<(.-)>>"
  
    -- Iterate over each match and replace the enclosed string with the output from the designated function
    for match in input:gmatch(pattern) do
      local replacement = processEnclosedString(match) -- Call the designated function
      output = output:gsub("<<.->>", replacement, 1) -- Replace the first occurrence of the enclosed string
    end
  
    return output
  end
  
  -- Example designated function
  function processEnclosedString(str)
    -- Process the enclosed string and return the desired output
    return "Processed: " .. str
  end
  
  -- Usage example
  --local input = "This is a <<test>> string with <<multiple>> markers."
  --local output = parseInputString(input)
  --print(output)
  
  --This is a Processed: test string with Processed: multiple markers.
  --[[
function process_s_functiona(list)
  -- Check if the list is empty
  if #list == 0 then
    return nil
  end

  -- Check if the first element is a function
  if type(list[1]) == "function" then
    local func = table.remove(list, 1) -- Remove and retrieve the first element (function)
    
  end

  -- Iterate over the list and process table entries recursively
  for i, entry in ipairs(list) do
    if type(entry) == "table" then
      list[i] = executeFunctionWithParameters(entry) -- Replace table entry with the result of the recursive call
    end
  end

  return func(unpack(list)) 
end

-- Example usage
local myFunction = function(param1, param2)
  return "Function called with parameters: " .. param1 .. " " .. param2
end

local innerFunction = function(param)
  return "Inner function called with parameter: " .. param
end

local myList = { myFunction, "Hello", { innerFunction, "World" }, 42 }
local result = executeFunctionWithParameters(myList)
print(result[1]) -- Output: "Function called with parameters: Hello Inner function called with parameter: World 42"

function flattenList(nestedList)
  local flattenedList = {}

  local function flattenHelper(list)
    for _, item in ipairs(list) do
      if type(item) == "table" then
        flattenHelper(item) -- Recursively flatten nested lists
      else
        table.insert(flattenedList, item) -- Append non-list items to the flattened list
      end
    end
  end

  flattenHelper(nestedList)

  return flattenedList
end

-- Example usage
local nestedList = {1, {2, {3, 4}, 5}, 6, {7, 8}}
local flattenedList = flattenList(nestedList)

-- Print the flattened list
for _, item in ipairs(flattenedList) do
  print(item)
end

hello = "return 'Hello World'"
> load(hello)()
Hello World
> print(load(hello))
function: 0x55e069c53580
> print(load(hello)())
Hello World

function chunkify (s)
  return "return " .. s
end

> load(chunkify("5+3"))()
8
> load(chunkify("'Hello World'"))()
Hello World
function compileLuaExpression(expression)
  local compiledFunction, errorMsg = load("return " .. expression)
  
  if errorMsg then
    print("Error compiling expression: " .. errorMsg)
    return nil
  end
  
  return compiledFunction()
end

-- Example usage
local expression = "2 + 3 * 4 - 1"
local result = compileLuaExpression(expression)
print("Result:", result)


  ]]