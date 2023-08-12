
-- insert static data
-- insert function code
-- add one shot function

local function_code = [[

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

]]

local function_code_header = [[

extern const int reset_buffer[1];
extern const int halt_buffer[1];
extern const int terminate_buffer[1];
extern const int terminate_engine_buffer[1];

int return_condition_code_CFL(const void *handle, void *aux_fn,
    void *params, Event_data_CFL_t *event_data);

    ]]



Store_column_function("RETURN_CONDITION_CODE",'return_condition_code_CFL',function_code,function_code_header)


function halt_column()
    Activate_column_function("RETURN_CONDITION_CODE")
    store_column_element('return_condition_code_CFL','NULL','(void *)halt_buffer')
end



function reset_column()
   
    Activate_column_function("RETURN_CONDITION_CODE")
    store_column_element('return_condition_code_CFL','NULL','(void *)reset_buffer')
end

function terminate_column()
    Activate_column_function("RETURN_CONDITION_CODE")
    store_column_element('return_condition_code_CFL','NULL','(void *)terminate_buffer')
end

function terminate_engine()
    Activate_column_function("RETURN_CONDITION_CODE")
    store_column_element('return_condition_code_CFL','NULL','(void *)terminate_engine_buffer')
end


