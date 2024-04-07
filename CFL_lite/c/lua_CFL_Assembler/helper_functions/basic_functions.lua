
local one_shot_header = [[

int one_shot_handler_CFL(const void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data);

]]


local one_shot_handler = [[


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
]]

local bidirectional_one_shot_header = [[

int bidirectional_one_shot_handler_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local bidirectional_one_shot_handler = [[

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
]]

local log_msg_header = [[
typedef struct Log_message_CFL_t{
   const char *entry_message;
   const bool  exit_flag;
   const char *exit_message;
}Log_message_CFL_t;

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);

]]

local log_msg_handler = [[

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

]]

local send_queue_event_header = [[

typedef struct Queue_event_CFL_t
{
  unsigned         event_queue_index;
  const Event_data_CFL_t *event_data;
}Queue_event_CFL_t;


void send_queue_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local send_queue_event_code = [[

void send_queue_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  Queue_event_CFL_t *queue_event = (Queue_event_CFL_t *)params;
  Event_data_CFL_t *event_data_to_send = ( Event_data_CFL_t *)queue_event->event_data;
  
  unsigned event_queue_index = queue_event->event_queue_index;
  enqueue_column_event_CFL(input,event_queue_index,event_data_to_send); 

}

]]

local send_event_header = [[

void send_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local send_event_code = [[

void send_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  Event_data_CFL_t *event_data_to_send = (Event_data_CFL_t *)params;
  enqueue_event_CFL(input,0,event_data_to_send); 

}

]]


Store_column_function("ONE_SHOT",'one_shot_handler_CFL',one_shot_handler,one_shot_header)
Store_column_function("BID_ONE_SHOT",'bidirectional_one_shot_handler_CFL',bidirectional_one_shot_handler,bidirectional_one_shot_header)

Store_one_shot_function("Send_event",'send_event_CFL',send_event_code,send_event_header)
Store_one_shot_function("Log_msg",'log_message_CFL',log_msg_handler,log_msg_header) 

Store_one_shot_function("Send_queue_event",'send_queue_event_CFL',send_queue_event_code,send_queue_event_header)

function Log_msg(message,message_exit)
  
  local message_print = string.format('-%s-',message_exit)
 
  if message_exit == nil then
 
    message_exit = 'NULL'
    messsage_exit_flag = false
    message = string.format('"%s"',message)

    
  else
    
    messsage_exit_flag = true
    message = string.format('"%s"',message)
    message_exit = string.format('"%s"',message_exit)
  end
  local column_fn_name
  if message_exit_flag == false then
      Activate_column_function("ONE_SHOT")
      column_fn_name = Get_column_function("ONE_SHOT")
     
  else
      Activate_column_function("BID_ONE_SHOT")
      column_fn_name = Get_column_function("BID_ONE_SHOT")
  end
  local one_shot_fn_name = Get_one_shot_function("Log_msg")
  
  local unique_name = generate_unique_function_name()
  local message = string.format("static const Log_message_CFL_t %s = { %s, %s, %s };\n",unique_name,message,messsage_exit_flag,message_exit)
  Store_user_code(message)
  store_column_element(column_fn_name,one_shot_fn_name,'(void *)&'..unique_name)
end

function One_shot_raw(one_shot_function,user_data)
  Activate_column_function("ONE_SHOT")
  local column_fn_name = Get_column_function("ONE_SHOT")
  if user_data ~= "NULL" then
    store_column_element(column_fn_nameone_shot_function,'(void *)&'..user_data)
  else
    store_column_element(column_fn_name,one_shot_function,'NULL')
  end
end

function One_shot(fn_string, user_data)
 
  Activate_column_function("ONE_SHOT")
  Activate_one_shot_function(fn_string)
  local one_shot_fn_name = Get_one_shot_function(fn_string)
  local column_fn_name = Get_column_function("ONE_SHOT")
  if user_data ~= "NULL" then
      store_column_element(column_fn_name,one_shot_fn_name,'(void *)&'..user_data)
  else
      store_column_element(column_fn_name,one_shot_fn_name,'NULL')
  end
end  

function One_shot_terminate_raw(function_name, user_data)
  Activate_column_function("BID_ONE_SHOT")
  Activate_one_shot_function(function_name)
  local column_fn_name = Get_column_function("BID_ONE_SHOT")
  if user_data ~= "NULL" then
    store_column_element(column_fn_name,function_name,'(void *)&'..user_data)
  else
    store_column_element(column_fn_name,function_name,'NULL')
  end
end
    

function One_shot_terminate(fn_string, user_data)
  Activate_column_function("BID_ONE_SHOT")
  Activate_one_shot_function(fn_string)
  local one_shot_fn_name = Get_one_shot_function(fn_string)
  local column_fn_name = Get_column_function("BID_ONE_SHOT")
  if user_data ~= "NULL" then
    store_column_element(column_fn_name,one_shot_fn_name,'(void *)&'..user_data)
  else
    store_column_element(column_fn_name,one_shot_fn_name,'NULL')
  end  
end

local generate_event_string = [[
const Event_data_CFL_t %s = { %s, %s, %s };
]]

function generate_event(event_index, malloc_flag, params)

  name = generate_unique_function_name()
  local message = string.format(generate_event_string,name,event_index, malloc_flag, params )
  Store_user_code(message) 
  return name
end

function send_global_event(event_data)
  Activate_column_function("ONE_SHOT")
  Activate_one_shot_function("Send_event")
  local one_shot_fn_name = Get_one_shot_function("Send_event")
  local column_fn_name = Get_column_function("ONE_SHOT")
  store_column_element(column_fn_name,one_shot_fn_name,'(void *)&'..event_data)
end

local queue_format_string = "const Queue_event_CFL_t %s = { %s, &%s };\n"

function send_queue_event(event_queue_name,event_data)
  event_queue_id = lookup_named_queue(event_queue_name)
  Activate_column_function("ONE_SHOT")
  Activate_one_shot_function("Send_queue_event")
  local one_shot_fn_name = Get_one_shot_function("Send_queue_event")
  local column_fn_name = Get_column_function("ONE_SHOT")
  local queue_structure = generate_unique_function_name()
  Store_user_code(string.format(queue_format_string,queue_structure,event_queue_id,event_data))

  store_column_element(column_fn_name,one_shot_fn_name,'(void *)&'..queue_structure)
end

local conditional_send_event_header = [[

typedef struct Conditional_send_event_CFL_t
{
  unsigned short number_of_columns; 
  unsigned short *queue_id;
}Conditional_send_event_CFL_t;


int conditional_send_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local conditional_send_event_code = [[

int conditional_send_event_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
  
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    const Conditional_send_event_CFL_t *conditional_send_event = (const Conditional_send_event_CFL_t *)params;
    if (event_data->event_index == EVENT_INIT_CFL)
    {
      fn(input, params, event_data);
      return HALT_CFL;
    }

]]

local column_data_header = [[

typedef struct Column_data_CFL_t
{
  unsigned short number_of_columns; 
  unsigned short *column_id;
  void *user_data;
}Column_data_CFL_t;


void store_column_data(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local column_data_code = [[

void store_column_data(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  const Column_data_CFL_t *column_data = (const Column_data_CFL_t *)params;
  for(unsigned i= 0; i< column_data->number_of_columns; i++)
  {
   
  
    store_column_data_CFL(input,column_data->column_id[i],(void *)column_data->user_data);
  }

}

]]

Store_one_shot_function("STORE_COLUMN_DATA",'store_column_data',column_data_code,column_data_header)

function Store_column_data(column_list ,column_data)
  column_array = generate_unique_function_name()
  local message = string.format("static unsigned short %s[] = { ",column_array)
  Store_user_code(message) 
  for i,v in ipairs(column_list) do
    local column_number =get_column_number(v)
    Store_user_code(column_number)
    if i ~= #column_list then
      Store_user_code(",")
    end
  end
  Store_user_code("};\n")
  local column_data_name = generate_unique_function_name()
  if column_data ~= "NULL" then
     local message = string.format("static const Column_data_CFL_t %s = { %d, %s, (void *)&%s };\n",column_data_name,#column_list,column_array,column_data)
     Store_user_code(message) 
  else
      local message = string.format("static const Column_data_CFL_t %s = { %d, %s, NULL };\n",column_data_name,#column_list,column_array)
      Store_user_code(message) 
  end      
  Activate_one_shot_function("STORE_COLUMN_DATA")
  One_shot("STORE_COLUMN_DATA",  column_data_name)
end


local terminate_reset_header = [[



int terminate_reset_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);


]]

local terminate_reset_code = [[

int terminate_reset_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{

  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    return HALT_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    return HALT_CFL;
  }
  
  
  if(fn(handle, params, event_data) == true)
  {
    return TERMINATE_CFL;
  }

  return RESET_CFL;
}

]]

Store_column_function("TERMINATE_RESET_CFL",'terminate_reset_CFL',terminate_reset_code,terminate_reset_header)

function Terminate_reset(bool_func, user_data)
  if user_data == nil then
    user_data = "NULL"
  end
 
  local bool_function_name = Get_boolean_function(bool_func)
  local column_fn_name = Get_column_function("TERMINATE_RESET_CFL")
  print("column_fn_name",column_fn_name)
  if user_data ~= "NULL" then
    store_column_element(column_fn_name,bool_function_name,'(void *)&'..user_data)
  else
    store_column_element(column_fn_name,bool_function_name,'NULL')
  end
  
end

local conditional_send_header = [[

typedef struct Conditional_send_event_CFL_t 
{
  unsigned short number_of_columns; 
  unsigned short *queue_id;
}Conditional_send_event_CFL_t;

int conditional_send_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);


]]

local conditional_send_code = [[

int conditional_send_CFL(const void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{

  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;


  const Conditional_send_event_CFL_t *conditional_send_event = (const Conditional_send_event_CFL_t *)params;


  if (event_data->event_index == EVENT_INIT_CFL)
  {
    fn(handle, params, event_data);
    return HALT_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    fn(handle, params, event_data);
    return HALT_CFL;
  }
  
  
  if(fn(handle, params, event_data) == true)
  {
     for(unsigned i= 0; i< conditional_send_event->number_of_columns; i++)
      {
        
        enqueue_column_event_CFL(handle,conditional_send_event->queue_id[i],event_data);
      }
    
  }

  return CONTINUE_CFL;
}

]]

Store_column_function("CONDITIONAL_SEND_EVENT",'conditional_send_CFL',conditional_send_code,conditional_send_header)

function conditional_send_event( bool_fn, list_of_columns)
  local bool_fn_name = Get_boolean_function(bool_fn)
  local column_fn_name = Get_column_function("CONDITIONAL_SEND_EVENT")

  local column_array = generate_unique_function_name()
  local message = string.format("static unsigned short %s[] = { ",column_array)
  Store_user_code(message) 
  for i,v in ipairs(list_of_columns) do
    local column_number =get_column_number(v)
    local queue_number = lookup_named_queue(v)
    Store_user_code(queue_number)
    if i ~= #list_of_columns then
      Store_user_code(",")
    end
  end
  Store_user_code("};\n")
  local column_data_name = generate_unique_function_name()
  local message = string.format("static const Conditional_send_event_CFL_t %s = { %d, %s};\n",column_data_name,#list_of_columns,column_array)
  Store_user_code(message) 
  store_column_element(column_fn_name,bool_fn_name,'(void *)&'..column_data_name)
end

local terminate_reset_header = [[

typedef struct display_event_CFL_t 
{
  unsigned short number_of_columns; 
  unsigned short *event_array;

}display_event_CFL_t;

int display_event_CFL(const void *input,void *aux_fn, void *params,Event_data_CFL_t *event_data);


]]

local terminate_reset_code = [[

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

]]



Store_column_function("DISPLAY_EVENT",'display_event_CFL',terminate_reset_code,terminate_reset_header)

function display_event( list_of_events)

  local column_fn_name = Get_column_function("DISPLAY_EVENT")

  local event_array = generate_unique_function_name()
  local message = string.format("static unsigned short %s[] = { ",event_array)
  Store_user_code(message) 
  for i,v in ipairs(list_of_events) do
   
    Store_user_code(v)
    if i ~= #list_of_events then
      Store_user_code(",")
    end
  end
  Store_user_code("};\n")
  local event_data_name = generate_unique_function_name()
  local message = string.format("static const display_event_CFL_t %s = { %d, %s};\n",event_data_name,#list_of_events,event_array)
  Store_user_code(message) 
  store_column_element(column_fn_name,"NULL",'(void *)&'..event_data_name)
end


local send_front_queue_event_header = [[

typedef struct Front_queue_event_CFL_t
{
  unsigned         column_id;
  const Event_data_CFL_t *event_data;
}Front_queue_event_CFL_t;

void send_front_queue_event_CFL(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local send_front_queue_event_code = [[

void send_front_queue_event_CFL(const void *input,void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
  const Front_queue_event_CFL_t *front_queue_event = (const Front_queue_event_CFL_t *)params;
 

  front_enqueue_column_index_event_CFL(input,front_queue_event->column_id, (Event_data_CFL_t *)front_queue_event->event_data); 
                    
}

]]

Store_one_shot_function("Send_front_queue_event",'send_front_queue_event_CFL',send_front_queue_event_code,send_front_queue_event_header)



function push_front_event(event_data,column_name)

  if column_name == nil then
    column_name = active_column["name"]
  end
  
  local column_number = get_column_number(column_name)
  
 
  Activate_column_function("ONE_SHOT")

  local one_shot_fn_name = Get_one_shot_function("Send_front_queue_event")
  local column_fn_name = Get_column_function("ONE_SHOT")
  local unique_name = generate_unique_function_name()
  local message = string.format("static const Front_queue_event_CFL_t %s = { %d, &%s };\n",unique_name,column_number,event_data)
  Store_user_code(message)

  store_column_element(column_fn_name,one_shot_fn_name,'(void *)&'..unique_name)
end


local residual_column_event_header = [[

typedef struct Residual_column_event_CFL_t
{
  const unsigned  column_id;
  const void *user_data;
}Residual_column_event_CFL_t;

int process_residual_column_event_queue(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);


]]
local residual_column_event_code = [[

int process_residual_column_event_queue(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data)
{
  
  (void)event_data;
  const Residual_column_event_CFL_t *residual_column_event = (const Residual_column_event_CFL_t *)params;
  One_shot_function_CFL_t fn = (One_shot_function_CFL_t)aux_fn;

  if(event_data->event_index == EVENT_TERMINATION_CFL){
   
    unsigned queue_id = residual_column_event->column_id + 1;
 
    while(is_queue_empty_CFL( input, queue_id ) == false){
     
      Event_data_CFL_t *event_data = peak_event_CFL(input,queue_id);
     
      fn(input,(void*)residual_column_event->user_data,event_data);
     
      dequeue_event_CFL(input,queue_id);
    }
    return TERMINATE_CFL;
  }
  
  return CONTINUE_CFL;
}


]]

Store_column_function("RESIDUAL_COLUMN_EVENT",'process_residual_column_event_queue',residual_column_event_code,residual_column_event_header)

function process_residual_named_event_queue(one_shot_fn,user_data, column_name)
  if column_name == nil then
    column_name = active_column["name"]
  end
  local one_shot_fn_name = Get_one_shot_function(one_shot_fn)
  local column_fn_name = Get_column_function("RESIDUAL_COLUMN_EVENT")
  local unique_name = generate_unique_function_name()
  local column_number = get_column_number(column_name)
  local message = string.format("static const Residual_column_event_CFL_t %s = { %d, (void *)%s };\n",unique_name,column_number,user_data)
  Store_user_code(message)
  store_column_element(column_fn_name,one_shot_fn_name,'(void *)&'..unique_name)
end


local reset_queue_header = [[
typedef struct Reset_queue_CFL_t
{
  const unsigned  column_id;
  
}Reset_queue_CFL_t;


void Reset_queue_CFL(const void *input, void *params,Event_data_CFL_t *event_data);

]]


local reset_queue_code = [[
void Reset_queue_CFL(const void *input, void *params,Event_data_CFL_t *event_data)
{
  (void)event_data;
  const Reset_queue_CFL_t *reset_queue = (const Reset_queue_CFL_t *)params;
  unsigned queue_id = reset_queue->column_id + 1;
  reset_queue_CFL(input,queue_id);
}

]]

Store_one_shot_function("RESET_QUEUE",'reset_queue_CFL',reset_queue_code,reset_queue_header)

function reset_queue(column_name)
  if column_name == nil then
    column_name = active_column["name"]
  end
  local column_number = get_column_number(column_name)
  local column_fn_name = Get_column_function("RESET_QUEUE")
  local unique_name = generate_unique_function_name()
  local message = string.format("static const Reset_queue_CFL_t %s = { %d };\n",unique_name,column_number)
  Store_user_code(message)
  local one_shot_fn_name = Get_one_shot_function("RESET_QUEUE")
  One_shot("RESET_QUEUE",unique_name)
end

