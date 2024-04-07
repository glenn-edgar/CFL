#ifndef __column_state_machine_H__
#define __column_state_machine_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define filter_event 100 


 #define state_change_event 101 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t ktdwlimrxq[7];
static Event_data_CFL_t xexkqefdzc[7];
static Event_data_CFL_t aecqllzpie[0];
static Event_data_CFL_t amshgwisnc[0];
static Event_data_CFL_t gnyabjostz[0];
static Event_data_CFL_t sxoyoingmn[0];
static Event_data_CFL_t rgxoinjyrl[0];
static Event_data_CFL_t pxrmxgbpbm[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hgzcwcyqhd[] = { 
     {  7, xexkqefdzc },
     {  0, aecqllzpie },
     {  0, amshgwisnc },
     {  0, gnyabjostz },
     {  0, sxoyoingmn },
     {  0, rgxoinjyrl },
     {  0, pxrmxgbpbm },
};
const Event_data_CFL_t ujqtuidpas = { filter_event, false, NULL };
const Event_data_CFL_t jvojsfpcjr = { state_change_event, false, NULL };
static const char *rkmurjprss = "test_start";
static const char *fjfucqnylt = "step 0";
static const char *kvmrcitciu = "step 1";
static const char *kcqyydopci = "step 2";
static const char *hlfdojhbxs = "step 3";
unsigned short pvgdoiuwkl = 0;
static const char *heinitvofb = "test_start";
static const char *xkhcjeehqc = "step 6";
static const char *yxqgmbryqh = "step 7";
static const char *aiayumlopl = "step 8";
static const char *ikfmoqzide = "step 9";
static const char *ngyfobipel = "step 10";
static const char *djvrllqmrg = "test_end";
static const char *crmkmoupph = "step 0";
static const char *xvmbsfxcpd = "step 1";
static const char *ezcpqztfrq = "step 2";
static const char *ynohtxwmhw = "step 3";
unsigned short jrxdyoibgz = 5;
static const char *hiirjlsyll = "step 5";
static const char *kktnxwnwow = "step 6";
static const char *oqhmvcgtpk = "step 7";
static const char *odlqztgoqx = "step 8";
static const char *dqgizpqebo = "step 9";
static const char *qwyoswxkdj = "test_end";
static const char *dibkgwmtzu = "test_middle";
static const char *nvwolqpbpc = "step 0";
static const char *vewtsdhpbz = "step 1";
static const char *cvzcmvcklq = "step 2";
static const char *ojgmfukpry = "step 3";
unsigned short lyjbzjkiuz = 3;
static const char *vokoczynts = "step 5";
static const char *spckpxbfae = "step 6";
static const char *mwyrgtaepb = "step 7";
static const char *mtwfjrwrjp = "test_middle";
static const char *xtmxulntqp = "step 9";
static const char *uqqxnbgivs = "step 10";


unsigned  zksujlchii;
const While_time_control_ROM_CFL_t ykuzfgfgka = { 120000,&zksujlchii };



static While_control_RAM_CFL_t zjxsdmqxvo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jtyvjyxkmi_rom = { 0 ,true, (void*)&ykuzfgfgka,&zjxsdmqxvo_ram,null_function};

    
static const char *dmrakcrnca = "event generator start";


unsigned  eybmnhlaki;
const While_time_control_ROM_CFL_t jnejirepxd = { 30000,&eybmnhlaki };



static While_control_RAM_CFL_t kaviyiwhbl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lwytmqviet_rom = { 0 ,true, (void*)&jnejirepxd,&kaviyiwhbl_ram,null_function};

    
static const char *gzjcfcguyh = "executing a sequence of actions first";
static const char *krtlapizzi = "action 1";


unsigned  bqvpozdqvp;
const While_time_control_ROM_CFL_t nbduoizrfa = { 1000,&bqvpozdqvp };



static While_control_RAM_CFL_t kwjbznayql_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t baalfmklhv_rom = { 0 ,true, (void*)&nbduoizrfa,&kwjbznayql_ram,null_function};

    
static const char *mcxuxeudih = "action 2";


unsigned  sdougbbvkl;
const While_time_control_ROM_CFL_t ktiogptfva = { 1000,&sdougbbvkl };



static While_control_RAM_CFL_t kwhyjzywwk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ashtyohiez_rom = { 0 ,true, (void*)&ktiogptfva,&kwhyjzywwk_ram,null_function};

    
static const char *rtypxqrjgd = "action 3";
unsigned short vymuczfmkm = 0;
static const char *gqnuechwaj = "state machines are active at this point";

static const char filter_event_data_1[] = "filter_event_data_1";



static int filter_event_1(const void *input,void *aux_fn,void *param,Event_data_CFL_t *event)
{
   (void)aux_fn;
   (void)param;
  if( event->event_index == EVENT_INIT_CFL){
    
    Printf_CFL(input,"filter_event_1 initialization event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    Printf_CFL(input,"filter_event_1 termination event \n");
    return CONTINUE_CFL;
  
  }
  if( event->event_index == filter_event){
    
    Printf_CFL(input,"filter event 1 received doing common action \n");
    Printf_CFL(input,"%s\n",filter_event_data_1);
    return HALT_CFL;
  
  }
  if(event->event_index == state_change_event){
    
    Printf_CFL(input,"state change event received doing changing column state to 3 \n");
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
    Printf_CFL(input,"sm_0 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    Printf_CFL(input,"second tics received \n");
    *count = *count + 1;
   
    if(*count >=  5){
      *count = 0;
      change_local_column_state_CFL(input, 1);
       return CONTINUE_CFL;
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
    Printf_CFL(input,"sm_1 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    Printf_CFL(input,"second tics received \n");
    *count = *count + 1;
   
    if(*count >=  5){
      *count = 0;
      change_local_column_state_CFL(input, 2);
       return CONTINUE_CFL;
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
    Printf_CFL(input,"sm_2 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    Printf_CFL(input,"second tics received \n");
    *count = *count + 1;
   
    if(*count >=  5){
      *count = 0;
      change_local_column_state_CFL(input, 3);
       return CONTINUE_CFL;
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
    Printf_CFL(input,"sm_3 initialization event \n");
    *count = 0;
    return CONTINUE_CFL;
  
  }
  if( event->event_index == EVENT_TERMINATION_CFL){
    
    ; // do nothing
    return CONTINUE_CFL;
  
  }
  if( event->event_index == SECOND_TICK_CFL){
    
    Printf_CFL(input,"second tics received \n");
    *count = *count + 1;
   
    if(*count >=  5){
      *count = 0;
      change_local_column_state_CFL(input, 0);
       return CONTINUE_CFL;
    }
    return CONTINUE_CFL;
  
  }
  
  return CONTINUE_CFL;
}



//----------RAM data structures for columns ----

unsigned hkdsgwfgaq[6];
Watch_dog_struct_CFL_t * icsfgjixgu[6];
unsigned char uwesdpwunm[6];
unsigned char narpdwwgno[6];
void* utoqqmaujm[6];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t bbwldakpuo[] = {
  { 1,true, 0, 12, 0, 6, 11,NULL },
  { 2,true, 1, 12, 24, 6, 11,NULL },
  { 3,true, 2, 12, 12, 6, 11,NULL },
  { 4,true, 3, 2, 36, -1, -1,NULL },
  { 5,true, 4, 5, 38, -1, -1,NULL },
  { 6,true, 5, 14, 43, 9, 12,NULL },
};


//----------Column elements RAM structures----



static unsigned char zyfecyscjq[57];


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

static const Column_element_CFL_t kiaerrenkb[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&rkmurjprss},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fjfucqnylt},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kvmrcitciu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kcqyydopci},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hlfdojhbxs},
    {change_column_state_CFL,NULL,(void *)&pvgdoiuwkl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&heinitvofb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xkhcjeehqc},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yxqgmbryqh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aiayumlopl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ikfmoqzide},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ngyfobipel},
    {one_shot_handler_CFL,log_message_CFL,(void *)&djvrllqmrg},
    {one_shot_handler_CFL,log_message_CFL,(void *)&crmkmoupph},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xvmbsfxcpd},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ezcpqztfrq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ynohtxwmhw},
    {change_column_state_CFL,NULL,(void *)&jrxdyoibgz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hiirjlsyll},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kktnxwnwow},
    {one_shot_handler_CFL,log_message_CFL,(void *)&oqhmvcgtpk},
    {one_shot_handler_CFL,log_message_CFL,(void *)&odlqztgoqx},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dqgizpqebo},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qwyoswxkdj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dibkgwmtzu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nvwolqpbpc},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vewtsdhpbz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cvzcmvcklq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ojgmfukpry},
    {change_column_state_CFL,NULL,(void *)&lyjbzjkiuz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vokoczynts},
    {one_shot_handler_CFL,log_message_CFL,(void *)&spckpxbfae},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mwyrgtaepb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mtwfjrwrjp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xtmxulntqp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uqqxnbgivs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jtyvjyxkmi_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dmrakcrnca},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lwytmqviet_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&ujqtuidpas},
    {one_shot_handler_CFL,send_event_CFL,(void *)&jvojsfpcjr},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gzjcfcguyh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&krtlapizzi},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&baalfmklhv_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mcxuxeudih},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ashtyohiez_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rtypxqrjgd},
    {change_column_state_CFL,NULL,(void *)&vymuczfmkm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gqnuechwaj},
    {filter_event_1,NULL,(void *)&filter_event_data_1},
    {sm_0,NULL,(void *)&sm_0_data},
    {sm_1,NULL,(void *)&sm_1_data},
    {sm_2,NULL,(void *)&sm_2_data},
    {sm_3,NULL,(void *)&sm_3_data},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
