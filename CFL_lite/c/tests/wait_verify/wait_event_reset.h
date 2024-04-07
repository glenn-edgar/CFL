#ifndef __wait_event_reset_H__
#define __wait_event_reset_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define test_event 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t rlykztkasi[4];
static Event_data_CFL_t zuejoljkyb[7];
static Event_data_CFL_t dpkhzftiii[0];
static Event_data_CFL_t wvxgzhrnyt[0];
static Event_data_CFL_t hawjdbalpl[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t jbowohxues[] = { 
     {  7, zuejoljkyb },
     {  0, dpkhzftiii },
     {  0, wvxgzhrnyt },
     {  0, hawjdbalpl },
};


static const char wait_event_reset_message_a[] = "wait event reset function called\n";


const Event_data_CFL_t lnrbwrbxrm = { test_event, false, NULL };
static const char *oqeaqttudg = "this column will terminate the engine";


unsigned  yazltpirtv;
const While_time_control_ROM_CFL_t zrwsjgjgym = { 11000,&yazltpirtv };



static While_control_RAM_CFL_t hnudmgiemq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uijoszzsxz_rom = { 0 ,true, (void*)&zrwsjgjgym,&hnudmgiemq_ram,null_function};

    
static const char *kaakgcpsja = "stopping engine because 11 seconds have passed";
static const char *ghrrkdqjnl = "this column will generate an event every second";


unsigned  sgjhdrdznu;
const While_time_control_ROM_CFL_t qnkjwwypml = { 1000,&sgjhdrdznu };



static While_control_RAM_CFL_t cjegfdpuok_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jayuhzkckx_rom = { 0 ,true, (void*)&qnkjwwypml,&cjegfdpuok_ram,null_function};

    
static const char *spkimujdvg = "sending event";
static const char *spenkxsofa = "wait event is column is starting";
static const char *jahlianbtu = "this column will reset because not enough time to receive 10 events";
 unsigned eiszvaoyuc_ram;
const While_event_control_ROM_t eiszvaoyuc_rom = { 10,test_event,9000,false,wait_event_reset_message_a,&eiszvaoyuc_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t nhbnztjlog_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dkwfsirjoh_rom = { 9000 ,false, (void*)&eiszvaoyuc_rom,&nhbnztjlog_ram,wait_event_reset_b};

    
static const char *chtzuombzq = "10 events have been received";
static const char *cpqbidrxpy = "stopping engine";


//----------RAM data structures for columns ----

unsigned kisyrkipen[3];
Watch_dog_struct_CFL_t * navdtoxjqv[3];
unsigned char dubkxdhbpn[3];
unsigned char akngvgsxjg[3];
void* bwhraeoteq[3];
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

static const Column_ROM_CFL_t hjlmipyxfq[] = {
  { 1,true, 0, 4, 0, -1, -1 },
  { 2,true, 1, 5, 4, -1, -1 },
  { 3,true, 2, 6, 9, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char laixdobqyn[15];


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

static const Column_element_CFL_t vyjlgltuas[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&oqeaqttudg},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uijoszzsxz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kaakgcpsja},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ghrrkdqjnl},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jayuhzkckx_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&lnrbwrbxrm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&spkimujdvg},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&spenkxsofa},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jahlianbtu},
    {while_handler_CFL,wait_event_handler,(void *)&dkwfsirjoh_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&chtzuombzq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cpqbidrxpy},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
Bitmap_CFL llpyhqugcn[0];
Registermap_CFL_t hvudpyyhes[0];
Floatmap_CFL_t xyxvsbuvuv[0];
const Sm_control_ROM_CFL_t wylyzncvzp[0];
Sm_control_RAM_CFL_t zvsqaeipdy[0];


static Time_control_CFL_t fbctqstfth;




static Engine_control_CFL_t cflbgemzoc;


/* remaining allocate heap size */

static unsigned nmoctamzlu;


/* current heap pointer */

static char* mdsvrrhvga;


/* heap block area */

static CS_MEMORY_CONTROL hgdpbijfeq;


    
    


const struct Handle_CFL_t hqfusqexgs =
{

  .queue_number = 4,
  .queue_rom = jbowohxues,
  .queue_ram = rlykztkasi,

  .column_elements_flags =laixdobqyn,
  .column_elements_ROM = vyjlgltuas,

  .watch_dog_struct = navdtoxjqv,
  .watch_dog_count  = kisyrkipen,
   
   
  .column_flags = dubkxdhbpn,
  .column_local_data = bwhraeoteq,
  .column_state = akngvgsxjg,
  .number_of_columns = 3,
  .column_rom_data = hjlmipyxfq,

  
  
  
  .time_control = &fbctqstfth,
  .engine_control =&cflbgemzoc,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &nmoctamzlu,
  .current_heap_location = &mdsvrrhvga,
  .private_heap   = &hgdpbijfeq,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  wylyzncvzp,
  .sm_ram     = zvsqaeipdy,
  .number_of_bitmaps = 0,
  .bitmaps = llpyhqugcn,
  .number_of_registermaps = 0,
  .registermaps = hvudpyyhes,
  .number_of_floatmaps = 0,
  .floatmaps = xyxvsbuvuv,
} ;

const Handle_CFL_t*  wait_event_reset_handle(){
    return &hqfusqexgs;
}
   

#ifdef __cplusplus
}
#endif

#endif
