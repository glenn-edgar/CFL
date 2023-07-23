/*

File: cf_chain_flow_support.h


*/

#ifndef __CF_CHAIN_FLOW_SUPPORT_H__
#define __CF_CHAIN_FLOW_SUPPORT_H__

//typedef unsigned char uint8;
//typedef unsigned  unsigned;

// Chain flow return codes

typedef enum{
          CONTINUE_CFL  =  0,
          HALT_CFL      = 1,
          DISABLE_CFL   =  2,  
          RESET_CFL     =  3,
          TERMINATE_CFL =  4 
};


union Event_Data{
   int   i;
   float f;
};

typedef struct Event_data_CFL_t {
  short       event_index;
  Event_Data  event_data;
  void        *params;
}Event_data_CFL_t;


  


    
typedef int (*FUN_AUX_CFL_t)(void *input,void *param,Event_data_CFL_t *event_data);

    
typedef int (*COLUMN_FN_CFL_t)( void *input, FUN_AUX_CFL aux_fn,void *params, Event_data_CFL_t *event_data);
                  
typedef struct RAM_LINK_CELL_CFL_t{
    Event_Data  data;
    unsigned    active:1;
    unsigned    initialized:1;
    

}RAM_LINK_CELL_CFL_t;




typedef struct ROM_LINK_CELL_CFL_t
{
   COLUMN_FN_CFL_t       func;  
   FUN_AUX_CFL_t         aux_fn;
   const void*           ram_data;
   const void*           rom_data;
   RAM_LINK_CELL_CFL_t   *ram_link_cell;
}ROM_LINK_CELL_CFL_t;

typedef struct RAM_COLUMN_CELL_CFL_t
{
   unsigned                   link_index; 
   unsigned                   active:1;
   unsigned                   initialized:1;
}RAM_COLUMN_CELL_CFL_t;

typedef struct ROM_COLUMN_CELL_CFL
{ 
   unsigned                   startup_flag:1;
   unsigned                   link_index; 
   unsigned                   chain_index;
   unsigned                   link_number; 
   const ROM_LINK_CELL_CFL_t  *link_cells; 
}ROM_COLUMN_CELL_CFL;

typedef struct RAM_COLUMN_CONTROL_T{
   unsigned short  current_column_index;

}RAM_COLUMN_CONTROL_T;

typedef struct ROM_COLUMN_CONTROL_T
{
   unsigned                   chain_number;
   const ROM_COLUMN_CELL_CFL  *column_cells;
   RAM_COLUMN_CONTROL_T       *ram_column_control;
}ROM_COLUMN_CONTROL_T;


typedef long long unsigned (*Elasped_ms_fn)(void);

typedef struct Time_control_CFL_t
{
  int tick_ms;
  Elasped_ms_fn ms_fn;
  unsigned short current_millis;
  unsigned short start_millis;
  unsigned char second;
  unsigned char minute;
  unsigned char hour;
  unsigned char day;
  unsigned char dow;
  unsigned char month;
  unsigned short day_of_year;
  unsigned short year;
} Time_control_CFL_t;

typedef void (*Idle_function_CFL_t)(void* handle, Time_control_CFL_t* timer_control, bool init_flag);
typedef void (*Calendar_function_CFL_t)(void* handle, Time_control_CFL_t* timer_control, bool init_flag);

void *Configure_engine_CFL(const ROM_COLUMN_CONTROL_T *rom_column_control,unsigned allocate_once_size);
 


void *Start_engine_CFL(void *input,unsigned short tick_ms, unsigned short queue_size,
                         Idle_function_CFL_t idle_function,Calendar_function_CFL_t calendar_function);




#if 0


#define cf_reset_chain  cf_enable_chain

void initialize_cf_system( ROM_COLUMN_CONTROL_T *rom_column );
void cf_process_cf_event( unsigned event, unsigned event_data );
unsigned cf_get_cell_value( unsigned link_id );
void  cf_store_cell_value( unsigned link_id , unsigned value );
void cf_change_state( unsigned chain_id, unsigned link_id);
void cf_enable_chain(  unsigned  chain_id );
void cf_disable_chain( unsigned  chain_id );
void cf_resume_chain(  unsigned  chain_id );
void cf_suspend_chain( unsigned  chain_id );
#endif

#endif
