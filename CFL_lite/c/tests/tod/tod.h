#ifndef __tod_H__
#define __tod_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t cuwynafphn[3];
static Event_data_CFL_t rjyyfvzceu[7];
static Event_data_CFL_t mzbzcnbyly[0];
static Event_data_CFL_t imwxhxbapd[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t swvlwtdvfa[] = { 
     {  7, rjyyfvzceu },
     {  0, mzbzcnbyly },
     {  0, imwxhxbapd },
};

static const char failure_verify_50[] = "failure for verify 50";
static const char failure_verify_49[] = "failure for verify 49";
static const char failure_verify_28[] = "failure for verify 28";

static const char *nwvxqjytvx = "wait less than 10 seconds";
   const Wait_tod_ROM_CFL_t zimhqtdcny_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,10,true,NULL }; 

static While_control_RAM_CFL_t rdlhfeotkv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t oxmrxowlep_rom = { -1 ,true, (void*)&zimhqtdcny_rom,&rdlhfeotkv_ram,null_function};

    
static const char *ghjbudlreu = "wait passed less than 10 seconds";
static const char *ihnjuwgpww = "wait less than equal 15 seconds";
   const Wait_tod_ROM_CFL_t wjjeotojtw_rom = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,15,true,NULL }; 

static While_control_RAM_CFL_t crjierhwfm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wpgzodjlpn_rom = { -1 ,true, (void*)&wjjeotojtw_rom,&crjierhwfm_ram,null_function};

    
static const char *maprjqklco = "wait equal 17 seconds";
   const Wait_tod_ROM_CFL_t srpramesua_rom = { OP_EQ_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t xzywphufow_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t faavpxzmyb_rom = { -1 ,true, (void*)&srpramesua_rom,&xzywphufow_ram,null_function};

    
static const char *vlwkgvconb = "wait greater than equal 20 seconds";
   const Wait_tod_ROM_CFL_t ucmwsjgifo_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,20,true,NULL }; 

static While_control_RAM_CFL_t uydttmmomn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t emcmstxdxg_rom = { -1 ,true, (void*)&ucmwsjgifo_rom,&uydttmmomn_ram,null_function};

    
static const char *zmhyjngypj = "wait greater than 50 seconds";
   const Wait_tod_ROM_CFL_t yuuynlslnx_rom = { OP_GT_CFL,-1,-1,-1,-1,-1,-1,50,true,NULL }; 

static While_control_RAM_CFL_t yyehkxdmub_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bctsrzffvr_rom = { -1 ,true, (void*)&yuuynlslnx_rom,&yyehkxdmub_ram,null_function};

    
static const char *tofucssueh = "Reseting column";
static const char *evqafqboqe = "verify tod column start";
   const Wait_tod_ROM_CFL_t ibqocoxbuu_rom = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,1,true,NULL }; 

static While_control_RAM_CFL_t zwjmgqvtjc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hxkcdojhyi_rom = { -1 ,true, (void*)&ibqocoxbuu_rom,&zwjmgqvtjc_ram,null_function};

    
static const char *ixyyukrcek = "made it pass 0";
   const Wait_tod_ROM_CFL_t yjtptsqylx_rom = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,17,true,NULL }; 

