#ifndef __named_queue_H__
#define __named_queue_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define crkybcxcsz 101 


 #define jlublsqlmo 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t mbjrjpimak[20];
static Event_control_RAM_CFL_t nnbdlwijxm[2];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hfqrxefgam_default = { 10, 0 };
static const Event_control_ROM_CFL_t hfqrxefgam_queue1 = { 10, 10 };
static const Event_control_ROM_CFL_t *hfqrxefgam[] = {
     &hfqrxefgam_default,
     &hfqrxefgam_queue1,
};
static const Named_event_queue_control_CFL_t jonvcdndoq = { 2,20,hfqrxefgam };
const Event_data_CFL_t coesienoda = { jlublsqlmo, false, NULL, };
const Event_data_CFL_t cbzdwpsimc = { crkybcxcsz, false, NULL, };


unsigned  brqnkqzhea;
const While_time_control_ROM_CFL_t dkgupjhqne = { 120000,&brqnkqzhea };



static While_control_RAM_CFL_t ohcwekiwlc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t iwlcmqqzay_rom = { 0 ,true, &dkgupjhqne,&ohcwekiwlc_ram,null_function};

    
static const char *hrhvosxltb = "event generator start";


unsigned  ihnyaoddzy;
const While_time_control_ROM_CFL_t rmchdzzkph = { 30000,&ihnyaoddzy };



static While_control_RAM_CFL_t gtbjbteszx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qqwthvrept_rom = { 0 ,true, &rmchdzzkph,&gtbjbteszx_ram,null_function};

    
static const char *wzisfztygk = "executing a sequence of actions first";
static const char *eteusbzkzs = "action 1";


unsigned  wjsadlflgy;
const While_time_control_ROM_CFL_t oncyhrxdov = { 1000,&wjsadlflgy };



static While_control_RAM_CFL_t cpwfrrshxa_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fzwkyzhvde_rom = { 0 ,true, &oncyhrxdov,&cpwfrrshxa_ram,null_function};

    
static const char *jnsuneacyi = "action 2";


unsigned  wcjofyqcti;
const While_time_control_ROM_CFL_t vjuzxcrwsp = { 1000,&wcjofyqcti };



static While_control_RAM_CFL_t bruramvcre_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zdmxlxgxpn_rom = { 0 ,true, &vjuzxcrwsp,&bruramvcre_ram,null_function};

    
static const char *vuazzcpvwd = "action 3";
unsigned short vcnvberdqe = 0;
static const char *lxsjvnirio = "state machines are active at this point";
static const char *gajmzrkygq = "end step";

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
  if( event->event_index == jlublsqlmo){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  if(event->event_index == crkybcxcsz){
    
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

unsigned jzttwtoxia[3];
unsigned ullaejbldp[3];
One_shot_function_CFL_t  yrqrsdkkfg[3];
bool  qjhxvlfnju[3];
void *  jitwnrmpom[3];
unsigned char wcrjwtnssy[3];
unsigned char nhxyjshpcu[3];
void* tvbbbeyxya[3];
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

static const Column_ROM_CFL_t femyvzwzzj[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 5, 2, -1, -1 },
  { 1,true, 2, 15, 7, 9, 12 },
};


//----------Column elements RAM structures----



static unsigned char rqmszazosr[22];


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

static const Column_element_CFL_t egzjklxfzd[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&iwlcmqqzay_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hrhvosxltb},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qqwthvrept_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&coesienoda},
    {one_shot_handler_CFL,send_event_CFL,(void *)&cbzdwpsimc},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wzisfztygk},
    {one_shot_handler_CFL,log_message_CFL,(void *)&eteusbzkzs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fzwkyzhvde_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jnsuneacyi},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zdmxlxgxpn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vuazzcpvwd},
    {change_column_state_CFL,NULL,(void *)&vcnvberdqe},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lxsjvnirio},
    {filter_event_1,NULL,(void *)&filter_event_data_1},
    {sm_0,NULL,(void *)&sm_0_data},
    {sm_1,NULL,(void *)&sm_1_data},
    {sm_2,NULL,(void *)&sm_2_data},
    {sm_3,NULL,(void *)&sm_3_data},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gajmzrkygq},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};


static Time_control_CFL_t sbfonnrpph;




static Engine_control_CFL_t rzsxuumzlr;


/* remaining allocate heap size */

static unsigned jsfpbaxgeb;


/* current heap pointer */

static char* hkugjbavhn;


/* heap block area */

static CS_MEMORY_CONTROL bgkzxxmank;


      
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t kzlhwfkiwc =
{

  .queue_rom    = &jonvcdndoq,
  .queue_ram =  nnbdlwijxm,
  .event_data = mbjrjpimak,

  .column_elements_flags =rqmszazosr,
  .column_elements_ROM = egzjklxfzd,

  .watch_dog_trigger_count = jzttwtoxia,
  .watch_dog_count       =  ullaejbldp,  
  .watch_dog_trigger_function = yrqrsdkkfg,
  .watch_dog_termination_flag = qjhxvlfnju,
  .watch_dog_user_data = jitwnrmpom,
   
   
  .column_flags = wcrjwtnssy,
  .column_local_data = tvbbbeyxya,
  .column_state = nhxyjshpcu,
  .number_of_columns = 3,
  .column_rom_data = femyvzwzzj,

  
  
  
  .time_control = &sbfonnrpph,
  .engine_control =&rzsxuumzlr,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &jsfpbaxgeb,
  .current_heap_location = &hkugjbavhn,
  .private_heap   = &bgkzxxmank,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  named_queue_handle(){
    return &kzlhwfkiwc;
}
   

#ifdef __cplusplus
}
#endif

#endif
