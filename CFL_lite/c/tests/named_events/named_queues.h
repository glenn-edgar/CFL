#ifndef __named_queues_H__
#define __named_queues_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define jsmzxoxroq 101 


 #define pxpsybrukm 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t xymeilqqwx[2];
static Event_data_CFL_t rboaixqnnh[10];
static Event_data_CFL_t fllripvwsv[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t rtfwlywrfy[] = { 
     {  10, rboaixqnnh },
     {  10, fllripvwsv },
};
const Event_data_CFL_t ytvyrzpmsb = { pxpsybrukm, false, NULL };
const Event_data_CFL_t bwgwytwkjr = { jsmzxoxroq, false, NULL };


unsigned  vaatvlfgfv;
const While_time_control_ROM_CFL_t txtowrswgt = { 120000,&vaatvlfgfv };



static While_control_RAM_CFL_t qxmvxsacey_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t udcklbcbib_rom = { 0 ,true, &txtowrswgt,&qxmvxsacey_ram,null_function};

    
static const char *xvqxokwnbi = "event generator start";


unsigned  kgkzgoxxkz;
const While_time_control_ROM_CFL_t jkhmmruauv = { 15000,&kgkzgoxxkz };



static While_control_RAM_CFL_t xjzyyggrkt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hmtnjyehhi_rom = { 0 ,true, &jkhmmruauv,&xjzyyggrkt_ram,null_function};

    
const Queue_event_CFL_t xhieruvylp = { 1, &ytvyrzpmsb };
const Queue_event_CFL_t sfyenndydc = { 1, &bwgwytwkjr };
static const char *zzafipvuut = "executing a sequence of actions first";
static const char *sttbexgvku = "action 1";


unsigned  jrihhmbbcf;
const While_time_control_ROM_CFL_t wukrrmbxvs = { 1000,&jrihhmbbcf };



static While_control_RAM_CFL_t jiagdyxgmr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zqnepdobke_rom = { 0 ,true, &wukrrmbxvs,&jiagdyxgmr_ram,null_function};

    
static const char *dysvlurgwo = "action 2";


unsigned  tvvflhmjpq;
const While_time_control_ROM_CFL_t kfknmqughf = { 1000,&tvvflhmjpq };



static While_control_RAM_CFL_t wughbhqknm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t flnwwtmjsn_rom = { 0 ,true, &kfknmqughf,&wughbhqknm_ram,null_function};

    
static const char *uuxcjwamah = "action 3";
unsigned short rwrdxcuacs = 0;
static const char *izcdwkcvni = "state machines are active at this point";
static const char *bztokhtajb = "end step";

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
    
    Printf_CFL("filter_event_1 termination event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == pxpsybrukm){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  if(event->event_index == jsmzxoxroq){
    
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
   
    if(*count >=  3){
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
   
    if(*count >=  3){
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
   
    if(*count >=  3){
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
   
    if(*count >=  3){
      change_local_column_state_CFL(input, 0);
       return HALT_CFL;
    }
    return CONTINUE_CFL;
  
  }
  
  return CONTINUE_CFL;
}



//----------RAM data structures for columns ----

unsigned lkyphocaaq[3];
Watch_dog_struct_CFL_t * ettcfhmnkx[3];
unsigned char labuankrkv[3];
unsigned char dweayeqzrp[3];
void* gafpdhnctu[3];
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

static const Column_ROM_CFL_t yckslrtolx[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 5, 2, -1, -1 },
  { 1,true, 2, 15, 7, 9, 12 },
};


//----------Column elements RAM structures----



static unsigned char yomxxwzmfw[22];


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

static const Column_element_CFL_t ebkeiprkwu[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&udcklbcbib_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xvqxokwnbi},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hmtnjyehhi_rom},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&xhieruvylp},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&sfyenndydc},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zzafipvuut},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sttbexgvku},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zqnepdobke_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dysvlurgwo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&flnwwtmjsn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uuxcjwamah},
    {change_column_state_CFL,NULL,(void *)&rwrdxcuacs},
    {one_shot_handler_CFL,log_message_CFL,(void *)&izcdwkcvni},
    {filter_event_1,NULL,(void *)&filter_event_data_1},
    {sm_0,NULL,(void *)&sm_0_data},
    {sm_1,NULL,(void *)&sm_1_data},
    {sm_2,NULL,(void *)&sm_2_data},
    {sm_3,NULL,(void *)&sm_3_data},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bztokhtajb},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
const Sm_control_ROM_CFL_t alhovwdvbj[0];
Sm_control_RAM_CFL_t mnnymqgbci[0];


static Time_control_CFL_t nvjlpyepun;




static Engine_control_CFL_t dqshuqhrsf;


/* remaining allocate heap size */

static unsigned fwfvjfhjln;


/* current heap pointer */

static char* pyjogvwmvx;


/* heap block area */

static CS_MEMORY_CONTROL akndjahsna;


    
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


const struct Handle_CFL_t hjcgvadpcy =
{

  .queue_number = 2,
  .queue_rom = rtfwlywrfy,
  .queue_ram = xymeilqqwx,

  .column_elements_flags =yomxxwzmfw,
  .column_elements_ROM = ebkeiprkwu,

  .watch_dog_struct = ettcfhmnkx,
  .watch_dog_count  = lkyphocaaq,
   
   
  .column_flags = labuankrkv,
  .column_local_data = gafpdhnctu,
  .column_state = dweayeqzrp,
  .number_of_columns = 3,
  .column_rom_data = yckslrtolx,

  
  
  
  .time_control = &nvjlpyepun,
  .engine_control =&dqshuqhrsf,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &fwfvjfhjln,
  .current_heap_location = &pyjogvwmvx,
  .private_heap   = &akndjahsna,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
   .sm_rom     =  alhovwdvbj,
   .sm_ram     = mnnymqgbci,
} ;


const Handle_CFL_t*  named_queue_handle(){
    return &hjcgvadpcy;
}
   

#ifdef __cplusplus
}
#endif

#endif
