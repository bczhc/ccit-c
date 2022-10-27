//
// Created by bczhc on 27/10/22.
//

#include "lib.h"

bool check_u64_mul(u64 a, u64 b, u64 *res) {
#ifdef GCC_BUILTIN_CHECKED_ARITHMETIC

#if __WORDSIZE == 64
    return __builtin_umull_overflow(a, b, res);
#elif __WORDSIZE == 32
    return __builtin_umulll_overflow(a, b, res);
#endif // __WORDSIZE

#else
    if (b > UINT64_MAX / a) {
        // overflow
        return true;
    } else {
        *res = a * b;
        return false;
    }
#endif // GCC_BUILTIN_CHECKED_ARITHMETIC
}

bool rectangle_area(u64 length, u64 width, u64 *res) {
    return check_u64_mul(length, width, res);
}
