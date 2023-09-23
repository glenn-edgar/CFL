#ifndef __state_machine_4_H__
#define __state_machine_4_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t oogalpscyq[6];
static Event_data_CFL_t msaddobvlq[10];
static Event_data_CFL_t wqotrqvvyr[10];
static Event_data_CFL_t jsnypbaczf[10];
static Event_data_CFL_t csbqkokqto[10];
static Event_data_CFL_t pwedqkotdo[10];
static Event_data_CFL_t ynqafdgwvb[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t dskcrawyuq[] = { 
     {  10, msaddobvlq },
     {  10, wqotrqvvyr },
     {  10, jsnypbaczf },
     {  10, csbqkokqto },
     {  10, pwedqkotdo },
     {  10, ynqafdgwvb },
};
const Event_data_CFL_t xtnrvysytr = { 101, false, NULL };
const Event_data_CFL_t otaecxyejn = { 102, false, NULL };
const Event_data_CFL_t taatqbxlsu = { 103, false, NULL };
const Event_data_CFL_t umdndxllij = { 104, false, NULL };
const Event_data_CFL_t rghipgudur = { 111, false, NULL };
const Event_data_CFL_t imblalkkrz = { 112, false, NULL };
const Event_data_CFL_t nngmtaipfb = { 113, false, NULL };

const char test_data_13[] = "state 1 debug message";
const char test_data_23[] = "state 2 debug message";
const char test_data_33[] = "state 3 debug message";
const char test_data_43[] = "state 4 debug message";
static const char *inhhszsyyd = "start column";

const unsigned short  ihrdowaepy[] = {0};

enable_disable_sm_CFL_t aofhfaigft = {1,ihrdowaepy };
static const unsigned short dkmdpwlwob[] = { 1};
const Enable_column_CFL_t gqnjxzpiun = { true, 1, dkmdpwlwob };


unsigned  lpoekcvqjy;
const While_time_control_ROM_CFL_t gnqrexxueg = { 60000,&lpoekcvqjy };



static While_control_RAM_CFL_t fgkxgmrjil_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lsqdwacnaw_rom = { 0 ,true, &gnqrexxueg,&fgkxgmrjil_ram,null_function};

    
static const char *wgsbkqfgvm = "terminating";
static const char *zrffodeouo = "event generator start";


unsigned  gdaefugnpk;
const While_time_control_ROM_CFL_t ysbiaidylm = { 2000,&gdaefugnpk };



static While_control_RAM_CFL_t tvgtmhengt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t mhshmxaxiz_rom = { 0 ,true, &ysbiaidylm,&tvgtmhengt_ram,null_function};

    
const sm_event_CFL_t gttbgnibfw = {0,&otaecxyejn};
const sm_event_CFL_t auelvxtamp = {0,&rghipgudur};
const sm_event_CFL_t gsknzcdnqb = {0,&imblalkkrz};
const sm_event_CFL_t qihemvmzum = {0,&nngmtaipfb};


unsigned  qsohmjqpba;
const While_time_control_ROM_CFL_t zhxugdbdmb = { 50,&qsohmjqpba };



static While_control_RAM_CFL_t mdrrppcnpu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t whpucapvdc_rom = { 0 ,true, &zhxugdbdmb,&mdrrppcnpu_ram,null_function};

    
const sm_event_CFL_t gnnhmpexlz = {0,&rghipgudur};
const sm_event_CFL_t cwpnlhngju = {0,&imblalkkrz};
const sm_event_CFL_t tpoxcbijxf = {0,&nngmtaipfb};


unsigned  ccakxaeijr;
const While_time_control_ROM_CFL_t kusopkbmlh = { 2000,&ccakxaeijr };



static While_control_RAM_CFL_t vlarjppdan_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rglvxslrbz_rom = { 0 ,true, &kusopkbmlh,&vlarjppdan_ram,null_function};

    
const sm_event_CFL_t ebovhgatie = {0,&taatqbxlsu};
const sm_event_CFL_t iqfbqvlqws = {0,&rghipgudur};
const sm_event_CFL_t buhwrzdcoz = {0,&imblalkkrz};
const sm_event_CFL_t fcvdoeeedg = {0,&nngmtaipfb};


unsigned  pbqvfqfrfu;
const While_time_control_ROM_CFL_t msqohnjsbv = { 50,&pbqvfqfrfu };



static While_control_RAM_CFL_t pwochjsoju_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ezaulbkino_rom = { 0 ,true, &msqohnjsbv,&pwochjsoju_ram,null_function};

    
const sm_event_CFL_t esmqaqdyji = {0,&rghipgudur};
const sm_event_CFL_t hfoguuaahv = {0,&imblalkkrz};
const sm_event_CFL_t nlbqgynqin = {0,&nngmtaipfb};


unsigned  iwuzssyhja;
const While_time_control_ROM_CFL_t joxkgboifs = { 2000,&iwuzssyhja };



static While_control_RAM_CFL_t owlamecyhi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t fyimjcahyf_rom = { 0 ,true, &joxkgboifs,&owlamecyhi_ram,null_function};

    
const sm_event_CFL_t ymlmueibmp = {0,&umdndxllij};
const sm_event_CFL_t pbdtvhuhrd = {0,&rghipgudur};
const sm_event_CFL_t lufgqoxerv = {0,&imblalkkrz};
const sm_event_CFL_t bevunvwnbf = {0,&nngmtaipfb};


unsigned  scoeontjxo;
const While_time_control_ROM_CFL_t feuxbdzkaa = { 50,&scoeontjxo };



static While_control_RAM_CFL_t dxaorgqqek_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t qvrqtcbknr_rom = { 0 ,true, &feuxbdzkaa,&dxaorgqqek_ram,null_function};

    
const sm_event_CFL_t ullnuostqo = {0,&rghipgudur};
const sm_event_CFL_t obepqapygo = {0,&imblalkkrz};
const sm_event_CFL_t iixivmfnfe = {0,&nngmtaipfb};


unsigned  rxcalcagyk;
const While_time_control_ROM_CFL_t yakrmuhdco = { 2000,&rxcalcagyk };



static While_control_RAM_CFL_t wyjcauicpo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kqybyudwkl_rom = { 0 ,true, &yakrmuhdco,&wyjcauicpo_ram,null_function};

    
const sm_event_CFL_t ulhmezbtrx = {0,&xtnrvysytr};
const sm_event_CFL_t etaripttjk = {0,&rghipgudur};
const sm_event_CFL_t zqckaqedxc = {0,&imblalkkrz};
const sm_event_CFL_t snpnodynng = {0,&nngmtaipfb};


unsigned  jyqxvakbvu;
const While_time_control_ROM_CFL_t ufrmijunnc = { 50,&jyqxvakbvu };



static While_control_RAM_CFL_t jbrorytxii_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xgktaidzzg_rom = { 0 ,true, &ufrmijunnc,&jbrorytxii_ram,null_function};

    
const sm_event_CFL_t uvryilzkgd = {0,&rghipgudur};
const sm_event_CFL_t pgimycaqyg = {0,&imblalkkrz};
const sm_event_CFL_t ohgzwehihy = {0,&nngmtaipfb};
static const char *wqukiakbag = "state machine manager starting";
const change_sm_state_CFL_t yaayqlquuj = {0,0};
const unsigned short qzivrvajzi[] = {101};
const state_change_CFL_t yzbgyiqfmq = {0,0,1,qzivrvajzi};
const unsigned short nlznughbev[] = {102};
const state_change_CFL_t eudbakwpwi = {0,1,1,nlznughbev};
const unsigned short jhhfxqkkyr[] = {103};
const state_change_CFL_t uzwlzcvkaf = {0,2,1,jhhfxqkkyr};
const unsigned short aectjjqcxa[] = {104};
const state_change_CFL_t wirbnkcpao = {0,3,1,aectjjqcxa};
const redirect_CFL_t iklkbdtcqr = {0,NULL};
static const char *aamxltfvxz = "state 1 starting";
const sync_events_t qzixqytuqo = {0,201};
const SM_debug_CFL_t qqxxvherju = {0,0,test_data_13};
static const char *mflfpbyxmu = "state 2 starting";
const sync_events_t erhoaemcph = {0,202};
const SM_debug_CFL_t lozqzaanvb = {0,1,test_data_23};
static const char *mciconugpz = "state 3 starting";
const sync_events_t zcqjyyhcwv = {0,203};
const SM_debug_CFL_t iscxwxcmyc = {0,2,test_data_33};
static const char *vdzshlijur = "state 4 starting";
const sync_events_t jzdtxgsvhz = {0,204};
const SM_debug_CFL_t pstpzigixj = {0,3,test_data_43};


//----------RAM data structures for columns ----

unsigned eqgvujtqzk[7];
Watch_dog_struct_CFL_t * ykvjsxrvyg[7];
unsigned char townpmqgro[7];
unsigned char dicexqaehe[7];
void* awgofpsobv[7];
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

static const Column_ROM_CFL_t arszjxwrba[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 38, 6, -1, -1 },
  { 1,false, 2, 8, 44, -1, -1 },
  { 2,false, 3, 4, 52, -1, -1 },
  { 3,false, 4, 4, 56, -1, -1 },
  { 4,false, 5, 4, 60, -1, -1 },
  { 5,false, 6, 4, 64, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char tadezkluec[68];


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

static const Column_element_CFL_t fzfiajquru[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&inhhszsyyd},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&aofhfaigft},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&gqnjxzpiun},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lsqdwacnaw_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wgsbkqfgvm},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zrffodeouo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&mhshmxaxiz_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gttbgnibfw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&auelvxtamp},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gsknzcdnqb},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qihemvmzum},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&whpucapvdc_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&gnnhmpexlz},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cwpnlhngju},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tpoxcbijxf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rglvxslrbz_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ebovhgatie},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&iqfbqvlqws},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&buhwrzdcoz},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&fcvdoeeedg},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ezaulbkino_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&esmqaqdyji},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hfoguuaahv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&nlbqgynqin},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&fyimjcahyf_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ymlmueibmp},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pbdtvhuhrd},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&lufgqoxerv},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bevunvwnbf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&qvrqtcbknr_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ullnuostqo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&obepqapygo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&iixivmfnfe},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kqybyudwkl_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ulhmezbtrx},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&etaripttjk},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&zqckaqedxc},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&snpnodynng},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xgktaidzzg_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&uvryilzkgd},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pgimycaqyg},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ohgzwehihy},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wqukiakbag},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&yaayqlquuj},
    {state_change_CFL,NULL,(void *)&yzbgyiqfmq},
    {state_change_CFL,NULL,(void *)&eudbakwpwi},
    {state_change_CFL,NULL,(void *)&uzwlzcvkaf},
    {state_change_CFL,NULL,(void *)&wirbnkcpao},
    {redirect_event_CFL,true_constant_handler,(void *)&iklkbdtcqr},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aamxltfvxz},
    {sync_events_CFL,NULL,(void *)&qzixqytuqo},
    {SM_debug_CFL,true_constant_handler,(void *)&qqxxvherju},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mflfpbyxmu},
    {sync_events_CFL,NULL,(void *)&erhoaemcph},
    {SM_debug_CFL,true_constant_handler,(void *)&lozqzaanvb},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mciconugpz},
    {sync_events_CFL,NULL,(void *)&zcqjyyhcwv},
    {SM_debug_CFL,true_constant_handler,(void *)&iscxwxcmyc},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vdzshlijur},
    {sync_events_CFL,NULL,(void *)&jzdtxgsvhz},
    {SM_debug_CFL,true_constant_handler,(void *)&pstpzigixj},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
