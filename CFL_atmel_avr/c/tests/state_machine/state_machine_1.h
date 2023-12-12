#ifndef __state_machine_1_H__
#define __state_machine_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


const char test_data[] = "test_data\n";
#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t selblfrswn[6];
static Event_data_CFL_t unludiohlr[10];
static Event_data_CFL_t dphbkgtghd[10];
static Event_data_CFL_t dyvlbhgqqc[10];
static Event_data_CFL_t vuzlfdenfo[10];
static Event_data_CFL_t oodivaqhhr[10];
static Event_data_CFL_t bbzqkxlker[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t rroevkczdy[] = { 
     {  10, unludiohlr },
     {  10, dphbkgtghd },
     {  10, dyvlbhgqqc },
     {  10, vuzlfdenfo },
     {  10, oodivaqhhr },
     {  10, bbzqkxlker },
};
static const char *atiqvahisz = "start column";

const unsigned short  qckyjntois[] = {0};

enable_disable_sm_CFL_t yhzccefitq = {1,qckyjntois };


unsigned  oenknovkzy;
const While_time_control_ROM_CFL_t kxloyxuzow = { 20000,&oenknovkzy };



static While_control_RAM_CFL_t jbfltvbhdp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t opjotehprq_rom = { 0 ,true, &kxloyxuzow,&jbfltvbhdp_ram,null_function};

    
static const char *jkvzfmuurq = "terminating";
static const char *szulmhdjqn = "state machine manager starting";


unsigned  flywdwxipc;
const While_time_control_ROM_CFL_t tiehtybjfr = { 2000,&flywdwxipc };



static While_control_RAM_CFL_t yolfztkoll_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pkvxbpejtd_rom = { 0 ,true, &tiehtybjfr,&yolfztkoll_ram,null_function};

    
const change_sm_state_CFL_t nlxovdsmpy = {0,0};
static const char *eiyrxzwtxn = "this message should not be printed";
static const char *plspeftyjt = "state 1 starting";


unsigned  xtfrrhftxt;
const While_time_control_ROM_CFL_t dvgojzaxee = { 2000,&xtfrrhftxt };



static While_control_RAM_CFL_t fvmzzfhgtj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t butvrarfxi_rom = { 0 ,true, &dvgojzaxee,&fvmzzfhgtj_ram,null_function};

    
const change_sm_state_CFL_t aaxygcwhlh = {0,1};
static const char *pncsdfqvsw = "this message should not be printed";
static const char *rdcvfdukir = "state 2 starting";


unsigned  jvfcgxlrjx;
const While_time_control_ROM_CFL_t bpbjgjvonn = { 2000,&jvfcgxlrjx };



static While_control_RAM_CFL_t nsaececalb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nwtvlqwodl_rom = { 0 ,true, &bpbjgjvonn,&nsaececalb_ram,null_function};

    
const change_sm_state_CFL_t riqcbqspng = {0,2};
static const char *hyjwvaiguq = "this message should not be printed";
static const char *evwpmztxam = "state 3 starting";


unsigned  ydahjiqtmy;
const While_time_control_ROM_CFL_t loomnooxtc = { 2000,&ydahjiqtmy };



static While_control_RAM_CFL_t bgiakxmcrz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t djnqykaxur_rom = { 0 ,true, &loomnooxtc,&bgiakxmcrz_ram,null_function};

    
const change_sm_state_CFL_t cqvhlxrocm = {0,3};
static const char *nhtdqjvpky = "this message should not be printed";
static const char *epvvlpydlc = "state 4 starting";


unsigned  uoqzzxemym;
const While_time_control_ROM_CFL_t bduuuerdpk = { 2000,&uoqzzxemym };



static While_control_RAM_CFL_t sncabfzwwd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jmgtjnuxfg_rom = { 0 ,true, &bduuuerdpk,&sncabfzwwd_ram,null_function};

    
const change_sm_state_CFL_t pqkegxayay = {0,0};
static const char *ywextvfxap = "this message should not be printed";


//----------RAM data structures for columns ----

unsigned zyxmkapges[6];
Watch_dog_struct_CFL_t * qkhfsxmnle[6];
unsigned char nkyrbmpnof[6];
unsigned char kngybahxdj[6];
void* rsbqtsfmkt[6];
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

static const Column_ROM_CFL_t klhnknmudl[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { 1,false, 1, 5, 5, -1, -1 },
  { 2,false, 2, 5, 10, -1, -1 },
  { 3,false, 3, 5, 15, -1, -1 },
  { 4,false, 4, 5, 20, -1, -1 },
  { 5,false, 5, 5, 25, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char bzqkcqmwow[30];


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

static const Column_element_CFL_t uzrhrdmgtj[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&atiqvahisz},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&yhzccefitq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&opjotehprq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jkvzfmuurq},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&szulmhdjqn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pkvxbpejtd_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&nlxovdsmpy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&eiyrxzwtxn},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&plspeftyjt},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&butvrarfxi_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&aaxygcwhlh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pncsdfqvsw},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rdcvfdukir},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nwtvlqwodl_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&riqcbqspng},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hyjwvaiguq},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&evwpmztxam},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&djnqykaxur_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&cqvhlxrocm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nhtdqjvpky},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&epvvlpydlc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jmgtjnuxfg_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&pqkegxayay},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ywextvfxap},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
Bitmap_CFL pnpparwttg[0];
short nffiuvdhgx[4] = {2,3,4,5,};
short mxtiogypzb[4] = {2,3,4,5,};
const Sm_control_ROM_CFL_t cbmgtjbkra[1] = {
{0,1,1,4,mxtiogypzb,nffiuvdhgx,(void *)test_data},
}; 
Sm_control_RAM_CFL_t lqziltexio[1];


static Time_control_CFL_t wbmsjwijig;




static Engine_control_CFL_t cnwjaauuiu;


/* remaining allocate heap size */

static unsigned yhinydhjfj;


/* current heap pointer */

static char* hbsrhpbmgx;


/* heap block area */

static CS_MEMORY_CONTROL eqaoxkaguy;


    
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


const struct Handle_CFL_t xbfmoiqrdi =
{

  .queue_number = 6,
  .queue_rom = rroevkczdy,
  .queue_ram = selblfrswn,

  .column_elements_flags =bzqkcqmwow,
  .column_elements_ROM = uzrhrdmgtj,

  .watch_dog_struct = qkhfsxmnle,
  .watch_dog_count  = zyxmkapges,
   
   
  .column_flags = nkyrbmpnof,
  .column_local_data = rsbqtsfmkt,
  .column_state = kngybahxdj,
  .number_of_columns = 6,
  .column_rom_data = klhnknmudl,

  
  
  
  .time_control = &wbmsjwijig,
  .engine_control =&cnwjaauuiu,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &yhinydhjfj,
  .current_heap_location = &hbsrhpbmgx,
  .private_heap   = &eqaoxkaguy,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  cbmgtjbkra,
   .sm_ram     = lqziltexio,
   .number_of_bitmaps = 0,
    .bitmaps = pnpparwttg,
} ;


const Handle_CFL_t*  state_machine_1_handle(){
    return &xbfmoiqrdi;
}
   

#ifdef __cplusplus
}
#endif

#endif
