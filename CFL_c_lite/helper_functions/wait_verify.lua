
local while_control_code = [[

typedef struct While_control_RAM_t{
    int current_count;
} While_control_RAM_t;


typedef struct While_control_ROM_t
{
    int time_out_ms;
    bool terminate_flag;
    void* user_data;
    While_control_RAM_t *while_control_ram;
    One_shot_function_CFL_t user_time_out_fn;
    
} While_control_ROM_t;


  
static int while_handler(void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
    While_control_RO_t *while_ctrl;
    While_control_ROM_t while_ctrl = (While_control_ROM_t *)params;
    While_control_RAM_t *while_ctrl_ram = while_ctrl->while_control_ram;

    if (event_data->event_index == EVENT_INIT_CFL)
    {

        while_ctrl_ram->current_count = 0;
        bool_fn(handle, while_ctrl->user_data, event_data);
        return CONTINUE_CFL;
    }

    if (bool_fn(handle, while_ctrl->user_data, event_data) == true)
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
    while_ctrl_ram->current_count += event_data->event_data;
    if (while_ctrl_ram->current_count < while_ctrl->time_out_ms)
    {
        return HALT_CFL;
    }
    // Time out at this point
    while_ctrl->user_time_out_fn(handle, while_ctrl->user_data, event_data);

    return generate_return_code(while_ctrl->terminate_flag);
}


]]

Store_column_function("WHILE_HANDLER",'while_handler',while_control_code)

local while_template_data_rom = [[


static const While_control_ROM_t *%s_rom = { %d ,%s, %s,%s,&%s_ram}\n;  // time out,terminate flag,user data,one shot function,link to ram structure
    
]]

local while_template_data_ram = [[

    static While_control_RAM_t *%s_ram = { 0 };\n current count

]]



function Wait(bool_fn_name, time_out_ms, terminate_flag, one_shot_time_out_fn, user_data)
  local fn_column = Get_column_function("WHILE_HANDLER")
  local fn_boolean = Get_boolean_function(bool_fn_name)
  local fn_time_out = Get_one_shot_function(one_shot_time_out_fn)
  -- generate unique name
  local unique_name = generate_unique_function_name()
  local message = string.format(while_template_data_ram, unique_name)
  Store_user_code(message)
  message = string.format(while_template_data_rom, unique_name, time_out_ms, tostring(terminate_flag), 
                        tostring(user_data), one_shot_time_out_fn, unique_name)
  Store_user_code(message)

  
  Store_column_element(fn_column, fn_boolean,'(void *)'..unique_name..'_rom')
end



local verify_handler_code = [[


typedef struct Verify_control_ROM_t
{
   bool terminate_flag;
   void* user_data;
   One_shot_function_CFL_t user_termination_fn;
} Verify_control_ROM_t;

// handle time_out_ms -1

static int verify_handler(void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    

    Verify_control_ROM_t *verify_control = (Verify_control_ROM_t *)params;
    if (event_data->event_index == EVENT_INIT_CFL)
    {

        fn(handle, verify_control->user_data, event_data);
        return CONTINUE_CFL;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {
        return CONTINUE_CFL;
    }

    if (fn(handle, verify_control->user_data, event_data) == false)
    {
        if (verify_control->user_termination_fn != NULL)
        {
            verify_control->user_termination_fn(handle, verify_control->user_data,event_data);
        }
        return generate_return_code(verify_control->terminate_flag);
    }
    return CONTINUE_CFL;
}

]]
Store_column_function("VERIFY_HANDLER",'verify_handler',verify_handler_code)


local verify_template_data_rom = [[
    static Verify_control_ROM_t *%s_rom = { %s, %s, %s };\n;  // terminate flag,user data,one shot function
]]

function Verify(bool_fn_name, time_out_ms, terminate_flag, one_shot_time_out_fn, user_data)
    local fn_column = Get_column_function("VERIFY_HANDLER")
    local fn_boolean = Get_boolean_function(bool_fn_name)
    local fn_time_out = Get_one_shot_function(one_shot_time_out_fn)

    local unique_name = generate_unique_function_name()
    
    message = string.format(verify_template_data_rom, unique_name,terminate_flag,user_data,one_shot_time_out_fn)
    Store_user_code(message)

    
    Store_column_element(fn_column, fn_boolean,'(void *)'..unique_name..'_rom')
  end
  







local while_event_control_code = [[

typedef struct While_event_control_RAM_t
{
    unsigned short current_count;
} While_event_control_RAM_t;

typedef struct While_event_control_ROM_t
{
   unsigned short  number_of_events;
   short     event_index;
   int       time_out_ms;
   bool      terminate_flag;
   void* user_data;
   One_shot_function_CFL_t user_termination_fn;
   While_event_control_RAM_t *while_event_control_ram;

} While_event_control_ROM_t;




static bool wait_event_handler(void *handle, void *params,
                               Event_data_CFL_t *event_data)
{
  (void)handle;
 

  While_event_control_ROM_t *while_event_control_rom = (While_event_control_ROM_t *)params;
  While_event_control_RAM_t *while_event_control_ram = while_event_control_rom->while_event_control_ram;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    while_event_control_ran->current_count = 0;
    
    return true;
  }
  
  if (event_data->event_index == while_event_control->event_index)
  {

    while_event_control_ram->current_count += 1;
    if (while_event_control_ram->current_count >=
        while_event_control_rom->number_of_events)
    {
    
      return true;
    }
  }

  return false;
}
]]
Store_boolean_function("WAIT_EVENT",'wait_event_handler', while_event_control_code)


