/*
 * Demonstrates strncpy usage and null-termination gotchas.
 * Copies fixed-length strings into buffers and prints them.
 */
#include <cstdio>
#include <cstring>

int main(int argc, char *argv[]) {
    (void)argc;
    char a[16];
    char b[16];
    char c[32];

    /* strncpy does NOT guarantee null-termination if source length >= n */
    std::strncpy(a, "0123456789abcdef", sizeof(a));
    std::strncpy(b, "0123456789abcdef0123456789abcdef", sizeof(b));
    /* Safely copy into larger buffer */
    std::strncpy(c, a, sizeof(c));
    c[sizeof(c)-1] = '\0';

    /* Ensure a and b are null-terminated for safe printing */
    a[sizeof(a)-1] = '\0';
    b[sizeof(b)-1] = '\0';

    std::printf("String a: %s\n", a);
    std::printf("String b: %s\n", b);
    std::printf("String c: %s\n", c);
    return 0;
}
