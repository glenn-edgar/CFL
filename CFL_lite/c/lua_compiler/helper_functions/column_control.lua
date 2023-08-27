
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
    local column_array = generate_column_array(column_list)
    local enable_name = generate_unique_function_name()
    local message = string.format(enable_format_string,enable_name,terminate_flag,#column_list,column_array)
    Store_user_code(message)
    One_shot_terminate("ENABLE_COLUMN",enable_name)

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
     local column_array = generate_column_array(column_list)
     local join_name = generate_unique_function_name()
     local message = string.format(join_format_string,join_name,terminate_flag,#column_list,column_array)
     Store_user_code(message)
     Activate_column_function('JOIN_COLUMN')
     local column_fn_name = Get_column_function("JOIN_COLUMN")
     local aux_fn_name = Get_one_shot_function("NULL")
     store_column_element(column_fn_name,aux_fn_name,'(void *)&'..join_name)

end


local if_function_header = [[
int if_column_handler(void *input, void *aux_fn, void *params,
                             Event_data_CFL_t *event_data);
]]



typedef struct If_control_CFL_t
{


  unsigned short column_number;
  unsigned short* column_indexes;
  bool* return_indexes;
  One_shot_function_CFL_t termination_fn;
  void* user_data;
} If_control_CFL_t;


local if_function_code = [[
int if_column_handler(void *input, void *aux_fn, void *params,
                             Event_data_CFL_t *event_data)
{

  If_function_CFL_t fn = (If_function_CFL_t)aux_fn;
  

  If_control_CFL_t *if_control = (If_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    for(unsigned short i=0;i<if_control->column_number;i++){
        if_control->return_indexes[i] = disable_column_CFL(input,if_control->column_indexes[i]);
    }
    fn(input, if_control);
    for(unsigned short i=0;i<if_control->column_number;i++){
        if(if_control->return_indexes[i]==true){
            enable_column_CFL(input,if_control->column_indexes[i]);
        }
    }
    return CONTINUE_CFL;
  }
  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {

    

    for(unsigned short i=0;i<if_control->column_number;i++){
        if_control->return_indexes[i] = disable_column_CFL(input,if_control->column_indexes[i]);
    }
    return CONTINUE_CFL;
   
  }

  
  if (number_Of_active_columns(input, if_control->column_number,
                               if_control->column_indexes) == 0)
  {
    if( if_control->termination_fn != NULL){
        if_control->termination_fn(input, if_control, event_data);
        
    }
    return DISABLE_CFL;
  }
  return HALT_CFL;
}
]]

Store_column_function('IF_COLUMN', 'if_column_handler',if_function_code, if_function_header)

local if_format_string = "const If_control_CFL_t %s = { %s, %s, %s, %s, %s };\n"

function if_column_control(if_fn,column_list,termination_fn,user_data)
    one_shot = Get_one_shot_function(termination_fn)
    Activate_one_shot_function(termination_function)
    local column_array = generate_column_array(column_list)
    local if_name = generate_unique_function_name()
    local message = string.format(if_format_string,if_name,#column_list,column_array,one_shot,'(void *)'..user_data)
    Store_user_code(message)
    Activate_column_function('IF_COLUMN')
    local column_fn_name = Get_column_function("IF_COLUMN")
    local aux_fn_name = Get_if_function(if_fn)
    Activate_if_function(if_fn)
    store_column_element(column_fn_name,aux_fn_name,'(void *)&'..if_name)
end


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



static int while_column_handler(void *handle, void *aux_fn, void *params,
                                Event_data_CFL_t *event_data)
{
  Bool_function_CFL_t fn = (Bool_function_CFL_t)aux_fn;
  While_column_control_CFL_t *while_control;
  while_control = (While_column_control_CFL_t *)params;

  if (event_data->event_index == EVENT_INIT_CFL)
  {
    while_control->state = 0;
    while_control->current_iterations = 0;
  }

  if (event_data->event_index == EVENT_TERMINATION_CFL)
  {
    disable_indexes(handle, while_control->number_of_columns,
                    while_control->column_indexes);
  }
  if (event_data->event_index != TIMER_TICK_CFL)
  {
    return HALT_CFL;
  }
  switch (while_control->state)
  {
  case 0:
    if (fn(handle, while_control, event_data) == false)
    {
      return DISABLE_CFL;
    }
    enable_indexes(handle, while_control->number_of_columns,
                   while_control->column_indexes);
    while_control->current_iterations += 1;
    while_control->state = 1;
    break;
  default:
    if (number_Of_active_columns(handle, while_control->number_of_columns,
                                 while_control->column_indexes) == 0)
    {
      while_control->state = 0;
    }
  }
  return HALT_CFL;
}

