
local function generate_column_array(column_list)
    local column_array = generate_unique_function_name()
    local message = string.format("static const unsigned short %s[] = { ",column_array)
    Store_user_code(message) 
    for i,v in ipairs(column_list) do
      local column_number =get_column_number(v)
      Store_user_code(column_number)
      if i ~= #column_list then
        Store_user_code(",")
      end
    end
    Store_user_code("};\n")
    return column_array
end

local enable_function_header = [[

typedef struct Enable_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Enable_column_CFL_t;

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


]]


local enable_function_code = [[

void enable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    
    Enable_column_CFL_t *enable_column = (Enable_column_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL )
    {
       
        for(unsigned i=0;i<enable_column->number_of_columns;i++){
          
            enable_column_CFL(input,enable_column->column_list[i]);
        }
        
        
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        if(enable_column->terminate_flag==true){
           for(unsigned i=0;i<enable_column->number_of_columns;i++){
              disable_column_CFL(input,enable_column->column_list[i]);
           }
        }
    }
        


}



]]

Store_one_shot_function('ENABLE_COLUMN', 'enable_columns_function_CFL',enable_function_code, enable_function_header)


local enable_format_string = "const Enable_column_CFL_t %s = { %s, %s, %s };\n"





function Enable_columns(column_list,terminate_flag)
    if terminate_flag == nil then
        terminate_flag = true
    end

    local column_array = generate_column_array(column_list)
    local enable_name = generate_unique_function_name()
    local message = string.format(enable_format_string,enable_name,terminate_flag,#column_list,column_array)
    Store_user_code(message)
    One_shot_terminate("ENABLE_COLUMN",enable_name)

end

function Reset_columns(column_list,terminate_flag)
    Enable_columns(column_list,terminate_flag)
end

function Chain(column_list)
    Enable_columns(column_list,false)
end









local disable_function_header = [[

typedef struct Disable_column_CFL_t {
    
    const unsigned short number_of_columns;
    const unsigned short *column_list;
}Disable_column_CFL_t;

void disable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data);


]]


local disable_function_code = [[




void disable_columns_function_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
   (void)event_data;
    Disable_column_CFL_t *disable_column = (Disable_column_CFL_t *)params;

    for(unsigned short i=0;i<disable_column->number_of_columns;i++){
        disable_column_CFL(input,disable_column->column_list[i]);
    }

}



]]

Store_one_shot_function('DISABLE_COLUMN', 'disable_columns_function_CFL',disable_function_code, disable_function_header)


local disable_format_string = "const Disable_column_CFL_t %s = { %s, %s };\n"





function Disable_columns(column_list) 
    local column_array = generate_column_array(column_list)
    local disable_name = generate_unique_function_name()
    local message = string.format(disable_format_string,disable_name,#column_list,column_array)
    Store_user_code(message)
    One_shot("DISABLE_COLUMN",disable_name)

end


local join_function_header = [[

typedef struct Join_column_CFL_t {
    const bool    terminate_flag;
    const unsigned short number_of_columns;
    const unsigned short *column_list;
} Join_column_CFL_t;

int join_columns_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);


]]


local join_function_code = [[


static inline void join_terminate_columns_CFL(const void *input, Join_column_CFL_t *join_column){
    unsigned short i;
    for(i=0;i<join_column->number_of_columns;i++){
        disable_column_CFL(input,join_column->column_list[i]);
    }
}

int join_columns_function_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Join_column_CFL_t *join_column = (Join_column_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        ; // do nothing
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
        if(join_column->terminate_flag==true){
            join_terminate_columns_CFL(input,join_column);
        }
        return DISABLE_CFL;
    }


    if(event_data->event_index == TIMER_TICK_CFL ){
       if(join_columns_CFL(input,join_column->number_of_columns,join_column->column_list)==true){
           return CONTINUE_CFL;
       }
       return HALT_CFL;
    }
    return HALT_CFL;
}



]]

Store_column_function('JOIN_COLUMN', 'join_columns_function_CFL',join_function_code, join_function_header)


local join_format_string = "const Join_column_CFL_t %s = { %s, %s, %s };\n"







