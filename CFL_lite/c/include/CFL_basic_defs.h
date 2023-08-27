#ifndef __CFL_BASIC_DEFS_H__
#define __CFL_BASIC_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct Event_data_CFL_t
{
  short event_index;
  bool  malloc_flag;
  void* params;
  

} Event_data_CFL_t;



#define RETICK_EVENT_CFL           -11   
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


typedef void (*One_shot_function_CFL_t)(const void* input, void* params, Event_data_CFL_t* event_data);

typedef struct If_control_CFL_t
{
  unsigned short column_number;
  unsigned short* column_indexes;
  bool* return_indexes;
  One_shot_function_CFL_t termination_fn;
  void* user_data;
} If_control_CFL_t;

typedef struct Try_column_CFL_t
{
  bool init_flag;
  bool invert_flag;
  bool terminate_flag;
  unsigned char progress_step;
  unsigned short current_column_index;
  unsigned short column_number;
  unsigned short* column_indexes;
  bool final_state;
  void* user_data;

} Try_column_CFL_t;






typedef bool (*Bool_function_CFL_t)(const void *input, void* params, Event_data_CFL_t* event_data);
typedef void (*If_function_CFL_t)(const void *input, If_control_CFL_t* params);
typedef void (*Try_function_CFL_t)(const void *input, Try_column_CFL_t* params);






typedef union {
    One_shot_function_CFL_t   one_shot_fn;
    Bool_function_CFL_t       bool_fn;
    If_function_CFL_t         if_fn;
    Try_function_CFL_t        try_fn;
    
} CFL_fn_t;
          
typedef int (*Column_function_CFL_t)(const void *input, void *aux_fun, void* params, Event_data_CFL_t* event_data);


#ifdef __cplusplus
}
#endif
#endif