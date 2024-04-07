

//----------Run time code  ----

#include "run_time_code_CFL.h"


int case_test_fn(const void *input, void* params, Event_data_CFL_t* event_data, bool *event_continue_flag){
    (void)input;
    const char *user_data = (const char *)params;
    printf("case_test_fn received event index %d\n",event_data->event_index);
    switch(event_data->event_index){
        case 100:
            *event_continue_flag = false;
            return 0;
        case 101:
            *event_continue_flag = false;
            return 1;
        case 102:
            *event_continue_flag = false;
            printf("%s This event is processed and the event is not continued %d\n",user_data,event_data->event_index);
            return -1;
        case 103:
            *event_continue_flag = true;
            return 3;
        default:
            *event_continue_flag = false;
            return -1;
    }
    return -1;
}



const int reset_buffer[1] = { RESET_CFL };
const int halt_buffer[1] = { HALT_CFL };
const int terminate_buffer[1] = { TERMINATE_CFL };
const int terminate_engine_buffer[1] = { ENGINE_TERMINATE_CFL };



int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)aux_fn;
    int *return_code;
    return_code = (int *)params;
    
    if (event_data->event_index == EVENT_INIT_CFL)
    {
        return CONTINUE_CFL;
    }
   
    return *return_code;
}


static void mark_disabled_columns(const void *input, Supervisor_data_CFL_t *supervisor_data)
{
  for (unsigned short i = 0; i < supervisor_data->column_number; i++)
  {
    supervisor_data->restart_mask[i] = !column_state_CFL(input, supervisor_data->column_list[i]);
  
    if (supervisor_data->restart_mask[i] != false)
    {
        supervisor_data->reset_count[i] = supervisor_data->reset_count[i] + 1;
       
    }
  }
}

static void mark_columns_for_reset(const void *input, Supervisor_data_CFL_t *supervisor_data)
{
  (void)input;
  switch (supervisor_data->reset_type)
  {
    case 0: // one for one
        for (unsigned i = 0; i < supervisor_data->column_number; i++)
        {
            if (supervisor_data->restart_mask[i] == true)
            {
        
            supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
            }
        }
      break;
    case 1: // one for all
        ;
        bool state = false;
        for (unsigned i = 0; i < supervisor_data->column_number; i++)
        {
            if (supervisor_data->restart_mask[i] == true)
            {
                state = true;
                break;
            }
            
        }
        if (state == true)
        {
            for (unsigned i = 0; i < supervisor_data->column_number; i++)
            {
                supervisor_data->restart_mask[i] = true;
                supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
            
            }
        }
        break;
    case 2: // rest for one
        
        state = false;
        for (unsigned i = 0; i < supervisor_data->column_number; i++)
        {
            if(state == false){
               if (supervisor_data->restart_mask[i] == true)
               {
                  state = true;
                  supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
                  
                } 
            } else {
             
                supervisor_data->restart_mask[i] = true;
                supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
            }
        }
        break;
    }
}

static void reset_marked_columns(const void *input, Supervisor_data_CFL_t *supervisor_data)
{
  for (unsigned i = 0; i < supervisor_data->column_number; i++)
  {
    if (supervisor_data->restart_mask[i] == true)
    {
      enable_column_CFL(input, supervisor_data->column_list[i]);
    }
  }
}

static void disable_all_supervised_columns(const void *input, Supervisor_data_CFL_t *supervisor_data){
    for (unsigned i = 0; i < supervisor_data->column_number; i++)
    {
        disable_column_CFL(input, supervisor_data->column_list[i]);
    }

}

