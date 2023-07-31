
#include "CFL_event_manager.h"
#include "CFL_user_functions.h"

bool is_queue_empty_CFL(Event_control_CFL_t *queue) {
    return queue->current_queued_number == 0;
}

bool is_queue_full(Event_control_CFL_t *queue) {
    return queue->current_queued_number == queue->max_number;
}

unsigned get_queue_number_CFL(Event_control_CFL_t *queue){
    return queue->current_queued_number;
}

unsigned get_queue_max_size_CFL(Event_control_CFL_t *queue){
    return queue->max_number;
}

Event_control_CFL_t *create_event_queue_CFL(void *handle, unsigned id,
                                            int max_number) {
  Event_control_CFL_t *queue = (Event_control_CFL_t *)Allocate_once_malloc_CFL(
      handle, sizeof(Event_control_CFL_t));
  initialize_event_data_CFL(handle, queue, id, max_number);
  return queue;
}

void initialize_event_data_CFL(void *handle, Event_control_CFL_t *queue,
                               unsigned id, unsigned max_number) {
  queue->id = id;
  queue->rx_index = 0;
  queue->tx_index = 0;
  queue->current_queued_number = 0;
  queue->max_number = max_number;
  queue->event_data_queue = (Event_data_CFL_t *)Allocate_once_malloc_CFL(
      handle, max_number * sizeof(Event_data_CFL_t));
}
 void reset_event_queue_CFL(Event_control_CFL_t *event_control){

  event_control->rx_index = 0;
  event_control->tx_index = 0;
  event_control->current_queued_number = 0;
 }

bool enqueue_event_CFL(Event_control_CFL_t *queue, Event_data_CFL_t *event) {
  if (is_queue_full(queue)) {
    return false;
  }

  queue->event_data_queue[queue->tx_index].event_index = event->event_index;
  queue->event_data_queue[queue->tx_index].event_data = event->event_data;
  queue->event_data_queue[queue->tx_index].params = event->params;
  queue->tx_index = (queue->tx_index + 1) % queue->max_number;
  queue->current_queued_number++;
  return true;
}

Event_data_CFL_t *dequeue_event_CFL(Event_control_CFL_t *queue) {
  if (is_queue_empty_CFL(queue)) {
    return NULL;
  }

  Event_data_CFL_t *event = &queue->event_data_queue[queue->rx_index];
  queue->rx_index = (queue->rx_index + 1) % queue->max_number;
  queue->current_queued_number--;
  return event;
}



Event_data_CFL_t *peak_event_CFL(Event_control_CFL_t *queue) {
  if (is_queue_empty_CFL(queue)) {
    return NULL;
  }

  return &queue->event_data_queue[queue->rx_index];
}