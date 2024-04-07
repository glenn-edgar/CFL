#ifndef __state_machine_3_H__
#define __state_machine_3_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"
#include "CFL_column_element_state_utilities.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t qqmiunokkb[8];
static Event_data_CFL_t finjezvysm[7];
static Event_data_CFL_t esyngoijci[0];
static Event_data_CFL_t gasptmeoar[0];
static Event_data_CFL_t stxkmeohch[8];
static Event_data_CFL_t zdexskcpzd[0];
static Event_data_CFL_t yhwgvtgely[0];
static Event_data_CFL_t tkbizjevzk[0];
static Event_data_CFL_t mtdkzqrbzz[0];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t zokqocgqwn[] = { 
     {  7, finjezvysm },
     {  0, esyngoijci },
     {  0, gasptmeoar },
     {  8, stxkmeohch },
     {  0, zdexskcpzd },
     {  0, yhwgvtgely },
     {  0, tkbizjevzk },
     {  0, mtdkzqrbzz },
};


//----------RAM data structures for rpc queues ----

static RPC_Packet_control_RAM_CFL_t lamqdbknge[0];


//------  ROM data structures for rpc queues ----

static const RPC_Packet_control_ROM_CFL_t  llnqajbkzx[] = { 
};
const char test_data_2b[] = "test_data\n";
const Event_data_CFL_t ccyozyobot = { 101, false, NULL };
const Event_data_CFL_t aoqybquigx = { 102, false, NULL };
const Event_data_CFL_t myvcuqoyvh = { 103, false, NULL };
const Event_data_CFL_t jvjwmmzpqr = { 104, false, NULL };
const Event_data_CFL_t tdvhshxwdq = { 111, false, NULL };
const Event_data_CFL_t wffxaypxgu = { 112, false, NULL };
const Event_data_CFL_t vycvceccch = { 113, false, NULL };
const Event_data_CFL_t mddagmcztr = { 114, false, NULL };

static const char test_data_11a[] = "state 1 debug message";
static const char test_data_21a[] = "state 2 debug message";
static const char test_data_31a[] = "state 3 debug message";
static const char test_data_41a[] = "state 4 debug message";



const Feed_events_test_data_t feed_test_data_1a = {
    .debug_message = "debug message for case construct"
};
const Feed_events_test_data_t feed_test_data_2a= {
    .debug_message = "debug message for feed events"
};
static const Log_message_CFL_t ruaoizgcbk = { "start column", false, NULL };

const unsigned short  zhqwsextai[] = {0};

enable_disable_sm_CFL_t fbicneuuof = {1,zhqwsextai };
static const unsigned short dgzndwjzrd[] = { 1};
const Enable_column_CFL_t ynykciclrj = { true, 1, dgzndwjzrd };


unsigned  bdvbuexfgu;
const While_time_control_ROM_CFL_t hewjzzjqmo = { 24000,&bdvbuexfgu };



static While_control_RAM_CFL_t nwtslkamls_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ngelcghtni_rom = { 0 ,true, (void*)&hewjzzjqmo,&nwtslkamls_ram,null_function};

    
static const Log_message_CFL_t orcuunkvjv = { "terminating", false, NULL };
static const Log_message_CFL_t kuulfkqztb = { "event generator start", false, NULL };


unsigned  geecsokkin;
const While_time_control_ROM_CFL_t vlddtjbvky = { 2000,&geecsokkin };



static While_control_RAM_CFL_t fzwckxvnue_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t chqzuleerz_rom = { 0 ,true, (void*)&vlddtjbvky,&fzwckxvnue_ram,null_function};

    
const sm_event_CFL_t cvcnnlyqji = {0,&tdvhshxwdq};
const sm_event_CFL_t pyrrvtdgpo = {0,&wffxaypxgu};
const sm_event_CFL_t wsrdocsttd = {0,&vycvceccch};
const sm_event_CFL_t xlrweawvbz = {0,&mddagmcztr};
const sm_event_CFL_t jknxtosyfu = {0,&ccyozyobot};


unsigned  fhtgbgrweh;
const While_time_control_ROM_CFL_t osrjjbghnz = { 2000,&fhtgbgrweh };



static While_control_RAM_CFL_t hwasssscqu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t iwxqwiguqv_rom = { 0 ,true, (void*)&osrjjbghnz,&hwasssscqu_ram,null_function};

    
const sm_event_CFL_t djocjtqhss = {0,&tdvhshxwdq};
const sm_event_CFL_t llcgnewkyq = {0,&wffxaypxgu};
const sm_event_CFL_t yystwvphwf = {0,&vycvceccch};
const sm_event_CFL_t tgzpxyroxg = {0,&mddagmcztr};
const sm_event_CFL_t orlyqmiciy = {0,&aoqybquigx};


