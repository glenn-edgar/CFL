
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   




//----------Ref function header code ----


int return_condition_code(void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    
int one_shot_handler_CFL(void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data)


void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data);



void log_message_CFL(void *input, void *params,
                        Event_data_CFL_t *event_data);


   void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data);
   

#ifdef __cplusplus
}
#endif

#endif
