#ifndef __return_codes_H__
#define __return_codes_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



 #define test_event 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t patlowyrgt[6];
static Event_data_CFL_t gkmdwornsp[7];
static Event_data_CFL_t gxgyvatiyk[10];
static Event_data_CFL_t mmayrssejl[5];
static Event_data_CFL_t vcdxahuaej[0];
static Event_data_CFL_t xyvhwdxgee[6];
static Event_data_CFL_t vcbyeyiewu[6];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t idjholycca[] = { 
     {  7, gkmdwornsp },
     {  10, gxgyvatiyk },
     {  5, mmayrssejl },
     {  0, vcdxahuaej },
     {  6, xyvhwdxgee },
     {  6, vcbyeyiewu },
};
static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";
static const char user_test_event_data[] = "test message";
const Event_data_CFL_t xmanvzfujl = { test_event, false, ( void *)user_test_event_data };
static const Log_message_CFL_t eimqvhuuqo = { "this is a test message", false, NULL };
static const Log_message_CFL_t onakfwwqay = { "entry message", true, "exit message" };


unsigned  dduqfzccoj;
const While_time_control_ROM_CFL_t wjexoxaeig = { 2000,&dduqfzccoj };



static While_control_RAM_CFL_t imvaubhmkb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t czheenhonh_rom = { 0 ,true, (void*)&wjexoxaeig,&imvaubhmkb_ram,null_function};

    
static const Log_message_CFL_t uelgzeyklb = { "reseting the column every 2 seconds", false, NULL };
static const Log_message_CFL_t bykmixbikd = { "test_halt_column", false, NULL };
static const Log_message_CFL_t hcpdirkpnn = { "halting the column", false, NULL };
static const Log_message_CFL_t ejtkqtouwf = { "test_terminate_column", false, NULL };


unsigned  gudikpseic;
const While_time_control_ROM_CFL_t pcyeioavpe = { 7500,&gudikpseic };



static While_control_RAM_CFL_t mlguubvodu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t gvbmazgugo_rom = { 0 ,true, (void*)&pcyeioavpe,&mlguubvodu_ram,null_function};

    
static const Log_message_CFL_t zzxsroghnz = { "column 3 is terminating after 7.5 seconds", false, NULL };
static const Log_message_CFL_t gnzspcfivx = { "test_terminate_engine", false, NULL };


unsigned  jayoandmak;
const While_time_control_ROM_CFL_t mozlfmgdje = { 10000,&jayoandmak };



static While_control_RAM_CFL_t apqdywboti_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t luekrsroly_rom = { 0 ,true, (void*)&mozlfmgdje,&apqdywboti_ram,null_function};

    
static const Log_message_CFL_t lxoslmbpfk = { "column 4 is terminating engine after 10 seconds", false, NULL };
static const Log_message_CFL_t egkcmofhpe = { "test counting 9 events", false, NULL };
 unsigned iypxmcrnaz_ram;
const While_event_control_ROM_t iypxmcrnaz_rom = { 9,test_event,0,true,NULL,&iypxmcrnaz_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t fvaonkujqx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uhxqvliies_rom = { 0 ,true, (void*)&iypxmcrnaz_rom,&fvaonkujqx_ram,null_function};

    
static const Log_message_CFL_t mimkcqknrz = { "column 5 is terminating engine after 9 events", false, NULL };


//----------RAM data structures for columns ----

unsigned hnpkqluooi[5];
Watch_dog_struct_CFL_t * skxpriojwa[5];
unsigned char cmjwembgus[5];
unsigned char uzcklevtxy[5];
void* givshznjjq[5];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t ejbwgvuzqs[] = {
  { 1,true, 0, 9, 0, -1, -1,NULL },
  { 2,true, 1, 4, 9, -1, -1,NULL },
  { 3,true, 2, 5, 13, -1, -1,NULL },
  { 4,true, 3, 5, 18, -1, -1,NULL },
  { 5,true, 4, 4, 23, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char sofayvswpz[27];


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

static const Column_element_CFL_t vtdgivznzu[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&eimqvhuuqo}, // 0 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&onakfwwqay}, // 1 
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message}, // 2 
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message}, // 3 
    {one_shot_handler_CFL,send_event_CFL,(void *)&xmanvzfujl}, // 4 
    {one_shot_handler_CFL,send_event_CFL,(void *)&xmanvzfujl}, // 5 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&czheenhonh_rom}, // 6 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&uelgzeyklb}, // 7 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 8 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&bykmixbikd}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hcpdirkpnn}, // 10 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 11 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 12 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ejtkqtouwf}, // 13 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&gvbmazgugo_rom}, // 14 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zzxsroghnz}, // 15 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 16 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 17 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&gnzspcfivx}, // 18 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&luekrsroly_rom}, // 19 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&lxoslmbpfk}, // 20 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 21 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 22 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&egkcmofhpe}, // 23 
    {while_handler_CFL,wait_event_handler,(void *)&uhxqvliies_rom}, // 24 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&mimkcqknrz}, // 25 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 26 
};
Bitmap_CFL dysbbikqck[0];
Registermap_CFL_t ksxwvqklip[0];
Floatmap_CFL_t lzgumrtfsc[0];
const Sm_control_ROM_CFL_t cxggrhshap[0];
Sm_control_RAM_CFL_t qrzmbcdudr[0];


static Time_control_CFL_t pllovaluld;




static Engine_control_CFL_t fpyfkuizlj;


/* remaining allocate heap size */

static unsigned rqhqpanhoy;


/* current heap pointer */

static char* neisbethrh;


/* heap block area */

static CS_MEMORY_CONTROL axwodfgyhb;


    
    


const struct Handle_CFL_t fdzuhtugov =
{

  .queue_number = 6,
  .queue_rom = idjholycca,
  .queue_ram = patlowyrgt,

  .column_elements_flags =sofayvswpz,
  .column_elements_ROM = vtdgivznzu,

  .watch_dog_struct = skxpriojwa,
  .watch_dog_count  = hnpkqluooi,
   
   
  .column_flags = cmjwembgus,
  .column_local_data = givshznjjq,
  .column_state = uzcklevtxy,
  .number_of_columns = 5,
  .column_rom_data = ejbwgvuzqs,

  
  
  
  .time_control = &pllovaluld,
  .engine_control =&fpyfkuizlj,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &rqhqpanhoy,
  .current_heap_location = &neisbethrh,
  .private_heap   = &axwodfgyhb,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  cxggrhshap,
  .sm_ram     = qrzmbcdudr,
  .number_of_bitmaps = 0,
  .bitmaps = dysbbikqck,
  .number_of_registermaps = 0,
  .registermaps = ksxwvqklip,
  .number_of_floatmaps = 0,
  .floatmaps = lzgumrtfsc,
} ;

const Handle_CFL_t*  return_codes_entry_point(){
    return &fdzuhtugov;
}
   

#ifdef __cplusplus
}
#endif

#endif
