set_h_file("chain_column_case.h")

local entry_point = "chain_column_case_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 





local case_test_fn_header = [[

int case_test_fn(const void *input, void* params, Event_data_CFL_t* event_data, bool *event_continue_flag);
]]



local case_test_fn_code = [[

int case_test_fn(const void *input, void* params, Event_data_CFL_t* event_data, bool *event_continue_flag){
    (void)input;
    const char *user_data = (const char *)params;
    printf("case_test_fn received event index %d\n",event_data->event_index);
    switch(event_data->event_index){
        case 100:
            *event_continue_flag = false;
            return 0;
        case 101:
            *event_continue_flag = false;
            return 1;
        case 102:
            *event_continue_flag = false;
            printf("%s This event is processed and the event is not continued %d\n",user_data,event_data->event_index);
            return -1;
        case 103:
            *event_continue_flag = true;
            return 3;
        default:
            *event_continue_flag = false;
            return -1;
    }
    return -1;
}


]]

Store_state_function("CASE_TEST_FUNCTION","case_test_fn",case_test_fn_code,case_test_fn_header)

Store_user_code("const char user_data[] = \"This is user data test string :::    \";")

set_user_event_start(100)



-- returns the event id
column_event_1_id = add_user_event("column_event_1")
-- returns const event address
column_event_1 = generate_event(get_event("column_event_1"),false, 'NULL')

-- returns the event id
column_event_2_id = add_user_event("column_event_2")
-- returns const event address
column_event_2 = generate_event(get_event("column_event_2"),false, 'NULL')

column_event_3_id = add_user_event("column_event_3")
-- returns const event address
column_event_3 = generate_event(get_event("column_event_3"),false, 'NULL')

-- returns the event id
column_event_4_id = add_user_event("column_event_4")
-- returns const event address
column_event_4 = generate_event(get_event("column_event_4"),false, 'NULL')

local column_list = {"terminate_column", "event_generator",  "case_column_1", "case_column_2", "case_column_3" }
define_columns({"chain_case_column"},4)
define_columns(column_list,0)

define_column("terminate_column",true)
  Wait_delay(12000)
  terminate_engine()
end_column()


define_column("event_generator",true)
    Log_msg("event generator start")
    Wait_delay(2000)
    Log_msg("sending events")
    send_queue_event("chain_case_column",column_event_3)
    send_queue_event("chain_case_column",column_event_4)
    send_queue_event("chain_case_column",column_event_1)
    send_queue_event("chain_case_column",column_event_2)
    
    Log_msg("done sending events")    
    reset_column()
end_column()


define_column("chain_case_column",true)
    Log_msg("chain_case_column")
    Enable_columns( { "case_column_1", "case_column_2", "case_column_3" } ,true)
    Chain_columns_case( "CASE_TEST_FUNCTION","user_data", {"case_column_1","case_column_2","case_column_3"} )
   
    display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
    halt_column()
end_column()





define_column("case_column_1",false)
    Log_msg("case_column_1")
    display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
    Wait_delay( 5000)
    Log_msg("case_column_1 wait done")
    reset_column()
end_column()

define_column("case_column_2",false)
    Log_msg("case_column_2")
    display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
    Wait_delay( 5500)
    Log_msg("case_column_2 wait done")
    reset_column()
end_column()



define_column("case_column_3",false)
    Log_msg("case_column_3")
    display_event( {column_event_1_id,column_event_2_id,column_event_3_id,column_event_4_id})
    Wait_delay( 5700)
    Log_msg("case_column_3 wait done")
    reset_column()
end_column()

dump_build()
