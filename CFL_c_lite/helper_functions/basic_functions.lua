
local one_shot_handler = [[


static int one_shot_handler(void *handle, void *aux_fn, void *params,
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

static int bidirectional_one_shot_handler(void *handle, void *aux_fn, void *params, Event_data_CFL_t *event_data)
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

local log_msg_handler = [[

static void log_message(void *input, void *params,
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

Store_column_function("ONE_SHOT",'one_shot_handler',one_shot_handler)
Store_column_function("BID_ONE_SHOT",'bidirectional_one_shot_handler',bidirectional_one_shot_handler)


Store_one_shot_function("Log_msg",'log_message',log_msg_handler)  


function Log_msg(message)
  Activate_column_function("ONE_SHOT")
  Activate_one_shot_function("Log_msg")
  local unique_name = generate_unique_function_name()
  Store_user_code('const char *'..unique_name..' = '..quote_string(message)..';\n')
  store_column_element('one_shot_handler','log_msg_handler','(void *)'..unique_name)
end

--[[
function Log_msg(message)
    message = quote_string(message)
    local message  = string.format("    Asm_log_message_CFL(input,%s);\n",message)
    file:write(message)
end

function Wait_delay(delay)
    local message = string.format("    Asm_wait_time_delay_CFL(input,%s);\n",delay)
    file:write(message)
end


function One_shot(fn_string, fn_parameter)
    fn_string = quote_string(fn_string)
    local message = string.format("    Asm_one_shot_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    file:write(message) 
end  

function One_shot_terminate(fn_string, fn_parameter)
    fn_string = quote_string(fn_string)
    local message = string.format("    Asm_one_shot_terminate_CFL(input,%s,%s);\n",fn_string,fn_parameter)
    file:write(message) 
end
]]
