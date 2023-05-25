#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_state_machine_util.h"
#include "CFL_state_machine_rt.h"

static void asm_change_state_CFL(void *input, void *user_data, Event_data_CFL_t *event_data);
static void asm_enable_state_machines_CFL(void *input, void *user_data, Event_data_CFL_t *event_data);
static void asm_disable_state_machines_CFL(void *input, void *user_data, Event_data_CFL_t *event_data);
static void asm_dump_state_machines_CFL(void *input, void *user_data, Event_data_CFL_t *event_data);


void initialize_sm_runtime_functions_CFL(void *input)
{
// one shot functions
//  --- 1. Enable sm "ENABLE_SM"
//  --- 2. Disable sm "DISABLE_SM"
//  --- 3. Change state "CHANGE_STATE"
//  --- 4. Dump state machines "DUMP_STATE_MACHINES"
Store_one_shot_function_CFL(input, "ENABLE_SM", asm_enable_state_machines_CFL); 
Store_one_shot_function_CFL(input, "DISABLE_SM", asm_disable_state_machines_CFL);
Store_one_shot_function_CFL(input, "CHANGE_STATE", asm_change_state_CFL);
Store_one_shot_function_CFL(input, "DUMP_STATE_MACHINES", asm_dump_state_machines_CFL);

}



/*

   CFL functions


*/

static void asm_change_state_CFL(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    change_sm_data_CFL_t *data = (change_sm_data_CFL_t *)user_data;
    Change_state_CFL(input, data->sm_index, data->state_index);
}

static void asm_enable_state_machines_CFL(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    enable_disable_data_CFL_t *data = (enable_disable_data_CFL_t *)user_data;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        Enable_state_machines_CFL(input,data->sm_number, data->sm_indexes);  
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        asm_disable_state_machines_CFL(input, user_data, event_data);
    }
}
static void asm_disable_state_machines_CFL(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    enable_disable_data_CFL_t *data = (enable_disable_data_CFL_t *)user_data;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        Disable_state_machines_CFL(input,data->sm_number, data->sm_indexes);  
    }
    
}

static void asm_dump_state_machines_CFL(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    ; //TBD
}




/*

   state machine functions


*/

void Enable_state_machines_CFL(void *input, unsigned short number_of_state_machines, unsigned short *state_machine_indexes)
{
    for (unsigned char i = 0; i < number_of_state_machines; i++)
    {
        Enable_state_machine_CFL(input, state_machine_indexes[i]);
    }
}

void Disable_state_machines_CFL(void *input, unsigned short number_of_state_machines, unsigned short *state_machine_indexes)
{
    for (unsigned char i = 0; i < number_of_state_machines; i++)
    {
        Disable_state_machine_CFL(input, state_machine_indexes[i]);
    }
}

void Enable_state_machine_CFL(void *input, unsigned char sm_index)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    Event_data_CFL_t event_data;
    event_data.event_index = EVENT_INIT_CFL;

    sm_control->state_change_fn(input, sm_control->user_data, &event_data);
        sm_control->active = true;
        for (unsigned char i = 0; i < sm_control->number_of_states; i++)
        {
             Enable_state_CFL(input,sm_index, i);
        }
        
     
    
}
void Disable_state_machine_CFL(void *input, unsigned char sm_index)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    Event_data_CFL_t event_data;
    event_data.event_index = EVENT_TERMINATION_CFL;

    sm_control->state_change_fn(input, sm_control->user_data, &event_data);
        sm_control->active = false;
        for (unsigned char i = 0; i < sm_control->number_of_states; i++)
        {
             Disable_state_CFL(input,sm_index, i);
        }
        
     
    
}


// find if state machine is active
bool State_machine_is_active_CFL(void *input, unsigned short sm_index)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    return sm_control->active;
}

void *Find_state_machine_user_data_CFL(void *input, unsigned short sm_index)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    return sm_control->user_data;
}

States_def_CFL_t *Find_current_state_CFL(void *input, unsigned short sm_index)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    if (sm_control->active == false)
    {
        return NULL;
    }
    if (sm_control->current_state >= sm_control->number_of_states)
    {
        ASSERT_PRINT_F("Error: Current state index %d out of range", sm_control->current_state);
    }
    States_def_CFL_t *state = sm_control->starting_state+sm_control->current_state;
    return state;
}
/*

    state c functions

*/




void Enable_state_CFL(void *input, unsigned short sm_index, unsigned char sm_state){
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    
    Event_data_CFL_t event_data;
    event_data.event_index = EVENT_INIT_CFL;
    if(sm_state >= sm_control->number_of_states){
       ASSERT_PRINT_F("Error: State index %d out of range max %d", sm_state,sm_control->number_of_states);
    }
    States_def_CFL_t *new_state = sm_control->starting_state+sm_state;
    
     new_state->state_change_fn(input, new_state->user_data, &event_data);
    
    for (unsigned char i = 0; i < new_state->number_of_chains; i++)
    {
        Enable_column_CFL(input, new_state->state_chains[i]);
    }
    sm_control->current_state = sm_state;
}

void Disable_state_CFL(void *input, unsigned short sm_index, unsigned char sm_state){
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
   
    Event_data_CFL_t event_data;
    event_data.event_index = EVENT_TERMINATION_CFL;
    
    
  States_def_CFL_t *new_state = sm_control->starting_state+sm_state;
    
     new_state->state_change_fn(input, new_state->user_data, &event_data);
    
    for (unsigned char i = 0; i < new_state->number_of_chains; i++)
    {
        Disable_column_CFL(input, new_state->state_chains[i]);
    }
    sm_control->current_state = sm_state;
}

void Change_state_CFL(void *input, unsigned short sm_index, unsigned char sm_state)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    
    Event_data_CFL_t event_data;

    States_def_CFL_t *current_state = Find_current_state_CFL(input, sm_index);
    if (current_state != NULL)
    {
        for (unsigned char i = 0; i < current_state->number_of_chains; i++)
        {
            Disable_column_CFL(input, current_state->state_chains[i]);
        }
    }
    event_data.event_index = EVENT_TERMINATION_CFL;
    current_state->state_change_fn(input, current_state->user_data, &event_data);

    States_def_CFL_t *new_state = Find_state_CFL(input, sm_index, sm_state);

    event_data.event_index = EVENT_INIT_CFL;
    new_state->state_change_fn(input, current_state->user_data, &event_data);
    for (unsigned char i = 0; i < new_state->number_of_chains; i++)
    {
        Enable_column_CFL(input, new_state->state_chains[i]);
    }
    sm_control->current_state = sm_state;
}



void *Find_state_user_data_CFL(void *input, unsigned short sm_index, unsigned char state_index)
{
    States_def_CFL_t *state = find_state_CFL(input, sm_index, state_index);
    return state->user_data;
}

States_def_CFL_t *Find_state_CFL(void *input, unsigned short sm_index, unsigned char state_index)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    if (sm_control->active == false)
    {
        return NULL;
    }
    if (sm_control->current_state >= sm_control->number_of_states)
    {
        ASSERT_PRINT_F("Error: Current state index %d out of range  limit %d \n", sm_control->current_state,sm_control->number_of_states);
    }
    States_def_CFL_t *state = sm_control->starting_state+state_index;
    return state;
}
