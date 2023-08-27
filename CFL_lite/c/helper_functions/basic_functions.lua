
local one_shot_header = [[

int one_shot_handler_CFL(void *handle, void *aux_fn, void *params,
                            Event_data_CFL_t *event_data)

]]


local one_shot_handler = [[


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
]]

local bidirectional_one_shot_handler = [[

int bidirectional_one_shot_handler_CFL(void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local bidirectional_one_shot_handler = [[

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
]]

local log_msg_header = [[


void log_message_CFL(void *input, void *params,
                        Event_data_CFL_t *event_data);

]]

local log_msg_handler = [[

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

]]

Store_column_function("ONE_SHOT",'CFL_one_shot_handler',one_shot_handler,one_shot_header)
Store_column_function("BID_ONE_SHOT",'CFL_bidirectional_one_shot_handler',bidirectional_one_shot_handler,bidirectional_one_shot_header)


Store_one_shot_function("Log_msg",'CFL_log_message',log_msg_handler,log_msg_header)  


function Log_msg(message)
  Activate_column_function("ONE_SHOT")
  Activate_one_shot_function("Log_msg")
  local one_shot_fn_name = Get_one_shot_function("Log_msg")
  local column_fn_name = Get_column_function("ONE_SHOT")
  local unique_name = generate_unique_function_name()
  Store_user_code('const char *'..unique_name..' = '..quote_string(message)..';\n')
  store_column_element(column_fn_name,one_shot_fn_name,'(void *)'..unique_name)
end


function One_shot(fn_string, user_data)
 
  Activate_column_function("ONE_SHOT")
  Activate_one_shot_function(fn_string)
  local one_shot_fn_name = Get_one_shot_function(fn_string)
  local column_fn_name = Get_column_function("ONE_SHOT")
  store_column_element(column_fn_name,one_shot_fn_name,'(void *)'..user_data)
end  

function One_shot_terminate(fn_string, user_data)
  Activate_column_function("BID_ONE_SHOT")
  Activate_one_shot_function(fn_string)
  local one_shot_fn_name = Get_one_shot_function(fn_string)
  local column_fn_name = Get_column_function("BID_ONE_SHOT")
  store_column_element(column_fn_name,one_shot_fn_name,'(void *)'..user_data)
end  

---
---
--- Code for dump nodes
---
---


function Dump_nodes()

end



