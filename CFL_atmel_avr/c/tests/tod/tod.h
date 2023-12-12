#ifndef __tod_H__
#define __tod_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t fxjdexsshv[1];
static Event_data_CFL_t hsepsknfxh[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t xutvybgick[] = { 
     {  10, hsepsknfxh },
};

static const char failure_verify_50[] = "failure for verify 50";
static const char failure_verify_49[] = "failure for verify 49";
static const char failure_verify_28[] = "failure for verify 28";



unsigned  nqivbdohke;
const While_time_control_ROM_CFL_t tmjsgtvopv = { 180000,&nqivbdohke };



static While_control_RAM_CFL_t nrqmyurisg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cgynrdyonc_rom = { 0 ,true, &tmjsgtvopv,&nrqmyurisg_ram,null_function};

    
static const char *ngocwighqk = "wait less than 10 seconds";
   const Wait_tod_ROM_CFL_t zsksvbmkwx_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,10,true,NULL }; 

static While_control_RAM_CFL_t omrhfchnnw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t clynqirrky_rom = { -1 ,true, &zsksvbmkwx_rom,&omrhfchnnw_ram,null_function};

    
static const char *tuwdqrbmub = "wait passed less than 10 seconds";
static const char *jxtnkmzjnu = "wait less than equal 15 seconds";
   const Wait_tod_ROM_CFL_t twnrbxxnqs_rom = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,15,true,NULL }; 

static While_control_RAM_CFL_t kukkdpbwfj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qhruxhymqz_rom = { -1 ,true, &twnrbxxnqs_rom,&kukkdpbwfj_ram,null_function};

    
static const char *ucjbnfhpna = "wait equal 17 seconds";
   const Wait_tod_ROM_CFL_t ohcqurgeny_rom = { OP_EQ_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t eqzbrhujvn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t touunrrtro_rom = { -1 ,true, &ohcqurgeny_rom,&eqzbrhujvn_ram,null_function};

    
static const char *nlheoutdtl = "wait greater than equal 20 seconds";
   const Wait_tod_ROM_CFL_t pibhmyzagn_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,20,true,NULL }; 

static While_control_RAM_CFL_t avazxtrcfx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kjsrfzyiep_rom = { -1 ,true, &pibhmyzagn_rom,&avazxtrcfx_ram,null_function};

    
static const char *cwjhpxoxgv = "wait greater than 50 seconds";
   const Wait_tod_ROM_CFL_t uirpkoikkf_rom = { OP_GT_CFL,-1,-1,-1,-1,-1,-1,50,true,NULL }; 

static While_control_RAM_CFL_t oudfvudhuc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t udrciiijvn_rom = { -1 ,true, &uirpkoikkf_rom,&oudfvudhuc_ram,null_function};

    
static const char *nuyribbugx = "Reseting column";
static const char *xmrxujtwue = "verify tod column start";
   const Wait_tod_ROM_CFL_t obpyouqkeb_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,1,true,NULL }; 

static While_control_RAM_CFL_t nqqhpaufhj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t akaggxbrti_rom = { -1 ,true, &obpyouqkeb_rom,&nqqhpaufhj_ram,null_function};

    
static const char *yisdyaaxoh = "made it pass 0";
   const Wait_tod_ROM_CFL_t xfkxcfjjeo_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t oqqyndzkyz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wbbetaaogw_rom = { -1 ,true, &xfkxcfjjeo_rom,&oqqyndzkyz_ram,null_function};

    
static const char *aqfzkzsjgu = "made it past 17 seconds";
   const Wait_tod_ROM_CFL_t glxigsdwhd = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,50,true,failure_verify_50 }; 
    static Verify_control_ROM_CFL_t msvzgrxcvj_rom = { true, (void *)&glxigsdwhd, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t monphzgfxi = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,49,true,failure_verify_49 }; 
    static Verify_control_ROM_CFL_t ickomtftbq_rom = { true, (void *)&monphzgfxi, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t xyznkaohdi = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,28,false,failure_verify_28 }; 
    static Verify_control_ROM_CFL_t kbnrejjehp_rom = { false, (void *)&xyznkaohdi, tod_verify_reset };  // terminate flag,user data,one shot function


//----------RAM data structures for columns ----

unsigned eqyutbaabg[3];
Watch_dog_struct_CFL_t * eqerhzijbu[3];
unsigned char oexvvmwmao[3];
unsigned char uunnwfqmtl[3];
void* ufgewdsijh[3];
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

static const Column_ROM_CFL_t axuiiqqibp[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 13, 2, -1, -1 },
  { -1,true, 2, 9, 15, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char pumfbgkwyd[24];


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

static const Column_element_CFL_t jlepgjkuwd[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cgynrdyonc_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ngocwighqk},
    {while_handler_CFL,test_tod_condition,(void *)&clynqirrky_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tuwdqrbmub},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jxtnkmzjnu},
    {while_handler_CFL,test_tod_condition,(void *)&qhruxhymqz_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ucjbnfhpna},
    {while_handler_CFL,test_tod_condition,(void *)&touunrrtro_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nlheoutdtl},
    {while_handler_CFL,test_tod_condition,(void *)&kjsrfzyiep_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cwjhpxoxgv},
    {while_handler_CFL,test_tod_condition,(void *)&udrciiijvn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nuyribbugx},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xmrxujtwue},
    {while_handler_CFL,test_tod_condition,(void *)&akaggxbrti_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yisdyaaxoh},
    {while_handler_CFL,test_tod_condition,(void *)&wbbetaaogw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aqfzkzsjgu},
    {verify_handler_CFL,test_tod_condition,(void *)&msvzgrxcvj_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&ickomtftbq_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&kbnrejjehp_rom},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};


static Time_control_CFL_t tvztkgunvu;




static Engine_control_CFL_t ktwpqthkfn;


/* remaining allocate heap size */

static unsigned zwlrnyvprd;


/* current heap pointer */

static char* tqalmrdtba;


/* heap block area */

static CS_MEMORY_CONTROL crqcdnltat;


    
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


const struct Handle_CFL_t dwnuhnmxxk =
{

  .queue_number = 1,
  .queue_rom = xutvybgick,
  .queue_ram = fxjdexsshv,

  .column_elements_flags =pumfbgkwyd,
  .column_elements_ROM = jlepgjkuwd,

  .watch_dog_struct = eqerhzijbu,
  .watch_dog_count  = eqyutbaabg,
   
   
  .column_flags = oexvvmwmao,
  .column_local_data = ufgewdsijh,
  .column_state = uunnwfqmtl,
  .number_of_columns = 3,
  .column_rom_data = axuiiqqibp,

  
  
  
  .time_control = &tvztkgunvu,
  .engine_control =&ktwpqthkfn,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &zwlrnyvprd,
  .current_heap_location = &tqalmrdtba,
  .private_heap   = &crqcdnltat,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  tod_handle(){
    return &dwnuhnmxxk;
}
   

#ifdef __cplusplus
}
#endif

#endif
