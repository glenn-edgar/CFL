#ifndef __state_machine_3_H__
#define __state_machine_3_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t hxngdiyzwk[6];
static Event_data_CFL_t wismdffvzv[10];
static Event_data_CFL_t jzrscaqjip[10];
static Event_data_CFL_t arlqtwqvnq[10];
static Event_data_CFL_t damktkwnkm[10];
static Event_data_CFL_t byajwecxpy[10];
static Event_data_CFL_t qnhbpnqspl[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t olahcgcizm[] = { 
     {  10, wismdffvzv },
     {  10, jzrscaqjip },
     {  10, arlqtwqvnq },
     {  10, damktkwnkm },
     {  10, byajwecxpy },
     {  10, qnhbpnqspl },
};
const Event_data_CFL_t utssnyvpbf = { 101, false, NULL };
const Event_data_CFL_t qgqeucmjbh = { 102, false, NULL };
const Event_data_CFL_t yjeffllvkt = { 103, false, NULL };
const Event_data_CFL_t lmaorlkaoo = { 104, false, NULL };
const Event_data_CFL_t yyqhimrznx = { 111, false, NULL };
const Event_data_CFL_t mpgksushnh = { 112, false, NULL };
const Event_data_CFL_t qwabhjaifa = { 113, false, NULL };
#define state_1_event 101
unsigned short test_counter = 0;
const condition_state_change_t bool_state_change = {state_1_event,3,&test_counter};


const char test_data_12[] = "state 1 debug message";
const char test_data_22[] = "state 2 debug message";
const char test_data_32[] = "state 3 debug message";
const char test_data_42[] = "state 4 debug message";
static const char *aljnkjghsd = "start column";

const unsigned short  ojggwlffeb[] = {0};

enable_disable_sm_CFL_t jcqbmfqhoi = {1,ojggwlffeb };
static const unsigned short jlrqevrroi[] = { 1};
const Enable_column_CFL_t gvrsgnfgph = { true, 1, jlrqevrroi };


unsigned  freigmvbev;
const While_time_control_ROM_CFL_t tykfcoidpb = { 60000,&freigmvbev };



static While_control_RAM_CFL_t sclpkyvhtl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dslwfoajcv_rom = { 0 ,true, &tykfcoidpb,&sclpkyvhtl_ram,null_function};

    
static const char *rfidqlnxfx = "terminating";
static const char *whsumlkbzw = "event generator start";


unsigned  eqqyanskol;
const While_time_control_ROM_CFL_t jlpolnhldw = { 1000,&eqqyanskol };



static While_control_RAM_CFL_t srpddyadde_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cgabfihbqi_rom = { 0 ,true, &jlpolnhldw,&srpddyadde_ram,null_function};

    
const sm_event_CFL_t yajriptdhf = {0,&yyqhimrznx};
const sm_event_CFL_t nhjfxbnwry = {0,&mpgksushnh};
const sm_event_CFL_t atsyhfytow = {0,&qwabhjaifa};
const sm_event_CFL_t vrttyygcgj = {0,&qgqeucmjbh};


unsigned  vswpqcvlsw;
const While_time_control_ROM_CFL_t ognhaxqbdt = { 1000,&vswpqcvlsw };



static While_control_RAM_CFL_t jfnnfxldxa_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ejiuvefbdq_rom = { 0 ,true, &ognhaxqbdt,&jfnnfxldxa_ram,null_function};

    
const sm_event_CFL_t zfadtbgahu = {0,&yyqhimrznx};
const sm_event_CFL_t gnsoqhqxpj = {0,&mpgksushnh};
const sm_event_CFL_t kztoqclwkn = {0,&qwabhjaifa};
const sm_event_CFL_t fbxvoihudd = {0,&yjeffllvkt};


unsigned  hlzrozckjz;
const While_time_control_ROM_CFL_t qbbnhzskns = { 1000,&hlzrozckjz };



static While_control_RAM_CFL_t oxhjeoovsm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t htzgshqkpb_rom = { 0 ,true, &qbbnhzskns,&oxhjeoovsm_ram,null_function};

    
const sm_event_CFL_t dvdatrbhto = {0,&yyqhimrznx};
const sm_event_CFL_t nfhwosmrek = {0,&mpgksushnh};
const sm_event_CFL_t ykndopaisf = {0,&qwabhjaifa};
const sm_event_CFL_t szjsfunjgd = {0,&lmaorlkaoo};


unsigned  lcfrwgovgb;
const While_time_control_ROM_CFL_t butvojqpdi = { 1000,&lcfrwgovgb };



static While_control_RAM_CFL_t undwsisqko_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t usjelrqzcv_rom = { 0 ,true, &butvojqpdi,&undwsisqko_ram,null_function};

    
const sm_event_CFL_t jmjgzjcanp = {0,&yyqhimrznx};
const sm_event_CFL_t ymfyauutzo = {0,&mpgksushnh};
const sm_event_CFL_t qyzabtoaog = {0,&qwabhjaifa};
const sm_event_CFL_t aqausjdllq = {0,&utssnyvpbf};
static const char *jigbphgevf = "state machine manager starting";
const change_sm_state_CFL_t jlzuliryzh = {0,0};
const redirect_CFL_t uvnhvqpnvy = {0,NULL};
static const char *izegebpgzu = "state 1 starting";
const unsigned short uxymemvlys[] = {102};
const state_change_CFL_t teicncqcon = {0,1,1,uxymemvlys};
const SM_debug_CFL_t dyesyvmfwj = {0,0,test_data_12};
static const char *nbkdmqyoig = "state 2 starting";
const unsigned short gtbnfsajhc[] = {103};
const state_change_CFL_t kbwfobacsq = {0,2,1,gtbnfsajhc};
const SM_debug_CFL_t dabhxysliy = {0,1,test_data_22};
static const char *sgprbmgafl = "state 3 starting";
const SM_debug_CFL_t odzlfoxdmx = {0,2,test_data_32};
const unsigned short asuyzdjiae[] = {104};
const state_change_CFL_t mwqvfthnbd = {0,3,1,asuyzdjiae};
static const char *ciunahzefn = "state 4 starting";
const conditional_state_change_CFL_t qfuwhpsoih = {0,0,(void *)&bool_state_change};
const SM_debug_CFL_t vnamiqqyow = {0,3,test_data_42};


//----------RAM data structures for columns ----

unsigned odxzbjxsvg[7];
Watch_dog_struct_CFL_t * tbazvxtjwu[7];
unsigned char fsadpymwbw[7];
unsigned char wjdyftidth[7];
void* vuutjiqgdx[7];
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

static const Column_ROM_CFL_t spkxgwsgoe[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 22, 6, -1, -1 },
  { 1,false, 2, 4, 28, -1, -1 },
  { 2,false, 3, 4, 32, -1, -1 },
  { 3,false, 4, 4, 36, -1, -1 },
  { 4,false, 5, 4, 40, -1, -1 },
  { 5,false, 6, 4, 44, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char ioibwlicql[48];


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

static const Column_element_CFL_t tkiplzsgem[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&aljnkjghsd},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&jcqbmfqhoi},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&gvrsgnfgph},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dslwfoajcv_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rfidqlnxfx},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&whsumlkbzw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cgabfihbqi_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&yajriptdhf},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nhjfxbnwry},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&atsyhfytow},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vrttyygcgj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ejiuvefbdq_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&zfadtbgahu},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gnsoqhqxpj},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kztoqclwkn},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&fbxvoihudd},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&htzgshqkpb_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dvdatrbhto},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nfhwosmrek},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ykndopaisf},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&szjsfunjgd},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&usjelrqzcv_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jmjgzjcanp},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ymfyauutzo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qyzabtoaog},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&aqausjdllq},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jigbphgevf},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&jlzuliryzh},
    {redirect_event_CFL,true_constant_handler,(void *)&uvnhvqpnvy},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&izegebpgzu},
    {state_change_CFL,NULL,(void *)&teicncqcon},
    {SM_debug_CFL,true_constant_handler,(void *)&dyesyvmfwj},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nbkdmqyoig},
    {state_change_CFL,NULL,(void *)&kbwfobacsq},
    {SM_debug_CFL,true_constant_handler,(void *)&dabhxysliy},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sgprbmgafl},
    {SM_debug_CFL,true_constant_handler,(void *)&odzlfoxdmx},
    {state_change_CFL,NULL,(void *)&mwqvfthnbd},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ciunahzefn},
    {conditional_state_change_CFL,conditional_state_change,(void *)&qfuwhpsoih},
    {SM_debug_CFL,conditional_state_change,(void *)&vnamiqqyow},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
