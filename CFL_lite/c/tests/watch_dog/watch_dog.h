#ifndef __watch_dog_H__
#define __watch_dog_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t imshfazwbw[10];
static Event_control_RAM_CFL_t uqbosjypxv[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t plabbybdme_default = { 10, 0 };
static const Event_control_ROM_CFL_t *plabbybdme[] = {
     &plabbybdme_default,
};
static const Named_event_queue_control_CFL_t tesmnvhklh = { 1,10,plabbybdme };


unsigned  eejowzdsey;
const While_time_control_ROM_CFL_t hinvovzsnz = { 30000,&eejowzdsey };



static While_control_RAM_CFL_t vvmbqygrln_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ghnvrkukat_rom = { 0 ,true, &hinvovzsnz,&vvmbqygrln_ram,null_function};

    
static const char *atzpkebqqb = "watch_dog_reset";
const Attach_watch_dog_CFL_t hkfdaidylw = { test_wd_handler, false, NULL, 5000};


unsigned  ocsuhwuxfb;
const While_time_control_ROM_CFL_t yizodxrwhn = { 10000,&ocsuhwuxfb };



static While_control_RAM_CFL_t ecnexbqhin_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t upxrovqvwu_rom = { 0 ,true, &yizodxrwhn,&ecnexbqhin_ram,null_function};

    
static const char *mtrtnkhxgl = "should not see this message";
static const char *tuutdojcuh = "watch_dog_terminate";
const Attach_watch_dog_CFL_t nnkqjlcwmk = { test_wd_handler, true, NULL, 5000};


unsigned  gukjmsdfqa;
const While_time_control_ROM_CFL_t gejmmngaop = { 10000,&gukjmsdfqa };



static While_control_RAM_CFL_t pxgxkmaimv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t egfcwwqecc_rom = { 0 ,true, &gejmmngaop,&pxgxkmaimv_ram,null_function};

    
static const char *afapvcgklg = "should not see this message";
static const char *dwgbdiccyx = "watch_dog_pass";
const Attach_watch_dog_CFL_t ewjllhicif = { test_wd_handler, true, NULL, 5000};


unsigned  pxivmzmltn;
const While_time_control_ROM_CFL_t qucvylgvyl = { 1000,&pxivmzmltn };



static While_control_RAM_CFL_t kckvytqtae_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wlrwhuqvgd_rom = { 0 ,true, &qucvylgvyl,&kckvytqtae_ram,null_function};

    


unsigned  mvfoqadsgc;
const While_time_control_ROM_CFL_t qzgiangesc = { 5000,&mvfoqadsgc };



static While_control_RAM_CFL_t sopimdoayj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rojidfwzmb_rom = { 0 ,true, &qzgiangesc,&sopimdoayj_ram,null_function};

    
static const char *ihkxiuihts = "watch_dog_pass passed";


//----------RAM data structures for columns ----

unsigned tvhfrofhpj[4];
unsigned wqaxgktvtu[4];
One_shot_function_CFL_t  apdaixgojr[4];
bool  cdpwzwdjtq[4];
void *  yaawvsohlj[4];
unsigned char qvneqjmdep[4];
unsigned char yeovghmkft[4];
void* poksatjpxq[4];
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

static const Column_ROM_CFL_t rvwwtygwqt[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 6, 2, -1, -1 },
  { -1,true, 2, 6, 8, -1, -1 },
  { -1,true, 3, 7, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char zuggbtqscx[21];


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

static const Column_element_CFL_t wqyshbzeqn[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ghnvrkukat_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&atzpkebqqb},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&hkfdaidylw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&upxrovqvwu_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mtrtnkhxgl},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tuutdojcuh},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&nnkqjlcwmk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&egfcwwqecc_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {one_shot_handler_CFL,log_message_CFL,(void *)&afapvcgklg},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dwgbdiccyx},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&ewjllhicif},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wlrwhuqvgd_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,(void *)&clear_watch_dog_placeholder},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rojidfwzmb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ihkxiuihts},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t slxlmfsqzx;




static Engine_control_CFL_t jrlbjvfqjs;


/* remaining allocate heap size */

static unsigned obrhebkzvz;


/* current heap pointer */

static char* tvcderseka;


/* heap block area */

static CS_MEMORY_CONTROL fwdiovxcac;


      
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t xbuoscxilh =
{

  .queue_rom    = &tesmnvhklh,
  .queue_ram =  uqbosjypxv,
  .event_data = imshfazwbw,

  .column_elements_flags =zuggbtqscx,
  .column_elements_ROM = wqyshbzeqn,

  .watch_dog_trigger_count = tvhfrofhpj,
  .watch_dog_count       =  wqaxgktvtu,  
  .watch_dog_trigger_function = apdaixgojr,
  .watch_dog_termination_flag = cdpwzwdjtq,
  .watch_dog_user_data = yaawvsohlj,
   
   
  .column_flags = qvneqjmdep,
  .column_local_data = poksatjpxq,
  .column_state = yeovghmkft,
  .number_of_columns = 4,
  .column_rom_data = rvwwtygwqt,

  
  
  
  .time_control = &slxlmfsqzx,
  .engine_control =&jrlbjvfqjs,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &obrhebkzvz,
  .current_heap_location = &tvcderseka,
  .private_heap   = &fwdiovxcac,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  watch_dog_handle(){
    return &xbuoscxilh;
}
   

#ifdef __cplusplus
}
#endif

#endif
