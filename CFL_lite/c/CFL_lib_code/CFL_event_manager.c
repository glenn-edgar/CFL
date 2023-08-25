
#include <stddef.h>
#include "CFL_inner_engine.h"


 bool is_queue_empty_CFL(const void *input, unsigned queue_id){
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Event_control_RAM_CFL_t *event_control_ram =  handle->queue_ram+queue_id;
    return (event_control_ram->current_queued_number == 0);
 }

 bool is_queue_full(const void *input,unsigned queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
    unsigned number = event_control_rom->queue_size;
    Event_control_RAM_CFL_t *event_control_ram = handle->queue_ram+queue_id;
    return (event_control_ram->current_queued_number >= number);
 }
unsigned get_queue_number_CFL(const void *input,unsigned queue_id){
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
   Event_control_RAM_CFL_t *event_control_ram =  handle->queue_ram+queue_id;
   return event_control_ram->current_queued_number;

}

unsigned get_queue_max_size_CFL(const void *input,unsigned queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
    return event_control_rom->queue_size;
}

static inline void  clear_event_data(const void *input, unsigned i){
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input; 
  const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+i;
  
  Event_data_CFL_t *event_data_array = event_control_rom->event_data_array;
   unsigned number = event_control_rom->queue_size;
   for(unsigned i= 0;i<number;i++){
    free_event_CFL(input, &event_data_array[i]);
   }


}



void reset_event_queue_CFL(const void *input,unsigned queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Event_control_RAM_CFL_t *event_control_ram = ((Event_control_RAM_CFL_t*) handle->queue_ram)+queue_id;
    event_control_ram->rx_index = 0;
    event_control_ram->tx_index = 0;
    event_control_ram->current_queued_number = 0;
    clear_event_data(input, queue_id);

}

void enqueue_event_CFL(const void *input,unsigned queue_id, Event_data_CFL_t *event) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if (is_queue_full(input,queue_id)) {
    ASSERT_PRINT_INT("Queue is full",queue_id);
  }
  const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
  Event_control_RAM_CFL_t *event_control_ram = handle->queue_ram+queue_id;
  Event_data_CFL_t *event_data_array = event_control_rom->event_data_array;
  event_data_array[event_control_ram->tx_index] = *event;
  event_control_ram->current_queued_number++;
  event_control_ram->tx_index = event_control_ram->tx_index + 1;
  if(event_control_ram->tx_index >= event_control_rom->queue_size){
    event_control_ram->tx_index = 0;
  }
   
}

void queue_global_event_CFL(const void *input, Event_data_CFL_t *event) {
  enqueue_event_CFL(input,0,event);
}

void dequeue_event_CFL(const void *input,unsigned queue_id) {
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Event_data_CFL_t *event;

  if (is_queue_empty_CFL(input,queue_id)) {
    ASSERT_PRINT_INT("Queue is empty",queue_id);
  }
   
  const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
  Event_control_RAM_CFL_t *event_control_ram =  handle->queue_ram+queue_id;
  Event_data_CFL_t *event_data_array = event_control_rom->event_data_array;
  
  
  event = &event_data_array[event_control_ram->rx_index];
  free_event_CFL(input,event);
  
  event_control_ram->current_queued_number--;
  event_control_ram->rx_index = event_control_ram->rx_index + 1;
  if(event_control_ram->rx_index >= event_control_rom->queue_size){
    event_control_ram->rx_index = 0;
  }
}

Event_data_CFL_t *peak_event_CFL(const void *input,unsigned queue_id){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Event_data_CFL_t *event;

  if (is_queue_empty_CFL(input, queue_id)) {
    return NULL;
  }
  Event_control_RAM_CFL_t *event_control_ram =  handle->queue_ram+queue_id;
  const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
  Event_data_CFL_t *event_data_array = event_control_rom->event_data_array;

  event = &event_data_array[event_control_ram->rx_index];
  return event;
}

void free_event_CFL(const void *input, Event_data_CFL_t *event_data)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if (event_data->malloc_flag == true)
  {

    handle->free(handle, event_data->params);
    event_data->malloc_flag = false;
  }
}

void reset_all_queues(const void *input)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const unsigned number = handle->queue_number;
  for (unsigned i = 0; i < number; i++)
  {
    reset_event_queue_CFL(input, i);
  }
  
}