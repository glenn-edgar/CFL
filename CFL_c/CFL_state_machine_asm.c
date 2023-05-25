#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_debug.h"
#include "CFL_element_storeage.h"
#include "CFL_state_machine_asm.h"
#include "CFL_state_machine_util.h"
#include "CFL_state_machine_rt.h"

static void check_for_undefined_states(void *input);
static void load_sm_change_data_struct(void *input,unsigned short number, const char **sm_names,bool state);



void Asm_define_sm(void *input, 
                   const char *sm_name, 
                   unsigned char  number_of_states, 
                   const char **state_names, 
                   const char *initial_state,
                   const char *sm_change_fn,
                   void *user_data){

    Handle_CFL_t *handle = (Handle_CFL_t *)input;

    if (handle->sm_assembly == true)
    {
        ASSERT_PRINT("Error: State machine generation should not be active", "");
    }
    handle->sm_assembly = true;

    // find sm_context structure
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_index = Find_Name_CFL(sm_dictionary->sm_names, sm_name);
    if (sm_index == -1)
    {
        ASSERT_PRINT_F("Error: State machine name %s not found", sm_name);
    }
    handle->sm_index = sm_index;

    Sm_control_CFL_t *sm_control = sm_dictionary->sm_control + sm_index;
    sm_control->active = false;
    sm_control->number_of_states = number_of_states;
    
    sm_control->current_state = 0;
    
    sm_control->state_change_fn = Get_one_shot_function_CFL(input, sm_change_fn);
    sm_control->user_data = user_data;
    sm_control->state_names = contruct_hash_cell_control_CFL(handle, number_of_states);
    for (int i = 0; i < number_of_states; i++)
    {
        int id = Store_Name_CFL(sm_control->state_names, state_names[i]);
        if (id == -1)
        {
            ASSERT_PRINT_F("Error: Duplicate state name %s\n", state_names[i]);
        }
    }
    short initial_state_id = Find_Name_CFL(sm_control->state_names, initial_state);
    if (initial_state_id == -1)
    {
        ASSERT_PRINT_F("Error: Initial state name %s not found", initial_state);
    }
    sm_control->initial_state = initial_state_id;
}

void Asm_end_state_machine_CFL(void *input){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    check_for_undefined_states(input);

    handle->sm_assembly = false;
    
}

void Asm_define_state_CFL(void *input, 
                        const char *state_name,
                        unsigned short chain_number, 
                        const char **chain_names,
                        const char *state_change_fn,
                        void *user_data){


   Handle_CFL_t* handle = (Handle_CFL_t*)input;

   
   if(handle->sm_assembly == false){
     ASSERT_PRINT_F("Error: State Definition is not Need a define statemachine for state %s\n",state_name);
   }

   Sm_control_CFL_t* sm_control = find_sm_CFL(input, handle->sm_index);
    short index = Find_Name_CFL(sm_control->state_names, state_name);
    if(index == -1){
        ASSERT_PRINT_F("Error: State %s name not found\n", state_name);
    }

   States_def_CFL_t* state_control = find_state_CFL(input, handle->sm_index, index);
   state_control->number_of_chains = chain_number;
    state_control->user_data = user_data;
    state_control->state_change_fn = Get_one_shot_function_CFL(input, state_change_fn);
    state_control->state_chains = Allocate_once_malloc_CFL(input, sizeof(unsigned short)*chain_number);
    
    for(unsigned i = 0; i<chain_number; i++){
        int id = Find_Name_CFL(sm_control->state_names, chain_names[i]);
        if(id == -1){
            ASSERT_PRINT_F("Error: Duplicate chain name %s\n", chain_names[i]);
        }
        state_control->state_chains[i] = id;
    }


}







void Asm_enable_sms_CFL(void *input,unsigned short number, const char **sm_names){
    load_sm_change_data_struct(input, number, sm_names, true);
}

void Asm_disable_sms_CFL(void *input,unsigned short number, const char **sm_names){
    load_sm_change_data_struct(input, number, sm_names, false);
}
  




void Asm_change_state_CFL(void *input, const char *state_machine_name, const char *state_name){
  
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  Sm_dictionary_CFL_t *sm_dictionary = find_sm_dictionary_CFL(input);
  
  short sm_index = Find_Name_CFL(sm_dictionary->sm_names, state_machine_name);
  if(sm_index < 0){
        ASSERT_PRINT_F("Error: State machine name %s not found", state_machine_name);
  }
  short state_index = Find_Name_CFL(sm_dictionary->sm_names, state_name);
    if(state_index < 0){
            ASSERT_PRINT_F("Error: State name %s not found", state_name);
    }
    change_sm_data_CFL_t *change_sm_data = (change_sm_data_CFL_t*)Allocate_once_malloc_CFL(handle, sizeof(change_sm_data_CFL_t));           
    change_sm_data->sm_index = sm_index;
    change_sm_data->state_index = state_index;
    Asm_one_shot_CFL(handle,"CHANGE_STATE", change_sm_data);

}





void Asm_dump_state_machines_CFL(void *input ){

   Asm_one_shot_CFL(input,"DUMP_STATE_MACHINES", NULL);

}

static void check_for_undefined_states(void *input)
{
   Handle_CFL_t* handle = (Handle_CFL_t*)input;      

   Sm_control_CFL_t* sm_control = find_sm_CFL(input, handle->sm_index);
   for(unsigned i = 0; i<sm_control->number_of_states; i++){
         States_def_CFL_t *state_control = find_state_CFL(input, handle->sm_index, i);
         if(state_control->number_of_chains == 0){
             ASSERT_PRINT_F("Error: State %d has not beem defined \n",i);
         }  
    }   
    
}


static void load_sm_change_data_struct(void *input,unsigned short number, const char **sm_names,bool state){
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  Sm_dictionary_CFL_t *sm_dictionary = find_sm_dictionary_CFL(input);
  
  enable_disable_data_CFL_t *enable_disable_data = ( enable_disable_data_CFL_t* )Allocate_once_malloc_CFL(handle, sizeof(enable_disable_data_CFL_t));
  enable_disable_data->sm_number = number;
  enable_disable_data->sm_indexes = (unsigned short*)Allocate_once_malloc_CFL(handle, sizeof(unsigned short)*number);
  for (unsigned  i = 0; i < number; i++){
        unsigned short index;
        index = Find_Name_CFL(sm_dictionary->sm_names, sm_names[i]);
        if(index < 0){
            ASSERT_PRINT_F("Error: State Machine name %s not found", sm_names[i]);
        }
       enable_disable_data->sm_indexes[i] = index;
  }
    if(state == true){
        Asm_one_shot_terminate_CFL(handle,"ENABLE_SM", enable_disable_data);
    }
  
  Asm_one_shot_CFL(handle,"DISABLE_SM", enable_disable_data);
}



