#include <limits.h>
#include <stdio.h>

void compliant_func(void) {
    long int a = LONG_MAX; // Change unsigned long to signed long
    signed char sc;

    // Check if 'a' is within the range of signed char
    if (a <= SCHAR_MAX && a >= SCHAR_MIN) {
        sc = (signed char)a; // Safe conversion within range
        printf("Compliant signed char value: %d\n", sc);
    } else {
        printf("Error: Value too large or too small for signed char.\n");
    }
}

int main(void) {
    compliant_func();
    return 0;
}
