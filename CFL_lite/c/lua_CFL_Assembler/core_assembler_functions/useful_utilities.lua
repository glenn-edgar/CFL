


function check_for_duplicates(list)
    local hash = {}
    for i, v in ipairs(list) do
        if hash[v] ~= nil then
            assert(false, "Duplicate value found in list: "..v.."   "..hash[v].."  "..i)
        end
        hash[v] = i
    end
end

function validate_list(list, fn_validataion)
    for i, v in ipairs(list) do
        fn_validataion(v)
    end
end

function generate_hash_array(list,fn_hash)
    local hash_dictionary = {}
    local hash_array = {}
    for i, v in ipairs(list) do
        if hash_dictionary[v] ~= nil then
            assert(false, "Duplicate hash value found in list: "..v.."   "..hash_dictionary[v].."  "..i)
        end
    
        table.insert(hash_array, fn_hash(v))
    end
    return hash_array
end

function check_if_in_list(list, check_item)
    for i, v in ipairs(list) do
        if v == check_item then
            return i-1
        end
    end
    assert(false, "Item not in list")
end

function convert_list(list, fn_convert)
    local new_list = {}
    for i, v in ipairs(list) do
        table.insert(new_list, fn_convert(v))
    end
    return new_list
end