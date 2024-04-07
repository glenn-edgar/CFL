
--[[




]]




local column_sm_properties = nil -- insure that the varaiable is local in this context
local active_sm = nil
local active_state = nil
local active_state_index = nil
local waiting_for_state = false


local function initialize_sm(sm_name,list_of_states)
  column_sm_properties["sm_definitions"][sm_name] = {}
  column_sm_properties["sm_definitions"][sm_name]["defined"] = true
  column_sm_properties["sm_definitions"][sm_name]["states"] = list_of_states
  column_sm_properties["sm_definitions"][sm_name]["state_defined"] = {}
  column_sm_properties["sm_definitions"][sm_name]["state_definition"] = {}
  column_sm_properties["sm_definitions"][sm_name]["sm_index"] = column_sm_properties["index"]
  column_sm_properties["index"] = column_sm_properties["index"] + 1
  for i, v in ipairs(list_of_states) do
   
      column_sm_properties["sm_definitions"][sm_name]["state_defined"][v] = false
      column_sm_properties["sm_definitions"][sm_name]["state_definition"][v] = {}
      column_sm_properties["sm_definitions"][sm_name]["state_definition"][v]["name"] = v
      column_sm_properties["sm_definitions"][sm_name]["state_definition"][v]["hash"] = (CFL_hash.fnv_hash(v)&0xffffffff)
      column_sm_properties["sm_definitions"][sm_name]["state_definition"][v]["index"] = i
      column_sm_properties["sm_definitions"][sm_name]["state_definition"][v]["memory_address"] = generate_unique_function_name()
      column_sm_properties["sm_definitions"][sm_name]["state_definition"][v]["defined"] = false

  end
  column_sm_properties["sm_definitions"][sm_name]["memory_address"] = generate_unique_function_name()
  column_sm_properties["sm_definitions"][sm_name]["state_def"] = {}
  column_sm_properties["sm_definitions"][sm_name]["name"] = sm_name
  column_sm_properties["sm_definitions"][sm_name]["hash"] = (CFL_hash.fnv_hash(sm_name)&0xffffffff)
  column_sm_properties["sm_definitions"][sm_name]["first_column_element"] = get_column_element_count()
  column_sm_properties["sm_definitions"][sm_name]["number_of_column_elements"] = 0 -- will be filled in later in the processing
  column_sm_properties["sm_definitions"][sm_name]["number_of_top_elements"] = 0 -- will be filled in later in the processing
  column_sm_properties["sm_definitions"][sm_name]["defined"] = false
  
end


local function function_assemble_sm_array(sm_name,field,address_flag)
  local data_array = {}
  for i, v in ipairs(column_sm_properties["sm_definitions"][sm_name]["states"]) do
    local data = column_sm_properties["sm_definitions"][sm_name]["state_definition"][v][field]
    if address_flag then
      data = "&"..data
    end
    table.insert(data_array, data)
  end
  local message = table.concat(data_array,",") .."};\n"
  Store_user_code(message)
end


local function finalize_sm(sm_name)
  column_sm_properties["sm_definitions"][sm_name]["defined"] = true
  -- verify defined states
  for i,v in pairs(column_sm_properties["sm_definitions"][sm_name]["state_definition"]) do
   
    assert(v['defined'] == true, "State "..i.." is not defined in state machine "..sm_name)
  end
 
  previous_index = -1  --- TBD
  local state_array = generate_unique_function_name()
  local message = string.format("const State_def_structure_CFL_t *%s[] = {",state_array)
  Store_user_code(message)
  function_assemble_sm_array(sm_name,"memory_address",true)
  
 
  message = string.format("const Sm_def_structure_CFL_t %s = {%d,%d,%d,%d,%d,%d ,%s};\n",
                          
                          column_sm_properties["sm_definitions"][sm_name]["memory_address"],


                          column_sm_properties["sm_definitions"][sm_name]["sm_index"],
                           #column_sm_properties["sm_definitions"][sm_name]["states"],
                           CFL_hash.fnv_hash(sm_name),
                          column_sm_properties["sm_definitions"][sm_name]["first_column_element"],
                          get_column_element_count() - column_sm_properties["sm_definitions"][sm_name]["first_column_element"],
                          column_sm_properties["sm_definitions"][sm_name]["number_of_top_elements"],
                          state_array)
  Store_user_code(message)
