#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "./parse.c"

void printLimits() {
    puts("wichtige Begrenzungen:\n");
    printf("Integer: %d\n", INT_MAX);
    printf("Unsigned Integer: %u\n", UINT_MAX);
    printf("Short: %d\n", SHRT_MAX);
    printf("Long Integer: %li\n", LONG_MAX);
    printf("Long unsigned Integer: %llu\n", ULLONG_MAX);
    printf("Long Long Integer: %lli", LONG_LONG_MAX);
    printf("Long Long unsigned Integer: %llu", ULONG_LONG_MAX);
    printf("Float: %f\n", FLT_MAX);
    printf("Double: %f\n", DBL_MAX);
}