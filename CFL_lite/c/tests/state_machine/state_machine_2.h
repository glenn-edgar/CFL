#ifndef __state_machine_2_H__
#define __state_machine_2_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t rcofvdhidu[6];
static Event_data_CFL_t qecegevttx[10];
static Event_data_CFL_t emhktgqtyq[10];
static Event_data_CFL_t zuzazxemwd[10];
static Event_data_CFL_t dmewuuphpa[10];
static Event_data_CFL_t tvdykmxcwy[10];
static Event_data_CFL_t iyyetprgcl[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t radkwfiafk[] = { 
     {  10, qecegevttx },
     {  10, emhktgqtyq },
     {  10, zuzazxemwd },
     {  10, dmewuuphpa },
     {  10, tvdykmxcwy },
     {  10, iyyetprgcl },
};
const char test_data_2[] = "test_data\n";
const Event_data_CFL_t uzuhymnzgc = { 101, false, NULL };
const Event_data_CFL_t zvhibqtzqm = { 102, false, NULL };
const Event_data_CFL_t uweqpptqoi = { 103, false, NULL };
const Event_data_CFL_t ewxzykfkkt = { 104, false, NULL };
const Event_data_CFL_t rrjwcdjceb = { 111, false, NULL };
const Event_data_CFL_t mpdvqixypf = { 112, false, NULL };
const Event_data_CFL_t ytsxdshhnx = { 113, false, NULL };

const char test_data_11[] = "state 1 debug message";
const char test_data_21[] = "state 2 debug message";
const char test_data_31[] = "state 3 debug message";
const char test_data_41[] = "state 4 debug message";
static const char *mzcdjxfmwx = "start column";

const unsigned short  pnxcvgexqj[] = {0};

enable_disable_sm_CFL_t ztrfurbqat = {1,pnxcvgexqj };
static const unsigned short wurrochefa[] = { 1};
const Enable_column_CFL_t aqnhwsaogl = { true, 1, wurrochefa };


unsigned  bfsrarnxly;
const While_time_control_ROM_CFL_t pkjnunwkbd = { 60000,&bfsrarnxly };



static While_control_RAM_CFL_t yawekghrwv_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dcqwcqunfy_rom = { 0 ,true, &pkjnunwkbd,&yawekghrwv_ram,null_function};

    
static const char *vfvxvcguzo = "terminating";
static const char *volkqjtibw = "event generator start";


unsigned  cxoounonhf;
const While_time_control_ROM_CFL_t qalspeufzz = { 2000,&cxoounonhf };



static While_control_RAM_CFL_t tqsnrgmpdo_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ebobpwnvxz_rom = { 0 ,true, &qalspeufzz,&tqsnrgmpdo_ram,null_function};

    
const sm_event_CFL_t zsszgcabdr = {0,&rrjwcdjceb};
const sm_event_CFL_t fmszhxwlnq = {0,&mpdvqixypf};
const sm_event_CFL_t bhnnwcwsea = {0,&ytsxdshhnx};
const sm_event_CFL_t booutwpvde = {0,&uzuhymnzgc};


unsigned  aebdcapale;
const While_time_control_ROM_CFL_t qtvlifhrmy = { 2000,&aebdcapale };



static While_control_RAM_CFL_t ceofzgvpaa_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t syelpryzbh_rom = { 0 ,true, &qtvlifhrmy,&ceofzgvpaa_ram,null_function};

    
const sm_event_CFL_t uyhrgggfzs = {0,&rrjwcdjceb};
const sm_event_CFL_t utbmlryrfw = {0,&mpdvqixypf};
const sm_event_CFL_t qbmavexzoo = {0,&ytsxdshhnx};
const sm_event_CFL_t ztouefacmn = {0,&zvhibqtzqm};


unsigned  lasixbjcfn;
const While_time_control_ROM_CFL_t vktkfslqff = { 2000,&lasixbjcfn };



static While_control_RAM_CFL_t wexqyyuouc_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yaealtonvq_rom = { 0 ,true, &vktkfslqff,&wexqyyuouc_ram,null_function};

    
const sm_event_CFL_t ykhuxtwuix = {0,&rrjwcdjceb};
const sm_event_CFL_t bgrxhqhvbz = {0,&mpdvqixypf};
const sm_event_CFL_t bjreousthe = {0,&ytsxdshhnx};
const sm_event_CFL_t kzcgznddey = {0,&uweqpptqoi};


unsigned  jwqeijeuho;
const While_time_control_ROM_CFL_t bvofqlpycc = { 2000,&jwqeijeuho };



static While_control_RAM_CFL_t wzqmryuykw_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t puvgauckgk_rom = { 0 ,true, &bvofqlpycc,&wzqmryuykw_ram,null_function};

    
const sm_event_CFL_t cbaphvrpxj = {0,&rrjwcdjceb};
const sm_event_CFL_t eulcsehakw = {0,&mpdvqixypf};
const sm_event_CFL_t sjvmxddhlo = {0,&ytsxdshhnx};
const sm_event_CFL_t hzjecdwxxw = {0,&ewxzykfkkt};
static const char *yvtgpotlxi = "state machine manager starting";
const change_sm_state_CFL_t mhrooolaaq = {0,0};
const unsigned short ljthbtqymt[] = {101};
const state_change_CFL_t yifrjkokoi = {0,0,1,ljthbtqymt};
const unsigned short cpafnwnbys[] = {102};
const state_change_CFL_t bwbirybtzk = {0,1,1,cpafnwnbys};
const unsigned short srxvherzgv[] = {103};
const state_change_CFL_t himvzqubhv = {0,2,1,srxvherzgv};
const unsigned short uvfftbokcd[] = {104};
const state_change_CFL_t utrckpquhh = {0,3,1,uvfftbokcd};
const redirect_CFL_t mjzwffatel = {0,NULL};
static const char *vmgyghztiu = "state 1 starting";
const SM_debug_CFL_t ykepcsyaic = {0,0,test_data_11};
static const char *wwpgqxpnhp = "state 2 starting";
const SM_debug_CFL_t yvhvxjrspj = {0,1,test_data_21};
static const char *nverilgloh = "state 3 starting";
const SM_debug_CFL_t kfyawucdyo = {0,2,test_data_31};
static const char *ndfdqqdkmm = "state 4 starting";
const SM_debug_CFL_t tsykswtpvx = {0,3,test_data_41};


//----------RAM data structures for columns ----

unsigned obvxdbijgd[7];
Watch_dog_struct_CFL_t * whronfkbgq[7];
unsigned char xhvwoxdrfe[7];
unsigned char pqymzosvje[7];
void* oshtxexicb[7];
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

static const Column_ROM_CFL_t cskifizagj[] = {
  { -1,true, 0, 6, 0, -1, -1 },
  { -1,false, 1, 22, 6, -1, -1 },
  { 1,false, 2, 8, 28, -1, -1 },
  { 2,false, 3, 3, 36, -1, -1 },
  { 3,false, 4, 3, 39, -1, -1 },
  { 4,false, 5, 3, 42, -1, -1 },
  { 5,false, 6, 3, 45, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char fudskbftcz[48];


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

static const Column_element_CFL_t xuqpnycruk[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzcdjxfmwx},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&ztrfurbqat},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&aqnhwsaogl},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dcqwcqunfy_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vfvxvcguzo},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&volkqjtibw},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ebobpwnvxz_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&zsszgcabdr},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&fmszhxwlnq},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bhnnwcwsea},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&booutwpvde},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&syelpryzbh_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&uyhrgggfzs},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&utbmlryrfw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&qbmavexzoo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ztouefacmn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yaealtonvq_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&ykhuxtwuix},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bgrxhqhvbz},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&bjreousthe},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&kzcgznddey},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&puvgauckgk_rom},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&cbaphvrpxj},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&eulcsehakw},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&sjvmxddhlo},
    {one_shot_handler_CFL,send_event_to_sm,(void *)&hzjecdwxxw},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yvtgpotlxi},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&mhrooolaaq},
    {state_change_CFL,NULL,(void *)&yifrjkokoi},
    {state_change_CFL,NULL,(void *)&bwbirybtzk},
    {state_change_CFL,NULL,(void *)&himvzqubhv},
    {state_change_CFL,NULL,(void *)&utrckpquhh},
    {redirect_event_CFL,true_constant_handler,(void *)&mjzwffatel},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vmgyghztiu},
    {SM_debug_CFL,true_constant_handler,(void *)&ykepcsyaic},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wwpgqxpnhp},
    {SM_debug_CFL,true_constant_handler,(void *)&yvhvxjrspj},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nverilgloh},
    {SM_debug_CFL,true_constant_handler,(void *)&kfyawucdyo},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ndfdqqdkmm},
    {SM_debug_CFL,true_constant_handler,(void *)&tsykswtpvx},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
