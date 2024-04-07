#ifndef __state_machine_1_H__
#define __state_machine_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t yhapnrjapa[7];
static Event_data_CFL_t pxfxcztijp[7];
static Event_data_CFL_t dvxazuhxwk[0];
static Event_data_CFL_t vjznqtlekm[0];
static Event_data_CFL_t vnlksvohjd[0];
static Event_data_CFL_t dprpmluiaf[0];
static Event_data_CFL_t ptegpcwhht[0];
static Event_data_CFL_t xlasbxnmzv[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ckujzbeglm[] = { 
     {  7, pxfxcztijp },
     {  0, dvxazuhxwk },
     {  0, vjznqtlekm },
     {  0, vnlksvohjd },
     {  0, dprpmluiaf },
     {  0, ptegpcwhht },
     {  0, xlasbxnmzv },
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t ewvmfiivvv[0];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  yrxoarfblr[] = { 
};
static const Log_message_CFL_t ielsenjjbu = { "start column", false, NULL };
const uint16_t  oceiqqcskm[] = {0};
const enable_sm_CFL_t wicacqpbzr = {1,oceiqqcskm };


unsigned  zxijpzgfcu;
const While_time_control_ROM_CFL_t fwpguwunre = { 20000,&zxijpzgfcu };



static While_control_RAM_CFL_t vkffufsxho_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t offqotywst_rom = { 0 ,true, (void*)&fwpguwunre,&vkffufsxho_ram,null_function};

    
static const Log_message_CFL_t ezgyzgjvab = { "disabling state machine", false, NULL };
const uint16_t  vjpssymnfn[] = {0};
const disable_sm_CFL_t arnkkxobzj = {1,vjpssymnfn };

const unsigned short  vmkwmaiymy[] = {0};

enable_disable_sm_CFL_t ppjbvdjnpx = {1,vmkwmaiymy };


unsigned  jpngvapqcq;
const While_time_control_ROM_CFL_t mfknkztowp = { 10000,&jpngvapqcq };



static While_control_RAM_CFL_t eurrhpyoxf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ebgipxztrg_rom = { 0 ,true, (void*)&mfknkztowp,&eurrhpyoxf_ram,null_function};

    
static const Log_message_CFL_t hjsoxpblrd = { "terminating", false, NULL };
const char test_data[] = "test_data\n";
static const Log_message_CFL_t rnvijgwhof = { "state machine manager starting", false, NULL };


unsigned  rsqlwkxgbz;
const While_time_control_ROM_CFL_t lmsdnxymcv = { 2000,&rsqlwkxgbz };



static While_control_RAM_CFL_t wjzfbvfyhb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vmvfmnyxgz_rom = { 0 ,true, (void*)&lmsdnxymcv,&wjzfbvfyhb_ram,null_function};

    
const ASM_change_state_machine_CFL_t fkyynbxjmj = {0,1 };


unsigned  pnmntpooon;
const While_time_control_ROM_CFL_t qzvzjhlwbb = { 2000,&pnmntpooon };



static While_control_RAM_CFL_t dtwycdvrer_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t btlpgdoaga_rom = { 0 ,true, (void*)&qzvzjhlwbb,&dtwycdvrer_ram,null_function};

    
static const Log_message_CFL_t rgttgrljra = { "manager column time out", false, NULL };
static const Log_message_CFL_t hdryejgmyq = { "state 1 starting", false, NULL };


unsigned  voemeajcjg;
const While_time_control_ROM_CFL_t phpfguzamg = { 2000,&voemeajcjg };



static While_control_RAM_CFL_t damnojwbyw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t maidwnxcid_rom = { 0 ,true, (void*)&phpfguzamg,&damnojwbyw_ram,null_function};

    
const ASM_change_state_machine_CFL_t qfwfabluop = {0,1 };
static const Log_message_CFL_t iywbrukvdu = { "this message should not be printed", false, NULL };
static const Log_message_CFL_t douszuayvs = { "state 2 starting", false, NULL };


unsigned  dtvknekziu;
const While_time_control_ROM_CFL_t mkiodjvfbt = { 2000,&dtvknekziu };



static While_control_RAM_CFL_t wledwfjlnc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jgjsjgscqk_rom = { 0 ,true, (void*)&mkiodjvfbt,&wledwfjlnc_ram,null_function};

    
const ASM_change_state_machine_CFL_t ejiqgkrfak = {0,2 };
static const Log_message_CFL_t ufshfhbumi = { "this message should not be printed", false, NULL };
static const Log_message_CFL_t ycjtkshwmc = { "state 3 starting", false, NULL };


unsigned  vpskenuhqq;
const While_time_control_ROM_CFL_t wcvmvatdjw = { 2000,&vpskenuhqq };



static While_control_RAM_CFL_t vjvxlpaodn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pcocvxtboe_rom = { 0 ,true, (void*)&wcvmvatdjw,&vjvxlpaodn_ram,null_function};

    
const ASM_change_state_machine_CFL_t ipxtjpjrtd = {0,3 };
static const Log_message_CFL_t kgkatldvek = { "this message should not be printed", false, NULL };
static const Log_message_CFL_t byllkamrxz = { "state 4 starting", false, NULL };


unsigned  akiudxlylv;
const While_time_control_ROM_CFL_t wnddvqpodf = { 2000,&akiudxlylv };



static While_control_RAM_CFL_t qiqhlxxtzl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t olbnyzaqbb_rom = { 0 ,true, (void*)&wnddvqpodf,&qiqhlxxtzl_ram,null_function};

    
const ASM_change_state_machine_CFL_t axdmoowwgy = {0,0 };
static const Log_message_CFL_t hcgdjcucff = { "this message should not be printed", false, NULL };


//----------RAM data structures for columns ----

unsigned dkadtjdwhn[6];
Watch_dog_struct_CFL_t * wpzuihupzz[6];
unsigned char gspugtdjsf[6];
unsigned char eiqfnzfwdo[6];
void* njhruzbmse[6];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t xygyalplkb[] = {
  { 1,true, 0, 9, 0, -1, -1,NULL },
  { 2,false, 1, 6, 9, -1, -1,NULL },
  { 3,false, 2, 5, 15, -1, -1,NULL },
  { 4,false, 3, 5, 20, -1, -1,NULL },
  { 5,false, 4, 5, 25, -1, -1,NULL },
  { 6,false, 5, 5, 30, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char navxifxcnw[35];


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

static const Column_element_CFL_t rduywmcqxt[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ielsenjjbu}, // 0 
    {one_shot_handler_CFL,enable_sm_CFL,(void *)&wicacqpbzr}, // 1 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&offqotywst_rom}, // 2 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ezgyzgjvab}, // 3 
    {one_shot_handler_CFL,disable_sm_CFL,(void *)&arnkkxobzj}, // 4 
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&ppjbvdjnpx}, // 5 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ebgipxztrg_rom}, // 6 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hjsoxpblrd}, // 7 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 8 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rnvijgwhof}, // 9 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vmvfmnyxgz_rom}, // 10 
    {one_shot_handler_CFL,Asm_change_state_machine_CFL,(void *)&fkyynbxjmj}, // 11 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&btlpgdoaga_rom}, // 12 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rgttgrljra}, // 13 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 14 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hdryejgmyq}, // 15 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&maidwnxcid_rom}, // 16 
    {one_shot_handler_CFL,Asm_change_state_machine_CFL,(void *)&qfwfabluop}, // 17 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&iywbrukvdu}, // 18 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 19 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&douszuayvs}, // 20 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jgjsjgscqk_rom}, // 21 
    {one_shot_handler_CFL,Asm_change_state_machine_CFL,(void *)&ejiqgkrfak}, // 22 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ufshfhbumi}, // 23 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 24 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ycjtkshwmc}, // 25 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pcocvxtboe_rom}, // 26 
    {one_shot_handler_CFL,Asm_change_state_machine_CFL,(void *)&ipxtjpjrtd}, // 27 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&kgkatldvek}, // 28 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 29 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&byllkamrxz}, // 30 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&olbnyzaqbb_rom}, // 31 
    {one_shot_handler_CFL,Asm_change_state_machine_CFL,(void *)&axdmoowwgy}, // 32 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hcgdjcucff}, // 33 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 34 
};
Bitmap_CFL nessvgjiee[0];
Registermap_CFL_t vtthqqzxjk[0];
Floatmap_CFL_t uoqacfplbw[0];
const uint32_t toiqdmouez[] = {1755618126,1738840507,1722062888,1839506221};
const uint16_t kukqmsmrcw[] = {2,3,4,5};
const Sm_control_ROM_CFL_t isdwknrbdj[1] = {
{0,1468586590,1,4,toiqdmouez,kukqmsmrcw,(void *)&test_data},
}; 
Sm_control_RAM_CFL_t wegcchclub[1];


static Time_control_CFL_t lvkylgyqec;




static Engine_control_CFL_t olunmzwtlx;


/* remaining allocate heap size */

static unsigned duzfmjiipu;


/* current heap pointer */

static char* twvauaggis;


/* heap block area */

static CS_MEMORY_CONTROL hbuwkchcqp;


    
    


const struct Handle_CFL_t vzwfxwmwdp =
{

  .queue_number = 7,
  .queue_rom = ckujzbeglm,
  .queue_ram = yhapnrjapa,

  .column_elements_flags =navxifxcnw,
  .column_elements_ROM = rduywmcqxt,

  .watch_dog_struct = wpzuihupzz,
  .watch_dog_count  = dkadtjdwhn,
   
   
  .column_flags = gspugtdjsf,
  .column_local_data = njhruzbmse,
  .column_state = eiqfnzfwdo,
  .number_of_columns = 6,
  .column_rom_data = xygyalplkb,

  
  
  
  .time_control = &lvkylgyqec,
  .engine_control =&olunmzwtlx,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &duzfmjiipu,
  .current_heap_location = &twvauaggis,
  .private_heap   = &hbuwkchcqp,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
  .sm_rom     =  isdwknrbdj,
  .sm_ram     = wegcchclub,
  .number_of_bitmaps = 0,
  .bitmaps = nessvgjiee,
  .number_of_registermaps = 0,
  .registermaps = vtthqqzxjk,
  .number_of_floatmaps = 0,
  .floatmaps = uoqacfplbw,
   .rpc_queue_number = 0,
  .rpc_queue_ram = ewvmfiivvv,
  .rpc_queue_rom = yrxoarfblr
} ;

const Handle_CFL_t*  state_machine_1_handle(){
    return &vzwfxwmwdp;
}
   

#ifdef __cplusplus
}
#endif

#endif
