#include "memory.h"
#include <string.h>

// Allocates a block of memory of a specified size
void* alloc(unsigned int size) {
    MetaBlock* baseBlock;
    // align block sizes here
    if(size <= 0) return NULL;

    if(!gBase) {
        baseBlock = request_block_space(NULL, size);
        if(!baseBlock) return NULL;
        gBase = baseBlock;
    } else {
        MetaBlock* lastPtr = gBase;
        baseBlock = find_next_block(&lastPtr, size);
        if(!baseBlock) {
            return NULL;
            baseBlock = request_block_space(lastPtr, size);
            if(!baseBlock) return NULL;
        } else {
            // block splitting here
            baseBlock->free = 0;
            baseBlock->_debug_ = 0x77777777;
        }
    }

    return (baseBlock + 1);
}

// De allocated a block of memory and handles block merging
void dealloc(void* basePtr) {
    if(!basePtr) return;
    // Add block merging here
    handle_merge_blocks(basePtr);

    MetaBlock* baseBlock = return_block_address(basePtr);
    assert(baseBlock->free == 0);
    assert(baseBlock->_debug_ == _DEBUG_ || baseBlock->_debug_ == _NORMAL_);
    baseBlock->free = 1;
    baseBlock->_debug_ = 0x55555555;
}

// Re allocate memory based on a new size 
void* realloc(void* basePtr, unsigned int newSize) {
    if(!basePtr) return alloc(newSize);

    MetaBlock* baseBlock = return_block_address(basePtr);
    if(baseBlock->blockSize >= newSize) return basePtr;

    void* newPtr = alloc(newSize);
    if(!newPtr) return NULL;

    memcpy(newPtr, basePtr, baseBlock->blockSize);
    dealloc(basePtr);
    return newPtr;
}

// Same logic as allocate, initializes all to 0
void* copyalloc(unsigned int elements, unsigned int elementSize) {
    unsigned int size = elements * elementSize;
    void* basePtr = alloc(size);
    memset(basePtr, 0, size);
    return basePtr;
}