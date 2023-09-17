#ifndef __state_machine_3_H__
#define __state_machine_3_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t lcaypwtosg[6];
static Event_data_CFL_t atusvraikq[10];
static Event_data_CFL_t cleugxoqxm[10];
static Event_data_CFL_t ontedyyahl[10];
static Event_data_CFL_t akmvpowerq[10];
static Event_data_CFL_t xevwnacjtz[10];
static Event_data_CFL_t jyfagnzucz[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hcdsbrmkfw[] = { 
     {  10, atusvraikq },
     {  10, cleugxoqxm },
     {  10, ontedyyahl },
     {  10, akmvpowerq },
     {  10, xevwnacjtz },
     {  10, jyfagnzucz },
};
const Event_data_CFL_t kbxbcutidh = { 101, false, NULL };
const Event_data_CFL_t wojpbvdeax = { 102, false, NULL };
const Event_data_CFL_t lvgpdmkfbz = { 103, false, NULL };
const Event_data_CFL_t jvsfviddqf = { 104, false, NULL };
const Event_data_CFL_t txqpnspkwn = { 111, false, NULL };
const Event_data_CFL_t oglydvetkt = { 112, false, NULL };
const Event_data_CFL_t ozlmljrcot = { 113, false, NULL };
#define state_1_event 101
unsigned short test_counter = 0;
const condition_state_change_t bool_state_change = {state_1_event,3,&test_counter};


const char test_data_12[] = "state 1 debug message";
const char test_data_22[] = "state 2 debug message";
const char test_data_32[] = "state 3 debug message";
const char test_data_42[] = "state 4 debug message";
static const char *anwvmvdhcc = "start column";

const unsigned short  iunswcvnst[] = {0};

enable_disable_sm_CFL_t fqcluuemet = {1,iunswcvnst };
static const unsigned short hxatcypcnb[] = { 1};
const Enable_column_CFL_t feqmqqrgya = { true, 1, hxatcypcnb };


unsigned  mgvdjazllh;
const While_time_control_ROM_CFL_t jaipobywvv = { 60000,&mgvdjazllh };



static While_control_RAM_CFL_t lfkwdiecwz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dzastnlzpa_rom = { 0 ,true, &jaipobywvv,&lfkwdiecwz_ram,null_function};

    
static const char *hadzmawtjw = "terminating";
static const char *wjiyxxshss = "event generator start";


unsigned  hgxpmdkpiu;
const While_time_control_ROM_CFL_t ptfvtctitf = { 1000,&hgxpmdkpiu };



static While_control_RAM_CFL_t hrasfinlev_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t irjjwmagxk_rom = { 0 ,true, &ptfvtctitf,&hrasfinlev_ram,null_function};

    
const sm_event_CFL_t mwwllmwngl = {0,&txqpnspkwn};
const sm_event_CFL_t ziyqbulbpx = {0,&oglydvetkt};
const sm_event_CFL_t anifjgibdk = {0,&ozlmljrcot};
const sm_event_CFL_t hdxlflyrlf = {0,&wojpbvdeax};


unsigned  trtfvhapwm;
const While_time_control_ROM_CFL_t dnzktrogak = { 1000,&trtfvhapwm };



static While_control_RAM_CFL_t pkuwkdudrf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bolranrfhi_rom = { 0 ,true, &dnzktrogak,&pkuwkdudrf_ram,null_function};

    
const sm_event_CFL_t xggcqiaqkq = {0,&txqpnspkwn};
const sm_event_CFL_t gftlybqatr = {0,&oglydvetkt};
const sm_event_CFL_t cwbxkyegub = {0,&ozlmljrcot};
const sm_event_CFL_t pltqueuxns = {0,&lvgpdmkfbz};


unsigned  tzxxnqxkes;
const While_time_control_ROM_CFL_t epodjdoglb = { 1000,&tzxxnqxkes };



static While_control_RAM_CFL_t qkvhwmqzqb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pjobkpdmsi_rom = { 0 ,true, &epodjdoglb,&qkvhwmqzqb_ram,null_function};

    
const sm_event_CFL_t tletjzeegw = {0,&txqpnspkwn};
const sm_event_CFL_t qrypqzdwdv = {0,&oglydvetkt};
const sm_event_CFL_t aelnkxgbhx = {0,&ozlmljrcot};
const sm_event_CFL_t spxkkwmzhx = {0,&jvsfviddqf};


unsigned  ynmiiiixsq;
const While_time_control_ROM_CFL_t tctsoazlzs = { 1000,&ynmiiiixsq };



static While_control_RAM_CFL_t jvvvojvnbl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t khhsvckxxq_rom = { 0 ,true, &tctsoazlzs,&jvvvojvnbl_ram,null_function};

    
const sm_event_CFL_t trknurmmak = {0,&txqpnspkwn};
const sm_event_CFL_t vnhchogvsz = {0,&oglydvetkt};
const sm_event_CFL_t kfepewznaq = {0,&ozlmljrcot};
const sm_event_CFL_t dzjjsnzvbr = {0,&kbxbcutidh};
static const char *ddxvjrigxe = "state machine manager starting";
const change_sm_state_CFL_t bssnxjmgdt = {0,0};
const redirect_CFL_t xqotqsfgjx = {0,NULL};
static const char *wmtfeboceg = "state 1 starting";
const unsigned short yzrmqqdkxa[] = {102};
const state_change_CFL_t ghqsunyvcf = {0,1,1,yzrmqqdkxa};
const SM_debug_CFL_t mfrjtenxid = {0,0,test_data_12};
static const char *uanmvkarwn = "state 2 starting";
const unsigned short foxcuqsiym[] = {103};
const state_change_CFL_t dgldndycrj = {0,2,1,foxcuqsiym};
const SM_debug_CFL_t zwsabejsxc = {0,1,test_data_22};
static const char *hojxceyffc = "state 3 starting";
const SM_debug_CFL_t xpaqzhbcpb = {0,2,test_data_32};
const unsigned short wzrrntsiig[] = {104};
const state_change_CFL_t ialaklkbzx = {0,3,1,wzrrntsiig};
static const char *nidesdauql = "state 4 starting";
const conditional_state_change_CFL_t moaoqavxkz = {0,0,(void *)&bool_state_change};
const SM_debug_CFL_t nzgzfgaxfd = {0,3,test_data_42};


//----------RAM data structures for columns ----

unsigned udtszxiccn[7];
Watch_dog_struct_CFL_t * drdxgpmagq[7];
unsigned char ubuzekaglv[7];
unsigned char nzzffwtyfq[7];
void* mzvhimoaqe[7];
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

static const Column_ROM_CFL_t wlefsarqew[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 22, 6, -1, -1 },
  { 1,false, 2, 4, 28, -1, -1 },
  { 2,false, 3, 4, 32, -1, -1 },
  { 3,false, 4, 4, 36, -1, -1 },
  { 4,false, 5, 4, 40, -1, -1 },
  { 5,false, 6, 4, 44, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char rukoauvgcv[48];


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

static const Column_element_CFL_t ncccbclppw[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&anwvmvdhcc},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&fqcluuemet},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&feqmqqrgya},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dzastnlzpa_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hadzmawtjw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wjiyxxshss},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&irjjwmagxk_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mwwllmwngl},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ziyqbulbpx},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&anifjgibdk},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hdxlflyrlf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bolranrfhi_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xggcqiaqkq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gftlybqatr},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cwbxkyegub},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pltqueuxns},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pjobkpdmsi_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tletjzeegw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qrypqzdwdv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&aelnkxgbhx},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&spxkkwmzhx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&khhsvckxxq_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&trknurmmak},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vnhchogvsz},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kfepewznaq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dzjjsnzvbr},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ddxvjrigxe},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&bssnxjmgdt},
    {redirect_event_CFL,true_constant_handler,(void *)&xqotqsfgjx},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wmtfeboceg},
    {state_change_CFL,NULL,(void *)&ghqsunyvcf},
    {SM_debug_CFL,true_constant_handler,(void *)&mfrjtenxid},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uanmvkarwn},
    {state_change_CFL,NULL,(void *)&dgldndycrj},
    {SM_debug_CFL,true_constant_handler,(void *)&zwsabejsxc},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hojxceyffc},
    {SM_debug_CFL,true_constant_handler,(void *)&xpaqzhbcpb},
    {state_change_CFL,NULL,(void *)&ialaklkbzx},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nidesdauql},
    {conditional_state_change_CFL,conditional_state_change,(void *)&moaoqavxkz},
    {SM_debug_CFL,conditional_state_change,(void *)&nzgzfgaxfd},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short iinyowzkhv[4] = {2,3,4,5,};
