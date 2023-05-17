#ifndef __CFL_PLC_FUNCTIONS_H__
#define __CFL_PLC_FUNCTIONS_H__

// add short arthmetic
// add float arthmetic



typedef struct Drum_Sequencer_CLF_t{
    unsigned short store_location;
    unsigned short step_number;
    unsigned short *time_steps;
    bool           *drum_states;

}Drum_Sequencer_CFL_t;

void Asm_plc_drum_CLF(void *input,unsigned short store_location, unsigned short step_number, unsigned short *time_steps, bool *drum_states);


void Asm_plc_wait_for_bit_transition_up_CFL(void *handle, const char *buffer_name, unsigned short bit_number, bool *bit_values);
void Asm_plc_wait_for_bit_transition_down_CLF(void *handle, const char *buffer_name, unsigned short bit_number, bool *bit_values);
void Asm_plc_start_timer_CFL(void *handle, const char *register_buffer, const char *bit_buffer,unsigned short set_point_register,
                         unsigned short current_status_register, unsigned short timer_status_bit);

void Asm_plc_start_timer_CFL(void *handle, const char *register_buffer, const char *bit_buffer,unsigned short set_point_register,
                         unsigned short current_status_register, unsigned short timer_status_bit,bool direction, unsigned short toggle_bit);

// add in drum sequencer

void Asm_shift_register(void *handle, const char *register_buffer, const char *bit_buffer,unsigned short set_point_register,
                        unsigned short current_status_register, unsigned short timer_status_bit,bool direction, unsigned short toggle_bit);


// in register section add register move and search functions
#endif