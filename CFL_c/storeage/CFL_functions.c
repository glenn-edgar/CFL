

#include "Cfl_core_aux_functions.h"
#include "Cfl_core_functions.h" 
#include "Cfl_data_flow_functions.h"
#include "Cfl_definitions.h"
#include "Cfl_element_storeage.h"
#include "Cfl_functions.h"
#include "Cfl_local_heap_functions.h"
#include "CFL_column_state_machine.h"
#include "CFL_named_event_queue_manager.h"
#include "Cfl_user_functions.h"

typedef struct Column_Function_t {
  int number;
  int max_number;
  Hash_cell_control_CFL_t *function_names;
  Column_function_CFL_t *functions;
} Column_Function_t;

typedef struct Bool_Function_t {
  int number;
  int max_number;
  Hash_cell_control_CFL_t *function_names;
  Bool_function_CFL_t *functions;

} Bool_Function_t;

typedef struct If_Function_t {
  int number;
  int max_number;
  Hash_cell_control_CFL_t *function_names;
  If_function_CFL_t *functions;

} If_Function_t;

typedef struct One_Shot_Function_t {
  int max_number;
  int number;
  Hash_cell_control_CFL_t *function_names;
  One_shot_function_CFL_t *functions;

} One_Shot_Function_t;

typedef struct Try_Function_t {
  int max_number;
  int number;
  Hash_cell_control_CFL_t *function_names;
  Try_function_CFL_t *functions;

} Try_Function_t;

typedef struct Function_Control_t {
  Column_Function_t column_element_functions;
  If_Function_t if_functions;
  Bool_Function_t bool_functions;
  One_Shot_Function_t one_shot_functions;
  Try_Function_t try_functions;

} Function_Control_t;

static void allocate_column_functions(Handle_CFL_t *handle,
                                      Function_Control_t *function_control,
                                      int number);
static void allocate_bool_functions(Handle_CFL_t *handle,
                                    Function_Control_t *function_control,
                                    int number);
static void allocate_if_functions(Handle_CFL_t *handle,
                                  Function_Control_t *function_control,
                                  int number);
static void allocate_one_shot_functions(Handle_CFL_t *handle,
                                        Function_Control_t *function_control,
                                        int number);
static void allocate_try_functions(Handle_CFL_t *handle,
                                   Function_Control_t *function_control,
                                   int number);

void allocate_function_space_CFL(void *input, int number_column_functions,
                                 int number_bool_functions,
                                 int number_if_functions,
                                 int number_one_shot_functions,
                                 int number_of_try_functions){
  
  Handle_CFL_t *handle = (Handle_CFL_t *)input;

  
  number_column_functions += reserve_column_function_space_CFL();
  number_column_functions += reserve_df_column_function_space_CFL();
  number_column_functions += reserve_column_sm_function_space_CFL();
  number_column_functions += named_event_reserve_column_space_CFL();
  Function_Control_t*control = (Function_Control_t *)Allocate_once_malloc_CFL(handle,sizeof(Function_Control_t));
  allocate_column_functions(handle, control, number_column_functions);


 
  number_bool_functions += reserve_bool_function_space_CFL();
  number_bool_functions += reserve_df_bool_function_space_CFL();
  allocate_bool_functions(handle, control, number_bool_functions);
  
  
  number_if_functions += reserve_if_function_space_CFL();
  allocate_if_functions(handle, control, number_if_functions);

  
  number_one_shot_functions += reserve_one_shot_function_space_CFL();
  number_one_shot_functions += reserve_df_one_shot_function_space_CFL();
  number_one_shot_functions += reserve_column_sm_one_shot_function_space_CFL();
  number_one_shot_functions += named_event_reserve_one_shot_functions_CFL();
  allocate_one_shot_functions(handle, control, number_one_shot_functions);

  
  number_of_try_functions += reserve_try_function_space_CFL();
  allocate_try_functions(handle, control, number_of_try_functions);

  handle->functions = control;

  load_column_functions_CFL(handle);
  load_df_column_functions_CFL(handle);
  load_name_event_column_functions_CFL(handle);

  load_one_shot_function_state_CFL(handle);
  load_df_one_shot_function_state_CFL(input);
  named_events_load_one_shot_functions_CFL(handle);
 
  load_bool_functions_CFL(input);
  load_df_bool_functions_CFL(input);
  
  
  load_if_functions_CFL(input);

  load_try_functions_CFL(input);
}
/*
  all the other functions have builtin functions to assure a number greater than
  zero

*/

static void allocate_try_functions(Handle_CFL_t *handle,
                                   Function_Control_t *function_control,
                                   int number) {
  function_control->try_functions.max_number = number;
  function_control->try_functions.number = 0;
  if (number > 0) {
    function_control->try_functions.function_names =
        contruct_hash_cell_control_CFL(handle, number);
    function_control->try_functions.functions =
        (Try_function_CFL_t *)allocate_once_CFL(
            handle, sizeof(Try_function_CFL_t) * number);
  } else {
    function_control->try_functions.function_names = NULL;
    function_control->try_functions.functions = NULL;
  }
}

static void allocate_column_functions(Handle_CFL_t *handle,
                                      Function_Control_t *function_control,
                                      int number) {
  function_control->column_element_functions.number = 0;
  function_control->column_element_functions.max_number = number;
  if(number == 0){return;}
  function_control->column_element_functions.function_names =
      contruct_hash_cell_control_CFL(handle, number);
  function_control->column_element_functions.functions =
      (Column_function_CFL_t *)allocate_once_CFL(
          handle, sizeof(Column_function_CFL_t) * number);
}

