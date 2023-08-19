
file = "" -- insure file is global
local file_extension = ".c"
local file_extension_mac = ".inc"




function compile_directory_mac()
    PXT_files = PXT.read_mac("./")
    
    for i, pxt_file in ipairs(PXT_files) do
        
        
        base_file = stripFileExtension(pxt_file)
        base_file = base_file..file_extension_mac
       compile_file(pxt_file, base_file)
    end
end


function compile_directory()
    PXT_files = PXT.read("./")
    
    for i, pxt_file in ipairs(PXT_files) do
        base_file = stripFileExtension(pxt_file)
        base_file = base_file..file_extension
       compile_file(pxt_file, base_file)
    end
end



function pass_c(input)
    input = Expand_text_stream(input)
    file:write(input)
end

function stripFileExtension(fileString)
    local dotIndex = fileString:find("%.[^%.]+$")
    if dotIndex then
        return fileString:sub(1, dotIndex - 1)
    else
        return fileString
    end
end

--[[
function saveOutputToFile(input_filefilePath)
    local file = io.open(filePath, "w")
    if file then
        file:write(output)
        file:close()
    else
        print("Error opening file for writing:", filePath)
    end
end
]]--

dofile("template_processor.lua")

function compile_file(input_file, output_file)
   
    file = io.open(output_file, "w")
    print("Compiling "..input_file.." to "..output_file)
    dofile(input_file)
    file:flush()
    file:close()
    
end

