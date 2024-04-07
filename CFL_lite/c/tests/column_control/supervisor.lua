set_h_file("supervisor.h")

local entry_point = "supervisor_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  


local one_for_one_header = [[
 
bool one_for_one_fn(const void* input, void* params, Event_data_CFL_t* event_data);

]]
--[[
typedef struct Supervisor_data_CFL_t
{
  unsigned short reset_type;
  unsigned short column_number;
  const unsigned short* column_list;
  bool *restart_mask;
  unsigned *reset_count;
  unsigned *secondary_reset_count;
  bool terminate_flag;
  const void* user_data;

} Supervisor_data_CFL_t;
]]

local one_for_one_code = [[

static void one_for_one_output(const void *input, const Supervisor_data_CFL_t* data, unsigned max_count) {
    Printf_CFL(input,"column reset state \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset state %d \n",data->column_list[i],data->restart_mask[i]);
    }
    Printf_CFL(input,"column reset counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset count %d \n",data->column_list[i],data->reset_count[i]);
    }
    Printf_CFL(input,"reset all counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d secondary  reset count %d \n",data->column_list[i],data->secondary_reset_count[i]);
    }

    
    Printf_CFL(input,"max reset count %d \n",max_count);
    Printf_CFL(input,"terminate flag %d \n",data->terminate_flag);
    Printf_CFL(input,"Column is ending \n");
}
bool one_for_one_fn(const void* input, void* params, Event_data_CFL_t* event_data){
    
    const Supervisor_data_CFL_t *data = (const Supervisor_data_CFL_t*)params;

    if (event_data->event_index == EVENT_INIT_CFL ) {
        Printf_CFL(input,"one for one supervisor init \n");
        return true;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL) {
        Printf_CFL(input,"one for one supervisor terminate \n");
        return true;
    }
    if (event_data->event_index == SUPERVISOR_EVENT_CFL) {
        Printf_CFL(input,"Supervisor event received \n");
        return true;
    }
    // at this point only timer tick events are sent here
    unsigned max_count = 0;
   

    for (int i = 0; i < data->column_number; i++) {
   
        if (data->reset_count[i] > max_count) {
            max_count = data->reset_count[i];   
        }
    }
    
    if (max_count > 15) {
        one_for_one_output(input,data,max_count);
        return false;
    }
    return true;


}
   

]]


Store_boolean_function('ONE_FOR_ONE_FN','one_for_one_fn',one_for_one_code,one_for_one_header)

local fn_control_header = [[
 
bool fn_column_control(const void* input, void* params, Event_data_CFL_t* event_data);

]]

local fn_control_code = [[

static void fn_output(const void *input, const Supervisor_data_CFL_t* data, unsigned max_count) {
    Printf_CFL(input,"column reset state \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset state %d \n",data->column_list[i],data->restart_mask[i]);
    }
    Printf_CFL(input,"column reset counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d reset count %d \n",data->column_list[i],data->reset_count[i]);
    }
    Printf_CFL(input,"reset all counts \n");
    for (int i = 0; i < data->column_number; i++) {
        Printf_CFL(input,"column %d secondary  reset count %d \n",data->column_list[i],data->secondary_reset_count[i]);
    }

    
    Printf_CFL(input,"max reset count %d \n",max_count);
    Printf_CFL(input,"terminate flag %d \n",data->terminate_flag);
    Printf_CFL(input,"Column is ending \n");
}
bool fn_column_control(const void* input, void* params, Event_data_CFL_t* event_data){
    
    const Supervisor_data_CFL_t *data = (const Supervisor_data_CFL_t*)params;

    if (event_data->event_index == EVENT_INIT_CFL ) {
        Printf_CFL(input,"one for one supervisor init \n");
        return true;
    }
    if (event_data->event_index == EVENT_TERMINATION_CFL) {
      
        Printf_CFL(input,"one for one supervisor terminate \n");
        return true;
    }
    if (event_data->event_index == SUPERVISOR_EVENT_CFL) {
        char* message = (char*)event_data->params;
        Printf_CFL(input,"Supervisor event received %s \n",message);
        return true;
    }
    // at this point only timer tick events are sent here
    unsigned max_count = 0;
   
    bool reset_flag = false;
    for (int i = 0; i < data->column_number; i++) {
        if (data->restart_mask[i] == true) {
            reset_flag = true;
        }
        if (data->reset_count[i] > max_count) {
            max_count = data->reset_count[i];   
        }
    }
    // implement an all fo one reset
    if (reset_flag == true) {
        for (int i = 0; i < data->column_number; i++) {
          if (data->restart_mask[i] == false) {
            data->restart_mask[i] = true;
            data->secondary_reset_count[i] += 1;
          }
        }
    }
    if (max_count > 15) {
       fn_output(input,data,max_count);
        return false;
    }
    return true;


}
   

]]


Store_boolean_function('FN_CONTROL_RESET','fn_column_control',fn_control_code,fn_control_header)

Store_user_code([[
static const char test_message[] = "\n\n ********************** This is test message for supervisor  *****************  \n\n\n";
]])
local SUPERVISOR_EVENT_CFL  =     0x7fff
test_event = generate_event(SUPERVISOR_EVENT_CFL ,false, '(void *)test_message')


