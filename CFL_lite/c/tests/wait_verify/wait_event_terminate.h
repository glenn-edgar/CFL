#ifndef __wait_event_terminate_H__
#define __wait_event_terminate_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define test_event 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t agvzvgvgfh[4];
static Event_data_CFL_t tvkcohvwnf[7];
static Event_data_CFL_t cjiiudbwir[0];
static Event_data_CFL_t njiwccpvnq[0];
static Event_data_CFL_t mqxzwoakyd[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t plaebuowck[] = { 
     {  7, tvkcohvwnf },
     {  0, cjiiudbwir },
     {  0, njiwccpvnq },
     {  0, mqxzwoakyd },
};

static const char wait_event_terminate_message_b[] = "wait event terminate function called\n";


const Event_data_CFL_t zrbbwvccgw = { test_event, false, NULL };
static const char *pcntnrkrru = "this column will terminate the engine";


unsigned  zhxwqhtcvo;
const While_time_control_ROM_CFL_t ylfimfbioh = { 11000,&zhxwqhtcvo };



static While_control_RAM_CFL_t skstsqdqjk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t alrmqdpuko_rom = { 0 ,true, (void*)&ylfimfbioh,&skstsqdqjk_ram,null_function};

    
static const char *ycmbgohegs = "stopping engine because 11 seconds have passed";
static const char *ijlcniszth = "this column will generate an event every second";


unsigned  wnboggvefa;
const While_time_control_ROM_CFL_t hpnfmfogzd = { 1000,&wnboggvefa };



static While_control_RAM_CFL_t nwjjwxfutu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ponllslqwm_rom = { 0 ,true, (void*)&hpnfmfogzd,&nwjjwxfutu_ram,null_function};

    
static const char *wcysgjibyb = "sending event";
static const char *gfbquulcoh = "wait event is column is starting";
static const char *gmmfrwxtpp = "this column will terminate because not enough time to receive 10 events";
 unsigned xfuyrbkihx_ram;
const While_event_control_ROM_t xfuyrbkihx_rom = { 10,test_event,9000,false,wait_event_terminate_message_b,&xfuyrbkihx_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t mtutgtviam_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qqepmatlnb_rom = { 9000 ,false, (void*)&xfuyrbkihx_rom,&mtutgtviam_ram,wait_event_terminate_b};

    
static const char *stybeynfdg = "10 events have been received";
static const char *pecnyswtmo = "stopping engine";


//----------RAM data structures for columns ----

unsigned oekwlqback[3];
Watch_dog_struct_CFL_t * whkajjhrmr[3];
unsigned char uxobjhsbtu[3];
unsigned char szedquvxyq[3];
void* gxfsijctuv[3];
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

static const Column_ROM_CFL_t thkvgyaddv[] = {
  { 1,true, 0, 4, 0, -1, -1 },
  { 2,true, 1, 5, 4, -1, -1 },
  { 3,true, 2, 6, 9, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char nsnytqxnbb[15];


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

static const Column_element_CFL_t srvasoypas[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&pcntnrkrru},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&alrmqdpuko_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ycmbgohegs},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ijlcniszth},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ponllslqwm_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&zrbbwvccgw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wcysgjibyb},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gfbquulcoh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gmmfrwxtpp},
    {while_handler_CFL,wait_event_handler,(void *)&qqepmatlnb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&stybeynfdg},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pecnyswtmo},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
Bitmap_CFL rcwahwskao[0];
Registermap_CFL_t mhqkvsaach[0];
Floatmap_CFL_t znurocmzqp[0];
const Sm_control_ROM_CFL_t zqsaxulqgh[0];
Sm_control_RAM_CFL_t cachmjvbrp[0];


static Time_control_CFL_t bxyskbrkkw;




static Engine_control_CFL_t qcleggvxlp;


/* remaining allocate heap size */

static unsigned vdhqlaagny;


/* current heap pointer */

static char* tbfovwvmyq;


/* heap block area */

static CS_MEMORY_CONTROL lnhaycromu;


    
    


const struct Handle_CFL_t nqebvzzxin =
{

  .queue_number = 4,
  .queue_rom = plaebuowck,
  .queue_ram = agvzvgvgfh,

  .column_elements_flags =nsnytqxnbb,
  .column_elements_ROM = srvasoypas,

  .watch_dog_struct = whkajjhrmr,
  .watch_dog_count  = oekwlqback,
   
   
  .column_flags = uxobjhsbtu,
  .column_local_data = gxfsijctuv,
  .column_state = szedquvxyq,
  .number_of_columns = 3,
  .column_rom_data = thkvgyaddv,

  
  
  
  .time_control = &bxyskbrkkw,
  .engine_control =&qcleggvxlp,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &vdhqlaagny,
  .current_heap_location = &tbfovwvmyq,
  .private_heap   = &lnhaycromu,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  zqsaxulqgh,
  .sm_ram     = cachmjvbrp,
  .number_of_bitmaps = 0,
  .bitmaps = rcwahwskao,
  .number_of_registermaps = 0,
  .registermaps = mhqkvsaach,
  .number_of_floatmaps = 0,
  .floatmaps = znurocmzqp,
} ;

const Handle_CFL_t*  wait_event_terminate_handle(){
    return &nqebvzzxin;
}
   

#ifdef __cplusplus
}
#endif

#endif
