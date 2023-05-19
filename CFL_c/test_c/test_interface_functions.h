#ifndef __TEST_INTERFACE_FUNCTIONS_H__
#define __TEST_INTERFACE_FUNCTIONS_H__

void debug_write(const void *buf, unsigned count);
void default_idle_function(void *handle,
                                  Time_control_CFL_t *timer_control,
                                  bool init_flag);


void default_calendar_function(void *handle,
                                      Time_control_CFL_t *timer_control,
                                      bool init_flag);

#endif