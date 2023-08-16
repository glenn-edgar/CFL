#ifndef __tod_H__
#define __tod_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t maqkfvqepn[10];
static Event_control_RAM_CFL_t brgbojotgv[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t gxvtrubgdx_default = { 10, 0 };
static const Event_control_ROM_CFL_t *gxvtrubgdx[] = {
     &gxvtrubgdx_default,
};
static const Named_event_queue_control_CFL_t aonnsrlpoi = { 1,10,gxvtrubgdx };

static const char failure_verify_50[] = "failure for verify 50";
static const char failure_verify_49[] = "failure for verify 49";
static const char failure_verify_28[] = "failure for verify 28";



unsigned  woilirnpix;
const While_time_control_ROM_CFL_t oqlygutziq = { 120000,&woilirnpix };



static While_control_RAM_CFL_t fquqbtsjaq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t howmdqfuxf_rom = { 0 ,true, &oqlygutziq,&fquqbtsjaq_ram,null_function};

    
static const char *ytmxqftqvj = "wait less than 10 seconds";
   const Wait_tod_ROM_CFL_t ukdvmfotau_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,10,true,NULL }; 

static While_control_RAM_CFL_t rzbzfyodrr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t luffmkpxke_rom = { -1 ,true, &ukdvmfotau_rom,&rzbzfyodrr_ram,null_function};

    
static const char *udyetngpmd = "wait passed less than 10 seconds";
static const char *fyslrxeycq = "wait less than equal 15 seconds";
   const Wait_tod_ROM_CFL_t xcnprqhjfh_rom = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,15,true,NULL }; 

static While_control_RAM_CFL_t vxnotnzdxd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ajwmugkkld_rom = { -1 ,true, &xcnprqhjfh_rom,&vxnotnzdxd_ram,null_function};

    
static const char *rqwhsbdzdo = "wait equal 17 seconds";
   const Wait_tod_ROM_CFL_t zedlqfshuk_rom = { OP_EQ_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t metledjbtx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t olmbeysgyh_rom = { -1 ,true, &zedlqfshuk_rom,&metledjbtx_ram,null_function};

    
static const char *rwyszazxjf = "wait greater than equal 20 seconds";
   const Wait_tod_ROM_CFL_t eabofaeckg_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,20,true,NULL }; 

static While_control_RAM_CFL_t apatyoxrlf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yfzuioavju_rom = { -1 ,true, &eabofaeckg_rom,&apatyoxrlf_ram,null_function};

    
static const char *bqrvpnsanh = "wait greater than 50 seconds";
   const Wait_tod_ROM_CFL_t fsdlbwbxth_rom = { OP_GT_CFL,-1,-1,-1,-1,-1,-1,50,true,NULL }; 

static While_control_RAM_CFL_t dzjozpouyj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bxgppdkzlx_rom = { -1 ,true, &fsdlbwbxth_rom,&dzjozpouyj_ram,null_function};

    
static const char *jkizbmruqt = "Reseting column";
static const char *ibjodigaca = "verify tod column start";
static const char *txuxgtcsdf = "made it past 20 seconds";
static const char *sqpkqfeudt = "at reset at 28";
   const Wait_tod_ROM_CFL_t vklnyhhqso_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,27,true,NULL }; 

static While_control_RAM_CFL_t ucduwsbbqy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dcozdwtnyf_rom = { -1 ,true, &vklnyhhqso_rom,&ucduwsbbqy_ram,null_function};

    
   const Wait_tod_ROM_CFL_t qevslyecdo_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,50,true,failure_verify_50 }; 
    static Verify_control_ROM_CFL_t kicizrpmsi_rom_rom = { true, (const void *)&qevslyecdo_rom, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t upzgjjaqxv_rom = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,49,true,failure_verify_49 }; 
    static Verify_control_ROM_CFL_t gftgadogtf_rom_rom = { true, (const void *)&upzgjjaqxv_rom, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t ohwvfzgypr_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,28,false,failure_verify_28 }; 
    static Verify_control_ROM_CFL_t vtaacpqwsn_rom_rom = { false, (const void *)&ohwvfzgypr_rom, tod_verify_reset };  // terminate flag,user data,one shot function


//----------RAM data structures for columns ----

unsigned char ecopgggozq[3];
unsigned char fmywnidynn[3];
void* sbicsfqwbb[3];
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

static const Column_ROM_CFL_t cbjfeclxpo[] = {
  { -1,true, 0, 2, 0, -1, -1,-1 },
  { -1,true, 1, 13, 2, -1, -1,-1 },
  { -1,true, 2, 8, 15, -1, -1,-1 },
};


//----------Column elements RAM structures----



static unsigned char urpqyrxxjf[23];


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

static const Column_element_CFL_t fjlbbahsjn[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&howmdqfuxf_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ytmxqftqvj},
    {while_handler_CFL,test_tod_condition,(void *)&luffmkpxke_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&udyetngpmd},
    {one_shot_handler_CFL,log_message_CFL,(void *)&fyslrxeycq},
    {while_handler_CFL,test_tod_condition,(void *)&ajwmugkkld_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rqwhsbdzdo},
    {while_handler_CFL,test_tod_condition,(void *)&olmbeysgyh_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rwyszazxjf},
    {while_handler_CFL,test_tod_condition,(void *)&yfzuioavju_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bqrvpnsanh},
    {while_handler_CFL,test_tod_condition,(void *)&bxgppdkzlx_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jkizbmruqt},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ibjodigaca},
    {one_shot_handler_CFL,log_message_CFL,(void *)&txuxgtcsdf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sqpkqfeudt},
    {while_handler_CFL,test_tod_condition,(void *)&dcozdwtnyf_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&kicizrpmsi_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&gftgadogtf_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&vtaacpqwsn_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t kygqezbnoe;




static Engine_control_CFL_t shdmfuzvlv;


/* remaining allocate heap size */

static unsigned koukfjlbcu;


/* current heap pointer */

static char* wcbtmsugtp;


/* heap block area */

static CS_MEMORY_CONTROL dbcqmgkhuz;



 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t musirggdwr =
{

  .queue_rom    = &aonnsrlpoi,
  .queue_ram =  brgbojotgv,
  .event_data = maqkfvqepn,

  .column_elements_flags =urpqyrxxjf,
  .column_elements_ROM = fjlbbahsjn,

  .column_flags = ecopgggozq,
  .column_local_data = sbicsfqwbb,
  .column_state = fmywnidynn,
  .number_of_columns = 3,
  .column_rom_data = cbjfeclxpo,

  .number_of_watch_dogs = 0,
  .watch_dog_active = NULL,
  .watch_dog_count = NULL,
  .watch_dog_trigger_count = NULL,
  .watch_dog_rom_data = NULL,
  .time_control = &kygqezbnoe,
  .engine_control =&shdmfuzvlv,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &koukfjlbcu,
  .current_heap_location = &wcbtmsugtp,
  .private_heap   = &dbcqmgkhuz,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  tod_handle(){
    return &musirggdwr;
}
   

#ifdef __cplusplus
}
#endif

#endif
