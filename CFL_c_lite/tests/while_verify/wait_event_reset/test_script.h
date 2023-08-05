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



void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}

static const char wait_event_reset_message[] = "wait event reset function called\n";
const Event_data_CFL_t user_test_event = { test_event, false, NULL, };
static const char *dccbntxexe = "this column will terminate the engine";


unsigned  oasuiyeshl;
const While_time_control_ROM_CFL_t bzkqhizmuc = { 11000,&oasuiyeshl };



static While_control_RAM_CFL_t owqfivjobr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t khvcyjrpnd_rom = { 0 ,true, &bzkqhizmuc,&owqfivjobr_ram,null_function};

    
static const char *sqzvdztzoi = "stopping engine because 11 seconds have passed";
static const char *mcnbuiigak = "this column will generate an event every second";


unsigned  hunyxbayym;
const While_time_control_ROM_CFL_t qmitjzyycp = { 1000,&hunyxbayym };



static While_control_RAM_CFL_t wvcibpcnns_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t grfjxmhkhf_rom = { 0 ,true, &qmitjzyycp,&wvcibpcnns_ram,null_function};

    
static const char *fufhgchrci = "sending event";
static const char *gmnagcyygd = "wait event is column is starting";
static const char *byhpgcbisb = "this column will reset because not enough time to receive 10 events";
 unsigned kgagjsjdof_ram;
const While_event_control_ROM_t kgagjsjdof_rom = { 10,test_event,9000,false,wait_event_reset_message,&kgagjsjdof_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t dhdsyqrclf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tmsjmtnxsy_rom = { 9000 ,false, &kgagjsjdof_rom,&dhdsyqrclf_ram,wait_event_reset};

    
static const char *dkwagytism = "10 events have been received";
static const char *jhfclpptqa = "stopping engine";


//----------RAM data structures for columns ----

unsigned char column_RAM_flags[3];
unsigned char column_RAM_new_state[3];
void* column_RAM_local_data[3];
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
  { -1,true, 2, 6, 9, -1, -1,-1 },
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
    {one_shot_handler_CFL,log_message_CFL,(void *)&dccbntxexe},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&khvcyjrpnd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sqzvdztzoi},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mcnbuiigak},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&grfjxmhkhf_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fufhgchrci},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gmnagcyygd},
    {one_shot_handler_CFL,log_message_CFL,(void *)&byhpgcbisb},
    {while_handler_CFL,wait_event_handler,(void *)&tmsjmtnxsy_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dkwagytism},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jhfclpptqa},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t xtscdbdxzu;




static Engine_control_CFL_t kbtexptxqx;


/*allocate once heap space */

static char kpdeoubegx[2000];


/* remaining allocate heap size */

static unsigned fvyzrddgth;


/* current heap pointer */

static char* leuyvxkoaq;


/* heap block area */

static CS_MEMORY_CONTROL ifxphocsdv;


/* heap storeage area */

static char inlwicxmjd[1000];



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t grsjoolbld =
{

  .queue_rom    = &queue_control,
  .queue_ram = event_control_ram,
  .event_data = event_data_array,

  .column_elements_flags =column_element_RAM ,
  .column_elements_ROM = column_elements_ROM,

  .column_flags = column_RAM_flags,
  .column_local_data = column_RAM_local_data,
  .column_state = column_RAM_new_state,
  .number_of_columns = 3,
  .column_rom_data = column_data_ROM,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &xtscdbdxzu,
  .engine_control =&kbtexptxqx,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = kpdeoubegx,
  .master_heap_size = 2000,
  .remaining_heap_size = &fvyzrddgth,
  .current_heap_location = &leuyvxkoaq,
  .private_heap   = &ifxphocsdv,
  .working_heap_area   = inlwicxmjd,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  Get_handle_CFL(){
    return &grsjoolbld;
}
   

#ifdef __cplusplus
}
#endif

#endif
