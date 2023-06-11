#ifndef _CFL_STATE_MACHINE_UTIL_H_   
#define _CFL_STATE_MACHINE_UTIL_H_

#include "CFL_user_functions.h"
#include "Cfl_element_storeage.h"

typedef struct States_def_CFL_t{
    unsigned short number_of_chains;
    unsigned short *state_chains;
    One_shot_function_CFL_t state_change_fn;
    void *user_data;
} States_def_CFL_t;

typedef struct State_dictionary_CFL_t
{   Hash_cell_control_CFL_t *state_names;
    unsigned short max_number_of_states;
    unsigned short current_state_index;
    States_def_CFL_t *state_cells;
} State_dictionary_CFL_t;

typedef struct Sm_control_CFL_t
{
    unsigned char    active:1;
    unsigned char    initial_state;
    unsigned char   current_state;  
    unsigned char    number_of_states;
    States_def_CFL_t *starting_state;
    Hash_cell_control_CFL_t *state_names;
    One_shot_function_CFL_t state_change_fn;
    void *user_data;
} Sm_control_CFL_t;

typedef struct Sm_dictionary_CFL_t
{
    unsigned short max_sm_number;
    unsigned short current_sm_number;
    Hash_cell_control_CFL_t *sm_names;
    Sm_control_CFL_t *sm_control;
} Sm_dictionary_CFL_t;


void Constuct_sm_system_CFL(void *input, Handle_config_CFL_t* config);
void Define_state_machines_CFL(void *input, unsigned short number_of_states, char **state_names);

// utility functions

// find state machine dictionary
Sm_dictionary_CFL_t *find_sm_dictionary_CFL(void *input);
Sm_control_CFL_t *find_sm_CFL(void *input, unsigned short sm_index);
States_def_CFL_t *find_state_CFL(void *input, unsigned short sm_index, unsigned char state_index);




#endif // _CFL_STATE_MACHINE_UTIL_H_