
#include <unistd.h>
#include "test_allocation.h"
#include "test_functions.h"
#include "test_return_codes.h"
#include "test_while_verify.h"
#include "test_column_control.h"
#include "test_watch_dog.h"
#include "test_column_events.h"
#include "test_named_queue_functions.h"
#include "test_df_functions.h"
#include "test_tod_functions.h"
#include "test_data_flow_functions.h"

#include "unit_test_short_sexpr.h"


#include "unit_test_s_logical_operations.h"
#include "test_column_state_machine.h"



// #include "test_data_flow.h"

int main (void )
{

 //test_allocation();
 //test_functions();
 //test_column_return_codes();
 //test_while_verify();
 printf("starting\n");
 //test_watch_dog();
 //test_tod_functions();
 //test_data_flow_functions();
 test_column_state_machine();
#if 0
  // test pipes
  // test statemacines
  // test s expressions ?
  test_column_control();
  test_chain_events();
  //test_named_queue_functions();
 // test_df_functions();
#endif  
}


