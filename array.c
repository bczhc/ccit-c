//
// Created by bczhc on 25/10/22.
//

#include "array.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEFAULT_CAPACITY 10

void init_array_capacity(Array *a, size_t capacity) {
    a->size = 0;
    a->capacity = capacity;
    a->items = malloc(capacity);
}

void array_init_with_capacity(Array *a, size_t capacity) {
    init_array_capacity(a, capacity);
}

void array_init(Array *a) {
    array_init_with_capacity(a, DEFAULT_CAPACITY);
}

void array_resize(Array *array, size_t new_size) {
    array->items = realloc(array->items, new_size);
}

void array_add(Array *a, const void *item, size_t size) {
    size_t new_size = a->size + size;
    if (new_size > a->capacity) {
        array_resize(a, new_size * 2);
    }
    memcpy(a->items + a->size, item, size);
    a->size = new_size;
}

void array_add_char(Array *a, char c) {
    array_add(a, &c, 1);
}

char array_get_char(Array *a, size_t i) {
    return ((char *) a->items)[i];
}

void array_get(const Array *a, size_t pos, size_t size, void *dest) {
    if (pos + size > a->size) {
        assert(!"Index out of bounds");
    }

    memcpy(dest, a->items + pos, size);
}

void array_remove(Array *a, size_t size) {
    if (size > a->size) {
        assert(!"No more items");
    }

    // just update the size; no shrink functions implemented yet
    a->size -= size;
}

char array_remove_char(Array *a) {
    array_remove(a, 1);
    return ((const char *) a->items)[a->size];
}

size_t array_size(const Array *a) {
    return a->size;
}

void array_free(Array *a) {
    free(a->items);
}

void *array_items(const Array *a) {
    return a->items;
}
