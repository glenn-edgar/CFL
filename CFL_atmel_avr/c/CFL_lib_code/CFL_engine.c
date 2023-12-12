
#include <stdbool.h>
#include <stddef.h>

#include "CFL_engine.h"


void  process_columns_CFL(Handle_CFL_t *handle,uint16_t column_index, uint16_t column_number, Column_function_CFL_t *column_function, bool process_flag);






char  process_column_elements_CFL(Handle_CFL_t *handle, int current_column,int column_element,Column_element_function_CFL_t *column_element_function);

void initialize_event_queue_CFL(Handle_CFL_t *handle);
Event_data_CFL_t peak_event(Handle_CFL_t *handle);
void dequeue_event_CFL(Handle_CFL_t *handle);
void queue_event_CFL(Handle_CFL_t *handle, short event_index, int32_t event_data);
unsigned char get_event_count(Handle_CFL_t *handle);


void start_engine_CFL(Handle_CFL_t *handle, unsigned short time_tick_ms, Idle_function_CFL_t idle_function);


bool  process_columns_array_CFL(Handle_CFL_t *handle, unsigned char column_number, Column_function_CFL_t *column_function){

  for(unsigned char i = 0; i < handle->column_number; i++){
    unsigned char column_state = handle->column_state[i];
    if (column_state & COLUMN_ACTIVE_CFL != 0){
      handle->current_column = i;
      if( column_function(handle,true) == false){
        disable_all_columns(handle);
        return false;
      }
      
    }
  }
  return true;
}

void terminate_column_CFL(Handle_CFL_t *handle, unsigned char column_number, Column_function_CFL_t *column_function, unsigned char column_index){

   Column_function_CFL_t column_function = column_function[column_index];
   column_function(handle,false)
}










bool process_column_element_events_CFL( Handle_CFL_t *handle, 
                                        unsigned char column_element_number,
                                        Column_element_function_CFL_t *column_element, 
                                        unsigned char *column_element_state){

  for(unsigned char i= 0; i< column_element_number; i++){

    unsigned char element_state = column_element_state[i];
    
    if( element_state & COLUMN_ELEMENT_ACTIVE_CFL != 0){
      handle->current_column_element = i;
      if( element_state & COLUMN_ELEMENT_INITIAILIZED_CFL == 0){

          column_function[i](handle,EVENT_INIT_CFL,0 );
          column_element_state[i] |= COLUMN_ELEMENT_INITIAILIZED_CFL;
      }
       Event_data_CFL_t *event_data = peak_event(handle);
      unsigned char return_code = column_element_function( handle, event_data->event_index, event_data->event_data );

      if (return_code == HALT_CFL){
        return true;
      }

      if (return_code == DISABLE_CFL){

        column_element_state[i] &= ~COLUMN_ELEMENT_ACTIVE_CFL;
      }
      if (return_code == TERMINATE_CFL)
        disable_column(handle);
      }
      if return_code == TERMINATE_ENGINE_CFL){
        return false;
      }
    }
  }
  return true;
}

void terminate_column_element_events_CFL( Handle_CFL_t *handle, 
                                        unsigned char column_element_number,
                                        Column_element_function_CFL_t *column_element, 
                                        unsigned char *column_element_state){

  for(unsigned char i = column_element_number; i--; i >= 0){

    unsigned char element_state = column_element_state[i];
    
    if( element_state & COLUMN_ELEMENT_ACTIVE_CFL != 0){
      handle->current_column_element = i;
      if( element_state & COLUMN_ELEMENT_INITIAILIZED_CFL == 0){

          column_function[i](handle,EVENT_TERMINATION_CFL,0 );
          column_element_state[i] = 0;
          
      }

  }
  return true;
}



static void enable_column(Handle_CFL_t *handle, unsigned char column_index){
  handle->column_state[column_index] |= COLUMN_ACTIVE_CFL;
  // need to add code to enable column elements
}

static void disable_column(Handle_CFL_t *handle, unsigned char column_index){
  handle->column_state[column_index] &= ~COLUMN_ACTIVE_CFL;
  
}

static disable_all_columns(Handle_CFL_t *handle){
  for(unsigned char i = 0; i < handle->column_number; i++){
     disable_column(handle,i);
  }
}