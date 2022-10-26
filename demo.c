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
#include "string.h"
#include "common.h"
#include <stdbool.h>

int main() {
    String line = read_line(stdin);

    printf("Input: %s\n", string_data(&line));

    ParseIntResult parsed = parse_int(string_data(&line));

    if (!parsed.ok) {
        switch (parsed.data.error) {
            case PIE_NO_DIGITS:
                perror("PIE_NO_DIGITS");
                break;
            case PIE_OUT_OF_RANGE:
                perror("PIE_OUT_OF_RANGE");
                break;
        }
    } else {
        printf("Parsed: %lu\n", parsed.data.result);
    }

    return 0;
}
