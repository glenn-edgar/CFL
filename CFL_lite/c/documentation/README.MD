# Description of CFL for Low RAM Devices <a id="Top"></a>

The original version of the CFL system was designed for devices with 4K of RAM and 32K of ROM. The current version is tailored for ARM devices with 32K of RAM and up to 256K of Flash. This system offers the following properties:

- The CFL language is constructed by a Lua preprocessor.
- C data structures are predominantly stored in Flash to conserve RAM.
    - **Disadvantages of Restricting Data Structures to Flash**:
        - The system cannot be changed at runtime.
            - An example of this limitation is that a column cannot be dynamically added. 
            - An instance where this would be useful is for tail recursion where a column clones itself.
        - Changes to startup data will be restricted.
    - **Advantages of Storing Data Structures in Flash**:
        - Data structures cannot be corrupted due to code overwriting them.
        - Extensive computational logic can be implemented into the target device as the overhead of the CFL system data structures are in flash.
- An "allocate once" heap, as well as a private heap, is provided. On startup, the CFL system requires:
    - The size of the "allocate once" heap.
    - The size of the private heap.
    - Area for the "allocate once" heap. This area must be specified by the user.
        - This can be via a static array buffer or a buffer allocated by the user. 
        - If `malloc` is used, then the user must free the buffer after the CFL system is terminated.
    - Area for the private heap is allocated from the "allocate once" heap.
    - The CFL system operations do not use any heap functions.
    - The heap system is provided to help users achieve:
        - Heap operations confined to a specific memory area.
        - System restarts without memory leaks.
- Another feature: Multiple CFL programs can operate in an RTOS system.
    - In an RTOS system, different CFL programs can communicate via the RTOS messaging system.
- CFL programs can be modularized into basic tasks like:
    - self-test 
    - factory test
    - various operational tests.
- CFL programs can execute in a sequence if the system is restricted to a single-threaded environment.

## Overview of the Rest of the Document

1. [Description of the CFL Language](#Appendix_A)
2. [Construction of the CFL System](#Appendix_B)
3. [Overview of the CFL Opcode](#Appendix_C)
4. The remainder of this document focuses on the verification unit for the CFL system, including:
   - [Directory Configuration](#Directory_Configuration)
   - [Getting Started and Directory Configuration](#Getting_Started)
   - [System Startup and Basic Heap Operations](#System_Startup)
   - [CFL Return Codes and Foundational Operations](#CFL_return_codes)
   - [While/Verify Opcodes](#While_Verify)
   - [Time of Day Opcodes](#TOD)
   - [Column Control](#Column_Control)
   - [Column State Machines](#Column_State_Machine)
   - [Complex State Machines](#Complex_State_Machines)
   - [S-expression Boolean Operations and Data Flow](#S-Expr)


<a id="Directory_Configuration"></a>
### Directory Configuration [Top](#Top)



<a id="Getting_Started"></a>
### Getting Started and Directory Configuration [Top](#Top)

The best way to describe the this section is to look at the build process.  The build process starts with with a build shell script or a composite make file.  In this example, a build shell script is used.  The build shell script is shown below.  The build shell script executes two steps a preprocessor step and a make directed compilation and linkage step.  



``` 
preprocessor generate_script.lua

if [ $? -ne 0 ]; then
    exit 1
fi
make clean
make
```
The preprocessor step is implemented by a lua script generate_script.lua. As discussed previously, the lua program is a modified from the standard lua distribution.  An extension was added to manipulate files under the linux operating system.  The modified lua program extensions will only run under a linux environment.  The examples here are developed in a Windows Environment using a Debian subsystem.

The code segment below is a bash command that exit the script if the lua preprocessing step has an error.
```
if [ $? -ne 0 ]; then
    exit 1
fi
```
The make step is optional as under an environment like Arduino, the IDE environment will compile the code.  Also the CFL engine environment will be compiled as an Arduino Library.  The make step shown below would be for an environment like a Debian Linux environment.  

The make sequence compiles the generated code as well as other user code.  The step make clean is used because I have not set up the dependencies correctly.  The make clean step ensures that all the files are recompiled.  The make step is shown below.

```
make clean
make
```

The make file two things from the CFL engine:
    - An include path to the include directory for the CFL engine.
    - A library path to the library directory for the CFL engine and the library which is CFL.a

The next section will describe a simple lua preprocessor script.


<a id="System_Startup"></a>
### System Startup and Basic Heap operations [Top](#Top)
This example is located in the github repository path of CFL/CFL_c_lite/tests/allocate directory.  The lua script that is called is generate_script.lua.  The salient segments of of the script generate_script.lua script is shown below.

The first section is shown below.

```

local current_working_directory = PXT.getwd() -- PXT is the added lua extension to manipulate files under linux

--- Note newDirectory is situational and is dependent on the location of the compiler.lua script
--- Usually this the location where the repository is cloned
local newDirectory = "../../lua_compiler/"  -- This is the directory where the compiler.lua is located

PXT.cwd(newDirectory)  -- Change the directory where the script compiler.lua is located
dofile("compiler.lua") -- This file import code to generate the CFL engine code
PXT.cwd(current_working_directory) -- Change the directory back to the original directory

```
The next set of code ...

```
-- this lua script is used to set the output file h file name which is passed to c routine which activates the CFL engine.
set_output("test_script.h") 

-- The local entry point is the name of the function that the c routine will call to this engine script.
local entry_point = "test_entry_point"


```


The next set of code loads in specific user supplied files.

```
local user_code = [[

/*
  This is the function that writes serial log messages to the screen.  
  The function below is for a linux environment.  
  This function will be passed to the CFL engine on startup.
*/
void debug_write(const void *buf, unsigned count)
{

    write(STDOUT_FILENO, buf, count);
}

/*
  Memory used for the "allocate once" is setup using a malloc call.  
  The reason for a malloc call is that the user can free the memory after the CFL engine is terminated and
  reused by other subsystems.
*/

char *allocate_once_memory = NULL;

void create_allocate_once_heap(){
    allocate_once_memory = (char *)malloc(2000);
}

void free_allocate_once_heap(){
    free(allocate_once_memory);
}

]]

This code is stored is appended to the lua variable user_code.  
This code is dumped to the .h file that is passed to the main C program.
Store_user_code(user_code)



The last output of the lua script function is shown below.

```
local allocate_once_heap_size = 2000
local private_heap_size = 1000
local default_event_queue_size = 10 
start_build(entry_point,"allocate_once_memory",allocate_once_heap_size,private_heap_size,default_event_queue_size) 
dump_output('debug_write') 

```






<a id="CFL_return_codes"></a>
### CFL return codes and foundational operations [Top](#Top)

[... content ...]

<a id="While_Verify"></a>
### While/Verify opcodes [Top](#Top)

[... content ...]


<a id="TOD"></a>
### Time of Day opcodes [Top](#Top)

[... content ...]


<a id="Column_Control"></a>
### Column Control [Top](#Top)

[... content ...]


<a id="Column_State_Machine"></a>
### Column State Machines [Top](#Top)

[... content ...]

<a id="Complex_State_Machines"></a>
### Complex State Machines [Top](#Top)

[... content ...]


<a id="S-Expr"></a>
### S-expression boolean operations [Top](#Top)

[... content ...]


<a id="Appendix_A"></a>
## Appendix A: Description of CFL Language [Top](#Top)




<a id="Appendix_B"></a>
## Appendix B: Description of the Lua Preprocessor [Top](#Top)

[... content ...]


<a id="Appendix_C"></a>
## Appendix C: Overview of CFL opcodes[Top](#Top)

[... content ...]
