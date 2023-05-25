#include "CFL_user_functions.h"
#include "CFL_tod_functions.h"


typedef struct Wait_tod_CFL_t{
   short day_of_year;
    short month;
    short day_of_week;
    short hour;
    short minute;
}Wait_tod_CFL_t;

static bool test_tod_condition(void *input, void *user_data, Event_data_CFL_t *event_data);

void Initialize_bool_functions_CFL(void *input)
{
    Store_bool_function_CFL(input, "test_tod", test_tod_condition);
}

void Asm_wait_tod(void *input, short Doy, short month, short dow, short hour, short minute)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Wait_tod_CFL_t));
    wait_tod->day_of_year = Doy;
    wait_tod->month = month;
    wait_tod->day_of_week = dow;
    wait_tod->hour = hour;
    wait_tod->minute = minute;
    Asm_wait_CFL(input,"test_tod",NO_TIME_OUT_CFL,true,NULL,wait_tod);

}

void Asm_verify_tod(void *input, short Doy, short month, short dow, short hour, short minute, bool terminate_flag)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Wait_tod_CFL_t));
    wait_tod->day_of_year = Doy;
    wait_tod->month = month;
    wait_tod->day_of_week = dow;
    wait_tod->hour = hour;
    wait_tod->minute = minute;
    Asm_verify_CFL(input,"test_tod",terminate_flag,NULL, wait_tod);
}


static bool test_tod_condition(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)user_data;
    if (wait_tod->day_of_year >=  0 )
    {
        // do test
    }
    if (wait_tod->month >=  0 )
    {
        // do test
    }
    if (wait_tod->day_of_week >= 0 )
    {
        // do test
    }
    if (wait_tod->hour >= 0 )
    {
       // do test
    }
    if (wait_tod->minute >= 0 )
    {
        //do test
    }
    return true;
    
}

