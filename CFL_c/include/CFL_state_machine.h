#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__
#include "CFL_user_functions.h"
#include "Cfl_element_storeage.h"

typedef struct Sm_control_CFL_t
{   
    Hash_cell_control_CFL_t *state_names;
    bool           active;
    bool           defined;
    unsigned short sm_id;
    unsigned short sm_queue_id;
    unsigned short manager_chain_id;
    unsigned short current_state;
    unsigned short initial_state;
    unsigned short number_of_states;
    short          *chain_ids;  // each state is a chain
    void          *user_data;
} Sm_control_CFL_t;



typedef struct Sm_dictionary_CFL_t
{
    Hash_cell_control_CFL_t *sm_names;
    unsigned short current_sm_number;
    unsigned short max_sms_number;
    Sm_control_CFL_t *sm_control;
} Sm_dictionary_CFL_t;

unsigned sm_reserve_one_shot_functions_CFL(void);
void sm_register_one_shot_functions_CFL(void *input);
void Constuct_sm_system_CFL(void *input, Handle_config_CFL_t* config);

void Define_state_machine_CFL(void *input, unsigned short number_of_states, const char **state_names);


void Asm_define_sm(void *input,
                   const char *sm_name,
                   unsigned char number_of_states,
                   const char **state_names,
                   const char *sm_manager_chain_name,
                   const char *sm_queue_name,
                   const char *initial_state,
                   void *user_data);


void Asm_define_state_CFL(void *input, 
                        const char *state_name,
                        const char *chain_name);

void Asm_end_state_machine_CFL(void *input);

void Asm_enable_disable_sms_CFL(void *input, char *sm_name, bool state);
                         
void Asm_sms_send_event(void *input, char *sm_name, Event_data_CFL_t *event_data);



void Asm_change_state_CFL(void *input, char *sm_name, char *new_state_name);

void Asm_dump_state_machines_CFL(void *input);

void Verify_all_sm_are_defined(void *input);




#endif