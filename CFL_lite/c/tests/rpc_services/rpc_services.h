#ifndef __rpc_services_H__
#define __rpc_services_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t kvhzszoeod[5];
static Event_data_CFL_t xkqddpokeh[10];
static Event_data_CFL_t khlusemerf[10];
static Event_data_CFL_t bshohhncgl[10];
static Event_data_CFL_t copekdvjzn[10];
static Event_data_CFL_t jjzxhlothf[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t wxhmxutbfo[] = { 
     {  10, xkqddpokeh },
     {  10, khlusemerf },
     {  10, bshohhncgl },
     {  10, copekdvjzn },
     {  10, jjzxhlothf },
};
const char clean_up_data[] = "clean up data for bad event";
static const char *mesnfermnu = "start column";
static const unsigned short phpdwucquw[] = { 1,2,3,4};
const Enable_column_CFL_t lvqryibglx = { true, 4, phpdwucquw };


unsigned  mhxflfxduk;
const While_time_control_ROM_CFL_t fjekufgcgt = { 60000,&mhxflfxduk };



static While_control_RAM_CFL_t nfmubuwkbm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mhrnhxaxxz_rom = { 0 ,true, &fjekufgcgt,&nfmubuwkbm_ram,null_function};

    
static const char *brrcmnaelk = "terminating";
const unsigned short vcxsnisqxt[] = {11, 12, 13, 14, 15};
const rpc_server_event_processor_CFL_t vypvnwvzdg = {NULL,5,vcxsnisqxt};
const unsigned short jpxrddqvsp[] = {21, 22, 23, 24, 25};
const rpc_server_event_processor_CFL_t xqgaemdwog = {NULL,5,jpxrddqvsp};
rpc_server_event_clean_up_CFL_t ptcbelzgod = {(void *)clean_up_data,true};


unsigned  ccdpuvyhdw;
const While_time_control_ROM_CFL_t gtwispwboj = { 45000,&ccdpuvyhdw };



static While_control_RAM_CFL_t qgnmlhvkmj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t axosizufpx_rom = { 0 ,true, &gtwispwboj,&qgnmlhvkmj_ram,null_function};

    


//----------RAM data structures for columns ----

unsigned tvmezfijqy[5];
Watch_dog_struct_CFL_t * efdosernyy[5];
unsigned char uwzshxdyfh[5];
unsigned char pjoxtrjonf[5];
void* vyghinkgbe[5];
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

static const Column_ROM_CFL_t rbnixnzarw[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { 1,true, 1, 4, 5, -1, -1 },
  { 2,true, 2, 1, 9, -1, -1 },
  { 3,true, 3, 1, 10, -1, -1 },
  { 4,true, 4, 2, 11, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char gvdpdodgiy[13];


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

static const Column_element_CFL_t voptradebe[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&mesnfermnu},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&lvqryibglx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mhrnhxaxxz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&brrcmnaelk},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {rpc_server_event_processor_CFL,service_handler_1,(void *)&vypvnwvzdg},
    {rpc_server_event_processor_CFL,service_handler_2,(void *)&xqgaemdwog},
    {rpc_server_event_clean_up_CFL,rpc_clean_up_one_shot,(void *)&ptcbelzgod},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&axosizufpx_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};
const Sm_control_ROM_CFL_t ihyrwgfjpi[0];
Sm_control_RAM_CFL_t cbswvahhtj[0];


static Time_control_CFL_t begnkugrvd;




static Engine_control_CFL_t ckutbwjbqk;


/* remaining allocate heap size */

static unsigned trbvjttwvn;


/* current heap pointer */

static char* bjhcmtjgqo;


/* heap block area */

static CS_MEMORY_CONTROL nafhevqbkh;


    
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


const struct Handle_CFL_t pentfpjixb =
{

  .queue_number = 5,
  .queue_rom = wxhmxutbfo,
  .queue_ram = kvhzszoeod,

  .column_elements_flags =gvdpdodgiy,
  .column_elements_ROM = voptradebe,

  .watch_dog_struct = efdosernyy,
  .watch_dog_count  = tvmezfijqy,
   
   
  .column_flags = uwzshxdyfh,
  .column_local_data = vyghinkgbe,
  .column_state = pjoxtrjonf,
  .number_of_columns = 5,
  .column_rom_data = rbnixnzarw,

  
  
  
  .time_control = &begnkugrvd,
  .engine_control =&ckutbwjbqk,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &trbvjttwvn,
  .current_heap_location = &bjhcmtjgqo,
  .private_heap   = &nafhevqbkh,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
   .sm_rom     =  ihyrwgfjpi,
   .sm_ram     = cbswvahhtj,
} ;


const Handle_CFL_t*  rpc_services_handle(){
    return &pentfpjixb;
}
   

#ifdef __cplusplus
}
#endif

#endif
