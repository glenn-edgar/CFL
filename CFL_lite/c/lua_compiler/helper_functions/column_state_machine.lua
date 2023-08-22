


local change_column_state_header = [[

int change_column_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local change_column_state_code = [[
int change_column_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
    (void)aux_fn;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        return CONTINUE_CFL;
    }
    unsigned short *new_state = (unsigned short *)params;
       
    change_local_column_state_CFL(input, *new_state);
    return COLUMN_STATE_CHANGE_CFL;
 }

]]
Store_column_function("COLUMN_STATE_CHANGE", 'change_column_state_CFL', change_column_state_code,change_column_state_header)

local new_state_format = "const unsigned short %s = %d;\n"

function Change_column_state(new_state)
    
    if type(new_state) ~= "number" then
        print("Error: change_column_state_function: new_state must be a number")
        os.exit(1)
    end
    table.insert(build_status["column_state_changes"],new_state) 
    new_state_name = generate_unique_function_name()
    Store_user_code(string.format(new_state_format,new_state_name,new_state))
    Activate_column_function("COLUMN_STATE_CHANGE")
    local column_fn_name = Get_column_function("COLUMN_STATE_CHANGE")
    store_column_element(column_fn_name,'NULL',"(void *)&"..new_state_name)
end






function Set_column_state_machine_start()
    if build_status["column_status"] == false then
        print("Cannot end column while no column is being defined")
        os.exit(1)
     end  
     local column_name = build_status["column_name"]
     local column_data = column_names[column_name]["data"]
     column_data["start_state"] = build_status["column_element_count"] - column_data["start"]-1
     column_names[column_name]["data"] = column_data
end


function Set_column_state_machine_end()
    if build_status["column_status"] == false then
        print("Cannot end column while no column is being defined")
        os.exit(1)
     end  
     local column_name = build_status["column_name"]
     local column_data = column_names[column_name]["data"]
     column_data["end_state"] = build_status["column_element_count"] - column_data["start"]-1
     column_names[column_name]["data"] = column_data
end


