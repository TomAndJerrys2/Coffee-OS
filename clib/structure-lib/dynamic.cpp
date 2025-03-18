#include <iostream>
#include "dynamic.h"
#include "../mem-lib/memory.h"

#define _INIT_SIZE_ 1
#define _SCALE_SIZE_ 2

using namespace Structure; // in dynamic.h

// Default Vector Constructor to allocate memory space
template<class T> Vector<T>::Vector() {
    baseVector = (T*)alloc(sizeof(T) * _INIT_SIZE_);
    capacity = { 1 };
    current = { 0 };

    std::cout << "> Vector Initialized" << '\n';
}

// Insert element + Overload [slow time complexity for the moment O(N^3)]
template<class T> void Vector<T>::push(T element) {
    if(current == capacity) {
        T* newBasePtr = (T*)realloc(baseVector, (sizeof(T) * _SCALE_SIZE_));
        // Copy elements from old base Vector to newBasePtr
        for(int i = 0; i < capacity; i++) {
            newBasePtr[i] = baseVector[i];
        }
        // Delete previous Pointer
        Vector::__cleanup__(baseVector);
        capacity *= 2; // increase capacity by 2
        baseVector = newBasePtr;
    }
    baseVector[current] = element;
    current++
    // Debug Messages
    std::cout << "> Element Added: " << element << '\n';
    std::cout << "> New Size: " << getSize() << '\n';
}

template<class T> void Vector<T>::push(T element, unsigned int index) {
    if(index == capacity)
        push(element);
    else
        baseVector[index] = element;
}

// Delete Element from Vector
template<class T> T Vector<T>::pop() {
    if(current == 0)
        throw new EmptyStructureException;
    else
        current--;
}

// Get Element from Index
template<class T> T Vector<T>::getElement(unsigned int index) {
    // checks index range
    if(index > current)
        return baseVector[index];
    return -1;
}

// Get Vector Capacity
template<class T> int Vector<T>::getCapacity() { return capacity }
// Get Vector Element Count
template<class T> int Vector<T>::getSize() { return current; }

// Default Vector Destructor
template<class T> Vector<T>::~Vector() {
    Vector::__cleanup__();
}