unsigned  ppjuwfklds;
const While_time_control_ROM_CFL_t zxjpgrlpna = { 2000,&ppjuwfklds };



static While_control_RAM_CFL_t vuesuuezfx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xfzdacnmvf_rom = { 0 ,true, (void*)&zxjpgrlpna,&vuesuuezfx_ram,null_function};

    
const sm_event_CFL_t eixzytfsvj = {0,&tdvhshxwdq};
const sm_event_CFL_t iujrtrdjkt = {0,&wffxaypxgu};
const sm_event_CFL_t uhfrhnmszv = {0,&vycvceccch};
const sm_event_CFL_t xltrbivhke = {0,&mddagmcztr};
const sm_event_CFL_t ygmcpqksna = {0,&myvcuqoyvh};
const sm_event_CFL_t mbeduujxkv = {0,&tdvhshxwdq};
const sm_event_CFL_t uljkndooum = {0,&wffxaypxgu};


unsigned  pmciburglw;
const While_time_control_ROM_CFL_t jfwutttpug = { 2000,&pmciburglw };



static While_control_RAM_CFL_t zvcqvzkipi_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t elyqzoqwkn_rom = { 0 ,true, (void*)&jfwutttpug,&zvcqvzkipi_ram,null_function};

    
const sm_event_CFL_t oqwnyequwt = {0,&tdvhshxwdq};
const sm_event_CFL_t denqmsvtzw = {0,&wffxaypxgu};
const sm_event_CFL_t ffhepxrsmx = {0,&vycvceccch};
const sm_event_CFL_t qavnbtbzfb = {0,&mddagmcztr};
const sm_event_CFL_t luolmqetxa = {0,&jvjwmmzpqr};
const sm_event_CFL_t npfcrpqymu = {0,&tdvhshxwdq};
const sm_event_CFL_t bkrzctwmqo = {0,&wffxaypxgu};
const Feed_events_test_data_t feed_test_data_a = {
    .debug_message = "feed event 2 debug message"
};
static const Log_message_CFL_t tsdadwwdkm = { "state machine manager starting", false, NULL };
const ASM_change_state_machine_CFL_t rvrvqmpkip = {0,3 };
SM_case_change_CFL_t cjsricwmah = {0,(void *)&feed_test_data_1a};
const SM_feed_state_CFL_t zobfuuycrc = {0, (void *)&feed_test_data_2a };
const SM_log_CFL_t wxhzodptwa = {0, 1, "state 1 starting","state_1 is exiting"};
const SM_debug_CFL_t njsaiijdil = {0,1,test_data_11a};
static const Log_message_CFL_t fbipusczup = { "state 2 starting", false, NULL };
const SM_debug_CFL_t udbihzpgcj = {0,2,test_data_21a};
static const Log_message_CFL_t iyonlcysfd = { "state 3 starting", false, NULL };
const SM_debug_CFL_t rhjihyomol = {0,3,test_data_31a};
static const Log_message_CFL_t qhssntnyvs = { "state 4 starting", false, NULL };
const sm_sync_events_t hberjvbexc = {3,120};
const SM_debug_CFL_t cphzwmdwqc = {0,4,test_data_41a};


//----------RAM data structures for columns ----

unsigned gdflhqwsqe[7];
Watch_dog_struct_CFL_t * jdmwndvrul[7];
unsigned char dktzbhahke[7];
unsigned char qzwkbdajzr[7];
void* jcujhstnms[7];


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t akltuxjzqr[] = {
  { 1,true, 0, 6, 0, -1, -1,NULL },
  { 2,false, 1, 30, 6, -1, -1,NULL },
  { 3,false, 2, 5, 36, -1, -1,NULL },
  { 4,false, 3, 3, 41, -1, -1,NULL },
  { 5,false, 4, 3, 44, -1, -1,NULL },
  { 6,false, 5, 3, 47, -1, -1,NULL },
  { 7,false, 6, 4, 50, -1, -1,NULL },
};


//----------Column elements RAM structures----



static unsigned char zxmqdnbzff[54];


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

