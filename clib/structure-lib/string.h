// Custom String Class by Kyle Brady

#pragma once
#ifndef STRING_H_
#define STRING_H_

#include "../mem-lib/memory.h"

class String {
    private:
        char* baseStr = nullptr;
        int charCount { 0 };

    public:
        // Default Constructor
        String();
        // Copy-Constructor
        String(const String& str);
        // C-String Constructor
        String(const char* str);

        // Assignment operations
        String& operator=(const String& str); // for class strings
        String& operator=(const char* str); // for c-style strings
        String& operator=(const char c); // for characters

        // Index operations
        char& operator[](unsigned int position);
        const char& operator[](unsigned int position) const;

        // Increment/Modify operations
        String& operator+=(const String& str);
        String& operator+=(const char* str);
        String& operator+=(const char c);

        // Class methods
        int length(String str);
        void swapString(String& strOne, String& strTwo) const;
        bool isEmpty(String str);
        void splitString(String str, int position);

        // String Destructor
        ~String();
};

#endif