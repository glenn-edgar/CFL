// bitmap.h

#ifndef __REGISTER_MAP_H__
#define __REGISTER_MAP_H__

#include <stdint.h>


typedef struct Registermap_CFL_t{
    uint16_t length;  // Number of bits in the bitmap
    int16_t* data;    // Each byte will represent 8 bits
} Registermap_CFL_t;

  
void registermap_set_bit_CFL(Registermap_CFL_t* bmp, uint32_t index, int16_t value);

int16_t registermap_get_bit_CFL(Registermap_CFL_t* bmp, unsigned index);

void registermap_set_all_CFL(Registermap_CFL_t* bmp, int16_t value);

Registermap_CFL_t* get_registermap_control_CFL(const void *input, unsigned buffer_number);

uint16_t registermap_buffer_size_CFL(const void *input, unsigned buffer_number);

int16_t *registermap_buffer(const void *input, unsigned buffer_number);

#endif // __REGISTER_MAP_H__
