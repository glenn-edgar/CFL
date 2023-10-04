
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

function get_buffer_number(buffer_name)
    local buffer_data = bit_map_definition[buffer_name]
    if buffer_data == nil then
        print("ERROR: buffer not defined",buffer_name)
        os.exit(1)
    end
    return buffer_data.number, buffer_data.byte_number
end

function check_buffer_parameters(source_buffer,source_offset,size)
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
    local buffer_number,buffer_size = get_buffer_number(buffer_name)
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
   
    local buffer_number = get_buffer_number(buffer_name)
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
    local source_buf_number = get_buffer_number(source_buffer)
        
    local destination_buf_number = get_buffer_number(destination_buffer)
    check_buffer_parameters(source_buffer,source_offset,size)
    check_buffer_parameters(destination_buffer,destination_offset,size)
   
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
    local source_buf_number = get_buffer_number(source_buffer)
        
    local destination_buf_number = get_buffer_number(destination_buffer)
    check_buffer_parameters(source_buffer,source_offset,size)
    check_buffer_parameters(destination_buffer,destination_offset,size)
   
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
    local source_buf_number = get_buffer_number(source_buffer)
        
    local destination_buf_number = get_buffer_number(destination_buffer)
    check_buffer_parameters(source_buffer,source_offset,size)
    check_buffer_parameters(destination_buffer,destination_offset,size)
   
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
    local source_buf_number = get_buffer_number(source_buffer)
        
    local destination_buf_number = get_buffer_number(destination_buffer)
    check_buffer_parameters(source_buffer,source_offset,size)
    check_buffer_parameters(destination_buffer,destination_offset,size)
   
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
    local source_buf_number = get_buffer_number(source_buffer)
        
    local destination_buf_number = get_buffer_number(destination_buffer)
    check_buffer_parameters(source_buffer,source_offset,size)
    check_buffer_parameters(destination_buffer,destination_offset,size)
   
    user_data = generate_unique_function_name()
    local message = string.format("static const bit_map_not_CFL_t %s = {%d,%d,%d,%d,%d};\n",user_data,source_buf_number,destination_buf_number,source_offset,destination_offset,size)
    Store_user_code(message)
    One_shot("NOT_BIT_MAP_BUFFER",user_data)
end







