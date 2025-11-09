#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

extern size_t popcount(uintmax_t);

#define PRECISION(x) (sizeof(x) * CHAR_BIT) // Calculate precision based on type size

void func(signed int si_a, signed int si_b) {
    unsigned int sresult = 0;
    
    // Check if the shift count exceeds the precision of signed int
    if (si_b < 0 || si_b >= PRECISION(INT_MAX)) {
        printf("Error: Shift count exceeds precision of signed int.\n");
    } else {
        // Perform right shift
        sresult = si_a >> si_b;
        printf("Result of right shift: %d\n",  sresult);
    }
}

int main() {
    signed int a = 10;
    signed int b = 2; // Valid shift
    
    // Test compliant right shift
    func(a, b); // Should show result
    return 0;
}
