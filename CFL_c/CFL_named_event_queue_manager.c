#include "CFL_named_event_queue_manager.h"
#include "CFL_definitions.h"
#include "CFL_event_manager.h"
#include "CFL_user_functions.h"
#include "Cfl_element_storeage.h"

typedef struct Named_event_queue_control_CFL_t {
  unsigned max_number;
  unsigned number;
  Hash_cell_control_CFL_t *names;
  Event_control_CFL_t *event_queues;
} Named_event_queue_control_CFL_t;

void allocate_named_event_queue_space_CFL(Handle_CFL_t *handle,
                                          unsigned number) {

  Named_event_queue_control_CFL_t *named_event_queue_control;

  named_event_queue_control =
      (Named_event_queue_control_CFL_t *)Allocate_once_malloc_CFL(
          handle, sizeof(Named_event_queue_control_CFL_t));

  named_event_queue_control->number = 0;
  named_event_queue_control->max_number = number;

  if (number > 0) {
    named_event_queue_control->names =
        contruct_hash_cell_control_CFL(handle, number);
    named_event_queue_control->event_queues =
        (Event_control_CFL_t *)Allocate_once_malloc_CFL(
            handle, sizeof(Event_control_CFL_t) * number);
  } else {
    named_event_queue_control->names = NULL;
    named_event_queue_control->event_queues = NULL;
  }
  handle->named_event_queue = named_event_queue_control;
}

void Asm_create_named_event_queue_CFL(void *input, const char *name, unsigned size ) {
  Handle_CFL_t *handle;
  Named_event_queue_control_CFL_t *named_event_control;
  Event_control_CFL_t *event_control;
  int id;

  
  handle = (Handle_CFL_t *)input;
  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
  if (named_event_control->number >= named_event_control->max_number ) {
    ASSERT_PRINT_INT("Too many named event queues",
                     named_event_control->number);
  }
  
 
  named_event_control->number += 1;
  id = Store_Name_CFL(named_event_control->names, name);
  event_control = named_event_control->event_queues+id;
  initialize_event_data_CFL(handle, event_control, id, size);
}

unsigned Get_named_event_queue_index_CFL(void *input, const char *name) {
  Handle_CFL_t *handle;
  int          return_value;
  Named_event_queue_control_CFL_t *named_event_control;
  //Event_control_CFL_t *event_control_queue;

  handle = (Handle_CFL_t *)input;
  

  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
 // event_control_queue = named_event_control->event_queues;
  return_value =  Find_Name_CFL(named_event_control->names, name);
  if(return_value < 0 ){
    ASSERT_PRINT(__func__, "Name not found");
  }
  return return_value;
}

Event_control_CFL_t *Get_named_event_queue_CFL(void *input, unsigned index) {
  Handle_CFL_t *handle;
  Named_event_queue_control_CFL_t *named_event_control;
  Event_control_CFL_t *event_control_queue;

  handle = (Handle_CFL_t *)input;
  named_event_control =
      (Named_event_queue_control_CFL_t *)handle->named_event_queue;
  if (index >= named_event_control->number) {
    ASSERT_PRINT_INT( "Name Queue Index too large", index);
  }
  event_control_queue = named_event_control->event_queues;
  return &event_control_queue[index];
}

void Send_named_event_CFL(void *handle, unsigned index,
                          Event_data_CFL_t *event_data) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
 
  if( enqueue_event_CFL(event_control, event_data) == false){
    ASSERT_PRINT(__func__, "Queue full");
  }
}

Event_data_CFL_t *Get_named_event_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return dequeue_event_CFL(event_control);
}

Event_data_CFL_t *Peak_named_event_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return peak_event_CFL(event_control);
}

unsigned Get_named_event_queue_number_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return get_queue_number_CFL(event_control);
}
Event_data_CFL_t *Pop_named_event_CFL(void *handle, unsigned index) {
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  return dequeue_event_CFL(event_control);
}

void Reset_named_event_queue_CFL(void* handle, unsigned index){
  Event_control_CFL_t *event_control;
  event_control = Get_named_event_queue_CFL(handle, index);
  reset_event_queue_CFL(event_control);
}