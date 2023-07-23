

//----------User  code ----


int bidirectional_one_shot_handler_CFL(void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{

  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    fn(handle, params, event_data);
  }

  return CONTINUE_CFL;
}


int one_shot_handler_CFL(void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data)
{
  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
    return DISABLE_CFL;
  }
  return DISABLE_CFL;
}


static const int reset_buffer[1] = { RESET_CFL }
static const int halt_buffer[1] = { HALT_CFL };
static const int terminate_buffer[1] = { TERMINATE_CFL };
static const int terminate_engine_buffer[1] = { ENGINE_TERMINATE_CFL };

int return_condition_code_CFL(void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    int *return_code;
    return_code = (int *)params;
    if (event_data->event_index > EVENT_INIT_CFL)
    {
        return *return_code;
    }
    return CONTINUE_CFL;
}


void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char *message;
  
  unsigned column_index;
  int column_element_number;
  message = (char *)params;
  Printf_CFL("Init event  %s\n",message);  
 
  
}


void log_message_CFL(void *input, void *params,
                        Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char *message;
  
  unsigned column_index;
  int column_element_number;
  message = (char *)params;

  column_index = Get_current_column_index_CFL(input);
  column_element_number = Get_current_column_element_index_CFL(input);
  Printf_CFL("Log !!!! column index %d column element %d  ---> msg: %s\n",
              column_index, column_element_number, message);
}


void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
 
  
   char *message;
   
   unsigned column_index;
   int column_element_number;
   message = (char *)params;
   if(event_data->event_index == EVENT_INIT_CFL)
   {
     Printf_CFL("Init event  %s\n",message);  
     
   }
    if(event_data->event_index == EVENT_TERMINATION_CFL)
    {
       Printf_CFL("Termination event %s\n",message);
    }
 
   
 }

