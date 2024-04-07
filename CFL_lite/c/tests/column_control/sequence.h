#ifndef __sequence_H__
#define __sequence_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t ojeaardczb[5];
static Event_data_CFL_t sckyagdnfz[7];
static Event_data_CFL_t fvffiqfsgq[0];
static Event_data_CFL_t tljabcvciy[0];
static Event_data_CFL_t vquzkykvcm[0];
static Event_data_CFL_t wiunkapnhj[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ubhnxsllzj[] = { 
     {  7, sckyagdnfz },
     {  0, fvffiqfsgq },
     {  0, tljabcvciy },
     {  0, vquzkykvcm },
     {  0, wiunkapnhj },
};
static const Log_message_CFL_t rncjvteehv = { "testing sequence columns command", false, NULL };
static const unsigned short tomeyoncjg[] = { 1,2,3};
unsigned short wpdudvzpyn = 0;
bool axoxllpmmk = true;
const sequence_columns_CFL_t bnglhxhmjc = { 3, tomeyoncjg, &wpdudvzpyn, &axoxllpmmk };
static const Log_message_CFL_t twsgsoikdb = { "sequence column test is done", false, NULL };
static const Log_message_CFL_t oxtggcdrmq = { "seq_0 should be active", false, NULL };


unsigned  wwyjxgvxsd;
const While_time_control_ROM_CFL_t fzxxvfdcdo = { 2000,&wwyjxgvxsd };



static While_control_RAM_CFL_t ysorwguppa_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t quohsythve_rom = { 0 ,true, (void*)&fzxxvfdcdo,&ysorwguppa_ram,null_function};

    
static const Log_message_CFL_t hhdmgocojh = { "seq_0 is terminating", false, NULL };
static const Log_message_CFL_t lzvueyreum = { "seq_1 should be active", false, NULL };


unsigned  yzwjiqudml;
const While_time_control_ROM_CFL_t tmypnsquib = { 1000,&yzwjiqudml };



static While_control_RAM_CFL_t yfsinrxvjt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qrdkjrocdr_rom = { 0 ,true, (void*)&tmypnsquib,&yfsinrxvjt_ram,null_function};

    
static const Log_message_CFL_t kjswtlfqqi = { "seq_1 is terminating ", false, NULL };
static const Log_message_CFL_t qigdcadxns = { "seq_2 should not be active", false, NULL };


unsigned  lhwlemxbih;
const While_time_control_ROM_CFL_t tbhjrbysyu = { 500,&lhwlemxbih };



static While_control_RAM_CFL_t llykdbkozk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hibdgtgshb_rom = { 0 ,true, (void*)&tbhjrbysyu,&llykdbkozk_ram,null_function};

    
static const Log_message_CFL_t egzyfslupa = { "seq_2 is terminating", false, NULL };


//----------RAM data structures for columns ----

unsigned sfqcjekrrj[4];
Watch_dog_struct_CFL_t * jeqwiqmtwu[4];
unsigned char dyvtmjudsg[4];
unsigned char hupofzhwgv[4];
void* eezduoozyx[4];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t dhepntcjft[] = {
  { 1,true, 0, 4, 0, -1, -1,NULL },
  { 2,false, 1, 4, 4, -1, -1,NULL },
  { 3,false, 2, 4, 8, -1, -1,NULL },
  { 4,false, 3, 4, 12, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char jubooczngv[16];


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

static const Column_element_CFL_t qaxzxdtuwg[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rncjvteehv}, // 0 
    {sequence_columns_CFL,NULL,(void *)&bnglhxhmjc}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&twsgsoikdb}, // 2 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&oxtggcdrmq}, // 4 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&quohsythve_rom}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hhdmgocojh}, // 6 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 7 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&lzvueyreum}, // 8 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qrdkjrocdr_rom}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&kjswtlfqqi}, // 10 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&qigdcadxns}, // 12 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hibdgtgshb_rom}, // 13 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&egzyfslupa}, // 14 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 15 
};
Bitmap_CFL prnihksibx[0];
Registermap_CFL_t uyqqblescl[0];
Floatmap_CFL_t ytagfhxlqn[0];
const Sm_control_ROM_CFL_t hhikkofxtu[0];
Sm_control_RAM_CFL_t ajslvwqirr[0];


static Time_control_CFL_t rarnmlmicl;




static Engine_control_CFL_t ruharnkewd;


/* remaining allocate heap size */

static unsigned edoqamtwhf;


/* current heap pointer */

static char* qyrdfmnzkg;


/* heap block area */

static CS_MEMORY_CONTROL qalfvqjfsg;


    
    


const struct Handle_CFL_t pzhzdmpgxl =
{

  .queue_number = 5,
  .queue_rom = ubhnxsllzj,
  .queue_ram = ojeaardczb,

  .column_elements_flags =jubooczngv,
  .column_elements_ROM = qaxzxdtuwg,

  .watch_dog_struct = jeqwiqmtwu,
  .watch_dog_count  = sfqcjekrrj,
   
   
  .column_flags = dyvtmjudsg,
  .column_local_data = eezduoozyx,
  .column_state = hupofzhwgv,
  .number_of_columns = 4,
  .column_rom_data = dhepntcjft,

  
  
  
  .time_control = &rarnmlmicl,
  .engine_control =&ruharnkewd,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &edoqamtwhf,
  .current_heap_location = &qyrdfmnzkg,
  .private_heap   = &qalfvqjfsg,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  hhikkofxtu,
  .sm_ram     = ajslvwqirr,
  .number_of_bitmaps = 0,
  .bitmaps = prnihksibx,
  .number_of_registermaps = 0,
  .registermaps = uyqqblescl,
  .number_of_floatmaps = 0,
  .floatmaps = ytagfhxlqn,
} ;

const Handle_CFL_t*  sequence_handle(){
    return &pzhzdmpgxl;
}
   

#ifdef __cplusplus
}
#endif

#endif
