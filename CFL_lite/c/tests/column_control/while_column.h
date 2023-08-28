#ifndef __while_column_H__
#define __while_column_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t cweotvkbkw[1];
static Event_data_CFL_t cnuwpfphkx[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t olozrrppqw[] = { 
     {  10, cnuwpfphkx },
};
static const char* while_message = "This is a test message for while \n";
static const char *dbtnbsswwa = "starting while command";
static const unsigned short kapyurgmlf[] = { 1,2,3};
bool nkbatrsxjr = true;
unsigned kemibgvgzi = 0;
const While_column_control_CFL_t nbtrqasrqv = { (bool *)&nkbatrsxjr, (unsigned *)&kemibgvgzi, (void *)&while_message, 3,kapyurgmlf };
static const char *hsmqqjkefj = "done with while statement";
static const char *zznjxhbbqd = "while_0 should be active";


unsigned  ahsvwgmwrd;
const While_time_control_ROM_CFL_t wjudakgbmr = { 1000,&ahsvwgmwrd };



static While_control_RAM_CFL_t kagmcevyck_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kyleiwoukm_rom = { 0 ,true, &wjudakgbmr,&kagmcevyck_ram,null_function};

    
static const char *tcklcssqso = "while_0 is terminating";
static const char *ospbwmkcts = "while_1 should be active";


unsigned  pwubvsjtsj;
const While_time_control_ROM_CFL_t milkpxnazq = { 2000,&pwubvsjtsj };



static While_control_RAM_CFL_t kmajelrfiq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pfauwghnsk_rom = { 0 ,true, &milkpxnazq,&kmajelrfiq_ram,null_function};

    
static const char *hsqwbmmtin = "while_1 is terminating";
static const char *fylxuaftkw = "while_2 should be active";


unsigned  qhpwiqzgxm;
const While_time_control_ROM_CFL_t mccnnhbrvr = { 3000,&qhpwiqzgxm };



static While_control_RAM_CFL_t cdendxfzfk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t viqdwwqaam_rom = { 0 ,true, &mccnnhbrvr,&cdendxfzfk_ram,null_function};

    
static const char *ixurtxyyot = "while_2 is terminating";


//----------RAM data structures for columns ----

unsigned riyadkansu[4];
Watch_dog_struct_CFL_t * fvfdhtvazy[4];
unsigned char ftrjcziqap[4];
unsigned char icurwpuitc[4];
void* ezfbraulxm[4];
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

static const Column_ROM_CFL_t lsrkjosgck[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,false, 1, 4, 4, -1, -1 },
  { -1,false, 2, 4, 8, -1, -1 },
  { -1,false, 3, 4, 12, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char cnaymokbcz[16];


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

static const Column_element_CFL_t atvvloreaf[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&dbtnbsswwa},
    {while_column_handler_CFL,while_column_test,(void *)&nbtrqasrqv},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hsmqqjkefj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zznjxhbbqd},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kyleiwoukm_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tcklcssqso},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ospbwmkcts},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pfauwghnsk_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hsqwbmmtin},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fylxuaftkw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&viqdwwqaam_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ixurtxyyot},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t pxkfizczij;




static Engine_control_CFL_t svotjukvcs;


/* remaining allocate heap size */

static unsigned zvvcjtbuad;


/* current heap pointer */

static char* yaahemxybw;


/* heap block area */

static CS_MEMORY_CONTROL ivgbsytmlp;


    
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


const struct Handle_CFL_t elpazzxeel =
{

  .queue_number = 1,
  .queue_rom = olozrrppqw,
  .queue_ram = cweotvkbkw,

  .column_elements_flags =cnaymokbcz,
  .column_elements_ROM = atvvloreaf,

  .watch_dog_struct = fvfdhtvazy,
  .watch_dog_count  = riyadkansu,
   
   
  .column_flags = ftrjcziqap,
  .column_local_data = ezfbraulxm,
  .column_state = icurwpuitc,
  .number_of_columns = 4,
  .column_rom_data = lsrkjosgck,

  
  
  
  .time_control = &pxkfizczij,
  .engine_control =&svotjukvcs,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &zvvcjtbuad,
  .current_heap_location = &yaahemxybw,
  .private_heap   = &ivgbsytmlp,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  while_column_handle(){
    return &elpazzxeel;
}
   

#ifdef __cplusplus
}
#endif

#endif
