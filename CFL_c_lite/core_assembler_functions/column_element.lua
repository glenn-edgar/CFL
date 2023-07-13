column_element_table = {}

function initialize_column_elements()
    column_element_table = {}
    build_status["column_element_count"] = 0
end

function store_column_element(column_function,helper_function,user_data)
    local temp = {}
     temp["column_function"] = column_function
     temp["helper_function"] = helper_function
     temp["user_data"] = user_data
     table.insert(column_element_table,temp)
     build_status["column_element_count"] = build_status["column_element_count"] + 1
    
  end

  function dump_column_elements()
    
    local message = "\n\n//----------Column elements ----\n\n"
    write_output(message)
    local message = string.format("const Column_element_CFL_t column_elements[] = {\n")
    write_output(message)
    print("message: " .. message)
    for i,element in ipairs(column_element_table) do
        local message = string.format("    {%s,%s,%s},\n",element["column_function"],element["helper_function"],element["user_data"])
        write_output(message)
    end
    local message = string.format("};\n")
    write_output(message)


  end 