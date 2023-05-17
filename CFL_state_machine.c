#include "CFL_user_functions.h"
#include "CFL_definitions.h"
#include "CFL_debug.h"
#include "CFL_element_storeage.h"
#include "CFL_state_machine.h"

typedef struct States_def_CFL_t
{
    unsigned short number_of_chains;
    unsigned short *active_chains;
    void *user_data;
} States_def_CFL_t;

typedef struct State_dictionary_CFL_t
{
    unsigned short max_number_of_states;
    unsigned short current_number_of_states;
    States_def_CFL_t *state_cells;
} State_dictionary_CFL_t;

typedef struct Sm_control_CFL_t
{
    bool active;
    unsigned short initial_state;
    unsigned short number_of_states;
    States_def_CFL_t *starting_state;
    Hash_cell_control_CFL_t *names;
    void *user_data;
} Sm_control_CFL_t;

typedef struct Sm_dictionary_CFL_t
{
    unsigned short max_sm_number;
    unsigned short current_sm_number;
    Hash_cell_control_CFL_t *names;
    Sm_control_CFL_t *sm_control;
} Sm_dictionary_CFL_t;

static inline States_def_CFL_t *find_starting_state(Handle_CFL_t *handle)
{
    State_dictionary_CFL_t *state_dictionary = (State_dictionary_CFL_t *)handle->state_dictionary;
    States_def_CFL_t *state_cells = state_dictionary->state_cells;
    return state_cells + state_dictionary->current_number_of_states;
}
#if 0
static inline bool is_sm_generation_active(Handle_CFL_t *handle){
    bool active =  handle->sm_assembly;
    return active;

}

static inline void set_sm_index(Handle_CFL_t *handle, bool value){
    handle->sm_assembly =value;

}

static inline unsigned short get_sm_index(Handle_CFL_t *handle){
    unsigned  short index = (unsigned ) handle->sm_assembly_state_index;
    return index;
}

static inline void set_sm_state_index(Handle_CFL_t *handle, unsigned short index){
    handle->sm_assembly_state_index = index;
}
#endif

void allocate_state_machine_CFL(void *input, unsigned short number_of_state_machines)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;

    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_dictionary_CFL_t));
    handle->sm_dictionary = sm_dictionary;

    
    sm_dictionary->max_sm_number = number_of_state_machines;
    sm_dictionary->current_sm_number = 0;
    if(number_of_state_machines == 0){
        sm_dictionary->sm_control = NULL;
        sm_dictionary->names = NULL;
        return;
    }
    sm_dictionary->names = contruct_hash_cell_control_CFL(handle, number_of_state_machines);
    sm_dictionary->sm_control = (Sm_control_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(Sm_control_CFL_t) * number_of_state_machines);
}

void allocate_state_space_CFL(void *input, unsigned short number_of_states)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
   
    if(number_of_states == 0){
       
        handle->state_dictionary = NULL;
        return;
    }
    State_dictionary_CFL_t *state_dictionary = (State_dictionary_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(State_dictionary_CFL_t) * number_of_states);
    state_dictionary->max_number_of_states = number_of_states;
    state_dictionary->current_number_of_states = 0;
    
    States_def_CFL_t *state_cells = (States_def_CFL_t *)Allocate_once_malloc_CFL(handle, sizeof(States_def_CFL_t) * number_of_states);

    state_dictionary->max_number_of_states = number_of_states;
    state_dictionary->current_number_of_states = 0;
    state_dictionary->state_cells = state_cells;

    for (int i = 0; i < number_of_states; i++)
    {
        state_cells[i].number_of_chains = 0;
        state_cells[i].active_chains = NULL;
        state_cells[i].user_data = NULL;
    }
    handle->state_dictionary = state_dictionary;
}

void Define_state_machines_CFL(void *input, unsigned short number_of_states, char **state_names)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)handle->sm_dictionary;

    if (sm_dictionary->current_sm_number + number_of_states >= sm_dictionary->max_sm_number)
    {
        ASSERT_PRINT("Error: Too many state machines", "");
    }

    for (int i = 0; i < number_of_states; i++)
    {
        int id = Store_Name_CFL(sm_dictionary->names, state_names[i]);
        if (id == -1)
        {
            ASSERT_PRINT("Error: Duplicate state name %s\n", state_names[i]);
        }
    }
}

void Asm_define_sm(void *input, char *sm_name, unsigned number_of_states, const char **state_names, char *initial_state, void *user_data)
{

    Handle_CFL_t *handle = (Handle_CFL_t *)input;

    if (handle->sm_assembly == true)
    {
        ASSERT_PRINT("Error: State machine generation should not be active", "");
    }
    handle->sm_assembly = true;

    // find sm_context structure
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short sm_index = Find_Name_CFL(sm_dictionary->names, sm_name);
    if (sm_index == -1)
    {
        ASSERT_PRINT_F("Error: State machine name %s not found", sm_name);
    }
    handle->sm_control_index = sm_index;

    Sm_control_CFL_t *sm_control = sm_dictionary->sm_control + sm_index;
    sm_control->active = false;
    sm_control->number_of_states = number_of_states,
    sm_control->starting_state = find_starting_state(handle);
    sm_control->user_data = user_data;
    sm_control->names = contruct_hash_cell_control_CFL(handle, number_of_states);
    for (int i = 0; i < number_of_states; i++)
    {
        int id = Store_Name_CFL(sm_control->names, state_names[i]);
        if (id == -1)
        {
            ASSERT_PRINT_F("Error: Duplicate state name %s\n", state_names[i]);
        }
    }
    short initial_state_id = Find_Name_CFL(sm_control->names, initial_state);
    if (initial_state_id == -1)
    {
        ASSERT_PRINT_F("Error: Initial state name %s not found", initial_state);
    }
    sm_control->initial_state = initial_state_id;
}

