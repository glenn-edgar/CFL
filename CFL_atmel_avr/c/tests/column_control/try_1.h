#ifndef __try_1_H__
#define __try_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t lysmtvhjhi[1];
static Event_data_CFL_t igrmtgerhs[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t zbzvugsyph[] = { 
     {  10, igrmtgerhs },
};
static const char *muonhhoojl = "test where there is success in one of the try columns";
static const char *bqbgrlexhd = "try column is active";
Try_function_RAM_t uckxjodtgk = {true, 0, 0 };
static const unsigned short rlqtvjwrbp[] = { 1,2,3};
const Try_column_CFL_t loecudxgfp = { false, 3, rlqtvjwrbp,&uckxjodtgk,(void *)user_data };
static const char *zxljftioli = "try column is done";
static const char *wuppjrvkuf = "try_0 should be active";


unsigned  tetzaznkds;
const While_time_control_ROM_CFL_t qjutxajmjy = { 2000,&tetzaznkds };



static While_control_RAM_CFL_t oxkvzevslg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zytzjcvkhp_rom = { 0 ,true, &qjutxajmjy,&oxkvzevslg_ram,null_function};

    
static const char *qykkgpiyvb = "try_0 is terminating with failure";
const Set_return_code_CFL_t qwcdolnbwh = { false };
static const char *apjzvapduk = "try_1 should be active";


unsigned  hgcxbvplpm;
const While_time_control_ROM_CFL_t oaauigctvi = { 2000,&hgcxbvplpm };



static While_control_RAM_CFL_t ezrzlmvqki_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xpxdkvsuys_rom = { 0 ,true, &oaauigctvi,&ezrzlmvqki_ram,null_function};

    
static const char *cccdstqutj = "try_1 is terminating with success";
const Set_return_code_CFL_t fneruvdsra = { true };
static const char *ewadngtnjl = "try_2 should not be active";


unsigned  ccmqqcqumq;
const While_time_control_ROM_CFL_t zibzdwfqxt = { 2000,&ccmqqcqumq };



static While_control_RAM_CFL_t cyxynnvsgu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rdkmmqsvpz_rom = { 0 ,true, &zibzdwfqxt,&cyxynnvsgu_ram,null_function};

    
static const char *txueestyon = "try_2 is terminating";
const Set_return_code_CFL_t vdyquscfrn = { false };


//----------RAM data structures for columns ----

unsigned bicdqnbwki[4];
Watch_dog_struct_CFL_t * eknybwcydm[4];
unsigned char qzmugklykx[4];
unsigned char lillrorhmk[4];
void* thbdvvyiwn[4];
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

static const Column_ROM_CFL_t risvxeaptl[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { -1,false, 1, 5, 5, -1, -1 },
  { -1,false, 2, 5, 10, -1, -1 },
  { -1,false, 3, 5, 15, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char qlaknlnlwb[20];


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

static const Column_element_CFL_t chpadxecrr[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&muonhhoojl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bqbgrlexhd},
    {try_column_handler_CFL,test_try_function,(void *)&loecudxgfp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zxljftioli},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wuppjrvkuf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zytzjcvkhp_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qykkgpiyvb},
    {set_return_code_CFL,NULL,(void *)&qwcdolnbwh},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&apjzvapduk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xpxdkvsuys_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cccdstqutj},
    {set_return_code_CFL,NULL,(void *)&fneruvdsra},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ewadngtnjl},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rdkmmqsvpz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&txueestyon},
    {set_return_code_CFL,NULL,(void *)&vdyquscfrn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t xudbkcnknv;




static Engine_control_CFL_t ntxcnsmktu;


/* remaining allocate heap size */

static unsigned dqztryijjc;


/* current heap pointer */

static char* sojvxibbhx;


/* heap block area */

static CS_MEMORY_CONTROL otvacxnfza;


    
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


const struct Handle_CFL_t vlwvjfeftq =
{

  .queue_number = 1,
  .queue_rom = zbzvugsyph,
  .queue_ram = lysmtvhjhi,

  .column_elements_flags =qlaknlnlwb,
  .column_elements_ROM = chpadxecrr,

  .watch_dog_struct = eknybwcydm,
  .watch_dog_count  = bicdqnbwki,
   
   
  .column_flags = qzmugklykx,
  .column_local_data = thbdvvyiwn,
  .column_state = lillrorhmk,
  .number_of_columns = 4,
  .column_rom_data = risvxeaptl,

  
  
  
  .time_control = &xudbkcnknv,
  .engine_control =&ntxcnsmktu,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &dqztryijjc,
  .current_heap_location = &sojvxibbhx,
  .private_heap   = &otvacxnfza,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  try_1_handle(){
    return &vlwvjfeftq;
}
   

#ifdef __cplusplus
}
#endif

#endif
