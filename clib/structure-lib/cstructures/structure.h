// C Data Structures for Coffee OS By Kyle Brady
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
Array* reverseArray(Array* revArr);
Array* mergeArrays(Array* arr1, Array* arr2);

void swapElement(Array* arr, const int position1, const int position2);
const int arrayInsert(Array* arr, int position, int data);
const int arrayRemove(Array* arr, int position);
int arrayMax(Array* arr);
int arrayMin(Array* arr);

// -- Matrix --
typedef struct _matrix_ {
    int** baseMatrix;
    unsigned int rows;
    unsigned int cols;
} IntMatrix;

typedef struct _float_matrix_ {
    float** baseMatrix;
    unsigned int rows;
    unsigned int cols;
} FloatMatrix;

// -- Matrix Functions -- Int/Float Overloads
IntMatrix** createMatrix(unsigned int nrows, unsigned int ncols);
IntMatrix** copyMatrix(IntMatrix** imatrix, unsigned int nrows, unsigned int ncols);
IntMatrix** deleteMatrix(IntMatrix** imatrix);

FloatMatrix** createMatrix(unsigned int nrows, unsigned int ncols);
FloatMatrix** copyMatrix(FloatMatrix** fmatrix, unsigned int nrows, unsigned int ncols);
FloatMatrix** deleteMatrix(FloatMatrix** fmatrix);


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