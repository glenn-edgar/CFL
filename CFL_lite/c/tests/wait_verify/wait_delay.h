#ifndef __wait_delay_H__
#define __wait_delay_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t yfbhushzkb[3];
static Event_data_CFL_t jehnefovgw[7];
static Event_data_CFL_t ymyonntueh[0];
static Event_data_CFL_t lkcmifrncg[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t mzdaaoknop[] = { 
     {  7, jehnefovgw },
     {  0, ymyonntueh },
     {  0, lkcmifrncg },
};
static const char *lvwxlnfwhn = "this column will terminate the engine after 10 seconds";


unsigned  rwuxzjvdyo;
const While_time_control_ROM_CFL_t kyzqichwmb = { 10000,&rwuxzjvdyo };



static While_control_RAM_CFL_t kevsfmtysf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lrqtysorpg_rom = { 0 ,true, (void*)&kyzqichwmb,&kevsfmtysf_ram,null_function};

    
static const char *vmpjidywst = "time delay done";
static const char *avryudfxgm = "stop engine";
static const char *qovibjnsaa = "this column will reset the engine every 2 seconds";


unsigned  mwujzkedqz;
const While_time_control_ROM_CFL_t gjkvwgxoef = { 2000,&mwujzkedqz };



static While_control_RAM_CFL_t juepiepmtd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pgjkqgauew_rom = { 0 ,true, (void*)&gjkvwgxoef,&juepiepmtd_ram,null_function};

    
static const char *vhdbzdzbcw = "two seconds past-- reset column";


//----------RAM data structures for columns ----

unsigned qkuknyrffe[2];
Watch_dog_struct_CFL_t * tjsktjdzos[2];
unsigned char qowjshbdbc[2];
unsigned char jwuwsnnnod[2];
void* wvvovoyhfd[2];
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

static const Column_ROM_CFL_t xefepretsz[] = {
  { 1,true, 0, 5, 0, -1, -1 },
  { 2,true, 1, 4, 5, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char vgpdwfzdew[9];


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

static const Column_element_CFL_t dzqfkbgvjp[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&lvwxlnfwhn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lrqtysorpg_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vmpjidywst},
    {one_shot_handler_CFL,log_message_CFL,(void *)&avryudfxgm},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qovibjnsaa},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pgjkqgauew_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vhdbzdzbcw},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};
Bitmap_CFL jflobtcpql[0];
Registermap_CFL_t yvouzdbliu[0];
Floatmap_CFL_t fcnyjertbw[0];
const Sm_control_ROM_CFL_t kjqsothoeq[0];
Sm_control_RAM_CFL_t qujtzavmmz[0];


static Time_control_CFL_t hthfnhnfyo;




static Engine_control_CFL_t jmhuqenhiz;


/* remaining allocate heap size */

static unsigned eisnzvefzf;


/* current heap pointer */

static char* edewghzgjp;


/* heap block area */

static CS_MEMORY_CONTROL guxsblkjvw;


    
    


const struct Handle_CFL_t tjbtvbueec =
{

  .queue_number = 3,
  .queue_rom = mzdaaoknop,
  .queue_ram = yfbhushzkb,

  .column_elements_flags =vgpdwfzdew,
  .column_elements_ROM = dzqfkbgvjp,

  .watch_dog_struct = tjsktjdzos,
  .watch_dog_count  = qkuknyrffe,
   
   
  .column_flags = qowjshbdbc,
  .column_local_data = wvvovoyhfd,
  .column_state = jwuwsnnnod,
  .number_of_columns = 2,
  .column_rom_data = xefepretsz,

  
  
  
  .time_control = &hthfnhnfyo,
  .engine_control =&jmhuqenhiz,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &eisnzvefzf,
  .current_heap_location = &edewghzgjp,
  .private_heap   = &guxsblkjvw,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  kjqsothoeq,
  .sm_ram     = qujtzavmmz,
  .number_of_bitmaps = 0,
  .bitmaps = jflobtcpql,
  .number_of_registermaps = 0,
  .registermaps = yvouzdbliu,
  .number_of_floatmaps = 0,
  .floatmaps = fcnyjertbw,
} ;

const Handle_CFL_t*  wait_delay_handle(){
    return &tjbtvbueec;
}
   

#ifdef __cplusplus
}
#endif

#endif
