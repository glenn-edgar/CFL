
#include "CFL_inner_engine.h"
#include "CFL_debug.h"
#include "CFL_float_map.h"
#include <stdlib.h>
#include <string.h>





Floatmap_CFL_t *get_floatmap_control_CFL(const void *input, unsigned float_map_number){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
   if(float_map_number >= handle->number_of_floatmaps){
     ASSERT_PRINT_F("float_map_number is out of range got %d, max %d\n", float_map_number, handle->number_of_floatmaps);
   }
  return &handle->floatmaps[float_map_number];

}

uint16_t floatmap_buffer_size_CFL(const void *input, unsigned buffer_number){
    Floatmap_CFL_t *bmp = get_floatmap_control_CFL(input, buffer_number);
    return bmp->length; 
}

float *floatmap_buffer(const void *input, unsigned buffer_number){
    Floatmap_CFL_t *bmp = get_floatmap_control_CFL(input, buffer_number);
    return bmp->data; 
}

void floatmap_set_CFL(Floatmap_CFL_t* bmp, unsigned index, float value) {
    if (index >= bmp->length) {
        ASSERT_PRINT_F("index is out of range got %d, max %d\n", index, bmp->length);
        return;
    }
    bmp->data[index] = value;
}

float floatmap_get_CFL(Floatmap_CFL_t* bmp,unsigned index) {
    if (index >= bmp->length) {
        ASSERT_PRINT_F("index is out of range got %d, max %d\n", index, bmp->length);
        return false;
    }
    
    return bmp->data[index];
}

void floatmap_set_all_CFL(Floatmap_CFL_t* bmp, float value) {
    for(unsigned i=0; i<bmp->length; i++){
        floatmap_set_CFL(bmp, i, value);
    }
}

