#ifndef __CFL_PIPES_H__
#define __CFL_PIPES_H__

 
enum {
    Chain_type_CFL_t = 0,
    If_chain_type_CFL_t = 1,
    Loop_start_type_CFL_t = 2,
    Loop_element_type_CFL_t = 3,
    Try_start_type_CFL_t = 4,
    Try_end_type_CFL_t = 5,
    Chain_element_type_CFL_t = 6,
    Chain_link_type_CFL_t = 7
} Pipe_type_CFL_t;

void Reset_pipe_CFL(void *input, unsigned pipe_id);






#endif // __CFL_PIPES_H__