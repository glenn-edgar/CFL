
#include <stddef.h>
#include "CFL_inner_engine.h"



void free_Rpc_data_CFL(const void *input, Rpc_data_CFL_t *rpc_data)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if (rpc_data->input_malloc_flag == true)
  {

    handle->free(handle, rpc_data->input);
    rpc_data->input_malloc_flag = false;
  }
  if (rpc_data->output_malloc_flag == true)
  {

    handle->free(handle, rpc_data->output);
    rpc_data->output_malloc_flag = false;
  }
  rpc_data->input = NULL;
  rpc_data->output = NULL;
  rpc_data->input_data_size = 0;
  rpc_data->output_data_size = 0;
}


static inline void  clear_RPC_Packet_data(const void *input, unsigned queue_id){
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input; 
  const RPC_Packet_control_ROM_CFL_t *RPC_control_rom = handle->rpc_queue_rom+queue_id;
  
  Rpc_data_CFL_t *RPC_Packet_data_array = RPC_control_rom->Rpc_data;
   unsigned number = RPC_control_rom->queue_size;
   for(unsigned i= 0;i<number;i++){
    free_Rpc_data_CFL(input, &RPC_Packet_data_array[i]);
   }
}

void reset_rpc_queue_CFL(const void *input,unsigned queue_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    RPC_Packet_control_RAM_CFL_t *RPC_ram = (RPC_Packet_control_RAM_CFL_t*) handle->rpc_queue_ram+queue_id;
    RPC_ram->rx_index = 0;
    RPC_ram->tx_index = 0;
    RPC_ram->current_queued_number = 0;
    clear_RPC_Packet_data(input, queue_id);

}


void reset_all_rpc_packet_queues_CFL(const void *input){

  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  const unsigned number = handle->rpc_queue_number;
  for (unsigned i = 0; i < number; i++)
  {
    reset_rpc_queue_CFL(input, i);
  }
  
}

 bool is_rpc_queue_empty_CFL(const void *input, unsigned queue_id){
   const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const unsigned number = handle->rpc_queue_number;
    if (queue_id >= number)
    {
      ASSERT_PRINT_INT(input,"Queue id is invalid",queue_id);
    }
  
    RPC_Packet_control_RAM_CFL_t *RPC_Packet_control_ram =  handle->rpc_queue_ram+queue_id;
    
    if (RPC_Packet_control_ram->current_queued_number == 0)
    {
      return true;
    }
    
    return false;
    
 }

 bool is_rpc_queue_full_CFL(const void *input,unsigned queue_id){
     const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const unsigned number = handle->rpc_queue_number;
    if (queue_id >= number)
    {
      ASSERT_PRINT_INT(input,"Queue id is invalid",queue_id);
    }
  
    RPC_Packet_control_RAM_CFL_t *RPC_Packet_control_ram =  handle->rpc_queue_ram+queue_id;
    const RPC_Packet_control_ROM_CFL_t *RPC_Packet_control_rom = handle->rpc_queue_rom+queue_id;
    if(RPC_Packet_control_ram->current_queued_number >= RPC_Packet_control_rom->queue_size){
      return true;
    }
    return false;

 }

unsigned get_rpc_queue_number_CFL(const void *input,unsigned queue_id){
     const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const unsigned number = handle->rpc_queue_number;
    if (queue_id >= number)
    {
      ASSERT_PRINT_INT(input,"Queue id is invalid",queue_id);
    }
  
    RPC_Packet_control_RAM_CFL_t *RPC_Packet_control_ram =  handle->rpc_queue_ram+queue_id;
  
    return RPC_Packet_control_ram->current_queued_number;
   

}

unsigned get_rpc_queue_max_size_CFL(const void *input,unsigned queue_id){
     const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const unsigned number = handle->rpc_queue_number;
    if (queue_id >= number)
    {
      ASSERT_PRINT_INT(input,"Queue id is invalid",queue_id);
    }
  
    
    const RPC_Packet_control_ROM_CFL_t *RPC_Packet_control_rom = handle->rpc_queue_rom+queue_id;
    return RPC_Packet_control_rom->queue_size;
   
 }

void enqueue_rpc_request_CFL(const void *input,uint16_t queue_id, uint16_t rpc_id, uint16_t *data_length, void *data, bool malloc_flag )  {
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if(is_rpc_queue_full_CFL(input,queue_id) == true){
    ASSERT_PRINT_INT(input,"Queue is full",queue_id);
  }
  const RPC_Packet_control_ROM_CFL_t *RPC_Packet_control_rom = handle->rpc_queue_rom+queue_id;
  RPC_Packet_control_RAM_CFL_t *RPC_Packet_control_ram =  handle->rpc_queue_ram+queue_id;
  Rpc_data_CFL_t *RPC_Packet_data_array = RPC_Packet_control_rom->Rpc_data;
  Rpc_data_CFL_t *rpc_data = &RPC_Packet_data_array[RPC_Packet_control_ram->tx_index];
  rpc_data->rpc_id = rpc_id;
  rpc_data->input_data_size = *data_length;
  rpc_data->input = data;
  rpc_data->input_malloc_flag = malloc_flag;
  RPC_Packet_control_ram->current_queued_number++;
  RPC_Packet_control_ram->tx_index = RPC_Packet_control_ram->tx_index + 1;
  if(RPC_Packet_control_ram->tx_index >= RPC_Packet_control_rom->queue_size){
    RPC_Packet_control_ram->tx_index = 0;
  }
  
   
}


void dequeue_Rpc_data_CFL(const void *input, uint16_t queue_id) {
 const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if(is_rpc_queue_empty_CFL(input,queue_id) == true){
    ASSERT_PRINT_INT(input,"Queue is empty",queue_id);
  }
  const RPC_Packet_control_ROM_CFL_t *RPC_Packet_control_rom = handle->rpc_queue_rom+queue_id;
  RPC_Packet_control_RAM_CFL_t *RPC_Packet_control_ram =  handle->rpc_queue_ram+queue_id;
  Rpc_data_CFL_t *RPC_Packet_data_array = RPC_Packet_control_rom->Rpc_data;
  Rpc_data_CFL_t *rpc_data = &RPC_Packet_data_array[RPC_Packet_control_ram->rx_index];
  free_Rpc_data_CFL(input, rpc_data);
  RPC_Packet_control_ram->current_queued_number--;
  RPC_Packet_control_ram->rx_index = RPC_Packet_control_ram->rx_index + 1;
  if(RPC_Packet_control_ram->rx_index >= RPC_Packet_control_rom->queue_size){
    RPC_Packet_control_ram->rx_index = 0;
  }
  
}

 Rpc_data_CFL_t *peak_rpc_data_CFL(const void *input,uint16_t queue_id){
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  if(is_rpc_queue_empty_CFL(input,queue_id) == true){
    ASSERT_PRINT_INT(input,"Queue is empty",queue_id);
  }
  
   const RPC_Packet_control_ROM_CFL_t *RPC_Packet_control_rom = handle->rpc_queue_rom+queue_id;
  RPC_Packet_control_RAM_CFL_t *RPC_Packet_control_ram =  handle->rpc_queue_ram+queue_id;
  Rpc_data_CFL_t *RPC_Packet_data_array = RPC_Packet_control_rom->Rpc_data;
  Rpc_data_CFL_t *rpc_data = &RPC_Packet_data_array[RPC_Packet_control_ram->rx_index];
  return rpc_data;
}



