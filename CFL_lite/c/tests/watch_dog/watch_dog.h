#ifndef __watch_dog_H__
#define __watch_dog_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t ornbuxtmmy[1];
static Event_data_CFL_t jzjpexrpet[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ssynmdpjts[] = { 
     {  10, jzjpexrpet },
};
    static const char test_message_1[] = "test_message_1";
    static const char test_message_2[] = "test_message_2";
    static const char test_message_3[] = "test_message_3";
    



unsigned  zvsrxtqyhj;
const While_time_control_ROM_CFL_t lsslptflzn = { 30000,&zvsrxtqyhj };



static While_control_RAM_CFL_t ztsdqrlesw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t spycnjrmau_rom = { 0 ,true, &lsslptflzn,&ztsdqrlesw_ram,null_function};

    
static const char *akyepkwgrj = "watch_dog_reset";
const Watch_dog_struct_CFL_t mekobsqdjk = { 5000, test_wd_handler, false, (void *)test_message_1};


unsigned  ajxfusppho;
const While_time_control_ROM_CFL_t hfhgpyjlbk = { 10000,&ajxfusppho };



static While_control_RAM_CFL_t qucvfmmbcd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fonojvmiok_rom = { 0 ,true, &hfhgpyjlbk,&qucvfmmbcd_ram,null_function};

    
static const char *qurunhbdhq = "should not see this message";
static const char *retjhavzrf = "watch_dog_terminate";
const Watch_dog_struct_CFL_t ykbdntewhu = { 5000, test_wd_handler, true, (void *)test_message_2};


unsigned  kjkfkoxuqx;
const While_time_control_ROM_CFL_t qgnprmukrf = { 10000,&kjkfkoxuqx };



static While_control_RAM_CFL_t kamcrlmyrw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fyuhsounui_rom = { 0 ,true, &qgnprmukrf,&kamcrlmyrw_ram,null_function};

    
static const char *emaklxorpx = "should not see this message";
static const char *nynzuxznee = "watch_dog_pass";
const Watch_dog_struct_CFL_t epsymjbzlf = { 5000, test_wd_handler, true, (void *)test_message_3};


unsigned  ukiyvrzrwb;
const While_time_control_ROM_CFL_t loeyldfqnm = { 1000,&ukiyvrzrwb };



static While_control_RAM_CFL_t umflquevyi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ezgfbjrala_rom = { 0 ,true, &loeyldfqnm,&umflquevyi_ram,null_function};

    


unsigned  pemxhwmqrz;
const While_time_control_ROM_CFL_t vfpufdscpu = { 5000,&pemxhwmqrz };



static While_control_RAM_CFL_t riqxasptkp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ajqkyjxnyq_rom = { 0 ,true, &vfpufdscpu,&riqxasptkp_ram,null_function};

    
static const char *haqoribzja = "watch_dog_pass passed";


//----------RAM data structures for columns ----

unsigned ejmsvfualy[4];
Watch_dog_struct_CFL_t * bivdqaetko[4];
unsigned char fzmgpnqvry[4];
unsigned char wvcgqemybq[4];
void* lagqdvyddb[4];
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

static const Column_ROM_CFL_t wekrrsjmpa[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 6, 2, -1, -1 },
  { -1,true, 2, 6, 8, -1, -1 },
  { -1,true, 3, 7, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char mwjbcwxafq[21];


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

static const Column_element_CFL_t hdzpahodde[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&spycnjrmau_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&akyepkwgrj},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&mekobsqdjk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fonojvmiok_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qurunhbdhq},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&retjhavzrf},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&ykbdntewhu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fyuhsounui_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&emaklxorpx},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nynzuxznee},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&epsymjbzlf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ezgfbjrala_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ajqkyjxnyq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&haqoribzja},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
Sm_control_ROM_CFL_t ooooceygkj[0];
Sm_control_RAM_CFL_t cklqbxtvay[0];


static Time_control_CFL_t wajdjysiix;




static Engine_control_CFL_t nnwfojkfvu;


/* remaining allocate heap size */

static unsigned eqhwrzlxfz;


/* current heap pointer */

static char* vkegdexdou;


/* heap block area */

static CS_MEMORY_CONTROL jaqtmusfmy;


    
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


const struct Handle_CFL_t ihdpxuiepj =
{

  .queue_number = 1,
  .queue_rom = ssynmdpjts,
  .queue_ram = ornbuxtmmy,

  .column_elements_flags =mwjbcwxafq,
  .column_elements_ROM = hdzpahodde,

  .watch_dog_struct = bivdqaetko,
  .watch_dog_count  = ejmsvfualy,
   
   
  .column_flags = fzmgpnqvry,
  .column_local_data = lagqdvyddb,
  .column_state = wvcgqemybq,
  .number_of_columns = 4,
  .column_rom_data = wekrrsjmpa,

  
  
  
  .time_control = &wajdjysiix,
  .engine_control =&nnwfojkfvu,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &eqhwrzlxfz,
  .current_heap_location = &vkegdexdou,
  .private_heap   = &jaqtmusfmy,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
   .sm_rom     =  ooooceygkj,
   .sm_ram     = cklqbxtvay,
} ;


const Handle_CFL_t*  watch_dog_handle(){
    return &ihdpxuiepj;
}
   

#ifdef __cplusplus
}
#endif

#endif
