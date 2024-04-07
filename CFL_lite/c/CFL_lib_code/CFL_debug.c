

#include "CFL_inner_engine.h"




void Printf_CFL(const void *input,const char* format, ...)
{  
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
    
  
   if(handle->debug_function == NULL){
        
        return;
    }
    char *buffer = private_heap_malloc_CFL(input, PRINT_BUF_SIZE_CFL);
    memset(buffer,0,sizeof(char)*PRINT_BUF_SIZE_CFL);
   va_list args;
     va_start(args, format);
    vsprintf(buffer,format, args);
    
    va_end(args);
           
    handle->debug_function(buffer,strlen(buffer));
    private_heap_free_CFL(input, buffer);
   
}

