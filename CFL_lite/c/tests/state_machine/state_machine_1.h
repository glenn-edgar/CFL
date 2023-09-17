#ifndef __state_machine_1_H__
#define __state_machine_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


const char test_data[] = "test_data\n";
#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t jnenvxfaiq[6];
static Event_data_CFL_t blihonhoqy[10];
static Event_data_CFL_t gzqmsvoqfn[10];
static Event_data_CFL_t kevwfdcpjr[10];
static Event_data_CFL_t uguxbtaqsk[10];
static Event_data_CFL_t mryifbihid[10];
static Event_data_CFL_t tahvwrbymm[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t zoveavqwry[] = { 
     {  10, blihonhoqy },
     {  10, gzqmsvoqfn },
     {  10, kevwfdcpjr },
     {  10, uguxbtaqsk },
     {  10, mryifbihid },
     {  10, tahvwrbymm },
};
static const char *hbxbimvait = "start column";

const unsigned short  kexojwzscs[] = {0};

enable_disable_sm_CFL_t gvemyvfgqa = {1,kexojwzscs };


unsigned  aqlaooymaq;
const While_time_control_ROM_CFL_t tksopoencz = { 20000,&aqlaooymaq };



static While_control_RAM_CFL_t rrlzbxzcvn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kcopehaxjq_rom = { 0 ,true, &tksopoencz,&rrlzbxzcvn_ram,null_function};

    
static const char *wcunkekrbq = "terminating";
static const char *dvhplgsrdf = "state machine manager starting";


unsigned  mijftmenzq;
const While_time_control_ROM_CFL_t mzctjghjix = { 2000,&mijftmenzq };



static While_control_RAM_CFL_t sxfibmukvj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tmnlclvyay_rom = { 0 ,true, &mzctjghjix,&sxfibmukvj_ram,null_function};

    
const change_sm_state_CFL_t leophiqpas = {0,0};
static const char *tgxbciqhnf = "this message should not be printed";
static const char *nkezbpztfb = "state 1 starting";


unsigned  caxamnswnq;
const While_time_control_ROM_CFL_t zqlitjprcq = { 2000,&caxamnswnq };



static While_control_RAM_CFL_t bpvxrrxgdh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lhyuqkmowz_rom = { 0 ,true, &zqlitjprcq,&bpvxrrxgdh_ram,null_function};

    
const change_sm_state_CFL_t ufpeooggjq = {0,1};
static const char *yragzxjyau = "this message should not be printed";
static const char *kzawjwyefr = "state 2 starting";


unsigned  utrohdmiwd;
const While_time_control_ROM_CFL_t qzuuaiasld = { 2000,&utrohdmiwd };



static While_control_RAM_CFL_t knvkwegwhr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rdyjpsmeed_rom = { 0 ,true, &qzuuaiasld,&knvkwegwhr_ram,null_function};

    
const change_sm_state_CFL_t qzyjqijgsa = {0,2};
static const char *rxinuvvjfo = "this message should not be printed";
static const char *xhitjhlkmn = "state 3 starting";


unsigned  yqieupbagn;
const While_time_control_ROM_CFL_t tcrvlnbhnn = { 2000,&yqieupbagn };



static While_control_RAM_CFL_t znytuyicxh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t iuraheadhb_rom = { 0 ,true, &tcrvlnbhnn,&znytuyicxh_ram,null_function};

    
const change_sm_state_CFL_t zjyiykvsmu = {0,3};
static const char *ofuwfdxuid = "this message should not be printed";
static const char *hoxofhahvv = "state 4 starting";


unsigned  ejaapoegsi;
const While_time_control_ROM_CFL_t xsfizboaii = { 2000,&ejaapoegsi };



static While_control_RAM_CFL_t rxvaxqvtbg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t apwpmzdiep_rom = { 0 ,true, &xsfizboaii,&rxvaxqvtbg_ram,null_function};

    
const change_sm_state_CFL_t lkhuhxvtve = {0,0};
static const char *dechambcda = "this message should not be printed";


//----------RAM data structures for columns ----

unsigned tfjfyukhxk[6];
Watch_dog_struct_CFL_t * oweubylpas[6];
unsigned char rjivbdfhne[6];
unsigned char zjcxrbkfuv[6];
void* kcjkzqnprz[6];
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

static const Column_ROM_CFL_t pfcjztupyr[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { 1,false, 1, 5, 5, -1, -1 },
  { 2,false, 2, 5, 10, -1, -1 },
  { 3,false, 3, 5, 15, -1, -1 },
  { 4,false, 4, 5, 20, -1, -1 },
  { 5,false, 5, 5, 25, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char ihvcebsgai[30];


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

static const Column_element_CFL_t kllheablxq[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&hbxbimvait},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&gvemyvfgqa},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kcopehaxjq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wcunkekrbq},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dvhplgsrdf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tmnlclvyay_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&leophiqpas},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tgxbciqhnf},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nkezbpztfb},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lhyuqkmowz_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&ufpeooggjq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yragzxjyau},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kzawjwyefr},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rdyjpsmeed_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&qzyjqijgsa},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rxinuvvjfo},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xhitjhlkmn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&iuraheadhb_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&zjyiykvsmu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ofuwfdxuid},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hoxofhahvv},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&apwpmzdiep_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&lkhuhxvtve},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dechambcda},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short yiiyrkffew[4] = {2,3,4,5,};
short alxdygopvh[4] = {2,3,4,5,};
const Sm_control_ROM_CFL_t vojnnypxbs[1] = {
{0,1,1,4,alxdygopvh,yiiyrkffew,(void *)test_data},
}; 
Sm_control_RAM_CFL_t gqdfqxelsi[1];


static Time_control_CFL_t jbyhnfkrbr;




static Engine_control_CFL_t qqjfgcrbtf;


/* remaining allocate heap size */

static unsigned xavpksjyms;


/* current heap pointer */

static char* vdbqocozwq;


/* heap block area */

static CS_MEMORY_CONTROL xqcsiohvtj;


    
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


const struct Handle_CFL_t mpbgjfjelh =
{

  .queue_number = 6,
  .queue_rom = zoveavqwry,
  .queue_ram = jnenvxfaiq,

  .column_elements_flags =ihvcebsgai,
  .column_elements_ROM = kllheablxq,

  .watch_dog_struct = oweubylpas,
  .watch_dog_count  = tfjfyukhxk,
   
   
  .column_flags = rjivbdfhne,
  .column_local_data = kcjkzqnprz,
  .column_state = zjcxrbkfuv,
  .number_of_columns = 6,
  .column_rom_data = pfcjztupyr,

  
  
  
  .time_control = &jbyhnfkrbr,
  .engine_control =&qqjfgcrbtf,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &xavpksjyms,
  .current_heap_location = &vdbqocozwq,
  .private_heap   = &xqcsiohvtj,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  vojnnypxbs,
   .sm_ram     = gqdfqxelsi,
} ;


const Handle_CFL_t*  state_machine_1_handle(){
    return &mpbgjfjelh;
}
   

#ifdef __cplusplus
}
#endif

#endif
