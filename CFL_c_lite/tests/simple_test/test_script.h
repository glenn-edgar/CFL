#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


/*

------------------------------------------ Event queue documentation ---------------------------------------------
typedef struct Event_data_CFL_t
{
  short event_index;
  bool  malloc_flag;
  void* params;

} Event_data_CFL_t;


typedef struct Event_control_RAM_CFL_t
{
  unsigned short rx_index;
  unsigned short tx_index;
  unsigned short current_queued_number;
} Event_data_RAM_t;

typedef struct Event_control_ROM_t{ 
  unsigned                 number;
  unsigned                start_index;
  Event_control_RAM_CFL_t *event_control_ram;
} Event_control_ROM_t;



typedef struct Named_event_queue_control_CFL_t
{
 
  unsigned number;
  Event_control_CFL_t *event_queues;
} Named_event_queue_control_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/


//----------RAM data structures for event queues ----

static Event_data_CFL_t event_data_array[50];
static Event_control_RAM_t event_control_ram[5];


//------  ROM data structures for event queues ----

static const Event_control_ROM_t event_control_rom_default = { 0, 10 };
static const Event_control_ROM_t event_control_rom_main_queue = { 10, 10 };
static const Event_control_ROM_t event_control_rom_queue1 = { 20, 10 };
static const Event_control_ROM_t event_control_rom_queue2 = { 30, 10 };
static const Event_control_ROM_t event_control_rom_queue3 = { 40, 10 };
static const Named_event_queue_control_CFL_t queue_control = { 50, {
     &event_control_rom_default,
     &event_control_rom_main_queue,
     &event_control_rom_queue1,
     &event_control_rom_queue2,
     &event_control_rom_queue3,
     }
};


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[4];
unsigned char column_RAM_new_state[4];
void* column_RAM_local_data[4];
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

static const Column_ROM_t column_data_ROM[] = {
  { 0,2 true, 4, 0, -1, -1,-1 },
  { 1,3 true, 1, 4, -1, -1,-1 },
  { 2,4 true, 1, 5, -1, -1,-1 },
  { 3,-1 true, 1, 6, -1, -1,-1 },
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

  

static unsigned char column_element_RAM[7];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
    {CFL_one_shot_handler,CFL_log_message,(void *)nrgikrvarq},
    {CFL_one_shot_handler,test_one_shot,(void *)test_one_shot_message},
    {CFL_bidirectional_one_shot_handler,test_bid_one_shot,(void *)test_bid_one_shot_message},
    {return_condition_code,NULL,(void *)reset_buffer},
    {return_condition_code,NULL,(void *)halt_buffer},
    {return_condition_code,NULL,(void *)terminate_buffer},
    {return_condition_code,NULL,(void *)terminate_engine_buffer},
};


static Time_control_CFL_t gmvzjhoghw;




static Engine_control_CFL_t ihimradrum;


/*
--------------------------- Handle definition ------------------------------
typedef struct Handle_CFL_t {
    
    void*                              queue_rom;
    void*                              queue_ram;
    void*                              event_data;

    void*                              column_elements_RAM;
    void*                              column_elements_ROM;
                
    void*                              column_flags;
    void*                              column_local_data;
    void*                              column_state;
    void*                              column_data;
          
   void*                              watch_dog_ram_data;        
   void*                              watch_dog_rom_data;
   void*                              time_control;
   void*                              engine_control;
   void*                              debug_function;
   private_heap_malloc                malloc;
   private_heap_free                  free;
   allocate_once_malloc               allocate_once_malloc;
 }Handle_CFL_t;
 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


static const Handle_CFL_t pqodazdnlb = {
   .queue_rom = queue_control;
   .queue_ram = event_control_ram;
   .event_data = event_data_array;
   .column_elements_flags = column_element_RAM;
   .column_elements_ROM = column_elements_ROM;
   .column_flags = column_RAM_flags;
   .column_local_data = column_RAM_local_data;
   .column_new_state = column_RAM_new_state;
   .column_data_ROM = column_data_ROM;
   .watch_dog_ram_data = NULL;
   .watch_dog_rom_data = NULL;
   .time_control = &gmvzjhoghw;
   .engine_control = &ihimradrum;
   .debug_function = debug_write;
}
static void test_entry_point() {
   Start_engine_CFL(&pqodazdnlb,2000,1000);
}
