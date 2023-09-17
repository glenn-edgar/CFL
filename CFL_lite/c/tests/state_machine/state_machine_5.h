#ifndef __state_machine_5_H__
#define __state_machine_5_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t spgueunqbd[6];
static Event_data_CFL_t lfjarapqdo[10];
static Event_data_CFL_t gpyfoztwqt[10];
static Event_data_CFL_t otyxfrepto[10];
static Event_data_CFL_t itecumdmkk[10];
static Event_data_CFL_t bvchxwesww[10];
static Event_data_CFL_t ztdeamaaar[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t swncdcmgee[] = { 
     {  10, lfjarapqdo },
     {  10, gpyfoztwqt },
     {  10, otyxfrepto },
     {  10, itecumdmkk },
     {  10, bvchxwesww },
     {  10, ztdeamaaar },
};
const Event_data_CFL_t lelrctuxra = { 101, false, NULL };
const Event_data_CFL_t qjrtitpoxk = { 102, false, NULL };
const Event_data_CFL_t vsfbrlwnwc = { 103, false, NULL };
const Event_data_CFL_t ssnrgrwxts = { 104, false, NULL };
const Event_data_CFL_t wbaogqwlql = { 111, false, NULL };
const Event_data_CFL_t nfieaqlphy = { 112, false, NULL };
const Event_data_CFL_t ndjvuebjsf = { 113, false, NULL };
const Event_data_CFL_t pjwtskmccu = { 200, false, NULL };
const Event_data_CFL_t qcxusogcve = { 200, false, NULL };
const Event_data_CFL_t uejtkrhnfh = { 201, false, NULL };

const char test_data_15[] = "state 1 debug message";
const char test_data_25[] = "state 2 debug message";
const char test_data_35[] = "state 3 debug message";
const char test_data_45[] = "state 4 debug message";
static const char *qzocisgrvk = "start column";

const unsigned short  wrdotszrge[] = {0};

enable_disable_sm_CFL_t ukurfhljbe = {1,wrdotszrge };
static const unsigned short xrgduqwkub[] = { 1};
const Enable_column_CFL_t wsukppjdxm = { true, 1, xrgduqwkub };


unsigned  irogmbwndt;
const While_time_control_ROM_CFL_t kdliuvanav = { 120000,&irogmbwndt };



static While_control_RAM_CFL_t nphlujpizc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wdsihptvuz_rom = { 0 ,true, &kdliuvanav,&nphlujpizc_ram,null_function};

    
static const char *cpjaoionch = "terminating";
static const char *hqpfnbmyjx = "event generator start";


unsigned  mclocqavjk;
const While_time_control_ROM_CFL_t fyioiyziii = { 2000,&mclocqavjk };



static While_control_RAM_CFL_t envubvayqb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mwztpauaap_rom = { 0 ,true, &fyioiyziii,&envubvayqb_ram,null_function};

    
const sm_event_CFL_t vbloroklyy = {0,&wbaogqwlql};
const sm_event_CFL_t enhnupjdcp = {0,&nfieaqlphy};
const sm_event_CFL_t mkxvvywrbr = {0,&ndjvuebjsf};
const sm_event_CFL_t nszmplnktz = {0,&lelrctuxra};


unsigned  vpayalzjtb;
const While_time_control_ROM_CFL_t wokauafmib = { 2000,&vpayalzjtb };



static While_control_RAM_CFL_t qzbjpelgww_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t byhbvzcluc_rom = { 0 ,true, &wokauafmib,&qzbjpelgww_ram,null_function};

    
const sm_event_CFL_t mrgcqnipvc = {0,&wbaogqwlql};
const sm_event_CFL_t dvlikuezpd = {0,&nfieaqlphy};
const sm_event_CFL_t joirunhjvi = {0,&ndjvuebjsf};
const sm_event_CFL_t rpohvcwzmu = {0,&qjrtitpoxk};


unsigned  nsefyrphat;
const While_time_control_ROM_CFL_t dudxlhxwrf = { 2000,&nsefyrphat };



static While_control_RAM_CFL_t qrqncpdtkk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sovguspslw_rom = { 0 ,true, &dudxlhxwrf,&qrqncpdtkk_ram,null_function};

    
const sm_event_CFL_t alvdzmwawy = {0,&wbaogqwlql};
const sm_event_CFL_t xpdzlbdqjj = {0,&nfieaqlphy};
const sm_event_CFL_t omamegnrns = {0,&ndjvuebjsf};
const sm_event_CFL_t cqguhktrwz = {0,&vsfbrlwnwc};


unsigned  vkuachjomo;
const While_time_control_ROM_CFL_t oufjctcbyt = { 2000,&vkuachjomo };



static While_control_RAM_CFL_t tfslqacoac_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mkzofayahv_rom = { 0 ,true, &oufjctcbyt,&tfslqacoac_ram,null_function};

    
const sm_event_CFL_t gtzelrkicl = {0,&wbaogqwlql};
const sm_event_CFL_t tqiopxzqyj = {0,&nfieaqlphy};
const sm_event_CFL_t yhoskmkdrd = {0,&ndjvuebjsf};
const sm_event_CFL_t tfjzchkckj = {0,&ssnrgrwxts};


unsigned  oruhzfftgk;
const While_time_control_ROM_CFL_t vctiwqoxhm = { 5000,&oruhzfftgk };



static While_control_RAM_CFL_t jptcgxqead_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sfbcjjwejo_rom = { 0 ,true, &vctiwqoxhm,&jptcgxqead_ram,null_function};

    
const sm_event_CFL_t cythacjjxe = {0,&qcxusogcve};
const sm_event_CFL_t vfbfyhsnmj = {0,&uejtkrhnfh};


unsigned  dsglisgqcb;
const While_time_control_ROM_CFL_t wnrjioemaa = { 30000,&dsglisgqcb };



static While_control_RAM_CFL_t qgcdzivssf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ynvqukvcyv_rom = { 0 ,true, &wnrjioemaa,&qgcdzivssf_ram,null_function};

    
static const char *rsqhpqdlzv = "state machine manager starting";
const change_sm_state_CFL_t khhuxsydkp = {0,0};
const unsigned short juuedcvmez[] = {101};
const state_change_CFL_t ntfcbabsgt = {0,0,1,juuedcvmez};
const unsigned short csnpkpnigy[] = {102};
const state_change_CFL_t qaksfuaagg = {0,1,1,csnpkpnigy};
const unsigned short jvskpqbtnl[] = {103};
const state_change_CFL_t rmhbszatvn = {0,2,1,jvskpqbtnl};
const unsigned short lkeperiuly[] = {104};
const state_change_CFL_t sxiwzlyfbb = {0,3,1,lkeperiuly};
const redirect_CFL_t nwquqlcdpr = {0,NULL};
static const char *hqbvtagpwn = "state 1 starting";
const SM_debug_CFL_t twmpqadims = {0,0,test_data_15};
static const char *ebmfygpbte = "state 2 starting";
const SM_debug_CFL_t rxrucoqhxq = {0,1,test_data_25};
static const char *rqzkyuljgy = "state 3 starting";
const SM_debug_CFL_t rgbysfivfu = {0,2,test_data_35};
static const char *ebaotgeisj = "executing a sequence of actions first";
static const char *egkemzizzn = "action 1";


unsigned  ycnzrgcesf;
const While_time_control_ROM_CFL_t cqhfeeklcz = { 1000,&ycnzrgcesf };



static While_control_RAM_CFL_t uncouhauqd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t krpaojlkbv_rom = { 0 ,true, &cqhfeeklcz,&uncouhauqd_ram,null_function};

    
static const char *tliqghopul = "action 2";


unsigned  nhbojcwncf;
const While_time_control_ROM_CFL_t aoiyiprhdm = { 1000,&nhbojcwncf };



static While_control_RAM_CFL_t lcbdwfzwww_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mwnzmguzsi_rom = { 0 ,true, &aoiyiprhdm,&lcbdwfzwww_ram,null_function};

    
static const char *hvibitnubn = "action 3";
unsigned short epayueghxb = 0;
static const char *uilarkimhg = "state machines are active at this point";
static const char *zdtyhuetbj = "end step";

static const char filter_event_data_1[] = "filter_event_data_1";



static int filter_event_1(const void *input,void *aux_fn,void *param,Event_data_CFL_t *event)
{
   (void)aux_fn;
   (void)param;
   (void)input;
  if( event->event_index == EVENT_INIT_CFL){
    
    Printf_CFL("filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    Printf_CFL("filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == 200){
    
    Printf_CFL("filter event 1 received doing common action \n");
    Printf_CFL("%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  

if(event->event_index == 201){
    
  Printf_CFL("change state received doing changing column state to 3 \n");
  
  change_local_column_state_CFL(input,3);
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

unsigned yawzejskdj[7];
Watch_dog_struct_CFL_t * ovjlvstoay[7];
unsigned char tteoaqsgxx[7];
unsigned char wcnjkdkwyz[7];
void* iomupzxodz[7];
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

static const Column_ROM_CFL_t yqgetoawou[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 26, 6, -1, -1 },
  { 1,false, 2, 8, 32, -1, -1 },
  { 2,false, 3, 3, 40, -1, -1 },
  { 3,false, 4, 3, 43, -1, -1 },
  { 4,false, 5, 3, 46, -1, -1 },
  { 5,false, 6, 15, 49, 9, 12 },
};


//----------Column elements RAM structures----



static unsigned char kqdbpegrto[64];


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

static const Column_element_CFL_t gajjwwhapd[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&qzocisgrvk},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&ukurfhljbe},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&wsukppjdxm},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wdsihptvuz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cpjaoionch},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hqpfnbmyjx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mwztpauaap_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vbloroklyy},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&enhnupjdcp},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mkxvvywrbr},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nszmplnktz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&byhbvzcluc_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mrgcqnipvc},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dvlikuezpd},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&joirunhjvi},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rpohvcwzmu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sovguspslw_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&alvdzmwawy},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xpdzlbdqjj},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&omamegnrns},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cqguhktrwz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mkzofayahv_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gtzelrkicl},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tqiopxzqyj},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&yhoskmkdrd},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tfjzchkckj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sfbcjjwejo_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cythacjjxe},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vfbfyhsnmj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ynvqukvcyv_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rsqhpqdlzv},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&khhuxsydkp},
    {state_change_CFL,NULL,(void *)&ntfcbabsgt},
    {state_change_CFL,NULL,(void *)&qaksfuaagg},
    {state_change_CFL,NULL,(void *)&rmhbszatvn},
    {state_change_CFL,NULL,(void *)&sxiwzlyfbb},
    {redirect_event_CFL,true_constant_handler,(void *)&nwquqlcdpr},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hqbvtagpwn},
    {SM_debug_CFL,true_constant_handler,(void *)&twmpqadims},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ebmfygpbte},
    {SM_debug_CFL,true_constant_handler,(void *)&rxrucoqhxq},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rqzkyuljgy},
    {SM_debug_CFL,true_constant_handler,(void *)&rgbysfivfu},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ebaotgeisj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&egkemzizzn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&krpaojlkbv_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tliqghopul},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mwnzmguzsi_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hvibitnubn},
    {change_column_state_CFL,NULL,(void *)&epayueghxb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uilarkimhg},
    {filter_event_1,NULL,(void *)&filter_event_data_1},
    {sm_0,NULL,(void *)&sm_0_data},
    {sm_1,NULL,(void *)&sm_1_data},
    {sm_2,NULL,(void *)&sm_2_data},
    {sm_3,NULL,(void *)&sm_3_data},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zdtyhuetbj},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short nvhpsdpdxe[4] = {2,3,4,5,};
