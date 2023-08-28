#ifndef __basic_control_H__
#define __basic_control_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t htycrgaebe[1];
static Event_data_CFL_t qfcwxszgqz[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t jszlwwktyv[] = { 
     {  10, qfcwxszgqz },
};
static const char *mzwegjkrnc = "will enable column and terminate";
static const unsigned short mpueyloqmx[] = { 1};
const Enable_column_CFL_t zvfdyhrxyq = { false, 1, mpueyloqmx };
static const char *iefwumdxuf = "timer is done";
static const char *wyptrvfyki = "will enable columns and wait 15 seconds and terminate";
static const unsigned short oidnjwnimt[] = { 3,2};
const Enable_column_CFL_t hlqdhssqtg = { true, 2, oidnjwnimt };


unsigned  xmlygtltin;
const While_time_control_ROM_CFL_t govufssbqj = { 5000,&xmlygtltin };



static While_control_RAM_CFL_t bleinrfxrf_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t wtkcdedtfz_rom = { 0 ,true, &govufssbqj,&bleinrfxrf_ram,null_function};

    
static const unsigned short esqhvamwsu[] = { 3};
const Enable_column_CFL_t mbteyungkf = { true, 1, esqhvamwsu };


unsigned  iucyydwtsk;
const While_time_control_ROM_CFL_t wbycrrmkxm = { 11000,&iucyydwtsk };



static While_control_RAM_CFL_t nanbjdekai_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lgbqkfzbpe_rom = { 0 ,true, &wbycrrmkxm,&nanbjdekai_ram,null_function};

    
static const char *apbnburqlf = "timer is done";
static const char *iddwzdenwq = "will wait 5 seconds and reset";


unsigned  unikujxajt;
const While_time_control_ROM_CFL_t qdqgzweajt = { 5000,&unikujxajt };



static While_control_RAM_CFL_t vclfjvuhxq_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ymdhkjjeyx_rom = { 0 ,true, &qdqgzweajt,&vclfjvuhxq_ram,null_function};

    
static const char *ureblovznr = "when reset happend this message will be seen";


unsigned  dipyghtwas;
const While_time_control_ROM_CFL_t bzcoozgtqc = { 17000,&dipyghtwas };



static While_control_RAM_CFL_t dczqjbllhb_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kelicrywxp_rom = { 0 ,true, &bzcoozgtqc,&dczqjbllhb_ram,null_function};

    
static const char *acjhmujfna = "this message should not be seen";
static const unsigned short wdeimiroag[] = { 5};
const Enable_column_CFL_t tkjfqcumug = { false, 1, wdeimiroag };
static const char *yqwgtwyarx = "will disable reset column after 12 seconds";


unsigned  hplefrosyq;
const While_time_control_ROM_CFL_t qkyecnjurm = { 12000,&hplefrosyq };



static While_control_RAM_CFL_t lpnyewuisu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t osohjnzssb_rom = { 0 ,true, &qkyecnjurm,&lpnyewuisu_ram,null_function};

    
static const unsigned short mevevtrkln[] = { 5};
const Disable_column_CFL_t zxvhxdczpq = { 1, mevevtrkln };
static const char *qrdbmtpcpo = "Now will wait till enable_terminate column terminates this column";


unsigned  dlzjxjotfg;
const While_time_control_ROM_CFL_t qrxxdakgzn = { 1000,&dlzjxjotfg };



static While_control_RAM_CFL_t mpijmwhdjx_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rbwtqhwqhh_rom = { 0 ,true, &qrxxdakgzn,&mpijmwhdjx_ram,null_function};

    
static const char *gtvzmdexjc = "will wait 5 seconds and reset";


unsigned  syfnqgkpax;
const While_time_control_ROM_CFL_t zzuluwaauf = { 5000,&syfnqgkpax };



static While_control_RAM_CFL_t nqacqhhyhu_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lulszobstz_rom = { 0 ,true, &zzuluwaauf,&nqacqhhyhu_ram,null_function};

    
static const unsigned short vxrfqjdtyv[] = { 7};
const Enable_column_CFL_t etdsvpeoex = { false, 1, vxrfqjdtyv };
static const char *uihunpzluy = "waiting for join";
static const unsigned short clmuwkxuzk[] = { 7};
const Join_column_CFL_t tdphtofazj = { true, 1, clmuwkxuzk };
static const char *hfslgxpyuw = "Column has been joined";
static const char *meyqkyijri = "will wait 5 seconds and terminate";


unsigned  sxfjiqujsk;
const While_time_control_ROM_CFL_t rnuooztmbj = { 5000,&sxfjiqujsk };



static While_control_RAM_CFL_t gfkyxmhkkh_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t jfrtahmgmk_rom = { 0 ,true, &rnuooztmbj,&gfkyxmhkkh_ram,null_function};

    
static const char *yakbssvdch = "timer is done";


//----------RAM data structures for columns ----

unsigned jadygcrvot[8];
Watch_dog_struct_CFL_t * ibwfbxcghd[8];
unsigned char hbualmaixo[8];
unsigned char txaonfowrr[8];
void* fqjewfsnvy[8];
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

static const Column_ROM_CFL_t hloaitgczt[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,false, 1, 7, 4, -1, -1 },
  { -1,false, 2, 3, 11, -1, -1 },
  { -1,false, 3, 4, 14, -1, -1 },
  { -1,true, 4, 7, 18, -1, -1 },
  { -1,false, 5, 3, 25, -1, -1 },
  { -1,true, 6, 5, 28, -1, -1 },
  { -1,false, 7, 4, 33, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char gomsrbhacx[37];


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

static const Column_element_CFL_t jowbvztvrm[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&mzwegjkrnc},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&zvfdyhrxyq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iefwumdxuf},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&wyptrvfyki},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&hlqdhssqtg},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&wtkcdedtfz_rom},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&mbteyungkf},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lgbqkfzbpe_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&apbnburqlf},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iddwzdenwq},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ymdhkjjeyx_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ureblovznr},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&kelicrywxp_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&acjhmujfna},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&tkjfqcumug},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yqwgtwyarx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&osohjnzssb_rom},
    {one_shot_handler_CFL,disable_columns_function_CFL,(void *)&zxvhxdczpq},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qrdbmtpcpo},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rbwtqhwqhh_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gtvzmdexjc},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lulszobstz_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&etdsvpeoex},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uihunpzluy},
    {join_columns_function_CFL,null_function,(void *)&tdphtofazj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&hfslgxpyuw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&meyqkyijri},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&jfrtahmgmk_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yakbssvdch},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};


