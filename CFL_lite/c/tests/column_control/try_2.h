#ifndef __try_2_H__
#define __try_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t vufhboofcl[1];
static Event_data_CFL_t pqeccrjtpp[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t jpvyufuoeq[] = { 
     {  10, pqeccrjtpp },
};
static const char *jyqgqfafvb = "test when all try columns  fail";
static const char *ynijefbkaj = "try column is active";
Try_function_RAM_t ucvfjqtxsm = {true, 0, 0 };
static const unsigned short rdfcoaxbrq[] = { 1,2,3};
const Try_column_CFL_t dtszpnfhxh = { false, 3, rdfcoaxbrq,&ucvfjqtxsm,(void *)user_data };
static const char *aaqxepsddh = "try column is done";
static const char *tnpfngoirf = "try_0 should be active";


unsigned  uoqlifqngo;
const While_time_control_ROM_CFL_t yxmyzgodlm = { 2000,&uoqlifqngo };



static While_control_RAM_CFL_t sezxjgnwtq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ifeozjqhlp_rom = { 0 ,true, &yxmyzgodlm,&sezxjgnwtq_ram,null_function};

    
static const char *dcchcafukq = "try_0 is terminating with failure";
const Set_return_code_CFL_t oswkgmrgar = { false };
static const char *gckfkevnfk = "try_1 should be active";


unsigned  drpgslullf;
const While_time_control_ROM_CFL_t hklynswlnu = { 2000,&drpgslullf };



static While_control_RAM_CFL_t urucxokiry_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ujkruhywgh_rom = { 0 ,true, &hklynswlnu,&urucxokiry_ram,null_function};

    
static const char *lwrrbukwnc = "try_1 is terminating with success";
const Set_return_code_CFL_t tfuzytbfwr = { false };
static const char *iglntpmwbx = "try_2 should not be active";


unsigned  fepnmukkoo;
const While_time_control_ROM_CFL_t ukchktlvxb = { 2000,&fepnmukkoo };



static While_control_RAM_CFL_t ourkynlvyf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uylrpolvgt_rom = { 0 ,true, &ukchktlvxb,&ourkynlvyf_ram,null_function};

    
static const char *uquhqpsdoi = "try_2 is terminating";
const Set_return_code_CFL_t viaqpnaamw = { false };


//----------RAM data structures for columns ----

unsigned tjgmhuqzft[4];
Watch_dog_struct_CFL_t * vlrptqpyns[4];
unsigned char xzqcnjcjkk[4];
unsigned char awboqwuunk[4];
void* epowxxfigh[4];
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

static const Column_ROM_CFL_t ojiownmzax[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { -1,false, 1, 5, 5, -1, -1 },
  { -1,false, 2, 5, 10, -1, -1 },
  { -1,false, 3, 5, 15, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char gyvhigeikx[20];


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

static const Column_element_CFL_t kdndyxccnt[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&jyqgqfafvb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ynijefbkaj},
    {try_column_handler_CFL,test_try_function,(void *)&dtszpnfhxh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aaqxepsddh},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tnpfngoirf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ifeozjqhlp_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dcchcafukq},
    {set_return_code_CFL,NULL,(void *)&oswkgmrgar},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gckfkevnfk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ujkruhywgh_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lwrrbukwnc},
    {set_return_code_CFL,NULL,(void *)&tfuzytbfwr},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iglntpmwbx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uylrpolvgt_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uquhqpsdoi},
    {set_return_code_CFL,NULL,(void *)&viaqpnaamw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t aysszcciuc;




static Engine_control_CFL_t lovwgbhnuc;


/* remaining allocate heap size */

static unsigned cxnssrqdyg;


/* current heap pointer */

static char* wqmeewgqdy;


/* heap block area */

static CS_MEMORY_CONTROL qebopjxyhb;


    
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
    
    } Handle_CFL_t;

    
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


const struct Handle_CFL_t ydwynvzliu =
{

  .queue_number = 1,
  .queue_rom = jpvyufuoeq,
  .queue_ram = vufhboofcl,

  .column_elements_flags =gyvhigeikx,
  .column_elements_ROM = kdndyxccnt,

  .watch_dog_struct = vlrptqpyns,
  .watch_dog_count  = tjgmhuqzft,
   
   
  .column_flags = xzqcnjcjkk,
  .column_local_data = epowxxfigh,
  .column_state = awboqwuunk,
  .number_of_columns = 4,
  .column_rom_data = ojiownmzax,

  
  
  
  .time_control = &aysszcciuc,
  .engine_control =&lovwgbhnuc,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &cxnssrqdyg,
  .current_heap_location = &wqmeewgqdy,
  .private_heap   = &qebopjxyhb,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  try_2_handle(){
    return &ydwynvzliu;
}
   

#ifdef __cplusplus
}
#endif

#endif
