#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_element_storeage.h"
#include "CFL_pipes.h"

;

typedef struct Chain_control_t
{
    unsigned short chain_number;
    unsigned short chain_start;
} Chain_control_CFL_t;
typedef struct If_chain_control_t
{
    unsigned short chain_number;
    unsigned short chain_start;
} If_chain_control_CFL_t;

typedef struct Loop_start_CFL_t
{
    unsigned short loop_start;
    unsigned short loop_number;
    unsigned short current_loop;
} Loop_start_CFL_t;

typedef struct Loop_element_CFL_t
{
    unsigned short loop_start;
    unsigned short loop_number;

} Loop_element_CFL_t;

typedef struct Try_start_CFL_t
{
    unsigned try_start;
    unsigned try_max_number;
    unsigned try_current_number;
} Try_start_CFL_t;

typedef struct Try_end_CLF_t
{
    bool success;
    bool inverse_flag;
    // TBD

} Try_end_CFL_t;

typedef struct Chain_element_CFL_t
{
    void *data_pointer;
} Chain_element_CFL_t;

typedef union Pipe_element_CFL_t
{
    Chain_control_CFL_t chain_control;
    If_chain_control_CFL_t if_chain_control;
    Loop_start_CFL_t loop_start;
    Loop_element_CFL_t loop_element;
    Try_start_CFL_t try_start;
    Try_end_CFL_t try_end;
    Chain_element_CFL_t chain_element;
} Pipe_element_CFL_t;

typedef struct Pipe_Slot_CFL_t
{
    unsigned short type;
    unsigned short pipe_position;
    unsigned short next_block;
    Pipe_element_CFL_t pipe_element;

} Pipe_Slot_CFL_t;

typedef struct Column_pipe_index_CFL_t
{
    bool active;
    unsigned short pipe_id;

} Column_pipe_index_CFL_t;

typedef struct Column_pipe_control_CFL_t
{
    unsigned short number_of_columns;
    Column_pipe_index_CFL_t *column_pipe_index;
} Column_pipe_control_CFL_t;

typedef struct Pipe_stack_element_CFL_t
{
    unsigned short control_index; // type of the control block
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
    Pipe_stack_CFL_t pipe_stack;
    unsigned short current_index;
    unsigned short max_number;
    Pipe_Slot_CFL_t *pipe_slots;
    unsigned short number_of_columns;
    Column_pipe_index_CFL_t *column_pipe_index;
} Pipe_control_CFL_t;

typedef struct Pipe_pool_CFL_t
{
    unsigned short current_pipe_index;
    unsigned short number_of_pipes;
    unsigned short number_of_columns;
    Pipe_control_CFL_t *pipes;
    Hash_cell_control_CFL_t *names;

} Pipe_pool_CFL_t;

static unsigned short get_pipe_id_CFL(void *input, const char *pipe_name);
static unsigned short get_column_pipe_index(void* input);
static void set_column_pipe_index_CFL(void *input, unsigned short column_id, unsigned short pipe_id);
static int walk_data_pipe(void *input, void *fn_aux, void *params, Event_data_CFL_t *event_data);
static void store_column_data(void *input, void *params, Event_data_CFL_t *event_data);
static void initialize_pipe_column_index_CFL(void *input, unsigned short number_of_columns,
                                             Column_pipe_index_CFL_t *column_pipe_index);
static void start_data_pipe(void *input, void *params, Event_data_CFL_t *event_data);
static void reset_data_pipe(void *input, void *params, Event_data_CFL_t *event_data);

/*


*/

unsigned reserve_pipe_control_column_functions_CFL()
{
    return 0;
}

void register_pipe_control_column_functions_CFL(void *input)
{
    Store_column_function_CFL(input,"WALK_DATA_PIPE", walk_data_pipe);
}

unsigned reserve_pipe_control_one_shot_functions_CFL(void *input)
{
    return 3;
}

