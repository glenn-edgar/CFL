--[[
   Definition of state machine test.inc

]]-- 
     Define_state_machines("sm_array_name",{"test_sm"})

     Def_columns("test_sm_column_array",{"test_sm_manager_chain","test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain"})

     Define_event_queue("test_sm_queue",10)

     Define_event_queue("test_sm_test_state1_queue",10)

     Define_event_queue("test_sm_test_state2_queue",10)

     Define_event_queue("test_sm_test_state3_queue",10)

     Define_sm("test_sm",{"test_state1","test_state2","test_state3"},"test_sm_manager_chain","test_sm_queue","test_state1","(void *)test_data")

       Define_state("test_state1","test_sm_test_state1_chain","test_sm_test_state1_queue")

       Define_state("test_state2","test_sm_test_state2_chain","test_sm_test_state2_queue")

       Define_state("test_state3","test_sm_test_state3_chain","test_sm_test_state3_queue")

     End_state_machine()




     Start_queue_column("test_sm_manager_chain",false,"test_sm_queue")
        Log_msg('state machine manager starting')
        Store_event_filter(quote_string('display_event'),'sm_manager_array',{47},'NULL',true)
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state1_chain",false,"test_sm_test_state1_queue")
        Log_msg('test_state1 starting')
        Wait_delay(1000)
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




