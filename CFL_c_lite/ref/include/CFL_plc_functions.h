#ifndef __CFL_PCL_FUNCTIONS_H__
#define __CFL_PCL_FUNCTIONS_H__

/*

   counters

*/
void Create_plc_bit_buffer_CFL(void* input, const char* buffer_name, unsigned short number_of_bits, bool initial_value);

void Asm_plc_drum_bit_controller_CFL(void *input,const char *bit_buffer_name, unsigned short output_bit, 
                                    unsigned short number_of_time_steps, unsigned short *time_values_ms, bool *bit_values,
                                    const char *register_buffer_name, 
                                    unsigned short step_number,
                                    unsigned short time_step_count,
                                    unsigned short time_step_value,
                                    unsigned short bit_state);
                                       
            


void Asm_pcl_wait_delay_toggle_CFL(void *input, const char *bit_buffer_name, int time_out_ms, 
                            unsigned short toggle_bit);



// event counter
void Asm_plc_up_counter_CFL(void *input, const char *bit_buffer_name, const char *register_buffer_name,
                            unsigned short toggle_bit,
                            unsigned short reset_current_count_bit,
                            unsigned short count_done_bit,
                            unsigned short load_count_bit,
                            unsigned short load_register,
                            unsigned short current_count_register);

void Asm_plc_down_counter_CFL(void *input, const char *bit_buffer_name, const char *register_buffer_name,
                            unsigned short toggle_bit,
                            unsigned short reset_current_count_bit,
                            unsigned short count_done_bit,
                            unsigned short load_count_bit,
                            unsigned short load_register,
                            unsigned short current_count_register);


// quad counter
void Asm_plc_quad_counter_CFL(void* input, const char* bit_buffer_name, const char *register_buffer_name,
                              unsigned short behind_toggle_bit, 
                              unsigned short forward_toggle_bit,
                              unsigned short reset_current_count_bit,
                              unsigned short count_done_bit,
                              unsigned short load_count_bit,
                              unsigned short load_register,
                              unsigned short current_count_register);


void Asm_plc_wait_up_transition_CFL(void* input, const char* buf_name,int bit_number, unsigned short *bit_positions);
void Asm_plc_wait_down_transition_CFL(void* input, const char* buf_name,int bit_number, unsigned short *bit_positions);
void Asm_plc_generate_up_pulse_CFL(void* input, const char* buf_name,int bit_number, unsigned short *bit_positions);
void Asm_plc_generate_down_pulse_CFL(void* input, const char* buf_name,int bit_number, unsigned short *bit_positions);

// bit buffer instructios

void Asm_plc_reset_bit_buffer_CFL(void* input, const char* buffer_name, bool value);
void Asm_plc_set_bit_positions_CFL(void* input, const char* name, unsigned short number, const unsigned short* positions, bool value);
void Asm_plc_copy_bit_positions_CFL(void *input,const char *from_buff_name, const char *to_buff_name, unsigned short number,
                       unsigned short *positions);
void Asm_plc_copy_bit_array_CFL(void* input, const char* from_bufF_name, const char* to_buff_name, unsigned short from_start, unsigned short to_start, unsigned short number);
void Asm_plc_print_bit_buf_CFL(void* input, const char* buffer_name); 
void Asm_plc_store_bit_s_expr_CFL(void* input, const char* buffer_name,unsigned short store_index, const char* s_expression);
  

void Asm_plc_wait_bit_s_expression_CFL(void* input, const char* buf_name, int time_out_ms,const char* one_shot_failure_fn, 
             void* user_data, bool terminate_flag,const char* s_expression_name);

void Asm_plc_verify_bit_s_expression_CFL(void* input, const char* buf_name, const char* one_shot_failure_fn, 
     void* user_data, bool terminate_flag,const char* s_expression_name);


/*

   Register operatios

*/
void Create_register_buffer_CFL(void* input, const char* buffer_name, unsigned short number_of_registers,short initial_value);
void Asm_plc_reset_register_buffer_CFL(void* input, const char* buffer_name, bool value);
void Asm_plc_set_register_positions_CFL(void* input, const char* name, unsigned short number, const unsigned short* positions, bool value);
void Asm_plc_copy_register_positions_CFL(void *input,const char *from_buff_name, const char *to_buff_name, unsigned short number,
                       unsigned short *positions);
void Asm_plc_copy_register_array_CFL(void* input, const char* from_bufF_name, const char* to_buff_name, unsigned short from_start, unsigned short to_start, unsigned short number);
void Asm_plc_print_register_buf_CFL(void* input, const char* buffer_name); 
void Asm_plc_store_register_s_expr_CFL(void* input, const char* buffer_name,unsigned short store_index, const char* s_expression);
  
void Asm_plc_search_registe_value_CFL(void *input, const char *register_buffer_name, unsigned short start_index, unsigned short end_index,
                        const char *s_expression, unsigned short result_value,
                        const char *bit_index, unsigned short result_state);
void Asm_plc_wait_register_s_expression_CFL(void* input, const char* buf_name, int time_out_ms,const char* one_shot_failure_fn, 
             void* user_data, bool terminate_flag,const char* s_expression_name);

void Asm_plc_verify_register_s_expression_CFL(void* input, const char* buf_name, const char* one_shot_failure_fn, 
     void* user_data, bool terminate_flag,const char* s_expression_name);

/*

    Float operations

*/
void Create_float_buffer_CFL(void* input, const char* buffer_name, unsigned short number_of_registers,float initial_value);
void Asm_plc_reset_float_buffer_CFL(void* input, const char* buffer_name, bool value);
void Asm_plc_set_float_positions_CFL(void* input, const char* name, unsigned short number, const unsigned short* positions, bool value);
void Asm_plc_copy_float_positions_CFL(void *input,const char *from_buff_name, const char *to_buff_name, unsigned short number,
                       unsigned short *positions);
void Asm_plc_copy_float_array_CFL(void* input, const char* from_bufF_name, const char* to_buff_name, unsigned short from_start, unsigned short to_start, unsigned short number);
void Asm_plc_print_float_buf_CFL(void* input, const char* buffer_name); 
void Asm_plc_store_float_s_expr_CFL(void* input, const char* buffer_name,unsigned short store_index, const char* s_expression);
  
void Asm_plc_search_float_value_CFL(void *input, const char *float_buffer_name, unsigned short start_index, unsigned short end_index,
                        const char *s_expression, unsigned short result_value,
                        const char *bit_index, unsigned short result_state);

void Asm_plc_wait_float_s_expression_CFL(void* input, const char* buf_name, int time_out_ms,const char* one_shot_failure_fn, 
             void* user_data, bool terminate_flag,const char* s_expression_name);

void Asm_plc_verify_float_s_expression_CFL(void* input, const char* buf_name, const char* one_shot_failure_fn, 
     void* user_data, bool terminate_flag,const char* s_expression_name);



#endif // __CFL_PCL_FUNCTIONS_H__