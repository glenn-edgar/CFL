#ifndef __while_column_H__
#define __while_column_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t skrvtitwvr[5];
static Event_data_CFL_t ifrhzekgpq[7];
static Event_data_CFL_t mrghlnwtae[0];
static Event_data_CFL_t bxvmndzjpk[0];
static Event_data_CFL_t exxtsvtfbz[0];
static Event_data_CFL_t gmibiebegw[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t xfwzojwuev[] = { 
     {  7, ifrhzekgpq },
     {  0, mrghlnwtae },
     {  0, bxvmndzjpk },
     {  0, exxtsvtfbz },
     {  0, gmibiebegw },
};
static const char* while_message = "This is a test message for while \n";
static const Log_message_CFL_t zgfabrikfq = { "starting while command", false, NULL };
static const unsigned short aexeaugvxw[] = { 1,2,3};
bool cbwfrpmhlq = true;
unsigned pzijcdpnde = 0;
const While_column_control_CFL_t gmlgosahoi = { (bool *)&cbwfrpmhlq, (unsigned *)&pzijcdpnde, (void *)&while_message, 3,aexeaugvxw };
static const Log_message_CFL_t vbfnfyxnqt = { "done with while statement", false, NULL };
static const Log_message_CFL_t sohiycbyba = { "while_0 should be active", false, NULL };


unsigned  tvktrvlzoh;
const While_time_control_ROM_CFL_t wfpxmaffdv = { 1000,&tvktrvlzoh };



static While_control_RAM_CFL_t vngshfosco_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mmdgydljbw_rom = { 0 ,true, (void*)&wfpxmaffdv,&vngshfosco_ram,null_function};

    
static const Log_message_CFL_t llsknlpjqp = { "while_0 is terminating", false, NULL };
static const Log_message_CFL_t txbyvnsulq = { "while_1 should be active", false, NULL };


unsigned  cysccqwzak;
const While_time_control_ROM_CFL_t dwumdltnmz = { 2000,&cysccqwzak };



static While_control_RAM_CFL_t brvpoprjvk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hqviqpfowv_rom = { 0 ,true, (void*)&dwumdltnmz,&brvpoprjvk_ram,null_function};

    
static const Log_message_CFL_t jgmjvhybjc = { "while_1 is terminating", false, NULL };
static const Log_message_CFL_t yrlztyfnsy = { "while_2 should be active", false, NULL };


unsigned  crqtewwfmf;
const While_time_control_ROM_CFL_t xbaxngdpsh = { 3000,&crqtewwfmf };



static While_control_RAM_CFL_t payouyvttu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fpnbxydyyz_rom = { 0 ,true, (void*)&xbaxngdpsh,&payouyvttu_ram,null_function};

    
static const Log_message_CFL_t xobncbeizj = { "while_2 is terminating", false, NULL };


//----------RAM data structures for columns ----

unsigned ucetfrughj[4];
Watch_dog_struct_CFL_t * qghtpyaxev[4];
unsigned char vignchpwaf[4];
unsigned char dneicpwkqs[4];
void* hgfeuiqvln[4];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t ovlrzlcytc[] = {
  { 1,true, 0, 4, 0, -1, -1,NULL },
  { 2,false, 1, 4, 4, -1, -1,NULL },
  { 3,false, 2, 4, 8, -1, -1,NULL },
  { 4,false, 3, 4, 12, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char dvbnfqghpo[16];


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

static const Column_element_CFL_t wfmxxbuprt[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zgfabrikfq}, // 0 
    {while_column_handler_CFL,while_column_test,(void *)&gmlgosahoi}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&vbfnfyxnqt}, // 2 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&sohiycbyba}, // 4 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mmdgydljbw_rom}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&llsknlpjqp}, // 6 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 7 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&txbyvnsulq}, // 8 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hqviqpfowv_rom}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&jgmjvhybjc}, // 10 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&yrlztyfnsy}, // 12 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fpnbxydyyz_rom}, // 13 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xobncbeizj}, // 14 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 15 
};
Bitmap_CFL jpewtffoyy[0];
Registermap_CFL_t oityijsgjn[0];
Floatmap_CFL_t pabjilxsht[0];
const Sm_control_ROM_CFL_t tpcoitaajr[0];
Sm_control_RAM_CFL_t qgjcgxhqdm[0];


static Time_control_CFL_t wtobktukaq;




static Engine_control_CFL_t bpfmnciiyy;


/* remaining allocate heap size */

static unsigned sgfhqgkcrk;


/* current heap pointer */

static char* tipxibjkxk;


/* heap block area */

static CS_MEMORY_CONTROL vdibiyadic;


    
    


const struct Handle_CFL_t hdmxjwbuny =
{

  .queue_number = 5,
  .queue_rom = xfwzojwuev,
  .queue_ram = skrvtitwvr,

  .column_elements_flags =dvbnfqghpo,
  .column_elements_ROM = wfmxxbuprt,

  .watch_dog_struct = qghtpyaxev,
  .watch_dog_count  = ucetfrughj,
   
   
  .column_flags = vignchpwaf,
  .column_local_data = hgfeuiqvln,
  .column_state = dneicpwkqs,
  .number_of_columns = 4,
  .column_rom_data = ovlrzlcytc,

  
  
  
  .time_control = &wtobktukaq,
  .engine_control =&bpfmnciiyy,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &sgfhqgkcrk,
  .current_heap_location = &tipxibjkxk,
  .private_heap   = &vdibiyadic,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  tpcoitaajr,
  .sm_ram     = qgjcgxhqdm,
  .number_of_bitmaps = 0,
  .bitmaps = jpewtffoyy,
  .number_of_registermaps = 0,
  .registermaps = oityijsgjn,
  .number_of_floatmaps = 0,
  .floatmaps = pabjilxsht,
} ;

const Handle_CFL_t*  while_column_handle(){
    return &hdmxjwbuny;
}
   

#ifdef __cplusplus
}
#endif

#endif
