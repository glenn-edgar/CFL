
local reserved_sms = {}
local reserved_sms_index = {}
local sm_dictionary = {}
local allocated_column = {}

local function find_sm_index(sm_name)
    for i,v in ipairs(reserved_sms_index) do
        if v == sm_name then
            return i-1,v
        end
    end
    assert(false,"error sm_name "..sm_name.." not found")
end

local function find_state_machine_id_all_columns()
    if active_column == nil then
        assert(false,"error no column being defined")
    end
   
    current_column = get_column_id(active_column["name"])
   
    for i,v in pairs(sm_dictionary) do
        if v.manager_column_id == current_column then
            return v.index,v.name
        end
        for ii,vv in ipairs(v.column_ids) do
            if vv == current_column then
                return v.index,v.name
            end
        end
    end
    assert(false,"error no state machine defined for column "..current_column)
end

local function find_state_location(sm_name,state_name)
    if active_column == nil then
       assert(false,"error no column being defined")
    end

    local sm_data = sm_dictionary[sm_name]
    local state_hash = CFL_hash.fnv_hash(state_name)
    for i,v in ipairs(sm_data.state_hash) do
        if v  == state_hash then
            return i-1
        end
    end
    assert(false,"error state "..state_name.." not found")
end
  
   
local function find_state_machine_id()
    if active_column == nil then
        assert(false,"error no column being defined")
    end
    current_column = get_column_id(active_column["name"])

    for i,v in pairs(sm_dictionary) do
        if v.manager_column_id == current_column then
            return v.index
            
        end
    end
    assert(false,"error no state machine defined for column "..current_column)
end

local function find_current_state(sm_name)
   local sm_data = sm_dictionary[sm_name]
   assert(sm_data ~= nil,"error sm_id "..sm_id.." not found")
   current_column = get_column_id(active_column["name"])
   for i,v in ipairs(sm_data.column_ids) do
       if v == current_column then
           return i
       end
   end
    assert(false,"error current state not found")   
end




function reset_state_machine()  -- called by start build command
    reserved_sms = {}
    reserved_sms_index = {}
    sm_dictionary = {}
    allocated_column = {}
end

