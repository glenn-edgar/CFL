#include "CFL_pipe_support.h"
#include "CFL_pipes.h"

static void start_data_pipe(void *input, void *params, Event_data_CFL_t *event_data);

typedef struct start_data_pipe
{
    unsigned short pipe_id;
} start_data_pipe_t;

void Asm_start_data_pipe_CFL(void *input, const char *pipe_name)
{
    start_data_pipe_t *start_data_pipe = (start_data_pipe_t *)Allocate_once_malloc_CFL(input, sizeof(start_data_pipe_t));
    start_data_pipe->pipe_id = get_pipe_id_CFL(input, pipe_name);
    Asm_one_shot_CFL(input, "START_DATA_PIPE", start_data_pipe);
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
    set_column_pipe(input,column->id, start_data_pipe->pipe_id);
    
}
  


void Asm_reset_data_pipe_CFL(void *input, const char *pipe_name)
{
    start_data_pipe_t *start_data_pipe = (start_data_pipe_t *)Allocate_once_malloc_CFL(input, sizeof(start_data_pipe_t));
    start_data_pipe->pipe_id = get_pipe_id_CFL(input, pipe_name);
    Asm_one_shot_CFL(input, "RESET_DATA_PIPE", start_data_pipe);
   
}

/*
   One shot implementation for "RESET_DATA_PIPE"
*/
static void reset_data_pipe(void *input, void *params, Event_data_CFL_t *event_data)
{
    unsigned short pipe_id = get_column_pipe_index(input);
    Reset_pipe_CFL(input, pipe_id);
}


void Reset_pipe_CFL(void *input, unsigned short pipe_id)
{
    Pipe_control_CFL_t *pipe_control = get_pipe_control_CFL(input, pipe_id);
    for(unsigned i = 0; i< pipe_control->current_index; i++){
        Pipe_Slot_CFL_t *pipe_slot = pipe_control->pipe_slots+i;
        if(pipe_slot->type == Column_element_type_CFL_t){
            Column_element_CFL_t *column_element = (Column_element_CFL_t *)pipe_slot->pipe_element.column_element;
            if(column_element->free_flag == true){
                column_element->free_flag = false;
                Private_heap_free_CFL(input, column_element->data_pointer   );

            }
            column_element->data_pointer = NULL;
            column_element->free_flag = false;
        }
        if(pipe_slot->type ==  Pipe_link_CFL_t){
            Pipe_link_t *pipe_link = (Pipe_link_t *)pipe_slot->pipe_element.pipe_link;
            Reset_pipe_CFL(input, pipe_link->pipe_id);
            
        }
    }
    pipe_control->current_index = 0;
    pipe_control->pipe_stack->current_level = 0;
}



typedef struct walk_data_pipe_t
{
    Pipe_control_CFL_t      *pipe_control;
    bool                   recurse_flag;
    One_shot_function_CFL_t *reduce_function;
    void *user_data;
 
} walk_data_pipe_t;

void Asm_walk_data_pipe_CFL(void *input, const char *pipe_name, const char *reduce_function, void *user_data,bool recurse_flag)
{
    walk_data_pipe_t *walk_data_pipe = (walk_data_pipe_t *)Allocate_once_malloc_CFL(input, sizeof(walk_data_pipe_t));
    walk_data_pipe->pipe_control = get_pipe_control_CFL(input, get_pipe_id_CFL(input, pipe_name));
    walk_data_pipe->user_data = user_data;
    walk_data_pipe->recurse_flag = recurse_flag;
    walk_data_pipe->reduce_function = Get_one_shot_function_CFL(input, reduce_function);
    Asm_one_shot_CFL(input, "WALK_DATA_PIPE", walk_data_pipe);       
}

static void walk_data_pipe_CLF(void *input,  void *params, Event_data_CFL_t *event_data){
   walk_data_pipe_t *walk_data_pipe = (walk_data_pipe_t *)params;
   One_shot_function_CFL_t reduce_function = walk_data_pipe->reduce_function;
   void *user_data = walk_data_pipe->user_data;

    Pipe_control_CFL_t *pipe_control = walk_data_pipe->pipe_control;
    unsigned short pipe_length = pipe_control->current_index;
    for(unsigned i = 0; i< pipe_length; i++){
        Pipe_Slot_CFL_t *pipe_slot = pipe_control->pipe_slots+i;
        reduce_function(input,(void *)pipe_slot, user_data);
        
        if(pipe_slot->type == Pipe_link_CFL_t){
            if(walk_data_pipe->recurse_flag){
               Pipe_link_t *pipe_link = (Pipe_link_t *)pipe_slot->pipe_element.pipe_link;
               walk_data_pipe_CLF(input, pipe_link->pipe_id,params, event_data);
            }
        }

    }
}

