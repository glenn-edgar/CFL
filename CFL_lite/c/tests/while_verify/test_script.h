#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define fcwiobvkhy 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t ianszwgvhp[10];
static Event_control_RAM_CFL_t dkybacnens[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t gmsptprzxe_default = { 10, 0 };
static const Event_control_ROM_CFL_t *gmsptprzxe[] = {
     &gmsptprzxe_default,
};
static const Named_event_queue_control_CFL_t quxsbsraja = { 1,10,gmsptprzxe };
const Event_data_CFL_t crlkvhvetb = { fcwiobvkhy, false, NULL, };
static const char *epoyzyhitz = "terminate engine column start";


unsigned  llqbchuote;
const While_time_control_ROM_CFL_t hohhirunfa = { 20000,&llqbchuote };



static While_control_RAM_CFL_t quwkzstolq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t anuefjheah_rom = { 0 ,true, &hohhirunfa,&quwkzstolq_ram,null_function};

    
static const char *sfbbgkuzqg = "stop engine";


unsigned  knmmstblkb;
const While_time_control_ROM_CFL_t qkawzbjxpt = { 1000,&knmmstblkb };



static While_control_RAM_CFL_t owkrzeltcx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yloskkuptw_rom = { 0 ,true, &qkawzbjxpt,&owkrzeltcx_ram,null_function};

    
static const char *vlspjiqrtg = "event has been sent";
static const char *fybbzmylrk = "verify reset column";
static const char *zscmgcgdgy = "this column will reset";
    static Verify_control_ROM_CFL_t ieyuzeejjo_rom = { false, (void *)&test_counter_1, verify_one_shot_reset };  // terminate flag,user data,one shot function

static While_control_RAM_CFL_t drjnjwblro_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t smewumlvhz_rom = { 0 ,true, NULL,&drjnjwblro_ram,null_function};

    
static const char *couknuitng = "This should not happen";
static const char *mndmatugbp = "verify terminate column";
static const char *zeothvdkmf = "this column will terminate";
    static Verify_control_ROM_CFL_t eemltmpjqx_rom = { true, (void *)&test_counter_2, verify_one_shot_terminate };  // terminate flag,user data,one shot function

static While_control_RAM_CFL_t quleqmjcxf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cikulmecaq_rom = { 0 ,true, NULL,&quleqmjcxf_ram,null_function};

    
static const char *lxdtzjseez = "This should not happen";


//----------RAM data structures for columns ----

unsigned char uzwfsdptpv[4];
unsigned char gwmxttbcbp[4];
void* wwoimsufdl[4];
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

static const Column_ROM_CFL_t bgnufzcjgs[] = {
  { -1,true, 0, 4, 0, -1, -1,-1 },
  { -1,true, 1, 4, 4, -1, -1,-1 },
  { -1,true, 2, 6, 8, -1, -1,-1 },
  { -1,true, 3, 6, 14, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char nmzdnsiskw[20];


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

static const Column_element_CFL_t ufisnkpgxo[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&epoyzyhitz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&anuefjheah_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sfbbgkuzqg},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yloskkuptw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vlspjiqrtg},
    {one_shot_handler_CFL,send_event_CFL,(void *)&crlkvhvetb},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fybbzmylrk},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zscmgcgdgy},
    {verify_handler_CFL,test_bool_fn_a,(void *)&ieyuzeejjo_rom},
    {while_handler_CFL,false_constant_handler,(void *)&smewumlvhz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&couknuitng},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mndmatugbp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zeothvdkmf},
    {verify_handler_CFL,test_bool_fn_a,(void *)&eemltmpjqx_rom},
    {while_handler_CFL,false_constant_handler,(void *)&cikulmecaq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lxdtzjseez},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t kunyelbykb;




static Engine_control_CFL_t zdqywnokif;




static Engine_control_CFL_t zdqywnokif;


/* remaining allocate heap size */

static unsigned qowhlwohog;


/* current heap pointer */

static char* qhvyqjusps;


/* heap block area */

static CS_MEMORY_CONTROL xeyvhubmgm;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t nhzpyitmwk =
{

  .queue_rom    = &quxsbsraja,
  .queue_ram =  dkybacnens,
  .event_data = ianszwgvhp,

  .column_elements_flags =nmzdnsiskw,
  .column_elements_ROM = ufisnkpgxo,

  .column_flags = uzwfsdptpv,
  .column_local_data = wwoimsufdl,
  .column_state = gwmxttbcbp,
  .number_of_columns = 4,
  .column_rom_data = bgnufzcjgs,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &kunyelbykb,
  .engine_control =&zdqywnokif,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &qowhlwohog,
  .current_heap_location = &qhvyqjusps,
  .private_heap   = &xeyvhubmgm,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  verify_handler(){
    return &nhzpyitmwk;
}
   

#ifdef __cplusplus
}
#endif

#endif
