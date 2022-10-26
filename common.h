//
// Created by bczhc on 26/10/22.
//

#ifndef CCIT_C_COMMON_H
#define CCIT_C_COMMON_H

#include <stdio.h>
#include "string.h"
#include <stdbool.h>
#include "def.h"

/**
 * read a line from a stream
 * now it only handles LF ('\\n') line delimiters
 * @param fp
 * @return line buffer, `string_free` is required
 */
String read_line(FILE *fp);

void eprintf(const char *format, ...);

enum ParseIntError {
    PIE_NO_DIGITS,
    PIE_OUT_OF_RANGE,
};

typedef struct {
    bool ok;
    union {
        u64 result;
        enum ParseIntError error;
    } data;
} ParseIntResult;

ParseIntResult parse_int(const char *s);

#endif //CCIT_C_COMMON_H
