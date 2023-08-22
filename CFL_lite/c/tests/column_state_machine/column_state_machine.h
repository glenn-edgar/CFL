#ifndef __column_state_machine_H__
#define __column_state_machine_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_data_CFL_t byxiamptlm[10];
static Event_control_RAM_CFL_t mhkxupflsg[1];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t eppvixvhyt_default = { 10, 0 };
static const Event_control_ROM_CFL_t *eppvixvhyt[] = {
     &eppvixvhyt_default,
};
static const Named_event_queue_control_CFL_t ygpaavznbg = { 1,10,eppvixvhyt };
static const char *rdwrjikgsk = "test_start";
static const char *tcqpefymfu = "step 0";
static const char *zhlxiiawpp = "step 1";
static const char *gwdojdznwb = "step 2";
static const char *vgzyybtpph = "step 3";
const unsigned short pqbaguhkqy = 0;
static const char *nohhnzgdxj = "test_start";
static const char *licbtdsjvx = "step 6";
static const char *jkjalkuyou = "step 7";
static const char *uhdkfdacgu = "step 8";
static const char *atmgorfgvu = "step 9";
static const char *gnnzifgdhz = "step 10";
static const char *ofhjgijyay = "test_end";
static const char *cgkdtdwaih = "step 0";
static const char *sdrkthxaoy = "step 1";
static const char *tbhsotjlfw = "step 2";
static const char *vegeqvwnzf = "step 3";
const unsigned short izvsozcjqr = 5;
static const char *elkdwilwfi = "step 5";
static const char *iigyouhplf = "step 6";
static const char *rohjcygelp = "step 7";
static const char *qeoqwectmv = "step 8";
static const char *ujuyufjyex = "step 9";
static const char *zvekvbxyym = "test_end";
static const char *sqnppteubo = "test_middle";
static const char *juavcjhgjv = "step 0";
static const char *tqfzulqsgn = "step 1";
static const char *atwrvssegl = "step 2";
static const char *uhcxxpupxz = "step 3";
const unsigned short nldpkqcjpy = 3;
static const char *vtalbsfcxb = "step 5";
static const char *xpeajgrtif = "step 6";
static const char *bhcghytkbz = "step 7";
static const char *yqrihwbzzf = "test_middle";
static const char *enznszzuci = "step 9";
static const char *ufyboiqmia = "step 10";


//----------RAM data structures for columns ----

unsigned yqexpdobdg[3];
unsigned mavekbkodc[3];
One_shot_function_CFL_t  clghfehtva[3];
bool  efovvgbesb[3];
void *  dfxogshoam[3];
unsigned char xhvwravieq[3];
unsigned char mlrioagzap[3];
void* mlcisalpum[3];
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

static const Column_ROM_CFL_t dpxrycfhxe[] = {
  { -1,true, 0, 12, 0, 6, 11 },
  { -1,true, 1, 12, 24, 6, 11 },
  { -1,true, 2, 12, 12, 6, 11 },
};


//----------Column elements RAM structures----



static unsigned char tjkoeanalg[36];


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

static const Column_element_CFL_t zsgvnyytrd[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&rdwrjikgsk},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tcqpefymfu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zhlxiiawpp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gwdojdznwb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vgzyybtpph},
    {change_column_state_CFL,NULL,(void *)&pqbaguhkqy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nohhnzgdxj},
    {one_shot_handler_CFL,log_message_CFL,(void *)&licbtdsjvx},
    {one_shot_handler_CFL,log_message_CFL,(void *)&jkjalkuyou},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uhdkfdacgu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&atmgorfgvu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gnnzifgdhz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ofhjgijyay},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cgkdtdwaih},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sdrkthxaoy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tbhsotjlfw},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vegeqvwnzf},
    {change_column_state_CFL,NULL,(void *)&izvsozcjqr},
    {one_shot_handler_CFL,log_message_CFL,(void *)&elkdwilwfi},
    {one_shot_handler_CFL,log_message_CFL,(void *)&iigyouhplf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&rohjcygelp},
    {one_shot_handler_CFL,log_message_CFL,(void *)&qeoqwectmv},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ujuyufjyex},
    {one_shot_handler_CFL,log_message_CFL,(void *)&zvekvbxyym},
    {one_shot_handler_CFL,log_message_CFL,(void *)&sqnppteubo},
    {one_shot_handler_CFL,log_message_CFL,(void *)&juavcjhgjv},
    {one_shot_handler_CFL,log_message_CFL,(void *)&tqfzulqsgn},
    {one_shot_handler_CFL,log_message_CFL,(void *)&atwrvssegl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&uhcxxpupxz},
    {change_column_state_CFL,NULL,(void *)&nldpkqcjpy},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vtalbsfcxb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xpeajgrtif},
    {one_shot_handler_CFL,log_message_CFL,(void *)&bhcghytkbz},
    {one_shot_handler_CFL,log_message_CFL,(void *)&yqrihwbzzf},
    {one_shot_handler_CFL,log_message_CFL,(void *)&enznszzuci},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ufyboiqmia},
};


static Time_control_CFL_t jcdxzsrpuz;




static Engine_control_CFL_t xlmyhdykfb;


/* remaining allocate heap size */

static unsigned rimzceuwlb;


/* current heap pointer */

static char* hhioblvzia;


/* heap block area */

static CS_MEMORY_CONTROL myuenggqpq;


      
     
 /*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
const struct Handle_CFL_t ogrkrwplai =
{

  .queue_rom    = &ygpaavznbg,
  .queue_ram =  mhkxupflsg,
  .event_data = byxiamptlm,

  .column_elements_flags =tjkoeanalg,
  .column_elements_ROM = zsgvnyytrd,

  .watch_dog_trigger_count = yqexpdobdg,
  .watch_dog_count       =  mavekbkodc,  
  .watch_dog_trigger_function = clghfehtva,
  .watch_dog_termination_flag = efovvgbesb,
  .watch_dog_user_data = dfxogshoam,
   
   
  .column_flags = xhvwravieq,
  .column_local_data = mlcisalpum,
  .column_state = mlrioagzap,
  .number_of_columns = 3,
  .column_rom_data = dpxrycfhxe,

  
  
  
  .time_control = &jcdxzsrpuz,
  .engine_control =&xlmyhdykfb,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &rimzceuwlb,
  .current_heap_location = &hhioblvzia,
  .private_heap   = &myuenggqpq,
  .private_heap_size =   1000,
} ;


const Handle_CFL_t*  column_state_machine_handle(){
    return &ogrkrwplai;
}
   

#ifdef __cplusplus
}
#endif

#endif
