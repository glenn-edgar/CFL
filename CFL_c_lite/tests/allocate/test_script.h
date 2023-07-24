#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "CFL_inner_engine.h"


//----------RAM data structures for event queues ----

static Event_data_CFL_t event_data_array[20];
static Event_control_RAM_CFL_t event_control_ram[2];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t event_control_rom_default = { 0, 10 };
static const Event_control_ROM_CFL_t event_control_rom_main_queue = { 10, 10 };
static const Event_control_ROM_CFL_t *queue_elements[] = {
     &event_control_rom_default,
     &event_control_rom_main_queue,
};
static const Named_event_queue_control_CFL_t queue_control = { 2,20,queue_elements };


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[0];
unsigned char column_RAM_new_state[0];
void* column_RAM_local_data[0];
/*
------------------------ ROM data structures for columns --------------------------
typedef struct Column_ROM_t
{
    short                         queue_number; //-1 means no attached event queue
    bool                          auto_start;   //true or false
    unsigned short                id;           // position in the table
    unsigned short                number;       // number of column elements
    unsigned short                start;        // starting position of the column element
   short                         start_state;   // start of first column state -1 means no state
   short                         end_state;     // end of last column state -1 means no state
   short                         watch_dog_id;  // watch dog number -1 means no watch dog
} Column_ROM_t;


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t column_data_ROM[] = {
};

  /* 
  ------------------------ Column element structure --------------------------
     typedef struct Column_element_CFL_t {
        Column_function_CFL_t column_function;
        void *aux_fn;
        void *params
     } Column_element_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

  

static unsigned char column_element_RAM[0];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
};


static Time_control_CFL_t tgmildztzt;




static Engine_control_CFL_t mwdgtqpodw;


/*
--------------------------- Handle definition ------------------------------
typedef struct Handle_CFL_t
{

  Named_event_queue_control_CFL_t *queue_rom;
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

 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ndaookcvwl =
{

  .queue_rom    = &queue_control,
  .queue_ram = event_control_ram,
  .event_data = event_data_array,

  .column_elements_flags =column_element_RAM ,
  .column_elements_ROM = column_elements_ROM,

  .column_flags = column_RAM_flags,
  .column_local_data = column_RAM_local_data,
  .column_state = column_RAM_new_state,
  .number_of_columns = 0,
  .column_rom_data = column_data_ROM,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &tgmildztzt,
  .engine_control =&mwdgtqpodw,
  .debug_function =NULL,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = NULL,
  .master_heap_size = 0,
  .remaining_heap_size = 0,
  .current_heap_location = NULL,
   .private_heap   = NULL,
  .working_heap_area   =NULL,
  .private_heap_size =   0,
} ;



static void test_entry_point() {
 Start_engine_CFL(&ndaookcvwl,2000,1000);
}
const Handle_CFL_t*  Get_handle_CFL(){
    return &ndaookcvwl;
}
#endif
