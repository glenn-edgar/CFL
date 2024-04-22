#ifndef __rpc_services_2_H__
#define __rpc_services_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"
#include "CFL_rpc_packets.h"

//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t hhkuenvfir[5];
static Event_data_CFL_t hpmleiqicj[7];
static Event_data_CFL_t lfbomwygzl[0];
static Event_data_CFL_t emfkvserpp[0];
static Event_data_CFL_t yygetyguxp[0];
static Event_data_CFL_t rjnvljsrdg[6];
static Event_data_CFL_t nigfdereek[2];
static Event_data_CFL_t jyebvsrvcy[0];
static Event_data_CFL_t jgmnaqsnha[0];
static Event_data_CFL_t xbfqehcatz[0];
static Event_data_CFL_t tjctrsaptv[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t rubmhnfolm[] = { 
     {  7, hpmleiqicj, 0, lfbomwygzl},
     {  0, emfkvserpp, 0, yygetyguxp},
     {  6, rjnvljsrdg, 2, nigfdereek},
     {  0, jyebvsrvcy, 0, jgmnaqsnha},
     {  0, xbfqehcatz, 0, tjctrsaptv},
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t zerdpaauon[1];
static Rpc_data_CFL_t   kgcirtrsgu[4];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  sftuyftsck[] = { 
     {  4, kgcirtrsgu },
};
static const Log_message_CFL_t cokmudrbsg = { "starting test_duration", false, NULL };


unsigned  hwcdiimywi;
const While_time_control_ROM_CFL_t rhrtaxewmg = { 20000,&hwcdiimywi };



static While_control_RAM_CFL_t yqkykkfhiu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ldrdttvaaj_rom = { 0 ,true, (void*)&rhrtaxewmg,&yqkykkfhiu_ram,null_function};

    
static const Log_message_CFL_t magrolbppa = { "ending test_duration", false, NULL };
static const Log_message_CFL_t qwuxbohnya = { "rpc_server_no_response starting", false, NULL };
bool vhcbcacmyu = false;
const Release_rpc_event_CFL_t etmjiztiyr = { &vhcbcacmyu, 0};
int32_t ccrhwajxak = 0;
uint16_t erjrsbxugt = 0;
const uint16_t irikshvpxm[] = { 1,2,3,4 };
const Process_rpc_CFL_t njvnddzwvl = { &ccrhwajxak, &erjrsbxugt, 0, 4, irikshvpxm, 3, 3500, false, (void *)server_time_out_data};
const Trap_rpc_event_CFL_t pojpxbyplg = { 0};
const Free_rpc_event_CFL_t mlhkcasylh = { 0};


unsigned  fmcnwmeque;
const While_time_control_ROM_CFL_t cfjjtahvac = { 5000,&fmcnwmeque };



static While_control_RAM_CFL_t oekejkezsh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dppjmplzrf_rom = { 0 ,true, (void*)&cfjjtahvac,&oekejkezsh_ram,null_function};

    
static const Log_message_CFL_t mewcpqxgut = { "rpc_server_no_response ending", false, NULL };
static const Log_message_CFL_t xxgnnbgysv = { "starting rpc_client", false, NULL };
int32_t soholvlunq = 0;
Rpc_transfer_data_packet_CFL_t ahjscouxye ;
Rpc_transfer_data_packet_CFL_t bvekfpuxpq ;
const Rpc_client_CFL_t libshufknu = { 0, 2,1, &ahjscouxye,client_data_load_code,NULL ,&bvekfpuxpq, client_data_verify_code, NULL, &soholvlunq ,3000, true, time_out_data_function, (void *)time_out_data };
static const Log_message_CFL_t sycswfiwms = { "rpc_worker_column time out starting", true, "rpc_worker_column rpc worker column  ending" };


unsigned  pitnvvwklw;
const While_time_control_ROM_CFL_t ifdqvqllgm = { 7000,&pitnvvwklw };



static While_control_RAM_CFL_t jhlushxfee_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rcymdygyjl_rom = { 0 ,true, (void*)&ifdqvqllgm,&jhlushxfee_ram,null_function};

    


//----------RAM data structures for columns ----

unsigned pblsanirfh[4];
Watch_dog_struct_CFL_t * gvlkboxuqo[4];
unsigned char drxcngdett[4];
unsigned char rmywizzrea[4];
void* yuyguyamzq[4];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t ikbfouqfeo[] = {
  { 1,true, 0, 4, 0, -1, -1,NULL },
  { 2,true, 1, 8, 4, -1, -1,NULL },
  { 3,true, 2, 3, 12, -1, -1,NULL },
  { 4,false, 3, 5, 15, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char qyuycvvnvm[20];


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

static const Column_element_CFL_t eblzaawfpm[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&cokmudrbsg}, // 0 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ldrdttvaaj_rom}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&magrolbppa}, // 2 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&qwuxbohnya}, // 4 
    {release_rpc_request_CFL,NULL,(void *)&etmjiztiyr}, // 5 
    {process_rpc_event_CFL,server_time_out_data_function,(void *)&njvnddzwvl}, // 6 
    {trap_rpc_event_CFL,NULL,(void *)&pojpxbyplg}, // 7 
    {free_rpc_event_CFL,NULL,(void *)&mlhkcasylh}, // 8 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dppjmplzrf_rom}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&mewcpqxgut}, // 10 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xxgnnbgysv}, // 12 
    {rpc_client_CFL,NULL,(void *)&libshufknu}, // 13 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 14 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&sycswfiwms}, // 15 
    {one_shot_handler_CFL,worker_first_action_code,NULL}, // 16 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rcymdygyjl_rom}, // 17 
    {one_shot_handler_CFL,worker_second_action_code,NULL}, // 18 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 19 
};
Bitmap_CFL xalpcxneav[0];
Registermap_CFL_t xbjvrciivb[0];
Floatmap_CFL_t gusofphogk[0];
const Sm_control_ROM_CFL_t zwhgdaxgmg[0];
Sm_control_RAM_CFL_t pafryswjvn[0];


static Time_control_CFL_t jtuacopbhu;




static Engine_control_CFL_t gdenmikwfb;


/* remaining allocate heap size */

static unsigned skkmhrmsjk;


/* current heap pointer */

static char* tipofnjqlz;


/* heap block area */

static CS_MEMORY_CONTROL eybejjdozb;


    
    


const struct Handle_CFL_t xkffyxeahb =
{

  .queue_number = 5,
  .queue_rom = rubmhnfolm,
  .queue_ram = hhkuenvfir,

  .column_elements_flags =qyuycvvnvm,
  .column_elements_ROM = eblzaawfpm,

  .watch_dog_struct = gvlkboxuqo,
  .watch_dog_count  = pblsanirfh,
   
   
  .column_flags = drxcngdett,
  .column_local_data = yuyguyamzq,
  .column_state = rmywizzrea,
  .number_of_columns = 4,
  .column_rom_data = ikbfouqfeo,

  
  
  
  .time_control = &jtuacopbhu,
  .engine_control =&gdenmikwfb,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &skkmhrmsjk,
  .current_heap_location = &tipofnjqlz,
  .private_heap   = &eybejjdozb,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  zwhgdaxgmg,
  .sm_ram     = pafryswjvn,
  .number_of_bitmaps = 0,
  .bitmaps = xalpcxneav,
  .number_of_registermaps = 0,
  .registermaps = xbjvrciivb,
  .number_of_floatmaps = 0,
  .floatmaps = gusofphogk,
   .rpc_queue_number = 1,
  .rpc_queue_ram = zerdpaauon,
  .rpc_queue_rom = sftuyftsck
} ;

const Handle_CFL_t*  rpc_services_handle_2(){
    return &xkffyxeahb;
}
   

#ifdef __cplusplus
}
#endif

#endif
