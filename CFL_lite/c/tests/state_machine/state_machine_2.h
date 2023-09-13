#ifndef __state_machine_2_H__
#define __state_machine_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t shqzrhwgew[6];
static Event_data_CFL_t zxmdsgnngn[10];
static Event_data_CFL_t ehkofwkbqa[10];
static Event_data_CFL_t xxvilrcnww[10];
static Event_data_CFL_t yxnddkkkkx[10];
static Event_data_CFL_t jwbtkiwlbd[10];
static Event_data_CFL_t aphlrjyufm[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t drwpujgwqq[] = { 
     {  10, zxmdsgnngn },
     {  10, ehkofwkbqa },
     {  10, xxvilrcnww },
     {  10, yxnddkkkkx },
     {  10, jwbtkiwlbd },
     {  10, aphlrjyufm },
};
const char test_data_2[] = "test_data\n";
const Event_data_CFL_t qerxchsvek = { 101, false, NULL };
const Event_data_CFL_t caclydbrcf = { 102, false, NULL };
const Event_data_CFL_t vkpzumszbm = { 103, false, NULL };
const Event_data_CFL_t ssjgzyyyii = { 104, false, NULL };
const Event_data_CFL_t qbnxmmdttt = { 105, false, NULL };
const Event_data_CFL_t tvbdrlsryj = { 111, false, NULL };
const Event_data_CFL_t gdftubplny = { 112, false, NULL };
const Event_data_CFL_t eiihnlpdaa = { 113, false, NULL };

const char test_data_11[] = "state 1 debug message";
const char test_data_21[] = "state 2 debug message";
const char test_data_31[] = "state 3 debug message";
const char test_data_41[] = "state 4 debug message";
static const char *lhkffqpztd = "start column";

const unsigned short  fbqidqnmrt[] = {0};

enable_disable_sm_CFL_t wsplwkrnxh = {1,fbqidqnmrt };
static const unsigned short rxqsjdcduu[] = { 1};
const Enable_column_CFL_t czrjfehhsn = { true, 1, rxqsjdcduu };


unsigned  iwxiggfpbp;
const While_time_control_ROM_CFL_t cyspdlians = { 60000,&iwxiggfpbp };



static While_control_RAM_CFL_t dbnqllvagu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ysjciuuahp_rom = { 0 ,true, &cyspdlians,&dbnqllvagu_ram,null_function};

    
static const char *tyhhyvndqw = "terminating";
static const char *bxzcrrbghk = "event generator start";


unsigned  tjbftkjbtp;
const While_time_control_ROM_CFL_t yizefkyyca = { 2000,&tjbftkjbtp };



static While_control_RAM_CFL_t tizhgzpwbd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vsxazwsrgt_rom = { 0 ,true, &yizefkyyca,&tizhgzpwbd_ram,null_function};

    
const sm_event_CFL_t dpqvvgrvdb = {0,&tvbdrlsryj};
const sm_event_CFL_t vhxpxvkkok = {0,&gdftubplny};
const sm_event_CFL_t rdlqmtewpw = {0,&eiihnlpdaa};
const sm_event_CFL_t qoxbesqlpv = {0,&qerxchsvek};
const sm_event_CFL_t ttkhyhiumw = {0,&caclydbrcf};


unsigned  riwusygdhj;
const While_time_control_ROM_CFL_t oxkfeyjjfk = { 2000,&riwusygdhj };



static While_control_RAM_CFL_t lfuqoghbpi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pixgqbtydf_rom = { 0 ,true, &oxkfeyjjfk,&lfuqoghbpi_ram,null_function};

    
const sm_event_CFL_t vflzxiazzo = {0,&tvbdrlsryj};
const sm_event_CFL_t azldspajqe = {0,&gdftubplny};
const sm_event_CFL_t ghcxssgcak = {0,&eiihnlpdaa};
const sm_event_CFL_t amcwmeccmo = {0,&qerxchsvek};
const sm_event_CFL_t pyhoucopws = {0,&vkpzumszbm};


unsigned  vqxqtyrgsk;
const While_time_control_ROM_CFL_t ecwgnbpfmw = { 2000,&vqxqtyrgsk };



static While_control_RAM_CFL_t wphnbomudp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fpmydshcfx_rom = { 0 ,true, &ecwgnbpfmw,&wphnbomudp_ram,null_function};

    
const sm_event_CFL_t guyiwsqzfv = {0,&tvbdrlsryj};
const sm_event_CFL_t yiphhanems = {0,&gdftubplny};
const sm_event_CFL_t waqdyvtbzk = {0,&eiihnlpdaa};
const sm_event_CFL_t mbkfqjryot = {0,&qerxchsvek};
const sm_event_CFL_t mmspqcoems = {0,&ssjgzyyyii};


unsigned  obojymjfzn;
const While_time_control_ROM_CFL_t ycctubngbr = { 2000,&obojymjfzn };



static While_control_RAM_CFL_t fcplrliafb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t iobkxbljke_rom = { 0 ,true, &ycctubngbr,&fcplrliafb_ram,null_function};

    
const sm_event_CFL_t hhxeuipgfa = {0,&tvbdrlsryj};
const sm_event_CFL_t elcjharief = {0,&gdftubplny};
const sm_event_CFL_t ztvaimljjw = {0,&eiihnlpdaa};
const sm_event_CFL_t eatsaokbof = {0,&qerxchsvek};
const sm_event_CFL_t aysxfbjmlw = {0,&qbnxmmdttt};
static const char *ialncltyyj = "state machine manager starting";
const change_sm_state_CFL_t xyywczknks = {0,0};
const unsigned short qcabiuepjk[] = {101};
const state_change_CFL_t euvhsbgxor = {0,0,1,qcabiuepjk};
const unsigned short mqfwukcwan[] = {102};
const state_change_CFL_t tutyefsovh = {0,1,1,mqfwukcwan};
const unsigned short nsfpiovlwb[] = {103};
const state_change_CFL_t rcvntkieif = {0,2,1,nsfpiovlwb};
const unsigned short kkeecujqsn[] = {104};
const state_change_CFL_t lhuilpcekf = {0,3,1,kkeecujqsn};
const redirect_CFL_t fuheglbogy = {0,NULL};
static const char *wtmzodeyfg = "state 1 starting";
const SM_debug_CFL_t adnkddczec = {0,0,test_data_11};
static const char *nignegcsvq = "state 2 starting";
const SM_debug_CFL_t ucxycvqrpw = {0,1,test_data_21};
static const char *piswlcgcai = "state 3 starting";
const SM_debug_CFL_t oyjaqeenpb = {0,2,test_data_31};
static const char *hjxlfkojqr = "state 4 starting";
const SM_debug_CFL_t jmrhsvpmye = {0,3,test_data_41};


//----------RAM data structures for columns ----

unsigned xzlyrovqse[7];
Watch_dog_struct_CFL_t * wzhqhzxoss[7];
unsigned char uykhlmztfp[7];
unsigned char mkoksiofhu[7];
void* xvgxyaibzi[7];
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

static const Column_ROM_CFL_t fpshcylajf[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 26, 6, -1, -1 },
  { 1,false, 2, 8, 32, -1, -1 },
  { 2,false, 3, 3, 40, -1, -1 },
  { 3,false, 4, 3, 43, -1, -1 },
  { 4,false, 5, 3, 46, -1, -1 },
  { 5,false, 6, 3, 49, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char cmtnbmxuul[52];


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

static const Column_element_CFL_t akvepbnzrp[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&lhkffqpztd},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&wsplwkrnxh},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&czrjfehhsn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ysjciuuahp_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tyhhyvndqw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bxzcrrbghk},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vsxazwsrgt_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dpqvvgrvdb},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vhxpxvkkok},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&rdlqmtewpw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qoxbesqlpv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ttkhyhiumw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pixgqbtydf_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&vflzxiazzo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&azldspajqe},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ghcxssgcak},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&amcwmeccmo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pyhoucopws},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fpmydshcfx_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&guyiwsqzfv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&yiphhanems},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&waqdyvtbzk},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mbkfqjryot},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mmspqcoems},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&iobkxbljke_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hhxeuipgfa},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&elcjharief},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ztvaimljjw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&eatsaokbof},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&aysxfbjmlw},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ialncltyyj},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&xyywczknks},
    {state_change_CFL,NULL,(void *)&euvhsbgxor},
    {state_change_CFL,NULL,(void *)&tutyefsovh},
    {state_change_CFL,NULL,(void *)&rcvntkieif},
    {state_change_CFL,NULL,(void *)&lhuilpcekf},
    {redirect_event_CFL,true_constant_handler,(void *)&fuheglbogy},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wtmzodeyfg},
    {SM_debug_CFL,true_constant_handler,(void *)&adnkddczec},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nignegcsvq},
    {SM_debug_CFL,true_constant_handler,(void *)&ucxycvqrpw},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&piswlcgcai},
    {SM_debug_CFL,true_constant_handler,(void *)&oyjaqeenpb},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hjxlfkojqr},
    {SM_debug_CFL,true_constant_handler,(void *)&jmrhsvpmye},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short qvvfueivnt[4] = {2,3,4,5,};
