

#include "CFL_debug.h"
#include "CFL_inner_engine.h"
#include <stdlib.h>
#include <string.h>




Floatmap_CFL_t* get_floatmap_control_CFL(const void *input, unsigned buffer_number){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
   if(buffer_number >= handle->number_of_floatmaps){
     ASSERT_PRINT_F("float_map_number is out of range got %d, max %d\n", buffer_number, handle->number_of_registermaps);
   }
  return &handle->floatmaps[buffer_number];

}

uint16_t floatmap_buffer_size_CFL(const void *input, unsigned buffer_number){
   Floatmap_CFL_t* bmp = get_floatmap_control_CFL(input, buffer_number);
    return bmp->length; 
}

float *floatmap_buffer_CFL(const void *input, unsigned buffer_number){
    Floatmap_CFL_t* bmp = get_floatmap_control_CFL(input, buffer_number);
    return bmp->data; 
}

void floatmap_set_value_CFL(Floatmap_CFL_t* bmp, unsigned index, float value) {
    if (index >= bmp->length) {
        ASSERT_PRINT_F("floatmap_set_value_CFL: index %d is out of range\n", index);
        return;
    }
    bmp->data[index] = value;
}

float floatmap_get_value_CFL(Floatmap_CFL_t* bmp, unsigned index) {
    return bmp->data[index];
}

void floatmap_set_all_CFL(Floatmap_CFL_t* bmp, float value) {
   for(unsigned i=0; i<bmp->length; i++){
       floatmap_set_value_CFL(bmp, i, value);
   }
}

