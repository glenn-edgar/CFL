#ifndef __watch_dog_H__
#define __watch_dog_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t nmqtseofvx[6];
static Event_data_CFL_t vlytrwzdja[7];
static Event_data_CFL_t vqjfueidnx[0];
static Event_data_CFL_t ldcjpdsdnu[0];
static Event_data_CFL_t nhmbxtmmch[0];
static Event_data_CFL_t hremfmjtis[0];
static Event_data_CFL_t sajdmthmju[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t oiwyrkescv[] = { 
     {  7, vlytrwzdja },
     {  0, vqjfueidnx },
     {  0, ldcjpdsdnu },
     {  0, nhmbxtmmch },
     {  0, hremfmjtis },
     {  0, sajdmthmju },
};
    static const char test_message_1[] = "test_message_1";
    static const char test_message_2[] = "test_message_2";
    static const char test_message_3[] = "test_message_3";
    



unsigned  zgpsaqgjrd;
const While_time_control_ROM_CFL_t awaulcagkx = { 10000,&zgpsaqgjrd };



static While_control_RAM_CFL_t yjodysijnm_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zyujhpalrc_rom = { 0 ,true, (void*)&awaulcagkx,&yjodysijnm_ram,null_function};

    
static const char *ozsessatsy = "watch_dog_reset";
const Watch_dog_struct_CFL_t mccrawjdgp = { 1000, test_wd_handler, false, (void*)&test_message_1};


unsigned  uasuqsgabr;
const While_time_control_ROM_CFL_t hulhzfseza = { 2000,&uasuqsgabr };



static While_control_RAM_CFL_t mjiuydszcy_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lquflnutne_rom = { 0 ,true, (void*)&hulhzfseza,&mjiuydszcy_ram,null_function};

    
static const char *ivqpgzyhdp = "should not see this message";
static const char *opdlnkasxn = "watch_dog_terminate";
const Watch_dog_struct_CFL_t mdzlhzbmiw = { 1000, test_wd_handler, true, (void*)&test_message_2};


unsigned  ujlaumejop;
const While_time_control_ROM_CFL_t fznjeywofj = { 2000,&ujlaumejop };



static While_control_RAM_CFL_t zppyfgnpyo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t uaeibhqlwr_rom = { 0 ,true, (void*)&fznjeywofj,&zppyfgnpyo_ram,null_function};

    
static const char *albwducpob = "should not see this message";
static const char *aqbypqcjmx = "watch_dog_pass";
const Watch_dog_struct_CFL_t abkxpwaurq = { 5000, test_wd_handler, true, (void*)&test_message_3};


unsigned  kkcvnvdgfl;
const While_time_control_ROM_CFL_t ghwyuhgner = { 1000,&kkcvnvdgfl };



static While_control_RAM_CFL_t yatqlsmwbu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t aebylvauyi_rom = { 0 ,true, (void*)&ghwyuhgner,&yatqlsmwbu_ram,null_function};

    
static const char *dkekzuxhwt = "watch_dog_pass passed";
static const char *xqzsuelvbx = "watch_dog_pass_repeat";
const Watch_dog_struct_CFL_t ngkekryiyn = { 5000, test_wd_handler, true, (void*)&test_message_3};


unsigned  owviufuduo;
const While_time_control_ROM_CFL_t yhekmnxjcg = { 1000,&owviufuduo };



static While_control_RAM_CFL_t ejbzhtdvry_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t zlphldjjaa_rom = { 0 ,true, (void*)&yhekmnxjcg,&ejbzhtdvry_ram,null_function};

    
static const char *oxtikouzqh = "watch_dog_repeat passed";
static const char *gsnvwkhejf = "watch_dog_reattach";
const Watch_dog_struct_CFL_t kemgleumsh = { 5000, test_wd_handler, true, (void*)&test_message_3};


unsigned  xkisscczsb;
const While_time_control_ROM_CFL_t prggipsguy = { 1000,&xkisscczsb };



static While_control_RAM_CFL_t yajjuhlvok_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yzpsfddtue_rom = { 0 ,true, (void*)&prggipsguy,&yajjuhlvok_ram,null_function};

    
static const char *icjgtjbgfy = "watch_dog_pass passed second time";


//----------RAM data structures for columns ----

unsigned ovljqounzu[5];
Watch_dog_struct_CFL_t * mbgtlqhfvq[5];
unsigned char chqejxftfo[5];
unsigned char ymqkigrhye[5];
void* siffezhpny[5];
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

static const Column_ROM_CFL_t gciguoblvr[] = {
  { 1,true, 0, 2, 0, -1, -1 },
  { 2,true, 1, 6, 2, -1, -1 },
  { 3,true, 2, 6, 8, -1, -1 },
  { 4,true, 3, 6, 14, -1, -1 },
  { 5,true, 4, 11, 20, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char zdvocqqboc[31];


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

static const Column_element_CFL_t zgndxetvyn[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zyujhpalrc_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ozsessatsy},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&mccrawjdgp},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lquflnutne_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ivqpgzyhdp},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&opdlnkasxn},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&mdzlhzbmiw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&uaeibhqlwr_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&albwducpob},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aqbypqcjmx},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&abkxpwaurq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&aebylvauyi_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dkekzuxhwt},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xqzsuelvbx},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&ngkekryiyn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&zlphldjjaa_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&oxtikouzqh},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gsnvwkhejf},
    {one_shot_handler_CFL,Start_watch_dog_CFL,(void *)&kemgleumsh},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yzpsfddtue_rom},
    {one_shot_handler_CFL,Clear_watch_dog_CFL,NULL},
    {one_shot_handler_CFL,log_message_CFL,(void *)&icjgtjbgfy},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
Bitmap_CFL zlohbfeuwp[0];
Registermap_CFL_t scsapanvso[0];
Floatmap_CFL_t mmemvfzvti[0];
const Sm_control_ROM_CFL_t qyhzolknal[0];
Sm_control_RAM_CFL_t sncimtwxew[0];


static Time_control_CFL_t oghzqsiqkp;




static Engine_control_CFL_t ubprmjbffn;


/* remaining allocate heap size */

static unsigned dccctsatya;


/* current heap pointer */

static char* gokpudqklu;


/* heap block area */

static CS_MEMORY_CONTROL mbkqhdxinj;


    
    


const struct Handle_CFL_t rblyblegsm =
{

  .queue_number = 6,
  .queue_rom = oiwyrkescv,
  .queue_ram = nmqtseofvx,

  .column_elements_flags =zdvocqqboc,
  .column_elements_ROM = zgndxetvyn,

  .watch_dog_struct = mbgtlqhfvq,
  .watch_dog_count  = ovljqounzu,
   
   
  .column_flags = chqejxftfo,
  .column_local_data = siffezhpny,
  .column_state = ymqkigrhye,
  .number_of_columns = 5,
  .column_rom_data = gciguoblvr,

  
  
  
  .time_control = &oghzqsiqkp,
  .engine_control =&ubprmjbffn,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &dccctsatya,
  .current_heap_location = &gokpudqklu,
  .private_heap   = &mbkqhdxinj,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  qyhzolknal,
  .sm_ram     = sncimtwxew,
  .number_of_bitmaps = 0,
  .bitmaps = zlohbfeuwp,
  .number_of_registermaps = 0,
  .registermaps = scsapanvso,
  .number_of_floatmaps = 0,
  .floatmaps = mmemvfzvti,
} ;

const Handle_CFL_t*  watch_dog_handle(){
    return &rblyblegsm;
}
   

#ifdef __cplusplus
}
#endif

#endif
