#ifndef __CFL_EVENT_MANAGER_H__
#define __CFL_EVENT_MANAGER_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "CFL_basic_defs.h"


typedef struct Event_control_RAM_CFL_t
{
  uint16_t rx_index;
  uint16_t tx_index;
  uint16_t current_queued_number;
  uint16_t push_number;
} Event_control_RAM_CFL_t;

typedef struct Event_control_ROM_CFL_t{ 

  const uint16_t            queue_size;
  Event_data_CFL_t           *event_data_array;
  const uint16_t             push_queue_size;
  Event_data_CFL_t           *push_array_data;
} Event_control_ROM_CFL_t;





 bool is_queue_empty_CFL(const void *input, uint16_t queue_id); 
 bool is_queue_full_CFL(const void *input,uint16_t queue_id); 
uint16_t get_queue_number_CFL(const void *input,uint16_t queue_id);
uint16_t get_queue_max_size_CFL(const void *input,uint16_t queue_id);
void reset_event_queue_CFL(const void *input,uint16_t queue_id);
void reset_current_event_queue_CFL(const void *input);
void enqueue_event_CFL(const void *input,uint16_t queue, Event_data_CFL_t *event); 
void enqueue_column_event_CFL(const void *input,uint16_t queue_id, Event_data_CFL_t *event);
void front_enqueue_event_CFL(const void *input, Event_data_CFL_t *event);
void dump_event_push_array_CFL(const void *input, uint16_t column_index);

void front_enqueue_column_index_event_CFL(const void *input, uint16_t column_index, Event_data_CFL_t *event);
void dequeue_event_CFL(const void *input,uint16_t queue_id);
Event_data_CFL_t *peak_event_CFL(const void *input,uint16_t queue_id);
void queue_global_event_CFL(const void *input, Event_data_CFL_t *event);
void free_event_CFL(const void *input, Event_data_CFL_t * event_data);
void reset_all_queues(const void *input);

#ifdef __cplusplus
}
#endif
#endif