function Join_columns(column_list,terminate_flag)
     if terminate_flag == nil then
        terminate_flag = true
     end
     local column_array = generate_column_array(column_list)
     local join_name = generate_unique_function_name()
     local message = string.format(join_format_string,join_name,terminate_flag,#column_list,column_array)
     Store_user_code(message)
     Activate_column_function('JOIN_COLUMN')
     local column_fn_name = Get_column_function("JOIN_COLUMN")
     local aux_fn_name = Get_one_shot_function("NULL")
     store_column_element(column_fn_name,aux_fn_name,'(void *)&'..join_name)

end

local if_then_else_header = [[
typedef struct If_then_else_CFL_t {
    const bool    terminate_flag;
    const bool    join_flag;
    const unsigned short number_of_then_columns;
    const unsigned short *then_column_list;
    const unsigned short number_of_else_columns;
    const unsigned short *else_column_list;
    void *user_data;
} If_then_else_CFL_t;

int if_then_else_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local if_then_else_code = [[

int if_then_else_function_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t )aux_fn;
    If_then_else_CFL_t *if_then_else = (If_then_else_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL ){
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            for(unsigned i=0;i<if_then_else->number_of_then_columns;i++){
          
                enable_column_CFL(input,if_then_else->then_column_list[i]);
            }
            
        }
        else{
            for(unsigned i=0;i<if_then_else->number_of_else_columns;i++){
          
                enable_column_CFL(input,if_then_else->else_column_list[i]);
            }

        }
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL ){
       
        if(if_then_else->terminate_flag==false){
            return CONTINUE_CFL;
        }
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            for(unsigned i=0;i<if_then_else->number_of_then_columns;i++){
                 disable_column_CFL(input,if_then_else->then_column_list[i]);
             }
        }
         else{
            for(unsigned i=0;i<if_then_else->number_of_else_columns;i++){
                disable_column_CFL(input,if_then_else->else_column_list[i]);
            }
        }
        return CONTINUE_CFL;
    }
   
    
    if(event_data->event_index == TIMER_TICK_CFL ){
        if((if_then_else->join_flag == false)&&(if_then_else->terminate_flag==false)){
            return DISABLE_CFL;
        }
        if((if_then_else->join_flag == false)&&(if_then_else->terminate_flag == true)){
            return CONTINUE_CFL;
        }
        if(bool_fn(input,if_then_else->user_data,event_data)==true){
            if(join_columns_CFL(input,if_then_else->number_of_then_columns,if_then_else->then_column_list) == true){
                return DISABLE_CFL;
            }
        }else{
            if(join_columns_CFL(input,if_then_else->number_of_else_columns,if_then_else->else_column_list) == true){
                return DISABLE_CFL;
            }
        }
    }
    return HALT_CFL;
    
}

]]

Store_column_function('IF_THEN_ELSE', 'if_then_else_function_CFL',if_then_else_code, if_then_else_header)



local if_then_format_string = "const If_then_else_CFL_t %s = { %s, %s, %s, %s, %s, %s,%s };\n"

