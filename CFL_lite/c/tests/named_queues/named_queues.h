#ifndef __named_queues_H__
#define __named_queues_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



 #define column_event_4 103 


 #define column_event_1 100 


 #define column_event_2 101 


 #define column_event_3 102 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t xxuwaprrdz[9];
static Event_data_CFL_t qalezjxvkd[7];
static Event_data_CFL_t xvhxxyojct[0];
static Event_data_CFL_t eqalxarseu[0];
static Event_data_CFL_t ccpkcoiepz[4];
static Event_data_CFL_t aaagjoivao[2];
static Event_data_CFL_t mmhuiccmkh[2];
static Event_data_CFL_t sfuootouit[0];
static Event_data_CFL_t ouxrbkjrob[4];
static Event_data_CFL_t wvbqusazjo[4];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t exyqjfhbbm[] = { 
     {  7, qalezjxvkd },
     {  0, xvhxxyojct },
     {  0, eqalxarseu },
     {  4, ccpkcoiepz },
     {  2, aaagjoivao },
     {  2, mmhuiccmkh },
     {  0, sfuootouit },
     {  4, ouxrbkjrob },
     {  4, wvbqusazjo },
};
const Event_data_CFL_t kunylkexbh = { column_event_1, false, NULL };
const Event_data_CFL_t elotjdokxt = { column_event_2, false, NULL };
const Event_data_CFL_t qqsxfymfum = { column_event_3, false, NULL };
const Event_data_CFL_t kllmksbfsi = { column_event_4, false, NULL };


unsigned  owfziagyhl;
const While_time_control_ROM_CFL_t rjroqhddlr = { 12000,&owfziagyhl };



static While_control_RAM_CFL_t thqvfptwtv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ubbsohksbh_rom = { 0 ,true, (void*)&rjroqhddlr,&thqvfptwtv_ram,null_function};

    
static const Log_message_CFL_t gcinmlcgwp = { "event generator start", false, NULL };


unsigned  tlqiryezqr;
const While_time_control_ROM_CFL_t iosfqrpftv = { 2000,&tlqiryezqr };



