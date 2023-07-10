/*



This is derivative work of the malloc algorithim presented in the K&R C book


**
*/

#include "Cfl_debug.h"
#include "Cfl_private_heap.h"

#include "CFL_debug.h"

#define CS_CONTROL_BLOCK_VALID 0x55aa55aa
#define CS_MEM_BLOCK_VALID 0xAA55AA55
#define CS_MEM_BLOCK_END_VALID 0xDEADBEEF
static const char *cs_heap_error_string[] = {
    "OK",
    "INVALID CONTROL BLOCK",
    "INVALID MEMORY  BLOCK",
    "MEMORY BLOCK LESS THAN PRIVATE HEAP",
    "MEMORY BLOCK GREATER THAN PRIVATE HEAP",
    "MEMORY BLOCK END CORRUPTION"};

static void *cs_malloc_allocate_a(CS_MEMORY_CONTROL *memoryControl,
                                  unsigned bytes);

static void *cs_malloc_realloc_a(CS_MEMORY_CONTROL *memoryControl, void *ptr,
                                 unsigned bytes);

static void cs_free_a(CS_MEMORY_CONTROL *memoryControl, void *ptr);

void initialize_privateHeap_CFL(CS_MEMORY_CONTROL *memoryControl, int heapSize,
                                void *heapMemory)

{
  memoryControl->heapSize = heapSize;
  memoryControl->allocatedSize = 0;
  memoryControl->heapMemoryArea = heapMemory;
  memoryControl->allocp = &memoryControl->base;
  memoryControl->base.next = (CS_MEM_BLOCK *)memoryControl->heapMemoryArea;
  memoryControl->base.units = 0;
  memoryControl->base.next->units = heapSize / sizeof(CS_MEM_BLOCK);
  memoryControl->base.next->next = &memoryControl->base;
  memoryControl->lastErrorCode = CS_OK;
  memoryControl->validTag = CS_CONTROL_BLOCK_VALID;
  memoryControl->lastErrorCodeString = cs_heap_error_string[CS_OK];
}

void reset_privateHeap_CFL(CS_MEMORY_CONTROL *memoryControl)
{

  if (verifyControlBlock_CFL(memoryControl) == CS_HEAP_TRUE)
  {

    memoryControl->allocatedSize = 0;
    memoryControl->allocp = &memoryControl->base;
    memoryControl->base.next = (CS_MEM_BLOCK *)memoryControl->heapMemoryArea;
    memoryControl->base.units = 0;
    memoryControl->base.next->units =
        memoryControl->heapSize / sizeof(CS_MEM_BLOCK);
    memoryControl->base.next->next = &memoryControl->base;
    memoryControl->validTag = CS_CONTROL_BLOCK_VALID;
    memoryControl->lastErrorCode = CS_OK;
    memoryControl->lastErrorCodeString = cs_heap_error_string[CS_OK];
  }
  else
  {
    ASSERT_PRINT(__func__, "bad memory control block");
  }
}

void *malloc_CFL(CS_MEMORY_CONTROL *memoryControl, unsigned bytes)
{
  void *returnValue;
  if (bytes == 0)
  {
    ASSERT_PRINT(__func__, "cannot allocate 0 bytes");
  }
  if (verifyControlBlock_CFL(memoryControl) == CS_HEAP_TRUE)
  {
    returnValue = cs_malloc_allocate_a(memoryControl, bytes);
    if (returnValue == NULL)
    {
      ASSERT_PRINT(__func__, "out of memory");
    }
  }
  else
  {
    ASSERT_PRINT(__func__, "bad memory control block");
    returnValue = NULL;
  }

  return returnValue;
}

