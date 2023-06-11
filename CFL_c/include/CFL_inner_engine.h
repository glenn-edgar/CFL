#ifndef __CFL_INNER_ENGINE_H__
#define __CFL_INNER_ENGINE_H__

#include "Cfl_user_functions.h"
#include "Cfl_definitions.h"

void  initialize_columns_CFL(Handle_CFL_t *handle);


bool   process_single_sweep_CFL(Handle_CFL_t *handle, Event_data_CFL_t *event_data);


#endif