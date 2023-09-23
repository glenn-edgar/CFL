// bitmap.h

#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t length;  // Number of bits in the bitmap
    uint8_t* data;    // Each byte will represent 8 bits
} Bitmap_CFL;

  
void bitmap_set_bit_CFL(Bitmap_CFL* bmp, uint32_t index, bool value);
bool bitmap_get_bit_CFL(Bitmap_CFL* bmp, uint32_t index);
void bitmap_set_all_CFL(Bitmap_CFL* bmp, bool value);

Bitmap_CFL* get_bitmap_control_CFL(const void *input, unsigned buffer_number);
Bitmap_CFL *get_bitmap_CFL(const void *input, unsigned bit_map_number);
uint16_t bitmap_buffer_size_CFL(const void *input, unsigned buffer_number);
uint8_t *bitmap_buffer(const void *input, unsigned buffer_number);

#endif
