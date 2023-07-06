#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_debug.h"
#include "CFL_element_storeage.h"
#include "CFL_state_machine.h"

#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "Cfl_element_storeage.h"
#include "CFL_state_machine.h"

static bool match_event(unsigned short number_of_events, unsigned short *event_ids, unsigned short event_index);

typedef struct Sm_control_CFL_t
{
    Hash_cell_control_CFL_t *state_names;
    bool active;
    bool defined;
    unsigned short sm_id;
    unsigned short sm_queue_id;
    unsigned short manager_chain_id;
    unsigned short current_state;
    unsigned short initial_state;
    unsigned short number_of_states;
    short *chain_ids; // each state is a chain
    short *queue_ids;
    void *user_data;
} Sm_control_CFL_t;

typedef struct Sm_dictionary_CFL_t
{
    Hash_cell_control_CFL_t *sm_names;
    unsigned short current_sm_number;
    unsigned short max_sms_number;
    Sm_control_CFL_t *sm_control;
} Sm_dictionary_CFL_t;

static void enable_disable_sms_CFL(void *input, void *params, Event_data_CFL_t *event_data);
static void change_state(void *input, void *params, Event_data_CFL_t *event_data);
static void dump_sm(void *input, void *params, Event_data_CFL_t *event_data);
static void process_set_sms_user_data(void *input, void *params, Event_data_CFL_t *event_data);
static void send_event_to_sm(void *input, void *params, Event_data_CFL_t *event_data);


unsigned sm_reserve_one_shot_functions_CFL(void)
{
    return 5;
}

void sm_register_one_shot_functions_CFL(void *input)
{
    Store_one_shot_function_CFL(input, "ENABLE_DISABLE_SM", enable_disable_sms_CFL);
    Store_one_shot_function_CFL(input, "CHANGE_STATE", change_state);
    Store_one_shot_function_CFL(input, "DUMP_STATE_MACHINES", dump_sm);
    Store_one_shot_function_CFL(input, "SMS_CHANGE_USER_DATA", process_set_sms_user_data);
    Store_one_shot_function_CFL(input, "SEND_EVENT_TO_SM", send_event_to_sm);
}


static int redirect_event(void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);
static int transfer_events_to_state(void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data);
static int transfer_events_to_sm(void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data);
static int conditional_state_change(void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data);
static int conditional_sm_status(void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data);

unsigned sm_reserve_column_functions_CFL(void)
{
    return 5;
}

void sms_register_column_functions_CFL(void *input)
{

    Store_column_function_CFL(input,"REDIRECT_EVENT",redirect_event);
    Store_column_function_CFL(input,"TRANSFER_EVENTS_TO_STATE", transfer_events_to_state);
    Store_column_function_CFL(input,"TRANSFER_EVENTS_TO_SM", transfer_events_to_sm);
    Store_column_function_CFL(input,"CONDITIONAL_STATE_CHANGE", conditional_state_change);
    Store_column_function_CFL(input,"CONDITIONAL_SM_STATUS", conditional_sm_status);

}

void Constuct_sm_system_CFL(void *input, Handle_config_CFL_t *config)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    unsigned sms_number = config->number_of_state_machines;
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_dictionary_CFL_t));
    handle->sm_dictionary = sm_dictionary;

    sm_dictionary->max_sms_number = sms_number;
    sm_dictionary->current_sm_number = 0;
    if (config->number_of_state_machines == 0)
    {
        sm_dictionary->sm_control = NULL;
        sm_dictionary->sm_names = NULL;
        return;
    }
    sm_dictionary->sm_names = contruct_hash_cell_control_CFL(handle, sms_number);
    sm_dictionary->sm_control = (Sm_control_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_control_CFL_t) * sms_number);
}

void  Define_state_machines_CFL(void *input, unsigned short number_of_states, const char **state_names)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    if (number_of_states >= (sm_dict->max_sms_number - sm_dict->current_sm_number))
    {
        ASSERT_PRINT_F("number_of_states %d >= (sm_dict->max_sms_number %d - sm_dict->current_sm_number %d)\n",
                       number_of_states, sm_dict->max_sms_number, sm_dict->current_sm_number);
    }

    Store_Names_CFL(sm_dict->sm_names, number_of_states, state_names);
    for (unsigned i = sm_dict->current_sm_number; i < sm_dict->current_sm_number + number_of_states; i++)
    {
        sm_dict->sm_control[i].defined = false;
    }
    sm_dict->current_sm_number += number_of_states;
}

