#ifndef __column_state_machine_H__
#define __column_state_machine_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define diiywdrezn 100 


 #define acereuhzhc 101 


//----------RAM data structures for event queues ----

static Event_data_CFL_t iqkdphugif[10];
static Event_control_RAM_CFL_t bhbwxxjadc[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ipaprukptf_default = { 10, 0 };
static const Event_control_ROM_CFL_t *ipaprukptf[] = {
     &ipaprukptf_default,
};
static const Named_event_queue_control_CFL_t swcvsvhnwo = { 1,10,ipaprukptf };
const Event_data_CFL_t iphreqqgse = { diiywdrezn, false, NULL, };
const Event_data_CFL_t kqbpnafdov = { acereuhzhc, false, NULL, };
static const char *lqwsvixqiq = "test_start";
static const char *kagngjzlap = "step 0";
static const char *fouqgtsxpa = "step 1";
static const char *cudbyfxbhw = "step 2";
static const char *fyhblkusue = "step 3";
unsigned short tjibwytvwl = 0;
static const char *gilqlcmsfs = "test_start";
static const char *zeykwhsffx = "step 6";
static const char *ctqwnxgroj = "step 7";
static const char *yixzbauiie = "step 8";
static const char *mzwnqjvrqb = "step 9";
static const char *xzefleypnb = "step 10";
static const char *algozgzyft = "test_end";
static const char *akxhiwnfwp = "step 0";
static const char *solsjgvdxa = "step 1";
static const char *dpvibgbpdx = "step 2";
static const char *dgxixpvcfg = "step 3";
unsigned short dyuwdubktv = 5;
static const char *hakhmhvhca = "step 5";
static const char *hxqbesnrxl = "step 6";
static const char *eqdgkeznmz = "step 7";
static const char *nsnjevzaaz = "step 8";
static const char *qbrhkxcfkv = "step 9";
static const char *lcuzaiodnm = "test_end";
static const char *rdtpxbxpwh = "test_middle";
static const char *mmlnjhlewy = "step 0";
static const char *trvyyssifj = "step 1";
static const char *alugzhtffa = "step 2";
static const char *bsboiqxdby = "step 3";
unsigned short wlqsyaeadz = 3;
static const char *arqcecyral = "step 5";
static const char *ivqxhewgma = "step 6";
static const char *dipqshqgvu = "step 7";
static const char *omftpzrygn = "test_middle";
static const char *cdaitnwjdl = "step 9";
static const char *mdynagyqjm = "step 10";


unsigned  bmdfbbfwke;
const While_time_control_ROM_CFL_t kmgynpcoqo = { 120000,&bmdfbbfwke };



static While_control_RAM_CFL_t hepqhlerib_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lobtiqttwx_rom = { 0 ,true, &kmgynpcoqo,&hepqhlerib_ram,null_function};

    
static const char *rfjfcutrxs = "event generator start";


unsigned  mzfaaesyys;
const While_time_control_ROM_CFL_t znarqvxqoh = { 30000,&mzfaaesyys };



static While_control_RAM_CFL_t zkvyxtozii_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ewegtlsezm_rom = { 0 ,true, &znarqvxqoh,&zkvyxtozii_ram,null_function};

    
static const char *mbroysellj = "executing a sequence of actions first";
static const char *osprteymlx = "action 1";


unsigned  budtsmdocy;
const While_time_control_ROM_CFL_t ziewlreqve = { 1000,&budtsmdocy };



static While_control_RAM_CFL_t euegagncet_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qbvlpaxmye_rom = { 0 ,true, &ziewlreqve,&euegagncet_ram,null_function};

    
static const char *pdjmbhpthj = "action 2";


unsigned  ijuqkzykql;
const While_time_control_ROM_CFL_t nmqrtzikxr = { 1000,&ijuqkzykql };



static While_control_RAM_CFL_t gndadmljhj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wzyzeqrtny_rom = { 0 ,true, &nmqrtzikxr,&gndadmljhj_ram,null_function};

    
static const char *ttdqymsert = "action 3";
unsigned short kfuqvurfgt = 0;
static const char *ckexkyxgjk = "state machines are active at this point";
static const char *qebektvyda = "end step";

static const char filter_event_data_1[] = "filter_event_data_1";



static int filter_event_1(const void *input,void *aux_fn,void *param,Event_data_CFL_t *event)
{
   (void)aux_fn;
   (void)param;
  if( event->event_index == EVENT_INIT_CFL){
    
    Printf_CFL("filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    Printf_CFL("filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == diiywdrezn){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  if(event->event_index == acereuhzhc){
    
    Printf_CFL("filter event 2 received doing changing column state to 3 \n");
    change_local_column_state_CFL(input, 3);
    return HALT_CFL;
  
  }
  return CONTINUE_CFL;
}

    static unsigned sm_0_data;
    static int sm_0(const void *input,void *aux_fn,void *param, Event_data_CFL_t *event)
{
   (void)aux_fn;

   unsigned *count = (unsigned *)param;

  if( event->event_index == EVENT_INIT_CFL){
    Printf_CFL("sm_0 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    
    *count = *count + 1;
   
    if(*count >=  5){
      change_local_column_state_CFL(input, 1);
       return HALT_CFL;
    }
    return CONTINUE_CFL;
  
  }
  
  return CONTINUE_CFL;
}

    static unsigned sm_1_data;
    static int sm_1(const void *input,void *aux_fn,void *param, Event_data_CFL_t *event)
{
   (void)aux_fn;

   unsigned *count = (unsigned *)param;

  if( event->event_index == EVENT_INIT_CFL){
    Printf_CFL("sm_1 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    
    *count = *count + 1;
   
    if(*count >=  5){
      change_local_column_state_CFL(input, 2);
       return HALT_CFL;
    }
    return CONTINUE_CFL;
  
  }
  
  return CONTINUE_CFL;
}

    static unsigned sm_2_data;
    static int sm_2(const void *input,void *aux_fn,void *param, Event_data_CFL_t *event)
{
   (void)aux_fn;

   unsigned *count = (unsigned *)param;

  if( event->event_index == EVENT_INIT_CFL){
    Printf_CFL("sm_2 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    
    *count = *count + 1;
   
    if(*count >=  5){
      change_local_column_state_CFL(input, 3);
       return HALT_CFL;
    }
    return CONTINUE_CFL;
  
  }
  
  return CONTINUE_CFL;
}

    static unsigned sm_3_data;
    static int sm_3(const void *input,void *aux_fn,void *param, Event_data_CFL_t *event)
{
   (void)aux_fn;

   unsigned *count = (unsigned *)param;

  if( event->event_index == EVENT_INIT_CFL){
    Printf_CFL("sm_3 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    
    *count = *count + 1;
   
    if(*count >=  5){
      change_local_column_state_CFL(input, 0);
       return HALT_CFL;
    }
    return CONTINUE_CFL;
  
  }
  
  return CONTINUE_CFL;
}



//----------RAM data structures for columns ----

unsigned wpomphanqb[6];
unsigned zairqtugck[6];
One_shot_function_CFL_t  upvwwgccon[6];
bool  epakooxqcn[6];
void *  xgtxlpunid[6];
unsigned char zvlprwbavr[6];
unsigned char wdagjmqlxg[6];
void* ahdnqoqcww[6];
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

static const Column_ROM_CFL_t xmkwhdplmm[] = {
  { -1,true, 0, 12, 0, 6, 11 },
  { -1,true, 1, 12, 24, 6, 11 },
  { -1,true, 2, 12, 12, 6, 11 },
  { -1,true, 3, 2, 36, -1, -1 },
  { -1,true, 4, 5, 38, -1, -1 },
  { -1,true, 5, 15, 43, 9, 12 },
};


//----------Column elements RAM structures----



static unsigned char pqllmyoeja[58];


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

static const Column_element_CFL_t ynrkqbfllz[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&lqwsvixqiq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kagngjzlap},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fouqgtsxpa},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cudbyfxbhw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fyhblkusue},
    {change_column_state_CFL,NULL,(void *)&tjibwytvwl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gilqlcmsfs},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zeykwhsffx},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ctqwnxgroj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yixzbauiie},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzwnqjvrqb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xzefleypnb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&algozgzyft},
    {one_shot_handler_CFL,log_message_CFL,(void *)&akxhiwnfwp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&solsjgvdxa},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dpvibgbpdx},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dgxixpvcfg},
    {change_column_state_CFL,NULL,(void *)&dyuwdubktv},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hakhmhvhca},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hxqbesnrxl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&eqdgkeznmz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nsnjevzaaz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qbrhkxcfkv},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lcuzaiodnm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rdtpxbxpwh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mmlnjhlewy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&trvyyssifj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&alugzhtffa},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bsboiqxdby},
    {change_column_state_CFL,NULL,(void *)&wlqsyaeadz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&arqcecyral},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ivqxhewgma},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dipqshqgvu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&omftpzrygn},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cdaitnwjdl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mdynagyqjm},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lobtiqttwx_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rfjfcutrxs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ewegtlsezm_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&iphreqqgse},
    {one_shot_handler_CFL,send_event_CFL,(void *)&kqbpnafdov},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mbroysellj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&osprteymlx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qbvlpaxmye_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pdjmbhpthj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wzyzeqrtny_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ttdqymsert},
    {change_column_state_CFL,NULL,(void *)&kfuqvurfgt},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ckexkyxgjk},
    {filter_event_1,NULL,(void *)&filter_event_data_1},
    {sm_0,NULL,(void *)&sm_0_data},
    {sm_1,NULL,(void *)&sm_1_data},
    {sm_2,NULL,(void *)&sm_2_data},
    {sm_3,NULL,(void *)&sm_3_data},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qebektvyda},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};


