#ifndef __CFL_DEBUG_H__
#define __CFL_DEBUG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "CFL_inner_engine.h"




#define PRINT_BUF_SIZE_CFL 256


void Printf_CFL(const void *input,const char* format, ...);
static inline void Dump_file_line(const void *input,const char *file, unsigned line){
   
    Printf_CFL(input,"%s %d \n",file,line);
}

#define ASSERT_PRINT(handle,message_1,message_2) Dump_file_line(handle,__FILE__,__LINE__); Printf_CFL(handle,"%s %s \n",message_1,message_2); while(1){;}
#define ASSERT_PRINT_INT(input,message_1,value) Dump_file_line(input,__FILE__,__LINE__);  Printf_CFL(input,"%s %d \n",message_1,value);while(1){;}
#define ASSERT_PRINT_F(handle,format, ...) Dump_file_line(handle,__FILE__,__LINE__);  Printf_CFL(handle,format, __VA_ARGS__);while(1){;}

#define LOG_OUTPUT_LINE(handle,line_output) Dump_file_line(handle,__FILE__,__LINE__);  Printf_CFL(handle,"%s \n",line_output);
#define MARK_LINE_CFL(handle,message)Dump_file_line(handle,__FILE__,__LINE__); Printf_CFL(handle,"%s \n",message);

#ifdef __cplusplus
}
#endif

#endif


