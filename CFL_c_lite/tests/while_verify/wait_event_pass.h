#ifndef __wait_event_pass_H__
#define __wait_event_pass_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define amllkhwzpw 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t frrnrxjfyu[10];
static Event_control_RAM_CFL_t uafphmzjkz[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ubozohqsyo_default = { 10, 0 };
static const Event_control_ROM_CFL_t *ubozohqsyo[] = {
     &ubozohqsyo_default,
};
static const Named_event_queue_control_CFL_t topnftlahk = { 1,10,ubozohqsyo };
const Event_data_CFL_t pbklhwvlgs = { amllkhwzpw, false, NULL, };
static const char *gksurlkezz = "this column will generate an event every second";


unsigned  svimuabrvb;
const While_time_control_ROM_CFL_t mxowucptav = { 1000,&svimuabrvb };



static While_control_RAM_CFL_t tfckjbmeeb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qxgvciyczi_rom = { 0 ,true, &mxowucptav,&tfckjbmeeb_ram,null_function};

    
static const char *ibctlzxmhd = "sending event";
static const char *qcgkxgtnqa = "this column will wait for to events and then stop the engine";
 unsigned lohhrwiods_ram;
const While_event_control_ROM_t lohhrwiods_rom = { 10,amllkhwzpw,11000,true,NULL,&lohhrwiods_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t pjyjjajqcy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mzwwvrrrdx_rom = { 11000 ,true, &lohhrwiods_rom,&pjyjjajqcy_ram,null_function};

    
static const char *avottclxfz = "10 events have been received";
static const char *ojwvlgactb = "stopping engine";


//----------RAM data structures for columns ----

unsigned char kfbhnosodl[2];
unsigned char ayqeswyheh[2];
void* tssguniexf[2];
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

static const Column_ROM_CFL_t cbqyjuomeh[] = {
  { -1,true, 0, 5, 0, -1, -1,-1 },
  { -1,true, 1, 5, 5, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char iauuacfxhc[10];


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

static const Column_element_CFL_t mctbgxkyio[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&gksurlkezz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qxgvciyczi_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&pbklhwvlgs},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ibctlzxmhd},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qcgkxgtnqa},
    {while_handler_CFL,wait_event_handler,(void *)&mzwwvrrrdx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&avottclxfz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ojwvlgactb},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
};


static Time_control_CFL_t wbjosjecoa;




static Engine_control_CFL_t zjhgicevrs;




static Engine_control_CFL_t zjhgicevrs;


/* remaining allocate heap size */

static unsigned pjwdkloxcp;


/* current heap pointer */

static char* xjgamdeclp;


/* heap block area */

static CS_MEMORY_CONTROL aierzozuqv;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ylflefimlc =
{

  .queue_rom    = &topnftlahk,
  .queue_ram =  uafphmzjkz,
  .event_data = frrnrxjfyu,

  .column_elements_flags =iauuacfxhc,
  .column_elements_ROM = mctbgxkyio,

  .column_flags = kfbhnosodl,
  .column_local_data = tssguniexf,
  .column_state = ayqeswyheh,
  .number_of_columns = 2,
  .column_rom_data = cbqyjuomeh,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &wbjosjecoa,
  .engine_control =&zjhgicevrs,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &pjwdkloxcp,
  .current_heap_location = &xjgamdeclp,
  .private_heap   = &aierzozuqv,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  wait_event_pass_handle(){
    return &ylflefimlc;
}
   

#ifdef __cplusplus
}
#endif

#endif
