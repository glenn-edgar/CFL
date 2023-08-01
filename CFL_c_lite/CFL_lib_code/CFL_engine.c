
#include <stdbool.h>
#include <stddef.h>

#include "Cfl_engine.h"
#include "Cfl_inner_engine.h"

#include "CFL_event_manager.h"
#include "CFL_debug.h"
#include "CFL_local_heap_functions.h"



static void default_idle_function(const void *handle,
                                  Time_control_CFL_t *timer_control,
                                  bool init_flag);
static void default_calendar_function(const void *handle,
                                      Time_control_CFL_t *timer_control,
                                      bool init_flag);



static void process_event_loop(const Handle_CFL_t *handle);
static bool process_single_loop(const Handle_CFL_t *handle);



Time_control_CFL_t *Get_time_control_CFL(const void *input)
{
  Handle_CFL_t *handle;
  handle = (Handle_CFL_t *)input;
  return (Time_control_CFL_t *)handle->time_control;
}

void Initialize_engine_CFL(const void *input)
{
  config_debug_handle_CFL(input);
  create_allocate_once_heap_CFL(input);
}

void Start_engine_CFL(const void *input, int ms_tick, Idle_function_CFL_t idle_function,
                      Calendar_function_CFL_t calendar_function)
{

 
  
  const Handle_CFL_t *handle = (const Handle_CFL_t *)input;
  Engine_control_CFL_t *engine_control = (Engine_control_CFL_t *)handle->engine_control;
  
  
  if (idle_function != NULL)
  {
    engine_control->idle_function = idle_function;
  }
  else
  {
    engine_control->idle_function = default_idle_function;
  }
  if (calendar_function != NULL)
  {
    engine_control->calendar_function = calendar_function;
  }
  else
  {
    engine_control->calendar_function = default_calendar_function;
  }

  

  reset_event_queue_CFL(handle,0);
  
  engine_control->idle_function(handle, handle->time_control, true);
  engine_control->calendar_function(handle, handle->time_control,
                                    true);
  handle->time_control->tick_ms = ms_tick;




  initialize_columns_CFL(handle);


  process_event_loop(handle);
}



static void process_event_loop(const Handle_CFL_t *handle)
{
  Engine_control_CFL_t *engine_ctrl;

  engine_ctrl = (Engine_control_CFL_t *)handle->engine_control;

  while (true)
  {
    engine_ctrl->idle_function(handle, handle->time_control, false);
    engine_ctrl->calendar_function(handle, handle->time_control, false);

    while ( get_queue_number_CFL(handle,0) > 0)
    { 
      
      
      // Empty event queue
      if (process_single_loop(handle) == false)
      {
       
        return; // Engine is done
      }
      
    }
  }
}

static bool process_single_loop(const Handle_CFL_t *handle)
{
  Event_data_CFL_t *current_event;
 
  
  current_event = dequeue_event_CFL(handle,0);
  
  if (current_event == NULL)
  {
    ASSERT_PRINT("Internal Program Error", "");
  }
  if (current_event->event_index == ENGINE_TERMINATE_EVENT_CFL)
  {
     disable_all_columns_CFL(handle);
    return false; // Engine terminate event
  }
 
  if (process_single_sweep_CFL(handle, current_event) == false)
  {
    return false; // Engine terminate event
  }
   if(current_event->malloc_flag == true){
      handle->free(handle,current_event->params);
      current_event->malloc_flag = false;
    }
    
  return true;
}

/*
  these are default linux handlers

*/

static unsigned time_tick = 0;
static unsigned elasped_time = 0;

void delay_ms_default(unsigned int milliseconds)
{
  elasped_time += milliseconds;
}


long long unsigned get_elapsed_time_ms_default(void)
{
  return elasped_time;
}

static void default_idle_function(const void *handle,
                                  Time_control_CFL_t *timer_control,
                                  bool init_flag)
{
  Event_data_CFL_t event_data;
  if (init_flag == true)
  {
    timer_control->start_millis = get_elapsed_time_ms_default();
    timer_control->current_millis = timer_control->start_millis;
    timer_control->ms_fn = get_elapsed_time_ms_default;
  }
  else
  {

    delay_ms_default(timer_control->tick_ms);
    time_tick = timer_control->tick_ms;
    timer_control->current_millis = get_elapsed_time_ms_default();
    timer_control->start_millis = timer_control->current_millis;
    event_data.event_index = TIMER_TICK_CFL;
    event_data.malloc_flag = false;
    event_data.params = &time_tick;
    enqueue_event_CFL(handle,0, &event_data); 
  
  }
}

static void default_calendar_function(const void *handle,
                                      Time_control_CFL_t *timer_control,
                                      bool init_flag)
{
  
     (void)handle;
      (void)timer_control;
      (void)init_flag;
  
}


