#ifndef __tod_H__
#define __tod_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t erycivbcgv[10];
static Event_control_RAM_CFL_t sgvkolgztb[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t hcbhdbsrxw_default = { 10, 0 };
static const Event_control_ROM_CFL_t *hcbhdbsrxw[] = {
     &hcbhdbsrxw_default,
};
static const Named_event_queue_control_CFL_t hqborluynv = { 1,10,hcbhdbsrxw };

static const char failure_verify_50[] = "failure for verify 50";
static const char failure_verify_49[] = "failure for verify 49";
static const char failure_verify_28[] = "failure for verify 28";



unsigned  cbldniqztf;
const While_time_control_ROM_CFL_t twsufbenck = { 180000,&cbldniqztf };



static While_control_RAM_CFL_t rtbukkddcp_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nplxgdkmpx_rom = { 0 ,true, &twsufbenck,&rtbukkddcp_ram,null_function};

    
static const char *vnfysgbkun = "wait less than 10 seconds";
   const Wait_tod_ROM_CFL_t eobdrowkcg_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,10,true,NULL }; 

static While_control_RAM_CFL_t fnkarlqgmu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uzxfbdwdyc_rom = { -1 ,true, &eobdrowkcg_rom,&fnkarlqgmu_ram,null_function};

    
static const char *ovjswavgrk = "wait passed less than 10 seconds";
static const char *xletcsfnka = "wait less than equal 15 seconds";
   const Wait_tod_ROM_CFL_t iqjbattszh_rom = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,15,true,NULL }; 

static While_control_RAM_CFL_t qdamltsduj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zlopnoxmtw_rom = { -1 ,true, &iqjbattszh_rom,&qdamltsduj_ram,null_function};

    
static const char *ohidlzdqtp = "wait equal 17 seconds";
   const Wait_tod_ROM_CFL_t jwehtxnikj_rom = { OP_EQ_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t tdwxhjrqvl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dbpfsaysyw_rom = { -1 ,true, &jwehtxnikj_rom,&tdwxhjrqvl_ram,null_function};

    
static const char *ztivkuejli = "wait greater than equal 20 seconds";
   const Wait_tod_ROM_CFL_t rphdvmrzlq_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,20,true,NULL }; 

static While_control_RAM_CFL_t hjkxjwpjeb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pecvstjzzo_rom = { -1 ,true, &rphdvmrzlq_rom,&hjkxjwpjeb_ram,null_function};

    
static const char *npibrsfqqd = "wait greater than 50 seconds";
   const Wait_tod_ROM_CFL_t hojweitdli_rom = { OP_GT_CFL,-1,-1,-1,-1,-1,-1,50,true,NULL }; 

static While_control_RAM_CFL_t vrleujkxmu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qdnxnuyhef_rom = { -1 ,true, &hojweitdli_rom,&vrleujkxmu_ram,null_function};

    
static const char *anxoeiuiqc = "Reseting column";
static const char *mdwegetxuy = "verify tod column start";
   const Wait_tod_ROM_CFL_t fxskfwylhc_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,1,true,NULL }; 

static While_control_RAM_CFL_t rpisimhazh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wbivjrduap_rom = { -1 ,true, &fxskfwylhc_rom,&rpisimhazh_ram,null_function};

    
static const char *vctzevlvuq = "made it pass 0";
   const Wait_tod_ROM_CFL_t qpiuvavrxn_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t nenkbugxrt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pdxfveqbow_rom = { -1 ,true, &qpiuvavrxn_rom,&nenkbugxrt_ram,null_function};

    
static const char *jvfldiqdyw = "made it past 17 seconds";
   const Wait_tod_ROM_CFL_t jnlgxustmi = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,50,true,failure_verify_50 }; 
    static Verify_control_ROM_CFL_t rhphlostwn_rom = { true, (void *)&jnlgxustmi, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t digrzcfbmq = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,49,true,failure_verify_49 }; 
    static Verify_control_ROM_CFL_t mkkcxsvway_rom = { true, (void *)&digrzcfbmq, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t nsmqiyweko = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,28,false,failure_verify_28 }; 
    static Verify_control_ROM_CFL_t esofdckahq_rom = { false, (void *)&nsmqiyweko, tod_verify_reset };  // terminate flag,user data,one shot function


//----------RAM data structures for columns ----

unsigned fbrhzadlrr[3];
unsigned pkequbkxrb[3];
One_shot_function_CFL_t  gypqjwfhgk[3];
bool  zdupzfhgne[3];
void *  ahkynqvnvp[3];
unsigned char gmcwrnccdl[3];
unsigned char amrbfyypjy[3];
void* hutykyofot[3];
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

static const Column_ROM_CFL_t ssqyweevmb[] = {
  { -1,true, 0, 2, 0, -1, -1 },
  { -1,true, 1, 13, 2, -1, -1 },
  { -1,true, 2, 9, 15, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char dzhjeumaww[24];


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

static const Column_element_CFL_t umqwktjxac[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nplxgdkmpx_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vnfysgbkun},
    {while_handler_CFL,test_tod_condition,(void *)&uzxfbdwdyc_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ovjswavgrk},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xletcsfnka},
    {while_handler_CFL,test_tod_condition,(void *)&zlopnoxmtw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ohidlzdqtp},
    {while_handler_CFL,test_tod_condition,(void *)&dbpfsaysyw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ztivkuejli},
    {while_handler_CFL,test_tod_condition,(void *)&pecvstjzzo_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&npibrsfqqd},
    {while_handler_CFL,test_tod_condition,(void *)&qdnxnuyhef_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&anxoeiuiqc},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mdwegetxuy},
    {while_handler_CFL,test_tod_condition,(void *)&wbivjrduap_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vctzevlvuq},
    {while_handler_CFL,test_tod_condition,(void *)&pdxfveqbow_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jvfldiqdyw},
    {verify_handler_CFL,test_tod_condition,(void *)&rhphlostwn_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&mkkcxsvway_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&esofdckahq_rom},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};


static Time_control_CFL_t ufkalvtsgr;




static Engine_control_CFL_t frkpxqmphk;


/* remaining allocate heap size */

static unsigned xghesgrnrn;


/* current heap pointer */

static char* ecazouawad;


/* heap block area */

static CS_MEMORY_CONTROL rblfbunngf;


      
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t iovbdnioaa =
{

  .queue_rom    = &hqborluynv,
  .queue_ram =  sgvkolgztb,
  .event_data = erycivbcgv,

  .column_elements_flags =dzhjeumaww,
  .column_elements_ROM = umqwktjxac,

  .watch_dog_trigger_count = fbrhzadlrr,
  .watch_dog_count       =  pkequbkxrb,  
  .watch_dog_trigger_function = gypqjwfhgk,
  .watch_dog_termination_flag = zdupzfhgne,
  .watch_dog_user_data = ahkynqvnvp,
   
   
  .column_flags = gmcwrnccdl,
  .column_local_data = hutykyofot,
  .column_state = amrbfyypjy,
  .number_of_columns = 3,
  .column_rom_data = ssqyweevmb,

  
  
  
  .time_control = &ufkalvtsgr,
  .engine_control =&frkpxqmphk,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &xghesgrnrn,
  .current_heap_location = &ecazouawad,
  .private_heap   = &rblfbunngf,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  tod_handle(){
    return &iovbdnioaa;
}
   

#ifdef __cplusplus
}
#endif

#endif
