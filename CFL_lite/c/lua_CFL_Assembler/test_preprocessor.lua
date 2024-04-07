
print("made it here to test of template_processor.lua")
reset_template_tables()
variable_table['a'] = "1"
variable_table['b'] = "2"

str = "this is a test"
print("input is ",str)
result = Expand_text_stream(str)
print("result is ",result)

str = 'this is a test <<p_l, - ,a,"b","c" >> <<p,a>> result'
print("input is ",str)
result = Expand_text_stream(str)
print("result is ",result)

str = 'this is a test <<p_l, - a "b" "c" <<p b>> >> <<p,a>> result'
print("input is ",str)
result = Expand_text_stream(str)
print("result is ",result)

set_template_marker("<{","}>")
print("made it here to test of template_processor.lua")
reset_template_tables()
variable_table['a'] = "1"
variable_table['b'] = "2"

str = "this is a test"
print("input is ",str)
result = Expand_text_stream(str)
print("result is ",result)

str = 'this is a test <{p_l, - ,a,"b","c" }> <{p,a}> result'
print("input is ",str)
result = Expand_text_stream(str)
print("result is ",result)

str = 'this is a test <{p_l, - a "b" "c" <{p b}> }> <{p,a}> result'
print("input is ",str)
result = Expand_text_stream(str)
print("result is ",result)
os.exit(1)
--[[
expected output is:
made it here to test of template_processor.lua
input is        this is a test
result is       this is a test
input is        this is a test <<p_l, - ,a,"b","c" >> <<p,a>> result
result is       this is a test 1-"b"-"c" 1 result
input is        this is a test <<p_l, - a "b" "c" <<p b>> >> <<p,a>> result
result is       this is a test 1-"b"-"c"-2 1 result

note 
p and p_l are functions that are defined in template_processor.lua assert
function_table['p_l'] = output
function_table['p'] = dump
variables are stored the folling way

user can add additional functions to function_table


where   
output dumps a list of arguments  
function output(...)
 
  return_value = ""
  local args = {...}  -- args are input parameters
  for i = 1, #args do
      if i==1 then
        token = args[i]  -- first argument is the separatore
      elseif i==2 then
        return_value = return_value..args[i] -- second argument is the first argument
      else
        return_value = return_value..token..args[i] -- all other arguments are separated by the token which is the first argument
      end
      
  end
 
  return return_value
end

function dump(x)
    return x  -- return the input argument but x has been evaluated if it is a variable
end
 ]]--