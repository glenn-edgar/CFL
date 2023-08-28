#ifndef __while_user_function_H__
#define __while_user_function_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define jfhqtatqte 100 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t lbrbabbbxv[1];
static Event_data_CFL_t zmhjivuzbu[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t yxamsdfqlo[] = { 
     {  10, zmhjivuzbu },
};
const Event_data_CFL_t xcdilqthnd = { jfhqtatqte, false, NULL };

static unsigned test_counter = 0;



static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
static const char *bstzpsqxax = "this column will terminate the engine";


unsigned  hadqhupwiu;
const While_time_control_ROM_CFL_t zallqrpfoa = { 16000,&hadqhupwiu };



static While_control_RAM_CFL_t rbpyirjdof_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lkjntajtgk_rom = { 0 ,true, &zallqrpfoa,&rbpyirjdof_ram,null_function};

    
static const char *mvabyhfixa = "stopping engine because 16 seconds have passed";
static const char *uacqzwmgsh = "this column will generate an event every second";


unsigned  yrawevpifx;
const While_time_control_ROM_CFL_t rlfppwuhey = { 1000,&yrawevpifx };



static While_control_RAM_CFL_t ahdsahnxza_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fvxvlbrlnr_rom = { 0 ,true, &rlfppwuhey,&ahdsahnxza_ram,null_function};

    
static const char *kjzwpovkqn = "sending event";
static const char *llswkpmlep = "user function column is starting";

static While_control_RAM_CFL_t neykfkqbtm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lwxlwqyjhn_rom = { 0 ,false, &test_counter,&neykfkqbtm_ram,null_function};

    
static const char *fxrvosvxly = "user function has passed";
static const char *gcqeutfgts = "terminating column";
static const char *uswjwtrcmx = "this demonstrates the reset feature of the wait opcode";

static While_control_RAM_CFL_t ksvrnjpznp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ontasgvunf_rom = { 5000 ,false, &wait_event_reset_message,&ksvrnjpznp_ram,wait_event_reset};

    
static const char *qkbgzhdpcr = "10 events have been received";
static const char *rcbqymlmfh = "terminating column";
static const char *zztjyoqvsn = "this demonstrates the terminate feature of the wait opcode";

static While_control_RAM_CFL_t ehpsclspir_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fltxwpmhpx_rom = { 5000 ,true, &wait_event_terminate_message,&ehpsclspir_ram,wait_event_terminate};

    
static const char *famcqhieto = "This step should not happpen as the wait opcode will reset because of timeout";


//----------RAM data structures for columns ----

unsigned fwxqhcldoo[5];
Watch_dog_struct_CFL_t * axtiblgbgv[5];
unsigned char hjmynlunde[5];
unsigned char tyimchpchb[5];
void* efwjxargvs[5];
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

static const Column_ROM_CFL_t ibtuezoeqe[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,true, 1, 5, 4, -1, -1 },
  { -1,true, 2, 5, 9, -1, -1 },
  { -1,true, 3, 4, 19, -1, -1 },
  { -1,true, 4, 5, 14, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char ucjbwzgzzt[23];


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

static const Column_element_CFL_t etenbfidij[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&bstzpsqxax},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lkjntajtgk_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mvabyhfixa},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uacqzwmgsh},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fvxvlbrlnr_rom},
    {one_shot_handler_CFL,send_event_CFL,(void *)&xcdilqthnd},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kjzwpovkqn},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&llswkpmlep},
    {while_handler_CFL,test_bool_fn,(void *)&lwxlwqyjhn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fxrvosvxly},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gcqeutfgts},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uswjwtrcmx},
    {while_handler_CFL,false_constant_handler,(void *)&ontasgvunf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qkbgzhdpcr},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rcbqymlmfh},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zztjyoqvsn},
    {while_handler_CFL,false_constant_handler,(void *)&fltxwpmhpx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&famcqhieto},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};


static Time_control_CFL_t fzzjramzdt;




static Engine_control_CFL_t aywpeltpjl;


/* remaining allocate heap size */

static unsigned ifuzevafpg;


/* current heap pointer */

static char* svanflmave;


/* heap block area */

static CS_MEMORY_CONTROL pdnjuvmokf;


    
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


const struct Handle_CFL_t homhdsvffx =
{

  .queue_number = 1,
  .queue_rom = yxamsdfqlo,
  .queue_ram = lbrbabbbxv,

  .column_elements_flags =ucjbwzgzzt,
  .column_elements_ROM = etenbfidij,

  .watch_dog_struct = axtiblgbgv,
  .watch_dog_count  = fwxqhcldoo,
   
   
  .column_flags = hjmynlunde,
  .column_local_data = efwjxargvs,
  .column_state = tyimchpchb,
  .number_of_columns = 5,
  .column_rom_data = ibtuezoeqe,

  
  
  
  .time_control = &fzzjramzdt,
  .engine_control =&aywpeltpjl,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &ifuzevafpg,
  .current_heap_location = &svanflmave,
  .private_heap   = &pdnjuvmokf,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  while_user_function_handle(){
    return &homhdsvffx;
}
   

#ifdef __cplusplus
}
#endif

#endif
