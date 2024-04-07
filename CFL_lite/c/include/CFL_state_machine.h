#ifndef __CFL_STATE_MACHINE_H__
#define __CFL_STATE_MACHINE_H__
#include "CFL_debug.h"
#include <stdint.h>



typedef struct Sm_control_RAM_CFL_t
{
  
    bool       active;
    uint16_t  current_state;
    uint32_t   state_hash;
    
} Sm_control_RAM_CFL_t;


typedef struct Sm_control_ROM_CFL_t
{
    uint16_t   sm_id;
    uint32_t   sm_hash;
   
    uint16_t   manager_column_id;

    uint16_t   number_of_states;
    const uint32_t   *state_hash;
    const uint16_t   *column_ids; // each state is a chain

    void       *user_data;
} Sm_control_ROM_CFL_t;



void disable_all_state_machines_CFL(const void *input);

void disable_state_machine_CFL(const void *input,uint16_t sm_id);
void disable_state_machine_hash_CFL(const void *input,uint32_t sm_id);

void enable_state_machine_CFL(const void *input,uint16_t sm_id);
void enable_state_machine_hash_CFL(const void *input,uint32_t sm_hash);


void change_state_machine_CFL(const void *input,uint16_t sm_id,uint16_t state_id);
void change_state_machine_hash_CFL(const void *input,uint32_t sm_id,uint32_t state_hash);

void send_sm_event(const void *input,uint16_t sm_id, Event_data_CFL_t *event);
void send_sm_event_hash(const void *input,uint32_t sm_hash, Event_data_CFL_t *event);

bool send_event_to_state(const void *input, Event_data_CFL_t *event);

const void *get_state_machine_user_data_CFL(const void *input,uint16_t sm_id);
#endif // __CFL_STATE_MACHINE_H__