void register_pipe_control_one_shot_functions_CFL(void *input)
{
    Store_one_shot_function_CFL(input, "START_DATA_PIPE", start_data_pipe);
    Store_one_shot_function_CFL(input,"RESET_DATA_PIPE",reset_data_pipe);
    Store_one_shot_function_CFL(input,"STORE_COLUMN_DATA_CRL",store_column_data);
}

unsigned reserve_pipe_control_boolean_functions_CFL(void *input)
{
    return 1;
}

void register_pipe_control_boolean_functions_CFL(void *input)
{

    ;
}

void intialize_pipe_control_CFL(void *input, unsigned short number_of_pipes, unsigned number_of_columns)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_pool_CFL_t *pipe_pool = (Pipe_pool_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Pipe_pool_CFL_t));
    pipe_pool->number_of_pipes = number_of_pipes;
    pipe_pool->current_pipe_index = 0;

    pipe_pool->pipes = (Pipe_control_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Pipe_control_CFL_t) * number_of_pipes);
    pipe_pool->names = (Hash_cell_control_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Hash_cell_control_CFL_t) * number_of_pipes);

    pipe_pool->number_of_columns = number_of_columns;
    handle->pipe_pool_control = pipe_pool;
}

void Create_pipe_control_CFL(void *input, const char *pipe_name, unsigned number_of_levels, unsigned short number_of_slots)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_pool_CFL_t *pipe_pool = (Pipe_pool_CFL_t *)handle->pipe_pool_control;
    if (pipe_pool->current_pipe_index >= pipe_pool->number_of_pipes)
    {
        ASSERT_PRINT_INT("Pipe Pool exceeded", pipe_pool->current_pipe_index);
    }
    unsigned short pipe_id = (unsigned short)Store_Name_CFL(pipe_pool->names, pipe_name);
    if (pipe_id != pipe_pool->current_pipe_index)
    {
        ASSERT_PRINT_INT("Pipe id is not equal to current pipe index", pipe_id);
    }
    pipe_pool->current_pipe_index++;
    Pipe_control_CFL_t *pipe_control = (Pipe_control_CFL_t *)pipe_pool->pipes+pipe_id;
    pipe_control->id = pipe_id;
    initializialize_pipe_stack_CFL(input, number_of_levels, pipe_control->pipe_stack);
    pipe_control->pipe_slots = (Pipe_Slot_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Pipe_Slot_CFL_t) * number_of_slots);
    pipe_control->max_number = number_of_slots;
    pipe_control->current_index = 0;
    pipe_control->number_of_columns = pipe_pool->number_of_columns;
    initialize_pipe_column_index_CFL(input, pipe_control->number_of_columns, pipe_control->column_pipe_index);

    
}



typedef struct start_data_pipe
{
    unsigned short pipe_id;
} start_data_pipe_t;

void Asm_start_data_pipe_CFL(void *input, const char *pipe_name)
{
    start_data_pipe_t *start_data_pipe = (start_data_pipe_t *)(input, sizeof(start_data_pipe_t));
    start_data_pipe->pipe_id = get_pipe_id_CFL(input, pipe_name);
    Asm_one_shot_CFL(input, "START_DATA_PIPE", pipe_name);
}

/*
   One shot implementation for "START_DATA_PIPE"
*/
static void start_data_pipe(void *input, void *params, Event_data_CFL_t *event_data)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Engine_control_CFL_t *engine_control = (Engine_control_CFL_t *)handle->engine_control;
    Column_CFL_t *column = (Column_CFL_t *)engine_control->current_column;
    unsigned short column_id = column->id;
    start_data_pipe_t *start_data_pipe = (start_data_pipe_t *)params;
    set_column_pipe_index_CFL(input, column_id, start_data_pipe->pipe_id);
}

void Asm_reset_data_pipe_CFL(void *input, const char *pipe_name)
{

    Asm_one_shot_CFL(input, "RESET_DATA_PIPE", NULL);
}

