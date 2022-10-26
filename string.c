//
// Created by bczhc on 26/10/22.
//

#include "string.h"
#include "array.h"
#include <stdlib.h>

void remove_terminator(String *s) {
    char removed = array_remove_char(&s->data);
    assert(removed == '\0');
}

void string_push(String *s, char c) {
    remove_terminator(s);
    array_add_char(&s->data, c);
    array_add_char(&s->data, '\0');
}

void string_init(String *s) {
    array_init(&s->data);
    array_add_char(&s->data, '\0');
}

void string_free(String *s) {
    array_free(&s->data);
}

void string_push_str(String *s, const char *str, const char *end) {
    size_t length;
    if (end == NULL) {
        length = strlen(str);
    } else {
        length = end - str + 1;
    }

    // the end '\0'
    remove_terminator(s);
    array_add(&s->data, str, length);
    array_add_char(&s->data, '\0');
}

const char *string_data(String *s) {
    return (const char *) s->data.items;
}

size_t string_length(String *s) {
    assert(array_get_char(&s->data, array_size(&s->data) - 1) == '\0');
    return array_size(&s->data) -1;
}
