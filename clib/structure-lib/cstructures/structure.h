// C Data Structures for Coffee OS By Kyle Brady
#pragma once

// --> Status Codes <--
#define STRUC_ERR -2
#define STRUC_DELETION -1
#define STRUC_INIT 0
#define STRUC_POS_EMPTY 1
#define STRUC_FULL 2

// Swap two integers with pointer assignment
void swapInt(int* numOne, int* numTwo) {
    int temp = *numOne;
    *numOne = *numTwo;
    *numTwo = temp;
}

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

// -- Matrix Functions --
IntMatrix** createMatrix(unsigned int nrows, unsigned int ncols);
IntMatrix** copyMatrix(IntMatrix** imatrix, unsigned int nrows, unsigned int ncols);
IntMatrix** deleteMatrix(IntMatrix** imatrix);

// Add or remove elements
IntMatrix** matrixInsert(IntMatrix** matrix, const int row, const int col);
IntMatrix** matrixRemove(IntMatrix** matrix, const int row, const int col);
int matrixMax(IntMatrix** matrix);
int matrixMin(IntMatrix** matrix);

// -- Stack -- FILO
typedef struct _stack_ {
    int capacity;
    int top;
    int* baseStack;
} Stack;

// -- Stack Functions --
Stack* createStack(unsigned int capacity);
void deleteStack();

int isEmpty(); // checks if the stack is empty
void push(Stack* stack, int element); // adds an element onto the stack
int pop(Stack* stack); // removes the element at the tail
const int peek(Stack* stack); // returns the tail element

// -- Queue -- FIFO
typedef struct _queue_ {
    int* baseQueue;
    int front;
    unsigned int size;
    unsigned int capacity;
} Queue;

// -- Queue Functions --
Queue* createQueue(unsigned int size);
void deleteQueue();

void enqueue(int element); // adds an element in the queue
void dequeue(); // removes the element at the head
int peek(); // returns the head element

// -- Priority Queue --
typedef struct _priority_queue_ {
    int* pQueueBase;
    int size;
} PriorityQueue;

PriorityQueue* createPQueue();
void deletePQueue(PriorityQueue* pq);

// Increase or decrease heap sizes during insertion/deletion
const void heapIncrease(PriorityQueue* pq, int index);
const void heapDecrease(PriorityQueue* pq, int index);
// Insertion/Deletion
void penqueue(PriorityQueue* pq, int element);
void pdequeue(PriorityQueue* pq);
int peek(PriorityQueue pq);

// -- Singularly Linked List --
typedef struct _node_ {
    int data;
    int size;
} Node;

typedef struct _linked_list_ {
    // head and next node
    Node* head;
    Node* next;
} LinkedList;

LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* ll);

// Insertion
const void insertHead(int element);
const void insertTail(int element);
const void insertAt(int element, unsigned int index);
// Deletion
void deleteHead();
void deleteTail();
void deleteAt(unsigned int index);
// Find Max/Min Elements
int findMax();
int findMin();
// Getters
int getNodeCount(LinkedList* ll);
int getNodeSize(LinkedList* ll);
// Algorithms
LinkedList* reverseLinkedList(LinkedList ll);

// -- Doubly Linked List --

// -- Circularly Linked List --

// -- Tree --

// -- Graph --

// -- Heap --

// -- Dictionary --

// -- Hashmap --