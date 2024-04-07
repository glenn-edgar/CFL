
#include "CFL_useful_utilities.h"


int sequence_columns_utility_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
   sequence_columns_CFL_t *sequence_columns = (sequence_columns_CFL_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    if(event_data->event_index == EVENT_INIT_CFL ){
      *sequence_columns->column_index = 0;
      *sequence_columns->state = true;
      return HALT_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
      for(int i = 0; i < sequence_columns->column_number; i++){
        disable_column_CFL(handle, sequence_columns->column_list[i]);
      }
      return DISABLE_CFL;
    }
   
    if(event_data->event_index != TIMER_TICK_CFL){
      return HALT_CFL;
    }
    if(*sequence_columns->state == true){
      if(*sequence_columns->column_index >= sequence_columns->column_number){
              return DISABLE_CFL;
      }
      enable_column_CFL(handle, sequence_columns->column_list[*sequence_columns->column_index]);
      *sequence_columns->state = false;      
    }
    else{
        if(column_state_CFL(handle, sequence_columns->column_list[*sequence_columns->column_index]) == false){
           *sequence_columns->state = true;
           *sequence_columns->column_index = *sequence_columns->column_index + 1;
           if(*sequence_columns->column_index >= sequence_columns->column_number){
              return DISABLE_CFL;
           }
        }   
       
    }
    return HALT_CFL;
}

void *Get_current_column_aux_data( const void *input ){
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  unsigned int column_index = handle->engine_control->current_column_index;
  void *aux_data = handle->column_rom_data[column_index].aux_data;
  return aux_data;
}


// FNV-1a constants
#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U



// Compute the FNV-1a hash of a buffer
uint32_t fnv_hash_CFL(const void *data, uint32_t len) {
  const char *ptr = (const char *)data;
  uint32_t hash = FNV_OFFSET_32;
  for (uint32_t i = 0; i < len; i++) {
    hash ^= ptr[i];
    hash *= FNV_PRIME_32;
  }
  return hash;
}

int fnv_hash_string_CFL(const char *data) {
  uint32_t len;
  len = strlen(data);
  return fnv_hash_CFL(data, len);
}



