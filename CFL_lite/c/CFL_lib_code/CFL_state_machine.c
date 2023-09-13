
#include "CFL_inner_engine.h"


void reset_all_state_machines_CFL(const void *input){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
   for(unsigned i = 0; i < handle->number_of_sm; i++){
     handle->sm_ram[i].active = false;
   }

}

static void disable_all_state_chains_CFL(const void *input,unsigned sm_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const Sm_control_ROM_CFL_t *sm_rom = handle->sm_rom+sm_id;
    
    for(unsigned i = 0; i < sm_rom->number_of_states; i++){
        disable_column_CFL(input,sm_rom->chain_ids[i]);
    }
}

void enable_state_machine_CFL(const void *input,unsigned sm_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(sm_id >= handle->number_of_sm){
        ASSERT_PRINT_INT("Invalid state machine id",sm_id);
    }
    enable_column_CFL(input,handle->sm_rom[sm_id].manager_chain_id);
    handle->sm_ram[sm_id].active = true;
    disable_all_state_chains_CFL(input,sm_id);
    // enable main chain
    
}


void disable_state_machine_CFL(const void *input,unsigned sm_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(sm_id >= handle->number_of_sm){
         ASSERT_PRINT_INT("Invalid state machine id",sm_id);
    }
    disable_column_CFL(input, handle->sm_rom[sm_id].manager_chain_id);
    handle->sm_ram[sm_id].active = false;
    disable_all_state_chains_CFL(input,sm_id);
    
}

void change_state_machine_CFL(const void *input,unsigned sm_id,unsigned state_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(state_id >= handle->sm_rom[sm_id].number_of_states){
         ASSERT_PRINT_INT("Invalid state machine id",sm_id);
    }

    if (state_id >= handle->sm_rom[sm_id].number_of_states){
        ASSERT_PRINT_INT("Invalid state id",state_id);
    }
    unsigned chain_id = handle->sm_rom[sm_id].chain_ids[state_id];
    handle->sm_ram[sm_id].current_state = state_id;
    handle->sm_ram[sm_id].active = true;
    disable_all_state_chains_CFL(input,sm_id);
    enable_column_CFL(input,chain_id);
    
}   
