#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define mudnwectzi 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t hqupazyvml[4];
static Event_data_CFL_t iixtfmncla[10];
static Event_data_CFL_t tlbwnkwela[10];
static Event_data_CFL_t deuvehosrv[10];
static Event_data_CFL_t nbmtmaucow[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t bizurakrhj[] = { 
     {  10, iixtfmncla },
     {  10, tlbwnkwela },
     {  10, deuvehosrv },
     {  10, nbmtmaucow },
};
static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";
static const char user_test_event_data[] = "test message";
const Event_data_CFL_t eqofcuobrq = { mudnwectzi, false, ( void *)user_test_event_data };
static const char *paserpjjxn = "this is a test message";


unsigned  eoffgjnjcb;
const While_time_control_ROM_CFL_t ykdsjkyeul = { 2000,&eoffgjnjcb };



static While_control_RAM_CFL_t piagghyvyc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lqkzdbjjgf_rom = { 0 ,true, &ykdsjkyeul,&piagghyvyc_ram,null_function};

    
static const char *cifxthksou = "reseting the column every 2 seconds";
static const char *uzlnpivdrj = "test_halt_column";
static const char *pwpnlwaxqx = "halting the column";
static const char *blbptsacue = "test_terminate_column";


unsigned  tqschxldgx;
const While_time_control_ROM_CFL_t holyrgdgno = { 7500,&tqschxldgx };



static While_control_RAM_CFL_t uuqoyrsely_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fzdasqejbj_rom = { 0 ,true, &holyrgdgno,&uuqoyrsely_ram,null_function};

    
static const char *xbqhndtrhv = "column 3 is terminating after 7.5 seconds";
static const char *bqwlslysnc = "test_terminate_engine";


unsigned  qjkocfrxsy;
const While_time_control_ROM_CFL_t zuttpvnwky = { 10000,&qjkocfrxsy };



static While_control_RAM_CFL_t suxhuaritx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ezqybarrwh_rom = { 0 ,true, &zuttpvnwky,&suxhuaritx_ram,null_function};

    
static const char *xdmgyjntcf = "column 4 is terminating engine after 10 seconds";
static const char *mjajoplfnt = "test_terminate_engine 5 second termination";
 unsigned fbsupapjzj_ram;
const While_event_control_ROM_t fbsupapjzj_rom = { 9,mudnwectzi,0,true,NULL,&fbsupapjzj_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t avdzsihgpu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ixcalzrfgo_rom = { 0 ,true, &fbsupapjzj_rom,&avdzsihgpu_ram,null_function};

    
static const char *kdxstwwfxp = "column 5 is terminating engine after 9 events";


//----------RAM data structures for columns ----

unsigned tsginccguv[5];
unsigned gxdunhifdd[5];
One_shot_function_CFL_t  klgnplleuj[5];
unsigned char wreoddhxzs[5];
void *  vnjzwsvewv[5];
unsigned char vtvsfzhyad[5];
unsigned char rxzpfhdywa[5];
void* sdlcxxgbhh[5];
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

static const Column_ROM_CFL_t wqvgvydfqy[] = {
  { 1,true, 0, 8, 0, -1, -1 },
  { 2,true, 1, 3, 8, -1, -1 },
  { 3,true, 2, 4, 11, -1, -1 },
  { -1,true, 3, 4, 15, -1, -1 },
  { -1,true, 4, 4, 19, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char lgkuibgzca[23];


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

static const Column_element_CFL_t vgyvwldyhz[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&paserpjjxn},
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message},
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message},
    {one_shot_handler_CFL,send_event_CFL,(void *)&eqofcuobrq},
    {one_shot_handler_CFL,send_event_CFL,(void *)&eqofcuobrq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lqkzdbjjgf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cifxthksou},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uzlnpivdrj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pwpnlwaxqx},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&blbptsacue},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fzdasqejbj_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xbqhndtrhv},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bqwlslysnc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ezqybarrwh_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xdmgyjntcf},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mjajoplfnt},
    {while_handler_CFL,wait_event_handler,(void *)&ixcalzrfgo_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kdxstwwfxp},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t oddguhklpf;




static Engine_control_CFL_t gieybutsmm;


/* remaining allocate heap size */

static unsigned uatpdgvhcg;


/* current heap pointer */

static char* gaowobetnx;


/* heap block area */

static CS_MEMORY_CONTROL vgwljkltsq;


    
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

  unsigned *watch_dog_trigger_count;
  unsigned *watch_dog_count;
 
  One_shot_function_CFL_t *watch_dog_trigger_function;
  unsigned char *watch_dog_termination_flag;
  void **watch_dog_user_data;
  
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

} Handle_CFL_t;
    local header_code = [[
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t moxoxzzqtc =
{

  .queue_number = 4,
  .queue_rom = bizurakrhj,
  .queue_ram = hqupazyvml,

  .column_elements_flags =lgkuibgzca,
  .column_elements_ROM = vgyvwldyhz,

  .watch_dog_trigger_count = tsginccguv,
  .watch_dog_count       =  gxdunhifdd,  
  .watch_dog_trigger_function = klgnplleuj,
  .watch_dog_termination_flag = wreoddhxzs,
  .watch_dog_user_data = vnjzwsvewv,
   
   
  .column_flags = vtvsfzhyad,
  .column_local_data = sdlcxxgbhh,
  .column_state = rxzpfhdywa,
  .number_of_columns = 5,
  .column_rom_data = wqvgvydfqy,

  
  
  
  .time_control = &oddguhklpf,
  .engine_control =&gieybutsmm,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &uatpdgvhcg,
  .current_heap_location = &gaowobetnx,
  .private_heap   = &vgwljkltsq,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &moxoxzzqtc;
}
   

#ifdef __cplusplus
}
#endif

#endif
