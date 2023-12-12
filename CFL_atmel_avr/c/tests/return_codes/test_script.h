#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define achkyqojfq 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t pxsjtnzkcw[4];
static Event_data_CFL_t qnrgvbmhnw[10];
static Event_data_CFL_t uvfiwikxpj[10];
static Event_data_CFL_t fonvsscoro[10];
static Event_data_CFL_t urgqhzlfvt[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t rwihehaxlh[] = { 
     {  10, qnrgvbmhnw },
     {  10, uvfiwikxpj },
     {  10, fonvsscoro },
     {  10, urgqhzlfvt },
};
static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";
static const char user_test_event_data[] = "test message";
const Event_data_CFL_t rgcfccznjn = { achkyqojfq, false, ( void *)user_test_event_data };
static const char *vrmqubwwbr = "this is a test message";


unsigned  ekdgfqybzt;
const While_time_control_ROM_CFL_t lcgvhteqhu = { 2000,&ekdgfqybzt };



static While_control_RAM_CFL_t xrcupsmguw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hgbqeddcym_rom = { 0 ,true, &lcgvhteqhu,&xrcupsmguw_ram,null_function};

    
static const char *vxzknwbero = "reseting the column every 2 seconds";
static const char *aoubealabs = "test_halt_column";
static const char *vorjpbejqe = "halting the column";
static const char *tovcgkxzip = "test_terminate_column";


unsigned  tkmciemnnw;
const While_time_control_ROM_CFL_t hvhbrkytaa = { 7500,&tkmciemnnw };



static While_control_RAM_CFL_t jqafedodlt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kqdjzhrnig_rom = { 0 ,true, &hvhbrkytaa,&jqafedodlt_ram,null_function};

    
static const char *ifkptkwtno = "column 3 is terminating after 7.5 seconds";
static const char *bcorwllomn = "test_terminate_engine";


unsigned  jvakmsdhii;
const While_time_control_ROM_CFL_t vigcjnbgqw = { 10000,&jvakmsdhii };



static While_control_RAM_CFL_t nwkxjaybca_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fyuvgmuncf_rom = { 0 ,true, &vigcjnbgqw,&nwkxjaybca_ram,null_function};

    
static const char *vufjjxdbjn = "column 4 is terminating engine after 10 seconds";
static const char *ethugutuvt = "test_terminate_engine 5 second termination";
 unsigned swibtmpoku_ram;
const While_event_control_ROM_t swibtmpoku_rom = { 9,achkyqojfq,0,true,NULL,&swibtmpoku_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t vxvoyqsbbg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vwzgphmmgb_rom = { 0 ,true, &swibtmpoku_rom,&vxvoyqsbbg_ram,null_function};

    
static const char *tzoxwmotth = "column 5 is terminating engine after 9 events";


//----------RAM data structures for columns ----

unsigned oexldjrexs[5];
Watch_dog_struct_CFL_t * przepywxhl[5];
unsigned char exprkggfwd[5];
unsigned char pvirkevlac[5];
void* emltprifvk[5];
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

static const Column_ROM_CFL_t cdkeumwnwg[] = {
  { 1,true, 0, 8, 0, -1, -1 },
  { 2,true, 1, 3, 8, -1, -1 },
  { 3,true, 2, 4, 11, -1, -1 },
  { -1,true, 3, 4, 15, -1, -1 },
  { -1,true, 4, 4, 19, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char wpmqwsnrrq[23];


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

static const Column_element_CFL_t rbtcyvpxgx[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&vrmqubwwbr},
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message},
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message},
    {one_shot_handler_CFL,send_event_CFL,(void *)&rgcfccznjn},
    {one_shot_handler_CFL,send_event_CFL,(void *)&rgcfccznjn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hgbqeddcym_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vxzknwbero},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aoubealabs},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vorjpbejqe},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tovcgkxzip},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kqdjzhrnig_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ifkptkwtno},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bcorwllomn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fyuvgmuncf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vufjjxdbjn},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ethugutuvt},
    {while_handler_CFL,wait_event_handler,(void *)&vwzgphmmgb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tzoxwmotth},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
const Sm_control_ROM_CFL_t socxfriqwv[0];
Sm_control_RAM_CFL_t rpzgljpkoy[0];


static Time_control_CFL_t izjwmivmao;




static Engine_control_CFL_t snflbzubjw;


/* remaining allocate heap size */

static unsigned ywxnmusbgd;


/* current heap pointer */

static char* yoslaqiwcg;


/* heap block area */

static CS_MEMORY_CONTROL jljxmmcsxj;


    
    /*
    --------------------------- Handle definition ------------------------------
   
    typedef struct Handle_CFL_t
    {
      const unsigned queue_number;
      const Event_control_ROM_CFL_t *queue_rom;
      Event_control_RAM_CFL_t *queue_ram;
      
    
      unsigned char *column_elements_flags;
      const Column_element_CFL_t *column_elements_ROM;
    
      unsigned char *column_flags;
      void **column_local_data;
      unsigned char *column_state;
      const unsigned short number_of_columns;
      const Column_ROM_CFL_t *column_rom_data;
    
      
      Watch_dog_struct_CFL_t **watch_dog_struct;
      unsigned *watch_dog_count;
     
      
      Time_control_CFL_t *time_control;
      Engine_control_CFL_t *engine_control;
      Debug_out_CFL_t debug_function;
      private_heap_malloc_fn malloc;
      private_heap_free_fn free;
      allocate_once_fn allocate_once;
      char **master_heap_starting_location; 
      const unsigned master_heap_size;             
      unsigned *remaining_heap_size;  // set by c runtime
      char **current_heap_location;  // set by c runtime
      CS_MEMORY_CONTROL *private_heap;      
      
      unsigned private_heap_size;
      unsigned number_of_sm;
      Sm_control_ROM_CFL_t *sm_rom;
      Sm_control_RAM_CFL_t *sm_ram;
    
    
    } Handle_CFL_t;

    
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


const struct Handle_CFL_t djukadpzfd =
{

  .queue_number = 4,
  .queue_rom = rwihehaxlh,
  .queue_ram = pxsjtnzkcw,

  .column_elements_flags =wpmqwsnrrq,
  .column_elements_ROM = rbtcyvpxgx,

  .watch_dog_struct = przepywxhl,
  .watch_dog_count  = oexldjrexs,
   
   
  .column_flags = exprkggfwd,
  .column_local_data = emltprifvk,
  .column_state = pvirkevlac,
  .number_of_columns = 5,
  .column_rom_data = cdkeumwnwg,

  
  
  
  .time_control = &izjwmivmao,
  .engine_control =&snflbzubjw,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &ywxnmusbgd,
  .current_heap_location = &yoslaqiwcg,
  .private_heap   = &jljxmmcsxj,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
   .sm_rom     =  socxfriqwv,
   .sm_ram     = rpzgljpkoy,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &djukadpzfd;
}
   

#ifdef __cplusplus
}
#endif

#endif
