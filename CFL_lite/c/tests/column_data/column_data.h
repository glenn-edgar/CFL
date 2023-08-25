#ifndef __column_data_H__
#define __column_data_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t vyhginaoka[1];
static Event_data_CFL_t iqjznjjzar[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hsbyqnlawa[] = { 
     {  10, iqjznjjzar },
};
char column_test_data[] ="this is the column data test";  static void get_column_local_data(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    unsigned short column_index = get_current_column_index_CFL(input); 
    Printf_CFL("column index %d \n",column_index);
    char *column_data = (char *)retrieve_local_column_data(input);
    
    Printf_CFL("user data for column_data_test %s \n",column_data);


  }



static const char *gicgruigob = "starting send";


unsigned  jlpeohnmjw;
const While_time_control_ROM_CFL_t yjzejkohrp = { 1000,&jlpeohnmjw };



static While_control_RAM_CFL_t tvmkbopcaz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t eabssbvrfa_rom = { 0 ,true, &yjzejkohrp,&tvmkbopcaz_ram,null_function};

    
static unsigned short kzoxsdavbn[] = { 1,2};
static const Column_data_CFL_t ifrbkscjgf = { 2, kzoxsdavbn, (void *)&column_test_data };
static const char *hejbhmzmbb = "ending send_column_data";
static const char *cyzfubaoac = "receive_1";


unsigned  rdhquegnvw;
const While_time_control_ROM_CFL_t oqxggxeemv = { 2000,&rdhquegnvw };



static While_control_RAM_CFL_t kqqghldagl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tfylhebmup_rom = { 0 ,true, &oqxggxeemv,&kqqghldagl_ram,null_function};

    
static const char *rejdbridui = "ending receive_1";
static const char *lalxbqfuzw = "starting column_receive_2";


unsigned  tohvcvpxyg;
const While_time_control_ROM_CFL_t efvmivhnmq = { 2000,&tohvcvpxyg };



static While_control_RAM_CFL_t utrrprvfqg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kcjgwhcggw_rom = { 0 ,true, &efvmivhnmq,&utrrprvfqg_ram,null_function};

    


//----------RAM data structures for columns ----

unsigned jvodlvvffs[3];
Watch_dog_struct_CFL_t * asxbdhenli[3];
unsigned char zwuoishzuu[3];
unsigned char xwhvvjlhvk[3];
void* xuetleucnl[3];
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

static const Column_ROM_CFL_t rsfaekrwev[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { -1,true, 1, 5, 5, -1, -1 },
  { -1,true, 2, 4, 10, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char wbmxxdipby[14];


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

static const Column_element_CFL_t csvmsyygxg[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&gicgruigob},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&eabssbvrfa_rom},
    {one_shot_handler_CFL,store_column_data,(void *)&ifrbkscjgf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hejbhmzmbb},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cyzfubaoac},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tfylhebmup_rom},
    {one_shot_handler_CFL,get_column_local_data,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rejdbridui},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lalxbqfuzw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kcjgwhcggw_rom},
    {one_shot_handler_CFL,get_column_local_data,NULL},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t fqwuigdace;




static Engine_control_CFL_t kahevmnmhk;


/* remaining allocate heap size */

static unsigned hvelykirjj;


/* current heap pointer */

static char* xabjtpvjto;


/* heap block area */

static CS_MEMORY_CONTROL oaybvccyzx;


    
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
    
      
      Watch_dog_struct_CFL_t **watch_dog_struct;
      unsigned *watch_dog_count;
     
      
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

    
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


const struct Handle_CFL_t qwwlizpiqt =
{

  .queue_number = 1,
  .queue_rom = hsbyqnlawa,
  .queue_ram = vyhginaoka,

  .column_elements_flags =wbmxxdipby,
  .column_elements_ROM = csvmsyygxg,

  .watch_dog_struct = asxbdhenli,
  .watch_dog_count  = jvodlvvffs,
   
   
  .column_flags = zwuoishzuu,
  .column_local_data = xuetleucnl,
  .column_state = xwhvvjlhvk,
  .number_of_columns = 3,
  .column_rom_data = rsfaekrwev,

  
  
  
  .time_control = &fqwuigdace,
  .engine_control =&kahevmnmhk,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &hvelykirjj,
  .current_heap_location = &xabjtpvjto,
  .private_heap   = &oaybvccyzx,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  column_data_handle(){
    return &qwwlizpiqt;
}
   

#ifdef __cplusplus
}
#endif

#endif
