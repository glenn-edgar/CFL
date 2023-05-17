#ifndef __CFL_CORE_AUX_FUNCTIONS_H__
#define __CFL_CORE_AUX_FUNCTIONS_H__

/*
** basic return code functions
*/ 


int reserve_one_shot_function_space_CFL(void);
void load_one_shot_function_state_CFL(void *input);
int reserve_bool_function_space_CFL(void);
void load_bool_functions_CFL(void *input);
int reserve_if_function_space_CFL(void);
void load_if_functions_CFL(void *input);
int reserve_try_function_space_CFL(void);
void load_try_functions_CFL(void *input);
#endif