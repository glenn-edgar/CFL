#ifndef __sync_service_1_H__
#define __sync_service_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"
#include "CFL_rpc_packets.h"

//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t alshaorbdb[5];
static Event_data_CFL_t hrvalzogef[7];
static Event_data_CFL_t ahymmrjvjz[0];
static Event_data_CFL_t useikneznz[0];
static Event_data_CFL_t nxhqjervlh[0];
static Event_data_CFL_t dxszyovugk[6];
static Event_data_CFL_t wxfqiamgnx[2];
static Event_data_CFL_t sjgtixwmwm[0];
static Event_data_CFL_t rtkimyhuog[0];
static Event_data_CFL_t cglrqlhqas[0];
static Event_data_CFL_t pnneurztkj[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ulqxaoduwk[] = { 
     {  7, hrvalzogef, 0, ahymmrjvjz},
     {  0, useikneznz, 0, nxhqjervlh},
     {  6, dxszyovugk, 2, wxfqiamgnx},
     {  0, sjgtixwmwm, 0, rtkimyhuog},
     {  0, cglrqlhqas, 0, pnneurztkj},
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t bgngpbvnjh[1];
static Rpc_data_CFL_t   rjonnsjjgv[4];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  fxwylgfwvy[] = { 
     {  4, rjonnsjjgv },
};
static const Log_message_CFL_t wuoscirkpv = { "starting test_duration", false, NULL };


unsigned  kpkurvoewu;
const While_time_control_ROM_CFL_t cebjnawlup = { 200000,&kpkurvoewu };



static While_control_RAM_CFL_t cszmfkdzpz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vhphowxxiu_rom = { 0 ,true, (void*)&cebjnawlup,&cszmfkdzpz_ram,null_function};

    
static const Log_message_CFL_t nduukwhnyj = { "ending test_duration", false, NULL };
static const Log_message_CFL_t otnwtefhne = { "rpc_sync_server_no_wait starting", false, NULL };
const Sync_rpc_CFL_t lxunikkufq = { false, 0};
static const Log_message_CFL_t nktplxveay = { "rpc_sync_server_no_wait starting", false, NULL };


unsigned  zkblybyjhi;
const While_time_control_ROM_CFL_t dhedikcjfm = { 1000,&zkblybyjhi };



static While_control_RAM_CFL_t ehwgylmdas_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t equgdtpfyv_rom = { 0 ,true, (void*)&dhedikcjfm,&ehwgylmdas_ram,null_function};

    
static const Log_message_CFL_t zxeodjdolm = { "rpc_sync_server_no_wait ending", false, NULL };
static const Log_message_CFL_t ozmiwbdxmb = { "starting rpc_client  1", false, NULL };


unsigned  urqhuqhjem;
const While_time_control_ROM_CFL_t lnvyhsaqhe = { 2000,&urqhuqhjem };



static While_control_RAM_CFL_t mmhhuogwxd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dxvpdlptas_rom = { 0 ,true, (void*)&lnvyhsaqhe,&mmhhuogwxd_ram,null_function};

    
static const Log_message_CFL_t hxhobiqard = { "rpc_client 1 request", false, NULL };
int32_t aqmpmawevw = 0;
Rpc_transfer_data_packet_CFL_t uypkbfumhy ;
Rpc_transfer_data_packet_CFL_t xqgzzvoony ;
const Rpc_client_CFL_t inxkaafmum = { 0, 2,1, &uypkbfumhy,sync_data_load_CFL,NULL ,&xqgzzvoony, sync_data_verify_CFL, NULL, &aqmpmawevw ,3000, true, time_out_data_function, (void *)time_out_data };
static const Log_message_CFL_t ytldtgcbez = { "starting rpc_client  2", false, NULL };


unsigned  yyzeretbbv;
const While_time_control_ROM_CFL_t hekimoghwc = { 3000,&yyzeretbbv };



static While_control_RAM_CFL_t isueuibrbq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ydxmubayce_rom = { 0 ,true, (void*)&hekimoghwc,&isueuibrbq_ram,null_function};

    
static const Log_message_CFL_t swpwjeicdj = { "rpc_client 1 request", false, NULL };
int32_t veavjfaugs = 0;
Rpc_transfer_data_packet_CFL_t rudvsnjwdj ;
Rpc_transfer_data_packet_CFL_t ltkzoyiaee ;
const Rpc_client_CFL_t qrbliokyhx = { 0, 3,1, &rudvsnjwdj,sync_data_load_CFL,NULL ,&ltkzoyiaee, sync_data_verify_CFL, NULL, &veavjfaugs ,3000, true, time_out_data_function, (void *)time_out_data };


//----------RAM data structures for columns ----

unsigned exjsdbaccm[4];
Watch_dog_struct_CFL_t * uzvjpvxwpm[4];
unsigned char ryqqelonqa[4];
unsigned char wsudfnhztp[4];
void* prlfonadyy[4];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t lvcluxejna[] = {
  { 1,true, 0, 4, 0, -1, -1,NULL },
  { 2,true, 1, 6, 4, -1, -1,NULL },
  { 3,true, 2, 5, 10, -1, -1,NULL },
  { 4,true, 3, 5, 15, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char kirkcfcqfe[20];


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

static const Column_element_CFL_t mdamitvyxb[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&wuoscirkpv}, // 0 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vhphowxxiu_rom}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&nduukwhnyj}, // 2 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&otnwtefhne}, // 4 
    {sync_rpc_event_CFL,sync_server_no_wait,(void *)&lxunikkufq}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&nktplxveay}, // 6 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&equgdtpfyv_rom}, // 7 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zxeodjdolm}, // 8 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ozmiwbdxmb}, // 10 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dxvpdlptas_rom}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hxhobiqard}, // 12 
    {rpc_client_CFL,NULL,(void *)&inxkaafmum}, // 13 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 14 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ytldtgcbez}, // 15 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ydxmubayce_rom}, // 16 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&swpwjeicdj}, // 17 
    {rpc_client_CFL,NULL,(void *)&qrbliokyhx}, // 18 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 19 
};
Bitmap_CFL pezwvxiruc[0];
Registermap_CFL_t tjbfubwbkx[0];
Floatmap_CFL_t ekjvieajol[0];
const Sm_control_ROM_CFL_t swzgsginps[0];
Sm_control_RAM_CFL_t vasxajbvtf[0];


static Time_control_CFL_t nzhjldbiyb;




static Engine_control_CFL_t rrwxdojqxq;


/* remaining allocate heap size */

static unsigned fkvhkzsdtf;


/* current heap pointer */

static char* xlpabdnqrh;


/* heap block area */

static CS_MEMORY_CONTROL vplwiocxfk;


    
    


const struct Handle_CFL_t dncfuvgkqk =
{

  .queue_number = 5,
  .queue_rom = ulqxaoduwk,
  .queue_ram = alshaorbdb,

  .column_elements_flags =kirkcfcqfe,
  .column_elements_ROM = mdamitvyxb,

  .watch_dog_struct = uzvjpvxwpm,
  .watch_dog_count  = exjsdbaccm,
   
   
  .column_flags = ryqqelonqa,
  .column_local_data = prlfonadyy,
  .column_state = wsudfnhztp,
  .number_of_columns = 4,
  .column_rom_data = lvcluxejna,

  
  
  
  .time_control = &nzhjldbiyb,
  .engine_control =&rrwxdojqxq,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &fkvhkzsdtf,
  .current_heap_location = &xlpabdnqrh,
  .private_heap   = &vplwiocxfk,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  swzgsginps,
  .sm_ram     = vasxajbvtf,
  .number_of_bitmaps = 0,
  .bitmaps = pezwvxiruc,
  .number_of_registermaps = 0,
  .registermaps = tjbfubwbkx,
  .number_of_floatmaps = 0,
  .floatmaps = ekjvieajol,
   .rpc_queue_number = 1,
  .rpc_queue_ram = bgngpbvnjh,
  .rpc_queue_rom = fxwylgfwvy
} ;

const Handle_CFL_t*  sync_service_1(){
    return &dncfuvgkqk;
}
   

#ifdef __cplusplus
}
#endif

#endif
