local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../../lua_compiler/"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)

local wait_event_reset_fn_header = [[

void wait_event_reset(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local wait_event_reset_fn_code = [[

void wait_event_reset(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   char *message = (char *)params;
   
  
  Printf_CFL("\n\n *************** Reset function ---   %s\n\n",message);  
 
  
}
]]

Store_one_shot_function("WAIT_EVENT_RESET",'wait_event_reset',wait_event_reset_fn_code,wait_event_reset_fn_header)


local wait_event_terminate_fn_header = [[

void wait_event_terminate(const void *input, void *params,Event_data_CFL_t *event_data);


]]

local wait_event_terminate_fn_code = [[

void wait_event_terminate(const void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)input;
 
   
   char *message = (char *)params;
  
  Printf_CFL("\n\n *************** Terminate function ---   %s\n\n",message);  
 
  
}
]]



Store_one_shot_function("WAIT_EVENT_TERMINATE",'wait_event_terminate',wait_event_terminate_fn_code,wait_event_terminate_fn_header)

-- start of user events
set_user_event_start(100)
-- returns the event id
local test_event_id = add_user_event("test_event","test_event")
local test_event_number = get_event_number("test_event")
-- returns const event address
local test_def = generate_event("user_test_event",get_event("test_event"),false, 'NULL')


local test_bool_fn_header = [[
bool test_bool_fn(const void *input, void *params,Event_data_CFL_t *event_data);
]]
reset_template_tables()
variable_table['test_event_id'] = test_event_number


local test_bool_fn_code = Expand_text_stream([[

#define EVENT_TEST_EVENT <<p, test_event_id>>

bool test_bool_fn(const void *input, void *params,Event_data_CFL_t *event_data)
{
    (void)input;
    unsigned *count = (unsigned *)params;
    if(event_data->event_index == EVENT_INIT_CFL)
    {
        *count = 0;
        Printf_CFL("\n\ninit event received from user function\n\n");
    }
    if(event_data->event_index == EVENT_TEST_EVENT)
    {
       *count = *count + 1;
        if(*count == 5)
        {
            Printf_CFL("\n\n 5 events received returning true \n\n");
            return true;
        }
    }
    return false;
}
      

]])

Store_boolean_function("TEST_BOOL_FN",'test_bool_fn',test_bool_fn_code,test_bool_fn_header)

local user_code = [[

static unsigned test_counter = 0;

void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}
char *allocate_once_memory = NULL;

void create_allocate_once_heap(){
    allocate_once_memory = (char *)malloc(2000);
}

void free_allocate_once_heap(){
    free(allocate_once_memory);
}

static const char wait_event_reset_message[] = "wait event reset function called\n";
static const char wait_event_terminate_message[] = "wait event terminate function called\n";
]]



Store_user_code(user_code)


set_output("test_script.h")

local entry_point = "test_entry_point"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size)  






local column_list = {"termination_engine","generate_event","user_function","wait_terminate","wait_reset"}
define_columns(column_list)

define_column("termination_engine",true,nil)
   Log_msg("this column will terminate the engine")
   Wait_delay(16000)
   Log_msg("stopping engine because 16 seconds have passed")
   terminate_engine()
end_column()


define_column("generate_event",true,nil)
   Log_msg("this column will generate an event every second")
   Wait_delay(1000)
   send_global_event(test_def)
   Log_msg("sending event")
   reset_column()
end_column()


define_column("user_function",true,nil)
   Log_msg("user function column is starting")
   Wait("TEST_BOOL_FN",0, false,'NULL','test_counter')
   Log_msg("user function has passed")
   Log_msg("terminating column")
   terminate_column()
end_column()

define_column("wait_reset",true,nil)
   Log_msg("this demonstrates the reset feature of the wait opcode")
   Wait("FALSE",5000, false, "WAIT_EVENT_RESET", 'wait_event_reset_message')
   Log_msg("10 events have been received")
   Log_msg("terminating column")
   terminate_column()
end_column()

define_column("wait_terminate",true,nil)
   Log_msg("this demonstrates the terminate feature of the wait opcode")
   Wait("FALSE",5000, true, "WAIT_EVENT_TERMINATE", 'wait_event_terminate_message')
   Log_msg("This step should not happpen as the wait opcode will reset because of timeout")
   reset_column()
end_column()

dump_output('debug_write')
   
