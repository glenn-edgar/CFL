#ifndef __state_machine_2_H__
#define __state_machine_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t qjvcafqhtk[6];
static Event_data_CFL_t ibhjmklujp[10];
static Event_data_CFL_t mmyunkvnnc[10];
static Event_data_CFL_t aijwudicbd[10];
static Event_data_CFL_t injdlpacws[10];
static Event_data_CFL_t dmirptxvwf[10];
static Event_data_CFL_t ehjvxzytxb[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t xxfhnmhxab[] = { 
     {  10, ibhjmklujp },
     {  10, mmyunkvnnc },
     {  10, aijwudicbd },
     {  10, injdlpacws },
     {  10, dmirptxvwf },
     {  10, ehjvxzytxb },
};
const char test_data_2[] = "test_data\n";
const Event_data_CFL_t fkbeglotls = { 101, false, NULL };
const Event_data_CFL_t wmszdhffdx = { 102, false, NULL };
const Event_data_CFL_t icbdsdcwpe = { 103, false, NULL };
const Event_data_CFL_t dprtrtpwek = { 104, false, NULL };
const Event_data_CFL_t qitjvfuwlr = { 111, false, NULL };
const Event_data_CFL_t rugqfnbych = { 112, false, NULL };
const Event_data_CFL_t fkywdkpxbf = { 113, false, NULL };

const char test_data_11[] = "state 1 debug message";
const char test_data_21[] = "state 2 debug message";
const char test_data_31[] = "state 3 debug message";
const char test_data_41[] = "state 4 debug message";
static const char *fsylpxmaev = "start column";

const unsigned short  qnfqatkvqw[] = {0};

enable_disable_sm_CFL_t yrthgsirlf = {1,qnfqatkvqw };
static const unsigned short adgedpvjzh[] = { 1};
const Enable_column_CFL_t pchxmaggbw = { true, 1, adgedpvjzh };


unsigned  rtkjggmdxs;
const While_time_control_ROM_CFL_t hnarxwwixu = { 60000,&rtkjggmdxs };



static While_control_RAM_CFL_t jvuehefqdz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t aqmwejxopc_rom = { 0 ,true, &hnarxwwixu,&jvuehefqdz_ram,null_function};

    
static const char *nlhnnsjvtq = "terminating";
static const char *wrghgvrjpj = "event generator start";


unsigned  nomwrqzzzp;
const While_time_control_ROM_CFL_t olgopjwjhh = { 2000,&nomwrqzzzp };



static While_control_RAM_CFL_t fvznrkyffo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t epjfnfbvmu_rom = { 0 ,true, &olgopjwjhh,&fvznrkyffo_ram,null_function};

    
const sm_event_CFL_t rdccmqrsbj = {0,&qitjvfuwlr};
const sm_event_CFL_t dlvfffncbr = {0,&rugqfnbych};
const sm_event_CFL_t syoalybvhg = {0,&fkywdkpxbf};
const sm_event_CFL_t nupmuyzdhj = {0,&fkbeglotls};


unsigned  vvuyebgtfh;
const While_time_control_ROM_CFL_t xffxuukvrx = { 2000,&vvuyebgtfh };



static While_control_RAM_CFL_t biutbbpmcc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cyniewuttf_rom = { 0 ,true, &xffxuukvrx,&biutbbpmcc_ram,null_function};

    
const sm_event_CFL_t rhkfeypzug = {0,&qitjvfuwlr};
const sm_event_CFL_t vidszpeilr = {0,&rugqfnbych};
const sm_event_CFL_t vrxnkgsdzk = {0,&fkywdkpxbf};
const sm_event_CFL_t xpweiulnld = {0,&wmszdhffdx};


unsigned  bufmigetih;
const While_time_control_ROM_CFL_t ejoxwywqfa = { 2000,&bufmigetih };



static While_control_RAM_CFL_t itgmirssqi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t skugamtqvu_rom = { 0 ,true, &ejoxwywqfa,&itgmirssqi_ram,null_function};

    
const sm_event_CFL_t sgnahngvpf = {0,&qitjvfuwlr};
const sm_event_CFL_t qhwyuftvkv = {0,&rugqfnbych};
const sm_event_CFL_t ywdxeurwyg = {0,&fkywdkpxbf};
const sm_event_CFL_t ructufcbgw = {0,&icbdsdcwpe};


unsigned  ngjkiuusff;
const While_time_control_ROM_CFL_t epovjsucfp = { 2000,&ngjkiuusff };



static While_control_RAM_CFL_t ubetubzyca_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ooyknijdjj_rom = { 0 ,true, &epovjsucfp,&ubetubzyca_ram,null_function};

    
const sm_event_CFL_t zgjtqiwfyk = {0,&qitjvfuwlr};
const sm_event_CFL_t vudhidlydb = {0,&rugqfnbych};
const sm_event_CFL_t ixbghiptlx = {0,&fkywdkpxbf};
const sm_event_CFL_t kufaynevaa = {0,&dprtrtpwek};
static const char *yjfglnkeyh = "state machine manager starting";
const change_sm_state_CFL_t xkvxqfwhny = {0,0};
const unsigned short bvsppsuzyx[] = {101};
const state_change_CFL_t nwihbvvwqo = {0,0,1,bvsppsuzyx};
const unsigned short yjjtnakxat[] = {102};
const state_change_CFL_t hjmaidzzsh = {0,1,1,yjjtnakxat};
const unsigned short tpayxkdxdr[] = {103};
const state_change_CFL_t fypdpksbov = {0,2,1,tpayxkdxdr};
const unsigned short eaivivngtf[] = {104};
const state_change_CFL_t bicnfwmjvh = {0,3,1,eaivivngtf};
const redirect_CFL_t drwurrfxqr = {0,NULL};
static const char *picuevbwqt = "state 1 starting";
const SM_debug_CFL_t lcpukmgbtg = {0,0,test_data_11};
static const char *smwqtyiazt = "state 2 starting";
const SM_debug_CFL_t hhmncfupjx = {0,1,test_data_21};
static const char *tsrbbdmgid = "state 3 starting";
const SM_debug_CFL_t xuavardfje = {0,2,test_data_31};
static const char *siqgywsiya = "state 4 starting";
const SM_debug_CFL_t tsxipvknld = {0,3,test_data_41};


//----------RAM data structures for columns ----

unsigned jwvhjfdhid[7];
Watch_dog_struct_CFL_t * tamymquqjk[7];
unsigned char zvruutupeb[7];
unsigned char ehagghzldu[7];
void* gopjnochvs[7];
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

static const Column_ROM_CFL_t wkhltcqjki[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 22, 6, -1, -1 },
  { 1,false, 2, 8, 28, -1, -1 },
  { 2,false, 3, 3, 36, -1, -1 },
  { 3,false, 4, 3, 39, -1, -1 },
  { 4,false, 5, 3, 42, -1, -1 },
  { 5,false, 6, 3, 45, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char ovcdvmdurq[48];


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

static const Column_element_CFL_t wtjuymwtww[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&fsylpxmaev},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&yrthgsirlf},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&pchxmaggbw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&aqmwejxopc_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nlhnnsjvtq},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wrghgvrjpj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&epjfnfbvmu_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rdccmqrsbj},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dlvfffncbr},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&syoalybvhg},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nupmuyzdhj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cyniewuttf_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rhkfeypzug},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vidszpeilr},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vrxnkgsdzk},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xpweiulnld},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&skugamtqvu_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&sgnahngvpf},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qhwyuftvkv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ywdxeurwyg},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ructufcbgw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ooyknijdjj_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&zgjtqiwfyk},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vudhidlydb},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ixbghiptlx},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kufaynevaa},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yjfglnkeyh},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&xkvxqfwhny},
    {state_change_CFL,NULL,(void *)&nwihbvvwqo},
    {state_change_CFL,NULL,(void *)&hjmaidzzsh},
    {state_change_CFL,NULL,(void *)&fypdpksbov},
    {state_change_CFL,NULL,(void *)&bicnfwmjvh},
    {redirect_event_CFL,true_constant_handler,(void *)&drwurrfxqr},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&picuevbwqt},
    {SM_debug_CFL,true_constant_handler,(void *)&lcpukmgbtg},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&smwqtyiazt},
    {SM_debug_CFL,true_constant_handler,(void *)&hhmncfupjx},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tsrbbdmgid},
    {SM_debug_CFL,true_constant_handler,(void *)&xuavardfje},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&siqgywsiya},
    {SM_debug_CFL,true_constant_handler,(void *)&tsxipvknld},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short bwnojksnlx[4] = {2,3,4,5,};
