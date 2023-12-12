
register_map_definition = {}
register_map_list = {}

function initialize_register_maps()

    register_map_definition = {}
    register_map_list = {}
end

local function check_for_integer(input)
    if type(input) == "number" then
        if math.floor(input) == input then
            return true
        else
            return false
        end
    end
 
end

function define_register_map(name,size,value)
    if value == nil then
        value = 0
    end
    if register_map_definition[name] ~= nil then
        error("ERROR: register map already defined",name)
        os.exit(1)
    end
    
    if check_for_integer(size) == false then
        error("ERROR: size not an integer",size)
        os.exit(1)
    end

    if check_for_integer(value) == false then
        error("ERROR: value not an integer",value)
        os.exit(1)
    end

    local definition = {}
    definition.number = #register_map_list
    table.insert(register_map_list,name)
  
    
    definition.name = name
    definition.size = size
    definition.state = value
    definition.array_name = generate_unique_function_name()
   
    register_map_definition[name] = definition
  
end

function dump_register_arrays()
    
    for i,register_name in ipairs(register_map_list) do
        local message = ""
        local value = ""
        local register_map = register_map_definition[register_name]
        
        register_state = register_map.state
       
        local register_size = register_map.size
        local register_array_name = register_map.array_name
        state_array = {}
        for i = 1, register_map.size do
            table.insert(state_array,  register_state) -- Insert the same value 'n' times
        end

        message = string.format("static int16_t %s[%d]= {%s};\n",register_array_name,register_map.size,table.concat(state_array,","))
        write_output(message)
    end
end
    
 




function get_s_register_buffer_number(buffer_name)
  
    local buffer_data = register_map_definition[buffer_name]
 
    if buffer_data == nil then
        print("ERROR: buffer not defined",buffer_name)
        error("ERROR: buffer not defined")
        os.exit(1)
    end
    return buffer_data.number, buffer_data.size
end

function check_s_register_buffer_parameters(source_buffer,source_offset,size)
   
    local buffer_data = register_map_definition[source_buffer]
    if buffer_data == nil then
        error("ERROR: buffer not defined",source_buffer)
        os.exit(1)
    end
    if source_offset + size > buffer_data.size then
        error("ERROR: buffer overflow",source_buffer,source_offset,size,buffer_data.size)
        os.exit(1)
    end
end



   


