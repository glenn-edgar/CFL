#ifndef __CFL_Master_Heap_H__
#define __CFL_Master_Heap_H__

#include "CFL_inner_engine.h"

void create_allocate_once_heap_CFL(void *input); 


void *allocate_once_CFL(Handle_CFL_t *handle, unsigned size); 


int remaining_allocate_once_heap_size_CFL(Handle_CFL_t *handle); 

/*
**
**  local heap functions
**
*/



void *private_heap_malloc_CFL(Handle_CFL_t *handle, unsigned size);


void private_heap_free_CFL(Handle_CFL_t *handle, void *ptr);

unsigned private_heap_largest_block_CFL(Handle_CFL_t *handle);

void private_heap_dump_blocks_CFL(Handle_CFL_t *handle); 

void private_heap_reset_CFL(Handle_CFL_t *handle);




#endif