static Time_control_CFL_t ldpauwkmeo;




static Engine_control_CFL_t dufxwjayeh;


/* remaining allocate heap size */

static unsigned kthdhsolxk;


/* current heap pointer */

static char* jwjxtnfuxg;


/* heap block area */

static CS_MEMORY_CONTROL ltscqukgew;


      
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t nfnqhxejvu =
{

  .queue_rom    = &swcvsvhnwo,
  .queue_ram =  bhbwxxjadc,
  .event_data = iqkdphugif,

  .column_elements_flags =pqllmyoeja,
  .column_elements_ROM = ynrkqbfllz,

  .watch_dog_trigger_count = wpomphanqb,
  .watch_dog_count       =  zairqtugck,  
  .watch_dog_trigger_function = upvwwgccon,
  .watch_dog_termination_flag = epakooxqcn,
  .watch_dog_user_data = xgtxlpunid,
   
   
  .column_flags = zvlprwbavr,
  .column_local_data = ahdnqoqcww,
  .column_state = wdagjmqlxg,
  .number_of_columns = 6,
  .column_rom_data = xmkwhdplmm,

  
  
  
  .time_control = &ldpauwkmeo,
  .engine_control =&dufxwjayeh,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &kthdhsolxk,
  .current_heap_location = &jwjxtnfuxg,
  .private_heap   = &ltscqukgew,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  column_state_machine_handle(){
    return &nfnqhxejvu;
}
   

#ifdef __cplusplus
}
#endif

#endif
