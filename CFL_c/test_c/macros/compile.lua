
-- insure file is global
file = ""

function compile_directory()
    PXT_files = PXT.read("./")
    
    for i, pxt_file in ipairs(PXT_files) do
        base_file = stripFileExtension(pxt_file)
        base_file = base_file..".c"
       compile_file(pxt_file, base_file)
    end
end

function pass_c(input)
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


function compile_file(input_file, output_file)
   
    file = io.open(output_file, "w")
    
    dofile(input_file)
    file:flush()
    file:close()
    print("Compiled "..input_file.." to "..output_file)
end

