
local sm_active_sm = false
local defining_state_machine = nil
local state_machines = {}


function Define_state_machines(sm_list)
  

    for i, sm in ipairs(sm_list) do
      assert( state_machines[sm] ~= nil,"State machine already defined: " .. sm)
      state_machines[sm] = {}
      state_machines[sm].states = {}
      state_machines[sm].defined = false
      
    end
    state_array_name = "def_"..sm_list[1].."_array"
    local message = string.format("static const char *%s[] = { %s };\n",state_array_name,table.concat(sm_list,",\n"))
    local message = string.format("     Define_state_machine_CFL(void *input, %d, %s);\n",#sm_list,state_array_name)
  end

function Define_sm(sm_name, number_of_states,state_names, sm_manager_chain_name, sm_queue_name, initial_state,user_data)    
    assert_inactive_state_machine_generation()                         
    validate_state_machine_name(sm_name)
    verify_column(sm_manager_chain_name)
    -- TBD ------------  verify valid sm_queue_name                     
    local number_of_states = #state_names
    local states_array  = sm_name.."_state_array"
    local message = "static const char *"..states_array.."state[] = {\n"..table.concat(state_names,",\n").."\n};\n"                 
    local message = string.format("    Asm_define_sm(input,%s,%d,%s,%s,%s,%s,%s);\n",sm_name,number_of_states,states_array,
               sm_manager_chain_name,sm_queue_name,initial_state,user_data)
    file:write(message)
    set_active_state_machine_generation()
    set_defining_state_machine(name)
    record_sm_state_names(sm_name,state_names,initial_state)

end                           

function Define_state(state_name,chain_name)
    assert(sm_active_sm == true,"State machine generation is not active")
    verify_new_state(state_name)
    verify_column(chain_name) 
    local message = string.format("    Asm_define_state_CFL(input,%s,%s);\n",state_name,chain_name)
                                
    file:write(message)
end

function End_state_machine()
    assert(sm_active_sm == true,"State machine generation is not active")
    verify_all_states_defined()
    local message = string.format("    Asm_end_state_machine_CFL(input);\n")
    file:write(message)
    sm_active_sm = false
    defining_state_machine = nil
end


function Enable_disable_sms(sm_name,sm_list)
    
    for i, sm in ipairs(sm_list) do
        verify_state_machin_defined(sm)
    end
    local message = string.format("    const char* %s[] = { %s };\n",sm_name,table.concat(sms,",\n"))
    file:write(message)   
    local number = tostring(#sm_list)
    local message = string.format("    Asm_enable_disable_sms_CFL(input,%s,%s);\n",number,sm_name)
    file:write(message)  

end

function Enable_sms(sm_name,sms)
   
    for i, sm in ipairs(sm_list) do
        verify_state_machin_defined(sm)
    end
    local message = string.format("    const char* %s[] = { %s };\n",sm_name,table.concat(sms,",\n"))
    file:write(message)   
    local number = tostring(#sm_list)
    local message = string.format("    Asm_enable_sms_CFL(input,%s,%s);\n",number,sm_name)
    file:write(message)  

end

function Disable_sms(sm_name,sms)
   
    for i, sm in ipairs(sm_list) do
        verify_state_machin_defined(sm)
    end
    local message = string.format("    const char* %s[] = { %s };\n",sm_name,table.concat(sms,",\n"))
    file:write(message)   
    local number = tostring(#sm_list)
    local message = string.format("    Asm_disable_sms_CFL(input,%s,%s);\n",number,sm_name)
    file:write(message)  
end



                         
function Send_state_machine_event(sm_name,event_data)
    verify_state_machin_defined(sm_name)
    
    local message = string.format("    Asm_sms_send_event_CFL(input,%s,%s);\n",sm_name,event_data)
    file:write(message)
end

function Redirect_event(boolean_fn_name,user_data,queue_name,queue_ids,event_name,event_ids)
    -- validate queue_name
    local event_number = #event_ids
    local message = string.format("    const char* %s[] = { %s };\n",queue_name,table.concat(queue_ids,",\n"))
    file:write(message)
    local queue_number = #queue_ids
    message = string.format("    unsigned short %s[] = { %s };\n",event_name,table.concat(event_ids,",\n"))
    file:write(message)
    message = string.format("    Asm_redirect_event_CFL(input,%s,%s,%d,%s,%d,%s);\n",
                                  boolean_fn_name,
                                  user_data,
                                  queue_number,
                                  queue_name,
                                  number_of_events,
                                  event_name)
    file:write(message)
end


function Change_state(sm_name,new_state_name)
    -- verify valid sm_name
    -- verify valid state
    local message = string.format("    Asm_change_state_CFL(input,%s,%s);\n",sm_name,new_state_name)
    file:write(message)
end


function Dump_state_machines_CFL(input)
    local message = string.format("    Asm_dump_state_machines_CFL(input);\n")
    file:write(message)
end



---
--- Helper functions
---
local function verify_column(name)
    assert(table_names[name] ~= nil,"Column not defined: " .. name)
end

function set_active_state_machine_generation()
    sm_active_sm = true
end

function set_inactive_state_machine_generation()
    sm_active_sm = false
end 

function assert_active_state_machine_generation()
    assert(sm_active_sm == true,"State machine generation is not active")
end

function assert_inactive_state_machine_generation()
    assert(sm_active_sm == false,"State machine generation is active")
end

function set_defining_state_machine(name)
    defining_state_machine = name
end

function clear_defining_state_machine()
    defining_state_machine = nil
end

function record_sm_state_names(sm_name,state_names,initial_state)
    
    local temp = {}
    temp.states = {}
    for i, state in ipairs(state_names) do
        temp.states[state] = {}
        temp.states[state]["defined"] = false
    end

    state_machines[sm_name].states = {}
    for i, state in ipairs(state_names) do
        state_machine[sm_name].states[state] = {}
        state_machines[sm_name].states[state]["defined"] = false
       
    end
    assert(state_machine[sm_name].states[initial] == nil,"Initial state not in state machine: " .. initial_state)
    
end

function verify_new_state(state)
    assert(sm_active_sm == true,"State machine generationnot active")
    assert(defining_state_machine ~= nil,"State machine not defined")
    local temp = state_machines[defining_state_machine]
    assert(temp ~= nil,"State machine not defined: " .. defining_state_machine)
    local local_state = temp.states[state]
    assert(local_state ~= nil,"State not specified: " .. state)
    assert(local_state.defined == false,"State machine already defined")
    temp.states[state].defined = true
    
    
end

function verify_all_states_defined()
    assert(sm_active_sm == true,"State machine generationnot active")
    assert(defining_state_machine ~= nil,"State machine not defined")
    local temp = state_machines[defining_state_machine]
    local states = temp.states
    for sm, sm_info in pairs(states) do
        assert(sm_info.defined == true,"State machine not defined: " .. sm)
    end
end

function verify_state_machin_defined(sms)
    assert(state_machines[sms] ~= nil,"State machine not defined: " .. sms)
end