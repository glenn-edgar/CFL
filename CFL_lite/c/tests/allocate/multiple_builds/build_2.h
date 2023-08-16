#ifndef __build_2_H__
#define __build_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t prxuesummo[10];
static Event_control_RAM_CFL_t pxnqvxyvzx[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t cgaequxtsk_default = { 10, 0 };
static const Event_control_ROM_CFL_t *cgaequxtsk[] = {
     &cgaequxtsk_default,
};
static const Named_event_queue_control_CFL_t wnobtkzafm = { 1,10,cgaequxtsk };


//----------RAM data structures for columns ----

unsigned char viphdeskkr[0];
unsigned char fbanpdbhig[0];
void* vyczybfkzn[0];
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

static const Column_ROM_CFL_t jghtbfjwyq[] = {
};


//----------Column elements RAM structures----



static unsigned char dkiwujodhn[0];


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

static const Column_element_CFL_t tdzjzsldka[] = {
};


static Time_control_CFL_t nfacmtpidk;




static Engine_control_CFL_t sjpqermnub;




static Engine_control_CFL_t sjpqermnub;


/* remaining allocate heap size */

static unsigned iswkqzvbnl;


/* current heap pointer */

static char* khjrxaiapk;


/* heap block area */

static CS_MEMORY_CONTROL dfnptzhwaz;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t lqvyqdnvty =
{

  .queue_rom    = &wnobtkzafm,
  .queue_ram =  pxnqvxyvzx,
  .event_data = prxuesummo,

  .column_elements_flags =dkiwujodhn,
  .column_elements_ROM = tdzjzsldka,

  .column_flags = viphdeskkr,
  .column_local_data = vyczybfkzn,
  .column_state = fbanpdbhig,
  .number_of_columns = 0,
  .column_rom_data = jghtbfjwyq,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &nfacmtpidk,
  .engine_control =&sjpqermnub,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &iswkqzvbnl,
  .current_heap_location = &khjrxaiapk,
  .private_heap   = &dfnptzhwaz,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point_2(){
    return &lqvyqdnvty;
}
   

#ifdef __cplusplus
}
#endif

#endif