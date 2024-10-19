#include "common.h"

#define HEAP_CONSTANT 0xA5
#define MIN_ALLOC_SIZE 16

#define MIN_HEAP_NODE_SIZE sizeof(HeapNode) + MIN_ALLOC_SIZE

/*
* Creates an empty heap of a given size.
*/
void* HuMemHeapInit(void* ptr, u32 size)
{
    HeapNode* heap = (HeapNode *)ptr;
    heap->size = size;
    heap->heap_constant = HEAP_CONSTANT;
    heap->active = 0;
    heap->prev = ptr;
    heap->next = ptr;
    return heap;
}

/*
* Allocates the requested size of memory in the given heap.
*/
void* HuMemMemoryAlloc(HeapNode* heap, s32 size)
{
    HeapNode* cur_heap;
    HeapNode* new_heap_temp;

    size = ALIGN_16(size);

    cur_heap = heap;
    do
    {
        if (!cur_heap->active)
        {
            if (cur_heap->size >= size)
            {
                if ((u32)(cur_heap->size - size) > MIN_HEAP_NODE_SIZE)
                {
                    new_heap_temp = ((void *)cur_heap) + size;
                    new_heap_temp->size = cur_heap->size - size;
                    new_heap_temp->heap_constant = HEAP_CONSTANT;
                    new_heap_temp->active = FALSE;

                    cur_heap->next->prev = new_heap_temp;
                    new_heap_temp->next = cur_heap->next;
                    cur_heap->next = new_heap_temp;
                    new_heap_temp->prev = cur_heap;
                    cur_heap->size = size;
                }

                cur_heap->active = TRUE;
                return (void *)cur_heap + sizeof(HeapNode);
            }
        }

        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return NULL;
}

/*
* Frees the given heap memory pointer.
*/
void HuMemMemoryFree(void *ptr)
{
    HeapNode *given_heap;
    HeapNode *heap_other;

    if (ptr == NULL)
    {
        return;
    }

    given_heap = (HeapNode *)(ptr - sizeof(HeapNode));
    if (given_heap->heap_constant != HEAP_CONSTANT)
    {
        return;
    }

    heap_other = given_heap->prev;
    if (((u32)heap_other < (u32)given_heap) && !heap_other->active)
    {
        given_heap->next->prev = heap_other;
        given_heap->prev->next = given_heap->next;
        given_heap->prev->size += given_heap->size;
        given_heap = given_heap->prev;
    }

    heap_other = given_heap->next;
    if (((u32)given_heap < (u32)heap_other) && !heap_other->active)
    {
        heap_other->next->prev = given_heap;
        given_heap->size += given_heap->next->size;
        given_heap->next = given_heap->next->next;
    }

    given_heap->active = FALSE;
}

/*
* Resizes a previously allocated buffer in a heap.
*/
void* HuMemMemoryRealloc(HeapNode *heap, void *mem, u32 new_size)
{
    void *ret;
    HeapNode *given_heap;
    HeapNode *new_heap;
    s32 alignedSize;

    given_heap = (HeapNode *)(mem - sizeof(HeapNode));

    alignedSize = ALIGN_16(new_size);

    if (given_heap->size >= alignedSize)
    {
        if ((u32)(given_heap->size - alignedSize) > MIN_HEAP_NODE_SIZE)
        {
            new_heap = (void *)given_heap + alignedSize;
            new_heap->size = given_heap->size - alignedSize;
            new_heap->heap_constant = HEAP_CONSTANT;
            new_heap->active = FALSE;
            given_heap->next->prev = new_heap;
            new_heap->next = given_heap->next;
            given_heap->next = new_heap;
            new_heap->prev = given_heap;
            given_heap->size = alignedSize;
        }

        return (void *)given_heap + sizeof(HeapNode);
    }
    else
    {
        ret = HuMemMemoryAlloc(heap, new_size);
        if (ret != NULL)
        {
            bcopy(mem, ret, given_heap->size - sizeof(HeapNode));
            HuMemMemoryFree(mem);
        }

        return ret;
    }

    return NULL;
}

/*
* Returns the total size of allocated buffers in a heap.
*/
u32 HuMemUsedMemorySizeGet(HeapNode* heap)
{
    HeapNode *cur_heap;
    u32 total_size;

    cur_heap = heap;
    total_size = 0;
    do
    {
        if (cur_heap->active == TRUE)
        {
            total_size += cur_heap->size;
        }
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return total_size;
}

/*
* Counts the number of used nodes in the heap's doubly linked list.
*/
u32 HuMemUsedMemoryBlockGet(HeapNode *heap)
{
    HeapNode *cur_heap;
    u32 count_free;

    cur_heap = heap;
    count_free = 0;
    do
    {
        count_free += (cur_heap->active ^ TRUE) == FALSE ? 1 : 0;
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return count_free;
}

/*
* Rounds a value up to align by 16.
*/
s32 HuMemMemoryAllocSizeGet(s32 value)
{
    return ALIGN_16(value);
}

// INCLUDE_ASM(const s32, "69060", func_800686F0_692F0);

// INCLUDE_ASM(const s32, "69060", func_80068720_69320);

// INCLUDE_ASM(const s32, "69060", func_80068744_69344);

// INCLUDE_ASM(const s32, "69060", func_8006877C_6937C);

// INCLUDE_ASM(const s32, "69060", func_800687B8_693B8);

// INCLUDE_ASM(const s32, "69060", func_800687FC_693FC);

// INCLUDE_ASM(const s32, "69060", func_80068964_69564);

// INCLUDE_ASM(const s32, "69060", func_800689A0_695A0);

// INCLUDE_ASM(const s32, "69060", func_80068A20_69620);

// INCLUDE_ASM(const s32, "69060", func_80068A84_69684);

// INCLUDE_ASM(const s32, "69060", func_80068AE0_696E0);

// INCLUDE_ASM(const s32, "69060", func_80068B80_69780);

// INCLUDE_ASM(const s32, "69060", func_80068C14_69814);

// INCLUDE_ASM(const s32, "69060", func_80068C48_69848);

// INCLUDE_ASM(const s32, "69060", func_80068CD4_698D4);

// INCLUDE_ASM(const s32, "69060", func_80068D24_69924);
