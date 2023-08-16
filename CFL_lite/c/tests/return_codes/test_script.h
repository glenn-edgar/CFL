#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define pgfonxkoai 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t zfguzxhvim[40];
static Event_control_RAM_CFL_t qhdafifydo[4];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t zynxwvdpub_default = { 10, 0 };
static const Event_control_ROM_CFL_t zynxwvdpub_queue1 = { 10, 10 };
static const Event_control_ROM_CFL_t zynxwvdpub_queue2 = { 10, 20 };
static const Event_control_ROM_CFL_t zynxwvdpub_queue3 = { 10, 30 };
static const Event_control_ROM_CFL_t *zynxwvdpub[] = {
     &zynxwvdpub_default,
     &zynxwvdpub_queue1,
     &zynxwvdpub_queue2,
     &zynxwvdpub_queue3,
};
static const Named_event_queue_control_CFL_t ykivzpcsgg = { 4,40,zynxwvdpub };
static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";
static const char user_test_event_data[] = "test message";
const Event_data_CFL_t wxtmwwdqrp = { pgfonxkoai, false, ( void *)user_test_event_data, };
static const char *amkuwgqtkv = "this is a test message";


unsigned  tlnfukhlto;
const While_time_control_ROM_CFL_t lctewetlbp = { 2000,&tlnfukhlto };



static While_control_RAM_CFL_t iedbivrsjy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cpikaofaay_rom = { 0 ,true, &lctewetlbp,&iedbivrsjy_ram,null_function};

    
static const char *uztokcufzl = "reseting the column every 2 seconds";
static const char *ojwqkyazeo = "test_halt_column";
static const char *gtikeugbaq = "halting the column";
static const char *yjlmomymcs = "test_terminate_column";


unsigned  rfeoaejiiw;
const While_time_control_ROM_CFL_t zybhqbhrju = { 7500,&rfeoaejiiw };



static While_control_RAM_CFL_t sabnwrgmow_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t aimfwfzzce_rom = { 0 ,true, &zybhqbhrju,&sabnwrgmow_ram,null_function};

    
static const char *rlkavsdjym = "column 3 is terminating after 7.5 seconds";
static const char *fptmijxzjj = "test_terminate_engine";


unsigned  wvjawouyla;
const While_time_control_ROM_CFL_t aoezlwbgie = { 10000,&wvjawouyla };



static While_control_RAM_CFL_t geptxecqxl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vkcofgjjdh_rom = { 0 ,true, &aoezlwbgie,&geptxecqxl_ram,null_function};

    
static const char *jswqezyvyg = "column 4 is terminating engine after 10 seconds";
static const char *xqisvauzuz = "test_terminate_engine 5 second termination";
 unsigned ymxkvdzfht_ram;
const While_event_control_ROM_t ymxkvdzfht_rom = { 9,pgfonxkoai,0,true,NULL,&ymxkvdzfht_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t ocekuzvimg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wjaieunaqs_rom = { 0 ,true, &ymxkvdzfht_rom,&ocekuzvimg_ram,null_function};

    
static const char *vexbqvymdo = "column 5 is terminating engine after 9 events";


//----------RAM data structures for columns ----

unsigned char whnmjlvqtr[5];
unsigned char xzqalhjuyh[5];
void* egrapovjje[5];
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
  short watch_dog_id;
} Column_ROM_CFL_t;

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t drilghesgu[] = {
  { 1,true, 0, 8, 0, -1, -1,-1 },
  { 2,true, 1, 3, 8, -1, -1,-1 },
  { 3,true, 2, 4, 11, -1, -1,-1 },
  { -1,true, 3, 4, 15, -1, -1,-1 },
  { -1,true, 4, 4, 19, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char buztsdkvmw[23];


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

static const Column_element_CFL_t kzsidtthla[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&amkuwgqtkv},
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message},
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message},
    {one_shot_handler_CFL,send_event_CFL,(void *)&wxtmwwdqrp},
    {one_shot_handler_CFL,send_event_CFL,(void *)&wxtmwwdqrp},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cpikaofaay_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uztokcufzl},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ojwqkyazeo},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gtikeugbaq},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yjlmomymcs},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&aimfwfzzce_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rlkavsdjym},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fptmijxzjj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vkcofgjjdh_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jswqezyvyg},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xqisvauzuz},
    {while_handler_CFL,wait_event_handler,(void *)&wjaieunaqs_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vexbqvymdo},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t vmhdncjskc;




static Engine_control_CFL_t fhbaucvmpg;


/* remaining allocate heap size */

static unsigned tigarefczn;


/* current heap pointer */

static char* gapsswgmwx;


/* heap block area */

static CS_MEMORY_CONTROL pikbcpwxtk;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t kuwlesovld =
{

  .queue_rom    = &ykivzpcsgg,
  .queue_ram =  qhdafifydo,
  .event_data = zfguzxhvim,

  .column_elements_flags =buztsdkvmw,
  .column_elements_ROM = kzsidtthla,

  .column_flags = whnmjlvqtr,
  .column_local_data = egrapovjje,
  .column_state = xzqalhjuyh,
  .number_of_columns = 5,
  .column_rom_data = drilghesgu,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &vmhdncjskc,
  .engine_control =&fhbaucvmpg,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &tigarefczn,
  .current_heap_location = &gapsswgmwx,
  .private_heap   = &pikbcpwxtk,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &kuwlesovld;
}
   

#ifdef __cplusplus
}
#endif

#endif
