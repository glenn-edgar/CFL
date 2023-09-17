#ifndef __CFL_STATE_MACHINE_H__
#define __CFL_STATE_MACHINE_H__
#include "CFL_debug.h"


typedef struct Sm_control_RAM_CFL_t
{
  
    bool active;
    unsigned short current_state;
    
} Sm_control_RAM_CFL_t;


typedef struct Sm_control_ROM_CFL_t
{
    unsigned short sm_id;
    unsigned short sm_queue_id;
    unsigned short manager_chain_id;
    unsigned short number_of_states;
    short *chain_ids; // each state is a chain
    short *queue_ids;
    void *user_data;
} Sm_control_ROM_CFL_t;


void reset_all_state_machines_CFL(const void *input);
void disable_state_machine_CFL(const void *input,unsigned sm_id);
void enable_state_machine_CFL(const void *input,unsigned sm_id);
void change_state_machine_CFL(const void *input,unsigned sm_id,unsigned state_id);

#endif // __CFL_STATE_MACHINE_H__