void *realloc_CFL(CS_MEMORY_CONTROL *memoryControl, void *ptr,
                  unsigned newSize)
{

  // CS_MEM_BLOCK *p;
  void *returnValue;

  if (newSize == 0)
  {
    ASSERT_PRINT(__func__, "cannot allocate 0 bytes");
  }
  returnValue = NULL;
  if (ptr == NULL)
  {
    returnValue = malloc_CFL(memoryControl, newSize);

    memset(returnValue, 0, newSize);
    goto done;
  }

  

  if (verifyMemBlock_CFL(ptr) != CS_HEAP_TRUE)
  {

    ASSERT_PRINT(__func__, "bad memory  block");
  }

  if (verifyControlBlock_CFL(memoryControl) != CS_HEAP_TRUE)
  {

    ASSERT_PRINT(__func__, "bad memory control block");
  }

  returnValue = cs_malloc_realloc_a(memoryControl, ptr, newSize);

done:
  return returnValue;
}

void free_CFL(CS_MEMORY_CONTROL *memoryControl, void *ptr)
{
  // CS_MEM_BLOCK *p;

  if (ptr == NULL)
  {
    return;
  }

  

  if (verifyMemBlock_CFL(ptr) != CS_HEAP_TRUE)
  {

    ASSERT_PRINT(__func__, "bad memory block");
  }

  if (verifyControlBlock_CFL(memoryControl) != CS_HEAP_TRUE)
  {

    ASSERT_PRINT(__func__, "bad memory control block");
  }

  if (memoryControl == NULL)
  {
    ASSERT_PRINT(__func__, "bad memory control block");
  }

  cs_free_a(memoryControl, ptr);

  ; // end function
}

CS_HEAP_BOOLEAN verifyMemBlock_CFL(void *data)
{
  
   CS_MEM_BLOCK *p = (CS_MEM_BLOCK *)data;
   p--;
#ifdef CS_MEM_PROTECTION
      if(p->validTag != CS_MEM_BLOCK_VALID){
        ASSERT_PRINT_F("bad memory initial block %p", data);
      }
      CS_MEM_BLOCK *z = p+p->units-1;
      if(z->validTag != CS_MEM_BLOCK_END_VALID){
        ASSERT_PRINT_F("bad memory ending block %p", data);
      }
    
#endif
  

  return CS_HEAP_TRUE;
}

CS_HEAP_BOOLEAN verifyControlBlock_CFL(CS_MEMORY_CONTROL *memoryControl)
{
  CS_HEAP_BOOLEAN returnValue;

  if (memoryControl->validTag != CS_CONTROL_BLOCK_VALID)
  {
    memoryControl->lastErrorCode = CS_INVALID_CONTROL_BLOCK;
    memoryControl->lastErrorCodeString =
        cs_heap_error_string[CS_INVALID_CONTROL_BLOCK];
    returnValue = CS_HEAP_FALSE;
  }
  else
  {
    returnValue = CS_HEAP_TRUE;
  }
  return returnValue;
}

// this is a diagnostic function
void dumpHeap_CFL(CS_MEMORY_CONTROL *memoryControl)
{
  CS_MEM_BLOCK *p = NULL;
  CS_MEM_BLOCK *q = NULL;
  unsigned totalUnits;

  totalUnits = 0;
  for (q = memoryControl->allocp, p = q->next; /**/; q = p, p = p->next)
  {
    totalUnits += p->units;
    Printf_CFL("\tp=%p p->units=%5d p+p->units=%p p->next=%p\r\n", p,
               p->units, p + p->units, p->next);
    if (p == memoryControl->allocp)
    {
      break;
    }
  }
  Printf_CFL("total memory blocks %d total bytes %d \r\n", totalUnits,
             (int)(totalUnits * sizeof(CS_MEM_BLOCK)));
}

unsigned largest_block_privateHeap_CFL(CS_MEMORY_CONTROL *memoryControl)
{

  CS_MEM_BLOCK *p = NULL;
  CS_MEM_BLOCK *q = NULL;
  unsigned max_block;

  max_block = 0;

  for (q = memoryControl->allocp, p = q->next; /**/; q = p, p = p->next)
  {
    if (p->units > max_block)
    {
      max_block = p->units;
    }

    if (p == memoryControl->allocp)
    {
      break;
    }
  }

  return max_block * sizeof(CS_MEM_BLOCK);
}

