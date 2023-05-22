#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_element_storeage.h"
#include "CFL_pipes.h"

/*
typedef struct Slot_CFL_t {
    unsigned short  type;
    unsigned short chain_id;
    unsigned short data_size;
    void *data;
}Slot_CFL_t;
*/

typedef struct Pipe_element_CFL_t {
    unsigned short id;
    unsigned short head;
    unsigned short tail;
    unsigned short pipe_size;
    Slot_CFL_t     *pipe_slots;
}Pipe_element_CFL_t;


typedef struct Pipe_control_CFL_t {
    unsigned short  slot_size;
    unsigned short  number_of_slots;
    Pipe_element_CFL_t *pipes;
    Hash_cell_control_CFL_t *names;
}Pipe_control_CFL_t;



void intialize_pipe_control_CFL(void *input,unsigned short slot_size, unsigned short number_of_pipes, unsigned short number_of_slots){
   
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_control_CFL_t *pipe_control = (Pipe_control_CFL_t *)Allocate_once_malloc_CFL(handle,sizeof(Pipe_control_CFL_t));
   handle->pipe_control = pipe_control;
    pipe_control->slot_size = slot_size;
    pipe_control->number_of_slots = number_of_pipes;
    pipe_control->pipes = (Pipe_element_CFL_t *)Allocate_once_malloc_CFL(handle,number_of_pipes*sizeof(Pipe_element_CFL_t));
    pipe_control->names = contruct_hash_cell_control_CFL(handle,number_of_pipes);
    for(unsigned i= 0; i<number_of_pipes; i++){
        pipe_control->pipes[i].id = i;
        pipe_control->pipes[i].head = 0;
        pipe_control->pipes[i].tail = 0;
        pipe_control->pipes[i].pipe_size = number_of_pipes;
        pipe_control->pipes[i].pipe_slots = (Slot_CFL_t *)Allocate_once_malloc_CFL(handle,number_of_slots*sizeof(Slot_CFL_t));
    }


}



unsigned short Pipe_length_CFL(void *input, unsigned short pipe_id){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_control_CFL_t *pipe_control = handle->pipe_control;
    return pipe_control->pipes[pipe_id].tail - pipe_control->pipes[pipe_id].head;
    
}

// returns NULL if pipe is empty
Slot_CFL_t  *Pop_pipe_CFL(void *input, unsigned short pipe_id){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_control_CFL_t *pipe_control = handle->pipe_control;
    Pipe_element_CFL_t *pipe = &pipe_control->pipes[pipe_id];
    if (pipe->head == pipe->tail)
    {
        return NULL;
    }
    
        Slot_CFL_t *slot = &pipe->pipe_slots[pipe->head];
        pipe->head = pipe->head + 1 ;
        return slot;
    
}

// returns number of free slots
unsigned short Push_pipe_CFL(void *input, unsigned short pipe_id, Slot_CFL_t *slot){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Pipe_control_CFL_t *pipe_control = handle->pipe_control;
    Pipe_element_CFL_t *pipe = &pipe_control->pipes[pipe_id];
    if (pipe->tail == pipe->pipe_size)
    {
        ASSERT_PRINT_F("Pipe is full pipe_id %d\n",pipe_id);
    }
    pipe->pipe_slots[pipe->tail] = *slot;
    pipe->tail = pipe->tail + 1;
    return pipe->pipe_size - pipe->head;
    
}



// Chain flow assembler commands

void ASM_create_pipes_CFL(void *input, unsigned short number, const char **names){
  
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Pipe_control_CFL_t *pipe_control = handle->pipe_control;
  Store_Names_CFL(pipe_control->names,number, names);

}

void ASM_set_local_pipe_CFL(void *input, const char *name){
;
}



void ASM_reduce_local_pipe_CFL(void *input, const char *one_shot_function){


}
