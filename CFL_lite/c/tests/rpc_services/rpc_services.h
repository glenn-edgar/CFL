#ifndef __rpc_services_H__
#define __rpc_services_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t ajqesiinpg[5];
static Event_data_CFL_t kspinmtqfr[10];
static Event_data_CFL_t ghgutzeqou[10];
static Event_data_CFL_t gzixesvfml[10];
static Event_data_CFL_t mjakpknjkq[10];
static Event_data_CFL_t nybwgbptzm[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t gknqorglyd[] = { 
     {  10, kspinmtqfr },
     {  10, ghgutzeqou },
     {  10, gzixesvfml },
     {  10, mjakpknjkq },
     {  10, nybwgbptzm },
};
const char clean_up_data[] = "clean up data for bad event";
static const char *fojdlvsdhs = "start column";
static const unsigned short xkurywwwts[] = { 1,2,3,4};
const Enable_column_CFL_t bdlcfprulh = { true, 4, xkurywwwts };


unsigned  vjysmcgtqp;
const While_time_control_ROM_CFL_t awdihfcpus = { 60000,&vjysmcgtqp };



static While_control_RAM_CFL_t kmsvnqoypj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rnpjyajiyn_rom = { 0 ,true, &awdihfcpus,&kmsvnqoypj_ram,null_function};

    
static const char *jykmnariwl = "terminating";
const unsigned short bkeiezaveg[] = {11, 12, 13, 14, 15};
const rpc_server_event_processor_CFL_t uktpccwjxc = {NULL,5,bkeiezaveg};
const unsigned short znslfwyzat[] = {21, 22, 23, 24, 25};
const rpc_server_event_processor_CFL_t vhrmxdiivo = {NULL,5,znslfwyzat};
rpc_server_event_clean_up_CFL_t uhhwqnvzlf = {(void *)clean_up_data,true};
rpc_ram_message_CFL_t mdpjyzyyej;
const rpc_rom_message_CFL_t kfplupbnws = {13,RPC_MESSAGE_ID_CFL,1,2,&mdpjyzyyej};
 unsigned kdgvacowvh_ram;
const While_event_control_ROM_t kdgvacowvh_rom = { 1,32767,1000,true,"unexpected one second time out",&kdgvacowvh_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t ekpmtzctpr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qufgwcgfol_rom = { 1000 ,true, &kdgvacowvh_rom,&ekpmtzctpr_ram,rpc_client_1_time_out};

    


unsigned  lzpmostlfb;
const While_time_control_ROM_CFL_t eofxkpdrtm = { 5000,&lzpmostlfb };



static While_control_RAM_CFL_t glsaheatvx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t denqkchtgb_rom = { 0 ,true, &eofxkpdrtm,&glsaheatvx_ram,null_function};

    
rpc_ram_message_CFL_t gysgfeuzzu;
const rpc_rom_message_CFL_t cciefzkmyd = {23,RPC_MESSAGE_ID_CFL,1,3,&gysgfeuzzu};


unsigned  zpjymzzykl;
const While_time_control_ROM_CFL_t mrsqtbxtnp = { 5000,&zpjymzzykl };



static While_control_RAM_CFL_t wsnshrazlr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zidqyxszqz_rom = { 0 ,true, &mrsqtbxtnp,&wsnshrazlr_ram,null_function};

    


unsigned  bqnfaktnzb;
const While_time_control_ROM_CFL_t tthgscsvim = { 45000,&bqnfaktnzb };



static While_control_RAM_CFL_t jxaiaoceso_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sexesbpptk_rom = { 0 ,true, &tthgscsvim,&jxaiaoceso_ram,null_function};

    
rpc_ram_message_CFL_t wchfpictpn;
const rpc_rom_message_CFL_t axiopwvyeu = {33,RPC_MESSAGE_ID_CFL,1,4,&wchfpictpn};


unsigned  tradefdddz;
const While_time_control_ROM_CFL_t zgzlxfcnyi = { 45000,&tradefdddz };



static While_control_RAM_CFL_t asrmuxeozz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nstdrfcmma_rom = { 0 ,true, &zgzlxfcnyi,&asrmuxeozz_ram,null_function};

    


//----------RAM data structures for columns ----

unsigned vwhoasbqka[5];
Watch_dog_struct_CFL_t * aoiysvlrsl[5];
unsigned char ypkpfafgha[5];
unsigned char utliamskpx[5];
void* iaatgjqaqe[5];
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

static const Column_ROM_CFL_t hwyejtrdto[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { 1,false, 1, 4, 5, -1, -1 },
  { 2,false, 2, 5, 9, -1, -1 },
  { 3,false, 3, 4, 14, -1, -1 },
  { 4,false, 4, 5, 18, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char lknljnxgqz[23];


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

static const Column_element_CFL_t wrgbsaaogq[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&fojdlvsdhs},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&bdlcfprulh},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rnpjyajiyn_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jykmnariwl},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {rpc_server_event_processor_CFL,service_handler_1,(void *)&uktpccwjxc},
    {rpc_server_event_processor_CFL,service_handler_2,(void *)&vhrmxdiivo},
    {rpc_server_event_clean_up_CFL,rpc_clean_up_one_shot,(void *)&uhhwqnvzlf},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {rpc_client_event_generator_CFL,rpc_client_1_generator,(void *)&kfplupbnws},
    {while_handler_CFL,wait_event_handler,(void *)&qufgwcgfol_rom},
    {rpc_client_event_processor_CFL,rpc_client_event_processor_1,(void *)&"process event 1 user data"},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&denqkchtgb_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {rpc_client_event_generator_CFL,rpc_client_2_generator,(void *)&cciefzkmyd},
    {rpc_client_event_processor_CFL,rpc_client_event_processor_1,(void *)&"process event 2 user data"},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zidqyxszqz_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sexesbpptk_rom},
    {rpc_client_event_generator_CFL,rpc_client_3_generator,(void *)&axiopwvyeu},
    {rpc_client_event_processor_CFL,rpc_client_event_processor_1,(void *)&"process event 3 user data"},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nstdrfcmma_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};
