#ifndef __state_machine_3_H__
#define __state_machine_3_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t lahkojoyzc[6];
static Event_data_CFL_t rbmphlvzhl[10];
static Event_data_CFL_t eerbvcnflt[10];
static Event_data_CFL_t tdmhqytasy[10];
static Event_data_CFL_t enyewfgtib[10];
static Event_data_CFL_t lfuqaukfhr[10];
static Event_data_CFL_t krjolikvcy[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hlgzbjlnmt[] = { 
     {  10, rbmphlvzhl },
     {  10, eerbvcnflt },
     {  10, tdmhqytasy },
     {  10, enyewfgtib },
     {  10, lfuqaukfhr },
     {  10, krjolikvcy },
};
const Event_data_CFL_t wsstibfklp = { 101, false, NULL };
const Event_data_CFL_t ileomtjpqv = { 102, false, NULL };
const Event_data_CFL_t cmqgowjxvd = { 103, false, NULL };
const Event_data_CFL_t dvovkgquad = { 104, false, NULL };
const Event_data_CFL_t fguhgvmhzc = { 111, false, NULL };
const Event_data_CFL_t uzdbqsnvpr = { 112, false, NULL };
const Event_data_CFL_t ydmymtuwfx = { 113, false, NULL };
#define state_1_event 101
unsigned short test_counter = 0;
const condition_state_change_t bool_state_change = {state_1_event,3,&test_counter};


const char test_data_12[] = "state 1 debug message";
const char test_data_22[] = "state 2 debug message";
const char test_data_32[] = "state 3 debug message";
const char test_data_42[] = "state 4 debug message";
static const char *vfwrencoaf = "start column";

const unsigned short  scgayxrxkb[] = {0};

enable_disable_sm_CFL_t wtsvtkpemi = {1,scgayxrxkb };
static const unsigned short ijazslufxp[] = { 1};
const Enable_column_CFL_t qsdqkxfpbo = { true, 1, ijazslufxp };


unsigned  slxetrthpt;
const While_time_control_ROM_CFL_t imoblynaxp = { 60000,&slxetrthpt };



static While_control_RAM_CFL_t hvhgrjxjbt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ewkgueqbzb_rom = { 0 ,true, &imoblynaxp,&hvhgrjxjbt_ram,null_function};

    
static const char *vtrgfywgew = "terminating";
static const char *xigtahlxlo = "event generator start";


unsigned  oiciyyrbow;
const While_time_control_ROM_CFL_t tbhgsnxxdk = { 1000,&oiciyyrbow };



static While_control_RAM_CFL_t xlqlarfyre_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bmxvttrxfc_rom = { 0 ,true, &tbhgsnxxdk,&xlqlarfyre_ram,null_function};

    
const sm_event_CFL_t kslkbuyomv = {0,&fguhgvmhzc};
const sm_event_CFL_t hfpjkkkqxq = {0,&uzdbqsnvpr};
const sm_event_CFL_t exyjetrwyu = {0,&ydmymtuwfx};
const sm_event_CFL_t apfbqnpwpc = {0,&ileomtjpqv};


unsigned  zufdkuujet;
const While_time_control_ROM_CFL_t afmhuslgqi = { 1000,&zufdkuujet };



static While_control_RAM_CFL_t fctzslfkxn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kcitxlcjcw_rom = { 0 ,true, &afmhuslgqi,&fctzslfkxn_ram,null_function};

    
const sm_event_CFL_t clgwyezcct = {0,&fguhgvmhzc};
const sm_event_CFL_t kbajrkxgai = {0,&uzdbqsnvpr};
const sm_event_CFL_t rqhhjrpmxw = {0,&ydmymtuwfx};
const sm_event_CFL_t ohmtadfmxs = {0,&cmqgowjxvd};


unsigned  nagifzontk;
const While_time_control_ROM_CFL_t qzlnyevpuv = { 1000,&nagifzontk };



static While_control_RAM_CFL_t poyjodyfrs_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t adpckvchrx_rom = { 0 ,true, &qzlnyevpuv,&poyjodyfrs_ram,null_function};

    
const sm_event_CFL_t jwoguflgfl = {0,&fguhgvmhzc};
const sm_event_CFL_t ozzlxwfbda = {0,&uzdbqsnvpr};
const sm_event_CFL_t wgwdsndbmu = {0,&ydmymtuwfx};
const sm_event_CFL_t gvqrxqfbvm = {0,&dvovkgquad};


unsigned  kalqvelpby;
const While_time_control_ROM_CFL_t nkuotibypf = { 1000,&kalqvelpby };



static While_control_RAM_CFL_t paneegmewt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rckdtepqps_rom = { 0 ,true, &nkuotibypf,&paneegmewt_ram,null_function};

    
const sm_event_CFL_t wgvwsrfpfv = {0,&fguhgvmhzc};
const sm_event_CFL_t dgaifsahpn = {0,&uzdbqsnvpr};
const sm_event_CFL_t htwdjvgemm = {0,&ydmymtuwfx};
const sm_event_CFL_t nqjncsqhve = {0,&wsstibfklp};
static const char *rfjbtkcqev = "state machine manager starting";
const change_sm_state_CFL_t kjevnizczw = {0,0};
const redirect_CFL_t fequqqzaas = {0,NULL};
static const char *hsiqvhqkdc = "state 1 starting";
const unsigned short bdxxheepwp[] = {102};
const state_change_CFL_t uszjswbvzm = {0,1,1,bdxxheepwp};
const SM_debug_CFL_t afudaqueue = {0,0,test_data_12};
static const char *esltrwqmyd = "state 2 starting";
const unsigned short ictylktmit[] = {103};
const state_change_CFL_t diabetkirw = {0,2,1,ictylktmit};
const SM_debug_CFL_t gosygelpjc = {0,1,test_data_22};
static const char *iezdbmqxee = "state 3 starting";
const SM_debug_CFL_t khlpxvtmwc = {0,2,test_data_32};
const unsigned short uoaoytlmiw[] = {104};
const state_change_CFL_t dzxwndckfr = {0,3,1,uoaoytlmiw};
static const char *mzsxayhprz = "state 4 starting";
const conditional_state_change_CFL_t bsxbdznmsd = {0,0,(void *)&bool_state_change};
const SM_debug_CFL_t wwngwutoiy = {0,3,test_data_42};


//----------RAM data structures for columns ----

unsigned vyxcivwaiy[7];
Watch_dog_struct_CFL_t * lhhuxiknfe[7];
unsigned char nrzpbzyitg[7];
unsigned char zsdlfefdsf[7];
void* eufdksadmm[7];
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

static const Column_ROM_CFL_t fjperhdlzu[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 22, 6, -1, -1 },
  { 1,false, 2, 4, 28, -1, -1 },
  { 2,false, 3, 4, 32, -1, -1 },
  { 3,false, 4, 4, 36, -1, -1 },
  { 4,false, 5, 4, 40, -1, -1 },
  { 5,false, 6, 4, 44, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char xwosovozgd[48];


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

static const Column_element_CFL_t aekbvqomde[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&vfwrencoaf},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&wtsvtkpemi},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&qsdqkxfpbo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ewkgueqbzb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vtrgfywgew},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xigtahlxlo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bmxvttrxfc_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kslkbuyomv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hfpjkkkqxq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&exyjetrwyu},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&apfbqnpwpc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kcitxlcjcw_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&clgwyezcct},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kbajrkxgai},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rqhhjrpmxw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ohmtadfmxs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&adpckvchrx_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jwoguflgfl},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ozzlxwfbda},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&wgwdsndbmu},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gvqrxqfbvm},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rckdtepqps_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&wgvwsrfpfv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dgaifsahpn},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&htwdjvgemm},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nqjncsqhve},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rfjbtkcqev},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&kjevnizczw},
    {redirect_event_CFL,true_constant_handler,(void *)&fequqqzaas},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hsiqvhqkdc},
    {state_change_CFL,NULL,(void *)&uszjswbvzm},
    {SM_debug_CFL,true_constant_handler,(void *)&afudaqueue},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&esltrwqmyd},
    {state_change_CFL,NULL,(void *)&diabetkirw},
    {SM_debug_CFL,true_constant_handler,(void *)&gosygelpjc},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iezdbmqxee},
    {SM_debug_CFL,true_constant_handler,(void *)&khlpxvtmwc},
    {state_change_CFL,NULL,(void *)&dzxwndckfr},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzsxayhprz},
    {conditional_state_change_CFL,conditional_state_change,(void *)&bsxbdznmsd},
    {SM_debug_CFL,conditional_state_change,(void *)&wwngwutoiy},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short qvuhezoyku[4] = {2,3,4,5,};
