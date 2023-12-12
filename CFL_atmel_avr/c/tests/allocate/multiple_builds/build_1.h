#ifndef __build_1_H__
#define __build_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t nmfhjvuvet[10];
static Event_control_RAM_CFL_t bgvpvifxal[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t wbwuoqtunu_default = { 10, 0 };
static const Event_control_ROM_CFL_t *wbwuoqtunu[] = {
     &wbwuoqtunu_default,
};
static const Named_event_queue_control_CFL_t norfyuctdf = { 1,10,wbwuoqtunu };


//----------RAM data structures for columns ----

unsigned char ynmyscihfd[0];
unsigned char hbweizaqgg[0];
void* phwmzgduxu[0];
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

static const Column_ROM_CFL_t ymouzdwdwq[] = {
};


//----------Column elements RAM structures----



static unsigned char njgrtevcys[0];


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

static const Column_element_CFL_t kvgqzjadob[] = {
};


static Time_control_CFL_t mllajdaagk;




static Engine_control_CFL_t ddchmjsmxc;




static Engine_control_CFL_t ddchmjsmxc;


/* remaining allocate heap size */

static unsigned xiuowuhjhe;


/* current heap pointer */

static char* xapqlwpdmf;


/* heap block area */

static CS_MEMORY_CONTROL csfdjurhpn;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t bbjsqcihqi =
{

  .queue_rom    = &norfyuctdf,
  .queue_ram =  bgvpvifxal,
  .event_data = nmfhjvuvet,

  .column_elements_flags =njgrtevcys,
  .column_elements_ROM = kvgqzjadob,

  .column_flags = ynmyscihfd,
  .column_local_data = phwmzgduxu,
  .column_state = hbweizaqgg,
  .number_of_columns = 0,
  .column_rom_data = ymouzdwdwq,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &mllajdaagk,
  .engine_control =&ddchmjsmxc,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &xiuowuhjhe,
  .current_heap_location = &xapqlwpdmf,
  .private_heap   = &csfdjurhpn,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point_1(){
    return &bbjsqcihqi;
}
   

#ifdef __cplusplus
}
#endif

#endif
