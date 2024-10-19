#ifndef _MACROS_H_
#define _MACROS_H_

#include "include_asm.h"

#define MAX_PLAYERS 4
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

#define ALIGN_16(size) (((size) + 0x1F) & ~0xF)

#define IS_DEBUG_PANIC(statement, file, line) do {} while(1)
#define ASSERT(condition) \
    if (!(condition)) { \
        IS_DEBUG_PANIC("Assertion failed: " #condition, __FILE__, __LINE__); \
    }

#endif