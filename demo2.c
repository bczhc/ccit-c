//
// Created by bczhc on 26/10/22.
//

#include <stdio.h>
#include <malloc.h>
#include "array.h"
#include "string.h"

int main() {
    String s;
    string_init(&s);

    string_push(&s,'h');
    string_push(&s,'e');
    string_push(&s,'l');
    string_push(&s,'l');
    string_push(&s,'o');
    string_push_str(&s, ", world!", NULL);

    printf("%zu\n", string_length(&s));
    printf("%s\n", string_data(&s));

    string_free(&s);

    return 0;
}