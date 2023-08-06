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

static Event_data_CFL_t event_data_array[40];
static Event_control_RAM_CFL_t event_control_ram[4];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t event_control_rom_default = { 10, 0 };
static const Event_control_ROM_CFL_t event_control_rom_queue1 = { 10, 10 };
static const Event_control_ROM_CFL_t event_control_rom_queue2 = { 10, 20 };
static const Event_control_ROM_CFL_t event_control_rom_queue3 = { 10, 30 };
static const Event_control_ROM_CFL_t *queue_elements[] = {
     &event_control_rom_default,
     &event_control_rom_queue1,
     &event_control_rom_queue2,
     &event_control_rom_queue3,
};
static const Named_event_queue_control_CFL_t queue_control = { 4,40,queue_elements };


//----------User code ----


static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";


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



static const char user_test_event_data[] = "test message";

const Event_data_CFL_t user_test_event = { test_event, false, ( void *)user_test_event_data, };
static const char *ktdlbdxsmv = "this is a test message";


unsigned  qyavypxkpi;
const While_time_control_ROM_CFL_t spjiktgymd = { 2000,&qyavypxkpi };



static While_control_RAM_CFL_t mbbtunbavr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zslbojqspr_rom = { 0 ,true, &spjiktgymd,&mbbtunbavr_ram,null_function};

    
static const char *mwclltzqba = "reseting the column every 2 seconds";
static const char *nyocgmzdav = "test_halt_column";
static const char *ypqwsnfehu = "halting the column";
static const char *kbaqztsknu = "test_terminate_column";


unsigned  zdzvsqgjcn;
const While_time_control_ROM_CFL_t taywcnglhe = { 7500,&zdzvsqgjcn };



static While_control_RAM_CFL_t pvwinrgygm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dqtmrnqgcf_rom = { 0 ,true, &taywcnglhe,&pvwinrgygm_ram,null_function};

    
static const char *wykekxoxzj = "column 3 is terminating after 7.5 seconds";
static const char *lcmiemalrq = "test_terminate_engine";


unsigned  woucymsxir;
const While_time_control_ROM_CFL_t rxjdxgdzqt = { 10000,&woucymsxir };



static While_control_RAM_CFL_t ijyhtoqenj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t iasosswgcd_rom = { 0 ,true, &rxjdxgdzqt,&ijyhtoqenj_ram,null_function};

    
static const char *gbpjyjltkz = "column 4 is terminating engine after 10 seconds";
static const char *tbpemdxfjt = "test_terminate_engine 5 second termination";
 unsigned sabiyysudr_ram;
const While_event_control_ROM_t sabiyysudr_rom = { 9,test_event,0,true,NULL,&sabiyysudr_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t ihqqowmejw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ztjdglulop_rom = { 0 ,true, &sabiyysudr_rom,&ihqqowmejw_ram,null_function};

    
static const char *grkjvesndp = "column 5 is terminating engine after 9 events";


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
  { 1,true, 0, 8, 0, -1, -1,-1 },
  { 2,true, 1, 3, 8, -1, -1,-1 },
  { 3,true, 2, 4, 11, -1, -1,-1 },
  { -1,true, 3, 4, 15, -1, -1,-1 },
  { -1,true, 4, 4, 19, -1, -1,-1 },
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
    {one_shot_handler_CFL,log_message_CFL,(void *)&ktdlbdxsmv},
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message},
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zslbojqspr_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mwclltzqba},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nyocgmzdav},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ypqwsnfehu},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kbaqztsknu},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dqtmrnqgcf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wykekxoxzj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lcmiemalrq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&iasosswgcd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gbpjyjltkz},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tbpemdxfjt},
    {while_handler_CFL,wait_event_handler,(void *)&ztjdglulop_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&grkjvesndp},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t vuqttsjvpx;




static Engine_control_CFL_t eyhywaravs;




static Engine_control_CFL_t eyhywaravs;


/* remaining allocate heap size */

static unsigned huoheplpcm;


/* current heap pointer */

static char* zlvoyiqooe;


/* heap block area */

static CS_MEMORY_CONTROL xkoxshggqj;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t qvlsoxomwz =
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
  .time_control = &vuqttsjvpx,
  .engine_control =&eyhywaravs,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &huoheplpcm,
  .current_heap_location = &zlvoyiqooe,
  .private_heap   = &xkoxshggqj,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &qvlsoxomwz;
}
   

#ifdef __cplusplus
}
#endif

#endif
