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

/**
 * @param end the end position of string `str`, inclusive, and `null` if `str` is null-terminated 
 */
void string_push_str(String *s, const char *str, const char *end);

const char *string_data(String *s);

size_t string_length(String *s);

#endif //CCIT_C_STRING_H
