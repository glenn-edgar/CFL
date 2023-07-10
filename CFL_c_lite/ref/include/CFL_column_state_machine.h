#ifndef __CFL_COLUMN_STATE_MACHINES_H__
#define __CFL_COLUMN_STATE_MACHINES_H__

unsigned reserve_column_sm_function_space_CFL(void);
unsigned reserve_column_sm_one_shot_function_space_CFL(void);
void Initialize_column_state_machine_CFL(void *input);


/*
   These two functions are implemented in CFL_columns.c
*/
void Asm_store_column_starting_state_CFL(void *input);
void Asm_store_column_ending_state_CLF(void *input);

/*
     event handlers


*/

void Asm_process_event_CFL(void *input,const char *event_handler,
                            unsigned event_number, short *event_values,
                             bool block_flag, short return_value, void *user_data);




void Asm_change_column_state_CFL(void *input, unsigned short new_state);



// runtime function

void Change_local_column_state_CFL(void *input, unsigned short new_state);

#endif // __CFL_COLUMN_STATE_MACHINES_H__