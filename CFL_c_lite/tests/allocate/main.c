#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "CFL_inner_engine.h"

#include "test_script.h"


static void test_debug_write(const Handle_CFL_t *handle);
static void test_working_heap(const Handle_CFL_t *handle);

static void test_allocate_once_heap(const Handle_CFL_t *handle);

int main() {



  
  const Handle_CFL_t *handle = Get_handle_CFL();
  

   Initialize_engine_CFL(handle);
   test_debug_write(handle);
   test_allocate_once_heap(handle);
   test_working_heap(handle);
    
 
}

/*
   This test checks that the CFL engine is configed and terminated ok
   Also the debug write function is tested
*/

static void test_debug_write(const Handle_CFL_t *handle){
 
   (void)handle;
   
   Printf_CFL("test message  debug write is ok \n");
  
   Printf_CFL("amount of allocate once heap %d \n",remaining_allocate_once_heap_size_CFL(handle));
   Printf_CFL("largest free block %d \n", private_heap_largest_block_CFL(handle));

  
}


/*
   This test makes sure that allocate once heap is working.
   Also the function remaining_allocate_once_heap_size_CFL is checked

*/

static void test_allocate_once_heap(const Handle_CFL_t *handle) {


  void* temp;
  Printf_CFL("test allocate once heap\n");
 
  Printf_CFL("amount of allocate once heap %d\n", remaining_allocate_once_heap_size_CFL(handle));
  Printf_CFL("allocationg 101 bytes\n");
  temp = handle->allocate_once(handle, 101); // test mod 8 allignment
  Printf_CFL("memory pointer %p \n", temp);
 Printf_CFL("amount of allocate once heap %d \n",remaining_allocate_once_heap_size_CFL(handle));

}

/*
   The purpose of this unit test is to test that private heap malloc blocks
   are join to form larger blocks when they are freed.
   This test allocate and frees in an order that is not sequential.

*/

static void test_working_heap(const Handle_CFL_t *handle) {
 
 
  void* test_array[10];
  unsigned size[10] = { 11, 23, 33, 44, 55, 66, 77, 88, 99, 199 };
  Printf_CFL("private heap size \n");
  Printf_CFL("largest free block %d \n",private_heap_largest_block_CFL(handle));
  for (int i = 0; i < 10; i++) {
    Printf_CFL("malloc size %d \n",size[i]);
    test_array[i] = handle->malloc(handle, size[i]);
    memset(test_array[i],0xff, size[i]);
     Printf_CFL("largest private heap size %d \n",private_heap_largest_block_CFL(handle));
  }
  // making sure heap allocates and reclaimes blocks
  handle->free(handle, test_array[9]);
   handle->free(handle, test_array[0]);
   handle->free(handle, test_array[8]);
   handle->free(handle, test_array[1]);
   handle->free(handle, test_array[7]);
   handle->free(handle, test_array[2]);
   handle->free(handle, test_array[6]);
   handle->free(handle, test_array[3]);
  handle->free(handle, test_array[5]);
   handle->free(handle, test_array[4]);

  Printf_CFL("largest private heap size %d \n",private_heap_largest_block_CFL(handle));

}