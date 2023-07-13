#ifndef __test_script_H__
#define __test_script_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   




//----------Column functions ----


static int bidirectional_one_shot_handler(void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{

  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    fn(handle, params, event_data);
  }

  return CONTINUE_CFL;
}


static int one_shot_handler(void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data)
{
  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
    return DISABLE_CFL;
  }
  return DISABLE_CFL;
}


const int reset_buffer[1] = { RESET_CFL };
const int halt_buffer[1] = { HALT_CFL };
const int terminate_buffer[1] = { TERMINATE_CFL };
const int terminate_engine_buffer[1] = { ENGINE_TERMINATE_CFL };

int return_condition_code(void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    int *return_code;
    return_code = (int *)params;
    if (event_data->event_index > EVENT_INIT_CFL)
    {
        return *return_code;
    }
    return CONTINUE_CFL;
}



//----------One shot functions ----


static void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char *message;
  
  unsigned column_index;
  int column_element_number;
  message = (char *)params;
  Printf_CFL("Init event  %s\n",message);  
 
  
}


static void log_message(void *input, void *params,
                        Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char *message;
  
  unsigned column_index;
  int column_element_number;
  message = (char *)params;

  column_index = Get_current_column_index_CFL(input);
  column_element_number = Get_current_column_element_index_CFL(input);
  Printf_CFL("Log !!!! column index %d column element %d  ---> msg: %s\n",
              column_index, column_element_number, message);
}


static void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
 
  
   char *message;
   
   unsigned column_index;
   int column_element_number;
   message = (char *)params;
   if(event_data->event_index == EVENT_INIT_CFL)
   {
     Printf_CFL("Init event  %s\n",message);  
     
   }
    if(event_data->event_index == EVENT_TERMINATION_CFL)
    {
       Printf_CFL("Termination event %s\n",message);
    }
 
   
 }



//----------User code ----


static char *test_one_shot_message = "test_one_shot";
static char *test_bid_one_shot_message = "test_one_bid_shot";

const char *virpqtizji = "this is a test message";


//----------RAM data structures for event queues ----

Event_data_CFL_t event_data_array[40];
Event_control_RAM_t event_control_ram[4];


//------  ROM data structures for event queues ----

const Event_control_ROM_t event_control_rom_queue1 = { 0, 10 };
const Event_control_ROM_t event_control_rom_queue2 = { 10, 10 };
const Event_control_ROM_t event_control_rom_default = { 20, 10 };
const Event_control_ROM_t event_control_rom_queue3 = { 30, 10 };
const Named_event_queue_control_CFL_t queue_control = { 40, {
     &event_control_rom_queue1,
     &event_control_rom_queue2,
     &event_control_rom_default,
     &event_control_rom_queue3,
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
    {one_shot_handler,log_message,(void *)virpqtizji},
    {one_shot_handler,test_one_shot,(void *)test_one_shot_message},
    {bidirectional_one_shot_handler,test_bid_one_shot,(void *)test_bid_one_shot_message},
    {return_condition_code,NULL,(void *)reset_buffer},
    {return_condition_code,NULL,(void *)halt_buffer},
    {return_condition_code,NULL,(void *)terminate_buffer},
    {return_condition_code,NULL,(void *)terminate_engine_buffer},
};
   

#ifdef __cplusplus
}
#endif

#endif
