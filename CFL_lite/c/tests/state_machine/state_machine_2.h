#ifndef __state_machine_2_H__
#define __state_machine_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t rtycreiiij[8];
static Event_data_CFL_t zdhxtdxxjj[7];
static Event_data_CFL_t ugpxorqsfy[0];
static Event_data_CFL_t ratzbvyvan[0];
static Event_data_CFL_t cyiuilcxue[8];
static Event_data_CFL_t lnssyvqfwr[0];
static Event_data_CFL_t zwoixbhxzt[0];
static Event_data_CFL_t evbmcdeqqb[0];
static Event_data_CFL_t sdqqpbosai[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t kvvltxajtj[] = { 
     {  7, zdhxtdxxjj },
     {  0, ugpxorqsfy },
     {  0, ratzbvyvan },
     {  8, cyiuilcxue },
     {  0, lnssyvqfwr },
     {  0, zwoixbhxzt },
     {  0, evbmcdeqqb },
     {  0, sdqqpbosai },
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t atvztbrctj[0];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  wezfzuahkt[] = { 
};
const char test_data_2[] = "test_data\n";
const Event_data_CFL_t wtzsupjznb = { 101, false, NULL };
const Event_data_CFL_t kbopvswvvx = { 102, false, NULL };
const Event_data_CFL_t egewfsbzzf = { 103, false, NULL };
const Event_data_CFL_t tjunaeqifk = { 104, false, NULL };
const Event_data_CFL_t fdffkuzbym = { 111, false, NULL };
const Event_data_CFL_t nyznkosrje = { 112, false, NULL };
const Event_data_CFL_t vkiyxnzihs = { 113, false, NULL };
const Event_data_CFL_t idaweoqdci = { 114, false, NULL };

const char test_data_11[] = "state 1 debug message";
const char test_data_21[] = "state 2 debug message";
const char test_data_31[] = "state 3 debug message";
const char test_data_41[] = "state 4 debug message";



const Feed_events_test_data_t feed_test_data = {
    .debug_message = "feed event 2 debug message"
};

static const Log_message_CFL_t jooukvwbml = { "start column", false, NULL };

const unsigned short  qatydquaux[] = {0};

enable_disable_sm_CFL_t vjtrcaqgog = {1,qatydquaux };
static const unsigned short tgevbjxiko[] = { 1};
const Enable_column_CFL_t unwiyydylf = { true, 1, tgevbjxiko };


unsigned  lhzmsjdejk;
const While_time_control_ROM_CFL_t cbotskdzrf = { 24000,&lhzmsjdejk };



static While_control_RAM_CFL_t jimopdouec_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kiynxcbjfz_rom = { 0 ,true, (void*)&cbotskdzrf,&jimopdouec_ram,null_function};

    
static const Log_message_CFL_t gzjfexnboq = { "terminating", false, NULL };
static const Log_message_CFL_t eycgmbwspj = { "event generator start", false, NULL };


unsigned  pudwzmcbyh;
const While_time_control_ROM_CFL_t vriycddjyg = { 2000,&pudwzmcbyh };



static While_control_RAM_CFL_t thnnhvzynj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vdyyuoulpe_rom = { 0 ,true, (void*)&vriycddjyg,&thnnhvzynj_ram,null_function};

    
const sm_event_CFL_t iczqzcmshs = {0,&fdffkuzbym};
const sm_event_CFL_t kjendzvrfd = {0,&nyznkosrje};
const sm_event_CFL_t cpnmkzmsnw = {0,&vkiyxnzihs};
const sm_event_CFL_t bdlfzmhviv = {0,&idaweoqdci};
const sm_event_CFL_t dvxgrxltyo = {0,&wtzsupjznb};


unsigned  zpdgotynfs;
const While_time_control_ROM_CFL_t chnqozxobz = { 2000,&zpdgotynfs };



static While_control_RAM_CFL_t vifwwkwyoa_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xzrbirtxvo_rom = { 0 ,true, (void*)&chnqozxobz,&vifwwkwyoa_ram,null_function};

    
const sm_event_CFL_t hxtifbzoic = {0,&fdffkuzbym};
const sm_event_CFL_t tlvvcoqxio = {0,&nyznkosrje};
const sm_event_CFL_t kwidngtpyx = {0,&vkiyxnzihs};
const sm_event_CFL_t qijhphkvfc = {0,&idaweoqdci};
const sm_event_CFL_t roiylwtbuu = {0,&kbopvswvvx};


unsigned  ufoipyxcgx;
const While_time_control_ROM_CFL_t jlodzdnnfl = { 2000,&ufoipyxcgx };



static While_control_RAM_CFL_t pnmccxhqhf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t noqynbuxgf_rom = { 0 ,true, (void*)&jlodzdnnfl,&pnmccxhqhf_ram,null_function};

    
const sm_event_CFL_t wubyfmglgx = {0,&fdffkuzbym};
const sm_event_CFL_t nbccnyhnjh = {0,&nyznkosrje};
const sm_event_CFL_t ynqljkfntn = {0,&vkiyxnzihs};
const sm_event_CFL_t pkzkeexohj = {0,&idaweoqdci};
const sm_event_CFL_t xkzcxibeku = {0,&egewfsbzzf};
const sm_event_CFL_t jmfrlfgqqx = {0,&fdffkuzbym};
const sm_event_CFL_t klkydrccuu = {0,&nyznkosrje};


unsigned  eyvjzlonzj;
const While_time_control_ROM_CFL_t eymbbqiwep = { 2000,&eyvjzlonzj };



static While_control_RAM_CFL_t cbgivfvoka_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t khaeziwymg_rom = { 0 ,true, (void*)&eymbbqiwep,&cbgivfvoka_ram,null_function};

    
const sm_event_CFL_t xharpqueos = {0,&fdffkuzbym};
const sm_event_CFL_t xswqmbllyz = {0,&nyznkosrje};
const sm_event_CFL_t qpgoewotdh = {0,&vkiyxnzihs};
const sm_event_CFL_t pgdyiyqqle = {0,&idaweoqdci};
const sm_event_CFL_t mumvjdszep = {0,&tjunaeqifk};
const sm_event_CFL_t soaxffwtvs = {0,&fdffkuzbym};
const sm_event_CFL_t jpzhrpspsn = {0,&nyznkosrje};
static const Log_message_CFL_t ldvxhjfend = { "state machine manager starting", false, NULL };
const ASM_change_state_machine_CFL_t scxcixksav = {0,3 };
const unsigned short vvvqdohyeh[] = {101};
const state_change_CFL_t nhcgjzuact = {0,0,1,vvvqdohyeh};
const unsigned short tqvharmfvc[] = {102};
const state_change_CFL_t xxiubjjjwk = {0,1,1,tqvharmfvc};
const unsigned short ohbqevopwz[] = {103};
const state_change_CFL_t lixaxpkqpd = {0,2,1,ohbqevopwz};
const unsigned short fbcnjwfsye[] = {104};
const state_change_CFL_t cjzmcqqgei = {0,3,1,fbcnjwfsye};
const SM_feed_state_CFL_t semefbztyb = {0, (void *)&feed_test_data };
const SM_log_CFL_t pongdjitak = {0, 1, "state 1 starting","state_1 is exiting"};
const SM_debug_CFL_t vipndcajyv = {0,1,test_data_11};
static const Log_message_CFL_t wikhazlwxi = { "state 2 starting", false, NULL };
const SM_debug_CFL_t ohibpojavo = {0,2,test_data_21};
static const Log_message_CFL_t cqidwdqzai = { "state 3 starting", false, NULL };
const SM_debug_CFL_t tlochkzunl = {0,3,test_data_31};
static const Log_message_CFL_t xnqlzpkeeg = { "state 4 starting", false, NULL };
const sm_sync_events_t duqpkfzjhs = {3,120};
const SM_debug_CFL_t esdwjicbjb = {0,4,test_data_41};


//----------RAM data structures for columns ----

unsigned iamvpaeukw[7];
Watch_dog_struct_CFL_t * duewevxkil[7];
unsigned char wpadjlddqc[7];
unsigned char decwmytqiq[7];
void* qpwjprdvdn[7];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t wlzxjrdtqh[] = {
  { 1,true, 0, 6, 0, -1, -1,NULL },
  { 2,false, 1, 30, 6, -1, -1,NULL },
  { 3,false, 2, 8, 36, -1, -1,NULL },
  { 4,false, 3, 3, 44, -1, -1,NULL },
  { 5,false, 4, 3, 47, -1, -1,NULL },
  { 6,false, 5, 3, 50, -1, -1,NULL },
  { 7,false, 6, 4, 53, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char jerooxhtxz[57];


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

static const Column_element_CFL_t jfqxsllaor[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&jooukvwbml}, // 0 
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&vjtrcaqgog}, // 1 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&unwiyydylf}, // 2 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kiynxcbjfz_rom}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&gzjfexnboq}, // 4 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&eycgmbwspj}, // 6 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vdyyuoulpe_rom}, // 7 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&iczqzcmshs}, // 8 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kjendzvrfd}, // 9 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cpnmkzmsnw}, // 10 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bdlfzmhviv}, // 11 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&dvxgrxltyo}, // 12 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xzrbirtxvo_rom}, // 13 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hxtifbzoic}, // 14 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tlvvcoqxio}, // 15 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kwidngtpyx}, // 16 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qijhphkvfc}, // 17 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&roiylwtbuu}, // 18 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&noqynbuxgf_rom}, // 19 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&wubyfmglgx}, // 20 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nbccnyhnjh}, // 21 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ynqljkfntn}, // 22 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pkzkeexohj}, // 23 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xkzcxibeku}, // 24 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jmfrlfgqqx}, // 25 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&klkydrccuu}, // 26 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&khaeziwymg_rom}, // 27 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xharpqueos}, // 28 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xswqmbllyz}, // 29 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qpgoewotdh}, // 30 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pgdyiyqqle}, // 31 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mumvjdszep}, // 32 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&soaxffwtvs}, // 33 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jpzhrpspsn}, // 34 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 35 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ldvxhjfend}, // 36 
    {one_shot_handler_CFL,Asm_change_state_machine_CFL,(void *)&scxcixksav}, // 37 
    {state_change_CFL,NULL,(void *)&nhcgjzuact}, // 38 
    {state_change_CFL,NULL,(void *)&xxiubjjjwk}, // 39 
    {state_change_CFL,NULL,(void *)&lixaxpkqpd}, // 40 
    {state_change_CFL,NULL,(void *)&cjzmcqqgei}, // 41 
    {sm_feed_state_CFL,feed_events_test,(void *)&semefbztyb}, // 42 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 43 
    {bidirectional_one_shot_handler_CFL,SM_log_function_CFL,(void *)&pongdjitak}, // 44 
    {SM_debug_CFL,NULL,(void *)&vipndcajyv}, // 45 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 46 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&wikhazlwxi}, // 47 
    {SM_debug_CFL,NULL,(void *)&ohibpojavo}, // 48 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 49 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&cqidwdqzai}, // 50 
    {SM_debug_CFL,NULL,(void *)&tlochkzunl}, // 51 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 52 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xnqlzpkeeg}, // 53 
    {sm_sync_events_CFL,NULL,(void *)&duqpkfzjhs}, // 54 
    {SM_debug_CFL,NULL,(void *)&esdwjicbjb}, // 55 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 56 
};
Bitmap_CFL uwvnwgadgm[0];
Registermap_CFL_t rdrqdaatni[0];
Floatmap_CFL_t eiyqgyxwil[0];
const uint32_t sflwalshsv[] = {3918956230,3902178611,3885400992,4002844325};
const uint16_t mjokkavbka[] = {3,4,5,6};
const Sm_control_ROM_CFL_t btalfirolp[1] = {
{0,1468586590,2,4,sflwalshsv,mjokkavbka,(void *)&feed_test_data},
}; 
Sm_control_RAM_CFL_t ywhnolwplr[1];


static Time_control_CFL_t ofrgboittj;




static Engine_control_CFL_t sidhissnyh;


/* remaining allocate heap size */

static unsigned sqspennvhx;


/* current heap pointer */

static char* aicjscynwh;


/* heap block area */

static CS_MEMORY_CONTROL tclwugdpvt;


    
    


const struct Handle_CFL_t fsksvbrmuy =
{

  .queue_number = 8,
  .queue_rom = kvvltxajtj,
  .queue_ram = rtycreiiij,

  .column_elements_flags =jerooxhtxz,
  .column_elements_ROM = jfqxsllaor,

  .watch_dog_struct = duewevxkil,
  .watch_dog_count  = iamvpaeukw,
   
   
  .column_flags = wpadjlddqc,
  .column_local_data = qpwjprdvdn,
  .column_state = decwmytqiq,
  .number_of_columns = 7,
  .column_rom_data = wlzxjrdtqh,

  
  
  
  .time_control = &ofrgboittj,
  .engine_control =&sidhissnyh,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &sqspennvhx,
  .current_heap_location = &aicjscynwh,
  .private_heap   = &tclwugdpvt,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
  .sm_rom     =  btalfirolp,
  .sm_ram     = ywhnolwplr,
  .number_of_bitmaps = 0,
  .bitmaps = uwvnwgadgm,
  .number_of_registermaps = 0,
  .registermaps = rdrqdaatni,
  .number_of_floatmaps = 0,
  .floatmaps = eiyqgyxwil,
   .rpc_queue_number = 0,
  .rpc_queue_ram = atvztbrctj,
  .rpc_queue_rom = wezfzuahkt
} ;

const Handle_CFL_t*  state_machine_2_handle(){
    return &fsksvbrmuy;
}
   

#ifdef __cplusplus
}
#endif

#endif
