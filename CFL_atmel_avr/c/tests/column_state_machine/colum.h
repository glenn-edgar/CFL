#ifndef __watch_dog_H__
#define __watch_dog_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t xqocitymzm[10];
static Event_control_RAM_CFL_t rfkonxnutu[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t kdvjuxmsru_default = { 10, 0 };
static const Event_control_ROM_CFL_t *kdvjuxmsru[] = {
     &kdvjuxmsru_default,
};
static const Named_event_queue_control_CFL_t nwqpcmsmxe = { 1,10,kdvjuxmsru };


unsigned  nbhctcnfbm;
const While_time_control_ROM_CFL_t bpoxdufnmo = { 30000,&nbhctcnfbm };



static While_control_RAM_CFL_t dejtdnzjxc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ptojqrutel_rom = { 0 ,true, &bpoxdufnmo,&dejtdnzjxc_ram,null_function};

    
static const char *wwvsatfoma = "watch_dog_reset";
const Attach_watch_dog_CFL_t bzvamujhci = { test_wd_handler, false, NULL, 5000};


unsigned  tnoiodpltv;
const While_time_control_ROM_CFL_t njkgghsrym = { 10000,&tnoiodpltv };



static While_control_RAM_CFL_t jofgmmogea_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ehkxxcazoy_rom = { 0 ,true, &njkgghsrym,&jofgmmogea_ram,null_function};

    
static const char *dlegowzwfu = "should not see this message";
static const char *bmpvfigrev = "watch_dog_terminate";
const Attach_watch_dog_CFL_t jopxuzmtzq = { test_wd_handler, true, NULL, 5000};


unsigned  qsynsrljov;
const While_time_control_ROM_CFL_t vkmzidmrkl = { 10000,&qsynsrljov };



static While_control_RAM_CFL_t jkymtqbgiz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nkhosrmgbf_rom = { 0 ,true, &vkmzidmrkl,&jkymtqbgiz_ram,null_function};

    
static const char *givmxglwpb = "should not see this message";
static const char *heqsamykfj = "watch_dog_pass";
const Attach_watch_dog_CFL_t gxwpjuitbm = { test_wd_handler, true, NULL, 5000};


unsigned  sezimpyhvb;
const While_time_control_ROM_CFL_t emzdsnzgky = { 1000,&sezimpyhvb };



static While_control_RAM_CFL_t vsoezeuger_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t izgpjjllbg_rom = { 0 ,true, &emzdsnzgky,&vsoezeuger_ram,null_function};

    


unsigned  udyzdwfitq;
const While_time_control_ROM_CFL_t phyffklfyk = { 5000,&udyzdwfitq };



static While_control_RAM_CFL_t nqgiqijtvp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uvyqqagssd_rom = { 0 ,true, &phyffklfyk,&nqgiqijtvp_ram,null_function};

    
static const char *isdypuumzj = "watch_dog_pass passed";


//----------RAM data structures for columns ----

unsigned bzwqlidzhd[4];
unsigned scucnmnawg[4];
One_shot_function_CFL_t  bhjgqrdsgf[4];
bool  hkzymacubp[4];
void *  xazrjoxykr[4];
unsigned char pirfaixuiv[4];
unsigned char nnlziarxta[4];
void* srezitlfoc[4];
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

static const Column_ROM_CFL_t tanlfkhfzz[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 6, 2, -1, -1 },
  { -1,true, 2, 6, 8, -1, -1 },
  { -1,true, 3, 7, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char pfxrprgrgy[21];


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

static const Column_element_CFL_t ovsasnmbnm[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ptojqrutel_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wwvsatfoma},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&bzvamujhci},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ehkxxcazoy_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dlegowzwfu},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bmpvfigrev},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&jopxuzmtzq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nkhosrmgbf_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {one_shot_handler_CFL,log_message_CFL,(void *)&givmxglwpb},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&heqsamykfj},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&gxwpjuitbm},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&izgpjjllbg_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uvyqqagssd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&isdypuumzj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t uqfajmmnby;




static Engine_control_CFL_t zebejtgrku;


/* remaining allocate heap size */

static unsigned givhcywcoy;


/* current heap pointer */

static char* heauflpflw;


/* heap block area */

static CS_MEMORY_CONTROL mxdbbijasm;


      
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ozneemleuv =
{

  .queue_rom    = &nwqpcmsmxe,
  .queue_ram =  rfkonxnutu,
  .event_data = xqocitymzm,

  .column_elements_flags =pfxrprgrgy,
  .column_elements_ROM = ovsasnmbnm,

  .watch_dog_trigger_count = bzwqlidzhd,
  .watch_dog_count       =  scucnmnawg,  
  .watch_dog_trigger_function = bhjgqrdsgf,
  .watch_dog_termination_flag = hkzymacubp,
  .watch_dog_user_data = xazrjoxykr,
   
   
  .column_flags = pirfaixuiv,
  .column_local_data = srezitlfoc,
  .column_state = nnlziarxta,
  .number_of_columns = 4,
  .column_rom_data = tanlfkhfzz,

  
  
  
  .time_control = &uqfajmmnby,
  .engine_control =&zebejtgrku,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &givhcywcoy,
  .current_heap_location = &heauflpflw,
  .private_heap   = &mxdbbijasm,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  watch_dog_handle(){
    return &ozneemleuv;
}
   

#ifdef __cplusplus
}
#endif

#endif
