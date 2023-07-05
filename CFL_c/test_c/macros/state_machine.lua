local sm_active_sm = false
local defining_state_machine = nil
local state_machines = {}
local columns = {}

function reset_sm_environment()
    sm_active_sm = false
    defining_state_machine = nil
    state_machines = {}
    columns = {}
end

function verify_state_machine_defined(sms)
    if state_machines[sms] == nil then
        print("State machine not defined: " .. sms)
        os.exit(1)
    end
end

function Define_state_machines(sm_array, sm_list)

    local temp_sm_quote = {}
    for i, sm in ipairs(sm_list) do

        if state_machines[sm] ~= nil then
            print("Error: state machine already defined: ", sm)
            assert(false)
        end

        temp_sm_quote[i] = quote_string(sm)
        state_machines[sm] = {}
        state_machines[sm]["states"] = {}
        state_machines[sm]["defined"] = false

    end

    local message = string.format("    static const char *%s[] = { %s };\n",
                                  sm_array, table.concat(temp_sm_quote, ","))
    file:write(message)
    local message = string.format(
                        "    Define_state_machines_CFL(input, %d, %s);\n",
                        #sm_list, sm_array)
    file:write(message)

end

function End_state_machine()
    assert(sm_active_sm == true, "State machine generation is not active")
    verify_all_states_defined()
    local message = string.format("    Asm_end_state_machine_CFL(input);\n")
    file:write(message)
    sm_active_sm = false
    defining_state_machine = nil
end



function Enable_disable_sms(sm_name, sms_list)
    q_sms_list = {}
    
    for i, sm in ipairs(sms_list) do

        q_sms_list[i] = quote_string(sm)
        verify_state_machine_defined(sm)
    end
    
    local message = string.format("    const char* %s[] = { %s };\n", sm_name,
                                  table.concat(q_sms_list, ","))
    file:write(message)

    local number = tostring(#sms_list)
    local message = string.format("    Asm_enable_disable_sms_CFL(input,%s,%s);\n",
                                  number, sm_name)
    file:write(message)

end

function Enable_sms_list(sm_name, sms_list)
    q_sms_list = {}

    for i, sm in ipairs(sms_list) do

        q_sms_list[i] = quote_string(sm)
        verify_state_machine_defined(sm)
    end

    local message = string.format("    const char* %s[] = { %s };\n", sm_name,
                                  table.concat(q_sms_list, ","))
    file:write(message)

    local number = tostring(#sms_list)
    local message = string.format("    Asm_enable_sms_CFL(input,%s,%s);\n",
                                  number, sm_name)
    file:write(message)

end

function Disable_sms_list(sm_name, sms_list)
    q_sms_list = {}

    for i, sm in ipairs(sms_list) do
        q_sms_list[i] = quote_string(sm)
        verify_state_machine_defined(sm)
    end

    local message = string.format("    const char* %s[] = { %s };\n", sm_name,
                                  table.concat(q_sms_list, ",\n"))
    file:write(message)

    local number = tostring(#sms_list)
    local message = string.format("    Asm_disable_sms_CFL(input,%s,%s);\n",
                                  number, sm_name)
    file:write(message)

end

function Send_state_machine_event(sm_name, event_data)
    verify_state_machine_defined(sm_name)

    local message = string.format("    Asm_sms_send_event_CFL(input,%s,%s);\n",
                                  quote_string(sm_name), event_data)
    file:write(message)
end

function Redirect_event(boolean_fn_name, user_data, queue_name, queue_ids,
                        event_name, event_ids)
    -- validate queue_name
    local event_number = #event_ids
    local message = string.format("    const char* %s[] = { %s };\n",
                                  queue_name, table.concat(queue_ids, ",\n"))
    file:write(message)
    local queue_number = #queue_ids
    message = string.format("    unsigned short %s[] = { %s };\n", event_name,
                            table.concat(event_ids, ",\n"))
    file:write(message)
    message = string.format(
                  "    Asm_redirect_event_CFL(input,%s,%s,%d,%s,%d,%s);\n",
                  boolean_fn_name, user_data, queue_number, queue_name,
                  number_of_events, event_name)
    file:write(message)
end

function Change_state(sm_name, new_state_name)
    -- verify valid sm_name
    -- verify valid state
    local message = string.format("    Asm_change_state_CFL(input,%s,%s);\n",
                                  quote_string(sm_name),
                                  quote_string(new_state_name))
    file:write(message)
end

function Dump_state_machines()
    local message = string.format("    Asm_dump_state_machines_CFL(input);\n")
    file:write(message)
end

function Set_sm_user_data(sm_name, user_data)

    local message = string.format(
                        "    Asm_sms_set_user_data_CFL(input,%s,%s);\n",
                        quote_string(sm_name), user_data)
    file:write(message)
end

---
--- Helper functions
---
local function validate_state_machine_name(sm_name)

    if state_machines[sm_name] == nil then
        print("State machine name is " .. sm_name .. " is not valid")
        os.exit(1)
    end

end

local function verify_column(name)
    if table_names[name] == nil then
        print("Column not defined: " .. name)
        os.exit(1)
    end

end

function set_active_state_machine_generation() sm_active_sm = true end

function set_inactive_state_machine_generation() sm_active_sm = false end

function assert_active_state_machine_generation()
    if sm_active_sm == false then
        print("State machine generation is not active")
        os.exit(1)
    end

end

function assert_inactive_state_machine_generation()
    if sm_active_sm == true then
        print("State machine generation is active")
        os.exit(1)
    end
end

function set_defining_state_machine(name) defining_state_machine = name end

function clear_defining_state_machine() defining_state_machine = nil end

function record_sm_state_names(sm_name, state_names, initial_state)

    local temp = {}
    temp.states = {}
    for i, state in ipairs(state_names) do
        temp.states[state] = {}
        temp.states[state]["defined"] = false
    end
    state_machines[sm_name] = temp

    if state_machines[sm_name].states[initial_state] == nil then
        print("Initial state not in state machine: " .. initial_state)

        os.exit(1)
    end

end

function verify_new_state(state)
    if (sm_active_sm == false) then
        print("State machine generation is not active")
        os.exit(1)
    end
    if (defining_state_machine == nil) then
        print("State machine not defined")
        os.exit(1)
    end

    local temp = state_machines[defining_state_machine]
    if (temp == nil) then
        print("State machine not defined: " .. defining_state_machine)
        os.exit(1)
    end

    local local_state = temp.states[state]
    if (local_state == nil) then
        print("State not in state machine: " .. state)
        os.exit(1)
    end
    if (local_state.defined == true) then
        print("State already defined: " .. state)
        os.exit(1)
    end

    temp.states[state].defined = true
    state_machines[defining_state_machine] = temp

end

function verify_all_states_defined()
    assert(sm_active_sm == true, "State machine generationnot active")
    assert(defining_state_machine ~= nil, "State machine not defined")
    local temp = state_machines[defining_state_machine]
    local states = temp.states
    for sm, sm_info in pairs(states) do
        assert(sm_info.defined == true, "State machine not defined: " .. sm)
    end
end

function Define_sm(sm_name, state_names, sm_manager_chain_name, sm_queue_name,
                   initial_state, user_data)

    assert_inactive_state_machine_generation()

    validate_state_machine_name(sm_name)

    -- TBD ------------  verify valid sm_queue_name                     
    local number_of_states = #state_names
    local states_array = sm_name .. "_state_array"
    local temp_names = {}
    for i, state in ipairs(state_names) do
        temp_names[i] = quote_string(state)
    end
    local message = '    static const char *' .. states_array .. '[] = {' ..
                        table.concat(temp_names, ",") .. "};\n"
    file:write(message)

    local message = string.format(
                        "    Asm_define_state_machine_CFL(input,%s,%d,%s,%s,%s,%s,%s);\n",
                        quote_string(sm_name), #state_names, states_array,
                        quote_string(sm_manager_chain_name),
                        quote_string(sm_queue_name),
                        quote_string(initial_state), user_data)
    file:write(message)
    set_active_state_machine_generation()

    set_defining_state_machine(sm_name)

    record_sm_state_names(sm_name, state_names, initial_state)

end

function Define_state(state_name, chain_name)

    if (sm_active_sm == false) then
        print("State machine generation is not active")
        os.exit(1)
    end
    verify_new_state(state_name)
    -- verify_column(chain_name) 
    local message = string.format("    Asm_define_state_CFL(input,%s,%s);\n",
                                  quote_string(state_name),
                                  quote_string(chain_name))

    file:write(message)
end
