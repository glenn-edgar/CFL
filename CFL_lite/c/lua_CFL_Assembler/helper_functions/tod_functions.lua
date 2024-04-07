
local tod_test_header_code = [[

#define OP_LT_CFL 0
#define OP_LE_CFL 1
#define OP_EQ_CFL 2
#define OP_GE_CFL 3
#define OP_GT_CFL 4


typedef struct Wait_tod_ROM_CFL_t
{
    unsigned short op_type;  //operation type
    short day_of_year;
    short month;
    short day;
    short dow;
    short hour;
    short minute;
    short second;
    bool terminate_flag;
    const void *user_data;

} Wait_tod_ROM_CFL_t;

bool test_tod_condition(const void *input, void *user_data, Event_data_CFL_t *event_data);


]]

local tod_test_code = [[

static bool test_while_tod_operations(const void *input,unsigned short op_type, short ref, short compare ){
    
    switch(op_type){
       
        case OP_LT_CFL:
            if (compare < ref)
            {
                return true;
            }
            break;
        case OP_LE_CFL:
            if (compare <= ref)
            {
                return true;
            }
            break;
        case OP_EQ_CFL:
            
            if (ref != compare)
            {
               
                return true;
            }
            break;    
        case OP_GE_CFL:
            if (compare >= ref )
            {
                return true;
            }
            break;
        case OP_GT_CFL:
            if (compare > ref)
            {
                return true;
            }
            break;
        default:
        ASSERT_PRINT_INT(input,"Invalid operator type",op_type);
    }
   
    return false;


}



bool test_tod_condition(const void *input, void *user_data, Event_data_CFL_t *event_data)
{
    (void)event_data;

    Wait_tod_ROM_CFL_t *wait_tod = (Wait_tod_ROM_CFL_t *)user_data;
    Time_control_CFL_t *time_control = Get_time_control_CFL(input);
    if (wait_tod->day_of_year >= 0)
    {
        if( test_while_tod_operations(input,wait_tod->op_type,time_control->day_of_year,  wait_tod->day_of_year ) == false){
            return true;
        }
    
    }
    if (wait_tod->month >= 0)
    {
        if( test_while_tod_operations(input,wait_tod->op_type,time_control->month,  wait_tod->month ) == false){
            return true;
        }
    }
    if (wait_tod->day >= 0)
    {
        if( test_while_tod_operations(input,wait_tod->op_type,time_control->day,  wait_tod->day ) == false){
            return true;
        }
    }
    if (wait_tod->dow >= 0)
    {
        if( test_while_tod_operations(input,wait_tod->op_type,time_control->dow,  wait_tod->dow ) == false){
            return true;
        }
    }
    if (wait_tod->hour >= 0)
    {
        if( test_while_tod_operations(input,wait_tod->op_type,time_control->hour,  wait_tod->hour ) == false){
            return true;
        }
    }
    if (wait_tod->minute >= 0)
    {
        if( test_while_tod_operations(input,wait_tod->op_type,time_control->minute,  wait_tod->minute ) == false){
            return true;
        }
     
    }
  
    if (wait_tod->second >= 0)
    {
      
        if( test_while_tod_operations(input,wait_tod->op_type,time_control->second,  wait_tod->second ) == false){
            return true;
        }
    }

    return false;
}
]]

Store_boolean_function("TOD_TEST",'test_tod_condition', tod_test_code,tod_test_header_code)

local wait_tod_rom = [[
   const Wait_tod_ROM_CFL_t %s_rom = { %s,%s,%s,%s,%s,%s,%s,%s,true,NULL }; 
]]

function generate_tod_dictionary()
    local return_value = {}
    return_value['day_of_year'] = -1
    return_value['month'] = -1
    return_value['day'] = -1
    return_value['dow'] = -1
    return_value['hour'] = -1
    return_value['minute'] = -1
    return_value['second'] = -1
    return return_value
end

function check_valid_dictionary(dictionary)
    
    keys = {'day_of_year','month','day','dow','hour','minute','second'}
    for i,key in ipairs(keys) do
        if dictionary[key] == nil then
            print("Invalid key in dictionary: "..key)
            os.exit(1)
        end
    end
    
end

