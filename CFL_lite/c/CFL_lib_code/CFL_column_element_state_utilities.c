
#include "CFL_useful_utilities.h"
#include "CFL_column_element_state_utilities.h"


static Event_data_CFL_t term_event = {EVENT_TERMINATION_CFL, false, NULL};

static void enable_column_element_state_CFL(const void *input, unsigned short start_index, unsigned short count)
{
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  //const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;
 

  unsigned char *flags = handle->column_elements_flags;
   
  for (int i =start_index; i < start_index+count ; i++)
  {
    
    unsigned column_element_number;
    
    column_element_number =  i;
    
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_INITIALIZED;
    flags[column_element_number] = flags[column_element_number] | COLUMN_ELEMENT_ACTIVE;
  }
}

static void disable_column_element_state_CFL(const void *input, unsigned short start_state, unsigned short count)
{

  
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
 // const Column_ROM_CFL_t *column = handle->column_rom_data + column_index;
  const Column_element_CFL_t *column_element_rom = handle->column_elements_ROM;
  unsigned char *flags = handle->column_elements_flags;

  unsigned column_element_number;
  char column_element_flag;
  int end_state = start_state+count;
  
  for (int i = end_state-1; i >= start_state; i--)
  {
   
    column_element_number =   i;
    column_element_flag = flags[column_element_number];


    if (((column_element_flag & COLUMN_ELEMENT_ACTIVE) != 0) &&
        ((column_element_flag & COLUMN_ELEMENT_INITIALIZED) != 0))
    {
      
      const Column_element_CFL_t *column_element = column_element_rom + column_element_number;
      column_element->column_function(handle, column_element->aux_fn,
                                      column_element->params, &term_event);
    }
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_INITIALIZED;
    flags[column_element_number] = flags[column_element_number] & ~COLUMN_ELEMENT_ACTIVE;
  }
}


void Initial_column_element_structures_CFL(const void *input){
   const Column_sm_structure_CFL_t* sm_def =  (const Column_sm_structure_CFL_t *)   Get_current_column_aux_data(input);
   *sm_def->sm_active = false;
   *sm_def->state_active = false;

}

bool  Get_sm_state_CFL(const void *input, uint16_t *active_sm, uint16_t *active_state ){
    const Column_sm_structure_CFL_t* sm_def =  (const Column_sm_structure_CFL_t *)   Get_current_column_aux_data(input);
    if(sm_def == NULL){
      ASSERT_PRINT_F(input, "No sm_def found for this column %d \n", get_current_column_index_CFL(input));
    }

    *active_sm = *sm_def->active_sm;
    *active_state = *sm_def->active_state;
    return *sm_def->sm_active;
}

void Disable_all_sm_CFL(const void *input){

    Column_sm_structure_CFL_t *column_sm =  (Column_sm_structure_CFL_t *) Get_current_column_aux_data(input);
    if(column_sm == NULL){
      ASSERT_PRINT_F(input, "No column_sm found for this column %d \n", get_current_column_index_CFL(input));
    }
    
    for( unsigned i = 0; i < column_sm->number_of_sm; i++){
      const Sm_def_structure_CFL_t *sm = column_sm->sm[i];
      unsigned start_index = sm->first_column_element;
      unsigned count = sm->total_number_of_column_elements;
     
    
      disable_column_element_state_CFL(input, start_index, count);
    }

    *column_sm->sm_active = false;
    *column_sm->state_active = false;
}

void Disable_column_element_sm_current_CFL(const void *input){
  Column_sm_structure_CFL_t *column_sm =  (Column_sm_structure_CFL_t *) Get_current_column_aux_data(input);
    if(column_sm == NULL){
      ASSERT_PRINT_F(input, "No column_sm found for this column %d \n", get_current_column_index_CFL(input));
    }
    if(*column_sm->sm_active == false){
      ASSERT_PRINT_F(input, "No sm active for this column %d \n", get_current_column_index_CFL(input));
    }
    unsigned sm_index = *column_sm->active_sm;
    const Sm_def_structure_CFL_t *sm = column_sm->sm[sm_index];
    unsigned start_index = sm->first_column_element;
    unsigned count = sm->total_number_of_column_elements;
    disable_column_element_state_CFL(input, start_index, count);
    *column_sm->sm_active = false;
    *column_sm->state_active = false;

}


