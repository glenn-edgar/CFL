#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CFL_inner_engine.h"
#include "test_interface.h"
#include "test_script.h"




int main() {


  
  const Handle_CFL_t *handle = Get_handle_CFL();
  Initialize_engine_CFL(handle);
  Start_engine_CFL(handle,500,default_idle_function,default_calendar_function);
 
}



