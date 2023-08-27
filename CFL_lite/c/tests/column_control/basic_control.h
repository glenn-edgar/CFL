#ifndef __basic_control_H__
#define __basic_control_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t gkntllemeb[1];
static Event_data_CFL_t phwwtetepp[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t eznumeubqo[] = { 
     {  10, phwwtetepp },
};
static const char *uwfnvotdds = "will enable column and terminate";
static const unsigned short tunjetymcc[] = { 1};
const Enable_column_CFL_t qvtaijrshq = { false, 1, tunjetymcc };
static const char *lczigefoup = "timer is done";
static const char *uuqnypwmuq = "will enable columns and wait 15 seconds and terminate";
static const unsigned short tjvyakuxny[] = { 3,2};
const Enable_column_CFL_t jaiatmjojw = { true, 2, tjvyakuxny };


unsigned  imbcmgugrm;
const While_time_control_ROM_CFL_t myumltakqt = { 5000,&imbcmgugrm };



static While_control_RAM_CFL_t qzgrebjisy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t eomnlejsmp_rom = { 0 ,true, &myumltakqt,&qzgrebjisy_ram,null_function};

    
static const unsigned short dlnvckewxx[] = { 3};
const Enable_column_CFL_t mivyhjaytz = { true, 1, dlnvckewxx };


unsigned  sfgfjiuqtq;
const While_time_control_ROM_CFL_t ndxcdzxnuo = { 11000,&sfgfjiuqtq };



static While_control_RAM_CFL_t yzelfmccxm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tdwrfbahpt_rom = { 0 ,true, &ndxcdzxnuo,&yzelfmccxm_ram,null_function};

    
static const char *sefxezgylh = "timer is done";
static const char *invgxoaecw = "will wait 5 seconds and reset";


unsigned  aetoyhyfen;
const While_time_control_ROM_CFL_t awchjplabm = { 5000,&aetoyhyfen };



static While_control_RAM_CFL_t ngsynqvzcy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hizzkyxnae_rom = { 0 ,true, &awchjplabm,&ngsynqvzcy_ram,null_function};

    
static const char *txfnddxudq = "when reset happend this message will be seen";


unsigned  evxyycqyfq;
const While_time_control_ROM_CFL_t fhwulfbmey = { 17000,&evxyycqyfq };



static While_control_RAM_CFL_t yuvutowcpi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ahriahftex_rom = { 0 ,true, &fhwulfbmey,&yuvutowcpi_ram,null_function};

    
static const char *swxlwdvtng = "this message should not be seen";
static const unsigned short sswnkfwxss[] = { 5};
const Enable_column_CFL_t xvbxcgfexy = { false, 1, sswnkfwxss };
static const char *algvmvsuvt = "will disable reset column after 12 seconds";


unsigned  xwhulsdbtg;
const While_time_control_ROM_CFL_t ftqwmmaaoc = { 12000,&xwhulsdbtg };



static While_control_RAM_CFL_t rdakawtgwd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tyhunhtkkb_rom = { 0 ,true, &ftqwmmaaoc,&rdakawtgwd_ram,null_function};

    
static const unsigned short omjwifgcgu[] = { 5};
const Disable_column_CFL_t cimamcyubi = { 1, omjwifgcgu };
static const char *ushhmbsjav = "Now will wait till enable_terminate column terminates this column";


unsigned  spkwelklhh;
const While_time_control_ROM_CFL_t omgdhupyjl = { 1000,&spkwelklhh };



static While_control_RAM_CFL_t wvuynlweqm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rzpijhfjod_rom = { 0 ,true, &omgdhupyjl,&wvuynlweqm_ram,null_function};

    
static const char *aiztxbusym = "will wait 5 seconds and reset";


unsigned  xkffttyhdq;
const While_time_control_ROM_CFL_t cwfuehfalt = { 5000,&xkffttyhdq };



static While_control_RAM_CFL_t lrcqchegjy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t quijlmcwnc_rom = { 0 ,true, &cwfuehfalt,&lrcqchegjy_ram,null_function};

    
static const unsigned short sioxlftoxx[] = { 7};
const Enable_column_CFL_t oqprhngezc = { false, 1, sioxlftoxx };
static const char *mktuwnoboq = "waiting for join";
static const unsigned short rjrfdrdipj[] = { 7};
const Join_column_CFL_t aydeanvxsx = { true, 1, rjrfdrdipj };
static const char *upzefqfiop = "Column has been joined";
static const char *mmjkflnhjs = "will wait 5 seconds and terminate";


unsigned  yrpflwrixn;
const While_time_control_ROM_CFL_t lsjuuzawds = { 5000,&yrpflwrixn };



static While_control_RAM_CFL_t ebnxfrjceq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t isdohekvxr_rom = { 0 ,true, &lsjuuzawds,&ebnxfrjceq_ram,null_function};

    
static const char *skememwsme = "timer is done";


//----------RAM data structures for columns ----

unsigned zwhpohdswd[8];
Watch_dog_struct_CFL_t * grgisbbnep[8];
unsigned char ilhdrpuqao[8];
unsigned char shwkmaivxe[8];
void* ezbutqoemb[8];
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

static const Column_ROM_CFL_t gqjdsvlkqz[] = {
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



static unsigned char funcbmmexi[37];


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

static const Column_element_CFL_t ojjtnxqple[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&uwfnvotdds},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&qvtaijrshq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lczigefoup},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uuqnypwmuq},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&jaiatmjojw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&eomnlejsmp_rom},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&mivyhjaytz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tdwrfbahpt_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sefxezgylh},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&invgxoaecw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hizzkyxnae_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&txfnddxudq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ahriahftex_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&swxlwdvtng},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&xvbxcgfexy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&algvmvsuvt},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tyhunhtkkb_rom},
    {one_shot_handler_CFL,disable_columns_function_CFL,(void *)&cimamcyubi},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ushhmbsjav},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rzpijhfjod_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aiztxbusym},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&quijlmcwnc_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&oqprhngezc},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mktuwnoboq},
    {join_columns_function_CFL,null_function,(void *)&aydeanvxsx},
    {one_shot_handler_CFL,log_message_CFL,(void *)&upzefqfiop},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mmjkflnhjs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&isdohekvxr_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&skememwsme},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t fpmxtohzof;




static Engine_control_CFL_t dzeelhvpez;


/* remaining allocate heap size */

static unsigned zagqaddiuw;


/* current heap pointer */

static char* sbuurxyomz;


/* heap block area */

static CS_MEMORY_CONTROL mortoetekm;


    
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


const struct Handle_CFL_t ophezilpfq =
{

  .queue_number = 1,
  .queue_rom = eznumeubqo,
  .queue_ram = gkntllemeb,

  .column_elements_flags =funcbmmexi,
  .column_elements_ROM = ojjtnxqple,

  .watch_dog_struct = grgisbbnep,
  .watch_dog_count  = zwhpohdswd,
   
   
  .column_flags = ilhdrpuqao,
  .column_local_data = ezbutqoemb,
  .column_state = shwkmaivxe,
  .number_of_columns = 8,
  .column_rom_data = gqjdsvlkqz,

  
  
  
  .time_control = &fpmxtohzof,
  .engine_control =&dzeelhvpez,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &zagqaddiuw,
  .current_heap_location = &sbuurxyomz,
  .private_heap   = &mortoetekm,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  basic_control_handle(){
    return &ophezilpfq;
}
   

#ifdef __cplusplus
}
#endif

#endif