void Enable_column_element_sm_CFL(const void *input, const uint16_t sm_index){

    Column_sm_structure_CFL_t *column_sm =  (Column_sm_structure_CFL_t *) Get_current_column_aux_data(input);
    
    if(column_sm == NULL){
      ASSERT_PRINT_F(input, "No column_sm found for this column %d \n", get_current_column_index_CFL(input));
    }
    Disable_all_sm_CFL(input);
    if(sm_index >= column_sm->number_of_sm){
      ASSERT_PRINT_F(input, "sm_index %d is out of range \n", sm_index);
    }
   
    const Sm_def_structure_CFL_t *sm = column_sm->sm[sm_index];
   

    unsigned start_index = sm->first_column_element;
    unsigned count = sm->number_of_top_elements;
    
    enable_column_element_state_CFL(input, start_index, count);
    *column_sm->sm_active = true;
    *column_sm->active_sm = sm_index;
    *column_sm->active_state = 0;
    *column_sm->state_active = false;



}


void Enable_column_element_sm_hash_CFL(const void *input, const uint32_t sm_hash){
    Column_sm_structure_CFL_t *column_sm =  (Column_sm_structure_CFL_t *) Get_current_column_aux_data(input);
    if(column_sm == NULL){
      ASSERT_PRINT_F(input, "No column_sm found for this column %d \n", get_current_column_index_CFL(input));
    }
    for( unsigned i = 0; i < column_sm->number_of_sm; i++){
      const Sm_def_structure_CFL_t *sm = column_sm->sm[i];
      if(sm->sm_hash == sm_hash){
       
        Enable_column_element_sm_CFL(input, i);
        return;
      }
    }
    ASSERT_PRINT_F(input, "No sm found for this hash %d \n", sm_hash);

}


void Enable_column_element_sm_string_CFL(const void *input, const char *sm_string){
    Enable_column_element_sm_hash_CFL(input, fnv_hash_string_CFL(sm_string));
}







void Change_column_element_state_index_CFL(const void *input,const uint16_t state_index){
    Column_sm_structure_CFL_t *column_sm =  (Column_sm_structure_CFL_t *) Get_current_column_aux_data(input);
    if(column_sm == NULL){
      ASSERT_PRINT_F(input, "No column_sm found for this column %d \n", get_current_column_index_CFL(input));
    }
    if(column_sm->sm_active == false){
      ASSERT_PRINT_F(input, "No sm active for this column %d \n", get_current_column_index_CFL(input));
    }
    unsigned sm_index = *column_sm->active_sm;
   
  
    if(sm_index >= column_sm->number_of_sm){
      ASSERT_PRINT_F(input, "sm_index %d is out of range \n", sm_index);
    }
    const Sm_def_structure_CFL_t *sm = column_sm->sm[sm_index];
    if(state_index >= sm->number_of_states){
      ASSERT_PRINT_F(input, "state_index %d is out of range \n", state_index);
    }
 
  
    disable_column_element_state_CFL(input,  sm->first_column_element+sm->number_of_top_elements, sm->total_number_of_column_elements-sm->number_of_top_elements);

    unsigned start_index = sm->state_def[state_index]->first_column_element;
    unsigned count = sm->state_def[state_index]->number_of_column_elements;
  
    enable_column_element_state_CFL(input,  start_index, count);
    *column_sm->active_state = state_index;
    *column_sm->state_active = true;


}
void Change_column_element_state_hash_CFL(const void *input, const uint32_t state_hash){

    Column_sm_structure_CFL_t *column_sm =  (Column_sm_structure_CFL_t *) Get_current_column_aux_data(input);
    if(column_sm == NULL){
      ASSERT_PRINT_F(input, "No column_sm found for this column %d \n", get_current_column_index_CFL(input));
    }
    if(*column_sm->sm_active == false){
      ASSERT_PRINT_F(input, "No sm active for this column %d \n", get_current_column_index_CFL(input));
    }
    unsigned sm_index = *column_sm->active_sm;

    const Sm_def_structure_CFL_t *sm = column_sm->sm[sm_index];
    
     for( unsigned i = 0; i < sm->number_of_states  ; i++){
      const State_def_structure_CFL_t *state_def = sm->state_def[i];
    
      if(state_def->name_hash == state_hash){
        Change_column_element_state_index_CFL(input, i);
        return;
      }
    }       
    ASSERT_PRINT_F(input, "No state found for this hash %d \n", state_hash);
}
        

void Change_column_element_state_string_CFL(const void *input, const char *state_hash_string){

    Change_column_element_state_hash_CFL(input, fnv_hash_string_CFL(state_hash_string));
}


bool Reference_sm_active_CFL(const void *input, uint32_t ref_hash){



    Column_sm_structure_CFL_t *column_sm =  (Column_sm_structure_CFL_t *) Get_current_column_aux_data(input);
    if(column_sm == NULL){
      ASSERT_PRINT_F(input, "No column_sm found for this column %d \n", get_current_column_index_CFL(input));
    }
    if(*column_sm->sm_active == false){
     return false;
    }
    unsigned sm_index = *column_sm->active_sm;
    const Sm_def_structure_CFL_t *sm = column_sm->sm[sm_index];
    if(sm->sm_hash == ref_hash){
      return true;
    }
    return false;
}