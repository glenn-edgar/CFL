output = nil -- insure global scope
local header_start = [[

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


]]

local header_end = [[
   

#ifdef __cplusplus
}
#endif

#endif
]]


local output = nil

function write_output(str)
   if output == nil then
      print("Output file not set")
      os.exit(1)
   end
   print(str)
   output:write(str)
end

function set_output(output_file)

   os.remove(output_file)
   output = io.open(output_file,"w")
   if output == nil then
      print("Cannot open output file "..output_file)
      os.exit(1)
   end
   
   local name = string.match(output_file, "(.+)%.[^%.]+$")
   local extension = string.match(output_file, "%.([^%.]+)$")
   write_output('#ifndef __'..name..'_H__\n')
   write_output('#define __'..name..'_H__\n')
   write_output(header_start)
end

function close_output()
   write_output(header_end)
   if output ~= nil then
      output:close()
   end
end





