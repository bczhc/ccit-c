//
// Created by bczhc on 25/10/22.
//

#ifndef CCIT_C_ARRAY_H
#define CCIT_C_ARRAY_H

#include <stddef.h>

struct Array;

void array_init(struct Array **a);

void array_free(struct Array *a);

void array_add(struct Array *a, const void *item, size_t size);

void array_remove(struct Array *a, size_t size);

size_t array_size(struct Array *a);

void array_get(struct Array *a, size_t pos, size_t size, void *dest);

#endif //CCIT_C_ARRAY_H
