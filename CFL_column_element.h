#ifndef __CFL_Column_Element_H__
#define __CFL_Column_Element_H__

#include "Cfl_element_storeage.h"
#include "Cfl_definitions.h"




void allocate_column_elements_CFL(Handle_CFL_t* handle, int number_of_column_elements);


Column_element_CFL_t* allocate_column_element_CFL(Handle_CFL_t* handle);

int free_column_elements_CFL(Handle_CFL_t* handle);





#endif

