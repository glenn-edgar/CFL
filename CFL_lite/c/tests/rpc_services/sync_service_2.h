#ifndef __sync_service_2_H__
#define __sync_service_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"
#include "CFL_rpc_packets.h"

//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t qtpzsbkmni[4];
static Event_data_CFL_t mlebzjogen[7];
static Event_data_CFL_t repsjdqjpt[0];
static Event_data_CFL_t eckuarlols[0];
static Event_data_CFL_t kmtwteqawd[0];
static Event_data_CFL_t naetmkqovh[6];
static Event_data_CFL_t dskqrynzhu[2];
static Event_data_CFL_t axuzvzotae[6];
static Event_data_CFL_t elcmnhpxcm[2];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t bzdyglfsil[] = { 
     {  7, mlebzjogen, 0, repsjdqjpt},
     {  0, eckuarlols, 0, kmtwteqawd},
     {  6, naetmkqovh, 2, dskqrynzhu},
     {  6, axuzvzotae, 2, elcmnhpxcm},
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t wpxfssnsap[2];
static Rpc_data_CFL_t   zslqtiksdr[4];
static Rpc_data_CFL_t   maeyrpdckc[4];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  atxceccydb[] = { 
     {  4, zslqtiksdr },
     {  4, maeyrpdckc },
};
static const Log_message_CFL_t mibwcusskq = { "starting test_duration", false, NULL };
const Reset_rpc_queue_CFL_t nczyxxxpzh = { 0};
const Reset_rpc_queue_CFL_t jzdkxdsliz = { 1};


unsigned  rrmvsqfnhj;
const While_time_control_ROM_CFL_t feoshbkcin = { 20000,&rrmvsqfnhj };



static While_control_RAM_CFL_t anbyxoqzwt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t eqzikcnddd_rom = { 0 ,true, (void*)&feoshbkcin,&anbyxoqzwt_ram,null_function};

    
static const Log_message_CFL_t uivzlujxxi = { "ending test_duration", false, NULL };
static const Log_message_CFL_t unwhpohhtn = { "starting column sync_element_1", false, NULL };


unsigned  pkhhpjlnag;
const While_time_control_ROM_CFL_t hhyblumkds = { 1000,&pkhhpjlnag };



static While_control_RAM_CFL_t yjrqrttqrm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wnnklafqsy_rom = { 0 ,true, (void*)&hhyblumkds,&yjrqrttqrm_ram,null_function};

    
static const Log_message_CFL_t ibmrvgbzjz = { "sync_element_1 server wait", false, NULL };
const Sync_rpc_CFL_t jqsdboqqed = { true, 0};
static const Log_message_CFL_t mrqqljrihg = { "sync_element_1 client wait", false, NULL };
int32_t loewwjjkjy = 0;
Rpc_transfer_data_packet_CFL_t ftybshvome ;
Rpc_transfer_data_packet_CFL_t lihuplabnl ;
const Rpc_client_CFL_t dsqhkvnago = { 1, 1,1, &ftybshvome,sync_data_load_CFL,NULL ,&lihuplabnl, sync_data_verify_CFL, NULL, &loewwjjkjy ,3000, true, time_out_data_function, (void *)time_out_data };
static const Log_message_CFL_t vylranpspa = { "starting column sync_element_2", false, NULL };
static const Log_message_CFL_t szawawlkpm = { "sync_element_2 client wait", false, NULL };
int32_t rleqmgyggi = 0;
Rpc_transfer_data_packet_CFL_t rorpuxjykf ;
Rpc_transfer_data_packet_CFL_t vqimtbwxwr ;
const Rpc_client_CFL_t mzvkotpzmb = { 0, 2,1, &rorpuxjykf,sync_data_load_CFL,NULL ,&vqimtbwxwr, sync_data_verify_CFL, NULL, &rleqmgyggi ,3000, true, time_out_data_function, (void *)time_out_data };


unsigned  ebnzsydjmw;
const While_time_control_ROM_CFL_t lsqeergtql = { 1000,&ebnzsydjmw };



static While_control_RAM_CFL_t vvlpddeutg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fvvnappxuu_rom = { 0 ,true, (void*)&lsqeergtql,&vvlpddeutg_ram,null_function};

    
static const Log_message_CFL_t dhyitzwlmm = { "sync_element_1 server wait", false, NULL };
const Sync_rpc_CFL_t cpfalzbaai = { true, 1};


//----------RAM data structures for columns ----

unsigned ouguxytxmp[3];
Watch_dog_struct_CFL_t * saoefnpitg[3];
unsigned char hitpayvvdz[3];
unsigned char bcrtvmauqn[3];
void* vskjdbinri[3];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t hacpyoymhi[] = {
  { 1,true, 0, 6, 0, -1, -1,NULL },
  { 2,true, 1, 7, 6, -1, -1,NULL },
  { 3,true, 2, 7, 13, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char ubpbgetstk[20];


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

static const Column_element_CFL_t qhmhydsgaa[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&mibwcusskq}, // 0 
    {one_shot_handler_CFL,ASM_reset_rpc_queue_CFL,(void *)&nczyxxxpzh}, // 1 
    {one_shot_handler_CFL,ASM_reset_rpc_queue_CFL,(void *)&jzdkxdsliz}, // 2 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&eqzikcnddd_rom}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&uivzlujxxi}, // 4 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&unwhpohhtn}, // 6 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wnnklafqsy_rom}, // 7 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ibmrvgbzjz}, // 8 
    {sync_rpc_event_CFL,sync_server_no_wait,(void *)&jqsdboqqed}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&mrqqljrihg}, // 10 
    {rpc_client_CFL,NULL,(void *)&dsqhkvnago}, // 11 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 12 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&vylranpspa}, // 13 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&szawawlkpm}, // 14 
    {rpc_client_CFL,NULL,(void *)&mzvkotpzmb}, // 15 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fvvnappxuu_rom}, // 16 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&dhyitzwlmm}, // 17 
    {sync_rpc_event_CFL,sync_server_no_wait,(void *)&cpfalzbaai}, // 18 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 19 
};
Bitmap_CFL itaqwanayp[0];
Registermap_CFL_t exqrgwpxca[0];
Floatmap_CFL_t plrovrysvk[0];
const Sm_control_ROM_CFL_t onnardhhvs[0];
Sm_control_RAM_CFL_t gkcezsjyfz[0];


static Time_control_CFL_t rphqmzmeaw;




static Engine_control_CFL_t yjmcfqpsbu;


/* remaining allocate heap size */

static unsigned niwduazhzm;


/* current heap pointer */

static char* sxrtqgpwml;


/* heap block area */

static CS_MEMORY_CONTROL ocdkhrnjsc;


    
    


const struct Handle_CFL_t mjkjxytqfn =
{

  .queue_number = 4,
  .queue_rom = bzdyglfsil,
  .queue_ram = qtpzsbkmni,

  .column_elements_flags =ubpbgetstk,
  .column_elements_ROM = qhmhydsgaa,

  .watch_dog_struct = saoefnpitg,
  .watch_dog_count  = ouguxytxmp,
   
   
  .column_flags = hitpayvvdz,
  .column_local_data = vskjdbinri,
  .column_state = bcrtvmauqn,
  .number_of_columns = 3,
  .column_rom_data = hacpyoymhi,

  
  
  
  .time_control = &rphqmzmeaw,
  .engine_control =&yjmcfqpsbu,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &niwduazhzm,
  .current_heap_location = &sxrtqgpwml,
  .private_heap   = &ocdkhrnjsc,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  onnardhhvs,
  .sm_ram     = gkcezsjyfz,
  .number_of_bitmaps = 0,
  .bitmaps = itaqwanayp,
  .number_of_registermaps = 0,
  .registermaps = exqrgwpxca,
  .number_of_floatmaps = 0,
  .floatmaps = plrovrysvk,
   .rpc_queue_number = 2,
  .rpc_queue_ram = wpxfssnsap,
  .rpc_queue_rom = atxceccydb
} ;

const Handle_CFL_t*  sync_service_2(){
    return &mjkjxytqfn;
}
   

#ifdef __cplusplus
}
#endif

#endif
