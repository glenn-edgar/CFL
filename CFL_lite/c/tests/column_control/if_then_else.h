#ifndef __if_then_else_H__
#define __if_then_else_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t whiceqqrhz[1];
static Event_data_CFL_t wzqfvpimkr[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ydsfhcqfhn[] = { 
     {  10, wzqfvpimkr },
};
static const char *vsjztmrahq = "starting test_if column";
static const unsigned short aclxhrebcs[] = { 1,2,3};
static const unsigned short rbbblwqyiv[] = { 4,5,6};
const If_then_else_CFL_t wcnuvokcuz = { true, true, 3, aclxhrebcs, 3, rbbblwqyiv,NULL };
static const unsigned short vzudapskjq[] = { 1,2,3};
static const unsigned short wadcxtxobr[] = { 4,5,6};
const If_then_else_CFL_t mkjfysegmc = { true, true, 3, vzudapskjq, 3, wadcxtxobr,NULL };
static const unsigned short uzytuoffxc[] = { 1,2,3};
static const unsigned short gsoczmpnee[] = { 4,5,6};
const If_then_else_CFL_t umpcdibrnj = { false, false, 3, uzytuoffxc, 3, gsoczmpnee,NULL };
static const unsigned short xelpbktrxq[] = { 1,2,3};
static const unsigned short frjqlszjoi[] = { 4,5,6};
const If_then_else_CFL_t lzjtikclea = { false, false, 3, xelpbktrxq, 3, frjqlszjoi,NULL };
static const char *oorzeerumu = "done with if_then_else column";


unsigned  mbtnlnrszs;
const While_time_control_ROM_CFL_t huinkexxoo = { 4000,&mbtnlnrszs };



static While_control_RAM_CFL_t cyutiusfpa_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mupjxupwik_rom = { 0 ,true, &huinkexxoo,&cyutiusfpa_ram,null_function};

    
static const char *msweqpvnqx = "time delay is over";
static const unsigned short zhkbsoctfw[] = { 1,2,3};
static const unsigned short mdxdlvzgow[] = { 4,5,6};
const If_then_else_CFL_t jrpszjtihg = { true, false, 3, zhkbsoctfw, 3, mdxdlvzgow,NULL };
static const unsigned short qyrxkovmzu[] = { 1,2,3};
static const unsigned short eaqfqwusfh[] = { 4,5,6};
const If_then_else_CFL_t wdaoudqeqg = { true, false, 3, qyrxkovmzu, 3, eaqfqwusfh,NULL };
static const char *aymwqaixtu = "terminate flag set to true will kill child columns when terminate_column is called";
static const char *bpdzimlvpx = "if_then_0 should be active";


unsigned  juawnuupvk;
const While_time_control_ROM_CFL_t lcsnotfdqm = { 1000,&juawnuupvk };



static While_control_RAM_CFL_t exgdshnsbh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nfzaxonkov_rom = { 0 ,true, &lcsnotfdqm,&exgdshnsbh_ram,null_function};

    
static const char *kikirdzruw = "if_then_0 is terminating";
static const char *pzhvrkrcbl = "if_then_1 should be active";


unsigned  ejwrkdxrvq;
const While_time_control_ROM_CFL_t twpexzelpv = { 2000,&ejwrkdxrvq };



static While_control_RAM_CFL_t altlprivit_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t huqkdublhs_rom = { 0 ,true, &twpexzelpv,&altlprivit_ram,null_function};

    
static const char *vjkljfljhe = "if_then_1 is terminating";
static const char *snvlyijngt = "if_then_2 should be active";


unsigned  opfwpstjmz;
const While_time_control_ROM_CFL_t kdlhevezqx = { 3000,&opfwpstjmz };



static While_control_RAM_CFL_t kqzrrqqapr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bfixsxolqy_rom = { 0 ,true, &kdlhevezqx,&kqzrrqqapr_ram,null_function};

    
static const char *wiyhabhawi = "if_then_2 is terminating";
static const char *qaahfwrmnu = "if_else_0 should be active";


unsigned  cjjvcrpuyn;
const While_time_control_ROM_CFL_t mjabbsiezz = { 1000,&cjjvcrpuyn };



static While_control_RAM_CFL_t bibkkfjtqy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kgqdlactoy_rom = { 0 ,true, &mjabbsiezz,&bibkkfjtqy_ram,null_function};

    
static const char *jyrzgtuuny = "if_else_0 is terminating";
static const char *xjialxuunf = "if_else_1 should be active";


unsigned  nyonospgwy;
const While_time_control_ROM_CFL_t xhibkupqsp = { 2000,&nyonospgwy };



static While_control_RAM_CFL_t ygknkhtgac_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t enylafmmxd_rom = { 0 ,true, &xhibkupqsp,&ygknkhtgac_ram,null_function};

    
static const char *qksnelbrrn = "if_else_1 is terminating";
static const char *ascdazwqar = "if_else_2 should be active";


unsigned  xssorygbph;
const While_time_control_ROM_CFL_t ggpbflgmoo = { 3000,&xssorygbph };



static While_control_RAM_CFL_t wfwwxpketj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ljpwunwynl_rom = { 0 ,true, &ggpbflgmoo,&wfwwxpketj_ram,null_function};

    
static const char *nptsfjodpr = "if_else_2 is terminating";


//----------RAM data structures for columns ----

unsigned hdjwvvyqkj[7];
Watch_dog_struct_CFL_t * wugejdignf[7];
unsigned char ajqnbjjqgy[7];
unsigned char kkttdfhoni[7];
void* djlqalpxhf[7];
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

static const Column_ROM_CFL_t lszafunxjw[] = {
  { -1,true, 0, 12, 0, -1, -1 },
  { -1,false, 1, 4, 12, -1, -1 },
  { -1,false, 2, 4, 16, -1, -1 },
  { -1,false, 3, 4, 20, -1, -1 },
  { -1,false, 4, 4, 24, -1, -1 },
  { -1,false, 5, 4, 28, -1, -1 },
  { -1,false, 6, 4, 32, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char gfrzwijlxp[36];


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

static const Column_element_CFL_t aokkdisllr[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&vsjztmrahq},
    {if_then_else_function_CFL,true_constant_handler,(void *)&wcnuvokcuz},
    {if_then_else_function_CFL,false_constant_handler,(void *)&mkjfysegmc},
    {if_then_else_function_CFL,true_constant_handler,(void *)&umpcdibrnj},
    {if_then_else_function_CFL,false_constant_handler,(void *)&lzjtikclea},
    {one_shot_handler_CFL,log_message_CFL,(void *)&oorzeerumu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mupjxupwik_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&msweqpvnqx},
    {if_then_else_function_CFL,true_constant_handler,(void *)&jrpszjtihg},
    {if_then_else_function_CFL,false_constant_handler,(void *)&wdaoudqeqg},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aymwqaixtu},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bpdzimlvpx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nfzaxonkov_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kikirdzruw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pzhvrkrcbl},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&huqkdublhs_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vjkljfljhe},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&snvlyijngt},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bfixsxolqy_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wiyhabhawi},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qaahfwrmnu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kgqdlactoy_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jyrzgtuuny},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xjialxuunf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&enylafmmxd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qksnelbrrn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ascdazwqar},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ljpwunwynl_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nptsfjodpr},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t hmmlgvhsky;




static Engine_control_CFL_t qdioxfwccw;


/* remaining allocate heap size */

static unsigned clqivmvaok;


/* current heap pointer */

static char* hvbezjafnr;


/* heap block area */

static CS_MEMORY_CONTROL crdbcdwtfe;


    
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


const struct Handle_CFL_t ujctlwarka =
{

  .queue_number = 1,
  .queue_rom = ydsfhcqfhn,
  .queue_ram = whiceqqrhz,

  .column_elements_flags =gfrzwijlxp,
  .column_elements_ROM = aokkdisllr,

  .watch_dog_struct = wugejdignf,
  .watch_dog_count  = hdjwvvyqkj,
   
   
  .column_flags = ajqnbjjqgy,
  .column_local_data = djlqalpxhf,
  .column_state = kkttdfhoni,
  .number_of_columns = 7,
  .column_rom_data = lszafunxjw,

  
  
  
  .time_control = &hmmlgvhsky,
  .engine_control =&qdioxfwccw,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &clqivmvaok,
  .current_heap_location = &hvbezjafnr,
  .private_heap   = &crdbcdwtfe,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  if_then_else_handle(){
    return &ujctlwarka;
}
   

#ifdef __cplusplus
}
#endif

#endif