short puuvqsaxuq[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t xfujlzkkoj[1] = {
{0,1,2,4,puuvqsaxuq,bwnojksnlx,(void *)test_data_2},
}; 
Sm_control_RAM_CFL_t npdrkxwgxy[1];


static Time_control_CFL_t tlyewvgkru;




static Engine_control_CFL_t hnbitcrjhs;


/* remaining allocate heap size */

static unsigned fsxnooihcn;


/* current heap pointer */

static char* owdhtyulrn;


/* heap block area */

static CS_MEMORY_CONTROL pajbxxuvyr;


    
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


const struct Handle_CFL_t ttfxqeuyeg =
{

  .queue_number = 6,
  .queue_rom = xxfhnmhxab,
  .queue_ram = qjvcafqhtk,

  .column_elements_flags =ovcdvmdurq,
  .column_elements_ROM = wtjuymwtww,

  .watch_dog_struct = tamymquqjk,
  .watch_dog_count  = jwvhjfdhid,
   
   
  .column_flags = zvruutupeb,
  .column_local_data = gopjnochvs,
  .column_state = ehagghzldu,
  .number_of_columns = 7,
  .column_rom_data = wkhltcqjki,

  
  
  
  .time_control = &tlyewvgkru,
  .engine_control =&hnbitcrjhs,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &fsxnooihcn,
  .current_heap_location = &owdhtyulrn,
  .private_heap   = &pajbxxuvyr,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  xfujlzkkoj,
   .sm_ram     = npdrkxwgxy,
} ;


const Handle_CFL_t*  state_machine_2_handle(){
    return &ttfxqeuyeg;
}
   

#ifdef __cplusplus
}
#endif

#endif
