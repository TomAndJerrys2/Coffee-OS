#include "structure.h"
#include "../mem-lib/memory.h"

#define EMPTY_STACK -1

// to check just for this file
static int isFull(Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// allocate memory to the stack structure
Stack* createStack(unsigned int capacity) {
    Stack* stackPtr = (Stack*)alloc(sizeof(Stack*) * capacity);
    stackPtr->baseStack = (Stack*)alloc(sizeof(Stack));
    stackPtr->capacity = capacity;
    stackPtr->top = EMPTY_STACK;
}

// Checks if the current stack is empty by checking the top
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// adds elements in a FILO Structure
void push(Stack* stack, int element) {
    if(isFull(stack)) {
        // needs debugging reallocate stack size if full to account for new element
        //Stack* tempStack = (Stack*)realloc(stack, sizeof(stack->baseStack) + sizeof(element));
        return; // cause of an overflow
    }
    stack->baseStack[++stack->top] = element;
}

// deletes the last element added and returns it
int pop(Stack* stack) {
    // debug this too, cause of an underflow
    if(isEmpty) return;

    return (stack->baseStack[stack->top--]);
}

// Delete and deallocate memory from the stack object
void deleteStack(Stack* stack) {
    dealloc(stack->baseStack);
    dealloc(stack);
}