static While_control_RAM_CFL_t dzeqjqmnpy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yvgytstsit_rom = { -1 ,true, (void*)&yjtptsqylx_rom,&dzeqjqmnpy_ram,null_function};

    
static const char *cxesxqfcjq = "made it past 17 seconds";
   const Wait_tod_ROM_CFL_t puknefsxzc = { OP_LT_CFL,-1,-1,-1,-1,-1,-1,50,false,(void*)&failure_verify_50 }; 
    static Verify_control_ROM_CFL_t ngssktzjfk_rom = { false, (void*)&puknefsxzc, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t scwwgspnqh = { OP_LE_CFL,-1,-1,-1,-1,-1,-1,49,false,(void*)&failure_verify_49 }; 
    static Verify_control_ROM_CFL_t ckhnzdxwyv_rom = { false, (void*)&scwwgspnqh, tod_verify_reset };  // terminate flag,user data,one shot function
   const Wait_tod_ROM_CFL_t jifqfcfwmg = { OP_GE_CFL,-1,-1,-1,-1,-1,-1,28,true,(void*)&failure_verify_28 }; 
    static Verify_control_ROM_CFL_t zkczwhmeml_rom = { true, (void*)&jifqfcfwmg, tod_verify_reset };  // terminate flag,user data,one shot function


//----------RAM data structures for columns ----

unsigned doktfvjnho[2];
Watch_dog_struct_CFL_t * kynzshzjuo[2];
unsigned char sgkvqsvsaf[2];
unsigned char kxjbrjbtnq[2];
void* sypvbvfbur[2];
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

static const Column_ROM_CFL_t jtcrcsjycw[] = {
  { 1,true, 0, 13, 0, -1, -1 },
  { 2,true, 1, 9, 13, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char vaztmuaqbx[22];


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

static const Column_element_CFL_t gufcjkdztr[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&nwvxqjytvx},
    {while_handler_CFL,test_tod_condition,(void *)&oxmrxowlep_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ghjbudlreu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ihnjuwgpww},
    {while_handler_CFL,test_tod_condition,(void *)&wpgzodjlpn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&maprjqklco},
    {while_handler_CFL,test_tod_condition,(void *)&faavpxzmyb_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vlwkgvconb},
    {while_handler_CFL,test_tod_condition,(void *)&emcmstxdxg_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zmhyjngypj},
    {while_handler_CFL,test_tod_condition,(void *)&bctsrzffvr_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tofucssueh},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&evqafqboqe},
    {while_handler_CFL,test_tod_condition,(void *)&hxkcdojhyi_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ixyyukrcek},
    {while_handler_CFL,test_tod_condition,(void *)&yvgytstsit_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cxesxqfcjq},
    {verify_handler_CFL,test_tod_condition,(void *)&ngssktzjfk_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&ckhnzdxwyv_rom},
    {verify_handler_CFL,test_tod_condition,(void *)&zkczwhmeml_rom},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
Bitmap_CFL bvmwqamtyp[0];
Registermap_CFL_t gmszwxmwcz[0];
Floatmap_CFL_t svawjpznst[0];
const Sm_control_ROM_CFL_t rfzqxovuhb[0];
Sm_control_RAM_CFL_t ewfyehbfkg[0];


static Time_control_CFL_t hrnkmtiloi;




static Engine_control_CFL_t inwckxqopy;


/* remaining allocate heap size */

static unsigned sfrwoszxwy;


/* current heap pointer */

static char* ardljkejhc;


/* heap block area */

static CS_MEMORY_CONTROL slxjeqfqcu;


    
    


const struct Handle_CFL_t fxisxqdcsl =
{

  .queue_number = 3,
  .queue_rom = swvlwtdvfa,
  .queue_ram = cuwynafphn,

  .column_elements_flags =vaztmuaqbx,
  .column_elements_ROM = gufcjkdztr,

  .watch_dog_struct = kynzshzjuo,
  .watch_dog_count  = doktfvjnho,
   
   
  .column_flags = sgkvqsvsaf,
  .column_local_data = sypvbvfbur,
  .column_state = kxjbrjbtnq,
  .number_of_columns = 2,
  .column_rom_data = jtcrcsjycw,

  
  
  
  .time_control = &hrnkmtiloi,
  .engine_control =&inwckxqopy,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &sfrwoszxwy,
  .current_heap_location = &ardljkejhc,
  .private_heap   = &slxjeqfqcu,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  rfzqxovuhb,
  .sm_ram     = ewfyehbfkg,
  .number_of_bitmaps = 0,
  .bitmaps = bvmwqamtyp,
  .number_of_registermaps = 0,
  .registermaps = gmszwxmwcz,
  .number_of_floatmaps = 0,
  .floatmaps = svawjpznst,
} ;

const Handle_CFL_t*  tod_handle(){
    return &fxisxqdcsl;
}
   

#ifdef __cplusplus
}
#endif

#endif
