/*

**
** This file implements a private heap function based upon
** algorithim in C & R C book
**  Derivative work to algorithm in the book
**
*/

#ifndef _CS_PRIVATE_HEAP_H_
#define _CS_PRIVATE_HEAP_H_

//#define CS_MEM_PROTECTION
//#define CS_MEM_PROTECTION
typedef enum
{
  CS_OK = 0,
  CS_INVALID_CONTROL_BLOCK = 1,
  CS_INVALID_MEMORY_BLOCK_UNDER_ADDRESS = 2,
  CS_INVALID_MEMORY_BLOCK_OVER_ADDRESS = 3,
  CS_INVALID_MEMORY_BLOCK_ENDING = 4,

} CS_HEAP_ERROR_CODE;

typedef enum
{
  CS_HEAP_FALSE = 0,
  CS_HEAP_TRUE = 1,
} CS_HEAP_BOOLEAN;

// this is the header must not change size

typedef void *CS_HEAP_TYPE;

typedef struct CS_MEM_BLOCK
{
  #ifdef CS_MEM_PROTECTION
  unsigned validTag:32;
  #endif
  struct CS_MEM_BLOCK *next;
  unsigned units:32;
} CS_MEM_BLOCK;

// control structure for Memory Handle
typedef struct
{
  void *heapMemoryArea;
  CS_MEM_BLOCK base;
  CS_MEM_BLOCK *allocp; // last free block
  unsigned allocatedSize;
  unsigned heapSize;
  unsigned validTag;
  CS_HEAP_ERROR_CODE lastErrorCode;
  const char *lastErrorCodeString;
} CS_MEMORY_CONTROL;

void initialize_privateHeap_CFL(CS_MEMORY_CONTROL *memoryControl,
                                int heapSize,
                                void *heapMemory);

void reset_privateHeap_CFL(CS_MEMORY_CONTROL *
                               memoryControl);

void *malloc_CFL(CS_MEMORY_CONTROL *memoryControl,
                 unsigned bytes);

void *realloc_CFL(CS_MEMORY_CONTROL *memoryControl,
                  void *prt, unsigned newSize);

void free_CFL(CS_MEMORY_CONTROL *memoryControl, void *ptr);

CS_HEAP_BOOLEAN verifyMemBlock_CFL(void *data);

CS_HEAP_BOOLEAN verifyControlBlock_CFL(CS_MEMORY_CONTROL *
                                           memoryControl);
// these are diagnostic functions

void dumpHeap_CFL(CS_MEMORY_CONTROL *memoryControl);

unsigned largest_block_privateHeap_CFL(CS_MEMORY_CONTROL *memoryControl);

int getHeapErrorCode_CFL(CS_MEMORY_CONTROL *
                             memoryControl);

const char *getHeapString_CFL(CS_MEMORY_CONTROL *memoryControl);

#endif
