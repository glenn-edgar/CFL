#ifndef __state_machine_4_H__
#define __state_machine_4_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t bqmmlemmwt[6];
static Event_data_CFL_t ztjoocdkws[10];
static Event_data_CFL_t dvrvexdcro[10];
static Event_data_CFL_t rdofmxbrvl[10];
static Event_data_CFL_t otxjomemxi[10];
static Event_data_CFL_t vhntpmwbbt[10];
static Event_data_CFL_t hbkjvhybku[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t pfaduvatge[] = { 
     {  10, ztjoocdkws },
     {  10, dvrvexdcro },
     {  10, rdofmxbrvl },
     {  10, otxjomemxi },
     {  10, vhntpmwbbt },
     {  10, hbkjvhybku },
};
const Event_data_CFL_t dlqskragej = { 101, false, NULL };
const Event_data_CFL_t ysrmixgjct = { 102, false, NULL };
const Event_data_CFL_t ngmhhvyjwz = { 103, false, NULL };
const Event_data_CFL_t vhuadawudc = { 104, false, NULL };
const Event_data_CFL_t hbmvpxpijn = { 111, false, NULL };
const Event_data_CFL_t gmhhnvdjrp = { 112, false, NULL };
const Event_data_CFL_t mrtoczzwsu = { 113, false, NULL };

const char test_data_13[] = "state 1 debug message";
const char test_data_23[] = "state 2 debug message";
const char test_data_33[] = "state 3 debug message";
const char test_data_43[] = "state 4 debug message";
static const char *nfynvratpb = "start column";

const unsigned short  izewefaqei[] = {0};

enable_disable_sm_CFL_t dvsioqajcu = {1,izewefaqei };
static const unsigned short ayuqlgfaos[] = { 1};
const Enable_column_CFL_t xnezkufcuy = { true, 1, ayuqlgfaos };


unsigned  ksopgbrnjt;
const While_time_control_ROM_CFL_t dxtdxatuon = { 60000,&ksopgbrnjt };



static While_control_RAM_CFL_t ifhbhwlowi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lichqfglau_rom = { 0 ,true, &dxtdxatuon,&ifhbhwlowi_ram,null_function};

    
static const char *mbqrsogpyz = "terminating";
static const char *bfducfjccr = "event generator start";


unsigned  mtrwwlzyhy;
const While_time_control_ROM_CFL_t pflcyrcquu = { 2000,&mtrwwlzyhy };



static While_control_RAM_CFL_t mxcdbiswup_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ewbgvavjzr_rom = { 0 ,true, &pflcyrcquu,&mxcdbiswup_ram,null_function};

    
const sm_event_CFL_t nzoiatjyjp = {0,&ysrmixgjct};
const sm_event_CFL_t vrbxqdkpdq = {0,&hbmvpxpijn};
const sm_event_CFL_t etnaogdlhq = {0,&gmhhnvdjrp};
const sm_event_CFL_t fohoibcrkv = {0,&mrtoczzwsu};


unsigned  ukmmbsxauv;
const While_time_control_ROM_CFL_t cemuxetzow = { 50,&ukmmbsxauv };



static While_control_RAM_CFL_t ciexillruy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rrrvqfnbyl_rom = { 0 ,true, &cemuxetzow,&ciexillruy_ram,null_function};

    
const sm_event_CFL_t jrlriidckk = {0,&hbmvpxpijn};
const sm_event_CFL_t pxebocnisp = {0,&gmhhnvdjrp};
const sm_event_CFL_t lbpihczeqy = {0,&mrtoczzwsu};


unsigned  xcdpenwqse;
const While_time_control_ROM_CFL_t ttjxqvwmgj = { 2000,&xcdpenwqse };



static While_control_RAM_CFL_t lzvanvwfbj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lluprsodcw_rom = { 0 ,true, &ttjxqvwmgj,&lzvanvwfbj_ram,null_function};

    
const sm_event_CFL_t byqhgtmzdq = {0,&ngmhhvyjwz};
const sm_event_CFL_t ncehkiukez = {0,&hbmvpxpijn};
const sm_event_CFL_t gfhwrnoxec = {0,&gmhhnvdjrp};
const sm_event_CFL_t cnsntfzxqi = {0,&mrtoczzwsu};


unsigned  vjvbtgkchj;
const While_time_control_ROM_CFL_t itaxrhifga = { 50,&vjvbtgkchj };



static While_control_RAM_CFL_t hyxemkjxwl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lbngtqnevg_rom = { 0 ,true, &itaxrhifga,&hyxemkjxwl_ram,null_function};

    
const sm_event_CFL_t dxxczyjyfh = {0,&hbmvpxpijn};
const sm_event_CFL_t rnqtlzixdl = {0,&gmhhnvdjrp};
const sm_event_CFL_t ejosdjyeha = {0,&mrtoczzwsu};


unsigned  tozelovtft;
const While_time_control_ROM_CFL_t tzwhhekukh = { 2000,&tozelovtft };



static While_control_RAM_CFL_t gkyinrdpxf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t siaowyycwz_rom = { 0 ,true, &tzwhhekukh,&gkyinrdpxf_ram,null_function};

    
const sm_event_CFL_t khrrswvyec = {0,&vhuadawudc};
const sm_event_CFL_t qcrwgsejye = {0,&hbmvpxpijn};
const sm_event_CFL_t sstlewpwpm = {0,&gmhhnvdjrp};
const sm_event_CFL_t hrlxhftczj = {0,&mrtoczzwsu};


unsigned  wkqkublrmw;
const While_time_control_ROM_CFL_t zqrvpdykaw = { 50,&wkqkublrmw };



static While_control_RAM_CFL_t cibrnygiol_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mpqbdhppgj_rom = { 0 ,true, &zqrvpdykaw,&cibrnygiol_ram,null_function};

    
const sm_event_CFL_t nzhqlxcvyg = {0,&hbmvpxpijn};
const sm_event_CFL_t daoiophlve = {0,&gmhhnvdjrp};
const sm_event_CFL_t qgvqwpycwq = {0,&mrtoczzwsu};


unsigned  awonpiusqy;
const While_time_control_ROM_CFL_t faeadwiyba = { 2000,&awonpiusqy };



static While_control_RAM_CFL_t maztcwkgws_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lgnkxumfec_rom = { 0 ,true, &faeadwiyba,&maztcwkgws_ram,null_function};

    
const sm_event_CFL_t nfktzemzuu = {0,&dlqskragej};
const sm_event_CFL_t jomfytxoko = {0,&hbmvpxpijn};
const sm_event_CFL_t tlwlgeelxx = {0,&gmhhnvdjrp};
const sm_event_CFL_t mgsgwakyio = {0,&mrtoczzwsu};


unsigned  ahvdbuzewv;
const While_time_control_ROM_CFL_t kgdpkexuet = { 50,&ahvdbuzewv };



static While_control_RAM_CFL_t diytcuztzy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cnxwxqdrlg_rom = { 0 ,true, &kgdpkexuet,&diytcuztzy_ram,null_function};

    
const sm_event_CFL_t otmftsyrtk = {0,&hbmvpxpijn};
const sm_event_CFL_t lsacqifwla = {0,&gmhhnvdjrp};
const sm_event_CFL_t rmgnjetjsy = {0,&mrtoczzwsu};
static const char *phxouqysiq = "state machine manager starting";
const change_sm_state_CFL_t lzuhrneitm = {0,0};
const unsigned short vahzgkqodr[] = {101};
const state_change_CFL_t ajgbkjcukq = {0,0,1,vahzgkqodr};
const unsigned short jnbthhafnr[] = {102};
const state_change_CFL_t sxupwhdqom = {0,1,1,jnbthhafnr};
const unsigned short dsxmifpiwf[] = {103};
const state_change_CFL_t etdexbysaj = {0,2,1,dsxmifpiwf};
const unsigned short fvmzrcbtzr[] = {104};
const state_change_CFL_t qythotvdic = {0,3,1,fvmzrcbtzr};
const redirect_CFL_t geitjozokc = {0,NULL};
static const char *ttvlzcaywe = "state 1 starting";
const sync_events_t ppykkzgmdr = {0,201};
const SM_debug_CFL_t mielbygifd = {0,0,test_data_13};
static const char *eygjicocrv = "state 2 starting";
const sync_events_t thofhfwhur = {0,202};
const SM_debug_CFL_t opayemctwm = {0,1,test_data_23};
static const char *idnavuasrv = "state 3 starting";
const sync_events_t yrbmpidbvt = {0,203};
const SM_debug_CFL_t ucvpscdofw = {0,2,test_data_33};
static const char *qayxcelznc = "state 4 starting";
const sync_events_t cfxovygwmq = {0,204};
const SM_debug_CFL_t wpvgjqqepw = {0,3,test_data_43};


//----------RAM data structures for columns ----

unsigned mrnbgutypg[7];
Watch_dog_struct_CFL_t * jrazeelbjv[7];
unsigned char wpwtoylikd[7];
unsigned char tnpanmvwtu[7];
void* galwomajss[7];
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

static const Column_ROM_CFL_t pmczxmevzn[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 38, 6, -1, -1 },
  { 1,false, 2, 8, 44, -1, -1 },
  { 2,false, 3, 4, 52, -1, -1 },
  { 3,false, 4, 4, 56, -1, -1 },
  { 4,false, 5, 4, 60, -1, -1 },
  { 5,false, 6, 4, 64, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char cmcluqmhmn[68];


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

static const Column_element_CFL_t gdskmhlchi[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&nfynvratpb},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&dvsioqajcu},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&xnezkufcuy},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lichqfglau_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mbqrsogpyz},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bfducfjccr},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ewbgvavjzr_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nzoiatjyjp},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vrbxqdkpdq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&etnaogdlhq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&fohoibcrkv},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rrrvqfnbyl_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jrlriidckk},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pxebocnisp},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&lbpihczeqy},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lluprsodcw_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&byqhgtmzdq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ncehkiukez},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gfhwrnoxec},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cnsntfzxqi},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lbngtqnevg_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dxxczyjyfh},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rnqtlzixdl},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ejosdjyeha},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&siaowyycwz_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&khrrswvyec},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qcrwgsejye},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&sstlewpwpm},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hrlxhftczj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mpqbdhppgj_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nzhqlxcvyg},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&daoiophlve},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qgvqwpycwq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lgnkxumfec_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nfktzemzuu},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jomfytxoko},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tlwlgeelxx},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mgsgwakyio},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cnxwxqdrlg_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&otmftsyrtk},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&lsacqifwla},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rmgnjetjsy},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&phxouqysiq},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&lzuhrneitm},
    {state_change_CFL,NULL,(void *)&ajgbkjcukq},
    {state_change_CFL,NULL,(void *)&sxupwhdqom},
    {state_change_CFL,NULL,(void *)&etdexbysaj},
    {state_change_CFL,NULL,(void *)&qythotvdic},
    {redirect_event_CFL,true_constant_handler,(void *)&geitjozokc},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ttvlzcaywe},
    {sync_events_CFL,NULL,(void *)&ppykkzgmdr},
    {SM_debug_CFL,true_constant_handler,(void *)&mielbygifd},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&eygjicocrv},
    {sync_events_CFL,NULL,(void *)&thofhfwhur},
    {SM_debug_CFL,true_constant_handler,(void *)&opayemctwm},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&idnavuasrv},
    {sync_events_CFL,NULL,(void *)&yrbmpidbvt},
    {SM_debug_CFL,true_constant_handler,(void *)&ucvpscdofw},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qayxcelznc},
    {sync_events_CFL,NULL,(void *)&cfxovygwmq},
    {SM_debug_CFL,true_constant_handler,(void *)&wpvgjqqepw},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short nqgfunuuuf[4] = {2,3,4,5,};
