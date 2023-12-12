#include "lib.c"
int testSkipWhiteSpace() {
    char * string = "    123123123";
    string = skipWhitespace(string);
    assert(*string == '1');
    return 1;
}
int testSkipDecimals() {
    char * string = "12312355F";
    string = skipDecimals(string);
    assert(*string == 'F');
    return 1;
}
int testParseInts() {
    char * string = "abc 123, 456 -590 123123 sadf123";
    ParsedInts ints = parseInts(string, 10);
    assert(ints.len == 5);
    assert(ints.ints[0] == 123);
    assert(ints.ints[1] == 456);
    assert(ints.ints[2] == -590);
    assert(ints.ints[3] == 123123);
    assert(ints.ints[4] == 123);
    free(ints.ints);
    return 1;
}
int testParseIntstwo() {
    char * string = "1,1,3,1,1,3,1,1,3,1,1,3,1,1,3";
    ParsedInts ints = parseInts(string, 15);
    for (int i = 0; i < ints.len; i++) {
        printf("%d ", ints.ints[i]);
    }
    assert(ints.len == 15);
    assert(ints.ints[0] == 1);
    assert(ints.ints[1] == 1);
    assert(ints.ints[2] == 3);
    assert(ints.ints[3] == 1);
    assert(ints.ints[4] == 1);
    assert(ints.ints[5] == 3);
    assert(ints.ints[6] == 1);
    assert(ints.ints[7] == 1);
    assert(ints.ints[8] == 3);
    assert(ints.ints[9] == 1);
    assert(ints.ints[10] == 1);
    assert(ints.ints[11] == 3);
    assert(ints.ints[12] == 1);
    assert(ints.ints[13] == 1);
    assert(ints.ints[14] == 3);
    free(ints.ints);
    return 1;
}
int main() {
    assert(testSkipWhiteSpace());
    assert(testSkipDecimals());
    assert(testParseInts());
    assert(testParseIntstwo());
    return 0;
}