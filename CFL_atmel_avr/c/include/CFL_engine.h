#ifndef __CFL_ENGINE_H__
#define __CFL_ENGINE_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <stdint.h>


typedef struct Event_data_CFL_t
{
  short event_index;
  int32_t event_data;
} Event_data_CFL_t;

typedef struct Event_queue_CFL_t{
    unsigned char    count;
    unsigned char    rx;
    unsigned char    tx;
    Event_data_CFL_t *event_data;

} Event_queue_CFL_t;


typedef struct Time_control_CFL_t 
{
    unsigned short tick_ms;
    unsigned long  time;
}Time_control_CFL_t;


typedef struct Handle_CFL_t
{
  unsigned char          current_column;
  unsigned char          current_column_element;
  Time_control_CFL_t     *time_control;
  Event_queue_CFL_t     *event_queue;
  unsigned char          column_number;
  Column_function_CFL_t *column_function;
  bool                  *column_states;
  Idle_function_CFL_t    idle_function;
} Handle_CFL_t;


typedef void (*Idle_function_CFL_t)(Handle_CFL_t *handle,bool init_flag);


typedef void (*Column_function_CFL_t)(Handle_CFL_t *handle, bool process_flag);
typedef short (*Column_element_function_CFL_t)(Handle_CFL_t *handle, unsigned char process_flag);

void  process_columns_CFL(Handle_CFL_t *handle,uint16_t column_index, uint16_t column_number, Column_function_CFL_t *column_function, bool process_flag);
char  process_column_elements_CFL(  Handle_CFL_t *handle, 
                                    int current_column,
                                    int column_element,
                                    Column_element_function_CFL_t *column_element_function,
                                    short event_index,
                                    int32_t event_data );

void initialize_event_queue_CFL(Handle_CFL_t *handle);
Event_data_CFL_t peak_event(Handle_CFL_t *handle);
void dequeue_event_CFL(Handle_CFL_t *handle);
void queue_event_CFL(Handle_CFL_t *handle, short event_index, int32_t event_data);
unsigned char get_event_count(Handle_CFL_t *handle);

void initialize_engine_CFL(Handle_CFL_t *handle);
void start_engine_CFL(Handle_CFL_t *handle, unsigned short time_tick_ms, Idle_function_CFL_t idle_function);


#ifdef __cplusplus
}
#endif




#endif