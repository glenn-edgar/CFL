
#include "CFL_inner_engine.h"





void disable_all_state_machines_CFL(const void *input){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  
   for(unsigned i = 0; i < handle->number_of_sm; i++){


  
     disable_state_machine_CFL(input,i);
   }

}



static void disable_all_state_chains_CFL(const void *input,uint16_t sm_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    const Sm_control_ROM_CFL_t *sm_rom = handle->sm_rom+sm_id;
    
    for(unsigned i = 0; i < sm_rom->number_of_states; i++){
        disable_column_CFL(input,sm_rom->column_ids[i]);
    }
}

void enable_state_machine_CFL(const void *input,uint16_t sm_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(sm_id >= handle->number_of_sm){
        ASSERT_PRINT_INT(input,"Invalid state machine id",sm_id);
    }
    enable_column_CFL(input,handle->sm_rom[sm_id].manager_column_id);
    handle->sm_ram[sm_id].active = true;
    
    disable_all_state_chains_CFL(input,sm_id);
    
    
}

void enable_state_machine_hash_CFL(const void *input,uint32_t sm_hash){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    for(unsigned i = 0; i < handle->number_of_sm; i++){
        if(handle->sm_rom[i].sm_hash == sm_hash){
            enable_state_machine_CFL(input,i);
            return;
        }
    }
    ASSERT_PRINT_INT(input,"Invalid state machine hash",sm_hash);
}

void disable_state_machine_CFL(const void *input,uint16_t sm_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(sm_id >= handle->number_of_sm){
         ASSERT_PRINT_INT(input,"Invalid state machine id",sm_id);
    }
  
    disable_column_CFL(input, handle->sm_rom[sm_id].manager_column_id);
    handle->sm_ram[sm_id].active = false;
    disable_all_state_chains_CFL(input,sm_id);
    
}

void disable_state_machine_hash_CFL(const void *input,uint32_t sm_hash){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    for(unsigned i = 0; i < handle->number_of_sm; i++){
        if(handle->sm_rom[i].sm_hash == sm_hash){
            disable_state_machine_CFL(input,i);
            return;
        }
    }
    ASSERT_PRINT_INT(input,"Invalid state machine hash",sm_hash);
}

void change_state_machine_CFL(const void *input,uint16_t sm_id,uint16_t state_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(sm_id >= handle->sm_rom[sm_id].number_of_states){
         ASSERT_PRINT_INT(input,"Invalid state machine id",sm_id);
    }

    if (state_id >= handle->sm_rom[sm_id].number_of_states){
        ASSERT_PRINT_INT(input,"Invalid state id",state_id);
    }
    unsigned column_id = handle->sm_rom[sm_id].column_ids[state_id];
    handle->sm_ram[sm_id].current_state = state_id;
    handle->sm_ram[sm_id].state_hash = handle->sm_rom[sm_id].state_hash[state_id];
    handle->sm_ram[sm_id].active = true;
    disable_all_state_chains_CFL(input,sm_id);
    enable_column_CFL(input,column_id);
    
}   




void change_state_machine_hash_CFL(const void *input,uint32_t sm_hash,uint32_t state_hash){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    for(unsigned i = 0; i < handle->number_of_sm; i++){
        if(handle->sm_rom[i].sm_hash == sm_hash){
            const uint32_t *state_hashes = handle->sm_rom[i].state_hash;
            for( unsigned j = 0; j < handle->sm_rom[i].number_of_states  ; j++){
                if(state_hashes[j] == state_hash){
                    change_state_machine_CFL(input,i,j);
                    return;
                }
            }
             ASSERT_PRINT_F(input,"Invalid state hash %d for state machine %d",i,state_hash);
            
        }

    }
    ASSERT_PRINT_INT(input,"Invalid state machine hash",sm_hash);
}

void send_sm_event(const void *input,uint16_t sm_id, Event_data_CFL_t *event){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(sm_id >= handle->number_of_sm){
        ASSERT_PRINT_INT(input,"Invalid state machine id",sm_id);
    }
    enqueue_event_CFL(input,handle->sm_rom[sm_id].manager_column_id+1,event);
}

void send_sm_event_hash(const void *input,uint32_t sm_hash, Event_data_CFL_t *event){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    for(unsigned i = 0; i < handle->number_of_sm; i++){
        if(handle->sm_rom[i].sm_hash == sm_hash){
            enqueue_event_CFL(input,handle->sm_rom[i].manager_column_id+1,event);
            return;
        }
    }
    ASSERT_PRINT_INT(input,"Invalid state machine hash",sm_hash);
}

bool send_event_to_state(const void *input, Event_data_CFL_t *event){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
   uint16_t current_column = get_current_column_index_CFL(input);
   for(unsigned i = 0; i < handle->number_of_sm; i++){
       if(handle->sm_rom[i].manager_column_id == current_column){
           unsigned state_column_id = handle->sm_rom[i].column_ids[handle->sm_ram[i].current_state];
           if(handle->sm_ram[i].active == true){
             return chain_single_sweep_CFL(input,state_column_id,event);
           }else{
            ASSERT_PRINT_INT(input,"No State machine is not active for column",current_column);
           }

       }

   }
   ASSERT_PRINT_INT(input,"No state machine found for column",current_column); 
   return false; 
}

 const void *get_state_machine_user_data_CFL(const void *input,uint16_t sm_id){
    const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
    if(sm_id >= handle->number_of_sm){
        ASSERT_PRINT_INT(input,"Invalid state machine id",sm_id);
    }
    return handle->sm_rom[sm_id].user_data;
 }   

