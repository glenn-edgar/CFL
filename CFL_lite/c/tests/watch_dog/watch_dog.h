#ifndef __watch_dog_H__
#define __watch_dog_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t sowqvfxoij[1];
static Event_data_CFL_t zbcwvipthq[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ofwbhkxanh[] = { 
     {  10, zbcwvipthq },
};
    static const char test_message_1[] = "test_message_1";
    static const char test_message_2[] = "test_message_2";
    static const char test_message_3[] = "test_message_3";
    



unsigned  pfmdhyupjh;
const While_time_control_ROM_CFL_t lucsfqprxz = { 30000,&pfmdhyupjh };



static While_control_RAM_CFL_t jukdinjnbf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yfdslxgqxm_rom = { 0 ,true, &lucsfqprxz,&jukdinjnbf_ram,null_function};

    
static const char *deoribvllg = "watch_dog_reset";
const Watch_dog_struct_CFL_t hemfulkfzo = { 5000, test_wd_handler, false, (void *)test_message_1};


unsigned  rmdyguqpas;
const While_time_control_ROM_CFL_t syhmgoftck = { 10000,&rmdyguqpas };



static While_control_RAM_CFL_t smrrydbcob_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ihflfhvksz_rom = { 0 ,true, &syhmgoftck,&smrrydbcob_ram,null_function};

    
static const char *dafobehxen = "should not see this message";
static const char *odekcfhrpf = "watch_dog_terminate";
const Watch_dog_struct_CFL_t fxmqkriirj = { 5000, test_wd_handler, true, (void *)test_message_2};


unsigned  iovplcptkk;
const While_time_control_ROM_CFL_t reyatmript = { 10000,&iovplcptkk };



static While_control_RAM_CFL_t ycuntlonav_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nscgywhqwq_rom = { 0 ,true, &reyatmript,&ycuntlonav_ram,null_function};

    
static const char *xekckbeben = "should not see this message";
static const char *qurveuuzep = "watch_dog_pass";
const Watch_dog_struct_CFL_t olodkvrqma = { 5000, test_wd_handler, true, (void *)test_message_3};


unsigned  tcalkjsimt;
const While_time_control_ROM_CFL_t agfoptorpt = { 1000,&tcalkjsimt };



static While_control_RAM_CFL_t llsdxqmjxq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zwsitdrikl_rom = { 0 ,true, &agfoptorpt,&llsdxqmjxq_ram,null_function};

    


unsigned  xylfairixy;
const While_time_control_ROM_CFL_t dnybbybmri = { 5000,&xylfairixy };



static While_control_RAM_CFL_t wxhbvlzicc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jwzhhqebjn_rom = { 0 ,true, &dnybbybmri,&wxhbvlzicc_ram,null_function};

    
static const char *yplnvzjaih = "watch_dog_pass passed";


//----------RAM data structures for columns ----

unsigned afniajyadu[4];
Watch_dog_struct_CFL_t * udlnuvlafr[4];
unsigned char sdcncthfnp[4];
unsigned char mxcarfnpqq[4];
void* lnyyplxjal[4];
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

static const Column_ROM_CFL_t vljlhsxghv[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 6, 2, -1, -1 },
  { -1,true, 2, 6, 8, -1, -1 },
  { -1,true, 3, 7, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char cjynxzojxj[21];


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

static const Column_element_CFL_t rzxqgbvolv[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yfdslxgqxm_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&deoribvllg},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&hemfulkfzo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ihflfhvksz_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dafobehxen},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&odekcfhrpf},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&fxmqkriirj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nscgywhqwq_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xekckbeben},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qurveuuzep},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&olodkvrqma},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zwsitdrikl_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jwzhhqebjn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yplnvzjaih},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t vjyolrjonp;




static Engine_control_CFL_t sonfmymkac;


/* remaining allocate heap size */

static unsigned vsdrzkaghk;


/* current heap pointer */

static char* ygdeqazfbo;


/* heap block area */

static CS_MEMORY_CONTROL yledwxvazb;


    
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


const struct Handle_CFL_t cqplloqnrd =
{

  .queue_number = 1,
  .queue_rom = ofwbhkxanh,
  .queue_ram = sowqvfxoij,

  .column_elements_flags =cjynxzojxj,
  .column_elements_ROM = rzxqgbvolv,

  .watch_dog_struct = udlnuvlafr,
  .watch_dog_count  = afniajyadu,
   
   
  .column_flags = sdcncthfnp,
  .column_local_data = lnyyplxjal,
  .column_state = mxcarfnpqq,
  .number_of_columns = 4,
  .column_rom_data = vljlhsxghv,

  
  
  
  .time_control = &vjyolrjonp,
  .engine_control =&sonfmymkac,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &vsdrzkaghk,
  .current_heap_location = &ygdeqazfbo,
  .private_heap   = &yledwxvazb,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  watch_dog_handle(){
    return &cqplloqnrd;
}
   

#ifdef __cplusplus
}
#endif

#endif
