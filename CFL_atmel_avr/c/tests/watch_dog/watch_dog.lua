set_h_file("watch_dog.h")

local entry_point = "watch_dog_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')


local test_wd_header = [[

void test_wd_handler(const void *input,void *params,Event_data_CFL_t *eventdata);


]]

local test_wd_handler = [[

void test_wd_handler(const void *input,void *params,Event_data_CFL_t *eventdata){
   (void)eventdata;
    Handle_CFL_t *handle = (Handle_CFL_t *)input;
   unsigned *column_index = (unsigned *)params;
    Printf_CFL("column index %d \n",*column_index); 
    Watch_dog_struct_CFL_t *wd_struct = handle->watch_dog_struct[*column_index];
    bool terminate_flag = wd_struct->watch_dog_termination_flag;
    if(terminate_flag==0){
        Printf_CFL("column index %d has been reset \n",*column_index);
    }
    else{
        Printf_CFL("column index %d has been terminated \n",*column_index);
    }
    Printf_CFL("user_data %s \n",wd_struct->watch_dog_user_data);
}
]]

Store_user_code([[
    static const char test_message_1[] = "test_message_1";
    static const char test_message_2[] = "test_message_2";
    static const char test_message_3[] = "test_message_3";
    

]])
Store_one_shot_function("TEST_WATCH_DOG_HANDLER",'test_wd_handler',test_wd_handler,test_wd_header)


local column_list = {"engine_time_out","watch_dog_reset","watch_dog_terminate","watch_dog_pass"}
define_columns(column_list)

define_column("engine_time_out",true,nill)
  Wait_delay(30000)
  terminate_engine()
end_column()
  


define_column("watch_dog_reset",true,nil)
    Log_msg("watch_dog_reset")
    attach_watch_dog_handler(5000,false,'TEST_WATCH_DOG_HANDLER','(void *)test_message_1')
    Wait_delay(10000)
    detach_watch_dog_handler()
    Log_msg("should not see this message")
    terminate_column()

end_column()


define_column("watch_dog_terminate",true,nil)
    Log_msg("watch_dog_terminate")
    attach_watch_dog_handler(5000,true,'TEST_WATCH_DOG_HANDLER','(void *)test_message_2')
    Wait_delay(10000)
    detach_watch_dog_handler()
    Log_msg("should not see this message")
    terminate_column()
end_column()

define_column("watch_dog_pass",true,nil)
    Log_msg("watch_dog_pass")
    attach_watch_dog_handler(5000,true,'TEST_WATCH_DOG_HANDLER','(void *)test_message_3')
    Wait_delay(1000)
    detach_watch_dog_handler()
    Wait_delay(5000)
    Log_msg("watch_dog_pass passed")
    terminate_column()
end_column()


dump_build()