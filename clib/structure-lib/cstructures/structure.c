#include <stdio.h>
#include "structure.h"
#include "../mem-lib/memory.h"

// Initialized memory through alloc and creates an array of a given size

// -- ARRAY FUNCTIONS --
Array* createArray(unsigned int size) {
    if(size <= 0) return NULL;

    Array* newArr = (Array*)alloc(sizeof(Array));
    newArr->basePtr = (int*)alloc(size * sizeof(int));
    newArr->size = size;
    newArr->capacity = 0;

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

// Inserts an element at a specified position
const int arrayInsert(Array* arr, int position, int data) {
    if(arr->capacity == arr->size) return -1;

    arr->basePtr[position] = data;
    arr->capacity++;

    return data;
}

// removes an element at a specified position
const int arrayRemove(Array* arr, int position) {
    if(arr->capacity == 0 || arr->size == 0) return -1;

    arr->basePtr[position] = 0;
    arr->capacity--;

    return arr->basePtr[position];
}

// Swaps elements in an array using positions / indexes
void swapElement(Array* arr, const int position1, const int position2) {
    int tempOne = arr->basePtr[position1];
    int tempTwo = arr->basePtr[position2];

    arr->basePtr[position1] = tempTwo;
    arr->basePtr[position2] = tempOne;
}