int supervisor_control_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
    Supervisor_data_CFL_t *supervisor_data = (Supervisor_data_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        bool_fn(input,supervisor_data,event_data);
        for(unsigned i=0;i<supervisor_data->column_number;i++){
            supervisor_data->reset_count[i] = 0;
            supervisor_data->secondary_reset_count[i] = 0;
            supervisor_data->restart_mask[i] = false;
        }
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        bool_fn(input,supervisor_data,event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index == SUPERVISOR_EVENT_CFL   ){
        bool_fn(input,supervisor_data,event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index != TIMER_TICK_CFL){
        return  CONTINUE_CFL;
    }
    // this path is for the timer tick
    // determine column state
    mark_disabled_columns(input, supervisor_data);
    
    mark_columns_for_reset(input, supervisor_data);
    bool result = bool_fn(input, supervisor_data, event_data);
   
    if( result == false){
        disable_all_supervised_columns(input, supervisor_data);
        if(supervisor_data->terminate_flag == true){
            return TERMINATE_CFL;
        }else{
            return RESET_CFL;
        }
    }
    reset_marked_columns(input, supervisor_data);
    return CONTINUE_CFL;
   
}


int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
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

int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
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

int chain_columns_case_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    State_function_CFL_t fn = (State_function_CFL_t)aux_fn;
    Chain_columns_case_CFL_t *chain_columns = (Chain_columns_case_CFL_t *)params;
    bool continue_flag = true;
    if(event_data->event_index >= 0){
      int result = fn(input,(void *)chain_columns->user_data,event_data,&continue_flag);
      if(result > chain_columns->number_of_columns -1){
          result = chain_columns->number_of_columns -1;
      }
      if( result >= 0){
            chain_single_sweep_CFL( input, chain_columns->column_list[result], event_data);
      }
      if(continue_flag == false){
          return HALT_CFL;
      }
        
    }
    return CONTINUE_CFL;
}



int display_event_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
  (void)aux_fn;
  const display_event_CFL_t *display_event = (const display_event_CFL_t *)params;
  
  for(unsigned i= 0; i< display_event->number_of_columns; i++)
  {
    if(event_data->event_index == display_event->event_array[i]){
      
      unsigned column_index = get_current_column_index_CFL(handle);
      unsigned column_element_number = get_current_column_element_index_CFL(handle);
      Printf_CFL(handle,"Display Event !!!! column index %d column element %d  ---> Event: %d\n",
              column_index, column_element_number,display_event->event_array[i]);
    }
    
  }
  

  return CONTINUE_CFL;
}

int while_column_handler_CFL(const void *input, void *aux_fn,void *params, Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    While_column_control_CFL_t *while_control;
    while_control = (While_column_control_CFL_t *)params;

    if (event_data->event_index == EVENT_INIT_CFL)
    {
       fn(input, while_control, event_data);
       *while_control->current_count = 0;
       *while_control->state = true;
      

    }

    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        fn(input, while_control, event_data);
        for(unsigned i=0;i<while_control->number_of_columns;i++){
            disable_column_CFL(input,while_control->column_indexes[i]);
        }
    }
    if (event_data->event_index != TIMER_TICK_CFL)
    {
        return HALT_CFL;
    }
    
    if(*while_control->state == true){
        if(fn(input, while_control, event_data) == false)
        {
           
            // chains are already disabled
            return DISABLE_CFL;
        }else{
            *while_control->current_count = *while_control->current_count + 1;
            for(unsigned i=0;i<while_control->number_of_columns;i++){
                enable_column_CFL(input,while_control->column_indexes[i]);
            }
            
        }
        *while_control->state = false;
        return HALT_CFL;
    }else{
        if(join_columns_CFL(input,while_control->number_of_columns,while_control->column_indexes) == true){
            *while_control->state = true;
        }


    }

    return HALT_CFL;
}


static inline void join_terminate_columns_CFL(const void *input, Join_column_CFL_t *join_column){
    unsigned short i;
    for(i=0;i<join_column->number_of_columns;i++){
        disable_column_CFL(input,join_column->column_list[i]);
    }
}

int join_columns_function_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Join_column_CFL_t *join_column = (Join_column_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        ; // do nothing
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        if(join_column->terminate_flag==true){
            join_terminate_columns_CFL(input,join_column);
        }
        return DISABLE_CFL;
    }


    if(event_data->event_index == TIMER_TICK_CFL ){
       if(join_columns_CFL(input,join_column->number_of_columns,join_column->column_list)==true){
           return DISABLE_CFL;
       }
       return HALT_CFL;
    }
    return HALT_CFL;
}




