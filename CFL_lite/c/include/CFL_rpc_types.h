#ifndef __CFL_RPC_TYPES_H__
#define __CFL_RPC_TYPES_H__

#include "CFL_basic_defs.h"

typedef struct rpc_ram_message_t
{    

  Event_data_CFL_t sent_event;
  Event_data_CFL_t received_event;
} rpc_ram_message_CFL_t;


typedef struct rpc_rom_message_t
{
  unsigned short    rpc_request_id;
  unsigned short    unique_id;  // insuring that rpc message is valid
  unsigned short    destination_queue;
  unsigned short    receieved_queue;
  rpc_ram_message_CFL_t *ram_message;
} rpc_rom_message_CFL_t;

#define RPC_MESSAGE_ID_CFL 0x4321
#define RPC_EVENT_CFL 0x1234

typedef void (*Generate_RPC_event_CFL_t )(const void *input,void *params, rpc_rom_message_CFL_t *data);
typedef void (*Client_Process_RPC_event_CFL_t )(const void *input,void *params, rpc_rom_message_CFL_t *data);
typedef void (*Server_Process_RPC_event_CFL_t )(const void *input,void *user_data, rpc_rom_message_CFL_t *data);

#endif // __CFL_RPC_TYPES_H__