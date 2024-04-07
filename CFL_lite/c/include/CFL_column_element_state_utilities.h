#ifndef CFL_COLUMN_ELEMENT_STATE_UTILITIES_H
#define CFL_COLUMN_ELEMENT_STATE_UTILITIES_H

#include "CFL_inner_engine.h"
#include "CFL_useful_utilities.h"

#define NO_STATE_CHANGE_CFL -1
#define BLOCK_STATE_EVENT_CFL -2
#define STATE_MACHINE_END_CFL -3

typedef struct State_def_structure_ROM_CFL_t
{
  const unsigned state_index;
  const unsigned name_hash;
  const unsigned first_column_element;
  const unsigned number_of_column_elements;
} State_def_structure_CFL_t;

typedef struct Sm_def_structure_CFL_t
{
  
  const uint16_t sm_index;
  const uint16_t number_of_states;
  const uint32_t sm_hash;
 
  const uint16_t first_column_element;
  const uint16_t total_number_of_column_elements;

  const uint16_t number_of_top_elements;

  const State_def_structure_CFL_t **state_def;
} Sm_def_structure_CFL_t;







typedef struct Column_sm_structure_CFL_t
{

bool *sm_active;
uint16_t *active_sm;
bool *state_active;
uint16_t *active_state;
const unsigned number_of_sm;
const Sm_def_structure_CFL_t **sm;

} Column_sm_structure_CFL_t;


void Initial_column_element_structures_CFL(const void *input);

bool Get_sm_state_CFL(const void *input, uint16_t *active_sm, uint16_t *active_state );
void Disable_all_sm_CFL(const void *input);
void Disable_column_element_sm_current_CFL(const void *input);

void Enable_column_element_sm_CFL(const void *input, const uint16_t sm_index);
void Enable_column_element_sm_hash_CFL(const void *input, const uint32_t sm_hash);
void Enable_column_element_sm_string_CFL(const void *input, const char *sm_string);



void Change_column_element_state_index_CFL(const void *input, const uint16_t state_index);
void Change_column_element_state_hash_CFL(const void *input,  const uint32_t state_hash);
void Change_column_element_state_string_CFL(const void *input, const char *state_string);
bool Reference_sm_active_CFL(const void *input, uint32_t ref_hash);












#endif // CFL_COLUMN_ELEMENT_STATE_UTILITIES_H
