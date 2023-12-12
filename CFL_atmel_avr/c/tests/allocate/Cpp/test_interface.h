#ifndef __TEST_INTERFACE_H__
#define __TEST_INTERFACE_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   
void delay_ms(unsigned int milliseconds);

unsigned long long get_elapsed_time_ms(void);

void default_idle_function(void *handle,
                           Time_control_CFL_t *timer_control,
                           bool init_flag);

void default_calendar_function(void *handle,
                               Time_control_CFL_t *timer_control,
                               bool init_flag);



                      


#ifdef __cplusplus
}
#endif




#endif // __TEST_INTERFACE_H__