typedef struct start_data_pipe_t
{
    unsigned short pipe_id;
} start_data_pipe_t;


void Asm_start_pipe(void *input, const char *pipe_name)
{
    start_data_pipe_t *start_data_pipe = (start_data_pipe_t *)Allocate_once_malloc_CFL(input, sizeof(start_data_pipe_t));
    start_data_pipe->pipe_id = get_pipe_id_CFL(input, pipe_name);
    Asm_one_shot_CFL(input, "START_PIPE", start_data_pipe);
}

void start_pipe(void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
    start_data_pipe_t *start_data_pipe = (start_data_pipe_t *)params;
    unsigned short pipe_id = start_data_pipe->pipe_id;
    Pipe_control_CFL_t *pipe_control = get_pipe_control_CFL(input, pipe_id);
    Reset_pipe_CFL(input,pipe_id);
    set_column_pipe(input,get_current_column(input), pipe_id);
}

typedef struct pipe_link_t
{
    unsigned short pipe_id;
} pipe_link_t;

void Asm_pipe_link_CFL(void *input, const char *pipe_name, const char *pipe_link_name)
{
    pipe_link_t *pipe_link = (pipe_link_t *)Allocate_once_malloc_CFL(input, sizeof(pipe_link_t));
    pipe_link->pipe_id = get_pipe_id_CFL(input, pipe_link_name);
    Asm_one_shot_CFL(input, "PIPE_LINK", pipe_link);
}

static void pipe_link(void *input,void *params,Event_data_CFL_t *data){
   pipe_link_t *pipe_link = (pipe_link_t *)params;
   // get current pipe
   // insert pipe link element



}



typedef struct store_column_data_t {
  void *data;
  bool free_flag;

}store_column_data_t;

void Asm_pipe_store_column_data_CFL(void *input,bool free_flag, void *data)
{
    store_column_data_t *store_column_data = (store_column_data_t *)Allocate_once_malloc_CFL(input, sizeof(store_column_data_t));
    store_column_data->data = data;
    store_column_data->free_flag = free_flag;
    Asm_one_shot_CFL(input, "PIPE_STORE_COLUMN_DATA", store_column_data);
}

static void pipe_store_column_data(void *input, void *params, Event_data_CFL_t *event_data)
{
    store_column_data_t *store_column_data = (store_column_data_t *)params;
    Pipe_control_CFL_t *pipe_control = get_pipe_control_CFL(input, get_column_pipe_index(input));
    Pipe_Slot_CFL_t *pipe_slot = pipe_control->pipe_slots+pipe_control->current_index;
    pipe_slot->type = Column_element_type_CFL_t;
    pipe_slot->pipe_element.column_element.data_pointer = store_column_data->data;
    pipe_slot->pipe_element.column_element.free_flag = store_column_data->free_flag;
    pipe_control->current_index++;
}

#if 0


void Create_chain_control_CFL(void *input, unsigned short chain_number, unsigned short chain_start);
void Verify_chain_control_end_CFL(void *input);
void Create_if_chain_control_CFL(void *input, unsigned short chain_number, unsigned short chain_start);
void Create_loop_start_CFL(void *input, unsigned short loop_start, unsigned short loop_number);
void Create_loop_element_CFL(void *input, unsigned short loop_start, unsigned short loop_number);
void Create_try_start_CFL(void *input, unsigned short try_start, unsigned short try_max_number);
void Create_try_end_CFL(void *input, bool success, bool inverse_flag);
void Create_chain_element_CFL(void *input);
#endif








typedef struct start_data_pipe
{
    unsigned short pipe_id;
} start_data_pipe_t;

void Asm_start_data_pipe_CFL(void *input, const char *pipe_name)
{
    start_data_pipe_t *start_data_pipe = (start_data_pipe_t *)Allocate_once_malloc_CFL(input, sizeof(start_data_pipe_t));
    start_data_pipe->pipe_id = get_pipe_id_CFL(input, pipe_name);
    Asm_one_shot_CFL(input, "START_DATA_PIPE", start_data_pipe);
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