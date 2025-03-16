#include <stdio.h>
#include "structure.h"
#include "../mem-lib/memory.h"

// Initialized memory through alloc and creates an array of a given size
Array* createArray(unsigned int size) {
    if(size <= 0) return NULL;

    Array* newArr = (Array*)alloc(sizeof(Array));
    newArr->basePtr = (int*)alloc(size * sizeof(int));
    newArr->size = size;

    return newArr;
}

Array* deleteArray(Array* delArr) {
    if(!delArr) return NULL;
    // Each element becomes 0 - will optimize later
    for(int i = 0; i < delArr->size; i++) {
        delArr->basePtr[i] = 0;
    }
    // Free Pointers
    dealloc(delArr);
    dealloc(delArr->basePtr);
    delArr = NULL;
}

// Copy an existing array to an array of a new size
Array* copyArray(Array* copyArr, unsigned int copySize) {
    if(!copyArr || copyArr->size <= 0) return NULL;
    if(copySize < copyArr->size) 
        printf("Cannot Copy! New Array is smaller than Old Array");

    Array* newArr = createArray(copySize);

    for(int i = 0; i < (copyArr->size); i++) {
        newArr->basePtr[i] = copyArr->basePtr[i];
        // elements allocated after last element are 0
        if(!copyArr->basePtr[i]) {
            newArr->basePtr[i] = 0;
        }
    }

    deleteArray(copyArr);

    return newArr;
}

int arrayInsert(Array* arr, int position, int data) {
    
}

int arrayRemove(Array* arr, int position) {

}

const void swapElement(Array* arr, int position1, int position2) {

}
