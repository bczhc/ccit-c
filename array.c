//
// Created by bczhc on 25/10/22.
//

#include "array.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEFAULT_CAPACITY 10

typedef struct Array Array;

struct Array {
    size_t capacity;
    size_t size;
    void *items;
};

Array *new_array_capacity(size_t capacity) {
    Array *array = (Array *) malloc(sizeof(Array));
    array->size = 0;
    array->capacity = capacity;
    array->items = malloc(capacity);
}

void array_init_with_capacity(struct Array **a, size_t capacity) {
    *a = new_array_capacity(capacity);
}

void array_init(struct Array **a) {
    array_init_with_capacity(a, DEFAULT_CAPACITY);
}

void array_resize(Array *array, size_t new_size) {
    array->items = realloc(array->items, new_size);
}

void array_add(struct Array *a, const void *item, size_t size) {
    size_t new_size = a->size + size;
    if (new_size > a->capacity) {
        array_resize(a, new_size * 2);
    }
    memcpy(a->items + a->size, item, size);
    a->size = new_size;
}

void array_get(struct Array *a, size_t pos, size_t size, void *dest) {
    if (pos + size > a->size) {
        assert(!"Index out of bounds");
    }

    memcpy(dest, a->items + pos, size);
}

void array_remove(struct Array *a, size_t size) {
    if (size > a->size) {
        assert(!"No more items");
    }

    // just update the size; no shrink functions implemented yet
    a->size -= size;
}

size_t array_size(struct Array *a) {
    return a->size;
}

void array_free(struct Array *a) {
    free(a->items);
    free(a);
}
