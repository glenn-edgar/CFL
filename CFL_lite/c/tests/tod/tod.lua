set_h_file("tod.h")

local entry_point = "tod_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  

Store_user_code([[

static const char failure_verify_50[] = "failure for verify 50";
static const char failure_verify_49[] = "failure for verify 49";
static const char failure_verify_28[] = "failure for verify 28";

]])

local tod_verify_reset_fn_header = [[

void tod_verify_reset(const void *input,void *params,Event_data_CFL_t *eventdata);


]]

local tod_verify_reset_fn_code = [[

void tod_verify_reset(const void *input,void *params,Event_data_CFL_t *eventdata){
   (void)input;
   (void)eventdata;
   Wait_tod_ROM_CFL_t *wait_tod = (Wait_tod_ROM_CFL_t *)params;

   Printf_CFL(input,"terminate flag %d \n",(int)(wait_tod->terminate_flag));
   Printf_CFL(input," %s \n",(const char *)wait_tod->user_data);
}
]]

Store_one_shot_function("TOD_VERIFY_RESET",'tod_verify_reset',tod_verify_reset_fn_code,tod_verify_reset_fn_header)


local lt_10 = generate_tod_dictionary()
add_second(lt_10,10)

local le_15 = generate_tod_dictionary()
add_second(le_15,15)

local eq_17 = generate_tod_dictionary()
add_second(eq_17,17)

local ge_20 = generate_tod_dictionary()
add_second(ge_20,20)

local gt_50 = generate_tod_dictionary()
add_second(gt_50,50)



local column_list = {"test_wait_tod_second","test_verify_tod_second"}
define_columns(column_list)



define_column("test_wait_tod_second",true,0)
   Log_msg("wait less than 10 seconds")
   Wait_tod_lt(lt_10)
   Log_msg("wait passed less than 10 seconds")
  
   Log_msg("wait less than equal 15 seconds")
   Wait_tod_le(le_15)
   
   Log_msg("wait equal 17 seconds")
   Wait_tod_eq(eq_17)
  
   Log_msg("wait greater than equal 20 seconds")
   Wait_tod_ge(ge_20)
   Log_msg("wait greater than 50 seconds")
   
   Wait_tod_gt(gt_50)
   Log_msg("Reseting column") 
   
   reset_column()
end_column()

local lt_1 = generate_tod_dictionary()
add_second(lt_1,1)

local ge_17 = generate_tod_dictionary()
add_second(ge_17,17)

local ge_28 = generate_tod_dictionary()
add_second(ge_28,28)


local lt_50 = generate_tod_dictionary()
add_second(lt_50,50)

local le_49 = generate_tod_dictionary()
add_second(le_49,49)


define_column("test_verify_tod_second",true,0)
   Log_msg("verify tod column start")
 
   
  
   Wait_tod_lt(lt_1)
   Log_msg("made it pass 0")
   Wait_tod_ge(ge_17)
   Log_msg("made it past 17 seconds")
  
   Verify_tod_lt(false,"TOD_VERIFY_RESET",'failure_verify_50',lt_50)
   Verify_tod_le(false,"TOD_VERIFY_RESET",'failure_verify_49',le_49)

   -- this verification fails with a reset
   Verify_tod_ge(true,"TOD_VERIFY_RESET",'failure_verify_28',ge_28)
  halt_column()
   
end_column()



 dump_build()
   




  

