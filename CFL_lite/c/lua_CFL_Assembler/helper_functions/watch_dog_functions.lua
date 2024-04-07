local attach_watch_dog_header = [[


int Start_watch_dog_CFL(const void *handle, void *params,
                            Event_data_CFL_t *event_data);

]]


local attach_watch_dog_handler_code = [[


int Start_watch_dog_CFL(const void *input,void *params,
                            Event_data_CFL_t *event_data)
{
  (void)event_data;
  const Watch_dog_struct_CFL_t *watch_dog_data = (const Watch_dog_struct_CFL_t *)params;
  attach_watch_dog_handler_CFL(input,watch_dog_data);
  return DISABLE_CFL;
    
}
]]

local detach_watch_dog_header = [[

int Clear_watch_dog_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);

]]


local detach_watch_dog_handler_code = [[



int Clear_watch_dog_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data)
{

 
 (void)params;
 (void)event_data;
 detach_watch_dog_handler_CFL(input);
    return DISABLE_CFL;
}
]]

Store_one_shot_function("START_WATCH_DOG",'Start_watch_dog_CFL',attach_watch_dog_handler_code,attach_watch_dog_header)
Store_one_shot_function("CLEAR_WATCH_DOG",'Clear_watch_dog_CFL',detach_watch_dog_handler_code,detach_watch_dog_header) 


local attach_data_format = "const Watch_dog_struct_CFL_t %s = { %s, %s, %s, %s};\n"

function attach_watch_dog_handler(ms_count,termination_flag,one_shot_termination,user_data)

    if user_data == 'NULL' then
        user_data = 'NULL'
      else
        user_data = '(void*)&'..user_data
      end
    one_shot = Get_one_shot_function(one_shot_termination)
    Activate_one_shot_function(one_shot_termination)
    local unique_name = generate_unique_function_name()
    local message = string.format(attach_data_format, unique_name,ms_count,one_shot,termination_flag,user_data)

    Store_user_code(message)
    One_shot("START_WATCH_DOG", unique_name)


end



function detach_watch_dog_handler()
    One_shot("CLEAR_WATCH_DOG", "NULL")

end


