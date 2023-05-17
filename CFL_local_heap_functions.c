

#include "Cfl_user_functions.h"

#include "Cfl_local_heap_functions.h"
#include "Cfl_private_heap.h"

// need to be 4 to protect alignment

#define HEAP_PROTECTION 0
// need to be 4 to protect alignment
#define PADDING 0

static void setup_private_heap(Handle_CFL_t *handle,
                               unsigned private_heap_size);

Handle_CFL_t *create_allocate_once_heap_CFL(int master_heap_size,
                                            unsigned private_heap_size) {
  Handle_CFL_t *handle;
  char *heap_location;
  int extra_size;
  if (master_heap_size == 0) {
    return NULL;
  }

  extra_size = sizeof(Handle_CFL_t) + PADDING;
  heap_location = (char *)malloc(master_heap_size + extra_size);
  if (heap_location == NULL) {
    ASSERT_PRINT("Cannot allocate local heap", NULL);
  }
  memset(heap_location, 0, master_heap_size + extra_size);
  handle = (Handle_CFL_t *)heap_location;
  handle->master_heap_starting_location = heap_location;
  handle->master_heap_size = master_heap_size;
  handle->remaining_heap_size = master_heap_size - extra_size;
  handle->current_heap_location = heap_location + extra_size;
  setup_private_heap(handle, private_heap_size);
  return handle;
}

static void setup_private_heap(Handle_CFL_t *handle,
                               unsigned private_heap_size) {
  void *working_heap_area;

  handle->private_heap = allocate_once_CFL(handle, sizeof(CS_MEMORY_CONTROL));
  handle->private_heap_size = private_heap_size;
  working_heap_area = allocate_once_CFL(handle, private_heap_size);
  initialize_privateHeap_CFL((CS_MEMORY_CONTROL *)handle->private_heap,
                             private_heap_size, working_heap_area);
}

// this macro will align but over estimate the space
#define align_8(addr) (((addr) + 7) & (~7))

void *allocate_once_CFL(Handle_CFL_t *handle, unsigned size) {
  void *return_value;
  char message[80];

  if (size == 0) {
    ASSERT_PRINT_INT("cannot allocate zero heap size",
                     size);
  }

  size = align_8(size);

  if ((size % 8) != 0) {
    size = size + align_8(size);
  }
  if (size >= handle->remaining_heap_size) {
    sprintf(message, "space: %d requested %d", handle->remaining_heap_size,
            size);
    ASSERT_PRINT("local heap space exceeded", message);
  }

  return_value = (void *)handle->current_heap_location;
  handle->current_heap_location += size + HEAP_PROTECTION;
  handle->remaining_heap_size -= size + HEAP_PROTECTION;

  return return_value;
}

void free_allocate_once_heap_CFL(Handle_CFL_t *handle) {

  free(handle->master_heap_starting_location);
}

int remaining_allocate_once_heap_size_CFL(Handle_CFL_t *handle) {

  return handle->remaining_heap_size;
}

/*
**
**  local heap functions
**
*/

void *create_private_heap_CFL(Handle_CFL_t *handle, unsigned size) {

  return allocate_once_CFL(handle, size);
}

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
