#include "CFL_user_functions.h"
#include "CFL_s_float_expression.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct S_record_CFL_t {
    bool fn_flag;
    float value;
} S_record_CFL_t;




typedef struct r_stack_t {
    int param_stack_index;
    S_float_fn_type_CFL_t fn;
}r_stack_t;


typedef struct S_record_control_CFL_t {
    int token_number;
    int max_nesting;
    S_record_CFL_t* token_array;
    int number_of_fn_records;
    S_float_fn_record_CFL_t* fn_records;
} S_record_Control_CFL_t;



static void verify_matched_tokens(char* str, int* max_nesting);

static void match_function(int number_of_records, S_float_fn_record_CFL_t* records, int* match_index, char* input);
static char* format_string(void* handle, const char* str);
static void tokenize_string(char* str, char** tokens, int max_tokens, int* num_tokens);
static S_record_CFL_t* parse_tokens(void *handle, int fn_number, S_float_fn_record_CFL_t* s_record, int token_number,  char** string_token_array);



float Evaluate_s_float_expression_CFL(void* handle, void* s_handle, void* user_data) {
    S_record_Control_CFL_t* s_record_control = (S_record_Control_CFL_t*)s_handle;
    int token_index = 0;
    int r_stack_index = 0;
    int param_stack_index = 0;
    r_stack_t* r_stack = (r_stack_t*)Private_heap_malloc_CFL(handle, sizeof(r_stack_t) * s_record_control->max_nesting);
    float* param_stack = (float *)Private_heap_malloc_CFL(handle, sizeof(float) * s_record_control->token_number);
    // initialize r_stack
    while (token_index < s_record_control->token_number) {
        if (s_record_control->token_array[token_index].fn_flag == false) {
            
            *(param_stack + param_stack_index) = s_record_control->token_array[token_index].value;
            param_stack_index++;
        }
        else if (s_record_control->token_array[token_index].value == -1) {
            token_index++;
            int fn_index = s_record_control->token_array[token_index].value;
            if (fn_index >= s_record_control->number_of_fn_records) {
                ASSERT_PRINT("Error: Invalid function index", "");
            }
            else {
                if (r_stack_index >= s_record_control->max_nesting) {
                    ASSERT_PRINT("Error: Too many nested functions", "");
                }
                r_stack[r_stack_index].fn = s_record_control->fn_records[fn_index].fn;
                r_stack[r_stack_index].param_stack_index = param_stack_index;
                r_stack_index++;
            
            }

        }
        else if (s_record_control->token_array[token_index].value == -2) {
             r_stack_index--;
           
            if (r_stack_index < 0) {
                ASSERT_PRINT("Internal Rstack error", "");
            }
           float temp;
            
            int number_of_parameters = param_stack_index - r_stack[r_stack_index].param_stack_index;
            float *param_locations = param_stack + r_stack[r_stack_index].param_stack_index;
            
            temp = r_stack[r_stack_index].fn(handle, user_data,number_of_parameters, param_locations);
            param_stack_index = r_stack[r_stack_index].param_stack_index;
           
            *(param_stack + param_stack_index) = temp;
            param_stack_index++;
           
        }
        else {
            ASSERT_PRINT("Error: Invalid token in expression", "");
        }
        
       
        token_index++;
    }
    Private_heap_free_CFL(handle, r_stack);
    Private_heap_free_CFL(handle, param_stack);
   
    return *(param_stack + param_stack_index - 1);



}


