#ifndef __CFL_PIPES_H__
#define __CFL_PIPES_H__

 

typedef struct Slot_CFL_t {
    unsigned short  type;
    unsigned short chain_id;
    unsigned short data_size;
    void *data;
}Slot_CFL_t;

enum Pipe_type_CFL_t {
    PIPE_START_ARRAY_CFL = 0,
    PIPE_END_ARRAY_CFL = 1,
    PIPE_LOOP_CFL = 2,
    PIPE_INNER_LOOP_START_CFL = 3,
    PIPE_INNER_LOOP_END_CFL = 4,   
    PIPE_END_LOOP_CFL = 5,
    PIPE_TRY_START_CFL = 6,
    PIPE_TRY_END_CFL = 7,
    PIPE_IF_START_CFL = 8,
    PIPE_IF_END_CFL = 9,
    PIPE_DATA_ELEMENT_CFL = 10,
};



void intialize_pipe_control_CFL(void *input,unsigned short slot_size, unsigned short number_of_pipes, unsigned short number_of_slots);



unsigned short Pipe_length_CFL(void *input, unsigned short pipe_id);

// returns NULL if pipe is empty
Slot_CFL_t  *Pop_pine_CFL(void *input, unsigned short pipe_id);

// returns number of elements in the pipe
unsigned short Push_pipe_CFL(void *input, unsigned short pipe_id, Slot_CFL_t *slot);



// Chain flow assembler commands

void ASM_create_pipes_CFL(void *input, unsigned short name_number, const char **names);
void ASM_set_local_pipe_CFL(void *input, const char *name);
void ASM_reduce_local_pipe_CFL(void *input, const char *one_shot_function);









#endif // __CFL_PIPES_H__