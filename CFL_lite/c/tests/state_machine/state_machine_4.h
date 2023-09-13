#ifndef __state_machine_4_H__
#define __state_machine_4_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t xqakbrmktb[6];
static Event_data_CFL_t tfssvadonb[10];
static Event_data_CFL_t cmdyftbxve[10];
static Event_data_CFL_t jirxfrigdw[10];
static Event_data_CFL_t izcxvxvteg[10];
static Event_data_CFL_t gfmoieetig[10];
static Event_data_CFL_t zfsfxkjzra[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t soudzwnafy[] = { 
     {  10, tfssvadonb },
     {  10, cmdyftbxve },
     {  10, jirxfrigdw },
     {  10, izcxvxvteg },
     {  10, gfmoieetig },
     {  10, zfsfxkjzra },
};
const Event_data_CFL_t ihxegmvccp = { 101, false, NULL };
const Event_data_CFL_t vzhhdqmnfq = { 102, false, NULL };
const Event_data_CFL_t lknqfdoqoz = { 103, false, NULL };
const Event_data_CFL_t osrocwqodv = { 104, false, NULL };
const Event_data_CFL_t grvalkodwf = { 111, false, NULL };
const Event_data_CFL_t tcjqobjyyi = { 112, false, NULL };
const Event_data_CFL_t idkjdpxvno = { 113, false, NULL };

const char test_data_13[] = "state 1 debug message";
const char test_data_23[] = "state 2 debug message";
const char test_data_33[] = "state 3 debug message";
const char test_data_43[] = "state 4 debug message";
static const char *vloagqlbgt = "start column";

const unsigned short  akgynzvxvg[] = {0};

enable_disable_sm_CFL_t dctngkuojw = {1,akgynzvxvg };
static const unsigned short gvmrohgzeo[] = { 1};
const Enable_column_CFL_t nnyrjdonnk = { true, 1, gvmrohgzeo };


unsigned  qgqvkfzhsv;
const While_time_control_ROM_CFL_t cgimcmuapx = { 60000,&qgqvkfzhsv };



static While_control_RAM_CFL_t xfgomlsxhf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jhdqzubibv_rom = { 0 ,true, &cgimcmuapx,&xfgomlsxhf_ram,null_function};

    
static const char *kgipvdnxqn = "terminating";
static const char *hjmiqbbiuo = "event generator start";


unsigned  uoftlwahrr;
const While_time_control_ROM_CFL_t zywwefoova = { 2000,&uoftlwahrr };



static While_control_RAM_CFL_t ivmjfcdwkh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tbjmeyzgww_rom = { 0 ,true, &zywwefoova,&ivmjfcdwkh_ram,null_function};

    
const sm_event_CFL_t kfglfkaqrq = {0,&vzhhdqmnfq};
const sm_event_CFL_t nstfoxqkby = {0,&grvalkodwf};
const sm_event_CFL_t nlvmcidius = {0,&tcjqobjyyi};
const sm_event_CFL_t psjmlqptec = {0,&idkjdpxvno};


unsigned  nylibsudlh;
const While_time_control_ROM_CFL_t mkxokqsgzv = { 50,&nylibsudlh };



static While_control_RAM_CFL_t vqdlzdwzfe_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lzoegmojtf_rom = { 0 ,true, &mkxokqsgzv,&vqdlzdwzfe_ram,null_function};

    
const sm_event_CFL_t fzlgjfapdt = {0,&grvalkodwf};
const sm_event_CFL_t bymnktsnin = {0,&tcjqobjyyi};
const sm_event_CFL_t xpvawihayu = {0,&idkjdpxvno};


unsigned  lxltfzdrsy;
const While_time_control_ROM_CFL_t mondisaiwe = { 2000,&lxltfzdrsy };



static While_control_RAM_CFL_t rshonxobyj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kfvyvdaxgv_rom = { 0 ,true, &mondisaiwe,&rshonxobyj_ram,null_function};

    
const sm_event_CFL_t bkbmmfcqsz = {0,&lknqfdoqoz};
const sm_event_CFL_t httkeojtwa = {0,&grvalkodwf};
const sm_event_CFL_t wbjcdkrnde = {0,&tcjqobjyyi};
const sm_event_CFL_t zwezlriqkd = {0,&idkjdpxvno};


unsigned  zdveiizccx;
const While_time_control_ROM_CFL_t znljoxyisu = { 50,&zdveiizccx };



static While_control_RAM_CFL_t yussmbkgsk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ilhtnvsygg_rom = { 0 ,true, &znljoxyisu,&yussmbkgsk_ram,null_function};

    
const sm_event_CFL_t iighxerlex = {0,&grvalkodwf};
const sm_event_CFL_t wnpxyglgcb = {0,&tcjqobjyyi};
const sm_event_CFL_t txxvxinfpv = {0,&idkjdpxvno};


unsigned  ccjjdwnabn;
const While_time_control_ROM_CFL_t trqugrwxiq = { 2000,&ccjjdwnabn };



static While_control_RAM_CFL_t jujuxrzwni_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uohxvbqkct_rom = { 0 ,true, &trqugrwxiq,&jujuxrzwni_ram,null_function};

    
const sm_event_CFL_t czsirhaekd = {0,&osrocwqodv};
const sm_event_CFL_t ocovxsmrlw = {0,&grvalkodwf};
const sm_event_CFL_t bwxifkqarx = {0,&tcjqobjyyi};
const sm_event_CFL_t tuqgimecid = {0,&idkjdpxvno};


unsigned  iqtrtstssu;
const While_time_control_ROM_CFL_t mophimfaab = { 50,&iqtrtstssu };



static While_control_RAM_CFL_t aktgrzzzto_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t djgvahulbq_rom = { 0 ,true, &mophimfaab,&aktgrzzzto_ram,null_function};

    
const sm_event_CFL_t bksxvxmsjn = {0,&grvalkodwf};
const sm_event_CFL_t ylfzuuyocp = {0,&tcjqobjyyi};
const sm_event_CFL_t twmspbligb = {0,&idkjdpxvno};


unsigned  nfbcedeqsi;
const While_time_control_ROM_CFL_t sigwzmbklq = { 2000,&nfbcedeqsi };



static While_control_RAM_CFL_t zvcnmacsgr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t skxkllrlun_rom = { 0 ,true, &sigwzmbklq,&zvcnmacsgr_ram,null_function};

    
const sm_event_CFL_t jbbiefdltl = {0,&ihxegmvccp};
const sm_event_CFL_t ibyhwdcvty = {0,&grvalkodwf};
const sm_event_CFL_t aiyudtwgws = {0,&tcjqobjyyi};
const sm_event_CFL_t hztjdgavmt = {0,&idkjdpxvno};


unsigned  uuztcbjtyj;
const While_time_control_ROM_CFL_t arkqgliabw = { 50,&uuztcbjtyj };



static While_control_RAM_CFL_t rpjksmxzoy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nfvlcjehib_rom = { 0 ,true, &arkqgliabw,&rpjksmxzoy_ram,null_function};

    
const sm_event_CFL_t mjxsbzaida = {0,&grvalkodwf};
const sm_event_CFL_t bzbqweyjra = {0,&tcjqobjyyi};
const sm_event_CFL_t attjyggowm = {0,&idkjdpxvno};
static const char *phzeowqjii = "state machine manager starting";
const change_sm_state_CFL_t pjkmctsvex = {0,0};
const unsigned short rlrwqbnfsi[] = {101};
const state_change_CFL_t rpkzkaubtz = {0,0,1,rlrwqbnfsi};
const unsigned short oxjduhoezm[] = {102};
const state_change_CFL_t ghljktmjks = {0,1,1,oxjduhoezm};
const unsigned short kilzfdfked[] = {103};
const state_change_CFL_t mnojbizlwe = {0,2,1,kilzfdfked};
const unsigned short sybtlhnkal[] = {104};
const state_change_CFL_t ypepnzwkte = {0,3,1,sybtlhnkal};
const redirect_CFL_t nehxvvvlmu = {0,NULL};
static const char *rketykcpnt = "state 1 starting";
const sync_events_t cwcxydolbk = {0,201};
const SM_debug_CFL_t rdkmxodoqy = {0,0,test_data_13};
static const char *flctytdyxu = "state 2 starting";
const sync_events_t ximhhimuvi = {0,202};
const SM_debug_CFL_t belqydkbqq = {0,1,test_data_23};
static const char *wzrbpcksxm = "state 3 starting";
const sync_events_t pypawdbukj = {0,203};
const SM_debug_CFL_t fljtasskmg = {0,2,test_data_33};
static const char *pvlzouapgo = "state 4 starting";
const sync_events_t ktjtqklgel = {0,204};
const SM_debug_CFL_t jildpgyopc = {0,3,test_data_43};


//----------RAM data structures for columns ----

unsigned wrmdzeleax[7];
Watch_dog_struct_CFL_t * ygogdigoay[7];
unsigned char bmxkhmamph[7];
unsigned char pzdivpodwd[7];
void* nhtrqeaeef[7];
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

static const Column_ROM_CFL_t mddurjvakv[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 38, 6, -1, -1 },
  { 1,false, 2, 8, 44, -1, -1 },
  { 2,false, 3, 4, 52, -1, -1 },
  { 3,false, 4, 4, 56, -1, -1 },
  { 4,false, 5, 4, 60, -1, -1 },
  { 5,false, 6, 4, 64, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char leryxvmjjk[68];


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

static const Column_element_CFL_t zeonemijrz[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&vloagqlbgt},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&dctngkuojw},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&nnyrjdonnk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jhdqzubibv_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kgipvdnxqn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hjmiqbbiuo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tbjmeyzgww_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kfglfkaqrq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nstfoxqkby},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nlvmcidius},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&psjmlqptec},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lzoegmojtf_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&fzlgjfapdt},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bymnktsnin},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xpvawihayu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kfvyvdaxgv_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bkbmmfcqsz},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&httkeojtwa},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&wbjcdkrnde},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&zwezlriqkd},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ilhtnvsygg_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&iighxerlex},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&wnpxyglgcb},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&txxvxinfpv},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uohxvbqkct_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&czsirhaekd},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ocovxsmrlw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bwxifkqarx},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tuqgimecid},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&djgvahulbq_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bksxvxmsjn},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ylfzuuyocp},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&twmspbligb},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&skxkllrlun_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jbbiefdltl},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ibyhwdcvty},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&aiyudtwgws},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hztjdgavmt},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nfvlcjehib_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mjxsbzaida},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bzbqweyjra},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&attjyggowm},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&phzeowqjii},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&pjkmctsvex},
    {state_change_CFL,NULL,(void *)&rpkzkaubtz},
    {state_change_CFL,NULL,(void *)&ghljktmjks},
    {state_change_CFL,NULL,(void *)&mnojbizlwe},
    {state_change_CFL,NULL,(void *)&ypepnzwkte},
    {redirect_event_CFL,true_constant_handler,(void *)&nehxvvvlmu},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rketykcpnt},
    {sync_events_CFL,NULL,(void *)&cwcxydolbk},
    {SM_debug_CFL,true_constant_handler,(void *)&rdkmxodoqy},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&flctytdyxu},
    {sync_events_CFL,NULL,(void *)&ximhhimuvi},
    {SM_debug_CFL,true_constant_handler,(void *)&belqydkbqq},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wzrbpcksxm},
    {sync_events_CFL,NULL,(void *)&pypawdbukj},
    {SM_debug_CFL,true_constant_handler,(void *)&fljtasskmg},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pvlzouapgo},
    {sync_events_CFL,NULL,(void *)&ktjtqklgel},
    {SM_debug_CFL,true_constant_handler,(void *)&jildpgyopc},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short bzifarfrlg[4] = {2,3,4,5,};
