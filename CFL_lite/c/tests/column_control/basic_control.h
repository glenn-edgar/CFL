#ifndef __basic_control_H__
#define __basic_control_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t hfilmsbpuq[1];
static Event_data_CFL_t flpzkkilcw[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t owbnklmjxo[] = { 
     {  10, flpzkkilcw },
};
static const char *ywfejcmagl = "will enable column and terminate";
static const unsigned short enkelmwywp[] = { 1};
const Enable_column_CFL_t swskghuaaw = { false, 1, enkelmwywp };
static const char *cpnttaeqrk = "timer is done";
static const char *bcfwrwwiko = "will enable columns and wait 15 seconds and terminate";
static const unsigned short grdyntzhwu[] = { 3,2};
const Enable_column_CFL_t kegoegpfdi = { true, 2, grdyntzhwu };


unsigned  sczrxkggqk;
const While_time_control_ROM_CFL_t sxlldnwgtw = { 5000,&sczrxkggqk };



static While_control_RAM_CFL_t qrmfcadrmz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t oqqwfsurzn_rom = { 0 ,true, &sxlldnwgtw,&qrmfcadrmz_ram,null_function};

    
static const unsigned short ohcozyzaed[] = { 3};
const Enable_column_CFL_t ijwkpiiayq = { true, 1, ohcozyzaed };


unsigned  rofpvvvzjx;
const While_time_control_ROM_CFL_t eefzudvpyr = { 11000,&rofpvvvzjx };



static While_control_RAM_CFL_t uokvbhbfxz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t karatshhwc_rom = { 0 ,true, &eefzudvpyr,&uokvbhbfxz_ram,null_function};

    
static const char *hqggxnnkij = "timer is done";
static const char *uegojicvjy = "will wait 5 seconds and reset";


unsigned  hzvhfybkln;
const While_time_control_ROM_CFL_t kdzoiixuuj = { 5000,&hzvhfybkln };



static While_control_RAM_CFL_t ojegdugvna_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xxcswmvgto_rom = { 0 ,true, &kdzoiixuuj,&ojegdugvna_ram,null_function};

    
static const char *xgysreyqxs = "when reset happend this message will be seen";


unsigned  hlmojcyyqp;
const While_time_control_ROM_CFL_t ayrgsstqll = { 17000,&hlmojcyyqp };



static While_control_RAM_CFL_t cxuyppbzqh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uqelimmsvh_rom = { 0 ,true, &ayrgsstqll,&cxuyppbzqh_ram,null_function};

    
static const char *vznvmbnlwi = "this message should not be seen";
static const unsigned short tpoqmzskre[] = { 5};
const Enable_column_CFL_t aqcxzhpgvo = { false, 1, tpoqmzskre };
static const char *yjxrlzzzpx = "will disable reset column after 12 seconds";


unsigned  movqkjqhfg;
const While_time_control_ROM_CFL_t zyjjktjfjk = { 12000,&movqkjqhfg };



static While_control_RAM_CFL_t jgspvwizvm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ybwgayucdw_rom = { 0 ,true, &zyjjktjfjk,&jgspvwizvm_ram,null_function};

    
static const unsigned short qupwcvbpej[] = { 5};
const Disable_column_CFL_t pemmrgkhhu = { 1, qupwcvbpej };
static const char *mzjgmnwmtm = "Now will wait till enable_terminate column terminates this column";


unsigned  augtstmbdv;
const While_time_control_ROM_CFL_t rkcwhgqune = { 1000,&augtstmbdv };



static While_control_RAM_CFL_t hovedtpnhz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ztlupuanuu_rom = { 0 ,true, &rkcwhgqune,&hovedtpnhz_ram,null_function};

    
static const char *mbfoinhcdd = "will wait 5 seconds and reset";


unsigned  dgeamhtohn;
const While_time_control_ROM_CFL_t ocmihfdsyv = { 5000,&dgeamhtohn };



static While_control_RAM_CFL_t buewdzlwfm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t oqgkqznraf_rom = { 0 ,true, &ocmihfdsyv,&buewdzlwfm_ram,null_function};

    
static const unsigned short htxwpwrnjy[] = { 7};
const Enable_column_CFL_t cycpajgzqq = { false, 1, htxwpwrnjy };
static const char *iieoenwfim = "waiting for join";
static const unsigned short jkrajscmkl[] = { 7};
const Join_column_CFL_t gprjfjxtxu = { true, 1, jkrajscmkl };
static const char *bulloutlcw = "Column has been joined";
static const char *eypkrlsomb = "will wait 5 seconds and terminate";


unsigned  zlxxpdspau;
const While_time_control_ROM_CFL_t wallhbkkiv = { 5000,&zlxxpdspau };



static While_control_RAM_CFL_t jwbndwrnsw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ecukjeiwlk_rom = { 0 ,true, &wallhbkkiv,&jwbndwrnsw_ram,null_function};

    
static const char *ohvjkczrlh = "timer is done";


//----------RAM data structures for columns ----

unsigned nmtbqrahwl[8];
Watch_dog_struct_CFL_t * sqrcswbjno[8];
unsigned char xmjdkftufh[8];
unsigned char qpyvsxagao[8];
void* erfwejcodu[8];
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

static const Column_ROM_CFL_t hsnnatxpoy[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,false, 1, 7, 4, -1, -1 },
  { -1,false, 2, 3, 11, -1, -1 },
  { -1,false, 3, 4, 14, -1, -1 },
  { -1,true, 4, 7, 18, -1, -1 },
  { -1,false, 5, 3, 25, -1, -1 },
  { -1,true, 6, 5, 28, -1, -1 },
  { -1,false, 7, 4, 33, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char atvmqqqwwt[37];


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

static const Column_element_CFL_t qypyoqxneq[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&ywfejcmagl},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&swskghuaaw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cpnttaeqrk},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bcfwrwwiko},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&kegoegpfdi},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&oqqwfsurzn_rom},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&ijwkpiiayq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&karatshhwc_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hqggxnnkij},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uegojicvjy},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xxcswmvgto_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xgysreyqxs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uqelimmsvh_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vznvmbnlwi},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&aqcxzhpgvo},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yjxrlzzzpx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ybwgayucdw_rom},
    {one_shot_handler_CFL,disable_columns_function_CFL,(void *)&pemmrgkhhu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzjgmnwmtm},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ztlupuanuu_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mbfoinhcdd},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&oqgkqznraf_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&cycpajgzqq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iieoenwfim},
    {join_columns_function_CFL,null_function,(void *)&gprjfjxtxu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bulloutlcw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&eypkrlsomb},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ecukjeiwlk_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ohvjkczrlh},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t iaucdxeptn;




static Engine_control_CFL_t ckvtunqcbx;


/* remaining allocate heap size */

static unsigned jbjuhbmjnw;


/* current heap pointer */

static char* ykiuqqrpes;


/* heap block area */

static CS_MEMORY_CONTROL flgvjfjlyw;


    
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


const struct Handle_CFL_t glsoohmjtc =
{

  .queue_number = 1,
  .queue_rom = owbnklmjxo,
  .queue_ram = hfilmsbpuq,

  .column_elements_flags =atvmqqqwwt,
  .column_elements_ROM = qypyoqxneq,

  .watch_dog_struct = sqrcswbjno,
  .watch_dog_count  = nmtbqrahwl,
   
   
  .column_flags = xmjdkftufh,
  .column_local_data = erfwejcodu,
  .column_state = qpyvsxagao,
  .number_of_columns = 8,
  .column_rom_data = hsnnatxpoy,

  
  
  
  .time_control = &iaucdxeptn,
  .engine_control =&ckvtunqcbx,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &jbjuhbmjnw,
  .current_heap_location = &ykiuqqrpes,
  .private_heap   = &flgvjfjlyw,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  basic_control_handle(){
    return &glsoohmjtc;
}
   

#ifdef __cplusplus
}
#endif

#endif