function merge_lists(list1, list2)
    local new_list = {}
    for i = 1, #list1 do
        table.insert(new_list, list1[i])
    end
    for i = 1, #list2 do
        table.insert(new_list, list2[i])
    end
    return new_list
end



---
--- columns for one for one test
one_for_one_columns = { "control_column_1_for_1", "test_1_for_1_a", "test_1_for_2_a", "test_1_for_3_a"}
one_for_one_test_columns = { "test_1_for_1_a", "test_1_for_2_a", "test_1_for_3_a"}

all_for_one_columns = { "control_column_all_for_1", "test_2_for_1_a", "test_2_for_2_a", "test_2_for_3_a"}
all_for_one_test_columns = { "test_2_for_1_a", "test_2_for_2_a", "test_2_for_3_a"}

rest_for_one_columns = { "control_column_rest_for_1", "test_3_for_1_a", "test_3_for_2_a", "test_3_for_3_a"}
rest_for_one_test_columns = { "test_3_for_1_a", "test_3_for_2_a", "test_3_for_3_a"}

function_control_reset_columns = { "test_4_fn_1_a", "test_4_fn_2_a", "test_4_fn_3_a"}
function_control_reset_test_columns = { "test_4_fn_1_a", "test_4_fn_2_a", "test_4_fn_3_a"}

column_names = merge_lists(one_for_one_columns, all_for_one_columns)
column_names = merge_lists(column_names, rest_for_one_columns)
column_names = merge_lists(column_names, function_control_reset_columns)
define_columns(column_names)
define_columns({ "function_controlled_rest"},1)  


define_column( "control_column_1_for_1", true)
  Log_msg( "starting control_column_1_for_1")
  Enable_columns(one_for_one_test_columns)
  Supervisor_1_for_1( one_for_one_test_columns,'ONE_FOR_ONE_FN', 'NULL', true)
  halt_column()
end_column()


define_column( "test_1_for_1_a", false)
  Log_msg( "starting test_1_for_1_a")
  Wait_delay( 2000)
  Log_msg( "ending test_1_for_1_a")
  terminate_column()
end_column()


define_column( "test_1_for_2_a", false)
  Log_msg( "starting test_1_for_2_a")
  Wait_delay( 1000)
  Log_msg( "ending test_1_for_2_a")
  terminate_column()
end_column()

define_column( "test_1_for_3_a", false)
  Log_msg( "starting test_1_for_3_a")
  Wait_delay( 3000)
  Log_msg( "ending test_1_for_3_a")
  terminate_column()
end_column()


define_column( "control_column_all_for_1",true)
  Log_msg( "starting control_column_1_for_1")
  Enable_columns(all_for_one_test_columns)
  Supervisor_1_for_all( all_for_one_test_columns,'ONE_FOR_ONE_FN', 'NULL', true)
  halt_column()
end_column()


define_column( "test_2_for_1_a", false)
  Log_msg( "starting test_2_for_1_a")
  Wait_delay( 2000)
  Log_msg( "ending test_2_for_1_a")
  terminate_column()
end_column()


define_column( "test_2_for_2_a", false)
  Log_msg( "starting test_2_for_2_a")
  Wait_delay( 1000)
  Log_msg( "ending test_2_for_2_a")
  terminate_column()
end_column()

define_column( "test_2_for_3_a", false)
  Log_msg( "starting test_2_for_3_a")
  Wait_delay( 3000)
  Log_msg( "ending test_2_for_3_a")
  terminate_column()
end_column()

define_column( "control_column_rest_for_1", true)
  Log_msg( "control_column_rest_for_1")
  Enable_columns(rest_for_one_test_columns)
  Supervisor_rest_for_one( rest_for_one_test_columns,'ONE_FOR_ONE_FN', 'NULL', true)
  halt_column()
end_column()


define_column( "test_3_for_1_a", false)
  Log_msg( "starting test_3_for_1_a")
  Wait_delay( 25000)
  Log_msg( "ending test_3_for_1_a")
  terminate_column()
end_column()


define_column( "test_3_for_2_a", false)
  Log_msg( "starting test_3_for_2_a")
  Wait_delay( 1000)
  Log_msg( "ending test_3_for_2_a")
  terminate_column()
end_column()

define_column( "test_3_for_3_a", false)
  Log_msg( "starting test_3_for_3_a")
  Wait_delay( 3000)
  Log_msg( "ending test_3_for_3_a")
end_column()

define_column( "function_controlled_rest", true)
  Log_msg( "control_function_controlled_rest")
  Enable_columns(function_control_reset_test_columns)
  Supervisor_1_for_1(function_control_reset_test_columns,'FN_CONTROL_RESET', 'NULL', true)
  Wait_delay( 1000)
  send_queue_event("function_controlled_rest",test_event)
  halt_column()
end_column()


define_column( "test_4_fn_1_a", false)
  Log_msg( "starting test_4_fn_1_a")
  Wait_delay( 25000)
  Log_msg( "ending test_4_fn_1_a")
  terminate_column()
end_column()


define_column( "test_4_fn_2_a", false)
  Log_msg( "starting test_4_fn_2_a")
  Wait_delay( 1000)
  Log_msg( "ending test_4_fn_2_a")
  terminate_column()
end_column()

define_column( "test_4_fn_3_a", false)
  Log_msg( "starting test_4_fn_3_a")
  Wait_delay( 25000)
  Log_msg( "ending test_4_fn_3_a")
end_column()

dump_build()