Bitmap_CFL wiwbyanffg[0];
short rqwseqtbea[4] = {2,3,4,5,};
short dovtjkdzjo[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t xyxngbzxwd[1] = {
{0,1,2,4,dovtjkdzjo,rqwseqtbea,NULL},
}; 
Sm_control_RAM_CFL_t btjxpsjdrs[1];


static Time_control_CFL_t kdyeaxvizk;




static Engine_control_CFL_t vvaqhmlbbw;


/* remaining allocate heap size */

static unsigned ywntcjqasg;


/* current heap pointer */

static char* gohtncshup;


/* heap block area */

static CS_MEMORY_CONTROL tmnqxrstrv;


    
    /*
    --------------------------- Handle definition ------------------------------
   
    typedef struct Handle_CFL_t
    {
      const unsigned queue_number;
      const Event_control_ROM_CFL_t *queue_rom;
      Event_control_RAM_CFL_t *queue_ram;
      
    
      unsigned char *column_elements_flags;
      const Column_element_CFL_t *column_elements_ROM;
    
      unsigned char *column_flags;
      void **column_local_data;
      unsigned char *column_state;
      const unsigned short number_of_columns;
      const Column_ROM_CFL_t *column_rom_data;
    
      
      Watch_dog_struct_CFL_t **watch_dog_struct;
      unsigned *watch_dog_count;
     
      
      Time_control_CFL_t *time_control;
      Engine_control_CFL_t *engine_control;
      Debug_out_CFL_t debug_function;
      private_heap_malloc_fn malloc;
      private_heap_free_fn free;
      allocate_once_fn allocate_once;
      char **master_heap_starting_location; 
      const unsigned master_heap_size;             
      unsigned *remaining_heap_size;  // set by c runtime
      char **current_heap_location;  // set by c runtime
      CS_MEMORY_CONTROL *private_heap;      
      
      unsigned private_heap_size;
      unsigned number_of_sm;
      Sm_control_ROM_CFL_t *sm_rom;
      Sm_control_RAM_CFL_t *sm_ram;
    
    
    } Handle_CFL_t;

    
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


const struct Handle_CFL_t cagdtblnhn =
{

  .queue_number = 6,
  .queue_rom = dskcrawyuq,
  .queue_ram = oogalpscyq,

  .column_elements_flags =tadezkluec,
  .column_elements_ROM = fzfiajquru,

  .watch_dog_struct = ykvjsxrvyg,
  .watch_dog_count  = eqgvujtqzk,
   
   
  .column_flags = townpmqgro,
  .column_local_data = awgofpsobv,
  .column_state = dicexqaehe,
  .number_of_columns = 7,
  .column_rom_data = arszjxwrba,

  
  
  
  .time_control = &kdyeaxvizk,
  .engine_control =&vvaqhmlbbw,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &ywntcjqasg,
  .current_heap_location = &gohtncshup,
  .private_heap   = &tmnqxrstrv,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  xyxngbzxwd,
   .sm_ram     = btjxpsjdrs,
   .number_of_bitmaps = 0,
    .bitmaps = wiwbyanffg,
} ;


const Handle_CFL_t*  state_machine_4_handle(){
    return &cagdtblnhn;
}
   

#ifdef __cplusplus
}
#endif

#endif
