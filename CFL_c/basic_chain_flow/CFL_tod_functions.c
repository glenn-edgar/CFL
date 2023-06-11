#include "CFL_user_functions.h"
#include "CFL_tod_functions.h"



static bool test_tod_condition_lt(void *input, void *user_data, Event_data_CFL_t *event_data);
static bool test_tod_condition_le(void *input, void *user_data, Event_data_CFL_t *event_data);
static bool test_tod_condition_eq(void *input, void *user_data, Event_data_CFL_t *event_data);
static bool test_tod_condition_ge(void *input, void *user_data, Event_data_CFL_t *event_data);
static bool test_tod_condition_gt(void *input, void *user_data, Event_data_CFL_t *event_data);

static void fill_out_wait_tod(void *input, const char *test_function, short doy, short month, short dow, short hour, short minute, short second);
static void fill_out_verify_tod(void *input, const char *test_function, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char *failure_fn, void *user_data);

void Initialize_bool_functions_CFL(void *input)
{
    Store_bool_function_CFL(input, "test_tod_lt", test_tod_condition_lt);
    Store_bool_function_CFL(input, "test_tod_le", test_tod_condition_le);
    Store_bool_function_CFL(input, "test_tod_eq", test_tod_condition_eq);
    Store_bool_function_CFL(input, "test_tod_ge", test_tod_condition_ge);
    Store_bool_function_CFL(input, "test_tod_gt", test_tod_condition_gt);
}

void Asm_wait_tod_lt(void *input, short doy, short month, short dow, short hour, short minute, short second)
{

    fill_out_wait_tod(input, "test_tod_lt", doy, month, dow, hour, minute, second);
}
void Asm_wait_tod_le(void *input, short doy, short month, short dow, short hour, short minute, short second)
{

    fill_out_wait_tod(input, "test_tod_le", doy, month, dow, hour, minute, second);
}
void Asm_wait_tod_eq(void *input, short doy, short month, short dow, short hour, short minute, short second)
{

    fill_out_wait_tod(input, "test_tod_eq", doy, month, dow, hour, minute, second);
}
void Asm_wait_tod_ge(void *input, short doy, short month, short dow, short hour, short minute, short second)
{

    fill_out_wait_tod(input, "test_tod_ge", doy, month, dow, hour, minute, second);
}
void Asm_wait_tod_gt(void *input, short doy, short month, short dow, short hour, short minute, short second)
{

    fill_out_wait_tod(input, "test_tod_gt", doy, month, dow, hour, minute, second);
}

void Asm_verify_tod_lt(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char *failure_function,void *user_data)
{

    fill_out_verify_tod(input, "test_tod_lt", doy, month, dow, hour, minute, second, terminate_flag,failure_function,user_data);
}

void Asm_verify_tod_le(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char *failure_function,void *user_data)
{

    fill_out_verify_tod(input, "test_tod_le", doy, month, dow, hour, minute, second, terminate_flag,failure_function,user_data);
}

void Asm_verify_tod_eq(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char *failure_function,void *user_data)
{

    fill_out_verify_tod(input, "test_tod_eq", doy, month, dow, hour, minute, second, terminate_flag,failure_function,user_data);
}

void Asm_verify_tod_ge(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char *failure_function,void *user_data)
{

    fill_out_verify_tod(input, "test_tod_ge", doy, month, dow, hour, minute, second, terminate_flag,failure_function,user_data);
}
void Asm_verify_tod_gt(void *input, short doy, short month, short dow, short hour, short minute, short second, bool terminate_flag,const char *failure_function,void *user_data)
{

    fill_out_verify_tod(input, "test_tod_gt", doy, month, dow, hour, minute, second, terminate_flag,failure_function,user_data);
}

static void fill_out_wait_tod(void *input, const char *test_function, short doy, short month, short dow, short hour, short minute, short second)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Wait_tod_CFL_t));
    wait_tod->day_of_year = doy;
    wait_tod->month = month;
    wait_tod->day_of_week = dow;
    wait_tod->hour = hour;
    wait_tod->minute = minute;
    wait_tod->second = second;
    wait_tod->user_data = NULL;
    wait_tod->terminate_flag = false;
    Asm_wait_CFL(input, test_function, NO_TIME_OUT_CFL, true, NULL, wait_tod);
}

static void fill_out_verify_tod(void *input, const char *test_function, short Doy, short month, short dow, short hour, short minute, short second, bool terminate_flag, const char *failure_function,void *user_data)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)Allocate_once_malloc_CFL(input, sizeof(Wait_tod_CFL_t));
    wait_tod->day_of_year = Doy;
    wait_tod->month = month;
    wait_tod->day_of_week = dow;
    wait_tod->hour = hour;
    wait_tod->minute = minute;
    wait_tod->second = second;
    wait_tod->user_data = user_data;
    wait_tod->terminate_flag = terminate_flag;
    Asm_verify_CFL(input, test_function, terminate_flag,failure_function, wait_tod);
}

