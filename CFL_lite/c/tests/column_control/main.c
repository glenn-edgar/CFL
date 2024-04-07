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
void supervisor_test(void);
void assert_column_test(void);
void try_test(void);
void sequence_test(void);
void assert_column_flag_test(void);
void chain_column_sequence_test(void);
void chain_column_chain_test(void);

int main()
{
  printf("\n\n test column control \n\n");
#if 0
  test_basic_control();
  test_while_control();
  test_if_then_else_control();
  supervisor_test();
  sequence_test();
  try_test();
  assert_column_test();
  assert_column_flag_test();

  chain_column_sequence_test();
#endif
  chain_column_chain_test();
  
}

#include "basic_control.h"
void test_basic_control(void)
{
 
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = basic_control_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}
#include "while_column.h"
void test_while_control(void)
{  
    
   printf("\n\n test while control \n\n");
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = while_column_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "if_then_else.h"
void test_if_then_else_control(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = if_then_else_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "supervisor.h"
void supervisor_test(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = supervisor_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 50, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}



#include "sequence.h"
void sequence_test(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = sequence_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 50, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}


#include "try.h"
void try_test(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = try_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 50, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}


#include "assert_column.h"
void assert_column_test(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = assert_column_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 50, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "assert_column_flag.h"

void assert_column_flag_test(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = assert_column_flag_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 50, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "chain_column_sequence.h"
void chain_column_sequence_test(void) {


   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = chain_column_sequence_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 50, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "chain_column_case.h"
void chain_column_chain_test(void) {


   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = chain_column_case_handle();
   Initialize_heap_CFL(handle);
   Initialize_engine_CFL(handle, 50, default_idle_function, default_calendar_function);
   Start_engine_CFL(handle);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}