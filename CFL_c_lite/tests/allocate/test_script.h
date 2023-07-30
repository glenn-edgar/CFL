#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "CFL_inner_engine.h"


//----------RAM data structures for event queues ----

static Event_data_CFL_t event_data_array[20];
static Event_control_RAM_CFL_t event_control_ram[2];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t event_control_rom_default = { 0, 10 };
static const Event_control_ROM_CFL_t event_control_rom_main_queue = { 10, 10 };
static const Event_control_ROM_CFL_t *queue_elements[] = {
     &event_control_rom_default,
     &event_control_rom_main_queue,
};
static const Named_event_queue_control_CFL_t queue_control = { 2,20,queue_elements };


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[0];
unsigned char column_RAM_new_state[0];
void* column_RAM_local_data[0];
/*
------------------------ ROM data structures for columns --------------------------
typedef struct Column_ROM_t
{
    short                         queue_number; //-1 means no attached event queue
    bool                          auto_start;   //true or false
    unsigned short                id;           // position in the table
    unsigned short                number;       // number of column elements
    unsigned short                start;        // starting position of the column element
   short                         start_state;   // start of first column state -1 means no state
   short                         end_state;     // end of last column state -1 means no state
   short                         watch_dog_id;  // watch dog number -1 means no watch dog
} Column_ROM_t;


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t column_data_ROM[] = {
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

  

static unsigned char column_element_RAM[0];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
};
#include <unistd.h>


void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}





static Time_control_CFL_t qbiievzdve;




static Engine_control_CFL_t htwfipfycn;


/*allocate once heap space */

static char yzwitwbzff[2000];


/* remaining allocate heap size */

static unsigned vniqwddtoz;


/* current heap pointer */

static char* azguclisai;


/* heap block area */

static CS_MEMORY_CONTROL iviqeuwdxc;


/* heap storeage area */

static char daoufgehjh[1000];



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t tdhgtpuren =
{

  .queue_rom    = &queue_control,
  .queue_ram = event_control_ram,
  .event_data = event_data_array,

  .column_elements_flags =column_element_RAM ,
  .column_elements_ROM = column_elements_ROM,

  .column_flags = column_RAM_flags,
  .column_local_data = column_RAM_local_data,
  .column_state = column_RAM_new_state,
  .number_of_columns = 0,
  .column_rom_data = column_data_ROM,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &qbiievzdve,
  .engine_control =&htwfipfycn,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = yzwitwbzff,
  .master_heap_size = 2000,
  .remaining_heap_size = &vniqwddtoz,
  .current_heap_location = &azguclisai,
  .private_heap   = &iviqeuwdxc,
  .working_heap_area   = daoufgehjh,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  Get_handle_CFL(){
    return &tdhgtpuren;
}
#endif
