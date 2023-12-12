#ifndef __if_then_else_H__
#define __if_then_else_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t jmmvqmecjo[1];
static Event_data_CFL_t dtwtwrjmxu[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t mhoxwfxmim[] = { 
     {  10, dtwtwrjmxu },
};
static const char *lvrlagydje = "starting test_if column";
static const unsigned short ewjcacnjzw[] = { 1,2,3};
static const unsigned short ljfatgmmbi[] = { 4,5,6};
const If_then_else_CFL_t izqcdevuaq = { true, true, 3, ewjcacnjzw, 3, ljfatgmmbi,NULL };
static const unsigned short yieshlcmdg[] = { 1,2,3};
static const unsigned short exihexidfs[] = { 4,5,6};
const If_then_else_CFL_t djmimvohae = { true, true, 3, yieshlcmdg, 3, exihexidfs,NULL };
static const unsigned short oyiknfrcjr[] = { 1,2,3};
static const unsigned short xofbngklai[] = { 4,5,6};
const If_then_else_CFL_t qlrytnknub = { false, false, 3, oyiknfrcjr, 3, xofbngklai,NULL };
static const unsigned short uihvueqeuq[] = { 1,2,3};
static const unsigned short moaribizji[] = { 4,5,6};
const If_then_else_CFL_t qoevjkjysj = { false, false, 3, uihvueqeuq, 3, moaribizji,NULL };
static const char *covtfldhly = "done with if_then_else column";


unsigned  qopvfwyuzr;
const While_time_control_ROM_CFL_t vlkjaufiod = { 4000,&qopvfwyuzr };



static While_control_RAM_CFL_t evunbnwagh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vypijvaivw_rom = { 0 ,true, &vlkjaufiod,&evunbnwagh_ram,null_function};

    
static const char *wlthbfxtle = "time delay is over";
static const unsigned short ulsmptuxaw[] = { 1,2,3};
static const unsigned short apircgladw[] = { 4,5,6};
const If_then_else_CFL_t iopfhezbvu = { true, false, 3, ulsmptuxaw, 3, apircgladw,NULL };
static const unsigned short kvklzehvph[] = { 1,2,3};
static const unsigned short pychfpnlfa[] = { 4,5,6};
const If_then_else_CFL_t gyxrlxcaby = { true, false, 3, kvklzehvph, 3, pychfpnlfa,NULL };
static const char *vxqqvnpfwc = "terminate flag set to true will kill child columns when terminate_column is called";
static const char *tniocxvftw = "if_then_0 should be active";


unsigned  kwdnhfooaw;
const While_time_control_ROM_CFL_t kfypiqclae = { 1000,&kwdnhfooaw };



static While_control_RAM_CFL_t ygltefofqy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vbnftofiuq_rom = { 0 ,true, &kfypiqclae,&ygltefofqy_ram,null_function};

    
static const char *srqtrcmmyw = "if_then_0 is terminating";
static const char *igycxiodgv = "if_then_1 should be active";


unsigned  bmmganjxxx;
const While_time_control_ROM_CFL_t zqupacliba = { 2000,&bmmganjxxx };



static While_control_RAM_CFL_t ashwsipwfl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t liqyqlhbzx_rom = { 0 ,true, &zqupacliba,&ashwsipwfl_ram,null_function};

    
static const char *foiiseloas = "if_then_1 is terminating";
static const char *jgnskxlfrc = "if_then_2 should be active";


unsigned  gapgvxtvaj;
const While_time_control_ROM_CFL_t aziguawudc = { 3000,&gapgvxtvaj };



static While_control_RAM_CFL_t stqpvjtnqx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t owqopvrfzp_rom = { 0 ,true, &aziguawudc,&stqpvjtnqx_ram,null_function};

    
static const char *tbhywiuawt = "if_then_2 is terminating";
static const char *nkwohaadfi = "if_else_0 should be active";


unsigned  mteceuekac;
const While_time_control_ROM_CFL_t niqutnpvbn = { 1000,&mteceuekac };



static While_control_RAM_CFL_t cmvtiemqtr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t viuhwwpjqm_rom = { 0 ,true, &niqutnpvbn,&cmvtiemqtr_ram,null_function};

    
static const char *vjwksodelv = "if_else_0 is terminating";
static const char *wppotqvlsx = "if_else_1 should be active";


unsigned  rqqdpvklla;
const While_time_control_ROM_CFL_t xixzqhasjm = { 2000,&rqqdpvklla };



static While_control_RAM_CFL_t crfcjuywdq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cszbnwbquw_rom = { 0 ,true, &xixzqhasjm,&crfcjuywdq_ram,null_function};

    
static const char *baelixnhyh = "if_else_1 is terminating";
static const char *wjhoarvllb = "if_else_2 should be active";


unsigned  fgjvaqncwh;
const While_time_control_ROM_CFL_t rbuvinourf = { 3000,&fgjvaqncwh };



static While_control_RAM_CFL_t uunubeifra_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cmbjigskiz_rom = { 0 ,true, &rbuvinourf,&uunubeifra_ram,null_function};

    
static const char *uxosdpxfwn = "if_else_2 is terminating";


//----------RAM data structures for columns ----

unsigned yljmebeefy[7];
Watch_dog_struct_CFL_t * ekotlllaru[7];
unsigned char svowpjxbjs[7];
unsigned char llsdibhbvc[7];
void* alunxwapog[7];
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

static const Column_ROM_CFL_t rlsippbgxj[] = {
  { -1,true, 0, 12, 0, -1, -1 },
  { -1,false, 1, 4, 12, -1, -1 },
  { -1,false, 2, 4, 16, -1, -1 },
  { -1,false, 3, 4, 20, -1, -1 },
  { -1,false, 4, 4, 24, -1, -1 },
  { -1,false, 5, 4, 28, -1, -1 },
  { -1,false, 6, 4, 32, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char comwguhojo[36];


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

static const Column_element_CFL_t qqjkvjvuot[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&lvrlagydje},
    {if_then_else_function_CFL,true_constant_handler,(void *)&izqcdevuaq},
    {if_then_else_function_CFL,false_constant_handler,(void *)&djmimvohae},
    {if_then_else_function_CFL,true_constant_handler,(void *)&qlrytnknub},
    {if_then_else_function_CFL,false_constant_handler,(void *)&qoevjkjysj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&covtfldhly},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vypijvaivw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wlthbfxtle},
    {if_then_else_function_CFL,true_constant_handler,(void *)&iopfhezbvu},
    {if_then_else_function_CFL,false_constant_handler,(void *)&gyxrlxcaby},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vxqqvnpfwc},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tniocxvftw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vbnftofiuq_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&srqtrcmmyw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&igycxiodgv},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&liqyqlhbzx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&foiiseloas},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jgnskxlfrc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&owqopvrfzp_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tbhywiuawt},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nkwohaadfi},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&viuhwwpjqm_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vjwksodelv},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wppotqvlsx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cszbnwbquw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&baelixnhyh},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wjhoarvllb},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cmbjigskiz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uxosdpxfwn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t pkvwvcrjox;




static Engine_control_CFL_t eyuwjuqkeq;


/* remaining allocate heap size */

static unsigned fqddmnegqk;


/* current heap pointer */

static char* qdyslrnjif;


/* heap block area */

static CS_MEMORY_CONTROL ltsabgfnih;


    
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


const struct Handle_CFL_t hzcbezaoey =
{

  .queue_number = 1,
  .queue_rom = mhoxwfxmim,
  .queue_ram = jmmvqmecjo,

  .column_elements_flags =comwguhojo,
  .column_elements_ROM = qqjkvjvuot,

  .watch_dog_struct = ekotlllaru,
  .watch_dog_count  = yljmebeefy,
   
   
  .column_flags = svowpjxbjs,
  .column_local_data = alunxwapog,
  .column_state = llsdibhbvc,
  .number_of_columns = 7,
  .column_rom_data = rlsippbgxj,

  
  
  
  .time_control = &pkvwvcrjox,
  .engine_control =&eyuwjuqkeq,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &fqddmnegqk,
  .current_heap_location = &qdyslrnjif,
  .private_heap   = &ltsabgfnih,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  if_then_else_handle(){
    return &hzcbezaoey;
}
   

#ifdef __cplusplus
}
#endif

#endif
