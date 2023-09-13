---
---
--- one shot lua state machine functions
--- 
---send_event_to_sm 
---


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
    Sm_control_ROM_CFL_t sm_rom = handle->sm_rom[sm_event->sm_id];
    unsigned short sm_queue_id = sm_rom.sm_queue_id;
    Event_data_CFL_t *event_data_to_send = ( Event_data_CFL_t *)sm_event->event_data;
   
    enqueue_event_CFL(input,sm_queue_id, event_data_to_send);
}
]]
Store_one_shot_function('SEND_EVENT_TO_SM', 'send_event_to_sm', send_event_to_sms_body, send_event_to_sms_header)

local send_event_to_sms_format = "const sm_event_CFL_t %s = {%s,{%s,%s,%s }};\n"  

function send_state_machine_event(sm_name,send_event)
   sm_id = find_index(sm_name)
   sm_event =  generate_unique_function_name()
   local message = string.format("const sm_event_CFL_t %s = {%s,&%s};\n",sm_event,sm_id,send_event)
   Store_user_code(message)
   Activate_one_shot_function("SEND_EVENT_TO_SM")
   One_shot("SEND_EVENT_TO_SM",sm_event)
end





local enable_sm_header = [[

typedef struct enable_sm_CFL_t
{
    short sm_number
    unsigned short *sm_indexes
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

local enable_index_format = "const unsigned short  %s[] = {"
local enable_index_value = "%s,"
local enable_index_format_end = "};\n"
local enable_sms_format = "const enable_sm_CFL_t %s = {%s,%s };\n"
function enable_sms(sm_list)
    local sm_index = {}
    for i,sm_name in ipairs(sm_list) do
        local sm_id = find_index(sm_name)
        table.insert(sm_index,sm_id)
    end
    local index_name = generate_unique_function_name()
    local message = string.format(enable_index_format,index_name)
    local messsage = message ..table.concat(sm_index,",")..enable_index_format_end
    write_output(message)
    local sm_event = generate_unique_function_name()
    local message = string.format(enable_sms_format,sm_event,#sm_index,index_name)
    write_output(message)
    Activate_one_shot_function("ENABLE_SM")
     One_shot("ENABLE_SM","&"..sm_event)
   
end   


local disable_sm_header = [[

typedef struct disable_sm_CFL_t
{
    short sm_number
    unsigned short *sm_indexes
} disable_sm_CFL_t;

void disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local disable_sm_body = [[

void disable_sm_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    disable_sm_CFL_t *enable_sm = (disable_sm_CFL_t *)params;
    for(unsigned i = 0; i< enable_sm->sm_number; i++)
    {
        disable_state_machine_CFL(input,enable_sm->sm_indexes[i]);
    }
    
}
]]

Store_one_shot_function('DISABLE_SM', 'disable_sm_CFL', disable_sm_body, disable_sm_header)

local disable_index_format = "const unsigned short  %s[] = {"

local disable_index_format_end = "};\n"
local disable_sms_format = "const disable_sm_CFL_t %s = {%s,%s };\n"
function disable_sms(sm_list)
    local sm_index = {}
    for i,sm_name in ipairs(sm_list) do
        local sm_id = find_index(sm_name)
        table.insert(sm_index,sm_id)
    end
    local index_name = generate_unique_function_name()
    local message = string.format(disable_index_format,index_name)
    local messsage = message ..table.concat(sm_index,",")..disable_index_format_end
    write_output(message)
    local sm_event = generate_unique_function_name()
    local message = string.format(disable_sms_format,sm_event,#sm_index,index_name)
    write_output(message)
    Activate_one_shot_function("DISABLE_SM")
     One_shot("DISABLE_SM","&"..sm_event)
    
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
        local sm_id = find_index(sm_name)
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



local change_sm_state_header = [[

  typedef struct change_sm_state_CFL_t {
    unsigned short sm_id;
    unsigned short new_state;
  } change_sm_state_CFL_t;
  
  void change_sm_state_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local change_sm_state_body = [[

void change_sm_state_CFL(const void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    change_sm_state_CFL_t *change_sm_state = (change_sm_state_CFL_t *)params;
    change_state_machine_CFL(input,change_sm_state->sm_id,change_sm_state->new_state);
}
]]
Store_one_shot_function('CHANGE_STATE_SM', 'change_sm_state_CFL', change_sm_state_body, change_sm_state_header)

function change_state(new_state)
    if(sm_active == fale) then
        print("error sm_active is in not active")
        os.exit(1)
    end
   
    sm_id = active_state_machine["index"] 
    new_state_id = find_state_location(new_state)
    unique_name = generate_unique_function_name()
    local message = string.format("const change_sm_state_CFL_t %s = {%s,%s};\n",unique_name, sm_id,new_state_id)
    Store_user_code(message)
    Activate_one_shot_function('CHANGE_STATE_SM')
    One_shot('CHANGE_STATE_SM',unique_name)
end