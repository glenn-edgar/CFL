

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CFL_inner_engine.h"
#include "CFL_local_heap_functions.h"
#include "CFL_private_heap.h"

// need to be 4 to protect alignment

#define HEAP_PROTECTION 0
// need to be 4 to protect alignment
#define PADDING 0


void create_allocate_once_heap_CFL(const void *input) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  *handle->current_heap_location = *handle->master_heap_starting_location;
  *handle->remaining_heap_size = handle->master_heap_size;  
 
  
  char *heap_start = (char *)allocate_once_CFL(handle, handle->private_heap_size);
   initialize_privateHeap_CFL(handle->private_heap, handle->private_heap_size+PRINT_BUF_SIZE_CFL+16,heap_start);
                    
}



// this macro will align but over estimate the space
#define align_8(addr) (((addr) + 7) & (~7))

void *allocate_once_CFL(const void *input, unsigned size) {
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  void *return_value;
  

  if (size == 0) {
    ASSERT_PRINT_INT(input,"cannot allocate zero heap size",
                     size);
  }

  size = align_8(size);

  if ((size % 8) != 0) {
    size = size + align_8(size);
  }
  if (size >= *handle->remaining_heap_size) {
  
    ASSERT_PRINT_F(input,"local heap space exceeded space: %d requested %d", handle->remaining_heap_size,
            size);
  }

  return_value = (void *)*handle->current_heap_location;
  *handle->current_heap_location += size + HEAP_PROTECTION;
  *handle->remaining_heap_size -= size + HEAP_PROTECTION;

  return return_value;
}


int remaining_allocate_once_heap_size_CFL(const void *input) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  return *handle->remaining_heap_size;
}

/*
**
**  local heap functions
**
*/



void *private_heap_malloc_CFL(const void *input, unsigned size) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  void *return_value;
  if(size == 0){
    ASSERT_PRINT_INT(input, "cannot allocate zero heap size",size);
  }
  return_value =  malloc_CFL(input,handle->private_heap, size);
  if(return_value == NULL){
    ASSERT_PRINT_INT(input, "ran out of heap space",size);
  }
  return return_value;
}


void private_heap_free_CFL(const void *input, void *ptr) {
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  free_CFL(input,handle->private_heap, ptr);
}

unsigned private_heap_largest_block_CFL(const void *input) {
 const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  return largest_block_privateHeap_CFL(handle->private_heap);
}

void private_heap_dump_blocks_CFL(const void *input) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  dumpHeap_CFL(input,handle->private_heap);
}

void private_heap_reset_CFL(const void *input) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  reset_privateHeap_CFL(input,handle->private_heap);
}
