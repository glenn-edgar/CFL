#ifndef __rpc_services_1_H__
#define __rpc_services_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"
#include "CFL_rpc_packets.h"

//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t fkmfpattni[5];
static Event_data_CFL_t rsyhtlkidz[7];
static Event_data_CFL_t bamgjbtvhc[0];
static Event_data_CFL_t ghclewhaiw[0];
static Event_data_CFL_t tzgkxuasxl[0];
static Event_data_CFL_t vpoucbpliq[6];
static Event_data_CFL_t uyuzoywxvz[2];
static Event_data_CFL_t ttejvohujc[0];
static Event_data_CFL_t xozxvxaesv[0];
static Event_data_CFL_t lyzbgmsigj[0];
static Event_data_CFL_t lryfywegnv[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t xsjvsuaslj[] = { 
     {  7, rsyhtlkidz, 0, bamgjbtvhc},
     {  0, ghclewhaiw, 0, tzgkxuasxl},
     {  6, vpoucbpliq, 2, uyuzoywxvz},
     {  0, ttejvohujc, 0, xozxvxaesv},
     {  0, lyzbgmsigj, 0, lryfywegnv},
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t gassrgwmtq[1];
static Rpc_data_CFL_t   nvoyevqqwj[4];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  ysayvonsza[] = { 
     {  4, nvoyevqqwj },
};

const char time_out_data[] ="Time out for RPC CLIENT TIME OUT";


const char server_time_out_data[] ="Time out for RPC SERVER TIME OUT";

static const Log_message_CFL_t ilrscxhres = { "starting test_duration", false, NULL };


unsigned  nwblkqwccc;
const While_time_control_ROM_CFL_t slchcatkxe = { 20000,&nwblkqwccc };



static While_control_RAM_CFL_t bimauwnsii_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qxxyvcojuq_rom = { 0 ,true, (void*)&slchcatkxe,&bimauwnsii_ram,null_function};

    
static const Log_message_CFL_t fjibbdyzjm = { "ending test_duration", false, NULL };
static const Log_message_CFL_t rimrizlpsi = { "rpc_server starting", false, NULL };
bool zvuzwhlfyr = false;
const Release_rpc_event_CFL_t lrlbwmfxcx = { &zvuzwhlfyr, 0};
int32_t czwuxhyygf = 0;
uint16_t uhvhtuahvk = 0;
const uint16_t hlsecamntl[] = { 1,2,3,4 };
const Process_rpc_CFL_t anczwfeods = { &czwuxhyygf, &uhvhtuahvk, 0, 4, hlsecamntl, 3, 3500, false, (void *)server_time_out_data};
const Free_rpc_event_CFL_t rbszozyfme = { 0};
static const Log_message_CFL_t yrcyqlaajf = { "starting rpc_client", false, NULL };
int32_t laffhpufgc = 0;
Rpc_transfer_data_packet_CFL_t mgcarcrhvi ;
Rpc_transfer_data_packet_CFL_t arurlbqimn ;
const Rpc_client_CFL_t utjhrdsmrh = { 0, 2,1, &mgcarcrhvi,client_data_load_code,NULL ,&arurlbqimn, client_data_verify_code, NULL, &laffhpufgc ,3000, true, time_out_data_function, (void *)time_out_data };


unsigned  snhhzddvyr;
const While_time_control_ROM_CFL_t qkmteipejq = { 1000,&snhhzddvyr };



static While_control_RAM_CFL_t nmbgweuwpo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tseqhsbuet_rom = { 0 ,true, (void*)&qkmteipejq,&nmbgweuwpo_ram,null_function};

    
int32_t aoubvighna = 0;
Rpc_transfer_data_packet_CFL_t hgwormyrwg ;
Rpc_transfer_data_packet_CFL_t ngexyslqqp ;
const Rpc_client_CFL_t lvkwagxmbw = { 0, 2,4, &hgwormyrwg,client_data_load_code,NULL ,&ngexyslqqp, client_data_verify_code, NULL, &aoubvighna ,3000, true, time_out_data_function, (void *)time_out_data };
int32_t ooxigfwttv = 0;
Rpc_transfer_data_packet_CFL_t kcxuhetjuz ;
Rpc_transfer_data_packet_CFL_t acewuiubpp ;
const Rpc_client_CFL_t fvpvcensad = { 0, 2,5, &kcxuhetjuz,client_data_load_code,NULL ,&acewuiubpp, client_data_verify_code, NULL, &ooxigfwttv ,3000, true, time_out_data_function, (void *)time_out_data };
static const Log_message_CFL_t aerwfjblpk = { "ending rpc_client", false, NULL };
static const Log_message_CFL_t jjftwrwzjj = { "rpc_worker_column starting", true, "rpc_worker_column ending" };


unsigned  lhtaajwxve;
const While_time_control_ROM_CFL_t yxbdhklvre = { 2000,&lhtaajwxve };



static While_control_RAM_CFL_t fbdvdcavlo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dhcxybopqs_rom = { 0 ,true, (void*)&yxbdhklvre,&fbdvdcavlo_ram,null_function};

    


//----------RAM data structures for columns ----

unsigned ubciwlbbtc[4];
Watch_dog_struct_CFL_t * gabthonzxm[4];
unsigned char qvvrpwmzjz[4];
unsigned char sflpxakjtk[4];
void* bdowilpejb[4];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t ptheapjyfr[] = {
  { 1,true, 0, 4, 0, -1, -1,NULL },
  { 2,true, 1, 5, 4, -1, -1,NULL },
  { 3,true, 2, 7, 9, -1, -1,NULL },
  { 4,false, 3, 5, 16, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char fjhjgrvmvq[21];


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

static const Column_element_CFL_t mjxlaxjlbp[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ilrscxhres}, // 0 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qxxyvcojuq_rom}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&fjibbdyzjm}, // 2 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rimrizlpsi}, // 4 
    {release_rpc_request_CFL,NULL,(void *)&lrlbwmfxcx}, // 5 
    {process_rpc_event_CFL,server_time_out_data_function,(void *)&anczwfeods}, // 6 
    {free_rpc_event_CFL,NULL,(void *)&rbszozyfme}, // 7 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 8 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&yrcyqlaajf}, // 9 
    {rpc_client_CFL,NULL,(void *)&utjhrdsmrh}, // 10 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tseqhsbuet_rom}, // 11 
    {rpc_client_CFL,NULL,(void *)&lvkwagxmbw}, // 12 
    {rpc_client_CFL,NULL,(void *)&fvpvcensad}, // 13 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&aerwfjblpk}, // 14 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 15 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&jjftwrwzjj}, // 16 
    {one_shot_handler_CFL,worker_first_action_code,NULL}, // 17 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dhcxybopqs_rom}, // 18 
    {one_shot_handler_CFL,worker_second_action_code,NULL}, // 19 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 20 
};
Bitmap_CFL hvswylkigw[0];
Registermap_CFL_t rcqszpfpaf[0];
Floatmap_CFL_t drsexmtwis[0];
const Sm_control_ROM_CFL_t tdgqomkzlw[0];
Sm_control_RAM_CFL_t kvuxshjpfz[0];


static Time_control_CFL_t gwlvbkxvsp;




static Engine_control_CFL_t nmhkrjkfgo;


/* remaining allocate heap size */

static unsigned wgajmlhcsl;


/* current heap pointer */

static char* aoafxwxbik;


/* heap block area */

static CS_MEMORY_CONTROL fgdczjkyuc;


    
    


const struct Handle_CFL_t bbjvxdxddy =
{

  .queue_number = 5,
  .queue_rom = xsjvsuaslj,
  .queue_ram = fkmfpattni,

  .column_elements_flags =fjhjgrvmvq,
  .column_elements_ROM = mjxlaxjlbp,

  .watch_dog_struct = gabthonzxm,
  .watch_dog_count  = ubciwlbbtc,
   
   
  .column_flags = qvvrpwmzjz,
  .column_local_data = bdowilpejb,
  .column_state = sflpxakjtk,
  .number_of_columns = 4,
  .column_rom_data = ptheapjyfr,

  
  
  
  .time_control = &gwlvbkxvsp,
  .engine_control =&nmhkrjkfgo,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &wgajmlhcsl,
  .current_heap_location = &aoafxwxbik,
  .private_heap   = &fgdczjkyuc,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  tdgqomkzlw,
  .sm_ram     = kvuxshjpfz,
  .number_of_bitmaps = 0,
  .bitmaps = hvswylkigw,
  .number_of_registermaps = 0,
  .registermaps = rcqszpfpaf,
  .number_of_floatmaps = 0,
  .floatmaps = drsexmtwis,
   .rpc_queue_number = 1,
  .rpc_queue_ram = gassrgwmtq,
  .rpc_queue_rom = ysayvonsza
} ;

const Handle_CFL_t*  rpc_services_handle_1(){
    return &bbjvxdxddy;
}
   

#ifdef __cplusplus
}
#endif

#endif
