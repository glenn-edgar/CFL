


local if_then_else_header = [[

typedef struct if_then_else_register_map_CFL_t{
    uint8_t source_buffer;
    uint8_t if_register;
    One_shot_function_CFL_t then_one_shot;
    One_shot_function_CFL_t else_one_shot;
    const void* then_data;
    const void* else_data;
} if_then_else_register_map_CFL_t;


void if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local if_then_else_body = [[

void  if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    if_then_else_register_map_CFL_t* setup = (if_then_else_register_map_CFL_t*)params;
    registermap_CFL* source_bmp      =  get_registermap_control_CFL(input,setup->source_buffer);
    bool source_register = registermap_get_register_CFL(source_bmp,setup->if_register);
    if(source_register == true){
        setup->then_one_shot(input,(void *)setup->then_data,event_data);
    }else{
        setup->else_one_shot(input,(void *)setup->else_data,event_data);
    }

}

]]



Store_one_shot_function("IF_THEN_ELSE_register_MAP","if_then_else_CFL",if_then_else_body, if_then_else_header,then_data,else_data)

function if_then_else_register_map(source_buffer,test_register,then_one_shot,then_one_shot_data, else_one_shot,else_one_shot_data)
 
    local source_buf_number = get_s_register_buffer_number(source_buffer) 
    check_s_register_buffer_parameters(source_buffer,test_register,1)
    unique_name = generate_unique_function_name()
    local then_one_shot_fn = Get_one_shot_function(then_one_shot)
    local else_one_shot_fn = Get_one_shot_function(else_one_shot)
    local message = string.format("static const if_then_else_register_map_CFL_t %s = {%d,%d,%s,%s,&%s,&%s};\n",unique_name,source_buf_number,test_register,
                                    then_one_shot_fn,else_one_shot_fn,then_one_shot_data,else_one_shot_data)
    Store_user_code(message)
    One_shot("IF_THEN_ELSE_register_MAP",unique_name)

end    


--[[
typedef struct s_register_definition_CFL_t{
    uint8_t register_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_operator_CFL_t *operator_stream;
}s_register_definition_CFL_t;

]]--


local s_expression_header = [[
typedef struct s_register_expression_CFL_t{

    uint8_t buffer_number;
    uint16_t offset;
    const s_register_definition_CFL_t* definition;
} s_register_expression_CFL_t;

void register_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local s_expression_body = [[

void register_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;

    const s_register_expression_CFL_t* setup = (const s_register_expression_CFL_t*)params; 
    bool result = process_s_register_buffer_CFL(input, setup->definition);
    
    registermap_CFL *bmp = get_registermap_control_CFL(input, setup->buffer_number);
    registermap_set_register_CFL(bmp,setup->offset,result);  
}

]]
Store_one_shot_function("EVALUATE_S_EXPRESSION"," register_map_s_expr_CFL",s_expression_body,s_expression_header)


function s_register_expression(destination_register_map, register_map_location,source_register_map,s_expression)
 
    local user_data = generate_unique_function_name()
    local register_map_number = get_s_register_buffer_number(destination_register_map)    
    
    check_s_register_buffer_parameters(destination_register_map, register_map_location,1)
    local s_expression_structure = generate_unique_function_name()
    
    generate_s_register_expression(s_expression_structure,source_register_map,s_expression)
    local message = string.format("static const s_register_expression_CFL_t %s = {%d,%d,&%s};\n",user_data,register_map_number,register_map_location,s_expression_structure)
    Store_user_code(message)
    One_shot("EVALUATE_S_EXPRESSION",user_data)
end






local wait_s_expression_header = [[



typedef struct wait_register_map_s_expr_CFL_t{
    const s_register_definition_CFL_t* definition;
    const void* time_out_data;
}wait_register_map_s_expr_CFL_t;

bool wait_register_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local wait_s_expression_body = [[

bool wait_register_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    wait_register_map_s_expr_CFL_t* setup = (wait_register_map_s_expr_CFL_t*)params;
    bool result = process_s_register_buffer_CFL(input, setup->definition);
    return result;    
}

]]
Store_boolean_function("WAIT_EVALUATE_register_MAP","wait_register_map_s_expr_CFL",wait_s_expression_body,wait_s_expression_header)



function Wait_s_expression(source_register_map,s_expression, time_out_ms, terminate_flag, one_shot_time_out_fn, time_out_data)
    local message = ""
    local wait_name = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()
    generate_s_register_expression(s_expression_structure,source_register_map,s_expression)
    if time_out_data ~= 'NULL' then
          message = string.format("static const wait_register_map_s_expr_CFL_t %s = {&%s,%s};\n",wait_name,s_expression_structure,"(const void *)&"..time_out_data)
    else
        message = string.format("static const wait_register_map_s_expr_CFL_t %s = {&%s,NULL};\n",wait_name,s_expression_structure)
    end
    
    Store_user_code(message)
    Wait("WAIT_EVALUATE_register_MAP", time_out_ms, terminate_flag, one_shot_time_out_fn, wait_name)
end  

local verify_s_expression_header = [[



typedef struct verify_register_map_s_expr_CFL_t {
    const s_register_definition_CFL_t* definition;
   const void* error_message;
}verify_register_map_s_expr_CFL_t;

bool verify_register_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local verify_s_expression_body = [[

bool verify_register_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    verify_register_map_s_expr_CFL_t* setup = (verify_register_map_s_expr_CFL_t*)params;  
    bool result = process_s_register_buffer_CFL(input, setup->definition);
    return result;  
}

]]

Store_boolean_function("VERIFY_EVALUATE_register_MAP","verify_register_map_s_expr_CFL",verify_s_expression_body,verify_s_expression_header)

function  Verify_s_expression(source_register_map,s_expression, terminate_flag, one_shot_failure_fn, error_data)
    local verify_name = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()
    generate_s_register_expression(s_expression_structure,source_register_map,s_expression)
    if error_data ~= 'NULL' then
        message = string.format("static const  verify_register_map_s_expr_CFL_t %s = {&%s,%s};\n",verify_name,s_expression_structure,"(const void *)&"..error_data)
  else
      message = string.format("static const  verify_register_map_s_expr_CFL_t %s = {&%s,NULL};\n",verify_name,s_expression_structure)
  end
  
    Store_user_code(message)
    Verify("VERIFY_EVALUATE_register_MAP", terminate_flag, one_shot_failure_fn, verify_name)
end