function reserve_state_machines(sm_list)
    
    for i,v in ipairs (sm_list) do
        if(reserved_sms[v] ~= nil) then
            assert(false,"error sm_name "..v.." already reserved")
        end
        reserved_sms[v] = false
        reserved_sms_index[#reserved_sms_index+1] = v
    end
end
local function find_sm_index(sm_name)

    return check_if_in_list(reserved_sms_index, sm_name)
end


local function verify_sm_defined()
    for i,v in ipairs(reserved_sms_index) do
        if(reserved_sms[v] == false) then
            assert(false,"error sm_name "..v.." not defined")
       
        end
    end
end

local function validate_column(column)
    if( allocated_column[column] ~= nil) then
        assert(false,"error column "..column.." already used in a state macihne")
    end
    allocated_column[column] = get_column_number(column) -- checks to make sure column is defined
end


local function validate_state_machine(sm_name)
    if(reserved_sms[sm_name] == nil) then
         assert(false,"error sm_name "..sm_name.." not reserved")
    end
    if(reserved_sms[sm_name] == true) then
        assert(false,"error sm_name "..sm_name.." already defined")
    end 
    reserved_sms[sm_name] = true
    
end 

function split_column_state_list(state_column_list)
    local column_list = {}
    local state_list = {}
    for i,v in ipairs(state_column_list) do
        local column = v[2]
        validate_column(column)
        local state = v[1]
        table.insert(column_list,column)
        table.insert(state_list,state)
    end
    return state_list,column_list
end




function define_state_machine(sm_name,manager_column_name,state_column_list, user_data)
    
    validate_list({sm_name},validate_state_machine)
    local column_list = nil
    local state_list = nil
    state_list,column_list = split_column_state_list(state_column_list)
    check_for_duplicates(state_list)
    check_for_duplicates(column_list)

    state_hash = generate_hash_array(state_list,CFL_hash.fnv_hash)
    column_ids = convert_list(column_list,get_column_number)
    
    
    sm_entry = {}
    sm_entry["index"] = find_sm_index(sm_name)
    sm_entry["name"] = sm_name
    sm_entry["hash"] = CFL_hash.fnv_hash(sm_name)
    sm_entry["manager_column_id"] =get_column_number(manager_column_name)

    sm_entry["number_of_states"] = #state_hash
    sm_entry["state_hash"] = state_hash
    sm_entry["column_ids"] = column_ids
    
    sm_entry["user_data"] = user_data
    sm_dictionary[sm_name] = sm_entry
  
end


function generate_column_id_array(column_ids)
    column_id_name = generate_unique_function_name()
    local message = string.format("const uint16_t %s[] = {",column_id_name)
    write_output(message)
    for i,v in ipairs(column_ids) do
        message = string.format("%s",v)
        write_output(message)
        if i < #column_ids then
            write_output(",")
        end
    end
    write_output("};\n")
    return column_id_name
end

function generate_state_hash_array(state_hash)
    state_hash_name = generate_unique_function_name()
    local message = string.format("const uint32_t %s[] = {",state_hash_name)
    write_output(message)
    for i,v in ipairs(state_hash) do
        message = string.format("%s",v)
        write_output(message)
        if i < #column_ids then
            write_output(",")
        end
    end
    write_output("};\n")
    return state_hash_name
end



local function generate_state_machine_line(sm_name,detailed_tables)

    local sm =sm_dictionary[sm_name] 

    local sm_id    = sm.index
    local sm_hash   = sm.hash
    local manager_column_id = sm.manager_column_id
   
    local number_of_states = sm.number_of_states
    local state_hash = sm.state_hash
    local column_ids = sm.column_ids
    local user_data = sm.user_data
    if user_data ~= 'NULL' then
        user_data = string.format("(void *)&%s",user_data)
    end
   
    local message = string.format("{%s,%s,%s,%s,%s,%s,%s},\n",
        sm_id,sm_hash,manager_column_id,number_of_states,
        state_hash,column_ids,user_data)
    write_output(message)
end

local function generate_populate_sms()
    verify_sm_defined()
    build_status["number_of_sm"] = #reserved_sms_index
    local detailed_tables = {}
  
    local sm_rom_name = generate_unique_function_name()
    local sm_ram_name = generate_unique_function_name()
    build_status["sm_rom"] = sm_rom_name
    build_status["sm_ram"] = sm_ram_name

    -- generate state hash and column id arrays
    for sm_name,sm in pairs(sm_dictionary) do
   
        sm.state_hash = generate_state_hash_array(sm.state_hash)
        sm.column_ids = generate_column_id_array(sm.column_ids)
        
    end



    --- generate Rom data structures
    message = string.format("const Sm_control_ROM_CFL_t %s[%s] = {\n",sm_rom_name,#reserved_sms_index)
    write_output(message)
   
    for i,sm in pairs(reserved_sms_index) do
        
         generate_state_machine_line(sm,detailed_tables[i])
    end
    message = string.format("}; \n")

    -- generate Ram data structures
    write_output(message)
    message = string.format("Sm_control_RAM_CFL_t %s[%s];\n",sm_ram_name,#reserved_sms_index)
    write_output(message)
   
end

local function generate_no_state_machines()
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

----
---- One shot functions
----

local enable_sm_header = [[

typedef struct enable_sm_CFL_t
{
    uint16_t sm_number;
    const uint16_t *sm_indexes;
} enable_sm_CFL_t;

void enable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local enable_sm_body = [[

void enable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    enable_sm_CFL_t *enable_sm = (enable_sm_CFL_t *)params;
    for(unsigned i = 0; i< enable_sm->sm_number; i++)
    {
        enable_state_machine_CFL(input,enable_sm->sm_indexes[i]);
    }
    
}
]]

Store_one_shot_function('ENABLE_SM', 'enable_sm_CFL', enable_sm_body, enable_sm_header)


function sms_enable(sm_list)
    local sm_index = {}
    for i,sm_name in ipairs(sm_list) do
        local sm_id = find_sm_index(sm_name)
        table.insert(sm_index,sm_id)
    end
    local index_name = generate_unique_function_name()
    local message = string.format("const uint16_t  %s[] = {",index_name)
    Store_user_code(message)
    for i,v in ipairs(sm_index) do
        message = string.format("%s",v)
        if i < #sm_index then
            message = message..","
        end
        Store_user_code(message)
    end
    message = "};\n"
    Store_user_code(message)
   

    
    local sm_event = generate_unique_function_name()
    local message = string.format( "const enable_sm_CFL_t %s = {%s,%s };\n",sm_event,#sm_list,index_name)

   Store_user_code(message)
    Activate_one_shot_function("ENABLE_SM")
     One_shot("ENABLE_SM",sm_event)
   
end   

local disable_sm_header = [[

typedef struct disable_sm_CFL_t
{
    uint16_t sm_number;
    const uint16_t *sm_indexes;
} disable_sm_CFL_t;

void disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local disable_sm_body = [[

void disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    enable_sm_CFL_t *enable_sm = (enable_sm_CFL_t *)params;
    for(unsigned i = 0; i< enable_sm->sm_number; i++)
    {
        disable_state_machine_CFL(input,enable_sm->sm_indexes[i]);
    }
    
}
]]

Store_one_shot_function('DISABLE_SM', 'disable_sm_CFL', disable_sm_body, disable_sm_header)

function sms_disable(sm_list)
    local sm_index = {}
    for i,sm_name in ipairs(sm_list) do
        local sm_id = find_sm_index(sm_name)
        table.insert(sm_index,sm_id)
    end
    local index_name = generate_unique_function_name()
    local message = string.format("const uint16_t  %s[] = {",index_name)
    Store_user_code(message)
    for i,v in ipairs(sm_index) do
        message = string.format("%s",v)
        if i < #sm_index then
            message = message..","
        end
        Store_user_code(message)
    end
    message = "};\n"
    Store_user_code(message)
   

    
    local sm_event = generate_unique_function_name()
    local message = string.format( "const disable_sm_CFL_t %s = {%s,%s };\n",sm_event,#sm_list,index_name)

   Store_user_code(message)
    Activate_one_shot_function("DISABLE_SM")
     One_shot("DISABLE_SM",sm_event)
   
end   



local change_state_machine_header = [[

typedef struct ASM_change_state_machine_CFL_t
{
    uint32_t sm_index;
    uint32_t state_index;
} ASM_change_state_machine_CFL_t;


void Asm_change_state_machine_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local change_state_machine_body = [[

void Asm_change_state_machine_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    ASM_change_state_machine_CFL_t *change_state_machine = (ASM_change_state_machine_CFL_t  *)params;
    change_state_machine_CFL(input,change_state_machine->sm_index,change_state_machine->state_index);

}
]]

Store_one_shot_function('ASM_CHANGE_STATE_MACHINE', 'Asm_change_state_machine_CFL', change_state_machine_body, change_state_machine_header)

function sms_change_state(state_name)
   sm_id,sm_name = find_state_machine_id_all_columns()

   state_index = find_state_location(sm_name,state_name)
  local state_hash = CFL_hash.fnv_hash(state_name)
  local name = generate_unique_function_name()
  local message = string.format("const ASM_change_state_machine_CFL_t %s = {%d,%d };\n",name,sm_id,state_index)
  Store_user_code(message)
  One_shot("ASM_CHANGE_STATE_MACHINE",name)
end


local enable_disable_sm_header = [[

typedef struct enable_disable_sm_CFL_t
{
    unsigned short sm_number;
    const unsigned short *sm_indexes;
} enable_disable_sm_CFL_t;

void enable_disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local enable_disable_sm_body = [[
    
void enable_disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    
    enable_disable_sm_CFL_t *enable_disable_sm = (enable_disable_sm_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        for(unsigned i = 0; i< enable_disable_sm->sm_number; i++)
        {   
            enable_state_machine_CFL(input,enable_disable_sm->sm_indexes[i]);
        }
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        for(unsigned i = 0; i< enable_disable_sm->sm_number; i++)
        {   
            disable_state_machine_CFL(input,enable_disable_sm->sm_indexes[i]);
        }
    }
}
]]

Store_one_shot_function('ENABLE_DISABLE_SM', 'enable_disable_sm_CFL', enable_disable_sm_body, enable_disable_sm_header)

local enable_disable_index_format = "\nconst unsigned short  %s[] = {"

local enable_disable_index_format_end = "};\n"
local enable_disable_sms_format = "\nenable_disable_sm_CFL_t %s = {%s,%s };\n"
function enable_disable_sms(sm_list)
    local sm_index = {}
    for i,sm_name in ipairs(sm_list) do
        local sm_id = find_sm_index(sm_name)
        table.insert(sm_index,sm_id)
    end
    local index_name = generate_unique_function_name()
    local message = string.format(enable_disable_index_format,index_name)..table.concat(sm_index,",")..enable_disable_index_format_end
    
   
    Store_user_code(message)
    local sm_event = generate_unique_function_name()
    local message = string.format(enable_disable_sms_format,sm_event,#sm_index,index_name)
    
    Store_user_code(message)
    Activate_one_shot_function("ENABLE_DISABLE_SM")
    One_shot_terminate("ENABLE_DISABLE_SM",sm_event)
    
end   



local send_event_to_sms_header = [[

 typedef struct sm_event_CFL_t
{
    short sm_id;
    const Event_data_CFL_t *event_data;
} sm_event_CFL_t;

void send_event_to_sm(const void *input, void *params, Event_data_CFL_t *event_data);

]]


local send_event_to_sms_body = [[
    
void send_event_to_sm(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    sm_event_CFL_t *sm_event = (sm_event_CFL_t *)params;
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Sm_control_ROM_CFL_t *sm_rom_array = (Sm_control_ROM_CFL_t *)handle->sm_rom;
    Sm_control_RAM_CFL_t *sm_ram_array = (Sm_control_RAM_CFL_t *)handle->sm_ram;
    Sm_control_ROM_CFL_t *sm_rom = &sm_rom_array[sm_event->sm_id];
    Sm_control_RAM_CFL_t *sm_ram = &sm_ram_array[sm_event->sm_id];
    if(sm_ram->active == false)
    { 
        return; // sm is not active
    }
    unsigned short sm_queue_id = sm_rom->manager_column_id +1;
    Event_data_CFL_t *event_data_to_send = ( Event_data_CFL_t *)sm_event->event_data;
  
    enqueue_event_CFL(input,sm_queue_id, event_data_to_send);
  
}
]]

Store_one_shot_function('SEND_EVENT_TO_SM', 'send_event_to_sm', send_event_to_sms_body, send_event_to_sms_header)



function send_state_machine_event(sm_name,send_event)
   local sm_id = find_sm_index(sm_name)
   local sm_event =  generate_unique_function_name()
   local message = string.format("const sm_event_CFL_t %s = {%s,&%s};\n",sm_event,sm_id,send_event)
   Store_user_code(message)
   Activate_one_shot_function("SEND_EVENT_TO_SM")
   One_shot("SEND_EVENT_TO_SM",sm_event)
end



local sm_log_header = [[

typedef struct SM_log_CFL_t
{
  const uint16_t sm_id;
  const uint16_t state_id;
  const char *entry_message;
  const char *exit_message;
  
} SM_log_CFL_t;

void SM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event);

]]

local sm_log_code = [[

void SM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event) {
  (void)event;
 
  SM_log_CFL_t *sm_data = (SM_log_CFL_t *)params;
  if(event->event_index == EVENT_INIT_CFL){
   
    Printf_CFL(input, "-------------------- State Machine %d  current state %d .." ,sm_data->sm_id,sm_data->state_id);
    Printf_CFL(input,"%s\n" ,sm_data->entry_message);
    return;
  }
  if(event->event_index == EVENT_TERMINATION_CFL){
   
    Printf_CFL(input, "------------------------ State Machine %d  current state %d  ..",sm_data->sm_id,sm_data->state_id);
    Printf_CFL(input,"%s\n",sm_data->exit_message);
    return;
  }

}

]]

Store_one_shot_function("SM_LOG","SM_log_function_CFL",sm_log_code,sm_log_header)



function SM_log(entry_message,exit_message)
    local sm_id,sm_name = find_state_machine_id_all_columns()
   local state_id = find_current_state(sm_name)
  local unique_address = generate_unique_function_name()
  local message = string.format('const SM_log_CFL_t %s = {%d, %d, "%s","%s"};\n',
          unique_address,sm_id,state_id, entry_message,exit_message)
  Store_user_code(message)
  One_shot_terminate("SM_LOG",unique_address)
end


----------------------
-- Event to State Machine chian
----------------------

local m_feed_state_header = [[
typedef struct SM_feed_state_CFL_t
{
   uint16_t sm_id;
   const char *user_data;

  
}  SM_feed_state_CFL_t;   

int sm_feed_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local sm_feed_state_code = [[

int sm_feed_state_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    const SM_feed_state_CFL_t *sm_feed_state_struct = (const SM_feed_state_CFL_t *)params;

    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;

    Sm_control_ROM_CFL_t *sm_rom_array = (Sm_control_ROM_CFL_t *)handle->sm_rom;
    Sm_control_RAM_CFL_t *sm_ram_array = (Sm_control_RAM_CFL_t *)handle->sm_ram;
    Sm_control_ROM_CFL_t *sm_rom = &sm_rom_array[sm_feed_state_struct->sm_id];
    Sm_control_RAM_CFL_t *sm_ram = &sm_ram_array[sm_feed_state_struct->sm_id];
    if(event_data->event_index == EVENT_INIT_CFL){
        fn(input,(void *)sm_feed_state_struct->user_data,event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        fn(input,(void *)sm_feed_state_struct->user_data,event_data);
        return CONTINUE_CFL;
    }

    if(event_data->event_index < 0){
        return CONTINUE_CFL;
    }
    if(sm_ram->active == false)
    {
       return CONTINUE_CFL;
    }
    bool result = fn(input,(void *)sm_feed_state_struct->user_data,event_data);
    if( result == true){
        chain_single_sweep_CFL( input, sm_rom->column_ids[sm_ram->current_state], event_data);
        return HALT_CFL;
    }
    return CONTINUE_CFL;
        
}


]]


Store_column_function("SM_FEED_STATE", 'sm_feed_state_CFL',sm_feed_state_code, m_feed_state_header )


function State_feed_state( bool_function,user_data)
    ---
    ---  verify manager chain 
    local bool_address = Get_boolean_function(bool_function)

    sm_id = find_state_machine_id()
    local data_structure = generate_unique_function_name()
    if(user_data == nil) then
        user_data = 'NULL'
    else
        user_data = string.format("(void *)&%s",user_data)
    end
    local message = string.format("const SM_feed_state_CFL_t %s = {%d, %s };\n",data_structure,sm_id,user_data)
    Store_user_code(message)
    local column_fn_name = Get_column_function("SM_FEED_STATE")
    store_column_element(column_fn_name, bool_address,'(void *)&'..data_structure)
end


local state_change_header = [[

typedef struct state_change_CFL_t{
    unsigned short sm_id;
    unsigned short new_state_id;
    unsigned short event_number;
    const unsigned short *event_indexes;
}state_change_CFL_t;

int state_change_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);

]]

local state_change_body = [[

int state_change_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data){
    (void)fn_aux;
    const state_change_CFL_t *state_change = (const state_change_CFL_t *)params;
   if(event_data->event_index < 0){
       return CONTINUE_CFL;
   }
   for(unsigned i = 0 ;i< state_change->event_number;i++){
      
       if(event_data->event_index == state_change->event_indexes[i]){
           
           change_state_machine_CFL(input,state_change->sm_id,state_change->new_state_id);
           return HALT_CFL;
       }
   }
   return CONTINUE_CFL;
}
   

]]

Store_column_function('STATE_EVENT_CHANGE', 'state_change_CFL', state_change_body, state_change_header)


function State_event_change(event_list,state_name)
    if(sm_active == false) then
        assert(false,"error sm_active is in not active")
       
    end
    local sm_id = find_state_machine_id()
    local state_id  = find_state_location(sm_name,state_name)
 
    local event_name = generate_unique_function_name()
    local message = string.format("const unsigned short %s[] = {%s};\n",event_name,table.concat(event_list,","))
    Store_user_code(message)
    local unique_name = generate_unique_function_name()
    local message = string.format("const state_change_CFL_t %s = {%s,%s,%s,%s};\n",unique_name,sm_id,state_id,#event_list,event_name)
    Store_user_code(message)
    local column_fn_name = Get_column_function("STATE_EVENT_CHANGE")
    store_column_element(column_fn_name,'NULL','(void *)&'..unique_name)
end



local sm_debug_header = [[

typedef struct SM_debug_CFL_t{
    const uint16_t sm_id;
    const uint16_t state_id;
    const char *debug_message;
}SM_debug_CFL_t;

int  SM_debug_CFL(const void *input, void *fn_aux,void *params, Event_data_CFL_t *event_data);

]]

local sm_debug_body = [[

int SM_debug_CFL(const void *input, void *fn_aux,void *params,Event_data_CFL_t *event_data){
   (void)fn_aux;
   (void)input;
   SM_debug_CFL_t *sm_debug = (SM_debug_CFL_t *)params;
   if(event_data->event_index < 0){
    return CONTINUE_CFL;
   }



   Printf_CFL(input,"State machine %d state %d event index %d %s\n",sm_debug->sm_id,sm_debug->state_id,event_data->event_index,sm_debug->debug_message);
   return CONTINUE_CFL;

}


]]

Store_column_function('SM_DEBUG', 'SM_debug_CFL', sm_debug_body, sm_debug_header)

local sm_debug_format_string = "const SM_debug_CFL_t %s = {%s,%s,%s};\n"

function sm_debug_function(debug_message)
    
    assert(active_column ~= nil,"error column is not being built")
    local sm_id,sm_name = find_state_machine_id_all_columns()
    local state_id = find_current_state(sm_name)
    local unique_name = generate_unique_function_name()
    local message = string.format(sm_debug_format_string,unique_name,sm_id,state_id,debug_message)
    Store_user_code(message)

    local column_fn_name = Get_column_function("SM_DEBUG")
    store_column_element(column_fn_name,'NULL','(void *)&'..unique_name)
end


local sm_case_change_header = [[

typedef struct SM_case_change_CFL_t{
    const uint16_t sm_id;
    const void *user_data;
}SM_case_change_CFL_t;

int SM_case_change_CFL(const void *input, void *fn_aux,void *params, Event_data_CFL_t *event_data);

]]

local sm_case_change_body = [[

int SM_case_change_CFL(const void *input, void *fn_aux,void *params,Event_data_CFL_t *event_data){

   State_function_CFL_t case_change = (State_function_CFL_t)fn_aux;
   SM_case_change_CFL_t *sm_case_change = (SM_case_change_CFL_t *)params;
   if(event_data->event_index < 0){
    return CONTINUE_CFL;
   }
    bool continue_flag = false;
   int new_state = case_change(input,(void *)sm_case_change->user_data,event_data,&continue_flag);
   if(new_state >= 0 ){
       change_state_machine_CFL(input,sm_case_change->sm_id,new_state);
       return HALT_CFL;
   }
   if(continue_flag == true){
       return CONTINUE_CFL;
   }
   return HALT_CFL;

}

]]
Store_column_function('SM_CASE_CHANGE', 'SM_case_change_CFL', sm_case_change_body, sm_case_change_header)   

function Sm_case_change_function(case_function,user_data)

    assert(active_column ~= nil,"error column is not being built")
    local sm_id,sm_name = find_state_machine_id_all_columns()
    unique_name = generate_unique_function_name()
    local message = string.format("SM_case_change_CFL_t %s = {%d,(void *)&%s};\n",unique_name,sm_id,user_data)
    Store_user_code(message)
    local case_address = Get_state_function(case_function)
    local column_fn_name = Get_column_function('SM_CASE_CHANGE')
    store_column_element(column_fn_name,case_address,'(void *)&'..unique_name)
end


local sm_sync_events_header = [[


typedef struct sm_sync_events_t{
  unsigned short sm_queue_id;
  int sync_event_index;

}sm_sync_events_t;

int sm_sync_events_CFL(const void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data);

]]

local sm_sync_events_body = [[

int sm_sync_events_CFL(const void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data){
    (void)aux_fn;
   
    sm_sync_events_t *sync_events = (sm_sync_events_t *)params;
    
    if(event_data->event_index == EVENT_INIT_CFL){
        
       
        Event_data_CFL_t   sync_event_data = {sync_events->sync_event_index,false,NULL};
        enqueue_event_CFL(input,sync_events->sm_queue_id,&sync_event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index >0)
    {
       
        if(event_data->event_index == sync_events->sync_event_index){
            return HALT_AND_DISABLE_CFL;
        }
    }

    return HALT_CFL;
}

]]

Store_column_function('SM_SYNC_EVENTS', 'sm_sync_events_CFL', sm_sync_events_body, sm_sync_events_header)

function SM_sync_events(event_index)
    assert(active_column ~= nil,"error column is not being built")
    local sm_id,sm_name = find_state_machine_id_all_columns()
    queue_id = sm_dictionary[sm_name].manager_column_id + 1
    local unique_name = generate_unique_function_name()
    local message = string.format("const sm_sync_events_t %s = {%d,%d};\n",unique_name,queue_id,event_index)
    Store_user_code(message)
   
    local column_fn_name = Get_column_function("SM_SYNC_EVENTS")
    store_column_element(column_fn_name,'NULL','(void *)&'..unique_name)
end