#ifndef __bit_maps_1_H__
#define __bit_maps_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t ncisvludnp[1];
static Event_data_CFL_t gaiugabdnd[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ctmipmrvla[] = { 
     {  10, gaiugabdnd },
};
static const char *bsexuikeae = "start column";
static const unsigned short golvdhwdor[] = { 1};
const Enable_column_CFL_t fnsormbfyh = { true, 1, golvdhwdor };


unsigned  qnauupejty;
const While_time_control_ROM_CFL_t waittwozor = { 6000,&qnauupejty };



static While_control_RAM_CFL_t lxscfnztvs_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t omhoxlfljn_rom = { 0 ,true, &waittwozor,&lxscfnztvs_ram,null_function};

    
static const char *kydgcqsgfx = "terminating system";
static const char *mrluvgrtzr = "configure bit maps";
static const char *mztfgholpm = "terminating bit map configuration";


//----------RAM data structures for columns ----

unsigned xyfbkbkfcw[2];
Watch_dog_struct_CFL_t * iipmjzfdyh[2];
unsigned char lfgnhvatwq[2];
unsigned char gzdpgipatz[2];
void* gzvqnztmuu[2];
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

static const Column_ROM_CFL_t cpamerxmkd[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { -1,false, 1, 3, 5, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char fblrcnhpsw[8];


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

static const Column_element_CFL_t ydlxvlfpxf[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&bsexuikeae},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&fnsormbfyh},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&omhoxlfljn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kydgcqsgfx},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mrluvgrtzr},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mztfgholpm},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
static uint8_t bioplfkaml[19]= {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
static uint8_t ulcpgeryym[8]= {0,0,0,0,0,0,0,0};
static uint8_t wuubghqyfg[10]= {0,0,0,0,0,0,0,0,0,0};
Bitmap_CFL gkayectvvi[3] = {
 {152, &bioplfkaml[0]},
 {63, &ulcpgeryym[0]},
 {75, &wuubghqyfg[0]},
};
const Sm_control_ROM_CFL_t wchdaphjbt[0];
Sm_control_RAM_CFL_t jkzdikfnwm[0];


static Time_control_CFL_t oolhttoscz;




static Engine_control_CFL_t oxnzboiwpf;


/* remaining allocate heap size */

static unsigned ummiikdlev;


/* current heap pointer */

static char* xrxoxuuzxp;


/* heap block area */

static CS_MEMORY_CONTROL axmelnvubx;


    
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


const struct Handle_CFL_t tzszhqfzxo =
{

  .queue_number = 1,
  .queue_rom = ctmipmrvla,
  .queue_ram = ncisvludnp,

  .column_elements_flags =fblrcnhpsw,
  .column_elements_ROM = ydlxvlfpxf,

  .watch_dog_struct = iipmjzfdyh,
  .watch_dog_count  = xyfbkbkfcw,
   
   
  .column_flags = lfgnhvatwq,
  .column_local_data = gzvqnztmuu,
  .column_state = gzdpgipatz,
  .number_of_columns = 2,
  .column_rom_data = cpamerxmkd,

  
  
  
  .time_control = &oolhttoscz,
  .engine_control =&oxnzboiwpf,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &ummiikdlev,
  .current_heap_location = &xrxoxuuzxp,
  .private_heap   = &axmelnvubx,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
   .sm_rom     =  wchdaphjbt,
   .sm_ram     = jkzdikfnwm,
   .number_of_bitmaps = 3,
    .bitmaps = gkayectvvi,
} ;


const Handle_CFL_t*  bit_maps_1_handle(){
    return &tzszhqfzxo;
}
   

#ifdef __cplusplus
}
#endif

#endif