end 


local function initialize_state(sm_name, state_name)
    active_state = state_name
    
    column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["first_column_element"] = get_column_element_count()
    column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["number_of_column_elements"] = 0
end



local function finalize_state(sm_name, state_name)
  
  column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["defined"] = true
  local last_position = column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["first_column_element"]
  column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["number_of_column_elements"] = get_column_element_count() - last_position 
  local count = get_column_element_count() - last_position
  local hash =  column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["hash"]
  local name = column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["memory_address"]

  local active_state_index = column_sm_properties["sm_definitions"][sm_name]["state_definition"][state_name]["index"]
 
  
  local message = string.format("const State_def_structure_CFL_t %s = {%d,%d,%d,%d};\n",name,active_state_index,hash,last_position,count)
  Store_user_code(message)

     
end

local initialize_sm_header = [[


void Initialize_sm_structure_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local initialize_sm_body = [[

void Initialize_sm_structure_CFL(const void *input, void *params, Event_data_CFL_t *event_data) {
  (void)event_data;
  (void)params;

  Initial_column_element_structures_CFL(input);
  Disable_all_sm_CFL(input);
}

]]

Store_one_shot_function("INITIALIZE_COLUMN_SM","Initialize_sm_structure_CFL",initialize_sm_body,initialize_sm_header)

function MCESM_initialize(list_of_state_machines)
    
    column_sm_properties = {}
    column_sm_properties["list_of_state_machines"] = list_of_state_machines
    -- construct sm dicctionary
    column_sm_properties["sm_list"] = {}
    column_sm_properties["memory_address"] = generate_unique_function_name()
    column_sm_properties["index"] = 0
    column_sm_properties["sm_definitions"] = {}
    One_shot("INITIALIZE_COLUMN_SM",'NULL')
    return column_sm_properties["memory_address"]
end




function MCESM_finalize()
   -- verify defined states
   for i,v in pairs(column_sm_properties["sm_definitions"]) do
   
    assert(v['defined'] == true, "State Machine "..i.." is not defined")
  end
  local data_array = {}
  column_sm_index = generate_unique_function_name()
  local message = string.format("const Sm_def_structure_CFL_t *%s[] = {",column_sm_index)
  Store_user_code(message)
  for i, v in ipairs(column_sm_properties["list_of_state_machines"]) do
    local data = column_sm_properties["sm_definitions"][v]["memory_address"]
    data = "&"..data
    table.insert(data_array, data)
  end
  data_array = table.concat(data_array,",") .."};\n"
  Store_user_code(data_array)

   
  local address = column_sm_properties["memory_address"]

   local bool_sm = generate_unique_function_name()
   local message = string.format("bool %s;\n",bool_sm)
    Store_user_code(message)
    local sm_addr = generate_unique_function_name()
    local message = string.format("uint16_t %s;\n",sm_addr)
    Store_user_code(message)
    local bool_state = generate_unique_function_name()
    local message = string.format("bool %s;\n",bool_state)
    Store_user_code(message)
    local state_addr = generate_unique_function_name()
    local message = string.format("uint16_t %s;\n",state_addr)
    Store_user_code(message)

  local message = string.format("const Column_sm_structure_CFL_t %s = {&%s,&%s,&%s,&%s,%d,%s};\n",address,bool_sm, sm_addr,bool_state, state_addr ,
  #column_sm_properties["list_of_state_machines"],column_sm_index)
  Store_user_code(message)
  
end




function MCESM_start_sm(sm_name,state_list)

    assert(active_sm == nil, "State machine "..sm_name.." definition is already active")
    active_sm = sm_name
    active_state = start_state
    active_state_index = 0
    waiting_for_state = true
    initialize_sm(sm_name, state_list)
  
end

local block_sm_event_header = [[
typedef struct Block_sm_event_CFL_t
{
  const uint32_t sm_hash;
  
} Block_sm_event_CFL_t;

int block_sm_event_function_CFL(const void *input, void *aux, void *params, Event_data_CFL_t *event_data);

]]
local block_sm_event_body = [[
int block_sm_event_function_CFL(const void *input, void *aux, void *params, Event_data_CFL_t *event_data) {
  (void)aux;
  Block_sm_event_CFL_t *sm_data = (Block_sm_event_CFL_t *)params;
  if(event_data->event_index == EVENT_INIT_CFL){
    return CONTINUE_CFL; // do nothing
  }
  if(event_data->event_index == EVENT_TERMINATION_CFL){
    return CONTINUE_CFL; // do nothing
  }
  if( Reference_sm_active_CFL(input, sm_data->sm_hash) == true){
    return HALT_CFL;
  }
  return CONTINUE_CFL;
}

]]

Store_column_function("BLOCK_SM_EVENT","block_sm_event_function_CFL",block_sm_event_body,block_sm_event_header) 
function Block_event(sm_name)
  local sm_hash = CFL_hash.fnv_hash(sm_name)
  local sm_data = generate_unique_function_name()
  local message = string.format("const Block_sm_event_CFL_t %s = {%d};\n",sm_data,sm_hash)
  Store_user_code(message)
  Activate_column_function("BLOCK_SM_EVENT")
  store_column_element('block_sm_event_function_CFL','NULL','(void *)&'..sm_data)
end


function MCESM_end_sm( state_machine_name)

  assert(active_sm ~= nil, "State machine "..state_machine_name.." definition is not active")
  assert(state_machine_name == active_sm, "State machine "..state_machine_name.." mismatch with active state machine "..active_sm)
  finalize_state(active_sm, active_state)
  finalize_sm(active_sm)
  active_sm = nil
  active_state = nil
  --Block_event(state_machine_name)
end



function MCESM_new_state( new_state_name)
    
   
    assert(active_sm ~= nil, "State machine definition is not active")
   
    if waiting_for_state == true then
      waiting_for_state = false
      local last_position = column_sm_properties["sm_definitions"][active_sm]["first_column_element"]
      column_sm_properties["sm_definitions"][active_sm]["number_of_top_elements"] = get_column_element_count() - last_position
     
    else
        assert(active_state ~= nil, "need and MCESM_start_state call before MCESM_new_state call")
        finalize_state(active_sm, active_state)
    end
    assert(column_sm_properties["sm_definitions"][active_sm]["state_defined"][new_state_name] ~= nil, "State "..new_state_name.." is not a valid state")
    assert(column_sm_properties["sm_definitions"][active_sm]["state_defined"][new_state_name] == false, "State "..new_state_name.." is already defined")
    initialize_state(active_sm, new_state_name)
  
end


local enable_sm_header = [[

typedef struct Sm_enable_CFL_t
{
  const uint32_t sm_hash;
  
} Sm_enable_CFL_t;

void Enable_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event);


]]

local enable_sm_body = [[

void Enable_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event) {
  (void)event;
  Sm_enable_CFL_t *sm_data = (Sm_enable_CFL_t *)params;

  Enable_column_element_sm_hash_CFL(input, sm_data->sm_hash);
}

]]

Store_one_shot_function("ENABLE_COLUMN_ELEMENT_SM","Enable_sm_function_CFL",enable_sm_body,enable_sm_header)


function MCESM_enable_sm(sm_name)
   local sm_data = generate_unique_function_name()
    local message = string.format('const Sm_enable_CFL_t %s = {%d};\n',
            sm_data, CFL_hash.fnv_hash(sm_name))
    Store_user_code(message)
    One_shot("ENABLE_COLUMN_ELEMENT_SM",sm_data)
end

local disable_sm_header = [[



void Disable_current_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event);


]]