static void allocate_bool_functions(Handle_CFL_t *handle,
                                    Function_Control_t *function_control,
                                    int number) {
  function_control->bool_functions.number = 0;
  function_control->bool_functions.max_number = number;
  if(number == 0){return;}
  function_control->bool_functions.function_names =
      contruct_hash_cell_control_CFL(handle, number);
  function_control->bool_functions.functions =
      (Bool_function_CFL_t *)allocate_once_CFL(
          handle, sizeof(Bool_function_CFL_t) * number);
}

static void allocate_if_functions(Handle_CFL_t *handle,
                                  Function_Control_t *function_control,
                                  int number) {
  function_control->if_functions.max_number = number;
  function_control->if_functions.number = 0;
  if(number == 0){return;}
  function_control->if_functions.function_names =
      contruct_hash_cell_control_CFL(handle, number);
  function_control->if_functions.functions =
      (If_function_CFL_t *)allocate_once_CFL(
          handle, sizeof(If_function_CFL_t *) * number);
}

static void allocate_one_shot_functions(Handle_CFL_t *handle,
                                        Function_Control_t *function_control,
                                        int number) {
  function_control->one_shot_functions.max_number = number;
  function_control->one_shot_functions.number = 0;
  if(number == 0){return;}
  function_control->one_shot_functions.function_names =
      contruct_hash_cell_control_CFL(handle, number);
  function_control->one_shot_functions.functions =
      (One_shot_function_CFL_t *)allocate_once_CFL(
          handle, sizeof(One_shot_function_CFL_t) * number);
}

void Store_try_function_CFL(void *input, const char *name,
                            Try_function_CFL_t function) {
  Handle_CFL_t *handle;
  Try_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->try_functions;
  if (control.number >= control.max_number) {
    ASSERT_PRINT_INT("Error: too many try functions\n", control.number);
  }
  control.number += 1;
  int id = Store_Name_CFL(control.function_names, name);
  *(control.functions + id) = function;
}

void Store_bool_function_CFL(void *input, const char *name,
                             Bool_function_CFL_t function) {
  Handle_CFL_t *handle;
  Bool_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->bool_functions;
  if (control.number >= control.max_number) {
    ASSERT_PRINT_INT("Error: too many try functions\n", control.number);
  }
  control.number += 1;
  int id = Store_Name_CFL(control.function_names, name);
  *(control.functions + id) = function;
}

void Store_if_function_CFL(void *input, const char *name,
                           If_function_CFL_t function) {
  Handle_CFL_t *handle;
  If_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->if_functions;
  if (control.number >= control.max_number) {
    ASSERT_PRINT_INT("Error: too many try functions\n", control.number);
  }
  control.number += 1;
  int id = Store_Name_CFL(control.function_names, name);
  *(control.functions + id) = function;
}

void Store_column_function_CFL(void *input, const char *name,
                               Column_function_CFL_t function) {
  Handle_CFL_t *handle;
  Column_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->column_element_functions;
  if (control.number >= control.max_number) {
    ASSERT_PRINT_INT("Error: too many try functions\n", control.number);
  }
  control.number += 1;
  int id = Store_Name_CFL(control.function_names, name);
  *(control.functions + id) = function;
}

void Store_one_shot_function_CFL(void *input, const char *name,
                                 One_shot_function_CFL_t function) {
  Handle_CFL_t *handle;
  One_Shot_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->one_shot_functions;
  if (control.number >= control.max_number) {
    ASSERT_PRINT_INT("Error: too many try functions\n", control.number);
  }
  control.number += 1;
  int id = Store_Name_CFL(control.function_names, name);
  *(control.functions + id) = function;
}

Try_function_CFL_t Get_try_function_CFL(void *input, const char *name) {
  Handle_CFL_t *handle;
  Try_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->try_functions;
  int id = Find_Name_CFL(control.function_names, name);
  if (id < 0) {
    ASSERT_PRINT("try function does not exist ", name);
  }
  return *(control.functions + id);
}
Bool_function_CFL_t Get_bool_function_CFL(void *input, const char *name) {
  Handle_CFL_t *handle;
  Bool_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->bool_functions;
  int id = Find_Name_CFL(control.function_names, name);
  if (id < 0) {
    ASSERT_PRINT("bool function does not exist ", name);
  }
  return *(control.functions + id);
}

If_function_CFL_t Get_if_function_CFL(void *input, const char *name) {
  Handle_CFL_t *handle;
  If_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->if_functions;
  int id = Find_Name_CFL(control.function_names, name);
  if (id < 0) {
    ASSERT_PRINT("if function does not exist ", name);
  }
  return *(control.functions + id);
}

Column_function_CFL_t Get_column_function_CFL(void *input, const char *name) {
  Handle_CFL_t *handle;
  Column_Function_t control;
  Function_Control_t *function_control;

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->column_element_functions;
  int id = Find_Name_CFL(control.function_names, name);
  if (id < 0) {
    ASSERT_PRINT("column function does not exist ", name);
  }
  return *(control.functions + id);
}

One_shot_function_CFL_t Get_one_shot_function_CFL(void *input,
                                                  const char *name) {
  Handle_CFL_t *handle;
  One_Shot_Function_t control;
  Function_Control_t *function_control;

  if (name == NULL) {
    name = "NULL";
  }

  handle = (Handle_CFL_t *)input;

  function_control = (Function_Control_t *)handle->functions;
  control = function_control->one_shot_functions;
  int id = Find_Name_CFL(control.function_names, name);
  if (id < 0) {
    ASSERT_PRINT("One shot function does not exist ", name);
  }
  return *(control.functions + id);
}
