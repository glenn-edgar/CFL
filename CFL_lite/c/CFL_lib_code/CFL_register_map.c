

#include "CFL_debug.h"
#include "CFL_inner_engine.h"
#include <stdlib.h>
#include <string.h>





Registermap_CFL_t *get_registermap_control_CFL(const void *input, unsigned reg_map_number){
   Handle_CFL_t *handle = (Handle_CFL_t *)input;
   if(reg_map_number >= handle->number_of_registermaps){
     ASSERT_PRINT_F("reg_map_number is out of range got %d, max %d\n", reg_map_number, handle->number_of_registermaps);
   }
  return &handle->registermaps[reg_map_number];

}

uint16_t registermap_buffer_size_CFL(const void *input, unsigned buffer_number){
    Registermap_CFL_t *bmp = get_registermap_control_CFL(input, buffer_number);
    return bmp->length; 
}

int16_t *registermap_buffer_CFL(const void *input, unsigned buffer_number){
    Registermap_CFL_t *bmp = get_registermap_control_CFL(input, buffer_number);
    return bmp->data; 
}

void registermap_set_value_CFL(Registermap_CFL_t* bmp, unsigned index, int16_t value) {
    if (index >= bmp->length) {
       ASSERT_PRINT_F("registermap_set_value_CFL: index %d is out of range\n", index);
        return;
    }
    bmp->data[index] = value;
}

int16_t registermap_get_value_CFL(Registermap_CFL_t* bmp, unsigned index) {
    return bmp->data[index];
}

void registermap_set_all_CFL(Registermap_CFL_t* bmp, int16_t value) {
   for(unsigned i=0; i<bmp->length; i++){
       registermap_set_value_CFL(bmp, i, value);
   }
}