function If_then_else_columns(bool_function_name,user_data,then_columns,else_columns,join_flag,terminate_flag)
    local bool_fn = Get_boolean_function(bool_function_name)
    Activate_boolean_function(bool_function_name)
    if join_flag == nil then
        join_flag = true
    end
    if terminate_flag == nil then
        terminate_flag = true
    end
    
    local then_array = generate_column_array(then_columns)
    local else_array = generate_column_array(else_columns)
    local if_then_else_name = generate_unique_function_name()
    local message = string.format(if_then_format_string,if_then_else_name,terminate_flag,join_flag,#then_columns,then_array,#else_columns,else_array,user_data)
    Store_user_code(message)
    Activate_column_function('IF_THEN_ELSE')
    column_fn_name = Get_column_function("IF_THEN_ELSE")
    store_column_element(column_fn_name,bool_fn,'(void *)&'..if_then_else_name)
end


local while_function_header = [[
typedef struct While_column_control_CFL_t
{
   bool  *state;
   unsigned *current_count;
   void* user_data;
   const unsigned short number_of_columns;
   const unsigned short* column_indexes;

   

} While_column_control_CFL_t;

int while_column_handler_CFL(const void *input, void *aux_fn,void *params, Event_data_CFL_t *event_data);

]]

local while_function_code = [[
int while_column_handler_CFL(const void *input, void *aux_fn,void *params, Event_data_CFL_t *event_data)
{
    Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
    While_column_control_CFL_t *while_control;
    while_control = (While_column_control_CFL_t *)params;

    if (event_data->event_index == EVENT_INIT_CFL)
    {
       fn(input, while_control, event_data);
       *while_control->current_count = 0;
       *while_control->state = true;
      

    }

    if (event_data->event_index == EVENT_TERMINATION_CFL)
    {

        for(unsigned i=0;i<while_control->number_of_columns;i++){
            disable_column_CFL(input,while_control->column_indexes[i]);
        }
    }
    if (event_data->event_index != TIMER_TICK_CFL)
    {
        return HALT_CFL;
    }
    
    if(*while_control->state == true){
        if(fn(input, while_control, event_data) == false)
        {
           
            // chains are already disabled
            return DISABLE_CFL;
        }else{
            *while_control->current_count = *while_control->current_count + 1;
            for(unsigned i=0;i<while_control->number_of_columns;i++){
                enable_column_CFL(input,while_control->column_indexes[i]);
            }
            
        }
        *while_control->state = false;
        return HALT_CFL;
    }else{
        if(join_columns_CFL(input,while_control->number_of_columns,while_control->column_indexes) == true){
            *while_control->state = true;
        }


    }

    return HALT_CFL;
}
]]

Store_column_function("WHILE_COLUMN", 'while_column_handler_CFL',while_function_code, while_function_header)


local while_format_string = "const While_column_control_CFL_t %s = { %s, %s, %s, %s,%s };\n"

local state_format = "bool %s = true;\n"

function while_handler(bool_function_name,user_data,column_list)
    local bool_fn = Get_boolean_function(bool_function_name)
    Activate_boolean_function(bool_function_name)
    local column_array = generate_column_array(column_list)
    local state_name = generate_unique_function_name()

    local message = string.format(state_format,state_name)
    Store_user_code(message)
    state_name = '(bool *)&'..state_name
    local current_count = generate_unique_function_name()
    message = string.format("unsigned %s = 0;\n",current_count)
    Store_user_code(message)
    current_count = '(unsigned *)&'..current_count;
    
    local while_name = generate_unique_function_name()
    if user_data ~= 'NULL' then
        user_data = '(void *)&'..user_data
    end
    local message = string.format(while_format_string,while_name,state_name,current_count,user_data,#column_list,column_array)
    Store_user_code(message)
    Activate_column_function('WHILE_COLUMN')
    local column_fn_name = Get_column_function("WHILE_COLUMN")
    
    store_column_element(column_fn_name,bool_fn,'(void *)&'..while_name)
end

--[[
bool state
//unsigned char progress_step;
  bool final_state;
typedef struct Try_column_CFL_t
{

  bool invert_flag;

  
  unsigned short current_column_index;
  unsigned short column_number;
  unsigned short* column_indexes;

  void* user_data;

} Try_column_CFL_t;





static int try_column_handler(void *input, void *aux_fn, void *params,
                              Event_data_CFL_t *event_data)
{

  Try_function_CFL_t fn = (Try_function_CFL_t)aux_fn;
  Try_column_CFL_t *data;
  bool pass_flag;

  data = (Try_column_CFL_t *)params;
  pass_flag = !data->invert_flag;
  if (event_data->event_index == EVENT_INIT_CFL)
  {

    data->progress_step = 0;
    data->current_column_index = 0;
    disable_indexes(input, data->column_number, data->column_indexes);
    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    

      disable_indexes(input, data->column_number, data->column_indexes);
   
  }
  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return HALT_CFL;
  }
  if (data->progress_step == 0)
  {
    Enable_column_CFL(input, data->column_indexes[data->current_column_index]);
    data->progress_step = 1;
    return HALT_CFL;
  }

  if (Column_State_CFL(
          input, data->column_indexes[data->current_column_index]) == false)
  {

    if (Get_column_index_return_code_CFL(
            input, data->column_indexes[data->current_column_index]) ==
        pass_flag)
    {
      data->final_state = true;
      fn(input, data);
      return DISABLE_CFL;
    }

    if (data->current_column_index < data->column_number - 1)
    {
      data->current_column_index += 1;
      data->progress_step = 0;
      return HALT_CFL;
    }
    else
    {
      data->final_state = false;
      fn(input, data);
      return DISABLE_CFL;
    }

    return HALT_CFL;
  }
  return HALT_CFL; // try column is still active
}

]]