short olpcflucwq[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t yvyjvbzckq[1] = {
{0,1,2,4,olpcflucwq,nqgfunuuuf,NULL},
}; 
Sm_control_RAM_CFL_t lyhjssaapp[1];


static Time_control_CFL_t wxnorkyvxd;




static Engine_control_CFL_t uiyjzayplt;


/* remaining allocate heap size */

static unsigned dkupehwvtn;


/* current heap pointer */

static char* aijtdispma;


/* heap block area */

static CS_MEMORY_CONTROL xhdamdcatv;


    
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


const struct Handle_CFL_t onznbdeyyn =
{

  .queue_number = 6,
  .queue_rom = pfaduvatge,
  .queue_ram = bqmmlemmwt,

  .column_elements_flags =cmcluqmhmn,
  .column_elements_ROM = gdskmhlchi,

  .watch_dog_struct = jrazeelbjv,
  .watch_dog_count  = mrnbgutypg,
   
   
  .column_flags = wpwtoylikd,
  .column_local_data = galwomajss,
  .column_state = tnpanmvwtu,
  .number_of_columns = 7,
  .column_rom_data = pmczxmevzn,

  
  
  
  .time_control = &wxnorkyvxd,
  .engine_control =&uiyjzayplt,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &dkupehwvtn,
  .current_heap_location = &aijtdispma,
  .private_heap   = &xhdamdcatv,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  yvyjvbzckq,
   .sm_ram     = lyhjssaapp,
} ;


const Handle_CFL_t*  state_machine_4_handle(){
    return &onznbdeyyn;
}
   

#ifdef __cplusplus
}
#endif

#endif
