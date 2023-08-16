#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t mgzvguddje[10];
static Event_control_RAM_CFL_t yflghbogfp[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ccdfsbznad_default = { 10, 0 };
static const Event_control_ROM_CFL_t *ccdfsbznad[] = {
     &ccdfsbznad_default,
};
static const Named_event_queue_control_CFL_t ygdqkaezuu = { 1,10,ccdfsbznad };


//----------RAM data structures for columns ----

unsigned char pmhoeqvzdb[0];
unsigned char kwsbrnoljv[0];
void* pxdythibzz[0];
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

static const Column_ROM_CFL_t piidxljkwx[] = {
};


//----------Column elements RAM structures----



static unsigned char jxbhimoahl[0];


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

static const Column_element_CFL_t gptyuwbuhr[] = {
};


static Time_control_CFL_t pmzcgdnmmz;




static Engine_control_CFL_t btamgcuoja;


/* remaining allocate heap size */

static unsigned jjfbhxstcq;


/* current heap pointer */

static char* qthdyecesi;


/* heap block area */

static CS_MEMORY_CONTROL pvznyisjhi;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t odemxshhxq =
{

  .queue_rom    = &ygdqkaezuu,
  .queue_ram =  yflghbogfp,
  .event_data = mgzvguddje,

  .column_elements_flags =jxbhimoahl,
  .column_elements_ROM = gptyuwbuhr,

  .column_flags = pmhoeqvzdb,
  .column_local_data = pxdythibzz,
  .column_state = kwsbrnoljv,
  .number_of_columns = 0,
  .column_rom_data = piidxljkwx,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &pmzcgdnmmz,
  .engine_control =&btamgcuoja,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &jjfbhxstcq,
  .current_heap_location = &qthdyecesi,
  .private_heap   = &pvznyisjhi,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &odemxshhxq;
}
   

#ifdef __cplusplus
}
#endif

#endif
