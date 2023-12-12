local current_working_directory = PXT.getwd()

-- Add a new directory to the path
local newDirectory = "../../../lua_compiler/"
PXT.cwd(newDirectory)
dofile("compiler.lua")
PXT.cwd(current_working_directory)


local entry_point = "test_entry_point"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size)

set_user_event_start(100)
local test_event_id = add_user_event("test_event","test_event")
local test_event_number = get_event_number("test_event")

 -- returns const event address
local test_def = generate_event("user_test_event",get_event("test_event"),false, 'NULL')
reset_template_tables()
variable_table['test_event_index'] = test_event_number
variable_table['test_event_count'] = 5
variable_table['term_message'] = "  verify is terminating the column "
variable_table['reset_message'] = " verify is resetting the column  "




local user_code = [[


void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}

static unsigned test_counter_1 = 0;
static unsigned test_counter_2 = 0;

char *allocate_once_memory = NULL;

void create_allocate_once_heap(){
    allocate_once_memory = (char *)malloc(2000);
}

void free_allocate_once_heap(){
    free(allocate_once_memory);
}

]]


Store_user_code(user_code)

local event_test_header = [[

bool test_bool_fn(const void *input, void *params,Event_data_CFL_t *event_data);

]]

local event_test_code = Expand_text_stream([[
#define EVENT_TEST_EVENT <<p, test_event_index>>
#define EVENT_TEST_EVENT_COUNT <<p, test_event_count, 5>>
  
bool test_bool_fn(const void *input, void *params,Event_data_CFL_t *event_data){
   (void)input;
   
   unsigned *count = (unsigned *)params;
   
   if(event_data->event_index == EVENT_INIT_CFL){
     
      *count = 0;
      Printf_CFL("\n\ninit event received\n\n");
   }
   if(event_data->event_index == EVENT_TEST_EVENT){
      *count = *count + 1;
      //printf("event count = %d\n",count);
      if(*count >= EVENT_TEST_EVENT_COUNT){
         Printf_CFL("\n\n 5 events received returning false \n\n");
         return false;  // verify will fail at this point
      }
   }
   return true; // verify will pass at this point
}

]])


Store_boolean_function("TEST_BOOL_FN",'test_bool_fn',event_test_code,event_test_header)


local verify_one_shot_reset_header = [[

void verify_one_shot_reset(const void *input, void *params,Event_data_CFL_t *event_data);

]]

local verify_one_shot_reset_code = Expand_text_stream([[
 
void verify_one_shot_reset(const void *input, void *params,Event_data_CFL_t *event_data){
      (void)input;
      (void)params;
      (void)event_data;
      static char reset_message[] = "<<p, reset_message>>";
      Printf_CFL("\n\n verify one shot reset function called %s \n\n",reset_message);


}
]])


Store_one_shot_function("VERIFY_ONE_SHOT_RESET",'verify_one_shot_reset',verify_one_shot_reset_code,verify_one_shot_reset_header)

local verify_one_shot_terminate_header = [[

void verify_one_shot_terminate(const void *input, void *params,Event_data_CFL_t *event_data);

]]

local verify_one_shot_terminate_code = Expand_text_stream([[
 
void verify_one_shot_terminate(const void *input, void *params,Event_data_CFL_t *event_data){
      (void)input;
      (void)params;
      (void)event_data;
      static char terminate_message[] = "<<p, term_message>>";
      Printf_CFL("verify one shot reset function called %s\n\n",terminate_message);


}
]])

Store_one_shot_function("VERIFY_ONE_SHOT_TERMINATE",'verify_one_shot_terminate',verify_one_shot_terminate_code,verify_one_shot_terminate_header)








set_output("test_script.h")



local column_list = {"terminate_engine","event_generator","verify_reset","verify_terminate"}
define_columns(column_list)

define_column("terminate_engine",true)
   Log_msg("terminate engine column start")
   Wait_delay(20000)
   Log_msg("stop engine")
   terminate_engine()
end_column()


define_column("event_generator",true)
   Wait_delay(1000)
   Log_msg("event has been sent")
   send_global_event(test_def)
   reset_column()
end_column()

define_column("verify_reset",true)
   Log_msg("verify reset column")
   Log_msg("this column will reset")
   Verify("TEST_BOOL_FN",  false, 'VERIFY_ONE_SHOT_RESET', "(void *)&test_counter_1")
   Wait("FALSE",0, true,'NULL', 'NULL') -- will wait forever
   Log_msg("This should not happen")
   terminate_column()
end_column()

define_column("verify_terminate",true)
   Log_msg("verify terminate column")
   Log_msg("this column will terminate")
   Verify("TEST_BOOL_FN",  true, 'VERIFY_ONE_SHOT_TERMINATE',"(void *)&test_counter_2")
 
   Wait("FALSE",0, true,'NULL', 'NULL') -- will wait forever
   Log_msg("This should not happen")
   terminate_column()
end_column()




dump_output('debug_write')
   


  

