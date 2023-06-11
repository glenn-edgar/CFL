#ifndef _CFL_STATE_MACHINE_ASM_H_
#define _CFL_STATE_MACHINE_ASM_H_

#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_debug.h"
#include "CFL_element_storeage.h"
#include "CFL_state_machine_util.h"
#include "CFL_state_machine_rt.h"


void Asm_define_sm(void *input, 
                   const char *sm_name, 
                   unsigned char  number_of_states, 
                   const char **state_names, 
                   const char *initial_state,
                   const char *sm_change_fn,
                   void *user_data);


void Asm_define_state_CFL(void *input, 
                        const char *state_name,
                        unsigned short chain_number, 
                        const char **chain_names,
                        const char *state_change_fn,
                        void *user_data);

void Asm_end_state_machine_CFL(void *input);

void Asm_enable_sms_CFL(void *input,
                        unsigned short number, 
                        const char **state_names);

void Asm_disable_sms_CFL(void *input,
                         unsigned short number, 
                         const char **sm_names);

void Asm_change_state_CFL(void *input, 
                          const char *state_machine_name, 
                          const char *state_name);

void Asm_dump_state_machines_CFL(void *input);


#endif