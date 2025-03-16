// Int Data structures for Coffee-OS
// See "dynamic.h" for Generic Data structures

#pragma once

#ifdef __cplusplus // for cpp compiler usage
extern "C" {
#endif

// --> Status Codes <--
#define STRUC_ERR -2
#define STRUC_DELETION -1
#define STRUC_INIT 0
#define STRUC_POS_EMPTY 1
#define STRUC_FULL 2

// -- Array --
typedef struct _array_ {
    // Properties
    int* basePtr;
    unsigned int size;
} Array;

// -- Array Functions --
Array* createArray(unsigned int size);
Array* copyArray(Array* copyArr, unsigned int copySize);
Array* deleteArray(Array* delArr);

const void swapElement(Array* arr, int position1, int position2);
int arrayInsert(Array* arr, int position, int data);
int arrayRemove(Array* arr, int position);
// ---------------------

// -- Matrix --

// -- Stack --

// -- Queue --

// -- Priority Queue --

// -- List (Dynamic-Type) --

// -- Singularly Linked List --

// -- Doubly Linked List --

// -- Circularly Linked List --

// -- Tree --

// -- Graph --

// -- Heap --

// -- Dictionary --

// -- Hashmap --


#ifdef __cplusplus
}
#endif