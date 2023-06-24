#ifndef __CFL_ASM_EVENTS_H__
#define __CFL_ASM_EVENTS_H__

// These are functions that allow for manipulation of events

// primary use is for statae machine use
void Asm_redirect_event_CFL(void *input, char *boolean_fn_name, void *user_data, unsigned short queue_number,
                           const char **queue_names, unsigned short number_of_events, unsigned short *event_ids);


/*
 note fn_name is a column function name


*/

void Asm_attach_event_handler_CFL(void* input, short event_index, const char* col_fn_name, void* user_data);

/*
   same as Asn_attach_event_handler_CFL except it allows for multiple events to be attached to the same function
*/

void Asm_attach_multi_event_handler_CFL(void* input, unsigned number, const short* event_index, const char* fn_name, void* user_data);

void Asm_filter_events_CFL(void *input, const char *event_handler_name,
                           unsigned event_number, short *event_values,
                           bool block_flag,  void *user_data);

#endif // __CLF_ASM_EVENTS_H__