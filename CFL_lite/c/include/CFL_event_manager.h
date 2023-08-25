#ifndef __CFL_EVENT_MANAGER_H__
#define __CFL_EVENT_MANAGER_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "CFL_basic_defs.h"


typedef struct Event_control_RAM_CFL_t
{
  unsigned short rx_index;
  unsigned short tx_index;
  unsigned short current_queued_number;
  
} Event_control_RAM_CFL_t;

typedef struct Event_control_ROM_CFL_t{ 

  const unsigned             queue_size;
  Event_data_CFL_t           *event_data_array;
} Event_control_ROM_CFL_t;





 bool is_queue_empty_CFL(const void *input, unsigned queue_id); 
 bool is_queue_full(const void *input,unsigned queue_id); 
unsigned get_queue_number_CFL(const void *input,unsigned queue_id);
unsigned get_queue_max_size_CFL(const void *input,unsigned queue_id);
void reset_event_queue_CFL(const void *input,unsigned queue_id);
void enqueue_event_CFL(const void *input,unsigned queue, Event_data_CFL_t *event); 
void dequeue_event_CFL(const void *input,unsigned queue_id);
Event_data_CFL_t *peak_event_CFL(const void *input,unsigned queue_id);
void queue_global_event_CFL(const void *input, Event_data_CFL_t *event);
void free_event_CFL(const void *input, Event_data_CFL_t * event_data);
void reset_all_queues(const void *input);

#ifdef __cplusplus
}
#endif
#endif