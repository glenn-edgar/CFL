--[[
   Definition of state machine test.inc

]]-- 
     Define_state_machines("sm_array_name",{"test_sm","test_sub_state"})

     Def_columns("test_sm_column_array",{"test_sm_manager_chain","test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain"})

     Define_event_queue("test_sm_queue",10)

     Define_event_queue("test_sm_test_state1_queue",10)

     Define_event_queue("test_sm_test_state2_queue",10)

     Define_event_queue("test_sm_test_state3_queue",10)

     Define_sm("test_sm",{"test_state1","test_state2","test_state3"},"test_sm_manager_chain","test_sm_queue","test_state1","(void *)test_data_1")

       Define_state("test_state1","test_sm_test_state1_chain","test_sm_test_state1_queue")

       Define_state("test_state2","test_sm_test_state2_chain","test_sm_test_state2_queue")

       Define_state("test_state3","test_sm_test_state3_chain","test_sm_test_state3_queue")

     End_state_machine()




     Def_columns("test_sub_state_column_array",{"test_sub_state_manager_chain","test_sub_state_test_state1_chain","test_sub_state_test_state2_chain","test_sub_state_test_state3_chain"})

     Define_event_queue("test_sub_state_queue",10)

     Define_event_queue("test_sub_state_test_state1_queue",10)

     Define_event_queue("test_sub_state_test_state2_queue",10)

     Define_event_queue("test_sub_state_test_state3_queue",10)

     Define_sm("test_sub_state",{"test_state1","test_state2","test_state3"},"test_sub_state_manager_chain","test_sub_state_queue","test_state1","(void *)test_data_2")

       Define_state("test_state1","test_sub_state_test_state1_chain","test_sub_state_test_state1_queue")

       Define_state("test_state2","test_sub_state_test_state2_chain","test_sub_state_test_state2_queue")

       Define_state("test_state3","test_sub_state_test_state3_chain","test_sub_state_test_state3_queue")

     End_state_machine()




     Start_queue_column("test_sm_manager_chain",false,"test_sm_queue")
        Log_msg('------------top level state machine manager starting')
        Store_event_filter("display_event","filtered_events",{47,48,49},"(void *)test_data_a",false)
        Transfer_all_events_to_state("test_sm")
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state1_chain",false,"test_sm_test_state1_queue")
        Log_msg('test_state1 starting')
        Enable_disable_sms('test_state_1_sm_names', {'test_sub_state'})
        Transfer_all_events_to_sm("test_sub_state")
        Log_msg('waiting 15 seconds')
        Wait_delay(15000)
        Log_msg('sub state machine test_sub_state is now disabled')
        Log_msg('changing state to test_state2')
        Change_state('test_sm','test_state2')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state2_chain",false,"test_sm_test_state2_queue")
        Log_msg('test_state2 starting')
        Wait_delay(1000)
        Log_msg('changing state to test_state3')
        Change_state('test_sm','test_state3')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state3_chain",false,"test_sm_test_state3_queue")
        Log_msg('test_state3 starting')
        Wait_delay(1000)
        Log_msg('changing state to test_state1')
        Change_state('test_sm','test_state1')
        Halt_column()
     End_column()




     Start_queue_column("test_sub_state_manager_chain",false,"test_sub_state_queue")
        Log_msg('------------- sub state machine manager starting')
        Store_event_filter(quote_string('display_event'),'sm_manager_array_1a',{47,48,49},'(void *)test_data_ba',false)
        Transfer_all_events_to_state("test_sub_state")
        Halt_column()
     End_column()




     Start_queue_column("test_sub_state_test_state1_chain",false,"test_sub_state_test_state1_queue")
        Log_msg('--- sub state --- test_state1 starting')
        Store_event_filter(quote_string('display_event'),'sm_manager_array_1',{47,48,49},'(void *)test_data_b',true)
        Wait_delay(2000)
        Log_msg('--- sub state ---- changing state to test_state2')
        Change_state('test_sub_state','test_state2')
        Halt_column()
     End_column()




     Start_queue_column("test_sub_state_test_state2_chain",false,"test_sub_state_test_state2_queue")
        Log_msg('--- sub state ---test_state2 starting')
        Store_event_filter(quote_string('display_event'),'sm_manager_array_2',{47,48,49},'(void *)test_data_c',true)
        Wait_delay(2000)
        Log_msg('--- sub state -----------------changing state to test_state3')
        Change_state('test_sub_state','test_state3')
        Halt_column()
     End_column()




     Start_queue_column("test_sub_state_test_state3_chain",false,"test_sub_state_test_state3_queue")
        Log_msg('---- sub state ----test_state3 starting')
        Store_event_filter(quote_string('display_event'),'sm_manager_array_3',{47,48,49},'(void *)test_data_d',true)
        Wait_delay(2000)
        Log_msg('---- sub state ------------------ changing state to test_state1')
        Change_state('test_sub_state','test_state1')
        Halt_column()
     End_column()




