#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#ifndef __basic_code_H__
#define __basic_code_H__


//----------User code ----


static char *test_one_shot_message = "test_one_shot";
static char *test_bid_one_shot_message = "test_one_bid_shot";

const char *yytprasyyd = "this is a test message";


//----------RAM data structures for event queues ----

Event_data_CFL_t event_data_array[40];
Event_control_RAM_t event_control_ram[4];


//------  ROM data structures for event queues ----

const Event_control_ROM_t event_control_rom_queue3 = { 0, 10 };
const Event_control_ROM_t event_control_rom_queue2 = { 10, 10 };
const Event_control_ROM_t event_control_rom_queue1 = { 20, 10 };
const Event_control_ROM_t event_control_rom_default = { 30, 10 };
const Named_event_queue_control_CFL_t queue_control = { 40, {
     &event_control_rom_queue3,
     &event_control_rom_queue2,
     &event_control_rom_queue1,
     &event_control_rom_default,
     }
};


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[4];
unsigned char column_RAM_new_state[4];
void* column_RAM_local_data[4];
Column_watch_dog_t column_RAM_watch_dog_control[4];


//----------ROM data structures for columns ----

const Column_ROM_t column_ROM_data[] = {
  { 0,1 true, 4, 0, -1, -1 },
  { 1,2 true, 1, 4, -1, -1 },
  { 2,3 true, 1, 5, -1, -1 },
  { 3,-1 true, 1, 6, -1, -1 },
};


//----------Column elements ----

const Column_element_CFL_t column_elements[] = {
    {CFL_one_shot_handler,CFL_log_message,(void *)yytprasyyd},
    {CFL_one_shot_handler,test_one_shot,(void *)test_one_shot_message},
    {CFL_bidirectional_one_shot_handler,test_bid_one_shot,(void *)test_bid_one_shot_message},
    {return_condition_code,NULL,(void *)reset_buffer},
    {return_condition_code,NULL,(void *)halt_buffer},
    {return_condition_code,NULL,(void *)terminate_buffer},
    {return_condition_code,NULL,(void *)terminate_engine_buffer},
};
   

#ifdef __cplusplus
}
#endif

#endif
