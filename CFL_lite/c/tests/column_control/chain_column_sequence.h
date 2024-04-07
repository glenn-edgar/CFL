#ifndef __chain_column_sequence_H__
#define __chain_column_sequence_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



 #define column_event_4 103 


 #define column_event_3 102 


 #define column_event_1 100 


 #define column_event_2 101 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t lznhlcvtzv[7];
static Event_data_CFL_t qjneogynho[7];
static Event_data_CFL_t usklzkbwte[4];
static Event_data_CFL_t ufovgmwsct[0];
static Event_data_CFL_t vobifghtho[0];
static Event_data_CFL_t zdiujlpvjv[0];
static Event_data_CFL_t tbxjplgqsz[0];
static Event_data_CFL_t cvnynbmxyp[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t phdkjcbtuh[] = { 
     {  7, qjneogynho },
     {  4, usklzkbwte },
     {  0, ufovgmwsct },
     {  0, vobifghtho },
     {  0, zdiujlpvjv },
     {  0, tbxjplgqsz },
     {  0, cvnynbmxyp },
};
const Event_data_CFL_t gwviafzvzb = { column_event_1, false, NULL };
const Event_data_CFL_t ladfkfqukl = { column_event_2, false, NULL };
const Event_data_CFL_t mzvwbvovpv = { column_event_3, false, NULL };
const Event_data_CFL_t oksxalqynz = { column_event_4, false, NULL };


unsigned  qmgfffgipr;
const While_time_control_ROM_CFL_t mvdeqpigss = { 12000,&qmgfffgipr };



static While_control_RAM_CFL_t gmfmsngtmc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uiefvnfuno_rom = { 0 ,true, (void*)&mvdeqpigss,&gmfmsngtmc_ram,null_function};

    
static const Log_message_CFL_t pxmnroavlv = { "event generator start", false, NULL };


unsigned  iexipqeagp;
const While_time_control_ROM_CFL_t uibvlugcfs = { 2000,&iexipqeagp };



static While_control_RAM_CFL_t aljicubhse_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sltnkyeism_rom = { 0 ,true, (void*)&uibvlugcfs,&aljicubhse_ram,null_function};

    
static const Log_message_CFL_t fkdbhialog = { "sending events", false, NULL };
const Queue_event_CFL_t zdzpexreoh = { 1, &mzvwbvovpv };
const Queue_event_CFL_t jijefuvcoy = { 1, &oksxalqynz };
const Queue_event_CFL_t nwrwzjkeui = { 1, &gwviafzvzb };
const Queue_event_CFL_t yxctuvegel = { 1, &ladfkfqukl };
static const Log_message_CFL_t xvqsbzjqiy = { "done sending events", false, NULL };
static const unsigned short xgdcmkrqec[] = { 3,4,5};
const Enable_column_CFL_t ayjlzvuggy = { true, 3, xgdcmkrqec };
static const unsigned short zlmpgkzfrg[] = { 3,4,5};
static const int16_t zjfrxxslpv[] = { column_event_1,column_event_2,column_event_4};
const Chain_columns_sequence_CFL_t kpbltiakmk = { 3, zlmpgkzfrg,3, zjfrxxslpv };
static const Log_message_CFL_t epuvaznkfc = { "sequence_column_1", false, NULL };
static unsigned short zkeiyvhztm[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t brimfnltef = { 4, zkeiyvhztm};


unsigned  jupkfmkccd;
const While_time_control_ROM_CFL_t exsyilhrym = { 5000,&jupkfmkccd };



static While_control_RAM_CFL_t utofqcoaje_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zezxufzvyp_rom = { 0 ,true, (void*)&exsyilhrym,&utofqcoaje_ram,null_function};

    
static const Log_message_CFL_t povesvqbkx = { "sequence_column_1 wait done", false, NULL };
static const Log_message_CFL_t jyzmgasicr = { "sequence_column_2", false, NULL };
static unsigned short udbvsvsjbn[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t yrkefyizxu = { 4, udbvsvsjbn};


unsigned  kzqwqknhjx;
const While_time_control_ROM_CFL_t kednniojwa = { 5500,&kzqwqknhjx };



static While_control_RAM_CFL_t guqzqtcixb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sipvhmafzc_rom = { 0 ,true, (void*)&kednniojwa,&guqzqtcixb_ram,null_function};

    
static const Log_message_CFL_t mtvicuffja = { "sequence_column_2 wait done", false, NULL };
static const Log_message_CFL_t lynjjsjxwt = { "sequence_column_3", false, NULL };
static unsigned short uzxnptkoqn[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t lrwyosksxk = { 4, uzxnptkoqn};


unsigned  zaebfvnfmp;
const While_time_control_ROM_CFL_t htswmcugze = { 5700,&zaebfvnfmp };



static While_control_RAM_CFL_t nadwuxklvg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t gklmpdeyyo_rom = { 0 ,true, (void*)&htswmcugze,&nadwuxklvg_ram,null_function};

    
static const Log_message_CFL_t amzczseoft = { "sequence_column_3 wait done", false, NULL };


//----------RAM data structures for columns ----

unsigned zyhjrrrnkt[6];
Watch_dog_struct_CFL_t * kgwlfatmkp[6];
unsigned char vwvhzeulzi[6];
unsigned char mhskfezspy[6];
void* obssithbcp[6];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t yxxgbikomp[] = {
  { 1,true, 0, 3, 11, -1, -1,NULL },
  { 2,true, 1, 2, 0, -1, -1,NULL },
  { 3,true, 2, 9, 2, -1, -1,NULL },
  { 4,false, 3, 5, 14, -1, -1,NULL },
  { 5,false, 4, 5, 19, -1, -1,NULL },
  { 6,false, 5, 5, 24, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char nvimtczwve[29];


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

static const Column_element_CFL_t kkowqlxrch[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uiefvnfuno_rom}, // 0 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&pxmnroavlv}, // 2 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sltnkyeism_rom}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&fkdbhialog}, // 4 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&zdzpexreoh}, // 5 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&jijefuvcoy}, // 6 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&nwrwzjkeui}, // 7 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&yxctuvegel}, // 8 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xvqsbzjqiy}, // 9 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 10 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&ayjlzvuggy}, // 11 
    {chain_columns_sequence_CFL,NULL,(void *)&kpbltiakmk}, // 12 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 13 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&epuvaznkfc}, // 14 
    {display_event_CFL,NULL,(void *)&brimfnltef}, // 15 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zezxufzvyp_rom}, // 16 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&povesvqbkx}, // 17 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 18 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&jyzmgasicr}, // 19 
    {display_event_CFL,NULL,(void *)&yrkefyizxu}, // 20 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sipvhmafzc_rom}, // 21 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&mtvicuffja}, // 22 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 23 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&lynjjsjxwt}, // 24 
    {display_event_CFL,NULL,(void *)&lrwyosksxk}, // 25 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&gklmpdeyyo_rom}, // 26 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&amzczseoft}, // 27 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 28 
};
Bitmap_CFL rvryfizyhm[0];
Registermap_CFL_t bebwoufraz[0];
Floatmap_CFL_t hfuhwbwcof[0];
const Sm_control_ROM_CFL_t kerjgdyijn[0];
Sm_control_RAM_CFL_t czgljdlmjh[0];


static Time_control_CFL_t aqvbyquloa;




static Engine_control_CFL_t ucquqnbwhn;


/* remaining allocate heap size */

static unsigned lnnophqevo;


/* current heap pointer */

static char* jsiywudamm;


/* heap block area */

static CS_MEMORY_CONTROL zsmfjkvpqp;


    
    


const struct Handle_CFL_t giperlgaww =
{

  .queue_number = 7,
  .queue_rom = phdkjcbtuh,
  .queue_ram = lznhlcvtzv,

  .column_elements_flags =nvimtczwve,
  .column_elements_ROM = kkowqlxrch,

  .watch_dog_struct = kgwlfatmkp,
  .watch_dog_count  = zyhjrrrnkt,
   
   
  .column_flags = vwvhzeulzi,
  .column_local_data = obssithbcp,
  .column_state = mhskfezspy,
  .number_of_columns = 6,
  .column_rom_data = yxxgbikomp,

  
  
  
  .time_control = &aqvbyquloa,
  .engine_control =&ucquqnbwhn,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &lnnophqevo,
  .current_heap_location = &jsiywudamm,
  .private_heap   = &zsmfjkvpqp,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  kerjgdyijn,
  .sm_ram     = czgljdlmjh,
  .number_of_bitmaps = 0,
  .bitmaps = rvryfizyhm,
  .number_of_registermaps = 0,
  .registermaps = bebwoufraz,
  .number_of_floatmaps = 0,
  .floatmaps = hfuhwbwcof,
} ;

const Handle_CFL_t*  chain_column_sequence_handle(){
    return &giperlgaww;
}
   

#ifdef __cplusplus
}
#endif

#endif
