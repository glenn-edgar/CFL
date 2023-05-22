#ifndef __CFL_definitions_H__
#define __CFL_definitions_H__

#include "Cfl_user_functions.h"
#include "Cfl_priority_queue.h"

typedef struct Handle_CFL_t
{
    unsigned master_heap_size;
    void *master_heap_starting_location;
    char *current_heap_location;
    unsigned remaining_heap_size;
    void *private_heap;
    unsigned private_heap_size;
    void *columns;
    void *column_element;
    void *event_element;
    void *token_element;
    void *functions;
    void *engine_control;

    void *named_event_queue;

    void *ref_column;
    void *time_control;

    void *user_extension;
    void *io_extension;
    void *delay_function;
    void *df_buf_control;
    void *sm_dictionary;
    void *state_dictionary;
    void *pipe_control;
    // used for building state machines
    bool sm_assembly;
    unsigned short sm_control_index;


} Handle_CFL_t;

typedef struct Hash_cell_CFL_t
{
    short link;
    short id;
    int hash;
    int secondary_hash;
   


} Hash_cell_CFL_t;

typedef struct Hash_cell_control_CFL_t
{

    unsigned short max_number;
    unsigned short current_number;
    Hash_cell_CFL_t *cell_array;
    int *hash_table;
} Hash_cell_control_CFL_t;

typedef struct Private_heap_element_t
{
    struct Private_Heap_Element *link;
    int size;
    void *data;

} Private_heap_element_t;

typedef struct Private_heap_control_t
{

    int number;
    Private_heap_element_t *private_heap;

} Private_heap_control_t;

typedef struct Column_element_CFL_t
{
    unsigned short id;
    unsigned  active:1;
    unsigned  initialized:1;
    Column_function_CFL_t fn;
    void *aux_function;
    void *params;

} Column_element_CFL_t;

typedef struct Column_element_control_CFL_t
{
    unsigned short max_number;
    unsigned short current_number;
    Column_element_CFL_t *column_element;

} Column_element_control_CFL_t;

typedef struct Column_CFL_t
{
    unsigned short             id;
    unsigned short                      column_element_number;
    
    unsigned                       defined:1;
    unsigned                       auto_start:1;
    unsigned                       active:1;
    unsigned                       fn_success:1;
    unsigned                   reset_state:1;   // whether column is in reset state
   
    Column_element_CFL_t* starting_column_element;
   
    Event_data_CFL_t* local_event;
    
    Event_control_CFL_t* named_event_queue;
    Column_watch_dog_CFL_t* watch_dog_control;
   
} Column_CFL_t;

typedef struct Column_control_CFL_t
{
    unsigned short max_number;
    unsigned short current_number;
    
   
    Node_control_CFL_t node_control;
    Node_cell_CFL_t *node_cell;
     Hash_cell_control_CFL_t *column_names;
    Column_CFL_t *column;
} Column_control_CFL_t;

struct Engine_control_CFL_t;

typedef struct Engine_control_CFL_t
{

    Time_control_CFL_t time_control;
    Event_control_CFL_t event_control;
    Idle_function_CFL_t idle_function;
    Calendar_function_CFL_t calendar_function;
    Column_CFL_t *current_column;
    Column_element_CFL_t *current_column_element;
    unsigned current_column_index;
    unsigned current_column_element_index;
    Event_control_CFL_t local_events;
    Event_data_CFL_t ref_event_data;
} Engine_control_CFL_t;

typedef struct one_shot_function_ref
{
    const char *name;
    One_shot_function_CFL_t fn;

} one_shot_function_ref;

typedef struct bool_function_ref
{
    const char *name;
    Bool_function_CFL_t fn;

} bool_function_ref;

typedef struct core_function_ref
{
    const char *name;
    Column_function_CFL_t fn;

} core_function_ref;

#endif