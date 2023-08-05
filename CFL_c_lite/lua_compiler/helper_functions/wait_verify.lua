
local while_control_header_code = [[


typedef struct While_control_RAM_CFL_t{
    int current_count;
} While_control_RAM_CFL_t;


typedef struct While_control_ROM_t
{
    const int time_out_ms;
    const bool terminate_flag;
    const void* user_data;
    While_control_RAM_CFL_t *while_control_ram;
    One_shot_function_CFL_t user_time_out_fn;
    
} While_control_ROM_CFL_t;

int while_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data);

]]
local while_control_code = [[
  static inline int generate_return_code_while(bool termination_flag)
  {
    if (termination_flag == true)
    {
      return TERMINATE_CFL;
    }
    return RESET_CFL;
  }  
int while_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
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


]]

Store_column_function("WHILE_HANDLER",'while_handler_CFL',while_control_code,while_control_header_code)

local while_template_data_rom = [[

  

static const While_control_ROM_CFL_t %s_rom = { %d ,%s, %s,&%s_ram,%s};

    
]]


local while_template_data_ram = [[

static While_control_RAM_CFL_t %s_ram = { 0 };  // current count 

]]


function Wait(bool_fn_name, time_out_ms, terminate_flag, one_shot_time_out_fn, user_data)
 
  local fn_column = Get_column_function("WHILE_HANDLER")
  local fn_boolean = Get_boolean_function(bool_fn_name)
  local fn_time_out = Get_one_shot_function(one_shot_time_out_fn)
  

  -- generate unique name
  local unique_name_ram = generate_unique_function_name()
  local message = string.format(while_template_data_ram, unique_name_ram)

  Store_user_code(message)
  local unique_name_rom = generate_unique_function_name()
 
  if user_data == 'NULL' then
    user_data = 'NULL'
  else
    user_data = '&'..user_data
  end


 
  message = string.format(while_template_data_rom, unique_name_rom, time_out_ms, tostring(terminate_flag), 
                        tostring(user_data),unique_name_ram,fn_time_out)
  Store_user_code(message)

  store_column_element(fn_column, fn_boolean,'(void *)&'..unique_name_rom..'_rom')
end



local verify_control_header_code = [[


typedef struct Verify_control_ROM_CFL_t
{
   bool terminate_flag;
   void* user_data;
   One_shot_function_CFL_t user_termination_fn;
} Verify_control_ROM_CFL_t;



int verify_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data);

]]
local verify_handler_code = [[
  static inline int generate_return_code_verify(bool termination_flag)
  {
    if (termination_flag == true)
    {
      return TERMINATE_CFL;
    }
    return RESET_CFL;
  }

int verify_handler_CFL(const void *handle, void *aux_fn, void *params,Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    

    Verify_control_ROM_CFL_t *verify_control = (Verify_control_ROM_CFL_t *)params;
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
        return generate_return_code_verify(verify_control->terminate_flag);
    }
    return CONTINUE_CFL;
}

]]
Store_column_function("VERIFY_HANDLER",'verify_handler_CFL',verify_handler_code,verify_control_header_code)


local verify_template_data_rom = [[
    static Verify_control_ROM_CFL_t %s_rom = { %s, %s, %s };  // terminate flag,user data,one shot function
]]

function Verify(bool_fn_name, terminate_flag, one_shot_time_out_fn, user_data)
    local fn_column = Get_column_function("VERIFY_HANDLER")
    local fn_boolean = Get_boolean_function(bool_fn_name)
    local fn_time_out = Get_one_shot_function(one_shot_time_out_fn)

    local unique_name = generate_unique_function_name()
    
    message = string.format(verify_template_data_rom, unique_name,terminate_flag,user_data,fn_time_out)
    Store_user_code(message)

    
    store_column_element(fn_column, fn_boolean,'(void *)&'..unique_name..'_rom')
  end
  





local wait_event_control_header_code = [[





typedef struct While_event_control_ROM_t
{
   unsigned   number_of_events;
   short     event_index;
   int       time_out_ms;
   bool      terminate_flag;
   const void* user_data;
   unsigned  *current_count;
  
} While_event_control_ROM_t;

bool wait_event_handler(const void *handle, void *params,
                               Event_data_CFL_t *event_data);
]]

local while_event_control_code = [[


bool wait_event_handler(const void *handle, void *params,
                               Event_data_CFL_t *event_data)
{
  (void)handle;
 
   
  const While_event_control_ROM_t *while_event_control_rom = (const While_event_control_ROM_t *)params;
  unsigned *current_count = while_event_control_rom->current_count;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    *current_count = 0;
    
    return true;
  }
  
  if (event_data->event_index == while_event_control_rom->event_index)
  {

    *current_count += 1;
    if (*current_count >= while_event_control_rom->number_of_events)
    {
    
      return true;
    }
  }

  return false;
}
]]
Store_boolean_function("WAIT_EVENT",'wait_event_handler', while_event_control_code,wait_event_control_header_code)


local wait_event_ram = [[
 unsigned %s_ram;
]]
local wait_event_rom = [[
const While_event_control_ROM_t %s_rom = { %s,%s,%s,%s,%s,&%s_ram };  
// number of events,event index,time out,terminate flag, ram_pit
]]


function Wait_event(event_id, number_of_events, time_out_ms, terminate_flag, one_shot_time_out_name, user_data)
  
  
  local unique_name = generate_unique_function_name()
  local message = string.format(wait_event_ram, unique_name)
  Store_user_code(message)
  message = string.format(wait_event_rom, unique_name,number_of_events,event_id,time_out_ms, tostring(terminate_flag),user_data,unique_name)
  Store_user_code(message)
 
  Wait("WAIT_EVENT", time_out_ms, terminate_flag, one_shot_time_out_name,unique_name..'_rom')
 
end


local wait_time_delay_header_code = [[

     
typedef struct While_time_control_ROM_t
{
   unsigned  time_delay;
   unsigned  *start_time;
} While_time_control_ROM_CFL_t;


bool wait_time_delay_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);
]]


local wait_time_delay_code = [[
 


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
]]



Store_boolean_function("WAIT_TIME_DELAY",'wait_time_delay_CFL', wait_time_delay_code,wait_time_delay_header_code)

local wait_time_delay_ram = [[


unsigned  %s;
const While_time_control_ROM_CFL_t %s = { %s,&%s };


]]


function Wait_delay(time_delay_ms)
  
  local unique_name_struct = generate_unique_function_name()
  local unique_name_end_time = generate_unique_function_name()


  local message = string.format(wait_time_delay_ram, unique_name_end_time,unique_name_struct,time_delay_ms,unique_name_end_time)
  Store_user_code(message)
  Wait("WAIT_TIME_DELAY", 0, true, 'NULL', unique_name_struct)
end

local true_constant_header_code = [[
bool true_constant_handler(void *handle, void *params,
  Event_data_CFL_t *event_data); 
]]

local true_constant_handler_code = [[

bool true_constant_handler(void *handle, void *params,
                                  Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return true;
}
]]

Store_boolean_function("TRUE",'true_constant_handler', true_constant_handler_code,true_constant_header_code)

local false_constant_header_code = [[
bool false_constant_handler(void *handle, void *params,
  Event_data_CFL_t *event_data);
]]


local false_constant_handler_code = [[
bool false_constant_handler(void *handle, void *params,
                                   Event_data_CFL_t *event_data)
{
  (void)handle;
  (void)params;
  (void)event_data;
  return false;
}
]]

Store_boolean_function("FALSE",'false_constant_handler', false_constant_handler_code,false_constant_header_code)







