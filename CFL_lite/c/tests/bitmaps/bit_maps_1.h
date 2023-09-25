#ifndef __bit_maps_1_H__
#define __bit_maps_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t kgyflrvsdr[1];
static Event_data_CFL_t fwhovaluqr[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t ppaqcfxznt[] = { 
     {  10, fwhovaluqr },
};
static const char *wsmhvyglcj = "start column";
static const unsigned short epyogkisyf[] = { 1};
const Enable_column_CFL_t qpejufpirx = { true, 1, epyogkisyf };


unsigned  mjjznidrcb;
const While_time_control_ROM_CFL_t nuvouxblak = { 6000,&mjjznidrcb };



static While_control_RAM_CFL_t gnipvheben_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t adqzmvpoem_rom = { 0 ,true, &nuvouxblak,&gnipvheben_ram,null_function};

    
static const char *xbrysynoct = "terminating system";
static const char *facfixbldg = "configure bit maps";
static const clear_bit_map_CFL_t jsjbddkxao = {0,true};
static const dump_buffer_CFL_t oxyxczhpoe = {0,19};
static const clear_bit_map_CFL_t znjwwolbhg = {0,false};
static const dump_buffer_CFL_t qumvnpcrpv = {0,19};
static const clear_bit_map_CFL_t samjokfalp = {1,true};
static const dump_buffer_CFL_t xttqikccns = {1,8};
static const bit_map_copy_CFL_t eikkjjjzev = {1,0,0,5,63};
static const dump_buffer_CFL_t nvwkbqszrv = {0,19};
static const bit_map_and_CFL_t mweydrnigb = {1,0,0,0,63};
static const dump_buffer_CFL_t rniewuvxwy = {0,19};
static const bit_map_or_CFL_t bbbbkskeqb = {1,0,0,0,63};
static const dump_buffer_CFL_t twpxqseoph = {0,19};
static const bit_map_xor_CFL_t zptafohtnw = {1,0,0,0,63};
static const dump_buffer_CFL_t jphvzfylfw = {0,19};
static const bit_map_not_CFL_t eaoojzoryr = {0,0,0,0,128};
static const dump_buffer_CFL_t cqmclllqfl = {0,19};
static const char *gpcrhdtwxw = "terminating bit map configuration";


//----------RAM data structures for columns ----

unsigned saenumeawd[2];
Watch_dog_struct_CFL_t * dvcosxsfgz[2];
unsigned char qtbsioylem[2];
unsigned char napcdhuubf[2];
void* gocquguemc[2];
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

static const Column_ROM_CFL_t woezgmmhud[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { -1,false, 1, 19, 5, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char njieyljwmw[24];


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

static const Column_element_CFL_t szxtqvmqzm[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&wsmhvyglcj},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&qpejufpirx},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&adqzmvpoem_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xbrysynoct},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&facfixbldg},
    {one_shot_handler_CFL,clear_bit_map_CFL,(void *)&jsjbddkxao},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&oxyxczhpoe},
    {one_shot_handler_CFL,clear_bit_map_CFL,(void *)&znjwwolbhg},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&qumvnpcrpv},
    {one_shot_handler_CFL,clear_bit_map_CFL,(void *)&samjokfalp},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&xttqikccns},
    {one_shot_handler_CFL,bit_map_copy_CFL,(void *)&eikkjjjzev},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&nvwkbqszrv},
    {one_shot_handler_CFL,bit_map_and_CFL,(void *)&mweydrnigb},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&rniewuvxwy},
    {one_shot_handler_CFL,bit_map_or_CFL,(void *)&bbbbkskeqb},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&twpxqseoph},
    {one_shot_handler_CFL,bit_map_xor_CFL,(void *)&zptafohtnw},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&jphvzfylfw},
    {one_shot_handler_CFL,bit_map_not_CFL,(void *)&eaoojzoryr},
    {one_shot_handler_CFL,dump_buffer_CFL,(void *)&cqmclllqfl},
    {one_shot_handler_CFL,log_message_CFL,(void *)&gpcrhdtwxw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
static uint8_t exfnppowbl[19]= {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
static uint8_t cduumlcggj[8]= {0,0,0,0,0,0,0,0};
static uint8_t yzdctlajdm[10]= {0,0,0,0,0,0,0,0,0,0};
Bitmap_CFL bhnxyqliny[3] = {
 {152, &exfnppowbl[0]},
 {63, &cduumlcggj[0]},
 {75, &yzdctlajdm[0]},
};
const Sm_control_ROM_CFL_t zvnbperfdw[0];
Sm_control_RAM_CFL_t jorfcdsluq[0];


static Time_control_CFL_t nkeqzxfbmz;




static Engine_control_CFL_t rovkkzlveg;


/* remaining allocate heap size */

static unsigned yqquevfube;


/* current heap pointer */

static char* dbjnrcenmm;


/* heap block area */

static CS_MEMORY_CONTROL phsgpcwozv;


    
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


const struct Handle_CFL_t vunhulsqcc =
{

  .queue_number = 1,
  .queue_rom = ppaqcfxznt,
  .queue_ram = kgyflrvsdr,

  .column_elements_flags =njieyljwmw,
  .column_elements_ROM = szxtqvmqzm,

  .watch_dog_struct = dvcosxsfgz,
  .watch_dog_count  = saenumeawd,
   
   
  .column_flags = qtbsioylem,
  .column_local_data = gocquguemc,
  .column_state = napcdhuubf,
  .number_of_columns = 2,
  .column_rom_data = woezgmmhud,

  
  
  
  .time_control = &nkeqzxfbmz,
  .engine_control =&rovkkzlveg,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 2000,
  .remaining_heap_size = &yqquevfube,
  .current_heap_location = &dbjnrcenmm,
  .private_heap   = &phsgpcwozv,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
   .sm_rom     =  zvnbperfdw,
   .sm_ram     = jorfcdsluq,
   .number_of_bitmaps = 3,
    .bitmaps = bhnxyqliny,
} ;


const Handle_CFL_t*  bit_maps_1_handle(){
    return &vunhulsqcc;
}
   

#ifdef __cplusplus
}
#endif

#endif
