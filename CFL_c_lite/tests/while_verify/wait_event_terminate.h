#ifndef __wait_event_terminate_H__
#define __wait_event_terminate_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define ixhvixlekw 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t eyrmkbgyln[10];
static Event_control_RAM_CFL_t fvqvbgpont[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t bourxgjqfv_default = { 10, 0 };
static const Event_control_ROM_CFL_t *bourxgjqfv[] = {
     &bourxgjqfv_default,
};
static const Named_event_queue_control_CFL_t fdptzrdzzd = { 1,10,bourxgjqfv };

static const char wait_event_terminate_message_b[] = "wait event terminate function called\n";


const Event_data_CFL_t vmttxxxcjw = { ixhvixlekw, false, NULL, };
static const char *oaiamcdamc = "this column will terminate the engine";


unsigned  xopcuzoodu;
const While_time_control_ROM_CFL_t ebozyttqdg = { 11000,&xopcuzoodu };



static While_control_RAM_CFL_t txdiylkjbp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wuqljlpyxw_rom = { 0 ,true, &ebozyttqdg,&txdiylkjbp_ram,null_function};

    
static const char *zigmvwjvzt = "stopping engine because 11 seconds have passed";
static const char *djiqycxwki = "this column will generate an event every second";


unsigned  dagmzbhjsw;
const While_time_control_ROM_CFL_t ilqeawwfwk = { 1000,&dagmzbhjsw };



static While_control_RAM_CFL_t gniqlnxats_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ydmnnmkjzd_rom = { 0 ,true, &ilqeawwfwk,&gniqlnxats_ram,null_function};

    
static const char *slxkadqsfq = "sending event";
static const char *mzsskmtzcl = "wait event is column is starting";
static const char *tirzkicizg = "this column will terminate because not enough time to receive 10 events";
 unsigned ldqipwokjo_ram;
const While_event_control_ROM_t ldqipwokjo_rom = { 10,ixhvixlekw,9000,false,wait_event_terminate_message_b,&ldqipwokjo_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t qxdgbwqvlu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ayxnandvdg_rom = { 9000 ,false, &ldqipwokjo_rom,&qxdgbwqvlu_ram,wait_event_terminate_b};

    
static const char *iwjfstvcvn = "10 events have been received";
static const char *whfdxjgtse = "stopping engine";


//----------RAM data structures for columns ----

unsigned char qhocjfvqhh[3];
unsigned char myiknclpat[3];
void* zdolhedtod[3];
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

static const Column_ROM_CFL_t gupbwqkfle[] = {
  { -1,true, 0, 4, 0, -1, -1,-1 },
  { -1,true, 1, 5, 4, -1, -1,-1 },
  { -1,true, 2, 6, 9, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char jeyykqxhey[15];


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

static const Column_element_CFL_t sripaynxek[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&oaiamcdamc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wuqljlpyxw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zigmvwjvzt},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&djiqycxwki},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ydmnnmkjzd_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&vmttxxxcjw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&slxkadqsfq},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzsskmtzcl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tirzkicizg},
    {while_handler_CFL,wait_event_handler,(void *)&ayxnandvdg_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iwjfstvcvn},
    {one_shot_handler_CFL,log_message_CFL,(void *)&whfdxjgtse},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t faaqorvtvf;




static Engine_control_CFL_t cjwmumorui;




static Engine_control_CFL_t cjwmumorui;


/* remaining allocate heap size */

static unsigned rhyasmqgwp;


/* current heap pointer */

static char* zhnobsksrx;


/* heap block area */

static CS_MEMORY_CONTROL ilqxtowfvd;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t wjxlalmcct =
{

  .queue_rom    = &fdptzrdzzd,
  .queue_ram =  fvqvbgpont,
  .event_data = eyrmkbgyln,

  .column_elements_flags =jeyykqxhey,
  .column_elements_ROM = sripaynxek,

  .column_flags = qhocjfvqhh,
  .column_local_data = zdolhedtod,
  .column_state = myiknclpat,
  .number_of_columns = 3,
  .column_rom_data = gupbwqkfle,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &faaqorvtvf,
  .engine_control =&cjwmumorui,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &rhyasmqgwp,
  .current_heap_location = &zhnobsksrx,
  .private_heap   = &ilqxtowfvd,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  wait_event_terminate_handle(){
    return &wjxlalmcct;
}
   

#ifdef __cplusplus
}
#endif

#endif
