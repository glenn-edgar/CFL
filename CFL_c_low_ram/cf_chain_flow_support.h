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

Configure_engine_CFL(%s,%s,%s);\n\n",config_handle,once_size,private_size) 
function Start_function(name)

void *Start_engine_CFL(void *input,tick_ms,queue_size,idle_function,calendar_function);
Destroy_engine_CFL(input);

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
