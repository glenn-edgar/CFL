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



//----------User code ----


static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";
#include <unistd.h>

void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}


static const char *mrspzbjazs = "this is a test message";


unsigned short nnarfgozem;
static const While_time_control_ROM_CFL_t oigvbwyrjl = { 2000,&nnarfgozem };



static While_control_RAM_CFL_t dxtuvpriah_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t scyiozdliz_rom = { 0 ,true, &oigvbwyrjl,&dxtuvpriah_ram,null_function};

    
static const char *qchbmlxqvv = "test_halt_column";
static const char *hicrljjjye = "test_terminate_column";


unsigned short orurvswmzu;
const While_time_control_ROM_CFL_t ayafoihxtv = { 7500,&orurvswmzu };



static While_control_RAM_CFL_t hiqnztsgde_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t eyvwrydoxf_rom = { 0 ,true, &ayafoihxtv,&hiqnztsgde_ram,null_function};

    
static const char *bdqoanvpnn = "column3 is terminating";
static const char *mievvabhuq = "test_terminate_engine";


unsigned short gvqckdedhq;
const While_time_control_ROM_CFL_t dxzxzzuiin = { 10000,&gvqckdedhq };



static While_control_RAM_CFL_t tqtmptrhlk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nshkybecgr_rom = { 0 ,true, &dxzxzzuiin,&tqtmptrhlk_ram,null_function};

    
static const char *yhueotvgui = "column4 is terminating engine";


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


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[4];
unsigned char column_RAM_new_state[4];
void* column_RAM_local_data[4];
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
  { 1,true, 0, 5, 0, -1, -1,-1 },
  { 2,true, 1, 2, 5, -1, -1,-1 },
  { 3,true, 2, 4, 7, -1, -1,-1 },
  { -1,true, 3, 4, 11, -1, -1,-1 },
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

  

static unsigned char column_element_RAM[15];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&mrspzbjazs},
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message},
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&scyiozdliz_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qchbmlxqvv},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hicrljjjye},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&eyvwrydoxf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bdqoanvpnn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mievvabhuq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nshkybecgr_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yhueotvgui},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
};


static Time_control_CFL_t bydmvorwqb;




static Engine_control_CFL_t nnfrrhczvg;


/*allocate once heap space */

static char ueqxwufgly[2000];


/* remaining allocate heap size */

static unsigned csevuiujvi;


/* current heap pointer */

static char* cgswmxdmlv;


/* heap block area */

static CS_MEMORY_CONTROL zcppapwhzm;


/* heap storeage area */

static char jxzddvrqlq[1000];



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t gknupshhpw =
{

  .queue_rom    = &queue_control,
  .queue_ram = event_control_ram,
  .event_data = event_data_array,

  .column_elements_flags =column_element_RAM ,
  .column_elements_ROM = column_elements_ROM,

  .column_flags = column_RAM_flags,
  .column_local_data = column_RAM_local_data,
  .column_state = column_RAM_new_state,
  .number_of_columns = 4,
  .column_rom_data = column_data_ROM,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &bydmvorwqb,
  .engine_control =&nnfrrhczvg,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = ueqxwufgly,
  .master_heap_size = 2000,
  .remaining_heap_size = &csevuiujvi,
  .current_heap_location = &cgswmxdmlv,
  .private_heap   = &zcppapwhzm,
  .working_heap_area   = jxzddvrqlq,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  Get_handle_CFL(){
    return &gknupshhpw;
}
#endif
