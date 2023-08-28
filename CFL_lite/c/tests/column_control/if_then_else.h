#ifndef __if_then_else_H__
#define __if_then_else_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t mzxeqmbvql[1];
static Event_data_CFL_t htjcccvrud[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t jxovacfaej[] = { 
     {  10, htjcccvrud },
};
static const char *tpsguvfzwy = "starting if_then_else command";
static const unsigned short lcogyjkyug[] = { 1,2,6};
static const unsigned short jtrvsbczci[] = { 4,5,6};
const If_then_else_CFL_t rtfemnwvbx = { true, true, 3, lcogyjkyug, 3, jtrvsbczci,NULL };
static const unsigned short ldsuhsbady[] = { 1,2,6};
static const unsigned short nqnkpfeauz[] = { 4,5,6};
const If_then_else_CFL_t ttvvouwuet = { true, true, 3, ldsuhsbady, 3, nqnkpfeauz,NULL };
static const char *niboqnwnfr = "done with if_then_else statement";
static const char *blohhpvluz = "if_then_0 should be active";


unsigned  lyaudlqmqh;
const While_time_control_ROM_CFL_t gprvcqmfzx = { 1000,&lyaudlqmqh };



static While_control_RAM_CFL_t ioohviryfj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vrwyolgntv_rom = { 0 ,true, &gprvcqmfzx,&ioohviryfj_ram,null_function};

    
static const char *odeohtdiby = "if_then_0 is terminating";
static const char *vwzsnlmrzn = "if_then_1 should be active";


unsigned  keclncbivh;
const While_time_control_ROM_CFL_t zsfjwyerit = { 2000,&keclncbivh };



static While_control_RAM_CFL_t hsppvfvdmd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rtnakjjckx_rom = { 0 ,true, &zsfjwyerit,&hsppvfvdmd_ram,null_function};

    
static const char *dbygcngxxg = "if_then_1 is terminating";
static const char *ogsqrojsar = "if_then_2 should be active";


unsigned  bohtqlnsmi;
const While_time_control_ROM_CFL_t ikbxbyjpmy = { 3000,&bohtqlnsmi };



static While_control_RAM_CFL_t acahcdtqhv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ogrznefdzk_rom = { 0 ,true, &ikbxbyjpmy,&acahcdtqhv_ram,null_function};

    
static const char *nczlgnyruh = "if_then_2 is terminating";
static const char *szduaidyqv = "if_else_0 should be active";


unsigned  ntvxqfwrtt;
const While_time_control_ROM_CFL_t vktzjbhqvu = { 1000,&ntvxqfwrtt };



static While_control_RAM_CFL_t qkzgsejwme_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zjopnuyqds_rom = { 0 ,true, &vktzjbhqvu,&qkzgsejwme_ram,null_function};

    
static const char *rifwfxrjfm = "if_else_0 is terminating";
static const char *umenanvwud = "if_else_0 should be active";


unsigned  bkvajqobio;
const While_time_control_ROM_CFL_t nusptqqtzx = { 2000,&bkvajqobio };



static While_control_RAM_CFL_t ntgnuuselk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hpbxxhbigx_rom = { 0 ,true, &nusptqqtzx,&ntgnuuselk_ram,null_function};

    
static const char *qpoquwrvxl = "if_else_1 is terminating";
static const char *smjrxauvup = "if_else_0 should be active";


unsigned  cddpibdyvk;
const While_time_control_ROM_CFL_t fdscexmhdv = { 3000,&cddpibdyvk };



static While_control_RAM_CFL_t xoujjfyksk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tujeyjwnxu_rom = { 0 ,true, &fdscexmhdv,&xoujjfyksk_ram,null_function};

    
static const char *etozrctsbk = "if_else_2 is terminating";


//----------RAM data structures for columns ----

unsigned dymmgcbaug[7];
Watch_dog_struct_CFL_t * nqkoctjuzf[7];
unsigned char fzcdvppigh[7];
unsigned char mthmdrjdoh[7];
void* eyildplxes[7];
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

static const Column_ROM_CFL_t ibcqzojjrx[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { -1,false, 1, 4, 5, -1, -1 },
  { -1,false, 2, 4, 9, -1, -1 },
  { -1,false, 3, 4, 13, -1, -1 },
  { -1,false, 4, 4, 17, -1, -1 },
  { -1,false, 5, 4, 21, -1, -1 },
  { -1,false, 6, 4, 25, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char xgzvqjufvi[29];


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

static const Column_element_CFL_t nsuuzjyfto[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&tpsguvfzwy},
    {if_then_else_function_CFL,true_constant_handler,(void *)&rtfemnwvbx},
    {if_then_else_function_CFL,false_constant_handler,(void *)&ttvvouwuet},
    {one_shot_handler_CFL,log_message_CFL,(void *)&niboqnwnfr},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&blohhpvluz},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vrwyolgntv_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&odeohtdiby},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vwzsnlmrzn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rtnakjjckx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dbygcngxxg},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ogsqrojsar},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ogrznefdzk_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nczlgnyruh},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&szduaidyqv},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zjopnuyqds_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rifwfxrjfm},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&umenanvwud},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hpbxxhbigx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qpoquwrvxl},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&smjrxauvup},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tujeyjwnxu_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&etozrctsbk},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t hagimllzse;




static Engine_control_CFL_t sypeqkubdh;


/* remaining allocate heap size */

static unsigned ihdqrbmnpw;


/* current heap pointer */

static char* klsfcbrpdl;


/* heap block area */

static CS_MEMORY_CONTROL qomkyzcnzv;


    
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


const struct Handle_CFL_t sjiouvftpw =
{

  .queue_number = 1,
  .queue_rom = jxovacfaej,
  .queue_ram = mzxeqmbvql,

  .column_elements_flags =xgzvqjufvi,
  .column_elements_ROM = nsuuzjyfto,

  .watch_dog_struct = nqkoctjuzf,
  .watch_dog_count  = dymmgcbaug,
   
   
  .column_flags = fzcdvppigh,
  .column_local_data = eyildplxes,
  .column_state = mthmdrjdoh,
  .number_of_columns = 7,
  .column_rom_data = ibcqzojjrx,

  
  
  
  .time_control = &hagimllzse,
  .engine_control =&sypeqkubdh,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &ihdqrbmnpw,
  .current_heap_location = &klsfcbrpdl,
  .private_heap   = &qomkyzcnzv,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  if_then_else_handle(){
    return &sjiouvftpw;
}
   

#ifdef __cplusplus
}
#endif

#endif
