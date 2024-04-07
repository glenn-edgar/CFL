#ifndef __supervisor_H__
#define __supervisor_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t yrpxsqtuij[17];
static Event_data_CFL_t ibgnzcyqlg[7];
static Event_data_CFL_t uaibemztjz[0];
static Event_data_CFL_t bwbtscosoc[0];
static Event_data_CFL_t vqvtpdpwuw[0];
static Event_data_CFL_t cjtataewpz[0];
static Event_data_CFL_t pefxknjkmb[0];
static Event_data_CFL_t afsebjkpge[0];
static Event_data_CFL_t lxstltktsb[0];
static Event_data_CFL_t kertjilhni[0];
static Event_data_CFL_t jyaanfzaqw[0];
static Event_data_CFL_t hdepnmwpqi[0];
static Event_data_CFL_t eoqsandcgn[0];
static Event_data_CFL_t ttbsdptkgo[0];
static Event_data_CFL_t ykzcsydzxy[0];
static Event_data_CFL_t iedmvfjmqc[0];
static Event_data_CFL_t zhxwgcnpup[0];
static Event_data_CFL_t plsswaoaaj[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ohwipiftqy[] = { 
     {  7, ibgnzcyqlg },
     {  0, uaibemztjz },
     {  0, bwbtscosoc },
     {  0, vqvtpdpwuw },
     {  0, cjtataewpz },
     {  0, pefxknjkmb },
     {  0, afsebjkpge },
     {  0, lxstltktsb },
     {  0, kertjilhni },
     {  0, jyaanfzaqw },
     {  0, hdepnmwpqi },
     {  0, eoqsandcgn },
     {  0, ttbsdptkgo },
     {  0, ykzcsydzxy },
     {  0, iedmvfjmqc },
     {  0, zhxwgcnpup },
     {  1, plsswaoaaj },
};
static const char test_message[] = "\n\n ********************** This is test message for supervisor  *****************  \n\n\n";
const Event_data_CFL_t cpufuuhrsi = { 32767, false, (void *)test_message };
static const Log_message_CFL_t lycurkwlcr = { "starting control_column_1_for_1", false, NULL };
static const unsigned short nocankarfz[] = { 1,2,3};
const Enable_column_CFL_t ibaphtbcff = { true, 3, nocankarfz };
static const unsigned short lwqvdwpknj[] = { 1,2,3};
static bool urdprwhawn[] = { false,false,false};
static unsigned cadnbbswsn[] = { 0,0,0};
static unsigned dzarclywdm[] = { 0,0,0};
const Supervisor_data_CFL_t qsdhltfyfl = { 0,3, lwqvdwpknj, urdprwhawn, cadnbbswsn,dzarclywdm,1,NULL};
static const Log_message_CFL_t ojjnvgwxnu = { "starting test_1_for_1_a", false, NULL };


unsigned  ywcglifmzh;
const While_time_control_ROM_CFL_t nqaualdzgs = { 2000,&ywcglifmzh };



static While_control_RAM_CFL_t baooosordo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lxguztfzeo_rom = { 0 ,true, (void*)&nqaualdzgs,&baooosordo_ram,null_function};

    
static const Log_message_CFL_t xbgjzayyea = { "ending test_1_for_1_a", false, NULL };
static const Log_message_CFL_t xdegpsxsaq = { "starting test_1_for_2_a", false, NULL };


unsigned  cnbzetsmmh;
const While_time_control_ROM_CFL_t yrxalwmokn = { 1000,&cnbzetsmmh };



static While_control_RAM_CFL_t evopqjrznt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xhyyxgfbdx_rom = { 0 ,true, (void*)&yrxalwmokn,&evopqjrznt_ram,null_function};

    
static const Log_message_CFL_t fjxchbaepg = { "ending test_1_for_2_a", false, NULL };
static const Log_message_CFL_t eptwgejhsg = { "starting test_1_for_3_a", false, NULL };


unsigned  vqcsqbpcjl;
const While_time_control_ROM_CFL_t xneuvxwgxn = { 3000,&vqcsqbpcjl };



static While_control_RAM_CFL_t vklmpmpvqj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bymzuazxmc_rom = { 0 ,true, (void*)&xneuvxwgxn,&vklmpmpvqj_ram,null_function};

    
static const Log_message_CFL_t rqupyvtojo = { "ending test_1_for_3_a", false, NULL };
static const Log_message_CFL_t luobpjztvb = { "starting control_column_1_for_1", false, NULL };
static const unsigned short gkmzkxnvry[] = { 5,6,7};
const Enable_column_CFL_t wwdlusdqlq = { true, 3, gkmzkxnvry };
static const unsigned short ossumoyiwh[] = { 5,6,7};
static bool elohtblahu[] = { false,false,false};
static unsigned eeiinzdvzj[] = { 0,0,0};
static unsigned letikqdbzf[] = { 0,0,0};
const Supervisor_data_CFL_t wyjaebzyvt = { 1,3, ossumoyiwh, elohtblahu, eeiinzdvzj,letikqdbzf,1,NULL};
static const Log_message_CFL_t hyaoslpusm = { "starting test_2_for_1_a", false, NULL };


unsigned  crhkevrava;
const While_time_control_ROM_CFL_t ovlhgbrkhc = { 2000,&crhkevrava };



static While_control_RAM_CFL_t fyhkgxgoss_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dekgrqtdli_rom = { 0 ,true, (void*)&ovlhgbrkhc,&fyhkgxgoss_ram,null_function};

    
static const Log_message_CFL_t fhmqoeyaia = { "ending test_2_for_1_a", false, NULL };
static const Log_message_CFL_t glfgustvfc = { "starting test_2_for_2_a", false, NULL };


unsigned  hdoxxgnvps;
const While_time_control_ROM_CFL_t npgnukasxn = { 1000,&hdoxxgnvps };



static While_control_RAM_CFL_t wgnnifzupk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xgibhqzpaa_rom = { 0 ,true, (void*)&npgnukasxn,&wgnnifzupk_ram,null_function};

    
static const Log_message_CFL_t wcvpoqurjv = { "ending test_2_for_2_a", false, NULL };
static const Log_message_CFL_t teraydzqct = { "starting test_2_for_3_a", false, NULL };


unsigned  hpmxslxbor;
const While_time_control_ROM_CFL_t iifwluwdcr = { 3000,&hpmxslxbor };



static While_control_RAM_CFL_t dmfbcnhcly_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t hbstsgpgbx_rom = { 0 ,true, (void*)&iifwluwdcr,&dmfbcnhcly_ram,null_function};

    
static const Log_message_CFL_t rwjzfnoodj = { "ending test_2_for_3_a", false, NULL };
static const Log_message_CFL_t rfqwrjlbhf = { "control_column_rest_for_1", false, NULL };
static const unsigned short frhyfjuqlv[] = { 9,10,11};
const Enable_column_CFL_t ihvjehjgeo = { true, 3, frhyfjuqlv };
static const unsigned short cyndwmphjy[] = { 9,10,11};
static bool zxtdvbyhrl[] = { false,false,false};
static unsigned pbexmvyuvn[] = { 0,0,0};
static unsigned paxuwvewnw[] = { 0,0,0};
const Supervisor_data_CFL_t hcdmvrqlkg = { 2,3, cyndwmphjy, zxtdvbyhrl, pbexmvyuvn,paxuwvewnw,1,NULL};
static const Log_message_CFL_t tvnhvrraxh = { "starting test_3_for_1_a", false, NULL };


unsigned  elzasbblxy;
const While_time_control_ROM_CFL_t yybdyourcz = { 25000,&elzasbblxy };



static While_control_RAM_CFL_t ykkkymqjns_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qvqjxmgiev_rom = { 0 ,true, (void*)&yybdyourcz,&ykkkymqjns_ram,null_function};

    
static const Log_message_CFL_t ynsbpryhfp = { "ending test_3_for_1_a", false, NULL };
static const Log_message_CFL_t bgdfwixkjm = { "starting test_3_for_2_a", false, NULL };


unsigned  fuajtqtypr;
const While_time_control_ROM_CFL_t ppyhgbzjjb = { 1000,&fuajtqtypr };



static While_control_RAM_CFL_t aulyuejmtx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t otlyvrafxg_rom = { 0 ,true, (void*)&ppyhgbzjjb,&aulyuejmtx_ram,null_function};

    
static const Log_message_CFL_t kphujvxdrq = { "ending test_3_for_2_a", false, NULL };
static const Log_message_CFL_t uqzmzdtgxn = { "starting test_3_for_3_a", false, NULL };


unsigned  nyluqijcnn;
const While_time_control_ROM_CFL_t gpksiblpnr = { 3000,&nyluqijcnn };



static While_control_RAM_CFL_t ypdwritrfz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fovskotpbz_rom = { 0 ,true, (void*)&gpksiblpnr,&ypdwritrfz_ram,null_function};

    
static const Log_message_CFL_t lqslwyiozp = { "ending test_3_for_3_a", false, NULL };
static const Log_message_CFL_t ulypykoncy = { "control_function_controlled_rest", false, NULL };
static const unsigned short idgibdzvgb[] = { 12,13,14};
const Enable_column_CFL_t rgqftumfev = { true, 3, idgibdzvgb };
static const unsigned short gxznjamsxo[] = { 12,13,14};
static bool ymwwpvkvcd[] = { false,false,false};
static unsigned nrovbacqij[] = { 0,0,0};
static unsigned gdyzonjfga[] = { 0,0,0};
const Supervisor_data_CFL_t qnonoqzmqk = { 0,3, gxznjamsxo, ymwwpvkvcd, nrovbacqij,gdyzonjfga,1,NULL};


unsigned  jmictgfyzg;
const While_time_control_ROM_CFL_t ghcvbxvbne = { 1000,&jmictgfyzg };



static While_control_RAM_CFL_t kccpcwhupg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t tvmkezfdbf_rom = { 0 ,true, (void*)&ghcvbxvbne,&kccpcwhupg_ram,null_function};

    
const Queue_event_CFL_t zwotpiguye = { 16, &cpufuuhrsi };
static const Log_message_CFL_t snhdnjkisd = { "starting test_4_fn_1_a", false, NULL };


unsigned  htkyoonwel;
const While_time_control_ROM_CFL_t prdxfggllv = { 25000,&htkyoonwel };



static While_control_RAM_CFL_t iililyesff_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fjuszxcbwv_rom = { 0 ,true, (void*)&prdxfggllv,&iililyesff_ram,null_function};

    
static const Log_message_CFL_t hyccpafmul = { "ending test_4_fn_1_a", false, NULL };
static const Log_message_CFL_t dpfvytofwf = { "starting test_4_fn_2_a", false, NULL };


unsigned  vrsfmxxjbt;
const While_time_control_ROM_CFL_t msuwfvapar = { 1000,&vrsfmxxjbt };



static While_control_RAM_CFL_t fzatexavxz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mhjqykraky_rom = { 0 ,true, (void*)&msuwfvapar,&fzatexavxz_ram,null_function};

    
static const Log_message_CFL_t ijuoapwcko = { "ending test_4_fn_2_a", false, NULL };
static const Log_message_CFL_t xvcbktgpxp = { "starting test_4_fn_3_a", false, NULL };


unsigned  wdmcgdfxto;
const While_time_control_ROM_CFL_t ucfwjlqsls = { 25000,&wdmcgdfxto };



static While_control_RAM_CFL_t nrnwijogxq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t oogmypsydx_rom = { 0 ,true, (void*)&ucfwjlqsls,&nrnwijogxq_ram,null_function};

    
static const Log_message_CFL_t timxbgfhyl = { "ending test_4_fn_3_a", false, NULL };


//----------RAM data structures for columns ----

unsigned otwcuzzrbl[16];
Watch_dog_struct_CFL_t * qkappzgvzy[16];
unsigned char iurxzunypp[16];
unsigned char uegptrqxyd[16];
void* bfurpetqui[16];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t kdfkbigdan[] = {
  { 1,true, 0, 4, 0, -1, -1,NULL },
  { 2,false, 1, 4, 4, -1, -1,NULL },
  { 3,false, 2, 4, 8, -1, -1,NULL },
  { 4,false, 3, 4, 12, -1, -1,NULL },
  { 5,true, 4, 4, 16, -1, -1,NULL },
  { 6,false, 5, 4, 20, -1, -1,NULL },
  { 7,false, 6, 4, 24, -1, -1,NULL },
  { 8,false, 7, 4, 28, -1, -1,NULL },
  { 9,true, 8, 4, 32, -1, -1,NULL },
  { 10,false, 9, 4, 36, -1, -1,NULL },
  { 11,false, 10, 4, 40, -1, -1,NULL },
  { 12,false, 11, 3, 44, -1, -1,NULL },
  { 13,false, 12, 4, 53, -1, -1,NULL },
  { 14,false, 13, 4, 57, -1, -1,NULL },
  { 15,false, 14, 3, 61, -1, -1,NULL },
  { 16,true, 15, 6, 47, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char srayvjmljc[64];


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

static const Column_element_CFL_t kgphmrlyfv[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&lycurkwlcr}, // 0 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&ibaphtbcff}, // 1 
    {supervisor_control_CFL,one_for_one_fn,(void *)&qsdhltfyfl}, // 2 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ojjnvgwxnu}, // 4 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lxguztfzeo_rom}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xbgjzayyea}, // 6 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 7 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xdegpsxsaq}, // 8 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xhyyxgfbdx_rom}, // 9 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&fjxchbaepg}, // 10 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 11 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&eptwgejhsg}, // 12 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bymzuazxmc_rom}, // 13 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rqupyvtojo}, // 14 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 15 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&luobpjztvb}, // 16 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&wwdlusdqlq}, // 17 
    {supervisor_control_CFL,one_for_one_fn,(void *)&wyjaebzyvt}, // 18 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 19 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hyaoslpusm}, // 20 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dekgrqtdli_rom}, // 21 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&fhmqoeyaia}, // 22 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 23 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&glfgustvfc}, // 24 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xgibhqzpaa_rom}, // 25 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&wcvpoqurjv}, // 26 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 27 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&teraydzqct}, // 28 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&hbstsgpgbx_rom}, // 29 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rwjzfnoodj}, // 30 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 31 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&rfqwrjlbhf}, // 32 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&ihvjehjgeo}, // 33 
    {supervisor_control_CFL,one_for_one_fn,(void *)&hcdmvrqlkg}, // 34 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 35 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&tvnhvrraxh}, // 36 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qvqjxmgiev_rom}, // 37 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ynsbpryhfp}, // 38 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 39 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&bgdfwixkjm}, // 40 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&otlyvrafxg_rom}, // 41 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&kphujvxdrq}, // 42 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 43 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&uqzmzdtgxn}, // 44 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fovskotpbz_rom}, // 45 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&lqslwyiozp}, // 46 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ulypykoncy}, // 47 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&rgqftumfev}, // 48 
    {supervisor_control_CFL,fn_column_control,(void *)&qnonoqzmqk}, // 49 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&tvmkezfdbf_rom}, // 50 
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&zwotpiguye}, // 51 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 52 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&snhdnjkisd}, // 53 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fjuszxcbwv_rom}, // 54 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&hyccpafmul}, // 55 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 56 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&dpfvytofwf}, // 57 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mhjqykraky_rom}, // 58 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ijuoapwcko}, // 59 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 60 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&xvcbktgpxp}, // 61 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&oogmypsydx_rom}, // 62 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&timxbgfhyl}, // 63 
};
Bitmap_CFL nqjazmmwky[0];
Registermap_CFL_t ecqugnfpkg[0];
Floatmap_CFL_t rslhioxfjf[0];
const Sm_control_ROM_CFL_t gqfzxvavyn[0];
Sm_control_RAM_CFL_t njqdmbjqrh[0];


static Time_control_CFL_t iqpctpzoyk;




static Engine_control_CFL_t fmkfemilnb;


/* remaining allocate heap size */

static unsigned vgmqitvhjd;


/* current heap pointer */

static char* ozkpghnwft;


/* heap block area */

static CS_MEMORY_CONTROL hlvxiuooiu;


    
    


const struct Handle_CFL_t jwzvhwhykw =
{

  .queue_number = 17,
  .queue_rom = ohwipiftqy,
  .queue_ram = yrpxsqtuij,

  .column_elements_flags =srayvjmljc,
  .column_elements_ROM = kgphmrlyfv,

  .watch_dog_struct = qkappzgvzy,
  .watch_dog_count  = otwcuzzrbl,
   
   
  .column_flags = iurxzunypp,
  .column_local_data = bfurpetqui,
  .column_state = uegptrqxyd,
  .number_of_columns = 16,
  .column_rom_data = kdfkbigdan,

  
  
  
  .time_control = &iqpctpzoyk,
  .engine_control =&fmkfemilnb,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &vgmqitvhjd,
  .current_heap_location = &ozkpghnwft,
  .private_heap   = &hlvxiuooiu,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  gqfzxvavyn,
  .sm_ram     = njqdmbjqrh,
  .number_of_bitmaps = 0,
  .bitmaps = nqjazmmwky,
  .number_of_registermaps = 0,
  .registermaps = ecqugnfpkg,
  .number_of_floatmaps = 0,
  .floatmaps = rslhioxfjf,
} ;

const Handle_CFL_t*  supervisor_handle(){
    return &jwzvhwhykw;
}
   

#ifdef __cplusplus
}
#endif

#endif
