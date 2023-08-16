
#include <stddef.h>
#include "CFL_inner_engine.h"


 bool is_queue_empty_CFL(const void *input, unsigned queue_id){
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Event_control_RAM_CFL_t *event_control_ram = ((Event_control_RAM_CFL_t*) handle->queue_ram)+queue_id;
    return (event_control_ram->current_queued_number == 0);
 }
 bool is_queue_full(const void *input,unsigned queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Named_event_queue_control_CFL_t *event_control = (Named_event_queue_control_CFL_t *)handle->queue_rom;
    const Event_control_ROM_CFL_t *event_control_rom = event_control->event_queues[queue_id];
    unsigned number = event_control_rom->number;
     Event_control_RAM_CFL_t *event_control_ram = ((Event_control_RAM_CFL_t*) handle->queue_ram)+queue_id;
    return (event_control_ram->current_queued_number >= number);
 }
unsigned get_queue_number_CFL(const void *input,unsigned queue_id){
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
   Event_control_RAM_CFL_t *event_control_ram = ((Event_control_RAM_CFL_t*) handle->queue_ram)+queue_id;
  return (event_control_ram->current_queued_number);

}

unsigned get_queue_max_size_CFL(const void *input,unsigned queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Named_event_queue_control_CFL_t *event_control = (Named_event_queue_control_CFL_t *)handle->queue_rom;
    const Event_control_ROM_CFL_t *event_control_rom = event_control->event_queues[queue_id];
    return (event_control_rom->number);
}

void initialize_event_data_array_CFL(const void *input){
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  Event_data_CFL_t *event_data_array = (Event_data_CFL_t *)handle->event_data;
  Named_event_queue_control_CFL_t *event_control = (Named_event_queue_control_CFL_t *)handle->queue_rom;
  unsigned number = event_control->number;
  for(unsigned i = 0; i < number; i++){
    event_data_array[i].params = NULL;
    event_data_array[i].event_index = 0; 
    event_data_array[i].malloc_flag = false;
  }
}

void reset_event_queue_CFL(const void *input,unsigned queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Named_event_queue_control_CFL_t *event_control = (Named_event_queue_control_CFL_t *)handle->queue_rom;
    const Event_control_ROM_CFL_t *event_control_rom = event_control->event_queues[queue_id];
    Event_control_RAM_CFL_t *event_control_ram = ((Event_control_RAM_CFL_t*) handle->queue_ram)+queue_id;
    Event_data_CFL_t *event_data_array = (Event_data_CFL_t *)handle->event_data;
    unsigned start_index = event_control_rom->start_index;
    unsigned number = event_control_rom->number;
    for(unsigned i = start_index; i < number; i++){
      if(event_data_array[start_index + i].malloc_flag == true){
        handle->free(handle,event_data_array[start_index + i].params);
      }
      
    }
    event_control_ram->rx_index = 0;
    event_control_ram->tx_index = 0;
    event_control_ram->current_queued_number = 0;

}
void enqueue_event_CFL(const void *input,unsigned queue_id, Event_data_CFL_t *event) {
  if (is_queue_full(input,queue_id)) {
    ASSERT_PRINT_INT("Queue is full",queue_id);
  }
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const Named_event_queue_control_CFL_t *event_control = handle->queue_rom;
  const Event_control_ROM_CFL_t *event_control_rom = event_control->event_queues[queue_id];
  Event_control_RAM_CFL_t *event_control_ram = handle->queue_ram+queue_id;
  Event_data_CFL_t *event_data_array = (Event_data_CFL_t *)handle->event_data;
  event_data_array[event_control_ram->tx_index] = *event;
  event_control_ram->tx_index = (event_control_ram->tx_index + 1);
  event_control_ram->current_queued_number++;
  if(event_control_ram->tx_index == event_control_rom->start_index + event_control_rom->number){
    event_control_ram->tx_index = event_control_rom->start_index;
  }
   

}

void queue_global_event_CFL(const void *input, Event_data_CFL_t *event) {
  enqueue_event_CFL(input,0,event);
}

Event_data_CFL_t *dequeue_event_CFL(const void *input,unsigned queue_id) {
  Event_data_CFL_t *event;
  if (is_queue_empty_CFL(input,queue_id)) {
    return NULL;
  }
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
  const Named_event_queue_control_CFL_t *event_control = handle->queue_rom;
  const Event_control_ROM_CFL_t *event_control_rom = event_control->event_queues[queue_id];
  Event_control_RAM_CFL_t *event_control_ram =  handle->queue_ram+queue_id;
  Event_data_CFL_t *event_data_array = handle->event_data;
  
  
  event = &event_data_array[event_control_ram->rx_index];
  event_control_ram->rx_index += 1;
  event_control_ram->current_queued_number--;
  if(event_control_ram->rx_index == event_control_rom->start_index + event_control_rom->number){
    event_control_ram->rx_index = event_control_rom->start_index;
  }
  return event;
}

Event_data_CFL_t *peak_event_CFL(const void *input,unsigned queue_id){
   Event_data_CFL_t *event;
  if (is_queue_empty_CFL(input, queue_id)) {
    return NULL;
  }
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
 
  Event_control_RAM_CFL_t *event_control_ram = ((Event_control_RAM_CFL_t*) handle->queue_ram)+queue_id;
  Event_data_CFL_t *event_data_array = (Event_data_CFL_t *)handle->event_data;
 
  
  event = &event_data_array[event_control_ram->rx_index];
  return event;
}