short sbwdrdlowq[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t zumrzhbdrj[1] = {
{0,1,2,4,sbwdrdlowq,qvvfueivnt,(void *)test_data_2},
}; 
Sm_control_RAM_CFL_t mwcgcazsju[1];


static Time_control_CFL_t cddcxtyinz;




static Engine_control_CFL_t knfjtqxmfd;


/* remaining allocate heap size */

static unsigned fxakjsopox;


/* current heap pointer */

static char* qiqgqznteo;


/* heap block area */

static CS_MEMORY_CONTROL fshecdjhod;


    
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


const struct Handle_CFL_t yocfcdstba =
{

  .queue_number = 6,
  .queue_rom = drwpujgwqq,
  .queue_ram = shqzrhwgew,

  .column_elements_flags =cmtnbmxuul,
  .column_elements_ROM = akvepbnzrp,

  .watch_dog_struct = wzhqhzxoss,
  .watch_dog_count  = xzlyrovqse,
   
   
  .column_flags = uykhlmztfp,
  .column_local_data = xvgxyaibzi,
  .column_state = mkoksiofhu,
  .number_of_columns = 7,
  .column_rom_data = fpshcylajf,

  
  
  
  .time_control = &cddcxtyinz,
  .engine_control =&knfjtqxmfd,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &fxakjsopox,
  .current_heap_location = &qiqgqznteo,
  .private_heap   = &fshecdjhod,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  zumrzhbdrj,
   .sm_ram     = mwcgcazsju,
} ;


const Handle_CFL_t*  state_machine_2_handle(){
    return &yocfcdstba;
}
   

#ifdef __cplusplus
}
#endif

#endif
