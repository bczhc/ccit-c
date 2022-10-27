//
// Created by bczhc on 26/10/22.
//

#include "common.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

String read_line(FILE *fp) {
    String line;
    string_init(&line);

    char c;
    while (1) {
        size_t size = fread(&c, 1, 1, fp);
        if (size == 0) {
            // error or EOF meets
            break;
        }
        if (c == '\n') {
            break;
        }
        string_push(&line, c);
    }

    return line;
}

void eprintf(const char *format, ...) {
    va_list p;
    va_start(p, format);
    vfprintf(stderr, format, p);
    va_end(p);
}

enum ParseIntResult parse_int(const char *s, i64 *res) {
    char *end_pos;
    long parsed = strtol(s, &end_pos, 10);

    if (end_pos == s) {
        return PIE_NO_DIGITS;
    }

    if ((parsed == LONG_MAX || parsed == LONG_MIN) && errno == ERANGE) {
        return PIE_OUT_OF_RANGE;
    }

    *res = parsed;
    return PIE_OK;
}
