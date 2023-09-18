#ifndef __rpc_services_H__
#define __rpc_services_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t dhwzmabvcz[5];
static Event_data_CFL_t xsttrxghao[10];
static Event_data_CFL_t lusmnxhryo[10];
static Event_data_CFL_t uktazwkwpj[10];
static Event_data_CFL_t pjwojmdoxq[10];
static Event_data_CFL_t ggnqwnuops[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ctonjzshim[] = { 
     {  10, xsttrxghao },
     {  10, lusmnxhryo },
     {  10, uktazwkwpj },
     {  10, pjwojmdoxq },
     {  10, ggnqwnuops },
};
const char clean_up_data[] = "clean up data for bad event";
static const char *ueodfnzqel = "start column";
static const unsigned short wpbmsxeqac[] = { 1,2,3,4};
const Enable_column_CFL_t ramjyipago = { true, 4, wpbmsxeqac };


unsigned  hynnnnfdcw;
const While_time_control_ROM_CFL_t ankhzmhluv = { 60000,&hynnnnfdcw };



static While_control_RAM_CFL_t yykagazaza_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t snwurhojou_rom = { 0 ,true, &ankhzmhluv,&yykagazaza_ram,null_function};

    
static const char *vjijwuunjn = "terminating";
const unsigned short fkzdsjqqam[] = {11, 12, 13, 14, 15};
const rpc_server_event_processor_CFL_t qeiqcakdgq = {NULL,5,fkzdsjqqam};
const unsigned short acwcmymzrf[] = {21, 22, 23, 24, 25};
const rpc_server_event_processor_CFL_t ezmggjftos = {NULL,5,acwcmymzrf};
rpc_server_event_clean_up_CFL_t rdglwoujxq = {(void *)clean_up_data,true};
rpc_ram_message_CFL_t sxohyfdbqt;
const rpc_rom_message_CFL_t ltztxpncdb = {13,RPC_MESSAGE_ID_CFL,1,2,&sxohyfdbqt};
 unsigned qimnzdtuse_ram;
const While_event_control_ROM_t qimnzdtuse_rom = { 1,32767,1000,true,"unexpected one second time out",&qimnzdtuse_ram };  
// number of events,event index,time out,terminate flag, ram_pit

static While_control_RAM_CFL_t rqyjocolst_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t spljhanufr_rom = { 1000 ,true, &qimnzdtuse_rom,&rqyjocolst_ram,rpc_client_1_time_out};

    


unsigned  rwutfwfjbv;
const While_time_control_ROM_CFL_t zcgurscmip = { 5000,&rwutfwfjbv };



static While_control_RAM_CFL_t dtxgmvqakk_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xnpfoxogwx_rom = { 0 ,true, &zcgurscmip,&dtxgmvqakk_ram,null_function};

    
rpc_ram_message_CFL_t fvpskrknau;
const rpc_rom_message_CFL_t miaoquhtfj = {23,RPC_MESSAGE_ID_CFL,1,3,&fvpskrknau};


unsigned  betgkmhsvd;
const While_time_control_ROM_CFL_t xaoegrssnz = { 5000,&betgkmhsvd };



static While_control_RAM_CFL_t hxqpooalvl_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t bvfqpqdxat_rom = { 0 ,true, &xaoegrssnz,&hxqpooalvl_ram,null_function};

    


unsigned  avpxoahfvq;
const While_time_control_ROM_CFL_t uzabevylvq = { 45000,&avpxoahfvq };



static While_control_RAM_CFL_t oazjerquak_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t xblvddysag_rom = { 0 ,true, &uzabevylvq,&oazjerquak_ram,null_function};

    
rpc_ram_message_CFL_t ytfridojie;
const rpc_rom_message_CFL_t inoqdtaoti = {33,RPC_MESSAGE_ID_CFL,1,4,&ytfridojie};


unsigned  aqnflcjplu;
const While_time_control_ROM_CFL_t gscuvhulsp = { 45000,&aqnflcjplu };



static While_control_RAM_CFL_t jzivnfwnik_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t lifyqbbduc_rom = { 0 ,true, &gscuvhulsp,&jzivnfwnik_ram,null_function};

    


//----------RAM data structures for columns ----

unsigned qbasetolid[5];
Watch_dog_struct_CFL_t * fpterdsmbp[5];
unsigned char cvrbzoobmg[5];
unsigned char vjjlswzcbp[5];
void* kqqrwmqnsm[5];
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

static const Column_ROM_CFL_t wdonnqxjem[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { 1,false, 1, 4, 5, -1, -1 },
  { 2,false, 2, 5, 9, -1, -1 },
  { 3,false, 3, 4, 14, -1, -1 },
  { 4,false, 4, 5, 18, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char tvhhppnark[23];


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

static const Column_element_CFL_t suguurkzqu[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&ueodfnzqel},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&ramjyipago},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&snwurhojou_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vjijwuunjn},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {rpc_server_event_processor_CFL,service_handler_1,(void *)&qeiqcakdgq},
    {rpc_server_event_processor_CFL,service_handler_2,(void *)&ezmggjftos},
    {rpc_server_event_clean_up_CFL,rpc_clean_up_one_shot,(void *)&rdglwoujxq},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {rpc_client_event_generator_CFL,rpc_client_1_generator,(void *)&ltztxpncdb},
    {while_handler_CFL,wait_event_handler,(void *)&spljhanufr_rom},
    {rpc_client_event_processor_CFL,rpc_client_event_processor_1,(void *)&"process event 1 user data"},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xnpfoxogwx_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {rpc_client_event_generator_CFL,rpc_client_2_generator,(void *)&miaoquhtfj},
    {rpc_client_event_processor_CFL,rpc_client_event_processor_1,(void *)&"process event 2 user data"},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&bvfqpqdxat_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&xblvddysag_rom},
    {rpc_client_event_generator_CFL,rpc_client_3_generator,(void *)&inoqdtaoti},
    {rpc_client_event_processor_CFL,rpc_client_event_processor_1,(void *)&"process event 3 user data"},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&lifyqbbduc_rom},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
};
const Sm_control_ROM_CFL_t qmbhqwmdsj[0];
Sm_control_RAM_CFL_t lxvgoideds[0];


static Time_control_CFL_t vpnecympoq;




static Engine_control_CFL_t ebshiphzph;


/* remaining allocate heap size */

static unsigned tsqjocpfnm;


/* current heap pointer */

static char* exuccvphcy;


/* heap block area */

static CS_MEMORY_CONTROL biyirtgash;


    
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


const struct Handle_CFL_t lldustwpqw =
{

  .queue_number = 5,
  .queue_rom = ctonjzshim,
  .queue_ram = dhwzmabvcz,

  .column_elements_flags =tvhhppnark,
  .column_elements_ROM = suguurkzqu,

  .watch_dog_struct = fpterdsmbp,
  .watch_dog_count  = qbasetolid,
   
   
  .column_flags = cvrbzoobmg,
  .column_local_data = kqqrwmqnsm,
  .column_state = vjjlswzcbp,
  .number_of_columns = 5,
  .column_rom_data = wdonnqxjem,

  
  
  
  .time_control = &vpnecympoq,
  .engine_control =&ebshiphzph,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &tsqjocpfnm,
  .current_heap_location = &exuccvphcy,
  .private_heap   = &biyirtgash,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
   .sm_rom     =  qmbhqwmdsj,
   .sm_ram     = lxvgoideds,
} ;


const Handle_CFL_t*  rpc_services_handle(){
    return &lldustwpqw;
}
   

#ifdef __cplusplus
}
#endif

#endif
