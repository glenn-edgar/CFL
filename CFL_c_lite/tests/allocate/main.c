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
  

   config_debug_handle_CFL(handle);
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
   Also the function Allocate_once_remaining_heap_size_CFL is checked

*/

static void test_allocate_once_heap(const Handle_CFL_t *handle) {
 (void)handle;
#if 0
  void* temp;
  Printf_CFL("test allocate once heap\n");
 
  Printf_CFL("amount of allocate once heap %d\n",Allocate_once_remaining_heap_size_CFL(input));
  Printf_CFL("allocationg 101 bytes\n");
  temp = Allocate_once_malloc_CFL(input, 101); // test mod 8 allignment
  Printf_CFL("memory pointer %p \n", temp);
 Printf_CFL("amount of allocate once heap %d \n",Allocate_once_remaining_heap_size_CFL(input));
 #endif
}

/*
   The purpose of this unit test is to test that private heap malloc blocks
   are join to form larger blocks when they are freed.
   This test allocate and frees in an order that is not sequential.

*/

static void test_working_heap(const Handle_CFL_t *handle) {
   (void)handle;
  #if 0
  void* input = Configure_engine_CFL(config_handle, 50000, 2000);
  void* test_array[10];
  unsigned size[10] = { 11, 23, 33, 44, 55, 66, 77, 88, 99, 199 };
  Printf_CFL("private heap size \n");
  Printf_CFL("largest free block %d \n",Private_heap_largest_free_block_CFL(input));
  for (int i = 0; i < 10; i++) {
    Printf_CFL("malloc size %d \n",size[i]);
    test_array[i] = Private_heap_malloc_CFL(input, size[i]);
    memset(test_array[i],0xff, size[i]);
     Printf_CFL("largest private heap size %d \n",Private_heap_largest_free_block_CFL(input));
  }
  // making sure heap allocates and reclaimes blocks
  Private_heap_free_CFL(input, test_array[9]);
  Private_heap_free_CFL(input, test_array[0]);
  Private_heap_free_CFL(input, test_array[8]);
  Private_heap_free_CFL(input, test_array[1]);
  Private_heap_free_CFL(input, test_array[7]);
  Private_heap_free_CFL(input, test_array[2]);
  Private_heap_free_CFL(input, test_array[6]);
  Private_heap_free_CFL(input, test_array[3]);
  Private_heap_free_CFL(input, test_array[5]);
  Private_heap_free_CFL(input, test_array[4]);

  Printf_CFL("largest private heap size %d \n",Private_heap_largest_free_block_CFL(input));
  #endif
}
