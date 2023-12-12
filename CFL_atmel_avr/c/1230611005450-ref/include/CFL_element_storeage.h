#ifndef __CFL_Element_Storeage_H__
#define __CFL_Element_Storeage_H__

#include "CFL_definitions.h"





Hash_cell_control_CFL_t *contruct_hash_cell_control_CFL(void *input,int cell_number);

void Store_Names_CFL(Hash_cell_control_CFL_t *hash_cell, int length, const char **names);
int Store_Name_CFL(Hash_cell_control_CFL_t *hash_cell_control, const char *name);



/*
**
**  Find the array index if not found return -1
**
*/

int Find_Name_CFL(Hash_cell_control_CFL_t *hash_cell, const char *name);

int Validate_Name_CFL(Hash_cell_control_CFL_t* hash_cell_control, const char *name);

#endif