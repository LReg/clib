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
int main() {
    assert(testSkipWhiteSpace());
    assert(testSkipDecimals());
    assert(testParseInts());
    return 0;
}