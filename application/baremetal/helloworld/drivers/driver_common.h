#pragma once

#define assert_param(expr) ((void)0)

// #if defined(__INT32_MAX__) && defined(__UINT32_MAX__)
// typedef signed int int32_t;
// typedef unsigned int uint32_t;
// #elif defined(__LONG_MAX__) && defined(__ULONG_MAX__)
// #if __LONG_MAX__ == 2147483647L
// typedef signed long int32_t;
// typedef unsigned long uint32_t;
// #endif
// #else
// typedef signed int int32_t;
// typedef unsigned int uint32_t;
// #endif

// #if defined(__INT16_MAX__) && defined(__UINT16_MAX__)
// typedef signed short int16_t;
// typedef unsigned short uint16_t;
// #else
// typedef signed short int16_t;
// typedef unsigned short uint16_t;
// #endif

// #if defined(__INT8_MAX__) && defined(__UINT8_MAX__)
// typedef signed char int8_t;
// typedef unsigned char uint8_t;
// #else
// typedef signed char int8_t;
// typedef unsigned char uint8_t;
// #endif

#include "nmsis_compiler.h"
// #include "nmsis_gcc.h"
#include "t690.h"

#ifdef __cplusplus
 extern "C" {
#endif


#ifdef __cplusplus
}
#endif