static const Column_element_CFL_t nciiewguxd[] = {
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&ruaoizgcbk}, // 0 
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&fbicneuuof}, // 1 
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&ynykciclrj}, // 2 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ngelcghtni_rom}, // 3 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&orcuunkvjv}, // 4 
    {return_condition_code_CFL,NULL,(void *)terminate_buffer}, // 5 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&kuulfkqztb}, // 6 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&chqzuleerz_rom}, // 7 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cvcnnlyqji}, // 8 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&pyrrvtdgpo}, // 9 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&wsrdocsttd}, // 10 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xlrweawvbz}, // 11 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&jknxtosyfu}, // 12 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&iwxqwiguqv_rom}, // 13 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&djocjtqhss}, // 14 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&llcgnewkyq}, // 15 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&yystwvphwf}, // 16 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&tgzpxyroxg}, // 17 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&orlyqmiciy}, // 18 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xfzdacnmvf_rom}, // 19 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&eixzytfsvj}, // 20 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&iujrtrdjkt}, // 21 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&uhfrhnmszv}, // 22 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&xltrbivhke}, // 23 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ygmcpqksna}, // 24 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&mbeduujxkv}, // 25 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&uljkndooum}, // 26 
    {while_handler_CFL,wait_time_delay_CFL,(void *)&elyqzoqwkn_rom}, // 27 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&oqwnyequwt}, // 28 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&denqmsvtzw}, // 29 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ffhepxrsmx}, // 30 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qavnbtbzfb}, // 31 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&luolmqetxa}, // 32 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&npfcrpqymu}, // 33 
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bkrzctwmqo}, // 34 
    {return_condition_code_CFL,NULL,(void *)reset_buffer}, // 35 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&tsdadwwdkm}, // 36 
    {one_shot_handler_CFL,Asm_change_state_machine_CFL,(void *)&rvrvqmpkip}, // 37 
    {SM_case_change_CFL,case_change_test,(void *)&cjsricwmah}, // 38 
    {sm_feed_state_CFL,feed_events_test_a,(void *)&zobfuuycrc}, // 39 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 40 
    {bidirectional_one_shot_handler_CFL,SM_log_function_CFL,(void *)&wxhzodptwa}, // 41 
    {SM_debug_CFL,NULL,(void *)&njsaiijdil}, // 42 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 43 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&fbipusczup}, // 44 
    {SM_debug_CFL,NULL,(void *)&udbihzpgcj}, // 45 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 46 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&iyonlcysfd}, // 47 
    {SM_debug_CFL,NULL,(void *)&rhjihyomol}, // 48 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 49 
    {bidirectional_one_shot_handler_CFL,log_message_CFL,(void *)&qhssntnyvs}, // 50 
    {sm_sync_events_CFL,NULL,(void *)&hberjvbexc}, // 51 
    {SM_debug_CFL,NULL,(void *)&cphzwmdwqc}, // 52 
    {return_condition_code_CFL,NULL,(void *)halt_buffer}, // 53 
};
Bitmap_CFL uouzwfsppx[0];
Registermap_CFL_t odkedaciqv[0];
Floatmap_CFL_t mwnvfhnalp[0];
const uint32_t cxzdvdaidb[] = {3918956230,3902178611,3885400992,4002844325};
const uint16_t whzamykutk[] = {3,4,5,6};
const Sm_control_ROM_CFL_t ihtzzlseso[1] = {
{0,1468586590,2,4,cxzdvdaidb,whzamykutk,(void *)&feed_test_data_a},
}; 
Sm_control_RAM_CFL_t knbdmyuoxb[1];


static Time_control_CFL_t chhncsgruy;




static Engine_control_CFL_t qslktqblvl;


/* remaining allocate heap size */

static unsigned tepxksewlc;


/* current heap pointer */

static char* wpormjwwrt;


/* heap block area */

static CS_MEMORY_CONTROL rogfpgvdvk;


    
    


const struct Handle_CFL_t pmtawghiro =
{

  .queue_number = 8,
  .queue_rom = zokqocgqwn,
  .queue_ram = qqmiunokkb,

  .column_elements_flags =zxmqdnbzff,
  .column_elements_ROM = nciiewguxd,

  .watch_dog_struct = jdmwndvrul,
  .watch_dog_count  = gdflhqwsqe,
   
   
  .column_flags = dktzbhahke,
  .column_local_data = jcujhstnms,
  .column_state = qzwkbdajzr,
  .number_of_columns = 7,
  .column_rom_data = akltuxjzqr,

  
  
  
  .time_control = &chhncsgruy,
  .engine_control =&qslktqblvl,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &tepxksewlc,
  .current_heap_location = &wpormjwwrt,
  .private_heap   = &rogfpgvdvk,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
  .sm_rom     =  ihtzzlseso,
  .sm_ram     = knbdmyuoxb,
  .number_of_bitmaps = 0,
  .bitmaps = uouzwfsppx,
  .number_of_registermaps = 0,
  .registermaps = odkedaciqv,
  .number_of_floatmaps = 0,
  .floatmaps = mwnvfhnalp,
   .rpc_queue_number = 0,
  .rpc_queue_ram = lamqdbknge,
  .rpc_queue_rom = llnqajbkzx
} ;

const Handle_CFL_t*  state_machine_3_handle(){
    return &pmtawghiro;
}
   

#ifdef __cplusplus
}
#endif

#endif