short rylutkfvcf[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t txwrnxbezj[1] = {
{0,1,2,4,rylutkfvcf,bzifarfrlg,NULL},
}; 
Sm_control_RAM_CFL_t lfzjqchubx[1];


static Time_control_CFL_t uirpyduixv;




static Engine_control_CFL_t qfgwjrwwvp;


/* remaining allocate heap size */

static unsigned qgfvkifadv;


/* current heap pointer */

static char* pmflkoabgv;


/* heap block area */

static CS_MEMORY_CONTROL aovpwhjnyn;


    
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


const struct Handle_CFL_t dyomxdsnhs =
{

  .queue_number = 6,
  .queue_rom = soudzwnafy,
  .queue_ram = xqakbrmktb,

  .column_elements_flags =leryxvmjjk,
  .column_elements_ROM = zeonemijrz,

  .watch_dog_struct = ygogdigoay,
  .watch_dog_count  = wrmdzeleax,
   
   
  .column_flags = bmxkhmamph,
  .column_local_data = nhtrqeaeef,
  .column_state = pzdivpodwd,
  .number_of_columns = 7,
  .column_rom_data = mddurjvakv,

  
  
  
  .time_control = &uirpyduixv,
  .engine_control =&qfgwjrwwvp,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &qgfvkifadv,
  .current_heap_location = &pmflkoabgv,
  .private_heap   = &aovpwhjnyn,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  txwrnxbezj,
   .sm_ram     = lfzjqchubx,
} ;


const Handle_CFL_t*  state_machine_4_handle(){
    return &dyomxdsnhs;
}
   

#ifdef __cplusplus
}
#endif

#endif
