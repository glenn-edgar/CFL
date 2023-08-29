#ifndef __while_column_H__
#define __while_column_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t yhjqexalym[1];
static Event_data_CFL_t gboaxnbkze[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t mmsvfcwamh[] = { 
     {  10, gboaxnbkze },
};
static const char* while_message = "This is a test message for while \n";
static const char *iemsstjfqi = "starting while command";
static const unsigned short hektbgiryk[] = { 1,2,3};
bool vubcltcksw = true;
unsigned pjltpidmue = 0;
const While_column_control_CFL_t jnwlwoiulu = { (bool *)&vubcltcksw, (unsigned *)&pjltpidmue, (void *)&while_message, 3,hektbgiryk };
static const char *piavmliffw = "done with while statement";
static const char *wjkpdfkaml = "while_0 should be active";


unsigned  dvbwlrprkn;
const While_time_control_ROM_CFL_t owqihznozi = { 1000,&dvbwlrprkn };



static While_control_RAM_CFL_t imsnipmyzq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yhdnlxbaad_rom = { 0 ,true, &owqihznozi,&imsnipmyzq_ram,null_function};

    
static const char *hhiuotimwo = "while_0 is terminating";
static const char *ekramlbfai = "while_1 should be active";


unsigned  secemsdrwl;
const While_time_control_ROM_CFL_t cqehqamcwb = { 2000,&secemsdrwl };



static While_control_RAM_CFL_t zthnucrsyp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rlkmcdaxox_rom = { 0 ,true, &cqehqamcwb,&zthnucrsyp_ram,null_function};

    
static const char *yvwmufqzqn = "while_1 is terminating";
static const char *dupikqezny = "while_2 should be active";


unsigned  tlvcvisidt;
const While_time_control_ROM_CFL_t dqwfjvarps = { 3000,&tlvcvisidt };



static While_control_RAM_CFL_t tgrndtrxgt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dibkkfklsf_rom = { 0 ,true, &dqwfjvarps,&tgrndtrxgt_ram,null_function};

    
static const char *wozodcgjjo = "while_2 is terminating";


//----------RAM data structures for columns ----

unsigned itqprugfaf[4];
Watch_dog_struct_CFL_t * qwdzdocury[4];
unsigned char chogkhofvk[4];
unsigned char bnddyhhezt[4];
void* ucryvtzwym[4];
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

static const Column_ROM_CFL_t tqvcfdbspj[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,false, 1, 4, 4, -1, -1 },
  { -1,false, 2, 4, 8, -1, -1 },
  { -1,false, 3, 4, 12, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char vbhdmmqzhg[16];


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

static const Column_element_CFL_t wylskbadmh[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&iemsstjfqi},
    {while_column_handler_CFL,while_column_test,(void *)&jnwlwoiulu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&piavmliffw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wjkpdfkaml},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yhdnlxbaad_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hhiuotimwo},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ekramlbfai},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rlkmcdaxox_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yvwmufqzqn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dupikqezny},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dibkkfklsf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wozodcgjjo},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t iyecyvieud;




static Engine_control_CFL_t pwwpbkrmem;


/* remaining allocate heap size */

static unsigned norazhbcqd;


/* current heap pointer */

static char* dolbgnvdta;


/* heap block area */

static CS_MEMORY_CONTROL ihxypoxiyx;


    
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


const struct Handle_CFL_t hlwxdentxx =
{

  .queue_number = 1,
  .queue_rom = mmsvfcwamh,
  .queue_ram = yhjqexalym,

  .column_elements_flags =vbhdmmqzhg,
  .column_elements_ROM = wylskbadmh,

  .watch_dog_struct = qwdzdocury,
  .watch_dog_count  = itqprugfaf,
   
   
  .column_flags = chogkhofvk,
  .column_local_data = ucryvtzwym,
  .column_state = bnddyhhezt,
  .number_of_columns = 4,
  .column_rom_data = tqvcfdbspj,

  
  
  
  .time_control = &iyecyvieud,
  .engine_control =&pwwpbkrmem,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &norazhbcqd,
  .current_heap_location = &dolbgnvdta,
  .private_heap   = &ihxypoxiyx,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  while_column_handle(){
    return &hlwxdentxx;
}
   

#ifdef __cplusplus
}
#endif

#endif
