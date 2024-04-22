
#include <stddef.h>
#include "CFL_inner_engine.h"


 bool is_queue_empty_CFL(const void *input, uint16_t queue_id){
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Event_control_RAM_CFL_t *event_control_ram =  handle->queue_ram+queue_id;
    
    if (event_control_ram->current_queued_number == 0)
    {
      return true;
    }
    
    return false;
    
 }



 bool is_queue_full_CFL(const void *input,uint16_t queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
    uint16_t number = event_control_rom->queue_size;
    Event_control_RAM_CFL_t *event_control_ram = handle->queue_ram+queue_id;
    return (event_control_ram->current_queued_number >= number);
 }
uint16_t get_queue_number_CFL(const void *input,uint16_t queue_id){
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
   Event_control_RAM_CFL_t *event_control_ram =  handle->queue_ram+queue_id;
   return event_control_ram->current_queued_number;

}

uint16_t get_queue_max_size_CFL(const void *input,uint16_t queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
    return event_control_rom->queue_size;
}

static inline void  clear_event_data(const void *input, uint16_t i){
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input; 
  const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+i;
  
  Event_data_CFL_t *event_data_array = event_control_rom->event_data_array;
   uint16_t number = event_control_rom->queue_size;
   for(uint16_t i= 0;i<number;i++){
    free_event_CFL(input, &event_data_array[i]);
   }


}

void reset_current_event_queue_CFL(const void *input){
  reset_event_queue_CFL(input, get_current_column_index_CFL(input));
}


void reset_event_queue_CFL(const void *input,uint16_t queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    Event_control_RAM_CFL_t *event_control_ram = ((Event_control_RAM_CFL_t*) handle->queue_ram)+queue_id;
    event_control_ram->rx_index = 0;
    event_control_ram->tx_index = 0;
    event_control_ram->current_queued_number = 0;
    event_control_ram->push_number = 0;
    clear_event_data(input, queue_id);

}

void enqueue_event_CFL(const void *input,uint16_t queue_id, Event_data_CFL_t *event) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if (is_queue_full_CFL(input,queue_id)) {
    ASSERT_PRINT_INT(input,"Queue is full",queue_id);
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

void enqueue_column_event_CFL(const void *input,uint16_t queue_id, Event_data_CFL_t *event) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  
  uint16_t column_id = queue_id - 1;
  if( get_column_state_CFL( input, column_id  ) == false){
    return; // do not store inactivated column
  }
  if (is_queue_full_CFL(input,queue_id)) {
    ASSERT_PRINT_INT(input,"Queue is full",queue_id);
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

void front_enqueue_event_CFL(const void *input, Event_data_CFL_t *event) {

 
  front_enqueue_column_index_event_CFL(input, get_current_column_index_CFL(input), event);
 
  
}


void front_enqueue_column_index_event_CFL(const void *input, uint16_t column_index, Event_data_CFL_t *event) {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  uint16_t queue_id = column_index + 1;
  const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
  Event_control_RAM_CFL_t *event_control_ram = handle->queue_ram+queue_id;
  Event_data_CFL_t *event_data_array = event_control_rom->push_array_data;
  if(event_control_ram->push_number < event_control_rom->push_queue_size){
    *(event_data_array+event_control_ram->push_number) = *event;
    event_control_ram->push_number +=1;
   
  }else{
    ASSERT_PRINT_INT(input,"Push Queue is full",queue_id)
  }
 
}

void dump_event_push_array_CFL(const void *input, uint16_t column_index){
 
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  uint16_t queue_id = column_index + 1;
  const Event_control_ROM_CFL_t *event_control_rom = handle->queue_rom+queue_id;
  Event_control_RAM_CFL_t *event_control_ram = handle->queue_ram+queue_id;
  Event_data_CFL_t *event_data_array = event_control_rom->push_array_data;
 
  for(int16_t i =  event_control_ram->push_number-1;i >= 0; i--){
        enqueue_column_event_CFL(input,queue_id,event_data_array+i); 
  }
  event_control_ram->push_number = 0;
}
 


void queue_global_event_CFL(const void *input, Event_data_CFL_t *event) {
  enqueue_event_CFL(input,0,event);
}

void dequeue_event_CFL(const void *input,uint16_t queue_id) {
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Event_data_CFL_t *event;

  if (is_queue_empty_CFL(input,queue_id)) {
    
    return;
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

Event_data_CFL_t *peak_event_CFL(const void *input,uint16_t queue_id){
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
  const uint16_t number = handle->queue_number;
  for (uint16_t i = 0; i < number; i++)
  {
    reset_event_queue_CFL(input, i);
  }
  
}