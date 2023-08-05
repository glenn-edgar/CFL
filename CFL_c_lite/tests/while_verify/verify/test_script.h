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


void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}

static unsigned test_counter_1 = 0;
static unsigned test_counter_2 = 0;


static const char *sxhkgydwfj = "terminate engine column start";


unsigned  cyzmndkmpi;
const While_time_control_ROM_CFL_t fitngxijof = { 20000,&cyzmndkmpi };



static While_control_RAM_CFL_t tfhcvimqpb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mkfwsqdawm_rom = { 0 ,true, &fitngxijof,&tfhcvimqpb_ram,null_function};

    
static const char *plunregqzn = "stop engine";


unsigned  yokozvvlss;
const While_time_control_ROM_CFL_t igtdlnocrh = { 1000,&yokozvvlss };



static While_control_RAM_CFL_t rufhseuwsn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uqypahjzxp_rom = { 0 ,true, &igtdlnocrh,&rufhseuwsn_ram,null_function};

    
static const char *qnwnqfvaxy = "event has been sent";
static const char *mjbpysqvmh = "verify reset column";
static const char *aunjiscwxb = "this column will reset";
    static Verify_control_ROM_CFL_t bvmnlogsiz_rom = { false, (void *)&test_counter_1, verify_one_shot_reset };  // terminate flag,user data,one shot function

static While_control_RAM_CFL_t shlumxawsc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bsucxzfxyj_rom = { 0 ,true, NULL,&shlumxawsc_ram,null_function};

    
static const char *lvghgfvjvl = "This should not happen";
static const char *ninpluozwa = "verify terminate column";
static const char *obzcoqwnxx = "this column will terminate";
    static Verify_control_ROM_CFL_t fxlfyeqbrp_rom = { true, (void *)&test_counter_2, verify_one_shot_terminate };  // terminate flag,user data,one shot function

static While_control_RAM_CFL_t ecrqrksqsj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t eckrmtfeqm_rom = { 0 ,true, NULL,&ecrqrksqsj_ram,null_function};

    
static const char *ptjnamwltj = "This should not happen";


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
  { -1,true, 0, 4, 0, -1, -1,-1 },
  { -1,true, 1, 4, 4, -1, -1,-1 },
  { -1,true, 2, 6, 8, -1, -1,-1 },
  { -1,true, 3, 6, 14, -1, -1,-1 },
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

  

static unsigned char column_element_RAM[20];



//----------Column elements ----

static const Column_element_CFL_t column_elements_ROM[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&sxhkgydwfj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mkfwsqdawm_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&plunregqzn},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uqypahjzxp_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qnwnqfvaxy},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mjbpysqvmh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aunjiscwxb},
    {verify_handler_CFL,test_bool_fn,(void *)&bvmnlogsiz_rom},
    {while_handler_CFL,false_constant_handler,(void *)&bsucxzfxyj_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lvghgfvjvl},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ninpluozwa},
    {one_shot_handler_CFL,log_message_CFL,(void *)&obzcoqwnxx},
    {verify_handler_CFL,test_bool_fn,(void *)&fxlfyeqbrp_rom},
    {while_handler_CFL,false_constant_handler,(void *)&eckrmtfeqm_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ptjnamwltj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t afrmzxutdn;




static Engine_control_CFL_t geunwqsfuf;


/*allocate once heap space */

static char gzzcwhlgbh[2000];


/* remaining allocate heap size */

static unsigned ocrpdgkkru;


/* current heap pointer */

static char* qylxdejxpk;


/* heap block area */

static CS_MEMORY_CONTROL kqfzojzzxh;


/* heap storeage area */

static char lmgeferlui[1000];



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t egefoougbx =
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
  .time_control = &afrmzxutdn,
  .engine_control =&geunwqsfuf,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = gzzcwhlgbh,
  .master_heap_size = 2000,
  .remaining_heap_size = &ocrpdgkkru,
  .current_heap_location = &qylxdejxpk,
  .private_heap   = &kqfzojzzxh,
  .working_heap_area   = lmgeferlui,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &egefoougbx;
}
   

#ifdef __cplusplus
}
#endif

#endif
