#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t event_data_array[10];
static Event_control_RAM_CFL_t event_control_ram[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t event_control_rom_default = { 10, 0 };
static const Event_control_ROM_CFL_t *queue_elements[] = {
     &event_control_rom_default,
};
static const Named_event_queue_control_CFL_t queue_control = { 1,10,queue_elements };


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[0];
unsigned char column_RAM_new_state[0];
void* column_RAM_local_data[0];
/*
------------------------ ROM data structures for columns --------------------------
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


static Time_control_CFL_t fsutwgewcv;




static Engine_control_CFL_t beslaxtkmz;




static Engine_control_CFL_t beslaxtkmz;


/* remaining allocate heap size */

static unsigned skaksqijue;


/* current heap pointer */

static char* odmiqcnpxp;


/* heap block area */

static CS_MEMORY_CONTROL agpqonsbos;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t idqvsmiuzu =
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
  .time_control = &fsutwgewcv,
  .engine_control =&beslaxtkmz,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &skaksqijue,
  .current_heap_location = &odmiqcnpxp,
  .private_heap   = &agpqonsbos,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &idqvsmiuzu;
}
   

#ifdef __cplusplus
}
#endif

#endif