Bitmap_CFL zbezfrzlbw[0];
Registermap_CFL_t wpflymslsb[0];
Floatmap_CFL_t pcqwnjtoxj[0];
const Sm_control_ROM_CFL_t bkndowpgxc[0];
Sm_control_RAM_CFL_t dtoalffhpm[0];


static Time_control_CFL_t virdhbeafl;




static Engine_control_CFL_t bdfedumwyr;


/* remaining allocate heap size */

static unsigned xuhhrypnzf;


/* current heap pointer */

static char* kvhtxhdkia;


/* heap block area */

static CS_MEMORY_CONTROL rumxtmckak;


    
    


const struct Handle_CFL_t tuotjedvds =
{

  .queue_number = 5,
  .queue_rom = gknqorglyd,
  .queue_ram = ajqesiinpg,

  .column_elements_flags =lknljnxgqz,
  .column_elements_ROM = wrgbsaaogq,

  .watch_dog_struct = aoiysvlrsl,
  .watch_dog_count  = vwhoasbqka,
   
   
  .column_flags = ypkpfafgha,
  .column_local_data = iaatgjqaqe,
  .column_state = utliamskpx,
  .number_of_columns = 5,
  .column_rom_data = hwyejtrdto,

  
  
  
  .time_control = &virdhbeafl,
  .engine_control =&bdfedumwyr,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &xuhhrypnzf,
  .current_heap_location = &kvhtxhdkia,
  .private_heap   = &rumxtmckak,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  bkndowpgxc,
  .sm_ram     = dtoalffhpm,
  .number_of_bitmaps = 0,
  .bitmaps = zbezfrzlbw,
  .number_of_registermaps = 0,
  .registermaps = wpflymslsb,
  .number_of_floatmaps = 0,
  .floatmaps = pcqwnjtoxj,
} ;

const Handle_CFL_t*  rpc_services_handle(){
    return &tuotjedvds;
}
   

#ifdef __cplusplus
}
#endif

#endif