Bitmap_CFL zhfstedrmx[0];
Registermap_CFL_t pfdksqhcly[0];
Floatmap_CFL_t xmvdifqoit[0];
const Sm_control_ROM_CFL_t xxqjdxwmqo[0];
Sm_control_RAM_CFL_t nrabnqqelz[0];


static Time_control_CFL_t olwetezhev;




static Engine_control_CFL_t obyirdzvtu;


/* remaining allocate heap size */

static unsigned gayhiokeni;


/* current heap pointer */

static char* hvwzdudypi;


/* heap block area */

static CS_MEMORY_CONTROL juqruzctrv;


    
    


const struct Handle_CFL_t arpmewpydp =
{

  .queue_number = 7,
  .queue_rom = hgzcwcyqhd,
  .queue_ram = ktdwlimrxq,

  .column_elements_flags =zyfecyscjq,
  .column_elements_ROM = kiaerrenkb,

  .watch_dog_struct = icsfgjixgu,
  .watch_dog_count  = hkdsgwfgaq,
   
   
  .column_flags = uwesdpwunm,
  .column_local_data = utoqqmaujm,
  .column_state = narpdwwgno,
  .number_of_columns = 6,
  .column_rom_data = bbwldakpuo,

  
  
  
  .time_control = &olwetezhev,
  .engine_control =&obyirdzvtu,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &gayhiokeni,
  .current_heap_location = &hvwzdudypi,
  .private_heap   = &juqruzctrv,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  xxqjdxwmqo,
  .sm_ram     = nrabnqqelz,
  .number_of_bitmaps = 0,
  .bitmaps = zhfstedrmx,
  .number_of_registermaps = 0,
  .registermaps = pfdksqhcly,
  .number_of_floatmaps = 0,
  .floatmaps = xmvdifqoit,
} ;

const Handle_CFL_t*  column_state_machine_handle(){
    return &arpmewpydp;
}
   

#ifdef __cplusplus
}
#endif

#endif
