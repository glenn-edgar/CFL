#ifndef __CFL_INNER_ENGINE_H__
#define __CFL_INNER_ENGINE_H__
#ifdef __cplusplus
extern "C" {
#endif


#include "CFL_debug.h"
#include "CFL_basic_defs.h"
#include "CFL_event_manager.h"
#include "CFL_private_heap.h"
#include "CFL_local_heap_functions.h"
#include "CFL_state_machine.h"
#include "CFL_rpc_packets.h"
#include "CFL_bit_map.h"
#include "CFL_s_bit_stack.h"
#include "CFL_s_bit_engine.h"


#include "CFL_register_map.h"
#include "CFL_s_register_engine.h"
#include "CFL_s_register_stack.h"

#include "CFL_float_map.h"
#include "CFL_s_float_engine.h"
#include "CFL_s_float_stack.h"

#include "CFL_rpc_packets.h"


typedef void (*Debug_out_CFL_t)(const void *buf, unsigned count);

typedef long long unsigned (*Elasped_ms_fn)(void);

typedef struct Time_control_CFL_t
{
  int tick_ms;
  Elasped_ms_fn ms_fn;
  unsigned  current_millis;
  unsigned  start_millis;
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
#define WATCH_DOG_ACTIVE 0x04


#define COLUMN_ELEMENT_ACTIVE 0x1
#define COLUMN_ELEMENT_INITIALIZED 0x2
#define COlUMN_ELEMENT_SUCCESS_FLAG 0x80



typedef struct Column_ROM_CFL_t
{
  short queue_number;
  bool auto_start;
  unsigned short id;
  unsigned short number;
  unsigned short start;
  short start_state;
  short end_state;
  void *aux_data;
} Column_ROM_CFL_t;

typedef struct Engine_control_CFL_t
{

  
  Idle_function_CFL_t idle_function;
  Calendar_function_CFL_t calendar_function;
  unsigned short current_column_index;
  unsigned short current_column_element_index;

  
} Engine_control_CFL_t;


void *private_heap_malloc_CFL(const void *input, unsigned size);
void private_heap_free_CFL(const void *input, void *ptr);
void *allocate_once_CFL(const void *input, unsigned size); 

typedef void *(*private_heap_malloc_fn)(const void *input, unsigned size );
typedef void (*private_heap_free_fn)(const void *input, void *ptr);
typedef void *(*allocate_once_fn)(const void *input, unsigned size);


typedef struct Watch_dog_struct_CFL_t{ 
  unsigned watch_dog_trigger_count;
  One_shot_function_CFL_t watch_dog_trigger_function;
  unsigned char watch_dog_termination_flag;
  void *watch_dog_user_data;
} Watch_dog_struct_CFL_t;
/*
  Structure set by lua preprocessor unless noted



*/
typedef struct Handle_CFL_t
{
  const unsigned queue_number;
  const Event_control_ROM_CFL_t *queue_rom;
  Event_control_RAM_CFL_t *queue_ram;
  

  unsigned char *column_elements_flags;
  const Column_element_CFL_t *column_elements_ROM;

  unsigned char *column_flags;
  void **column_local_data;
  unsigned char *column_state;
  const unsigned short number_of_columns;
  const Column_ROM_CFL_t *column_rom_data;

  
  Watch_dog_struct_CFL_t **watch_dog_struct;
  unsigned *watch_dog_count;
 
  
  Time_control_CFL_t *time_control;
  Engine_control_CFL_t *engine_control;
  Debug_out_CFL_t debug_function;
  private_heap_malloc_fn malloc;
  private_heap_free_fn free;
  allocate_once_fn allocate_once;
  char **master_heap_starting_location; 
  const unsigned master_heap_size;             
  unsigned *remaining_heap_size;  // set by c runtime
  char **current_heap_location;  // set by c runtime
  CS_MEMORY_CONTROL *private_heap;      
  
  unsigned private_heap_size;

  unsigned number_of_sm;
  const Sm_control_ROM_CFL_t *sm_rom;
  Sm_control_RAM_CFL_t *sm_ram;
  const unsigned number_of_bitmaps;
  Bitmap_CFL *bitmaps;
  const unsigned number_of_registermaps;
  Registermap_CFL_t *registermaps;
  const unsigned number_of_floatmaps;
  Floatmap_CFL_t *floatmaps;

  const uint16_t rpc_queue_number;
  RPC_Packet_control_RAM_CFL_t *rpc_queue_ram;
  const RPC_Packet_control_ROM_CFL_t *rpc_queue_rom;

} Handle_CFL_t;



bool process_single_sweep_CFL(const void *input, Event_data_CFL_t *event_data);

void disable_all_columns_CFL(const void *input);

void enable_column_CFL(const void *input, unsigned column_index);

void reset_column_CFL(const void *input, unsigned column_index);

void disable_column_CFL(const void *input, unsigned column_index);


bool column_state_CFL(const void *input, unsigned column_index);

bool join_columns_CFL(const void *input, const unsigned short number_of_columns, const unsigned short *column_list);

void initialize_columns_CFL(const void *input);



void set_column_return_code_CFL(const void *input,unsigned short column_index, bool state);

bool get_column_return_code_CFL(const void *input,unsigned short column_index);


bool get_column_state_CFL(const void *input, unsigned short column_index);

unsigned short get_current_column_index_CFL(const void *input);


void change_local_column_state_CFL(const void *input, unsigned char new_state);

Time_control_CFL_t *Get_time_control_CFL(const void *input);





void attach_watch_dog_handler_CFL(const void *input,const Watch_dog_struct_CFL_t *watch_dog_struct);
                                  
void detach_watch_dog_handler_CFL(const void *input);

void store_column_data_CFL(const void *input, unsigned short column_id, void *column_data);
void store_current_column_data_CFL(const void *input,  void *column_data);

// current column id is used to retrieve the data
void *retrieve_current_column_data_CFL(const void *input);
void *retreive_column_data_CFL(const void *input, unsigned short column_id);


unsigned get_current_column_element_index_CFL(const void *input);

bool chain_single_sweep_CFL(const void *input,
                             const uint16_t column_index,
                              Event_data_CFL_t *event_data);  

void Initialize_heap_CFL(const void *input);

void Initialize_engine_CFL(const void *input, int ms_tick, Idle_function_CFL_t idle_function,
                      Calendar_function_CFL_t calendar_function);
void Start_engine_CFL(const void *input);
#ifdef __cplusplus
}
#endif

#endif