#ifndef __chain_column_case_H__
#define __chain_column_case_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



 #define column_event_4 103 


 #define column_event_3 102 


 #define column_event_1 100 


 #define column_event_2 101 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t ptjwfnopug[7];
static Event_data_CFL_t dixfqnqyvg[7];
static Event_data_CFL_t ypzytushnf[4];
static Event_data_CFL_t ghyuaoqqmu[0];
static Event_data_CFL_t yjwpycjwwt[0];
static Event_data_CFL_t rzhzqbbshn[0];
static Event_data_CFL_t qzrdrizqap[0];
static Event_data_CFL_t uftvfvqutb[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t yxgemwgiot[] = { 
     {  7, dixfqnqyvg },
     {  4, ypzytushnf },
     {  0, ghyuaoqqmu },
     {  0, yjwpycjwwt },
     {  0, rzhzqbbshn },
     {  0, qzrdrizqap },
     {  0, uftvfvqutb },
};
const char user_data[] = "This is user data test string :::    ";const Event_data_CFL_t yrilojrpaq = { column_event_1, false, NULL };
const Event_data_CFL_t nrtsjpnkww = { column_event_2, false, NULL };
const Event_data_CFL_t fiamancurc = { column_event_3, false, NULL };
const Event_data_CFL_t itwmsywpag = { column_event_4, false, NULL };


unsigned  tvmlrjiwdo;
const While_time_control_ROM_CFL_t byashdvvfc = { 12000,&tvmlrjiwdo };



static While_control_RAM_CFL_t kuyuszuyav_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t knrqxhjyln_rom = { 0 ,true, (void*)&byashdvvfc,&kuyuszuyav_ram,null_function};

    
static const Log_message_CFL_t luenewdbps = { "event generator start", false, NULL };


unsigned  twwyrgxkxy;
const While_time_control_ROM_CFL_t eiiibwehgl = { 2000,&twwyrgxkxy };



static While_control_RAM_CFL_t vvxywiqtsx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ztgeleuqan_rom = { 0 ,true, (void*)&eiiibwehgl,&vvxywiqtsx_ram,null_function};

    
static const Log_message_CFL_t jjfqnazacu = { "sending events", false, NULL };
const Queue_event_CFL_t kbjxcxiikk = { 1, &fiamancurc };
const Queue_event_CFL_t qhfepsfzrc = { 1, &itwmsywpag };
const Queue_event_CFL_t katpkgfpgk = { 1, &yrilojrpaq };
const Queue_event_CFL_t pikrtydkqv = { 1, &nrtsjpnkww };
static const Log_message_CFL_t fmaluopmtv = { "done sending events", false, NULL };
static const Log_message_CFL_t nfqacfpwjl = { "chain_case_column", false, NULL };
static const unsigned short axjdnessxc[] = { 3,4,5};
const Enable_column_CFL_t mbfzupowph = { true, 3, axjdnessxc };
static const unsigned short hodstharrs[] = { 3,4,5};
const Chain_columns_case_CFL_t pgnwksdyuh = { 3, hodstharrs, (void *)&user_data };
static unsigned short ziwdpxyrum[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t tbgqnjnhtd = { 4, ziwdpxyrum};
static const Log_message_CFL_t httmimgeoy = { "case_column_1", false, NULL };
static unsigned short wbreqlioga[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t wpwekpvwqo = { 4, wbreqlioga};


unsigned  vxoeejhmqm;
const While_time_control_ROM_CFL_t wluuwmmpyl = { 5000,&vxoeejhmqm };



static While_control_RAM_CFL_t rjkheinsmx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t nagfvtdnaf_rom = { 0 ,true, (void*)&wluuwmmpyl,&rjkheinsmx_ram,null_function};

    
static const Log_message_CFL_t qqoreiujgv = { "case_column_1 wait done", false, NULL };
static const Log_message_CFL_t upbenedlfj = { "case_column_2", false, NULL };
static unsigned short mqajzsrvkq[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t gfyqawordx = { 4, mqajzsrvkq};


unsigned  orkfgxwmpc;
const While_time_control_ROM_CFL_t xujptbngyr = { 5500,&orkfgxwmpc };



static While_control_RAM_CFL_t idgrwpoiim_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t iyilovmymu_rom = { 0 ,true, (void*)&xujptbngyr,&idgrwpoiim_ram,null_function};

    
static const Log_message_CFL_t vmawbenqth = { "case_column_2 wait done", false, NULL };
static const Log_message_CFL_t ajrpaxfdtw = { "case_column_3", false, NULL };
static unsigned short pepklooarv[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t umbrdxwxqw = { 4, pepklooarv};


unsigned  uptuorqrak;
const While_time_control_ROM_CFL_t xctyqglgrf = { 5700,&uptuorqrak };



static While_control_RAM_CFL_t krcfppunej_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tccnjswmjm_rom = { 0 ,true, (void*)&xctyqglgrf,&krcfppunej_ram,null_function};

    
static const Log_message_CFL_t gaszbscfon = { "case_column_3 wait done", false, NULL };


//----------RAM data structures for columns ----

unsigned qsycuiisjc[6];
Watch_dog_struct_CFL_t * scrllhquta[6];
unsigned char bqwprgjjsg[6];
unsigned char pbkhawfkjm[6];
void* xkmsrhnnen[6];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t swgivafhqo[] = {
  { 1,true, 0, 5, 11, -1, -1,NULL },
  { 2,true, 1, 2, 0, -1, -1,NULL },
  { 3,true, 2, 9, 2, -1, -1,NULL },
  { 4,false, 3, 5, 16, -1, -1,NULL },
  { 5,false, 4, 5, 21, -1, -1,NULL },
  { 6,false, 5, 5, 26, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char etkmeftcqu[31];


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

static const Column_element_CFL_t rnecplqcoh[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&knrqxhjyln_rom}, // 0 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&luenewdbps}, // 2 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ztgeleuqan_rom}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&jjfqnazacu}, // 4 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&kbjxcxiikk}, // 5 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&qhfepsfzrc}, // 6 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&katpkgfpgk}, // 7 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&pikrtydkqv}, // 8 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&fmaluopmtv}, // 9 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 10 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&nfqacfpwjl}, // 11 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&mbfzupowph}, // 12 
    {chain_columns_case_CFL,case_test_fn,(void *)&pgnwksdyuh}, // 13 
    {display_event_CFL,NULL,(void *)&tbgqnjnhtd}, // 14 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 15 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&httmimgeoy}, // 16 
    {display_event_CFL,NULL,(void *)&wpwekpvwqo}, // 17 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&nagfvtdnaf_rom}, // 18 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&qqoreiujgv}, // 19 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 20 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&upbenedlfj}, // 21 
    {display_event_CFL,NULL,(void *)&gfyqawordx}, // 22 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&iyilovmymu_rom}, // 23 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&vmawbenqth}, // 24 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 25 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ajrpaxfdtw}, // 26 
    {display_event_CFL,NULL,(void *)&umbrdxwxqw}, // 27 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tccnjswmjm_rom}, // 28 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&gaszbscfon}, // 29 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 30 
};
Bitmap_CFL jxrcfqsetz[0];
Registermap_CFL_t dtkuvgixdk[0];
Floatmap_CFL_t lygvanomtp[0];
const Sm_control_ROM_CFL_t yeujeqkihz[0];
Sm_control_RAM_CFL_t kapbtjnqso[0];


static Time_control_CFL_t kuffkzzipa;




static Engine_control_CFL_t qkjurvgtnj;


/* remaining allocate heap size */

static unsigned slhzexlepq;


/* current heap pointer */

static char* rffxucovbo;


/* heap block area */

static CS_MEMORY_CONTROL nuyhjzxpdh;


    
    


const struct Handle_CFL_t zdegcrdqpd =
{

  .queue_number = 7,
  .queue_rom = yxgemwgiot,
  .queue_ram = ptjwfnopug,

  .column_elements_flags =etkmeftcqu,
  .column_elements_ROM = rnecplqcoh,

  .watch_dog_struct = scrllhquta,
  .watch_dog_count  = qsycuiisjc,
   
   
  .column_flags = bqwprgjjsg,
  .column_local_data = xkmsrhnnen,
  .column_state = pbkhawfkjm,
  .number_of_columns = 6,
  .column_rom_data = swgivafhqo,

  
  
  
  .time_control = &kuffkzzipa,
  .engine_control =&qkjurvgtnj,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &slhzexlepq,
  .current_heap_location = &rffxucovbo,
  .private_heap   = &nuyhjzxpdh,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  yeujeqkihz,
  .sm_ram     = kapbtjnqso,
  .number_of_bitmaps = 0,
  .bitmaps = jxrcfqsetz,
  .number_of_registermaps = 0,
  .registermaps = dtkuvgixdk,
  .number_of_floatmaps = 0,
  .floatmaps = lygvanomtp,
} ;

const Handle_CFL_t*  chain_column_case_handle(){
    return &zdegcrdqpd;
}
   

#ifdef __cplusplus
}
#endif

#endif
