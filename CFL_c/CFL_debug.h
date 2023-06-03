#ifndef __CFL_DEBUG_H__
#define __CFL_DEBUG_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*Debug_out_CFL_t)(const void *buf, unsigned count);

int freeMemory();

void config_debug_handle_CFL(void *input, Debug_out_CFL_t debug_out);
void Printf_CFL(const char* format, ...);
static inline void Dump_file_line(const char *file, unsigned line){
   
    Printf_CFL("%s %d \n",file,line);
}

#define ASSERT_PRINT(message_1,message_2) Dump_file_line(__FILE__,__LINE__); Printf_CFL("%s %s \n",message_1,message_2); while(1){;}
#define ASSERT_PRINT_INT(message_1,value) Dump_file_line(__FILE__,__LINE__); Printf_CFL("%s %d \n",message_1,value);while(1){;}
#define ASSERT_PRINT_F(format, ...) Dump_file_line(__FILE__,__LINE__); Printf_CFL(format, __VA_ARGS__);while(1){;}

#define LOG_OUTPUT_LINE(line_output) Dump_file_line(__FILE__,__LINE__); Printf_CFL("%s \n",line_output);
#define MARK_LINE_CFL(message)Dump_file_line(__FILE__,__LINE__); Printf_CFL(input,"%s \n",message);



#endif
