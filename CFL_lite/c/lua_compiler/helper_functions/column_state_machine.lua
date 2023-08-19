




















function set_column_state_machine_start()
    if build_status["column_status"] == false then
        print("Cannot end column while no column is being defined")
        os.exit(1)
     end  
     local column_name = build_status["column_name"]
     local column_data = column_names[column_name]["data"]
     column_data["start_state"] = build_status["column_element_count"] - column_data["start"]
     column_names[column_name]["data"] = column_data
end


function set_column_state_machine_end()
    if build_status["column_status"] == false then
        print("Cannot end column while no column is being defined")
        os.exit(1)
     end  
     local column_name = build_status["column_name"]
     local column_data = column_names[column_name]["data"]
     column_data["end_state"] = build_status["column_element_count"] - column_data["start"]
     column_names[column_name]["data"] = column_data
end


function set_column_state_machine_state(state_number)

end