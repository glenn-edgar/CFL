#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"

static const int reset_buffer[1] = { RESET_CFL };
static const int halt_buffer[1] = { HALT_CFL };
static const int terminate_buffer[1] = { TERMINATE_CFL };
static const int terminate_engine_buffer[1] = { ENGINE_TERMINATE_CFL };



//nuser defined events 



 #define test_event 100 


//----------RAM data structures for event queues ----

static Event_data_CFL_t event_data_array[10];
static Event_control_RAM_CFL_t event_control_ram[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t event_control_rom_default = { 10, 0 };
static const Event_control_ROM_CFL_t *queue_elements[] = {
     &event_control_rom_default,
};
static const Named_event_queue_control_CFL_t queue_control = { 1,10,queue_elements };


//----------User code ----

const Event_data_CFL_t user_test_event = { test_event, false, NULL, };

static unsigned test_counter = 0;

void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}
char *allocate_once_memory = NULL;

void create_allocate_once_heap(){
    allocate_once_memory = (char *)malloc(2000);
}

void free_allocate_once_heap(){
    free(allocate_once_memory);
}

static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
static const char *wrsncljvqy = "this column will terminate the engine";


unsigned  odwggbeoqj;
const While_time_control_ROM_CFL_t esblxcympy = { 16000,&odwggbeoqj };



static While_control_RAM_CFL_t eewgnizawr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t essvkdipmz_rom = { 0 ,true, &esblxcympy,&eewgnizawr_ram,null_function};

    
static const char *wvdmxqlesn = "stopping engine because 16 seconds have passed";
static const char *efjidnnqib = "this column will generate an event every second";


unsigned  uobgzypyto;
const While_time_control_ROM_CFL_t aqryrfcfgi = { 1000,&uobgzypyto };



static While_control_RAM_CFL_t xtcyurlcya_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t axwfotszvb_rom = { 0 ,true, &aqryrfcfgi,&xtcyurlcya_ram,null_function};

    
static const char *pshybgpqgh = "sending event";
static const char *bnelamzdsj = "user function column is starting";

static While_control_RAM_CFL_t mznnjypvjf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bbcbupdiqq_rom = { 0 ,false, &test_counter,&mznnjypvjf_ram,null_function};

    
static const char *eypvammjnn = "user function has passed";
static const char *wfyvinfkya = "terminating column";
static const char *pnxriurprh = "this demonstrates the reset feature of the wait opcode";

static While_control_RAM_CFL_t rogyejcdml_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vnvkriwstl_rom = { 5000 ,false, &wait_event_reset_message,&rogyejcdml_ram,wait_event_reset};

    
static const char *pygyzeltnd = "10 events have been received";
static const char *fzaznleywy = "terminating column";
static const char *newdywusyw = "this demonstrates the terminate feature of the wait opcode";

static While_control_RAM_CFL_t qctxozqnzk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ktwymswwkn_rom = { 5000 ,true, &wait_event_terminate_message,&qctxozqnzk_ram,wait_event_terminate};

    
static const char *xenbhzecvx = "This step should not happpen as the wait opcode will reset because of timeout";


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[5];
unsigned char column_RAM_new_state[5];
void* column_RAM_local_data[5];
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

static const Column_ROM_CFL_t column_data_ROM[] = {
  { -1,true, 0, 4, 0, -1, -1,-1 },
  { -1,true, 1, 5, 4, -1, -1,-1 },
  { -1,true, 2, 5, 9, -1, -1,-1 },
  { -1,true, 3, 4, 19, -1, -1,-1 },
  { -1,true, 4, 5, 14, -1, -1,-1 },
};

  /* 
  ------------------------ Column element structure --------------------------
     typedef struct Column_element_CFL_t {
        Column_function_CFL_t column_function;
        void *aux_fn;
        void *params
     } Column_element_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

  

static unsigned char column_element_RAM[23];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&wrsncljvqy},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&essvkdipmz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wvdmxqlesn},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&efjidnnqib},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&axwfotszvb_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pshybgpqgh},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bnelamzdsj},
    {while_handler_CFL,test_bool_fn,(void *)&bbcbupdiqq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&eypvammjnn},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wfyvinfkya},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pnxriurprh},
    {while_handler_CFL,false_constant_handler,(void *)&vnvkriwstl_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pygyzeltnd},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fzaznleywy},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&newdywusyw},
    {while_handler_CFL,false_constant_handler,(void *)&ktwymswwkn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xenbhzecvx},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t exkfbrtexq;




static Engine_control_CFL_t rajegoyapr;




static Engine_control_CFL_t rajegoyapr;


/* remaining allocate heap size */

static unsigned gcaihxrrcu;


/* current heap pointer */

static char* kqriobvuym;


/* heap block area */

static CS_MEMORY_CONTROL hnmabsmait;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t aasfbgcbux =
{

  .queue_rom    = &queue_control,
  .queue_ram = event_control_ram,
  .event_data = event_data_array,

  .column_elements_flags =column_element_RAM ,
  .column_elements_ROM = column_elements_ROM,

  .column_flags = column_RAM_flags,
  .column_local_data = column_RAM_local_data,
  .column_state = column_RAM_new_state,
  .number_of_columns = 5,
  .column_rom_data = column_data_ROM,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &exkfbrtexq,
  .engine_control =&rajegoyapr,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &gcaihxrrcu,
  .current_heap_location = &kqriobvuym,
  .private_heap   = &hnmabsmait,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &aasfbgcbux;
}
   

#ifdef __cplusplus
}
#endif

#endif
