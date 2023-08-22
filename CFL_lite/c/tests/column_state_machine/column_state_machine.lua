set_h_file("column_state_machine.h")

local entry_point = "column_state_machine_handle"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,'debug_write')


local column_list = {"test_start","test_middle","test_end"}
define_columns(column_list)

define_column("test_start",true,nil)
  Log_msg("test_start")
  Log_msg("step 0")
  Log_msg("step 1")
  Log_msg("step 2")
  Log_msg("step 3")
  Change_column_state(0) -- step 4
  Log_msg("test_start")
  Set_column_state_machine_start()
  Log_msg("step 6")
  Log_msg("step 7")
  Log_msg("step 8")
  Log_msg("step 9")
  Log_msg("step 10")
  Set_column_state_machine_end()
end_column()

define_column("test_end",true,nil)
  Log_msg("test_end")
  Log_msg("step 0")
  Log_msg("step 1")
  Log_msg("step 2")
  Log_msg("step 3")
  Change_column_state(5) -- step 4
  Log_msg("step 5")
  Set_column_state_machine_start()
  Log_msg("step 6")
  Log_msg("step 7")
  Log_msg("step 8")
  Log_msg("step 9")
  Log_msg("test_end")
  Set_column_state_machine_end()
end_column()

define_column("test_middle",true,nil)
  Log_msg("test_middle")
  Log_msg("step 0")
  Log_msg("step 1")
  Log_msg("step 2")
  Log_msg("step 3")
  Change_column_state(3) -- step 4
  Log_msg("step 5")
  Set_column_state_machine_start()
  Log_msg("step 6")
  Log_msg("step 7")
  Log_msg("test_middle")
  Log_msg("step 9")
  Log_msg("step 10")
  Set_column_state_machine_end()
end_column()

define_column("test_sm_structure",true,nil)
 Log_msg("test_sm_structure")
 Log_msg("setup step 0")
 Log_msg("setup step 1")
 Log_msg("setup step 2")
 Wait_delay(3000)
 --- these are event filters
 store_column_element('filter_event_1','NULL',"(void *)&filter_event_data_1")
 store_column_element('filter_event_1','NULL',"(void *)&filter_event_data_2")
 store_column_element('filter_event_1','NULL',"(void *)&filter_event_data_3") 
 Change_column_state(3)
 store_column_element('sm_1','NULL',"(void *)&sm_1_data_1")
 store_column_element('sm_1','NULL',"(void *)&sm_1_data_2")
 store_column_element('sm_1','NULL',"(void *)&sm_1_data_3")
 store_column_element('sm_1','NULL',"(void *)&sm_1_data_4")
 store_column_element('sm_1','NULL',"(void *)&sm_1_data_5")
 Set

end_column()


dump_build()

