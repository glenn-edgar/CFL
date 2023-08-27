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

char *allocate_once_memory = NULL;

void create_allocate_once_heap(){
    allocate_once_memory = (char *)malloc(2000);
}

void free_allocate_once_heap(){
    free(allocate_once_memory);
}

static const char *tncokojofj = "terminate engine column start";


unsigned  yeiejxpxpj;
const While_time_control_ROM_CFL_t qjnonbfdln = { 20000,&yeiejxpxpj };



static While_control_RAM_CFL_t nlvmzgsdrt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bjdpvatqbt_rom = { 0 ,true, &qjnonbfdln,&nlvmzgsdrt_ram,null_function};

    
static const char *tyqzpfzmap = "stop engine";


unsigned  xwmntdueci;
const While_time_control_ROM_CFL_t xujuenbzxj = { 1000,&xwmntdueci };



static While_control_RAM_CFL_t gyaryjxakw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fuoivajdbo_rom = { 0 ,true, &xujuenbzxj,&gyaryjxakw_ram,null_function};

    
static const char *qtorwkxgtc = "event has been sent";
static const char *gjgfitqwsu = "verify reset column";
static const char *akppbcjkda = "this column will reset";
    static Verify_control_ROM_CFL_t ssbjewilhp_rom = { false, (void *)&test_counter_1, verify_one_shot_reset };  // terminate flag,user data,one shot function

static While_control_RAM_CFL_t skhnfdqjnk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zgotdbfvje_rom = { 0 ,true, NULL,&skhnfdqjnk_ram,null_function};

    
static const char *yuvmjqjftb = "This should not happen";
static const char *xkepgstubl = "verify terminate column";
static const char *uxcasrkvca = "this column will terminate";
    static Verify_control_ROM_CFL_t igprxkstfr_rom = { true, (void *)&test_counter_2, verify_one_shot_terminate };  // terminate flag,user data,one shot function

static While_control_RAM_CFL_t umhmcbvcab_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bnhnltkswf_rom = { 0 ,true, NULL,&umhmcbvcab_ram,null_function};

    
static const char *hsxqsdstpg = "This should not happen";


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
    {one_shot_handler_CFL,log_message_CFL,(void *)&tncokojofj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bjdpvatqbt_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tyqzpfzmap},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fuoivajdbo_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qtorwkxgtc},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gjgfitqwsu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&akppbcjkda},
    {verify_handler_CFL,test_bool_fn,(void *)&ssbjewilhp_rom},
    {while_handler_CFL,false_constant_handler,(void *)&zgotdbfvje_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yuvmjqjftb},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xkepgstubl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uxcasrkvca},
    {verify_handler_CFL,test_bool_fn,(void *)&igprxkstfr_rom},
    {while_handler_CFL,false_constant_handler,(void *)&bnhnltkswf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hsxqsdstpg},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t eeobuuzwvm;




static Engine_control_CFL_t wcagskhxob;




static Engine_control_CFL_t wcagskhxob;


/* remaining allocate heap size */

static unsigned juzosnjgjr;


/* current heap pointer */

static char* ysyjpphxfj;


/* heap block area */

static CS_MEMORY_CONTROL bxljvhvlnr;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t lqaroawlpm =
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
  .time_control = &eeobuuzwvm,
  .engine_control =&wcagskhxob,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &juzosnjgjr,
  .current_heap_location = &ysyjpphxfj,
  .private_heap   = &bxljvhvlnr,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  test_entry_point(){
    return &lqaroawlpm;
}
   

#ifdef __cplusplus
}
#endif

#endif
