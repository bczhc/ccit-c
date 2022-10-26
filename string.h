//
// Created by bczhc on 26/10/22.
//

#ifndef CCIT_C_STRING_H
#define CCIT_C_STRING_H

#include "array.h"
#include <string.h>
#include <assert.h>

typedef struct {
    Array data;
} String;

void string_push(String *s, char c);

void string_init(String *s);

void string_free(String *s);

void string_push_str(String *s, const char *ptr, size_t length);

const char *string_data(String *s);

size_t string_length(String *s);

Array string_split(String *str, const char *separator, size_t sep_size);

void string_init_with_capacity(String *s, size_t capacity);

String string_new_from_str(const char *str, size_t length);

#endif //CCIT_C_STRING_H
