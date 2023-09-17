#ifndef __state_machine_2_H__
#define __state_machine_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t dwceuclawt[6];
static Event_data_CFL_t igqktmyclc[10];
static Event_data_CFL_t nyvexplqon[10];
static Event_data_CFL_t aohgaqitij[10];
static Event_data_CFL_t cqskxyvgvf[10];
static Event_data_CFL_t lcbudyabay[10];
static Event_data_CFL_t dkpgsrdfxk[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t metlwvivwi[] = { 
     {  10, igqktmyclc },
     {  10, nyvexplqon },
     {  10, aohgaqitij },
     {  10, cqskxyvgvf },
     {  10, lcbudyabay },
     {  10, dkpgsrdfxk },
};
const char test_data_2[] = "test_data\n";
const Event_data_CFL_t yczfvupixj = { 101, false, NULL };
const Event_data_CFL_t ndlmpqykpx = { 102, false, NULL };
const Event_data_CFL_t ziwhgykdpm = { 103, false, NULL };
const Event_data_CFL_t fdctrgrtyl = { 104, false, NULL };
const Event_data_CFL_t aehqzxcdfj = { 111, false, NULL };
const Event_data_CFL_t uboepuopse = { 112, false, NULL };
const Event_data_CFL_t hxhthljeec = { 113, false, NULL };

const char test_data_11[] = "state 1 debug message";
const char test_data_21[] = "state 2 debug message";
const char test_data_31[] = "state 3 debug message";
const char test_data_41[] = "state 4 debug message";
static const char *zlrjknddnx = "start column";

const unsigned short  eofagyxjlg[] = {0};

enable_disable_sm_CFL_t cqowscvcpl = {1,eofagyxjlg };
static const unsigned short iavvkdypbc[] = { 1};
const Enable_column_CFL_t knrdfbykax = { true, 1, iavvkdypbc };


unsigned  mepiyfzqap;
const While_time_control_ROM_CFL_t vboattnqpv = { 60000,&mepiyfzqap };



static While_control_RAM_CFL_t bsrsvxffxu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bfgmksckmz_rom = { 0 ,true, &vboattnqpv,&bsrsvxffxu_ram,null_function};

    
static const char *ovwkeybdpz = "terminating";
static const char *wguvdipssa = "event generator start";


unsigned  bndpemgzrx;
const While_time_control_ROM_CFL_t kcqpsjrmku = { 2000,&bndpemgzrx };



static While_control_RAM_CFL_t nammgtlxrm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kheugnxlkm_rom = { 0 ,true, &kcqpsjrmku,&nammgtlxrm_ram,null_function};

    
const sm_event_CFL_t yoajogvsfo = {0,&aehqzxcdfj};
const sm_event_CFL_t jmuukyntsv = {0,&uboepuopse};
const sm_event_CFL_t dyyjaofofa = {0,&hxhthljeec};
const sm_event_CFL_t gqiirxrhgs = {0,&yczfvupixj};


unsigned  taywxttdts;
const While_time_control_ROM_CFL_t rvsecgrbkm = { 2000,&taywxttdts };



static While_control_RAM_CFL_t yogfaqfnuo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hwnngqhrsz_rom = { 0 ,true, &rvsecgrbkm,&yogfaqfnuo_ram,null_function};

    
const sm_event_CFL_t xyeygbieoy = {0,&aehqzxcdfj};
const sm_event_CFL_t hluhknyfdq = {0,&uboepuopse};
const sm_event_CFL_t xwygmezjib = {0,&hxhthljeec};
const sm_event_CFL_t qtyocxbmlo = {0,&ndlmpqykpx};


unsigned  icvenzmkel;
const While_time_control_ROM_CFL_t paoqxqaqbm = { 2000,&icvenzmkel };



static While_control_RAM_CFL_t zsaasypinw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hfvdosdfvk_rom = { 0 ,true, &paoqxqaqbm,&zsaasypinw_ram,null_function};

    
const sm_event_CFL_t ogurrmgqvt = {0,&aehqzxcdfj};
const sm_event_CFL_t qtwhvmzyvt = {0,&uboepuopse};
const sm_event_CFL_t lpzksyirci = {0,&hxhthljeec};
const sm_event_CFL_t bqwworlrdw = {0,&ziwhgykdpm};


unsigned  ihugrbouio;
const While_time_control_ROM_CFL_t bybxycraje = { 2000,&ihugrbouio };



static While_control_RAM_CFL_t ybozjxqqao_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wyzycxacum_rom = { 0 ,true, &bybxycraje,&ybozjxqqao_ram,null_function};

    
const sm_event_CFL_t jyfnjzcedb = {0,&aehqzxcdfj};
const sm_event_CFL_t kxqrozbwoe = {0,&uboepuopse};
const sm_event_CFL_t viavcwqkma = {0,&hxhthljeec};
const sm_event_CFL_t rovmmraqio = {0,&fdctrgrtyl};
static const char *cmlrndearl = "state machine manager starting";
const change_sm_state_CFL_t ausbxvyldu = {0,0};
const unsigned short lfofxxxnak[] = {101};
const state_change_CFL_t uibnqstwqy = {0,0,1,lfofxxxnak};
const unsigned short tqwurkahgo[] = {102};
const state_change_CFL_t igrypgjpdv = {0,1,1,tqwurkahgo};
const unsigned short yeefxtfpzy[] = {103};
const state_change_CFL_t dvyyhmzefo = {0,2,1,yeefxtfpzy};
const unsigned short lryeujafsv[] = {104};
const state_change_CFL_t ahnxzktjba = {0,3,1,lryeujafsv};
const redirect_CFL_t wgszssrkgx = {0,NULL};
static const char *kqiakykkyr = "state 1 starting";
const SM_debug_CFL_t kgkbauacfi = {0,0,test_data_11};
static const char *zrbuuiiiqm = "state 2 starting";
const SM_debug_CFL_t hqnwaarrhv = {0,1,test_data_21};
static const char *ddlhcfjeet = "state 3 starting";
const SM_debug_CFL_t ohsharlqbg = {0,2,test_data_31};
static const char *euxnjtyytl = "state 4 starting";
const SM_debug_CFL_t ewgvpbnxdq = {0,3,test_data_41};


//----------RAM data structures for columns ----

unsigned yihnfapeob[7];
Watch_dog_struct_CFL_t * pxkdkqfvpl[7];
unsigned char zpuhbnysxl[7];
unsigned char elbyvtgvhv[7];
void* upilwnvjhs[7];
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

static const Column_ROM_CFL_t rrgmwjopoq[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 22, 6, -1, -1 },
  { 1,false, 2, 8, 28, -1, -1 },
  { 2,false, 3, 3, 36, -1, -1 },
  { 3,false, 4, 3, 39, -1, -1 },
  { 4,false, 5, 3, 42, -1, -1 },
  { 5,false, 6, 3, 45, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char atcbzpoomc[48];


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

static const Column_element_CFL_t afqpspzzzv[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&zlrjknddnx},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&cqowscvcpl},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&knrdfbykax},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bfgmksckmz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ovwkeybdpz},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wguvdipssa},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kheugnxlkm_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&yoajogvsfo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jmuukyntsv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dyyjaofofa},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gqiirxrhgs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hwnngqhrsz_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xyeygbieoy},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hluhknyfdq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xwygmezjib},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qtyocxbmlo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hfvdosdfvk_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ogurrmgqvt},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qtwhvmzyvt},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&lpzksyirci},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bqwworlrdw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wyzycxacum_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jyfnjzcedb},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kxqrozbwoe},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&viavcwqkma},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rovmmraqio},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cmlrndearl},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&ausbxvyldu},
    {state_change_CFL,NULL,(void *)&uibnqstwqy},
    {state_change_CFL,NULL,(void *)&igrypgjpdv},
    {state_change_CFL,NULL,(void *)&dvyyhmzefo},
    {state_change_CFL,NULL,(void *)&ahnxzktjba},
    {redirect_event_CFL,true_constant_handler,(void *)&wgszssrkgx},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kqiakykkyr},
    {SM_debug_CFL,true_constant_handler,(void *)&kgkbauacfi},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zrbuuiiiqm},
    {SM_debug_CFL,true_constant_handler,(void *)&hqnwaarrhv},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ddlhcfjeet},
    {SM_debug_CFL,true_constant_handler,(void *)&ohsharlqbg},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&euxnjtyytl},
    {SM_debug_CFL,true_constant_handler,(void *)&ewgvpbnxdq},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short bbmgvvetgn[4] = {2,3,4,5,};
