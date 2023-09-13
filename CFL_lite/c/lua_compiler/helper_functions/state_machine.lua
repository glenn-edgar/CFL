
sm_active = false
reserved_sms = {}
reserved_sms_index = {}
sm_dictionary = {}
active_state_machine = {}

function reset_state_machine()
    sm_active = false
    reserved_sms = {}
    reserved_sms_index = {}
    sm_dictionary = {}
    active_state_machine = {}
end

function reserve_state_machines(sm_list)
    
    for i,v in ipairs (sm_list) do
        if(reserved_sms[v] ~= nil) then
            print("error sm_name "..v.." already reserved")
            os.exit(1)
        end
        reserved_sms[v] = false
        reserved_sms_index[#reserved_sms_index+1] = v
    end
end


function check_for_defined_sms()
    for v,value in ipairs(reserved_sms)do
        if value == false then
            print("error sm_name "..reserved_sms_index[v].." not defined")
            os.exit(1)
        end
    end
end

function validate_state_machine(sm_name)
    if(reserved_sms[sm_name] == nil) then
        print("error sm_name "..sm_name.." not reserved")
        os.exit(1)
    end
    if(reserved_sms[sm_name] == true) then
        print("error sm_name "..sm_name.." already defined")
        os.exit(1)
    end 
    reserved_sms[sm_name] = true
    
end 

function find_index(sm_name)
    for i,v in ipairs(reserved_sms_index) do
        if v == sm_name then
            return i-1
        end
    end
    print("error sm_name "..sm_name.." not found")
    os.exit(1)
end

function define_state_machine(sm_name,state_list,queue_name,queue_size,user_data)
    if(sm_active == true) then
        print("error sm_active is in current operation")
        os.exit(1)
    end
    if(sm_dictionary[sm_name] ~= nil) then
        print("error sm_name already defined")
        os.exit(1)
    end
    validate_state_machine(sm_name)

    active_state_machine = {}
    active_state_machine["index"] = find_index(sm_name)
    active_state_machine["queue_size"] = queue_size
    active_state_machine["name"] = sm_name
    active_state_machine["state_list"] = {}
    active_state_machine["chain_list"] = {}
    active_state_machine["queue_list"] = {}
    active_state_machine["state_order"] = state_list
    
    for i,v in ipairs(state_list)do
        active_state_machine["state_list"][v] = false
    end
    active_state_machine["queue_name"] = queue_name
    
    active_state_machine["user_data"] = user_data
    active_state_machine.defined_states = {}
    sm_active = true
end

function define_add_manager_chain()
    chain_name = generate_unique_function_name()
    if(sm_active == false) then
        print("error sm_active is not active")
        os.exit(1)
    end
    if( active_state_machine.sm_manager ~= nil) then
        print("error sm_manager already defined")
        os.exit(1)
    end
    if( active_state_machine.sm_queue ~= nil) then
        print("error sm_queue already defined")
        os.exit(1)
    end
    
    queue_name = active_state_machine.queue_name
    if(queue_name == nil) then
        print("error queue_name is nil")
        os.exit(1)
    end
    active_state_machine.sm_manager = chain_name

    
    define_named_queue(queue_name,active_state_machine.queue_size)
    define_columns({chain_name})
    define_column(chain_name,false,queue_name)
end

function verify_state(state_name)
    if(active_state_machine.state_list[state_name] == nil) then
        print("error state_name "..state_name.." not defined")
        os.exit(1)
    end
    if(active_state_machine.state_list[state_name] == true) then
        print("error state_name "..state_name.." already defined")
        os.exit(1)
    end
    active_state_machine.state_list[state_name] = true
end

local function check_for_defined_state(state_name)
    if(active_state_machine.state_list[state_name] == nil) then
        print("error state_name "..state_name.." not defined")
        os.exit(1)
    end
    if(active_state_machine.state_list[state_name] == true) then
        print("error state_name "..state_name.." already defined")
        os.exit(1)
    end
    active_state_machine.state_list[state_name] = true
end

function find_state_location(state_name)
    for i,v in ipairs(active_state_machine.state_order) do
        if v == state_name then
            return i-1
        end
    end
    print("error state_name "..state_name.." not found")
    os.exit(1)
end

function define_state(state_name)
    chain_name = generate_unique_function_name()
    queue_name = generate_unique_function_name()
    if(sm_active == false) then
        print("error sm_active is not actove")
        os.exit(1)
    end
    if( active_state_machine.sm_manager == nil) then
        print("error sm_manager not defined")
        os.exit(1)
    end
    check_for_defined_state(state_name)
    if(chain_name == nil) then
        print("error chain_name is nil")
        os.exit(1)
    end
    if(queue_name == nil) then
        print("error queue_name is nil")
        os.exit(1)
    end
    active_state_machine.current_state = state_name

    active_state_machine.defined_states[state_name] = {chain_name,queue_name}
    define_columns({chain_name})
 
    define_named_queue(queue_name,active_state_machine.queue_size)
  
    define_column(chain_name,false,queue_name)
end



local function check_for_undefined_states()
    for i,v in pairs(active_state_machine.state_list) do
        if v == false then
            print("error state "..i.." not defined")
            os.exit(1)
        end
    end
end

function end_state_machine()
    if(sm_active == false) then
        print("error sm_active is not active operation")
        os.exit(1)
    end
    check_for_undefined_states()
    local sm_name = active_state_machine.name
 
    sm_dictionary[sm_name]=active_state_machine
   
    sm_active = false
    active_state = nil
    
end


---
---
---  generate state machine runtime data structures
---
---

function generate_queue_list(queue_id_name,sm)
   
    local message = string.format("short %s[%s] = {",queue_id_name,#sm.state_order)
    for i,v in pairs(sm.state_order) do
        local queue_id = lookup_named_queue(sm.defined_states[v][2])
        message = message..string.format("%s,",queue_id)
    end
    message = message.."};\n"
    write_output(message)
end

function generate_chain_list(chain_id_name,sm)
    local message = string.format("short %s[%s] = {",chain_id_name,#sm.state_order)
    for i,v in pairs(sm.state_order) do
        local chain_id = column_names[sm.defined_states[v][1]]["number"]
        message = message..string.format("%s,",chain_id)
    end
    message = message.."};\n"
    write_output(message)
end

function generate_detailed_tables(index,sm_name)
    local sm = sm_dictionary[sm_name]
    local queue_id_name = generate_unique_function_name()
    generate_queue_list(queue_id_name,sm)
    local chain_id_name = generate_unique_function_name()
    generate_chain_list(chain_id_name,sm)
    return {queue_id_name,chain_id_name}
end


function generate_state_machine_line(index,sm_name,detailed_tables)
    local sm = sm_dictionary[sm_name]
    
    local queue_id = lookup_named_queue(sm.queue_name)
    local manager_chain_id = column_names[sm.sm_manager]["number"]
    
    local number_of_states = #sm.state_order
    local chain_id_name = detailed_tables[2]
    local queue_ids_name = detailed_tables[1]
    
    local user_data = sm.user_data
    local message = string.format("{%s,%s,%s,%s,%s,%s,%s},\n",index-1,queue_id,manager_chain_id,
                  number_of_states,chain_id_name,queue_ids_name,user_data)
    write_output(message)
end

function generate_populate_sms()
    build_status["number_of_sm"] = #reserved_sms_index
    local detailed_tables = {}
    for i,sm in pairs(reserved_sms_index) do
    
         local temp = generate_detailed_tables(i,sm)
         detailed_tables[i] = temp
    end
    local sm_rom_name = generate_unique_function_name()
    local sm_ram_name = generate_unique_function_name()
    build_status["sm_rom"] = sm_rom_name
    build_status["sm_ram"] = sm_ram_name
    message = string.format("const Sm_control_ROM_CFL_t %s[%s] = {\n",sm_rom_name,#reserved_sms_index)
    write_output(message)
   
    for i,sm in pairs(reserved_sms_index) do
        
         generate_state_machine_line(i,sm,detailed_tables[i])
    end
    message = string.format("}; \n")
    write_output(message)
    message = string.format("Sm_control_RAM_CFL_t %s[%s];\n",sm_ram_name,#reserved_sms_index)
    write_output(message)
   
end

function generate_no_state_machines()
    build_status["number_of_sm"] = #reserved_sms_index

    local sm_rom_name = generate_unique_function_name()
    local sm_ram_name = generate_unique_function_name()
    build_status["sm_rom"] = sm_rom_name
    build_status["sm_ram"] = sm_ram_name
    message = string.format("const Sm_control_ROM_CFL_t %s[0];\n",sm_rom_name)
    write_output(message)
    message = string.format("Sm_control_RAM_CFL_t %s[0];\n",sm_ram_name)
    write_output(message)

end


function  generate_state_machines()
    if #reserved_sms_index == 0 then
        generate_no_state_machines()
    else
        generate_populate_sms()
    end
end

