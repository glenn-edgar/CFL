

local sm_debug_header = [[

typedef struct SM_debug_CFL_t{
    unsigned short sm_id;
    unsigned short state_id;
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
   Printf_CFL("State machine %d state %d event index %d %s\n",sm_debug->sm_id,sm_debug->state_id,event_data->event_index,sm_debug->debug_message);
   return HALT_CFL;

}


]]

Store_column_function('SM_DEBUG', 'SM_debug_CFL', sm_debug_body, sm_debug_header)

local sm_debug_format_string = "const SM_debug_CFL_t %s = {%s,%s,%s};\n"

function sm_debug_function(debug_message)
    if(sm_active == false) then
        print("error sm_active is in not active")
        os.exit(1)
    end
    
    local state_name = active_state_machine.current_state
    local state_id = find_state_location(state_name)
    local unique_name = generate_unique_function_name()
    local message = string.format(sm_debug_format_string,unique_name,sm_id,state_id,debug_message)
    Store_user_code(message)
    Activate_column_function("SM_DEBUG")
    local column_fn_name = Get_column_function("SM_DEBUG")
    store_column_element(column_fn_name,boolean_fn,'(void *)&'..unique_name)
end



local redirect_event_header = [[

typedef struct redirect_CFL_t{
  unsigned short sm_id;
  void *user_data;

}redirect_CFL_t;


int redirect_event_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);
]]

local redirect_event_body = [[



int redirect_event_CFL(const void *input,void *fn_aux,void *params, Event_data_CFL_t *event_data){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Bool_function_CFL_t boolean_fn = (Bool_function_CFL_t )fn_aux;
    const redirect_CFL_t *redirect = (const redirect_CFL_t *)params;
    unsigned short sm_id = redirect->sm_id;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        boolean_fn(input, redirect->user_data, event_data);
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        boolean_fn(input,redirect->user_data, event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index <0)
    {
        return CONTINUE_CFL;
    }
    if(boolean_fn(input,redirect->user_data,event_data) == true){
        Sm_control_RAM_CFL_t sm_ram = handle->sm_ram[sm_id];
        Sm_control_ROM_CFL_t sm_rom = handle->sm_rom[sm_id];
        if(sm_ram.active == false){
            return CONTINUE_CFL;
        }
        unsigned short sm_queue_id = sm_rom.queue_ids[sm_ram.current_state];
        enqueue_event_CFL(input,sm_queue_id,event_data);
        return HALT_CFL;
    }

    return CONTINUE_CFL;
}

]]

Store_column_function('REDIRECT_EVENT', 'redirect_event_CFL', redirect_event_body, redirect_event_header)

local redirect_format_string_null = "const redirect_CFL_t %s = {%s,%s};\n"
local redirect_format_string = "const redirect_CFL_t %s = {%s,(void *)&%s};\n"
function redirect_event(boolean_fn_name,user_data)
  
    if(sm_active == false) then
        print("error sm_active is in not active")
        os.exit(1)
    end
   
    boolean_fn = Get_boolean_function(boolean_fn_name)
    Activate_boolean_function(boolean_fn_name)
    local unique_name = generate_unique_function_name()
    local sm_id = active_state_machine["index"] 
    if(user_data ~= 'NULL') then
        local message = string.format(redirect_format_string,unique_name,sm_id,user_data)
        Store_user_code(message)
    else
        local message = string.format(redirect_format_string_null,unique_name,sm_id,user_data)
        Store_user_code(message)
    end
    
    Activate_column_function("REDIRECT_EVENT")
    local column_fn_name = Get_column_function("REDIRECT_EVENT")
    store_column_element(column_fn_name,boolean_fn,'(void *)&'..unique_name)
end


