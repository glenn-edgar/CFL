#ifndef __named_queues_H__
#define __named_queues_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"
#include "CFL_rpc_packets.h"

//nuser defined events 



 #define column_event_1 100 


 #define column_event_4 103 


 #define column_event_3 102 


 #define column_event_2 101 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t arovmyccwz[9];
static Event_data_CFL_t nhftfyelwf[7];
static Event_data_CFL_t qvpvbdylsw[0];
static Event_data_CFL_t zcnrzhttkh[0];
static Event_data_CFL_t jwmhkvznrc[0];
static Event_data_CFL_t gecdsxoqwn[0];
static Event_data_CFL_t jbpkgnralp[0];
static Event_data_CFL_t olfxdzrfoe[4];
static Event_data_CFL_t hvsaugxgaj[0];
static Event_data_CFL_t hmdremcpkr[2];
static Event_data_CFL_t wmrfdbezhz[0];
static Event_data_CFL_t eshijnukxc[2];
static Event_data_CFL_t sttnzfbvhs[0];
static Event_data_CFL_t uipdrkgiwa[0];
static Event_data_CFL_t tholbvbdqs[0];
static Event_data_CFL_t jrxxxfermz[8];
static Event_data_CFL_t xojpoustjp[4];
static Event_data_CFL_t rzfiyclyci[8];
static Event_data_CFL_t bdwdsecapm[4];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t naynlatjsd[] = { 
     {  7, nhftfyelwf, 0, qvpvbdylsw},
     {  0, zcnrzhttkh, 0, jwmhkvznrc},
     {  0, gecdsxoqwn, 0, jbpkgnralp},
     {  4, olfxdzrfoe, 0, hvsaugxgaj},
     {  2, hmdremcpkr, 0, wmrfdbezhz},
     {  2, eshijnukxc, 0, sttnzfbvhs},
     {  0, uipdrkgiwa, 0, tholbvbdqs},
     {  8, jrxxxfermz, 4, xojpoustjp},
     {  8, rzfiyclyci, 4, bdwdsecapm},
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t hhcaxmroek[0];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  paotmyjdns[] = { 
};
const Event_data_CFL_t kctfudrnws = { column_event_1, false, NULL };
const Event_data_CFL_t tujxnmubit = { column_event_2, false, NULL };
const Event_data_CFL_t rsujpzahtq = { column_event_3, false, NULL };
const Event_data_CFL_t kobxibldvz = { column_event_4, false, NULL };


unsigned  dwuxqzuhdq;
const While_time_control_ROM_CFL_t sttibddcvn = { 12000,&dwuxqzuhdq };



static While_control_RAM_CFL_t sfjqenwvnt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hwrpfvhwrj_rom = { 0 ,true, (void*)&sttibddcvn,&sfjqenwvnt_ram,null_function};

    
static const Log_message_CFL_t rqshzpelol = { "event generator start", false, NULL };


unsigned  wptbpudqba;
const While_time_control_ROM_CFL_t ddslwnrkrr = { 2000,&wptbpudqba };



static While_control_RAM_CFL_t dhmvtbrccz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mxcecmokdi_rom = { 0 ,true, (void*)&ddslwnrkrr,&dhmvtbrccz_ram,null_function};

    
static const Log_message_CFL_t izyvlhbkpe = { "sending events", false, NULL };
const Queue_event_CFL_t vfvbdrghiz = { 3, &rsujpzahtq };
const Queue_event_CFL_t lsayjoxaie = { 3, &kobxibldvz };
const Queue_event_CFL_t zrzldvdkqq = { 3, &kctfudrnws };
const Queue_event_CFL_t hrixjvrluf = { 3, &tujxnmubit };
const Queue_event_CFL_t sdmbkpyvkn = { 6, &tujxnmubit };
static const Log_message_CFL_t hmmqvjmemy = { "done sending events", false, NULL };
static const Log_message_CFL_t cmqyituwmp = { "event distributor start", false, NULL };
static unsigned short ttzjeudcyb[] = { 4};
static const Conditional_send_event_CFL_t iwuoqyzapf = { 1, ttzjeudcyb};
static unsigned short wrmklmrxsj[] = { 5};
static const Conditional_send_event_CFL_t xzzkmbvsrw = { 1, wrmklmrxsj};
static const Log_message_CFL_t ltwubvaljv = { "event_client_1", false, NULL };
static unsigned short xdrmxjxpgn[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t ljcobjycxh = { 4, xdrmxjxpgn};
static const Log_message_CFL_t vewzwabzda = { "event_client_2", false, NULL };
static unsigned short yfwqwtcpfb[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t nekqbusqjw = { 4, yfwqwtcpfb};
static const Log_message_CFL_t xwftjebqav = { "idle column", false, NULL };
static unsigned short zxfoazfokf[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t sqgyulphkx = { 4, zxfoazfokf};
static const Log_message_CFL_t vibiuqfhdd = { "push front event", false, NULL };
static unsigned short hmozevcpfp[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t leoegrtcps = { 4, hmozevcpfp};
static const Front_queue_event_CFL_t iffjfosoub = { 6, &kctfudrnws };
static const Front_queue_event_CFL_t gckmldcbtg = { 6, &tujxnmubit };
static const Front_queue_event_CFL_t tmfnanajts = { 6, &rsujpzahtq };
static const Front_queue_event_CFL_t nhmwcmnnfe = { 6, &kobxibldvz };
  static const char display_message[] = "display_message";
static const Log_message_CFL_t kdsqyvulso = { "dump residual events", false, NULL };
static const Residual_column_event_CFL_t rfyzajdxzk = { 7, (void *)(void *)display_message };
static const Front_queue_event_CFL_t bzvmfyalbk = { 7, &kctfudrnws };
static const Front_queue_event_CFL_t ydpsvxzaqw = { 7, &tujxnmubit };
static const Front_queue_event_CFL_t ahphoowgvc = { 7, &rsujpzahtq };
static const Front_queue_event_CFL_t eshundldvs = { 7, &kobxibldvz };


//----------RAM data structures for columns ----

unsigned qmyfmbymzq[8];
Watch_dog_struct_CFL_t * cqhpmfvtll[8];
unsigned char qffnestunw[8];
unsigned char cknzfoxuki[8];
void* hiunyorejl[8];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t fktmfglizr[] = {
  { 1,true, 0, 2, 0, -1, -1,NULL },
  { 2,true, 1, 10, 2, -1, -1,NULL },
  { 3,true, 2, 4, 12, -1, -1,NULL },
  { 4,true, 3, 3, 16, -1, -1,NULL },
  { 5,true, 4, 3, 19, -1, -1,NULL },
  { 6,false, 5, 3, 22, -1, -1,NULL },
  { 7,true, 6, 7, 25, -1, -1,NULL },
  { 8,true, 7, 7, 32, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char mthitanflw[39];


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

static const Column_element_CFL_t zdzvruvuqy[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hwrpfvhwrj_rom}, // 0 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rqshzpelol}, // 2 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mxcecmokdi_rom}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&izyvlhbkpe}, // 4 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&vfvbdrghiz}, // 5 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&lsayjoxaie}, // 6 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&zrzldvdkqq}, // 7 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&hrixjvrluf}, // 8 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&sdmbkpyvkn}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hmmqvjmemy}, // 10 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&cmqyituwmp}, // 12 
    {conditional_send_CFL,routing_1,(void *)&iwuoqyzapf}, // 13 
    {conditional_send_CFL,routing_2,(void *)&xzzkmbvsrw}, // 14 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 15 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ltwubvaljv}, // 16 
    {display_event_CFL,NULL,(void *)&ljcobjycxh}, // 17 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 18 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&vewzwabzda}, // 19 
    {display_event_CFL,NULL,(void *)&nekqbusqjw}, // 20 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 21 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xwftjebqav}, // 22 
    {display_event_CFL,NULL,(void *)&sqgyulphkx}, // 23 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 24 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&vibiuqfhdd}, // 25 
    {display_event_CFL,NULL,(void *)&leoegrtcps}, // 26 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&iffjfosoub}, // 27 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&gckmldcbtg}, // 28 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&tmfnanajts}, // 29 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&nhmwcmnnfe}, // 30 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 31 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&kdsqyvulso}, // 32 
    {process_residual_column_event_queue,residual_display,(void *)&rfyzajdxzk}, // 33 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&bzvmfyalbk}, // 34 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&ydpsvxzaqw}, // 35 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&ahphoowgvc}, // 36 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&eshundldvs}, // 37 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 38 
};
Bitmap_CFL fxgnfxfnmg[0];
Registermap_CFL_t dxcqehscnp[0];
Floatmap_CFL_t uthxgbvtpz[0];
const Sm_control_ROM_CFL_t upbbwrzhuh[0];
Sm_control_RAM_CFL_t dtzdytzhij[0];


static Time_control_CFL_t ollotghgiu;




static Engine_control_CFL_t ecqhibchqv;


/* remaining allocate heap size */

static unsigned ryboumjgmr;


/* current heap pointer */

static char* kxkuccpkic;


/* heap block area */

static CS_MEMORY_CONTROL weqkznogbn;


    
    


const struct Handle_CFL_t jhgbrlrsur =
{

  .queue_number = 9,
  .queue_rom = naynlatjsd,
  .queue_ram = arovmyccwz,

  .column_elements_flags =mthitanflw,
  .column_elements_ROM = zdzvruvuqy,

  .watch_dog_struct = cqhpmfvtll,
  .watch_dog_count  = qmyfmbymzq,
   
   
  .column_flags = qffnestunw,
  .column_local_data = hiunyorejl,
  .column_state = cknzfoxuki,
  .number_of_columns = 8,
  .column_rom_data = fktmfglizr,

  
  
  
  .time_control = &ollotghgiu,
  .engine_control =&ecqhibchqv,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &ryboumjgmr,
  .current_heap_location = &kxkuccpkic,
  .private_heap   = &weqkznogbn,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  upbbwrzhuh,
  .sm_ram     = dtzdytzhij,
  .number_of_bitmaps = 0,
  .bitmaps = fxgnfxfnmg,
  .number_of_registermaps = 0,
  .registermaps = dxcqehscnp,
  .number_of_floatmaps = 0,
  .floatmaps = uthxgbvtpz,
   .rpc_queue_number = 0,
  .rpc_queue_ram = hhcaxmroek,
  .rpc_queue_rom = paotmyjdns
} ;

const Handle_CFL_t*  column_queue_handle(){
    return &jhgbrlrsur;
}
   

#ifdef __cplusplus
}
#endif

#endif
