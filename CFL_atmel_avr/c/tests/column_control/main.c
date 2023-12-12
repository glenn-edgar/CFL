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



void test_basic_control(void);
void test_while_control(void);
void test_if_then_else_control(void);
void test_try_1(void);
void test_try_2(void);
void test_try_3(void);

int main()
{
  printf("\n\n test column control \n\n");
  test_basic_control();
  test_while_control();
  test_if_then_else_control();
  printf("\n\n test try 1 \n\n");
  test_try_1();
  printf("\n\n test try 2 \n\n");
  test_try_3();
  printf("\n\n test try 2 \n\n");
  test_try_3();
 
}

#include "basic_control.h"
void test_basic_control(void)
{
 
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = basic_control_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 500, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}
#include "while_column.h"
void test_while_control(void)
{  
    
   
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = while_column_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 500, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "if_then_else.h"
void test_if_then_else_control(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = if_then_else_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 500, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "try_1.h"
void test_try_1(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = try_1_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 500, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "try_2.h"
void test_try_2(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = try_2_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 500, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "try_3.h"
void test_try_3(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = try_3_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 500, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}