local conditional_state_change_header = [[

typedef struct conditional_state_change_CFL{
    unsigned short sm_id;
    unsigned short new_state_id;
    void *user_data;
  }conditional_state_change_CFL_t;
  
  
  int conditional_state_change_CFL(const void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);
  ]]
  
  local conditional_state_change_body = [[
  
  
  
  int conditional_state_change_CFL(const void *input,void *fn_aux,void *params, Event_data_CFL_t *event_data){
      const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
      Bool_function_CFL_t boolean_fn = (Bool_function_CFL_t )fn_aux;
      const conditional_state_change_CFL_t *state_change = (const conditional_state_change_CFL_t; *)params;
      
      if (event_data->event_index == EVENT_INIT_CFL)
      {
          boolean_fn(input,state_change->user_data, event_data);
          return CONTINUE_CFL;
      }
      if (event_data->event_index == EVENT_TERMINATION_CFL)
      {
          boolean_fn(input,state_change->user_data, event_data);
          return CONTINUE_CFL;
      }
      if(event_data->event_index <0)
      {
          return CONTINUE_CFL;
      }
      if(boolean_fn(input,state_change->user_data,event_data) == true){
          Sm_control_RAM_CFL_t sm_ram = handle->sm_ram[sm_id];
          
          if(sm_ram.active == false){
              return CONTINUE_CFL;
          }
          change_state_machine_CFL(input,state_change->sm_id,state_change->new_state);

          return HALT_CFL;
      }
  
      return CONTINUE_CFL;
  }
]]



Store_column_function('CONDITIONAL_STATE_CHANGE', 'conditional_state_change_CFL', conditional_state_change_body, conditional_state_change_header)
local state_change_string_null = "constconditional_state_change_CFL_t %s = {%s,%s,%s};\n"
local state_change_string = "const conditional_state_change_CFL_t %s = {%s,%s,(void *)&%s};\n"
function conditional_state_change(boolean_fn,user_data,state_name)
 
    if(sm_active == false) then
        print("error sm_active is in not active")
        os.exit(1)
    end
    local state_id = find_state_location(state_name)
    local sm_id = active_state_machine["index"]
    boolean_fn = Get_boolean_function(boolean_fn_name)
    Activate_boolean_function(boolean_fn_name)
    local unique_name = generate_unique_function_name()
    local sm_id = active_state_machine["index"] 
    if(user_data ~= 'NULL') then
        local message = string.format(state_change_string,unique_name,sm_id,state_id,user_data)
        Store_user_code(message)
    else
        local message = string.format(state_change_string_null,unique_name,sm_id,state_id,user_data)
        Store_user_code(message)
    end
    
    Activate_column_function("CONDITIONAL_STATE_CHANGE")
    local column_fn_name = Get_column_function("CONDITIONAL_STATE_CHANGE")
    store_column_element(column_fn_name,boolean_fn,'(void *)&'..unique_name)
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

Store_column_function('STATE_CHANGE', 'state_change_CFL', state_change_body, state_change_header)