void  Asm_define_state_machine_CFL(void *input,
                   const char *sm_name,
                   unsigned char number_of_states,
                   const char **state_names,
                   const char *sm_manager_chain_name,
                   const char *sm_queue_name,
                   const char *initial_state,
                   void *user_data)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    if (handle->sm_assembly == true)
    {
        ASSERT_PRINT("error sm_assembly is in current operation\n", "");
    }
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    // find sm_id from name table
    short sm_id = Find_Name_CFL(sm_dict->sm_names, sm_name);
    if (sm_id < 0)
    {
        ASSERT_PRINT_F("sm_name %s not found\n", sm_name);
    }
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;
    sm_control->state_names = contruct_hash_cell_control_CFL(handle, number_of_states);
    Store_Names_CFL(sm_control->state_names, number_of_states, state_names);
    sm_control->defined = true;
    sm_control->active = false;
    sm_control->sm_id = sm_id;
    sm_control->manager_chain_id = Find_column_index_CFL(handle, sm_manager_chain_name);
    sm_control->number_of_states = number_of_states;
    sm_control->chain_ids = (short *)Allocate_once_malloc_CFL(handle, sizeof(unsigned short) * number_of_states);
    sm_control->queue_ids = (short *)Allocate_once_malloc_CFL(handle, sizeof(unsigned short) * number_of_states);
    for (int i = 0; i < number_of_states; i++)
    {
        sm_control->queue_ids[i] = -1;
        sm_control->chain_ids[i] = -1;
    }
    sm_control->user_data = user_data;
    sm_control->sm_queue_id = Get_named_event_queue_index_CFL(handle, sm_queue_name);

    sm_control->initial_state = Find_Name_CFL(sm_control->state_names, initial_state);
    handle->sm_assembly = true;
    handle->sm_index = sm_id;
}
  
void Asm_define_state_CFL(void *input,
                          const char *state_name,
                          const char *chain_name,
                          const char *queue_name)   
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    if (handle->sm_assembly == false)
    {
        ASSERT_PRINT("sm_assembly not started\n", "");
    }
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + handle->sm_index;
    short state_id = Find_Name_CFL(sm_control->state_names, state_name);
    if (state_id < 0)
    {
        ASSERT_PRINT_F("state_name %s not found\n", state_name);
    }
    sm_control->chain_ids[state_id] = Find_column_index_CFL(handle, chain_name);
    sm_control->queue_ids[state_id] = Get_named_event_queue_index_CFL(handle, queue_name);
}

void Asm_end_state_machine_CFL(void *input)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    if (handle->sm_assembly == false)
    {
        ASSERT_PRINT("sm_assembly not started\n", "");
    }
    handle->sm_assembly = false;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + handle->sm_index;
    for (int i = 0; i < sm_control->number_of_states; i++)
    {
        if (sm_control->chain_ids[i] == -1)
        {
            ASSERT_PRINT_F("state %d not defined\n", i);
        }
    }
}

void Verify_all_sm_are_defined(void *input)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    for (unsigned i = 0; i < sm_dict->current_sm_number; i++)
    {
        if (sm_dict->sm_control[i].defined == false)
        {
            ASSERT_PRINT_F("sm %d not defined\n", i);
        }
    }
}

typedef struct enable_state_CFL_t
{
    bool state;
    unsigned short number_of_sms;
    unsigned short *sms;
    
} enable_state_CFL_t;

void Asm_enable_disable_sms_CFL(void *input,unsigned short number, const char **sm_name)
{

    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    enable_state_CFL_t *enable_state = (enable_state_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(enable_state_CFL_t));
    enable_state->number_of_sms = number;
    enable_state->sms = (unsigned short *)Allocate_once_malloc_CFL(handle, sizeof(unsigned short) * number);
    enable_state->state = true;
    for (int i = 0; i < number; i++)
    {
        short sm_id = Find_Name_CFL(sm_dict->sm_names,*sm_name++);
        if (sm_id < 0)
        {
          ASSERT_PRINT_F("sm_name %s not found\n", sm_name);
        }
        enable_state->sms[i] = sm_id;
    }
    Asm_one_shot_terminate_CFL(input, "ENABLE_DISABLE_SM", enable_state);
}

