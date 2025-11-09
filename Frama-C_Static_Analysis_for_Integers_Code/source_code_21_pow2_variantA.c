#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

// Function to count set bits (popcount)
size_t popcount(uintmax_t num) {
    size_t precision = 0;
    while (num != 0) {
        if (num % 2 == 1) {
            precision++;
        }
        num >>= 1;
    }
    return precision;
}

#define PRECISION(umax_value) popcount(umax_value)

// Function to compute 2^exp, where exp is a signed integer
signed int pow2(signed int exp) {
    if (exp < 0 || exp >= PRECISION(INT_MAX)) {
        // Handle error if exponent is negative or exceeds precision of signed int
        printf("Error: Exponent out of range.\n");
        return 0; // Return 0 for this example
    }
    return 1 << exp; // Shift left by exp bits
}

int main() {
    unsigned int result = pow2 (31); // Trying to compute 2^31 for signed int
    printf("Result: %d\n", result);
    return 0;
}
