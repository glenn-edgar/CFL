
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


local function generate_short_array(array_list)
    local int_array = generate_unique_function_name()
    local message = string.format("static const int16_t %s[] = { ",int_array)
    Store_user_code(message) 
    for i,v in ipairs(array_list) do
     
      Store_user_code(v)
      if i ~= #array_list then
        Store_user_code(",")
      end
    end
    Store_user_code("};\n")
    return int_array
end

local function generate_boolean_array(number_of_items)
    local boolean_array = generate_unique_function_name()
    local message = string.format("static bool %s[] = { ",boolean_array)
    Store_user_code(message) 
    for i=1,number_of_items do
          Store_user_code("false")
          if i ~= number_of_items then
            Store_user_code(",")
          end
    end
    Store_user_code("};\n")
    return boolean_array
end
 
function generate_unsigned_array(number_of_items)
    local unsigned_array = generate_unique_function_name()
    local message = string.format("static unsigned %s[] = { ",unsigned_array)
    Store_user_code(message) 
    for i=1,number_of_items do
          Store_user_code("0")
          if i ~= number_of_items then
            Store_user_code(",")
          end
    end
    Store_user_code("};\n")
    return unsigned_array
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
            if(get_current_column_index_CFL(input) != enable_column->column_list[i]){
               enable_column_CFL(input,enable_column->column_list[i]);
            }
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
           return DISABLE_CFL;
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
        fn(input, while_control, event_data);
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


---
---
--- Generate Column Function for Supervisor


