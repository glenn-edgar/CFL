
#include "Cfl_definitions.h"
#include "Cfl_user_functions.h"
#include "test_interface_functions.h"

static void test_storing_functions(void* input);
static void test_retrieving_functions(void* input);

static bool test_boolean_function(void* handle, void* params,
  Event_data_CFL_t* event_data);
static void test_if_function(void* handle, If_control_CFL_t* params);
static int test_column_function(void* handle, void* aux_fun, void* params,
  Event_data_CFL_t* event_data);
static void test_one_shot(void* handle, void* params,
  Event_data_CFL_t* event_data);
static void test_try_function(void* handle, Try_column_CFL_t* params);

void test_functions() {


  Handle_config_CFL_t* config_handle = Create_config_handle_CFL(debug_write);
  
 


 
  

  config_handle->number_of_columns = 30;
  config_handle->number_of_column_elements = 300;

  config_handle->number_column_functions = 100;
  config_handle->number_bool_functions = 50;
  config_handle->number_if_functions = 50;
  config_handle->one_shot_functions = 50;
  config_handle->number_of_try_functions = 50;
   config_handle->debug_out = debug_write;


  void *input = Configure_engine_CFL(config_handle, 50000, 4000);

   Printf_CFL("test_functions");



  test_storing_functions(input);
  test_retrieving_functions(input);

   

  Destroy_engine_CFL(input);
  free(config_handle);
   
}

static void test_storing_functions(void* input) {

  Store_bool_function_CFL(input, "test_boolean_functions",
    test_boolean_function);
  Store_if_function_CFL(input, "test_if_functions", test_if_function);
  Store_column_function_CFL(input, "test_column_functions",
    test_column_function);
  Store_one_shot_function_CFL(input, "test_one_shoot", test_one_shot);
  Store_try_function_CFL(input, "test_try", test_try_function);
}

static Bool_function_CFL_t bool_function;
static If_function_CFL_t if_function;
static Column_function_CFL_t column_function;
static One_shot_function_CFL_t one_shot_function;
static Try_function_CFL_t try_function;

static void test_retrieving_functions(void* input) {

  bool_function = Get_bool_function_CFL(input, "test_boolean_functions");
  if_function = Get_if_function_CFL(input, "test_if_functions");
  column_function = Get_column_function_CFL(input, "test_column_functions");
  one_shot_function = Get_one_shot_function_CFL(input, "test_one_shoot");
  try_function = Get_try_function_CFL(input, "test_try");
   
   Printf_CFL("test ptr %p %p \n", bool_function, test_boolean_function);
  
   Printf_CFL("test ptr  %p %p \n", if_function, test_if_function);
  
   Printf_CFL("test ptr  %p %p \n", column_function, test_column_function);
  ;
  Printf_CFL ("test ptr  %p %p \n", one_shot_function, test_one_shot);
  
  Printf_CFL("test ptr  %p %p \n", test_try_function, try_function);
}

static bool test_boolean_function(void* handle, void* params,
  Event_data_CFL_t* event_data) {

  (void)handle;
  (void)params;
  (void)event_data;
  return true;
}

static void test_if_function(void* handle, If_control_CFL_t* params) {
  (void)handle;
  (void)params;
}

static int test_column_function(void* handle, void * aux_fun, void* params,
  Event_data_CFL_t* event_data) {
  (void)handle;
  (void)params;
  (void)event_data;
  (void)aux_fun;
  return CONTINUE_CFL;
}
static void test_one_shot(void* handle, void* params,
  Event_data_CFL_t* event_data) {
  (void)handle;
  (void)params;
  (void)event_data;
}
static void test_try_function(void* handle, Try_column_CFL_t* params) {
  (void)handle;
  (void)params;
}
