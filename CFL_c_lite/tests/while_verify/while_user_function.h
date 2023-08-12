#ifndef __while_user_function_H__
#define __while_user_function_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define kaamqdeqho 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t oyifkwnxqn[10];
static Event_control_RAM_CFL_t znwjqpnotn[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hugrcwnuhc_default = { 10, 0 };
static const Event_control_ROM_CFL_t *hugrcwnuhc[] = {
     &hugrcwnuhc_default,
};
static const Named_event_queue_control_CFL_t uxpqspnvbv = { 1,10,hugrcwnuhc };
const Event_data_CFL_t ovhropofxe = { kaamqdeqho, false, NULL, };

static unsigned test_counter = 0;



static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
static const char *cbiyweddzc = "this column will terminate the engine";


unsigned  oemxksjhkq;
const While_time_control_ROM_CFL_t ytpruaqhgv = { 16000,&oemxksjhkq };



static While_control_RAM_CFL_t engaplxijj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pjwdwkbqkf_rom = { 0 ,true, &ytpruaqhgv,&engaplxijj_ram,null_function};

    
static const char *dfjeknjwuc = "stopping engine because 16 seconds have passed";
static const char *yxhwwqhyyd = "this column will generate an event every second";


unsigned  kgfkjyrehq;
const While_time_control_ROM_CFL_t soguqxhmuz = { 1000,&kgfkjyrehq };



static While_control_RAM_CFL_t xiqcfmqdas_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yelouybfyh_rom = { 0 ,true, &soguqxhmuz,&xiqcfmqdas_ram,null_function};

    
static const char *mnxcitulxa = "sending event";
static const char *xudqnjpmyi = "user function column is starting";

static While_control_RAM_CFL_t mgqzoqoknc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rgrewqvlbu_rom = { 0 ,false, &test_counter,&mgqzoqoknc_ram,null_function};

    
static const char *xmbwstfrpy = "user function has passed";
static const char *rigcfiyqwd = "terminating column";
static const char *olqiriljfd = "this demonstrates the reset feature of the wait opcode";

static While_control_RAM_CFL_t bqksbctqiq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t gtxebirjzx_rom = { 5000 ,false, &wait_event_reset_message,&bqksbctqiq_ram,wait_event_reset};

    
static const char *yjyykuubmj = "10 events have been received";
static const char *mygipzktjv = "terminating column";
static const char *cqryyxryuf = "this demonstrates the terminate feature of the wait opcode";

static While_control_RAM_CFL_t kgdcksbbwq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sftdwjmfaf_rom = { 5000 ,true, &wait_event_terminate_message,&kgdcksbbwq_ram,wait_event_terminate};

    
static const char *qirslmwdaj = "This step should not happpen as the wait opcode will reset because of timeout";


//----------RAM data structures for columns ----

unsigned char uesepblsmd[5];
unsigned char ufkceawzje[5];
void* yahqahzzwq[5];
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

static const Column_ROM_CFL_t gglavzutvp[] = {
  { -1,true, 0, 4, 0, -1, -1,-1 },
  { -1,true, 1, 5, 4, -1, -1,-1 },
  { -1,true, 2, 5, 9, -1, -1,-1 },
  { -1,true, 3, 4, 19, -1, -1,-1 },
  { -1,true, 4, 5, 14, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char pfqyxrovnn[23];


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

static const Column_element_CFL_t qlbzsauacr[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&cbiyweddzc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pjwdwkbqkf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dfjeknjwuc},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yxhwwqhyyd},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yelouybfyh_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&ovhropofxe},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mnxcitulxa},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xudqnjpmyi},
    {while_handler_CFL,test_bool_fn,(void *)&rgrewqvlbu_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xmbwstfrpy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rigcfiyqwd},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&olqiriljfd},
    {while_handler_CFL,false_constant_handler,(void *)&gtxebirjzx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yjyykuubmj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mygipzktjv},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cqryyxryuf},
    {while_handler_CFL,false_constant_handler,(void *)&sftdwjmfaf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qirslmwdaj},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t emwjyuxmjt;




static Engine_control_CFL_t ajylrlofka;




static Engine_control_CFL_t ajylrlofka;


/* remaining allocate heap size */

static unsigned xaqfldetce;


/* current heap pointer */

static char* ziwbapgpwg;


/* heap block area */

static CS_MEMORY_CONTROL biywpziyhe;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ehrmzzmars =
{

  .queue_rom    = &uxpqspnvbv,
  .queue_ram =  znwjqpnotn,
  .event_data = oyifkwnxqn,

  .column_elements_flags =pfqyxrovnn,
  .column_elements_ROM = qlbzsauacr,

  .column_flags = uesepblsmd,
  .column_local_data = yahqahzzwq,
  .column_state = ufkceawzje,
  .number_of_columns = 5,
  .column_rom_data = gglavzutvp,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &emwjyuxmjt,
  .engine_control =&ajylrlofka,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &xaqfldetce,
  .current_heap_location = &ziwbapgpwg,
  .private_heap   = &biywpziyhe,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  while_user_function_handle(){
    return &ehrmzzmars;
}
   

#ifdef __cplusplus
}
#endif

#endif
