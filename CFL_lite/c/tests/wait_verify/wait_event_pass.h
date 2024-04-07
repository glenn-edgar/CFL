#ifndef __wait_event_pass_H__
#define __wait_event_pass_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define test_event 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t rnjwxhdnnq[3];
static Event_data_CFL_t ktvpjfsmzi[7];
static Event_data_CFL_t llulydkhmn[0];
static Event_data_CFL_t pxlgzknixc[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t comyklpwgn[] = { 
     {  7, ktvpjfsmzi },
     {  0, llulydkhmn },
     {  0, pxlgzknixc },
};
const Event_data_CFL_t vfydwldvuz = { test_event, false, NULL };
static const char *boqsywbwmd = "this column will generate an event every second";


unsigned  frqidavfqt;
const While_time_control_ROM_CFL_t cibfsssigz = { 1000,&frqidavfqt };



static While_control_RAM_CFL_t lcsysnvirp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ulianjjyyx_rom = { 0 ,true, (void*)&cibfsssigz,&lcsysnvirp_ram,null_function};

    
static const char *mpeugezbuu = "sending event";
static const char *nctlmcowid = "this column will wait for to events and then stop the engine";
 unsigned vtacouspqu_ram;
const While_event_control_ROM_t vtacouspqu_rom = { 10,test_event,11000,true,NULL,&vtacouspqu_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t eenhwiaygz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tyvzoutwrj_rom = { 11000 ,true, (void*)&vtacouspqu_rom,&eenhwiaygz_ram,null_function};

    
static const char *rfqttaamrd = "10 events have been received";
static const char *hkrxyokxsd = "stopping engine";


//----------RAM data structures for columns ----

unsigned bbkkfmgbtf[2];
Watch_dog_struct_CFL_t * fuiqiwvafj[2];
unsigned char sqksakbiah[2];
unsigned char sonkjgjiag[2];
void* kxhphzcdzi[2];
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

static const Column_ROM_CFL_t aynpiaheir[] = {
  { 1,true, 0, 5, 0, -1, -1 },
  { 2,true, 1, 5, 5, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char dnkkceroxc[10];


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

static const Column_element_CFL_t wwhjlhgtlx[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&boqsywbwmd},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ulianjjyyx_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&vfydwldvuz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mpeugezbuu},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nctlmcowid},
    {while_handler_CFL,wait_event_handler,(void *)&tyvzoutwrj_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rfqttaamrd},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hkrxyokxsd},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
};
Bitmap_CFL lkeagfglrp[0];
Registermap_CFL_t bxymdqrnvs[0];
Floatmap_CFL_t efhrbggtta[0];
const Sm_control_ROM_CFL_t rdiunosatp[0];
Sm_control_RAM_CFL_t zbcscalito[0];


static Time_control_CFL_t simlzoewqd;




static Engine_control_CFL_t mwmcdlfnll;


/* remaining allocate heap size */

static unsigned qvtvtgmrnh;


/* current heap pointer */

static char* hhsxlracmh;


/* heap block area */

static CS_MEMORY_CONTROL kutkfcnnpp;


    
    


const struct Handle_CFL_t hffyrkiwmf =
{

  .queue_number = 3,
  .queue_rom = comyklpwgn,
  .queue_ram = rnjwxhdnnq,

  .column_elements_flags =dnkkceroxc,
  .column_elements_ROM = wwhjlhgtlx,

  .watch_dog_struct = fuiqiwvafj,
  .watch_dog_count  = bbkkfmgbtf,
   
   
  .column_flags = sqksakbiah,
  .column_local_data = kxhphzcdzi,
  .column_state = sonkjgjiag,
  .number_of_columns = 2,
  .column_rom_data = aynpiaheir,

  
  
  
  .time_control = &simlzoewqd,
  .engine_control =&mwmcdlfnll,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &qvtvtgmrnh,
  .current_heap_location = &hhsxlracmh,
  .private_heap   = &kutkfcnnpp,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  rdiunosatp,
  .sm_ram     = zbcscalito,
  .number_of_bitmaps = 0,
  .bitmaps = lkeagfglrp,
  .number_of_registermaps = 0,
  .registermaps = bxymdqrnvs,
  .number_of_floatmaps = 0,
  .floatmaps = efhrbggtta,
} ;

const Handle_CFL_t*  wait_event_pass_handle(){
    return &hffyrkiwmf;
}
   

#ifdef __cplusplus
}
#endif

#endif
