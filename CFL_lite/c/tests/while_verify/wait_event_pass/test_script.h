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

const Event_data_CFL_t user_test_event = { test_event, false, NULL, };
static const char *uotiesmxua = "this column will generate an event every second";


unsigned  jjjhgylhxo;
const While_time_control_ROM_CFL_t mfmyboqtmf = { 1000,&jjjhgylhxo };



static While_control_RAM_CFL_t gdfzztjyas_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xozipynbgh_rom = { 0 ,true, &mfmyboqtmf,&gdfzztjyas_ram,null_function};

    
static const char *thiizbmyaq = "sending event";
static const char *ptkotesjmc = "this column will wait for to events and then stop the engine";
 unsigned sikziiwzvs_ram;
const While_event_control_ROM_t sikziiwzvs_rom = { 10,test_event,11000,true,NULL,&sikziiwzvs_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t kzblvxqqgf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ztaxfbpulx_rom = { 11000 ,true, &sikziiwzvs_rom,&kzblvxqqgf_ram,null_function};

    
static const char *qufnekbdtf = "10 events have been received";
static const char *nwsvdziais = "stopping engine";


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[2];
unsigned char column_RAM_new_state[2];
void* column_RAM_local_data[2];
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
  { -1,true, 0, 5, 0, -1, -1,-1 },
  { -1,true, 1, 5, 5, -1, -1,-1 },
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

  

static unsigned char column_element_RAM[10];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&uotiesmxua},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xozipynbgh_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {one_shot_handler_CFL,log_message_CFL,(void *)&thiizbmyaq},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ptkotesjmc},
    {while_handler_CFL,wait_event_handler,(void *)&ztaxfbpulx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qufnekbdtf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nwsvdziais},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
};


static Time_control_CFL_t zjvltccgvo;




static Engine_control_CFL_t ctjgymaepm;




static Engine_control_CFL_t ctjgymaepm;


/* remaining allocate heap size */

static unsigned omepzwqjwt;


/* current heap pointer */

static char* zdbrdhyaku;


/* heap block area */

static CS_MEMORY_CONTROL ffcdhcgzon;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ekcnkfjwxb =
{

  .queue_rom    = &queue_control,
  .queue_ram = event_control_ram,
  .event_data = event_data_array,

  .column_elements_flags =column_element_RAM ,
  .column_elements_ROM = column_elements_ROM,

  .column_flags = column_RAM_flags,
  .column_local_data = column_RAM_local_data,
  .column_state = column_RAM_new_state,
  .number_of_columns = 2,
  .column_rom_data = column_data_ROM,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &zjvltccgvo,
  .engine_control =&ctjgymaepm,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &omepzwqjwt,
  .current_heap_location = &zdbrdhyaku,
  .private_heap   = &ffcdhcgzon,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &ekcnkfjwxb;
}
   

#ifdef __cplusplus
}
#endif

#endif