static bool test_tod_condition_lt(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)user_data;
    Time_control_CFL_t *time_control = Get_time_control_CFL(input);
    if (wait_tod->day_of_year >= 0)
    {
        if (time_control->day_of_year >= wait_tod->day_of_year)
        {
            return false;
        }
    }
    if (wait_tod->month >= 0)
    {
        if (time_control->month >= wait_tod->month)
        {
            return false;
        }
    }
    if (wait_tod->day_of_week >= 0)
    {
        if (time_control->dow >= wait_tod->day_of_week)
        {
            return false;
        }
    }
    if (wait_tod->hour >= 0)
    {
        if (time_control->hour >= wait_tod->hour)
        {
            return false;
        }
    }
    if (wait_tod->minute >= 0)
    {
        if (time_control->minute >= wait_tod->minute)
        {
            return false;
        }
    }
    if (wait_tod->second >= 0)
    {
        if (time_control->second >= wait_tod->second)
        {
            return false;
        }
    }

    return true;
}

static bool test_tod_condition_le(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)user_data;
    Time_control_CFL_t *time_control = Get_time_control_CFL(input);
    if (wait_tod->day_of_year >= 0)
    {
        if (time_control->day_of_year >= wait_tod->day_of_year)
        {
            return false;
        }
    }
    if (wait_tod->month >= 0)
    {
        if (time_control->month >= wait_tod->month)
        {
            return false;
        }
    }
    if (wait_tod->day_of_week >= 0)
    {
        if (time_control->dow >= wait_tod->day_of_week)
        {
            return false;
        }
    }
    if (wait_tod->hour >= 0)
    {
        if (time_control->hour >= wait_tod->hour)
        {
            return false;
        }
    }
    if (wait_tod->minute >= 0)
    {
        if (time_control->minute >= wait_tod->minute)
        {
            return false;
        }
    }
    if (wait_tod->second >= 0)
    {
        if (time_control->second >= wait_tod->second)
        {
            return false;
        }
    }

    return true;
}

static bool test_tod_condition_eq(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)user_data;
    Time_control_CFL_t *time_control = Get_time_control_CFL(input);
    if (wait_tod->day_of_year >= 0)
    {
        if (time_control->day_of_year != wait_tod->day_of_year)
        {
            return false;
        }
    }
    if (wait_tod->month >= 0)
    {
        if (time_control->month != wait_tod->month)
        {
            return false;
        }
    }
    if (wait_tod->day_of_week >= 0)
    {
        if (time_control->dow != wait_tod->day_of_week)
        {
            return false;
        }
    }
    if (wait_tod->hour >= 0)
    {
        if (time_control->hour != wait_tod->hour)
        {
            return false;
        }
    }
    if (wait_tod->minute >= 0)
    {
        if (time_control->minute != wait_tod->minute)
        {
            return false;
        }
    }
    if (wait_tod->second >= 0)
    {
        if (time_control->second != wait_tod->second)
        {
            return false;
        }
    }

    return true;
}

static bool test_tod_condition_ge(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)user_data;
    Time_control_CFL_t *time_control = Get_time_control_CFL(input);
    if (wait_tod->day_of_year >= 0)
    {
        if (time_control->day_of_year < wait_tod->day_of_year)
        {
            return false;
        }
    }
    if (wait_tod->month >= 0)
    {
        if (time_control->month < wait_tod->month)
        {
            return false;
        }
    }
    if (wait_tod->day_of_week >= 0)
    {
        if (time_control->dow < wait_tod->day_of_week)
        {
            return false;
        }
    }
    if (wait_tod->hour >= 0)
    {
        if (time_control->hour < wait_tod->hour)
        {
            return false;
        }
    }
    if (wait_tod->minute >= 0)
    {
        if (time_control->minute < wait_tod->minute)
        {
            return false;
        }
    }
    if (wait_tod->second >= 0)
    {
        if (time_control->second < wait_tod->second)
        {
            return false;
        }
    }

    return true;
}

static bool test_tod_condition_gt(void *input, void *user_data, Event_data_CFL_t *event_data)
{
    Wait_tod_CFL_t *wait_tod = (Wait_tod_CFL_t *)user_data;
    Time_control_CFL_t *time_control = Get_time_control_CFL(input);
    if (wait_tod->day_of_year >= 0)
    {
        if (time_control->day_of_year <= wait_tod->day_of_year)
        {
            return false;
        }
    }
    if (wait_tod->month >= 0)
    {
        if (time_control->month <= wait_tod->month)
        {
            return false;
        }
    }
    if (wait_tod->day_of_week >= 0)
    {
        if (time_control->dow <= wait_tod->day_of_week)
        {
            return false;
        }
    }
    if (wait_tod->hour >= 0)
    {
        if (time_control->hour <= wait_tod->hour)
        {
            return false;
        }
    }
    if (wait_tod->minute >= 0)
    {
        if (time_control->minute <= wait_tod->minute)
        {
            return false;
        }
    }
    if (wait_tod->second >= 0)
    {
        if (time_control->second <= wait_tod->second)
        {
            return false;
        }
    }

    return true;
}
