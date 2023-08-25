#ifndef __named_queues_H__
#define __named_queues_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define ojrayoimbt 100 


 #define otgdtnginb 101 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t jmyaqiimru[2];
static Event_data_CFL_t jmkidiszky[10];
static Event_data_CFL_t jhdkstizus[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hotqsaikwi[] = { 
     {  10, jmkidiszky },
     {  10, jhdkstizus },
};
const Event_data_CFL_t qhojedqkmh = { ojrayoimbt, false, NULL };
const Event_data_CFL_t ndtghmgtjr = { otgdtnginb, false, NULL };


unsigned  axviyalxpq;
const While_time_control_ROM_CFL_t urpxpctpcd = { 120000,&axviyalxpq };



static While_control_RAM_CFL_t yzgotqdler_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kpzyfbfiyd_rom = { 0 ,true, &urpxpctpcd,&yzgotqdler_ram,null_function};

    
static const char *rmsrdweahr = "event generator start";


unsigned  frqzipyitu;
const While_time_control_ROM_CFL_t ihwopffmyb = { 15000,&frqzipyitu };



static While_control_RAM_CFL_t nokytxlvdr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ozwbzekptz_rom = { 0 ,true, &ihwopffmyb,&nokytxlvdr_ram,null_function};

    
const Queue_event_CFL_t rwrysuztty = { 1, &qhojedqkmh };
const Queue_event_CFL_t hjahcdcemf = { 1, &ndtghmgtjr };
static const char *fsrjivqvcz = "executing a sequence of actions first";
static const char *scbppymyuz = "action 1";


unsigned  desletcvgu;
const While_time_control_ROM_CFL_t iatiihwisl = { 1000,&desletcvgu };



static While_control_RAM_CFL_t dlszbefkzv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rmtxosvdbb_rom = { 0 ,true, &iatiihwisl,&dlszbefkzv_ram,null_function};

    
static const char *xzgrbcywyq = "action 2";


unsigned  rjgobzjugj;
const While_time_control_ROM_CFL_t ogzztcjqje = { 1000,&rjgobzjugj };



static While_control_RAM_CFL_t nfzmrvcbzy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jlzyxbcfhq_rom = { 0 ,true, &ogzztcjqje,&nfzmrvcbzy_ram,null_function};

    
static const char *otfvmjkjhc = "action 3";
unsigned short xfihmwsyyf = 0;
static const char *nafvmmhhgl = "state machines are active at this point";
static const char *ztjcnbolie = "end step";

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
  if( event->event_index == ojrayoimbt){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  if(event->event_index == otgdtnginb){
    
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

unsigned bwipapskdz[3];
unsigned icnxsbmbmj[3];
One_shot_function_CFL_t  ngjmfaijco[3];
unsigned char apkbqdjkyr[3];
void *  vdjjppmvxz[3];
unsigned char gvzaiszjyq[3];
unsigned char dtwerimdcq[3];
void* aecrtdsktj[3];
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

static const Column_ROM_CFL_t wtzsgciwnt[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 5, 2, -1, -1 },
  { 1,true, 2, 15, 7, 9, 12 },
};


//----------Column elements RAM structures----



static unsigned char zxpqajgzpi[22];


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

static const Column_element_CFL_t mtjxejrvop[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kpzyfbfiyd_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rmsrdweahr},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ozwbzekptz_rom},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&rwrysuztty},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&hjahcdcemf},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fsrjivqvcz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&scbppymyuz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rmtxosvdbb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xzgrbcywyq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jlzyxbcfhq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&otfvmjkjhc},
    {change_column_state_CFL,NULL,(void *)&xfihmwsyyf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nafvmmhhgl},
    {filter_event_1,NULL,(void *)&filter_event_data_1},
    {sm_0,NULL,(void *)&sm_0_data},
    {sm_1,NULL,(void *)&sm_1_data},
    {sm_2,NULL,(void *)&sm_2_data},
    {sm_3,NULL,(void *)&sm_3_data},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ztjcnbolie},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};


static Time_control_CFL_t giifnykwoc;




static Engine_control_CFL_t etzkrwzszk;


/* remaining allocate heap size */

static unsigned yggahfvxqa;


/* current heap pointer */

static char* bmfrqxivfr;


/* heap block area */

static CS_MEMORY_CONTROL qxanabtyqq;


    
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

  unsigned *watch_dog_trigger_count;
  unsigned *watch_dog_count;
 
  One_shot_function_CFL_t *watch_dog_trigger_function;
  unsigned char *watch_dog_termination_flag;
  void **watch_dog_user_data;
  
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

} Handle_CFL_t;
    local header_code = [[
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t wkhqzwlzpo =
{

  .queue_number = 2,
  .queue_rom = hotqsaikwi,
  .queue_ram = jmyaqiimru,

  .column_elements_flags =zxpqajgzpi,
  .column_elements_ROM = mtjxejrvop,

  .watch_dog_trigger_count = bwipapskdz,
  .watch_dog_count       =  icnxsbmbmj,  
  .watch_dog_trigger_function = ngjmfaijco,
  .watch_dog_termination_flag = apkbqdjkyr,
  .watch_dog_user_data = vdjjppmvxz,
   
   
  .column_flags = gvzaiszjyq,
  .column_local_data = aecrtdsktj,
  .column_state = dtwerimdcq,
  .number_of_columns = 3,
  .column_rom_data = wtzsgciwnt,

  
  
  
  .time_control = &giifnykwoc,
  .engine_control =&etzkrwzszk,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &yggahfvxqa,
  .current_heap_location = &bmfrqxivfr,
  .private_heap   = &qxanabtyqq,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  named_queue_handle(){
    return &wkhqzwlzpo;
}
   

#ifdef __cplusplus
}
#endif

#endif
