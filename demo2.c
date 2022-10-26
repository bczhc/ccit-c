//
// Created by bczhc on 26/10/22.
//

#include <stdio.h>
#include <malloc.h>
#include "array.h"

int main() {
    Array array;
    array_init(&array);

    for (int i = 0; i < 50; ++i) {
        array_add(&array, &i, sizeof(int));
    }

    array_remove(&array, sizeof(int));

    for (int i = 0; i < array_size(&array) / sizeof(int); ++i) {
        int get = ((int *) array_items(&array))[i];
        printf("Get: %i\n", get);
    }

    array_free(&array);

    return 0;
}