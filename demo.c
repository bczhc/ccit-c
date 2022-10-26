//
// Created by bczhc on 25/10/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "array.h"
#include <pthread.h>

/**
 * read a line from a stream
 * now it only handles LF ('\\n') line delimiters
 * @param fp
 * @return line buffer, `array_free` is required
 */
Array read_line(FILE *fp) {
    Array buf;
    array_init(&buf);

    char c;
    while (1) {
        size_t size = fread(&c, 1, 1, fp);
        if (size == 0) {
            // error or EOF meets
            break;
        }
        array_add(&buf, &c, 1);
        if (c == '\n') {
            break;
        }
    }

    return buf;
}

int main() {
    Array line = read_line(stdin);
    {
        // end of string
        char c = '\0';
        array_add(&line, &c, 1);
    }
    void *line_inner = array_items(&line);
    printf("Input: %s\n", (char *) line_inner);
    long parsed = strtol((const char *) line_inner, NULL, 10);
    array_free(&line);

    if ((parsed == LONG_MAX || parsed == LONG_MIN) && errno == ERANGE) {
        printf("Out of range!\n");
        return 1;
    }


    printf("Parsed: %ld\n", parsed);

    return 0;
}