void Asm_enable_sms_CFL(void *input,unsigned short number, const char **sm_names)
{

    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    enable_state_CFL_t *enable_state = (enable_state_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(enable_state_CFL_t));
    enable_state->number_of_sms = number;
    enable_state->sms = (unsigned short *)Allocate_once_malloc_CFL(handle, sizeof(unsigned short) * number);
    enable_state->state = true;
    for (int i = 0; i < number; i++)
    {
        short sm_id = Find_Name_CFL(sm_dict->sm_names,*sm_names);
        if (sm_id < 0)
        {
          ASSERT_PRINT_F("sm_name %s not found\n", *sm_names);
        }
        enable_state->sms[i] = sm_id;
        sm_names++;
    }
    Asm_one_shot_CFL(input, "ENABLE_DISABLE_SM", enable_state);
}
void Asm_disable_sms_CFL(void *input,unsigned short number,const char **sm_names)
{

    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    enable_state_CFL_t *enable_state = (enable_state_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(enable_state_CFL_t));
    enable_state->number_of_sms = number;
    enable_state->sms = (unsigned short *)Allocate_once_malloc_CFL(handle, sizeof(unsigned short) * number);
    enable_state->state = false;
    for (int i = 0; i < number; i++)
    {
        short sm_id = Find_Name_CFL(sm_dict->sm_names,*sm_names);
        if (sm_id < 0)
        {
          ASSERT_PRINT_F("sm_name %s not found\n", *sm_names);
        }
        enable_state->sms[i] = sm_id;
        sm_names++;
    }
    Asm_one_shot_CFL(input, "ENABLE_DISABLE_SM", enable_state);
}

static void enable_disable_sms_CFL(void *input, void *params, Event_data_CFL_t *event_data)
{
    enable_state_CFL_t *enable_state = (enable_state_CFL_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    if(event_data->event_index == EVENT_INIT_CFL){
         for(unsigned i = 0; i < enable_state->number_of_sms; i++){
            Sm_control_CFL_t *sm_control = sm_dict->sm_control + enable_state->sms[i];
            sm_control->active = true;
            Reset_named_event_queue_CFL(handle, sm_control->sm_queue_id);
            for(unsigned i= 0; i < sm_control->number_of_states; i++){
               Reset_named_event_queue_CFL(handle, sm_control->queue_ids[i]);
            }
            Enable_column_CFL(input, sm_control->manager_chain_id);
            Enable_column_CFL(input, sm_control->chain_ids[sm_control->initial_state]);
            sm_control->current_state = sm_control->initial_state;
            
        }
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        for(unsigned i = 0; i < enable_state->number_of_sms; i++){
            Sm_control_CFL_t *sm_control = sm_dict->sm_control + enable_state->sms[i];
            sm_control->active = false;
            Disable_column_CFL(input, sm_control->manager_chain_id);
            for (int i = 0; i < sm_control->number_of_states; i++)
            {
                    Disable_column_CFL(input, sm_control->chain_ids[i]);
            }
            
        }
    }
    
    
}

typedef struct sm_event_CFL_t
{
    short queue_id;
    Event_data_CFL_t sent_event;
} sm_event_CFL_t;

void Asm_sms_send_event_CFL(void *input,const  char *sm_name, Event_data_CFL_t *event_data)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    sm_event_CFL_t *sm_event = (sm_event_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(sm_event_CFL_t));
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_id = Find_Name_CFL(sm_dict->sm_names, sm_name);
    if (sm_id < 0)
    {
        ASSERT_PRINT_F("sm_name %s not found\n", sm_name);
    }
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;
    sm_event->queue_id = sm_control->sm_queue_id;
    sm_event->sent_event = *event_data;
    Asm_one_shot_CFL(input, "SEND_EVENT_TO_SM", sm_event);
   
}

static void send_event_to_sm(void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    sm_event_CFL_t *sm_event = (sm_event_CFL_t *)params;
    Send_named_event_CFL(input, sm_event->queue_id, &sm_event->sent_event);
}
typedef struct change_state_CFL_t
{
    short sm_id;
    short new_state_id;
} change_state_CFL_t;

void Asm_change_state_CFL(void *input, const char *sm_name, const char *new_state_name)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_id = Find_Name_CFL(sm_dict->sm_names, sm_name);
    if (sm_id < 0)
    {
        ASSERT_PRINT_F("sm_name %s not found\n", sm_name);
    }
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;
    short new_state_id = Find_Name_CFL(sm_control->state_names, new_state_name);
    if (new_state_id < 0)
    {
        ASSERT_PRINT_F("new_state_name %s not found\n", new_state_name);
    }
    change_state_CFL_t *change_state = (change_state_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(change_state_CFL_t));
    change_state->sm_id = sm_id;
    change_state->new_state_id = new_state_id;
    Asm_one_shot_CFL(input, "CHANGE_STATE", change_state);
}

static void change_state(void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)event_data;
    change_state_CFL_t *change_state = (change_state_CFL_t *)params;
    Change_state_CFL(input, change_state->sm_id, change_state->new_state_id);
}

typedef struct transfer_to_state_t{
    short sm_id;
    unsigned short number_of_events;
    unsigned short *event_indexes;
    
}transfer_to_state_t;



