#include <stdio.h>
#include <limits.h>

void func(signed long si_a, signed long si_b) {
    signed long result;

    // Check for left shift overflow:
    // - Ensure si_b is within the valid range
    // - Ensure si_a is within a range that doesn't overflow when shifted
    if (si_b < 0 || si_b >= sizeof(signed long) * 8 || si_a > (LONG_MAX >> si_b)) {
        printf("Error: Left shift overflow\n");
    } else {
        result = si_a << si_b;
        printf("Left Shift Result: %ld\n", result);
    }
}

int main() {
    func(1, 33); // Example that may cause overflow (on systems where long is 32 bits)
    func(4, 2); // Safe left shift
    return 0;
}
