#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t kacouidhel[10];
static Event_control_RAM_CFL_t fbjgdibhhs[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t bxagvsqvib_default = { 10, 0 };
static const Event_control_ROM_CFL_t *bxagvsqvib[] = {
     &bxagvsqvib_default,
};
static const Named_event_queue_control_CFL_t yhvhvylfcy = { 1,10,bxagvsqvib };


//----------RAM data structures for columns ----

unsigned char ajyhmsebku[0];
unsigned char ttpqpqmngm[0];
void* kzxvvfggzw[0];
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

static const Column_ROM_CFL_t zlwajouyzw[] = {
};


//----------Column elements RAM structures----



static unsigned char ioirlapvbv[0];


  /* 
  ------------------------ Column element Flash structure --------------------------
     typedef struct Column_element_CFL_t {
        Column_function_CFL_t column_function;
        void *aux_fn;
        void *params
     } Column_element_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

  

//----------Column elements Flash structures----

static const Column_element_CFL_t zbvroesviq[] = {
};


static Time_control_CFL_t uaucfireli;




static Engine_control_CFL_t izlpwsfagp;




static Engine_control_CFL_t izlpwsfagp;


/* remaining allocate heap size */

static unsigned tonpqdzexe;


/* current heap pointer */

static char* xqfjvtgump;


/* heap block area */

static CS_MEMORY_CONTROL jhszjpdtqy;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t vwtjuxcpme =
{

  .queue_rom    = &yhvhvylfcy,
  .queue_ram =  fbjgdibhhs,
  .event_data = kacouidhel,

  .column_elements_flags =ioirlapvbv,
  .column_elements_ROM = zbvroesviq,

  .column_flags = ajyhmsebku,
  .column_local_data = kzxvvfggzw,
  .column_state = ttpqpqmngm,
  .number_of_columns = 0,
  .column_rom_data = zlwajouyzw,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &uaucfireli,
  .engine_control =&izlpwsfagp,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &tonpqdzexe,
  .current_heap_location = &xqfjvtgump,
  .private_heap   = &jhszjpdtqy,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &vwtjuxcpme;
}
   

#ifdef __cplusplus
}
#endif

#endif
