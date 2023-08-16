#ifndef __CFL_HANDLE_H__
#define __CFL_HANDLE_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "CFL_local_heap_functions.h"
/*
typedef struct Handle_CFL_t  = {
    
    Named_event_queue_control_CFL_t*   queue_rom;
    Event_control_RAM_CFL_t*           queue_ram;
    Event_data_CFL_t*                  event_data;

    Column_element_CFL_t*              column_elements;
                
    char*                              column_flags;
    void*                              column_local_data;
    Column_ROM_t                       *column_data;
          
    unsigned                           *watch_dog_ram_data;        
    Column_watch_dog_ROM_CFL_t         *watch_dog_rom_data;
 }Handle_CFL_t;
*/
#ifdef __cplusplus
}
#endif

#endif // __CFL_HANDLE_H__