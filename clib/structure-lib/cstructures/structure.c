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

// Add two arrays together into one big array (merge action)
Array* mergeArrays(Array* arr1, Array* arr2) {
    // New Array Size
    int newSize = (arr1->capacity + arr2->capacity);
    // Allocating Space
    Array* newArr = (Array*)alloc(sizeof(Array));
    newArr->basePtr = (int*)alloc(sizeof(int) * newSize);

    // Adds first array
    int indexCounter = 0;
    for(int i = 0; i < arr1->capacity; i++) {
        newArr->basePtr[indexCounter] = arr1->basePtr[indexCounter];
        indexCounter++;
    }

    // Adds second array
    for(int i = indexCounter; indexCounter < arr2->capacity; indexCounter++) {
        newArr->basePtr[indexCounter] = arr2->basePtr[indexCounter];
        indexCounter++;
    }
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

// Returns a reversed result of the array passed
Array* reverseArray(Array* revArr) {
    Array* newArr = (Array*)alloc(sizeof(Array));
    newArr->basePtr = (int*)alloc(sizeof(int) * revArr->size);

    for(int i = revArr->capacity; i > 0; i--) {
        newArr->basePtr[i] = revArr->basePtr[i];
    }

    dealloc(revArr->basePtr);
    dealloc(revArr);

    return newArr;
}

// finds the max value
int arrayMax(Array* arr) {
    if(!arr) return -1;

    int maxValue = 0;
    for(int i = 0; i < arr->capacity; i++) {
        if(arr->basePtr[i] > maxValue)
            maxValue = arr->basePtr[i];

    } return maxValue;
}

// finds the min value
int arrayMin(Array* arr) {

    if(!arr) return -1;

    int minValue = 0;
    for(int i = 0; i < arr->capacity; i++) {
        if(arr->basePtr[i] < minValue)
            minValue = arr->basePtr[i];

    } return minValue;
}

// -- MATRIX FUNCTIONS --