local disable_sm_body = [[

void Disable_current_sm_function_CFL(const void *input,  void *params, Event_data_CFL_t *event) {
  (void)event;
  (void)params;

  Disable_column_element_sm_current_CFL(input);
}

]]

Store_one_shot_function("DISABLE_CURRENT_COLUMN_ELEMENT_SM","Disable_current_sm_function_CFL",disable_sm_body,disable_sm_header)


function MCESM_disable_current_sm()
   
    One_shot("DISABLE_CURRENT_COLUMN_ELEMENT_SM",'NULL')
end

local mcesm_log_header = [[

typedef struct MCESM_log_CFL_t
{
  const char *entry_message;
  const char *exit_message;
  
} MCESM_log_CFL_t;

void MCESM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event);

]]

local mcesm_log_code = [[

void MCESM_log_function_CFL(const void *input, void *params, Event_data_CFL_t *event) {
  (void)event;
  uint16_t sm_id;
  uint16_t sm_state;

  MCESM_log_CFL_t *sm_data = (MCESM_log_CFL_t *)params;
  if(event->event_index == EVENT_INIT_CFL){
    Get_sm_state_CFL(input,&sm_id,&sm_state );
    Printf_CFL(input, "State Machine %d  current state %d    ",sm_id,sm_state);
    Printf_CFL(input, sm_data->entry_message);
    return;
  }
  if(event->event_index == EVENT_TERMINATION_CFL){
    Get_sm_state_CFL(input,&sm_id,&sm_state );
    Printf_CFL(input, "State Machine %d  current state %d     ",sm_id,sm_state);
    Printf_CFL(input,sm_data->exit_message);
    return;
  }

}

]]

