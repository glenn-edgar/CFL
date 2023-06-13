#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_debug.h"
#include "CFL_element_storeage.h"
#include "CFL_state_machine.h"


#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "Cfl_element_storeage.h"
#include "CFL_state_machine.h"


  
void Constuct_sm_system_CFL(void *input, Handle_config_CFL_t *config)
{ 
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    unsigned sms_number = config->number_of_state_machines;
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_dictionary_CFL_t));
    handle->sm_dictionary = sm_dictionary;
   
    sm_dictionary->max_sms_number = sms_number;
    sm_dictionary->current_sm_number = 0;
    if (config->number_of_state_machines == 0)
    {
        sm_dictionary->sm_control = NULL;
        sm_dictionary->sm_names = NULL;
        return;
    }
    sm_dictionary->sm_names = contruct_hash_cell_control_CFL(handle,sms_number);
    sm_dictionary->sm_control = (Sm_control_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_control_CFL_t) *sms_number);
    
}

void Define_state_machine_CFL(void *input, unsigned short number_of_states, const char **state_names){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
   Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t*)handle->sm_dictionary;
   if(number_of_states >= (sm_dict->max_sms_number - sm_dict->current_sm_number)){
     ASSERT_PRINT_F("number_of_states %d >= (sm_dict->max_sms_number %d - sm_dict->current_sm_number %d)\n",
                                    number_of_states,sm_dict->max_sms_number,sm_dict->current_sm_number);
       
   }
  
   Store_Names_CFL(sm_dict->sm_names,number_of_states,state_names);
   for( unsigned i= sm_dict->current_sm_number; i< sm_dict->current_sm_number + number_of_states; i++){
       sm_dict->sm_control[i].defined = false;
   }
   sm_dict->current_sm_number += number_of_states;

}




void Asm_define_sm(void *input, 
                   const char *sm_name, 
                   unsigned char  number_of_states, 
                   const char **state_names, 
                   const char *sm_manager_chain_name,
                   const char *sm_queue_name,
                   void *user_data){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    if( handle->sm_assembly == true ){
        ASSERT_PRINT("error sm_assembly is in current operation\n","");
    }
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t*)handle->sm_dictionary;
    // find sm_id from name table
    short sm_id = Find_Name_CFL(sm_dict->sm_names,sm_name);
    if(sm_id < 0){
        ASSERT_PRINT_F("sm_name %s not found\n",sm_name);
    }
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + sm_id;
    sm_control->state_names = contruct_hash_cell_control_CFL(handle,number_of_states);
    Store_Names_CFL(sm_control->state_names,number_of_states,state_names);
    sm_control->defined = true;
    sm_control->active = false;
    sm_control->sm_id = sm_id;
    sm_control->manager_chain_id = Find_column_index_CFL(handle,sm_manager_chain_name);
    sm_control->number_of_states = number_of_states;
    sm_control->chain_ids = (short *)Allocate_once_malloc_CFL(handle,sizeof(unsigned short)*number_of_states);
    for(int i = 0; i < number_of_states; i++){
        sm_control->chain_ids[i] = -1;
    }
    sm_control->user_data = user_data;
    sm_control->sm_queue_id = Find_column_index_CFL(handle,sm_queue_name);
    handle->sm_assembly = true;
    handle->sm_index = sm_id;
}

void Asm_define_state_CFL(void *input, 
                        const char *state_name,
                        const char *chain_name){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t*)handle->sm_dictionary;
    if(handle->sm_assembly == false){
        ASSERT_PRINT("sm_assembly not started\n","");
    }
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + handle->sm_index;
    short state_id = Find_Name_CFL(sm_control->state_names,state_name);
    if(state_id < 0){
        ASSERT_PRINT_F("state_name %s not found\n",state_name);
    }
    sm_control->chain_ids[state_id] = Find_column_index_CFL(handle,chain_name);
    
}

void Asm_end_state_machine_CFL(void *input){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
   if(handle->sm_assembly == false){
        ASSERT_PRINT("sm_assembly not started\n","");
    }
    handle->sm_assembly = false;
     Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t*)handle->sm_dictionary;
    Sm_control_CFL_t *sm_control = sm_dict->sm_control + handle->sm_index;
    for(int i = 0; i < sm_control->number_of_states; i++){
        if(sm_control->chain_ids[i] == -1){
            ASSERT_PRINT_F("state %d not defined\n",i);
        }
    }
}

void Verify_all_sm_are_defined(void *input){
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  Sm_dictionary_CFL_t *sm_dict = (Sm_dictionary_CFL_t*)handle->sm_dictionary;
  for(unsigned i = 0; i < sm_dict->current_sm_number; i++){
      if(sm_dict->sm_control[i].defined == false){
          ASSERT_PRINT_F("sm %d not defined\n",i);
      }
  }

}

/*

  Local functions


*/
 



