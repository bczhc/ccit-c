//
// Created by bczhc on 25/10/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "array.h"

int main() {
    struct Array *a;
    array_init(&a);

    for (int i = 0; i < 10; ++i) {
        array_add(a, &i, sizeof(int));
    }

    array_remove(a, 2 * sizeof(int));

    {
        int item = 123;
        array_add(a, &item, sizeof(int));
    }

    for (int i = 0; i < array_size(a) / sizeof(int); ++i) {
        int get;
        array_get(a, i * sizeof(int), sizeof(int), &get);
        printf("Get: %d\n", get);
    }

    array_free(a);

    return 0;
}
