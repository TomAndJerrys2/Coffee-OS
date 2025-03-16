// Int Data structures for Coffee-OS
// See "dynamic.h" for Generic Data structures

#pragma once

// --> Status Codes <--
#define STRUC_ERR -2
#define STRUC_DELETION -1
#define STRUC_INIT 0
#define STRUC_POS_EMPTY 1
#define STRUC_FULL 2

// -- Array --
typedef struct _array_ {
    int* basePtr;
    unsigned int size;

    unsigned int capacity;
} Array;

// -- Array Functions --
Array* createArray(unsigned int size);
Array* copyArray(Array* copyArr, unsigned int copySize);
Array* deleteArray(Array* delArr);

void swapElement(Array* arr, const int position1, const int position2);
const int arrayInsert(Array* arr, int position, int data);
const int arrayRemove(Array* arr, int position);

// -- Matrix --

// -- Stack --

// -- Queue --

// -- Priority Queue --

// -- Singularly Linked List --

// -- Doubly Linked List --

// -- Circularly Linked List --

// -- Tree --

// -- Graph --

// -- Heap --

// -- Dictionary --

// -- Hashmap --