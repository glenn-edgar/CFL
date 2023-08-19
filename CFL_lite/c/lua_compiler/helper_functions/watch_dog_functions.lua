local attach_watch_dog_header = [[
typedef struct Attach_watch_dog_CFL_t{
   One_shot_function_CFL_t    watch_dog_trigger_function;
    bool                      watch_dog_termination_flag;
    void *                    watch_dog_user_data;
    unsigned                  watch_dog_trigger_count;
}Attach_watch_dog_CFL_t;


int Start_watch_dog_CFL(const void *handle, void *params,
                            Event_data_CFL_t *event_data);

]]


local attach_watch_dog_handler_code = [[


int Start_watch_dog_CFL(const void *input,void *params,
                            Event_data_CFL_t *event_data)
{
  (void)event_data;
  Attach_watch_dog_CFL_t *watch_dog_data = (Attach_watch_dog_CFL_t *)params;
  attach_watch_dog_handler_CFL(input,
    watch_dog_data->watch_dog_trigger_function,
    watch_dog_data->watch_dog_user_data,
    watch_dog_data->watch_dog_termination_flag,
    watch_dog_data->watch_dog_trigger_count);
  
    return DISABLE_CFL;
    
}
]]

local detach_watch_dog_header = [[
extern const char *clear_watch_dog_placeholder;
int Clear_watch_dog_CFL(const void *input, void *params,
                            Event_data_CFL_t *event_data);

]]


local detach_watch_dog_handler_code = [[

const char *clear_watch_dog_placeholder = "";

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


local attach_data_format = "const Attach_watch_dog_CFL_t %s = { %s, %s, %s, %s};\n"

function attach_watch_dog_handler(ms_count,termination_flag,one_shot_termination,user_data)

    one_shot = Get_one_shot_function(one_shot_termination)
    Activate_one_shot_function(one_shot_termination)
    local unique_name = generate_unique_function_name()
    local message = string.format(attach_data_format, unique_name,one_shot,termination_flag,user_data,ms_count)

    Store_user_code(message)
    One_shot("START_WATCH_DOG", unique_name)


end



function detach_watch_dog_handler()
    One_shot("CLEAR_WATCH_DOG", 'clear_watch_dog_placeholder')

end


