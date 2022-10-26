//
// Created by bczhc on 25/10/22.
//

#ifndef CCIT_C_ARRAY_H
#define CCIT_C_ARRAY_H

#include <stddef.h>

typedef struct {
    size_t capacity;
    size_t size;
    void *items;
} Array;

void array_init_with_capacity(Array *a, size_t capacity);

void array_init(Array *a);

void array_free(Array *a);

void array_add(Array *a, const void *item, size_t size);

void array_remove(Array *a, size_t size);

size_t array_size(const Array *a);

char array_remove_char(Array *a);

void array_add_char(Array *a, char c);

char array_get_char(Array *a, size_t i);

void array_get(const Array *a, size_t pos, size_t size, void *dest);

void *array_items(const Array *a);

#endif //CCIT_C_ARRAY_H
