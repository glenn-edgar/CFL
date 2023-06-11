#include "Cfl_column_element.h"
#include "Cfl_functions.h"
#include "Cfl_local_heap_functions.h"
#include "Cfl_user_functions.h"


static void mark_id(int number, Column_element_CFL_t* pointer);

void allocate_column_elements_CFL(Handle_CFL_t* handle,
  int number_of_column_elements) {
  Column_element_control_CFL_t* column_element_control_ptr;
  
  column_element_control_ptr =
    (Column_element_control_CFL_t*)allocate_once_CFL(
      handle, sizeof(Column_element_control_CFL_t));
  column_element_control_ptr->max_number = number_of_column_elements;
  column_element_control_ptr->current_number = 0;
  handle->column_element = column_element_control_ptr;
  if(number_of_column_elements == 0){
    return;
  }
  column_element_control_ptr->column_element =
    (Column_element_CFL_t*)allocate_once_CFL(
      handle, sizeof(Column_element_CFL_t) * number_of_column_elements);
  mark_id(number_of_column_elements,
    column_element_control_ptr->column_element);
  
}

Column_element_CFL_t* allocate_column_element_CFL(Handle_CFL_t* handle) {
  Column_element_control_CFL_t* ptr;
  Column_element_CFL_t* return_value;
  ptr = (Column_element_control_CFL_t*)handle->column_element;
  if (ptr->current_number >= ptr->max_number - 1) {
    ASSERT_PRINT_INT("column element out of space", ptr->current_number);
  }
  return_value = ptr->column_element + ptr->current_number;
  ptr->current_number += 1;
  return return_value;
}

int free_column_elements_CFL(Handle_CFL_t* handle) {
  Column_element_control_CFL_t* ptr;

  ptr = (Column_element_control_CFL_t*)handle->column_element;
  return ptr->max_number - ptr->current_number;
}

static void mark_id(int cell_number, Column_element_CFL_t* pointer) {
  for (int i = 0; i < cell_number; i++) {
    pointer->id = i;
    pointer++;
  }
}
