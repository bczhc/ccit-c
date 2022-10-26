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
#include "string.h"

/**
 * read a line from a stream
 * now it only handles LF ('\\n') line delimiters
 * @param fp
 * @return line buffer, `string_free` is required
 */
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
        string_push(&line, c);
        if (c == '\n') {
            break;
        }
    }

    return line;
}

int main() {
    String line = read_line(stdin);

    printf("Input: %s\n", string_data(&line));

    char *end_pos;
    long parsed = strtol(string_data(&line), &end_pos, 10);

    if (end_pos == string_data(&line)) {
        printf("No digits found");
        return 1;
    }
    string_free(&line);

    if ((parsed == LONG_MAX || parsed == LONG_MIN) && errno == ERANGE) {
        printf("Out of range!\n");
        return 1;
    }

    printf("Parsed: %ld\n", parsed);

    return 0;
}
