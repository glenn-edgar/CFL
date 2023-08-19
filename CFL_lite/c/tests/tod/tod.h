#ifndef __tod_H__
#define __tod_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t rnwysxqulc[10];
static Event_control_RAM_CFL_t bpqyoseraq[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t teimajlrvk_default = { 10, 0 };
static const Event_control_ROM_CFL_t *teimajlrvk[] = {
     &teimajlrvk_default,
};
static const Named_event_queue_control_CFL_t nhskgnlcsu = { 1,10,teimajlrvk };

static const char failure_verify_50[] = "failure for verify 50";
static const char failure_verify_49[] = "failure for verify 49";
static const char failure_verify_28[] = "failure for verify 28";



unsigned  akjojccevz;
const While_time_control_ROM_CFL_t retmhqbkix = { 180000,&akjojccevz };



static While_control_RAM_CFL_t vfxgkrposv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t gqxawdkxqm_rom = { 0 ,true, &retmhqbkix,&vfxgkrposv_ram,null_function};

    
static const char *navvicdhvr = "wait less than 10 seconds";
   const Wait_tod_ROM_CFL_t wlyqsuqexo_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,10,true,NULL }; 

static While_control_RAM_CFL_t zzanmmpael_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lyovxbghwt_rom = { -1 ,true, &wlyqsuqexo_rom,&zzanmmpael_ram,null_function};

    
static const char *zcrifhpmvv = "wait passed less than 10 seconds";
static const char *slmgvqwior = "wait less than equal 15 seconds";
   const Wait_tod_ROM_CFL_t rqtqwmttgf_rom = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,15,true,NULL }; 

static While_control_RAM_CFL_t mgfpmyujpl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t aezdgwoibv_rom = { -1 ,true, &rqtqwmttgf_rom,&mgfpmyujpl_ram,null_function};

    
static const char *zrcbupyoxl = "wait equal 17 seconds";
   const Wait_tod_ROM_CFL_t uaerwdncjs_rom = { OP_EQ_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t thxqmqgxbq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jdryxzmfrb_rom = { -1 ,true, &uaerwdncjs_rom,&thxqmqgxbq_ram,null_function};

    
static const char *mlkfedjveb = "wait greater than equal 20 seconds";
   const Wait_tod_ROM_CFL_t ulzqrywqog_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,20,true,NULL }; 

static While_control_RAM_CFL_t abwoktqhas_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uqpdkoouvw_rom = { -1 ,true, &ulzqrywqog_rom,&abwoktqhas_ram,null_function};

    
static const char *xnobkjwwap = "wait greater than 50 seconds";
   const Wait_tod_ROM_CFL_t fcsrgpqxgw_rom = { OP_GT_CFL,-1,-1,-1,-1,-1,-1,50,true,NULL }; 

static While_control_RAM_CFL_t wgujclkgjm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t prsmkitlyq_rom = { -1 ,true, &fcsrgpqxgw_rom,&wgujclkgjm_ram,null_function};

    
static const char *ipskjzkhxi = "Reseting column";
static const char *nezlnoagda = "verify tod column start";
   const Wait_tod_ROM_CFL_t izlqzgsrzh_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,1,true,NULL }; 

static While_control_RAM_CFL_t smsldbnhpf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zjocmfpecu_rom = { -1 ,true, &izlqzgsrzh_rom,&smsldbnhpf_ram,null_function};

    
static const char *nndlfrpvnz = "made it pass 0";
   const Wait_tod_ROM_CFL_t wdgcgbbllz_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t ntvivmdvgd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tlupgalkqi_rom = { -1 ,true, &wdgcgbbllz_rom,&ntvivmdvgd_ram,null_function};

    
static const char *lhwyjvnoji = "made it past 17 seconds";
   const Wait_tod_ROM_CFL_t zvgfodydnm = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,50,true,failure_verify_50 }; 
    static Verify_control_ROM_CFL_t rjaeakmash_rom = { true, (void *)&zvgfodydnm, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t pwcoyzfoeb = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,49,true,failure_verify_49 }; 
    static Verify_control_ROM_CFL_t tyfrdlaxqk_rom = { true, (void *)&pwcoyzfoeb, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t jtgehxrrjy = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,28,false,failure_verify_28 }; 
    static Verify_control_ROM_CFL_t nffxuhejgx_rom = { false, (void *)&jtgehxrrjy, tod_verify_reset };  // terminate flag,user data,one shot function


//----------RAM data structures for columns ----

unsigned lqyvzugycr[3];
unsigned zcuprzsams[3];
unsigned short uozceyrkty[3];
unsigned char aucfdsscpn[3];
unsigned char yknifysrrv[3];
void* afewxgtjxk[3];
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

static const Column_ROM_CFL_t yxqonukvmd[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 13, 2, -1, -1 },
  { -1,true, 2, 9, 15, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char qziwextjcd[24];


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

static const Column_element_CFL_t zczaegiwxb[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&gqxawdkxqm_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&navvicdhvr},
    {while_handler_CFL,test_tod_condition,(void *)&lyovxbghwt_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zcrifhpmvv},
    {one_shot_handler_CFL,log_message_CFL,(void *)&slmgvqwior},
    {while_handler_CFL,test_tod_condition,(void *)&aezdgwoibv_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zrcbupyoxl},
    {while_handler_CFL,test_tod_condition,(void *)&jdryxzmfrb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mlkfedjveb},
    {while_handler_CFL,test_tod_condition,(void *)&uqpdkoouvw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xnobkjwwap},
    {while_handler_CFL,test_tod_condition,(void *)&prsmkitlyq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ipskjzkhxi},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nezlnoagda},
    {while_handler_CFL,test_tod_condition,(void *)&zjocmfpecu_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nndlfrpvnz},
    {while_handler_CFL,test_tod_condition,(void *)&tlupgalkqi_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lhwyjvnoji},
    {verify_handler_CFL,test_tod_condition,(void *)&rjaeakmash_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&tyfrdlaxqk_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&nffxuhejgx_rom},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};


static Time_control_CFL_t ruprbybavt;




static Engine_control_CFL_t jxxngfsiar;


/* remaining allocate heap size */

static unsigned bnjymoojbd;


/* current heap pointer */

static char* arfgoskwar;


/* heap block area */

static CS_MEMORY_CONTROL vabmlemkpx;


      const Column_watch_dog_ROM_CFL_t watch_dog_control[0];
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ubppozixit =
{

  .queue_rom    = &nhskgnlcsu,
  .queue_ram =  bpqyoseraq,
  .event_data = rnwysxqulc,

  .column_elements_flags =qziwextjcd,
  .column_elements_ROM = zczaegiwxb,
  
  .watch_dog_trigger_count = lqyvzugycr,
  .watch_dog_count       =  zcuprzsams,  
  .watch_dog_id          =  uozceyrkty,
  .watch_dog_number    =    0,

   .watch_dog_rom_data = watch_dog_control,
  .column_flags = aucfdsscpn,
  .column_local_data = afewxgtjxk,
  .column_state = yknifysrrv,
  .number_of_columns = 3,
  .column_rom_data = yxqonukvmd,

  
  
  
  .time_control = &ruprbybavt,
  .engine_control =&jxxngfsiar,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &bnjymoojbd,
  .current_heap_location = &arfgoskwar,
  .private_heap   = &vabmlemkpx,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  tod_handle(){
    return &ubppozixit;
}
   

#ifdef __cplusplus
}
#endif

#endif
