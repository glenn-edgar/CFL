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



void test_delay_wait(void);
void test_wait_event_pass(void);
void test_wait_event_reset(void);
void test_wait_event_terminate(void);
void test_while_user_function(void);
void test_verify(void);

int main()
{
  printf("\n\n testing delay wait \n\n");
  test_delay_wait();
  printf("\n\n testing wait event pass \n\n");
  test_wait_event_pass();
  printf("\n\n testing wait event reset \n\n");
  test_wait_event_reset();
  printf("\n\n testing wait event terminate \n\n");
  test_wait_event_terminate();
  printf("\n\n testing while user function \n\n");
  test_while_user_function();  
  printf("\n\n testing verify \n\n");
  test_verify();

 
}

#include "delay_wait.h"
void test_delay_wait(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = delay_wait_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "wait_event_pass.h"

void test_wait_event_pass(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = wait_event_pass_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "wait_event_reset.h"

void test_wait_event_reset(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = wait_event_reset_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "wait_event_terminate.h"

void test_wait_event_terminate(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = wait_event_terminate_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}

#include "while_user_function.h"

void test_while_user_function(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = while_user_function_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}
#include "verify.h"
void test_verify(void)
{
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = verify_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}