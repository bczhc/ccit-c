//
// Created by bczhc on 26/10/22.
//

#ifndef CCIT_C_DEF_H
#define CCIT_C_DEF_H

#include <stddef.h>
#include <stdint.h>

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef size_t usize;
typedef ssize_t isize;

#define UNREACHABLE() assert(!"Unreachable!")

#endif //CCIT_C_DEF_H