short eobfbwjazd[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t fkxaguumow[1] = {
{0,1,2,4,eobfbwjazd,iinyowzkhv,NULL},
}; 
Sm_control_RAM_CFL_t indmgimuzu[1];


static Time_control_CFL_t wldlassfuc;




static Engine_control_CFL_t whavgejwsh;


/* remaining allocate heap size */

static unsigned qoradekdcn;


/* current heap pointer */

static char* gsyvgksyvz;


/* heap block area */

static CS_MEMORY_CONTROL doiwlcdlwa;


    
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


const struct Handle_CFL_t qxiugnweni =
{

  .queue_number = 6,
  .queue_rom = hcdsbrmkfw,
  .queue_ram = lcaypwtosg,

  .column_elements_flags =rukoauvgcv,
  .column_elements_ROM = ncccbclppw,

  .watch_dog_struct = drdxgpmagq,
  .watch_dog_count  = udtszxiccn,
   
   
  .column_flags = ubuzekaglv,
  .column_local_data = mzvhimoaqe,
  .column_state = nzzffwtyfq,
  .number_of_columns = 7,
  .column_rom_data = wlefsarqew,

  
  
  
  .time_control = &wldlassfuc,
  .engine_control =&whavgejwsh,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &qoradekdcn,
  .current_heap_location = &gsyvgksyvz,
  .private_heap   = &doiwlcdlwa,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  fkxaguumow,
   .sm_ram     = indmgimuzu,
} ;


const Handle_CFL_t*  state_machine_3_handle(){
    return &qxiugnweni;
}
   

#ifdef __cplusplus
}
#endif

#endif