int chain_columns_sequence_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Chain_columns_sequence_CFL_t *chain_columns = (Chain_columns_sequence_CFL_t *)params;
   
    if(event_data->event_index >= 0){
        for(unsigned i=0;i< chain_columns->number_of_events;i++){
            if(chain_columns->event_list[i] == event_data->event_index){
                for(unsigned i=0;i<chain_columns->number_of_columns;i++){
                    chain_single_sweep_CFL( input, chain_columns->column_list[i], event_data);
                }
            }
        }
   
    }
    return CONTINUE_CFL;
}


  static inline int generate_return_code_while(bool termination_flag)
  {
    if (termination_flag == true)
    {
      return TERMINATE_CFL;
    }
    return RESET_CFL;
  }  
int while_handler_CFL(const void *input, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
    
    const While_control_ROM_CFL_t *while_ctrl = (While_control_ROM_CFL_t *)params;
    While_control_RAM_CFL_t *while_ctrl_ram = while_ctrl->while_control_ram;
    
    if (event_data->event_index == EVENT_INIT_CFL)
    {
       
        
        while_ctrl_ram->current_count = 0;
        bool_fn(handle,(void *) while_ctrl->user_data, event_data);
        
        return CONTINUE_CFL;
    }
    
    if (bool_fn(handle, (void *)while_ctrl->user_data, event_data) == true)
    {
        return DISABLE_CFL;
    }
    if (while_ctrl->time_out_ms <= 0)
    {
        return HALT_CFL;
    }
    if (event_data->event_index != TIMER_TICK_CFL)
    {
        return HALT_CFL;
    }
    while_ctrl_ram->current_count += *(unsigned short *)event_data->params;
    if (while_ctrl_ram->current_count < while_ctrl->time_out_ms)
    {
        return HALT_CFL;
    }
    // Time out at this point
    while_ctrl->user_time_out_fn(handle, (void *)while_ctrl->user_data, event_data);
    
    return generate_return_code_while(while_ctrl->terminate_flag);
}


static inline void  mark_return_code_CFL(const void *input, bool status_flag){
   unsigned short column_number = get_current_column_index_CFL(input);
   set_column_return_code_CFL(input,column_number,status_flag);
}

static inline bool try_check_column_state_CFL(const void *input, unsigned short column_index, bool invert_flag){
    bool state = get_column_return_code_CFL(input,column_index);
    
    if(invert_flag != state){
        
        mark_return_code_CFL(input,true);
        return true;
    }
    return false;

}

int try_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data ){
    (void)aux_fn;
    const Try_columns_CFL_t* try_columns = (const Try_columns_CFL_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    if(event_data->event_index == EVENT_INIT_CFL ){
      *try_columns->column_index = 0;
      *try_columns->state = true;
      return HALT_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
      for(int i = 0; i < try_columns->column_number; i++){
        disable_column_CFL(handle, try_columns->column_list[i]);
      }
      return DISABLE_CFL;
    }
    if(event_data->event_index != TIMER_TICK_CFL){
      return HALT_CFL;
    }
    if(*try_columns->state == true){

      enable_column_CFL(handle, try_columns->column_list[*try_columns->column_index]);
      *try_columns->state = false;      
    }
    else{
        if(column_state_CFL(handle, try_columns->column_list[*try_columns->column_index]) == false){
           if(try_check_column_state_CFL(handle, try_columns->column_list[*try_columns->column_index],try_columns->invert_flag) == true){
              return DISABLE_CFL;
           }
           *try_columns->state = true;
           *try_columns->column_index = *try_columns->column_index + 1;
           if(*try_columns->column_index >= try_columns->column_number){
              mark_return_code_CFL(handle, false);
              return DISABLE_CFL;
           }
        }   
       
    }
    return HALT_CFL;
}


int sequence_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data ){
    (void)aux_fn;
   
    return sequence_columns_utility_CFL(input, params, event_data);

}

