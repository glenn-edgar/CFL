set_h_file("return_codes.h")

local entry_point = "return_codes_entry_point"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  



  

local test_one_shot_header_code = [[

   void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data);
]]

local test_one_shot_code = [[

void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
  char **message;
  
 
  message = (char **)params;
  Printf_CFL(input,"Init event  %s\n",*message);  
 
  
}

]]

local test_one_bid_header_code = [[

void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data);

]]

local test_one_bid_shot_code = [[

void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
   (void)input;
  
   char **message;
   
   
   message = (char **)params;
   if(event_data->event_index == EVENT_INIT_CFL)
   {
     Printf_CFL(input,"Init event  %s\n",*message);  
     
   }
    if(event_data->event_index == EVENT_TERMINATION_CFL)
    {
       Printf_CFL(input,"Termination event %s\n",*message);
    }
 
   
 }

]]

Store_user_code([[
static const char *test_one_shot_message = "test_one_shot";
static const char *test_bid_one_shot_message = "test_one_bid_shot";
static const char user_test_event_data[] = "test message";
]])

Store_one_shot_function("TEST_ONE_SHOT",'test_one_shot',test_one_shot_code,test_one_shot_header_code)  

Store_one_shot_function("TEST_BID_ONE_SHOT",'test_one_bid_shot',test_one_bid_shot_code,test_one_bid_header_code)  

set_user_event_start(100)
test_event_id = add_user_event("test_event")

test_def = generate_event(get_event("test_event"),false, '( void *)user_test_event_data')

define_columns({"column1"},10)
define_columns({"column2"},5)
define_columns({"column3"})  
define_columns({"column4","column5"},6)

define_column("column1",true)
  Log_msg("this is a test message")
  Log_msg("entry message", "exit message")
  One_shot("TEST_ONE_SHOT", 'test_one_shot_message')
  One_shot_terminate("TEST_BID_ONE_SHOT",'test_bid_one_shot_message')
  send_global_event(test_def)
  send_global_event(test_def)
  Wait_delay(2000)
  Log_msg("reseting the column every 2 seconds")
  reset_column()
end_column()

define_column("column2",true)
Log_msg('test_halt_column')
   Log_msg("halting the column")
   halt_column() 
   reset_column()
end_column()

define_column("column3",true)
Log_msg( 'test_terminate_column')
Wait_delay(7500)
Log_msg( 'column 3 is terminating after 7.5 seconds')
terminate_column()
reset_column()
end_column()



define_column("column4",true)
Log_msg( 'test_terminate_engine')
Wait_delay(10000)
Log_msg( 'column 4 is terminating engine after 10 seconds')
terminate_engine()
reset_column()
end_column()

define_column("column5",true)
Log_msg( 'test counting 9 events')

Wait_event(test_event_id,9, 0, true, 'NULL', 'NULL')

Log_msg( 'column 5 is terminating engine after 9 events')
terminate_column()
end_column()



dump_build()


