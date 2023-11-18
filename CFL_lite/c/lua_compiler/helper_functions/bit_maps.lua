
bit_map_definition = {}
bit_map_list = {}

function initialize_bit_maps()

    bit_map_definition = {}
    bit_map_list = {}
end


function define_bit_map(name,size,state)
    if state == nil then
        state = false
    end
    if bit_map_definition[name] ~= nil then
        error("ERROR: bit map already defined",name)
        os.exit(1)
    end
    
    if type(state) ~= "boolean" then
        error("ERROR: state must be boolean",name,state)
        os.exit(1)
    end
    local definition = {}
    definition.number = #bit_map_list
    table.insert(bit_map_list,name)
  
    
    definition.name = name
    definition.size = size
    definition.byte_number = math.floor(size/8)
    if(size % 8 ~= 0) then
        definition.byte_number = definition.byte_number + 1
    end
   
    definition.state = state
    definition.array_name = generate_unique_function_name()
    
    bit_map_definition[name] = definition
end

function get_s_bit_buffer_number(buffer_name)
   
    local buffer_data = bit_map_definition[buffer_name]
    if buffer_data == nil then
        error("ERROR: buffer not defined",buffer_name)
        os.exit(1)
    end
    return buffer_data.number, buffer_data.byte_number, buffer_data.size
end

function check_s_bit_buffer_parameters(source_buffer,source_offset,size)
    local buffer_data = bit_map_definition[source_buffer]
    if buffer_data == nil then
        error("ERROR: buffer not defined",source_buffer)
        os.exit(1)
    end
    if source_offset + size > buffer_data.size then
        error("ERROR: buffer overflow",source_buffer,source_offset,size,buffer_data.size)
        os.exit(1)
    end
end

function add_bit_map_label(bit_map_name,label_name,position)
    if bit_map_definition[bit_map_name] == nil then
        error("ERROR: bit map not defined",bit_map_name)
        os.exit(1)
    end
    local bit_map = bit_map_definition[bit_map_name]
   
    bit_map_definition[bit_map_name] = bit_map
end

--
--  Generate bit maps and tie structures to the engine handle
--
--
--

function dump_bit_arrays()
    
    for i,bit_name in ipairs(bit_map_list) do
        local message = ""
        local value = ""
        local bit_map = bit_map_definition[bit_name]
        
        bit_state = bit_map.state
        if bit_state == true then 
            value = 0xFF
        else
            value = 0x00
        end     
        local bit_size = bit_map.size
        local bit_array_name = bit_map.array_name
        state_array = {}
        for i = 1, bit_map.byte_number do
            table.insert(state_array, value) -- Insert the same value 'n' times
        end
        
        
        message = string.format("static uint8_t %s[%d]= {%s};\n",bit_array_name,bit_map.byte_number,table.concat(state_array,","))
        write_output(message)
    end
end


