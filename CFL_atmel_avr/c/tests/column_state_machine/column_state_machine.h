#ifndef __column_state_machine_H__
#define __column_state_machine_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define ypuxbspwvm 100 


 #define szygrzycef 101 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t zozgdbwujd[1];
static Event_data_CFL_t mqhagbyqmt[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t thbqlmjvmr[] = { 
     {  10, mqhagbyqmt },
};
const Event_data_CFL_t gjgxzsunuu = { ypuxbspwvm, false, NULL };
const Event_data_CFL_t viwtmrifsa = { szygrzycef, false, NULL };
static const char *jefuquvuvx = "test_start";
static const char *vyneebyvjb = "step 0";
static const char *nmfxggfvkt = "step 1";
static const char *tvurpyobey = "step 2";
static const char *lhmhpojotx = "step 3";
unsigned short klhdghfpuq = 0;
static const char *yhoafyshmh = "test_start";
static const char *iabcmibfxs = "step 6";
static const char *fwgggkdvam = "step 7";
static const char *ltqqybiuhm = "step 8";
static const char *csowdqefpo = "step 9";
static const char *ksxpnhkwfu = "step 10";
static const char *etsaugdtzn = "test_end";
static const char *dvryfktydh = "step 0";
static const char *pvtfzvehwo = "step 1";
static const char *lmgudeticg = "step 2";
static const char *tyupuhwtxf = "step 3";
unsigned short vuedbtspre = 5;
static const char *aiviqcoael = "step 5";
static const char *kiednjcvac = "step 6";
static const char *iggxwzlbsw = "step 7";
static const char *nmknmeptyv = "step 8";
static const char *memrspawgm = "step 9";
static const char *aolbmoeaqe = "test_end";
static const char *hmvupcbqlk = "test_middle";
static const char *kmfpxleabt = "step 0";
static const char *xdcgxcqxkq = "step 1";
static const char *mrtwjsjgmm = "step 2";
static const char *togqcporwi = "step 3";
unsigned short qjgsylgadt = 3;
static const char *hdokerqyyj = "step 5";
static const char *haowiiktpg = "step 6";
static const char *qbyfmlbuaf = "step 7";
static const char *rbeykjqoes = "test_middle";
static const char *pjelhtastw = "step 9";
static const char *hypcdadujx = "step 10";


unsigned  sabtktylfs;
const While_time_control_ROM_CFL_t wdpjdganhe = { 120000,&sabtktylfs };



static While_control_RAM_CFL_t ohixgcbsuf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bwtjenuwjm_rom = { 0 ,true, &wdpjdganhe,&ohixgcbsuf_ram,null_function};

    
static const char *etzjfulnnz = "event generator start";


unsigned  dyjdwgibjo;
const While_time_control_ROM_CFL_t naeorgonxr = { 30000,&dyjdwgibjo };



static While_control_RAM_CFL_t dbnkveswqs_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hanwjodblb_rom = { 0 ,true, &naeorgonxr,&dbnkveswqs_ram,null_function};

    
static const char *ogrkrvgztw = "executing a sequence of actions first";
static const char *ccllcrvzfc = "action 1";


unsigned  mcihpftziy;
const While_time_control_ROM_CFL_t sttxyzargb = { 1000,&mcihpftziy };



static While_control_RAM_CFL_t agviecgipk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uzcrlwmdmq_rom = { 0 ,true, &sttxyzargb,&agviecgipk_ram,null_function};

    
static const char *hqzmiasjeq = "action 2";


unsigned  mfafnfwlaz;
const While_time_control_ROM_CFL_t gbemsnqdyk = { 1000,&mfafnfwlaz };



static While_control_RAM_CFL_t ojrrpqpxpq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qdqxfjreaa_rom = { 0 ,true, &gbemsnqdyk,&ojrrpqpxpq_ram,null_function};

    
static const char *nsrlwsznbb = "action 3";
unsigned short gigisqnzby = 0;
static const char *moegtkdard = "state machines are active at this point";
static const char *mnyhjvbgrg = "end step";

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
  if( event->event_index == ypuxbspwvm){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  if(event->event_index == szygrzycef){
    
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

unsigned boruwqdynd[6];
unsigned jhawvricbb[6];
One_shot_function_CFL_t  wqiywjfudm[6];
unsigned char uhdbexsivr[6];
void *  pvuyktjfjz[6];
unsigned char aubdjydbmp[6];
unsigned char veeaoekrfv[6];
void* exjqcmrbma[6];
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

static const Column_ROM_CFL_t toqukhjjqs[] = {
  { -1,true, 0, 12, 0, 6, 11 },
  { -1,true, 1, 12, 24, 6, 11 },
  { -1,true, 2, 12, 12, 6, 11 },
  { -1,true, 3, 2, 36, -1, -1 },
  { -1,true, 4, 5, 38, -1, -1 },
  { -1,true, 5, 15, 43, 9, 12 },
};


//----------Column elements RAM structures----



static unsigned char vntyazkexy[58];


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

static const Column_element_CFL_t zjerixbjdn[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&jefuquvuvx},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vyneebyvjb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nmfxggfvkt},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tvurpyobey},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lhmhpojotx},
    {change_column_state_CFL,NULL,(void *)&klhdghfpuq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yhoafyshmh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iabcmibfxs},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fwgggkdvam},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ltqqybiuhm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&csowdqefpo},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ksxpnhkwfu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&etsaugdtzn},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dvryfktydh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pvtfzvehwo},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lmgudeticg},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tyupuhwtxf},
    {change_column_state_CFL,NULL,(void *)&vuedbtspre},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aiviqcoael},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kiednjcvac},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iggxwzlbsw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nmknmeptyv},
    {one_shot_handler_CFL,log_message_CFL,(void *)&memrspawgm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aolbmoeaqe},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hmvupcbqlk},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kmfpxleabt},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xdcgxcqxkq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mrtwjsjgmm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&togqcporwi},
    {change_column_state_CFL,NULL,(void *)&qjgsylgadt},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hdokerqyyj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&haowiiktpg},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qbyfmlbuaf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rbeykjqoes},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pjelhtastw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hypcdadujx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bwtjenuwjm_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&etzjfulnnz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hanwjodblb_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&gjgxzsunuu},
    {one_shot_handler_CFL,send_event_CFL,(void *)&viwtmrifsa},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ogrkrvgztw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ccllcrvzfc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uzcrlwmdmq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hqzmiasjeq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qdqxfjreaa_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nsrlwsznbb},
    {change_column_state_CFL,NULL,(void *)&gigisqnzby},
    {one_shot_handler_CFL,log_message_CFL,(void *)&moegtkdard},
    {filter_event_1,NULL,(void *)&filter_event_data_1},
    {sm_0,NULL,(void *)&sm_0_data},
    {sm_1,NULL,(void *)&sm_1_data},
    {sm_2,NULL,(void *)&sm_2_data},
    {sm_3,NULL,(void *)&sm_3_data},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mnyhjvbgrg},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};


