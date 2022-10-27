//
// Created by bczhc on 26/10/22.
//

#include <string.h>
#include <stdlib.h>
#include "lib.h"

i64 parse_int_check(const char *s) {
    i64 parsed;
    enum ParseIntResult result = parse_int(s, &parsed);
    switch (result) {
        case PIE_NO_DIGITS:
            eprintf("No digits found: %s", s);
            exit(EXIT_FAILURE);
        case PIE_OUT_OF_RANGE:
            eprintf("Out of range: %s", s);
            exit(EXIT_FAILURE);
        case PIE_OK:
            return parsed;
        default:
            UNREACHABLE();
    }
}

int main() {
    printf("Input (format: '<number> <number>'): "), fflush(stdin);

    String line = read_line(stdin);
    Array split = string_split(&line, " ", 1 /* size of the single space */);

    size_t item_size = array_size(&split) / sizeof(String);
    if (item_size != 2) {
        eprintf("Invalid input format");
        return 1;
    }

    String length_input = ((String *) split.items)[0];
    String width_input = ((String *) split.items)[1];

    i64 length = parse_int_check(string_data(&length_input));
    i64 width = parse_int_check(string_data(&width_input));

    if (length < 0 && width < 0) {
        eprintf("Requires positive numbers");
        return 1;
    }

    u64 area;
    if (rectangle_area(length, width, &area)) {
        eprintf("Multiplication overflow!");
        return 1;
    }

    printf("Rectangle area: %lu\n", area);

    string_free(&length_input);
    string_free(&width_input);
    array_free(&split);
    string_free(&line);

    return 0;
}
