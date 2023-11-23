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



void float_maps_1(void);



int main()

{
  printf("\n\ntest bit_maps \n\n");
  float_maps_1();
  
  
 
}


#include "float_maps_1.h"
void  float_maps_1(void)
{  
    
 
 
   create_allocate_once_heap(); // create allocate once heap

   const Handle_CFL_t *handle = float_map_1_handle();
   Initialize_engine_CFL(handle);
   Start_engine_CFL(handle, 10, default_idle_function, default_calendar_function);
   free_allocate_once_heap(); // free allocate once heap
 
   printf("Engine is done \n");
}


