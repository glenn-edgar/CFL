#ifndef __CFL_Master_Heap_H__
#define __CFL_Master_Heap_H__

#include "CFL_inner_engine.h"

void create_allocate_once_heap_CFL(const void *input); 





int remaining_allocate_once_heap_size_CFL(const void *input); 

/*
**
**  local heap functions
**
*/





unsigned private_heap_largest_block_CFL(const void *input);

void private_heap_dump_blocks_CFL(const void *input); 

void private_heap_reset_CFL(const void *input);




#endif