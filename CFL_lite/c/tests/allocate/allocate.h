#ifndef __allocate_H__
#define __allocate_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t txlkxpdgek[1];
static Event_data_CFL_t gwswrvwcrt[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ddcncakpeu[] = { 
     {  10, gwswrvwcrt },
};


//----------RAM data structures for columns ----

unsigned qsdapfqqze[0];
Watch_dog_struct_CFL_t * qfbygedton[0];
unsigned char fduaajntxa[0];
unsigned char plybhpypha[0];
void* xzlcssmyby[0];
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
  
} Column_ROM_CFL_t;

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t lbjdyxsgtp[] = {
};


//----------Column elements RAM structures----



static unsigned char fovmszsdsn[0];


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

static const Column_element_CFL_t ayhaniciwq[] = {
};
Bitmap_CFL ojxcgdyomc[0];
Registermap_CFL_t jxerpsktds[0];
Floatmap_CFL_t nxfelswdra[0];
const Sm_control_ROM_CFL_t espitikyuv[0];
Sm_control_RAM_CFL_t jhlhvpwryp[0];


static Time_control_CFL_t efmcldduva;




static Engine_control_CFL_t jmupuwcnzg;


/* remaining allocate heap size */

static unsigned qyvnofjhwj;


/* current heap pointer */

static char* fahxnxfcul;


/* heap block area */

static CS_MEMORY_CONTROL jqtwtapxfa;


    
    


const struct Handle_CFL_t hqcmavgjas =
{

  .queue_number = 1,
  .queue_rom = ddcncakpeu,
  .queue_ram = txlkxpdgek,

  .column_elements_flags =fovmszsdsn,
  .column_elements_ROM = ayhaniciwq,

  .watch_dog_struct = qfbygedton,
  .watch_dog_count  = qsdapfqqze,
   
   
  .column_flags = fduaajntxa,
  .column_local_data = xzlcssmyby,
  .column_state = plybhpypha,
  .number_of_columns = 0,
  .column_rom_data = lbjdyxsgtp,

  
  
  
  .time_control = &efmcldduva,
  .engine_control =&jmupuwcnzg,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &qyvnofjhwj,
  .current_heap_location = &fahxnxfcul,
  .private_heap   = &jqtwtapxfa,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  espitikyuv,
  .sm_ram     = jhlhvpwryp,
  .number_of_bitmaps = 0,
  .bitmaps = ojxcgdyomc,
  .number_of_registermaps = 0,
  .registermaps = jxerpsktds,
  .number_of_floatmaps = 0,
  .floatmaps = nxfelswdra,
} ;

const Handle_CFL_t*  allocate_entry_point(){
    return &hqcmavgjas;
}
   

#ifdef __cplusplus
}
#endif

#endif
