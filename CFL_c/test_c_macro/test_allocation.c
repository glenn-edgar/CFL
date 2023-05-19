#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

/*
**
  This test makes sure that
  1. Engine Configures
  2. User Defined Enities Load
  3. Column assembly is not tested here
     Will be done later.

**
*/





static void test_debug_write(Handle_config_CFL_t* config_handle);
static void test_working_heap(Handle_config_CFL_t* config_handle);

static void test_allocate_once_heap(Handle_config_CFL_t* config_handle);

void test_allocation() {



  Handle_config_CFL_t* config_handle = Create_config_handle_CFL();
  
  

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
  config_handle->debug_out = debug_write;
 
   test_debug_write(config_handle);
   test_allocate_once_heap(config_handle);
   test_working_heap(config_handle);
    free(config_handle);
 
}

/*
   This test checks that the CFL engine is configed and terminated ok
   Also the debug write function is tested
*/

static void test_debug_write(Handle_config_CFL_t* config_handle){
 
  void* input = Configure_engine_CFL(config_handle,100000, 2000);
   
   Printf_CFL("test message  debug write is ok \n");
  
    Printf_CFL("amount of allocate once heap %d \n",Allocate_once_remaining_heap_size_CFL(input));
   Printf_CFL("largest free block %d \n",Private_heap_largest_free_block_CFL(input));
  Destroy_engine_CFL(input);
  
}


/*
   This test makes sure that allocate once heap is working.
   Also the function Allocate_once_remaining_heap_size_CFL is checked

*/

static void test_allocate_once_heap(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 50000, 2000);

  void* temp;
  Printf_CFL("test allocate once heap\n");
 
  Printf_CFL("amount of allocate once heap %d\n",Allocate_once_remaining_heap_size_CFL(input));
  Printf_CFL("allocationg 101 bytes\n");
  temp = Allocate_once_malloc_CFL(input, 101); // test mod 8 allignment
  Printf_CFL("memory pointer %p \n", temp);
 Printf_CFL("amount of allocate once heap %d \n",Allocate_once_remaining_heap_size_CFL(input));
}

/*
   The purpose of this unit test is to test that private heap malloc blocks
   are join to form larger blocks when they are freed.
   This test allocate and frees in an order that is not sequential.

*/

static void test_working_heap(Handle_config_CFL_t* config_handle) {
  void* input = Configure_engine_CFL(config_handle, 50000, 2000);
  void* test_array[10];
  unsigned size[10] = { 11, 23, 33, 44, 55, 66, 77, 88, 99, 199 };
  Printf_CFL("private heap size \n");
  Printf_CFL("largest free block %d \n",Private_heap_largest_free_block_CFL(input));
  for (int i = 0; i < 10; i++) {
    Printf_CFL("malloc size %d \n",size[i]);
    test_array[i] = Private_heap_malloc_CFL(input, size[i]);
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
}
