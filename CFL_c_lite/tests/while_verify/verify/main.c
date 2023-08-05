#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "CFL_inner_engine.h"
#include "test_interface.h"

#include "test_script.h"




int main() {


  
  const Handle_CFL_t *handle = test_entry_point();
  Initialize_engine_CFL(handle);
  Start_engine_CFL(handle,10,default_idle_function,default_calendar_function);
  printf("Engine is done");
}



