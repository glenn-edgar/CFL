
local function generate_column_array(column_list)
   column_array_name = generate_unique_function_name()
   local message = string.format("const uint16_t %s[] = {",column_array_name)
    Store_user_code(message)
    for i,v in pairs(column_list) do
        local  column_number = get_column_number(v)
        if i < #column_list-1 then
            message = string.format("%s,",column_number)
        else
            message = string.format("%s};\n",column_number)
        end
        Store_user_code(message)
    end
   return column_array_name
end

local function generate_void array()
    local return_value = generate_unique_function_name(column_number)
    local message = string.format("void * %s[%d];\n",return_value,column_number)
    Store_user_code(message)
    return return_value
end

function Workflow_launch(list_of_columns)
    Enable_columns(column_list,true)
end

function Workflow_cancel(list_of_columns)
    Disable_columns(column_list) 
end


function Workflow_sync(list_of_columns)
    Join_columns(column_list)
end

function Workflow_sequence_elements(invert_flag, list_of_columns)
    Try_columns(invert_flag, list_of_columns)
end



local aggregator_header = [[

typedef struct Workflow_aggregator_CFL_t
{
  Aggregator_function_CFL_t  aggregator_fn;
  Aggregator_CFL_t           aggregator_data;
} Workflow_aggregator_CFL_t;


void Workflow_aggregator_CFL(const void *aggregator_fn, void *user_data, Event_data_CFL_t *event_data);

]]

local aggegator_code = [[
void Workflow_aggregator_CFL(const void *aggregator_fn, void *params, Event_data_CFL_t *event_data){

  (void)event_data;
  Workflow_aggregator_CFL_t *workflow_aggregator = (Workflow_aggregator_CFL_t *)params;
  for(int i = 0; i < workflow_aggregator->aggregator_data.number_of_columns; i++){
    workflow_aggregator->aggregator_data[i] = retreive_column_data_CFL(workflow_aggregator->aggregator_data.column_list[i]);
  }
  store_current_column_data_CFL(workflow_aggregator->aggregator_fn(workflow_aggregator->aggregator_data));
  

}

]]

Store_one_shot_function("WORKFLOW_AGGREGATOR",'Workflow_aggregator_CFL', aggregator_header,aggegator_code)




function Workflow_aggregator(aggregator_fn, user_data, list_of_columns)
   -- generate list of columns
   column_array_name = generate_column_array(list_of_columns)
   void_name = generate_void array()
   Aggregator_name = generate_unique_function_name()
   local message = string.format("const Aggregator_CFL_t %s = { %s, %d, %s, %s};\n",Aggregator_name,user_data,#list_of_columns,column_array_name,void_name)
    Store_user_code(message)
    One_shot("WORKFLOW_AGGREGATOR",Aggregator_name)
   
end


local work_flow_initializer_header = [[

typedef struct Work_flow_initializer_CFL_t
{
  const uint16_t number_of_columns;
  const uint16_t *column_list;
  void **column_data;
} Work_flow_initializer_CFL_t;


void Work_flow_initializer_CFL(const void *input,void *params,Event_data_CFL_t *event_data);

]]

local work_flow_initializer_code = [[

void Work_flow_initializer_CFL(const void *input,void *params,Event_data_CFL_t *event_data){
  (void)event_data;
  Work_flow_initializer_CFL_t *work_flow_initializer = (Work_flow_initializer_CFL_t *)params;
  for(int i = 0; i < work_flow_initializer->number_of_columns; i++){
    uint16_t column_number = work_flow_initializer->column_list[i];
    void *column_data = work_flow_initializer->column_data[i];
    store_column_data_CFL(column_number,column_data);
  }
}

]]

Store_one_shot_function("WORK_FLOW_INITIALIZER",'Work_flow_initializer_CFL', work_flow_initializer_header,work_flow_initializer_code)

function Work_flow_initializer(list_of_columns, array_of_data )
    assert(#list_of_columns == #array_of_data,"Number of columns and data do not match")
    data_structure = generate_unique_function_name()
    column_array_name = generate_column_array(list_of_columns)
    void_name = generate_void array()
    local message = string.format("const Work_flow_initializer_CFL_t %s = { %d, %s, %s};\n",data_structure,#list_of_columns,column_array_name,void_name
    Store_user_code(message)
    One_shot("WORK_FLOW_INITIALIZER",data_structure)    
end



function workflow_event_flow( event_fn, user_data, list_of_columns)
    Chain_columns_case( event_fn, user_data,list_of_columns )
end