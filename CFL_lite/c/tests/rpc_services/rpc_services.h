#ifndef __rpc_services_H__
#define __rpc_services_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t htrisfkbjh[5];
static Event_data_CFL_t fnbqewhqyu[7];
static Event_data_CFL_t riuxgprnfj[0];
static Event_data_CFL_t ykcireobbt[0];
static Event_data_CFL_t vmsgckcipq[4];
static Event_data_CFL_t sgtpjsssfd[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t wzsyraqyak[] = { 
     {  7, fnbqewhqyu },
     {  0, riuxgprnfj },
     {  0, ykcireobbt },
     {  4, vmsgckcipq },
     {  0, sgtpjsssfd },
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t uwvnzczrti[4];
static Rpc_data_CFL_t   wfyimijnxg[4];
static Rpc_data_CFL_t   pupcmrgotp[4];
static Rpc_data_CFL_t   kzpsuqshbp[4];
static Rpc_data_CFL_t   zoomfsdgud[4];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  hsyrnfrobt[] = { 
     {  4, wfyimijnxg },
     {  4, pupcmrgotp },
     {  4, kzpsuqshbp },
     {  4, zoomfsdgud },
};
static const Log_message_CFL_t ebksmbxkug = { "starting test_duration", false, NULL };


unsigned  dckgvpmrcy;
const While_time_control_ROM_CFL_t dwuwniesre = { 20000,&dckgvpmrcy };



static While_control_RAM_CFL_t mxtigiumas_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lzptjduksg_rom = { 0 ,true, (void*)&dwuwniesre,&mxtigiumas_ram,null_function};

    
static const Log_message_CFL_t mvzssjhipv = { "ending test_duration", false, NULL };
static const Log_message_CFL_t doyjlopjtn = { "starting rpc_client", false, NULL };
static const Log_message_CFL_t mpkbxykjvh = { "ending rpc_client", false, NULL };
static const Log_message_CFL_t lwvogopzoc = { "rpc_server starting", false, NULL };
bool tsiuvwtvky = false;
const Release_rpc_event_CFL_t vnaihkkqju = { &tsiuvwtvky, 0};
uint16_t qhynzqxbjo = 0;
uint16_t dujwxopmwl = 0;
const uint16_t tytawljypz[] = { 1,2,3,4 };
const Process_rpc_CFL_t xzosjdfwtf = { &qhynzqxbjo, &dujwxopmwl, 0, 4, tytawljypz, 3, -1, false, NULL};
const Trap_rpc_event_CFL_t zhfmpixldt = { 0};
static const Log_message_CFL_t vmesrbihqy = { "rpc_worker_column starting", false, NULL };


//----------RAM data structures for columns ----

unsigned xfetcyhkks[4];
Watch_dog_struct_CFL_t * gfighzkyko[4];
unsigned char arjdnbvktw[4];
unsigned char ogizzrynyw[4];
void* pkstsdaowa[4];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t hvohxxkzjp[] = {
  { 1,true, 0, 4, 0, -1, -1,NULL },
  { 2,true, 1, 3, 4, -1, -1,NULL },
  { 3,true, 2, 5, 7, -1, -1,NULL },
  { 4,false, 3, 2, 12, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char tqszopenvm[14];


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

static const Column_element_CFL_t agwbvjgmxn[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ebksmbxkug}, // 0 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lzptjduksg_rom}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&mvzssjhipv}, // 2 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&doyjlopjtn}, // 4 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&mpkbxykjvh}, // 5 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 6 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&lwvogopzoc}, // 7 
    {release_rpc_request_CFL,NULL,(void *)&vnaihkkqju}, // 8 
    {process_rpc_event_CFL,null_function,(void *)&xzosjdfwtf}, // 9 
    {trap_rpc_event_CFL,NULL,(void *)&zhfmpixldt}, // 10 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&vmesrbihqy}, // 12 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 13 
};
Bitmap_CFL oojejhwoxy[0];
Registermap_CFL_t aazkmslqvb[0];
Floatmap_CFL_t vszuinfziu[0];
const Sm_control_ROM_CFL_t lmzvhwsovn[0];
Sm_control_RAM_CFL_t aaoupyatap[0];


static Time_control_CFL_t frumbujspj;




static Engine_control_CFL_t ugexyqfdip;


/* remaining allocate heap size */

static unsigned yovaznvfur;


/* current heap pointer */

static char* nrlnexicfp;


/* heap block area */

static CS_MEMORY_CONTROL khbcsqwphe;


    
    


const struct Handle_CFL_t gkcozrqpsx =
{

  .queue_number = 5,
  .queue_rom = wzsyraqyak,
  .queue_ram = htrisfkbjh,

  .column_elements_flags =tqszopenvm,
  .column_elements_ROM = agwbvjgmxn,

  .watch_dog_struct = gfighzkyko,
  .watch_dog_count  = xfetcyhkks,
   
   
  .column_flags = arjdnbvktw,
  .column_local_data = pkstsdaowa,
  .column_state = ogizzrynyw,
  .number_of_columns = 4,
  .column_rom_data = hvohxxkzjp,

  
  
  
  .time_control = &frumbujspj,
  .engine_control =&ugexyqfdip,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &yovaznvfur,
  .current_heap_location = &nrlnexicfp,
  .private_heap   = &khbcsqwphe,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  lmzvhwsovn,
  .sm_ram     = aaoupyatap,
  .number_of_bitmaps = 0,
  .bitmaps = oojejhwoxy,
  .number_of_registermaps = 0,
  .registermaps = aazkmslqvb,
  .number_of_floatmaps = 0,
  .floatmaps = vszuinfziu,
   .rpc_queue_number = 4,
  .rpc_queue_ram = uwvnzczrti,
  .rpc_queue_rom = hsyrnfrobt
} ;

const Handle_CFL_t*  rpc_services_handle(){
    return &gkcozrqpsx;
}
   

#ifdef __cplusplus
}
#endif

#endif