function add_day_of_year(dictionary,day_of_year)
    check_valid_dictionary(dictionary)
    dictionary['day_of_year'] = day_of_year
end

function add_month(dictionary,month)
    check_valid_dictionary(dictionary)
    dictionary['month'] = month
end 

function add_day(dictionary,day)
    check_valid_dictionary(dictionary)
    dictionary['day'] = day
end 

function add_dow(dictionary,dow)
    check_valid_dictionary(dictionary)
    dictionary['dow'] = dow
end

function add_hour(dictionary,hour)
    check_valid_dictionary(dictionary)
    dictionary['hour'] = hour
end 

function add_minute(dictionary,minute)
    check_valid_dictionary(dictionary)
    dictionary['minute'] = minute
end

function add_second(dictionary,second)
    check_valid_dictionary(dictionary)
    dictionary['second'] = second
end 



function Wait_tod(to_type,dictionary)
    local unique_name = generate_unique_function_name()
    local day_of_year = dictionary['day_of_year']
    local month = dictionary['month']
    local day_of_week = dictionary['day']
    local hour = dictionary['hour']
    local minute = dictionary['minute']
    local second = dictionary['second']
    local day = dictionary['day']

    message = string.format(wait_tod_rom, unique_name, to_type,day_of_year,month,day,day_of_week,hour,minute, second)
    Store_user_code(message)
    Wait("TOD_TEST", -1,true,'NULL',unique_name..'_rom')    
end

function Wait_tod_gt(dictionary)
    local op_type = 'OP_GT_CFL' 
    Wait_tod(op_type,dictionary)
end

function Wait_tod_ge(dictionary)
    local op_type = 'OP_GE_CFL'
    Wait_tod(op_type,dictionary)
end

function Wait_tod_eq(dictionary)
    local op_type = 'OP_EQ_CFL'
    Wait_tod(op_type,dictionary)
end

function Wait_tod_lt(dictionary)
    local op_type = 'OP_LT_CFL'
    Wait_tod(op_type,dictionary)   
end

function Wait_tod_le(dictionary)
    local op_type = 'OP_LE_CFL'
    Wait_tod(op_type,dictionary)    
end

local verify_event_rom = [[
   const Wait_tod_ROM_CFL_t %s = { %s,%s,%s,%s,%s,%s,%s,%s,%s,%s }; 
]]

function Verify_tod(op_type,terminate_flag,failure_function,user_data,dictionary)
    local unique_name = generate_unique_function_name()
    local day_of_year = dictionary['day_of_year']
    local month = dictionary['month']
    local day = dictionary['day']
    local day_of_week = dictionary['dow']
    local hour = dictionary['hour']
    local minute = dictionary['minute']
    local second = dictionary['second']

    if user_data == 'NULL' then
        user_data = 'NULL'
      else
        user_data = '(void*)&'..user_data
      end
    message = string.format(verify_event_rom, unique_name, op_type,day_of_year,month,day,day_of_week,hour,minute,second,terminate_flag,user_data)
    
    Store_user_code(message)
    Verify("TOD_TEST", terminate_flag,failure_function,unique_name)    

   
end



function Verify_tod_gt(terminate_flag,failure_function,user_data,dictionary)
    local op_type = 'OP_GT_CFL' 
    Verify_tod(op_type,terminate_flag,failure_function,user_data,dictionary)
end



function Verify_tod_ge(terminate_flag,failure_function,user_data,dictionary)
    local op_type = 'OP_GE_CFL' 
   
    Verify_tod(op_type,terminate_flag,failure_function,user_data,dictionary)
end




function Verify_tod_lt(terminate_flag,failure_function,user_data,dictionary)
    local op_type = 'OP_LT_CFL' 
    Verify_tod(op_type,terminate_flag,failure_function,user_data,dictionary)
end

function Verify_tod_le(terminate_flag,failure_function,user_data,dictionary)
    local op_type = 'OP_LE_CFL' 
    Verify_tod(op_type,terminate_flag,failure_function,user_data,dictionary)
end

function Verify_tod_eq(terminate_flag,failure_function,user_data,dictionary)
    local op_type ='OP_EQ_CFL' 
    Verify_tod(op_type,terminate_flag,failure_function,user_data,dictionary)
end