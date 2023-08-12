#ifndef __TEST_INTERFACE_H__
#define __TEST_INTERFACE_H__

void delay_ms(unsigned int milliseconds);

unsigned long long get_elapsed_time_ms(void);

void default_idle_function(void *handle,
                           Time_control_CFL_t *timer_control,
                           bool init_flag);

void default_calendar_function(void *handle,
                               Time_control_CFL_t *timer_control,
                               bool init_flag);



                      






#endif // __TEST_INTERFACE_H__