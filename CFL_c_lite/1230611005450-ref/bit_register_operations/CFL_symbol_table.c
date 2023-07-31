#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_debug.h"
#include "Cfl_element_storeage.h"


typedef struct symbol_record_t {
    int value;
    int type;
}symbol_record_t;


typedef struct df_symbol_control_t {
    unsigned short number_symbols;
    symbol_record_t* symbol_array;
    Hash_cell_control_CFL_t* names;
} df_symbol_control_t;



Symbol_table_handle_CFL_t Construct_symbol_table_CFL(void* input, unsigned short symbol_number, const Symbol_record_CFL_t* symbol_array) {

    df_symbol_control_t* df_symbol_control = (df_symbol_control_t*)Allocate_once_malloc_CFL(input, sizeof(df_symbol_control_t));

    df_symbol_control->number_symbols = symbol_number;
    df_symbol_control->symbol_array = (symbol_record_t*)Allocate_once_malloc_CFL(input, sizeof(symbol_record_t) * symbol_number);
    df_symbol_control->names = contruct_hash_cell_control_CFL(input, symbol_number);
    for (int i = 0;i < symbol_number;i++) {
        Store_Name_CFL(df_symbol_control->names, symbol_array[i].name);
        (df_symbol_control->symbol_array + i)->value = symbol_array[i].value;
        (df_symbol_control->symbol_array + i)->type = symbol_array[i].type;
    }
    return df_symbol_control;
}



bool Get_symbol_table_entry_CFL(void* input, Symbol_table_handle_CFL_t symbol_hamdle, const char* name, int* value, int* type) {
    df_symbol_control_t* symbol_record_control = (df_symbol_control_t*)symbol_hamdle;
    (void)input;
    int id = Find_Name_CFL(symbol_record_control->names, name);
    if (id < 0) {
        return false;
    }
    *value = symbol_record_control->symbol_array[id].value;
    *type = symbol_record_control->symbol_array[id].type;
    return true;
}
