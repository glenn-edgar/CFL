#ifndef __while_column_H__
#define __while_column_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t mhoxxepmwk[1];
static Event_data_CFL_t swaidcvsir[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t tcgaythxvx[] = { 
     {  10, swaidcvsir },
};
static const char* while_message = "This is a test message for while \n";
static const char *xvoovillbl = "starting while command";
static const unsigned short agycfpbdsk[] = { 1,2,3};
bool dfyhsikwqz = true;
unsigned tkkezebrxh = 0;
const While_column_control_CFL_t dxetpjukqe = { (bool *)&dfyhsikwqz, (unsigned *)&tkkezebrxh, (void *)&while_message, 3,agycfpbdsk };
static const char *uhgvtwrthy = "done with while statement";
static const char *vhaighvvpx = "while_0 should be active";


unsigned  xhwqkomfnn;
const While_time_control_ROM_CFL_t noohxotmtk = { 1000,&xhwqkomfnn };



static While_control_RAM_CFL_t mbgycyuxme_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qhbfpxbcsc_rom = { 0 ,true, &noohxotmtk,&mbgycyuxme_ram,null_function};

    
static const char *fzlsqfhgbe = "while_0 is terminating";
static const char *iiqiycrrse = "while_1 should be active";


unsigned  vempyscjlt;
const While_time_control_ROM_CFL_t gsybrkdfxw = { 2000,&vempyscjlt };



static While_control_RAM_CFL_t fnnjtjtfnu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t luqdjlozim_rom = { 0 ,true, &gsybrkdfxw,&fnnjtjtfnu_ram,null_function};

    
static const char *dgjtuchyri = "while_1 is terminating";
static const char *sliikzilkw = "while_2 should be active";


unsigned  helxpmfekm;
const While_time_control_ROM_CFL_t yeytmbugwz = { 3000,&helxpmfekm };



static While_control_RAM_CFL_t kxfvpezugc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qlcujokggd_rom = { 0 ,true, &yeytmbugwz,&kxfvpezugc_ram,null_function};

    
static const char *wduiewjyev = "while_2 is terminating";


//----------RAM data structures for columns ----

unsigned tmfsggmdat[4];
Watch_dog_struct_CFL_t * yfgvsbbuaa[4];
unsigned char bsrukcgslj[4];
unsigned char kyjjxncbks[4];
void* ldsyutvbsm[4];
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

static const Column_ROM_CFL_t xfdratilfd[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,false, 1, 4, 4, -1, -1 },
  { -1,false, 2, 4, 8, -1, -1 },
  { -1,false, 3, 4, 12, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char uorcxsawsc[16];


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

static const Column_element_CFL_t ckquwftzjy[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&xvoovillbl},
    {while_column_handler_CFL,while_column_test,(void *)&dxetpjukqe},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uhgvtwrthy},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vhaighvvpx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qhbfpxbcsc_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fzlsqfhgbe},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iiqiycrrse},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&luqdjlozim_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dgjtuchyri},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sliikzilkw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qlcujokggd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wduiewjyev},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t cltyxlnnbx;




static Engine_control_CFL_t nkwdvcfeqr;


/* remaining allocate heap size */

static unsigned tibhkvzkih;


/* current heap pointer */

static char* pnumowuefi;


/* heap block area */

static CS_MEMORY_CONTROL ypnqcymhan;


    
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


const struct Handle_CFL_t wjyughczkx =
{

  .queue_number = 1,
  .queue_rom = tcgaythxvx,
  .queue_ram = mhoxxepmwk,

  .column_elements_flags =uorcxsawsc,
  .column_elements_ROM = ckquwftzjy,

  .watch_dog_struct = yfgvsbbuaa,
  .watch_dog_count  = tmfsggmdat,
   
   
  .column_flags = bsrukcgslj,
  .column_local_data = ldsyutvbsm,
  .column_state = kyjjxncbks,
  .number_of_columns = 4,
  .column_rom_data = xfdratilfd,

  
  
  
  .time_control = &cltyxlnnbx,
  .engine_control =&nkwdvcfeqr,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &tibhkvzkih,
  .current_heap_location = &pnumowuefi,
  .private_heap   = &ypnqcymhan,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  while_column_handle(){
    return &wjyughczkx;
}
   

#ifdef __cplusplus
}
#endif

#endif
