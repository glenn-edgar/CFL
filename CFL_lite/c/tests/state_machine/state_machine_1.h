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

static Event_control_RAM_CFL_t hsairwiasz[6];
static Event_data_CFL_t gfiqauimbe[10];
static Event_data_CFL_t irbltgmyat[10];
static Event_data_CFL_t awxjgygees[10];
static Event_data_CFL_t ujrqpvtijs[10];
static Event_data_CFL_t tzknlxwgzk[10];
static Event_data_CFL_t ftnudkzlfs[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ggtyvtadza[] = { 
     {  10, gfiqauimbe },
     {  10, irbltgmyat },
     {  10, awxjgygees },
     {  10, ujrqpvtijs },
     {  10, tzknlxwgzk },
     {  10, ftnudkzlfs },
};
static const char *lqozymtobp = "start column";

const unsigned short  klkdugiexn[] = {0};

enable_disable_sm_CFL_t lfuklhbngu = {1,klkdugiexn };


unsigned  bfapctiwus;
const While_time_control_ROM_CFL_t pmtrfvyjzz = { 20000,&bfapctiwus };



static While_control_RAM_CFL_t wceuctawav_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qdepfydxhs_rom = { 0 ,true, &pmtrfvyjzz,&wceuctawav_ram,null_function};

    
static const char *pxcptwhgzc = "terminating";
static const char *fmureufgpu = "state machine manager starting";


unsigned  ftooidgdzl;
const While_time_control_ROM_CFL_t wdimsbszcf = { 2000,&ftooidgdzl };



static While_control_RAM_CFL_t jtemptqjns_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ugwnlhoyqu_rom = { 0 ,true, &wdimsbszcf,&jtemptqjns_ram,null_function};

    
const change_sm_state_CFL_t mwmxtlqbvu = {0,0};
static const char *gezzuvxfuu = "this message should not be printed";
static const char *rrdggpxgns = "state 1 starting";


unsigned  kwcpesbmfe;
const While_time_control_ROM_CFL_t cghkleumwc = { 2000,&kwcpesbmfe };



static While_control_RAM_CFL_t mmocvydchr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bfjdjagnym_rom = { 0 ,true, &cghkleumwc,&mmocvydchr_ram,null_function};

    
const change_sm_state_CFL_t ievfjtsqwh = {0,1};
static const char *dtnqoplsem = "this message should not be printed";
static const char *fmvhmqtthj = "state 2 starting";


unsigned  zotarknyct;
const While_time_control_ROM_CFL_t ykosyoprrl = { 2000,&zotarknyct };



static While_control_RAM_CFL_t uiseglxzrq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bruowgddsa_rom = { 0 ,true, &ykosyoprrl,&uiseglxzrq_ram,null_function};

    
const change_sm_state_CFL_t behevxvtkt = {0,2};
static const char *xrcdaxizhl = "this message should not be printed";
static const char *eiedhnleyy = "state 3 starting";


unsigned  maxelqdsgi;
const While_time_control_ROM_CFL_t tjqpinjgsf = { 2000,&maxelqdsgi };



static While_control_RAM_CFL_t pojvmgcmvs_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nazmepsllk_rom = { 0 ,true, &tjqpinjgsf,&pojvmgcmvs_ram,null_function};

    
const change_sm_state_CFL_t yxygyiopsf = {0,3};
static const char *ajmzxozfzg = "this message should not be printed";
static const char *ufpkczkwif = "state 4 starting";


unsigned  zwysqbuqes;
const While_time_control_ROM_CFL_t gdflgpqoon = { 2000,&zwysqbuqes };



static While_control_RAM_CFL_t uiayvyangs_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t llruacboxy_rom = { 0 ,true, &gdflgpqoon,&uiayvyangs_ram,null_function};

    
const change_sm_state_CFL_t zwhvpstdkh = {0,0};
static const char *rvnacvbivo = "this message should not be printed";


//----------RAM data structures for columns ----

unsigned bzbcgyjxoo[6];
Watch_dog_struct_CFL_t * xubhguuixx[6];
unsigned char hyakidjdqh[6];
unsigned char rdshqhyeny[6];
void* nqdmomugta[6];
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

static const Column_ROM_CFL_t vlprjhtblm[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { 1,false, 1, 5, 5, -1, -1 },
  { 2,false, 2, 5, 10, -1, -1 },
  { 3,false, 3, 5, 15, -1, -1 },
  { 4,false, 4, 5, 20, -1, -1 },
  { 5,false, 5, 5, 25, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char xjfltymabp[30];


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

static const Column_element_CFL_t khukchrirh[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&lqozymtobp},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&lfuklhbngu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qdepfydxhs_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pxcptwhgzc},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fmureufgpu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ugwnlhoyqu_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&mwmxtlqbvu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gezzuvxfuu},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rrdggpxgns},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bfjdjagnym_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&ievfjtsqwh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dtnqoplsem},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fmvhmqtthj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bruowgddsa_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&behevxvtkt},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xrcdaxizhl},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&eiedhnleyy},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nazmepsllk_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&yxygyiopsf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ajmzxozfzg},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ufpkczkwif},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&llruacboxy_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&zwhvpstdkh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rvnacvbivo},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short idrswgscgs[4] = {2,3,4,5,};
short ugaijrucrd[4] = {2,3,4,5,};
const Sm_control_ROM_CFL_t tbddtfmmoq[1] = {
{0,1,1,4,ugaijrucrd,idrswgscgs,(void *)test_data},
}; 
Sm_control_RAM_CFL_t knwwxuedcv[1];


static Time_control_CFL_t ifdpldqggt;




static Engine_control_CFL_t ajxgagtkjs;


/* remaining allocate heap size */

static unsigned htitfvavbs;


/* current heap pointer */

static char* whqenydgdv;


/* heap block area */

static CS_MEMORY_CONTROL hphovnekvx;


    
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


const struct Handle_CFL_t aqreqgpsdh =
{

  .queue_number = 6,
  .queue_rom = ggtyvtadza,
  .queue_ram = hsairwiasz,

  .column_elements_flags =xjfltymabp,
  .column_elements_ROM = khukchrirh,

  .watch_dog_struct = xubhguuixx,
  .watch_dog_count  = bzbcgyjxoo,
   
   
  .column_flags = hyakidjdqh,
  .column_local_data = nqdmomugta,
  .column_state = rdshqhyeny,
  .number_of_columns = 6,
  .column_rom_data = vlprjhtblm,

  
  
  
  .time_control = &ifdpldqggt,
  .engine_control =&ajxgagtkjs,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &htitfvavbs,
  .current_heap_location = &whqenydgdv,
  .private_heap   = &hphovnekvx,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  tbddtfmmoq,
   .sm_ram     = knwwxuedcv,
} ;


const Handle_CFL_t*  state_machine_1_handle(){
    return &aqreqgpsdh;
}
   

#ifdef __cplusplus
}
#endif

#endif