static Time_control_CFL_t jcfcgyaaoc;




static Engine_control_CFL_t zvwevxsgfo;


/* remaining allocate heap size */

static unsigned riuvzmxqti;


/* current heap pointer */

static char* dzcmquuprf;


/* heap block area */

static CS_MEMORY_CONTROL efpwifpgsr;


    
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
    
    } Handle_CFL_t;

    
      
     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


const struct Handle_CFL_t uvvulkectz =
{

  .queue_number = 1,
  .queue_rom = jszlwwktyv,
  .queue_ram = htycrgaebe,

  .column_elements_flags =gomsrbhacx,
  .column_elements_ROM = jowbvztvrm,

  .watch_dog_struct = ibwfbxcghd,
  .watch_dog_count  = jadygcrvot,
   
   
  .column_flags = hbualmaixo,
  .column_local_data = fqjewfsnvy,
  .column_state = txaonfowrr,
  .number_of_columns = 8,
  .column_rom_data = hloaitgczt,

  
  
  
  .time_control = &jcfcgyaaoc,
  .engine_control =&zvwevxsgfo,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &riuvzmxqti,
  .current_heap_location = &dzcmquuprf,
  .private_heap   = &efpwifpgsr,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  basic_control_handle(){
    return &uvvulkectz;
}
   

#ifdef __cplusplus
}
#endif

#endif
