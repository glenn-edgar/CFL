#ifndef __fibonacci_H__
#define __fibonacci_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t vfobwgffed[3];
static Event_data_CFL_t cbvgdywboo[7];
static Event_data_CFL_t yainkyvpkm[0];
static Event_data_CFL_t frmccvziic[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t xjxipdbukm[] = { 
     {  7, cbvgdywboo },
     {  0, yainkyvpkm },
     {  0, frmccvziic },
};
/*
// defined in the runtime
typedef struct fibonacci_data_t
{
  unsigned number;
  unsigned index;
  unsigned fibonacci;
  unsigned first;
  unsigned second;
}fibonacci_data_t;
*/
static fibonacci_data_t fibonacci_data;

static unsigned short yqjgxdrnop[] = { 0,1};
static const Column_data_CFL_t juizrbctdj = { 2, yqjgxdrnop, (void *)&fibonacci_data };
static const unsigned short zhpubxfqug[] = { 1};
const Enable_column_CFL_t evogaftmqq = { false, 1, zhpubxfqug };
static const Log_message_CFL_t tdxobiphtu = { "Starting Fibonacci computation", false, NULL };
static const unsigned short czdmfuwezn[] = { 1};
const Join_column_CFL_t djgtzrhwab = { true, 1, czdmfuwezn };
static const Log_message_CFL_t uozmpmdkfg = { "calculating fibonaci", false, NULL };


//----------RAM data structures for columns ----

unsigned yclzymtcjx[2];
Watch_dog_struct_CFL_t * mydpdrwseq[2];
unsigned char ljrxvjofog[2];
unsigned char dzjlhjawmg[2];
void* pmxtwxxcwj[2];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t eaoyhqsduk[] = {
  { 1,true, 0, 7, 0, -1, -1,NULL },
  { 2,false, 1, 2, 7, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char neqehfsiqg[9];


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

static const Column_element_CFL_t esewhicote[] = {
    {one_shot_handler_CFL,store_column_data,(void *)&juizrbctdj}, // 0 
    {one_shot_handler_CFL,initialize_fibonaci,NULL}, // 1 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&evogaftmqq}, // 2 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&tdxobiphtu}, // 3 
    {join_columns_function_CFL,null_function,(void *)&djgtzrhwab}, // 4 
    {one_shot_handler_CFL,display_fibonaci,NULL}, // 5 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 6 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&uozmpmdkfg}, // 7 
    {terminate_reset_CFL,calculate_fibonaci,NULL}, // 8 
};
Bitmap_CFL bcqmfqsyig[0];
Registermap_CFL_t qtdlouodxc[0];
Floatmap_CFL_t uhfdltexjd[0];
const Sm_control_ROM_CFL_t pcpigcaqbc[0];
Sm_control_RAM_CFL_t lspreaikaj[0];


static Time_control_CFL_t eicgxdesjd;




static Engine_control_CFL_t wmmkdzyjhi;


/* remaining allocate heap size */

static unsigned lkofshilwz;


/* current heap pointer */

static char* ibxpxhpndj;


/* heap block area */

static CS_MEMORY_CONTROL xkxruogkof;


    
    


const struct Handle_CFL_t ulikwdxygd =
{

  .queue_number = 3,
  .queue_rom = xjxipdbukm,
  .queue_ram = vfobwgffed,

  .column_elements_flags =neqehfsiqg,
  .column_elements_ROM = esewhicote,

  .watch_dog_struct = mydpdrwseq,
  .watch_dog_count  = yclzymtcjx,
   
   
  .column_flags = ljrxvjofog,
  .column_local_data = pmxtwxxcwj,
  .column_state = dzjlhjawmg,
  .number_of_columns = 2,
  .column_rom_data = eaoyhqsduk,

  
  
  
  .time_control = &eicgxdesjd,
  .engine_control =&wmmkdzyjhi,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &lkofshilwz,
  .current_heap_location = &ibxpxhpndj,
  .private_heap   = &xkxruogkof,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  pcpigcaqbc,
  .sm_ram     = lspreaikaj,
  .number_of_bitmaps = 0,
  .bitmaps = bcqmfqsyig,
  .number_of_registermaps = 0,
  .registermaps = qtdlouodxc,
  .number_of_floatmaps = 0,
  .floatmaps = uhfdltexjd,
} ;

const Handle_CFL_t*  fibonacci_entry_point(){
    return &ulikwdxygd;
}
   

#ifdef __cplusplus
}
#endif

#endif
