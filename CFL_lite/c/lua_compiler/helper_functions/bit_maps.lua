
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
        print("ERROR: bit map already defined",name)
        os.exit(1)
    end
    
    if type(state) ~= "boolean" then
        print("ERROR: state must be boolean",name,state)
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
    definition.labels = {}
    definition.state = state
    definition.array_name = generate_unique_function_name()
    
    bit_map_definition[name] = definition
end

function get_s_bit_buffer_number(buffer_name)
   
    local buffer_data = bit_map_definition[buffer_name]
    if buffer_data == nil then
        print("ERROR: buffer not defined",buffer_name)
        os.exit(1)
    end
    return buffer_data.number, buffer_data.byte_number, buffer_data.size
end

function check_s_bit_buffer_parameters(source_buffer,source_offset,size)
    local buffer_data = bit_map_definition[source_buffer]
    if buffer_data == nil then
        print("ERROR: buffer not defined",source_buffer)
        os.exit(1)
    end
    if source_offset + size > buffer_data.size then
        print("ERROR: buffer overflow",source_buffer,source_offset,size,buffer_data.size)
        os.exit(1)
    end
end

function add_bit_map_label(bit_map_name,label_name,position)
    if bit_map_definition[bit_map_name] == nil then
        print("ERROR: bit map not defined",bit_map_name)
        os.exit(1)
    end
    local bit_map = bit_map_definition[bit_map_name]
    if bit_map.labels[label_name] ~= nil then
        print("ERROR: label already defined",bit_map_name,label_name)
        os.exit(1)
    end
    bit_map.labels[label_name] = position
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
        local bit_array_name = generate_unique_function_name()
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
    bitmap_set_all_CFL(map, state);

}



]]  

Store_one_shot_function("CLEAR_BIT_MAP","clear_bit_map_CFL",clear_bit_map_body,clear_bit_map_header)

function clear_bit_map(buffer_name,state)
   
    local buffer_number = get_s_bit_buffer_number(buffer_name)
    local user_data = generate_unique_function_name()
    local message = string.format("static const clear_bit_map_CFL_t %s = {%d,%s};\n",user_data,buffer_number,state)
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
   
    user_data = generate_unique_function_name()
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
   
    user_data = generate_unique_function_name()
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
   
    user_data = generate_unique_function_name()
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
   
    user_data = generate_unique_function_name()
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
   
    user_data = generate_unique_function_name()
    local message = string.format("static const bit_map_not_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,
    source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("NOT_BIT_MAP_BUFFER",user_data)
end


function if_then_else_bit_map(source_buffer,bit,then_one_shot,else_one_shot)

end    

function shift_bit_map_buffer(source_buffer,offset,shift_direction,fill_bit)

end

function drum_operation_bit_map()
   --tbd
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



typedef wait_bit_map_s_expr_CFL_t struct{
    s_bit_definition_CFL_t* definition;
    void* time_out_message
}wait_bit_map_s_expr_CFL_t;

void wait_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local wait_s_expression_body = [[

bool wait_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    wait_bit_map_s_expr_CFL_t* setup = (wait_bit_map_s_expr_CFL_t*)params;   
}

]]
Store_boolean_function("WAIT_EVALUATE_BIT_MAP","wait_bit_map_s_expr_CFL",wait_s_expression_body,wait_s_expression_header)



function Wait_s_expression(s_buffer,s_expression, time_out_ms, terminate_flag, one_shot_time_out_fn, time_out_data)
    local user_data = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()
    generate_s_bit_expression(s_expression_structure,source_bit_map,s_expression)
    local message = string.format("static const wait_bit_map_s_expr_CFL_t %s = {%s,%s};\n",s_expression_structure,"(void *)&"..time_out_data)
    Store_user_code(message)
    Wait("EVALUATE_BIT_MAP", time_out_ms, terminate_flag, one_shot_time_out_fn, user_data)

end  

local verify_s_expression_header = [[



typedef verify_bit_map_s_expr_CFL_t struct{
    s_bit_definition_CFL_t* definition;
    void* error_message
}verify_bit_map_s_expr_CFL_t;

void verify_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]

local verify_s_expression_body = [[

bool verify_bit_map_s_expr_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    verify_bit_map_s_expr_CFL_t* setup = (verify_bit_map_s_expr_CFL_t*)params;   
}

]]