short qejayzcshy[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t jytspfafvc[1] = {
{0,1,2,4,qejayzcshy,nvhpsdpdxe,NULL},
}; 
Sm_control_RAM_CFL_t qjfmuoktel[1];


static Time_control_CFL_t rggwwzrtno;




static Engine_control_CFL_t tpsbazyazw;


/* remaining allocate heap size */

static unsigned qrqfkqogfw;


/* current heap pointer */

static char* vxjwgkyhiw;


/* heap block area */

static CS_MEMORY_CONTROL mhlrphmlim;


    
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


const struct Handle_CFL_t mpgkacdbpu =
{

  .queue_number = 6,
  .queue_rom = swncdcmgee,
  .queue_ram = spgueunqbd,

  .column_elements_flags =kqdbpegrto,
  .column_elements_ROM = gajjwwhapd,

  .watch_dog_struct = ovjlvstoay,
  .watch_dog_count  = yawzejskdj,
   
   
  .column_flags = tteoaqsgxx,
  .column_local_data = iomupzxodz,
  .column_state = wcnjkdkwyz,
  .number_of_columns = 7,
  .column_rom_data = yqgetoawou,

  
  
  
  .time_control = &rggwwzrtno,
  .engine_control =&tpsbazyazw,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &qrqfkqogfw,
  .current_heap_location = &vxjwgkyhiw,
  .private_heap   = &mhlrphmlim,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  jytspfafvc,
   .sm_ram     = qjfmuoktel,
} ;


const Handle_CFL_t*  state_machine_5_handle(){
    return &mpgkacdbpu;
}
   

#ifdef __cplusplus
}
#endif

#endif