local wait_event_ram = [[
    While_event_control_RAM_t *%s_ram = { 0,0 };\n
]]
local wait_event_rom = [[
    While_event_control_ROM_t *%s_rom = { %d,%d,%d,%s,%s,%s };\n;  // number of events,event index,time out,terminate flag,user data,one shot function
]]

function Wait_event(event_id, number_of_events, time_out_ms, terminate_flag, one_shot_time_out_name, user_data)
  local boolean_fn_name = Get_boolean_function("WAIT_EVENT")
  local column_fn_name = Get_column_function("WHILE_HANDLER")
  local one_shot_time_out_fn_name = Get_one_shot_function(one_shot_time_out_name)
  local unique_name = generate_unique_function_name()
  local message = string.format(wait_event_ram, unique_name)
  Store_user_code(message)
  message = string.format(wait_event_rom, unique_name,number_of_events,event_id,time_out_ms, tostring(terminate_flag), 
                            tostring(user_data), one_shot_time_out_fn)
  Store_user_code(message)
  Wait(boolean_fn_name, time_out_ms, terminate_flag, one_shot_time_out_fn,'(void *)'..unique_name..'_rom')
end


local wait_time_delay_code = [[
typedef struct While_time_control_CFL_t
{
    unsigned time_delay;
    unsigned ending_time;
} While_time_control_CFL_t;
    

static bool wait_time_delay(void *input, void *params,
                            Event_data_CFL_t *event_data)
{
  

  While_time_control_RAM_t *while_time_control = (While_time_control_RAM_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    
    while_time_control->ending_time =
        Get_current_ms_value(input) + while_time_control->time_delay;

    return false;
  }
  if (event_data->event_index == TIMER_TICK_CFL)
  {
    if (while_time_control->ending_time <= Get_current_ms_value(input))
    {
      return true;
    }
  }

  return false;
}
]]
Store_boolean_function("WAIT_TIME_DELAY",'wait_time_delay', wait_time_delay_code)

local wait_time_delay_ram = [[
    While_time_control_RAM_t *%s_ram = { 0,0 };\n current count
]]


function Wait_delay(time_delay_ms)
  local boolean_name = Get_boolean_function("WAIT_TIME_DELAY")
  local column_fn_name = Get_column_function("WHILE_HANDLER")
  local unique_name = generate_unique_function_name()
  local message = string.format(wait_time_delay_ram, unique_name)
  Store_user_code('unsigned '..unique_name..' = '..time_delay_ms..';\n')
  store_column_element(column_fn_name,boolean_name,'(void *)'..unique_name..'_ram')
end





local true_constant_handler_code = [[

static bool true_constant_handler(void *handle, void *params,
                                  Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return true;
}
]]
Store_boolean_function("TRUE",'true_constant_handler', true_constant_handler_code)

local false_constant_handler_code = [[
static bool false_constant_handler(void *handle, void *params,
                                   Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return false;
}
]]

Store_boolean_function("FALSE",'false_constant_handler', false_constant_handler_code)