int assert_column_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
   Assert_column_CFL_t *assert_column = ( Assert_column_CFL_t *)params;
   Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
   if(event_data->event_index == EVENT_INIT_CFL){
      *assert_column->result = bool_fn(input,assert_column->user_data,event_data);
      if(*assert_column->result == false){
        sequence_columns_utility_CFL(input,  &assert_column->sequence_columns, event_data);
     }
   }
   if(event_data->event_index == EVENT_TERMINATION_CFL){
     if(*assert_column->result == false){
        sequence_columns_utility_CFL(input,   &assert_column->sequence_columns, event_data);
     }
     return CONTINUE_CFL;
   }
   if(*assert_column->result == true){
      return DISABLE_CFL;
   }
    if(event_data->event_index != TIMER_TICK_CFL){
        return HALT_CFL;
    }
   int return_code = sequence_columns_utility_CFL(input, &assert_column->sequence_columns, event_data);
   if(return_code == DISABLE_CFL){
      if(assert_column->termination_flag == true){
         return TERMINATE_CFL;
      }
      return RESET_CFL;
   }
   return HALT_CFL;

}


int if_then_else_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t )aux_fn;
    If_then_else_CFL_t *if_then_else = (If_then_else_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            for(unsigned i=0;i<if_then_else->number_of_then_columns;i++){
          
                enable_column_CFL(input,if_then_else->then_column_list[i]);
            }
            
        }
        else{
            for(unsigned i=0;i<if_then_else->number_of_else_columns;i++){
          
                enable_column_CFL(input,if_then_else->else_column_list[i]);
            }

        }
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
       
        if(if_then_else->terminate_flag==false){
            return CONTINUE_CFL;
        }
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            for(unsigned i=0;i<if_then_else->number_of_then_columns;i++){
                 disable_column_CFL(input,if_then_else->then_column_list[i]);
             }
        }
         else{
            for(unsigned i=0;i<if_then_else->number_of_else_columns;i++){
                disable_column_CFL(input,if_then_else->else_column_list[i]);
            }
        }
        return CONTINUE_CFL;
    }
   
    
    if(event_data->event_index == TIMER_TICK_CFL ){
        if((if_then_else->join_flag == false)&&(if_then_else->terminate_flag==false)){
            return DISABLE_CFL;
        }
        if((if_then_else->join_flag == false)&&(if_then_else->terminate_flag == true)){
            return CONTINUE_CFL;
        }
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            if(join_columns_CFL(input,if_then_else->number_of_then_columns,if_then_else->then_column_list) == true){
                return DISABLE_CFL;
            }
        }else{
            if(join_columns_CFL(input,if_then_else->number_of_else_columns,if_then_else->else_column_list) == true){
                return DISABLE_CFL;
            }
        }
    }
    return HALT_CFL;
    
}

            
void set_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Set_return_code_CFL_t *set_return_code = (Set_return_code_CFL_t *)params;
    for(unsigned i=0;i<set_return_code->column_number;i++){
        set_column_return_code_CFL(input,set_return_code->column_list[i],set_return_code->bool_flag);
    }
    
   
}
            
            
void display_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Display_return_code_CFL_t *display_return_code = (Display_return_code_CFL_t *)params;
    Printf_CFL(input,"Displaying column flags\n");
    for(unsigned i=0;i<display_return_code->column_number;i++){
        bool  column_value  = get_column_return_code_CFL(input,display_return_code->column_list[i]);
        Printf_CFL(input,"Column %d has column flag %d\n",display_return_code->column_list[i],column_value);
    }
    
   
}
            
void null_function(const void *handle,
    void *params, Event_data_CFL_t *event_data){
    (void)handle;
    (void)params;
    (void)event_data;
    return;
}