void Asm_transfer_events_to_state_CFL(void *input,const char *state_machine_name,unsigned short number_of_events,short *event_indexes){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_id = Find_Name_CFL(sm_dict->sm_names, state_machine_name);
    if (sm_id < 0)
    {
        ASSERT_PRINT_F("sm_name %s not found\n", state_machine_name);
    }
    transfer_to_state_t *transfer_to_state = (transfer_to_state_t *)Allocate_once_malloc_CFL(input, sizeof(transfer_to_state_t));
    transfer_to_state->sm_id = sm_id;
    transfer_to_state->number_of_events = number_of_events;
    if(number_of_events == 0){
        transfer_to_state->event_indexes = NULL;
    }else{
        transfer_to_state->event_indexes = (unsigned short *)Allocate_once_malloc_CFL(input, sizeof(unsigned short) * number_of_events);
        for(unsigned i = 0; i < number_of_events; i++){
            transfer_to_state->event_indexes[i] = event_indexes[i];
        }
    }
    
    Asm_store_column_element_CFL(input, "TRANSFER_EVENTS_TO_STATE",NULL, transfer_to_state);
      
}



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
        return CONTINUE_CFL;
    }
    // find active state queue
    unsigned short sm_queue_id = sm_control->queue_ids[sm_control->current_state];
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


void Asm_transfer_events_to_sm_CFL(void *input,const const char *transfer_sm, 
                   unsigned short number_of_events, short *event_indexes){
  
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    
    short sm_id_transfer = Find_Name_CFL(sm_dict->sm_names, transfer_sm);
    if (sm_id_transfer < 0)
    {
        ASSERT_PRINT_F("sm_name %s not found\n", transfer_sm);
    }


    transfer_to_sm_t *transfer_to_sm = (transfer_to_sm_t *)Allocate_once_malloc_CFL(input, sizeof(transfer_to_sm_t));
    transfer_to_sm->sm_id_transfer = sm_id_transfer;
    transfer_to_sm->number_of_events = number_of_events;
    if(number_of_events == 0){
        transfer_to_sm->event_indexes = NULL;
    }else{
        transfer_to_sm->event_indexes = (unsigned short *)Allocate_once_malloc_CFL(input, sizeof(unsigned short) * number_of_events);
        for(unsigned i = 0; i < number_of_events; i++){
            transfer_to_sm->event_indexes[i] = event_indexes[i];
        }
    }
    
    Asm_store_column_element_CFL(input, "TRANSFER_TO_SM",NULL, transfer_to_sm);
      
}



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
    // state machine is not active
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

typedef struct conditional_state_change_CFL_t{
    short sm_id;
    short new_state_id;
   
    void *user_data;
}conditional_state_change_CFL_t;

void Asm_conditional_state_change_CFL(void *input,const char *state_machine_name,const char *new_state,const char *bool_fn_name, void *user_data){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_id = Find_Name_CFL(sm_dict->sm_names, state_machine_name);
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;
     Bool_function_CFL_t bool_fn = Get_bool_function_CFL(input, bool_fn_name);
    if (sm_id < 0)
    {
        ASSERT_PRINT_F("sm_name %s not found\n", state_machine_name);
    }  
    short new_state_id = Find_Name_CFL(sm_control->state_names, new_state);
    if (new_state_id < 0)
    {
        ASSERT_PRINT_F("new_state_name %s not found\n", new_state);
    }
    conditional_state_change_CFL_t *conditional_state_change = (conditional_state_change_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(conditional_state_change_CFL_t));
    conditional_state_change->sm_id = sm_id;
    conditional_state_change->new_state_id = new_state_id;
    conditional_state_change->user_data = user_data;
    Asm_store_column_element_CFL(input,"CONDITIONAL_STATE_CHANGE",bool_fn, conditional_state_change);
}


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

typedef struct conditional_sm_status_CFL_t{
    short sm_id_transfer;   
    bool  action;
    void *user_data;
}conditional_sm_status_CFL_t;

void Asm_conditional_sm_status_CFL(void *input,const char *transfer_sm,bool action,const char *bool_fn_name, void *user_data){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_id_transfer = Find_Name_CFL(sm_dict->sm_names, transfer_sm);
    if( sm_id_transfer){
        ASSERT_PRINT_F("sm_name %s not found\n", transfer_sm);
    }
    
    Bool_function_CFL_t bool_fn = Get_bool_function_CFL(input, bool_fn_name);
    conditional_sm_status_CFL_t *conditional_sm_status = (conditional_sm_status_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(conditional_sm_status_CFL_t));
    conditional_sm_status->sm_id_transfer = sm_id_transfer;
    conditional_sm_status->user_data = user_data;
    conditional_sm_status->action = action;
    Asm_store_column_element_CFL(input,"CONDITIONAL_SM_STATUS",bool_fn, conditional_sm_status);
    
}


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
            Reset_named_event_queue_CFL(handle, sm_control->sm_queue_id);
            for(unsigned i= 0; i < sm_control->number_of_states; i++){
              Reset_named_event_queue_CFL(handle, sm_control->queue_ids[i]);
            }
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


