#ifndef CFL_USEFUL_UTILITIES_H
#define CFL_USEFUL_UTILITIES_H

#include "CFL_inner_engine.h"
typedef struct sequence_columns_CFL_t
{
  unsigned short column_number;
  const unsigned short *column_list;
  unsigned short *column_index;
  bool *state;
} sequence_columns_CFL_t;

int sequence_columns_utility_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

void *Get_current_column_aux_data(const void *input);

uint32_t fnv_hash_CFL(const void *data, uint32_t len);
int fnv_hash_string_CFL(const char *data);


#endif