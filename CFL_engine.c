

#include "Cfl_engine.h"
#include "Cfl_inner_engine.h"
#include "Cfl_local_heap_functions.h"
#include "Cfl_user_functions.h"
#include "CFL_event_manager.h"

static void default_idle_function(void *handle,
                                  Time_control_CFL_t *timer_control,
                                  bool init_flag);
static void default_calendar_function(void *handle,
                                      Time_control_CFL_t *timer_control,
                                      bool init_flag);

static void check_for_undefined_columns(Handle_CFL_t *handle);

static void process_event_loop(Handle_CFL_t *handle);
static bool process_single_loop(Handle_CFL_t *handle);

void Queue_event_CFL(void *input, Event_data_CFL_t *event_data)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;

  handle = (Handle_CFL_t *)input;
  engine_control = (Engine_control_CFL_t *)handle->engine_control;

  if (enqueue_event_CFL(&engine_control->event_control, event_data) == false)
  {
    ASSERT_PRINT_INT("Event Queue Overflow number", get_queue_number_CFL(&engine_control->event_control));
  }
}

Time_control_CFL_t *Get_time_control_CFL(void *input)
{
  Handle_CFL_t *handle;
  handle = (Handle_CFL_t *)input;
  return (Time_control_CFL_t *)handle->time_control;
}

void Start_engine_CFL(void *input, int ms_tick, int event_queue_depth,
                      Idle_function_CFL_t idle_function,
                      Calendar_function_CFL_t calendar_function)
{
  Handle_CFL_t *handle;
  Engine_control_CFL_t *engine_control;
  handle = (Handle_CFL_t *)input;
  handle = (Handle_CFL_t *)input;

  engine_control = (Engine_control_CFL_t *)allocate_once_CFL(
      handle, sizeof(Engine_control_CFL_t));
  handle->engine_control = engine_control;

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

  handle->time_control = &engine_control->time_control;

  initialize_event_data_CFL(handle, &engine_control->event_control, 0, event_queue_depth);

  engine_control->idle_function(handle, &engine_control->time_control, true);
  engine_control->calendar_function(handle, &engine_control->time_control,
                                    true);
  engine_control->time_control.tick_ms = ms_tick;

  check_for_undefined_columns(handle);

  initialize_columns_CFL(handle);

  process_event_loop(handle);
}

static void check_for_undefined_columns(Handle_CFL_t *handle)
{
  Column_control_CFL_t *column_control;
  Column_CFL_t *column;
  int column_number;

  column_control = (Column_control_CFL_t *)handle->columns;
  column = column_control->column;
  column_number = column_control->current_number;

  for (int i = 0; i < column_number; i++)
  {
    if (column->defined == false)
    {
      ASSERT_PRINT("undefined column",
                   (column_control->column_names->cell_array + i)->name);
    }
    column++;
  }
}

static void process_event_loop(Handle_CFL_t *handle)
{
  Engine_control_CFL_t *engine_ctrl;

  engine_ctrl = (Engine_control_CFL_t *)handle->engine_control;

  while (true)
  {
    engine_ctrl->idle_function(handle, &engine_ctrl->time_control, false);
    engine_ctrl->calendar_function(handle, &engine_ctrl->time_control, false);

    while (get_queue_number_CFL(&engine_ctrl->event_control) > 0)
    { // Empty event queue
      if (process_single_loop(handle) == false)
      {
        return; // Engine is done
      }
    }
  }
}

static bool process_single_loop(Handle_CFL_t *handle)
{
  Event_data_CFL_t *current_event;
  Engine_control_CFL_t *engine_ctrl;

  engine_ctrl = (Engine_control_CFL_t *)handle->engine_control;
  current_event = dequeue_event_CFL(&engine_ctrl->event_control);
  if (current_event == NULL)
  {
    ASSERT_PRINT("Internal Program Error", "");
  }
  if (current_event->event_index == ENGINE_TERMINATE_EVENT_CFL)
  {
    Disable_all_columns_CFL(handle);
    return false; // Engine terminate event
  }

  if (process_single_sweep_CFL(handle, current_event) == false)
  {
    return false; // Engine terminate event
  }

  return true;
}
#ifdef ARDUNIO
// need to handle the over flow
static void default_idle_function(void *handle,
                                  Time_control_CFL_t *timer_control,
                                  bool init_flag)
{
  Event_data_CFL_t event_data;
  if (init_flag == true)
  {
    timer_control->start_mills = millis();
    timer_control->current_millis = timer_control->start_mills;
    timer_control->ms_fn = millis;
  }
  else
  {
    while (true)
    {
      timer_control->current_millis = millis();
      if (timer_control->current_millis >
          (timer_control->start_mills + timer_control->tick_ms))
      {

        timer_control->start_mills += timer_control->tick_ms;
        event_data.event_index = TIMER_TICK_CFL;
        event_data.event_data = timer_control->tick_ms;
        event_data.params = NULL;
        Queue_event_CFL(handle, &event_data);
        return;
      }
#ifdef __MAINTAIN_REAL_TIME__
      if ((timer_control->current_millis - timer_control->start_mills) >
          (2 * timer_control->tick_ms))
      {
        ASSERT_PRINT(__func__, "loss of real time");
      }
#endif

    } // while
  }   // end if
}

static void default_calendar_function(void *handle,
                                      Time_control_CFL_t *timer_control,
                                      bool init_flag)
{
  if (init_flag == true)
  {
    timer_control->current_second = 0;
    timer_control->current_minute = 0;
    timer_control->current_hour = 0;
    timer_control->current_day = 0;
    timer_control->current_month = 0;
    timer_control->current_year = 0;
  }
  else
  {
    ; // TBD
  }
}
#endif
#define LINUX
#ifdef LINUX

static unsigned time_tick = 0;

void delay_ms(unsigned int milliseconds)
{
  time_tick += milliseconds;
}


long long unsigned get_elapsed_time_ms(void)
{
  return time_tick;
}

static void default_idle_function(void *handle,
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
    event_data.event_data = timer_control->tick_ms;
    event_data.params = NULL;
    Queue_event_CFL(handle, &event_data);
  
  }
}

static void default_calendar_function(void *handle,
                                      Time_control_CFL_t *timer_control,
                                      bool init_flag)
{
  
     (void)handle;
      (void)timer_control;
      (void)init_flag;
  
}

#endif
