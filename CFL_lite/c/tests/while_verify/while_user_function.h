#ifndef __while_user_function_H__
#define __while_user_function_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define ijxsvqiftr 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t tfhakcilhq[1];
static Event_data_CFL_t fcsgumhrve[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t gsnrgnywli[] = { 
     {  10, fcsgumhrve },
};
const Event_data_CFL_t jxvahbpyde = { ijxsvqiftr, false, NULL };

static unsigned test_counter = 0;



static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
static const char *lpjvusticq = "this column will terminate the engine";


unsigned  olmcvjrirj;
const While_time_control_ROM_CFL_t nppynfxwju = { 16000,&olmcvjrirj };



static While_control_RAM_CFL_t hgcuyuxepq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t gqlszisyfz_rom = { 0 ,true, &nppynfxwju,&hgcuyuxepq_ram,null_function};

    
static const char *rdfllmsdhr = "stopping engine because 16 seconds have passed";
static const char *fkvwpgwopo = "this column will generate an event every second";


unsigned  vfjescmjrt;
const While_time_control_ROM_CFL_t grideuqexs = { 1000,&vfjescmjrt };



static While_control_RAM_CFL_t pfomoufymf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t glywdqmwmg_rom = { 0 ,true, &grideuqexs,&pfomoufymf_ram,null_function};

    
static const char *ssnwyordcc = "sending event";
static const char *yqnqjrsoec = "user function column is starting";

static While_control_RAM_CFL_t cwcfxnkgdf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t iqqfcoafnl_rom = { 0 ,false, &test_counter,&cwcfxnkgdf_ram,null_function};

    
static const char *lusqezijrs = "user function has passed";
static const char *lgfmkiysvm = "terminating column";
static const char *vwsxuwvrmw = "this demonstrates the reset feature of the wait opcode";

static While_control_RAM_CFL_t jvbyiznijg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qutobdmiso_rom = { 5000 ,false, &wait_event_reset_message,&jvbyiznijg_ram,wait_event_reset};

    
static const char *evsshfjkwx = "10 events have been received";
static const char *yuoqcjewpn = "terminating column";
static const char *tyamvjsrgs = "this demonstrates the terminate feature of the wait opcode";

static While_control_RAM_CFL_t lostvjtzfd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t extzvxwhsm_rom = { 5000 ,true, &wait_event_terminate_message,&lostvjtzfd_ram,wait_event_terminate};

    
static const char *vufvktjjkk = "This step should not happpen as the wait opcode will reset because of timeout";


//----------RAM data structures for columns ----

unsigned ernbtfpalu[5];
unsigned lpnhdqglqa[5];
One_shot_function_CFL_t  cyvxgnzwoj[5];
unsigned char iufuvrarbg[5];
void *  ojoimkwkbd[5];
unsigned char lxtervsgqd[5];
unsigned char efalkicokz[5];
void* qqogdazznx[5];
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
  
} Column_ROM_CFL_t;

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t odsvylaczb[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,true, 1, 5, 4, -1, -1 },
  { -1,true, 2, 5, 9, -1, -1 },
  { -1,true, 3, 4, 19, -1, -1 },
  { -1,true, 4, 5, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char vbeaipnteq[23];


  /* 
  ------------------------ Column element Flash structure --------------------------
     typedef struct Column_element_CFL_t {
        Column_function_CFL_t column_function;
        void *aux_fn;
        void *params
     } Column_element_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

  

//----------Column elements Flash structures----

static const Column_element_CFL_t jjdmxwvemp[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&lpjvusticq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&gqlszisyfz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rdfllmsdhr},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fkvwpgwopo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&glywdqmwmg_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&jxvahbpyde},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ssnwyordcc},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yqnqjrsoec},
    {while_handler_CFL,test_bool_fn,(void *)&iqqfcoafnl_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lusqezijrs},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lgfmkiysvm},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vwsxuwvrmw},
    {while_handler_CFL,false_constant_handler,(void *)&qutobdmiso_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&evsshfjkwx},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yuoqcjewpn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tyamvjsrgs},
    {while_handler_CFL,false_constant_handler,(void *)&extzvxwhsm_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vufvktjjkk},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t yugdcndpxb;




static Engine_control_CFL_t uopuokxmeu;


/* remaining allocate heap size */

static unsigned pyhhwagecy;


/* current heap pointer */

static char* jmarwcloyr;


/* heap block area */

static CS_MEMORY_CONTROL botnkrafbs;


    
    /*
    --------------------------- Handle definition ------------------------------
   

  


    typedef struct Handle_CFL_t
{
  const unsigned queue_number;
  const Event_control_ROM_CFL_t *queue_rom;
  Event_control_RAM_CFL_t *queue_ram;
  

  unsigned char *column_elements_flags;
  const Column_element_CFL_t *column_elements_ROM;

  unsigned char *column_flags;
  void **column_local_data;
  unsigned char *column_state;
  const unsigned short number_of_columns;
  const Column_ROM_CFL_t *column_rom_data;

  unsigned *watch_dog_trigger_count;
  unsigned *watch_dog_count;
 
  One_shot_function_CFL_t *watch_dog_trigger_function;
  unsigned char *watch_dog_termination_flag;
  void **watch_dog_user_data;
  
  Time_control_CFL_t *time_control;
  Engine_control_CFL_t *engine_control;
  Debug_out_CFL_t debug_function;
  private_heap_malloc_fn malloc;
  private_heap_free_fn free;
  allocate_once_fn allocate_once;
  char **master_heap_starting_location; 
  const unsigned master_heap_size;             
  unsigned *remaining_heap_size;  // set by c runtime
  char **current_heap_location;  // set by c runtime
  CS_MEMORY_CONTROL *private_heap;      
  
  unsigned private_heap_size;

} Handle_CFL_t;
    local header_code = [[
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t mwtqurcwxa =
{

  .queue_number = 1,
  .queue_rom = gsnrgnywli,
  .queue_ram = tfhakcilhq,

  .column_elements_flags =vbeaipnteq,
  .column_elements_ROM = jjdmxwvemp,

  .watch_dog_trigger_count = ernbtfpalu,
  .watch_dog_count       =  lpnhdqglqa,  
  .watch_dog_trigger_function = cyvxgnzwoj,
  .watch_dog_termination_flag = iufuvrarbg,
  .watch_dog_user_data = ojoimkwkbd,
   
   
  .column_flags = lxtervsgqd,
  .column_local_data = qqogdazznx,
  .column_state = efalkicokz,
  .number_of_columns = 5,
  .column_rom_data = odsvylaczb,

  
  
  
  .time_control = &yugdcndpxb,
  .engine_control =&uopuokxmeu,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &pyhhwagecy,
  .current_heap_location = &jmarwcloyr,
  .private_heap   = &botnkrafbs,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  while_user_function_handle(){
    return &mwtqurcwxa;
}
   

#ifdef __cplusplus
}
#endif

#endif
