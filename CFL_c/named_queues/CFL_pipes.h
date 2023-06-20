#ifndef __CFL_PIPES_H__
#define __CFL_PIPES_H__

 
enum {
    Column_control_type_CFL_t = 0,
    If_chain_type_CFL_t = 1,
    Loop_start_type_CFL_t = 2,
    Loop_element_type_CFL_t = 3,
    Try_element_type_CFL_t = 4,
    Column_element_type_CFL_t = 5,
    Pipe_link_CFL_t = 6,
} Pipe_type_CFL_t;

unsigned reserve_pipe_control_column_functions_CFL(void);
void register_pipe_control_column_functions_CFL(void *input);
unsigned reserve_pipe_control_one_shot_functions_CFL(void );
void register_pipe_control_one_shot_functions_CFL(void *input);
unsigned reserve_pipe_control_boolean_functions_CFL(void);
void register_pipe_control_boolean_functions_CFL(void *input);


void intialize_pipe_control_CFL(void *input, unsigned short number_of_pipes);


void Create_pipe_control_CFL(void *input, const char *pipe_name, unsigned number_of_levels, unsigned short number_of_slots);
void Asm_start_pipe_processing_CFL(void *input, const char *pipe_name);
void Asm_reset_data_pipe_CFL(void *input, const char *pipe_name);
void Asm_walk_data_pipe_CFL(void *input, const char *pipe_name, const char *reduce_function, void *user_data);
void Asm_pipe_store_column_data_CFL(void *input, void *data);

void Create_chain_control_CFL(void *input, unsigned short chain_number, unsigned short chain_start);
void Verify_chain_control_end_CFL(void *input);
void Create_if_chain_control_CFL(void *input, unsigned short chain_number, unsigned short chain_start);
void Create_loop_start_CFL(void *input, unsigned short loop_start, unsigned short loop_number);
void Create_loop_element_CFL(void *input, unsigned short loop_start, unsigned short loop_number);
void Create_try_start_CFL(void *input, unsigned short try_start, unsigned short try_max_number);
void Create_try_end_CFL(void *input, bool success, bool inverse_flag);
void Create_chain_element_CFL(void *input);

/*
   c runtime functions
*/
void Reset_pipe_CFL(void *input, unsigned pipe_id);







#endif // __CFL_PIPES_H__

#if 0 
pipes are data packets that represent the traversal of a tree
tree traversal is from
 pipe control contains the starting location of the pipe
 as well as the ending point of the pipe
  
  The following links are link tree elements
  Each of these data structures link to the next structure at the same level
  a stack is needed on pipe control

  a.  Enable/Disable columns
  b  Try operations
  c. loop operations
  d. if operations
  data packets from column elements are of type column_element_CFL_t
  data packets can link to other pipes throug the Pipe_link_CFL_t node

Processing elements need to know which pipe id to uses
The column start operation will set up this information in the current colum
Enamble/Disable operations will transfer information to their child columns

The pipe information is store in the column element

#endif

   
    
  