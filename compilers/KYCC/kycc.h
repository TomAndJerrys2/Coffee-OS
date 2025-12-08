// Main header file for the Kyle C Compiler
//
// By Kyle Brady - Designed to be Lightweight and Efficient.
//
//

#define _LP64 1

#define __KYCC__ 1
#define __ELF__ 1

// Standard Sizes of Integral types
#define __SIZEOF_INT__ 4
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_LONG__ 8
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_LONG_DOUBLE_ 8
#define __SIZEOF_POINTER__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_SIZE_T__ 8
#define __SIZEOF_PTRDIFF_T 8

#define __STDC_HOSTED__ 1
#define __STDC_NO_ATOMICS__ 1
#define __STDC_ISO_10646__ 201103L
#define __STDC_NO_COMPLEX__ 1
#define __STDC_NO_THREADS__ 1
#define __STDC_NO_VLA__ 1

#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_VERSION__ 201103L

#define __STDC__ 1

// Architecture mappings

#define __amd64 1
#define __amd64__ 1

#define __gnu_linux__ 1

#define __linux 1
#define __linux__ 1

#define __unix 1
#define __unix__ 1

#define __x86_64 1
#define __x86_64__ 1

#define linux 1

#define __alignof__ alignof
#define __const__ const
#define __inline__ inline
#define __typeof__ typeof
#define __signed__ signed
#define __restrict__ restrict
#define __restrict restrict
#define __volatile__ volatile


// character assigned structures
//

typedef unsigned short char16_t;
typedef unsigned int char32_t;