static Time_control_CFL_t swmmvntpqu;




static Engine_control_CFL_t xkxwnyaeta;


/* remaining allocate heap size */

static unsigned vrlolfkhgd;


/* current heap pointer */

static char* nodxsktmjv;


/* heap block area */

static CS_MEMORY_CONTROL trqbhuzsfl;


    
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
const struct Handle_CFL_t qymyuaelte =
{

  .queue_number = 1,
  .queue_rom = thbqlmjvmr,
  .queue_ram = zozgdbwujd,

  .column_elements_flags =vntyazkexy,
  .column_elements_ROM = zjerixbjdn,

  .watch_dog_trigger_count = boruwqdynd,
  .watch_dog_count       =  jhawvricbb,  
  .watch_dog_trigger_function = wqiywjfudm,
  .watch_dog_termination_flag = uhdbexsivr,
  .watch_dog_user_data = pvuyktjfjz,
   
   
  .column_flags = aubdjydbmp,
  .column_local_data = exjqcmrbma,
  .column_state = veeaoekrfv,
  .number_of_columns = 6,
  .column_rom_data = toqukhjjqs,

  
  
  
  .time_control = &swmmvntpqu,
  .engine_control =&xkxwnyaeta,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &vrlolfkhgd,
  .current_heap_location = &nodxsktmjv,
  .private_heap   = &trqbhuzsfl,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  column_state_machine_handle(){
    return &qymyuaelte;
}
   

#ifdef __cplusplus
}
#endif

#endif
