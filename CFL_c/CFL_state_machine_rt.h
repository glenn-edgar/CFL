#ifndef _CFL_STATE_MACHINE_RT_H_
#define _CFL_STATE_MACHINE_RT_H_

// define structures for sm functions





typedef struct change_sm_data_CFL_t{
    unsigned short sm_index;
    unsigned short state_index;
}change_sm_data_CFL_t;


typedef struct enable_disable_data_CFL_t{
    unsigned short sm_number; 
    unsigned short *sm_indexes; 

}enable_disable_data_CFL_t;

void Enable_state_machines_CFL(void *input, unsigned short number_of_state_machines, unsigned short *state_machine_indexes);
void Disable_state_machines_CFL(void *input, unsigned short number_of_state_machines, unsigned short *state_machine_indexes);
void Enable_state_machine_CFL(void *input, unsigned char sm_index);
void Disable_state_machine_CFL(void *input, unsigned char sm_index);
void *Find_state_machine_user_data_CFL(void *input, unsigned short sm_index);
bool State_machine_is_active_CFL(void *input, unsigned short sm_index);
States_def_CFL_t *Find_current_state_CFL(void *input, unsigned short sm_index);

/*

    state c functions

*/

void Enable_state_CFL(void *input, unsigned short sm_index, unsigned char sm_state);
void Disable_state_CFL(void *input, unsigned short sm_index, unsigned char sm_state);
void Change_state_CFL(void *input, unsigned short sm_index, unsigned char sm_state);
void *Find_state_user_data_CFL(void *input, unsigned short sm_index, unsigned char state_index);
States_def_CFL_t *Find_state_CFL(void *input, unsigned short sm_index, unsigned char state_index);

#endif // _CFL_STATE_MACHINE_RT_H_