void Change_state_CFL(void *input, short sm_id, short new_state_id)
{
    
    
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;

   
    
    Disable_column_CFL(input, sm_control->chain_ids[sm_control->current_state]);
    sm_control->current_state = new_state_id;
    Enable_column_CFL(input, sm_control->chain_ids[new_state_id]);
    sm_control->current_state = new_state_id;
}

void Asm_dump_state_machines_CFL(void *input)
{

    Asm_one_shot_CFL(input, "DUMP_STATE_MACHINES", NULL);
}

static void dump_sm(void *input, void *params, Event_data_CFL_t *event_data)
{
    (void)params;
    (void)event_data;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control;
   
    Printf_CFL(input, "STATE Machine Dump %s\n"," ");
    Printf_CFL("number of state machines %d\n", sm_dict->current_sm_number);
    for (unsigned i = 0; i < sm_dict->current_sm_number; i++)
    {
        Printf_CFL("state machine %d\n", i);
        Printf_CFL("number of states %d\n", sm_control[i].number_of_states);
        
        if (sm_control[i].active == true)
        {
            Printf_CFL("current state is %d\n", sm_control[i].current_state);
        }else{
            Printf_CFL("state machine is not active %s\n"," ");
        }
    }
}

typedef struct redirect_CFL_t
{
    void *user_data;
    unsigned short queue_number;
    unsigned short *queue_ids;
    unsigned short event_number;
    unsigned short *event_ids;
} redirect_CFL_t;

void Asm_redirect_event_CFL(void *input, const char *boolean_fn_name, void *user_data, unsigned short queue_number,
                           const char **queue_names, unsigned short number_of_events, unsigned short *event_ids)
{
    Bool_function_CFL_t boolean_fn = Get_bool_function_CFL(input, boolean_fn_name);
    redirect_CFL_t *redirect = (redirect_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(redirect_CFL_t));
    redirect->user_data = user_data;
    redirect->queue_number = queue_number;
    redirect->queue_ids = (unsigned short *)Allocate_once_malloc_CFL(input, sizeof(unsigned short) * queue_number);
    for (unsigned i = 0; i < queue_number; i++)
    {
        redirect->queue_ids[i] = Get_named_event_queue_index_CFL(input, queue_names[i]);  
    } 
    
    redirect->event_number = number_of_events;
    redirect->event_ids = (unsigned short *)Allocate_once_malloc_CFL(input, sizeof(unsigned short) * number_of_events);
    for (unsigned i = 0; i < number_of_events; i++)
    {
        redirect->event_ids[i] = event_ids[i];
    }
    Asm_store_column_element_CFL(input,"REDIRECT_EVENT",boolean_fn, redirect);
}


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

typedef struct sms_change_user_data_CFL_t
{
    void *user_data;
    unsigned short sms_number;
} sms_change_user_data_CFL_t;

void Asm_sms_set_user_data_CFL(void *input, const char *sm_name, void *user_data){

   Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_id = Find_Name_CFL(sm_dict->sm_names, sm_name);
    if (sm_id < 0)
    {
        ASSERT_PRINT_F("sm_name %s not found\n", sm_name);
    }
    sms_change_user_data_CFL_t *sms_change_user_data = (sms_change_user_data_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(sms_change_user_data_CFL_t));
    sms_change_user_data->user_data = user_data;
    sms_change_user_data->sms_number = sm_id;
    Asm_one_shot_CFL(input, "SMS_CHANGE_USER_DATA",sms_change_user_data);

}

static void process_set_sms_user_data(void *input , void *params, Event_data_CFL_t *event_data){
    
    (void)event_data;
    sms_change_user_data_CFL_t *sms_change_user_data = (sms_change_user_data_CFL_t *)params;
    
    Sms_set_user_data_CFL(input, sms_change_user_data->sms_number, sms_change_user_data->user_data);
}


void Sms_set_user_data_CFL(void *input, unsigned short sm_id, void *user_data)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;
    sm_control->user_data = user_data;
}

void *Sms_get_user_data_CFL(void *input, unsigned short sm_id)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;
    return sm_control->user_data;
}
/*

  Local functions


*/
