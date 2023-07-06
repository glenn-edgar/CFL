#ifndef __STATE_MACHINE_CFL_H__
#define __STATE_MACHINE_CFL_H__
#include "CFL_user_functions.h"



unsigned sm_reserve_one_shot_functions_CFL(void);
void sm_register_one_shot_functions_CFL(void *input);

unsigned sm_reserve_column_functions_CFL(void);
void sms_register_column_functions_CFL(void *input);
void Constuct_sm_system_CFL(void *input, Handle_config_CFL_t* config);

void Define_state_machines_CFL(void *input, unsigned short number_of_states, const char **state_names);


void Asm_define_state_machine_CFL(void *input,
                   const char *sm_name,
                   unsigned char number_of_states,
                   const char **state_names,
                   const char *sm_manager_chain_name,
                   const char *sm_queue_name,
                   const char *initial_state,
                   void *user_data);


void Asm_define_state_CFL(void *input,
                          const char *state_name,
                          const char *chain_name,
                          const char *queue_name); 

void Asm_end_state_machine_CFL(void *input);

void Asm_enable_disable_sms_CFL(void *input,unsigned short number, const char **sm_name);

void Asm_disable_sms_CFL(void *input,unsigned short number, const char **sm_names);

void Asm_enable_sms_CFL(void *input,unsigned short number, const char **sm_names);

void Asm_sms_send_event_CFL(void *input, const char *sm_name, Event_data_CFL_t *event_data);

void Asm_sms_set_user_data_CFL(void *input, const char *sm_name, void *user_data);


void Asm_change_state_CFL(void *input, const char *sm_name,const char *new_state_name);

void Asm_dump_state_machines_CFL(void *input);

void Asm_sms_set_user_data_CFL(void *input, const char *sm_name, void *user_data);

void Asm_transfer_events_to_state_CFL(void *input,const char *state_machine_name,unsigned short number_of_events,short* event_indexes);
void Asm_transfer_events_to_sm_CFL(void *input,const const char *transfer_sm, 
                   unsigned short number_of_events, short* event_indexes);
void Asm_conditional_state_change_CFL(void *input,const char *state_machine_name,const char *new_state,const char *bool_fn_name, void *user_data);
void Asm_conditional_sm_status_CFL(void *input,const char *transfer_sm,bool action,const char *bool_fn, void *user_data);
/**
* c runtime functions
*/
void Sms_set_user_data_CFL(void *input, unsigned short sm_id, void *user_data);
void *Sms_get_user_data_CFL(void *input, unsigned short sm_id);

  
void Verify_all_sm_are_defined(void *input);
void Change_state_CFL(void *input, short sm_id, short new_state_id);



#endif