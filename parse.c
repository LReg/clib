#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

char * skipWhitespace(char * str) {

    while(isblank(*str))
        str++;
    return str;
}

char * skipOperator(char * str) {
    while(*str == '-' || *str == '+' || *str == '*' || *str == '/')
        str++;
    return str;
}

char * skipDecimals(char * str) {
    while(isdigit(*str))
        str++;
    return str;
}

char * skipNonDigits(char * str) {
    while(!isdigit(*str) && *str != '\n' && *str != '\0' && *str != '-' && *str != '+')
        str++;
    return str;
}

FILE * assertOpenFile(char * path, char * mode) {
    FILE * f = fopen(path, mode);
    if (f == NULL) {
        fprintf(stderr, "Could not read file: %s", path);
        exit(1);
    }
    return f;
}

typedef struct ParsedInts {
    int * ints;
    size_t len;
} ParsedInts;

ParsedInts parseInts(char * line, size_t maxNumbers) {
    int * nums = malloc(sizeof(int) * maxNumbers);
    int * numPos = nums;
    while(*line != '\n' || *line != '\0') {
        line = skipNonDigits(line);
        if (*line == '\n' || *line == '\0')
            break;
        *numPos++ = atoi(line);
        line = skipDecimals(skipOperator(line));
    }
    size_t len = numPos - nums;
    nums = realloc(nums, len);
    ParsedInts ret = { nums, len };
    return ret;
}
