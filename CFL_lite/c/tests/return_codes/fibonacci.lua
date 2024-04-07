set_h_file("fibonacci.h")

local entry_point = "fibonacci_entry_point"

local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 0
local global_event_queue_size = 7
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size,global_event_queue_size,'debug_write')  


Store_user_code([[
/*
// defined in the runtime
typedef struct fibonacci_data_t
{
  unsigned number;
  unsigned index;
  unsigned fibonacci;
  unsigned first;
  unsigned second;
}fibonacci_data_t;
*/
static fibonacci_data_t fibonacci_data;

]]
)



 

local display_fibonaci_header = [[

   void display_fibonaci(void *input, void *params,Event_data_CFL_t *event_data);
]]

local display_fibonaci_code = [[

void display_fibonaci(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;
   (void)params;

   fibonacci_data_t *fibonacci_data = (fibonacci_data_t *)retrieve_current_column_data_CFL(input);
  Printf_CFL(input,"Fibanaci Data  %d\n",fibonacci_data->fibonacci);  
 
}

]]

Store_one_shot_function("display_fibonaci",'display_fibonaci',display_fibonaci_code,display_fibonaci_header) 


local initalize_fibonaci_header = [[

typedef struct fibonacci_data_t
{
  unsigned number;
  unsigned index;
  unsigned fibonacci;
  unsigned first;
  unsigned second;
}fibonacci_data_t;

   void initialize_fibonaci(void *input, void *params,Event_data_CFL_t *event_data);
]]

local initialize_fibonaci_code = [[

void initialize_fibonaci(void *input, void *params,Event_data_CFL_t *event_data)
{

  (void)event_data;

   (void)params;
   fibonacci_data_t *fibonacci_data = (fibonacci_data_t *)retrieve_current_column_data_CFL(input);
  
   fibonacci_data->number = 15;
   fibonacci_data->index = 2;
   fibonacci_data->fibonacci = 0;
   fibonacci_data->first = 0;
   fibonacci_data->second = 1;
  
}

]]

Store_one_shot_function("initialize_fibonaci",'initialize_fibonaci',initialize_fibonaci_code,initalize_fibonaci_header) 

local calculate_fibonacii_header = [[

bool calculate_fibonaci(void *input, void *params,Event_data_CFL_t *event_data);
]]



local calculate_fibonaci_code = [[

bool calculate_fibonaci(void *input, void *params,Event_data_CFL_t *event_data)
{

   (void)event_data;
   (void)params;

   fibonacci_data_t *fibonacci_data = (fibonacci_data_t *)retrieve_current_column_data_CFL(input);
   
   if(event_data->event_index != TIMER_TICK_CFL)
   {
     return false;
   }
   if(fibonacci_data->index <= fibonacci_data->number)
   {
     fibonacci_data->fibonacci = fibonacci_data->first + fibonacci_data->second;
     fibonacci_data->first = fibonacci_data->second;
     fibonacci_data->second = fibonacci_data->fibonacci;
     fibonacci_data->index++;
     return false;
   }
   else
   {
     return true;
   }
}

]]

Store_boolean_function("calculate_fibonaci",'calculate_fibonaci',calculate_fibonaci_code,calculate_fibonacii_header)


define_columns({'setup_computation','fibonaci'},0)


define_column('setup_computation',true)
    Store_column_data({'setup_computation','fibonaci'} ,'fibonacci_data')
    One_shot("initialize_fibonaci","NULL")
    Enable_columns({'fibonaci'},false)
    Log_msg("Starting Fibonacci computation")
    Join_columns({'fibonaci'},true)
    One_shot('display_fibonaci','NULL')
    terminate_column()
end_column()  

define_column("fibonaci",false)
   Log_msg('calculating fibonaci')
   Terminate_reset('calculate_fibonaci','NULL')    
end_column()

dump_build()

