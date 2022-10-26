//
// Created by bczhc on 26/10/22.
//

#include "../common.h"
#include <string.h>
#include <stdlib.h>

u64 parse_int_check(const char *s) {
    ParseIntResult parsed = parse_int(s);
    if (parsed.ok) {
        return parsed.data.result;
    } else {
        switch (parsed.data.error) {
            case PIE_NO_DIGITS:
                eprintf("No digits found: %s", s);
                exit(EXIT_FAILURE);
            case PIE_OUT_OF_RANGE:
                eprintf("Out of range: %s", s);
                exit(EXIT_FAILURE);
        }
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

    String width_input = ((String *) split.items)[0];
    String height_input = ((String *) split.items)[1];

    u64 width = parse_int_check(string_data(&width_input));
    u64 height = parse_int_check(string_data(&height_input));

    u64 area = width * height;

    printf("Rectangle area: %lu\n", area);

    string_free(&width_input);
    string_free(&height_input);
    array_free(&split);
    string_free(&line);

    return 0;
}