void send_queue_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  Queue_event_CFL_t *queue_event = (Queue_event_CFL_t *)params;
  Event_data_CFL_t *event_data_to_send = ( Event_data_CFL_t *)queue_event->event_data;
  
  unsigned event_queue_index = queue_event->event_queue_index;
  enqueue_column_event_CFL(input,event_queue_index,event_data_to_send); 

}


void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    
    Enable_column_CFL_t *enable_column = (Enable_column_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL )
    {
       
        for(unsigned i=0;i<enable_column->number_of_columns;i++){
            if(get_current_column_index_CFL(input) != enable_column->column_list[i]){
               enable_column_CFL(input,enable_column->column_list[i]);
            }
        }
        
        
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        if(enable_column->terminate_flag==true){
           for(unsigned i=0;i<enable_column->number_of_columns;i++){
              disable_column_CFL(input,enable_column->column_list[i]);
           }
        }
    }
        


}







void disable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
   (void)event_data;
    Disable_column_CFL_t *disable_column = (Disable_column_CFL_t *)params;

    for(unsigned short i=0;i<disable_column->number_of_columns;i++){
        disable_column_CFL(input,disable_column->column_list[i]);
    }

}




void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  Log_message_CFL_t *log_message = (Log_message_CFL_t *)params;
  
  unsigned column_index;
  int column_element_number;

  if(event_data->event_index == EVENT_INIT_CFL){
      column_index = get_current_column_index_CFL(input);
      column_element_number = get_current_column_element_index_CFL(input);
      Printf_CFL(input,"Log !!!! entering column index %d column element %d  ---> msg: %s\n",
              column_index, column_element_number, log_message->entry_message);
      return;
  }
  if(event_data->event_index == EVENT_TERMINATION_CFL){
      if(log_message->exit_flag == true){
        column_index = get_current_column_index_CFL(input);
        column_element_number = get_current_column_element_index_CFL(input);
        Printf_CFL(input,"Log !!!! Termination msg: %s\n",log_message->exit_message);
      }
      return;
  }
}


static void fn_output(const void *input, const Supervisor_data_CFL_t* data, unsigned max_count) {
    Printf_CFL(input,"column reset state \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset state %d \n",data->column_list[i],data->restart_mask[i]);
    }
    Printf_CFL(input,"column reset counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset count %d \n",data->column_list[i],data->reset_count[i]);
    }
    Printf_CFL(input,"reset all counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d secondary  reset count %d \n",data->column_list[i],data->secondary_reset_count[i]);
    }

    
    Printf_CFL(input,"max reset count %d \n",max_count);
    Printf_CFL(input,"terminate flag %d \n",data->terminate_flag);
    Printf_CFL(input,"Column is ending \n");
}
bool fn_column_control(const void* input, void* params, Event_data_CFL_t* event_data){
    
    const Supervisor_data_CFL_t *data = (const Supervisor_data_CFL_t*)params;

    if (event_data->event_index == EVENT_INIT_CFL ) {
        Printf_CFL(input,"one for one supervisor init \n");
        return true;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL) {
      
        Printf_CFL(input,"one for one supervisor terminate \n");
        return true;
    }
    if (event_data->event_index == SUPERVISOR_EVENT_CFL) {
        char* message = (char*)event_data->params;
        Printf_CFL(input,"Supervisor event received %s \n",message);
        return true;
    }
    // at this point only timer tick events are sent here
    unsigned max_count = 0;
   
    bool reset_flag = false;
    for (int i = 0; i < data->column_number; i++) {
        if (data->restart_mask[i] == true) {
            reset_flag = true;
        }
        if (data->reset_count[i] > max_count) {
            max_count = data->reset_count[i];   
        }
    }
    // implement an all fo one reset
    if (reset_flag == true) {
        for (int i = 0; i < data->column_number; i++) {
          if (data->restart_mask[i] == false) {
            data->restart_mask[i] = true;
            data->secondary_reset_count[i] += 1;
          }
        }
    }
    if (max_count > 15) {
       fn_output(input,data,max_count);
        return false;
    }
    return true;


}
   