/*
   One shot implementation for "RESET_DATA_PIPE"
*/
static void reset_data_pipe(void *input, void *params, Event_data_CFL_t *event_data)
{

    unsigned short pipe_id = get_column_pipe_index(input);
    Reset_pipe_CFL(input, pipe_id);
}
typedef struct walk_data_pipe
{
    unsigned short pipe_id;
    void *walk_function;
    void *user_data;
    Pipe_Slot_CFL_t *pipe_slot;
} walk_data_pipe_t;


void Asm_walk_data_pipe_CFL(void *input, const char *pipe_name, const char *reduce_function, void *user_data)
{
    walk_data_pipe_t *parameters = (walk_data_pipe_t *)Allocate_once_malloc_CFL(input, sizeof(walk_data_pipe_t));
    parameters->pipe_id = (input, pipe_name);
    parameters->walk_function = Get_bool_function_CFL(input, reduce_function);
    parameters->user_data = user_data;
    parameters->pipe_slot = NULL;
    Asm_store_column_element_CFL(input, "WALK_DATA_PIPE", (void *)fn, (void *)parameters);
}

/*
   One shot implementation for "WALK_DATA_PIPE"
*/
static int walk_data_pipe(void *input, const void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
    if (event_data->event_index != EVENT_INIT_CFL)
    {

        Handle_CFL_t *handle = (Handle_CFL_t *)input;
        walk_data_pipe_t *parameters = (walk_data_pipe_t *)params;
        unsigned short pipe_id = parameters->pipe_id;
        Pipe_pool_CFL_t *pipe_pool_control = (Pipe_pool_CFL_t *)handle->pipe_pool_control;
        Pipe_control_CFL_t *pipe_control = (Pipe_control_CFL_t *)pipe_pool_control->pipes[pipe_id];
        for (unsigned short i = 0; i < pipe_control->current_index; i++)
        {
            Pipe_Slot_CFL_t pipe_slot = pipe_control->pipe_slots[i];

            parameters->pipe_slot = pipe_slot;
            if (!walk_function(input,parameters,event_data))
            {
                break;
            }
        }
    }
    return DISABLE_CFL
}

void Asm_pipe_store_column_data_CFL(void *input, void *data)
{
    Asm_one_shot_CFL(input, "STORE_COLUMN_DATA_CRL", data);
}

// one shot implementation for "STORE_PIPE_DATA_PTR"

static void store_column_data(void *input, void *params, Event_data_CFL_t *event_data)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    // get column index
    // find pipe element
    // if pipe set data ptr to the column element
}

/*
   C runtime functions these commands work in the background when column control functions are called

*/
void Create_chain_control_CFL(void *input, unsigned short chain_number, unsigned short chain_start)
{
    ;
}

void Verify_chain_control_end_CFL(void *input)
{
    ;
}

void Create_if_chain_control_CFL(void *input, unsigned short chain_number, unsigned short chain_start)
{
    ;
}

void Create_loop_start_CFL(void *input, unsigned short loop_start, unsigned short loop_number)
{
    ;
}

void Create_loop_element_CFL(void *input, unsigned short loop_start, unsigned short loop_number)
{
    ;
}

void Create_try_start_CFL(void *input, unsigned short try_start, unsigned short try_max_number)
{
    ;
}

void Create_try_end_CFL(void *input, bool success, bool inverse_flag)
{
    ;
}

void Create_chain_element_CFL(void *input)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    // get column index
    // if pipe is active
    // store pipe element
    // set pipe data pointer to NULL
}

/*
   static utility functions

*/

static unsigned short get_pipe_id_CFL(void *input, const char *pipe_name)
{

    ; // TBD
}

static unsigned short get_column_pipe_index(void *input)
{
    //Column_CFL_t *column = (Column_CFL_t *)get_column_index(input);

}

static void set_column_pipe_index_CFL(void *input, unsigned short column_id, unsigned short pipe_id)
{
    ; // TBD
}