short qqspkblbqy[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t ppiapkgqlo[1] = {
{0,1,2,4,qqspkblbqy,qvuhezoyku,NULL},
}; 
Sm_control_RAM_CFL_t tfkvfrvbcj[1];


static Time_control_CFL_t smkleszxei;




static Engine_control_CFL_t yhncubuyhm;


/* remaining allocate heap size */

static unsigned wbmnihmrws;


/* current heap pointer */

static char* xslxirimdt;


/* heap block area */

static CS_MEMORY_CONTROL yrjrbymnfa;


    
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


const struct Handle_CFL_t yugdhbckos =
{

  .queue_number = 6,
  .queue_rom = hlgzbjlnmt,
  .queue_ram = lahkojoyzc,

  .column_elements_flags =xwosovozgd,
  .column_elements_ROM = aekbvqomde,

  .watch_dog_struct = lhhuxiknfe,
  .watch_dog_count  = vyxcivwaiy,
   
   
  .column_flags = nrzpbzyitg,
  .column_local_data = eufdksadmm,
  .column_state = zsdlfefdsf,
  .number_of_columns = 7,
  .column_rom_data = fjperhdlzu,

  
  
  
  .time_control = &smkleszxei,
  .engine_control =&yhncubuyhm,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &wbmnihmrws,
  .current_heap_location = &xslxirimdt,
  .private_heap   = &yrjrbymnfa,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  ppiapkgqlo,
   .sm_ram     = tfkvfrvbcj,
} ;


const Handle_CFL_t*  state_machine_3_handle(){
    return &yugdhbckos;
}
   

#ifdef __cplusplus
}
#endif

#endif