function dump_register_maps()
 
    build_status["number_of_register_maps"] = #register_map_list
    
    local register_array_name = generate_unique_function_name()
    build_status["registermaps"]  = register_array_name
    if(#register_map_list == 0) then
        local message = string.format("Registermap_CFL_t %s[%d];\n",register_array_name,#register_map_list)
        write_output(message)
        return
    end
    dump_register_arrays()
    local message = string.format("Registermap_CFL_t %s[%d] = {\n",register_array_name,#register_map_list)
    write_output(message)
    for i,register_name in ipairs(register_map_list) do
        local register_map = register_map_definition[register_name]
    
        local array_name = register_map.array_name
        message = string.format(' {%d, &%s[0]},\n',register_map.size,array_name)
        write_output(message)
    end
    message = string.format("};\n")
    write_output(message)

end




local dump_register_buffer_header = [[

typedef struct dump_register_buffer_CFL_t{
    uint16_t buffer_number;
    uint16_t size;
}dump_register_buffer_CFL_t;

void dump_register_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local dump_register_buffer_body = [[

void dump_register_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    dump_register_buffer_CFL_t* setup = (dump_register_buffer_CFL_t*)params;
    uint16_t size = setup->size;
    
    int16_t *register_map = registermap_buffer_CFL(handle,setup->buffer_number);
   
    Printf_CFL("\n\nDumping Register Buffer %d\n",setup->buffer_number);
    Printf_CFL("Register Buffer Size %d\n",size);
    Printf_CFL("Buffer register Map ");
    for(unsigned i = 0; i< size;i++){
        Printf_CFL("%d ",register_map[i]);
    }
    Printf_CFL("\n\n");
    
}

]]  


Store_one_shot_function("DUMP_REGISTER_MAP","dump_register_buffer_CFL",dump_register_buffer_body,dump_register_buffer_header)

function dump_register_map_buffer(buffer_name)
    local buffer_number,buffer_size = get_s_register_buffer_number(buffer_name)
    local user_data = generate_unique_function_name()
    local message = string.format("static const dump_register_buffer_CFL_t %s = {%d,%d};\n",user_data,buffer_number,buffer_size)
    Store_user_code(message)
    One_shot("DUMP_REGISTER_MAP",user_data)
end

local clear_register_map_header = [[

typedef struct clear_register_map_CFL_t{
    uint16_t buffer_number;
    int16_t state;
    uint16_t start;
    uint16_t  number;
}clear_register_map_CFL_t;

void clear_register_map_CFL(const void *input, void *params, Event_data_CFL_t *event_data);
]]

local clear_register_map_body = [[

void clear_register_map_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    clear_register_map_CFL_t* setup = (clear_register_map_CFL_t*)params;
   
    int16_t *register_map = registermap_buffer_CFL(handle,setup->buffer_number);
    
    
    for(unsigned i = setup->start; i< setup->number+setup->start;i++){
    
        register_map[i] = setup->state;
    }

}



]]  

Store_one_shot_function("CLEAR_REGISTER_MAP","clear_register_map_CFL",clear_register_map_body,clear_register_map_header)

function clear_register_map(buffer_name,state,start,number)
    
    local buffer_number = get_s_register_buffer_number(buffer_name)
    if start == nil then
        start = 0
    end
    if number < 0 then
        print("ERROR: number must be greater than 0",number)
        error("ERROR: number must be greater than 0")
        os.exit(1)
    end
    
    if start+number > register_map_definition[buffer_name].size then
        print("ERROR: ending must be less than buffer size",ending, register_map_definition[buffer_name].size)
        error("ERROR:ending must be less than buffer size")
        os.exit(1)
    end
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const clear_register_map_CFL_t %s = {%d,%d,%d,%d};\n",user_data,buffer_number,state,start,number)
    Store_user_code(message)
    One_shot("CLEAR_REGISTER_MAP", user_data)
end


local set_register_header = [[

typedef struct set_register_buffer_CFL_t{
    uint16_t buffer_number;
    uint16_t start;
    uint16_t register_array_size;
    const int16_t *register_array;
}set_register_buffer_CFL_t;

void set_register_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);
]]

local set_register_body = [[

void set_register_buffer_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    set_register_buffer_CFL_t* setup = (set_register_buffer_CFL_t *)params;
   
    int16_t *register_map = registermap_buffer_CFL(handle,setup->buffer_number);
    
    
    for(unsigned i = 0; i< setup->register_array_size;i++){
    
        register_map[i+setup->start] = setup->register_array[i];
    }

}



]]  

Store_one_shot_function("SET_REGISTER_BUFFER","set_register_buffer_CFL",set_register_body,set_register_header)


function check_buffer_for_integer(input_array)
    for i,v in ipairs(input_array) do
        if check_for_integer(v) == false then
            print("ERROR: array contains non integer",i,v)
            error("ERROR: array contains non integer")
            os.exit(1)
        end
    end
end



function set_register_buffer_fn(buffer_name,start_number,array)
    local buffer_number,buffer_size = get_s_register_buffer_number(buffer_name)
    if start_number + #array > buffer_size then
        print("ERROR: array too large for buffer",buffer_name,start_number,#array,buffer_size)
        error("ERROR: array too large for buffer")
        os.exit(1)
    end
    check_buffer_for_integer(array)
    local data_array_name = generate_unique_function_name()
    local message = string.format("static const int16_t %s[%d] = {%s};\n",data_array_name,#array,table.concat(array,","))
    Store_user_code(message)
    local user_data = generate_unique_function_name()
    message = string.format("static const set_register_buffer_CFL_t %s = {%d,%d,%d,%s};\n",user_data,buffer_number,start_number,#array,data_array_name)
    Store_user_code(message)
    One_shot("SET_REGISTER_BUFFER",user_data)
end


    
    
local register_map_copy_header = [[

typedef struct register_map_copy_CFL_t{
    uint16_t source_buffer;
    uint16_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}register_map_copy_CFL_t;

void register_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local register_map_copy_body = [[

void register_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void )event_data;
    register_map_copy_CFL_t* setup = (register_map_copy_CFL_t*)params;
    Registermap_CFL_t* source_bmp      =   get_registermap_control_CFL(input,setup->source_buffer);
    Registermap_CFL_t* destination_bmp =  get_registermap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        int16_t source_register = registermap_get_value_CFL(source_bmp,setup->source_offset + i);
        registermap_set_value_CFL(destination_bmp,setup->destination_offset + i,source_register);
    }
}

]]

Store_one_shot_function("COPY_REGISTER_MAP_BUFFER","register_map_copy_CFL",register_map_copy_body,register_map_copy_header)

function cp_register_buffer(source_buffer,destination_buffer,source_offset,destination_offset,size)

    local source_buf_number = get_s_register_buffer_number(source_buffer)
        
    local destination_buf_number = get_s_register_buffer_number(destination_buffer)
    check_s_register_buffer_parameters(source_buffer,source_offset,size)
    check_s_register_buffer_parameters(destination_buffer,destination_offset,size)
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const register_map_copy_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("COPY_REGISTER_MAP_BUFFER",user_data)
end   


local s_expression_header = [[
typedef struct s_reg_expression_CFL_t{

    uint8_t buffer_number;
    uint16_t offset;
    const  s_register_definition_CFL_t* definition;
} s_reg_expression_CFL_t;

void reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local s_expression_body = [[

void reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;

    const  s_reg_expression_CFL_t* setup = (const  s_reg_expression_CFL_t*)params; 
    int16_t result =  process_s_register_buffer_CFL(input, setup->definition);
    
    Registermap_CFL_t* bmp =  get_registermap_control_CFL(input, setup->buffer_number);
    registermap_set_value_CFL(bmp,setup->offset,result);  
}

]]
Store_one_shot_function("EVALUATE_S_REG_EXPRESSION","reg_map_s_expr_CFL",s_expression_body,s_expression_header)


function s_reg_expression(destination_reg_map, destination_reg_location,source_reg_map,s_expression)
 
    local user_data = generate_unique_function_name()
    local reg_map_number =  get_s_register_buffer_number(destination_reg_map)    
    
    check_s_register_buffer_parameters(destination_reg_map, destination_reg_location,1)
    local s_expression_structure = generate_unique_function_name()
    
    generate_s_reg_expression(s_expression_structure,source_reg_map,s_expression)
    local message = string.format("static const s_reg_expression_CFL_t %s = {%d,%d,&%s};\n",user_data,reg_map_number ,destination_reg_location,s_expression_structure)
    Store_user_code(message)
    One_shot("EVALUATE_S_REG_EXPRESSION",user_data)
end




local wait_s_reg_expression_header = [[



typedef struct wait_reg_map_s_expr_CFL_t{
    const s_register_definition_CFL_t* definition;
    const void* time_out_data;
}wait_reg_map_s_expr_CFL_t;

bool wait_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local wait_s_reg_expression_body = [[

bool wait_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    wait_reg_map_s_expr_CFL_t* setup = (wait_reg_map_s_expr_CFL_t*)params;
    bool result = process_s_register_buffer_CFL(input, setup->definition);
    return result;    
}

]]
Store_boolean_function("WAIT_EVALUATE_REG_MAP","wait_reg_map_s_expr_CFL",wait_s_reg_expression_body,wait_s_reg_expression_header)



function Wait_s_reg_expression(source_reg_map,s_expression, time_out_ms, terminate_flag, one_shot_time_out_fn, time_out_data)
    local message = ""
    local wait_name = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()
   
    generate_s_reg_expression(s_expression_structure,source_reg_map,s_expression)
    if time_out_data ~= 'NULL' then
          message = string.format("static const wait_reg_map_s_expr_CFL_t %s = {&%s,%s};\n",wait_name,s_expression_structure,"(const void *)&"..time_out_data)
    else
        message = string.format("static const wait_reg_map_s_expr_CFL_t %s = {&%s,NULL};\n",wait_name,s_expression_structure)
    end
    
    Store_user_code(message)
    Wait("WAIT_EVALUATE_REG_MAP", time_out_ms, terminate_flag, one_shot_time_out_fn, wait_name)
end  

local verify_s_reg_expression_header = [[



typedef struct verify_reg_map_s_expr_CFL_t {
    const s_register_definition_CFL_t* definition;
   const void* error_message;
}verify_reg_map_s_expr_CFL_t;

bool verify_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local verify_s_reg_expression_body = [[

bool verify_reg_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    verify_reg_map_s_expr_CFL_t* setup = (verify_reg_map_s_expr_CFL_t*)params;  
    bool result = process_s_register_buffer_CFL(input, setup->definition);
    return result;  
}

]]

Store_boolean_function("VERIFY_EVALUATE_REG_MAP","verify_reg_map_s_expr_CFL",verify_s_reg_expression_body,verify_s_reg_expression_header)

function  Verify_s_register_expression(source_reg_map,s_expression, terminate_flag, one_shot_failure_fn, error_data)
    local verify_name = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()

    generate_s_reg_expression(s_expression_structure,source_reg_map,s_expression)
    if error_data ~= 'NULL' then
        message = string.format("static const  verify_reg_map_s_expr_CFL_t %s = {&%s,%s};\n",verify_name,s_expression_structure,"(const void *)&"..error_data)
  else
      message = string.format("static const  verify_reg_map_s_expr_CFL_t %s = {&%s,NULL};\n",verify_name,s_expression_structure)
  end
  
    Store_user_code(message)
    Verify("VERIFY_EVALUATE_REG_MAP", terminate_flag, one_shot_failure_fn, verify_name)
end


local if_then_else_header = [[

typedef struct if_then_else_reg_map_CFL_t{
    uint8_t source_buffer;
    uint16_t if_reg;
    One_shot_function_CFL_t then_one_shot;
    One_shot_function_CFL_t else_one_shot;
    const void* then_data;
    const void* else_data;
} if_then_else_reg_map_CFL_t;


void if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local if_then_else_body = [[

void  if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    if_then_else_reg_map_CFL_t* setup = (if_then_else_reg_map_CFL_t* )params;
    Registermap_CFL_t* source_bmp      =  get_registermap_control_CFL(input,setup->source_buffer);
    bool source_reg =  registermap_get_value_CFL(source_bmp,setup->if_reg);
    if(source_reg == true){
        setup->then_one_shot(input,(void *)setup->then_data,event_data);
    }else{
        setup->else_one_shot(input,(void *)setup->else_data,event_data);
    }

}

]]



Store_one_shot_function("IF_THEN_ELSE_REG_MAP","if_then_else_CFL",if_then_else_body, if_then_else_header)

function if_then_else_reg_map(source_buffer,test_reg,then_one_shot,then_one_shot_data, else_one_shot,else_one_shot_data)
 
    local source_buf_number = get_s_register_buffer_number(source_buffer)
    check_s_register_buffer_parameters(source_buffer,test_reg,1)
    unique_name = generate_unique_function_name()
    local then_one_shot_fn = Get_one_shot_function(then_one_shot)
    local else_one_shot_fn = Get_one_shot_function(else_one_shot)
    local message = string.format("static const if_then_else_reg_map_CFL_t %s = {%d,%d,%s,%s,&%s,&%s};\n",unique_name,source_buf_number,test_reg,
                                    then_one_shot_fn,else_one_shot_fn,then_one_shot_data,else_one_shot_data)
    Store_user_code(message)
    One_shot("IF_THEN_ELSE_REG_MAP",unique_name)

end    

  