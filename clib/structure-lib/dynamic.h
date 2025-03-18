// Dynamic data structures by Kyle Brady
// Will Optimize throughout patches of the operating system

#pragma once
#ifndef DYNAMIC_H_
#define DYNAMIC_H_

namespace Structure {
    // Custom Vector Implementation
    template <class T> class Vector {
        private:
            T* baseVector = nullptr; // Dynamic Structure
            unsigned int capacity = {0}; // Vector Capacity
            unsigned int current = {0}; // Current Number of Elements
            // Clean-up function
            void __cleanup__() {
                if(this->baseVector != nullptr) {
                    dealloc(baseVector);
                    baseVector = nullptr;
                }
            }
    
        public:
            // Default Constructor
            explicit Vector();

            // Insertion / Deletion
            void push(T element);
            void push(T element, unsigned int index);

            // Pop also returns the element deleted
            T pop();

            // Getters
            T getElement(unsigned int index);
            int getSize();
            int getCapacity();
            
            // Return a reversed version of the vector passed
            static Vector reverseVector(Vector vec);

            // For Number values
            int vecMax(); // Max Int
            int vecMin(); // Min Int
            float vecMax(); // Max Float
            float vecMax(); // Min Float
            double vecMax(); // Max Double
            double vecMax(); // Min Double

            static void printVector(Vector vec); // prints vector

            // Destructor to deallocate memory
            ~Vector();
    };

    template <class T> class DynamicList {
        
    };

    template <class T> class DynamicStack {

    };

    template <class T> class DynamicQueue {

    };

    template <class T> class DynamicLinkedList {

    };

    template <class T> class DynamicTree {

    };

    template <class T, class V> class DynamicDictionary {

    };
}

#endif