local supervisor_header = [[
typedef struct Supervisor_data_CFL_t
{
  const unsigned short reset_type;
  const unsigned short column_number;
  const unsigned short* column_list;
  bool *restart_mask;
  unsigned *reset_count;
  unsigned *secondary_reset_count;
  const bool terminate_flag;
  const void* user_data;

} Supervisor_data_CFL_t;


int supervisor_control_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local supervisor_code = [[

static void mark_disabled_columns(const void *input, Supervisor_data_CFL_t *supervisor_data)
{
  for (unsigned short i = 0; i < supervisor_data->column_number; i++)
  {
    supervisor_data->restart_mask[i] = !column_state_CFL(input, supervisor_data->column_list[i]);
  
    if (supervisor_data->restart_mask[i] != false)
    {
        supervisor_data->reset_count[i] = supervisor_data->reset_count[i] + 1;
       
    }
  }
}

static void mark_columns_for_reset(const void *input, Supervisor_data_CFL_t *supervisor_data)
{
  (void)input;
  switch (supervisor_data->reset_type)
  {
    case 0: // one for one
        for (unsigned i = 0; i < supervisor_data->column_number; i++)
        {
            if (supervisor_data->restart_mask[i] == true)
            {
        
            supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
            }
        }
      break;
    case 1: // one for all
        ;
        bool state = false;
        for (unsigned i = 0; i < supervisor_data->column_number; i++)
        {
            if (supervisor_data->restart_mask[i] == true)
            {
                state = true;
                break;
            }
            
        }
        if (state == true)
        {
            for (unsigned i = 0; i < supervisor_data->column_number; i++)
            {
                supervisor_data->restart_mask[i] = true;
                supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
            
            }
        }
        break;
    case 2: // rest for one
        
        state = false;
        for (unsigned i = 0; i < supervisor_data->column_number; i++)
        {
            if(state == false){
               if (supervisor_data->restart_mask[i] == true)
               {
                  state = true;
                  supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
                  
                } 
            } else {
             
                supervisor_data->restart_mask[i] = true;
                supervisor_data->secondary_reset_count[i] = supervisor_data->secondary_reset_count[i] + 1;
            }
        }
        break;
    }
}

static void reset_marked_columns(const void *input, Supervisor_data_CFL_t *supervisor_data)
{
  for (unsigned i = 0; i < supervisor_data->column_number; i++)
  {
    if (supervisor_data->restart_mask[i] == true)
    {
      enable_column_CFL(input, supervisor_data->column_list[i]);
    }
  }
}

static void disable_all_supervised_columns(const void *input, Supervisor_data_CFL_t *supervisor_data){
    for (unsigned i = 0; i < supervisor_data->column_number; i++)
    {
        disable_column_CFL(input, supervisor_data->column_list[i]);
    }

}

int supervisor_control_CFL(const void *input,void *aux_fn, void *params, Event_data_CFL_t *event_data){
    Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
    Supervisor_data_CFL_t *supervisor_data = (Supervisor_data_CFL_t *)params;
    if(event_data->event_index == EVENT_INIT_CFL){
        bool_fn(input,supervisor_data,event_data);
        for(unsigned i=0;i<supervisor_data->column_number;i++){
            supervisor_data->reset_count[i] = 0;
            supervisor_data->secondary_reset_count[i] = 0;
            supervisor_data->restart_mask[i] = false;
        }
        return CONTINUE_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
        bool_fn(input,supervisor_data,event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index == SUPERVISOR_EVENT_CFL   ){
        bool_fn(input,supervisor_data,event_data);
        return CONTINUE_CFL;
    }
    if(event_data->event_index != TIMER_TICK_CFL){
        return  CONTINUE_CFL;
    }
    // this path is for the timer tick
    // determine column state
    mark_disabled_columns(input, supervisor_data);
    
    mark_columns_for_reset(input, supervisor_data);
    bool result = bool_fn(input, supervisor_data, event_data);
   
    if( result == false){
        disable_all_supervised_columns(input, supervisor_data);
        if(supervisor_data->terminate_flag == true){
            return TERMINATE_CFL;
        }else{
            return RESET_CFL;
        }
    }
    reset_marked_columns(input, supervisor_data);
    return CONTINUE_CFL;
   
}
]]

Store_column_function("SUPERVISOR", 'supervisor_control_CFL',supervisor_code, supervisor_header)


--[[
 unsigned short reset_type;
  unsigned short column_number;
  const unsigned short* column_indexes;
  bool *restart_mask;
  unsigned *reset_count;
  unsigned *secondary_reset_count;
  bool terminate_flag;
  dconst void* user_data;


]]

local function bool_to_number(value)
    return value and 1 or 0
end

function Supervisor(list_of_columns,reset_type, error_function, user_data, termination_flag)
    if termination_flag == nil then
        termination_flag = true
    end
    termination_flag = bool_to_number(termination_flag)
    error_function_name = Get_boolean_function(error_function)
    local column_array = generate_column_array(list_of_columns)
    local reset_mask =   generate_boolean_array(#list_of_columns)
    local reset_count = generate_unsigned_array(#list_of_columns)
    local secondary_reset_count = generate_unsigned_array(#list_of_columns)
    local supervisor_name = generate_unique_function_name()
    if user_data == 'NULL' then
        user_data = 'NULL'
    else
        user_data = '(void *)&'..user_data
    end
    local message = string.format("const Supervisor_data_CFL_t %s = { %d,%d, %s, %s, %s,%s,%d,%s};\n",
                supervisor_name,
                reset_type,
                #list_of_columns,
                column_array,
                reset_mask,
                reset_count,
                secondary_reset_count,
                termination_flag,
                user_data)
    Store_user_code(message)
    Activate_column_function('SUPERVISOR')
    local column_fn_name = Get_column_function("SUPERVISOR")
    store_column_element(column_fn_name, error_function_name,'(void *)&'..supervisor_name)
end


function Supervisor_1_for_1( list_of_columns, error_function, user_data, termination_flag)
    Supervisor(list_of_columns,0, error_function, user_data, termination_flag)
end

function Supervisor_1_for_all( list_of_columns, error_function, user_data,  termination_flag)
    Supervisor(list_of_columns,1, error_function, user_data, termination_flag)
end

function Supervisor_rest_for_one( list_of_columns, error_function, user_data, termination_flag)
    Supervisor(list_of_columns,2, error_function, user_data, termination_flag)
end



set_boolean_column_flags_header = [[

typedef struct Set_return_code_CFL_t
{
    unsigned short column_number;
    const unsigned short *column_list;
    bool bool_flag;
} Set_return_code_CFL_t;
            
void set_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data);
            
]]
            
local set_boolean_column_flags_code = [[
            
void set_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Set_return_code_CFL_t *set_return_code = (Set_return_code_CFL_t *)params;
    for(unsigned i=0;i<set_return_code->column_number;i++){
        set_column_return_code_CFL(input,set_return_code->column_list[i],set_return_code->bool_flag);
    }
    
   
}
            
]]
Store_one_shot_function("SET_RETURN_CODE", 'set_return_code_CFL',set_boolean_column_flags_code, set_boolean_column_flags_header)

display_boolean_column_flags_header = [[

typedef struct Display_return_code_CFL_t
{
    unsigned short column_number;
    const unsigned short *column_list;
} Display_return_code_CFL_t;
            
void display_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data);
            
]]
            
local display_boolean_column_flags_code = [[
            
void display_return_code_CFL(const void *input,void *params, Event_data_CFL_t *event_data){
    (void)event_data;
    Display_return_code_CFL_t *display_return_code = (Display_return_code_CFL_t *)params;
    Printf_CFL(input,"Displaying column flags\n");
    for(unsigned i=0;i<display_return_code->column_number;i++){
        bool  column_value  = get_column_return_code_CFL(input,display_return_code->column_list[i]);
        Printf_CFL(input,"Column %d has column flag %d\n",display_return_code->column_list[i],column_value);
    }
    
   
}
            
]]


            
Store_one_shot_function("DISPLAY_RETURN_CODE", 'display_return_code_CFL',display_boolean_column_flags_code, display_boolean_column_flags_header)
            
            
function Set_column_flag(list_of_columns, boolean_value)

    local structure_name = generate_unique_function_name()
    local column_array = generate_column_array(list_of_columns)
    local message = string.format("const Set_return_code_CFL_t %s = { %d,%s,%s };\n",structure_name,#list_of_columns,column_array,boolean_value)
    Store_user_code(message)
    One_shot("SET_RETURN_CODE",structure_name)
end
            
function Display_column_flag(list_of_columns)

    local structure_name = generate_unique_function_name()
    local column_array = generate_column_array(list_of_columns)
    local message = string.format("const Display_return_code_CFL_t %s = { %d,%s };\n",structure_name,#list_of_columns,column_array)
    Store_user_code(message)
    One_shot("DISPLAY_RETURN_CODE",structure_name)
end
        

local sequence_columns_header = [[
#include "CFL_useful_utilities.h"
int sequence_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data );
    
]]


local sequence_columns_code = [[


int sequence_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data ){
    (void)aux_fn;
   
    return sequence_columns_utility_CFL(input, params, event_data);

}
]]



Store_column_function("SEQUENCE_COLUMNS", 'sequence_columns_CFL',sequence_columns_code, sequence_columns_header)


function generate_sequence_columns( list_of_columns )
    local sequence_name = generate_unique_function_name()
    local column_number = #list_of_columns
    local column_array = generate_column_array(list_of_columns)
    local column_index = generate_unique_function_name()
    local state = generate_unique_function_name()
    local message = string.format("unsigned short %s = 0;\n",column_index)
    Store_user_code(message)
    message = string.format("bool %s = true;\n",state)
    Store_user_code(message)

    message = string.format("const sequence_columns_CFL_t %s = { %d, %s, &%s, &%s };\n",sequence_name,column_number, column_array,column_index,state)
    Store_user_code(message)
    return sequence_name
end

function Sequence_columns( list_of_columns )
    local sequence_name = generate_sequence_columns( list_of_columns )
    local column_fn_name = Get_column_function("SEQUENCE_COLUMNS")
    store_column_element(column_fn_name, 'NULL','(void *)&'..sequence_name)
end

local try_column_header = [[
typedef struct Try_columns_CFL_t
{
  unsigned short column_number;
  const unsigned short *column_list;
  bool invert_flag;
  unsigned short *column_index;
  bool *state;
} Try_columns_CFL_t;

int try_columns_CFL(const void *input,void *fn_aux, void *params, Event_data_CFL_t *event_data );
]]

local try_columns_code = [[
static inline void  mark_return_code_CFL(const void *input, bool status_flag){
   unsigned short column_number = get_current_column_index_CFL(input);
   set_column_return_code_CFL(input,column_number,status_flag);
}

static inline bool try_check_column_state_CFL(const void *input, unsigned short column_index, bool invert_flag){
    bool state = get_column_return_code_CFL(input,column_index);
    
    if(invert_flag != state){
        
        mark_return_code_CFL(input,true);
        return true;
    }
    return false;

}

int try_columns_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data ){
    (void)aux_fn;
    const Try_columns_CFL_t* try_columns = (const Try_columns_CFL_t *)params;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
    if(event_data->event_index == EVENT_INIT_CFL ){
      *try_columns->column_index = 0;
      *try_columns->state = true;
      return HALT_CFL;
    }
    if(event_data->event_index == EVENT_TERMINATION_CFL){
      for(int i = 0; i < try_columns->column_number; i++){
        disable_column_CFL(handle, try_columns->column_list[i]);
      }
      return DISABLE_CFL;
    }
    if(event_data->event_index != TIMER_TICK_CFL){
      return HALT_CFL;
    }
    if(*try_columns->state == true){

      enable_column_CFL(handle, try_columns->column_list[*try_columns->column_index]);
      *try_columns->state = false;      
    }
    else{
        if(column_state_CFL(handle, try_columns->column_list[*try_columns->column_index]) == false){
           if(try_check_column_state_CFL(handle, try_columns->column_list[*try_columns->column_index],try_columns->invert_flag) == true){
              return DISABLE_CFL;
           }
           *try_columns->state = true;
           *try_columns->column_index = *try_columns->column_index + 1;
           if(*try_columns->column_index >= try_columns->column_number){
              mark_return_code_CFL(handle, false);
              return DISABLE_CFL;
           }
        }   
       
    }
    return HALT_CFL;
}
]]

Store_column_function("TRY_COLUMN", 'try_columns_CFL',try_columns_code, try_column_header)

function Try_columns(invert_flag, list_of_columns)
    local column_list = generate_column_array(list_of_columns)
    local try_name = generate_unique_function_name()
    local column_index = generate_unique_function_name()
    local state = generate_unique_function_name()
    local message = string.format("unsigned short %s = 0;\n",column_index)
    Store_user_code(message)
    message = string.format("bool %s = true;\n",state)
    Store_user_code(message)
    message = string.format("const Try_columns_CFL_t %s = { %d, %s, %s, &%s, &%s };\n",try_name,#list_of_columns, column_list,invert_flag,column_index,state)   
    Store_user_code(message)
    local column_fn_name = Get_column_function("TRY_COLUMN")
    store_column_element(column_fn_name, 'NULL','(void *)&'..try_name)
end
  

local assert_column_header = [[
#include "CFL_useful_utilities.h"    
typedef struct Assert_column_CFL_t
{

    sequence_columns_CFL_t sequence_columns;
    void *user_data;
    bool termination_flag;
    bool *result;
} Assert_column_CFL_t;


int assert_column_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data );

]]

local assert_column_code = [[

int assert_column_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
   Assert_column_CFL_t *assert_column = ( Assert_column_CFL_t *)params;
   Bool_function_CFL_t bool_fn = (Bool_function_CFL_t)aux_fn;
   if(event_data->event_index == EVENT_INIT_CFL){
      *assert_column->result = bool_fn(input,assert_column->user_data,event_data);
      if(*assert_column->result == false){
        sequence_columns_utility_CFL(input,  &assert_column->sequence_columns, event_data);
     }
   }
   if(event_data->event_index == EVENT_TERMINATION_CFL){
     if(*assert_column->result == false){
        sequence_columns_utility_CFL(input,   &assert_column->sequence_columns, event_data);
     }
     return CONTINUE_CFL;
   }
   if(*assert_column->result == true){
      return DISABLE_CFL;
   }
    if(event_data->event_index != TIMER_TICK_CFL){
        return HALT_CFL;
    }
   int return_code = sequence_columns_utility_CFL(input, &assert_column->sequence_columns, event_data);
   if(return_code == DISABLE_CFL){
      if(assert_column->termination_flag == true){
         return TERMINATE_CFL;
      }
      return RESET_CFL;
   }
   return HALT_CFL;

}

]]
Store_column_function("ASSERT_COLUMN", 'assert_column_CFL',assert_column_code, assert_column_header)

function Assert_column( Bool_fn,  user_data, termination_flag, list_of_columns)
    if user_data == 'NULL' then
        user_data = 'NULL'
    else
        user_data = '(void *)&'..user_data
    end
    local bool_fn = Get_boolean_function(Bool_fn)
    local assert_name = generate_unique_function_name()
    local sequence_name = generate_sequence_columns( list_of_columns )
    local result = generate_unique_function_name()
    message = string.format("bool %s = true;\n",result)
    Store_user_code(message)

    local message = string.format("const Assert_column_CFL_t %s = { %s, %s, %s, &%s };\n",assert_name,sequence_name,user_data,termination_flag,result)
    Store_user_code(message)

    local column_fn_name = Get_column_function("ASSERT_COLUMN")
    store_column_element(column_fn_name,bool_fn,'(void *)&'..assert_name)
end


local assert_flag_header = [[
typedef struct Assert_flag_CFL_t
{
    bool flag_value;
    unsigned short column_index;
    Bool_function_CFL_t bool_fn;
    void *user_data;
} Assert_flag_CFL_t;


bool assert_flag_CFL(const void *input, void *params, Event_data_CFL_t *event_data);

]]


local assert_flag_code = [[

bool assert_flag_CFL(const void *input, void *params, Event_data_CFL_t *event_data){
    Assert_flag_CFL_t *assert_flag = (Assert_flag_CFL_t *)params;


    
    bool flag = get_column_return_code_CFL(input,assert_flag->column_index);
   
   
    if(flag != assert_flag->flag_value){
        return assert_flag->bool_fn(input,assert_flag->user_data,event_data);
    }
    
    return true;


}

]]

Store_boolean_function("ASSERT_COLUMN_FLAG", 'assert_flag_CFL',assert_flag_code, assert_flag_header)




function Assert_flag( column_name, bool_value, Bool_name, user_data,termination_flag, list_of_columns)
    Bool_fn = Get_boolean_function(Bool_name)
    local column_index = get_column_number(column_name)
    
    function_data = generate_unique_function_name()
    if user_data == 'NULL' then
        user_data = 'NULL'
    else
        user_data = '(void *)&'..user_data
    end 
    local message = string.format("const Assert_flag_CFL_t %s = { %s, %s,%s, %s };\n",function_data,bool_value,column_index,Bool_fn,user_data)
    Store_user_code(message)

    Assert_column( "ASSERT_COLUMN_FLAG",  function_data, termination_flag, list_of_columns)
end

function Assert_col_flag( bool_value, Bool_fn, user_data,termination_flag, list_of_columns)
  local column =  active_column["name"]
  Assert_flag( column_index, bool_value, Bool_fn, user_data,termination_flag, list_of_columns)
end

----------------------
-- Chain Columns Sequence
----------------------

local chain_columns_sequence_header = [[
typedef struct Chain_columns_sequence_CFL_t
{
   uint16_t number_of_columns;
   const uint16_t *column_list;
   uint16_t number_of_events;
   const int16_t *event_list;

} Chain_columns_sequence_CFL_t;   

int chain_columns_sequence_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local chain_columns_sequence_code = [[

int chain_columns_sequence_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    (void)aux_fn;
    Chain_columns_sequence_CFL_t *chain_columns = (Chain_columns_sequence_CFL_t *)params;
   
    if(event_data->event_index >= 0){
        for(unsigned i=0;i< chain_columns->number_of_events;i++){
            if(chain_columns->event_list[i] == event_data->event_index){
                for(unsigned i=0;i<chain_columns->number_of_columns;i++){
                    chain_single_sweep_CFL( input, chain_columns->column_list[i], event_data);
                }
            }
        }
   
    }
    return CONTINUE_CFL;
}


]]


Store_column_function("CHAIN_COLUMNS_SEQUENCE", 'chain_columns_sequence_CFL',chain_columns_sequence_code, chain_columns_sequence_header)


function Chain_columns_sequence( event_list,  list_of_columns )

    local chain_name = generate_unique_function_name()
    local column_array = generate_column_array(list_of_columns)
    local event_array = generate_short_array(event_list)

    local message = string.format("const Chain_columns_sequence_CFL_t %s = { %d, %s,%d, %s };\n",chain_name,#list_of_columns,column_array,#event_list,event_array)
    Store_user_code(message)
    local column_fn_name = Get_column_function("CHAIN_COLUMNS_SEQUENCE")
    store_column_element(column_fn_name, 'NULL','(void *)&'..chain_name)
end



----------------------
-- Chain Columns Case
----------------------

local chain_columns_case_header = [[
typedef struct Chain_columns_case_CFL_t
{
   uint16_t number_of_columns;
   const uint16_t *column_list;
   const void *user_data;
  
} Chain_columns_case_CFL_t;   

int chain_columns_case_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data);

]]

local chain_columns_case_code = [[

int chain_columns_case_CFL(const void *input, void *aux_fn, void *params, Event_data_CFL_t *event_data){
    State_function_CFL_t fn = (State_function_CFL_t)aux_fn;
    Chain_columns_case_CFL_t *chain_columns = (Chain_columns_case_CFL_t *)params;
    bool continue_flag = true;
    if(event_data->event_index >= 0){
      int result = fn(input,(void *)chain_columns->user_data,event_data,&continue_flag);
      if(result > chain_columns->number_of_columns -1){
          result = chain_columns->number_of_columns -1;
      }
      if( result >= 0){
            chain_single_sweep_CFL( input, chain_columns->column_list[result], event_data);
      }
      if(continue_flag == false){
          return HALT_CFL;
      }
        
    }
    return CONTINUE_CFL;
}


]]


Store_column_function("CHAIN_COLUMNS_CASE", 'chain_columns_case_CFL',chain_columns_case_code, chain_columns_case_header)


function Chain_columns_case( case_function, user_data,list_of_columns )
    local case_fn_address = Get_state_function(case_function)
    local chain_name = generate_unique_function_name()
    local column_array = generate_column_array(list_of_columns)
    if user_data == 'NULL' then
        user_data = 'NULL'
    else
        user_data = '(void *)&'..user_data
    end
    local message = string.format("const Chain_columns_case_CFL_t %s = { %d, %s, %s };\n",chain_name,#list_of_columns,column_array,user_data)
    Store_user_code(message)
    local column_fn_name = Get_column_function("CHAIN_COLUMNS_CASE")
    store_column_element(column_fn_name, case_fn_address,'(void *)&'..chain_name)
end

