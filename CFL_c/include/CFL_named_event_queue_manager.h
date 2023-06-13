#ifndef __CFL_NAMED_EVENT_QUEUE_MANAGER_H__
#define __CFL_NAMED_EVENT_QUEUE_MANAGER_H__

//#include "CFL_user_functions.h"
#include "CFL_definitions.h"

void allocate_named_event_queue_space_CFL( void *input, unsigned number );



unsigned named_event_reserve_one_shot_functions_CFL();
void named_events_load_one_shot_functions_CFL(void *input);

unsigned named_event_reserve_column_space_CFL();
void load_name_event_column_functions_CFL(void *input);

void Define_named_event_queue_CFL(void *input, const char *name, unsigned size );



/*
   RPC client functions

*/
#define RPC_HEADER_MAGIC 0xDEADBEEF
typedef struct RPC_message_header_CFL_t {
   bool           success;
   unsigned       magic;
   unsigned short event_id;
   unsigned short request_id;
   unsigned short client_queue_id;
   unsigned short server_queue_id;
   bool           client_free_message_data;
   unsigned short client_data_size;
   void*          client_message_data;
   bool           server_free_message_data;
   unsigned short server_data_size;
   void*          server_message_data;
} RPC_message_header_CFL_t;


void Asm_send_named_events_CFL(void *input, unsigned number,
                               const char **event_queue_names,
                               Event_data_CFL_t *event_data);


                                       

void Asm_reset_named_event_queues_CFL(void *input, unsigned number,
                                      const char **event_queue_names);
void Asm_wait_for_client_rpc_CFL(void *input, unsigned short rpc_event,
                                const char *message_handler, void *user_data);

void Asm_wait_for_server_rpc_CFL(void *input,unsigned short rpc_event,
                            const char *bool_function, void *user_data);

void Asm_dispose_rpc_event_CFL(void *input, unsigned short rpc_event,bool flag,const char *message_handler, void *user_data);

void Asm_send_rpc_CFL(void *input, unsigned short rpc_event_id, unsigned short rpc_request_id,
                      const char *client_queue_name, const char *server_queue_name,
                      bool client_free_message_data, unsigned short client_data_size, void *client_message_data);

                           
/************************************* Run Time Functions *********************************/
/*
   Named Event Queue Functions

*/

unsigned Get_named_event_queue_index_CFL(void *input, const char *name);






unsigned Get_named_event_queue_number_CFL(void *input, unsigned index); 



void Reset_named_event_queue_CFL(void* input, unsigned index);



#endif