Bitmap_CFL fnxtaudymx[0];
short evehntfuhe[4] = {2,3,4,5,};
short trsmlolpuq[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t shamxtprew[1] = {
{0,1,2,4,trsmlolpuq,evehntfuhe,NULL},
}; 
Sm_control_RAM_CFL_t rstfarihno[1];


static Time_control_CFL_t lcatqetgvq;




static Engine_control_CFL_t vbvkvlbdhp;


/* remaining allocate heap size */

static unsigned tmdpnbfxfa;


/* current heap pointer */

static char* hkceddnxac;


/* heap block area */

static CS_MEMORY_CONTROL wbkdcfvgmk;


    
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


const struct Handle_CFL_t wyyfdvxdhc =
{

  .queue_number = 6,
  .queue_rom = olahcgcizm,
  .queue_ram = hxngdiyzwk,

  .column_elements_flags =ioibwlicql,
  .column_elements_ROM = tkiplzsgem,

  .watch_dog_struct = tbazvxtjwu,
  .watch_dog_count  = odxzbjxsvg,
   
   
  .column_flags = fsadpymwbw,
  .column_local_data = vuutjiqgdx,
  .column_state = wjdyftidth,
  .number_of_columns = 7,
  .column_rom_data = spkxgwsgoe,

  
  
  
  .time_control = &lcatqetgvq,
  .engine_control =&vbvkvlbdhp,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &tmdpnbfxfa,
  .current_heap_location = &hkceddnxac,
  .private_heap   = &wbkdcfvgmk,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  shamxtprew,
   .sm_ram     = rstfarihno,
   .number_of_bitmaps = 0,
    .bitmaps = fnxtaudymx,
} ;


const Handle_CFL_t*  state_machine_3_handle(){
    return &wyyfdvxdhc;
}
   

#ifdef __cplusplus
}
#endif

#endif
