#ifndef __column_state_machine_H__
#define __column_state_machine_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t vxtdesawdg[10];
static Event_control_RAM_CFL_t usrvinnlsc[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t oaivkhbvva_default = { 10, 0 };
static const Event_control_ROM_CFL_t *oaivkhbvva[] = {
     &oaivkhbvva_default,
};
static const Named_event_queue_control_CFL_t jdgclpvqui = { 1,10,oaivkhbvva };


unsigned  tfuagdcjqb;
const While_time_control_ROM_CFL_t qcyqjxktpe = { 30000,&tfuagdcjqb };



static While_control_RAM_CFL_t vjoaakdlam_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rcikfmywxd_rom = { 0 ,true, &qcyqjxktpe,&vjoaakdlam_ram,null_function};

    
static const char *mzsrifvurq = "watch_dog_reset";
const Attach_watch_dog_CFL_t izffrtdyvb = { test_wd_handler, false, NULL, 5000};


unsigned  uidixwhdiq;
const While_time_control_ROM_CFL_t bcfpdkqrnm = { 10000,&uidixwhdiq };



static While_control_RAM_CFL_t utsjyvilwq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hlqlnlojvv_rom = { 0 ,true, &bcfpdkqrnm,&utsjyvilwq_ram,null_function};

    
static const char *qweqxhjndr = "should not see this message";
static const char *mzvabxgwfo = "watch_dog_terminate";
const Attach_watch_dog_CFL_t nkckrmiwwe = { test_wd_handler, true, NULL, 5000};


unsigned  cgnnukosam;
const While_time_control_ROM_CFL_t wkwwkeeoed = { 10000,&cgnnukosam };



static While_control_RAM_CFL_t xebcucnkgm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t eaddrawhcr_rom = { 0 ,true, &wkwwkeeoed,&xebcucnkgm_ram,null_function};

    
static const char *adiznhpsqj = "should not see this message";
static const char *hpblcgpxoj = "watch_dog_pass";
const Attach_watch_dog_CFL_t cqxgryfjxu = { test_wd_handler, true, NULL, 5000};


unsigned  tqeffoxnnj;
const While_time_control_ROM_CFL_t zraeqvmutp = { 1000,&tqeffoxnnj };



static While_control_RAM_CFL_t wevreudnls_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t psnzfzahqg_rom = { 0 ,true, &zraeqvmutp,&wevreudnls_ram,null_function};

    


unsigned  uqsghxdori;
const While_time_control_ROM_CFL_t fatnjtorpj = { 5000,&uqsghxdori };



static While_control_RAM_CFL_t isapsryztn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t aovynpgyoi_rom = { 0 ,true, &fatnjtorpj,&isapsryztn_ram,null_function};

    
static const char *kgolahdtyy = "watch_dog_pass passed";


//----------RAM data structures for columns ----

unsigned xuwifxpiwz[4];
unsigned vaskinrhue[4];
One_shot_function_CFL_t  enrfxtkvmt[4];
bool  jqykgthpjg[4];
void *  nmgtjlcbwn[4];
unsigned char qyvdhsrudx[4];
unsigned char kvnnejtyqd[4];
void* xfzeswxyqg[4];
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

static const Column_ROM_CFL_t woxchjaljo[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 6, 2, -1, -1 },
  { -1,true, 2, 6, 8, -1, -1 },
  { -1,true, 3, 7, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char ypjxobpghi[21];


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

static const Column_element_CFL_t dyfrdtqahl[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rcikfmywxd_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzsrifvurq},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&izffrtdyvb},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hlqlnlojvv_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qweqxhjndr},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzvabxgwfo},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&nkckrmiwwe},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&eaddrawhcr_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {one_shot_handler_CFL,log_message_CFL,(void *)&adiznhpsqj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hpblcgpxoj},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&cqxgryfjxu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&psnzfzahqg_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&aovynpgyoi_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kgolahdtyy},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t hcyxdttibd;




static Engine_control_CFL_t qvkuaoamae;


/* remaining allocate heap size */

static unsigned bvkfexvgpe;


/* current heap pointer */

static char* zghleodsfk;


/* heap block area */

static CS_MEMORY_CONTROL jmlwpmzigj;


      
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t fyewhaifve =
{

  .queue_rom    = &jdgclpvqui,
  .queue_ram =  usrvinnlsc,
  .event_data = vxtdesawdg,

  .column_elements_flags =ypjxobpghi,
  .column_elements_ROM = dyfrdtqahl,

  .watch_dog_trigger_count = xuwifxpiwz,
  .watch_dog_count       =  vaskinrhue,  
  .watch_dog_trigger_function = enrfxtkvmt,
  .watch_dog_termination_flag = jqykgthpjg,
  .watch_dog_user_data = nmgtjlcbwn,
   
   
  .column_flags = qyvdhsrudx,
  .column_local_data = xfzeswxyqg,
  .column_state = kvnnejtyqd,
  .number_of_columns = 4,
  .column_rom_data = woxchjaljo,

  
  
  
  .time_control = &hcyxdttibd,
  .engine_control =&qvkuaoamae,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &bvkfexvgpe,
  .current_heap_location = &zghleodsfk,
  .private_heap   = &jmlwpmzigj,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  column_state_machine_handle(){
    return &fyewhaifve;
}
   

#ifdef __cplusplus
}
#endif

#endif
