#pragma once
#ifndef DYNAMIC_H_
#define DYNAMIC_H_

#include "../mem-lib/memory.h"

namespace Structure {
    // Custom Vector Implementation
    template <class T> class Vector {
        private:
            T* baseVector = nullptr; // Dynamic Structure
            unsigned int capacity = {0}; // Vector Capacity
            unsigned int current = {0}; // Current Number of Elements
        public:
            // Default Constructor
            explicit Vector();

            // Insertion / Deletion
            void push(T element) const;
            void push(T element, unsigned int index);

            // Pop also returns the element deleted
            T pop() const;

            // Getter
            T getElement(unsigned int index);
            
            // Return a reversed version of the vector passed
            static T* reverseVector(T* vec);

            // For Number values
            int vecMax(); // Max Int
            int vecMin(); // Min Int
            float vecMax(); // Max Float
            float vecMax(); // Min Float
            double vecMax(); // Max Double
            double vecMax(); // Min Double

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