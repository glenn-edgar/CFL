// bitmap.h

#ifndef __FLOAT_MAP_H__
#define __FLOAT_MAP_H__

#include <stdint.h>


typedef struct Floatmap_CFL_t{
    uint16_t length;  // Number of bits in the bitmap
    float* data;    // Each byte will represent 8 bits
} Floatmap_CFL_t;

  
void  floatmap_set_value_CFL(const void *input,Floatmap_CFL_t* bmp, unsigned index, float value);

float floatmap_get_value_CFL(const void *input,Floatmap_CFL_t* bmp, unsigned index);

void floatmap_set_all_CFL(const void *input,Floatmap_CFL_t* bmp, float value);

Floatmap_CFL_t* get_floatmap_control_CFL(const void *input, unsigned buffer_number);

uint16_t floatmap_buffer_size_CFL(const void *input, unsigned buffer_number);

float *floatmap_buffer_CFL(const void *input, unsigned buffer_number);

#endif // __FLOAT_MAP_H__
