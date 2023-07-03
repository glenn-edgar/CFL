--[[
   Definition of state machine

]]-- 
     Def_columns("test_sm_column_array",{"test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain","test_sm_manager_chain"})

     Define_event_queue("test_sm_test_state1_queue",10)

     Define_event_queue("test_sm_test_state2_queue",10)

     Define_event_queue("test_sm_test_state3_queue",10)

     Define_event_queue("test_sm_queue",10)

     Define_state_machines("test_sm_array",{"test_sm"})

     Define_sm("test_sm",{"test_state1","test_state2","test_state3"},"test_sm_manager_chain","test_sm_queue","test_state1","(void *)test_data")

       Define_state("test_sm_test_state1","test_sm_test_state1_chain")

       Define_state("test_sm_test_state2","test_sm_test_state2_chain")

       Define_state("test_sm_test_state3","test_sm_test_state3_chain")

     End_state_machine()




     Start_queue_column("test_sm_manager_chain",false,"test_sm_queue")
        Log_msg('test_state1 starting')
        Wait_delay(1000)
        Log_msg('test_state2 terminating')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state1",false,"test_sm_test_state1_queue")
        Log_msg('test_state1 starting')
        Wait_delay(1000)
        Log_msg('test_state2 terminating')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state2",false,"test_sm_test_state2_queue")
        Log_msg('test_state1 starting')
        Wait_delay(1000)
        Log_msg('test_state2 terminating')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state3",false,"test_sm_test_state3_queue")
        Log_msg('test_state1 starting')
        Wait_delay(1000)
        Log_msg('test_state2 terminating')
        Halt_column()
     End_column()




