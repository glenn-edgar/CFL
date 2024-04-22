#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "CFL_inner_engine.h"
#include <unistd.h>
#include "test_interface.h"


void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}

char *allocate_once_memory = NULL;

void create_allocate_once_heap(){
    allocate_once_memory = (char *)malloc(2000);
}

void free_allocate_once_heap(){
    free(allocate_once_memory);
}



void test_rpc_services_1(void);
void test_rpc_services_2(void);
void test_sync_no_wait(void);
void test_sync_wait(void);


int main()

{
  printf("\n\n test rpc services \n\n");
  //test_rpc_services_1();
  //test_rpc_services_2();
  //test_sync_no_wait();
  test_sync_wait();
 
}


#include "rpc_services_1.h"
void test_rpc_services_1(void)
{  
    
 

   create_allocate_once_heap(); // create allocate once heap

  
   const Handle_CFL_t *handle = rpc_services_handle_1();
 
   Initialize_heap_CFL(handle);
     
   Initialize_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
  
}



#include "rpc_services_2.h"

void test_rpc_services_2(void)
{  
    
 

   create_allocate_once_heap(); // create allocate once heap

  
   const Handle_CFL_t *handle = rpc_services_handle_2();
 
   Initialize_heap_CFL(handle);
     
   Initialize_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
  
}

#include "sync_service_1.h"
void test_sync_no_wait(void)
{  
    
 

   create_allocate_once_heap(); // create allocate once heap

  
   const Handle_CFL_t *handle = sync_service_1();
 
   Initialize_heap_CFL(handle);
     
   Initialize_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
  
}

#include "sync_service_2.h"
void test_sync_wait(void)
{  
    
 

   create_allocate_once_heap(); // create allocate once heap

  
   const Handle_CFL_t *handle = sync_service_2();
 
   Initialize_heap_CFL(handle);
     
   Initialize_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
  
}

