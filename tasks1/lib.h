//
// Created by bczhc on 27/10/22.
//

#ifndef CCIT_C_LIB_H
#define CCIT_C_LIB_H

#include "../common.h"

bool check_u64_mul(u64 a, u64 b, u64 *res);

/**
 * @return `true` if overflowing
 */
bool rectangle_area(u64 length, u64 width, u64 *res);

#endif //CCIT_C_LIB_H
