#ifndef __CFL_INNER_ENGINE_H__
#define __CFL_INNER_ENGINE_H__
#include "CFL_debug.h"
#include "CFL_basic_defs.h"
#include "CFL_event_manager.h"

typedef long long unsigned (*Elasped_ms_fn)(void);

typedef struct Time_control_CFL_t
{
  int tick_ms;
  Elasped_ms_fn ms_fn;
  unsigned short current_millis;
  unsigned short start_millis;
  unsigned char second;
  unsigned char minute;
  unsigned char hour;
  unsigned char day;
  unsigned char dow;
  unsigned char month;
  unsigned short day_of_year;
  unsigned short year;
} Time_control_CFL_t;

typedef void (*Idle_function_CFL_t)(const void *input, Time_control_CFL_t *timer_control, bool init_flag);
typedef void (*Calendar_function_CFL_t)(const void *input, Time_control_CFL_t *timer_control, bool init_flag);

typedef struct Column_element_CFL_t
{
  Column_function_CFL_t column_function;
  void *aux_fn;
  void *params;
} Column_element_CFL_t;

#define COLUMN_ACTIVE 0x01
#define COLUMN_SUCCESS 0x02

#define COLUMN_ELEMENT_ACTIVE 0x1
#define COLUMN_ELEMENT_INITIALIZED 0x2

typedef struct Column_watch_dog_ROM_CFL_t
{
  bool termination_flag;
  unsigned short column_index;
  unsigned short trigger_count;
  void *user_data;
  One_shot_function_CFL_t trigger_function;

} Column_watch_dog_ROM_CFL_t;

typedef struct Column_ROM_CFL_t
{
  short queue_number;
  bool auto_start;
  unsigned short id;
  unsigned short number;
  unsigned short start;
  short start_state;
  short end_state;
  short watch_dog_id;
} Column_ROM_CFL_t;

typedef struct Engine_control_CFL_t
{

  Time_control_CFL_t time_control;
  Idle_function_CFL_t idle_function;
  Calendar_function_CFL_t calendar_function;
  unsigned short current_column_index;
  unsigned short current_column_element_index;

  Event_data_CFL_t ref_event_data;
} Engine_control_CFL_t;


void *private_heap_malloc_CFL(const void *input, unsigned size);
void private_heap_free_CFL(const void *input, void *ptr);
void *allocate_once_CFL(void *handle, unsigned size); 

typedef void *(*private_heap_malloc_fn)(void *, unsigned );
typedef void (*private_heap_free_fn)(const void *input, void *ptr);
typedef void *(*allocate_once_fn)(const void *input, unsigned size);
typedef struct Handle_CFL_t
{

  const Named_event_queue_control_CFL_t *queue_rom;
  Event_control_RAM_CFL_t *queue_ram;
  Event_data_CFL_t *event_data;

  unsigned char *column_elements_flags;
  const Column_element_CFL_t *column_elements_ROM;

  unsigned char *column_flags;
  void **column_local_data;
  unsigned char *column_state;
  const unsigned short number_of_columns;
  const Column_ROM_CFL_t *column_rom_data;

  const unsigned short number_of_watch_dogs;
  bool *watch_dog_active;
  unsigned *watch_dog_count;
  unsigned *watch_dog_trigger_count;
  const Column_watch_dog_ROM_CFL_t *watch_dog_rom_data;
  Time_control_CFL_t *time_control;
  Engine_control_CFL_t *engine_control;
  Debug_out_CFL_t *debug_function;
  private_heap_malloc_fn malloc;
  private_heap_free_fn free;
  allocate_once_fn allocate_once;
  const char *master_heap_starting_location; // set by lua preprocessor
  unsigned master_heap_size;                 // set by lua preprocessor
  unsigned remaining_heap_size;
  char *current_heap_location;
  char *private_heap;      // set by lua preprocessor
  char *working_heap_area; // set by lua preprocessor
  unsigned private_heap_size;

} Handle_CFL_t;

void initialize_columns_CFL(const void *input);

bool process_single_sweep_CFL(const void *input, Event_data_CFL_t *event_data);

void disable_all_columns_CFL(const void *input);

void enable_column_CFL(const void *input, unsigned column_index);

void reset_column_CFL(const void *input, unsigned column_index);

void disable_column_CFL(const void *input, unsigned column_index);

bool column_state_CFL(const void *input, unsigned column_index);

bool join_columns_CFL(const void *input, unsigned short number_of_columns, unsigned short *column_list);

void initialize_columns_CFL(const void *input);

void set_local_data_CFL(const void *input, unsigned column_index,
                        void *data);

void *get_local_data_CFL(const void *input, unsigned column_index);

void set_current_column_return_code_CFL(const void *input, bool state);

bool get_current_column_return_code_CFL(const void *input);

unsigned get_current_column_element_index_CFL(const void *input);

unsigned short get_current_column_index_CFL(const void *input);

void set_column_watch_dog_CFL(const void *input, void *params,
                              Event_data_CFL_t *event_data);

void clear_column_watch_dog_CFL(const void *input, void *params,
                                Event_data_CFL_t *event_data);

void change_local_column_state_CFL(const void *input, unsigned char new_state);

Time_control_CFL_t *Get_time_control_CFL(const void *input);

void Create_heap_CFL(const void *input);

void Start_engine_CFL(const const void *input, int ms_tick, Idle_function_CFL_t idle_function,
                      Calendar_function_CFL_t calendar_function);

#endif