function state_change(event_list,state_name)
    if(sm_active == false) then
        print("error sm_active is in not active")
        os.exit(1)
    end
    local state_id = find_state_location(state_name)
    local sm_id = active_state_machine["index"]
    local event_name = generate_unique_function_name()
    local message = string.format("const unsigned short %s[] = {%s};\n",event_name,table.concat(event_list,","))
    Store_user_code(message)
    local unique_name = generate_unique_function_name()
    local message = string.format("const state_change_CFL_t %s = {%s,%s,%s,%s};\n",unique_name,sm_id,state_id,#event_list,event_name)
    Store_user_code(message)
    Activate_column_function("STATE_CHANGE")
    local column_fn_name = Get_column_function("STATE_CHANGE")
    store_column_element(column_fn_name,'NULL','(void *)&'..unique_name)
end


--[[

Store_column_function_CFL(input,"TRANSFER_EVENTS_TO_STATE", transfer_events_to_state);
Store_column_function_CFL(input,"TRANSFER_EVENTS_TO_SM", transfer_events_to_sm);
Store_column_function_CFL(input,"CONDITIONAL_STATE_CHANGE", conditional_state_change);
Store_column_function_CFL(input,"CONDITIONAL_SM_STATUS", conditional_sm_status);
Store_column_function_CFL(input,"TRANSFER_EVENTS_TO_SM_STATE", transfer_events_to_sm_state);
Store_column_function_CFL(input,"SYNC_EVENTS",sync_events );








typedef struct conditional_sm_status_CFL_t{
    short sm_id_transfer;   
    bool  action;
    void *user_data;
}conditional_sm_status_CFL_t;

static int conditional_sm_status(void *input,  void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
    conditional_sm_status_CFL_t *conditional_sm_status = (conditional_sm_status_CFL_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + conditional_sm_status->sm_id_transfer;
    if(event_data->event_index == EVENT_INIT_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }   
    if(bool_fn(input,conditional_sm_status->user_data,event_data) == true){
        sm_control->active = conditional_sm_status->action;
        Reset_named_event_queue_CFL(handle, sm_control->sm_queue_id);
        for(unsigned i= 0; i < sm_control->number_of_states; i++){
            Reset_named_event_queue_CFL(handle, sm_control->queue_ids[i]);
        }
        if(conditional_sm_status->action == true){
            
            Enable_column_CFL(input, sm_control->manager_chain_id);
            Enable_column_CFL(input, sm_control->chain_ids[sm_control->initial_state]);
            sm_control->current_state = sm_control->initial_state;
            sm_control->active = true;
        }else{
            sm_control->active = false;
            Disable_column_CFL(input, sm_control->manager_chain_id);
            for (int i = 0; i < sm_control->number_of_states; i++)
            {
                    Disable_column_CFL(input, sm_control->chain_ids[i]);
            }
        }
        return HALT_CFL;
    }
    return CONTINUE_CFL;
}

typedef struct conditional_state_change_CFL_t{
    short sm_id;
    short new_state_id;
   
    void *user_data;
}conditional_state_change_CFL_t;

static int conditional_state_change(void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
    conditional_state_change_CFL_t *conditional_state_change = (conditional_state_change_CFL_t *)params;
    
    
    if(event_data->event_index == EVENT_INIT_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }
    if(bool_fn(input,conditional_state_change->user_data,event_data) == true){
        Change_state_CFL(input, conditional_state_change->sm_id, conditional_state_change->new_state_id);
        return DISABLE_CFL;
    }
    
    return CONTINUE_CFL;
}

typedef struct redirect_CFL_t
{
    void *user_data;
    unsigned short queue_number;
    unsigned short *queue_ids;
    unsigned short event_number;
    unsigned short *event_ids;
} redirect_CFL_t;

static bool match_event(unsigned short number_of_events, unsigned short *event_ids, unsigned short event_index)
{
    for (unsigned i = 0; i < number_of_events; i++)
    {
        if (event_ids[i] == event_index)
        {
            return true;
        }
    }
    return false;
}
static void send_events_to_queue(void *input,unsigned short queue_numbers, 
     unsigned short *queue_ids, Event_data_CFL_t *event_data)
{
    
    for (unsigned i = 0; i < queue_numbers; i++)
    {
        Send_named_event_CFL(input,queue_ids[i], event_data);
    }
}

static int redirect_event(void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t boolean_fn = (Bool_function_CFL_t )fn_aux;
    redirect_CFL_t *redirect = (redirect_CFL_t *)params;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        boolean_fn(input, redirect->user_data, event_data);
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        boolean_fn(input, redirect->user_data, event_data);
        return CONTINUE_CFL;
    }
    if (match_event(redirect->event_number, redirect->event_ids, event_data->event_index) == true)
    {
        if (boolean_fn(input, redirect->user_data, event_data) == true)
        {
            send_events_to_queue(input, redirect->queue_number, redirect->queue_ids, event_data);
        
            return HALT_CFL;
        }
    }

    return CONTINUE_CFL;
}

typedef struct transfer_to_state_t{
    short sm_id;
    unsigned short number_of_events;
    unsigned short *event_indexes;
    
}transfer_to_state_t;

static int transfer_events_to_state(void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    transfer_to_state_t *transfer_to_state = (transfer_to_state_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + transfer_to_state->sm_id;
    
    if(event_data->event_index == EVENT_INIT_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }
    // state machine is not active
    if(sm_control->active == false){
        //printf("sm %d be active\n",transfer_to_state->sm_id);
        return CONTINUE_CFL;
    }
    if(event_data->event_index <0)
    {
        return CONTINUE_CFL;
    }
    if(sm_control->active == false){
        ASSERT_PRINT_F("sm %d be active\n",transfer_to_state->sm_id);
    }
    unsigned short sm_queue_id = sm_control->queue_ids[sm_control->current_state];
    
    
    // find active state queue
    
    if((transfer_to_state->number_of_events == 0)&&(event_data->event_index >= 0)){
        Send_named_event_CFL(input,sm_queue_id,event_data);
        return HALT_CFL;
    }
    if(match_event(transfer_to_state->number_of_events,transfer_to_state->event_indexes,event_data->event_index) == true){
        Send_named_event_CFL(input,sm_queue_id,event_data);
        return HALT_CFL;            
    }
    // unmatched  event
    return CONTINUE_CFL;


}

typedef struct transfer_to_sm_t{
    short sm_id_transfer;
    unsigned short number_of_events;
    unsigned short *event_indexes;
    
}transfer_to_sm_t;

static int transfer_events_to_sm(void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data){
    (void)aux_fn;
    transfer_to_sm_t *transfer_to_state = (transfer_to_sm_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + transfer_to_state->sm_id_transfer;
    
    if(event_data->event_index == EVENT_INIT_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index <0)
    {
        return CONTINUE_CFL;
    }
    
    if(sm_control->active == false){
        return CONTINUE_CFL;
    }
    // find active state queue
    
    if((transfer_to_state->number_of_events == 0)&&(event_data->event_index >= 0)){
        Send_named_event_CFL(input,sm_control->sm_queue_id,event_data);
        return HALT_CFL;
    }
    if(match_event(transfer_to_state->number_of_events,transfer_to_state->event_indexes,event_data->event_index) == true){
        Send_named_event_CFL(input,sm_control->sm_queue_id,event_data);
        return HALT_CFL;            
    }
    // unmatched  event
    return CONTINUE_CFL;


}

typedef struct transfer_to_sm_state_data_t{
    short sm_id_transfer;
    short state;
    unsigned short number_of_events;
    unsigned short *event_indexes;
    
}transfer_to_sm_state_t;

static int transfer_events_to_sm_state(void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data){
    (void)aux_fn;
    transfer_to_sm_state_t *transfer_to_state = (transfer_to_sm_state_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + transfer_to_state->sm_id_transfer;
    
    if(event_data->event_index == EVENT_INIT_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index <0)
    {
        return CONTINUE_CFL;
    }
    
    if(sm_control->active == false){
        return CONTINUE_CFL;
    }
    if(sm_control->current_state != transfer_to_state->state){
        return CONTINUE_CFL;
    }
    // fine queue for current state
    unsigned short sm_queue_id = sm_control->queue_ids[sm_control->current_state];
    // find active state queue
    
    if((transfer_to_state->number_of_events == 0)&&(event_data->event_index >= 0)){
        Send_named_event_CFL(input,sm_queue_id,event_data);
        return HALT_CFL;
    }
    if(match_event(transfer_to_state->number_of_events,transfer_to_state->event_indexes,event_data->event_index) == true){
        Send_named_event_CFL(input,sm_queue_id,event_data);
        return HALT_CFL;            
    }
    // unmatched  event
    return CONTINUE_CFL;


}

typedef struct syn_events_t{
    unsigned short number_of_events;
    unsigned short *event_indexes;
 }syn_events_t;

static int sync_events(void *input,void *aux_fn,void *params,Event_data_CFL_t *event_data){
    (void)aux_fn;
    syn_events_t *syn_events = (syn_events_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        return CONTINUE_CFL;
    }
    if(event_data->event_index <0)
    {
        return CONTINUE_CFL;
    }
    if(match_event(syn_events->number_of_events,syn_events->event_indexes,event_data->event_index) == true){
        return DISABLE_CFL;            
    }
    // unmatched  event
    return HALT_CFL;
}

]]