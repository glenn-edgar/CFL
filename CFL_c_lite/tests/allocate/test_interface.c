#include <unistd.h>

#include <time.h>
#include "CFL_inner_engine.h"


void delay_ms(unsigned int milliseconds)
{
    struct timespec delay;
    delay.tv_sec = milliseconds / 1000;
    delay.tv_nsec = (milliseconds % 1000) * 1000000;

    nanosleep(&delay, NULL);
}

unsigned long long get_elapsed_time_ms(void)
{
    struct timespec currentTime;
    clock_gettime(CLOCK_MONOTONIC, &currentTime);
    return (unsigned long long)(currentTime.tv_sec * 1000LL + currentTime.tv_nsec / 1000000);
}

void default_idle_function(void *handle,
                           Time_control_CFL_t *timer_control,
                           bool init_flag)
{
    Event_data_CFL_t event_data;
    if (init_flag == true)
    {
        timer_control->start_millis = get_elapsed_time_ms();
        timer_control->current_millis = timer_control->start_millis;
        timer_control->ms_fn = get_elapsed_time_ms;
    }
    else
    {
        
        delay_ms(timer_control->tick_ms);
        timer_control->current_millis = get_elapsed_time_ms();
        timer_control->start_millis = timer_control->current_millis;
        event_data.event_index = TIMER_TICK_CFL;
        
        event_data.params = &timer_control->tick_ms;
        event_data.malloc_flag = false;
       queue_global_event_CFL(handle, &event_data);
    }
}

void default_calendar_function(void *handle,
                               Time_control_CFL_t *timer_control,
                               bool init_flag)
{
    Event_data_CFL_t event_data;

    time_t currentTime;
    struct tm *timeInfo;
    
    if (init_flag == true)
    {
        
        time(&currentTime);
        timeInfo = localtime(&currentTime);
        timer_control->second = timeInfo->tm_sec;
        timer_control->minute = timeInfo->tm_min;
        timer_control->hour = timeInfo->tm_hour;
        timer_control->day = timeInfo->tm_mday;
        timer_control->dow = timeInfo->tm_wday;
        timer_control->month = timeInfo->tm_mon;
        // time_control->month = timeInfo->tm_mon + 1;  // Months are zero-based, so add 1
        timer_control->year = timeInfo->tm_year + 1900; // Years are measured from 1900
       
    }
    else
    {
       

        time(&currentTime);
        timeInfo = localtime(&currentTime);
        if (timer_control->second != timeInfo->tm_sec)
        {
            event_data.event_index = SECOND_TICK_CFL;
            event_data.params = &timeInfo->tm_sec;
            event_data.malloc_flag = false;
            queue_global_event_CFL(handle, &event_data);
          
           
        }
        timer_control->second = timeInfo->tm_sec;
        if (timer_control->minute != timeInfo->tm_min)
        {
            event_data.event_index = MINUTE_TICK_CFL;
            event_data.params = &timeInfo->tm_min;
            event_data.malloc_flag = false;
            queue_global_event_CFL(handle, &event_data);
           
           
        }
        timer_control->minute = timeInfo->tm_min;
        if (timer_control->hour !=timeInfo->tm_hour)
        {
            event_data.event_index = HOUR_TICK_CFL;
            event_data.params = &timeInfo->tm_hour;
            event_data.malloc_flag = false;
            queue_global_event_CFL(handle, &event_data);
            
        }
        timer_control->hour = timeInfo->tm_hour;
        if (timer_control->day != timeInfo->tm_mday)
        {
            event_data.event_index = DAY_TICK_CFL;
            event_data.params = &timeInfo->tm_mday;
            event_data.malloc_flag = false;
            queue_global_event_CFL(handle, &event_data);
        }
        timer_control->day = timeInfo->tm_mday;

        timer_control->dow = timeInfo->tm_wday;

        if (timer_control->month != timeInfo->tm_mon)
        {
            event_data.event_index = MONTH_TICK_CFL;
            event_data.params = &timeInfo->tm_mon;
            event_data.malloc_flag = false;
            queue_global_event_CFL(handle, &event_data);
        }
        timer_control->month = timeInfo->tm_mon;
        timer_control->month = timeInfo->tm_mon + 1;  // Months are zero-based, so add 1

        if (timer_control->year != timeInfo->tm_year + 1900)
        {
            event_data.event_index = YEAR_TICK_CFL;
            event_data.params = &timeInfo->tm_year;
            event_data.malloc_flag = false;
            queue_global_event_CFL(handle, &event_data);
        }
        timer_control->year = timeInfo->tm_year + 1900; // Years are measured from 1900
       
    }
}
