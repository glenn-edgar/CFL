#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_element_storeage.h"
#include "CFL_symbol_table.h"
#include "CFL_data_flow_functions.h"




typedef struct df_buf_t {
  unsigned short number;
  bool* bit_array;
  Symbol_table_handle_CFL_t  df_symbol_array;
} df_buf_t;

typedef struct df_buf_contol_t {
  unsigned short max_number;
  unsigned short number;
  Hash_cell_control_CFL_t* names;
  df_buf_t* df_buf;
  
} df_buf_contol_t;




static inline void check_position(void* handle, df_buf_t* df_buf, unsigned short* position) {
  (void)handle;
  if (*position >= df_buf->number) {
    ASSERT_PRINT_INT("Bit_Field_Control position exceeded", *position);
  }
}

void allocate_df_buf_space_CFL(void* input, int number_of_df_bufs) {

  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_buf_control = (df_buf_contol_t*)Allocate_once_malloc_CFL(handle, sizeof(df_buf_contol_t));
  handle->df_buf_control = (void*)df_buf_control;

  df_buf_control->max_number = number_of_df_bufs;
  df_buf_control->number = 0;
  if (df_buf_control->max_number == 0) {
    return;
  }
  df_buf_control->names =
    contruct_hash_cell_control_CFL(handle, number_of_df_bufs);

  df_buf_control->df_buf = (df_buf_t*)Allocate_once_malloc_CFL(handle, sizeof(df_buf_t) * number_of_df_bufs);
}



void Define_df_buf_CFL(void* input, const char* buf_name, unsigned short buf_size,unsigned short symbol_number, const Symbol_record_CFL_t* symbol_records) {

  Handle_CFL_t* handle = (Handle_CFL_t*)input;

  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* df_buf;
  int id;

  if (df_control->number >= df_control->max_number) {
    ASSERT_PRINT_INT("To many data flow buffers", df_control->number);
  }


  df_control->number += 1;
  id = Store_Name_CFL(df_control->names, buf_name);
  df_buf = df_control->df_buf + id;
  df_buf->number = buf_size;
  df_buf->bit_array = (bool*)Allocate_once_malloc_CFL(handle, sizeof(bool) * df_buf->number);
  if(symbol_number == 0){
    df_buf->df_symbol_array = NULL;
  }else{
    df_buf->df_symbol_array = Construct_symbol_table_CFL(handle, symbol_number, symbol_records);
  }

}




unsigned short Get_df_buf_index_CFL(void* input, const char* name) {

  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  int id;

  id = Find_Name_CFL(df_control->names, name);
  if (id < 0) {
    ASSERT_PRINT("Data flow buf name not found", name);
  }
  return id;

}



Symbol_table_handle_CFL_t Get_df_buf_symbol_table_CFL(void *input, unsigned short buf_index){
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* df_buf = df_control->df_buf + buf_index;
  
  return df_buf->df_symbol_array;
}



unsigned short Get_df_buf_size_CFL(void* input, unsigned short index) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;

  df_buf_t* df_buf = df_control->df_buf + index;
  return df_buf->number;

}

bool Get_df_buf_value_CFL(void* input, unsigned short buf_index, unsigned short position_index) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;


  df_buf_t* df_buf = df_control->df_buf + buf_index;
  if (position_index >= df_buf->number) {

    ASSERT_PRINT_INT("Data flow buf index exceeded", position_index);
  }
  return *(df_buf->bit_array + position_index);
}


void  Set_df_buf_number_CFL(void* input, unsigned short buf_index, unsigned short position_index, bool value) {

  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;


  df_buf_t* df_buf = df_control->df_buf + buf_index;
  if (position_index >= df_buf->number) {

    ASSERT_PRINT_INT("Data flow buf index exceeded", position_index);
  }
  *(df_buf->bit_array + position_index) = value;
}


void Reset_df_buf_CFL(void* input, unsigned short buf_index, bool value) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* df_buf = df_control->df_buf + buf_index;
  for (int i = 0;i < df_buf->number;i++) {
    *(df_buf->bit_array + i) = value;
  }
}



