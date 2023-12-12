#ifndef __CFL_BASIC_DEFS_H__
#define __CFL_BASIC_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>





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





#ifdef __cplusplus
}
#endif
#endif