local user_code = {}
local basic_code = {}
local basic_header_code = {}

local basic_file_name = "basic_code.c"
local basic_header_name = "basic_code.h"

function Store_user_code(code)
     table.insert(user_code, code) 
end

function Store_basic_code(code) 
    
    table.insert(basic_code, code) 
end

function Store_basic_header_code(code) 
    
   
    table.insert(basic_header_code, code) 
end

function dump_user_code()
    local message = "\n\n//----------User code ----\n\n"
    write_output(message)
    for i, str in ipairs(user_code) do write_output(str) end
end
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

function dump_basic_header_code()
    os.remove(basic_header_name)
    local output = io.open(basic_header_name, "w")
    if output == nil then
        print("Cannot open output file " .. output_file)
        os.exit(1)
    end
    output:write(header_start)
    local name = string.match(basic_header_name, "(.+)%.[^%.]+$")
    write_output('#ifndef __'..name..'_H__\n')
    write_output('#define __'..name..'_H__\n')
    local message = "\n\n//----------Ref function header code ----\n\n"
    output:write(message)
    for i, str in ipairs(basic_header_code) do output:write(str) end
    output:write(header_end)
    output:close()
end

function dump_basic_code()
    os.remove(basic_file_name)
    local output = io.open(basic_file_name, "w")
    if output == nil then
        print("Cannot open output file " .. output_file)
        os.exit(1)
    end

    local message = "\n\n//----------User  code ----\n\n"
    output:write(message)
    for i, str in ipairs(basic_code) do output:write(str) end
    output:close()
end
