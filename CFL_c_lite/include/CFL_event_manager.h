#ifndef __CFL_EVENT_MANAGER_H__
#define __CFL_EVENT_MANAGER_H__


#include <stdbool.h>
#include "CFL_basic_defs.h"


typedef struct Event_control_RAM_CFL_t
{
  unsigned short rx_index;
  unsigned short tx_index;
  unsigned short current_queued_number;
} Event_control_RAM_CFL_t;

typedef struct Event_control_ROM_CFL_t{ 
  const unsigned                 number;
  const unsigned                start_index;
  
} Event_control_ROM_CFL_t;



typedef struct Named_event_queue_control_CFL_t
{
 
  const unsigned number;
  const unsigned queue_number;
  const Event_control_ROM_CFL_t  **event_queues;
} Named_event_queue_control_CFL_t;


 bool is_queue_empty_CFL(const void *input, unsigned queue_id); 
 bool is_queue_full(const void *input,unsigned queue_id); 
unsigned get_queue_number_CFL(const void *input,unsigned queue_id);
unsigned get_queue_max_size_CFL(const void *input,unsigned queue_id);
void reset_event_queue_CFL(const void *input,unsigned queue_id);
void enqueue_event_CFL(const void *input,unsigned queue, Event_data_CFL_t *event); 
Event_data_CFL_t *dequeue_event_CFL(const void *input,unsigned queue_id);
Event_data_CFL_t *peak_event_CFL(const void *input,unsigned queue_id);
void queue_global_event_CFL(const void *input, Event_data_CFL_t *event);

#endif