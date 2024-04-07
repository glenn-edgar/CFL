local column_element_table = {}

function initialize_column_elements()
    column_element_table = {}
    build_status["column_element_count"] = 0
end
function get_column_element_count()
    return #column_element_table
end

function store_column_element(column_function,helper_function,user_data)
    local temp = {}
     temp["column_function"] = column_function
     temp["helper_function"] = helper_function
     temp["user_data"] = user_data
     table.insert(column_element_table,temp)
     build_status["column_element_count"] = build_status["column_element_count"] + 1
    
  end
  local header_definition = [[

  /* 
  ------------------------ Column element Flash structure --------------------------
     typedef struct Column_element_CFL_t {
        Column_function_CFL_t column_function;
        void *aux_fn;
        void *params
     } Column_element_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

  ]]

  function dump_column_elements()
    
    message = "\n\n//----------Column elements RAM structures----\n\n"
    write_output(message)
    build_status["column_element_ram"] = generate_unique_function_name()
    local message = string.format("\n\nstatic unsigned char %s[%s];\n\n",build_status["column_element_ram"],build_status["column_element_count"])
    write_output(message);
    message = "\n\n//----------Column elements Flash structures----\n\n"
    write_output(header_definition)
    write_output(message)
    build_status["column_element_rom"] = generate_unique_function_name()
    local message = string.format("static const Column_element_CFL_t %s[] = {\n",build_status["column_element_rom"])
    write_output(message)
   
    for i,element in ipairs(column_element_table) do
        local message = string.format("    {%s,%s,%s}, // %d \n",element["column_function"],element["helper_function"],element["user_data"],i-1)
        write_output(message)
    end
    local message = string.format("};\n")
    write_output(message)


  end 