void* Parse_s_float_expression_CFL(void* handle, int fn_number, S_float_fn_record_CFL_t* s_functions, const char* input) {
    char* ref_buffer;
    int  token_array_size = strlen(input);
    char** token_array = (char**)Private_heap_malloc_CFL(handle, sizeof(char*) * token_array_size);


    S_record_Control_CFL_t* s_record_control = (S_record_Control_CFL_t*)Allocate_once_malloc_CFL(handle, sizeof(S_record_Control_CFL_t));

    s_record_control->number_of_fn_records = fn_number;
    s_record_control->fn_records = s_functions;



    
    ref_buffer = format_string(handle, input);
   
    verify_matched_tokens(ref_buffer, &s_record_control->max_nesting);
    
    tokenize_string(ref_buffer, token_array, token_array_size, &s_record_control->token_number);
   
    
    
    s_record_control->token_array = parse_tokens(handle,fn_number, s_functions,s_record_control->token_number,token_array);
   
   
    Private_heap_free_CFL(handle, ref_buffer);
    Private_heap_free_CFL(handle, token_array);
    return s_record_control;




}




static S_record_CFL_t* parse_tokens(void *handle, int fn_number, S_float_fn_record_CFL_t* s_record, int token_number,  char** string_token_array) {

    S_record_CFL_t *token_array = (S_record_CFL_t*)Allocate_once_malloc_CFL(handle, sizeof(S_record_CFL_t) * token_number);
    char* token;
    for (int i = 0; i < token_number; i++) {
       

        // Iterate through tokens in the input string
        token = string_token_array[i];
       

        // Check for start paren
        if (strcmp(token, "(") == 0) {
        
            token_array[i].fn_flag = true;
            token_array[i].value = -1;
           
        }
        // Check for end paren
        else if (strcmp(token, ")") == 0) {
            
            token_array[i].fn_flag = true;
            token_array[i].value = -2;
            
        }
        // Check for integer
        else if (sscanf(token, "%f", &token_array[i].value) == 1) {
            
            token_array[i].fn_flag = false;
            
        }
        // Check for function
        else {
            int match_index;
            
            match_function(fn_number, s_record, &match_index, token);
            token_array[i].fn_flag = true;
            token_array[i].value = match_index;
           


        }
      


    }
 
    return token_array;



}




static void match_function(int number_of_records, S_float_fn_record_CFL_t* records, int* match_index, char* input) {
    int i;

    for (i = 0; i < number_of_records; i++) {
        if (strcmp(input, records[i].name) == 0) {
            *match_index = i;
            return;
        }
    }

    ASSERT_PRINT("Missed match starting closing {} ", input);
}


void verify_matched_tokens(char* str, int* max_nesting) {
    int count = 0;
    int nesting = 0;
    int max_nesting_local = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            count++;
            nesting++;
            if (nesting > max_nesting_local) {
                max_nesting_local = nesting;
            }
        }
        else if (str[i] == ')') {
            count--;
            nesting--;
            if (nesting < 0) {
                ASSERT_PRINT("Error: Unbalanced parentheses", "");
            }
        }
        if (count < 0) {
            ASSERT_PRINT("Error: losing parentheses before opening parentheses", "");

        }
    }

    if (count != 0) {

        ASSERT_PRINT("Error: Unbalanced parentheses", "");
    }

    *max_nesting = max_nesting_local;

}



static char* format_string(void* handle, const char* str) {
    int len = strlen(str);
    char* new_str = (char*)Private_heap_malloc_CFL(handle, sizeof(char) * (2 * len + 1));  // allocate memory for new string
    int new_index = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == ',') {
            new_str[new_index++] = ' ';  // replace comma with space
        }
        else if (str[i] == '(' || str[i] == ')') {
            new_str[new_index++] = ' ';  // insert space before and after parentheses
            new_str[new_index++] = str[i];
            new_str[new_index++] = ' ';
        }
        else {
            new_str[new_index++] = str[i];  // copy other characters as is
        }
    }
    new_str[new_index] = '\0';  // add null terminator to end of new string
    return new_str;
}

static void tokenize_string(char* str, char** tokens, int max_tokens, int* num_tokens) {
    char* token = strtok(str, " ,");  // get first token

    while (token != NULL && *num_tokens < max_tokens) {
        tokens[*num_tokens] = token;
        (*num_tokens)++;
        token = strtok(NULL, " ,");  // get next token
        if (*num_tokens >= max_tokens)
        {
            ASSERT_PRINT("Error: Too many tokens in string", "");
        }
    }
}