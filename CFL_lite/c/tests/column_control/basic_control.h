#ifndef __basic_control_H__
#define __basic_control_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t bboehxfeus[1];
static Event_data_CFL_t xoouimsdnt[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ohuawgaaaj[] = { 
     {  10, xoouimsdnt },
};
static const char *hgsjbnocda = "will enable column and terminate";
static const unsigned short cigpdpowej[] = { 1};
const Enable_column_CFL_t gsnnpfssyk = { false, 1, cigpdpowej };
static const char *zgzchbpdrk = "timer is done";
static const char *efzqazdqeu = "will enable columns and wait 15 seconds and terminate";
static const unsigned short ybgkruzbvc[] = { 3,2};
const Enable_column_CFL_t yxooybnqqo = { true, 2, ybgkruzbvc };


unsigned  yevfupsvyx;
const While_time_control_ROM_CFL_t hdhzhyxiya = { 5000,&yevfupsvyx };



static While_control_RAM_CFL_t ceelfzubru_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vibeiuemht_rom = { 0 ,true, &hdhzhyxiya,&ceelfzubru_ram,null_function};

    
static const unsigned short wpilkuxylo[] = { 3};
const Enable_column_CFL_t jirabnmfmk = { true, 1, wpilkuxylo };


unsigned  thqlprbyqn;
const While_time_control_ROM_CFL_t uytxbxrycj = { 11000,&thqlprbyqn };



static While_control_RAM_CFL_t rwpnjxnvmy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t oxadekmjyv_rom = { 0 ,true, &uytxbxrycj,&rwpnjxnvmy_ram,null_function};

    
static const char *jkhiwajfns = "timer is done";
static const char *miitcodmpz = "will wait 5 seconds and reset";


unsigned  ybglfrrqqp;
const While_time_control_ROM_CFL_t jqtucwdwri = { 5000,&ybglfrrqqp };



static While_control_RAM_CFL_t zagacydmmc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sgbrtniuvm_rom = { 0 ,true, &jqtucwdwri,&zagacydmmc_ram,null_function};

    
static const char *ewucstfkdh = "when reset happend this message will be seen";


unsigned  vngrdlcoms;
const While_time_control_ROM_CFL_t jkkfflcjmh = { 17000,&vngrdlcoms };



static While_control_RAM_CFL_t sqfpwuuqwe_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dnitgzlkzb_rom = { 0 ,true, &jkkfflcjmh,&sqfpwuuqwe_ram,null_function};

    
static const char *tglolhkhrn = "this message should not be seen";
static const unsigned short hiwlxapori[] = { 5};
const Enable_column_CFL_t yrmbujyluq = { false, 1, hiwlxapori };
static const char *mwsfkfekom = "will disable reset column after 12 seconds";


unsigned  mnkdtikdlf;
const While_time_control_ROM_CFL_t hjwqjcxgnp = { 12000,&mnkdtikdlf };



static While_control_RAM_CFL_t jopoyohlqt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jnkhdjyrjd_rom = { 0 ,true, &hjwqjcxgnp,&jopoyohlqt_ram,null_function};

    
static const unsigned short tlsglkbish[] = { 5};
const Disable_column_CFL_t sdfokmcysf = { 1, tlsglkbish };
static const char *qbljhzlrpz = "Now will wait till enable_terminate column terminates this column";


unsigned  gbjmgofcui;
const While_time_control_ROM_CFL_t lszjaliejz = { 1000,&gbjmgofcui };



static While_control_RAM_CFL_t uaszdqstao_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vtikojnbef_rom = { 0 ,true, &lszjaliejz,&uaszdqstao_ram,null_function};

    
static const char *fddeepfcqu = "will wait 5 seconds and reset";


unsigned  qhbrrrvrty;
const While_time_control_ROM_CFL_t wtistueztw = { 5000,&qhbrrrvrty };



static While_control_RAM_CFL_t uokggeaxjt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wwufizjsqq_rom = { 0 ,true, &wtistueztw,&uokggeaxjt_ram,null_function};

    
static const unsigned short ativbayfho[] = { 7};
const Enable_column_CFL_t wpkekrutgp = { false, 1, ativbayfho };
static const char *hiztoxqunc = "waiting for join";
static const unsigned short jkaxgjyxge[] = { 7};
const Join_column_CFL_t jqayjhwsew = { true, 1, jkaxgjyxge };
static const char *jnvwekivnp = "Column has been joined";
static const char *ljwbitzqwz = "will wait 5 seconds and terminate";


unsigned  rzmbdxfozp;
const While_time_control_ROM_CFL_t awhinrbynf = { 5000,&rzmbdxfozp };



static While_control_RAM_CFL_t bjdshjrgwx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zhzepcujhi_rom = { 0 ,true, &awhinrbynf,&bjdshjrgwx_ram,null_function};

    
static const char *rzesmsxxte = "timer is done";


//----------RAM data structures for columns ----

unsigned hngbipboin[8];
Watch_dog_struct_CFL_t * kqdiurykrz[8];
unsigned char vmdljlpnui[8];
unsigned char xxzaqztjcp[8];
void* ixkzcskvgd[8];
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

static const Column_ROM_CFL_t bpdxortplp[] = {
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



static unsigned char qmmmzokvnw[37];


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

static const Column_element_CFL_t iwqdhmhdvd[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&hgsjbnocda},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&gsnnpfssyk},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zgzchbpdrk},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&efzqazdqeu},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&yxooybnqqo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vibeiuemht_rom},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&jirabnmfmk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&oxadekmjyv_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jkhiwajfns},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&miitcodmpz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sgbrtniuvm_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ewucstfkdh},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dnitgzlkzb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tglolhkhrn},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&yrmbujyluq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mwsfkfekom},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jnkhdjyrjd_rom},
    {one_shot_handler_CFL,disable_columns_function_CFL,(void *)&sdfokmcysf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qbljhzlrpz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vtikojnbef_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fddeepfcqu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wwufizjsqq_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&wpkekrutgp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hiztoxqunc},
    {join_columns_function_CFL,null_function,(void *)&jqayjhwsew},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jnvwekivnp},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ljwbitzqwz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zhzepcujhi_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rzesmsxxte},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t molgelibsq;




static Engine_control_CFL_t lltayfektv;


/* remaining allocate heap size */

static unsigned jgqwucfzle;


/* current heap pointer */

static char* ybqkdrcwvg;


/* heap block area */

static CS_MEMORY_CONTROL hsnyclycmm;


    
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


const struct Handle_CFL_t ajvakkkydk =
{

  .queue_number = 1,
  .queue_rom = ohuawgaaaj,
  .queue_ram = bboehxfeus,

  .column_elements_flags =qmmmzokvnw,
  .column_elements_ROM = iwqdhmhdvd,

  .watch_dog_struct = kqdiurykrz,
  .watch_dog_count  = hngbipboin,
   
   
  .column_flags = vmdljlpnui,
  .column_local_data = ixkzcskvgd,
  .column_state = xxzaqztjcp,
  .number_of_columns = 8,
  .column_rom_data = bpdxortplp,

  
  
  
  .time_control = &molgelibsq,
  .engine_control =&lltayfektv,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &jgqwucfzle,
  .current_heap_location = &ybqkdrcwvg,
  .private_heap   = &hsnyclycmm,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  basic_control_handle(){
    return &ajvakkkydk;
}
   

#ifdef __cplusplus
}
#endif

#endif
