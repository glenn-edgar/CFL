#ifndef __CFL_Columns_H__
#define __CFL_Columns_H__

#include "Cfl_definitions.h"

void allocate_columns_CFL(Handle_CFL_t* handle, int number_of_columns);
void reserve_column_names_CFL(void* input, int number_of_columns, const char** column_names);






#endif