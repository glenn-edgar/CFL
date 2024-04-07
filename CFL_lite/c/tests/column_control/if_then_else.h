#ifndef __if_then_else_H__
#define __if_then_else_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t lfmwyblcql[8];
static Event_data_CFL_t brguuitakz[7];
static Event_data_CFL_t avdfjflmwe[0];
static Event_data_CFL_t pjnebfnket[0];
static Event_data_CFL_t aawnoqdlaj[0];
static Event_data_CFL_t whxvwadwno[0];
static Event_data_CFL_t kytafppfxm[0];
static Event_data_CFL_t arimpaumwx[0];
static Event_data_CFL_t qnpentmakg[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t eboppkjzsr[] = { 
     {  7, brguuitakz },
     {  0, avdfjflmwe },
     {  0, pjnebfnket },
     {  0, aawnoqdlaj },
     {  0, whxvwadwno },
     {  0, kytafppfxm },
     {  0, arimpaumwx },
     {  0, qnpentmakg },
};
static const Log_message_CFL_t hnzjfkbqni = { "starting test_1", false, NULL };
static const unsigned short kdnigtntii[] = { 5};
static const unsigned short bhdkjlxesf[] = { 6};
const If_then_else_CFL_t ojibfzoukt = { false, true, 1, kdnigtntii, 1, bhdkjlxesf,NULL };
static const Log_message_CFL_t niotlwaglc = { "ending test_1", false, NULL };
static const Log_message_CFL_t pkiyqzqfxc = { "starting test_2", false, NULL };
static const unsigned short lzgpeyjnsm[] = { 5};
static const unsigned short revzjasgav[] = { 6};
const If_then_else_CFL_t uqvjmcdhjt = { false, false, 1, lzgpeyjnsm, 1, revzjasgav,NULL };
static const Log_message_CFL_t wavizgtpwq = { "ending test_2", false, NULL };
static const Log_message_CFL_t twnpisbokd = { "starting test_3", false, NULL };
static const unsigned short sfevxgfffz[] = { 5};
static const unsigned short htaxdfzrbs[] = { };
const If_then_else_CFL_t mefiozvezc = { true, false, 1, sfevxgfffz, 0, htaxdfzrbs,NULL };


unsigned  jiuzhdyhcv;
const While_time_control_ROM_CFL_t nljynaentr = { 1000,&jiuzhdyhcv };



static While_control_RAM_CFL_t vosphahvfb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hezatxfwon_rom = { 0 ,true, (void*)&nljynaentr,&vosphahvfb_ram,null_function};

    
static const Log_message_CFL_t iycmtuvpua = { "ending test_3", false, NULL };
static const Log_message_CFL_t sgqtgvreku = { "starting test_4", false, NULL };
static const unsigned short musmiyjrhe[] = { };
static const unsigned short vqthrgisyu[] = { 6};
const If_then_else_CFL_t cyrhwaoccd = { false, false, 0, musmiyjrhe, 1, vqthrgisyu,NULL };
static const Log_message_CFL_t gyyklchvtp = { "ending test_4", false, NULL };
static const Log_message_CFL_t gvkdqgrrpr = { "starting test_5", false, NULL };
static const unsigned short lqogyuytgg[] = { };
static const unsigned short vulcrudjvf[] = { 6};
const If_then_else_CFL_t sdboikucdh = { false, false, 0, lqogyuytgg, 1, vulcrudjvf,NULL };
static const Log_message_CFL_t lmnfjtdfdb = { "ending test_5", false, NULL };
static const Log_message_CFL_t csxhenusga = { "then column active", false, NULL };


unsigned  pwowgtoufk;
const While_time_control_ROM_CFL_t dhsofacsph = { 3000,&pwowgtoufk };



static While_control_RAM_CFL_t ylkhnettzf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rznmiruhtm_rom = { 0 ,true, (void*)&dhsofacsph,&ylkhnettzf_ram,null_function};

    
static const Log_message_CFL_t hoyclyvfzu = { "then column is terminating", false, NULL };
static const Log_message_CFL_t laonbxxztg = { "else column active", false, NULL };


unsigned  zbbcgpjdvk;
const While_time_control_ROM_CFL_t jrkmdwocbf = { 3000,&zbbcgpjdvk };



static While_control_RAM_CFL_t dbubxlbyrd_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yawqicgjos_rom = { 0 ,true, (void*)&jrkmdwocbf,&dbubxlbyrd_ram,null_function};

    
static const Log_message_CFL_t fwujsygomp = { "else column is terminating", false, NULL };


//----------RAM data structures for columns ----

unsigned iwdzldqtjt[7];
Watch_dog_struct_CFL_t * vlgihwunei[7];
unsigned char wrqtzgfjdv[7];
unsigned char pcqepznuym[7];
void* kzbcebqlau[7];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t lchjxfbfcf[] = {
  { 1,true, 0, 3, 0, -1, -1,NULL },
  { 2,false, 1, 3, 3, -1, -1,NULL },
  { 3,false, 2, 5, 6, -1, -1,NULL },
  { 4,false, 3, 4, 11, -1, -1,NULL },
  { 5,false, 4, 4, 15, -1, -1,NULL },
  { 6,false, 5, 4, 19, -1, -1,NULL },
  { 7,false, 6, 4, 23, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char kytaonnehm[27];


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

static const Column_element_CFL_t iyrhjfpmiu[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hnzjfkbqni}, // 0 
    {if_then_else_function_CFL,true_constant_handler,(void *)&ojibfzoukt}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&niotlwaglc}, // 2 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&pkiyqzqfxc}, // 3 
    {if_then_else_function_CFL,false_constant_handler,(void *)&uqvjmcdhjt}, // 4 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&wavizgtpwq}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&twnpisbokd}, // 6 
    {if_then_else_function_CFL,true_constant_handler,(void *)&mefiozvezc}, // 7 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hezatxfwon_rom}, // 8 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&iycmtuvpua}, // 9 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 10 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&sgqtgvreku}, // 11 
    {if_then_else_function_CFL,false_constant_handler,(void *)&cyrhwaoccd}, // 12 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&gyyklchvtp}, // 13 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 14 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&gvkdqgrrpr}, // 15 
    {if_then_else_function_CFL,true_constant_handler,(void *)&sdboikucdh}, // 16 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&lmnfjtdfdb}, // 17 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 18 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&csxhenusga}, // 19 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rznmiruhtm_rom}, // 20 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hoyclyvfzu}, // 21 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 22 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&laonbxxztg}, // 23 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yawqicgjos_rom}, // 24 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&fwujsygomp}, // 25 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 26 
};
Bitmap_CFL dbgrxstgam[0];
Registermap_CFL_t fibzuzjpmw[0];
Floatmap_CFL_t eyfjaultzl[0];
const Sm_control_ROM_CFL_t wcexkinfsm[0];
Sm_control_RAM_CFL_t uftxwykrpd[0];


static Time_control_CFL_t sksgspubrk;




static Engine_control_CFL_t drxtzmplaf;


/* remaining allocate heap size */

static unsigned dihzonhart;


/* current heap pointer */

static char* uebxlucavr;


/* heap block area */

static CS_MEMORY_CONTROL fnyukupjwh;


    
    


const struct Handle_CFL_t qeqtucwpgo =
{

  .queue_number = 8,
  .queue_rom = eboppkjzsr,
  .queue_ram = lfmwyblcql,

  .column_elements_flags =kytaonnehm,
  .column_elements_ROM = iyrhjfpmiu,

  .watch_dog_struct = vlgihwunei,
  .watch_dog_count  = iwdzldqtjt,
   
   
  .column_flags = wrqtzgfjdv,
  .column_local_data = kzbcebqlau,
  .column_state = pcqepznuym,
  .number_of_columns = 7,
  .column_rom_data = lchjxfbfcf,

  
  
  
  .time_control = &sksgspubrk,
  .engine_control =&drxtzmplaf,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &dihzonhart,
  .current_heap_location = &uebxlucavr,
  .private_heap   = &fnyukupjwh,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  wcexkinfsm,
  .sm_ram     = uftxwykrpd,
  .number_of_bitmaps = 0,
  .bitmaps = dbgrxstgam,
  .number_of_registermaps = 0,
  .registermaps = fibzuzjpmw,
  .number_of_floatmaps = 0,
  .floatmaps = eyfjaultzl,
} ;

const Handle_CFL_t*  if_then_else_handle(){
    return &qeqtucwpgo;
}
   

#ifdef __cplusplus
}
#endif

#endif
