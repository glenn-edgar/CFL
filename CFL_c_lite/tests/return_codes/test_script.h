#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define fvwoxvznfa 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t itfybfougo[40];
static Event_control_RAM_CFL_t hbimuvgsdx[4];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t razttmtaas_default = { 10, 0 };
static const Event_control_ROM_CFL_t razttmtaas_queue1 = { 10, 10 };
static const Event_control_ROM_CFL_t razttmtaas_queue2 = { 10, 20 };
static const Event_control_ROM_CFL_t razttmtaas_queue3 = { 10, 30 };
static const Event_control_ROM_CFL_t *razttmtaas[] = {
     &razttmtaas_default,
     &razttmtaas_queue1,
     &razttmtaas_queue2,
     &razttmtaas_queue3,
};
static const Named_event_queue_control_CFL_t xxtnfakxhw = { 4,40,razttmtaas };
static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";
static const char user_test_event_data[] = "test message";
const Event_data_CFL_t zfcatsabuz = { fvwoxvznfa, false, ( void *)user_test_event_data, };
static const char *gjfvtwweys = "this is a test message";


unsigned  fnoevkxxsi;
const While_time_control_ROM_CFL_t vfrwwefwaj = { 2000,&fnoevkxxsi };



static While_control_RAM_CFL_t qkjftumpgh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nuasgrdfuz_rom = { 0 ,true, &vfrwwefwaj,&qkjftumpgh_ram,null_function};

    
static const char *sbvryzfdeh = "reseting the column every 2 seconds";
static const char *vqxfspzela = "test_halt_column";
static const char *drukwkiany = "halting the column";
static const char *sbdtntorfa = "test_terminate_column";


unsigned  mesrtfxlzp;
const While_time_control_ROM_CFL_t yrufvwynyg = { 7500,&mesrtfxlzp };



static While_control_RAM_CFL_t letptjdtir_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ddopmojzds_rom = { 0 ,true, &yrufvwynyg,&letptjdtir_ram,null_function};

    
static const char *wdrjgvqdre = "column 3 is terminating after 7.5 seconds";
static const char *bgearachzj = "test_terminate_engine";


unsigned  uqgibyomii;
const While_time_control_ROM_CFL_t zxfvmyglsw = { 10000,&uqgibyomii };



static While_control_RAM_CFL_t korxhxoakk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pjpdjaagdu_rom = { 0 ,true, &zxfvmyglsw,&korxhxoakk_ram,null_function};

    
static const char *rsdurorxed = "column 4 is terminating engine after 10 seconds";
static const char *grazewdfsx = "test_terminate_engine 5 second termination";
 unsigned gnjmffnxox_ram;
const While_event_control_ROM_t gnjmffnxox_rom = { 9,fvwoxvznfa,0,true,NULL,&gnjmffnxox_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t fleptgfyjr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t furfyvrcid_rom = { 0 ,true, &gnjmffnxox_rom,&fleptgfyjr_ram,null_function};

    
static const char *jpjkdtlgir = "column 5 is terminating engine after 9 events";


//----------RAM data structures for columns ----

unsigned char sgzywsdcor[5];
unsigned char ifumohqnin[5];
void* eouhbjujyp[5];
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

static const Column_ROM_CFL_t opomgigjbf[] = {
  { 1,true, 0, 8, 0, -1, -1,-1 },
  { 2,true, 1, 3, 8, -1, -1,-1 },
  { 3,true, 2, 4, 11, -1, -1,-1 },
  { -1,true, 3, 4, 15, -1, -1,-1 },
  { -1,true, 4, 4, 19, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char drzvrryaus[23];


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

static const Column_element_CFL_t saqcytgwvb[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&gjfvtwweys},
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message},
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message},
    {one_shot_handler_CFL,send_event_CFL,(void *)&zfcatsabuz},
    {one_shot_handler_CFL,send_event_CFL,(void *)&zfcatsabuz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nuasgrdfuz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sbvryzfdeh},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vqxfspzela},
    {one_shot_handler_CFL,log_message_CFL,(void *)&drukwkiany},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sbdtntorfa},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ddopmojzds_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wdrjgvqdre},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bgearachzj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pjpdjaagdu_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rsdurorxed},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&grazewdfsx},
    {while_handler_CFL,wait_event_handler,(void *)&furfyvrcid_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jpjkdtlgir},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t kuhrepztxp;




static Engine_control_CFL_t uewbfydkra;




static Engine_control_CFL_t uewbfydkra;


/* remaining allocate heap size */

static unsigned gpyazroobf;


/* current heap pointer */

static char* cmbablvdgy;


/* heap block area */

static CS_MEMORY_CONTROL upqwjamdoi;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t shsvbizrxo =
{

  .queue_rom    = &xxtnfakxhw,
  .queue_ram =  hbimuvgsdx,
  .event_data = itfybfougo,

  .column_elements_flags =drzvrryaus,
  .column_elements_ROM = saqcytgwvb,

  .column_flags = sgzywsdcor,
  .column_local_data = eouhbjujyp,
  .column_state = ifumohqnin,
  .number_of_columns = 5,
  .column_rom_data = opomgigjbf,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &kuhrepztxp,
  .engine_control =&uewbfydkra,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &gpyazroobf,
  .current_heap_location = &cmbablvdgy,
  .private_heap   = &upqwjamdoi,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &shsvbizrxo;
}
   

#ifdef __cplusplus
}
#endif

#endif