Bitmap_CFL dcgzakcgjy[0];
short gfhpnweikb[4] = {2,3,4,5,};
short jtmeamgvns[4] = {3,4,5,6,};
const Sm_control_ROM_CFL_t ocojmclpnm[1] = {
{0,1,2,4,jtmeamgvns,gfhpnweikb,(void *)test_data_2},
}; 
Sm_control_RAM_CFL_t egwrlodrxa[1];


static Time_control_CFL_t krpvcbxtxv;




static Engine_control_CFL_t irkrtkwudb;


/* remaining allocate heap size */

static unsigned mooikhyqbd;


/* current heap pointer */

static char* yaizvpvexa;


/* heap block area */

static CS_MEMORY_CONTROL tbuagtctmf;


    
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


const struct Handle_CFL_t odwgvqlbfn =
{

  .queue_number = 6,
  .queue_rom = radkwfiafk,
  .queue_ram = rcofvdhidu,

  .column_elements_flags =fudskbftcz,
  .column_elements_ROM = xuqpnycruk,

  .watch_dog_struct = whronfkbgq,
  .watch_dog_count  = obvxdbijgd,
   
   
  .column_flags = xhvwoxdrfe,
  .column_local_data = oshtxexicb,
  .column_state = pqymzosvje,
  .number_of_columns = 7,
  .column_rom_data = cskifizagj,

  
  
  
  .time_control = &krpvcbxtxv,
  .engine_control =&irkrtkwudb,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &mooikhyqbd,
  .current_heap_location = &yaizvpvexa,
  .private_heap   = &tbuagtctmf,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  ocojmclpnm,
   .sm_ram     = egwrlodrxa,
   .number_of_bitmaps = 0,
    .bitmaps = dcgzakcgjy,
} ;


const Handle_CFL_t*  state_machine_2_handle(){
    return &odwgvqlbfn;
}
   

#ifdef __cplusplus
}
#endif

#endif
