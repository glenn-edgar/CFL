#ifndef __CFL_NAMED_EVENT_QUEUE_MANAGER_H__
#define __CFL_NAMED_EVENT_QUEUE_MANAGER_H__

//#include "CFL_user_functions.h"
#include "CFL_definitions.h"

void allocate_named_event_queue_space_CFL( void *input, unsigned number );



unsigned named_event_reserve_one_shot_functions_CFL();
void named_events_load_one_shot_functions(void *input);

void Define_named_event_queue_CFL(void *input, const char *name, unsigned size );


void Asm_send_named_events_CFL(void* input, unsigned number, const char** event_queue_names, Event_data_CFL_t* event_data);

void Asm_send_named_events_fn_CFL(void* input, unsigned number, const char** event_queue_names, const char* event_function, void* user_data);

void Asm_reset_named_event_queues_CFL(void* input, unsigned number, const char** name);


void Asm_wait_for_rpc_CFL(void *input,unsigned short rpc_event,const char *message_handler, void *user_data);
void Asm_send_rpc_bad_response_CFL(void *input, short rpc_event);
void Asm_send_receive_rpc_CFL(void* input,unsigned short rpc_event, const char *message_handler, void *message_user_data,
      const char *failure_handler, void *failure_user_data, short time_out, bool termination_flag);
                           
/************************************* Run Time Functions *********************************/
/*
   Named Event Queue Functions

*/

unsigned Get_named_event_queue_index_CFL(void *input, const char *name);






unsigned Get_named_event_queue_number_CFL(void *input, unsigned index); 



void Reset_named_event_queue_CFL(void* input, unsigned index);



#endif