#ifndef __while_user_function_H__
#define __while_user_function_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define test_event 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t gtjclnaaek[6];
static Event_data_CFL_t dpbyminmes[7];
static Event_data_CFL_t dyavcroxxw[0];
static Event_data_CFL_t wultcmseyx[0];
static Event_data_CFL_t zbxqsuqkac[0];
static Event_data_CFL_t nwvupxuiit[0];
static Event_data_CFL_t uczylxuhxi[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t aexlcpvwpt[] = { 
     {  7, dpbyminmes },
     {  0, dyavcroxxw },
     {  0, wultcmseyx },
     {  0, zbxqsuqkac },
     {  0, nwvupxuiit },
     {  0, uczylxuhxi },
};
const Event_data_CFL_t ittpbxxhck = { test_event, false, NULL };

static unsigned test_counter = 0;



static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
static const char *wumwkubsuk = "this column will terminate the engine";


unsigned  gpkiwpcobi;
const While_time_control_ROM_CFL_t yivugpzybo = { 16000,&gpkiwpcobi };



static While_control_RAM_CFL_t lmgwclnxru_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qrlnsdicna_rom = { 0 ,true, (void*)&yivugpzybo,&lmgwclnxru_ram,null_function};

    
static const char *fcjlhfjska = "stopping engine because 16 seconds have passed";
static const char *okmjaocnol = "this column will generate an event every second";


unsigned  hdhpstntro;
const While_time_control_ROM_CFL_t kyjntwwcue = { 1000,&hdhpstntro };



static While_control_RAM_CFL_t cofuhtmxdi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jljdztxejc_rom = { 0 ,true, (void*)&kyjntwwcue,&cofuhtmxdi_ram,null_function};

    
static const char *itoyiskfjr = "sending event";
static const char *fhbrhilakt = "user function column is starting";

static While_control_RAM_CFL_t nefxqpkanv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ssgloyshaf_rom = { 0 ,false, (void*)&test_counter,&nefxqpkanv_ram,null_function};

    
static const char *iayxothjka = "user function has passed";
static const char *xklgapkiia = "terminating column";
static const char *zekisnavuz = "this demonstrates the reset feature of the wait opcode";

static While_control_RAM_CFL_t ovzyazjrdc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kzykhgczwe_rom = { 5000 ,false, (void*)&wait_event_reset_message,&ovzyazjrdc_ram,wait_event_reset};

    
static const char *dqmyjswayf = "10 events have been received";
static const char *cojakqotre = "terminating column";
static const char *cikxgvermg = "this demonstrates the terminate feature of the wait opcode";

static While_control_RAM_CFL_t ksoehzpzxj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zhhtmitlva_rom = { 5000 ,true, (void*)&wait_event_terminate_message,&ksoehzpzxj_ram,wait_event_terminate};

    
static const char *ffrmwwnqra = "This step should not happpen as the wait opcode will reset because of timeout";


//----------RAM data structures for columns ----

unsigned nbwxgzdmmg[5];
Watch_dog_struct_CFL_t * jlmijezlsu[5];
unsigned char khoshovctu[5];
unsigned char pygseckwgv[5];
void* enjjhpnson[5];
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

static const Column_ROM_CFL_t ikyedhrohn[] = {
  { 1,true, 0, 4, 0, -1, -1 },
  { 2,true, 1, 5, 4, -1, -1 },
  { 3,true, 2, 5, 9, -1, -1 },
  { 4,true, 3, 4, 19, -1, -1 },
  { 5,true, 4, 5, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char ozwqlncxiy[23];


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

static const Column_element_CFL_t bwrpezkdvn[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&wumwkubsuk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qrlnsdicna_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fcjlhfjska},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&okmjaocnol},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jljdztxejc_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&ittpbxxhck},
    {one_shot_handler_CFL,log_message_CFL,(void *)&itoyiskfjr},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fhbrhilakt},
    {while_handler_CFL,test_bool_fn,(void *)&ssgloyshaf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iayxothjka},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xklgapkiia},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zekisnavuz},
    {while_handler_CFL,false_constant_handler,(void *)&kzykhgczwe_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dqmyjswayf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cojakqotre},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cikxgvermg},
    {while_handler_CFL,false_constant_handler,(void *)&zhhtmitlva_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ffrmwwnqra},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};
Bitmap_CFL fcbljkmvmp[0];
Registermap_CFL_t mmfbmvalbl[0];
Floatmap_CFL_t ibpiufusne[0];
const Sm_control_ROM_CFL_t fguskqjicm[0];
Sm_control_RAM_CFL_t hbbwbdoatk[0];


static Time_control_CFL_t ahxvkiejio;




static Engine_control_CFL_t qskenmrrbh;


/* remaining allocate heap size */

static unsigned ppbktnzfyp;


/* current heap pointer */

static char* csghtixqsh;


/* heap block area */

static CS_MEMORY_CONTROL skjroxdjnc;


    
    


const struct Handle_CFL_t ptcbuslagv =
{

  .queue_number = 6,
  .queue_rom = aexlcpvwpt,
  .queue_ram = gtjclnaaek,

  .column_elements_flags =ozwqlncxiy,
  .column_elements_ROM = bwrpezkdvn,

  .watch_dog_struct = jlmijezlsu,
  .watch_dog_count  = nbwxgzdmmg,
   
   
  .column_flags = khoshovctu,
  .column_local_data = enjjhpnson,
  .column_state = pygseckwgv,
  .number_of_columns = 5,
  .column_rom_data = ikyedhrohn,

  
  
  
  .time_control = &ahxvkiejio,
  .engine_control =&qskenmrrbh,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &ppbktnzfyp,
  .current_heap_location = &csghtixqsh,
  .private_heap   = &skjroxdjnc,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  fguskqjicm,
  .sm_ram     = hbbwbdoatk,
  .number_of_bitmaps = 0,
  .bitmaps = fcbljkmvmp,
  .number_of_registermaps = 0,
  .registermaps = mmfbmvalbl,
  .number_of_floatmaps = 0,
  .floatmaps = ibpiufusne,
} ;

const Handle_CFL_t*  while_user_function_handle(){
    return &ptcbuslagv;
}
   

#ifdef __cplusplus
}
#endif

#endif
