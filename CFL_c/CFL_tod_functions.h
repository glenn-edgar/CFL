#ifndef __Tod_functions_CFL_h__
#define __Tod_functions_CFL_h__

void Initialize_bool_functions_CFL(void *input);

void Asm_wait_tod_lt(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_le(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_eq(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_ge(void *input, short doy, short month, short dow, short hour, short minute, short second);
void Asm_wait_tod_gt(void *input, short doy, short month, short dow, short hour, short minute,  short second);

void Asm_verify_tod_lt(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag);
void Asm_verify_tod_le(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag);
void Asm_verify_tod_eq(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag);
void Asm_verify_tod_ge(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag);
void Asm_verify_tod_gt(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag);

#endif // __Tod_functions_CFL_h__