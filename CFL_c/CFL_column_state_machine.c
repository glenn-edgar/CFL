#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_column_state_machine.h"

static int process_event_groups(void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);
static void change_column_state_CFL(void *input, void *params, Event_data_CFL_t *event_data);
static bool match_events(unsigned short event_number, short *event_indexes, short event_index);
static short filter_return_code(short return_code);
/*

    Event handler is a boolean function
    false -- let event go through column
    true --  block event

*/
typedef struct process_event_t_CFL
{
    unsigned short event_number;
    short          *event_indexes;
    bool block_flag;
    short return_value;
    void *user_data;
} process_event_t_CFL;

unsigned reserve_column_sm_function_space_CFL(void)
{
    return 1;
}

unsigned reserve_column_sm_one_shot_function_space_CFL(void)
{
    return 1;
}

void Initialize_column_state_machine_CFL(void *input){
  Store_column_function_CFL(input, "PROCESS_EVENTS", process_event_groups);
  Store_one_shot_function_CFL(input, "CHANGE_COLUMN_STATE", change_column_state_CFL);
}






void Asm_process_event_CFL(void *input, const char *event_handler_name,
                           unsigned event_number, short *event_values,
                           bool block_flag, short return_value, void *user_data)
{
    process_event_t_CFL *process_event = (process_event_t_CFL *)Allocate_once_malloc_CFL(input, sizeof(process_event_t_CFL));
    process_event->event_number = event_number;
    process_event->event_indexes = (short *)Allocate_once_malloc_CFL(input, sizeof(short) * event_number);
    for (unsigned i = 0; i < event_number; i++)
    {
        process_event->event_indexes[i] = event_values[i];
    }
    process_event->block_flag = block_flag;
    process_event->user_data = user_data;
    process_event->return_value = filter_return_code(return_value);
    One_shot_function_CFL_t event_handler = Get_one_shot_function_CFL(input, event_handler_name);
    Asm_store_column_element_CFL(input, "PROCESS_EVENTS", event_handler, process_event);
}

void Asm_synch_event_change_state_CFL(void *input, unsigned event_number, short *event_values, unsigned change_state)
{
    unsigned short *new_state = Allocate_once_malloc_CFL(input, sizeof(unsigned short));
    *new_state = change_state;
    Asm_process_event_CFL(input, "CHANGE_COLUMN_STATE", event_number, event_values, true, COLUMN_STATE_CHANGE_CFL, new_state);
}

void Asm_synch_event_CFL(void *input, unsigned event_number, short *event_values)
{

    Asm_process_event_CFL(input, "NULL", event_number, event_values, true, DISABLE_CFL, NULL);
}


void Asm_change_column_state_CFL(void *input, unsigned new_state){

   ; // tbd

}



static int process_event_groups(void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
    process_event_t_CFL *process_event = (process_event_t_CFL *)params;
    One_shot_function_CFL_t event_handler = (One_shot_function_CFL_t)aux_fn;
  
   
    switch (event_data->event_index)
    {
    case EVENT_INIT_CFL:
        event_handler(input, process_event, event_data);
        return CONTINUE_CFL;
        break;
    case EVENT_TERMINATION_CFL:; // do nothing for now
        event_handler(input, process_event, event_data);
        return CONTINUE_CFL;
        break;

    default:
        if (match_events(process_event->event_number, process_event->event_indexes, event_data->event_index) == false)
        {
            if (process_event->block_flag == true)
            {
                return HALT_CFL;
            }
            return CONTINUE_CFL;
        }
        // match at this point
        event_handler(input, process_event, event_data);
        return process_event->return_value;
    } // switch

    return CONTINUE_CFL; // should never get here
}

static void change_column_state_CFL(void *input, void *params, Event_data_CFL_t *event_data)
{
    process_event_t_CFL *process_event = (process_event_t_CFL *)params;

    if (event_data->event_index != EVENT_TERMINATION_CFL)
    {
        unsigned short *new_state = (unsigned short *)process_event->user_data;
        Change_local_column_state_CFL(input, *new_state);
    }
}

static bool match_events(unsigned short event_number, short *event_indexes, short event_index)
{

    for (unsigned i = 0; i < event_number; i++)
    {
        if (event_indexes[i] == event_index)
        {
            return true;
        }
    }
    return false;
}

static short filter_return_code(short return_code)
{
    switch (return_code)
    {
    case CONTINUE_CFL:
    case DISABLE_CFL:
    case HALT_CFL:
    case RESET_CFL:
    case TERMINATE_CFL:
    case ENGINE_TERMINATE_CFL:
    case COLUMN_STATE_CHANGE_CFL:
        break;

    default:
        ASSERT_PRINT_INT("Invalid return code", return_code);
    }
    return return_code;
}