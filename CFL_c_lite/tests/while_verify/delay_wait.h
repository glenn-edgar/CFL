#ifndef __delay_wait_H__
#define __delay_wait_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t zkhuzuebrj[10];
static Event_control_RAM_CFL_t bzftmlcnbk[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t yoizsosuuv_default = { 10, 0 };
static const Event_control_ROM_CFL_t *yoizsosuuv[] = {
     &yoizsosuuv_default,
};
static const Named_event_queue_control_CFL_t cjxhvjmwmd = { 1,10,yoizsosuuv };
static const char *nomgnpcnrm = "this column will terminate the engine after 10 seconds";


unsigned  qivvhlerfz;
const While_time_control_ROM_CFL_t dhvysepanm = { 10000,&qivvhlerfz };



static While_control_RAM_CFL_t pmlnmdnhli_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hujqttjesz_rom = { 0 ,true, &dhvysepanm,&pmlnmdnhli_ram,null_function};

    
static const char *tzqhkusoco = "time delay done";
static const char *zbybxogtzu = "stop engine";
static const char *gzbpcjdqyn = "this column will reset the engine every 2 seconds";


unsigned  hphhowmijn;
const While_time_control_ROM_CFL_t gvopnjntfx = { 2000,&hphhowmijn };



static While_control_RAM_CFL_t kxrmsudmjp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xmzrxvonuo_rom = { 0 ,true, &gvopnjntfx,&kxrmsudmjp_ram,null_function};

    
static const char *fgrgceecry = "two seconds past-- reset column";


//----------RAM data structures for columns ----

unsigned char gcdwxywzkk[2];
unsigned char elzaopfjcn[2];
void* ayopyrtddh[2];
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

static const Column_ROM_CFL_t xqtuxlxaoh[] = {
  { -1,true, 0, 5, 0, -1, -1,-1 },
  { -1,true, 1, 4, 5, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char gxxndkmngt[9];


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

static const Column_element_CFL_t zprhksydsd[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&nomgnpcnrm},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hujqttjesz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tzqhkusoco},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zbybxogtzu},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gzbpcjdqyn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xmzrxvonuo_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fgrgceecry},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t rfjlhcjftx;




static Engine_control_CFL_t kczrawkglf;




static Engine_control_CFL_t kczrawkglf;


/* remaining allocate heap size */

static unsigned yhjztacubr;


/* current heap pointer */

static char* dzbafmlabf;


/* heap block area */

static CS_MEMORY_CONTROL povpzzwesq;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t oqlulkbycd =
{

  .queue_rom    = &cjxhvjmwmd,
  .queue_ram =  bzftmlcnbk,
  .event_data = zkhuzuebrj,

  .column_elements_flags =gxxndkmngt,
  .column_elements_ROM = zprhksydsd,

  .column_flags = gcdwxywzkk,
  .column_local_data = ayopyrtddh,
  .column_state = elzaopfjcn,
  .number_of_columns = 2,
  .column_rom_data = xqtuxlxaoh,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &rfjlhcjftx,
  .engine_control =&kczrawkglf,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &yhjztacubr,
  .current_heap_location = &dzbafmlabf,
  .private_heap   = &povpzzwesq,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  delay_wait_handle(){
    return &oqlulkbycd;
}
   

#ifdef __cplusplus
}
#endif

#endif
