#ifndef __CFL_Master_Heap_H__
#define __CFL_Master_Heap_H__


#include "Cfl_user_functions.h"
#include "Cfl_definitions.h"

/*
** Allocate once heap functions
*/

Handle_CFL_t *create_allocate_once_heap_CFL(int master_heap_size,unsigned private_heap_size);

void *allocate_once_CFL(Handle_CFL_t *handle,unsigned size);

void free_allocate_once_heap_CFL(Handle_CFL_t *handle);

int remaining_allocate_once_heap_size_CFL(Handle_CFL_t *handle);



/*
**
** Private Heap Functions
**
*/
void *create_private__heap_CFL(Handle_CFL_t *handle,unsigned size);
void *private_heap_malloc_CFL(Handle_CFL_t *handle, unsigned size);
void  private_heap_free_CFL( Handle_CFL_t *handle, void *ptr );
unsigned   private_heap_largest_block_CFL(Handle_CFL_t *handle);
void  private_heap_reset_CFL(Handle_CFL_t *handle);
void private_heap_dump_blocks_CFL(Handle_CFL_t *handle);



#endif