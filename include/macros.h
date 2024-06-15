#ifndef _MACROS_H_
#define _MACROS_H_

#include "include_asm.h"

#define IS_DEBUG_PANIC(statement, file, line) do {} while(1)
#define ASSERT(condition) \
    if (!(condition)) { \
        IS_DEBUG_PANIC("Assertion failed: " #condition, __FILE__, __LINE__); \
    }

#endif