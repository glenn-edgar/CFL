#ifndef __CFL_RPC_PACKETS_H__
#define __CFL_RPC_PACKETS_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "CFL_basic_defs.h"

typedef struct Rpc_data_CFL_t
{
  uint16_t receiver_queue;
  uint16_t rpc_id;
  bool     input_malloc_flag;
  uint16_t input_data_type;
  void    *input;
  bool     output_malloc_flag;
  uint16_t output_data_type;
  void   *output;
} Rpc_data_CFL_t;



typedef struct RPC_Packet_control_RAM_CFL_t
{
  unsigned short rx_index;
  unsigned short tx_index;
  unsigned short current_queued_number;
  
} RPC_Packet_control_RAM_CFL_t;

typedef struct RPC_Packet_control_ROM_CFL_t{ 

  const unsigned        queue_size;
  Rpc_data_CFL_t        *Rpc_data;
} RPC_Packet_control_ROM_CFL_t;





 bool is_rpc_queue_empty_CFL(const void *input, unsigned queue_id); 
 bool is_rpc_queue_full_CFL(const void *input,unsigned queue_id); 
unsigned get_rpc_queue_number_CFL(const void *input,unsigned queue_id);
unsigned get_rpc_queue_max_size_CFL(const void *input,unsigned queue_id);
void reset_rpc_queue_CFL(const void *input,unsigned queue_id);

void enqueue_rpc_request_CFL(const void *input,uint16_t queue_id,uint16_t receiver_queue, uint16_t rpc_id, uint16_t data_type, void *data, bool malloc_flag );
void return_rpc_event_CFL(const void *input,int16_t receiver_queue, Rpc_data_CFL_t *rpc_event);
void dequeue_Rpc_data_CFL(const void *input, uint16_t queue_id);
Rpc_data_CFL_t *peak_rpc_data_CFL(const void *input,uint16_t queue_id);
void free_Rpc_data_CFL(const void *input, Rpc_data_CFL_t * RPC_data);
void reset_all_rpc_packet_queues_CFL(const void *input);

#ifdef __cplusplus
}
#endif
#endif