bool bool_true_function(const void *input,void *params,Event_data_CFL_t *event_data)
{
    (void)event_data;
    char *message = (char *)params;
  
    Printf_CFL(input,"pass function -> %s \n",message);
    return true;  

}

bool true_constant_handler(void *handle, void *params,
                                  Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return true;
}

bool assert_flag_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    Assert_flag_CFL_t *assert_flag = (Assert_flag_CFL_t *)params;


    
    bool flag = get_column_return_code_CFL(input,assert_flag->column_index);
   
   
    if(flag != assert_flag->flag_value){
        return assert_flag->bool_fn(input,assert_flag->user_data,event_data);
    }
    
    return true;


}


bool bool_false_function(const void *input,void *params,Event_data_CFL_t *event_data)
{
    (void)event_data;
    char *message = (char *)params;
    
    Printf_CFL(input,"failure function -> %s \n",message);
    return false;  

}

static void one_for_one_output(const void *input, const Supervisor_data_CFL_t* data, unsigned max_count) {
    Printf_CFL(input,"column reset state \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset state %d \n",data->column_list[i],data->restart_mask[i]);
    }
    Printf_CFL(input,"column reset counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset count %d \n",data->column_list[i],data->reset_count[i]);
    }
    Printf_CFL(input,"reset all counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d secondary  reset count %d \n",data->column_list[i],data->secondary_reset_count[i]);
    }

    
    Printf_CFL(input,"max reset count %d \n",max_count);
    Printf_CFL(input,"terminate flag %d \n",data->terminate_flag);
    Printf_CFL(input,"Column is ending \n");
}
bool one_for_one_fn(const void* input, void* params, Event_data_CFL_t* event_data){
    
    const Supervisor_data_CFL_t *data = (const Supervisor_data_CFL_t*)params;

    if (event_data->event_index == EVENT_INIT_CFL ) {
        Printf_CFL(input,"one for one supervisor init \n");
        return true;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL) {
        Printf_CFL(input,"one for one supervisor terminate \n");
        return true;
    }
    if (event_data->event_index == SUPERVISOR_EVENT_CFL) {
        Printf_CFL(input,"Supervisor event received \n");
        return true;
    }
    // at this point only timer tick events are sent here
    unsigned max_count = 0;
   

    for (int i = 0; i < data->column_number; i++) {
   
        if (data->reset_count[i] > max_count) {
            max_count = data->reset_count[i];   
        }
    }
    
    if (max_count > 15) {
        one_for_one_output(input,data,max_count);
        return false;
    }
    return true;


}
   

 


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data)
{
  
  Handle_CFL_t *handle = (Handle_CFL_t *)input;
  const While_time_control_ROM_CFL_t *while_time_control = (const While_time_control_ROM_CFL_t *)params;
  
  if (event_data->event_index == EVENT_INIT_CFL)
  {
    
    *while_time_control->start_time = handle->time_control->current_millis;
    
    return false;
  }
  if (event_data->event_index == TIMER_TICK_CFL)
  {
    unsigned timeElasped = handle->time_control->current_millis - *while_time_control->start_time;
    if (timeElasped >= while_time_control->time_delay)
    {
      return true;
    }
  }

  return false;
}
bool false_constant_handler(void *handle, void *params,
                                   Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return false;
}

bool while_column_test(void* input, void* params, Event_data_CFL_t* event_data) {
  (void)input; // unused parameter 
  (void)event_data; // unused parameter
  While_column_control_CFL_t* while_control = (While_column_control_CFL_t*)params;
  
  
  
  
  const char** message = (const char**)while_control->user_data;
  Printf_CFL(input,*message); // testing user data
 
  Printf_CFL(input,"number of iterations %d max_iterations 4 \n",*while_control->current_count);
  if (*while_control->current_count >= 4) {
    Printf_CFL(input,"while column is terminating \n");
    return false;
  }
  Printf_CFL(input,"returning true \n");
  return true;
}


