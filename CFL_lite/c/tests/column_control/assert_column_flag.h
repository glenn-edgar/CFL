#ifndef __assert_column_flag_H__
#define __assert_column_flag_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t qvvejkyifn[9];
static Event_data_CFL_t wjtvvcbhlp[7];
static Event_data_CFL_t pvlbcuvqmn[0];
static Event_data_CFL_t gcgdljdahf[0];
static Event_data_CFL_t ihzjjsamky[0];
static Event_data_CFL_t dhzwhbqzhr[0];
static Event_data_CFL_t kyosfbildv[0];
static Event_data_CFL_t pkedzvolgh[0];
static Event_data_CFL_t yxfhdlcxub[0];
static Event_data_CFL_t ymfubmcuuu[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t pjeecupujk[] = { 
     {  7, wjtvvcbhlp },
     {  0, pvlbcuvqmn },
     {  0, gcgdljdahf },
     {  0, ihzjjsamky },
     {  0, dhzwhbqzhr },
     {  0, kyosfbildv },
     {  0, pkedzvolgh },
     {  0, yxfhdlcxub },
     {  0, ymfubmcuuu },
};


  static const char should_not_see_message[] = "should not see this message";
  static const char true_message[]= "true message";
  static const char fail_termination_message[] = "fail termination message";  
static const Log_message_CFL_t zjleacutll = { "main column is active", false, NULL };
static const unsigned short qqiezvniyn[] = { 3};
const Set_return_code_CFL_t gxqncydajf = { 1,qqiezvniyn,true };
static const unsigned short unpvahjgfp[] = { 4};
const Set_return_code_CFL_t nhldlkibmk = { 1,unpvahjgfp,false };
static const unsigned short miruibzgzk[] = { 1};
const Enable_column_CFL_t brdxgjkujg = { false, 1, miruibzgzk };
static const unsigned short vtsxreusby[] = { 1};
const Join_column_CFL_t facwnpvfzx = { true, 1, vtsxreusby };
static const unsigned short jqilgvkxrp[] = { 2};
const Enable_column_CFL_t muiezaphrb = { true, 1, jqilgvkxrp };


unsigned  dicqebmkxk;
const While_time_control_ROM_CFL_t luyxtqpdio = { 10000,&dicqebmkxk };



static While_control_RAM_CFL_t lslxcxuamu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t cakvdwumfg_rom = { 0 ,true, (void*)&luyxtqpdio,&lslxcxuamu_ram,null_function};

    
static const Log_message_CFL_t zktgnuwhah = { "main column is terminating", false, NULL };
static const Log_message_CFL_t bkegfpwdmz = { "test_column_1 is active", false, NULL };
const Assert_flag_CFL_t wtxibjgnin = { true, 3,bool_true_function, (void *)&should_not_see_message };
static const unsigned short psfwsawjpl[] = { 5,6,7};
unsigned short zhlolxoifg = 0;
bool jrppusxvhm = true;
const sequence_columns_CFL_t vexxlvtmww = { 3, psfwsawjpl, &zhlolxoifg, &jrppusxvhm };
bool pelyiklfqh = true;
const Assert_column_CFL_t bfyljybyyz = { vexxlvtmww, (void *)&wtxibjgnin, false, &pelyiklfqh };
static const Log_message_CFL_t zzvgyqvoem = { "this test should pass", false, NULL };
const Assert_flag_CFL_t vpbaljjseu = { false, 3,bool_true_function, (void *)&true_message };
static const unsigned short uwurzftmze[] = { 5,6,7};
unsigned short uplkrccdxy = 0;
bool qsvlfamxfn = true;
const sequence_columns_CFL_t hjmgxyxliq = { 3, uwurzftmze, &uplkrccdxy, &qsvlfamxfn };
bool jakebftgug = true;
const Assert_column_CFL_t qdmdqpbetl = { hjmgxyxliq, (void *)&vpbaljjseu, false, &jakebftgug };
static const Log_message_CFL_t varlfizszc = { "this test should pass", false, NULL };
const Assert_flag_CFL_t sqnsvvgaby = { false, 3,bool_false_function, (void *)&fail_termination_message };
static const unsigned short dywutlysmk[] = { 5,6,7};
unsigned short hkhetdnnfk = 0;
bool kmjxkigsep = true;
const sequence_columns_CFL_t leejibnizc = { 3, dywutlysmk, &hkhetdnnfk, &kmjxkigsep };
bool rxfesktsxy = true;
const Assert_column_CFL_t opypmrbbcc = { leejibnizc, (void *)&sqnsvvgaby, true, &rxfesktsxy };
static const Log_message_CFL_t zsxkhkifnr = { "should not see this log message", false, NULL };
static const Log_message_CFL_t oswskxzdxn = { "test_column_2 is active with reset flag option", false, NULL };


unsigned  oszzellzpz;
const While_time_control_ROM_CFL_t iwryfzlkhs = { 1000,&oszzellzpz };



static While_control_RAM_CFL_t uvdacbpnqo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vhjkuminka_rom = { 0 ,true, (void*)&iwryfzlkhs,&uvdacbpnqo_ram,null_function};

    
const Assert_flag_CFL_t jftcnxrwfn = { true, 4,bool_false_function, (void *)&fail_termination_message };
static const unsigned short ivnonvouzd[] = { };
unsigned short trtmymepoz = 0;
bool fwrwpljwfe = true;
const sequence_columns_CFL_t dhfjhkzekl = { 0, ivnonvouzd, &trtmymepoz, &fwrwpljwfe };
bool whzfhgfuzz = true;
const Assert_column_CFL_t fryuehhjbb = { dhfjhkzekl, (void *)&jftcnxrwfn, false, &whzfhgfuzz };
static const Log_message_CFL_t idfhynbltm = { "should not see this log message", false, NULL };
static const Log_message_CFL_t cuzkxdelia = { "test_column_1 is active", false, NULL };


unsigned  qckmdbdnzc;
const While_time_control_ROM_CFL_t ogtfkpyuig = { 100,&qckmdbdnzc };



static While_control_RAM_CFL_t lgizyjdmup_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t igjdnvtumo_rom = { 0 ,true, (void*)&ogtfkpyuig,&lgizyjdmup_ram,null_function};

    
static const Log_message_CFL_t qmkcunedvq = { "test_column_1 is terminating", false, NULL };
static const Log_message_CFL_t rvmojmjnyq = { "test_column_2 is active", false, NULL };


unsigned  oopiavxupd;
const While_time_control_ROM_CFL_t aiwpixwhve = { 100,&oopiavxupd };



static While_control_RAM_CFL_t eqilborkdc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t elhchnamus_rom = { 0 ,true, (void*)&aiwpixwhve,&eqilborkdc_ram,null_function};

    
static const Log_message_CFL_t swkchuqdzw = { "test_column_2 is terminating", false, NULL };
static const Log_message_CFL_t uweiuwwixw = { "error_column_1 is active", false, NULL };


unsigned  tavzetoehg;
const While_time_control_ROM_CFL_t igsukosboh = { 100,&tavzetoehg };



static While_control_RAM_CFL_t uyyvlgjorv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kuzehbvkrm_rom = { 0 ,true, (void*)&igsukosboh,&uyyvlgjorv_ram,null_function};

    
static const Log_message_CFL_t thiyyndgps = { "error_column_1 is terminating", false, NULL };
static const Log_message_CFL_t zdbwidtdpe = { "error_column_2 is active", false, NULL };


unsigned  tszlyzdojq;
const While_time_control_ROM_CFL_t gwhbvpygxe = { 100,&tszlyzdojq };



static While_control_RAM_CFL_t jvvnyjnenj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t vgalzyhqcq_rom = { 0 ,true, (void*)&gwhbvpygxe,&jvvnyjnenj_ram,null_function};

    
static const Log_message_CFL_t guvuhpvdmt = { "error_column_2 is terminating", false, NULL };
static const Log_message_CFL_t qvnbstfdbs = { "error_column_3 is active", false, NULL };


unsigned  bblixvxrry;
const While_time_control_ROM_CFL_t msupzzpqhi = { 100,&bblixvxrry };



static While_control_RAM_CFL_t obarmmlelt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sbjwrfzvty_rom = { 0 ,true, (void*)&msupzzpqhi,&obarmmlelt_ram,null_function};

    
static const Log_message_CFL_t dxatusvdwl = { "error_column_3 is terminating", false, NULL };


//----------RAM data structures for columns ----

unsigned ntrlhgndyc[8];
Watch_dog_struct_CFL_t * dxlprxiqph[8];
unsigned char wmdmhjntly[8];
unsigned char ysaevylenn[8];
void* pusqjsiqeq[8];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t vlyvvwvpbw[] = {
  { 1,true, 0, 9, 0, -1, -1,NULL },
  { 2,false, 1, 8, 9, -1, -1,NULL },
  { 3,false, 2, 5, 17, -1, -1,NULL },
  { 4,false, 3, 4, 22, -1, -1,NULL },
  { 5,false, 4, 4, 26, -1, -1,NULL },
  { 6,false, 5, 4, 30, -1, -1,NULL },
  { 7,false, 6, 4, 34, -1, -1,NULL },
  { 8,false, 7, 4, 38, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char watysqhfel[42];


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

static const Column_element_CFL_t nrqkgpbxkt[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zjleacutll}, // 0 
    {one_shot_handler_CFL,set_return_code_CFL,(void *)&gxqncydajf}, // 1 
    {one_shot_handler_CFL,set_return_code_CFL,(void *)&nhldlkibmk}, // 2 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&brdxgjkujg}, // 3 
    {join_columns_function_CFL,null_function,(void *)&facwnpvfzx}, // 4 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&muiezaphrb}, // 5 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&cakvdwumfg_rom}, // 6 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zktgnuwhah}, // 7 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 8 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&bkegfpwdmz}, // 9 
    {assert_column_CFL,assert_flag_CFL,(void *)&bfyljybyyz}, // 10 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zzvgyqvoem}, // 11 
    {assert_column_CFL,assert_flag_CFL,(void *)&qdmdqpbetl}, // 12 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&varlfizszc}, // 13 
    {assert_column_CFL,assert_flag_CFL,(void *)&opypmrbbcc}, // 14 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zsxkhkifnr}, // 15 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 16 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&oswskxzdxn}, // 17 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vhjkuminka_rom}, // 18 
    {assert_column_CFL,assert_flag_CFL,(void *)&fryuehhjbb}, // 19 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&idfhynbltm}, // 20 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 21 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&cuzkxdelia}, // 22 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&igjdnvtumo_rom}, // 23 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&qmkcunedvq}, // 24 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 25 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rvmojmjnyq}, // 26 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&elhchnamus_rom}, // 27 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&swkchuqdzw}, // 28 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 29 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&uweiuwwixw}, // 30 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kuzehbvkrm_rom}, // 31 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&thiyyndgps}, // 32 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 33 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&zdbwidtdpe}, // 34 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&vgalzyhqcq_rom}, // 35 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&guvuhpvdmt}, // 36 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 37 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&qvnbstfdbs}, // 38 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sbjwrfzvty_rom}, // 39 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&dxatusvdwl}, // 40 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 41 
};
Bitmap_CFL buytejuosc[0];
Registermap_CFL_t atuzhccysx[0];
Floatmap_CFL_t pdgwhldpmg[0];
const Sm_control_ROM_CFL_t fkqpdfbcsg[0];
Sm_control_RAM_CFL_t dpwdmrpont[0];


static Time_control_CFL_t zqgdqvkjwl;




static Engine_control_CFL_t ujtjjssqqa;


/* remaining allocate heap size */

static unsigned qidbdfdfxv;


/* current heap pointer */

static char* bmcowlzguw;


/* heap block area */

static CS_MEMORY_CONTROL uzunthsodq;


    
    


const struct Handle_CFL_t iaengcpuln =
{

  .queue_number = 9,
  .queue_rom = pjeecupujk,
  .queue_ram = qvvejkyifn,

  .column_elements_flags =watysqhfel,
  .column_elements_ROM = nrqkgpbxkt,

  .watch_dog_struct = dxlprxiqph,
  .watch_dog_count  = ntrlhgndyc,
   
   
  .column_flags = wmdmhjntly,
  .column_local_data = pusqjsiqeq,
  .column_state = ysaevylenn,
  .number_of_columns = 8,
  .column_rom_data = vlyvvwvpbw,

  
  
  
  .time_control = &zqgdqvkjwl,
  .engine_control =&ujtjjssqqa,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &qidbdfdfxv,
  .current_heap_location = &bmcowlzguw,
  .private_heap   = &uzunthsodq,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  fkqpdfbcsg,
  .sm_ram     = dpwdmrpont,
  .number_of_bitmaps = 0,
  .bitmaps = buytejuosc,
  .number_of_registermaps = 0,
  .registermaps = atuzhccysx,
  .number_of_floatmaps = 0,
  .floatmaps = pdgwhldpmg,
} ;

const Handle_CFL_t*  assert_column_flag_handle(){
    return &iaengcpuln;
}
   

#ifdef __cplusplus
}
#endif

#endif
