
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


void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data);

]]

local log_msg_handler = [[

void log_message_CFL(const void *input, void *params,
                        Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char **message;
  
  unsigned column_index;
  int column_element_number;
  message = (char **)params;

  column_index = get_current_column_index_CFL(input);
  column_element_number = get_current_column_element_index_CFL(input);
  Printf_CFL("Log !!!! column index %d column element %d  ---> msg: %s\n",
              column_index, column_element_number, *message);
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
  printf("Sending event to queue %d %d\n",queue_event->event_queue_index,queue_event->event_data->event_index);
  unsigned event_queue_index = queue_event->event_queue_index;
  enqueue_event_CFL(input,event_queue_index,event_data_to_send); 

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

function Log_msg(message)
  Activate_column_function("ONE_SHOT")
  Activate_one_shot_function("Log_msg")
  local one_shot_fn_name = Get_one_shot_function("Log_msg")
  local column_fn_name = Get_column_function("ONE_SHOT")
  local unique_name = generate_unique_function_name()
  Store_user_code('static const char *'..unique_name..' = '..quote_string(message)..';\n')
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
   
    store_local_column_data(input,column_data->column_id[i],(void *)column_data->user_data);
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
  Activate_one_shot_function("Send_event")
  One_shot("STORE_COLUMN_DATA",  column_data_name)
end




