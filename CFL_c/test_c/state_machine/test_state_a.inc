--[[
   Definition of state machine test.inc

]]-- 
     Def_columns("test_sm_column_array",{"test_sm_test_state1_chain","test_sm_test_state2_chain","test_sm_test_state3_chain","test_sm_manager_chain"})

     Define_event_queue("test_sm_test_state1_queue",10)

     Define_event_queue("test_sm_test_state2_queue",10)

     Define_event_queue("test_sm_test_state3_queue",10)

     Define_event_queue("test_sm_queue",10)

    Define_state_machines("test_sm_array",{"test_sm"})

     Define_sm("test_sm",{"test_state1","test_state2","test_state3"},"test_sm_manager_chain","test_sm_queue","test_state1","(void *)test_data")

       Define_state("test_state1","test_sm_test_state1_chain")

       Define_state("test_state2","test_sm_test_state2_chain")

       Define_state("test_state3","test_sm_test_state3_chain")

     End_state_machine()




     Start_queue_column("test_sm_manager_chain",false,"test_sm_queue")
        Log_msg('state machine manager starting')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state1_chain",false,"test_sm_test_state1_queue")
        Log_msg('test_state1 starting')
        Set_sm_user_data('test_sm','(void *)state1_data')
        One_shot('DISPLAY_SM_USER_DATA','NULL')
        Wait_delay(1000)
        Log_msg('changing state to test_state2')
        Change_state('test_sm','test_state2')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state2_chain",false,"test_sm_test_state2_queue")
        Log_msg('test_state2 starting')
        Set_sm_user_data('test_sm','(void *)state2_data')
        One_shot('DISPLAY_SM_USER_DATA','NULL')
        Wait_delay(1000)
        Log_msg('changing state to test_state3')
        Change_state('test_sm','test_state3')
        Halt_column()
     End_column()




     Start_queue_column("test_sm_test_state3_chain",false,"test_sm_test_state3_queue")
        Log_msg('test_state3 starting')
        Set_sm_user_data('test_sm','(void *)state3_data')
        One_shot('DISPLAY_SM_USER_DATA','NULL')
        Wait_delay(1000)
        Log_msg('changing state to test_state1')
        Change_state('test_sm','test_state1')
        Halt_column()
     End_column()




