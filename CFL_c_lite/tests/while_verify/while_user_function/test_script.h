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

static unsigned test_counter = 0;

void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}
static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
static const char *gwvoalfhve = "this column will terminate the engine";


unsigned  uigcybluvn;
const While_time_control_ROM_CFL_t odxymzwxmk = { 11000,&uigcybluvn };



static While_control_RAM_CFL_t iwujfmnotr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yejljynikd_rom = { 0 ,true, &odxymzwxmk,&iwujfmnotr_ram,null_function};

    
static const char *tthwekspje = "stopping engine because 11 seconds have passed";
static const char *kekndnyldn = "this column will generate an event every second";


unsigned  mlayfclmuz;
const While_time_control_ROM_CFL_t nwkwbsalxa = { 1000,&mlayfclmuz };



static While_control_RAM_CFL_t momaqgnggy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nxanqvqxbn_rom = { 0 ,true, &nwkwbsalxa,&momaqgnggy_ram,null_function};

    
static const char *evwlnzbefa = "sending event";
static const char *qwtsnrdovd = "user function column is starting";

static While_control_RAM_CFL_t qqvnsqveea_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bskneekucc_rom = { 0 ,false, &test_counter,&qqvnsqveea_ram,null_function};

    
static const char *wmkenhtbka = "user function has passed";
static const char *zdsjlecrua = "terminating column";
static const char *cygmctghwo = "this demonstrates the reset feature of the wait opcode";

static While_control_RAM_CFL_t epmyvqxpxy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hmdmbfotsr_rom = { 5000 ,true, &wait_event_reset_message,&epmyvqxpxy_ram,wait_event_reset};

    
static const char *goorzzcaqh = "10 events have been received";
static const char *jffpnnusxs = "terminating column";
static const char *yiwbhvhbdc = "this demonstrates the terminate feature of the wait opcode";

static While_control_RAM_CFL_t ukqiuatcpx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yrnnuspkaj_rom = { 5000 ,true, &wait_event_terminate_message,&ukqiuatcpx_ram,wait_event_terminate};

    
static const char *kvyakymfax = "This step should not happpen as the wait opcode will reset because of timeout";


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
  { -1,true, 0, 4, 0, -1, -1,-1 },
  { -1,true, 1, 5, 4, -1, -1,-1 },
  { -1,true, 2, 5, 9, -1, -1,-1 },
  { -1,true, 3, 4, 19, -1, -1,-1 },
  { -1,true, 4, 5, 14, -1, -1,-1 },
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
    {one_shot_handler_CFL,log_message_CFL,(void *)&gwvoalfhve},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yejljynikd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tthwekspje},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kekndnyldn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nxanqvqxbn_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {one_shot_handler_CFL,log_message_CFL,(void *)&evwlnzbefa},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qwtsnrdovd},
    {while_handler_CFL,test_bool_fn,(void *)&bskneekucc_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wmkenhtbka},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zdsjlecrua},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cygmctghwo},
    {while_handler_CFL,false_constant_handler,(void *)&hmdmbfotsr_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&goorzzcaqh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jffpnnusxs},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yiwbhvhbdc},
    {while_handler_CFL,false_constant_handler,(void *)&yrnnuspkaj_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kvyakymfax},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t qyiumiaplc;




static Engine_control_CFL_t ttgdplteub;


/*allocate once heap space */

static char iczforvhlq[2000];


/* remaining allocate heap size */

static unsigned ryshdvofmr;


/* current heap pointer */

static char* twtbjumezj;


/* heap block area */

static CS_MEMORY_CONTROL zdgvfxkqww;


/* heap storeage area */

static char rfnsvauato[1000];



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t plaisfwzkd =
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
  .time_control = &qyiumiaplc,
  .engine_control =&ttgdplteub,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = iczforvhlq,
  .master_heap_size = 2000,
  .remaining_heap_size = &ryshdvofmr,
  .current_heap_location = &twtbjumezj,
  .private_heap   = &zdgvfxkqww,
  .working_heap_area   = rfnsvauato,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  Get_handle_CFL(){
    return &plaisfwzkd;
}
   

#ifdef __cplusplus
}
#endif

#endif
