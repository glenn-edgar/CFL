#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "Cfl_element_storeage.h"
#include "CFL_state_machine_util.h"

static void allocate_state_machine_CFL(void *input, unsigned short number_of_state_machines);
static void allocate_state_space_CFL(void *input, unsigned short number_of_states);
 void initialize_sm_runtime_functions_CFL(void *input);
void Constuct_sm_system_CFL(void *input, Handle_config_CFL_t *config)
{

    allocate_state_machine_CFL(input, config->number_of_state_machines);
    allocate_state_space_CFL(input, config->number_of_states);
    initialize_sm_runtime_functions_CFL(input);
}
void Define_state_machines_CFL(void *input, unsigned short number_of_states, char **state_names)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)handle->sm_dictionary;

    if (sm_dictionary->current_sm_number + number_of_states >= sm_dictionary->max_sm_number)
    {
        ASSERT_PRINT_F("Error: Too many state machines %d limit %d \n", number_of_states,sm_dictionary->max_sm_number);
    }

    for (int i = 0; i < number_of_states; i++)
    {
        int id = Store_Name_CFL(sm_dictionary->sm_names, state_names[i]);
        if (id < 0)
        {
            ASSERT_PRINT_F("Error: Duplicate state name %s\n", state_names[i]);
        }
    }
}

// utility functions

// find state machine dictionary
Sm_dictionary_CFL_t *find_sm_dictionary_CFL(void *input)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    return sm_dictionary;
}

// find state machine
Sm_control_CFL_t *find_sm_CFL(void *input, unsigned short sm_index)
{
    Sm_dictionary_CFL_t *sm_dictionary = find_sm_dictionary_CFL(input);
    if (sm_index >= sm_dictionary->current_sm_number)
    {
        ASSERT_PRINT_F("Error: State machine index %d out of range", sm_index);
    }
    Sm_control_CFL_t *sm_control = &sm_dictionary->sm_control[sm_index];
    return sm_control;
}

States_def_CFL_t *find_state_CFL(void *input, unsigned short sm_index, unsigned char state_index)
{
    Sm_control_CFL_t *sm_control = find_sm_CFL(input, sm_index);
    if (state_index >= sm_control->number_of_states)
    {
        ASSERT_PRINT_F("Error: State index %d out of range", state_index);
    }
    States_def_CFL_t *state = &sm_control->starting_state[state_index];
    return state;
}




/*

  Local functions


*/

static void allocate_state_machine_CFL(void *input, unsigned short number_of_state_machines)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;

    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_dictionary_CFL_t));
    handle->sm_dictionary = sm_dictionary;

    sm_dictionary->max_sm_number = number_of_state_machines;
    sm_dictionary->current_sm_number = 0;
    if (number_of_state_machines == 0)
    {
        sm_dictionary->sm_control = NULL;
        sm_dictionary->sm_names = NULL;
        return;
    }
    sm_dictionary->sm_names = contruct_hash_cell_control_CFL(handle, number_of_state_machines);
    sm_dictionary->sm_control = (Sm_control_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_control_CFL_t) * number_of_state_machines);
}

static void allocate_state_space_CFL(void *input, unsigned short number_of_states)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;

    if (number_of_states == 0)
    {

        handle->state_dictionary = NULL;
        return;
    }
    State_dictionary_CFL_t *state_dictionary = (State_dictionary_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(State_dictionary_CFL_t) * number_of_states);
    state_dictionary->max_number_of_states = number_of_states;
    state_dictionary->current_state_index = 0;

    States_def_CFL_t *state_cells = (States_def_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(States_def_CFL_t) * number_of_states);

    for (int i = 0; i < number_of_states; i++)
    {
        state_cells[i].number_of_chains = 0;
        state_cells[i].state_chains = NULL;
        state_cells[i].user_data = NULL;
    }
    handle->state_dictionary = state_dictionary;
}