void Set_df_buf_positions_CFL(void* input, unsigned short buf_index, unsigned short position_number, const unsigned short* position_indexes, bool value) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* df_buf = df_control->df_buf + buf_index;
  for (int i = 0;i < position_number;i++) {
    if (position_indexes[i] >= df_buf->number) {
      ASSERT_PRINT_INT("Data flow buf index exceeded", position_indexes[i]);
    }
    *(df_buf->bit_array + position_indexes[i]) = value;
  }
}

void Copy_df_buff_array_CFL(void* input, unsigned short from_bufF_index, unsigned short to_buff_index, unsigned short from_start, unsigned short to_start, unsigned short number) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* from_buf = df_control->df_buf + from_bufF_index;
  df_buf_t* to_buf = df_control->df_buf + to_buff_index;
  if (from_start + number > from_buf->number) {
    ASSERT_PRINT_INT("Data flow buf from index exceeded", from_start + number);
  }
  if (to_start + number > to_buf->number) {
    ASSERT_PRINT_INT("Data flow buf to index exceeded", to_start + number);
  }
  for (int i = 0;i < number;i++) {
    *(to_buf->bit_array + to_start + i) = *(from_buf->bit_array + from_start + i);
  }

}

bool Match_df_buf_positions_CFL(void* input, unsigned short buf_index, unsigned short position_number, const unsigned short* positions, bool value) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* df_buf = df_control->df_buf + buf_index;
  for (int i = 0;i < position_number;i++) {
    if (positions[i] >= df_buf->number) {
      ASSERT_PRINT_INT("Data flow buf index exceeded", positions[i]);
    }
    if (*(df_buf->bit_array + positions[i]) != value) {
      return false;
    }
  }
  return true;
}



void shift_boolean_array(unsigned buffer_size, bool* buffer, short shift_number,
  unsigned short start, short number_to_shift,bool back_fill, bool fill_value) {
  // Check if buffer limits are exceeded
 
  // Shift the booleans to the right
  if (shift_number > 0) {
    for (int i = start + number_to_shift - 1; i >= start; i--) {
      if(i+shift_number >= (short)buffer_size){
        continue;
      }
      
      buffer[i + shift_number] = buffer[i];

    }
  }
  // Shift the booleans to the left
  else if (shift_number < 0) {
    for (int i = start; i < start + number_to_shift; i++) {
      if(i+shift_number < 0){
        continue;
      }     
       
      buffer[i + shift_number] = buffer[i];

    }
  }
  if(back_fill == false){
    return;
  }

  // Insert the fill value on the shifted values
  int fill_start = shift_number > 0 ? start : start + number_to_shift + shift_number;
  int fill_end = shift_number > 0 ? start + shift_number : start + number_to_shift;
  for (int i = fill_start; i < fill_end; i++) {
    if( (i >= 0 )&& (i < (int)buffer_size ) ){
      buffer[i] = fill_value;
    }
  }



}





void Shift_df_buf_array_CFL(void* input, unsigned short buf_index, int shift_number, unsigned short start, unsigned short number, bool back_fill,bool fill_bit) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* df_buf = df_control->df_buf + buf_index;

  if (shift_number == 0) {
    return;
  }
  
  shift_boolean_array(df_buf->number, df_buf->bit_array, shift_number, start, number,back_fill, fill_bit);



}

void Print_df_buf_CFL(void* input, unsigned short buf_index) {
  Handle_CFL_t* handle = (Handle_CFL_t*)input;
  df_buf_contol_t* df_control = (df_buf_contol_t*)handle->df_buf_control;
  df_buf_t* df_buf = df_control->df_buf + buf_index;
  Printf_CFL("Data flow buffer %d number %d \n", buf_index, df_buf->number);
  for (int i = 0;i < df_buf->number;i++) {
    Printf_CFL("%d ", *(df_buf->bit_array + i));
  }
  Printf_CFL("\n");
}


