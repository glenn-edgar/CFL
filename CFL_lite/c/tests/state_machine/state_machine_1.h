#ifndef __state_machine_1_H__
#define __state_machine_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


const char test_data[] = "test_data\n";
#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t fijctsvtdh[6];
static Event_data_CFL_t yvvxzgjvnm[10];
static Event_data_CFL_t nqkklgtgeu[10];
static Event_data_CFL_t uvdpwfvbwb[10];
static Event_data_CFL_t cdmqenyhky[10];
static Event_data_CFL_t czukbtuulf[10];
static Event_data_CFL_t ctpibolzmi[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t beflbhpbea[] = { 
     {  10, yvvxzgjvnm },
     {  10, nqkklgtgeu },
     {  10, uvdpwfvbwb },
     {  10, cdmqenyhky },
     {  10, czukbtuulf },
     {  10, ctpibolzmi },
};
static const char *xslbvqhqjp = "start column";

const unsigned short  unqgoyfczr[] = {0};

enable_disable_sm_CFL_t wcpboaujxj = {1,unqgoyfczr };


unsigned  xhcwtewgsc;
const While_time_control_ROM_CFL_t beddhjvzjz = { 20000,&xhcwtewgsc };



static While_control_RAM_CFL_t xhszncfidr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t yptfjjkkuo_rom = { 0 ,true, &beddhjvzjz,&xhszncfidr_ram,null_function};

    
static const char *ijyymwrshj = "terminating";
static const char *gtirobscju = "state machine manager starting";


unsigned  gcreydofwo;
const While_time_control_ROM_CFL_t rgvvkmqjdq = { 2000,&gcreydofwo };



static While_control_RAM_CFL_t paeddllxfh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ixxfphdaet_rom = { 0 ,true, &rgvvkmqjdq,&paeddllxfh_ram,null_function};

    
const change_sm_state_CFL_t egghfmpiug = {0,0};
static const char *xbrbuvmorr = "this message should not be printed";
static const char *okflptjnup = "state 1 starting";


unsigned  gaxxnwfxyi;
const While_time_control_ROM_CFL_t gtojlmlptp = { 2000,&gaxxnwfxyi };



static While_control_RAM_CFL_t bgaeiadffl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t evgecjxeck_rom = { 0 ,true, &gtojlmlptp,&bgaeiadffl_ram,null_function};

    
const change_sm_state_CFL_t tsiuzzabjc = {0,1};
static const char *lxjgwokcic = "this message should not be printed";
static const char *vyypyrugua = "state 2 starting";


unsigned  swbjwvmvls;
const While_time_control_ROM_CFL_t kjqrbfkwyb = { 2000,&swbjwvmvls };



static While_control_RAM_CFL_t yygditoljt_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t gilsdfduee_rom = { 0 ,true, &kjqrbfkwyb,&yygditoljt_ram,null_function};

    
const change_sm_state_CFL_t pwuewazdey = {0,2};
static const char *xrgwaenhkj = "this message should not be printed";
static const char *mexuzcccfm = "state 3 starting";


unsigned  araerzmcwv;
const While_time_control_ROM_CFL_t nswkwsqxtn = { 2000,&araerzmcwv };



static While_control_RAM_CFL_t inphqjzetl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t dqbsjangma_rom = { 0 ,true, &nswkwsqxtn,&inphqjzetl_ram,null_function};

    
const change_sm_state_CFL_t odhrphwrjc = {0,3};
static const char *ldjmntunmg = "this message should not be printed";
static const char *nlrfcaidut = "state 4 starting";


unsigned  psyhwrojxz;
const While_time_control_ROM_CFL_t wmpcnekdof = { 2000,&psyhwrojxz };



static While_control_RAM_CFL_t kzdiopvdzn_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t sohphjpcpg_rom = { 0 ,true, &wmpcnekdof,&kzdiopvdzn_ram,null_function};

    
const change_sm_state_CFL_t mvveiofcta = {0,0};
static const char *vhihjuyfuc = "this message should not be printed";


//----------RAM data structures for columns ----

unsigned kayeevmous[6];
Watch_dog_struct_CFL_t * beevtoumpc[6];
unsigned char pgzywikmul[6];
unsigned char vmohhhkiut[6];
void* jrgjgajshk[6];
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

static const Column_ROM_CFL_t pilwrqwhtj[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { 1,false, 1, 5, 5, -1, -1 },
  { 2,false, 2, 5, 10, -1, -1 },
  { 3,false, 3, 5, 15, -1, -1 },
  { 4,false, 4, 5, 20, -1, -1 },
  { 5,false, 5, 5, 25, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char fsaxqwdrxy[30];


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

static const Column_element_CFL_t kmecourlak[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&xslbvqhqjp},
    {bidirectional_one_shot_handler_CFL,enable_disable_sm_CFL,(void *)&wcpboaujxj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&yptfjjkkuo_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ijyymwrshj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gtirobscju},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ixxfphdaet_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&egghfmpiug},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xbrbuvmorr},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&okflptjnup},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&evgecjxeck_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&tsiuzzabjc},
    {one_shot_handler_CFL,log_message_CFL,(void *)&lxjgwokcic},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vyypyrugua},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&gilsdfduee_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&pwuewazdey},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xrgwaenhkj},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mexuzcccfm},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&dqbsjangma_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&odhrphwrjc},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ldjmntunmg},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nlrfcaidut},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&sohphjpcpg_rom},
    {one_shot_handler_CFL,change_sm_state_CFL,(void *)&mvveiofcta},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vhihjuyfuc},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
short vmtpxiwqrs[4] = {2,3,4,5,};
short srunibajee[4] = {2,3,4,5,};
const Sm_control_ROM_CFL_t homkvcuwia[1] = {
{0,1,1,4,srunibajee,vmtpxiwqrs,(void *)test_data},
}; 
Sm_control_RAM_CFL_t vehsiaqphf[1];


static Time_control_CFL_t vwakkthcxh;




static Engine_control_CFL_t ywfueowmhj;


/* remaining allocate heap size */

static unsigned vfqvtsibhl;


/* current heap pointer */

static char* gsdxkytrms;


/* heap block area */

static CS_MEMORY_CONTROL jvhendlbzx;


    
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


const struct Handle_CFL_t sdhpxpqfky =
{

  .queue_number = 6,
  .queue_rom = beflbhpbea,
  .queue_ram = fijctsvtdh,

  .column_elements_flags =fsaxqwdrxy,
  .column_elements_ROM = kmecourlak,

  .watch_dog_struct = beevtoumpc,
  .watch_dog_count  = kayeevmous,
   
   
  .column_flags = pgzywikmul,
  .column_local_data = jrgjgajshk,
  .column_state = vmohhhkiut,
  .number_of_columns = 6,
  .column_rom_data = pilwrqwhtj,

  
  
  
  .time_control = &vwakkthcxh,
  .engine_control =&ywfueowmhj,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &vfqvtsibhl,
  .current_heap_location = &gsdxkytrms,
  .private_heap   = &jvhendlbzx,
  .private_heap_size =   1000,
  .number_of_sm      = 1,
   .sm_rom     =  homkvcuwia,
   .sm_ram     = vehsiaqphf,
} ;


const Handle_CFL_t*  state_machine_1_handle(){
    return &sdhpxpqfky;
}
   

#ifdef __cplusplus
}
#endif

#endif
