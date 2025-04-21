#pragma once

#ifndef MEMORY_H_
#define MEMORY_H_

// -- Involved Headers
#include <assert.h>
#include <sys/types.h>

// Address Codes
#define _NORMAL_ 0x12345678
#define _DEBUG_ 0x77777777
#define _EXTRA_ 0x55555555

// Operating system Codes
#define _COFFEE_OS_ 0x1000
#define _WIN64_ 0x2000
#define _DEBIAN_LINUX_ 0x3000
#define _UBUNTU_LINUX_ 0x4000

// Size of block
#define _META_SIZE_ sizeof(struct _block_meta_data_)

// Base Address
void *gBase = NULL;
int operatingCode = _WIN64_;

// Block Meta-Data
typedef struct _block_meta_data_
{
    unsigned int blockSize;
    struct _block_meta_data_ *next;
    int free;
    int _debug_; // debug state
} MetaBlock;

// Finds next free block
MetaBlock *find_next_block(MetaBlock **lastPtr, unsigned int size)
{
    MetaBlock *current = (MetaBlock *)gBase;
    while (current && !(current->free && current->blockSize >= size))
    {
        *lastPtr = current;
        current = current->next;
    }
}

// If no free block is found, request the space
MetaBlock *request_block_space(MetaBlock *lastPtr, unsigned int size)
{
    MetaBlock *baseBlock;
    baseBlock = sbrk(0); // syscall
    void *blockRequest = sbrk(size + _META_SIZE_);
    assert((void *)baseBlock == blockRequest); // will optimize for thread safety

    if (blockRequest == (void *)-1)
    {
        lastPtr->next = baseBlock;
    }

    baseBlock->blockSize = size;
    baseBlock->next = NULL;
    baseBlock->free = 0;
    baseBlock->_debug_ = _NORMAL_;

    return baseBlock;
}

// Return the address of our block
MetaBlock *return_block_address(void *basePtr)
{
    return ((MetaBlock *)basePtr - 1);
}

// For merging two blocks together
MetaBlock *handle_merge_blocks(MetaBlock *fblock)
{
    // merge two blocks together
    // implement later
}

MetaBlock *split_block(MetaBlock *fblock, unsigned int segments)
{
    // split block into segments
    // implement later
}

// Allocate Memory of a specified Size
void *alloc(unsigned int size);
// Copy-allocate Memory of a specified Size
void *copyalloc(unsigned int elements, unsigned int elementSize);
// Re-allocate Memory to a new specified Size
void *realloc(void *basePtr, unsigned int newSize);
// de-allocate Memory [Free]
void dealloc(void *basePtr);

#endif