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


//----------User code ----


static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";


void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}




static const char user_test_event_data[] = "test message";

const Event_data_CFL_t user_test_event = { test_event, false, ( void *)user_test_event_data, };
static const char *igytvocxie = "this is a test message";


unsigned  aeckivuoyt;
const While_time_control_ROM_CFL_t kbeghqmlgs = { 2000,&aeckivuoyt };



static While_control_RAM_CFL_t dwsnnjzfuj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wbfvfqotjo_rom = { 0 ,true, &kbeghqmlgs,&dwsnnjzfuj_ram,null_function};

    
static const char *kappxkwkqw = "reseting the column every 2 seconds";
static const char *gyyxkeudcz = "test_halt_column";
static const char *xmkssigtfr = "halting the column";
static const char *oeqmuxpmar = "test_terminate_column";


unsigned  aqchngyfsf;
const While_time_control_ROM_CFL_t wuimvsdgqf = { 7500,&aqchngyfsf };



static While_control_RAM_CFL_t zywsonskuh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ymzhzcbeyo_rom = { 0 ,true, &wuimvsdgqf,&zywsonskuh_ram,null_function};

    
static const char *szimenmqny = "column 3 is terminating after 7.5 seconds";
static const char *cxzmbpyssf = "test_terminate_engine";


unsigned  zutbmmctws;
const While_time_control_ROM_CFL_t ismgpesfpd = { 10000,&zutbmmctws };



static While_control_RAM_CFL_t ivxffxecmj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t gzphgxxmca_rom = { 0 ,true, &ismgpesfpd,&ivxffxecmj_ram,null_function};

    
static const char *ackfzaxqfj = "column 4 is terminating engine after 10 seconds";
static const char *lgzkmlujrt = "test_terminate_engine 5 second termination";
 unsigned sgiqgbdrtn_ram;
const While_event_control_ROM_t sgiqgbdrtn_rom = { 9,test_event,0,true,NULL,null_function,&sgiqgbdrtn_ram };  
// number of events,event index,time out,terminate flag,user data,one shot function ram_pit

static While_control_RAM_CFL_t czkyqrgqkh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xhmtdghsui_rom = { 0 ,true, &sgiqgbdrtn_rom,&czkyqrgqkh_ram,NULL};

    
static const char *elovofqdft = "column 5 is terminating engine after 9 events";


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
  { 1,true, 0, 8, 0, -1, -1,-1 },
  { 2,true, 1, 3, 8, -1, -1,-1 },
  { 3,true, 2, 4, 11, -1, -1,-1 },
  { -1,true, 3, 4, 15, -1, -1,-1 },
  { -1,true, 4, 4, 19, -1, -1,-1 },
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
    {one_shot_handler_CFL,log_message_CFL,(void *)&igytvocxie},
    {one_shot_handler_CFL,test_one_shot,(void *)&test_one_shot_message},
    {bidirectional_one_shot_handler_CFL,test_one_bid_shot,(void *)&test_bid_one_shot_message},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {one_shot_handler_CFL,send_event_CFL,(void *)&user_test_event},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wbfvfqotjo_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kappxkwkqw},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gyyxkeudcz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xmkssigtfr},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&oeqmuxpmar},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ymzhzcbeyo_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&szimenmqny},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cxzmbpyssf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&gzphgxxmca_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ackfzaxqfj},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lgzkmlujrt},
    {while_handler_CFL,wait_event_handler,(void *)&xhmtdghsui_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&elovofqdft},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t jkdmvpaeya;




static Engine_control_CFL_t cyjumnkdmg;


/*allocate once heap space */

static char qednxsuuqy[2000];


/* remaining allocate heap size */

static unsigned tkxxtkysjv;


/* current heap pointer */

static char* kdepdarngg;


/* heap block area */

static CS_MEMORY_CONTROL gcahnibzhm;


/* heap storeage area */

static char qmedojxgaj[1000];



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ykfdrxokxc =
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
  .time_control = &jkdmvpaeya,
  .engine_control =&cyjumnkdmg,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = qednxsuuqy,
  .master_heap_size = 2000,
  .remaining_heap_size = &tkxxtkysjv,
  .current_heap_location = &kdepdarngg,
  .private_heap   = &gcahnibzhm,
  .working_heap_area   = qmedojxgaj,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  Get_handle_CFL(){
    return &ykfdrxokxc;
}
   

#ifdef __cplusplus
}
#endif

#endif