int getHeapErrorCode_CFL(CS_MEMORY_CONTROL *memoryControl)
{
  return memoryControl->lastErrorCode;
}

const char *getHeapString_CFL(CS_MEMORY_CONTROL *memoryControl)
{
  return memoryControl->lastErrorCodeString;
}

static void *cs_malloc_allocate_a(CS_MEMORY_CONTROL *memoryControl,
                                  unsigned bytes)
{
  unsigned units;
  CS_MEM_BLOCK *p = NULL;
  CS_MEM_BLOCK *q = NULL;
  
  /* number of MEM's we need to hold header_info + bytes */
  units = 1 + (bytes + sizeof(CS_MEM_BLOCK) - 1) / sizeof(CS_MEM_BLOCK);
  
#ifdef CS_MEM_PROTECTION
 // put a tag at the end of the block
  units += 1;
  
#endif
  q = memoryControl->allocp;

  /* cruise for a large enough block (first fit) */
  for (p = q->next;; q = p, p = p->next)
  {  
    if (p->units >= units)
    {
      if (p->units == units)
      {
        /* exactly right ... unlink <p> */
        q->next = p->next;
      }
      else
      {
        /* reduce p's units and return p's tail */
        p->units -= units;
        p += p->units;
        p->units = units;
      }
      /* set next start point and return */
      memoryControl->allocp = q;
      memoryControl->allocatedSize += units;
      memset((p + 1), 0, (units - 1) * sizeof(CS_MEM_BLOCK));
#ifdef CS_MEM_PROTECTION
      p->validTag = CS_MEM_BLOCK_VALID;
      CS_MEM_BLOCK *z = p+units-1;
      z->validTag = CS_MEM_BLOCK_END_VALID;
#endif

      return (void *)(p + 1); // advance past memory Block
    }

    /* wrapped around freelist ... No Memory Abort Loop */
    if (p == memoryControl->allocp)
    {

      return NULL;
    }
  }
}

static void *cs_malloc_realloc_a(CS_MEMORY_CONTROL *memoryControl, void *ptr,
                                 unsigned bytes)
{
  unsigned units;
  CS_MEM_BLOCK *p;
  void *returnValue;
  /* number of MEM's we need to hold header_info + bytes */
  units = 1 + (bytes + sizeof(CS_MEM_BLOCK) - 1) / sizeof(CS_MEM_BLOCK);
#ifdef CS_MEM_PROTECTION
  units += 1;
#endif
  if (ptr == NULL)
  {
    return NULL;
  }
  p = (CS_MEM_BLOCK *)ptr - 1;

  if (units > p->units)
  {
    // note this is not an optimium realloc as I did not check to see if
    // there is an adjacent free block
    returnValue = cs_malloc_allocate_a(memoryControl, bytes);
    if (returnValue != NULL)
    {
      memset(returnValue, 0, bytes);
      memcpy(returnValue, ptr, bytes);
      cs_free_a(memoryControl, ptr);
      ;
    }
  }
  else
  {
    returnValue = ptr;
  }
  return returnValue;
}

static void cs_free_a(CS_MEMORY_CONTROL *memoryControl, void *ptr)
{
  CS_MEM_BLOCK *p;
  CS_MEM_BLOCK *q;
  ;

  if (ptr == NULL)
  {
    return;
  }

  p = (CS_MEM_BLOCK *)ptr - 1;

  memoryControl->allocatedSize -= p->units;
  for (q = memoryControl->allocp; !(p > q && p < q->next); q = q->next)
  {
    if (q >= q->next && (p > q || p < q->next))
      break;
  }

  if (p + p->units == q->next)
  {
    /* merge right */
    p->units += q->next->units;
    p->next = q->next->next;
  }
  else
  {
    /* insert right */
    p->next = q->next;
  }

  if (q + q->units == p)
  {
    /* merge left */
    q->units += p->units;
    q->next = p->next;
  }
  else
  {
    /* insert left */
    q->next = p;
  }
  memoryControl->allocp = q;
}
