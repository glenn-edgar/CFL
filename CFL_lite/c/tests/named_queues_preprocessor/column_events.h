#ifndef __column_events_H__
#define __column_events_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



 #define column_event_4 103 


 #define column_event_2 101 


 #define column_event_1 100 


 #define column_event_3 102 


//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t xpvuunkfnd[6];
static Event_data_CFL_t dgoqoeunwn[7];
static Event_data_CFL_t tovudhtxzg[0];
static Event_data_CFL_t mtbfybkvwk[0];
static Event_data_CFL_t vgaeyyajyj[4];
static Event_data_CFL_t mwacrcrpnf[2];
static Event_data_CFL_t hndpfzuswu[2];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t wjbiblhhjp[] = { 
     {  7, dgoqoeunwn },
     {  0, tovudhtxzg },
     {  0, mtbfybkvwk },
     {  4, vgaeyyajyj },
     {  2, mwacrcrpnf },
     {  2, hndpfzuswu },
};
const Event_data_CFL_t jznrbwxnzw = { column_event_1, false, NULL };
const Event_data_CFL_t txshkctorb = { column_event_2, false, NULL };
const Event_data_CFL_t mcziaaseus = { column_event_3, false, NULL };
const Event_data_CFL_t fajnokeyqi = { column_event_4, false, NULL };


unsigned  xspgcoiwwe;
const While_time_control_ROM_CFL_t iygvyqhztl = { 12000,&xspgcoiwwe };



static While_control_RAM_CFL_t nqydjltfch_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t belpldklzr_rom = { 0 ,true, &iygvyqhztl,&nqydjltfch_ram,null_function};

    
static const char *ewfqftfrbj = "event generator start";


unsigned  wjjvzmnppo;
const While_time_control_ROM_CFL_t dxupdqfdiv = { 2000,&wjjvzmnppo };



static While_control_RAM_CFL_t ovygnxjkgr_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rebhipftbf_rom = { 0 ,true, &dxupdqfdiv,&ovygnxjkgr_ram,null_function};

    
static const char *taycxpnzae = "sending events";
const Queue_event_CFL_t imxyszrfst = { 3, &mcziaaseus };
const Queue_event_CFL_t cquwmbytpd = { 3, &fajnokeyqi };
const Queue_event_CFL_t pqegnktqrp = { 3, &jznrbwxnzw };
const Queue_event_CFL_t bugxtiykuf = { 3, &txshkctorb };
static const char *autnbuwohz = "done sending events";
static const char *jtcjbalenl = "event distributor start";
static unsigned short gzbtkfckil[] = { 4};
static const Conditional_send_event_CFL_t bnlvdcahpq = { 1, gzbtkfckil};
static unsigned short jrkxxvhccm[] = { 5};
static const Conditional_send_event_CFL_t sbqxmgmrad = { 1, jrkxxvhccm};
static const char *chlsvxuzmd = "event_client_1";
static unsigned short ibqvapuexe[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t gsfawyooou = { 4, ibqvapuexe};
static const char *ujnomagxog = "event_client_2";
static unsigned short bfvgqdhmpm[] = { column_event_1,column_event_2,column_event_3,column_event_4};
static const display_event_CFL_t uuexicnkpg = { 4, bfvgqdhmpm};


//----------RAM data structures for columns ----

unsigned cotbfdmvqf[5];
Watch_dog_struct_CFL_t * sjijdgipxf[5];
unsigned char llitcmnwvu[5];
unsigned char ggfilqhqhy[5];
void* jkdbuzlugj[5];
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

static const Column_ROM_CFL_t msjsqfxpic[] = {
  { 1,true, 0, 2, 0, -1, -1 },
  { 2,true, 1, 9, 2, -1, -1 },
  { 3,true, 2, 4, 11, -1, -1 },
  { 4,true, 3, 3, 15, -1, -1 },
  { 5,true, 4, 3, 18, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char oyjxqpxvsh[21];


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

static const Column_element_CFL_t zjwtpqfqup[] = {
    {while_handler_CFL,wait_time_delay_CFL,(void *)&belpldklzr_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_engine_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ewfqftfrbj},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rebhipftbf_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&taycxpnzae},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&imxyszrfst},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&cquwmbytpd},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&pqegnktqrp},
    {one_shot_handler_CFL,send_queue_event_CFL,(void *)&bugxtiykuf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&autnbuwohz},
    {return_condition_code_CFL,NULL,(void *)reset_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jtcjbalenl},
    {conditional_send_CFL,routing_1,(void *)&bnlvdcahpq},
    {conditional_send_CFL,routing_2,(void *)&sbqxmgmrad},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&chlsvxuzmd},
    {display_event_CFL,NULL,(void *)&gsfawyooou},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ujnomagxog},
    {display_event_CFL,NULL,(void *)&uuexicnkpg},
    {return_condition_code_CFL,NULL,(void *)halt_buffer},
};
Bitmap_CFL wuchntibrf[0];
Registermap_CFL_t xcsgwdopom[0];
Floatmap_CFL_t jdfccspngl[0];
const Sm_control_ROM_CFL_t wkkztctumn[0];
Sm_control_RAM_CFL_t qknsdfnfih[0];


static Time_control_CFL_t ojpndwaftv;




static Engine_control_CFL_t memqkoigvw;


/* remaining allocate heap size */

static unsigned prbkmpgyvi;


/* current heap pointer */

static char* inojuoxvrm;


/* heap block area */

static CS_MEMORY_CONTROL nzfugahxdn;


    
    


const struct Handle_CFL_t zswfmgwwrq =
{

  .queue_number = 6,
  .queue_rom = wjbiblhhjp,
  .queue_ram = xpvuunkfnd,

  .column_elements_flags =oyjxqpxvsh,
  .column_elements_ROM = zjwtpqfqup,

  .watch_dog_struct = sjijdgipxf,
  .watch_dog_count  = cotbfdmvqf,
   
   
  .column_flags = llitcmnwvu,
  .column_local_data = jkdbuzlugj,
  .column_state = ggfilqhqhy,
  .number_of_columns = 5,
  .column_rom_data = msjsqfxpic,

  
  
  
  .time_control = &ojpndwaftv,
  .engine_control =&memqkoigvw,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &prbkmpgyvi,
  .current_heap_location = &inojuoxvrm,
  .private_heap   = &nzfugahxdn,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  wkkztctumn,
  .sm_ram     = qknsdfnfih,
  .number_of_bitmaps = 0,
  .bitmaps = wuchntibrf,
  .number_of_registermaps = 0,
  .registermaps = xcsgwdopom,
  .number_of_floatmaps = 0,
  .floatmaps = jdfccspngl,
} ;

const Handle_CFL_t*  column_events_handle(){
    return &zswfmgwwrq;
}
   

#ifdef __cplusplus
}
#endif

#endif