Store_boolean_function("VERIFY_EVALUATE_BIT_MAP","verify_bit_map_s_expr_CFL",verify_s_expression_body,verify_s_expression_header)

function  Verify_s_expression(source_bit_map,s_expression, terminate_flag, one_shot_time_out_fn, error_data)
    local user_data = generate_unique_function_name()
    local s_expression_structure = generate_unique_function_name()
    generate_s_bit_expression(s_expression_structure,source_bit_map,s_expression)
    local message = string.format("static constverify_bit_map_s_expr_CFL_t %s = {%s,%s};\n",s_expression_structure,"(void *)&"..error_data)
    Store_user_code(message)
    Verify("VERIFY_EVALUATE_BIT_MAP", terminate_flag, one_shot_time_out_fn, user_data)
end

function verify_integer(value)
    if type(value) ~= "number" then
        print("ERROR: value must be a number",value)
        os.exit(1)
    end
    if value < 0 then
        print("ERROR: value must be positive",value)
        os.exit(1)
    end
    if math.floor(value) ~= value then
        print("ERROR: value must be an integer",value)
        os.exit(1)
    end
end

local function verify_no_null_entries(s_expression)
    
    for i = 1, #s_expression do
   
        if s_expression[i] == nil then
            print("ERROR: s_expression must not have nil entries")
            os.exit(1)
        end
    end
end


function add_buffer_positions_to_s_expression(source_buffer,s_expression,position_index_list)
    verify_no_null_entries(position_index_list)
    for i,v in ipairs(position_index_list) do
        verify_integer(v)
        check_s_bit_buffer_parameters(source_buffer,v,1)
        table.insert(s_expression,v)
    end
    table.insert(s_expression,")")
end





function s_and_buffer(bit_map,position_indexes)
    s_expression = {}
    table.insert( s_expression,"@&" )
    add_buffer_positions_to_s_expression(bit_map,s_expression,position_indexes)
    return s_expression

end

function s_or_buffer(bit_map,position_indexes)
    s_expression = {}
    table.insert( s_expression,"@|" )
    add_buffer_positions_to_s_expression(bit_map,s_expression,position_indexes)
    return s_expression    

end

function s_nor_buffer(bit_map,position_indexes)
    s_expression = {}
    table.insert( s_expression,"@~" )
    add_buffer_positions_to_s_expression(bit_map,s_expression,position_indexes)
    return s_expression 

end

function check_for_boolean_operator(operator)
    if type(operator) ~= "boolean" then
        print("ERROR: operator must be a boolean",operator)
        os.exit(1)
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
function pack_boolean(v)
    if(type(v) ~= "boolean") then
        print("ERROR: parameter must be a boolean",v)
        os.exit(1)
    end
    if v == true then
        table.insert(s_expression,1)
    else
        table.insert(s_expression,0)
    end
end



function expand_table(s_expr,parameter_list)
    local op_type = nil
    verify_no_null_entries(parameter_list)
    for i,v in ipairs(parameter_list) do
        table.insert(s_expr,v)
 
    end

 end
 
function expand_table_start(bit_map,s_expression,position_indexes)
    
    verify_no_null_entries(position_indexes)
    for i,v in ipairs(position_indexes) do
        if(type(v) == "table") then
            expand_table(s_expression,v)
        else
            pack_boolean(v)
        end
    end
    table.insert(s_expression,")")
 end


function s_and(bit_map,position_indexes)

    s_expression = {}
    table.insert(s_expression, "&&" )
    expand_table_start(bit_map,s_expression,position_indexes)
    return s_expression

end

function s_or(bit_map,position_indexes)
    s_expression = {}
    table.insert( s_expression,"||" )
    expand_table_start(bit_map,s_expression,position_indexes)
    return s_expression

end

function s_nor(bit_map,position_indexes)
    s_expression = {}
    table.insert( s_expression,"~~" )
    expand_table_start(bit_map,s_expression,position_indexes)
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