#ifndef __CFL_PIPE_SUPPORT_H__
#define __CFL_PIPE_SUPPORT_H__

#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_element_storeage.h"
#include "CFL_pipes.h"



typedef struct Column_control_t // Enable/Disable
{
    unsigned short column_number;
    unsigned short column_start;
} Column_control_CFL_t;

typedef struct If_column_control_t  // IF control
{
    unsigned short Column_number;
    unsigned short Column_start;
} If_Column_control_CFL_t;

typedef struct Loop_start_CFL_t // Loop control
{
    unsigned short loop_start;
    unsigned short loop_number;
    unsigned short current_loop;
} Loop_start_CFL_t;

typedef struct Loop_element_CFL_t  // loop pass
{
    unsigned short loop_start;
    unsigned short loop_number;

} Loop_element_CFL_t;

typedef struct Try_element_CFL_t // try control
{
    unsigned try_start;
    unsigned try_max_number;
    unsigned try_current_number;
    // add try status
} Try_element_CFL_t;



typedef struct Column_element_CFL_t
{
    bool free_flag;
    void *data_pointer;
} Column_element_CFL_t;

typedef struct Pipe_link_t
{
    unsigned short pipe_id;

} Pipe_link_t;

typedef union Pipe_element_CFL_t
{
    Column_control_CFL_t     column_control;
    If_Column_control_CFL_t  if_Column_control;
    Loop_start_CFL_t        loop_start;
    Loop_element_CFL_t       loop_index;
    Try_element_CFL_t       try_element;
    Column_element_CFL_t    column_element;
    Pipe_link_t             pipe_link;
} Pipe_element_CFL_t;

typedef struct Pipe_Slot_CFL_t
{ 
    unsigned short id;
    unsigned short type;
    unsigned short pipe_position;
    unsigned short next_block;
    Pipe_element_CFL_t pipe_element;

} Pipe_Slot_CFL_t;



typedef struct Pipe_stack_element_CFL_t
{
    unsigned short control_index; // index at the start of the
    unsigned short control_type;  // type of the control element

} Pipe_stack_element_CFL_t;

typedef struct Pipe_stack_CFL_t
{
    unsigned short current_level;
    unsigned short max_levels;
    Pipe_stack_element_CFL_t *pipe_stack_elements;
} Pipe_stack_CFL_t;

typedef struct Pipe_control_CFL_t
{
    unsigned short id;
    Pipe_stack_CFL_t *pipe_stack;
    unsigned short current_index;
    unsigned short max_number;
    Pipe_Slot_CFL_t *pipe_slots;
} Pipe_control_CFL_t;

typedef struct Pipe_pool_CFL_t
{
    unsigned short current_pipe_index;
    unsigned short number_of_pipes;
    Pipe_control_CFL_t *pipes;
    Hash_cell_control_CFL_t *names;
    
} Pipe_pool_CFL_t;

static inline Column_CFL_t *find_column_entry(void *input, unsigned column_id){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Column_control_CFL_t *column_control =(Column_control_CFL_t *) handle->columns;
    if(column_id >= column_control->max_number)
    {
        ASSERT_PRINT_F("ERROR: Column id %d is out of range\n", column_id);
        
    }
    return column_control->column_entries+column_id; 

}

static inline Column_CFL_t *get_current_column(void *input){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
   Engine_control_CFL_t *engine_control = (Engine_control_CFL_t *)handle->engine_control;
   return engine_control->current_column;

}

static inline set_column_pipe(void *input,Column_CFL_t *column, unsigned short pipe_id){
    if(column->pipe_active)
    {
        ASSERT_PRINT_F("ERROR: Pipe %s is already active\n", column->id);
        
    }
    column->pipe_active = true;
    column->pipe_index = pipe_id;
}

static inline clear_column_pipe(void *input,Column_CFL_t *column){
    if(!column->pipe_active)
    {
        ASSERT_PRINT_F("ERROR: Pipe %s is not active\n", column->id);
        
    }
    column->pipe_active = false;
    column->pipe_index = 0;
}

static inline unsigned  get_pipe_id(void *input, const char *pipe_name)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_pool_CFL_t *pipe_pool_control = (Pipe_pool_CFL_t *)handle->pipe_pool_control;
    return Find_Name_CFL(input, pipe_pool_control->names, pipe_name);    
}

static inline Pipe_control_CFL_t * get_pipe_control(void *input, unsigned short index)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_pool_CFL_t *pipe_pool_control = (Pipe_pool_CFL_t *)handle->pipe_pool_control;
    if(index >= pipe_pool_control->number_of_pipes)
    {
        ASSERT_PRINT_F("ERROR: Pipe index %d is out of range\n", index);
        
    }
    return pipe_pool_control->pipes+index;
}





#endif // __CFL_PIPE_SUPPORT_H__