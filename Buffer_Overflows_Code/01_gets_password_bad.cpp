/*
 * Vulnerable example: uses gets() (no bounds checking).
 * Demonstrates unbounded input -> buffer overflow.
 *
 * Note: gets() is removed from modern C libraries; this is intentionally
 * vulnerable code for demonstration only.
 */
#include <cstdio>

int main(void) {
    char Password[8];
    std::printf("Enter 8-character password: ");
    /* Vulnerable: gets performs no bounds checking */
    gets(Password);
    std::printf("Password entered: %s\n", Password);
    return 0;
}
