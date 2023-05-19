#ifndef __CFL_EVENT_MANAGER_H__
#define __CFL_EVENT_MANAGER_H__

#include "CFL_user_functions.h"
#include "CFL_definitions.h"

 bool is_queue_empty_CFL(Event_control_CFL_t *queue); 
 bool is_queue_full(Event_control_CFL_t *queue); 
unsigned get_queue_number_CFL(Event_control_CFL_t *queue);
unsigned get_queue_max_size_CFL(Event_control_CFL_t *queue);

Event_control_CFL_t *create_event_queue_CFL(void *handle,unsigned id, int max_number);

void initialize_event_data_CFL(void *handle, Event_control_CFL_t *queue, unsigned id, unsigned max_number);


void reset_event_queue_CFL(Event_control_CFL_t *event_control);



bool enqueue_event_CFL(Event_control_CFL_t *queue, Event_data_CFL_t *event); 

Event_data_CFL_t *dequeue_event_CFL(Event_control_CFL_t *queue);

Event_data_CFL_t *peak_event_CFL(Event_control_CFL_t *queue);

void destroy_event_queue_CFL(Event_control_CFL_t *queue); 

#endif