short dgbuxxszbv[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t anxcbxghxw[1] = {
{0,1,2,4,dgbuxxszbv,bbmgvvetgn,(void *)test_data_2},
}; 
Sm_control_RAM_CFL_t wwvzxzkkwc[1];


static Time_control_CFL_t jtbxdhkher;




static Engine_control_CFL_t bqslewikhu;


/* remaining allocate heap size */

static unsigned wuizeavwui;


/* current heap pointer */

static char* lghyvynzzl;


/* heap block area */

static CS_MEMORY_CONTROL lopraibxgl;


    
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


const struct Handle_CFL_t xdrauwshbw =
{

  .queue_number = 6,
  .queue_rom = metlwvivwi,
  .queue_ram = dwceuclawt,

  .column_elements_flags =atcbzpoomc,
  .column_elements_ROM = afqpspzzzv,

  .watch_dog_struct = pxkdkqfvpl,
  .watch_dog_count  = yihnfapeob,
   
   
  .column_flags = zpuhbnysxl,
  .column_local_data = upilwnvjhs,
  .column_state = elbyvtgvhv,
  .number_of_columns = 7,
  .column_rom_data = rrgmwjopoq,

  
  
  
  .time_control = &jtbxdhkher,
  .engine_control =&bqslewikhu,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &wuizeavwui,
  .current_heap_location = &lghyvynzzl,
  .private_heap   = &lopraibxgl,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  anxcbxghxw,
   .sm_ram     = wwvzxzkkwc,
} ;


const Handle_CFL_t*  state_machine_2_handle(){
    return &xdrauwshbw;
}
   

#ifdef __cplusplus
}
#endif

#endif
