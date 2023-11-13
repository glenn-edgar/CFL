// bitmap.c

#include "CFL_debug.h"
#include "CFL_bit_map.h"
#include <stdlib.h>
#include <string.h>





Bitmap_CFL *get_bitmap_control_CFL(const void *input, unsigned bit_map_number){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
   if(bit_map_number >= handle->number_of_bitmaps){
     ASSERT_PRINT_F("bit_map_number is out of range got %d, max %d\n", bit_map_number, handle->number_of_bitmaps);
   }
  return &handle->bitmaps[bit_map_number];

}

uint16_t bitmap_buffer_size_CFL(const void *input, unsigned buffer_number){
    Bitmap_CFL *bmp = get_bitmap_control_CFL(input, buffer_number);
    return bmp->length; 
}

uint8_t *bitmap_buffer(const void *input, unsigned buffer_number){
    Bitmap_CFL *bmp = get_bitmap_control_CFL(input, buffer_number);
    return bmp->data; 
}

void bitmap_set_bit_CFL(Bitmap_CFL* bmp, uint32_t index, bool value) {
    if (index >= bmp->length) {
        ASSERT_PRINT_F("index is out of range got %d, max %d\n", index, bmp->length);
        return;
    }
    uint32_t byteIndex = index / 8;
    uint8_t bitIndex = index % 8;
    if (value) {
        bmp->data[byteIndex] |= (1 << bitIndex);
    } else {
        bmp->data[byteIndex] &= ~(1 << bitIndex);
    }
}

bool bitmap_get_bit_CFL(Bitmap_CFL* bmp, uint32_t index) {
    if (index >= bmp->length) {
        ASSERT_PRINT_F("index is out of range got %d, max %d\n", index, bmp->length);
        return false;
    }
    uint32_t byteIndex = index / 8;
    uint8_t bitIndex = index % 8;
    return (bmp->data[byteIndex] & (1 << bitIndex)) != 0;
}

void bitmap_set_all_CFL(Bitmap_CFL* bmp, bool value) {
    uint32_t dataSize = (bmp->length + 7) / 8;
   
    if (value) {
        // Set all bits to 1
        memset(bmp->data, 0xFF, dataSize);
    } else {
        // Set all bits to 0
        memset(bmp->data, 0, dataSize);
    }
}




static void shift_one_time(uint8_t *buffer, size_t size, size_t start, size_t end, int direction) {
   (void)size;

    size_t startByte = start / 8;
    size_t endByte = (end - 1) / 8;
    size_t startBit = start % 8;
    size_t endBit = (end - 1) % 8;
   
    if (direction > 0) {
        // Sift in the + direction
        for (size_t i = endByte; i > startByte; --i) {
            buffer[i] = (buffer[i] << 1) | (buffer[i - 1] >> 7);
        }
        buffer[startByte] <<= 1;

        // Handle edge bits if start and end are not byte-aligned
        if (endBit != 7) {
            buffer[endByte] &= ~(1 << endBit);
           
        }
       
    } else {
        // Sift in the - direction
        for (size_t i = startByte; i < endByte; ++i) {
            buffer[i] = (buffer[i] >> 1) | (buffer[i + 1] << 7);
        }
        buffer[endByte] >>= 1;

        // Handle edge bits if start and end are not byte-aligned
        if (startBit != 0) {
            buffer[startByte] &= ~(1 << (7 - startBit));
           
        }
         
    }
}

static void shiftBits(uint8_t *buffer, size_t size, size_t start, size_t end, int number){
  int shift_direction = number > 0 ? 1 : -1;
  if(number < 0){
    number = -number;

  }

  for(int i = 0; i < number; i++){
    shift_one_time(buffer, size, start, end, shift_direction);
  }

}



void bitmap_shift_bits_CFL(Bitmap_CFL* bmp, uint16_t start, uint16_t end, int direction) {
   
    shiftBits(bmp->data, bmp->length, start, end, direction);
}