function dump_bit_maps()
    build_status["number_of_bitmaps"] = #bit_map_list
    
    local bit_array_name = generate_unique_function_name()
    build_status["bitmaps"]  = bit_array_name
    if(#bit_map_list == 0) then
        local message = string.format("Bitmap_CFL %s[%d];\n",bit_array_name,#bit_map_list)
        write_output(message)
        return
    end
    dump_bit_arrays()
    local message = string.format("Bitmap_CFL %s[%d] = {\n",bit_array_name,#bit_map_list)
    write_output(message)
    for i,bit_name in ipairs(bit_map_list) do
        local bit_map = bit_map_definition[bit_name]
        --local bit_array_name = generate_unique_function_name()
        local array_name = bit_map.array_name
        message = string.format(' {%d, &%s[0]},\n',bit_map.size,array_name)
        write_output(message)
    end
    message = string.format("};\n")
    write_output(message)

end







----
---- CFL instructions
----


local dump_buffer_header = [[

typedef struct dump_buffer_CFL_t{
    uint16_t buffer_number;
    uint16_t size;
}dump_buffer_CFL_t;

void dump_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local dump_buffer_body = [[

void dump_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    dump_buffer_CFL_t* setup = (dump_buffer_CFL_t*)params;
    uint16_t size = setup->size;
    
    uint8_t *bit_map = bitmap_buffer(handle,setup->buffer_number);
   
    Printf_CFL("\n\nDumping Buffer %d\n",setup->buffer_number);
    Printf_CFL("Buffer Size %d\n",size);
    Printf_CFL("Buffer Bit Map ");
    for(unsigned i = 0; i< size;i++){
        Printf_CFL("%02x ",bit_map[i]);
    }
    Printf_CFL("\n\n");
    
}

]]  


Store_one_shot_function("DUMP_BIT_MAP","dump_buffer_CFL",dump_buffer_body,dump_buffer_header)

function dump_bit_map_buffer(buffer_name)
    local buffer_number,buffer_size = get_s_bit_buffer_number(buffer_name)
    local user_data = generate_unique_function_name()
    local message = string.format("static const dump_buffer_CFL_t %s = {%d,%d};\n",user_data,buffer_number,buffer_size)
    Store_user_code(message)
    One_shot("DUMP_BIT_MAP",user_data)
end


local clear_bit_map_header = [[

typedef struct clear_bit_map_CFL_t{
    uint16_t buffer_number;
    bool state;
    uint16_t start;
    uint16_t ending;
}clear_bit_map_CFL_t;

void clear_bit_map_CFL(const void *input, void *params, Event_data_CFL_t *event_data);
]]

local clear_bit_map_body = [[

void clear_bit_map_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
    (void)event_data;
    Handle_CFL_t* handle = (Handle_CFL_t*)input;
    clear_bit_map_CFL_t* setup = (clear_bit_map_CFL_t*)params;
   
    Bitmap_CFL* map = get_bitmap_control_CFL(handle,setup->buffer_number);
    bool state = setup->state;

    for(unsigned i = setup->start; i< setup->ending;i++){
    
        bitmap_set_bit_CFL(map,i,state);
    }

}



]]  

Store_one_shot_function("CLEAR_BIT_MAP","clear_bit_map_CFL",clear_bit_map_body,clear_bit_map_header)

function clear_bit_map(buffer_name,state,start,ending)
    
    local buffer_number = get_s_bit_buffer_number(buffer_name)
    if start == nil then
        start = 0
    end
   
    if ending == nil then
        ending = bit_map_definition[buffer_name].size
    
    end
    if start > bit_map_definition[buffer_name].size then
        print("ERROR: start must be less than buffer size",start, bit_map_definition[buffer_name].size)
        error("ERROR: start must be less than buffer size")
        os.exit(1)
    end
    if ending > bit_map_definition[buffer_name].size then
        print("ERROR: ending must be less than buffer size",ending, bit_map_definition[buffer_name].size)
        error("ERROR:ending must be less than buffer size")
        os.exit(1)
    end
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const clear_bit_map_CFL_t %s = {%d,%s,%d,%d};\n",user_data,buffer_number,state,start,ending)
    Store_user_code(message)
    One_shot("CLEAR_BIT_MAP", user_data)
end








local bit_map_copy_header = [[

typedef struct bit_map_copy_CFL_t{
    uint16_t source_buffer;
    uint16_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}bit_map_copy_CFL_t;

void bit_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local bit_map_copy_body = [[

void bit_map_copy_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void )event_data;
    bit_map_copy_CFL_t* setup = (bit_map_copy_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,source_bit);
    }
}

]]

Store_one_shot_function("COPY_BIT_MAP_BUFFER","bit_map_copy_CFL",bit_map_copy_body,bit_map_copy_header)

function cp_buffer(source_buffer,destination_buffer,source_offset,destination_offset,size)
    local source_buf_number = get_s_bit_buffer_number(source_buffer)
        
    local destination_buf_number = get_s_bit_buffer_number(destination_buffer)
    check_s_bit_buffer_parameters(source_buffer,source_offset,size)
    check_s_bit_buffer_parameters(destination_buffer,destination_offset,size)
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const bit_map_copy_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("COPY_BIT_MAP_BUFFER",user_data)
end



local bit_map_and_header = [[

typedef struct bit_map_and_CFL_t{
    uint8_t source_buffer;
    uint8_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}bit_map_and_CFL_t;

void bit_map_and_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local bit_map_and_body = [[

void bit_map_and_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_and_CFL_t* setup = (bit_map_and_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bool destination_bit = bitmap_get_bit_CFL(destination_bmp,setup->destination_offset + i);
        bool output_bit = source_bit && destination_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
    }
}

]]

Store_one_shot_function("AND_BIT_MAP_BUFFER","bit_map_and_CFL",bit_map_and_body,bit_map_and_header)

function and_bit_map_buffer(source_buffer,destination_buffer,source_offset,destination_offset,size)
    local source_buf_number = get_s_bit_buffer_number(source_buffer)
        
    local destination_buf_number = get_s_bit_buffer_number(destination_buffer)
    check_s_bit_buffer_parameters(source_buffer,source_offset,size)
    check_s_bit_buffer_parameters(destination_buffer,destination_offset,size)
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const bit_map_and_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("AND_BIT_MAP_BUFFER",user_data)
end

local bit_map_or_header = [[

typedef struct bit_map_or_CFL_t{
    uint8_t source_buffer;
    uint8_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}bit_map_or_CFL_t;

void bit_map_or_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local bit_map_or_body = [[

void bit_map_or_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_or_CFL_t* setup = (bit_map_or_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bool destination_bit = bitmap_get_bit_CFL(destination_bmp,setup->destination_offset + i);
        bool output_bit = source_bit || destination_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
    }
}

]]

Store_one_shot_function("OR_BIT_MAP_BUFFER","bit_map_or_CFL",bit_map_or_body,bit_map_or_header)

function or_bit_map_buffer(source_buffer,destination_buffer,source_offset,destination_offset,size)
    local source_buf_number = get_s_bit_buffer_number(source_buffer)
        
    local destination_buf_number = get_s_bit_buffer_number(destination_buffer)
    check_s_bit_buffer_parameters(source_buffer,source_offset,size)
    check_s_bit_buffer_parameters(destination_buffer,destination_offset,size)
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const bit_map_or_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("OR_BIT_MAP_BUFFER",user_data)
end

local bit_map_xor_header = [[

typedef struct bit_map_xor_CFL_t{
    uint8_t source_buffer;
    uint8_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}bit_map_xor_CFL_t;

void bit_map_xor_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local bit_map_xor_body = [[

void bit_map_xor_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_xor_CFL_t* setup = (bit_map_xor_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        bool destination_bit = bitmap_get_bit_CFL(destination_bmp,setup->destination_offset + i);
        bool output_bit = source_bit ^ destination_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
    }
}

]]

Store_one_shot_function("XOR_BIT_MAP_BUFFER","bit_map_xor_CFL",bit_map_xor_body,bit_map_xor_header)

function xor_bit_map_buffer(source_buffer,destination_buffer,source_offset,destination_offset,size)
    local source_buf_number = get_s_bit_buffer_number(source_buffer)
        
    local destination_buf_number = get_s_bit_buffer_number(destination_buffer)
    check_s_bit_buffer_parameters(source_buffer,source_offset,size)
    check_s_bit_buffer_parameters(destination_buffer,destination_offset,size)
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const bit_map_xor_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("XOR_BIT_MAP_BUFFER",user_data)
end

local bit_map_not_header = [[

typedef struct bit_map_not_CFL_t{
    uint8_t source_buffer;
    uint8_t destination_buffer;
    uint16_t source_offset;
    uint16_t destination_offset;
    uint16_t size;
}bit_map_not_CFL_t;


void bit_map_not_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local bit_map_not_body = [[

void bit_map_not_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    bit_map_not_CFL_t* setup = (bit_map_not_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    Bitmap_CFL* destination_bmp =  get_bitmap_control_CFL(input,setup->destination_buffer);
    
    for(unsigned i = 0; i< setup->size;i++){
        bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->source_offset + i);
        
        bool output_bit = !source_bit;
        bitmap_set_bit_CFL(destination_bmp,setup->destination_offset + i,output_bit);
    }
}

]]

Store_one_shot_function("NOT_BIT_MAP_BUFFER","bit_map_not_CFL",bit_map_not_body,bit_map_not_header)

function not_bit_map_buffer(source_buffer,destination_buffer,source_offset,destination_offset,size)
    
    local source_buf_number = get_s_bit_buffer_number(source_buffer)    
    local destination_buf_number = get_s_bit_buffer_number(destination_buffer)
    check_s_bit_buffer_parameters(source_buffer,source_offset,size)
    check_s_bit_buffer_parameters(destination_buffer,destination_offset,size)
   
    local user_data = generate_unique_function_name()
    local message = string.format("static const bit_map_not_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,
    source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("NOT_BIT_MAP_BUFFER",user_data)
end


local if_then_else_header = [[

typedef struct if_then_else_bit_map_CFL_t{
    uint8_t source_buffer;
    uint8_t if_bit;
    One_shot_function_CFL_t then_one_shot;
    One_shot_function_CFL_t else_one_shot;
    const void* then_data;
    const void* else_data;
} if_then_else_bit_map_CFL_t;


void if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local if_then_else_body = [[

void  if_then_else_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    if_then_else_bit_map_CFL_t* setup = (if_then_else_bit_map_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    bool source_bit = bitmap_get_bit_CFL(source_bmp,setup->if_bit);
    if(source_bit == true){
        setup->then_one_shot(input,(void *)setup->then_data,event_data);
    }else{
        setup->else_one_shot(input,(void *)setup->else_data,event_data);
    }

}

]]



Store_one_shot_function("IF_THEN_ELSE_BIT_MAP","if_then_else_CFL",if_then_else_body, if_then_else_header,then_data,else_data)

function if_then_else_bit_map(source_buffer,test_bit,then_one_shot,then_one_shot_data, else_one_shot,else_one_shot_data)
 
    local source_buf_number = get_s_bit_buffer_number(source_buffer) 
    check_s_bit_buffer_parameters(source_buffer,test_bit,1)
    unique_name = generate_unique_function_name()
    local then_one_shot_fn = Get_one_shot_function(then_one_shot)
    local else_one_shot_fn = Get_one_shot_function(else_one_shot)
    local message = string.format("static const if_then_else_bit_map_CFL_t %s = {%d,%d,%s,%s,&%s,&%s};\n",unique_name,source_buf_number,test_bit,
                                    then_one_shot_fn,else_one_shot_fn,then_one_shot_data,else_one_shot_data)
    Store_user_code(message)
    One_shot("IF_THEN_ELSE_BIT_MAP",unique_name)

end    


--[[
typedef struct s_bit_definition_CFL_t{
    uint8_t bit_map_number;
    uint8_t parameter_stack_size;
    uint8_t operator_stack_size;
    uint8_t stream_length;
    const s_operator_CFL_t *operator_stream;
}s_bit_definition_CFL_t;

]]--


local s_expression_header = [[
typedef struct s_bit_expression_CFL_t{

    uint8_t buffer_number;
    uint16_t offset;
    const s_bit_definition_CFL_t* definition;
} s_bit_expression_CFL_t;

void bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local s_expression_body = [[

void bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;

    const s_bit_expression_CFL_t* setup = (const s_bit_expression_CFL_t*)params; 
    bool result = process_s_bit_buffer_CFL(input, setup->definition);
    
    Bitmap_CFL *bmp = get_bitmap_control_CFL(input, setup->buffer_number);
    bitmap_set_bit_CFL(bmp,setup->offset,result);  
}

]]
Store_one_shot_function("EVALUATE_S_EXPRESSION"," bit_map_s_expr_CFL",s_expression_body,s_expression_header)


function s_bit_expression(destination_bit_map, bit_map_location,source_bit_map,s_expression)
 
    local user_data = generate_unique_function_name()
    local bit_map_number = get_s_bit_buffer_number(destination_bit_map)    
    
    check_s_bit_buffer_parameters(destination_bit_map, bit_map_location,1)
    local s_expression_structure = generate_unique_function_name()
    
    generate_s_bit_expression(s_expression_structure,source_bit_map,s_expression)
    local message = string.format("static const s_bit_expression_CFL_t %s = {%d,%d,&%s};\n",user_data,bit_map_number,bit_map_location,s_expression_structure)
    Store_user_code(message)
    One_shot("EVALUATE_S_EXPRESSION",user_data)
end






local wait_s_expression_header = [[



typedef struct wait_bit_map_s_expr_CFL_t{
    const s_bit_definition_CFL_t* definition;
    const void* time_out_data;
}wait_bit_map_s_expr_CFL_t;

bool wait_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local wait_s_expression_body = [[

bool wait_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    wait_bit_map_s_expr_CFL_t* setup = (wait_bit_map_s_expr_CFL_t*)params;
    bool result = process_s_bit_buffer_CFL(input, setup->definition);
    return result;    
}

]]
Store_boolean_function("WAIT_EVALUATE_BIT_MAP","wait_bit_map_s_expr_CFL",wait_s_expression_body,wait_s_expression_header)



function Wait_s_expression(source_bit_map,s_expression, time_out_ms, terminate_flag, one_shot_time_out_fn, time_out_data)
    local message = ""
    local wait_name = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()
    generate_s_bit_expression(s_expression_structure,source_bit_map,s_expression)
    if time_out_data ~= 'NULL' then
          message = string.format("static const wait_bit_map_s_expr_CFL_t %s = {&%s,%s};\n",wait_name,s_expression_structure,"(const void *)&"..time_out_data)
    else
        message = string.format("static const wait_bit_map_s_expr_CFL_t %s = {&%s,NULL};\n",wait_name,s_expression_structure)
    end
    
    Store_user_code(message)
    Wait("WAIT_EVALUATE_BIT_MAP", time_out_ms, terminate_flag, one_shot_time_out_fn, wait_name)
end  

local verify_s_expression_header = [[



typedef struct verify_bit_map_s_expr_CFL_t {
    const s_bit_definition_CFL_t* definition;
   const void* error_message;
}verify_bit_map_s_expr_CFL_t;

bool verify_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local verify_s_expression_body = [[

bool verify_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    verify_bit_map_s_expr_CFL_t* setup = (verify_bit_map_s_expr_CFL_t*)params;  
    bool result = process_s_bit_buffer_CFL(input, setup->definition);
    return result;  
}

]]

Store_boolean_function("VERIFY_EVALUATE_BIT_MAP","verify_bit_map_s_expr_CFL",verify_s_expression_body,verify_s_expression_header)

function  Verify_s_expression(source_bit_map,s_expression, terminate_flag, one_shot_failure_fn, error_data)
    local verify_name = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()
    generate_s_bit_expression(s_expression_structure,source_bit_map,s_expression)
    if error_data ~= 'NULL' then
        message = string.format("static const  verify_bit_map_s_expr_CFL_t %s = {&%s,%s};\n",verify_name,s_expression_structure,"(const void *)&"..error_data)
  else
      message = string.format("static const  verify_bit_map_s_expr_CFL_t %s = {&%s,NULL};\n",verify_name,s_expression_structure)
  end
  
    Store_user_code(message)
    Verify("VERIFY_EVALUATE_BIT_MAP", terminate_flag, one_shot_failure_fn, verify_name)
end



local  shift_bit_buffer_body = [[


void shift_bit_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    shift_bit_buffer_CFL_t* setup = (shift_bit_buffer_CFL_t*)params;
    Bitmap_CFL* source_bmp      =  get_bitmap_control_CFL(input,setup->source_buffer);
    unsigned start_bit = setup->start_bit;
    unsigned ending_bit = setup->ending_bit;
    int direction = setup->shift_direction;
  
    bitmap_shift_bits_CFL(source_bmp, start_bit,ending_bit,direction);
    
}

]]
local  shift_bit_buffer_header = [[



typedef  struct  shift_bit_buffer_CFL_t{
    uint16_t source_buffer;
    uint16_t start_bit;
    uint16_t ending_bit;
    int16_t shift_direction;
  
}shift_bit_buffer_CFL_t;

void shift_bit_buffer_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]
Store_one_shot_function("SHIFT_BIT_BUFFER_CFL","shift_bit_buffer_CFL",shift_bit_buffer_body,shift_bit_buffer_header)



function shift_bit_map_buffer(source_buffer,start,stream_length,shift_direction)
    local source_buf_number = get_s_bit_buffer_number(source_buffer)
    local ending = start + stream_length
    check_s_bit_buffer_parameters(source_buffer,start,stream_length)
    local unique_name = generate_unique_function_name()
    local message = string.format("static const shift_bit_buffer_CFL_t %s = {%d,%d,%d,%d};\n",unique_name,source_buf_number,start,ending,shift_direction)
    Store_user_code(message)
    One_shot("SHIFT_BIT_BUFFER_CFL",unique_name)
end

function drum_operation_bit_map()
   --tbd
end




local function verify_no_null_entries(s_expression)
    
    for i = 1, #s_expression do
   
        if s_expression[i] == nil then
            error("ERROR: s_expression must not have nil entries")
            os.exit(1)
        end
    end
end

function isValidInteger(str)
    local num = tonumber(str)
    -- Check if 'num' is a number and an integer
    if num and num == math.floor(num) then
        return true
    else
        return false
    end
end


function add_table_entries(s_expression,position_list)
    verify_no_null_entries(position_list)
    for i,v in ipairs(position_list) do
        
        if(type(v) == "table") then
            add_table_entries(s_expression,v)
        else
            table.insert(s_expression,v)
        end
    end
end




function expand_table(s_expr,parameter_list)
    local op_type = nil
    verify_no_null_entries(parameter_list)
    for i,v in ipairs(parameter_list) do
        table.insert(s_expr,v)
 
    end

 end
 
function expand_table_start(s_expression,position_indexes)
    
    verify_no_null_entries(position_indexes)
    for i,v in ipairs(position_indexes) do
        if(type(v) == "table") then
            expand_table(s_expression,v)
        else

            table.insert(s_expression,v)
        end
    end
    table.insert(s_expression,")")
 end


function s_and(position_indexes)

    s_expression = {}
    table.insert(s_expression, "&&" )
    expand_table_start(s_expression,position_indexes)
    return s_expression

end

function s_or(position_indexes)
    s_expression = {}
    table.insert( s_expression,"||" )
    expand_table_start(s_expression,position_indexes)
    return s_expression

end

function s_nor(position_indexes)
    s_expression = {}
    table.insert( s_expression,"~~" )
    expand_table_start(s_expression,position_indexes)
    return s_expression

end

function dump_s_expression(s_expression,tab)
    if tab == nil then
        tab = "->"
    end
    for i,v in ipairs(s_expression) do
        if(type(v) == "table") then
           
            dump_s_expression(v,"----"..tab)
           
            
        else
            print(tab,i,v)
        end
    end
end

