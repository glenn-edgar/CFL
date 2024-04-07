#ifndef __CFL_BASIC_DEFS_H__
#define __CFL_BASIC_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef struct Event_data_CFL_t
{
  short event_index;
  bool  malloc_flag;
  void* params;
  

} Event_data_CFL_t;


#define ENGINE_TERMINATE_EVENT_CFL -10
#define EVENT_TERMINATION_CFL      -9
#define EVENT_INIT_CFL             -8
#define TIMER_TICK_CFL             -7
#define SECOND_TICK_CFL            -6
#define MINUTE_TICK_CFL            -5
#define HOUR_TICK_CFL              -4
#define DAY_TICK_CFL               -3
#define MONTH_TICK_CFL             -2
#define YEAR_TICK_CFL              -1


#define USER_EVENT_START_CFL        0

#define RPC_CLIENT_RESULT_CFL      0x7ffc
#define RPC_ACTION_COMPLETE_CFL     0x7ffd
#define RPC_NEW_EVENT              0x7ffe
#define  SUPERVISOR_EVENT_CFL      0x7fff
// add event id;s at this point

/*
** Column Functions Return Functions
**
*/

#define CONTINUE_CFL 1
#define DISABLE_CFL 2
#define HALT_CFL 3
#define RESET_CFL 4
#define TERMINATE_CFL 5
#define ENGINE_TERMINATE_CFL 6
#define HALT_AND_DISABLE_CFL 7



typedef void (*One_shot_function_CFL_t)(const void* input, void* params, Event_data_CFL_t* event_data);






typedef bool (*Bool_function_CFL_t)(const void *input, void* params, Event_data_CFL_t* event_data);



typedef int (*State_function_CFL_t)(const void *input, void* params, Event_data_CFL_t* event_data, bool *event_continue_flag);


typedef struct Aggregator_CFL_t
{
  
  void *user_data;
  const uint16_t number_of_columns;
  const uint16_t *list_of_columns;
  void **aggregator_data;
} Aggregator_CFL_t;

typedef void *(*Aggregator_function_CFL_t)(const void *input, Aggregator_CFL_t* params, Event_data_CFL_t* event_data);



typedef int (*Column_function_CFL_t)(const void *input, void *aux_fun, void* params, Event_data_CFL_t* event_data);


#ifdef __cplusplus
}
#endif
#endif