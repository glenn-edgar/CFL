#ifndef __delay_wait_H__
#define __delay_wait_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t qmeotyozox[10];
static Event_control_RAM_CFL_t zopeutwruh[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t kpquvzarzv_default = { 10, 0 };
static const Event_control_ROM_CFL_t *kpquvzarzv[] = {
     &kpquvzarzv_default,
};
static const Named_event_queue_control_CFL_t gqzkobqofh = { 1,10,kpquvzarzv };
static const char *pwmswruhms = "this column will terminate the engine after 10 seconds";


unsigned  twuocxsesa;
const While_time_control_ROM_CFL_t bkifbpgnzh = { 10000,&twuocxsesa };



static While_control_RAM_CFL_t oefhqtoopk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pskithztho_rom = { 0 ,true, &bkifbpgnzh,&oefhqtoopk_ram,null_function};

    
static const char *tczimyjmlf = "time delay done";
static const char *fzcculowuw = "stop engine";
static const char *ngxxllqful = "this column will reset the engine every 2 seconds";


unsigned  yyxsdbgshz;
const While_time_control_ROM_CFL_t wxneerfoej = { 2000,&yyxsdbgshz };



static While_control_RAM_CFL_t ifolrqmxmb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tiubqxsqjc_rom = { 0 ,true, &wxneerfoej,&ifolrqmxmb_ram,null_function};

    
static const char *iokqnsulij = "two seconds past-- reset column";


//----------RAM data structures for columns ----

unsigned char txvnwfxwcm[2];
unsigned char vtninhblqs[2];
void* gjnqzreepc[2];
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

static const Column_ROM_CFL_t smoclgggsr[] = {
  { -1,true, 0, 5, 0, -1, -1,-1 },
  { -1,true, 1, 4, 5, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char coxetsuwsb[9];


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

static const Column_element_CFL_t ldksfzjbfx[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&pwmswruhms},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pskithztho_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tczimyjmlf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fzcculowuw},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ngxxllqful},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tiubqxsqjc_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iokqnsulij},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t ruekdajtfa;




static Engine_control_CFL_t cfmzieczra;


/* remaining allocate heap size */

static unsigned omdtsetewu;


/* current heap pointer */

static char* ulsbuopkuw;


/* heap block area */

static CS_MEMORY_CONTROL igzbqnemzl;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t zwncalykbg =
{

  .queue_rom    = &gqzkobqofh,
  .queue_ram =  zopeutwruh,
  .event_data = qmeotyozox,

  .column_elements_flags =coxetsuwsb,
  .column_elements_ROM = ldksfzjbfx,

  .column_flags = txvnwfxwcm,
  .column_local_data = gjnqzreepc,
  .column_state = vtninhblqs,
  .number_of_columns = 2,
  .column_rom_data = smoclgggsr,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &ruekdajtfa,
  .engine_control =&cfmzieczra,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &omdtsetewu,
  .current_heap_location = &ulsbuopkuw,
  .private_heap   = &igzbqnemzl,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  delay_wait_handle(){
    return &zwncalykbg;
}
   

#ifdef __cplusplus
}
#endif

#endif