void Asm_define_state_CFL(void *input, const char *state_name,unsigned short chain_number, const char **chain_names,void *user_data){
    // find state machine structure
    // find state machine context
    // id state index
    // increment state index
    // store chain indexs into state machine
    // store user data

#if 0
   Handle_CFL_t* handle = (Handle_CFL_t*)input;
   State_context_CFL_t*   state_context;
   State_context_CFL_t   current_state;
   States_def_CFL_t      new_state;
   Sm_control_CFL_t *sm_control = (Sm_control_CFL_t*)handle->sm_control;
   if(is_sm_generation_active(handle) == false){
       ASSERT_PRINT("Error: State machine generation should  be active","");
   }
   short index = get_sm_index(handle);
   current_state = sm_control->state_control[index];
   short id = Store_Name_CFL(current_state.names, state_name);
   if(Store_Name_CFL(current_state.names, state_name) == -1){
       ASSERT_PRINT("Error: Duplicate state name %s\n", state_name);
   }
   new_state = current_state.state_control[id];
    new_state.number_of_chains = chain_number;
    new_state.active_chains = (unsigned short*)Allocate_once_malloc_CFL(handle, sizeof(unsigned short)*chain_number);
    new_state.user_data = user_data;
    for(int i = 0; i < chain_number; i++){
        new_state.active_chains[i] = Find_Name_CFL(sm_control->names, chain_names[i]);
    }
#endif
}

void Asm_end_state_machine_CFL(void *input){
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    //Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    //Sm_control_CFL_t *sm_control = sm_dictionary->sm_control + handle->sm_control_index;


    handle->sm_assembly = false;
    // verify that all states have been defined
    // set state machine control to inactive

#if 0 
   Handle_CFL_t* handle = (Handle_CFL_t*)input;
   State_context_CFL_t   state_context;
   Sm_control_CFL_t *sm_control = (Sm_control_CFL_t*)handle->sm_control;
   if(is_sm_generation_active(handle) == true){
       ASSERT_PRINT("Error: State machine generation should not be active","");
   }
    short index = get_sm_index(handle);
    state_context = sm_control->state_control[index];
    state_context.stating_state = Find_Name_CFL(state_context.names, starting_state);
    set_sm_index(handle, false);
#endif 
}
#if 0
static void check_for_undefined_columns(Handle_CFL_t *handle)
{
  Column_control_CFL_t *column_control;
  Column_CFL_t *column;
  int column_number;

  column_control = (Column_control_CFL_t *)handle->columns;
  column = column_control->column;
  column_number = column_control->current_number;

  for (int i = 0; i < column_number; i++)
  {
    if (column->defined == false)
    {
      ASSERT_PRINT("undefined column",
                   (column_control->column_names->cell_array + i)->name);
    }
    column++;
  }
}
#endif


#if 0
void Asm_enable_state_machine_CFL(void *input,const char *state_machine_name, const char *state_name){
  // find state machine
  // if active find running state and disable running chains
  // find new state and enable running chains
  // set state machine control to active

}


void Asm_disable_state_machine_CFL(void *input,const char *state_machine_name){
  // find state machine
    // if active find running state and disable running chains
    // set state machine control to inactive

}

void Asm_change_state_CFL(void *input, const char *state_machine_name, const char *state_name){
   Asm_disable_state_machine_CFL(input,state_machine_name);
   Asm_enable_state_machine_CFL(input,state_machine_name, state_name);
}





void Asm_dump_state_machines_CFL(void *input ){


}

void *Get_state_machine_user_data_CFL(void *input, const char *state_machine_name){
  return NULL;
}

void *Get_state_user_data_CFL(void *input, const char *state_machine_name, const char *state_name){
  return NULL;
}  


void Set_state_machine_user_data_CFL(void *input, const char *state_machine_name, void *user_data){

}

void Set_state_user_data_CFL(void *input, const char *sm_name, const char *state_name, void *user_data){

}
#endif

/***********************  Run time support    *********************************************/
bool State_machine_is_active_CFL(void *input, const char *state_machine_name)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Sm_dictionary_CFL_t *sm_dictionary = (Sm_dictionary_CFL_t *)handle->sm_dictionary;
    short index = Find_Name_CFL(sm_dictionary->names, state_machine_name);
    if (index == -1)
    {
        ASSERT_PRINT("Error: State machine name %s not found", state_machine_name);
    }
    Sm_control_CFL_t state_context = sm_dictionary->sm_control[index];
    return state_context.active;
}
