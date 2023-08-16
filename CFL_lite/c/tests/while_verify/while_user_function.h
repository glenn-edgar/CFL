#ifndef __while_user_function_H__
#define __while_user_function_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define mswedciswi 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t ghapgoydvy[10];
static Event_control_RAM_CFL_t hhzdgxodjz[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t wuvulvzrob_default = { 10, 0 };
static const Event_control_ROM_CFL_t *wuvulvzrob[] = {
     &wuvulvzrob_default,
};
static const Named_event_queue_control_CFL_t bbbmjkxzol = { 1,10,wuvulvzrob };
const Event_data_CFL_t wjzxzwbyjy = { mswedciswi, false, NULL, };

static unsigned test_counter = 0;



static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
static const char *rvlmvsaxvz = "this column will terminate the engine";


unsigned  csqsrbjthh;
const While_time_control_ROM_CFL_t axzfatnixl = { 16000,&csqsrbjthh };



static While_control_RAM_CFL_t dkmpvinacl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kjlggvybru_rom = { 0 ,true, &axzfatnixl,&dkmpvinacl_ram,null_function};

    
static const char *jcswjukkdc = "stopping engine because 16 seconds have passed";
static const char *prppssyjse = "this column will generate an event every second";


unsigned  zmctgmtmqb;
const While_time_control_ROM_CFL_t wlflhxkjkh = { 1000,&zmctgmtmqb };



static While_control_RAM_CFL_t ssahrwykrv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kuvyegutpt_rom = { 0 ,true, &wlflhxkjkh,&ssahrwykrv_ram,null_function};

    
static const char *hclqdpuqsz = "sending event";
static const char *treiscuxtf = "user function column is starting";

static While_control_RAM_CFL_t qkjyovxjsu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zaqowyucoc_rom = { 0 ,false, &test_counter,&qkjyovxjsu_ram,null_function};

    
static const char *raesofbkbs = "user function has passed";
static const char *nhbnliehgi = "terminating column";
static const char *ykosoppdqp = "this demonstrates the reset feature of the wait opcode";

static While_control_RAM_CFL_t gznndevczq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t efjafxqvin_rom = { 5000 ,false, &wait_event_reset_message,&gznndevczq_ram,wait_event_reset};

    
static const char *cxcvjyqiei = "10 events have been received";
static const char *osjpjzgsqw = "terminating column";
static const char *xocofrndpa = "this demonstrates the terminate feature of the wait opcode";

static While_control_RAM_CFL_t tsyknavxog_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t doydrwonac_rom = { 5000 ,true, &wait_event_terminate_message,&tsyknavxog_ram,wait_event_terminate};

    
static const char *dtxhqplhvv = "This step should not happpen as the wait opcode will reset because of timeout";


//----------RAM data structures for columns ----

unsigned char hunjqfokon[5];
unsigned char hbzxjiapfk[5];
void* hwbsawfgot[5];
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

static const Column_ROM_CFL_t hyxnwejwfo[] = {
  { -1,true, 0, 4, 0, -1, -1,-1 },
  { -1,true, 1, 5, 4, -1, -1,-1 },
  { -1,true, 2, 5, 9, -1, -1,-1 },
  { -1,true, 3, 4, 19, -1, -1,-1 },
  { -1,true, 4, 5, 14, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char hqkbunonoy[23];


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

static const Column_element_CFL_t ddwykbqheg[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&rvlmvsaxvz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kjlggvybru_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jcswjukkdc},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&prppssyjse},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kuvyegutpt_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&wjzxzwbyjy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hclqdpuqsz},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&treiscuxtf},
    {while_handler_CFL,test_bool_fn,(void *)&zaqowyucoc_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&raesofbkbs},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nhbnliehgi},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ykosoppdqp},
    {while_handler_CFL,false_constant_handler,(void *)&efjafxqvin_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cxcvjyqiei},
    {one_shot_handler_CFL,log_message_CFL,(void *)&osjpjzgsqw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xocofrndpa},
    {while_handler_CFL,false_constant_handler,(void *)&doydrwonac_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dtxhqplhvv},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t rvbifmkcme;




static Engine_control_CFL_t kirqirmalg;


/* remaining allocate heap size */

static unsigned cmnuykiaky;


/* current heap pointer */

static char* uryzdihens;


/* heap block area */

static CS_MEMORY_CONTROL aiwxkzrdkp;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t tpetfrrkhg =
{

  .queue_rom    = &bbbmjkxzol,
  .queue_ram =  hhzdgxodjz,
  .event_data = ghapgoydvy,

  .column_elements_flags =hqkbunonoy,
  .column_elements_ROM = ddwykbqheg,

  .column_flags = hunjqfokon,
  .column_local_data = hwbsawfgot,
  .column_state = hbzxjiapfk,
  .number_of_columns = 5,
  .column_rom_data = hyxnwejwfo,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &rvbifmkcme,
  .engine_control =&kirqirmalg,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &cmnuykiaky,
  .current_heap_location = &uryzdihens,
  .private_heap   = &aiwxkzrdkp,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  while_user_function_handle(){
    return &tpetfrrkhg;
}
   

#ifdef __cplusplus
}
#endif

#endif
