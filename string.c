//
// Created by bczhc on 26/10/22.
//

#include "string.h"
#include "array.h"

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

void string_push_str(String *s, const char *ptr, size_t length) {
    remove_terminator(s);
    array_add(&s->data, ptr, length);
    array_add_char(&s->data, '\0');
}

const char *string_data(String *s) {
    return (const char *) s->data.items;
}

size_t string_length(String *s) {
    assert(array_get_char(&s->data, array_size(&s->data) - 1) == '\0');
    return array_size(&s->data) - 1;
}

Array string_split(String *str, const char *separator, size_t sep_size) {
    const char *s = string_data(str);
    size_t stringSize = string_length(str);

    Array list, indices;
    array_init(&list), array_init(&indices);

    size_t length = sep_size;
    const char *found;
    const char *start = s;
    while (start - s <= stringSize && (found = strstr(start, separator)) != NULL) {
        size_t index_item = found - s;
        array_add(&indices, &index_item, sizeof(size_t));
        start = found + 1;
    }
    size_t len = array_size(&indices) / sizeof(size_t);
    size_t subStart = 0;

    for (size_t i = 0; i < len; ++i) {
        size_t index = ((size_t *) indices.items)[i];
        size_t size = index - subStart;

        String r = string_new_from_str(s + subStart, size);

        array_add(&list, &r, sizeof(String));
        subStart = index + length;
    }

    String rest = string_new_from_str(s + subStart, stringSize - subStart);
    array_add(&list, &rest, sizeof(String));

    array_free(&indices);

    return list;
}

String string_new_from_str(const char *str, size_t length) {
    String s;
    string_init_with_capacity(&s, length);
    string_push_str(&s, str, length);
    return s;
}

void string_init_with_capacity(String *s, size_t capacity) {
    array_init_with_capacity(&s->data, capacity + 1 /* for the end '\0' */);
    array_add_char(&s->data, '\0');
}
