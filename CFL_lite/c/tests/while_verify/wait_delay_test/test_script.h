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

static const char *rgdvpgantb = "this column will terminate the engine after 10 seconds";


unsigned  aryictwfmx;
const While_time_control_ROM_CFL_t yslvykfekz = { 10000,&aryictwfmx };



static While_control_RAM_CFL_t tcmaftvakz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xtnesfwrgd_rom = { 0 ,true, &yslvykfekz,&tcmaftvakz_ram,null_function};

    
static const char *btvxohwzqm = "time delay done";
static const char *ysuomszmfc = "stop engine";
static const char *ifgyzxduao = "this column will reset the engine every 2 seconds";


unsigned  dyeaqugyho;
const While_time_control_ROM_CFL_t xgxdglyotn = { 2000,&dyeaqugyho };



static While_control_RAM_CFL_t vvclzylwtq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ffybvhhtal_rom = { 0 ,true, &xgxdglyotn,&vvclzylwtq_ram,null_function};

    
static const char *svplqxqdzu = "two seconds past-- reset column";


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
  { -1,true, 1, 4, 5, -1, -1,-1 },
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

  

static unsigned char column_element_RAM[9];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&rgdvpgantb},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xtnesfwrgd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&btvxohwzqm},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ysuomszmfc},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ifgyzxduao},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ffybvhhtal_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&svplqxqdzu},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t tetexqrtnv;




static Engine_control_CFL_t leiafzsspv;




static Engine_control_CFL_t leiafzsspv;


/* remaining allocate heap size */

static unsigned msjxmxlasl;


/* current heap pointer */

static char* dbcbnfyoli;


/* heap block area */

static CS_MEMORY_CONTROL tugwnwnjyk;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t xldafkwqie =
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
  .time_control = &tetexqrtnv,
  .engine_control =&leiafzsspv,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &msjxmxlasl,
  .current_heap_location = &dbcbnfyoli,
  .private_heap   = &tugwnwnjyk,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &xldafkwqie;
}
   

#ifdef __cplusplus
}
#endif

#endif
