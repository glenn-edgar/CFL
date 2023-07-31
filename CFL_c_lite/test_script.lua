
set_output("test_script.h")

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(allocate_once_heap_size,private_heap_size,default_event_queue_size)  

local column_list = {"column1","column2","column3"}
define_columns(column_list)
define_named_queue("queue1",10) 
define_named_queue("queue2",10)
define_named_queue("queue3",10)


local test_one_shot_header_code = [[

   void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data);
]]

local test_one_shot_code = [[

void test_one_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;

 
  char *message;
  
  unsigned column_index;
  int column_element_number;
  message = (char *)params;
  Printf_CFL("Init event  %s\n",message);  
 
  
}

]]

local test_one_bid_header_code = [[

void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data);

]]

local test_one_bid_shot_code = [[

void test_one_bid_shot(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
 
  
   char *message;
   
   unsigned column_index;
   int column_element_number;
   message = (char *)params;
   if(event_data->event_index == EVENT_INIT_CFL)
   {
     Printf_CFL("Init event  %s\n",message);  
     
   }
    if(event_data->event_index == EVENT_TERMINATION_CFL)
    {
       Printf_CFL("Termination event %s\n",message);
    }
 
   
 }

]]

local user_code = [[

static char *test_one_shot_message = "test_one_shot";
static char *test_bid_one_shot_message = "test_one_bid_shot";

]]

Store_user_code(user_code)


Store_one_shot_function("TEST_ONE_SHOT",'test_one_shot',test_one_shot_code,test_one_shot_header_code)  
Store_one_shot_function("TEST_BID_ONE_SHOT",'test_bid_one_shot',test_one_bid_shot_code,test_one_bid_header_code)  




define_column("column1",true,"queue1")
  Log_msg("this is a test message")
  One_shot("TEST_ONE_SHOT", 'test_one_shot_message')
  One_shot_terminate("TEST_BID_ONE_SHOT",'test_bid_one_shot_message')
  reset_column()
end_column()

define_column("column2",true,"queue2")
   halt_column()       
end_column()

define_column("column3",true,"queue3")
   terminate_column()
end_column()

define_columns({"column4"})
define_column("column4",true,nil)
   terminate_engine()
end_column()

dump_output()

