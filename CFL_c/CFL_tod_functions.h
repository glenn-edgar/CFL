#ifndef __Tod_functions_CFL_h__
#define __Tod_functions_CFL_h__

void Initialize_bool_functions_CFL(void *input);

void Asm_wait_tod(void *input, short Doy, short month, short dow, short hour, short minute);

void Asm_verify_tod(void *input, short Doy, short month, short dow, short hour, short minute, bool terminate_flag); 

#endif // __Tod_functions_CFL_h__