static While_control_RAM_CFL_t hdsdobcral_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rcjpwroulp_rom = { 0 ,true, (void*)&iosfqrpftv,&hdsdobcral_ram,null_function};

    
static const Log_message_CFL_t oegiphjqym = { "sending events", false, NULL };
const Queue_event_CFL_t tygxeziybu = { 3, &qqsxfymfum };
const Queue_event_CFL_t qmvxldlixw = { 3, &kllmksbfsi };
const Queue_event_CFL_t buzvvrfcqo = { 3, &kunylkexbh };
const Queue_event_CFL_t bfwokzlwdc = { 3, &elotjdokxt };
const Queue_event_CFL_t fsfmirduyk = { 6, &elotjdokxt };
static const Log_message_CFL_t xrdlrmdyft = { "done sending events", false, NULL };
static const Log_message_CFL_t ieuimtqgdp = { "event distributor start", false, NULL };
static unsigned short oxrngdslah[] = { 4};
static const Conditional_send_event_CFL_t bqdkxmaxew = { 1, oxrngdslah};
static unsigned short twduopicpn[] = { 5};
static const Conditional_send_event_CFL_t vioabjfmgn = { 1, twduopicpn};
static const Log_message_CFL_t ardpmbbsuo = { "event_client_1", false, NULL };
static unsigned short ucfarugjhn[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t niuytzuaxo = { 4, ucfarugjhn};
static const Log_message_CFL_t rfbvtqfztd = { "event_client_2", false, NULL };
static unsigned short wcsjglkxhs[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t kzrgetgtlm = { 4, wcsjglkxhs};
static const Log_message_CFL_t zgbbodmdpy = { "idle column", false, NULL };
static unsigned short tujccngpng[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t sbsainonit = { 4, tujccngpng};
static const Log_message_CFL_t iccjfoqpqu = { "push front event", false, NULL };
static unsigned short dfzfnkhuif[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t itwszpifgt = { 4, dfzfnkhuif};
static const Front_queue_event_CFL_t vjnvhhdjzw = { 6, &kunylkexbh };
static const Front_queue_event_CFL_t psjkbgcbgu = { 6, &elotjdokxt };
static const Front_queue_event_CFL_t fqaqneujap = { 6, &qqsxfymfum };
static const Front_queue_event_CFL_t vbzuidfbzz = { 6, &kllmksbfsi };
  static const char display_message[] = "display_message";
static const Log_message_CFL_t pljzunjlwj = { "dump residual events", false, NULL };
static const Residual_column_event_CFL_t jrmsbfezun = { 7, (void *)(void *)display_message };
static const Front_queue_event_CFL_t czkeuafgsj = { 7, &kunylkexbh };
static const Front_queue_event_CFL_t byjyitvczo = { 7, &elotjdokxt };
static const Front_queue_event_CFL_t vvbslpeqlk = { 7, &qqsxfymfum };
static const Front_queue_event_CFL_t mibwjrugwx = { 7, &kllmksbfsi };


//----------RAM data structures for columns ----

unsigned qjhycamzmh[8];
Watch_dog_struct_CFL_t * kolwepfwpa[8];
unsigned char tmdtxpnndh[8];
unsigned char xnpxpdrbip[8];
void* wzvcffcogc[8];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t caeiijoizy[] = {
  { 1,true, 0, 2, 0, -1, -1,NULL },
  { 2,true, 1, 10, 2, -1, -1,NULL },
  { 3,true, 2, 4, 12, -1, -1,NULL },
  { 4,true, 3, 3, 16, -1, -1,NULL },
  { 5,true, 4, 3, 19, -1, -1,NULL },
  { 6,false, 5, 3, 22, -1, -1,NULL },
  { 7,true, 6, 7, 25, -1, -1,NULL },
  { 8,true, 7, 7, 32, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char kjnbuqhqnr[39];


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

static const Column_element_CFL_t tffiugazrk[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ubbsohksbh_rom}, // 0 
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer}, // 1 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&gcinmlcgwp}, // 2 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rcjpwroulp_rom}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&oegiphjqym}, // 4 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&tygxeziybu}, // 5 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&qmvxldlixw}, // 6 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&buzvvrfcqo}, // 7 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&bfwokzlwdc}, // 8 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&fsfmirduyk}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xrdlrmdyft}, // 10 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ieuimtqgdp}, // 12 
    {conditional_send_CFL,routing_1,(void *)&bqdkxmaxew}, // 13 
    {conditional_send_CFL,routing_2,(void *)&vioabjfmgn}, // 14 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 15 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ardpmbbsuo}, // 16 
    {display_event_CFL,NULL,(void *)&niuytzuaxo}, // 17 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 18 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rfbvtqfztd}, // 19 
    {display_event_CFL,NULL,(void *)&kzrgetgtlm}, // 20 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 21 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zgbbodmdpy}, // 22 
    {display_event_CFL,NULL,(void *)&sbsainonit}, // 23 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 24 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&iccjfoqpqu}, // 25 
    {display_event_CFL,NULL,(void *)&itwszpifgt}, // 26 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&vjnvhhdjzw}, // 27 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&psjkbgcbgu}, // 28 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&fqaqneujap}, // 29 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&vbzuidfbzz}, // 30 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 31 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&pljzunjlwj}, // 32 
    {process_residual_column_event_queue,residual_display,(void *)&jrmsbfezun}, // 33 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&czkeuafgsj}, // 34 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&byjyitvczo}, // 35 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&vvbslpeqlk}, // 36 
    {one_shot_handler_CFL,send_front_queue_event_CFL,(void *)&mibwjrugwx}, // 37 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 38 
};
Bitmap_CFL ycmvllpzdn[0];
Registermap_CFL_t wkoyihqcij[0];
Floatmap_CFL_t yrjpetnedi[0];
const Sm_control_ROM_CFL_t btxgqcbcut[0];
Sm_control_RAM_CFL_t xvkevbicpv[0];


static Time_control_CFL_t yicgiljgba;




static Engine_control_CFL_t tjxeujtykx;


/* remaining allocate heap size */

static unsigned gtzmrcjrwg;


/* current heap pointer */

static char* aqwmabxeie;


/* heap block area */

static CS_MEMORY_CONTROL xpjmagjgsh;


    
    


const struct Handle_CFL_t fldyaefrtk =
{

  .queue_number = 9,
  .queue_rom = exyqjfhbbm,
  .queue_ram = xxuwaprrdz,

  .column_elements_flags =kjnbuqhqnr,
  .column_elements_ROM = tffiugazrk,

  .watch_dog_struct = kolwepfwpa,
  .watch_dog_count  = qjhycamzmh,
   
   
  .column_flags = tmdtxpnndh,
  .column_local_data = wzvcffcogc,
  .column_state = xnpxpdrbip,
  .number_of_columns = 8,
  .column_rom_data = caeiijoizy,

  
  
  
  .time_control = &yicgiljgba,
  .engine_control =&tjxeujtykx,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &gtzmrcjrwg,
  .current_heap_location = &aqwmabxeie,
  .private_heap   = &xpjmagjgsh,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  btxgqcbcut,
  .sm_ram     = xvkevbicpv,
  .number_of_bitmaps = 0,
  .bitmaps = ycmvllpzdn,
  .number_of_registermaps = 0,
  .registermaps = wkoyihqcij,
  .number_of_floatmaps = 0,
  .floatmaps = yrjpetnedi,
} ;

const Handle_CFL_t*  column_queue_handle(){
    return &fldyaefrtk;
}
   

#ifdef __cplusplus
}
#endif

#endif
