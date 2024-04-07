set_h_file("column_element_state_machine.h")

local entry_point = "column_element_state_machine_handle"


local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write') 


local column_list = {"sequence","test_1","test_2"}
define_columns(column_list)
local sequence_list = {"test_1","test_2"}


define_column("sequence",true,nil)
    Sequence_columns( sequence_list )
end_column()

define_column("test_1",false,{"test_sm_1","test_sm_2"})
    Log_msg('made it here start of column  1a')
    MCESM_enable_sm( "test_sm_1")
    Log_msg('made it here start of column  1b')
    MCESM_start_sm( "test_sm_1",{"state_0","state_1","state_2","state_3"})
        Log_msg('made it here start of column  1c')
        Change_sm_state("state_2")
        MCESM_new_state( "state_0")
            MCESM_log("entered state_0","left state_0")
            Wait_delay(2000)
            Log_msg('made it here state_0 after wait')
            Change_sm_state("state_1")
        MCESM_new_state( "state_1")
            MCESM_log("entered state_1","left state_1")
            Wait_delay(2000)
            Log_msg('made it here state_1 after wait')
            MCESM_disable_current_sm()
        MCESM_new_state( "state_2")
            MCESM_log("entered state_2","left state_2")
            Wait_delay(2000)
            Log_msg('made it here  state_2 after wait')
            Change_sm_state("state_3")
            
        MCESM_new_state( "state_3")
            MCESM_log("entered state_3","left state_3")
            Wait_delay(2000)
            Log_msg('made it here state_3 after wait')
            Change_sm_state("state_0")

    MCESM_end_sm( "test_sm_1")


    Log_msg('made it here start of column  1a')
    MCESM_enable_sm( "test_sm_2")
    Log_msg('made it here start of column  1b')
    MCESM_start_sm( "test_sm_2",{"state_0","state_1","state_2","state_3"})
        Log_msg('made it here start of column  1c')
        Change_sm_state("state_2")
        MCESM_new_state( "state_0")
            MCESM_log("entered state_0","left state_0")
            Wait_delay(2000)
            Log_msg('made it here state_0 after wait')
            Change_sm_state("state_1")
        MCESM_new_state( "state_1")
            MCESM_log("entered state_1","left state_1")
            Wait_delay(2000)
            Log_msg('made it here state_1 after wait')
            terminate_column()
        MCESM_new_state( "state_2")
            MCESM_log("entered state_2","left state_2")
            Wait_delay(2000)
            Log_msg('made it here  state_2 after wait')
            Change_sm_state("state_3")
            
        MCESM_new_state( "state_3")
            MCESM_log("entered state_3","left state_3")
            Wait_delay(2000)
            Log_msg('made it here state_3 after wait')
            Change_sm_state("state_0")

    MCESM_end_sm( "test_sm_2")
    Log_msg('made it here end of column')
   
    
end_column()


define_column("test_2",false,{"test_sm_1"})
    MCESM_enable_sm( "test_sm_1")
    MCESM_start_sm( "test_sm_1",{"state_0","state_1","state_2","state_3"})
        Change_sm_state("state_2")
    MCESM_new_state( "state_0")
        MCESM_log("entered state_0","left state_0")
        Wait_delay(2000)
        Log_msg('made it here state_0 after wait')
        Change_sm_state("state_1")
    MCESM_new_state( "state_1")
        MCESM_log("entered state_1","left state_1")
        Wait_delay(2000)
        Log_msg('made it here state_1 after wait')
        terminate_column()
    MCESM_new_state( "state_2")
        MCESM_log("entered state_2","left state_2")
        Wait_delay(2000)
        Log_msg('made it here  state_2 after wait')
        Change_sm_state("state_3")
        
    MCESM_new_state( "state_3")
     MCESM_log("entered state_3","left state_3")
        Wait_delay(2000)
        Log_msg('made it here state_3 after wait')
        Change_sm_state("state_0")
    MCESM_end_sm( "test_sm_1")
    
   
    
end_column()
dump_build()