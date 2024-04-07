set_h_file("column_data.h")

local entry_point = "column_data_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  


local column_data_1 = 'char column_test_data_1[] ="this is the column data 1 test";'
Store_user_code(column_data_1)


local column_data_2 = 'char column_test_data_2[] ="this is the column data 2 test";'
Store_user_code(column_data_2)

Store_user_code([[
  static void get_current_column_data(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    unsigned short column_index = get_current_column_index_CFL(input); 
    Printf_CFL(input,"column index %d \n",column_index);
    char *column_data = (char *)retrieve_current_column_data_CFL(input);
    
    Printf_CFL(input,"user data for column_data_test %s \n",column_data);


  }



]])

Store_user_code([[
  static void get_column_data(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    unsigned short column_index = get_current_column_index_CFL(input); 
    Printf_CFL(input,"column index %d \n",column_index);
    char *column_data = (char *)retreive_column_data_CFL(input,column_index);
    
    Printf_CFL(input,"user data for column_data_test %s \n",column_data);


  }



]])


local column_list = {"store","receive_1","receive_2"}
define_columns(column_list)

define_column("store",true)
  Log_msg('starting store')

  Store_column_data({"receive_1",},'column_test_data_1')
  Store_column_data({'receive_2'},'column_test_data_2')
  Log_msg('ending store column data')
  terminate_column()
end_column()


define_column("receive_1",true)
  Log_msg('receive_1')
  Wait_delay(1000)
  One_shot_raw('get_current_column_data','NULL')
  Log_msg('ending receive_1')
  terminate_column()
end_column()

define_column("receive_2",true)
  Log_msg('starting column_receive_2')
  Wait_delay(1000)
  One_shot_raw('get_column_data','NULL')
  Log_msg('ending receive_2')
  terminate_column()
end_column()


dump_build()

--[[
Store_one_shot(one_shot_name,one_shot_fn)

Start_column(column_name,true)
  Log_msg(q('starting column_event_test'))
  Store_local_column_data('(void*) '..column_address)
  
  One_shot(one_shot_name,'NULL')
  Log_msg(q('ending column_event_test'))
  Term_column()
End_column()

Start_engine( 100, 30, 'default_idle_function', 'default_calendar_function');
Destroy_engine(input, 'Engine Done\\n');


---
--- start of column_event_test_b
---
local one_shot_name = q('column_data_handler_b')
local one_shot_fn = 'column_data_fn_b'
local column_names = {q('column_send'),q('column_receive_1'),q('column_receive_2')}


local send_columns = {q('column_receive_1'),q('column_receive_2')}  

column_name_1 = "column_data_test_1"
column_name_2 = "column_data_test_2"

column_data_1 = q('this is the column data test 1')
column_data_2 = q('this is the column data test 2')

local send_data = {'(void *)'..column_data_1, '(void *)'..column_data_2}

reset_template_tables()
variable_table['fn'] = one_shot_fn
variable_table['data_name_1'] = column_name_1
variable_table['data_1'] = column_data_1
variable_table['data_name_2'] = column_name_2
variable_table['data_2'] = column_data_2

pass_c([[
  
  static void <<p fn>>(void *input,void *param,Event_data_CFL_t *event_data){
    (void) param;
    (void) event_data;
    char *column_data = (char *)Get_current_column_local_data_CFL(input);
    Printf_CFL("user data for column_data_test %s \n",column_data);


  }
]]





