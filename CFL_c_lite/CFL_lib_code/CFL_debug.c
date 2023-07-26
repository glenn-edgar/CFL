

#include "CFL_inner_engine.h"

static const Handle_CFL_t *handle;

Debug_out_CFL_t debug_fn;
void config_debug_handle_CFL(const void *input)
{
   handle = (Handle_CFL_t *)input;
    
    debug_fn = handle->debug_function;
}


#ifdef ENABLE_DEBUG_MSG_CFL  

static char print_buffer[PRINT_BUF_SIZE_CFL];
#endif

void Printf_CFL(const char* format, ...)
{  
#ifdef ENABLE_DEBUG_MSG_CFL  
    char *buffer = print_buffer;
    memset(buffer,0,sizeof(print_buffer));
   va_list args;
     va_start(args, format);
    vsprintf(buffer,format, args);
    
    va_end(args);
   
    if(debug_fn != NULL){
        
        debug_fn(buffer,strlen(buffer));
    }
#endif
   
}


#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char *sbrk(int incr);       
#else  // __ARM__
extern char *__brkval;
#endif // __arm__

int freeMemory() {
 return 0; // implement on host
}