Store_one_shot_function("MCESM_LOG","MCESM_log_function_CFL",mcesm_log_code,mcesm_log_header)



function MCESM_log(entry_message,exit_message)
  local user_data = generate_unique_function_name()
  local message = string.format('const MCESM_log_CFL_t %s = {"%s\\n","%s\\n"};\n',
          user_data, entry_message,exit_message)
  Store_user_code(message)
  One_shot_terminate("MCESM_LOG", user_data)
end


local change_state_header = [[

typedef struct Change_state_structure_CFL_t
{

  const uint32_t state_hash;
  
} Change_state_structure_CFL_t;

int change_state_function_CFL(const void *input, void *aux, void *params, Event_data_CFL_t *event);

]]

local change_state_body = [[

int change_state_function_CFL(const void *input,void *aux,  void *params, Event_data_CFL_t *event_data) {
  (void)aux;
  Change_state_structure_CFL_t *sm_data = (Change_state_structure_CFL_t *)params;
  if(event_data->event_index == EVENT_INIT_CFL){
    return CONTINUE_CFL; // do nothing
  }
  if(event_data->event_index == EVENT_TERMINATION_CFL){
    return CONTINUE_CFL; // do nothing
  }
  
  Change_column_element_state_hash_CFL(input, sm_data->state_hash);
  return HALT_AND_DISABLE_CFL;
}

]]

Store_column_function("CHANGE_SM_STATE","change_state_function_CFL",change_state_body,change_state_header)


function Change_sm_state(new_state)
 

  local sm_data = generate_unique_function_name()

  local message = string.format('const Change_state_structure_CFL_t %s = {%d};\n',
          sm_data, CFL_hash.fnv_hash(new_state))
  Store_user_code(message)
  sm_data = "(void*)&"..sm_data
  Activate_column_function("CHANGE_SM_STATE")
  store_column_element('change_state_function_CFL','NULL',sm_data)
end