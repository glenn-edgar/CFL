#ifndef __column_data_H__
#define __column_data_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t rxlihbsvgh[4];
static Event_data_CFL_t ugiqqpjanq[7];
static Event_data_CFL_t xyuvdghwfc[0];
static Event_data_CFL_t sluwckfngt[0];
static Event_data_CFL_t uecngimenj[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t dnsseivfny[] = { 
     {  7, ugiqqpjanq },
     {  0, xyuvdghwfc },
     {  0, sluwckfngt },
     {  0, uecngimenj },
};
char column_test_data_1[] ="this is the column data 1 test";char column_test_data_2[] ="this is the column data 2 test";  static void get_current_column_data(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    unsigned short column_index = get_current_column_index_CFL(input); 
    Printf_CFL(input,"column index %d \n",column_index);
    char *column_data = (char *)retrieve_current_column_data_CFL(input);
    
    Printf_CFL(input,"user data for column_data_test %s \n",column_data);


  }



  static void get_column_data(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    unsigned short column_index = get_current_column_index_CFL(input); 
    Printf_CFL(input,"column index %d \n",column_index);
    char *column_data = (char *)retreive_column_data_CFL(input,column_index);
    
    Printf_CFL(input,"user data for column_data_test %s \n",column_data);


  }



static const Log_message_CFL_t dtyymhdqyt = { "starting store", false, NULL };
static unsigned short plkyvqirrp[] = { 1};
static const Column_data_CFL_t djsmuporld = { 1, plkyvqirrp, (void *)&column_test_data_1 };
static unsigned short bmnslimfor[] = { 2};
static const Column_data_CFL_t wcniwwivfl = { 1, bmnslimfor, (void *)&column_test_data_2 };
static const Log_message_CFL_t issfqabfvz = { "ending store column data", false, NULL };
static const Log_message_CFL_t rzwjfcsftk = { "receive_1", false, NULL };


unsigned  lrjskygiqj;
const While_time_control_ROM_CFL_t shwnewlmqc = { 1000,&lrjskygiqj };



static While_control_RAM_CFL_t rmnbbimwas_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wgwwztjgza_rom = { 0 ,true, (void*)&shwnewlmqc,&rmnbbimwas_ram,null_function};

    
static const Log_message_CFL_t amdmyrqjgt = { "ending receive_1", false, NULL };
static const Log_message_CFL_t oquziaemkr = { "starting column_receive_2", false, NULL };


unsigned  qwwvhqybzd;
const While_time_control_ROM_CFL_t mbstcrisej = { 1000,&qwwvhqybzd };



static While_control_RAM_CFL_t zenjdfijjz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qxzzqpsbnc_rom = { 0 ,true, (void*)&mbstcrisej,&zenjdfijjz_ram,null_function};

    
static const Log_message_CFL_t imixktjpdk = { "ending receive_2", false, NULL };


//----------RAM data structures for columns ----

unsigned kqwmxfgfyi[3];
Watch_dog_struct_CFL_t * jbnnunuyom[3];
unsigned char dywfjqcdwz[3];
unsigned char twfjyuzdbb[3];
void* kleijlufec[3];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t jblntfzaek[] = {
  { 1,true, 0, 5, 0, -1, -1,NULL },
  { 2,true, 1, 5, 5, -1, -1,NULL },
  { 3,true, 2, 5, 10, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char xpnoludzex[15];


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

static const Column_element_CFL_t ssvygdemxz[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&dtyymhdqyt}, // 0 
    {one_shot_handler_CFL,store_column_data,(void *)&djsmuporld}, // 1 
    {one_shot_handler_CFL,store_column_data,(void *)&wcniwwivfl}, // 2 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&issfqabfvz}, // 3 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 4 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rzwjfcsftk}, // 5 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wgwwztjgza_rom}, // 6 
    {one_shot_handler_CFL,get_current_column_data,NULL}, // 7 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&amdmyrqjgt}, // 8 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&oquziaemkr}, // 10 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qxzzqpsbnc_rom}, // 11 
    {one_shot_handler_CFL,get_column_data,NULL}, // 12 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&imixktjpdk}, // 13 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 14 
};
Bitmap_CFL dgwchlhtvl[0];
Registermap_CFL_t xsfbzzbqfl[0];
Floatmap_CFL_t sltogqdvzb[0];
const Sm_control_ROM_CFL_t fogpmobomy[0];
Sm_control_RAM_CFL_t ongdvyfnqd[0];


static Time_control_CFL_t fzuzcjuvqj;




static Engine_control_CFL_t mfcvkyggse;


/* remaining allocate heap size */

static unsigned zjaakfiibv;


/* current heap pointer */

static char* jxfbepkuuy;


/* heap block area */

static CS_MEMORY_CONTROL awlpbbyuss;


    
    


const struct Handle_CFL_t nwxkihjnin =
{

  .queue_number = 4,
  .queue_rom = dnsseivfny,
  .queue_ram = rxlihbsvgh,

  .column_elements_flags =xpnoludzex,
  .column_elements_ROM = ssvygdemxz,

  .watch_dog_struct = jbnnunuyom,
  .watch_dog_count  = kqwmxfgfyi,
   
   
  .column_flags = dywfjqcdwz,
  .column_local_data = kleijlufec,
  .column_state = twfjyuzdbb,
  .number_of_columns = 3,
  .column_rom_data = jblntfzaek,

  
  
  
  .time_control = &fzuzcjuvqj,
  .engine_control =&mfcvkyggse,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &zjaakfiibv,
  .current_heap_location = &jxfbepkuuy,
  .private_heap   = &awlpbbyuss,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  fogpmobomy,
  .sm_ram     = ongdvyfnqd,
  .number_of_bitmaps = 0,
  .bitmaps = dgwchlhtvl,
  .number_of_registermaps = 0,
  .registermaps = xsfbzzbqfl,
  .number_of_floatmaps = 0,
  .floatmaps = sltogqdvzb,
} ;

const Handle_CFL_t*  column_data_handle(){
    return &nwxkihjnin;
}
   

#ifdef __cplusplus
}
#endif

#endif
