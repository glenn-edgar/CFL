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



void test_state_machine_1(void);
void test_state_machine_2(void);
void test_state_machine_3(void);
void test_state_machine_4(void);
void test_state_machine_5(void);


int main()

{
  printf("\n\n test_state machine \n\n");
  test_state_machine_1();
  test_state_machine_2();
  test_state_machine_3();
  test_state_machine_4();
  test_state_machine_5();
  
 
}


#include "state_machine_1.h"
void test_state_machine_1(void)
{  
    


   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = state_machine_1_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "state_machine_2.h"
void test_state_machine_2(void)
{  
    


   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = state_machine_2_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "state_machine_3.h"
void test_state_machine_3(void)
{  
    


   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = state_machine_3_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}
#include "state_machine_4.h"
void test_state_machine_4(void)
{  
    


   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = state_machine_4_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}
#include "state_machine_5.h"
void test_state_machine_5(void)
{  
    


   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = state_machine_5_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}