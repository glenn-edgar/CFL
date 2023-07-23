

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

static void setup_private_heap(Handle_CFL_t *handle);

void create_allocate_once_heap_CFL(void *input) {
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  handle->current_heap_location = (void *)handle->master_heap_starting_location;
  handle->remaining_heap_size = handle->master_heap_size;  
  setup_private_heap(handle);
  
}

static void setup_private_heap(Handle_CFL_t *handle) {
  
 
  initialize_privateHeap_CFL((CS_MEMORY_CONTROL *)handle->private_heap,
                            handle->private_heap_size, handle->working_heap_area);
}

// this macro will align but over estimate the space
#define align_8(addr) (((addr) + 7) & (~7))

void *allocate_once_CFL(Handle_CFL_t *handle, unsigned size) {
  void *return_value;
  

  if (size == 0) {
    ASSERT_PRINT_INT("cannot allocate zero heap size",
                     size);
  }

  size = align_8(size);

  if ((size % 8) != 0) {
    size = size + align_8(size);
  }
  if (size >= handle->remaining_heap_size) {
  
    ASSERT_PRINT_F("local heap space exceeded space: %d requested %d", handle->remaining_heap_size,
            size);
  }

  return_value = (void *)handle->current_heap_location;
  handle->current_heap_location += size + HEAP_PROTECTION;
  handle->remaining_heap_size -= size + HEAP_PROTECTION;

  return return_value;
}


int remaining_allocate_once_heap_size_CFL(Handle_CFL_t *handle) {

  return handle->remaining_heap_size;
}

/*
**
**  local heap functions
**
*/



void *private_heap_malloc_CFL(Handle_CFL_t *handle, unsigned size) {
  void *return_value;
  if(size == 0){
    ASSERT_PRINT_INT( "cannot allocate zero heap size",size);
  }
  return_value =  malloc_CFL((CS_MEMORY_CONTROL *)handle->private_heap, size);
  if(return_value == NULL){
    ASSERT_PRINT_INT( "ran out of heap space",size);
  }
  return return_value;
}


void private_heap_free_CFL(Handle_CFL_t *handle, void *ptr) {
  free_CFL((CS_MEMORY_CONTROL *)handle->private_heap, ptr);
}

unsigned private_heap_largest_block_CFL(Handle_CFL_t *handle) {

  return largest_block_privateHeap_CFL(
      (CS_MEMORY_CONTROL *)handle->private_heap);
}

void private_heap_dump_blocks_CFL(Handle_CFL_t *handle) {
  dumpHeap_CFL((CS_MEMORY_CONTROL *)handle->private_heap);
}

void private_heap_reset_CFL(Handle_CFL_t *handle) {
  reset_privateHeap_CFL((CS_MEMORY_CONTROL *)handle->private_heap);
}
